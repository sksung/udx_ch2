/******************************************************************************
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_ctrl.h
 * @brief
 */
/*****************************************************************************/

#ifndef _APP_CTRL_H_
#define _APP_CTRL_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#include "ti_vdis.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define DISP_HDMI	VDIS_DEV_HDMI
#define DISP_LCD	VDIS_DEV_DVO2
#define DISP_TVO	VDIS_DEV_SD

typedef enum {
	RATE_CTRL_VBR,
	RATE_CTRL_CBR,
	MAX_RATE_CTRL
} app_rate_ctrl_e;

typedef enum {
	Q_LO,
	Q_MD,
	Q_HI,
	MAX_LEVEL_CTRL
} app_level_e;

typedef enum {
    SERDES_EQ_LV0,		//# B, 0.5m~15m
    SERDES_EQ_LV1,		//# D, 3m~25m
    SERDES_EQ_LV2,		//# C, 0.5m~20m
    SERDES_EQ_LV3,		//# E, 3m~30m
    SERDES_EQ_LV4,		//# A, 0.15m~15m
    MAX_SERDES_EQ_LV
} serdes_eq_e;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int ctrl_hdcam_frame(int ch, int value);
int ctrl_hdcam_mirror(int ch, int value);
int ctrl_hdcam_bright(int ch, int value);
int ctrl_hdcam_state(int ch);
int ctrl_serdes_pwroff(void);

int ctrl_vid_frame(int ch, int fr);
int ctrl_vid_bitrate(int ch, int br, int fr);
int ctrl_vid_rate(int ch, int rc, int br);		//# runtime
int ctrl_vid_motion(int ch, int level);			//# runtime

int ctrl_swms_set(int dev, int win_num, int ch);
int ctrl_disp_zoom(int dev, int win_id, int x, int y, int ratio);

int ctrl_get_hw_version(char *version);
int ctrl_get_mcu_version(char *version);

int test_enc_ctrl(void);
int test_cap_ctrl(void);
int test_swms(void);

#endif	/* _APP_CTRL_H_ */
