/*
 * Copyright (c) 2022 CHIPSEA Co., Ltd. All rights reserved.
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
#ifndef __CSBTMSG_H
#define __CSBTMSG_H

/* cs msg base module id */
typedef enum CS_MSG_MODULE{
    CS_COMMON = 1,
    CS_MGR,
    CS_A2DP,
    CS_AVRCP,
    CS_HFP,
    CS_HSP,
    CS_HID,
    CS_SPP,
    CS_TEST,
    CS_TWS,
    CS_MAX_MODULE
}cs_bt_msg_module;



/*cs adp msg base module id */
enum{
    CS_ADP_COMMON      = (CS_COMMON    <<8 ),
    CS_ADP_MGR         = (CS_MGR       <<8 ),
    CS_ADP_A2DP        = (CS_A2DP      <<8 ),
    CS_ADP_AVRCP       = (CS_AVRCP     <<8 ),
    CS_ADP_HFP         = (CS_HFP       <<8 ),
    CS_ADP_HSP         = (CS_HSP       <<8 ),
    CS_ADP_HID         = (CS_HID       <<8 ),
    CS_ADP_SPP         = (CS_SPP       <<8 ),
    CS_ADP_TEST        = (CS_TEST      <<8 ),
    CS_ADP_TWS         = (CS_TWS       <<8 ),
    CS_ADP_MAX_MODULE  = (CS_MAX_MODULE<<8 )
};

#define CS_ADP_MSG_OFFSET  0

/*cs adp msg */
enum{
    CS_ADP_FIRST_COMMON_MSG = (CS_ADP_MSG_OFFSET + CS_ADP_COMMON),
    CS_ADP_STACK_INIT,
    CS_ADP_ACCESSIBLE_CHANGE,
    CS_ADP_ENCRYPYION_CHANGE,
    CS_ADP_LAST_COMMON_MSG,

    CS_ADP_FIRST_MGR_MSG    = (CS_ADP_MSG_OFFSET + CS_ADP_MGR),
    CS_ADP_ACL_CONNECT_IND,
    CS_ADP_ACL_CONNECT_CNF,
    CS_ADP_ACL_DISCONNECT,
    CS_ADP_SCO_CONNECT_IND,
    CS_ADP_SCO_CONNECT_CNF,
    CS_ADP_SCO_DISCONNECTED,
    CS_ADP_PAIRING_COMPLETE,
    CS_ADP_INQUIRY_RESULT,
    CS_ADP_INQUIRY_COMPLETE,
    CS_ADP_INQUIRY_CANCELED,
    CS_ADP_BLE_ADV_DATA,
    CS_ADP_LAST_MGR_MSG,

    CS_ADP_FIRST_A2DP_MSG   = (CS_ADP_MSG_OFFSET + CS_ADP_A2DP),
    CS_ADP_A2DP_STREAM_OPEN,
    CS_ADP_A2DP_STREAM_STARTED,
    CS_ADP_A2DP_STREAM_SUSPENDED,
    CS_ADP_A2DP_STREAM_CLOSED,
    CS_ADP_A2DP_STREAM_DATA_IND,
    CS_ADP_A2DP_STREAM_PACKET_SENT,
    CS_ADP_LAST_A2DP_MSG,

    CS_ADP_FIRST_AVRCP_MSG  = (CS_ADP_MSG_OFFSET + CS_ADP_AVRCP),
    CS_ADP_AVRCP_CONNECT,
    CS_ADP_AVRCP_DISCONNECT,
    CS_ADP_AVRCP_PANEL_PRESS,
    CS_ADP_AVRCP_ADV_VOLUME_CHANGE,
    CS_ADP_AVRCP_ADV_PLAYSTAUTS_CHANGE,
    CS_ADP_LAST_AVRCP_MSG,

    CS_ADP_FIRST_HFP_MSG    = (CS_ADP_MSG_OFFSET + CS_ADP_HFP),
    CS_ADP_HFP_CONNECTED,
    CS_ADP_HFP_DISCONNECTED,
    CS_ADP_HFP_AUDIO_CONNECTED,
    CS_ADP_HFP_AUDIO_DISCONNECTED,
    CS_ADP_HFP_AUDIO_DATA_SENT,
    CS_ADP_HFP_AUDIO_DATA_IND,
    CS_ADP_HFP_CALL_STATUS_IND,
    CS_ADP_HFP_CALLSETUP_STATUS_IND,
    CS_ADP_HFP_CALLHOLD_STATUS_IND,
    CS_ADP_HFP_RING_IND,
    CS_ADP_HFP_CURRENT_CALL_NUM,
    CS_ADP_HFP_SPEAKER_VOLUME,
    CS_ADP_HFP_SIRI_STATUS,
    CS_ADP_HFP_AG_INDICATORS_STATUS,
    CS_ADP_HFP_COMMON_AT_RESULT_IND,
    CS_ADP_LAST_HFP_MSG,

    CS_ADP_FIRST_HSP_MSG    = (CS_ADP_MSG_OFFSET + CS_ADP_HSP),
    CS_ADP_HSP_CONNECTED,
    CS_ADP_HSP_DISCONNECTED,
    CS_ADP_HSP_AUDIO_CONNECTED,
    CS_ADP_HSP_AUDIO_DISCONNECTED,
    CS_ADP_HSP_AUDIO_DATA_SENT,
    CS_ADP_HSP_AUDIO_DATA_IND,
    CS_ADP_HSP_RING_IND,
    CS_ADP_HSP_SPEAKER_VOLUME,
    CS_ADP_LAST_HSP_MSG,

    CS_ADP_FIRST_HID_MSG    = (CS_ADP_MSG_OFFSET + CS_ADP_HID),
    CS_ADP_HID_CONNECTED,
    CS_ADP_HID_DISCONNECTED,
    CS_ADP_LAST_HID_MSG,

    CS_ADP_FIRST_SPP_MSG    = (CS_ADP_MSG_OFFSET + CS_ADP_SPP),
    CS_ADP_SPP_CONNECTED_IND,
    CS_ADP_SPP_CONNECTED_CNF,
    CS_ADP_SPP_DISCONNECTED,
    CS_ADP_SPP_DATA_SENT,
    CS_ADP_SPP_DATA_IND,
    CS_ADP_LAST_SPP_MSG,

    CS_ADP_FIRST_TEST_MSG   = (CS_ADP_MSG_OFFSET + CS_ADP_TEST),
    CS_ADP_TEST_CONNECTED_CNF,
    CS_ADP_TEST_DISCONNECTED,
    CS_ADP_TEST_SCO_CONNECT,
    CS_ADP_TEST_SCO_DISCONNECT,
    CS_ADP_TEST_SCO_DATA_SENT,
    CS_ADP_TEST_SCO_DATA_IND,
    CS_ADP_TEST_INQUIRY_RESULT,
    CS_ADP_TEST_INQUIRY_COMPLETE,
    CS_ADP_TEST_INQUIRY_CANCELED,
    CS_ADP_TEST_L2CAP_CONNECTD,
    CS_ADP_TEST_L2CAP_DISCONNECTD,
    CS_ADP_TEST_L2CAP_DATA_SENT,
    CS_ADP_TEST_L2CAP_DATA_IND,
    CS_ADP_LAST_TEST_MSG,

    CS_ADP_FIRST_TWS_MSG    = (CS_ADP_MSG_OFFSET + CS_ADP_TWS),
    CS_ADP_TWS_CONNECTED_IND,
    CS_ADP_TWS_CONNECTED_CNF,
    CS_ADP_TWS_DISCONNECTED,
    CS_ADP_TWS_STREAM_STARTED,
    CS_ADP_TWS_STREAM_SUSPENDED,
    CS_ADP_TWS_STREAM_DATA_IND,
    CS_ADP_TWS_SCO_CONNECT,
    CS_ADP_TWS_SCO_DISCONNECT,
    CS_ADP_TWS_SCO_DATA_IND,
    CS_ADP_TWS_DATA_IND,
    CS_ADP_TWS_DATA_SEND,
    CS_ADP_TWS_TRIG_NUM,
    CS_ADP_TWS_AUDIO_SYNC_MSG,
    CS_ADP_TWS_ADV_DATA,
    CS_ADP_TWS_LOST_SEQUENCE,
    CS_ADP_TWS_MSS_COMPLETE,
    CS_ADP_LAST_TWS_MSG,
};

#endif
