/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_ctrl.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.04.01 : First Created
 *     - 2013.08.21 : Modified by sksung
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <glob.h>
#include <errno.h>

#include "ti_vsys.h"
#include "ti_vcam.h"
#include "ti_vcap.h"
#include "ti_venc.h"
#include "ti_vdis.h"

#include "dev_common.h"
#include "dev_wifi.h"
#include "dev_env.h"
#include "dev_disk.h"

#include "ucx_main.h"
#include "app_gui.h"
#include "app_set.h"
#include "app_util.h"
#include "app_ctrl.h"
#include "app_snd.h"
#include "app_rec.h"
#include "app_dev.h"
#include "app_tzone.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define DEF_LOCAL_TIME		(9)

#define FLOOR_ALIGN(val, align)  (((val) / (align)) * (align))

#define VDIS_ON		"1"
#define VDIS_OFF	"0"
#define VDIS_SYSFSCMD_SETVENC	"/sys/devices/platform/vpss/display%d/enabled"
#define VDIS_SYSFSCMD_SETGRPX	"/sys/devices/platform/vpss/graphics%d/enabled"

#define CAP_DEV_PWR_OFF		0x10
/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/
static inline int Vdis_sysfsWrite(char *fileName, char *val)
{
    FILE *fp;
    int ret;

    fp = fopen(fileName, "w");
    if (fp == NULL) {
        eprintf("Failed to open %s for writing\n", fileName);
        return -1;
    }
    ret = fwrite(val, strlen(val) + 1, 1, fp);
    if ( ret != 1) {
        eprintf("Failed to write sysfs variable %s to %s\n", fileName, val);
        fclose(fp);
        return -1;
    }
    fflush(fp);
    fclose(fp);
    return 0;
}

static void Vdis_sysfsCmd(char *cmd, int id, char *value)
{
	char buf[100];

	sprintf(buf, cmd, id);
	Vdis_sysfsWrite(buf, value);
}

/*****************************************************************************
 * @brief    tv-out control function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
void ctrl_tvo_enable(int enable)
{
	if(enable)
	{
		if(!app_cfg->state.tvo) {
			Vdis_swMs_pause(VDIS_DEV_SD, 0);
			Vdis_sysfsCmd(VDIS_SYSFSCMD_SETVENC, 2, VDIS_ON);
			Vdis_sysfsCmd(VDIS_SYSFSCMD_SETGRPX, 2, VDIS_ON);
			Vdis_startDrv(VDIS_DEV_SD);
			app_cfg->state.tvo = 1;
		}
	}
	else {
		if(app_cfg->state.tvo) {
			Vdis_stopDrv(VDIS_DEV_SD);
			Vdis_sysfsCmd(VDIS_SYSFSCMD_SETGRPX, 2, VDIS_OFF);
			Vdis_sysfsCmd(VDIS_SYSFSCMD_SETVENC, 2, VDIS_OFF);
			Vdis_swMs_pause(VDIS_DEV_SD, 1);
			app_cfg->state.tvo = 0;
		}
	}
}

/*****************************************************************************
* @brief    SW mosaic(Video layout) control function
* @section  DESC Description
*   - desc
*****************************************************************************/
void ctrl_swMs_reset()
{
	VDIS_MOSAIC_S vdMosaicParam;
	int out_wi, out_he, wi_align;
	int win_id, win_wi, win_he;

	out_wi = 720;
	out_he = 480;
	wi_align = 8;

	win_wi = FLOOR_ALIGN(out_wi, wi_align);
	win_he = out_he;

	win_id = 0;
	vdMosaicParam.chnMap[win_id] 			= VDIS_CHN_INVALID;
	vdMosaicParam.winList[win_id].start_X 	= 0;
	vdMosaicParam.winList[win_id].start_Y 	= 0;
	vdMosaicParam.winList[win_id].width 	= win_wi;
	vdMosaicParam.winList[win_id].height 	= win_he;
	vdMosaicParam.useLowCostScaling[win_id] = FALSE;
	win_id++;

	win_wi = 288;
	win_he = (out_he*win_wi)/out_wi;

	vdMosaicParam.chnMap[win_id] 			= VDIS_CHN_INVALID;
	vdMosaicParam.winList[win_id].start_X 	= (out_wi - win_wi);
	vdMosaicParam.winList[win_id].start_Y 	= 0;//(out_he - win_he);
	vdMosaicParam.winList[win_id].width 	= win_wi;
	vdMosaicParam.winList[win_id].height 	= win_he;
	vdMosaicParam.useLowCostScaling[win_id] = FALSE;

	Vdis_setMosaicParams(VDIS_DEV_SD, &vdMosaicParam);
}

int ctrl_swMs_set(int win_num, int ch, int ch_swap)
{
	VDIS_MOSAIC_S vdMosaicParam;
	int out_wi, out_he, wi_align;
	int win_id, win_wi, win_he, offset;

	out_wi = 720;
	out_he = 480;
	wi_align = 8;
	offset = 16;

	vdMosaicParam.displayWindow.width		= out_wi;
	vdMosaicParam.displayWindow.height		= out_he;
	vdMosaicParam.numberOfWindows 			= win_num;
	vdMosaicParam.displayWindow.start_X		= 0;
	vdMosaicParam.displayWindow.start_Y		= 0;
	vdMosaicParam.onlyCh2WinMapChanged		= FALSE;
	vdMosaicParam.outputFPS 				= 30;

	out_wi -= offset*2;
	out_he -= offset*2;

	win_id = 0;
	if(win_num == 2)
	{
		win_wi = FLOOR_ALIGN(out_wi, wi_align);
    	win_he = out_he;
        if(ch_swap)
    		vdMosaicParam.chnMap[win_id] = ch--;
    	else
            vdMosaicParam.chnMap[win_id] = ch++;
    	vdMosaicParam.winList[win_id].start_X 	= offset;
		vdMosaicParam.winList[win_id].start_Y 	= offset;
		vdMosaicParam.winList[win_id].width 	= win_wi;
		vdMosaicParam.winList[win_id].height 	= win_he;
		vdMosaicParam.useLowCostScaling[win_id] = FALSE;
		win_id++;

		win_wi = 288;
    	win_he = (out_he*win_wi)/out_wi;
    	vdMosaicParam.chnMap[win_id] = ch++;
    	vdMosaicParam.winList[win_id].start_X 	= offset + (out_wi - win_wi);
		vdMosaicParam.winList[win_id].start_Y 	= offset;
		vdMosaicParam.winList[win_id].width 	= win_wi;
		vdMosaicParam.winList[win_id].height 	= win_he;
		vdMosaicParam.useLowCostScaling[win_id] = FALSE;
	}
	else //# (win_num == 1)
	{
		win_wi = FLOOR_ALIGN(out_wi, wi_align);
		win_he = out_he;
		vdMosaicParam.chnMap[win_id] = ch;
    	vdMosaicParam.winList[win_id].start_X 	= offset;
		vdMosaicParam.winList[win_id].start_Y 	= offset;
		vdMosaicParam.winList[win_id].width 	= win_wi;
		vdMosaicParam.winList[win_id].height 	= win_he;
		vdMosaicParam.useLowCostScaling[win_id] = FALSE;
	}

	Vdis_setMosaicParams(VDIS_DEV_SD, &vdMosaicParam);

	return 0;
}

/*****************************************************************************
 * @brief    get version function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int ctrl_get_isp_version(char *version)
{
	unsigned int ver;

	Vcam_get_alg_version(&ver);
	sprintf(version, "%02d.%02d.%02d", (ver>>16)&0xF, (ver>>8)&0xF, ver&0xF);

	return 0;
}

#define MAX_HW_VER (0x07)
int ctrl_get_hw_version(char *version)
{
    int ver;
	float rev;

	ver = dev_get_board_info();
	if(ver > MAX_HW_VER){
		sprintf(version, "Rev %.1f", rev);
	}
	else{
		rev = (float)(ver+1.)/10;
		sprintf(version, "Rev %.1f", rev);
	}

	return 0;
}

/*****************************************************************************
* @brief    Sensor control function
* @section  DESC Description
*   - desc
*****************************************************************************/
int ctrl_hdcam_state(int ch)
{
	int     ret;
    UInt8   reg_val;
	if(ch == 0)			//# imx122
	{
		ret = Vcam_get_sensor_reg(0x20, &reg_val);
		if(ret < 0)
			return -1;
		if(reg_val != 0x3c)
			return -1;
	}
	else if(ch == 1)	//# ph1100k
	{
		//# todo : read lock signal

		ret = Vcap_get_video_reg(2, 0x04, &reg_val);
		if(ret < 0)
			return -1;
		if(!(reg_val & (1<<7)))
			return -1;
	}

	dprintf("detect sensor CH%d\n", ch);

	return 0;
}

#ifdef FLIKER
int ctrl_hdcam_frame_set(int ch, int frame)
{
	if(frame!=30 && frame!=25 && frame!=20 && frame!=15 && frame!=12 && frame!=10 && frame!=7 && frame!=5) {
		eprintf("invaild params - ch%d: %d!\n", ch, frame);
		return -1;
	}

	Vcap_set_video_reg(ch, 0x03, 0x00);
#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x4F, 0x08);	//# 60Hz
#else
		Vcap_set_video_reg(ch, 0x4F, 0x04);	//# 50Hz
#endif
#endif
	if(frame==30) {
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x41, 0x01);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#else
		Vcap_set_video_reg(ch, 0x41, 0x02);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#endif

#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x51, 0x05);
		Vcap_set_video_reg(ch, 0x52, 0x79);
		Vcap_set_video_reg(ch, 0x5A, 0xBB);
		Vcap_set_video_reg(ch, 0x5B, 0x80);
#else
		Vcap_set_video_reg(ch, 0x53, 0x04);
		Vcap_set_video_reg(ch, 0x54, 0x8D);
		Vcap_set_video_reg(ch, 0x5D, 0xE1);
		Vcap_set_video_reg(ch, 0x5E, 0x00);
#endif
		Vcap_set_video_reg(ch, 0x5F, 0x04);
		Vcap_set_video_reg(ch, 0x60, 0x65);
#endif
	}
	if(frame==25) {
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x41, 0x06);
		Vcap_set_video_reg(ch, 0x42, 0x37);
#else
		Vcap_set_video_reg(ch, 0x41, 0x0C);
		Vcap_set_video_reg(ch, 0x42, 0x37);
#endif

#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x51, 0x06);
		Vcap_set_video_reg(ch, 0x52, 0x90);
		Vcap_set_video_reg(ch, 0x5A, 0x9C);
		Vcap_set_video_reg(ch, 0x5B, 0x40);
#else
		Vcap_set_video_reg(ch, 0x53, 0x05);
		Vcap_set_video_reg(ch, 0x54, 0x79);
		Vcap_set_video_reg(ch, 0x5D, 0xBB);
		Vcap_set_video_reg(ch, 0x5E, 0x80);
#endif
		Vcap_set_video_reg(ch, 0x5F, 0x03);
		Vcap_set_video_reg(ch, 0x60, 0xA9);
#endif
	}
	else if(frame==20) {
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x41, 0x03);
		Vcap_set_video_reg(ch, 0x42, 0x16);
#else
        Vcap_set_video_reg(ch, 0x42, 0x0B);
		Vcap_set_video_reg(ch, 0x41, 0x03);
#endif

#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x51, 0x08);
		Vcap_set_video_reg(ch, 0x52, 0x31);
		Vcap_set_video_reg(ch, 0x5A, 0x7D);
		Vcap_set_video_reg(ch, 0x5B, 0x00);
#else
		Vcap_set_video_reg(ch, 0x53, 0x06);
		Vcap_set_video_reg(ch, 0x54, 0xD3);
		Vcap_set_video_reg(ch, 0x5D, 0x96);
		Vcap_set_video_reg(ch, 0x5E, 0x00);
#endif
		Vcap_set_video_reg(ch, 0x5F, 0x02);
		Vcap_set_video_reg(ch, 0x60, 0xEE);
#endif
	}
	else if(frame==15) {
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x41, 0x02);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#else
		Vcap_set_video_reg(ch, 0x41, 0x04);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#endif

#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x51, 0x0B);
		Vcap_set_video_reg(ch, 0x52, 0x02);
		Vcap_set_video_reg(ch, 0x5A, 0x5D);
		Vcap_set_video_reg(ch, 0x5B, 0xC0);
#else
		Vcap_set_video_reg(ch, 0x53, 0x09);
		Vcap_set_video_reg(ch, 0x54, 0x24);
		Vcap_set_video_reg(ch, 0x5D, 0x70);
		Vcap_set_video_reg(ch, 0x5E, 0x80);
#endif
		Vcap_set_video_reg(ch, 0x5F, 0x02);
		Vcap_set_video_reg(ch, 0x60, 0x32);
#endif
	}
	else if(frame==12) {
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x41, 0x06);
		Vcap_set_video_reg(ch, 0x42, 0x37);
#else
		Vcap_set_video_reg(ch, 0x41, 0x07);
		Vcap_set_video_reg(ch, 0x42, 0x10);
#endif

#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x51, 0x0D);
		Vcap_set_video_reg(ch, 0x52, 0x4C);
		Vcap_set_video_reg(ch, 0x5A, 0x4D);
		Vcap_set_video_reg(ch, 0x5B, 0xEC);
#else
		Vcap_set_video_reg(ch, 0x53, 0x0B);
		Vcap_set_video_reg(ch, 0x54, 0x02);
		Vcap_set_video_reg(ch, 0x5D, 0x5D);
		Vcap_set_video_reg(ch, 0x5E, 0x81);
#endif
		Vcap_set_video_reg(ch, 0x5F, 0x01);
		Vcap_set_video_reg(ch, 0x60, 0xD3);
#endif
	}
	else if(frame==10) {
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x41, 0x03);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#else
		Vcap_set_video_reg(ch, 0x41, 0x06);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#endif

#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x51, 0x10);
		Vcap_set_video_reg(ch, 0x52, 0x84);
		Vcap_set_video_reg(ch, 0x5A, 0x3E);
		Vcap_set_video_reg(ch, 0x5B, 0x80);
#else
		Vcap_set_video_reg(ch, 0x53, 0x0D);
		Vcap_set_video_reg(ch, 0x54, 0xA7);
		Vcap_set_video_reg(ch, 0x5D, 0x4B);
		Vcap_set_video_reg(ch, 0x5E, 0x00);
#endif
		Vcap_set_video_reg(ch, 0x5F, 0x01);
		Vcap_set_video_reg(ch, 0x60, 0x77);
#endif
	}
	else if(frame==7) {
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x5F, 0x04);
		Vcap_set_video_reg(ch, 0x60, 0x0B);
#else
		Vcap_set_video_reg(ch, 0x41, 0x08);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#endif

#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x51, 0x16);
		Vcap_set_video_reg(ch, 0x52, 0x42);
		Vcap_set_video_reg(ch, 0x5A, 0x2E);
		Vcap_set_video_reg(ch, 0x5B, 0xE0);
#else
		Vcap_set_video_reg(ch, 0x53, 0x12);
		Vcap_set_video_reg(ch, 0x54, 0x49);
		Vcap_set_video_reg(ch, 0x5D, 0x38);
		Vcap_set_video_reg(ch, 0x5E, 0x40);
#endif
		Vcap_set_video_reg(ch, 0x5F, 0x01);
		Vcap_set_video_reg(ch, 0x60, 0x19);
#endif
	}
	else if(frame==5) {
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x41, 0x06);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#else
		Vcap_set_video_reg(ch, 0x41, 0x0C);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
#endif

#ifdef FLIKER
#if FLIKER_MODE_60HZ
		Vcap_set_video_reg(ch, 0x51, 0x21);
		Vcap_set_video_reg(ch, 0x52, 0x08);
		Vcap_set_video_reg(ch, 0x5A, 0x1F);
		Vcap_set_video_reg(ch, 0x5B, 0x40);
#else
		Vcap_set_video_reg(ch, 0x53, 0x1B);
		Vcap_set_video_reg(ch, 0x54, 0xAC);
		Vcap_set_video_reg(ch, 0x5D, 0x25);
		Vcap_set_video_reg(ch, 0x5E, 0x80);
#endif
		Vcap_set_video_reg(ch, 0x5F, 0x00);
		Vcap_set_video_reg(ch, 0x60, 0xBB);
#endif
	}

	return 0;
}
#else
int ctrl_hdcam_frame_set(int ch, int frame)
{
	if(frame!=30 && frame!=25 && frame!=20 && frame!=15 && frame!=10) {
		eprintf("invaild params - ch%d: %d!\n", ch, frame);
		return -1;
	}

	Vcap_set_video_reg(ch, 0x03, 0x00);
	if(frame==30) {
		Vcap_set_video_reg(ch, 0x41, 0x01);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
	}
	if(frame==25) {
		Vcap_set_video_reg(ch, 0x41, 0x06);
		Vcap_set_video_reg(ch, 0x42, 0x37);
	}
	else if(frame==20) {
		Vcap_set_video_reg(ch, 0x41, 0x03);
		Vcap_set_video_reg(ch, 0x42, 0x16);
	}
	else if(frame==15) {
		Vcap_set_video_reg(ch, 0x41, 0x02);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
	}
	else if(frame==10) {
		Vcap_set_video_reg(ch, 0x41, 0x03);
		Vcap_set_video_reg(ch, 0x42, 0x0B);
	}

	return 0;
}
#endif

int ctrl_hdcam_mirror(int ch, int value)
{
	//# only phX100k, mirror 0: VH, 1: V, 2: H, 3: off
//	ch = 1 - ch;
	Vcap_set_video_reg(ch, 0x03, 0x00);
	Vcap_set_video_reg(ch, 0x05, value);

	return 0;
}

int ctrl_hdcam_brightness(int dev, int value)
{
	int max_value, min_value;
	int offset = 10;

	if (dev < 0 || dev > 1)
		return -1;

	if (value < 1 || value > 5) {
		eprintf("the brightness was out of range\n");
		return -1;
	}

    dev = 1 - dev;	//CAM1 <-> CAM2(later ti_tools\hdvpss_01_00_01_37\packages\ti\psp\devices\ph3100k\src\vpsdrv_ph3100kI2c.c line 56, 57 change)

	if (dev == 1) {	//# front cam
		max_value = 0x73 + ((value - 3) * offset);
		min_value = 0x68 + ((value - 3) * offset);
	} else if (dev == 0) {	//# rear cam
		max_value = 0x70 + ((value - 3) * offset);
		min_value = 0x60 + ((value - 3) * offset);
	} else {
		return 0;
	}

	Vcap_set_video_reg(dev, 0x03, 0x04);
	Vcap_set_video_reg(dev, 0x3B, max_value);
	Vcap_set_video_reg(dev, 0x3D, max_value);
	Vcap_set_video_reg(dev, 0x3C, min_value);
	Vcap_set_video_reg(dev, 0x3E, min_value);

	return 0;
}

int ctrl_hdcam_pwroff(void)
{
	#if 0		//# ctrl by serdes driver
	//# CTL_W_POWER (all sensor)
	Vcap_set_video_reg(CAP_DEV_PWR_OFF, 0, 0);
	#else		//# ctrl by gpio
	gpio_set_value(HDSENS0_PWR_GIO, 0);
	gpio_set_value(HDSENS1_PWR_GIO, 0);
	#endif

	return 0;
}

int ctrl_hdcam_pwron(void)
{
	//# ctrl by gpio
	gpio_set_value(HDSENS0_PWR_GIO, 1);
    OSA_waitMsecs(10);
	gpio_set_value(HDSENS1_PWR_GIO, 1);

	return 0;
}

/*****************************************************************************
* @brief    Encoder control function
* @section  DESC Description
*   - desc
*****************************************************************************/
int ctrl_enc_br_set(int ch, int bitrate)
{
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };

	/*if(bitrate < 100) {
		eprintf("invaild params - ch%d: %d!\n", ch, bitrate);
		return -1;
	}*/

	params.targetBitRate = bitrate*1000;

	return Venc_setDynamicParam(ch, 0, &params, VENC_BITRATE);
}

int ctrl_enc_fr_set(int ch, int framerate)
{
    VENC_CHN_DYNAMIC_PARAM_S params = { 0 };
    int default_fps = DEFAULT_FPS;

    params.frameRate        = framerate;

    Venc_setInputFrameRate(ch, default_fps);
    //Venc_setInputFrameRate(ch, framerate);

    Venc_setDynamicParam(ch, 0, &params, VENC_FRAMERATE);

    return 0;
}

int ctrl_enc_gop_set(int ch, int gop)
{
    VENC_CHN_DYNAMIC_PARAM_S params = { 0 };

    params.intraFrameInterval = gop;

    return Venc_setDynamicParam(ch, 0, &params, VENC_IPRATIO);
}

int ctrl_enc_rc_set(int ch, int rc, int br)
{
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };

	if(rc == RATE_CTRL_VBR)
	{
		params.qpMax 	= 45;
		params.qpInit 	= -1;

		if(br >= 8000) {
			params.qpMin 	= 22;		//# for VBR setting (4M~8.5M when bitrate was 8M)
		}
		else if(br >= 6000) {
			params.qpMin 	= 26;		//# for VBR setting (1.8M~5.6M when bitrate was 5M)
		}
		else if(br >= 2000) {
			params.qpMin 	= 28;
		}
		else {
			params.qpMin 	= 30;
		}
	}
	else
	{
		params.qpMin	= 10;
		params.qpMax 	= 40;
		params.qpInit 	= -1;
	}

	return Venc_setDynamicParam(ch, 0, &params, VENC_QPVAL_P);

}

int ctrl_enc_motion_set(int ch, int level)
{
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };


	if(level == 0) {
		params.bMotionEnable = 0;
	}
	else
	{
		params.bMotionEnable = 1;
    	params.MotionLevel = level-1;	//# 0:low ~ 2:high
    	params.MotionBlock = 0xfff;		//# 3x4
    	/*
         | 1 2 4 8 |  => 1st Byte
         | 1 2 4 8 |  => 2nd Byte
         | 1 2 4 8 |  => 3rd Byte
         */
	}

	Venc_setDynamicParam(ch, 0, &params, VENC_MDPARAM);

	return 0;
}


static int ctrl_set_fps(int mode)
{
	int i, ret = SOK;
	int fps, br;
	app_ch_cfg_t* ch;


	if(app_cfg->state.cap)
	{
		app_rec_stop();

		for(i = 0; i < MAX_CH_NUM; i++)
		{
			if(mode == MODE_PARKING)
				ch = &app_set->ch_prk[i];
			else
				ch = &app_set->ch[i];

			fps = get_fps_val(ch->framerate);
			app_cfg->ifrm[i].fr = fps;

            //#--- sensor framerate
            //if(ctrl_hdcam_frame_set(i, fps) != SOK)
            if(ctrl_hdcam_frame_set(i, DEFAULT_FPS) != SOK)
            {
                eprintf("Ch %02d sensor frame setting failed!!!\n", i+1);
				ret = EFAIL;
                goto frm_err;
            }

            //#--- set enc framerate
            if(ctrl_enc_fr_set(i, fps) != SOK)
            {
                eprintf("Ch %02d frame rate setting failed!!!\n", i+1);
				ret = EFAIL;
                goto frm_err;
            }

            //#--- set enc i interval
            if(ctrl_enc_gop_set(i, fps) != SOK)
            {
                eprintf("Ch %02d I-frame interval setting failed!!!\n", i+1);
				ret = EFAIL;
                goto frm_err;
            }

            //#--- set bitrate
            br = get_bitrate_val(ch->quality, ch->resol);
            app_cfg->ifrm[i].br = (br * fps)/DEFAULT_FPS;

            if(ctrl_enc_br_set(i, app_cfg->ifrm[i].br) != SOK)
            {
                eprintf("Ch %02d bitrate setting failed!!!\n", i+1);
				ret = EFAIL;
                goto frm_err;
            }

            //#--- set qp
            if(ctrl_enc_rc_set(i, ch->rate_ctrl, app_cfg->ifrm[i].br) != SOK)
            {
                eprintf("Ch %02d QP setting failed!!!\n", i+1);
				ret = EFAIL;
                goto frm_err;
            }
		}
	}

frm_err:

	Vsys_datetime_init();	//# m3 Date/Time init
	if(!app_cfg->state.mmc_err)
        app_rec_start();

    return ret;

}

static int ctrl_set_bps(int mode)
{
	int i;
	app_ch_cfg_t* ch;


	if(app_cfg->state.cap)
	{
		int br, fps;
		for(i = 0; i < MAX_CH_NUM; i++)
		{
			if(mode == MODE_PARKING)
				ch = &app_set->ch_prk[i];
			else
				ch = &app_set->ch[i];

			fps = get_fps_val(ch->framerate);

            //#--- set bitrate
            br = get_bitrate_val(ch->quality, ch->resol);
            app_cfg->ifrm[i].br = (br * fps)/DEFAULT_FPS;

            if(ctrl_enc_br_set(i, app_cfg->ifrm[i].br) != SOK)
            {
                eprintf("Ch %02d bitrate setting failed!!!\n", i+1);
                return EFAIL;
            }

            //#--- set qp
            if(ctrl_enc_rc_set(i, ch->rate_ctrl, app_cfg->ifrm[i].br) != SOK)
            {
                eprintf("Ch %02d QP setting failed!!!\n", i+1);
                return EFAIL;
            }

		}
	}

	return SOK;
}

int ctrl_set_enc_prm(int mode, int fps_idx, int bps_idx)
{
	int i, ret = SOK;

	if(fps_idx > FPS_MAX || fps_idx < FPS_30 || bps_idx > MAX_QUALITY || bps_idx < Q_HIGH)
		return EFAIL;

	if(mode == MODE_PARKING)
	{
		if(app_set->ch_prk[0].framerate != fps_idx)
		{
			for(i = 0; i < MAX_CH_NUM; i++)
			{
				app_set->ch_prk[i].framerate 	= fps_idx;
				app_set->ch_prk[i].quality 		= bps_idx;
			}

			if(app_cfg->state.park)
				ret = ctrl_set_fps(mode);
		}
		else if (app_set->ch_prk[0].quality != bps_idx)
		{
			for(i = 0; i < MAX_CH_NUM; i++)
				app_set->ch_prk[i].quality 		= bps_idx;

			if(app_cfg->state.park)
				ret = ctrl_set_bps(mode);
		}
	}
	else
	{
		if(app_set->ch[0].framerate != fps_idx)
		{
			for(i = 0; i < MAX_CH_NUM; i++)
			{
				app_set->ch[i].framerate 	= fps_idx;
				app_set->ch[i].quality 		= bps_idx;
			}

			if(!app_cfg->state.park)
				ret = ctrl_set_fps(mode);
		}
		else if (app_set->ch[0].quality != bps_idx)
		{
			for(i = 0; i < MAX_CH_NUM; i++)
				app_set->ch[i].quality 		= bps_idx;

			if(!app_cfg->state.park)
				ret = ctrl_set_bps(mode);
		}
	}

	return ret;
}

/*****************************************************************************
* @brief    SWOSD control function
* @section  DESC Description
*   - desc
*****************************************************************************/
void ctrl_swosd_enable(int idx, int ch, int draw)
{

	Vsys_swOsdPrm swosdGuiPrm;

	swosdGuiPrm.streamId = ch;
	swosdGuiPrm.enable = draw;
	switch(idx)
	{
		case STE_GPS:
			Vsys_setSwOsdPrm(VSYS_SWOSD_GPS, &swosdGuiPrm);
			break;
		case STE_EVENT:
			Vsys_setSwOsdPrm(VSYS_SWOSD_EVENT, &swosdGuiPrm);
			break;
		case STE_MOTION:
			Vsys_setSwOsdPrm(VSYS_SWOSD_MOTION, &swosdGuiPrm);
			break;
		case STE_MODE:
			Vsys_setSwOsdPrm(VSYS_SWOSD_PARK, &swosdGuiPrm);
			break;
	}

	return;
}

void ctrl_swosd_speed(int value, int draw)
{
	Vsys_swOsdPrm swosdGuiPrm;

	swosdGuiPrm.streamId = 0;
	swosdGuiPrm.enable = draw;
	swosdGuiPrm.speed = value;

	Vsys_setSwOsdPrm(VSYS_SWOSD_SPEED, &swosdGuiPrm);
}

void ctrl_swosd_voltage(int value, int draw)
{
	Vsys_swOsdPrm swosdGuiPrm;

	swosdGuiPrm.streamId = 0;
	swosdGuiPrm.enable = draw;
	swosdGuiPrm.volt = value;

	Vsys_setSwOsdPrm(VSYS_SWOSD_VOLTAGE, &swosdGuiPrm);
}

void ctrl_swosd_gsensor(int x, int y, int z, int draw)
{
	Vsys_swOsdPrm swosdGuiPrm;

	swosdGuiPrm.streamId = 0;
	swosdGuiPrm.enable = draw;
	swosdGuiPrm.x = x;
	swosdGuiPrm.x = y;
	swosdGuiPrm.x = z;

	Vsys_setSwOsdPrm(VSYS_SWOSD_GSENS, &swosdGuiPrm);
}

void ctrl_swosd_userstr(char *str, int draw)
{
	Vsys_swOsdPrm swosdGuiPrm;

	swosdGuiPrm.streamId = 0;
	swosdGuiPrm.enable = draw;
	strcpy((char*)swosdGuiPrm.usrString, str);

	Vsys_setSwOsdPrm(VSYS_SWOSD_USERSTR, &swosdGuiPrm);
}

void ctrl_swosd_temperature(int value, int draw)
{
	Vsys_swOsdPrm swosdGuiPrm;

	swosdGuiPrm.streamId = 0;
	swosdGuiPrm.enable = draw;
	swosdGuiPrm.temp = value;

	Vsys_setSwOsdPrm(VSYS_SWOSD_TEMPERATURE, &swosdGuiPrm);
}

/*****************************************************************************
 * @brief    mmc state function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int ctrl_mmc_state(void)
{
	return dev_disk_check_mount(MMC_MOUNT_POINT);
}

/*****************************************************************************
 * @brief    int ctrl_mmc_check_fsck(void)
 * -n : no-op, check non-interactively without changing
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int ctrl_mmc_check_fsck(void)
{
/*
 * EXIT STATUS
 *   0 : No recoverable errors have been detected.
 *   1 : Recoverable errors have been detected.
 *   2 : Usage error. fsck.fat did not access the filesystem.(required reboot)
 */
	char *cmd = "/sbin/fsck.fat -n /dev/mmcblk0p1";

	return dev_execlp(cmd);
}

/*****************************************************************************
 * @brief    int ctrl_mmc_run_fsck(void)
 * -w : write changes to disk immediately
 * -a : automatically repair the filesystem
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int ctrl_mmc_run_fsck(void)
{
/* -a: Automatically repair the filesystem.
 * -w: Write changes to disk immediately.
 */
	char *cmd = "/sbin/fsck.fat -a -w /dev/mmcblk0p1";

	return dev_execlp(cmd);
}

/*****************************************************************************
 * @brief    int ctrl_mmc_check_partitions(int *num_part)
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int ctrl_mmc_check_partitions(void)
{
	FILE *part_f = NULL;

	char buf[256 + 1] = {0,};
	char name[128 + 1] = {0,};

	int ma, mi; //# major, minor
	int count = 0;

	unsigned long long sz;

	part_f = fopen("/proc/partitions", "r");
	if (part_f == NULL) {
		eprintf("couldn't open /proc/partitions\n");
		return -1;
	}

	/* major minor  #blocks  name
  	 * 	31     0     128 	 mtdblock0
 	 *  179    0   30915584  mmcblk0
 	 *  179    1   30915552  mmcblk0p1
     */
	while (fgets(buf, sizeof(buf) - 1, part_f) != NULL)
	{
		/* except \n */
		if (sscanf(buf, " %d %d %llu %128[^\n ]", &ma, &mi, &sz, name) != 4)
			continue;

		if (strncmp(name, "mmcblk0", 7) == 0) {
		    count += 1;
		}
	}
    fclose(part_f);

    return ((count == 2)?0:-1);
}

/*****************************************************************************
 * @brief    mmc partition check function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
 struct mmc_part_info mmc_part = {
	.part_no = 0,
	.part_type = 0,
	.part_size = 0
};

int ctrl_mmc_check_exfat(unsigned long *size)
{
	int ret = 0;

	if (size == NULL)
		return -1;

	ret = dev_disk_mmc_part_check_info(MMC_BLK_DEV_NAME, &mmc_part);
	if (ret) {
		eprintf("please check sd card!!\n");
		return -1;
	}

	if (mmc_part.part_size > MMC_SIZE_128GB) {
		eprintf("Not suppoted sd card (%lu MB)!!\n", mmc_part.part_size);
		return -1;
	}
	if (mmc_part.part_no != 1) {
		eprintf("Invalid partition sd card!!\n");
		return -1;
	}

	if (mmc_part.part_type == MMC_PART_TYPE_EXFAT) {
		/*
		 * we have to check mount from mdev mount.sh
		 */
		ret = 1;
	}

	*size = mmc_part.part_size;

	return ret;
}

int ctrl_exfat_format(unsigned long size)
{
    char cmd[256] = {0,};
    int blkid = 0, i;
    DIR *mount_dir = NULL;

    if (dev_disk_check_mount(MMC_MOUNT_POINT)) {
		dev_disk_mmc_part_unmount(MMC_PART_NAME);
		/* wait done */
		OSA_waitMsecs(300);
	}
	/*
	 * first loop-> changed partition fat32
	 * second loop-> make mmcblk0p1
	 */
	for (i = 0; i < 2; i++) {
		dev_disk_mmc_part_delete(mmc_part.part_no);
		usleep(500000); //# wait for done!
		dev_disk_mmc_part_create();
	}

	blkid = dev_disk_mmc_part_format(size);
	if (blkid < 0) {
		dprintf("Failed to format sdcard\n");
		/* todo: return or reboot?? */
		return -1;
	}
	usleep(500000); //# wait for done!

	//# check /mmc directory.
	mount_dir = opendir("/mmc");
	if (mount_dir == NULL) {
		mkdir("/mmc", 0775);
		sync();
	} else
		closedir(mount_dir);

	snprintf(cmd, sizeof(cmd),
			"/bin/mount -t vfat /dev/mmcblk%d""p1 /mmc", blkid);
	dev_execlp(cmd);

    return 0;
}

/*****************************************************************************
 * @brief    mode change function
 * @section  DESC Description
 *   - desc
 *	 - Not change parking or driving mode while running playback.
 *   - battery safe time(bsafe_start) is reset entered parking mode.
 *****************************************************************************/
int ctrl_mode_change(int mode)
{
	int change=0;

	if(mode == MODE_PARKING)
	{
		if(!app_cfg->state.park)
		{
            app_cfg->state.park 	= 1;
			app_cfg->bsafe_start 	= 0;
			change = 1;
 		}
	}
	else
	{
		if(app_cfg->state.park)
		{
            app_cfg->state.park = 0;
			change = 1;
		}
	}

	if(change) {
        system_buzzer(SYSTEM_OPER);
        OSA_waitMsecs(300);
        event_send(app_cfg->mObj, UBX_CMD_RESTART, 0, 0);
	}

	return 0;
}

int ctrl_time_set(int year, int mon, int day, int hour, int min, int sec, int utc)
{
    struct tm ts;
	time_t set;
	char msg[CHAR_128], buf[CHAR_64];
	app_cfg->state.nokey = 1;

    ts.tm_year = (year - 1900);
    ts.tm_mon  = (mon - 1);
    ts.tm_mday = day;
    ts.tm_hour = hour;
    ts.tm_min  = min;
    ts.tm_sec  = sec;

	if (utc) {
		int h=0,m=0;
		get_time_zone(app_set->tz.tz_idx, &h, &m);
		set = mktime(&ts) + ((h*3600)+(m*60)) + (get_summer_time_idx(app_set->tz.st_idx)*3600)+1;	//# GPS sync with time_zone...
	}
	else {
		set = mktime(&ts);
	}

	strftime( buf, sizeof(buf), "%Y%2m%2d_%2H%2M%2S", &ts );
	sprintf( msg, "[APP_CTRL] Time Change : %s", buf );
	app_log_write( MSG_LOG_WRITE, msg );

	stime(&set);
    Vsys_datetime_init();	//# m3 Date/Time init
    OSA_waitMsecs(100);

	//# have to set localtime.
	if (utc)
		localtime_r((const time_t *)&set, &ts);

	if (dev_rtc_set_time(ts) < 0) {
		sprintf(msg, "[APP_CTRL] !!! Failed to set system time to rtc !!!");
		app_log_write( MSG_LOG_WRITE, msg );
	}

//	set_format_dur();
	app_cfg->state.nokey = 0;

    return 0;
}

/*****************************************************************************
 * @brief    upgrade function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int ctrl_sd_format(void)
{
	char cmd[256] = {0,};
	int blkid = 0, r;

	struct mmc_part_info partinfo = {
		.part_no = 0,
		.part_type = 0,
		.part_size = 0
	};

	app_cfg->state.format = 1;
	app_cfg->state.secu_on = 1;

	app_rec_stop();
    app_log_stop();
    system("killall -9 wis-streamer");
    system("killall -9 hostapd");
    system("killall -9 busybox");
	/* for umount */
	OSA_waitMsecs(500);//# 100

	r = dev_disk_mmc_part_check_info(MMC_BLK_DEV_NAME, &partinfo);
	if (r) {
		eprintf("please check sd card!!\n");
		return -1;
	}

	if (partinfo.part_size > MMC_SIZE_128GB) {
		eprintf("Not suppoted sd card (%lu MB)!!\n", partinfo.part_size);
		return -1;
	}

	if (partinfo.part_no != 1) {
		eprintf("Invalid partition sd card!!\n");
		return -1;
	}

	/*
	 * we have to check mount from mdev mount.sh
	 */
	if (dev_disk_check_mount(MMC_MOUNT_POINT)) {
		dev_disk_mmc_part_unmount(MMC_PART_NAME);
		/* wait done */
		OSA_waitMsecs(300);
	}

	blkid = dev_disk_mmc_part_format(partinfo.part_size);
	if (blkid < 0) {
		eprintf("Failed to format sdcard\n");
		/* todo: return or reboot?? */
		return -1;
	}

	/* writing config files */
	memset(cmd, 0, sizeof(cmd));
	snprintf(cmd, sizeof(cmd),
			"/bin/mount -t vfat /dev/mmcblk%d""p1 /mmc", blkid);
	dev_execlp(cmd);
	sleep(1);

	set_format_dur();
    ubx_write_setting(0);
    sync();

	app_cfg->state.secu_on = 0;
	return 0;
}

/*****************************************************************************
 * @brief    upgrade function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
 /*---------------------------------------------------
 Firmware update
-----------------------------------------------------*/
typedef struct{
    char item[CHAR_8];
    char value[CHAR_8];
	char CTAG[CHAR_8];
}fw_version_t;

#define FW_FILE_NUM 6

#define FW_TYPE     0   //# "normal" or "debug"
#define FW_MODEL    1   //# "D16"
#define FW_MAJOR    2   //# "X"
#define FW_MINOR    3   //# "XX"
#define FW_PATCH    4   //# "XX"
#define FW_CTAG		5	//# "X"

//////psp update////
#define F_EMERGENCY "boot.scr"
#define F_MLO       "MLO"
#define F_RFS       "rfs_hd2.ubifs"
#define F_UBOOTBIN  "u-boot_hd2.bin"
#define F_UBOOTNAND "u-boot_hd2.min.nand"
#define F_UIMAGE    "uImage_hd2"
#define F_RELEASE   "release"
#define FW_DIR	    "/mmc/fw_version.txt"
//#define F_LOGO      "ubx_logo.raw"

#define F_EXT       ".app"

static char* find_ext(void)
{
	char path[255];
	static char	extPath[255];
	glob_t globbuf;

	memset(&globbuf, 0, sizeof(glob_t));

	sprintf(path, "%s/*%s", DIR_UPDATE, F_EXT);
    if(glob(path, GLOB_DOOFFS, NULL, &globbuf) == 0)
   	{
   		if(globbuf.gl_pathc > 0)
		{
			strcpy(extPath,globbuf.gl_pathv[0]);
			globfree(&globbuf);
			return extPath;
		}
   	}
	else
    {
		eprintf("Not found firmware file: %s\n",DIR_UPDATE);
    }

	globfree(&globbuf);

	return NULL;
}

void check_nand_update()
{
    int i=0;

    fw_version_t fw[FW_FILE_NUM];
    FILE *F_fw;
	F_fw = fopen(FW_DIR, "r");

    if( F_fw != NULL ) {

		while( !feof(F_fw) ){
			fscanf(F_fw,"%s %s", fw[i].item, fw[i].value);
			i++;

			if( i == FW_FILE_NUM )
				break;
		}
    	fclose(F_fw);

        if(strcmp(fw[FW_TYPE].value, F_RELEASE) == 0){
            printf("\n TYPE RELEASE!! \n");
            delete_nand_update();
        }
    }
}

void delete_nand_update()
{
    char cmd[256];
    char* pFile = NULL;
    int del=0;

    pFile = find_ext();
    if (pFile == NULL){
        printf("\n find_ext error!!\n");
        del=1;
    }

    if(del==0){
	    sprintf(cmd, "rm -f %s", FW_DIR);
	    dev_execlp(cmd);

	    sprintf(cmd, "rm -f %s/%s", DIR_UPDATE, F_EMERGENCY);
	    dev_execlp(cmd);

	    sprintf(cmd, "rm -f %s/%s", DIR_UPDATE, F_MLO);
	    dev_execlp(cmd);

	    sprintf(cmd, "rm -f %s/%s", DIR_UPDATE, F_RFS);
	    dev_execlp(cmd);

	    sprintf(cmd, "rm -f %s/%s", DIR_UPDATE, F_UBOOTBIN);
	    dev_execlp(cmd);

	    sprintf(cmd, "rm -f %s/%s", DIR_UPDATE, F_UBOOTNAND);
	    dev_execlp(cmd);

	    //sprintf(cmd, "rm -f %s/%s", DIR_UPDATE, F_LOGO);
	    //dev_execlp(cmd);

	    sprintf(cmd, "rm -f %s/%s", DIR_UPDATE, F_UIMAGE);
	    dev_execlp(cmd);

	    sprintf(cmd, "rm -f %s", pFile);
	    dev_execlp(cmd);
    }
}

int check_fw()
{
    int re_val=EFAIL; // 0 : success, -1 : file not found, -2 : is not ucx file, -3 : version is same or low
    int app_maj=0, app_min=0, app_pat=0; // mmc firmware verwion(major, minor, patch)
    int i=0, del_cfg=0;

    char buf[CHAR_128];
	char msg[CHAR_128];
    char* pFile = NULL;

    fw_version_t fw[FW_FILE_NUM];
    FILE *F_fw;

    //#--- find .app file and uncompressed
    pFile = find_ext();
    if (pFile == NULL){
		printf("%s\n", msg);
        return EFAIL;
    }

    printf("/*--------------------------------------------------*/\n");
    printf("\n    File Unpacking...\n");

    sprintf(buf, "tar xvf %s -C /mmc", pFile);
    dev_execlp(buf);
    OSA_waitMsecs(1000); 	//# wait for complete..
    sync();   				//# For safe writing on sd card..

    printf("/*--------------------------------------------------*/\n");

	//# open fw_version.ext file
    F_fw = fopen(FW_DIR, "r");
	if( F_fw == NULL )
	{
		sprintf(msg, "[APP_CTRL] !!! fw_version file open failed !!!");
		app_log_write( MSG_LOG_WRITE, msg );
		printf("%s\n", msg);
		goto fw_exit;
	}

	//# read fw_version.ext
	i = 0;
	while( !feof(F_fw) ){
		fscanf(F_fw,"%s %s", fw[i].item, fw[i].value);
		i++;

		if( i == FW_FILE_NUM )
			break;
	}
	fclose(F_fw);

    app_maj = atoi(fw[FW_MAJOR].value);
    app_min = atoi(fw[FW_MINOR].value);
    app_pat = atoi(fw[FW_PATCH].value);

	//# check f/w model
    if(strcmp(fw[FW_MODEL].value, TCX_MODEL) != 0){
        sprintf(msg, "[APP_CTRL] !!! Different firmware MODEL : %s!!!", fw[FW_MODEL].value);
		app_log_write(MSG_LOG_WRITE, msg);
		printf("%s\n", msg);
		del_cfg = 1;
    }

#if 0
	//# check older f/w
	sprintf(buf, "%s.%s.%s%s", fw[FW_MAJOR].value, fw[FW_MINOR].value, fw[FW_PATCH].value, fw[FW_CTAG].value);
	if( strcmp(app_set->info.sw_ver, buf ) > 0 ) {
		sprintf(msg, "[APP_CTRL] Old F/W version : %s!!", buf);
		app_log_write(MSG_LOG_WRITE, msg);
		printf("%s\n", msg);
		del_cfg = 1;
	}
#endif

	//# if diff f/w model or older f/w then reset cfg!
	if(del_cfg)
		ubx_delete_cfg();


	sprintf(buf, "%s/%s", DIR_UPDATE, F_EMERGENCY);
	if (0 == access(buf, 0)) {
		
		ui_draw_logo(DISP_FWUPDATE);
		
		/* debugging */
		dev_fw_setenv("nand_update", "1", 0);
        OSA_waitMsecs(20);
        sync();

		app_log_write(MSG_LOG_WRITE, "[APP_CTRL] Firmware update start");

		/* reboot */
        dev_system_reboot(REBOOT_UPDATE);

        re_val = 0;
	}


fw_exit:

    return re_val;
}

/*****************************************************************************
 * @brief    wifi state function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int ctrl_wifi_set(int on)
{
	int ret = SOK;
	int vid, pid;
    int stealth = 0 ;
	int i, channel;
	int run_5g = 0;

	char path[128] = {0,};
	char name[128] = {0,};
	char msg[CHAR_128] = {0,};

	app_cfg->state.nokey = 1;
	channel = 6; //# default channel

    if (on)
    {
    	sprintf( msg, "[APP_CTRL] WiFi ON ssid:%s", app_set->net.ssid);
		app_log_write( MSG_LOG_WRITE, msg );

    	if (dev_wifi_is_exist(&vid, &pid)) {
			/* not connected wifi usb module */
            app_cfg->state.nokey = 0;
			app_log_write( MSG_LOG_WRITE, "!!! Not Connected WiFi USB Module !!!");
			return EFAIL;
		}

		if ((vid == RTL_8188E_VID) && (pid == RTL_8188E_PID)) {
			strcpy(path, RTL_8188E_PATH);
			strcpy(name, RTL_8188E_NAME);
		} else if ((vid == RTL_8188C_VID) && (pid == RTL_8188C_PID)) {
			strcpy(path, RTL_8188C_PATH);
			strcpy(name, RTL_8188C_NAME);
		} else if ((vid == RTL_8192C_VID) && (pid == RTL_8192C_PID)) {
			strcpy(path, RTL_8188C_PATH);
			strcpy(name, RTL_8188C_NAME);
		} else if ((vid == RTL_8821A_VID) && (pid == RTL_8821A_PID)) {
			run_5g = 1; channel = 149;
			strcpy(path, RTL_8821A_PATH);
			strcpy(name, RTL_8821A_NAME);
		} else if ((vid == RTL_8192E_VID) && (pid == RTL_8192E_PID)) {
			strcpy(path, RTL_8192E_PATH);
			strcpy(name, RTL_8192E_NAME);
		} else {
			/* invalid wifi usb module */
            app_cfg->state.nokey = 0;
			app_log_write( MSG_LOG_WRITE, "!!! Not Supported WiFi USB Module !!!");
			return EFAIL;
		}

        if (app_cfg->state.wifi == 0) {
        	if (dev_wifi_get_module_state(name) == 0) {
        		dev_wifi_load((const char *)path);
				/* waiting for driver loaded */
				for (i = 0; i < 20; i++)
				{
					ret = access("/sys/class/net/wlan0/operstate", R_OK);
				    if ((ret == 0) || (errno == EACCES)) {
				      	break;
				    } else
						OSA_waitMsecs(100);
				}
				if (i >= 20)
	                ret = EFAIL;
        	}


			if (!ret) {
	            if (run_5g) {
					if (channel <= 0 || channel > 150)
						channel = 149;
				} else {
					if (channel <= 0 || channel > 11)
						channel = 6;
				}

				/*
				 * 1st -> Wi-Fi SSID
				 * 2nd -> Wi-Fi Password
				 * 3th -> Wi-Fi Channel
				 * 4th -> 0:2.4GHz 1:5GHz.
				 */
// TO Do  -->stealth = app_set->stealth;
	            if (dev_wifi_on(app_set->net.ssid, app_set->net.pwd, channel, run_5g, stealth) != 0) {
	                app_log_write( MSG_LOG_WRITE, "!!! WIFI Start failed !!!");
	                app_cfg->state.nokey = 0;
	                return EFAIL;
	            }
	            app_cfg->state.wifi = 1;
	        } else
	        	app_cfg->state.wifi = 0; /* Failed to load wi-fi driver */
        }
    } else {
        if (app_cfg->state.wifi) {
        	app_cfg->state.wifi = 0;
           	dev_wifi_off();
			app_log_write( MSG_LOG_WRITE, "WIFI Module OFF...");
        }
    }
	app_cfg->state.nokey = 0;

	return ret;
}

int ctrl_set_ssid(char* ssid)
{
    return 0;
}

int ctrl_set_ap_pwd(char* pwd)
{
    return 0;
}
