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
/**
 ****************************************************************************************
 *
 * @file asdma_mst_api2.h
 *
 * @brief ASDMA utility functions
 *
 ****************************************************************************************
 */

#ifndef _ASDMA_MST_API2_H_
#define _ASDMA_MST_API2_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "dma_common.h"

/*
 * Structs
 ****************************************************************************************
 */
typedef struct {
    uint32_t ADDR;          /* Src/Dest Addr */
    uint32_t TBL0CR;        /* Trans Blk Lvl-0 Cnt */
    uint32_t TBL1CR;        /* Trans Blk Lvl-1 Cnt */
    uint32_t LNAR;          /* Lli Node Addr(DWord Align) */
} ASDMA_DESC_T;

void asdma_handler_register(uint8_t ch, CS_DMA_IRQ_HANDLER_T handler);
void asdma_config(CS_DMA_CH_ENUM ch, DMA_CFG_T *cfg);
void asdma_desc_link(DMA_CFG_T *cfg, ASDMA_DESC_T *desc, ASDMA_DESC_T *next);
uint32_t asdma_get_addr_rd(CS_DMA_CH_ENUM ch);
uint32_t asdma_get_addr_wr(CS_DMA_CH_ENUM ch);
uint16_t asdma_get_lli_cntr(CS_DMA_CH_ENUM ch);
void asdma_set_lli_cntr(CS_DMA_CH_ENUM ch, uint16_t val);
uint32_t asdma_get_trsf_bytes_cntr(CS_DMA_CH_ENUM ch);
void asdma_set_trsf_bytes_cntr(CS_DMA_CH_ENUM ch, uint32_t val);
void asdma_mst_audio_tx_cfg(void);
void asdma_mst_audio_rx_cfg(void);
void asdma_mst_audio_cfg(void);
void asdma_mst_audio_tx_frag_len(unsigned short len);
void asdma_mst_audio_rx_frag_len(unsigned short len);
void asdma_mst_audio_tx_cfg_slv_fifo_threshold(unsigned short th);
void asdma_mst_audio_rx_cfg_slv_fifo_threshold(unsigned short th);
uint32_t asdma_mst_audio_cfg_trig_threshold_get(void);

#endif /* _ASDMA_MST_API2_H_ */

