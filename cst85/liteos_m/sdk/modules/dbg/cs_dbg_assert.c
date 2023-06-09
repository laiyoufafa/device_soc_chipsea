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
#include "dbg_assert.h"
#include "dbg.h"
//#include "ke_event.h"
//#include "hal_machw.h"
//#include "reg_sysctrl.h"
#include "arch.h"

int dbg_assert_block = 1;

#if 0
void dbg_assert_rec(const char *condition, const char * file, int line)
{
    // Disable the interrupts
    GLOBAL_INT_DISABLE();

    // Display a trace message showing the error
    TRACE("ASSERT recovery: %F:%d", (line >> 24) , line);
    line = (line & 0xffffff);
    dbg(D_ERR "ASSERT (%s) at %s:%d\n", condition, file, line);

    // Restore the interrupts
    GLOBAL_INT_RESTORE();
}
#endif

void dbg_assert_err(const char *condition, const char * file, int line)
{
    TRACE("ASSERT error: %F:%d", (line >> 24) , line);
    line = (line & 0xffffff);

    // Stop the interrupts
    GLOBAL_INT_STOP();

    // Display a trace message showing the error
    dbg(D_ERR "ASSERT (%s) at %s:%d\n", condition, file, line);

    while(dbg_assert_block);
}

void dbg_assert_warn(const char *condition, const char * file, int line)
{
    TRACE("ASSERT warning: %F:%d", (line >> 24) , line);
    line = (line & 0xffffff);
    dbg(D_ERR "WARNING (%s) at %s:%d\n", condition, file, line);
}

