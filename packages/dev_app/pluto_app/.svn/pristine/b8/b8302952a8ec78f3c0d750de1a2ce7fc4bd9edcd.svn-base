/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_util.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.04.01 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <linux/input.h>

#include "dev_gpio.h"

#include "ucx_main.h"
#include "app_gui.h"
#include "app_util.h"
#include "app_key.h"
#include "app_snd.h"
#include "app_ctrl.h"
#include "app_rec.h"
#include "app_dev.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define POLL_TIMEOUT 		(3 * 1000) /* 3 seconds */

typedef struct {
	app_thr_obj *keyObj;	//# key thread
	app_thr_obj *tsObj; 	//# touch thread
} app_key_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_key_t t_key;
static app_key_t *ikey=NULL;

static int gpio_rec_key_num = -1;
/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 key process function
-----------------------------------------------------------------------------*/

/*****************************************************************************
* @brief    key main function
* @section  DESC Description
*   - desc
*****************************************************************************/
static void *key_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	int ret, value;

	printf(" [task] %s start...\n", __func__);
	tObj->done = 0;

	while(!tObj->done)
	{
		ret = gpio_irq_read(gpio_rec_key_num, &value, POLL_TIMEOUT); //# 300ms
		if (ret) {
			/* return nonzero, if gpio set active low flag. */
			//printf("press key\n");
		}

		if(tObj->cmd == UBX_CMD_STOP)		//# stop
			tObj->done = 1;
	}

	printf(" [task] %s stop\n", __func__);

	return NULL;
}

/*****************************************************************************
* @brief    key thread start/stop function
* @section  DESC Description
*   - desc
*****************************************************************************/
void app_key_start(void)
{
	app_thr_obj *tObj;

	ikey = &t_key;
	memset(ikey, 0, sizeof(app_key_t));

	if (dev_get_udx_info() == EFAIL) {
		gpio_rec_key_num = GPIO_N(3, 10);	//# old h/w
	} else {
		gpio_rec_key_num = GPIO_N(3, 7);	//# new h/w
	}

	/* gpio record key (active low) */
	gpio_init(gpio_rec_key_num, GPIO_INPUT, GPIO_IRQ_FALLING, 0);

	//# create key thread
	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj == NULL) {
		eprintf("thread obj malloc fail\n");
		return;
	}

	OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
	OSA_thrCreate(&tObj->thr, key_main, FXN_TSK_PRI, 0, tObj);

	//# resgister thread obj
	ikey->keyObj = tObj;
}

void app_key_stop(void)
{
    app_thr_obj *tObj;

	if(ikey == NULL)
		return;

	tObj = (app_thr_obj *)ikey->keyObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
	}

	gpio_free(gpio_rec_key_num);

	ikey = NULL;

    dprintf("done...\n");
}
