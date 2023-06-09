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
#ifndef _COMMAND_H_
#define _COMMAND_H_

#ifdef __cplusplus
extern "C" {
#endif
typedef int (*cmd_func_t)(int argc, char *const argv[]);
typedef struct {
    const char *name;       /* Command Name                 */
    const char *usage;      /* Usage message                */
    int        maxargs;     /* Maximum number of arguments  */
    cmd_func_t cmd;         /* Callback function            */
} cmd_tbl_t;

void command_init(void);
int command_handle_char(char ch);
void command_parser(void);
int  command_add(const char *name, const char *usage, int maxargs, cmd_func_t func);
unsigned int command_strtoul(const char *cp, char **endp, unsigned int base);
unsigned int command_pend_list_empty(void);

#ifdef __cplusplus
}
#endif

#endif /* _COMMAND_H_ */
