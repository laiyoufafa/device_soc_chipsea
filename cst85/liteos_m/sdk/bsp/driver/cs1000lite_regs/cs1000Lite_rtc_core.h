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
#ifndef _CS1000LITE_RTC_CORE_H_
#define _CS1000LITE_RTC_CORE_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// ============================================================================
// CS1000LITE_RTC_CORE_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_CS1000LITE_RTC_CORE_BASE 0x50018800

typedef volatile struct
{
  __IO uint32_t                          rtc_rg_clk_cfg1;              //0x00000000
  __IO uint32_t                          rtc_rg_clk_cfg2;              //0x00000004
  __IO uint32_t                          rtc_rg_dcdc_rf_cfg1;          //0x00000008
  __IO uint32_t                          rtc_rg_por_ctrl_cfg1;         //0x0000000C
  __IO uint32_t                          rtc_rg_por_ctrl_cfg2;         //0x00000010
  __IO uint32_t                          rtc_rg_other_ctrl_cfg1;       //0x00000014
  __IO uint32_t                          rtc_rg_other_ctrl_cfg2;       //0x00000018
  __IO uint32_t                          rtc_rg_por_seq_num_cfg1;      //0x0000001C
  __IO uint32_t                          rtc_rg_por_seq_num_cfg2;      //0x00000020
  __IO uint32_t                          rtc_rg_por_seq_num_cfg3;      //0x00000024
  __IO uint32_t                          rtc_rg_other_ctrl_cfg3;       //0x00000028
  __IO uint32_t                          rtc_rg_int_irq;               //0x0000002C
  __IO uint32_t                          rtc_rg_pwr_cfg;               //0x00000030
} HWP_CS1000LITE_RTC_CORE_T;

static HWP_CS1000LITE_RTC_CORE_T * const cs1000liteRtcCore = ((HWP_CS1000LITE_RTC_CORE_T*)REG_CS1000LITE_RTC_CORE_BASE);


//rtc_rg_clk_cfg1
#define CS1000LITE_RTC_CORE_RTC_RG_PU_XTAL32K (1<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL32K_MODE_SEL (1<<1)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL32K_COMP_IBIT(n) (((n)&7)<<2)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL32K_IBIT(n) (((n)&7)<<5)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL32K_AMP_BIT(n) (((n)&7)<<8)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL32K_CLK_EN(n) (((n)&7)<<11)
#define CS1000LITE_RTC_CORE_RTC_RG_POR_CLK32K_FBIT(n) (((n)&7)<<14)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL_CAP_STEP(n) (((n)&0x3F)<<17)
#define CS1000LITE_RTC_CORE_RTC_RG_LPO512K_TEMP_COEF_BIT(n) (((n)&7)<<23)
#define CS1000LITE_RTC_CORE_RTC_RG_LPO512K_CLK_SEL (1<<26)
#define CS1000LITE_RTC_CORE_RTC_RG_CLK_128K_OUT_EN_SW_MODE (1<<27)
#define CS1000LITE_RTC_CORE_RTC_RG_CLK_128K_OUT_EN_SW_SET (1<<28)

//rtc_rg_clk_cfg2
#define CS1000LITE_RTC_CORE_RTC_RG_PU_MDLL128K (1<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_MDLL128K_DIV_BIT(n) (((n)&7)<<1)
#define CS1000LITE_RTC_CORE_RTC_RG_MDLL128K_FREQ_C_BIT(n) (((n)&15)<<4)
#define CS1000LITE_RTC_CORE_RTC_RG_MDLL128K_FREQ_F_BIT(n) (((n)&0x3F)<<8)
#define CS1000LITE_RTC_CORE_RTC_RG_MDLL128K_RSTN (1<<14)
#define CS1000LITE_RTC_CORE_RTC_RG_MDLL128K_EN (1<<15)
#define CS1000LITE_RTC_CORE_RTC_RG_MDLL128K_SEL (1<<16)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL_CAP_LP_BIT(n) (((n)&31)<<17)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL_CAP2_BIT(n) (((n)&31)<<22)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL_CAP1_BIT(n) (((n)&31)<<27)

//rtc_rg_dcdc_rf_cfg1
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_PFM_THRESHOLD(n) (((n)&3)<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_VBIT_NOR_TUNE(n) (((n)&15)<<6)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_VBIT_DS_SW(n) (((n)&15)<<10)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_VBIT_AVDD12(n) (((n)&3)<<14)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_VREF_SOURCE_INT (1<<16)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_ADD_I_LIMIT (1<<17)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_LESS_SOFTTIME(n) (((n)&3)<<18)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_IBIT_LDO_LIMIT (1<<20)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_EN_CURRENT_LIMIT (1<<24)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_DISCHARGE_ENB (1<<25)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_PFM_MODE_SEL (1<<26)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_REDUCE_I_LIMIT (1<<27)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_CLK_DETVO_LP_DIV(n) (((n)&3)<<28)
#define CS1000LITE_RTC_CORE_RTC_RG_PU_DCDC_RF_AVDDRF (1<<30)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_RDY (1<<31)

//rtc_rg_por_ctrl_cfg1
#define CS1000LITE_RTC_CORE_RTC_RG_POR_VRTC_VBIT (1<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_DCDC_MODE_SEL (1<<1)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_PA_DCDC_MODE_SEL (1<<2)
#define CS1000LITE_RTC_CORE_RTC_RG_POR_MS_VBIT(n) (((n)&3)<<3)
#define CS1000LITE_RTC_CORE_RTC_RG_PU_VBAT_SENSE (1<<5)
#define CS1000LITE_RTC_CORE_RTC_RG_UVLO0_EN (1<<6)
#define CS1000LITE_RTC_CORE_RTC_RG_UVLO0_VBIT(n) (((n)&15)<<7)
#define CS1000LITE_RTC_CORE_RTC_RG_WDG_RSTN_PD_EN (1<<11)
#define CS1000LITE_RTC_CORE_RTC_RG_BOR_VBAT_SEL_BIT (1<<12)
#define CS1000LITE_RTC_CORE_RTC_RG_LDO_VRTC09_DISABLE_CLK (1<<13)
#define CS1000LITE_RTC_CORE_RTC_RG_LVL_PULLR_ENB (1<<14)
#define CS1000LITE_RTC_CORE_RTC_RG_POR_EN_VRTC_CLAMP (1<<15)
#define CS1000LITE_RTC_CORE_RTC_RG_POR_EN_VIOULP_CLAMP (1<<16)
#define CS1000LITE_RTC_CORE_RTC_RG_PU_VRTC_SENSE (1<<17)
#define CS1000LITE_RTC_CORE_RTC_RG_BOR_EN (1<<18)
#define CS1000LITE_RTC_CORE_RTC_RG_BOR_VBIT(n) (((n)&15)<<19)
#define CS1000LITE_RTC_CORE_RTC_RG_PD_RC512K_PWR_PD_EN (1<<23)
#define CS1000LITE_RTC_CORE_RTC_RG_LDO_VCORE09_PU_EN (1<<24)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_VCORE09_PU_EN (1<<25)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_PA_LDO_MODE_EN (1<<26)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_LDO_MODE_EN (1<<27)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO_CFG(n) (((n)&15)<<28)

//rtc_rg_por_ctrl_cfg2
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_MUX0_EN(n) (((n)&0x3F)<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_MUX1_EN(n) (((n)&0x3F)<<6)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_MUX2_EN(n) (((n)&0x3F)<<12)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_PULL_DN(n) (((n)&0x3F)<<18)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_PULL_UP(n) (((n)&0x3F)<<24)

//rtc_rg_other_ctrl_cfg1
#define CS1000LITE_RTC_CORE_RTC_RG_PRESETN_PSM (1<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_PRESETN_CALENDAR (1<<1)
#define CS1000LITE_RTC_CORE_RTC_RG_ALM_POWER_ON_EN (1<<2)
#define CS1000LITE_RTC_CORE_RTC_RG_REPOWER_BOR_EN (1<<3)
#define CS1000LITE_RTC_CORE_RTC_RG_DEEP_SLEEP_AWAKE_EN(n) (((n)&15)<<4)
#define CS1000LITE_RTC_CORE_RTC_RG_REPOWER_WDG_EN (1<<8)
#define CS1000LITE_RTC_CORE_RTC_RG_WDG_RST_RTC_RF_EN (1<<9)
#define CS1000LITE_RTC_CORE_RTC_RG_BOR_EN_PWR_PD (1<<10)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO_SLEW_RATE_D(n) (((n)&15)<<11)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO_IBIT_D (1<<15)
#define CS1000LITE_RTC_CORE_RTC_RG_TEST_EN_DCDC_PA (1<<16)
#define CS1000LITE_RTC_CORE_RTC_RG_TEST_EN_DCDC_RF (1<<17)
#define CS1000LITE_RTC_CORE_RTC_RG_TEST_EN_DCDC_CORE (1<<18)
#define CS1000LITE_RTC_CORE_RTC_RG_TEST_EN_XTAL26M (1<<19)
#define CS1000LITE_RTC_CORE_RTC_RG_AVDD_SENSE_EN_V33V18V13 (1<<20)
#define CS1000LITE_RTC_CORE_RTC_RG_MS_VIO_RO (1<<21)
#define CS1000LITE_RTC_CORE_RTC_RG_TEST_EN_OSC13M (1<<22)
#define CS1000LITE_RTC_CORE_RTC_RG_TEST_EN_USB (1<<23)
#define CS1000LITE_RTC_CORE_RTC_RG_TEST_BIT(n) (((n)&15)<<24)
#define CS1000LITE_RTC_CORE_RTC_RG_LED0_MODE (1<<28)
#define CS1000LITE_RTC_CORE_RTC_RG_LED1_MODE (1<<29)

//rtc_rg_other_ctrl_cfg2
#define CS1000LITE_RTC_CORE_CFG_ANA_FIX_DCDC_RF_VOL (1<<2)
#define CS1000LITE_RTC_CORE_A2D_RTC_MS_VBAT (1<<12)
#define CS1000LITE_RTC_CORE_RTC_RG_DEVICE_ID_CFG(n) (((n)&7)<<13)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL_IBIAS_STEP(n) (((n)&0x3F)<<16)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL_IBIAS_LP_BIT(n) (((n)&31)<<22)
#define CS1000LITE_RTC_CORE_RTC_RG_XTAL_IBIAS_BIT(n) (((n)&31)<<27)

//rtc_rg_por_seq_num_cfg1
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_PU_SEQ_NUM(n) (((n)&31)<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_VCORE09_PU_SEQ_NUM(n) (((n)&31)<<5)
#define CS1000LITE_RTC_CORE_RTC_RG_LDO_PA_PU_SEQ_NUM(n) (((n)&31)<<10)
#define CS1000LITE_RTC_CORE_RTC_RG_AVDD18_PU_SEQ_NUM(n) (((n)&31)<<15)
#define CS1000LITE_RTC_CORE_RTC_RG_PU_USB_SEQ_NUM(n) (((n)&31)<<20)
#define CS1000LITE_RTC_CORE_RTC_RG_USBPLL_CLK_EN_SEQ_NUM(n) (((n)&31)<<25)
#define CS1000LITE_RTC_CORE_RTC_RG_DEVICE_HYS_PFM_MODE_EN (1<<30)
#define CS1000LITE_RTC_CORE_RTC_RG_DEVICE_PU_DCDC_RF_SEQ_EN (1<<31)

//rtc_rg_por_seq_num_cfg2
#define CS1000LITE_RTC_CORE_RTC_RG_XEN_EN_SEQ_NUM(n) (((n)&31)<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_RESET_B_SEQ_NUM(n) (((n)&31)<<5)
#define CS1000LITE_RTC_CORE_RTC_RG_SLP_XEN_EN_SEQ_NUM(n) (((n)&31)<<10)
#define CS1000LITE_RTC_CORE_RTC_RG_SLP_RESET_B_SEQ_NUM(n) (((n)&31)<<15)
#define CS1000LITE_RTC_CORE_RTC_RG_VBAT_RSTN_TH(n) (((n)&0xFF)<<20)

//rtc_rg_por_seq_num_cfg3
#define CS1000LITE_RTC_CORE_RTC_RG_PBINT_POR_TRIG_CNT_TH(n) (((n)&0xFF)<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_PBINT_POR_DEBC_CNT_TH(n) (((n)&0xFF)<<8)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO_POR_TRIG_CNT_TH(n) (((n)&0xFF)<<16)
#define CS1000LITE_RTC_CORE_RTC_RG_DEVICE_POR_TRIG_CNT_TH(n) (((n)&0xFF)<<24)

//rtc_rg_other_ctrl_cfg3
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO_SLEW_RATE_B(n) (((n)&15)<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO_SLEW_RATE_C(n) (((n)&15)<<4)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_OUT_REG(n) (((n)&0x3F)<<8)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_IE(n) (((n)&0x3F)<<14)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_SEL(n) (((n)&0x3F)<<20)
#define CS1000LITE_RTC_CORE_RTC_RG_GPIO27_OEN(n) (((n)&0x3F)<<26)

//rtc_rg_int_irq
#define CS1000LITE_RTC_CORE_RTC_RG_INT_MASK(n) (((n)&15)<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_INT_CLR(n) (((n)&15)<<4)
#define CS1000LITE_RTC_CORE_RTC_RG_DBG_MUX(n) (((n)&31)<<8)
#define CS1000LITE_RTC_CORE_RTC_RG_INT_EN (1<<15)
#define CS1000LITE_RTC_CORE_RTC_INT_RAW_STATUS(n) (((n)&15)<<16)
#define CS1000LITE_RTC_CORE_RTC_INT_MASK_STATUS(n) (((n)&15)<<20)

//rtc_rg_pwr_cfg
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_VBIT_DET_VO_NOR(n) (((n)&15)<<0)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_VBIT_DET_VO_DS(n) (((n)&15)<<4)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_LOW_SENSE_NOR(n) (((n)&7)<<8)
#define CS1000LITE_RTC_CORE_RTC_RG_DCDC_RF_LOW_SENSE_DS(n) (((n)&7)<<11)

#endif
