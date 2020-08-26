/*
 * Copyright (C) 2010 Texas Instruments
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 * ----------------------------------------------------------------------------
 *
 */

#ifndef _DDR_DEFS_TI810X_H
#define _DDR_DEFS_TI810X_H

#include <asm/arch/hardware.h>

/* DDR Phy MMRs OFFSETs */
#define CMD0_REG_PHY_CTRL_SLAVE_RATIO_0		0x01C
#define CMD0_REG_PHY_DLL_LOCK_DIFF_0		0x028
#define CMD0_REG_PHY_INVERT_CLKOUT_0		0x02C
#define CMD1_REG_PHY_CTRL_SLAVE_RATIO_0		0x050
#define CMD1_REG_PHY_DLL_LOCK_DIFF_0		0x05C
#define CMD1_REG_PHY_INVERT_CLKOUT_0		0x060
#define CMD2_REG_PHY_CTRL_SLAVE_RATIO_0		0x084
#define CMD2_REG_PHY_DLL_LOCK_DIFF_0		0x090
#define CMD2_REG_PHY_INVERT_CLKOUT_0		0x094

/* DDR0 Phy MMRs */
#define CMD0_REG_PHY0_CTRL_SLAVE_RATIO_0	(0x01C + DDR0_PHY_BASE_ADDR)
#define CMD0_REG_PHY0_DLL_LOCK_DIFF_0		(0x028 + DDR0_PHY_BASE_ADDR)
#define CMD0_REG_PHY0_INVERT_CLKOUT_0		(0x02C + DDR0_PHY_BASE_ADDR)
#define CMD1_REG_PHY0_CTRL_SLAVE_RATIO_0	(0x050 + DDR0_PHY_BASE_ADDR)
#define CMD1_REG_PHY0_DLL_LOCK_DIFF_0		(0x05C + DDR0_PHY_BASE_ADDR)
#define CMD1_REG_PHY0_INVERT_CLKOUT_0		(0x060 + DDR0_PHY_BASE_ADDR)
#define CMD2_REG_PHY0_CTRL_SLAVE_RATIO_0	(0x084 + DDR0_PHY_BASE_ADDR)
#define CMD2_REG_PHY0_DLL_LOCK_DIFF_0		(0x090 + DDR0_PHY_BASE_ADDR)
#define CMD2_REG_PHY0_INVERT_CLKOUT_0		(0x094 + DDR0_PHY_BASE_ADDR)

#define DATA0_REG_PHY0_RD_DQS_SLAVE_RATIO_0	(0x0C8 + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_WR_DQS_SLAVE_RATIO_0	(0x0DC + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_WRLVL_INIT_RATIO_0	(0x0F0 + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_WRLVL_INIT_MODE_0	(0x0F8 + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_GATELVL_INIT_RATIO_0	(0x0FC + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_GATELVL_INIT_MODE_0	(0x104 + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_FIFO_WE_SLAVE_RATIO_0	(0x108 + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_WR_DATA_SLAVE_RATIO_0	(0x120 + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_USE_RANK0_DELAYS		(0x134 + DDR0_PHY_BASE_ADDR)
#define DATA0_REG_PHY0_DLL_LOCK_DIFF_0		(0x138 + DDR0_PHY_BASE_ADDR)

#define DATA1_REG_PHY0_RD_DQS_SLAVE_RATIO_0	(0x16C + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_WR_DQS_SLAVE_RATIO_0	(0x180 + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_WRLVL_INIT_RATIO_0	(0x194 + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_WRLVL_INIT_MODE_0	(0x19C + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_GATELVL_INIT_RATIO_0	(0x1A0 + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_GATELVL_INIT_MODE_0	(0x1A8 + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_FIFO_WE_SLAVE_RATIO_0	(0x1AC + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_WR_DATA_SLAVE_RATIO_0	(0x1C4 + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_USE_RANK0_DELAYS		(0x1D8 + DDR0_PHY_BASE_ADDR)
#define DATA1_REG_PHY0_DLL_LOCK_DIFF_0		(0x1DC + DDR0_PHY_BASE_ADDR)

#define DATA2_REG_PHY0_RD_DQS_SLAVE_RATIO_0	(0x210 + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_WR_DQS_SLAVE_RATIO_0	(0x224 + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_WRLVL_INIT_RATIO_0	(0x238 + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_WRLVL_INIT_MODE_0	(0x240 + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_GATELVL_INIT_RATIO_0	(0x244 + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_GATELVL_INIT_MODE_0	(0x24C + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_FIFO_WE_SLAVE_RATIO_0	(0x250 + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_WR_DATA_SLAVE_RATIO_0	(0x268 + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_USE_RANK0_DELAYS		(0x27C + DDR0_PHY_BASE_ADDR)
#define DATA2_REG_PHY0_DLL_LOCK_DIFF_0		(0x280 + DDR0_PHY_BASE_ADDR)

#define DATA3_REG_PHY0_RD_DQS_SLAVE_RATIO_0	(0x2B4 + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_WR_DQS_SLAVE_RATIO_0	(0x2C8 + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_WRLVL_INIT_RATIO_0	(0x2DC + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_WRLVL_INIT_MODE_0	(0x2E4 + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_GATELVL_INIT_RATIO_0	(0x2E8 + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_GATELVL_INIT_MODE_0	(0x2F0 + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_FIFO_WE_SLAVE_RATIO_0	(0x2F4 + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_WR_DATA_SLAVE_RATIO_0	(0x30C + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_USE_RANK0_DELAYS		(0x320 + DDR0_PHY_BASE_ADDR)
#define DATA3_REG_PHY0_DLL_LOCK_DIFF_0		(0x324 + DDR0_PHY_BASE_ADDR)

#define DATA_MACRO_0		0
#define DATA_MACRO_1		1
#define DATA_MACRO_2		2
#define DATA_MACRO_3		3
#define DDR_PHY0			0
#define DDR_PHY1			1

/* Common DDR PHY parameters */
#define	PHY_INVERT_CLKOUT_DEFINE		0
#define	DDR3_PHY_INVERT_CLKOUT_OFF		0
#define	PHY_REG_USE_RANK0_DELAY_DEFINE		0
#define	mDDR_PHY_REG_USE_RANK0_DELAY_DEFINE	1
#define	PHY_DLL_LOCK_DIFF_DEFINE		0x4
#define	PHY_CMD0_DLL_LOCK_DIFF_DEFINE		0x4
#define DDR_EMIF_REF_TRIGGER			0x10000000

#define	PHY_GATELVL_INIT_CS0_DEFINE		0x0
#define	PHY_WRLVL_INIT_CS0_DEFINE		0x0

#define	PHY_GATELVL_INIT_CS1_DEFINE		0x0
#define	PHY_WRLVL_INIT_CS1_DEFINE		0x0
#define	PHY_CTRL_SLAVE_RATIO_CS1_DEFINE		0x80

/* TI813X DDR3 PHY CFG parameters   <emif0> */
#define DDR3_PHY_RD_DQS_CS0_BYTE0		0x3B
#define DDR3_PHY_RD_DQS_CS0_BYTE1		0x36
#define DDR3_PHY_RD_DQS_CS0_BYTE2		0x3D
#define DDR3_PHY_RD_DQS_CS0_BYTE3		0x3C

#define DDR3_PHY_WR_DQS_CS0_BYTE0		0x47
#define DDR3_PHY_WR_DQS_CS0_BYTE1		0x3E
#define DDR3_PHY_WR_DQS_CS0_BYTE2		0x52
#define DDR3_PHY_WR_DQS_CS0_BYTE3		0x50

#define DDR3_PHY_RD_DQS_GATE_CS0_BYTE0	0x90
#define DDR3_PHY_RD_DQS_GATE_CS0_BYTE1	0x97
#define DDR3_PHY_RD_DQS_GATE_CS0_BYTE2	0xa5
#define DDR3_PHY_RD_DQS_GATE_CS0_BYTE3	0xa3

#define DDR3_PHY_WR_DATA_CS0_BYTE0		0x82
#define DDR3_PHY_WR_DATA_CS0_BYTE1		0x82
#define DDR3_PHY_WR_DATA_CS0_BYTE2		0x84
#define DDR3_PHY_WR_DATA_CS0_BYTE3		0x84

#define DDR3_PHY_CTRL_SLAVE_RATIO_CS0_DEFINE	0x80

/* DDR0/1 IO CTRL parameters */
#define DDR0_IO_CTRL_DEFINE			0x00030303
#define DDR1_IO_CTRL_DEFINE			0x00030303

/* Initially set a large DDR refresh period */
#define DDR_EMIF_REF_CTRL			0x00004000
#define DDR3_EMIF_SDRAM_ZQCR		0x50074BE2

/* select the DDR3 Freq and timing paramets */
/* TI813X DDR3 EMIF CFG Registers values 400MHz */
#if defined(CONFIG_TI813X_DDR3_400)
#define DDR3_EMIF_READ_LATENCY		0x00170208		//RD_ODT=0x2, IDLE_ODT=0x0, Dynamic power_down enabled
#define DDR3_EMIF_TIM1				0x0AAAE523
#define DDR3_EMIF_TIM2				0x20437FDA
#define DDR3_EMIF_TIM3				0x507F83FF
#define DDR3_EMIF_REF_CTRL			0x00000C30
#define DDR3_EMIF_SDRAM_CONFIG		0x61C012B2
#endif

/* TI813X DDR3 EMIF CFG Registers values 533MHz */
#if defined(CONFIG_TI813X_DDR3_533)
#define DDR3_EMIF_READ_LATENCY     	0x00170209
#define DDR3_EMIF_TIM1          	0x0EEF36F3
#define DDR3_EMIF_TIM2          	0x305A7FDA
#define DDR3_EMIF_TIM3          	0x507F855F
#define DDR3_EMIF_REF_CTRL      	0x0000103D
#define DDR3_EMIF_SDRAM_CONFIG      0x61C11AB2
#endif

/*
 * TI813X  DM385 DMM LISA MAPPING
 * 1G contiguous section with no interleaving
 */
#define DDR3_DMM_LISA_MAP__0		0x0
#define DDR3_DMM_LISA_MAP__1		0x0
#define DDR3_DMM_LISA_MAP__2		0x0
#define DDR3_DMM_LISA_MAP__3		0x80600100

#endif  /* _DDR_DEFS_TI810X_H */
