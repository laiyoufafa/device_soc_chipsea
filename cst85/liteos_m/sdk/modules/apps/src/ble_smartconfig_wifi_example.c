/*
 * Copyright (c) 2021 Chipsea Technologies (Shenzhen) Corp., Ltd. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "wifi_host.h"
#include "netdb.h"
#include "wifi_host_config.h"
#include "wifi_host_cntrl.h"
#include "wifi_nx_msg_tx.h"
#include "wlan_if.h"
#include "sleep_api.h"
#if PLF_BLE_STACK
#include "app_smartconfig.h"
#include "ble_task.h"
#endif
#define TEST_SCAN       0
#define TRACE_APP(...)  do {} while (0)

/**
 *******************************************************************************
 * @defgroup BLE_SMARTCONFIG_WIFI_EXAMPLE
 * @ingroup FHOST
 * @{
 *
 * This module contains code of an example application.\n
 * Each application needs to define a few mandatory functions:
 * - fhost_application_init: Called during firmware intialization to prepare
 *   the application task.\n
 *   In this example the function creates a single task.
 *
 * - fhost_config_get_next_item: Used by control task to retrieve runtime
 *   configuration of the wifi firmware.\n
 *   In this example the configuration is read from variable @ref example_config
 *
 * This example application is very basic:
 * - First it enable ble advertising
 *   When host receiver adv packets, connect to ble device, send ssid/pw to it
 * - Then it connect to an Access Point
 *   Then a DHCP procedure is started to retrieve an IP address.
 *   When DHCP done, it send wifi connect state to host through ble
 *
 *******************************************************************************
 */

#define TEST_CONNECT  0

/// Link parameters
static struct fhost_cntrl_link *cntrl_link;

#if TEST_CONNECT
static int example_connect_website()
{
    char host[] = "api.forismatic.com";
    char query[] = "\
GET /api/1.0/?method=getQuote&format=text&lang=en HTTP/1.1\r\n\
Host: api.forismatic.com\r\n\
\r\n";
    char *resp_buf = NULL;
    char *resp_ptr;
    int resp_buf_len = 1024;
    struct addrinfo hints;
    struct addrinfo *res = NULL;
    int sock = -1;
    int to_sent, sent, bytes, resp_len;

    resp_buf = rtos_malloc(resp_buf_len);
    if (!resp_buf)
        return -1;

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = 0;
    hints.ai_flags = AI_NUMERICSERV;

    if (getaddrinfo(host, "80", &hints, &res))
    {
        return -1;
    }
    else
    {
        // create socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0)
            goto error;

        // and it to the host address
        if (connect(sock, res->ai_addr, res->ai_addrlen) < 0)
            goto error;

        freeaddrinfo(res);
        res = NULL;
    }

    // Send the query
    sent = 0;
    to_sent = strlen(query);
    while (to_sent > sent)
    {
        bytes = send(sock, &query[sent], to_sent - sent, 0);
        if (bytes < 0)
            goto error;
        sent += bytes;
    }

    // Receive the response
    bytes = recv(sock, resp_buf, resp_buf_len, 0);
    if (bytes < 0)
        goto error;
    resp_len = bytes;


    // Extract quote from the response
    resp_ptr = strstr(resp_buf, "\r\n");
    if (!resp_ptr)
    {
         goto invalid_response;
    }
    else if (strncmp(&resp_ptr[-2], "OK", 2))
    {
        resp_ptr[0] = '\0';
        TRACE_APP(ERR, "%s", TR_STR_8(resp_buf));
        goto invalid_response;
    }
    else
    {
        char *quote_len_str;
        int quote_len;
        resp_ptr = strstr(resp_buf, "\r\n\r\n");
        if (!resp_ptr)
            goto invalid_response;

        resp_ptr += 4;
        quote_len_str = resp_ptr;
        resp_ptr = strstr(resp_ptr, "\r\n");
        resp_ptr[0] = '\0';
        resp_ptr += 2;
        quote_len = strtol(quote_len_str, NULL, 16);

        // If quote is too long to fit in resp_buff, truncate it
        if (quote_len - 1> resp_buf_len)
            quote_len = resp_buf_len - 1;

        resp_len -= (resp_ptr - resp_buf);
        memmove(resp_buf, resp_ptr, resp_len);
        quote_len -= resp_len;

        if (quote_len > 0)
        {
            bytes = recv(sock, &resp_buf[resp_len], quote_len, MSG_DONTWAIT);
            if (bytes >= 0)
                resp_len += bytes;
        }
        resp_buf[resp_len] = '\0';

        TRACE_APP(INF, "quote received: %s", TR_STR_8(resp_buf));
        dbg("%s", resp_buf);
    }

  invalid_response:
    // flush socket
    while (bytes > 0)
        bytes = recv(sock, resp_buf, resp_buf_len, MSG_DONTWAIT);

    rtos_free(resp_buf);
    close(sock);
    return 0;

  error:
    TRACE_APP(ERR, "Connection to website failed");
    if (resp_buf)
        rtos_free(resp_buf);

    if (sock > 0)
        close(sock);

    if (res)
        freeaddrinfo(res);

    return -1;
}
#endif /* TEST_CONNECT */

#if PLF_BLE_STACK
rtos_semaphore ble_smartconfig_sema;
static struct ble_smartconfig ble_smartconfig_result;
#define APP_SUCCESS_RSP            ("successful")
#define APP_FAILED_RSP             ("failed")
#define HOST_RSP            ("disconnect")
#define HOST_RSP_LEN        sizeof(HOST_RSP)

void ble_smartconfig_ap_info_received(uint8_t* data, uint32_t length)
{
    int i = 0;
    uint8_t index = 0;
    int ret = 0;
    uint8_t rsp[20];

    dbg("%s recv ap info %d\r\n", __func__, length);

    for (i = 0; i < length; i++) {
        if (data[i] == '\n') {
            memcpy(&ble_smartconfig_result.ssid[0], &data[0], i);
            index = i + 1;
            break;
        }
    }

    for (i = index; i < length; i++) {
            memcpy(&ble_smartconfig_result.pwd[0], &data[index], length - index);
    }

    dbg("ssid %s\r\n", ble_smartconfig_result.ssid);
    dbg("pwd %s\r\n", ble_smartconfig_result.pwd);
    rtos_semaphore_signal(ble_smartconfig_sema, true);

    return;
    ret = wlan_start_sta((uint8_t *)ble_smartconfig_result.ssid, (uint8_t *)ble_smartconfig_result.pwd, 0);
    if (ret == 0) {
        dbg("connect success\r\n");
        #if TEST_CONNECT
        example_connect_website();
        #endif
        memcpy(&rsp[0], APP_SUCCESS_RSP, sizeof(APP_SUCCESS_RSP));
        app_smartconfig_send_rsp(rsp,  sizeof(APP_SUCCESS_RSP));
    } else {
        dbg("connect fail %d\r\n", ret);
        memcpy(&rsp[0], APP_FAILED_RSP, sizeof(APP_FAILED_RSP));
        app_smartconfig_send_rsp(rsp,  sizeof(APP_FAILED_RSP));
    }
}

void ble_smartconfig_state_info_received(uint8_t* data, uint32_t length)
{
    if (memcmp(data, HOST_RSP, HOST_RSP_LEN) == 0) {
        dbg("disconnect\r\n");
        ble_task_deinit();
    }
}

void sta_do_connect()
{
    int ret = 0;
    uint8_t rsp[20];
	dbg("wlan_start_sta start\r\n");
    ret = wlan_start_sta((uint8_t *)ble_smartconfig_result.ssid, (uint8_t *)ble_smartconfig_result.pwd, 0);
	dbg("wlan_start_sta end\r\n");
    if (ret == 0) {
        dbg("connect success\r\n");
        memcpy(&rsp[0], APP_SUCCESS_RSP, sizeof(APP_SUCCESS_RSP));
        app_smartconfig_send_rsp(rsp,  sizeof(APP_SUCCESS_RSP));
        #if TEST_CONNECT
        example_connect_website();
        #endif
    } else {
        dbg("connect fail %d\r\n", ret);
        memcpy(&rsp[0], APP_FAILED_RSP, sizeof(APP_FAILED_RSP));
        app_smartconfig_send_rsp(rsp,  sizeof(APP_FAILED_RSP));
    }
}
#endif
/*
 * Entry point of this example application
 */
static RTOS_TASK_FCT(blewifi_smartconfig_example_task)
{
#if PLF_BLE_STACK
    //ble_task_init();
    app_smartconfig_register_ap_info_cb(ble_smartconfig_ap_info_received);
    app_smartconfig_register_state_info_cb(ble_smartconfig_state_info_received);
    int ret = rtos_semaphore_create(&ble_smartconfig_sema, 1, 0);
    if (ret) {
        dbg("sema create fail: %d\r\n", ret);
    }
#endif
#if TEST_SCAN
    int nb_res;
    struct mac_scan_result result;
    ipc_host_cntrl_start();

    cntrl_link = fhost_cntrl_cfgrwnx_link_open();
    if (cntrl_link == NULL) {
        dbg(D_ERR "Failed to open link with control task\n");
        ASSERT_ERR(0);
    }
    // Reset STA interface (this will end previous wpa_supplicant task)
    if (fhost_set_vif_type(cntrl_link, 0, VIF_UNKNOWN, false) ||
        fhost_set_vif_type(cntrl_link, 0, VIF_STA, false)) {

        fhost_cntrl_cfgrwnx_link_close(cntrl_link);
        return;
   }

    nb_res = fhost_scan(cntrl_link, 0, NULL);
    dbg("Got %d scan results\n", nb_res);

    nb_res = 0;
    while(fhost_get_scan_results(cntrl_link, nb_res++, 1, &result)) {
        result.ssid.array[result.ssid.length] = '\0'; // set ssid string ending
        dbg("(%3d dBm) CH=%3d BSSID=%02x:%02x:%02x:%02x:%02x:%02x SSID=%s\n",
            (int8_t)result.rssi, phy_freq_to_channel(result.chan->band, result.chan->freq),
            ((uint8_t *)result.bssid.array)[0], ((uint8_t *)result.bssid.array)[1],
            ((uint8_t *)result.bssid.array)[2], ((uint8_t *)result.bssid.array)[3],
            ((uint8_t *)result.bssid.array)[4], ((uint8_t *)result.bssid.array)[5],
            (char *)result.ssid.array);
    }

    fhost_cntrl_cfgrwnx_link_close(cntrl_link);
#endif
#if PLF_BLE_STACK
    dbg("wait for connect...smartconfig\r\n");
    rtos_semaphore_wait(ble_smartconfig_sema, -1);
    sta_do_connect();
#endif
    while (1) {
    }
//#else
//#error "invalid test"
//#endif

    rtos_task_delete(NULL);
}

/******************************************************************************
 * Fhost FW interfaces:
 * These are the functions required by the fhost FW that are specific to the
 * final application.
 *****************************************************************************/
/*
 * fhost_application_init: Must initialize the minimum for the application to
 *                         start.
 * In this example only create a new task with the entry point set to the
 * 'fhost_example_task'. The rest on the initialization will be done in this
 * function.
 */
#if CFG_APP_BLESMARTCONFIGWIFI
int fhost_application_init(void)
{
    if (rtos_task_create(blewifi_smartconfig_example_task, "Example task", APPLICATION_TASK,
                         2048, NULL, RTOS_TASK_PRIORITY(1), NULL))
        return 1;

    return 0;
}
#endif
