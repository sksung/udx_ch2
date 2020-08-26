/******************************************************************************
 * UDX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 * In Huvitech: 143HD(PH3100K + No CDS(IR)), 290H(PH3100K + CDS(IR))
 *---------------------------------------------------------------------------*/
 /**
 * @file	vpsdrv_ph3100kI2c.c (MCLK27MHz)
 *          SERDES: (MAXIM) MAX9271 / MAX9272
 * @brief
 * @author	phoong
 * @section	MODIFY history
 *	   - 2012.01.01	: First	Created	based vpsdrv_tvp5158I2c.c
 * @revision history
 *     - 2014.01.02 : changes to pll_ms: W4102->W4101, W2508->W250A
 *     - 2014.10.04 : Turnel Enviroment update.
 *     - 2015.06.12 : For DTC (5, 7.5, 12.46, 15, 20, 25, 30fps Add, Flicker 50Hz)
 *     - 2015.08.29 : Apply D15 Setting(Huvitech 4CH DVR and Flicker 50Hz)
 *     - 2015.09.01 : Add 290H (IR Mode)
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#include <ti/psp/devices/ph3100k/src/vpsdrv_ph3100kPriv.h>
#include <ti/psp/platforms/vps_platform.h>
#include <ti/psp/cslr/soc_TI8107.h>

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define PH3100K_I2C_ID		2

#define PH3100K_I2C_ADDR	0x32
#define MAX9272_I2C_ADDR	0x48
#define MAX9271_I2C_ADDR	0x40

#define MAX_DEV_NUM			2

//# sensor dev command (using deviceNum)
#define DEV_PWR_OFF			0x10
#define DEV_R_STATE			0x20

#define WRITE_RETRY_CNT		3
#define PLL_DELAY			100		//# ms

#define SZ_720				0
#define SZ_480				1

#define FLICKER_50Hz		0
#define NIGHT_GAIN_DEF		(1)
#define NIGHT_GAIN_X20		(2)
#define NIGHT_GAIN_X22		(3)
#define NIGHT_GAIN_X24		(4)
#define NIGHT_GAIN_X26		(5)
#define NIGHT_GAIN_X28		(6)
#define NIGHT_GAIN_MAX		(7)

#define NIGHT_GAIN			(NIGHT_GAIN_DEF)

struct regval_list {
	unsigned char reg;	//# register address
	unsigned char val;	//# register value
};

typedef struct {
	char pwr;		//# camer module power
	char pdn;		//# diserialize pdn
	char led;		//# sensor module led - if initialization is successful, led on
	char lock;		//# diserialize lock, input
} gio_ctrl_t;

//# control gpio
static gio_ctrl_t gio[MAX_DEV_NUM] = {
	/* CAM_PWR   PDN        LED        LOCK */
	{ GIO(2,29), GIO(3,0), GIO(3,11), GIO(3,4)  },	//# VIN[0]B
	{ GIO(3,16), GIO(3,8), GIO(2,31), GIO(3,18) }	//# VIN[0]A
};

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static int d_init = 0;				//# deserialize init flag
static int s_init[MAX_DEV_NUM];		//# sensor init flag
static int s_size[MAX_DEV_NUM];		//# sensor image size
static int eq_lv[MAX_DEV_NUM];		//# serdes equalizer/preemphasis level

//# PH3100K (standard front) init data --------------------------------------------------------
static const struct regval_list ph3100k_init_reg_fs[] = {	//# front side
	 #if 0
	 //# pll init ---
	{0x03, 0x00}, //# A bank
	{0x25, 0x08}, //# ppclk 1/2 : 0xA (140102) => ppclk 1/1 : 0x08 (150623 - jaeki)
   	{0x41, 0x01}, //2->1(140102) //# pll_ms
   	{0x42, 0x0B}, //# pll_ns	//# 27M*(ns/ms) = 148.5M
   	{0x40, 0x3C},
   	{DELAY, PLL_DELAY},

	{0x40, 0x2C},
	{0x29, 0x08}, //# pad ctrl
   	{DELAY, 30},
   	#endif

   	//{0x03, 0x00}, // A bank
   	//{0x04, 0x02}, //# chip mode (00: smpte, x01: sampling, x02: Digital)
   	//{0x05, 0x03}, //# mirror
   	{0x06, 0x06}, //# framewidth_h
   	{0x07, 0x71}, //# framewidth_l
   	{0x08, 0x02}, //# fd_fheight_a_h
   	{0x09, 0xED}, //# fd_fheight_a_l
   	{0x0A, 0x02}, //# fd_fheight_b_h
   	{0x0B, 0xED}, //# fd_fheight_b_l
   	{0x0C, 0x00}, //# windowx1_h
   	{0x0D, 0x05}, //# windowx1_l
   	{0x0E, 0x00}, //# windowy1_h
   	{0x0F, 0x05}, //# windowy1_l
   	{0x10, 0x05}, //# windowx2_h
   	{0x11, 0x04}, //# windowx2_l
   	{0x12, 0x02}, //# windowy2_h
   	{0x13, 0xD4}, //# windowy2_l
   	{0x14, 0x00}, //# vsyncstartrow_f0_h
   	{0x15, 0x16}, //# vsyncstartrow_f0_l	*15
   	{0x16, 0x02}, //# vsyncstoprow_f0_h
   	{0x17, 0xEB}, //# vsyncstoprow_f0_l		*E9
   	{0xD3, 0x80}, //# ???

/* ############# Start Settings ################ */
   	/*
   	 * pad_drv[7:6]
   	 * pclk_drv[5:4]
   	 * pclk_delay[3:0]
   	 */
   	{0x28, 0xF0}, //# pad_control2 //0xF4
   	{0x33, 0x02}, //# pixelbias
   	{0x34, 0x01}, //# compbias
	{0x36, 0x80}, //# tx_bais, recommended by design 1
	{0x38, 0x58}, //# black_bias '011', rangesel "000", recommended by design 1

   	{0x03, 0x01}, //# B bank
   	{0x1E, 0x0E}, //# bsmode '0'
   	{0x26, 0x03}, //# blacksunth_h

/* ############# BLACK ################ */
   	{0xB1, 0x30}, //# adc offset	*0x28
   	{0x03, 0x04}, //# E bank
   	{0x06, 0x98}, //# front_black_fitting[4], ycont/ybright[3], adcoffset_fitting[2]

   	{0x03, 0x01}, //# B bank
   	{0xA4, 0x00}, //# front_black_ref0		*88
	{0xA5, 0x00}, //# front_black_ref1
    {0xA6, 0x00}, //# front_black_ref2
    {0xA7, 0x00}, //# front_black_ref3
    {0xA8, 0x00}, //# front_black_ref4
    {0xA9, 0x08}, //# front_black_ref5
/* ############# AWB ################ */
    /* AWB gain control */
    {0x03, 0x04}, //# E bank
    {0x06, 0xB8}, //# auto_control_3 enable
	/* AWB gain control */
	{0x75, 0x28}, //# awb_rgain_min1 LOW TEMP
	{0x76, 0x28}, //# awb_rgain_min2
	{0x77, 0x78}, //# awb_rgain_max1 HIGH TEMP
	{0x78, 0x78}, //# awb_rgain_max2
	{0x79, 0x48}, //# awb_bgain_min1 HIGH TEMP	*38
	{0x7A, 0x48}, //# awb_bgain_min2			*38
	{0x7B, 0xB8}, //# awb_bgain_max1 LOW TEMP	*80
	{0x7C, 0xB8}, //# awb_bgain_max2			*80
	{0x7D, 0x01},
	{0x7E, 0x00},
	{0x7F, 0x02},
	{0x80, 0x07},
	{0x73, 0x08}, //08->0C(140102) //# AWB lock range	*0c
	{0x74, 0x04}, //04->08(140102) //# AWB speed		*08
	/* Set AWB Sampling Boundary */
	{0x51, 0x10},
	{0x52, 0xE0},
	{0x53, 0x02},
	{0x54, 0x02},
	{0x55, 0x40},
	{0x56, 0xC0},
	{0x57, 0x04},
	{0x58, 0x6E},
	{0x59, 0x45},
	{0x5A, 0x23}, //# awb_rmin1 LOW TEMP white point	*26
	{0x5B, 0x4B}, //# awb_rmax1 HIGH TEMP				*47
	{0x5C, 0x64}, //# awb_bmin1 HIGH TMEP				*70
	{0x5D, 0xAA}, //# awb_bmax1 LOW TEMP				*af
	{0x5E, 0x23}, //#									*14
	{0x5F, 0x28}, //#									*1c
	{0x60, 0x4B}, //# awb_rmin2 white point				*47
	{0x61, 0x73}, //# awb_rmax2							*62
	{0x62, 0x3C}, //# awb_bmin2							*3a
	{0x63, 0x87}, //# awb_bmax2							*8e
	{0x64, 0x2D}, //# 									*1e
	{0x65, 0x2D}, //# 									*14
	/* awb rg/bg ratio axis */
	{0x6E, 0x3A}, //# 									*2f
	{0x6F, 0x50}, //# 									*58
	{0x70, 0x60}, //# 									*5e
	/* lens / cs axis */
	{0x03, 0x03},
	{0x16, 0x3A}, //# 									*2f
	{0x17, 0x50}, //# 									*58
	{0x18, 0x60}, //# 									*5e
	{0x19, 0x1C}, //# user CS gain
/* ############# AE ################ */
	{0x03, 0x04}, //# E bank
	{0x05, 0x64}, //# AE on
	{0x30, 0x08}, //# 63 AE weight left up
	{0x31, 0x08}, //# AE weight right up
	{0x32, 0x08}, //# AE weight left down
	{0x33, 0x08}, //# AE weight right up
	{0x34, 0x08}, //# AE weight center
	{0x3B, 0xA0}, //# 70 #max_yt1 y target				*70
	{0x3C, 0x70}, //# 70 #max_yt2						*60
	{0x3D, 0x70}, //# 70 #min_yt1						*70
	{0x3E, 0x50}, //# 70 #min_yt2						*60
	{0x3F, 0x24}, //# 									*08
	{0x40, 0x4B}, //# 									*10
	/* Auto exposure control */
	{0x12, 0x02},
	{0x13, 0xE8},
	{0x14, 0x02},
	{0x15, 0xE8},
	{0x16, 0x02},
	{0x17, 0xE8},
	{0x1B, 0x00},

#if (NIGHT_GAIN == NIGHT_GAIN_X20)
	{0x1C, 0x3A}, //# +5D0
	{0x1D, 0x20}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_X22)
	{0x1C, 0x3F}, //# +5D0
	{0x1D, 0xF0}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_X24)
	{0x1C, 0x45}, //# +5D0
	{0x1D, 0xC0}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_X26)
	{0x1C, 0x4B}, //# +5D0
	{0x1D, 0x90}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_X28)
	{0x1C, 0x51}, //# +5D0
	{0x1D, 0x60}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_MAX)
	{0x1C, 0x5D}, //# +5D0
	{0x1D, 0x00}, //# +5D0
#else			//# NIGHT_GAIN_DEF
	{0x1C, 0x1C}, //# midexp_h 2F X8 11 #x6 17 #0B #low light	38	*17
	{0x1D, 0x30}, //# midexp_m 70 #40 #C0 #low light				*50
#endif
	{0x1E, 0x00}, //# maxexp_t

#if (NIGHT_GAIN == NIGHT_GAIN_X20)
	{0x1F, 0x3A}, //# maxexp_h 11 #17 #0B #low light	38			*17
	{0x20, 0x20}, //# maxexp_m 70 #40 #C0 #low light				*50
#elif (NIGHT_GAIN == NIGHT_GAIN_X22)
	{0x1F, 0x3F}, //# +5D0
	{0x20, 0xF0}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_X24)
	{0x1F, 0x45}, //# +5D0
	{0x20, 0xC0}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_X26)
	{0x1F, 0x4B}, //# +5D0
	{0x20, 0x90}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_X28)
	{0x1F, 0x51}, //# +5D0
	{0x20, 0x60}, //# +5D0
#elif (NIGHT_GAIN == NIGHT_GAIN_MAX)
	{0x1F, 0x5D}, //# +5D0
	{0x20, 0x00}, //# +5D0
#else			//# NIGHT_GAIN_DEF
	{0x1F, 0x1C}, //# maxexp_h 11 #17 #0B #low light	38			*17
	{0x20, 0x30}, //# maxexp_m 70 #40 #C0 #low light				*50
#endif
	/* Auto exposure option */
	{0x48, 0x08}, //04->08(140102) //# AE Speed
	{0x49, 0x08}, //04->08(140102)
	{0x4A, 0x08}, //08->0E(140102)						*0E
	/* saturation level th */
	{0x2C, 0x66}, //# 66 Saturation decision TH			*bb
	/* saturation ratio fitting */
	{0x41, 0x04},
	{0x42, 0x08},
	{0x43, 0x10},
	{0x44, 0x20},
	{0x2E, 0x04}, //# 05 Saturation ratio
#if FLICKER_50Hz
	/* Flicker canceling mode - manual 50hz */
	{0x03, 0x00}, //# A bank
	{0x4F, 0x04},
	{0x59, 0x00},
	{0x5A, 0xBA}, //# BB
	{0x5B, 0x00}, //# 80
	{0x5C, 0x00},
	{0x5D, 0xE1},
	{0x5E, 0x00},
#else
	/* Flicker canceling mode - manual 60hz */
	{0x03, 0x00}, //# A bank
	{0x4F, 0x08},
	{0x59, 0x00},
	{0x5A, 0xBA}, //# BB
	{0x5B, 0x00}, //# 80
#endif
/* ############### Data range ################ */
	{0x03, 0x02}, //# C bank
	{0x09, 0x40}, //# Yrange selection BIT[6]0 b: 0~255 (reference 8bit output), 1b : 16~235 (reference 8bit output)
	{0x9B, 0x02},
/* ############### COLOR ################ */
	/* Color correction */
	{0x33, 0x37},
	{0x34, 0x90},
	{0x35, 0x87},
	{0x36, 0x8E},
	{0x37, 0x3B},
	{0x38, 0x8C},
	{0x39, 0x82},
	{0x3A, 0x98},
	{0x3B, 0x3A},
	/* Color saturation */
	{0x03, 0x03}, //# D bank
	{0x0C, 0x25}, //# Color saturation matrix fitting reference
	{0x0D, 0x88},
	{0x0E, 0x00},
	{0x0F, 0x25},

	{0x6D, 0x7F},
	{0x6E, 0x0E},
	{0x6F, 0x0E},
	{0x71, 0x7F},
	{0x72, 0x22},
	{0x73, 0x10},
	{0xA1, 0x40},
	{0xA2, 0x7F},
	{0xA3, 0x7F},

/* ############### GAMMA ################ */
	{0x03, 0x02}, //# C bank
	{0x95, 0x00}, //#
	{0x96, 0x00}, //#
	{0x97, 0x10}, //#

	/* gamma curve fitting */
	{0x3D, 0x00}, //# *00
	{0x3E, 0x03}, //# *03
	{0x3F, 0x0C}, //# *0C
	{0x40, 0x19}, //# *18
	{0x41, 0x26}, //# *22
	{0x42, 0x3F}, //# *34
	{0x43, 0x52}, //# *43
	{0x44, 0x6E}, //# *5A
	{0x45, 0x82}, //# *6D
	{0x46, 0xA1}, //# *8D
	{0x47, 0xB9}, //# *A8
	{0x48, 0xCE}, //# *C0
	{0x49, 0xE0}, //# *D7
	{0x4A, 0xF0}, //# *EC
	{0x4B, 0xFF}, //# *FF
	/* gamma curve fitting */
	{0x4C, 0x00}, //# 00 *00
	{0x4D, 0x12}, //# 0B *0F
	{0x4E, 0x28}, //# 17 *26
	{0x4F, 0x40}, //# 22 *37
	{0x50, 0x5C}, //# 2E *43
	{0x51, 0x7D}, //# 40 *54
	{0x52, 0x9B}, //# 50 *62
	{0x53, 0xB4}, //# 6E *77
	{0x54, 0xC8}, //# 88 *88
	{0x55, 0xD7}, //# AE *A4
	{0x56, 0xE4}, //# CA *BB
	{0x57, 0xEE}, //# DC *CF
	{0x58, 0xF6}, //# EC *E0
	{0x59, 0xFB}, //# F6 *F1
	{0x5A, 0xFF}, //# FF *FF
	/* gamma curve fitting (0.75) */
	{0x5B, 0x00}, //# *00
	{0x5C, 0x03}, //# *0B
	{0x5D, 0x0C}, //# *13
	{0x5E, 0x19}, //# *1A
	{0x5F, 0x26}, //# *20
	{0x60, 0x3F}, //# *2B
	{0x61, 0x52}, //# *36
	{0x62, 0x6E}, //# *49
	{0x63, 0x82}, //# *5A
	{0x64, 0xA1}, //# *7B
	{0x65, 0xB9}, //# *98
	{0x66, 0xCE}, //# *B4
	{0x67, 0xE0}, //# *CE
	{0x68, 0xF0}, //# *E7
	{0x69, 0xFF}, //# *FF
	/* gamma curve fitting (0.75) */
	{0x6A, 0x00}, //# 00 *00
	{0x6B, 0x12}, //# 0B *0B
	{0x6C, 0x28}, //# 17 *13
	{0x6D, 0x40}, //# 22 *1A
	{0x6E, 0x5C}, //# 2E *20
	{0x6F, 0x7D}, //# 40 *2B
	{0x70, 0x9B}, //# 50 *36
	{0x71, 0xB4}, //# 6E *49
	{0x72, 0xC8}, //# 88 *5A
	{0x73, 0xD7}, //# AE *7B
	{0x74, 0xE4}, //# CA *98
	{0x75, 0xEE}, //# DC *B4
	{0x76, 0xF6}, //# EC *CE
	{0x77, 0xFB}, //# F6 *E7
	{0x78, 0xFF}, //# FF *FF
	/* Y weight control */
	{0x8D, 0x30},
/* ############### EDGE ################ */
	/* sharpness control */
	{0x2F, 0x28}, //# 10 #Edge gain						*20
	{0x30, 0x20}, //# Positive max edge clamp gain		*30
	{0x31, 0x60}, //# Negative max edge clamp gain		*30
/* ############### DARK ################ */
	{0x03, 0x04}, //# E bank
	{0x09, 0x00}, //# 01->00
	/* dark_dpc_p */
	{0x03, 0x03}, //# C bank
	{0x26, 0x00},
	{0x27, 0x10}, //# *00
	{0x28, 0x40}, //# *00
	/* dark_blf */
	{0x2E, 0x7F},
	{0x2F, 0x7F},
	{0x30, 0x7F},
	/* dark_nf */
	{0x32, 0x00},
	{0x33, 0x00},
	{0x34, 0x00},
	{0x77, 0x00}, //# dark_dc
	{0x78, 0x00},
	{0x79, 0x00},
	/* dark_e_blf */
	{0xA1, 0x40}, //# *40
	{0xA2, 0x20}, //# *7F
	{0xA3, 0x20}, //# *7F
	/* Darkness X reference */
	{0x03, 0x04}, //# E bank
	{0x82, 0x0A}, //# *03
	{0x83, 0x10}, //# *05
	{0x84, 0x28}, //# *07

	{0x03, 0x03}, //# D bank
	{0x2A, 0x00},
	{0x2B, 0x00},
	{0x2C, 0x00},
	/* lens scale */
	{0x03, 0x02}, //# C bank
	{0x0D, 0x0A},
	{0x0E, 0x0A},
	{0x0F, 0x0A},
	{0x10, 0x0A},
	{0x11, 0x0A},
	{0x12, 0x0A},
	{0x13, 0x0A},
	{0x14, 0x0A},
	{0x15, 0x0A},
	{0x16, 0x0A},
	{0x17, 0x0A},
	{0x18, 0x0A},
	{0x19, 0x0A},
	{0x1A, 0x0A},
	{0x1B, 0x0A},
	{0x1C, 0x0A},
	/* awb rg/bg ratio fitting */
	{0x03, 0x04}, //# E bank
	{0x68, 0x81},
	{0x69, 0x7F},
	{0x6A, 0x81},
	{0x6B, 0x7F},
	{0x6C, 0x82},
	{0x6D, 0x80},
	/* lens gain fitting */
	{0x03, 0x02}, //# C bank
	{0x1E, 0x80},
	{0x1F, 0x80},

	{0x03, 0x03}, //# D bank
	{0x10, 0xC0},
	{0x11, 0x84},
	{0x12, 0xC0},
	{0x13, 0x68},
	{0x14, 0xC8},
	{0x15, 0x68},

	//# 2017.10.18 lens shading
	//#enable lens/cs fitting
	{0x03, 0x04},
	{0x05, 0x64},
	//#lens gain fitting
	{0x03, 0x02},
	{0x1E, 0x02},
	{0x1F, 0x02},

	{0x03, 0x03},

	{0x10, 0x03},
	{0x11, 0x00},
	{0x12, 0x03},
	{0x13, 0x00},
	{0x14, 0x04},
	{0x15, 0x00},
	//# end of lens shading

	{0x03, 0x02}, //# C bank
	{0x8B, 0x00}, //# ???

	{0x03, 0x00},
	{0x05, 0x03}, //# mirror H
	//{DELAY, 30},
	{TERM, 0xff}
};

static const struct regval_list ph3100k_init_reg_rs[] = {	//# rear side
	#if 0
	 //# pll init ---
	{0x03, 0x00}, //# A bank
	{0x25, 0x08}, //# ppclk 1/2 : 0xA (140102) => ppclk 1/1 : 0x08 (150623 - jaeki)
   	{0x41, 0x01}, //2->1(140102) //# pll_ms
   	{0x42, 0x0B}, //# pll_ns	//# 27M*(ns/ms) = 148.5M
   	{0x40, 0x3C},
   	{DELAY, PLL_DELAY},

	{0x40, 0x2C},
	{0x29, 0x08}, //# pad ctrl
   	{DELAY, 30},
   	#endif

   	//{0x03, 0x00}, // A bank
   	//{0x04, 0x02},
   	//{0x05, 0x03},
   	{0x06, 0x06}, //# framewidth_h
   	{0x07, 0x71}, //# framewidth_l
   	{0x08, 0x02}, //# fd_fheight_a_h
   	{0x09, 0xED}, //# fd_fheight_a_l
   	{0x0A, 0x02}, //# fd_fheight_b_h
   	{0x0B, 0xED}, //# fd_fheight_b_l
   	{0x0C, 0x00}, //# windowx1_h
   	{0x0D, 0x05}, //# windowx1_l
   	{0x0E, 0x00}, //# windowy1_h
   	{0x0F, 0x05}, //# windowy1_l
   	{0x10, 0x05}, //# windowx2_h
   	{0x11, 0x04}, //# windowx2_l
   	{0x12, 0x02}, //# windowy2_h
   	{0x13, 0xD4}, //# windowy2_l
   	{0x14, 0x00}, //# vsyncstartrow_f0_h
   	{0x15, 0x16}, //# vsyncstartrow_f0_l	*15
   	{0x16, 0x02}, //# vsyncstoprow_f0_h
   	{0x17, 0xEB}, //# vsyncstoprow_f0_l		*E9
   	{0xD3, 0x80}, //# ???

/* ############# Start Settings ################ */
   	{0x28, 0xF0}, //# pad_control2 //0xF4
   	{0x33, 0x02}, //# pixelbias
   	{0x34, 0x01}, //# compbias
	{0x36, 0x80}, //# tx_bais, recommended by design 1
	{0x38, 0x58}, //# black_bias '011', rangesel "000", recommended by design 1

   	{0x03, 0x01}, //# B bank
   	{0x1E, 0x0E}, //# bsmode '0'
   	{0x26, 0x03}, //# blacksunth_h

/* ############# BLACK ################ */
   	{0xB1, 0x30}, //# adc offset	*0x28
   	{0x03, 0x04}, //# E bank
   	{0x06, 0x98}, //# front_black_fitting[4], ycont/ybright[3], adcoffset_fitting[2]

   	{0x03, 0x01}, //# B bank
   	{0xA4, 0x00}, //# front_black_ref0		*88
	{0xA5, 0x00}, //# front_black_ref1
    {0xA6, 0x00}, //# front_black_ref2
    {0xA7, 0x00}, //# front_black_ref3
    {0xA8, 0x00}, //# front_black_ref4
    {0xA9, 0x08}, //# front_black_ref5
/* ############# AWB ################ */
    /* AWB gain control */
    {0x03, 0x04}, //# E bank
    {0x06, 0xB8}, //# auto_control_3 enable
	/* AWB gain control */
	{0x75, 0x28}, //# awb_rgain_min1 LOW TEMP
	{0x76, 0x28}, //# awb_rgain_min2
	{0x77, 0x78}, //# awb_rgain_max1 HIGH TEMP
	{0x78, 0x78}, //# awb_rgain_max2
	{0x79, 0x48}, //# awb_bgain_min1 HIGH TEMP	*38
	{0x7A, 0x48}, //# awb_bgain_min2			*38
	{0x7B, 0xB8}, //# awb_bgain_max1 LOW TEMP	*80
	{0x7C, 0xB8}, //# awb_bgain_max2			*80
	{0x7D, 0x01},
	{0x7E, 0x00},
	{0x7F, 0x02},
	{0x80, 0x07},
	{0x73, 0x08}, //08->0C(140102) //# AWB lock range	*0c
	{0x74, 0x04}, //04->08(140102) //# AWB speed		*08
	/* Set AWB Sampling Boundary */
	{0x51, 0x10},
	{0x52, 0xE0},
	{0x53, 0x02},
	{0x54, 0x02},
	{0x55, 0x40},
	{0x56, 0xC0},
	{0x57, 0x04},
	{0x58, 0x6E},
	{0x59, 0x45},
	{0x5A, 0x23}, //# awb_rmin1 LOW TEMP white point	*26
	{0x5B, 0x4B}, //# awb_rmax1 HIGH TEMP				*47
	{0x5C, 0x64}, //# awb_bmin1 HIGH TMEP				*70
	{0x5D, 0xAA}, //# awb_bmax1 LOW TEMP				*af
	{0x5E, 0x23}, //#									*14
	{0x5F, 0x28}, //#									*1c
	{0x60, 0x4B}, //# awb_rmin2 white point				*47
	{0x61, 0x73}, //# awb_rmax2							*62
	{0x62, 0x3C}, //# awb_bmin2							*3a
	{0x63, 0x87}, //# awb_bmax2							*8e
	{0x64, 0x2D}, //# 									*1e
	{0x65, 0x2D}, //# 									*14
	/* awb rg/bg ratio axis */
	{0x6E, 0x3A}, //# 									*2f
	{0x6F, 0x50}, //# 									*58
	{0x70, 0x60}, //# 									*5e
	/* lens / cs axis */
	{0x03, 0x03},
	{0x16, 0x3A}, //# 									*2f
	{0x17, 0x50}, //# 									*58
	{0x18, 0x60}, //# 									*5e
	{0x19, 0x1C}, //# user CS gain
/* ############# AE ################ */
	{0x03, 0x04}, //# E bank
	{0x05, 0x64}, //# AE on
	{0x30, 0x08}, //# 63 AE weight left up
	{0x31, 0x08}, //# AE weight right up
	{0x32, 0x08}, //# AE weight left down
	{0x33, 0x08}, //# AE weight right up
	{0x34, 0x08}, //# AE weight center
	{0x3B, 0xA0}, //# 70 #max_yt1 y target				*70
	{0x3C, 0x70}, //# 70 #max_yt2						*60
	{0x3D, 0x70}, //# 70 #min_yt1						*70
	{0x3E, 0x50}, //# 70 #min_yt2						*60
	{0x3F, 0x24}, //# 									*08
	{0x40, 0x4B}, //# 									*10
	/* Auto exposure control */
	{0x12, 0x02},
	{0x13, 0xE8},
	{0x14, 0x02},
	{0x15, 0xE8},
	{0x16, 0x02},
	{0x17, 0xE8},
	{0x1B, 0x00},
#if NIGHT_GAIN_X20
	{0x1C, 0x3A}, //#2F X8 11 #x6 17 #0B #low light	38	*17
	{0x1D, 0x20}, //# 70 #40 #C0 #low light				*50
#else
	{0x1C, 0x1C}, //#2F X8 11 #x6 17 #0B #low light	38	*17
	{0x1D, 0x30}, //# 70 #40 #C0 #low light				*50
#endif
	{0x1E, 0x00},
#if NIGHT_GAIN_X20
	{0x1F, 0x3A}, //# 11 #17 #0B #low light	38			*17
	{0x20, 0x20}, //# 70 #40 #C0 #low light				*50
#else
	{0x1F, 0x1C}, //# 11 #17 #0B #low light	38			*17
	{0x20, 0x30}, //# 70 #40 #C0 #low light				*50
#endif
	/* Auto exposure option */
	{0x48, 0x08}, //04->08(140102) //# AE Speed
	{0x49, 0x08}, //04->08(140102)
	{0x4A, 0x08}, //08->0E(140102)						*0E
	/* saturation level th */
	{0x2C, 0x66}, //# 66 Saturation decision TH			*bb
	/* saturation ratio fitting */
	{0x41, 0x04},
	{0x42, 0x08},
	{0x43, 0x10},
	{0x44, 0x20},
	{0x2E, 0x04}, //# 05 Saturation ratio
#if FLICKER_50Hz
	/* Flicker canceling mode - manual 50hz */
	{0x03, 0x00}, //# A bank
	{0x4F, 0x04},
	{0x59, 0x00},
	{0x5A, 0xBA}, //# BB
	{0x5B, 0x00}, //# 80
	{0x5C, 0x00},
	{0x5D, 0xE1},
	{0x5E, 0x00},
#else
	/* Flicker canceling mode - manual 60hz */
	{0x03, 0x00}, //# A bank
	{0x4F, 0x08},
	{0x59, 0x00},
	{0x5A, 0xBA}, //# BB
	{0x5B, 0x00}, //# 80
#endif
/* ############### Data range ################ */
	{0x03, 0x02}, //# C bank
	{0x09, 0x40}, //# Yrange selection BIT[6]0 b: 0~255 (reference 8bit output), 1b : 16~235 (reference 8bit output)
	{0x9B, 0x02},
/* ############### COLOR ################ */
	/* Color correction */
	{0x33, 0x37},
	{0x34, 0x90},
	{0x35, 0x87},
	{0x36, 0x8E},
	{0x37, 0x3B},
	{0x38, 0x8C},
	{0x39, 0x82},
	{0x3A, 0x98},
	{0x3B, 0x3A},
	/* Color saturation */
	{0x03, 0x03}, //# D bank
	{0x0C, 0x25}, //# Color saturation matrix fitting reference
	{0x0D, 0x88},
	{0x0E, 0x00},
	{0x0F, 0x25},

	{0x6D, 0x7F},
	{0x6E, 0x0E},
	{0x6F, 0x0E},
	{0x71, 0x7F},
	{0x72, 0x22},
	{0x73, 0x10},
	{0xA1, 0x40},
	{0xA2, 0x7F},
	{0xA3, 0x7F},

/* ############### GAMMA ################ */
	{0x03, 0x02}, //# C bank
	{0x95, 0x00}, //#
	{0x96, 0x00}, //#
	{0x97, 0x10}, //#

	/* gamma curve fitting */
	{0x3D, 0x00}, //# *00
	{0x3E, 0x03}, //# *03
	{0x3F, 0x0C}, //# *0C
	{0x40, 0x19}, //# *18
	{0x41, 0x26}, //# *22
	{0x42, 0x3F}, //# *34
	{0x43, 0x52}, //# *43
	{0x44, 0x6E}, //# *5A
	{0x45, 0x82}, //# *6D
	{0x46, 0xA1}, //# *8D
	{0x47, 0xB9}, //# *A8
	{0x48, 0xCE}, //# *C0
	{0x49, 0xE0}, //# *D7
	{0x4A, 0xF0}, //# *EC
	{0x4B, 0xFF}, //# *FF
	/* gamma curve fitting */
	{0x4C, 0x0 }, //# 00 *00
	{0x4D, 0x12}, //# 0B *0F
	{0x4E, 0x28}, //# 17 *26
	{0x4F, 0x40}, //# 22 *37
	{0x50, 0x5C}, //# 2E *43
	{0x51, 0x7D}, //# 40 *54
	{0x52, 0x9B}, //# 50 *62
	{0x53, 0xB4}, //# 6E *77
	{0x54, 0xC8}, //# 88 *88
	{0x55, 0xD7}, //# AE *A4
	{0x56, 0xE4}, //# CA *BB
	{0x57, 0xEE}, //# DC *CF
	{0x58, 0xF6}, //# EC *E0
	{0x59, 0xFB}, //# F6 *F1
	{0x5A, 0xFF}, //# FF *FF
	/* gamma curve fitting (0.75) */
	{0x5B, 0x00}, //# *00
	{0x5C, 0x03}, //# *0B
	{0x5D, 0x0C}, //# *13
	{0x5E, 0x19}, //# *1A
	{0x5F, 0x26}, //# *20
	{0x60, 0x3F}, //# *2B
	{0x61, 0x52}, //# *36
	{0x62, 0x6E}, //# *49
	{0x63, 0x82}, //# *5A
	{0x64, 0xA1}, //# *7B
	{0x65, 0xB9}, //# *98
	{0x66, 0xCE}, //# *B4
	{0x67, 0xE0}, //# *CE
	{0x68, 0xF0}, //# *E7
	{0x69, 0xFF}, //# *FF
	/* gamma curve fitting (0.75) */
	{0x6A, 0x0 }, //# 00 *00
	{0x6B, 0x12}, //# 0C *0B
	{0x6C, 0x28}, //# 19 *13
	{0x6D, 0x40}, //# 27 *1A
	{0x6E, 0x5C}, //# 34 *20
	{0x6F, 0x7D}, //# 4B *2B
	{0x70, 0x9B}, //# 5C *36
	{0x71, 0xB4}, //# 74 *49
	{0x72, 0xC8}, //# 86 *5A
	{0x73, 0xD7}, //# A4 *7B
	{0x74, 0xE4}, //# B4 *98
	{0x75, 0xEE}, //# CE *B4
	{0x76, 0xF6}, //# E0 *CE
	{0x77, 0xFB}, //# F1 *E7
	{0x78, 0xFF}, //# FF *FF
	/* Y weight control */
	{0x8D, 0x30},
/* ############### EDGE ################ */
	/* sharpness control */
	{0x2F, 0x28}, //# 10 #Edge gain						*20
	{0x30, 0x20}, //# Positive max edge clamp gain		*30
	{0x31, 0x60}, //# Negative max edge clamp gain		*30
/* ############### DARK ################ */
	{0x03, 0x04}, //# E bank
	{0x09, 0x00}, //# 01->00
	/* dark_dpc_p */
	{0x03, 0x03}, //# C bank
	{0x26, 0x00},
	{0x27, 0x10}, //# *00
	{0x28, 0x40}, //# *00
	/* dark_blf */
	{0x2E, 0x7F},
	{0x2F, 0x7F},
	{0x30, 0x7F},
	/* dark_nf */
	{0x32, 0x00},
	{0x33, 0x00},
	{0x34, 0x00},
	{0x77, 0x00}, //# dark_dc
	{0x78, 0x00},
	{0x79, 0x00},
	/* dark_e_blf */
	{0xA1, 0x40}, //# *40
	{0xA2, 0x20}, //# *7F
	{0xA3, 0x20}, //# *7F
	/* Darkness X reference */
	{0x03, 0x04}, //# E bank
	{0x82, 0x0A}, //# *03
	{0x83, 0x10}, //# *05
	{0x84, 0x28}, //# *07

	{0x03, 0x03}, //# D bank
	{0x2A, 0x00},
	{0x2B, 0x00},
	{0x2C, 0x00},
	/* lens scale */
	{0x03, 0x02}, //# C bank
	{0x0D, 0x0A},
	{0x0E, 0x0A},
	{0x0F, 0x0A},
	{0x10, 0x0A},
	{0x11, 0x0A},
	{0x12, 0x0A},
	{0x13, 0x0A},
	{0x14, 0x0A},
	{0x15, 0x0A},
	{0x16, 0x0A},
	{0x17, 0x0A},
	{0x18, 0x0A},
	{0x19, 0x0A},
	{0x1A, 0x0A},
	{0x1B, 0x0A},
	{0x1C, 0x0A},
	/* awb rg/bg ratio fitting */
	{0x03, 0x04}, //# E bank
	{0x68, 0x81},
	{0x69, 0x7F},
	{0x6A, 0x81},
	{0x6B, 0x7F},
	{0x6C, 0x82},
	{0x6D, 0x80},
	/* lens gain fitting */
	{0x03, 0x02}, //# C bank
	{0x1E, 0x80},
	{0x1F, 0x80},

	{0x03, 0x03}, //# D bank
	{0x10, 0xC0},
	{0x11, 0x84},
	{0x12, 0xC0},
	{0x13, 0x68},
	{0x14, 0xC8},
	{0x15, 0x68},

	//# 2017.10.18 lens shading
	//#enable lens/cs fitting
	{0x03, 0x04},
	{0x05, 0x64},
	//#lens gain fitting
	{0x03, 0x02},
	{0x1E, 0x02},
	{0x1F, 0x02},

	{0x03, 0x03},

	{0x10, 0x03},
	{0x11, 0x00},
	{0x12, 0x03},
	{0x13, 0x00},
	{0x14, 0x04},
	{0x15, 0x00},
	//# end of lens shading

	{0x03, 0x02}, //# C bank
	{0x8B, 0x00}, //# ???

	{0x03, 0x00},
	{0x05, 0x03}, //# mirror H

	{TERM, 0xff}
};

//# ----------------------------------- PH3100K + CDS (IR) Setting -------------------------------
static const struct regval_list ph3100k_ir_init_reg_fs[] = { //# IR front side
	 #if 0
	 //# pll init ---
	{0x03, 0x00}, //# A bank
	{0x25, 0x08}, //# ppclk 1/2 : 0xA (140102) => ppclk 1/1 : 0x08 (150623 - jaeki)
   	{0x41, 0x01}, //2->1(140102) //# pll_ms
   	{0x42, 0x0B}, //# pll_ns	//# 27M*(ns/ms) = 148.5M
   	{0x40, 0x3C},
   	{DELAY, PLL_DELAY},

	{0x40, 0x2C},
	{0x29, 0x08}, //# pad ctrl
   	{DELAY, 30},
   	#endif

   	//{0x03, 0x00}, // A bank
   	//{0x04, 0x02}, //# chip mode (00: smpte, x01: sampling, x02: Digital)
   	//{0x05, 0x03}, //# mirror
   	{0x06, 0x06}, //# framewidth_h
   	{0x07, 0x71}, //# framewidth_l
   	{0x08, 0x02}, //# fd_fheight_a_h
   	{0x09, 0xED}, //# fd_fheight_a_l
   	{0x0A, 0x02}, //# fd_fheight_b_h
   	{0x0B, 0xED}, //# fd_fheight_b_l
   	{0x0C, 0x00}, //# windowx1_h
   	{0x0D, 0x05}, //# windowx1_l
   	{0x0E, 0x00}, //# windowy1_h
   	{0x0F, 0x05}, //# windowy1_l
   	{0x10, 0x05}, //# windowx2_h
   	{0x11, 0x04}, //# windowx2_l
   	{0x12, 0x02}, //# windowy2_h
   	{0x13, 0xD4}, //# windowy2_l
   	{0x14, 0x00}, //# vsyncstartrow_f0_h
   	{0x15, 0x16}, //# vsyncstartrow_f0_l	*15
   	{0x16, 0x02}, //# vsyncstoprow_f0_h
   	{0x17, 0xEB}, //# vsyncstoprow_f0_l		*E9
   	{0xD3, 0x80}, //# ???

/* ############# Start Settings ################ */
   	/*
   	 * pad_drv[7:6]
   	 * pclk_drv[5:4]
   	 * pclk_delay[3:0]
   	 */
   	{0x28, 0xF0}, //# pad_control2 //0xF4
   	{0x33, 0x02}, //# pixelbias
   	{0x34, 0x01}, //# compbias
	{0x36, 0x80}, //# tx_bais, recommended by design 1
	{0x38, 0x58}, //# black_bias '011', rangesel "000", recommended by design 1

   	{0x03, 0x01}, //# B bank
   	{0x1E, 0x0E}, //# bsmode '0'
   	{0x26, 0x03}, //# blacksunth_h

/* ############# BLACK ################ */
   	{0xB1, 0x30}, //# adc offset	*0x28
   	{0x03, 0x04}, //# E bank
   	{0x06, 0x98}, //# front_black_fitting[4], ycont/ybright[3], adcoffset_fitting[2]

   	{0x03, 0x01}, //# B bank
   	{0xA4, 0x00}, //# front_black_ref0		*88
	{0xA5, 0x00}, //# front_black_ref1
    {0xA6, 0x00}, //# front_black_ref2
    {0xA7, 0x00}, //# front_black_ref3
    {0xA8, 0x00}, //# front_black_ref4
    {0xA9, 0x08}, //# front_black_ref5
/* ############# AWB ################ */
    /* AWB gain control */
    {0x03, 0x04}, //# E bank
    {0x06, 0xB8}, //# auto_control_3 enable
	/* AWB gain control */
	{0x75, 0x28}, //# awb_rgain_min1 LOW TEMP
	{0x76, 0x28}, //# awb_rgain_min2
	{0x77, 0x78}, //# awb_rgain_max1 HIGH TEMP
	{0x78, 0x78}, //# awb_rgain_max2
	{0x79, 0x48}, //# awb_bgain_min1 HIGH TEMP	*38
	{0x7A, 0x48}, //# awb_bgain_min2			*38
	{0x7B, 0xB8}, //# awb_bgain_max1 LOW TEMP	*80
	{0x7C, 0xB8}, //# awb_bgain_max2			*80
	{0x7D, 0x01},
	{0x7E, 0x00},
	{0x7F, 0x02},
	{0x80, 0x07},
	{0x73, 0x08}, //08->0C(140102) //# AWB lock range	*0c
	{0x74, 0x04}, //04->08(140102) //# AWB speed		*08
	/* Set AWB Sampling Boundary */
	{0x51, 0x10},
	{0x52, 0xE0},
	{0x53, 0x02},
	{0x54, 0x02},
	{0x55, 0x40},
	{0x56, 0xC0},
	{0x57, 0x04},
	{0x58, 0x6E},
	{0x59, 0x45},
	{0x5A, 0x23}, //# awb_rmin1 LOW TEMP white point	*26
	{0x5B, 0x4B}, //# awb_rmax1 HIGH TEMP				*47
	{0x5C, 0x64}, //# awb_bmin1 HIGH TMEP				*70
	{0x5D, 0xAA}, //# awb_bmax1 LOW TEMP				*af
	{0x5E, 0x23}, //#									*14
	{0x5F, 0x28}, //#									*1c
	{0x60, 0x4B}, //# awb_rmin2 white point				*47
	{0x61, 0x73}, //# awb_rmax2							*62
	{0x62, 0x3C}, //# awb_bmin2							*3a
	{0x63, 0x87}, //# awb_bmax2							*8e
	{0x64, 0x2D}, //# 									*1e
	{0x65, 0x2D}, //# 									*14
	/* awb rg/bg ratio axis */
	{0x6E, 0x3A}, //# 									*2f
	{0x6F, 0x50}, //# 									*58
	{0x70, 0x60}, //# 									*5e
	/* lens / cs axis */
	{0x03, 0x03}, //# C bank
	{0x16, 0x3A}, //# 									*2f
	{0x17, 0x50}, //# 									*58
	{0x18, 0x60}, //# 									*5e
	{0x19, 0x1C}, //# user CS gain
/* ############# AE ################ */
	{0x03, 0x04}, //# E bank
	{0x05, 0x64}, //# AE on
	{0x30, 0x08}, //# 63 AE weight left up
	{0x31, 0x08}, //# AE weight right up
	{0x32, 0x08}, //# AE weight left down
	{0x33, 0x08}, //# AE weight right up
	{0x34, 0x08}, //# AE weight center
	{0x3B, 0xA0}, //# 70 #max_yt1 y target				*70
	{0x3C, 0x70}, //# 70 #max_yt2						*60
	{0x3D, 0x70}, //# 70 #min_yt1						*70
	{0x3E, 0x50}, //# 70 #min_yt2						*60
	{0x3F, 0x24}, //# 									*08
	{0x40, 0x4B}, //# 									*10
	/* Auto exposure control */
	{0x12, 0x02},
	{0x13, 0xE8},
	{0x14, 0x02},
	{0x15, 0xE8},
	{0x16, 0x02},
	{0x17, 0xE8},
	{0x1B, 0x00},
	{0x1C, 0x1C}, //#2F X8 11 #x6 17 #0B #low light	38	*17
	{0x1D, 0x30}, //# 70 #40 #C0 #low light				*50
	{0x1E, 0x00},
	{0x1F, 0x1C}, //# 11 #17 #0B #low light	38			*17
	{0x20, 0x30}, //# 70 #40 #C0 #low light				*50
	/* Auto exposure option */
	{0x48, 0x08}, //04->08(140102) //# AE Speed
	{0x49, 0x08}, //04->08(140102)
	{0x4A, 0x08}, //08->0E(140102)						*0E
	/* saturation level th */
	{0x2C, 0x66}, //# 66 Saturation decision TH			*bb
	/* saturation ratio fitting */
	{0x41, 0x04},
	{0x42, 0x08},
	{0x43, 0x10},
	{0x44, 0x20},
	{0x2E, 0x04}, //# 05 Saturation ratio
#if FLICKER_50Hz
	/* Flicker canceling mode - manual 50hz */
	{0x03, 0x00}, //# A bank
	{0x4F, 0x04},
	{0x59, 0x00},
	{0x5A, 0xBA}, //# BB
	{0x5B, 0x00}, //# 80
	{0x5C, 0x00},
	{0x5D, 0xE1},
	{0x5E, 0x00},
#else
	/* Flicker canceling mode - manual 60hz */
	{0x03, 0x00}, //# A bank
	{0x4F, 0x08},
	{0x59, 0x00},
	{0x5A, 0xBA}, //# BB
	{0x5B, 0x00}, //# 80
#endif
/* ############### Data range ################ */
	{0x03, 0x02}, //# C bank
	{0x09, 0x40}, //# Yrange selection BIT[6]0 b: 0~255 (reference 8bit output), 1b : 16~235 (reference 8bit output)
	{0x9B, 0x02},
/* ############### COLOR ################ */
	/* Color correction */
	{0x33, 0x37},
	{0x34, 0x90},
	{0x35, 0x87},
	{0x36, 0x8E},
	{0x37, 0x3B},
	{0x38, 0x8C},
	{0x39, 0x82},
	{0x3A, 0x98},
	{0x3B, 0x3A},
	/* Color saturation */
	{0x03, 0x03}, //# D bank
	{0x0C, 0x25}, //# Color saturation matrix fitting reference
	{0x0D, 0x88},
	{0x0E, 0x00},
	{0x0F, 0x25},

	{0x6D, 0x7F}, //# Reserved
	{0x6E, 0x0E}, //# Reserved
	{0x6F, 0x0E}, //# Reserved
	{0x71, 0x7F}, //# Reserved
	{0x72, 0x22}, //# Reserved
	{0x73, 0x10}, //# Reserved
	{0xA1, 0x40}, //# Dark edge Blf filter0 control
	{0xA2, 0x7F}, //# Dark edge Blf filter1 control
	{0xA3, 0x7F}, //# Dark edge Blf filter2 control

/* ############### GAMMA ################ */
	{0x03, 0x02}, //# C bank
	{0x95, 0x00}, //# Dark Y Brightness fitting control (ref 0, def: [0x00])
	{0x96, 0x00}, //# Dark Y Brightness fitting control (ref 1, def: [0x00])
	{0x97, 0x10}, //# Dark Y Brightness fitting control (ref 2, def: [0x00])

	/* gamma1 cofficient curve fitting */
	{0x3D, 0x00}, //# *00
	{0x3E, 0x03}, //# *03
	{0x3F, 0x0C}, //# *0C
	{0x40, 0x19}, //# *18
	{0x41, 0x26}, //# *22
	{0x42, 0x3F}, //# *34
	{0x43, 0x52}, //# *43
	{0x44, 0x6E}, //# *5A
	{0x45, 0x82}, //# *6D
	{0x46, 0xA1}, //# *8D
	{0x47, 0xB9}, //# *A8
	{0x48, 0xCE}, //# *C0
	{0x49, 0xE0}, //# *D7
	{0x4A, 0xF0}, //# *EC
	{0x4B, 0xFF}, //# *FF

	/* gamma2 cofficient curve fitting */
	{0x4C, 0x0 }, //# 00 *00
	{0x4D, 0x12}, //# 0B *0F
	{0x4E, 0x28}, //# 17 *26
	{0x4F, 0x40}, //# 22 *37
	{0x50, 0x5C}, //# 2E *43
	{0x51, 0x7D}, //# 40 *54
	{0x52, 0x9B}, //# 50 *62
	{0x53, 0xB4}, //# 6E *77
	{0x54, 0xC8}, //# 88 *88
	{0x55, 0xD7}, //# AE *A4
	{0x56, 0xE4}, //# CA *BB
	{0x57, 0xEE}, //# DC *CF
	{0x58, 0xF6}, //# EC *E0
	{0x59, 0xFB}, //# F6 *F1
	{0x5A, 0xFF}, //# FF *FF

	/* RGB gamma1 cofficient curve fitting(0.75) */
	{0x5B, 0x00}, //# *00
	{0x5C, 0x03}, //# *0B
	{0x5D, 0x0C}, //# *13
	{0x5E, 0x19}, //# *1A
	{0x5F, 0x26}, //# *20
	{0x60, 0x3F}, //# *2B
	{0x61, 0x52}, //# *36
	{0x62, 0x6E}, //# *49
	{0x63, 0x82}, //# *5A
	{0x64, 0xA1}, //# *7B
	{0x65, 0xB9}, //# *98
	{0x66, 0xCE}, //# *B4
	{0x67, 0xE0}, //# *CE
	{0x68, 0xF0}, //# *E7
	{0x69, 0xFF}, //# *FF

	/* RGB gamma2 cofficient curve fitting(0.75) */
	{0x6A, 0x0 }, //# 00 *00
	{0x6B, 0x12}, //# 0B *0B
	{0x6C, 0x28}, //# 17 *13
	{0x6D, 0x40}, //# 22 *1A
	{0x6E, 0x5C}, //# 2E *20
	{0x6F, 0x7D}, //# 40 *2B
	{0x70, 0x9B}, //# 50 *36
	{0x71, 0xB4}, //# 6E *49
	{0x72, 0xC8}, //# 88 *5A
	{0x73, 0xD7}, //# AE *7B
	{0x74, 0xE4}, //# CA *98
	{0x75, 0xEE}, //# DC *B4
	{0x76, 0xF6}, //# EC *CE
	{0x77, 0xFB}, //# F6 *E7
	{0x78, 0xFF}, //# FF *FF
	/* Y weight control */
	{0x8D, 0x30},
/* ############### EDGE ################ */
	/* sharpness control */
	{0x2F, 0x28}, //# 10 #Edge gain						*20
	{0x30, 0x20}, //# Positive max edge clamp gain		*30
	{0x31, 0x60}, //# Negative max edge clamp gain		*30
/* ############### DARK ################ */
	{0x03, 0x04}, //# E bank
	{0x09, 0x00}, //# 01->00
	/* dark_dpc_p */
	{0x03, 0x03}, //# D bank
	{0x26, 0x00}, //# dark_dpc_p
	{0x27, 0x10}, //# *00
	{0x28, 0x40}, //# *00
	/* dark_blf */
	{0x2E, 0x7F}, /* Dark bilateral filter fitting control_0 : set default */
	{0x2F, 0x7F}, /* Dark bilateral filter fitting control_1 : set default */
	{0x30, 0x7F}, /* Dark bilateral filter fitting control_2 : set default */
	/* dark_nf */
	{0x32, 0x00}, /* Dark noise floor fitting control_0 #default 40 */
	{0x33, 0x00}, /* Dark noise floor fitting control_1 #default 40 */
	{0x34, 0x00}, /* Dark noise floor fitting control_0 #default 40 */
	{0x77, 0x00}, //# dark_dc
	{0x78, 0x00},
	{0x79, 0x00},
	/* dark_e_blf */
	{0xA1, 0x40}, //# *40 //# dark_edge_blf
	{0xA2, 0x20}, //# *7F
	{0xA3, 0x20}, //# *7F
	/* Darkness X reference */
	{0x03, 0x04}, //# E bank
	{0x82, 0x0A}, //# *03
	{0x83, 0x10}, //# *05
	{0x84, 0x28}, //# *07

	{0x03, 0x03}, //# D bank
	{0x2A, 0x00},
	{0x2B, 0x00},
	{0x2C, 0x00},
	/* lens scale and shading */
	{0x03, 0x02}, //# C bank
	{0x0D, 0x0A},
	{0x0E, 0x0A},
	{0x0F, 0x0A},
	{0x10, 0x0A},
	{0x11, 0x0A},
	{0x12, 0x0A},
	{0x13, 0x0A},
	{0x14, 0x0A},
	{0x15, 0x0A},
	{0x16, 0x0A},
	{0x17, 0x0A},
	{0x18, 0x0A},
	{0x19, 0x0A},
	{0x1A, 0x0A},
	{0x1B, 0x0A},
	{0x1C, 0x0A},
	/* awb rg/bg ratio fitting */
	{0x03, 0x04}, //# E bank
	{0x68, 0x81},
	{0x69, 0x7F},
	{0x6A, 0x81},
	{0x6B, 0x7F},
	{0x6C, 0x82},
	{0x6D, 0x80},
	/* lens gain fitting */
	{0x03, 0x02}, //# C bank
	{0x1E, 0x80},
	{0x1F, 0x80},

	{0x03, 0x03}, //# D bank
	{0x10, 0xC0},
	{0x11, 0x84},
	{0x12, 0xC0},
	{0x13, 0x68},
	{0x14, 0xC8},
	{0x15, 0x68},

	{0x03, 0x02}, //# C bank
	{0x8B, 0x00}, //# ???

	{0x03, 0x00},
	{0x05, 0x03}, //# mirror H

	//##################LED SETTING##################
	{0x03, 0x00}, //# A-Bank
	/*
	 * pad_control4: default 0x00
	 *       [7]: ledctrl_en : 0->disable 1->enable
	 *     [6:5]: ledctrl_pad_drv : LED pad drivability control
	 */
	{0x2A, 0x80},
	/*
	 * pad_control6: default 0x00
	 *       [7]: mirsctrl_en : MIRS output pad
	 *     [6:5]: ledctrl_pad_drv : LED pad drivability control
	 *       [4]: iris output pad
	 *     [3:2]: iris output pad drivability control
	 */
	{0x2C, 0x80},
	//##################CDS START##################
	{0x03, 0x04}, //# E-Bank
	{0x07, 0xA0}, //# auto control4 - auto led control enable (0x80 with cds mode)

	{0x03, 0x00}, //# A-Bank
	/*
	 * led_control1: default 0x00
	 *       [7]: ledctrl_en : 0->disable 1->enable
	 *       [6]: ledctrl manual : LED pad drivability control
	 *       [5]: led output polarity change
	 *       [4]: black & white mode: 0->disable 1->enable
	 */
	{0x8E, 0x98},
	/*
	 * led_control2: default 0x01
	 *     [3:2]: led mode selection: 00->led control with CDS
	 *                                01->auto led control without CDS
	 *                                10->auto led control with CDS
	 *       [0]: exrom_set_en: enable setting from external rom @ led on/off
	 */
	{0x8F, 0x03}, //# led_control2 Led control mode selection & exrom

	{0x90, 0x50}, //# led_lvth1
	{0x91, 0xB8}, //# led_lvth2
	{0x92, 0x10}, //# led_frame
	{0x93, 0xFF}, //# mirs_pREGW = X

	{0x03, 0x01}, //# B bank
	/*
	 * bayer_control_01: ??
	 */
	{0x16, 0x00}, //# 01 = 7:0 , 10 = 8:1 11 or 00 = 9:2
	{0x17, 0xFA}, //# led invertig disable

	//################# LED off th(without CDS)
	{0x03, 0x00}, //# A bank
	{0x99, 0x00},
	{0x9A, 0x00},
	{0x9B, 0x00},
	{0x9C, 0x00},
	{0x9D, 0x00},
	{0x9E, 0x25},
	//############### LED ################
	{0x03, 0x00}, //# A bank
	{0x7F, 0x00}, //# led_exposure_t   //LS -1X
	{0x80, 0x04}, //# led_exposure_h 04
	{0x81, 0x0E}, //# led_exposure_m 0E
	{0x82, 0xFF}, //# led_exposure_l 00

	{0x03, 0x00}, //# A bank
	{0x8A, 0x02}, //# led_on_th_t
	{0x8B, 0x47}, //# led_on_th_h  47  71
	{0x8C, 0xE0}, //# led_on_th_m  E0 224

	{0x03, 0x00}, //# A Bank
	{0x7C, 0x04}, //# max_ledlight_h
	{0x7D, 0x77}, //# max_ledlight_m
	{0x97, 0x04}, //# max_led_pp_h
	{0x98, 0x77}, //# max_led_pp_l

	{TERM, 0xff}
};

static const struct regval_list ph3100k_ir_init_reg_rs[] = {	//# rear side
	 #if 0
	 //# pll init ---
	{0x03, 0x00}, //# A bank
	{0x25, 0x08}, //# ppclk 1/2 : 0xA (140102) => ppclk 1/1 : 0x08 (150623 - jaeki)
   	{0x41, 0x01}, //2->1(140102) //# pll_ms
   	{0x42, 0x0B}, //# pll_ns	//# 27M*(ns/ms) = 148.5M
   	{0x40, 0x3C},
   	{DELAY, PLL_DELAY},

	{0x40, 0x2C},
	{0x29, 0x08}, //# pad ctrl
   	{DELAY, 30},
   	#endif

   	//{0x03, 0x00}, // A bank
   	//{0x04, 0x02}, //# chip mode (00: smpte, x01: sampling, x02: Digital)
   	//{0x05, 0x03}, //# mirror
   	{0x06, 0x06}, //# framewidth_h
   	{0x07, 0x71}, //# framewidth_l
   	{0x08, 0x02}, //# fd_fheight_a_h
   	{0x09, 0xED}, //# fd_fheight_a_l
   	{0x0A, 0x02}, //# fd_fheight_b_h
   	{0x0B, 0xED}, //# fd_fheight_b_l
   	{0x0C, 0x00}, //# windowx1_h
   	{0x0D, 0x05}, //# windowx1_l
   	{0x0E, 0x00}, //# windowy1_h
   	{0x0F, 0x05}, //# windowy1_l
   	{0x10, 0x05}, //# windowx2_h
   	{0x11, 0x04}, //# windowx2_l
   	{0x12, 0x02}, //# windowy2_h
   	{0x13, 0xD4}, //# windowy2_l
   	{0x14, 0x00}, //# vsyncstartrow_f0_h
   	{0x15, 0x16}, //# vsyncstartrow_f0_l	*15
   	{0x16, 0x02}, //# vsyncstoprow_f0_h
   	{0x17, 0xEB}, //# vsyncstoprow_f0_l		*E9
   	{0xD3, 0x80}, //# ???

/* ############# Start Settings ################ */
   	/*
   	 * pad_drv[7:6]
   	 * pclk_drv[5:4]
   	 * pclk_delay[3:0]
   	 */
   	{0x28, 0xF0}, //# pad_control2 //0xF4
   	{0x33, 0x02}, //# pixelbias
   	{0x34, 0x01}, //# compbias
	{0x36, 0x80}, //# tx_bais, recommended by design 1
	{0x38, 0x58}, //# black_bias '011', rangesel "000", recommended by design 1

   	{0x03, 0x01}, //# B bank
   	{0x1E, 0x0E}, //# bsmode '0'
   	{0x26, 0x03}, //# blacksunth_h

/* ############# BLACK ################ */
   	{0xB1, 0x30}, //# adc offset	*0x28
   	{0x03, 0x04}, //# E bank
   	{0x06, 0x98}, //# front_black_fitting[4], ycont/ybright[3], adcoffset_fitting[2]

   	{0x03, 0x01}, //# B bank
   	{0xA4, 0x00}, //# front_black_ref0		*88
	{0xA5, 0x00}, //# front_black_ref1
    {0xA6, 0x00}, //# front_black_ref2
    {0xA7, 0x00}, //# front_black_ref3
    {0xA8, 0x00}, //# front_black_ref4
    {0xA9, 0x08}, //# front_black_ref5
/* ############# AWB ################ */
    /* AWB gain control */
    {0x03, 0x04}, //# E bank
    {0x06, 0xB8}, //# auto_control_3 enable
	/* AWB gain control */
	{0x75, 0x28}, //# awb_rgain_min1 LOW TEMP
	{0x76, 0x28}, //# awb_rgain_min2
	{0x77, 0x78}, //# awb_rgain_max1 HIGH TEMP
	{0x78, 0x78}, //# awb_rgain_max2
	{0x79, 0x48}, //# awb_bgain_min1 HIGH TEMP	*38
	{0x7A, 0x48}, //# awb_bgain_min2			*38
	{0x7B, 0xB8}, //# awb_bgain_max1 LOW TEMP	*80
	{0x7C, 0xB8}, //# awb_bgain_max2			*80
	{0x7D, 0x01},
	{0x7E, 0x00},
	{0x7F, 0x02},
	{0x80, 0x07},
	{0x73, 0x08}, //08->0C(140102) //# AWB lock range	*0c
	{0x74, 0x04}, //04->08(140102) //# AWB speed		*08
	/* Set AWB Sampling Boundary */
	{0x51, 0x10},
	{0x52, 0xE0},
	{0x53, 0x02},
	{0x54, 0x02},
	{0x55, 0x40},
	{0x56, 0xC0},
	{0x57, 0x04},
	{0x58, 0x6E},
	{0x59, 0x45},
	{0x5A, 0x23}, //# awb_rmin1 LOW TEMP white point	*26
	{0x5B, 0x4B}, //# awb_rmax1 HIGH TEMP				*47
	{0x5C, 0x64}, //# awb_bmin1 HIGH TMEP				*70
	{0x5D, 0xAA}, //# awb_bmax1 LOW TEMP				*af
	{0x5E, 0x23}, //#									*14
	{0x5F, 0x28}, //#									*1c
	{0x60, 0x4B}, //# awb_rmin2 white point				*47
	{0x61, 0x73}, //# awb_rmax2							*62
	{0x62, 0x3C}, //# awb_bmin2							*3a
	{0x63, 0x87}, //# awb_bmax2							*8e
	{0x64, 0x2D}, //# 									*1e
	{0x65, 0x2D}, //# 									*14
	/* awb rg/bg ratio axis */
	{0x6E, 0x3A}, //# 									*2f
	{0x6F, 0x50}, //# 									*58
	{0x70, 0x60}, //# 									*5e
	/* lens / cs axis */
	{0x03, 0x03}, //# C bank
	{0x16, 0x3A}, //# 									*2f
	{0x17, 0x50}, //# 									*58
	{0x18, 0x60}, //# 									*5e
	{0x19, 0x1C}, //# user CS gain
/* ############# AE ################ */
	{0x03, 0x04}, //# E bank
	{0x05, 0x64}, //# AE on
	{0x30, 0x08}, //# 63 AE weight left up
	{0x31, 0x08}, //# AE weight right up
	{0x32, 0x08}, //# AE weight left down
	{0x33, 0x08}, //# AE weight right up
	{0x34, 0x08}, //# AE weight center
	{0x3B, 0xA0}, //# 70 #max_yt1 y target				*70
	{0x3C, 0x70}, //# 70 #max_yt2						*60
	{0x3D, 0x70}, //# 70 #min_yt1						*70
	{0x3E, 0x50}, //# 70 #min_yt2						*60
	{0x3F, 0x24}, //# 									*08
	{0x40, 0x4B}, //# 									*10
	/* Auto exposure control */
	{0x12, 0x02},
	{0x13, 0xE8},
	{0x14, 0x02},
	{0x15, 0xE8},
	{0x16, 0x02},
	{0x17, 0xE8},
	{0x1B, 0x00},
	{0x1C, 0x1C}, //#2F X8 11 #x6 17 #0B #low light	38	*17
	{0x1D, 0x30}, //# 70 #40 #C0 #low light				*50
	{0x1E, 0x00},
	{0x1F, 0x1C}, //# 11 #17 #0B #low light	38			*17
	{0x20, 0x30}, //# 70 #40 #C0 #low light				*50
	/* Auto exposure option */
	{0x48, 0x08}, //04->08(140102) //# AE Speed
	{0x49, 0x08}, //04->08(140102)
	{0x4A, 0x08}, //08->0E(140102)						*0E
	/* saturation level th */
	{0x2C, 0x66}, //# 66 Saturation decision TH			*bb
	/* saturation ratio fitting */
	{0x41, 0x04},
	{0x42, 0x08},
	{0x43, 0x10},
	{0x44, 0x20},
	{0x2E, 0x04}, //# 05 Saturation ratio
#if FLICKER_50Hz
	/* Flicker canceling mode - manual 50hz */
	{0x03, 0x00}, //# A bank
	{0x4F, 0x04},
	{0x59, 0x00},
	{0x5A, 0xBA}, //# BB
	{0x5B, 0x00}, //# 80
	{0x5C, 0x00},
	{0x5D, 0xE1},
	{0x5E, 0x00},
#else
	/* Flicker canceling mode - manual 60hz */
	{0x03, 0x00}, //# A bank
	{0x4F, 0x08},
	{0x59, 0x00},
	{0x5A, 0xBA}, //# BB
	{0x5B, 0x00}, //# 80
#endif
/* ############### Data range ################ */
	{0x03, 0x02}, //# C bank
	{0x09, 0x40}, //# Yrange selection BIT[6]0 b: 0~255 (reference 8bit output), 1b : 16~235 (reference 8bit output)
	{0x9B, 0x02},
/* ############### COLOR ################ */
	/* Color correction */
	{0x33, 0x37},
	{0x34, 0x90},
	{0x35, 0x87},
	{0x36, 0x8E},
	{0x37, 0x3B},
	{0x38, 0x8C},
	{0x39, 0x82},
	{0x3A, 0x98},
	{0x3B, 0x3A},
	/* Color saturation */
	{0x03, 0x03}, //# D bank
	{0x0C, 0x25}, //# Color saturation matrix fitting reference
	{0x0D, 0x88},
	{0x0E, 0x00},
	{0x0F, 0x25},

	{0x6D, 0x7F}, //# Reserved
	{0x6E, 0x0E}, //# Reserved
	{0x6F, 0x0E}, //# Reserved
	{0x71, 0x7F}, //# Reserved
	{0x72, 0x22}, //# Reserved
	{0x73, 0x10}, //# Reserved
	{0xA1, 0x40}, //# Dark edge Blf filter0 control
	{0xA2, 0x7F}, //# Dark edge Blf filter1 control
	{0xA3, 0x7F}, //# Dark edge Blf filter2 control

/* ############### GAMMA ################ */
	{0x03, 0x02}, //# C bank
	{0x95, 0x00}, //# Dark Y Brightness fitting control (ref 0, def: [0x00])
	{0x96, 0x00}, //# Dark Y Brightness fitting control (ref 1, def: [0x00])
	{0x97, 0x10}, //# Dark Y Brightness fitting control (ref 2, def: [0x00])

	/* gamma1 cofficient curve fitting */
	{0x3D, 0x00}, //# *00
	{0x3E, 0x03}, //# *03
	{0x3F, 0x0C}, //# *0C
	{0x40, 0x19}, //# *18
	{0x41, 0x26}, //# *22
	{0x42, 0x3F}, //# *34
	{0x43, 0x52}, //# *43
	{0x44, 0x6E}, //# *5A
	{0x45, 0x82}, //# *6D
	{0x46, 0xA1}, //# *8D
	{0x47, 0xB9}, //# *A8
	{0x48, 0xCE}, //# *C0
	{0x49, 0xE0}, //# *D7
	{0x4A, 0xF0}, //# *EC
	{0x4B, 0xFF}, //# *FF

	/* gamma2 cofficient curve fitting */
	{0x4C, 0x0 }, //# 00 *00
	{0x4D, 0x12}, //# 0B *0F
	{0x4E, 0x28}, //# 17 *26
	{0x4F, 0x40}, //# 22 *37
	{0x50, 0x5C}, //# 2E *43
	{0x51, 0x7D}, //# 40 *54
	{0x52, 0x9B}, //# 50 *62
	{0x53, 0xB4}, //# 6E *77
	{0x54, 0xC8}, //# 88 *88
	{0x55, 0xD7}, //# AE *A4
	{0x56, 0xE4}, //# CA *BB
	{0x57, 0xEE}, //# DC *CF
	{0x58, 0xF6}, //# EC *E0
	{0x59, 0xFB}, //# F6 *F1
	{0x5A, 0xFF}, //# FF *FF

	/* RGB gamma1 cofficient curve fitting(0.75) */
	{0x5B, 0x00}, //# *00
	{0x5C, 0x03}, //# *0B
	{0x5D, 0x0C}, //# *13
	{0x5E, 0x19}, //# *1A
	{0x5F, 0x26}, //# *20
	{0x60, 0x3F}, //# *2B
	{0x61, 0x52}, //# *36
	{0x62, 0x6E}, //# *49
	{0x63, 0x82}, //# *5A
	{0x64, 0xA1}, //# *7B
	{0x65, 0xB9}, //# *98
	{0x66, 0xCE}, //# *B4
	{0x67, 0xE0}, //# *CE
	{0x68, 0xF0}, //# *E7
	{0x69, 0xFF}, //# *FF

	/* RGB gamma2 cofficient curve fitting(0.75) */
	{0x6A, 0x0 }, //# 00 *00
	{0x6B, 0x12}, //# 0B *0B
	{0x6C, 0x28}, //# 17 *13
	{0x6D, 0x40}, //# 22 *1A
	{0x6E, 0x5C}, //# 2E *20
	{0x6F, 0x7D}, //# 40 *2B
	{0x70, 0x9B}, //# 50 *36
	{0x71, 0xB4}, //# 6E *49
	{0x72, 0xC8}, //# 88 *5A
	{0x73, 0xD7}, //# AE *7B
	{0x74, 0xE4}, //# CA *98
	{0x75, 0xEE}, //# DC *B4
	{0x76, 0xF6}, //# EC *CE
	{0x77, 0xFB}, //# F6 *E7
	{0x78, 0xFF}, //# FF *FF
	/* Y weight control */
	{0x8D, 0x30},
/* ############### EDGE ################ */
	/* sharpness control */
	{0x2F, 0x28}, //# 10 #Edge gain						*20
	{0x30, 0x20}, //# Positive max edge clamp gain		*30
	{0x31, 0x60}, //# Negative max edge clamp gain		*30
/* ############### DARK ################ */
	{0x03, 0x04}, //# E bank
	{0x09, 0x00}, //# 01->00
	/* dark_dpc_p */
	{0x03, 0x03}, //# D bank
	{0x26, 0x00}, //# dark_dpc_p
	{0x27, 0x10}, //# *00
	{0x28, 0x40}, //# *00
	/* dark_blf */
	{0x2E, 0x7F}, /* Dark bilateral filter fitting control_0 : set default */
	{0x2F, 0x7F}, /* Dark bilateral filter fitting control_1 : set default */
	{0x30, 0x7F}, /* Dark bilateral filter fitting control_2 : set default */
	/* dark_nf */
	{0x32, 0x00}, /* Dark noise floor fitting control_0 #default 40 */
	{0x33, 0x00}, /* Dark noise floor fitting control_1 #default 40 */
	{0x34, 0x00}, /* Dark noise floor fitting control_0 #default 40 */
	{0x77, 0x00}, //# dark_dc
	{0x78, 0x00},
	{0x79, 0x00},
	/* dark_e_blf */
	{0xA1, 0x40}, //# *40 //# dark_edge_blf
	{0xA2, 0x20}, //# *7F
	{0xA3, 0x20}, //# *7F
	/* Darkness X reference */
	{0x03, 0x04}, //# E bank
	{0x82, 0x0A}, //# *03
	{0x83, 0x10}, //# *05
	{0x84, 0x28}, //# *07

	{0x03, 0x03}, //# D bank
	{0x2A, 0x00},
	{0x2B, 0x00},
	{0x2C, 0x00},
	/* lens scale and shading */
	{0x03, 0x02}, //# C bank
	{0x0D, 0x0A},
	{0x0E, 0x0A},
	{0x0F, 0x0A},
	{0x10, 0x0A},
	{0x11, 0x0A},
	{0x12, 0x0A},
	{0x13, 0x0A},
	{0x14, 0x0A},
	{0x15, 0x0A},
	{0x16, 0x0A},
	{0x17, 0x0A},
	{0x18, 0x0A},
	{0x19, 0x0A},
	{0x1A, 0x0A},
	{0x1B, 0x0A},
	{0x1C, 0x0A},
	/* awb rg/bg ratio fitting */
	{0x03, 0x04}, //# E bank
	{0x68, 0x81},
	{0x69, 0x7F},
	{0x6A, 0x81},
	{0x6B, 0x7F},
	{0x6C, 0x82},
	{0x6D, 0x80},
	/* lens gain fitting */
	{0x03, 0x02}, //# C bank
	{0x1E, 0x80},
	{0x1F, 0x80},

	{0x03, 0x03}, //# D bank
	{0x10, 0xC0},
	{0x11, 0x84},
	{0x12, 0xC0},
	{0x13, 0x68},
	{0x14, 0xC8},
	{0x15, 0x68},

	{0x03, 0x02}, //# C bank
	{0x8B, 0x00}, //# ???

	{0x03, 0x00},
	{0x05, 0x03}, //# mirror H

	//##################LED SETTING##################
	{0x03, 0x00}, //# A-Bank
	/*
	 * pad_control4: default 0x00
	 *       [7]: ledctrl_en : 0->disable 1->enable
	 *     [6:5]: ledctrl_pad_drv : LED pad drivability control
	 */
	{0x2A, 0x80},
	/*
	 * pad_control6: default 0x00
	 *       [7]: mirsctrl_en : MIRS output pad
	 *     [6:5]: ledctrl_pad_drv : LED pad drivability control
	 *       [4]: iris output pad
	 *     [3:2]: iris output pad drivability control
	 */
	{0x2C, 0x80},
	//##################CDS START##################
	{0x03, 0x04}, //# E-Bank
	{0x07, 0xA0}, //# auto control4 - auto led control enable (0x80 with cds mode)

	{0x03, 0x00}, //# A-Bank
	/*
	 * led_control1: default 0x00
	 *       [7]: ledctrl_en : 0->disable 1->enable
	 *       [6]: ledctrl manual : LED pad drivability control
	 *       [5]: led output polarity change
	 *       [4]: black & white mode: 0->disable 1->enable
	 */
	{0x8E, 0x98},
	/*
	 * led_control2: default 0x01
	 *     [3:2]: led mode selection: 00->led control with CDS
	 *                                01->auto led control without CDS
	 *                                10->auto led control with CDS
	 *       [0]: exrom_set_en: enable setting from external rom @ led on/off
	 */
	{0x8F, 0x03}, //# led_control2 Led control mode selection & exrom

	{0x90, 0x50}, //# led_lvth1
	{0x91, 0xB8}, //# led_lvth2
	{0x92, 0x10}, //# led_frame
	{0x93, 0xFF}, //# mirs_pREGW = X

	{0x03, 0x01}, //# B bank
	/*
	 * bayer_control_01: ??
	 */
	{0x16, 0x00}, //# 01 = 7:0 , 10 = 8:1 11 or 00 = 9:2
	{0x17, 0xFA}, //# led invertig disable

	//################# LED off th(without CDS)
	{0x03, 0x00}, //# A bank
	{0x99, 0x00},
	{0x9A, 0x00},
	{0x9B, 0x00},
	{0x9C, 0x00},
	{0x9D, 0x00},
	{0x9E, 0x25},
	//############### LED ################
	{0x03, 0x00}, //# A bank
	{0x7F, 0x00}, //# led_exposure_t   //LS -1X
	{0x80, 0x04}, //# led_exposure_h 04
	{0x81, 0x0E}, //# led_exposure_m 0E
	{0x82, 0xFF}, //# led_exposure_l 00

	{0x03, 0x00}, //# A bank
	{0x8A, 0x02}, //# led_on_th_t
	{0x8B, 0x47}, //# led_on_th_h  47  71
	{0x8C, 0xE0}, //# led_on_th_m  E0 224

	{0x03, 0x00}, //# A Bank
	{0x7C, 0x04}, //# max_ledlight_h
	{0x7D, 0x77}, //# max_ledlight_m
	{0x97, 0x04}, //# max_led_pp_h
	{0x98, 0x77}, //# max_led_pp_l

	{TERM, 0xff}
};
//------------------------------------------------------------------------------------------------------

static const struct regval_list ph3100k_720p[] = {
	{0x03, 0x00},
	{0x0C, 0x00}, //# windowx1_h
	{0x0D, 0x05}, //# windowx1_l (5)
	{0x0E, 0x00}, //# windowy1_h
	{0x0F, 0x05}, //# windowy1_l (5)
	{0x10, 0x05}, //# windowx2_h
	{0x11, 0x04}, //# windowx2_l (1284)
	{0x12, 0x02}, //# windowy2_h
	{0x13, 0xD4}, //# windowy2_l (724)
	{DELAY,   1},

	{0x03, 0x02}, //# C bank
	{0x7B, 0x20}, //# H scale factor
	{0x7C, 0x20}, //# V scale factor
	{0x7D, 0x00}, //# scale buffer thres
	{0x7E, 0x0A}, //0x17

	{0xB3, 0x00}, //# AE window X start_h
	{0xB4, 0x05}, //# AE window X start_l	(5)
	{0xB5, 0x05}, //# AE window X stop_h
	{0xB6, 0x04}, //# AE window X stop_l	(1284)
	{0xB7, 0x00}, //# AE window Y start_h
	{0xB8, 0x05}, //# AE window Y start_l 	(5)
	{0xB9, 0x02}, //# AE window Y stop_h
	{0xBA, 0xD4}, //# AE window Y stop_l	(724)
	{0xBB, 0x01}, //# AE center X start_h
	{0xBC, 0xAF}, //# AE center X start_l 	(431)
	{0xBD, 0x03}, //# AE center X stop_h
	{0xBE, 0x5A}, //# AE center X stop_l	(858)
	{0xBF, 0x00}, //# AE center Y start_h
	{0xC0, 0xF5}, //# AE center Y start_l 	(245)
	{0xC1, 0x01}, //# AE center Y stop_h
	{0xC2, 0xE4}, //# AE center Y stop_l	(484)
	{0xC3, 0x02}, //# AE window X axis_h
	{0xC4, 0x85}, //# AE window X axis_l
	{0xC5, 0x01}, //# AE window Y axis_h
	{0xC6, 0x6D}, //# AE window Y axis_l
	{0xC7, 0x00}, //# AWB window X start_h
	{0xC8, 0x05}, //# AWB window X start_l
	{0xC9, 0x05}, //# AWB window X stop_h
	{0xCA, 0x04}, //# AWB window X stop_l
	{0xCB, 0x00}, //# AWB window Y start_h
	{0xCC, 0x05}, //# AWB window Y start_l
	{0xCD, 0x02}, //# AWB window Y stop_h
	{0xCE, 0xD4}, //# AWB window Y stop_l

	{TERM, 0xff}
};

static const struct regval_list ph3100k_d1[] = {
	{0x03, 0x00},
	{0x0C, 0x00}, //# windowx1_h
	{0x0D, 0x03}, //# windowx1_l (3)
	{0x0E, 0x00}, //# windowy1_h
	{0x0F, 0x03}, //# windowy1_l (3)
	{0x10, 0x03}, //# windowx2_h
	{0x11, 0x56}, //# windowx2_l (854)
	{0x12, 0x01}, //# windowy2_h
	{0x13, 0xE2}, //# windowy2_l (482)
	{DELAY,   1},

	{0x03, 0x02}, //# C bank
	{0x7B, 0x30}, //# H scale factor
	{0x7C, 0x30}, //# V scale factor
	{0x7D, 0x02}, //# scale buffer thres
	{0x7E, 0x56},

	{0xB3, 0x00}, //# AE window X start_h
	{0xB4, 0x03}, //# AE window X start_l	(3)
	{0xB5, 0x03}, //# AE window X stop_h
	{0xB6, 0x56}, //# AE window X stop_l	(854)
	{0xB7, 0x00}, //# AE window Y start_h
	{0xB8, 0x03}, //# AE window Y start_l	(3)
	{0xB9, 0x01}, //# AE window Y stop_h
	{0xBA, 0xE2}, //# AE window Y stop_l	(482)
	{0xBB, 0x00}, //# AE center X start_h
	{0xBC, 0xC5}, //# AE center X start_l	(197)
	{0xBD, 0x01}, //# AE center X stop_h
	{0xBE, 0xBF}, //# AE center X stop_l	(447)
	{0xBF, 0x00}, //# AE center Y start_h
	{0xC0, 0xA3}, //# AE center Y start_l	(163)
	{0xC1, 0x01}, //# AE center Y stop_h
	{0xC2, 0x43}, //# AE center Y stop_l	(323)
	{0xC3, 0x01}, //# AE window X axis_h
	{0xC4, 0x42}, //# AE window X axis_l	(322)
	{0xC5, 0x00}, //# AE window Y axis_h
	{0xC6, 0xF3}, //# AE window Y axis_l	(243)
	{0xC7, 0x00}, //# AWB window X start_h
	{0xC8, 0x03}, //# AWB window X start_l
	{0xC9, 0x03}, //# AWB window X stop_h
	{0xCA, 0x56}, //# AWB window X stop_l
	{0xCB, 0x00}, //# AWB window Y start_h
	{0xCC, 0x03}, //# AWB window Y start_l
	{0xCD, 0x01}, //# AWB window Y stop_h
	{0xCE, 0xE2}, //# AWB window Y stop_l

	{TERM, 0xff}
};

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 I2C read/write wrapper function.
-----------------------------------------------------------------------------*/
static Int32 dev_i2c_read8(UInt8 i2cInstId, UInt8 i2cDevAddr,
								UInt8 regAddr, UInt8 *regVal)
{
	Int32 ret = FVID2_SOK;

	if(NULL == regVal) {
		return FVID2_EFAIL;
	}

	ret = Vps_deviceRead8(i2cInstId, i2cDevAddr, &regAddr, regVal, 1);
	if (FVID2_SOK != ret) {
		//eprintf("%s: dev 0x%x, addr 0x%x\n", __func__, i2cDevAddr, regAddr);
	}

	return (ret);
}

static Int32 dev_i2c_write8(UInt8 i2cInstId, UInt8 i2cDevAddr,
								UInt8 regAddr, UInt8 regVal)
{
	Int32 ret = FVID2_SOK;

	ret = Vps_deviceWrite8(i2cInstId, i2cDevAddr, &regAddr, &regVal, 1);
	if (FVID2_SOK != ret) {
		//eprintf("%s: dev 0x%x, addr 0x%x\n", __func__, i2cDevAddr, regAddr);
	}

	return (ret);
}

/*----------------------------------------------------------------------------
 Control status led
-----------------------------------------------------------------------------*/
static void ctrl_status_led(int idx, int on)
{
	vps_gpio_write_data(gio[idx].led, on);

	//# sensor sucess
	s_init[idx] = on;
}

/*----------------------------------------------------------------------------
 Control Power
-----------------------------------------------------------------------------*/
static void ctrl_main_pwr(int idx, int on)
{
	vps_gpio_write_data(gio[idx].pwr, on);
}

static void ctrl_pwr_reset(int idx)
{
	vps_gpio_write_data(gio[idx].pwr, VPS_OFF);
	Task_sleep(45);
	vps_gpio_write_data(gio[idx].pwr, VPS_ON);
	Task_sleep(20);

	ctrl_status_led(idx, VPS_OFF);
}

static void ctrl_des_pwr(int idx, int on)
{
	//# diserialize pdn - high : disable, low : enable
	vps_gpio_write_data(gio[idx].pdn, on);

	if(on) {
		Task_sleep(10);
	}
}

/*----------------------------------------------------------------------------
 IR Control
-----------------------------------------------------------------------------*/
static Int32 ir_enable(void)
{
	Int32 ret;

	ret = dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x03, 0x00); //# A Bank
	/*
	 * pad_control4: default 0x00
	 *       [7]: ledctrl_en : 0->disable 1->enable
	 *     [6:5]: ledctrl_pad_drv : LED pad drivability control
	 */
	ret = dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x2A, 0x80); //# Pad Control4 LED pad
	/*
	 * pad_control6: default 0x00
	 *       [7]: mirsctrl_en : MIRS output pad
	 *     [6:5]: ledctrl_pad_drv : LED pad drivability control
	 *       [4]: iris output pad
	 *     [3:2]: iris output pad drivability control
	 */
	ret = dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x2C, 0x80); //# Pad Control6 MIRS pad
	/*
	 * led_control1: default 0x00
	 *       [7]: ledctrl_en : 0->disable 1->enable
	 *       [6]: ledctrl manual : LED pad drivability control
	 *       [5]: led output polarity change
	 *       [4]: black & white mode: 0->disable 1->enable
	 */
	ret = dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x8E, 0x98);
	if (ret < 0)
		eprintf("failed to enable ir\n");

	return ret;
}

static Int32 ir_check(void)
{
	UInt8 ir_mode = 0;

	dev_i2c_read8(PH3100K_I2C_ID, MAX9271_I2C_ADDR, 0x10, &ir_mode);
	ir_mode = ((ir_mode & 0x02) >> 1);

	return ir_mode;
}

/*----------------------------------------------------------------------------
 serdes initialize function
-----------------------------------------------------------------------------*/
static Int32 max9272_init(int idx)
{
	Int32 ret=FVID2_SOK;
	unsigned char addr;

	ret |= dev_i2c_write8(PH3100K_I2C_ID, MAX9272_I2C_ADDR, 0x07, 0x80);
	ret |= dev_i2c_write8(PH3100K_I2C_ID, MAX9272_I2C_ADDR, 0x02, 0x5F);	//# 2% spread
	ret |= dev_i2c_write8(PH3100K_I2C_ID, MAX9272_I2C_ADDR, 0x05, 0x37);	//# 8.2dB equalizer default

	if(FVID2_SOK == ret) {
		if(idx > 0) {	//# change i2c address when multi-connected
			addr = (MAX9272_I2C_ADDR + idx) << 1;
			ret |= dev_i2c_write8(PH3100K_I2C_ID, MAX9272_I2C_ADDR, 0x01, addr);
		}
	}
	if(FVID2_SOK != ret) {
		eprintf("%s: #%d\n", __func__, idx);
	}

	Task_sleep(10);

	return ret;
}

static Int32 max9271_init(int idx)
{
	Int32 ret=FVID2_SOK;
	unsigned char eq, pe;

	if(eq_lv[idx] == 1) {			//# 3m~25m
		eq = 0x3A;		//# 11.7dB
		pe = 0xAC;		//#  6.0dB
	} else if(eq_lv[idx] == 2) {	//# 0.5m~20m
		eq = 0x39;		//# 10.7dB
		pe = 0xAA;		//#  3.3dB
	} else if(eq_lv[idx] == 3) {	//# 3m~30m
		eq = 0x39;		//# 10.7dB
		pe = 0xAD;		//#  8.0dB
	} else if(eq_lv[idx] == 4) {	//# 0.15m~15m
		eq = 0x3A;		//# 10.7dB
		pe = 0xA0;		//#    off
	} else {						//# 0.5m~15m
		eq = 0x37;		//# 8.2dB equalizer
		pe = 0xA9;		//# 2.2dB preemphasis
	}

	//# set max9272 equalizer
	ret |= dev_i2c_write8(PH3100K_I2C_ID, MAX9272_I2C_ADDR+idx, 0x05, eq);
	Task_sleep(10);

	//# init max9271
	ret |= dev_i2c_write8(PH3100K_I2C_ID, MAX9271_I2C_ADDR, 0x07, 0x80);
	ret |= dev_i2c_write8(PH3100K_I2C_ID, MAX9271_I2C_ADDR, 0x02, 0x3F);	//# 0.5% spread
	ret |= dev_i2c_write8(PH3100K_I2C_ID, MAX9271_I2C_ADDR, 0x06, pe);		//# preemphasis

	if(FVID2_SOK != ret) {
		eprintf("%s: #%d\n", __func__, idx);
	}

	Task_sleep(10);

	return ret;
}

/*----------------------------------------------------------------------------
 serdes fwd/rev enable
-----------------------------------------------------------------------------*/
static int max927x_select(int idx)
{
	#if (MAX_DEV_NUM > 1)	//# need select des
	int i;
	for(i=0; i<MAX_DEV_NUM; i++)
	{
		if(i == idx) {		//# FWDCCEN/REVCCEN enable
			dev_i2c_write8(PH3100K_I2C_ID, MAX9272_I2C_ADDR+i, 0x04, 0x07);
		} else {			//# FWDCCEN/REVCCEN disable
			dev_i2c_write8(PH3100K_I2C_ID, MAX9272_I2C_ADDR+i, 0x04, 0x04);
		}
	}
	Task_sleep(10);
	#endif

	return FVID2_SOK;
}

/*----------------------------------------------------------------------------
 Check serdes lock.
-----------------------------------------------------------------------------*/
static Int32 max927x_check_lock(int idx)
{
	unsigned int locked=0;

	//# max9272 lock check
	locked = vps_gpio_read_data(gio[idx].lock);

	return locked;
}

/*----------------------------------------------------------------------------
 sensor initialize function
-----------------------------------------------------------------------------*/
static int ph3100k_check_sensor(int idx)
{
	int ret, locked=0;

	max927x_select(idx);
	ret = max9271_init(idx);
	if (FVID2_SOK != ret) {
		return 0;
	}

	//# sensor pad control enable
	ret  = dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x03, 0x00);
	/*
	 * vsync pad[7] -> disable.
	 * hsync drv[6:5]
	 * hsync pad_en[4]-> disable
	 * data Y[3]-> enable
	 */
	ret |= dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x29, 0x08);

	if(FVID2_SOK == ret)
	{
		Task_sleep(10);		//# wait link established(~3ms)
		locked = max927x_check_lock(idx);
	}

	return locked;
}

static int ph3100k_pll_init(int idx)
{
	int locked=0;

	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x03, 0x00); //# A bank

	/*
	 * REG 0x25->0x0A:ppclk diver = 1/2 [010]
	 * REG 0x41:pll_ms = 1
	 * REG 0x42:pll_ns = 0xB
	 * fRef->27MHz
	 * fRef->PLL->VCO: VCO = fRef * (pll_ns[5:0] / pll_ms[5:0])
	 *                     = 27MHz * (11 / 1)
	 *                     = 297MHz
	 *                 ppclk = VCO / 2 = 148.5
	 *
	 * REG 0x25->0x08:ppclk diver = 1/1 [000]
	 * REG 0x41:pll_ms = 2
	 * REG 0x42:pll_ns = 0xB
	 * fRef->27MHz
	 * fRef->PLL->VCO: VCO = fRef * (pll_ns[5:0] / pll_ms[5:0])
	 *                     = 27MHz * (11 / 2)
	 *                     = 148.5MHz
	 *                 ppclk = VCO / 1 = 148.5
	 * 0x40[3:2]->frange = 11 (100MHz ~ 300MHz)
	 */
#if FLICKER_50Hz
//	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x25, 0x08); //# Register Default value
	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x41, 0x02); //# pll_m
#else
	/*
	 * Clock divider1 : 0x0A
	 *     [4:3]main clk divider: 00->1/1 (01->1/2) 10->1/3 11->1/4 = VCO / 2
	 *     [2:0]ppclk_div:        000->1/1 001->2/3 010->1/2 011->1/3
	 *                            100->1/4 101->1/8 else: 1/1 ppclk=pclk
	 *     ppclk->essential clock for internal operation.
	 */
	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x25, 0x0A); //# clkdiv1
	/*
	 * Clock divider2 : 0x41
	 *     [7] p_pp_eqeal : pclk divider, 0-> ppclk/2 1->ppclk (148 / 2 = 74.25MHz) ??
	 *     [6] mipioff    :iclk clock on/off
	 *   [5:3] iclk_div   :iclk divider
	 *   [3:0] dclk_div   :dclk divider
	 */
	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x41, 0x01); //# pll_ms
#endif
	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x42, 0x0B); //# pll_ns
	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x40, 0x3C); //# pll_control
	Task_sleep(PLL_DELAY);
	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x40, 0x2C); //# pll_control
	/*
	 * pad_control3: 0x08
	 *      [7] vsync_pad_en : vsync enable/disable
	 *    [6:5] hsync_drv    : hsync drivabiliry control
	 *      [4] hsync_pad_en : hsync enable/disable
	 *      [3] data_y_pad_en: data pad enable/disable.
	 */
	dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, 0x29, 0x08); //# pad_ctrl (0x98)
	Task_sleep(30);

	locked = max927x_check_lock(idx);
	if(!locked) {
		eprintf("#%d pll lock fail\n", idx);
	}

	return locked;
}

static int ph3100k_sensor_init(int idx)
{
	Int32 ret, recnt;
	struct regval_list *vals;
	int locked=0;
	int is_IR=0;

	//# serializer init
	max927x_select(idx);
	ret = max9271_init(idx);
	if (FVID2_SOK != ret) {
		return FVID2_EFAIL;
	}

	locked = ph3100k_pll_init(idx);
	if(!locked) {
		return FVID2_EFAIL;
	}

	is_IR = ir_check();		//# check IR Mode.
	if (!is_IR) {
		if (idx == 1) {
			vals = (struct regval_list *)ph3100k_init_reg_fs; //# front
		} else {
			vals = (struct regval_list *)ph3100k_init_reg_rs; //# rear
		}
	} else {
		/* IR camera mode */
		if (idx == 1) {
			vals = (struct regval_list *)ph3100k_ir_init_reg_fs; //# front
		} else {
			vals = (struct regval_list *)ph3100k_ir_init_reg_rs; //# rear
		}
	}

	while (vals->reg != 0xff)
	{
		//# delay
		if (vals->reg == DELAY) {
			Task_sleep(vals->val);
			vals++;
			continue;
		}

		/* Write the common settings for all the modes */
		recnt = WRITE_RETRY_CNT;
		while(recnt--)
		{
			ret = dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR,
					vals->reg, vals->val);
			if(FVID2_SOK == ret)
				break;
			Task_sleep(5);
		}

		if (FVID2_SOK != ret) {
			//eprintf("%s: 0x%x, 0x%x\n", __func__, vals->reg, vals->val);
			break;
		}

		vals++;
	}

	if(ret == FVID2_SOK) {
		locked = max927x_check_lock(idx);
		if(locked) {
			s_size[idx] = SZ_720;
			ctrl_status_led(idx, VPS_ON);
			Vps_printf(" [ph3100k] %s #%d done!\n", __func__, idx);

			return FVID2_SOK;
		}
	}

	ctrl_status_led(idx, VPS_OFF);
	eprintf("%s #%d fail!\n", __func__, idx);

	return FVID2_EFAIL;
}

/*****************************************************************************
* @brief	Deserializer init/deinit function
* @section	DESC Description
*	- desc :
*****************************************************************************/
Int32 Vps_ph3100kSerdes_init(void)
{
	Int32 ret, i;

	if(d_init) {			//# init already
		return FVID2_SOK;
	}

	//# deserializer init
	for(i=(MAX_DEV_NUM-1); i>=0; i--)
	{
		ctrl_des_pwr(i, VPS_ON);
		ret = max9272_init(i);
		if(ret != FVID2_SOK) {
			return ret;
		}
	}

	//# camera module power on
	for(i=0; i<MAX_DEV_NUM; i++) {
		ctrl_main_pwr(i, VPS_ON);
		Task_sleep(50);
	}
	Task_sleep(30);			//# wait after camera module power on

	//# init config
	for(i=0; i<MAX_DEV_NUM; i++) {
		s_init[i] = 0;
		s_size[i] = SZ_720;
	}
	d_init = 1;

	return FVID2_SOK;
}

Int32 Vps_ph3100kSerdes_deinit(void)
{
	int i;

	if(!d_init) {			//# exit already
		return FVID2_SOK;
	}

	//# serdes power down
	for(i=0; i<MAX_DEV_NUM; i++)
	{
		ctrl_status_led(i, VPS_OFF);
		ctrl_des_pwr(i, VPS_OFF);
		ctrl_main_pwr(i, VPS_OFF);
	}

	d_init = 0;

	return FVID2_SOK;
}

/*****************************************************************************
* @brief	Sensor init/deinit function
* @section	DESC Description
*	- desc :
*****************************************************************************/
Int32 Vps_ph3100kInitSensor(Vps_ph3100kHandleObj *pObj)
{
	Int32 ret=FVID2_SOK;
	int idx = pObj->handleId;

	if(s_init[idx]) {		//# init already
		return FVID2_SOK;
	}

	eq_lv[idx] = pObj->serdes_eq;
	ret = ph3100k_sensor_init(idx);

	return ret;
}

Int32 Vps_ph3100kDeinitSensor(Vps_ph3100kHandleObj *pObj)
{
	#if 0	//# not used currently
	int i;

	for(i=0; i<MAX_DEV_NUM; i++) {
		ctrl_status_led(i, VPS_OFF);
	}
	#endif

	return FVID2_SOK;
}

/*****************************************************************************
* @brief	Vps_ph3100kRegWriteIoctl function
* @section	DESC Description
*	- desc : Writes to device registers.
*****************************************************************************/
Int32 Vps_ph3100kRegWriteIoctl(Vps_ph3100kHandleObj *pObj,
							   Vps_VideoDecoderRegRdWrParams *pPrm)
{
	Int32 ret = FVID2_SOK;
	Int32 recnt;
	Int32 idx;

	/* Check for errors */
	if (NULL == pPrm) {
		GT_0trace(VpsDeviceTrace, GT_ERR, "Null pointer/Invalid arguments\n");
		return FVID2_EBADARGS;
	}

	//# deviceNum field is command
	//# regAddr field is device number
	idx = pPrm->regAddr;
	if(pPrm->deviceNum == DEV_PWR_OFF) {		//# power off
		Vps_ph3100kSerdes_deinit();
		return FVID2_SOK;
	}

	max927x_select(pPrm->deviceNum);

	recnt = WRITE_RETRY_CNT;
	while(recnt--)
	{
		ret = dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, pPrm->regAddr, pPrm->regValue);
		if(FVID2_SOK == ret) {
			break;
		}
	}

	return (ret);
}

/*****************************************************************************
* @brief	Vps_ph3100kRegReadIoctl function
* @section	DESC Description
*	- desc : Reads from device registers.
*****************************************************************************/
Int32 Vps_ph3100kRegReadIoctl(Vps_ph3100kHandleObj *pObj,
							  Vps_VideoDecoderRegRdWrParams *pPrm)
{
	Int32	ret = FVID2_SOK;
	int idx;

	/* Check for errors */
	if (NULL == pPrm) {
		GT_0trace(VpsDeviceTrace, GT_ERR, "Null pointer/Invalid arguments\n");
		ret = FVID2_EBADARGS;
	}

	//# deviceNum field is command
	//# regAddr field is device number
	idx = pPrm->regAddr;
	if(pPrm->deviceNum == DEV_R_STATE) {
		pPrm->regValue = s_init[idx];
		return FVID2_SOK;
	}

	max927x_select(pPrm->deviceNum);
	ret = dev_i2c_read8(PH3100K_I2C_ID, PH3100K_I2C_ADDR, pPrm->regAddr, &pPrm->regValue);

	return (ret);
}

/*****************************************************************************
* @brief	Vps_ph3100kGetVideoStatusIoctl function
* @section	DESC Description
*	- desc : Gets the video status of the detected video.
*            Only used video loss detect
*****************************************************************************/
Int32 Vps_ph3100kGetVideoStatusIoctl(Vps_ph3100kHandleObj *pObj,
									 Vps_VideoDecoderVideoStatusParams *pPrm,
									 Vps_VideoDecoderVideoStatus *pStatus)
{
	pStatus->isVideoDetect = s_init[pObj->handleId];

	return FVID2_SOK;
}

Int32 Vps_ph3100kSensorDetect(Vps_ph3100kHandleObj *pObj)
{
	Int32 locked, idx;

    if(!d_init) {
		return FVID2_SOK;
	}

    idx = pObj->handleId;
	if(s_init[idx])
	{
		locked = max927x_check_lock(idx);
		if(!locked) {
			ctrl_status_led(idx, VPS_OFF);
		}
	}
	else
	{
		locked = ph3100k_check_sensor(idx);
		if(locked) {
			ctrl_pwr_reset(idx);
			ph3100k_sensor_init(idx);
		}
	}

	return FVID2_SOK;
}

/*****************************************************************************
* @brief	Vps_ph3100kSetVideoModeIoctl function
* @section	DESC Description
*	- desc : Sets the required video standard and output formats depending
*            on requested parameters.
*****************************************************************************/
Int32 Vps_ph3100kSetVideoModeIoctl(Vps_ph3100kHandleObj *pObj,
								   Vps_VideoDecoderVideoModeParams *pPrm)
{
	Int32 ret = FVID2_SOK;
	struct regval_list *vals;
	Int32 recnt;
	UInt16 win_size;

	if(!s_init[pObj->handleId]) {
		return FVID2_SOK;
	}

	win_size=s_size[pObj->handleId];

	switch (pPrm->standard)
    {
        case FVID2_STD_D1:
			if(win_size == SZ_480)
				return ret;

			vals = (struct regval_list *)ph3100k_d1;
			win_size = SZ_480;
            break;

		case FVID2_STD_720P_60:
        default:
    		if(win_size == SZ_720)
        		return ret;

			vals = (struct regval_list *)ph3100k_720p;
			win_size = SZ_720;
            break;
    }

    while (vals->reg != TERM)
	{
		//# delay
		if (vals->reg == DELAY) {
			Task_sleep(vals->val);
			vals++;
			continue;
		}

		recnt = WRITE_RETRY_CNT;
		while(recnt--)
		{
			ret = dev_i2c_write8(PH3100K_I2C_ID, PH3100K_I2C_ADDR,
					vals->reg, vals->val);
			if(FVID2_SOK == ret)
				break;
		}

		if (FVID2_SOK != ret) {
			eprintf("%s: 0x%x, 0x%x\n", __func__, vals->reg, vals->val);
			break;
		}

		vals++;
	}

	if (FVID2_SOK == ret) {
		s_size[pObj->handleId] = win_size;
		Vps_printf(" [ph3100k] set %s done(%d)\n", (win_size==SZ_720)?"720P":"480P", ret);
	}

	return (ret);
}

/*****************************************************************************
* @brief	Vps_ph3100kGetChipIdIoctl function
* @section	DESC Description
*	- desc : Gets PH3100K Chip ID and revision ID.
*****************************************************************************/
Int32 Vps_ph3100kGetChipIdIoctl(Vps_ph3100kHandleObj *pObj,
								Vps_VideoDecoderChipIdParams *pPrm,
								Vps_VideoDecoderChipIdStatus *pStatus)
{
	Int32 ret = FVID2_SOK;
	#if 0	//# skip read for start on low temperature
	UInt16 devId=0;

	ret = dev_i2c_read16(0x00, &devId);
	if(ret != FVID2_SOK)
		ctrl_status_led(pObj->handleId, VPS_OFF);

	pStatus->chipId = devId;
	#else
	pStatus->chipId = 0x3100;
	#endif

	pStatus->chipRevision = 0;
	pStatus->firmwareVersion = 0;

	pPrm->deviceNum = pObj->handleId;

	return ret;
}

/*****************************************************************************
* @brief	Vps_ph3100kResetIoctl function
* @section	DESC Description
*	- desc : Resets the PH3100K.
*****************************************************************************/
Int32 Vps_ph3100kResetIoctl(Vps_ph3100kHandleObj *pObj)
{
	Int32 ret = FVID2_SOK;

	//dprintf("%s done (%d)\n", __func__, ret);

	return (ret);
}

/*****************************************************************************
* @brief	Vps_ph3100kStartIoctl function
* @section	DESC Description
*	- desc : Starts PH3100K.
*****************************************************************************/
Int32 Vps_ph3100kStartIoctl(Vps_ph3100kHandleObj *pObj)
{
	Int32 ret = FVID2_SOK;

	//dprintf("%s done (%d)\n", __func__, ret);

	return (ret);
}

/*****************************************************************************
* @brief	Vps_ph3100kStopIoctl function
* @section	DESC Description
*	- desc : Stops PH3100K.
*****************************************************************************/
Int32 Vps_ph3100kStopIoctl(Vps_ph3100kHandleObj *pObj)
{
	Int32           ret = FVID2_SOK;

	//dprintf("%s done (%d)\n", __func__, ret);

	return (ret);
}

/*****************************************************************************
* @brief	Pin Mux for PH3100K driver
* @section	DESC Description
*	- desc :
*****************************************************************************/
void Vps_ph3100kPinMux(void)
{
	//# ctrl gpio - UDX
	//# serdes #0
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B7C) = 0x60080;   //# gp3[16], serdes #0 power_en
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B5C) = 0x60080;   //# gp3[8], 9272 pdn
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B38) = 0x60080;   //# gp2[31], 9272 led
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B84) = 0x60080;   //# gp3[18], 9272 lock
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B80) = 0x60080;   //# gp3[17], sensor ready (to app)

	//# serdes #1
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B30) = 0x60080;   //# gp2[29], serdes #1 power_en
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B3C) = 0x60080;   //# gp3[0], 9272 pdn
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B68) = 0x60080;   //# gp3[11], 9272 led
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B4C) = 0x60080;   //# gp3[4], 9272 lock
	REG32(CSL_TI8107_CTRL_MODULE_BASE + 0x0B74) = 0x60080;   //# gp3[14], sensor ready (to app)

	//# default control
	//# serdes #0
	vps_gpio_direction_output(gio[0].pwr, 0);		//# cam pwr : off
	vps_gpio_direction_output(gio[0].pdn, 0);		//# diserialize power : disable, must disable
	vps_gpio_direction_output(gio[0].led, 0);		//# sensor led : off
	vps_gpio_direction_input(gio[0].lock);			//# serdes lock
	vps_gpio_direction_input(GIO(3,17));			//# sensor ready (to A8), complement

	//# serdes #1
	vps_gpio_direction_output(gio[1].pwr, 0);		//# cam pwr : off
	vps_gpio_direction_output(gio[1].pdn, 0);
	vps_gpio_direction_output(gio[1].led, 0);
	vps_gpio_direction_input(gio[1].lock);
	vps_gpio_direction_input(GIO(3,14));
}
