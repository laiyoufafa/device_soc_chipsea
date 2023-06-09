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
#ifndef _RTOS_OHOS_DEF_H
#define _RTOS_OHOS_DEF_H

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "cmsis_os2.h"
#include "los_swtmr.h"
#include "los_tick.h"
#include "los_memory.h"
#include "los_task.h"

/*
 * DEFINITIONS
 ****************************************************************************************
 */
typedef long BaseType_t;
typedef unsigned long UBaseType_t;
typedef uint32_t TickType_t;

#define pdFALSE    ( ( BaseType_t ) 0 )
#define pdTRUE     ( ( BaseType_t ) 1 )
/// RTOS task handle
//typedef TaskHandle_t   rtos_task_handle;
typedef osThreadId_t rtos_task_handle;

/// RTOS priority
//typedef UBaseType_t         rtos_prio;
typedef osPriority_t   rtos_prio;

/// RTOS task function
//typedef TaskFunction_t      rtos_task_fct;
typedef osThreadFunc_t  rtos_task_fct;

/// RTOS queue
//typedef QueueHandle_t       rtos_queue;
typedef osMessageQueueId_t  rtos_queue;

/// RTOS semaphore
//typedef SemaphoreHandle_t   rtos_semaphore;
typedef osSemaphoreId_t rtos_semaphore;

/// RTOS mutex
//typedef SemaphoreHandle_t   rtos_mutex;
typedef osMutexId_t rtos_mutex;

/// RTOS event group
//typedef EventGroupHandle_t  rtos_event_group;

/// RTOS scheduler state
typedef BaseType_t  rtos_sched_state;

typedef osTimerId_t TimerHandle_t;

typedef void (*TimerCallbackFunction_t)(TimerHandle_t xTimer);
/*
 * MACROS
 ****************************************************************************************
 */
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

/// Macro building the prototype of a RTOS task function
#define RTOS_TASK_FCT(name)        portTASK_FUNCTION(name, env)

/// Macro building a task priority as an offset of the IDLE task priority
#define RTOS_TASK_PRIORITY(prio)  (osPriorityNormal + (prio))

/// Macro defining a null RTOS task handle
#define RTOS_TASK_NULL     NULL
#define configTICK_RATE_HZ ((TickType_t)1000)
#define portMAX_DELAY      osWaitForever

#define pdMS_TO_TICKS LOS_MS2Tick


#endif // _RTOS_OHOS_DEF_H
