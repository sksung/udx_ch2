/******************************************************************************
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_main.h
 * @brief
 */
/*****************************************************************************/

#ifndef _APP_MAIN_H_
#define _APP_MAIN_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define MAX_CH_NUM		(2)

typedef union {
	struct {
		int cap		: 1;
		int rec		: 1;
	} b;
	int w;
} app_state;

typedef struct {
	int wi;			//# width
	int he;			//# height
	int fr;			//# framerate
	int br;			//# bitrate (KB)
	int rc;			//# rate ctrl(VBR/CBR)
	int mot;		//# enable motion
} ch_info_t;

typedef struct {
	app_thr_obj mObj;	//# main thread

	app_state ste;

	int num_ch;

	int is_pal;			//# 0: NTSC, 1: PAL
	int snapshoot;
	int disp_dev;		//# DISP_HDMI/DISP_LCD/DISP_TVO

	ch_info_t ich[MAX_CH_NUM];

	//# component
	int en_enc;
	int en_jpg;
	int en_rec;
	int en_dual;		//# second stream
	int en_rtsp;

	//# display
	int en_tvo;
	int en_lcd;
	int en_hdmi;

} app_cfg_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
extern app_cfg_t *iapp;

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/

#endif	/* _APP_MAIN_H_ */
