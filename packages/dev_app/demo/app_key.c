/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_key.c
 * @brief	key/ir input thread
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <linux/input.h>

#include "dev_key.h"

#include "app_comm.h"
#include "gui_main.h"
#include "app_key.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define USE_KEY				0	//# udx have not key

#define TIME_KEY_CYCLE		100	//# msec

typedef struct {
	app_thr_obj kObj;		//# key thread
	app_thr_obj tObj;		//# touch thread
} app_key_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_key_t key_obj;
static app_key_t *ikey=&key_obj;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*****************************************************************************
* @brief    key thread function
* @section  [desc]
*****************************************************************************/
#if USE_KEY
static void *THR_key(void *prm)
{
	app_thr_obj *tObj = &ikey->kObj;
	int ret, exit=0;
	struct key_recv_data_t key;

	aprintf("enter...\n");
	tObj->active = 1;

	dev_key_init();

	while(!exit)
	{
		if(tObj->cmd == APP_CMD_EXIT) {
			break;
		}

		//# key check
		ret = dev_key_read(&key, TIME_KEY_CYCLE);
		if(ret == 0)		//# valid key
		{
			if(key.value == 1)		//# 1:press, 0:release, 2:pressing
			{
				switch(key.code)
				{
					case KEY_F1: case KEY_MENU/*0x8b*/:
						dprintf("press KEY_MENU\n");
						break;
					case KEY_F2: case KEY_ESC/*0x01*/:
						dprintf("press KEY_ESC\n");
						break;
					case KEY_F3: case KEY_SETUP/*0x8d*/:
						dprintf("press KEY_SETUP\n");
						break;
					case KEY_F4: case KEY_ENTER/*0x1c*/:
						dprintf("press KEY_ENTER\n");
						break;
					default:
						break;
				}
			}
		}
	}

	dev_key_exit();

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}
#endif

/*****************************************************************************
* @brief    key thread start/stop function
* @section  DESC Description
*   - desc
*****************************************************************************/
int app_key_start(void)
{
	app_thr_obj *tObj;

	//# static config clear
	memset((void *)ikey, 0x0, sizeof(app_key_t));

	#if USE_KEY
	//#--- create key thread
	tObj = &ikey->kObj;
	if(thread_create(tObj, THR_key, UI_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return -1;
	}
	#endif

	return 0;
}

int app_key_stop(void)
{
	app_thr_obj *tObj;

	#if USE_KEY
	//#--- stop key thread
	tObj = &ikey->kObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);
	#endif

	return 0;
}
