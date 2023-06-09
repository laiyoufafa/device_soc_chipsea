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
#ifndef _CS1000LITE_SPI_H_
#define _CS1000LITE_SPI_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================
#define SPI_TX_FIFO_SIZE                        (16)
#define SPI_RX_FIFO_SIZE                        (16)

// =============================================================================
//  TYPES
// =============================================================================

// ============================================================================
// CS1000LITE_SPI_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_CS1000LITE_SPI_BASE   0x5001C000

typedef volatile struct
{
    __IO uint32_t                          ctrl;                         //0x00000000
    __IO uint32_t                          status;                       //0x00000004
    /// Spi1 fifo size (rxtx_buffer): 8bits.
    /// Spi2 fifo size (rxtx_buffer): 8bits.
    /// Spi3 fifo size (rxtx_buffer): 32bits.
    ///
    __IO uint32_t                          rxtx_buffer;                  //0x00000008
    __IO uint32_t                          cfg;                          //0x0000000C
    __IO uint32_t                          pattern;                      //0x00000010
    __IO uint32_t                          stream;                       //0x00000014
    __IO uint32_t                          pin_control;                  //0x00000018
    __IO uint32_t                          irq;                          //0x0000001C
} HWP_CS1000LITE_SPI_T;

static HWP_CS1000LITE_SPI_T * const cs1000liteSpi = ((HWP_CS1000LITE_SPI_T *)REG_CS1000LITE_SPI_BASE);


//ctrl
#define CS1000LITE_SPI_ENABLE     (1<<0)
#define CS1000LITE_SPI_CS_SEL(n)  (((n)&3)<<1)
#define CS1000LITE_SPI_CS_SEL_MASK (3<<1)
#define CS1000LITE_SPI_CS_SEL_SHIFT (1)
#define CS1000LITE_SPI_CS_SEL_CS0 (0<<1)
#define CS1000LITE_SPI_CS_SEL_CS1 (1<<1)
#define CS1000LITE_SPI_CS_SEL_CS2 (2<<1)
#define CS1000LITE_SPI_CS_SEL_CS3 (3<<1)
#define CS1000LITE_SPI_INPUT_MODE (1<<4)
#define CS1000LITE_SPI_CLOCK_POLARITY (1<<5)
#define CS1000LITE_SPI_CLOCK_DELAY(n) (((n)&3)<<6)
#define CS1000LITE_SPI_DO_DELAY(n) (((n)&3)<<8)
#define CS1000LITE_SPI_DI_DELAY(n) (((n)&3)<<10)
#define CS1000LITE_SPI_CS_DELAY(n) (((n)&3)<<12)
#define CS1000LITE_SPI_CS_PULSE(n) (((n)&3)<<14)
#define CS1000LITE_SPI_FRAME_SIZE(n) (((n)&31)<<16)
#define CS1000LITE_SPI_OE_DELAY(n) (((n)&31)<<24)
#define CS1000LITE_SPI_CTRL_DATA_MUX_SEL (1<<29)
#define CS1000LITE_SPI_CTRL_DATA_MUX_SEL_MASK (1<<29)
#define CS1000LITE_SPI_CTRL_DATA_MUX_SEL_SHIFT (29)
#define CS1000LITE_SPI_CTRL_DATA_MUX_SEL_CTRL_REG_SEL (0<<29)
#define CS1000LITE_SPI_CTRL_DATA_MUX_SEL_DATA_REG_SEL (1<<29)
#define CS1000LITE_SPI_INPUT_SEL(n) (((n)&3)<<30)

//status
#define CS1000LITE_SPI_ACTIVE_STATUS (1<<0)
#define CS1000LITE_SPI_CAUSE_RX_OVF_IRQ (1<<3)
#define CS1000LITE_SPI_CAUSE_TX_TH_IRQ (1<<4)
#define CS1000LITE_SPI_CAUSE_TX_DMA_IRQ (1<<5)
#define CS1000LITE_SPI_CAUSE_RX_TH_IRQ (1<<6)
#define CS1000LITE_SPI_CAUSE_RX_DMA_IRQ (1<<7)
#define CS1000LITE_SPI_TX_OVF     (1<<9)
#define CS1000LITE_SPI_RX_UDF     (1<<10)
#define CS1000LITE_SPI_RX_OVF     (1<<11)
#define CS1000LITE_SPI_TX_TH      (1<<12)
#define CS1000LITE_SPI_TX_DMA_DONE (1<<13)
#define CS1000LITE_SPI_RX_TH      (1<<14)
#define CS1000LITE_SPI_RX_DMA_DONE (1<<15)
#define CS1000LITE_SPI_TX_SPACE(n) (((n)&31)<<16)
#define CS1000LITE_SPI_TX_SPACE_MASK (31<<16)
#define CS1000LITE_SPI_TX_SPACE_SHIFT (16)
#define CS1000LITE_SPI_RX_LEVEL(n) (((n)&31)<<24)
#define CS1000LITE_SPI_RX_LEVEL_MASK (31<<24)
#define CS1000LITE_SPI_RX_LEVEL_SHIFT (24)
#define CS1000LITE_SPI_FIFO_FLUSH (1<<30)
#define CS1000LITE_SPI_IRQ_CAUSE(n) (((n)&31)<<3)
#define CS1000LITE_SPI_IRQ_CAUSE_MASK (31<<3)
#define CS1000LITE_SPI_IRQ_CAUSE_SHIFT (3)

//rxtx_buffer
#define CS1000LITE_SPI_DATA_IN_OUT(n) (((n)&0x1FFFFFFF)<<0)
#define CS1000LITE_SPI_CS(n)      (((n)&3)<<29)
#define CS1000LITE_SPI_CS_MASK    (3<<29)
#define CS1000LITE_SPI_CS_SHIFT   (29)
#define CS1000LITE_SPI_READ_ENA   (1<<31)
#define CS1000LITE_SPI_READ_ENA_MASK (1<<31)
#define CS1000LITE_SPI_READ_ENA_SHIFT (31)

//cfg
#define CS1000LITE_SPI_CS_POLARITY_0 (1<<0)
#define CS1000LITE_SPI_CS_POLARITY_0_MASK (1<<0)
#define CS1000LITE_SPI_CS_POLARITY_0_SHIFT (0)
#define CS1000LITE_SPI_CS_POLARITY_0_ACTIVE_HIGH (0<<0)
#define CS1000LITE_SPI_CS_POLARITY_0_ACTIVE_LOW (1<<0)
#define CS1000LITE_SPI_CS_POLARITY_1 (1<<1)
#define CS1000LITE_SPI_CS_POLARITY_1_MASK (1<<1)
#define CS1000LITE_SPI_CS_POLARITY_1_SHIFT (1)
#define CS1000LITE_SPI_CS_POLARITY_1_ACTIVE_HIGH (0<<1)
#define CS1000LITE_SPI_CS_POLARITY_1_ACTIVE_LOW (1<<1)
#define CS1000LITE_SPI_CS_POLARITY_2 (1<<2)
#define CS1000LITE_SPI_CS_POLARITY_2_MASK (1<<2)
#define CS1000LITE_SPI_CS_POLARITY_2_SHIFT (2)
#define CS1000LITE_SPI_CS_POLARITY_2_ACTIVE_HIGH (0<<2)
#define CS1000LITE_SPI_CS_POLARITY_2_ACTIVE_LOW (1<<2)
#define CS1000LITE_SPI_CLOCK_DIVIDER(n) (((n)&0x3FF)<<16)
#define CS1000LITE_SPI_CLOCK_DIVIDER_MASK (0x3FF<<16)
#define CS1000LITE_SPI_CLOCK_DIVIDER_SHIFT (16)
#define CS1000LITE_SPI_CLOCK_LIMITER (1<<28)
#define CS1000LITE_SPI_CLOCK_LIMITER_MASK (1<<28)
#define CS1000LITE_SPI_CLOCK_LIMITER_SHIFT (28)
#define CS1000LITE_SPI_CS_POLARITY(n) (((n)&7)<<0)
#define CS1000LITE_SPI_CS_POLARITY_MASK (7<<0)
#define CS1000LITE_SPI_CS_POLARITY_SHIFT (0)

//pattern
#define CS1000LITE_SPI_PATTERN(n) (((n)&0xFF)<<0)
#define CS1000LITE_SPI_PATTERN_MODE (1<<8)
#define CS1000LITE_SPI_PATTERN_MODE_MASK (1<<8)
#define CS1000LITE_SPI_PATTERN_MODE_SHIFT (8)
#define CS1000LITE_SPI_PATTERN_MODE_DISABLED (0<<8)
#define CS1000LITE_SPI_PATTERN_MODE_ENABLED (1<<8)
#define CS1000LITE_SPI_PATTERN_SELECTOR (1<<9)
#define CS1000LITE_SPI_PATTERN_SELECTOR_MASK (1<<9)
#define CS1000LITE_SPI_PATTERN_SELECTOR_SHIFT (9)
#define CS1000LITE_SPI_PATTERN_SELECTOR_UNTIL (0<<9)
#define CS1000LITE_SPI_PATTERN_SELECTOR_WHILE (1<<9)

//stream
#define CS1000LITE_SPI_TX_STREAM_BIT (1<<0)
#define CS1000LITE_SPI_TX_STREAM_BIT_MASK (1<<0)
#define CS1000LITE_SPI_TX_STREAM_BIT_SHIFT (0)
#define CS1000LITE_SPI_TX_STREAM_BIT_ZERO (0<<0)
#define CS1000LITE_SPI_TX_STREAM_BIT_ONE (1<<0)
#define CS1000LITE_SPI_TX_STREAM_MODE (1<<8)
#define CS1000LITE_SPI_TX_STREAM_MODE_MASK (1<<8)
#define CS1000LITE_SPI_TX_STREAM_MODE_SHIFT (8)
#define CS1000LITE_SPI_TX_STREAM_MODE_DISABLED (0<<8)
#define CS1000LITE_SPI_TX_STREAM_MODE_ENABLED (1<<8)
#define CS1000LITE_SPI_TX_STREAM_STOP_WITH_RX_DMA_DONE (1<<16)
#define CS1000LITE_SPI_TX_STREAM_STOP_WITH_RX_DMA_DONE_MASK (1<<16)
#define CS1000LITE_SPI_TX_STREAM_STOP_WITH_RX_DMA_DONE_SHIFT (16)
#define CS1000LITE_SPI_TX_STREAM_STOP_WITH_RX_DMA_DONE_DISABLED (0<<16)
#define CS1000LITE_SPI_TX_STREAM_STOP_WITH_RX_DMA_DONE_ENABLED (1<<16)

//pin_control
#define CS1000LITE_SPI_CLK_CTRL(n) (((n)&3)<<0)
#define CS1000LITE_SPI_CLK_CTRL_MASK (3<<0)
#define CS1000LITE_SPI_CLK_CTRL_SHIFT (0)
#define CS1000LITE_SPI_CLK_CTRL_SPI_CTRL (0<<0)
#define CS1000LITE_SPI_CLK_CTRL_INPUT_CTRL (1<<0)
#define CS1000LITE_SPI_CLK_CTRL_FORCE_0_CTRL (2<<0)
#define CS1000LITE_SPI_CLK_CTRL_FORCE_1_CTRL (3<<0)
#define CS1000LITE_SPI_DO_CTRL(n) (((n)&3)<<2)
#define CS1000LITE_SPI_DO_CTRL_MASK (3<<2)
#define CS1000LITE_SPI_DO_CTRL_SHIFT (2)
#define CS1000LITE_SPI_DO_CTRL_SPI_CTRL (0<<2)
#define CS1000LITE_SPI_DO_CTRL_INPUT_CTRL (1<<2)
#define CS1000LITE_SPI_DO_CTRL_FORCE_0_CTRL (2<<2)
#define CS1000LITE_SPI_DO_CTRL_FORCE_1_CTRL (3<<2)
#define CS1000LITE_SPI_CS0_CTRL(n) (((n)&3)<<4)
#define CS1000LITE_SPI_CS0_CTRL_MASK (3<<4)
#define CS1000LITE_SPI_CS0_CTRL_SHIFT (4)
#define CS1000LITE_SPI_CS0_CTRL_SPI_CTRL (0<<4)
#define CS1000LITE_SPI_CS0_CTRL_INPUT_CTRL (1<<4)
#define CS1000LITE_SPI_CS0_CTRL_FORCE_0_CTRL (2<<4)
#define CS1000LITE_SPI_CS0_CTRL_FORCE_1_CTRL (3<<4)
#define CS1000LITE_SPI_CS1_CTRL(n) (((n)&3)<<6)
#define CS1000LITE_SPI_CS1_CTRL_MASK (3<<6)
#define CS1000LITE_SPI_CS1_CTRL_SHIFT (6)
#define CS1000LITE_SPI_CS1_CTRL_SPI_CTRL (0<<6)
#define CS1000LITE_SPI_CS1_CTRL_INPUT_CTRL (1<<6)
#define CS1000LITE_SPI_CS1_CTRL_FORCE_0_CTRL (2<<6)
#define CS1000LITE_SPI_CS1_CTRL_FORCE_1_CTRL (3<<6)
#define CS1000LITE_SPI_CS2_CTRL(n) (((n)&3)<<8)
#define CS1000LITE_SPI_CS2_CTRL_MASK (3<<8)
#define CS1000LITE_SPI_CS2_CTRL_SHIFT (8)
#define CS1000LITE_SPI_CS2_CTRL_SPI_CTRL (0<<8)
#define CS1000LITE_SPI_CS2_CTRL_INPUT_CTRL (1<<8)
#define CS1000LITE_SPI_CS2_CTRL_FORCE_0_CTRL (2<<8)
#define CS1000LITE_SPI_CS2_CTRL_FORCE_1_CTRL (3<<8)

//irq
#define CS1000LITE_SPI_MASK_RX_OVF_IRQ (1<<0)
#define CS1000LITE_SPI_MASK_TX_TH_IRQ (1<<1)
#define CS1000LITE_SPI_MASK_TX_DMA_IRQ (1<<2)
#define CS1000LITE_SPI_MASK_RX_TH_IRQ (1<<3)
#define CS1000LITE_SPI_MASK_RX_DMA_IRQ (1<<4)
#define CS1000LITE_SPI_TX_THRESHOLD(n) (((n)&3)<<5)
#define CS1000LITE_SPI_TX_THRESHOLD_MASK (3<<5)
#define CS1000LITE_SPI_TX_THRESHOLD_SHIFT (5)
#define CS1000LITE_SPI_TX_THRESHOLD_1_EMPTY_SLOT (0<<5)
#define CS1000LITE_SPI_TX_THRESHOLD_4_EMPTY_SLOTS (1<<5)
#define CS1000LITE_SPI_TX_THRESHOLD_8_EMPTY_SLOTS (2<<5)
#define CS1000LITE_SPI_TX_THRESHOLD_12_EMPTY_SLOTS (3<<5)
#define CS1000LITE_SPI_RX_THRESHOLD(n) (((n)&3)<<7)
#define CS1000LITE_SPI_RX_THRESHOLD_MASK (3<<7)
#define CS1000LITE_SPI_RX_THRESHOLD_SHIFT (7)
#define CS1000LITE_SPI_RX_THRESHOLD_1_VALID_DATA (0<<7)
#define CS1000LITE_SPI_RX_THRESHOLD_4_VALID_DATA (1<<7)
#define CS1000LITE_SPI_RX_THRESHOLD_8_VALID_DATA (2<<7)
#define CS1000LITE_SPI_RX_THRESHOLD_12_VALID_DATA (3<<7)
#define CS1000LITE_SPI_IRQ_MASK(n) (((n)&31)<<0)
#define CS1000LITE_SPI_IRQ_MASK_MASK (31<<0)
#define CS1000LITE_SPI_IRQ_MASK_SHIFT (0)

#endif /* _CS1000LITE_SPI_H_ */
