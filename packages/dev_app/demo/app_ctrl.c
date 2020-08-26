/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_ctrl.c
 * @brief	control for mcfw functions
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <sys/stat.h>

#include "ti_vcam.h"
#include "ti_vcap.h"
#include "ti_venc.h"
#include "ti_vdis.h"

#include "dev_common.h"
#include "dev_micom.h"

#include "app_comm.h"
#include "app_main.h"
#include "app_dev.h"
#include "gui_main.h"
#include "app_ctrl.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define DEFAULT_FPS			30
#define FLOOR_ALIGN(val, align)  (((val) / (align)) * (align))

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*****************************************************************************
* @brief    HD camera(ph3100k) control function
* @section  [desc] 2HD cam -> dev(0 or 1)
*****************************************************************************/
#define DEV_PWR_OFF			0x10
#define DEV_R_STATE			0x20

int ctrl_hdcam_frame(int ch, int fr)
{
	int dev = ch;		//# dev and ch are same

	if(fr!=30 && fr!=25 && fr!=20 && fr!=15 && fr!=10) {
		eprintf("invaild params - ch%d: %d!\n", ch, fr);
		return EPARAM;
	}

	Vcap_set_video_reg(dev, 0x03, 0x00);
	if(fr==30) {
		Vcap_set_video_reg(dev, 0x41, 0x01);
		Vcap_set_video_reg(dev, 0x42, 0x0B);
	}
	else if(fr==25) {
		Vcap_set_video_reg(dev, 0x41, 0x06);
		Vcap_set_video_reg(dev, 0x42, 0x37);
	}
	else if(fr==20) {
		Vcap_set_video_reg(dev, 0x41, 0x03);
		Vcap_set_video_reg(dev, 0x42, 0x16);
	}
	else if(fr==15) {
		Vcap_set_video_reg(dev, 0x41, 0x02);
		Vcap_set_video_reg(dev, 0x42, 0x0B);
	}
	else if(fr==10) {
		Vcap_set_video_reg(dev, 0x41, 0x03);
		Vcap_set_video_reg(dev, 0x42, 0x0B);
	}

	Vcap_link_reset();	//# capture link reset

	return SOK;
}

int ctrl_hdcam_mirror(int ch, int value)
{
	int dev = ch;		//# dev and ch are same

	//# mirror 0:VH, 1:V, 2:H, 3:off
	Vcap_set_video_reg(dev, 0x03, 0x00);
	Vcap_set_video_reg(dev, 0x05, value);

	return SOK;
}

int ctrl_hdcam_bright(int ch, int value)
{
	int dev = ch;		//# dev and ch are same

	//# rear value, default: 3
	Vcap_set_video_reg(dev, 0x03, 0x04);
	if (value == 1) {
		Vcap_set_video_reg(dev, 0x3B, 0x53);
		Vcap_set_video_reg(dev, 0x3D, 0x53);
		Vcap_set_video_reg(dev, 0x3C, 0x48);
		Vcap_set_video_reg(dev, 0x3E, 0x48);
	} else if (value == 2) {
		Vcap_set_video_reg(dev, 0x3B, 0x63);
		Vcap_set_video_reg(dev, 0x3D, 0x63);
		Vcap_set_video_reg(dev, 0x3C, 0x58);
		Vcap_set_video_reg(dev, 0x3E, 0x58);
	} else if (value == 3) {
		Vcap_set_video_reg(dev, 0x3B, 0x73);
		Vcap_set_video_reg(dev, 0x3D, 0x73);
		Vcap_set_video_reg(dev, 0x3C, 0x68);
		Vcap_set_video_reg(dev, 0x3E, 0x68);
	} else if (value == 4) {
		Vcap_set_video_reg(dev, 0x3B, 0x83);
		Vcap_set_video_reg(dev, 0x3D, 0x83);
		Vcap_set_video_reg(dev, 0x3C, 0x78);
		Vcap_set_video_reg(dev, 0x3E, 0x78);
	} else if (value == 5) {
		Vcap_set_video_reg(dev, 0x3B, 0x93);
		Vcap_set_video_reg(dev, 0x3D, 0x93);
		Vcap_set_video_reg(dev, 0x3C, 0x88);
		Vcap_set_video_reg(dev, 0x3E, 0x88);
	}

	return SOK;
}

int ctrl_hdcam_state(int ch)
{
	unsigned char value;
	int dev = ch;		//# dev and ch are same

	Vcap_get_video_reg(DEV_R_STATE, dev, &value);

	return (int)value;
}

int ctrl_serdes_pwroff(void)
{
	int ret;

	//# hdcam and serdes power off
	ret = Vcap_set_video_reg(DEV_PWR_OFF, 0x00, 0x00);

	dprintf("HD cam power off\n");

	return ret;
}

/*****************************************************************************
* @brief    video frame control function
* @section  [desc]
*****************************************************************************/
int ctrl_vid_frame(int ch, int frame)
{
	#if 1		//# 0 -> change in encoder
	ctrl_hdcam_frame(ch, frame);
	#else
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };

	//# encoder framerate
	//Venc_setInputFrameRate(ch, 30);	//# fixed 30fps

	params.frameRate = frame;
	Venc_setDynamicParam(ch, 0, &params, VENC_FRAMERATE);

	params.intraFrameInterval = frame;
	Venc_setDynamicParam(ch, 0, &params, VENC_IPRATIO);
	#endif

	dprintf("ch%d frame %d\n", ch, frame);

	return SOK;
}

int ctrl_vid_bitrate(int ch, int br, int fr)
{
	int bitrate;
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };

	if(br < 500) {
		eprintf("invaild params - ch%d: %d!\n", ch, br);
		return EFAIL;
	}

	bitrate = (br * fr)/DEFAULT_FPS;	//# for keep size per frame

	params.targetBitRate = bitrate*1000;
	Venc_setDynamicParam(ch, 0, &params, VENC_BITRATE);

	dprintf("ch%d bitrate %d\n", ch, br);

	return SOK;
}

int ctrl_vid_rate(int ch, int rc, int br)
{
	VENC_CHN_DYNAMIC_PARAM_S params = { 0 };

	if(rc == RATE_CTRL_VBR)
	{
		params.qpMax 	= 45;
		params.qpInit 	= -1;

		if(br >= 8000) {
			params.qpMin 	= 22;	//# for VBR setting (4M~8.5M when bitrate was 8M)
		}
		else if(br >= 6000) {
			params.qpMin 	= 26;	//# for VBR setting (1.8M~5.6M when bitrate was 5M)
		}
		else if(br >= 2000) {
			params.qpMin 	= 28;
		}
		else {
			params.qpMin 	= 30;
		}
	}
	else	//# RATE_CTRL_CBR
	{
		params.qpMin	= 10;
		params.qpMax 	= 40;
		params.qpInit 	= -1;
	}

	Venc_setDynamicParam(ch, 0, &params, VENC_QPVAL_P);

	//dprintf("ch%d rate control %s\n", ch, rc==RATE_CTRL_VBR?"VBR":"CBR");

	return SOK;
}

int ctrl_vid_motion(int ch, int level)
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
	}

	Venc_setDynamicParam(ch, 0, &params, VENC_MDPARAM);

	//dprintf("ch%d motion %s (lv=%d)\n", ch, en?"enable":"disable", level);

	return SOK;
}

/*****************************************************************************
* @brief    SW mosaic(Video layout) control function
* @section  DESC Description
*   - desc
*****************************************************************************/
int ctrl_swms_set(int dev, int win_num, int ch)
{
	VDIS_MOSAIC_S vdMosaicParam;
	int out_wi, out_he, wi_align, offset=0;
	int win_id, win_wi, win_he, winY;
	int row, col;

	if(dev == DISP_HDMI) {
		out_wi = 1920;
		out_he = 1080;
	} else { //if(dev == DISP_TVO) {
		offset = 16;
		out_wi = 720 - (offset*2);
		out_he = 480 - (offset*2);
	}
	wi_align = 8;

	vdMosaicParam.displayWindow.width		= out_wi;
	vdMosaicParam.displayWindow.height		= out_he;
	vdMosaicParam.numberOfWindows 			= win_num;
	vdMosaicParam.displayWindow.start_X		= 0;
	vdMosaicParam.displayWindow.start_Y		= 0;
	vdMosaicParam.onlyCh2WinMapChanged		= FALSE;
	vdMosaicParam.outputFPS 				= 30;

	win_id = 0;
	if(win_num == 1)
	{
		win_wi = FLOOR_ALIGN(out_wi, wi_align);
		win_he = out_he;
		vdMosaicParam.chnMap[win_id] = ch;
    	vdMosaicParam.winList[win_id].start_X = offset;
		vdMosaicParam.winList[win_id].start_Y = offset;
		vdMosaicParam.winList[win_id].width = win_wi;
		vdMosaicParam.winList[win_id].height = win_he;
		vdMosaicParam.useLowCostScaling[win_id] = FALSE;
	}
	else if(win_num == 2)
	{
		win_wi = FLOOR_ALIGN(out_wi, wi_align);
		win_he = out_he;
		vdMosaicParam.chnMap[win_id] = ch++;
    	vdMosaicParam.winList[win_id].start_X = offset;
		vdMosaicParam.winList[win_id].start_Y = offset;
		vdMosaicParam.winList[win_id].width = win_wi;
		vdMosaicParam.winList[win_id].height = win_he;
		vdMosaicParam.useLowCostScaling[win_id] = FALSE;
		win_id++;

		win_wi = FLOOR_ALIGN((out_wi*0.4), wi_align);
		win_he = (out_he*win_wi)/out_wi;
		vdMosaicParam.chnMap[win_id] = ch;
    	vdMosaicParam.winList[win_id].start_X = offset + (out_wi-win_wi);
		vdMosaicParam.winList[win_id].start_Y = offset;
		vdMosaicParam.winList[win_id].width = win_wi;
		vdMosaicParam.winList[win_id].height = win_he;
		vdMosaicParam.useLowCostScaling[win_id] = FALSE;
	}
	else {
		return -1;
	}

	Vdis_setMosaicParams(dev, &vdMosaicParam);

	//# wait for the info prints to complete
	OSA_waitMsecs(100);

	return 0;
}

int ctrl_disp_zoom(int dev, int win_id, int x, int y, int ratio)
{
	WINDOW_S chnlInfo, winCrop;
	int sx=0, sy=0;

	Vdis_getChnlInfoFromWinId(dev, win_id, &chnlInfo);

	if (ratio == 1) {
		winCrop.start_X = 0;
		winCrop.start_Y = 0;
		winCrop.width = chnlInfo.width;
		winCrop.height = chnlInfo.height;
	}
	else
	{
		if(ratio == 4) {
			winCrop.width = chnlInfo.width/4;
			winCrop.height = chnlInfo.height/4;
		}
		else if(ratio == 6) {
			winCrop.width = chnlInfo.width/6;
			winCrop.height = chnlInfo.height/6;
		}
		else {	//# default x2
			winCrop.width = chnlInfo.width/2;
			winCrop.height = chnlInfo.height/2;
		}

		sx = x-(winCrop.width/2);
		sy = y-(winCrop.height/2);
		if(sx < 0)
			sx = 0;
		if(sx > (chnlInfo.width-winCrop.width))
			sx = chnlInfo.width-winCrop.width;
		if(sy < 0)
			sy = 0;
		if(sy > (chnlInfo.height-winCrop.height))
			sy = chnlInfo.height-winCrop.height;

		winCrop.start_X = sx;
		winCrop.start_Y = sy;
	}

	dprintf("input : %d, %d\n", chnlInfo.width, chnlInfo.height);
	dprintf("crop : %d, %d, %d, %d\n", sx, sy, winCrop.width, winCrop.height);

	Vdis_SetCropParam(VDIS_DEV_HDMI, win_id, winCrop);

	return 0;
}

/*****************************************************************************
* @brief    get version function
* @section  DESC Description
*   - desc
*****************************************************************************/
int ctrl_get_hw_version(char *version)
{
	int ver;

	/* d16 (usb1)
	   0x1 -> ver0.2
	   0x2 -> ver0.3
	   0x3 -> ver0.4
	   ...
	*/
	/* dtc (usb2)
	   0x0 -> ver0.1
	   0x1 -> ver0.2
	   0x2 -> ver0.3
	   ...
	*/
	ver = dev_get_board_info();
	if(ver < 1) {
		sprintf(version, "UNKNOWN");
		return -1;
	}

	if(version != NULL) {
		sprintf(version, "00.%02d", (ver+1));
	}

	return ver;
}

int ctrl_get_mcu_version(char *version)
{
	int ver;

	ver = (int)mic_get_version();
	sprintf(version, "%02d.%02X", (ver>>8)&0xFF, ver&0xFF);

	return ver;
}

/*****************************************************************************
* @brief    encoder control demo function
* @section  [desc]
*****************************************************************************/
const char menu_enc_ctrl[] = {
	"\r\n -------------"
	"\r\n ENC Ctrl Menu"
	"\r\n -------------"
	"\r\n 0: exit"
	"\r\n 1: framerate"
	"\r\n%s2: motion set"
	"\r\n 3: rate ctrl"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_enc_ctrl(void)
{
	int done = 0;
	char cmd = 0;
	int ch, value, mot_ch=0;
	int max_ch = iapp->num_ch;

	while (!done)
	{
		printf(menu_enc_ctrl, mot_ch?"*":" ");
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
			{
				printf("channel? (0~%d) : ", max_ch-1);
				ch = menu_get_data();
				if(ch > max_ch-1) {
					eprintf("invalid channel %d\n", ch);
					break;
				}
				printf("frame? (1-30) ");
				value = menu_get_data();

				ctrl_vid_frame(ch, value);

				break;
			}
			case '2':
			{
				if(!mot_ch) {
					printf("channel? (0~%d) : ", max_ch-1);
					ch = menu_get_data();
					if(ch > max_ch-1) {
						eprintf("invalid channel %d\n", ch);
						break;
					}
					printf("motion level? (1:low ~ 3:high) ");
					value = menu_get_data();
					if(value > 3) {
						eprintf("invalid level %d\n", value);
						break;
					}

					ctrl_vid_motion(ch, value);
					mot_ch = ch +1;
				}
				else {
					ctrl_vid_motion(mot_ch-1, 0);
					mot_ch = 0;
				}
				break;
			}
			case '3':
			{
				printf("channel? (0~%d) : ", max_ch-1);
				ch = menu_get_data();
				if(ch > max_ch-1) {
					eprintf("invalid channel %d\n", ch);
					break;
				}
				printf("rate control? (0:VBR, 1:CBR) ");
				value = menu_get_data();
				if(value > 1) {
					eprintf("invalid control %d\n", value);
					break;
				}

				ctrl_vid_rate(ch, value, iapp->ich[ch].br);
				break;
			}
		}
	}

	if(mot_ch) {
		ctrl_vid_motion(mot_ch-1, 0);
	}

	return 0;
}

/*****************************************************************************
* @brief    capture control demo function
* @section  [desc]
*****************************************************************************/
const char menu_cap_ctrl[] = {
	"\r\n -------------"
	"\r\n CAP Ctrl Menu"
	"\r\n -------------"
	"\r\n 0: exit"
	"\r\n 1: HDcam mirror"
	"\r\n 2: HDcam bright"
	"\r\n 3: HDcam state"
	"\r\n%s4: HDcam on/off(h/w)"
	"\r\n 5: Serdes Power off"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_cap_ctrl(void)
{
	int done=0;
	char cmd=0;
	int ch, value;
	int ste_hd=1;	//# default on state
	int max_ch = iapp->num_ch;

	while (!done)
	{
		printf(menu_cap_ctrl, ste_hd?"*":" ");
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':			//# HD mirror
			{
				printf("channel? (0~%d) : ", max_ch-1);
				ch = menu_get_data();
				if(ch > max_ch-1) {
					eprintf("invalid channel %d\n", ch);
					break;
				}
				printf("mirror? (0:VH, 1:V, 2:H, 3:off): ");
				value = menu_get_data();
				if(ch > 3) {
					eprintf("invalid value %d\n", value);
					break;
				}

				ctrl_hdcam_mirror(ch, value);

				break;
			}
			case '2':			//# HDcam brightness
			{
				printf("channel? (0~%d) : ", max_ch-1);
				ch = menu_get_data();
				if(ch > max_ch-1) {
					eprintf("invalid channel %d\n", ch);
					break;
				}
				printf("value? (1~5, def:3): ");
				value = menu_get_data();
				if(ch > 3) {
					eprintf("invalid value %d\n", value);
					break;
				}

				ctrl_hdcam_bright(ch, value);
				break;
			}
			case '3':			//# HDcam get state
			{
				printf("channel? (0~%d) : ", max_ch-1);
				ch = menu_get_data();
				if(ch > max_ch-1) {
					eprintf("invalid channel %d\n", ch);
					break;
				}

				//value = ctrl_hdcam_state(ch);
				value = ste_hdcam(ch);
				dprintf("HDcam #%d %s\n", ch, value?"active":"inactive");
				break;
			}
			case '4':			//# HDcam power off by gpio
			{
				ste_hd = 1 - ste_hd;
				ctrl_hdcam_pwr(ste_hd);

				if(ste_hd) {
					app_msleep(100);
					Vcap_link_reset();	//# capture link reset
				}
				break;
			}
			case '5':			//# serdes power off
			{
				ctrl_serdes_pwroff();
				break;
			}
		}
	}

	return 0;
}

/*****************************************************************************
* @brief    sw mosaic demo function
* @section  [desc]
*****************************************************************************/
const char menu_swms[] = {
	"\r\n -------------"
	"\r\n SWMS Menu"
	"\r\n -------------"
	"\r\n 0: exit"
	"\r\n 1: 1 ch"
	"\r\n 2: 2 ch"
	"\r\n 3: disp zoom"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_swms(void)
{
	int done = 0;
	char cmd = 0;
	int ch, max_ch = iapp->num_ch;

	while (!done)
	{
		printf(menu_swms);
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
			{
				printf("channel? (0~%d) : ", max_ch-1);
				ch = menu_get_data();
				if(ch > max_ch-1) {
					eprintf("\n invalid channel %d\n", ch);
					break;
				}
				ctrl_swms_set(iapp->disp_dev, 1, ch);

				break;
			}
			case '2':
			{
				ch = 0;
				ctrl_swms_set(iapp->disp_dev, 2, ch);
				break;
			}
			case '3':
			{
				int x, y, ratio;

				printf("winID of current swms? : ");
				ch = menu_get_data();
				printf("ratio? (1, 2, 4, 6): ");
				ratio = menu_get_data();
				if(ratio != 1) {
					printf("x? : ");
					x = menu_get_data();
					printf("y? : ");
					y = menu_get_data();
				}

				ctrl_disp_zoom(iapp->disp_dev, ch, x, y, ratio);
				break;
			}
		}
	}

	return 0;
}
