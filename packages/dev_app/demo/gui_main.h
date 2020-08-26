/******************************************************************************
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	gui_main.h
 * @brief
 */
/*****************************************************************************/

#ifndef _GUI_MAIN_H_
#define _GUI_MAIN_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
//# common include
#include "dev_gfx.h"
#include "draw_gui.h"
#include "draw_text.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define UI_HDMI			GFX0
#define UI_LCD			GFX1
#define UI_TVO			GFX2

#define UI_TVO_WI		720
#define UI_TVO_HE		480
#define UI_HDMI_WI		UI_TVO_WI
#define UI_HDMI_HE		UI_TVO_HE

#define UI_DRAW			1
#define UI_CLEAR		0

//# Do not set lower than APP_THREAD_PRI
#define UI_THREAD_PRI	2

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int app_gui_init(void);
int app_gui_exit(void);

int gui_ctrl(int cmd, int p0, int p1);

void gui_draw_logo(void);
void gui_draw_clear(void);
void gui_draw_time(void);

#endif	/* _GUI_MAIN_H_ */
