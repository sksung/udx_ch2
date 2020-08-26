/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_gfx.h
 * @brief
 * @author	phoong
 * @section	MODIFY history
 *  - 2013.08.22 Modified by sksung
 */
/*****************************************************************************/

#ifndef _APP_GUI_H_
#define _APP_GUI_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#include "draw_gui.h"
/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define UI_TVO_WI       	720
#define UI_TVO_HE       	480

#define UI_LCD_WI			480
#define UI_LCD_HE			800

#define UI_DRAW		1
#define UI_CLEAR	0


#define UI_MENU		0	//# 0: lcd, 1:tv-out

typedef struct {
	int fd;
	unsigned int w;
	unsigned int h;
	Upix *buf;
	unsigned int size;
} gfx_t;

typedef struct {
	gfx_t tvo;
	gfx_t lcd;
} app_gfx_t;

typedef struct {
	app_gfx_t gfx_obj;

	int day;		//# current day
	int lcnt;
} app_gui_t;


typedef enum {
	STE_SD,
	STE_GPS,
	STE_EVENT,
	STE_MOTION,
	STE_SNDOUT,
	STE_SNDREC,
	STE_VOLT,
	STE_GSENS,
	STE_MODE,
	STE_CHINF,

	UI_STE_MAX
} app_ui_ste_e;


//# ani structure --------------------------------
#define MAX_NUM_ANI		10

typedef struct {
	int num_img;
	int delay;		//# ms
	int timeout;	//# sec

	int x, y;
	int idx[MAX_NUM_ANI];
} app_ani_t;
//# ani structure --------------------------------


/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
void app_gui_start(void);
void app_gui_stop(void);

int app_capt_main(void);
int app_pbk_main(void);

void ui_draw_logo(int dest);
void ui_draw_clear(int dest);
void ui_draw_state(int idx, int value, int draw);
void app_gui_layout(int layout);
void app_gui_layout_swap(void);

void ui_draw_txt_tvo(void);
void ui_draw_gsv();

#endif	/* _APP_GUI_H_ */
