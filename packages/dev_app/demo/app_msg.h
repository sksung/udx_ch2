/******************************************************************************
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_msg.h
 * @brief
 */
/*****************************************************************************/

#ifndef _APP_MSG_H_
#define _APP_MSG_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#include <osa.h>
#include <osa_thr.h>
#include <osa_sem.h>
#include <osa_mutex.h>

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
//# thread structure
#define MAX_PENDING_SEM_CNT		(1)
#define APP_THREAD_PRI			(2)
#define APP_THREAD_STACK_SIZE	(0) /* 0 means system default will be used */

typedef struct {
	OSA_ThrHndl thr;
	OSA_SemHndl sem;
	int active;

	int cmd;
	int param0;
	int param1;
} app_thr_obj;

//# app command
typedef enum {
	APP_CMD_NONE,

	//# for thread
	APP_CMD_START,
	APP_CMD_STOP,
	APP_CMD_PAUSE,
	APP_CMD_NOTY,
	APP_CMD_EXIT,

	//# event
	APP_EVT_PWROFF = 0x10,
	APP_EVT_MMC,

	//# for key
	APP_KEY_UP = 0x20,
	APP_KEY_LEFT,
	APP_KEY_SEL,
	APP_KEY_RIGHT,
	APP_KEY_DOWN,

	//# for touch
	APP_TS_SEL = 0x30,
	APP_TS_UP,
	APP_TS_LEFT,
	APP_TS_RIGHT,
	APP_TS_DOWN,
	APP_TS_LEFT_DN,

	//# for rec proc
	APP_REC_START = 0x40,
	APP_REC_STOP,

	//# for pb
	APP_PB_PLAY = 0x50,
	APP_PB_PAUSE,
	APP_PB_FF,
	APP_PB_FR,
	APP_PB_START,
	APP_PB_DONE,

	//# for gui
	GUI_DRAW_RUN = 0x60,
	GUI_DRAW_STOP,
	GUI_DRAW_EXIT,

	MAX_APP_CMD
} app_cmd_e;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int proc_msg_init(int msg_key);
int proc_msg_send(int qid, void *pdata , int size);
int proc_msg_recv(int qid, int msg_type, void *pdata , int size);
int proc_msg_exit(int qid);

int thread_create(app_thr_obj *tObj, void *fxn, int pri, void *prm);
void thread_delete(app_thr_obj *tObj);

int event_wait(app_thr_obj *tObj);
int event_send(app_thr_obj *tObj, int cmd, int param0, int param1);

#endif	/* _APP_MSG_H_ */
