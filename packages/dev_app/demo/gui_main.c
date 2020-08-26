/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    gui_main.c
 * @brief
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "app_comm.h"
#include "app_main.h"
#include "app_ctrl.h"
#include "gui_main.h"

#include "img_ud_logo_tvo.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define UI_CYCLE_TIME		500		//# ms

typedef struct {
	app_thr_obj uObj;	//# gui run thread

	int run_draw;

	Upix *tvo_buf;
	Upix *hdmi_buf;
} app_gui_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_gui_t gui_obj;
static app_gui_t *igui=&gui_obj;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 draw_logo/clear function
-----------------------------------------------------------------------------*/
void gui_draw_logo(void)
{
	ui_pos_t st;

	if(iapp->en_tvo) {
		st.x=0; st.y=0; st.w=720; st.h=480;
		draw_img((Upix *)igui->tvo_buf, (Upix *)img_ud_logo_tvo, st);
	}
}

void gui_draw_clear(void)
{
	if(iapp->en_tvo) {
		draw_fill_color((Upix *)igui->tvo_buf, RGB_KEY);
	}
}

void gui_draw_time(void)
{
	time_t now;
	struct tm *ts;
	char buf_date[64];

	//# get current date & time
	now = time(NULL);
	ts = localtime(&now);

	strftime(buf_date, sizeof(buf_date), "%Y/%2m/%2d %2I:%2M:%2S", ts);		//# %Y/%2m/%2d, %2H:%2M:%2S or %X, %p(AM/PM)

	if(iapp->en_tvo) {
		draw_text((Upix *)igui->tvo_buf, buf_date, FNT_SZ01, 32, 16, RGB_WHITE, RGB_BLACK);
	}
}

/*****************************************************************************
* @brief    gui run thread function
* @section  [desc]
*****************************************************************************/
static void *THR_gui_run(void *prm)
{
	app_thr_obj *tObj = &igui->uObj;
	int cmd, exit=0;

	aprintf("enter...\n");
	tObj->active = 1;

	gui_draw_logo();
	while(!exit)
	{
		cmd = tObj->cmd;
		if(cmd==APP_CMD_EXIT || cmd==GUI_DRAW_EXIT) {
			break;
		}

		switch(cmd)
		{
			case GUI_DRAW_RUN:
			{
				gui_draw_clear();
				igui->run_draw = 1;
				break;
			}
			case GUI_DRAW_STOP:
			{
				gui_draw_logo();
				igui->run_draw = 0;
				break;
			}
			case APP_CMD_EXIT:
			{
				exit = 1;
				break;
			}
			default:
				break;
		}

		if(igui->run_draw)
		{
			gui_draw_time();
		}

		//# cmd clear
		tObj->cmd = 0;

		//# wait time
		app_msleep(UI_CYCLE_TIME);
	}

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    gui control function
* @section  [desc]
*****************************************************************************/
int gui_ctrl(int cmd, int p0, int p1)
{
	event_send(&igui->uObj, cmd, p0, p1);

	return 0;
}

/*****************************************************************************
* @brief    gui init/exit function
* @section  [desc]
*****************************************************************************/
int app_gui_init(void)
{
	app_thr_obj *tObj;
	int buf;

	//# static config clear
	memset((void *)igui, 0x0, sizeof(app_gui_t));

	//# graphic init
	if(iapp->en_tvo) {
		dev_gfx_init(UI_TVO, &buf, 720, iapp->is_pal?576:480);
		igui->tvo_buf = (Upix *)buf;
	}

	//#--- create gui run thread
	tObj = &igui->uObj;
	if(thread_create(tObj, THR_gui_run, UI_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	return SOK;
}

int app_gui_exit(void)
{
	app_thr_obj *tObj;

	//#--- stop thread
	tObj = &igui->uObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		app_msleep(10);
	}
	thread_delete(tObj);

	if(iapp->en_tvo) {
		dev_gfx_exit(UI_TVO);
	}

	return SOK;
}
