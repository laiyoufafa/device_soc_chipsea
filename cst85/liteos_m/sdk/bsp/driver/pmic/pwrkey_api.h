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
#ifndef _PWRKEY_API_H_
#define _PWRKEY_API_H_

#include "chip.h"
#include "plf.h"
#include "pmic_api.h"

#define USER_DEFINED_PWRKEY_EN          (1)
#define USER_DEFINED_POWERON_TIME_MS    (0)
#define USER_DEFINED_POWEROFF_TIME_MS   (5200)

enum {
    PWRKEY_IRQ_EVENT_KEYDOWN = 0,
    PWRKEY_IRQ_EVENT_KEYUP,
    PWRKEY_IRQ_EVENT_KEYUP_SINGLE,
};

typedef void (*pwrkey_irq_handler_t)(int event);

/**
 * @brief: Enable pwrkey function if necessary
 */
void pwrkey_init(void);

/**
 * @brief: Power-on check, boot to app if got key event as user defined time
 */
void pwrkey_poweron_check(void);

/**
 * @brief: IRQ handler with event
 * @param[in] event: pos or neg
 */
void pwrkey_irq_handler(int event);

/**
 * @brief: Register pwerkey IRQ callback function
 * @param[in] event: pos or neg
 */
void pwrkey_irq_callback_register(pwrkey_irq_handler_t callback);

/**
 * @brief: Get user config
 * @return: Pwrkey enable or not
 */
int user_pwrkey_enabled(void);

/**
 * @brief: Get user defined power-on time
 * @return: Power-on time in ms, 0 or greater than 400
 */
unsigned int user_pwrkey_poweron_time_get(void);

/**
 * @brief: Get user defined power-off time
 * @return: Power-on time in ms
 */
unsigned int user_pwrkey_poweroff_time_get(void);

#endif /* _PWRKEY_API_H_ */
