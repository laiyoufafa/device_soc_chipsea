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
#ifndef _WB_CO_INT_H
#define _WB_CO_INT_H


#include <stdint.h>

#ifndef BIT
#define BIT(x)                  (1ul << (x))
#endif
/* Bit Values */
#define BIT31                   ((uint32_t)(1ul << 31))
#define BIT30                   ((uint32_t)(1ul << 30))
#define BIT29                   ((uint32_t)(1ul << 29))
#define BIT28                   ((uint32_t)(1ul << 28))
#define BIT27                   ((uint32_t)(1ul << 27))
#define BIT26                   ((uint32_t)(1ul << 26))
#define BIT25                   ((uint32_t)(1ul << 25))
#define BIT24                   ((uint32_t)(1ul << 24))
#define BIT23                   ((uint32_t)(1ul << 23))
#define BIT22                   ((uint32_t)(1ul << 22))
#define BIT21                   ((uint32_t)(1ul << 21))
#define BIT20                   ((uint32_t)(1ul << 20))
#define BIT19                   ((uint32_t)(1ul << 19))
#define BIT18                   ((uint32_t)(1ul << 18))
#define BIT17                   ((uint32_t)(1ul << 17))
#define BIT16                   ((uint32_t)(1ul << 16))
#define BIT15                   ((uint32_t)(1ul << 15))
#define BIT14                   ((uint32_t)(1ul << 14))
#define BIT13                   ((uint32_t)(1ul << 13))
#define BIT12                   ((uint32_t)(1ul << 12))
#define BIT11                   ((uint32_t)(1ul << 11))
#define BIT10                   ((uint32_t)(1ul << 10))
#define BIT9                    ((uint32_t)(1ul << 9))
#define BIT8                    ((uint32_t)(1ul << 8))
#define BIT7                    ((uint32_t)(1ul << 7))
#define BIT6                    ((uint32_t)(1ul << 6))
#define BIT5                    ((uint32_t)(1ul << 5))
#define BIT4                    ((uint32_t)(1ul << 4))
#define BIT3                    ((uint32_t)(1ul << 3))
#define BIT2                    ((uint32_t)(1ul << 2))
#define BIT1                    ((uint32_t)(1ul << 1))
#define BIT0                    ((uint32_t)(1ul << 0))
#define ALL_BITS                (0xFFFFFFFFul)

typedef enum {
    FAIL     = 0,
    SUCCESS
} STATUS_T;

#ifndef NULL
#define NULL (void *)0
#endif

/* chipsea */
// #ifndef INLINE
// #define INLINE static __inline
// #endif

#define SHIFT_DSCR_OFFSET(offst, wdth)  (32 - (wdth) - (offst))
#define DSCR_MASK(offst, wdth)          (((wdth) < 32) ? \
        ((uint32_t)((1 << (wdth)) - 1) << (SHIFT_DSCR_OFFSET(offst, wdth))) : \
        (0xFFFFFFFF))
#define GET_DSCR(offst, wdth, ptr)      (((*(uint32_t *) ptr) & \
        (DSCR_MASK(offst,wdth))) >> (SHIFT_DSCR_OFFSET(offst, wdth)))
#define SET_DSCR(offst, wdth, ptr, val) (*(uint32_t *)ptr = ((((uint32_t)(val) << \
        (SHIFT_DSCR_OFFSET(offst,wdth))) & (DSCR_MASK(offst,wdth))) | \
        ((*(uint32_t *) (ptr)) & (~(DSCR_MASK(offst, wdth))))))

#endif // _WB_CO_INT_H
