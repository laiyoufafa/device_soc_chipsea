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
#ifndef _CS1000AUD_ANALOG_REG_H_
#define _CS1000AUD_ANALOG_REG_H_

#include "chip.h"

// =============================================================================
//  MACROS
// =============================================================================

// =============================================================================
//  TYPES
// =============================================================================

// =============================================================================
// CS1000AUD_ANALOG_REG_T
// -----------------------------------------------------------------------------
///
// =============================================================================
#define REG_CS1000AUD_ANALOG_REG_BASE 0x50019000

typedef struct {
    __IO uint32_t Reserved_00000000[8];         //0x00000000
    __IO uint32_t               cfg_ana_touch_ctrl;         //0x00000020
    __IO uint32_t Reserved_00000024[55];        //0x00000024
    __IO uint32_t               dcdc_rf_cfg2;               //0x00000100
    __IO uint32_t               dcdc_core_cfg1;             //0x00000104
    __IO uint32_t               dcdc_core_cfg2;             //0x00000108
    __IO uint32_t               dcdc_pa_cfg1;               //0x0000010C
    __IO uint32_t               dcdc_pa_cfg2;               //0x00000110
    __IO uint32_t               ldo_cfg;                    //0x00000114
    __IO uint32_t               pwr_pd_crtl;                //0x00000118
    __IO uint32_t               sw_rst_ctrl;                //0x0000011C
    __IO uint32_t               clk_ctrl1;                  //0x00000120
    __IO uint32_t               clk_ctrl2;                  //0x00000124
    __IO uint32_t               clk_ctrl3;                  //0x00000128
    __IO uint32_t               por_ctrl;                   //0x0000012C
    __IO uint32_t               div128k_cfg;                //0x00000130
    __IO uint32_t               pwr_key_cfg;                //0x00000134
    __IO uint32_t               pwr_lp_ctrl;                //0x00000138
    __IO uint32_t               dcdc_rf_dvfs_ctrl;          //0x0000013C
    __IO uint32_t               dcdc_vcore_dvfs_ctrl;       //0x00000140
    __IO uint32_t               ldo_vrtc_dvfs_ctrl;         //0x00000144
    __IO uint32_t               status_flag;                //0x00000148
    __IO uint32_t Reserved_0000014C;            //0x0000014C
    __IO uint32_t               other_ctrl_cfg3;            //0x00000150
    __IO uint32_t               gpio_ctrl0;                 //0x00000154
    __IO uint32_t               gpio_ctrl1;                 //0x00000158
    __IO uint32_t               gpio_ctrl2;                 //0x0000015C
    __IO uint32_t Reserved_00000160[2];         //0x00000160
    __IO uint32_t               test_en_ctrl;               //0x00000168
    __IO uint32_t               agpio_ctrl;                 //0x0000016C
    __IO uint32_t Reserved_00000170;            //0x00000170
    __IO uint32_t               ldo_vcore09_cfg;            //0x00000174
} HWP_CS1000AUD_ANALOG_REG_T;

static HWP_CS1000AUD_ANALOG_REG_T * const cs1000audAnalogReg = ((HWP_CS1000AUD_ANALOG_REG_T *)REG_CS1000AUD_ANALOG_REG_BASE);


//cfg_ana_touch_ctrl
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_CHOP_SEL (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_CHOP_EN(n) (((n)&3)<<1)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_CLK_EDGE_SEL (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_CDC_MODE(n) (((n)&3)<<4)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_COS_BIT (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_LP_MODE (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_REFV1_BIT(n) (((n)&3)<<8)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_PU_BIT(n) (((n)&3)<<10)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_REFV_BIT(n) (((n)&7)<<12)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_REFC_BIT(n) (((n)&7)<<16)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_IBIT(n) (((n)&7)<<20)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TOUCH_IOS_BIT(n) (((n)&7)<<24)

//dcdc_rf_cfg2
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_VBIT_OFFSET(n) (((n)&15)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_FBIT(n) (((n)&3)<<4)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_SLOPEXHALF (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_EN_AUTOZERO (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_COUNTER_DISABLE (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_PGATE_DELAY (1<<9)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_NGATE_DELAY (1<<10)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_DISABLE_COMP (1<<12)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_ADD_REDUCE_VOS (1<<13)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_EN_BUFFER (1<<14)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_BIT_SLOPE(n) (((n)&3)<<15)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_EN_SOFTSTART (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_HEAVY_LOAD(n) (((n)&3)<<18)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_CLK_AMP (1<<20)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_SLOPE_EN (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_CLK_DIASBLE (1<<22)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_EN_PFM_MAX (1<<23)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_EN_ANTIRING (1<<24)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_VBIT_PFM_HYS(n) (((n)&3)<<25)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_RF_EN_DIGZERO (1<<27)

//dcdc_core_cfg1
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_BIT_SLOPE(n) (((n)&3)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_DISCHARGE_ENB (1<<2)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_DISABLE_COMP (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_PGATE_DELAY (1<<5)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_EN_SOFTSTART (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_CLK_DIASBLE (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_LOW_SENSE_NOR(n) (((n)&7)<<8)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_MORE_P (1<<11)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_EN_BUFFER (1<<12)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_SLOPE_EN (1<<13)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_EN_ANTIRING (1<<14)
#define CS1000AUD_ANALOG_REG_CFG_ANA_PU_DCDC_CORE_AVDDRF (1<<15)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_VREF_SOURCE_INT (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_RDY (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_VBIT_PFM_BYS(n) (((n)&3)<<18)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_EN_AUTOZERO (1<<20)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_EN_DIGZERO (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_LOW_SENSE_DS(n) (((n)&7)<<22)

//dcdc_core_cfg2
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_EN_AUTOZERO (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_RDY (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_VBIT_OFFSET(n) (((n)&15)<<5)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_PFM_THRESHOLD(n) (((n)&3)<<9)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_VBIT_DET_VO(n) (((n)&7)<<11)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_VBIT_AVDD12(n) (((n)&3)<<14)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_FBIT(n) (((n)&3)<<16)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_SLOPEXHALF (1<<19)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_NGATE_DELAY (1<<20)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_PFM_MODE_SEL (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_LESS_SOFTTIME(n) (((n)&3)<<22)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_ENB_DET_VO (1<<24)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_ADD_REDUCE_VOS (1<<25)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_HEAVY_LOAD(n) (((n)&3)<<26)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_CLK_AMP (1<<28)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_COUNTER_DISABLE (1<<30)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_CORE_EN_PFM_MAX (1<<31)

//dcdc_pa_cfg1
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_NGATE_DELAY(n) (((n)&3)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_DISCHARGE_ENB (1<<2)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_DISABLE_COMP (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_ADD_REDUCE_VOS (1<<4)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_EN_BUFFER (1<<5)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_BIT_SLOPE(n) (((n)&3)<<6)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_EN_SOFTSTART (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_PA_PFM_MODE_SEL (1<<9)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_HEAVY_LOAD(n) (((n)&3)<<10)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_CLK_AMP (1<<12)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_PA_SLP_DROP_EN (1<<13)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_SLOPE_EN (1<<14)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_CLK_DIASBLE (1<<15)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_EN_PFM_MAX (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_EN_ANTIRING (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_REDUCE_I_LIMIT (1<<18)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_VBIT_BOND (1<<19)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_ENB_DETVO (1<<20)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_MORE_PPM (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_VBIT_PFM_HYS(n) (((n)&3)<<22)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_PA_PFM_MODE_SLP_EN (1<<24)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_COUNTER_DISABLE (1<<25)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_IBIT_LDO_LIMIT (1<<26)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_PGATE_DELAY (1<<27)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_LOW_SENSE_NOR(n) (((n)&7)<<28)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_EN_CURRENT_LIMIT (1<<31)

//dcdc_pa_cfg2
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_VBIT_OFFSET(n) (((n)&15)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_PFM_THRESHOLD(n) (((n)&3)<<4)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_VBIT_DETVO(n) (((n)&7)<<6)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_PA_1V8_VBIT_NOR_TUNE(n) (((n)&0x3F)<<9)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_VBIT_AVDD12(n) (((n)&3)<<15)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_FBIT(n) (((n)&3)<<17)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_SLOPEXHALF (1<<19)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_EN_DIGZERO (1<<20)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_VREF_SOURCE_INT (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_ADD_I_LIMIT (1<<22)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_LESS_SOFTTIME(n) (((n)&3)<<23)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_PA_VBIT_DS_SW(n) (((n)&0x3F)<<25)
#define CS1000AUD_ANALOG_REG_CFG_ANA_PU_DCDC_PA_AVDDRF (1<<31)

//ldo_cfg
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_AVDD18_VBIT_DS_SW(n) (((n)&15)<<3)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_AVDD18_VBIT_NOR_TUNE(n) (((n)&15)<<7)
#define CS1000AUD_ANALOG_REG_CFG_ANA_AVDD_SENSE_SEL(n) (((n)&3)<<11)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_AVDD18_SLP_DROP_EN (1<<18)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_PA_3V3_VBIT_NOR_TUNE(n) (((n)&0x3F)<<19)
#define CS1000AUD_ANALOG_REG_CFG_ANA_DCDC_PA_LOW_SENSE_DS(n) (((n)&7)<<25)

//pwr_pd_crtl
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_BG (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_DCDC_RF (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_LDO_AVDD18 (1<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_DCDC_VCORE09 (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_LDO_VCORE09 (1<<4)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_DCDC_PA (1<<5)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_LDO_VRTC09 (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_CHGR (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PD_LDO_AVDD33_AUD (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_RTC_AON_GPIO_VIO_ULP_SEL (1<<9)
#define CS1000AUD_ANALOG_REG_CFG_RTC_AON_GPIO_VIO_SEL (1<<10)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_FORCE_BG (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_FORCE_DCDC_RF (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_FORCE_LDO_AVDD18 (1<<18)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_FORCE_DCDC_VCORE09 (1<<19)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_FORCE_DCDC_PA (1<<20)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_FORCE_LDO_VRTC09 (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_FORCE_LDO_VCORE09 (1<<22)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_FORCE_LDO_AVDD33_AUD (1<<23)

//sw_rst_ctrl
#define CS1000AUD_ANALOG_REG_CFG_RTC_SOFT_RST (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_REG_RST_PD_EN (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_RST_PD_THRESHOLD_(n) (((n)&15)<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_WDG_RST_PD_EN (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_KEY_RST_PD_EN (1<<9)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_RST_XEN_PD_EN (1<<10)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_RST_LDO_VRTC09_PD_EN (1<<11)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_RST_LDO_AVDD18_PD_EN (1<<12)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_RST_DCDC_RF_PD_EN (1<<13)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_RST_DCDC_VCORE09_PD_EN (1<<14)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_RST_DCDC_PA_PD_EN (1<<15)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_RST_LDO_AVDD33_AUD_PD_EN (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_OFF_SEQ_EN (1<<31)

//clk_ctrl1
#define CS1000AUD_ANALOG_REG_CFG_RTC_PU_LPO256K (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RC_256K_EN (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PU_XTAL (1<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PU_OSC13M (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_13M_EN (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_RTC_XTAL_CLK_6P5M_EN (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_RTC_XTAL_CLK_26M_EN (1<<10)
#define CS1000AUD_ANALOG_REG_CFG_RTC_XTAL_COMP_EN (1<<11)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RC_128K_SEL (1<<12)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CORE_SW_FAST_CLK_SEL_SET (1<<13)
#define CS1000AUD_ANALOG_REG_CFG_RTC_XEN_SW_SET (1<<14)
#define CS1000AUD_ANALOG_REG_CFG_RTC_XTAL_BUF_EN (1<<15)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_26M_EN_SW_MODE(n) (((n)&0x3F)<<16)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_26M_EN_SW_SET(n) (((n)&0x3F)<<22)

//clk_ctrl2
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_NOR_IREF_BIT(n) (((n)&7)<<6)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_COMP_IBIT(n) (((n)&7)<<10)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_NOR_REG_VBIT(n) (((n)&15)<<13)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_PU_BIT(n) (((n)&3)<<17)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_IBIAS_LP_BIT(n) (((n)&15)<<19)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_RF_ON_REG_VBIT(n) (((n)&15)<<23)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_CAP_AVDD_SEL (1<<28)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_RF_ON_IREF_BIT(n) (((n)&7)<<29)

//clk_ctrl3
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_CAP_FINE_BIT(n) (((n)&0x3F)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_NOR_VBCG_EN (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_CLK_DLY_BIT(n) (((n)&7)<<7)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_NOR_REG_BYPASS (1<<10)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_RF_ON_REG_BYPASS (1<<11)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_IREF_LP_BIT(n) (((n)&7)<<12)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_FB_RBIT(n) (((n)&7)<<16)
#define CS1000AUD_ANALOG_REG_CFG_ANA_XTAL_RF_ON_VBCG_EN (1<<19)

//por_ctrl
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_TX_ON_DCDC_RF_PFM_MODE_EN (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_TX_ON_DCDC_CORE_PFM_MODE_EN (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_RX_ON_DCDC_RF_PFM_MODE_EN (1<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_RX_ON_DCDC_CORE_PFM_MODE_EN (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PU_MDLL_DCDC_RF_PFM_MODE_EN (1<<4)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PU_MDLL_DCDC_CORE_PFM_MODE_EN (1<<5)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PSM_DCDC_RF_PFM_MODE_EN (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PSM_DCDC_RF_HYS_PFM_MODE_EN (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_RTC_MS_VIO_EN (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_ANA_MS_VIO_VBIT(n) (((n)&15)<<9)
#define CS1000AUD_ANALOG_REG_CFG_RTC_VIO_VIOULP_SHORT (1<<13)
#define CS1000AUD_ANALOG_REG_CFG_ANA_PU_MDLL_MODE_EN (1<<14)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_TX_ON_DCDC_RF_DVFS_MODE_EN (1<<15)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_TX_ON_DCDC_CORE_DVFS_MODE_EN (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_RX_ON_DCDC_RF_DVFS_MODE_EN (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_RX_ON_DCDC_CORE_DVFS_MODE_EN (1<<18)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PU_MDLL_DCDC_RF_DVFS_MODE_EN (1<<19)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PU_MDLL_DCDC_CORE_DVFS_MODE_EN (1<<20)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PU_MDLL_XTAL_MODE_EN (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_RX_ON_XTAL_MODE_EN (1<<22)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RF_TX_ON_XTAL_MODE_EN (1<<23)
#define CS1000AUD_ANALOG_REG_CFG_ANA_MS_GPIO_SW (1<<24)
#define CS1000AUD_ANALOG_REG_CFG_ANA_MS_GPIO_HW_EN (1<<25)

//div128k_cfg
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_DIV_128K_STEP_OFFSET_NORMAL(n) (((n)&0xFF)<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_DIV_128K_STEP_OFFSET_LP(n) (((n)&0xFF)<<8)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_DIV_128K_STEP_OFFSET_UPDATE (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_DIV_128K_LP_MODE_H_REG (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_DIV_128K_LP_MODE_H_DR (1<<18)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_6P5M_DIV_128K_EN (1<<20)

//pwr_key_cfg
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_KEY_LONG_RST_THRESHOLD(n) (((n)&15)<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_KEY_LONG_AUTO_ON_EN (1<<4)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_KEY_LONG_RST_MODE (1<<5)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_KEY_LONG_SW_RST_MODE (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_KEY_LONG_RST_DISABLE (1<<7)

//pwr_lp_ctrl
#define CS1000AUD_ANALOG_REG_CFG_RTC_BG_SLP_PD_EN (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SLP_LDO_PD_EN (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_SLP_PD_EN (1<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_PA_SLP_PD_EN (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_VCORE09_SLP_PD_EN (1<<4)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VRTC09_SLP_PD_EN (1<<5)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_AVDD18_SLP_PD_EN (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_RTC_XTAL_SLP_PD_EN (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_RTC_OSC13M_SLP_PD_EN (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_RTC_OSC13M_SLP_DIS_EN (1<<9)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_COMP_SLP_DIS_EN (1<<10)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_6P5M_SLP_DIS_EN (1<<11)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_BUF_SLP_DIS_EN (1<<12)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CLK_26M_SLP_DIS_EN (1<<13)
#define CS1000AUD_ANALOG_REG_CFG_RTC_GATE_TO_DBB_SLP_EN (1<<14)
#define CS1000AUD_ANALOG_REG_CFG_RTC_CORE_ISO_SLP_EN (1<<15)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_SLP_LP_EN (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_PA_SLP_LP_EN (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SLP_RTC_PCLK_SW_EN (1<<18)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_AVDD18_SLP_LP_EN (1<<19)
#define CS1000AUD_ANALOG_REG_CFG_RTC_XEN_SLP_PD_EN (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_RTC_XTAL_SLP_LP_EN (1<<22)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RESET_B_SLP_EN (1<<23)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SLP_CORE_CLK_FAST_SEL_EN (1<<24)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_SLP_IN_MSADC_SEL (1<<25)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VCORE09_SLP_PD_EN (1<<26)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_VCORE09_PFM_MODE_SLP_EN (1<<27)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_PFM_MODE_SLP_EN (1<<28)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_HYS_PFM_MODE_SLP_EN (1<<29)
#define CS1000AUD_ANALOG_REG_CFG_RTC_MS_VIO_SLP_PD_EN (1<<30)
#define CS1000AUD_ANALOG_REG_CFG_RTC_AON_GPIO_VIO_SEL_SLP_EN (1<<31)

//dcdc_rf_dvfs_ctrl
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_SLP_DROP_EN (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_SLP_STEP_EN (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_SLP_STEP_VOL(n) (((n)&15)<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_SLP_STEP_NUM(n) (((n)&15)<<6)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_SLP_STEP_DELAY(n) (((n)&3)<<10)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_NOR_DROP_EN (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_NOR_STEP_EN (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_NOR_STEP_VOL(n) (((n)&15)<<18)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_NOR_STEP_NUM(n) (((n)&15)<<22)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_RF_NOR_STEP_DELAY(n) (((n)&3)<<26)

//dcdc_vcore_dvfs_ctrl
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_SLP_DROP_EN (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_SLP_STEP_EN (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_SLP_STEP_VOL(n) (((n)&31)<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_SLP_STEP_NUM(n) (((n)&15)<<7)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_SLP_STEP_DELAY(n) (((n)&3)<<11)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_VOSEL_DS_SW(n) (((n)&31)<<13)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_VOSEL_NOR_TUNE(n) (((n)&31)<<18)

//ldo_vrtc_dvfs_ctrl
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VRTC09_SLP_DROP_EN (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VRTC09_SLP_STEP_EN (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VRTC09_SLP_STEP_VOL(n) (((n)&31)<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VRTC09_SLP_STEP_NUM(n) (((n)&15)<<7)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VRTC09_SLP_STEP_DELAY(n) (((n)&3)<<11)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VRTC09_VOSEL_DS_SW(n) (((n)&31)<<13)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VRTC09_VOSEL_NOR_TUNE(n) (((n)&31)<<18)

//status_flag
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_KEY_LONG_FLAG (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SOFT_RST_FLAG (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_POR_CHIP_PD_FLAG (1<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_UVLO_CHIP_PD_FLAG (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_RTC_HW_PWR_KEY_CHIP_PD_FLAG (1<<4)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_CHIP_PD_FLAG (1<<5)
#define CS1000AUD_ANALOG_REG_CFG_RTC_HW_CHIP_PD_FLAG (1<<6)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LP_MODE_H_FLAG (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_RTC_RTC_BATTERY_FLAG (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_RTC_WDG_RST_FLAG (1<<9)
#define CS1000AUD_ANALOG_REG_CFG_RTC_PWR_KEY_LONG_FLAG_CLR (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SOFT_RST_FLAG_CLR (1<<17)
#define CS1000AUD_ANALOG_REG_CFG_RTC_POR_CHIP_PD_FLAG_CLR (1<<18)
#define CS1000AUD_ANALOG_REG_CFG_RTC_UVLO_CHIP_PD_FLAG_CLR (1<<19)
#define CS1000AUD_ANALOG_REG_CFG_RTC_HW_PWR_KEY_CHIP_PD_FLAG_CLR (1<<20)
#define CS1000AUD_ANALOG_REG_CFG_RTC_SW_CHIP_PD_FLAG_CLR (1<<21)
#define CS1000AUD_ANALOG_REG_CFG_RTC_HW_CHIP_PD_FLAG_CLR (1<<22)
#define CS1000AUD_ANALOG_REG_CFG_RTC_WDG_RST_FLAG_CLR (1<<23)
#define CS1000AUD_ANALOG_REG_CFG_RTC_POR_SRC_STS(n) (((n)&0xFF)<<24)

//other_ctrl_cfg3
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_NOR_DROP_EN (1<<0)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_NOR_STEP_EN (1<<1)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_NOR_STEP_VOL(n) (((n)&31)<<2)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_NOR_STEP_NUM(n) (((n)&15)<<7)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_NOR_STEP_DELAY(n) (((n)&3)<<11)
#define CS1000AUD_ANALOG_REG_CFG_RTC_DCDC_CORE_NOR_VOSEL_NOR_SW(n) (((n)&31)<<13)

//gpio_ctrl0
#define CS1000AUD_ANALOG_REG_CFG_ANA_GPIO_SLEW_RATE_A(n) (((n)&15)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_GPIO_SLEW_RATE_B(n) (((n)&15)<<4)
#define CS1000AUD_ANALOG_REG_CFG_ANA_GPIO_IBIT_A (1<<16)
#define CS1000AUD_ANALOG_REG_CFG_ANA_GPIO_IBIT_B (1<<17)

//gpio_ctrl1
#define CS1000AUD_ANALOG_REG_CFG_ANA_GPIO_IE(n) (((n)&0xFFFF)<<0)

//gpio_ctrl2
#define CS1000AUD_ANALOG_REG_CFG_ANA_GPIO_MUX0_EN(n) (((n)&0xFFFF)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_GPIO_MUX1_EN(n) (((n)&0xFFFF)<<16)

//test_en_ctrl
#define CS1000AUD_ANALOG_REG_CFG_ANA_TEST_BIT(n) (((n)&15)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TEST_EN_XTAL26M (1<<4)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TEST_EN_DCDC_PA (1<<5)
#define CS1000AUD_ANALOG_REG_CFG_ANA_TEST_EN_DCDC_CORE (1<<6)

//agpio_ctrl
#define CS1000AUD_ANALOG_REG_CFG_ANA_AGPIO_SLEW_RATE(n) (((n)&3)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_AGPIO_OEN_DLY(n) (((n)&3)<<2)
#define CS1000AUD_ANALOG_REG_CFG_ANA_AGPIO_IBIT (1<<4)
#define CS1000AUD_ANALOG_REG_CFG_ANA_AGPIO_HOLD (1<<5)

//ldo_vcore09_cfg
#define CS1000AUD_ANALOG_REG_CFG_ANA_LDO_VCORE09_LESS_SOFTTIME(n) (((n)&3)<<0)
#define CS1000AUD_ANALOG_REG_CFG_ANA_LDO_VCORE09_SOFT_ICLAMP (1<<2)
#define CS1000AUD_ANALOG_REG_CFG_ANA_LDO_VCORE09_EN_DISCHARGE (1<<3)
#define CS1000AUD_ANALOG_REG_CFG_ANA_LDO_VCORE09_IBIT_LIMIT(n) (((n)&7)<<4)
#define CS1000AUD_ANALOG_REG_CFG_ANA_LDO_VCORE09_EN_ILIMIT (1<<7)
#define CS1000AUD_ANALOG_REG_CFG_ANA_LDO_VCORE09_SOFTSTART (1<<8)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VCORE09_VOSEL_DS_SW(n) (((n)&31)<<9)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VCORE09_VOSEL_NOR_TUNE(n) (((n)&31)<<14)
#define CS1000AUD_ANALOG_REG_CFG_RTC_LDO_VCORE09_SLP_DROP_EN (1<<19)

#endif
