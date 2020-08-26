/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_mcu.c
 * @brief	micom(volt, temp, acc, switch) check thread
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include "app_comm.h"
#include "app_main.h"
#include "app_mcu.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define TIME_DATA_CYCLE		  100	//# msec, data receive period from micom
#define TIME_ACC_CHK		  500	//# msec, acc hold time
#define TIME_PSW_CHK		 1000	//# msec, power switch hold time
#define TIME_WATCHDOG          30  	//# sec

typedef struct {
	app_thr_obj cObj;	//# micom thread

	dev_val_t val;
	int view;			//# for test
} app_mcu_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_mcu_t mcu_obj;
static app_mcu_t *imcu=&mcu_obj;

/*----------------------------------------------------------------------------
 micom config
-----------------------------------------------------------------------------*/
static void mic_cfg_init(void)
{
	micom_cfg_t cfg;

	//# set config micom
	cfg.t_acc_chk = TIME_ACC_CHK;
	cfg.t_psw_chk = TIME_PSW_CHK;

	mic_set_config(&cfg);
}

/*****************************************************************************
* @brief    micom value i/f function
* @section	[desc]
*****************************************************************************/
void app_get_data(int *mvolt, int *svolt, int *temp)
{
    *mvolt = imcu->val.mvolt;
    *svolt = imcu->val.svolt;
    *temp = imcu->val.temp;
}

int app_get_acc(void)
{
	return imcu->val.acc;
}

/*****************************************************************************
* @brief	micom message main function
* @section  [desc] check power switch and acc power
*****************************************************************************/
static void *THR_micom(void *prm)
{
	app_thr_obj *tObj = &imcu->cObj;
	int cmd, exit=0, ret=0;
	mic_msg_t msg;

	aprintf("enter...\n");
	tObj->active = 1;

	mic_cfg_init();
	#ifdef SW_RELEASE
	mic_set_watchdog(ENA, TIME_WATCHDOG);
	#endif

	mic_data_send(1, TIME_DATA_CYCLE);

	while(!exit)
	{
		ret = mic_recv_msg((char*)&msg, sizeof(mic_msg_t));
		if(ret < 0) {
			continue;
		}

		switch(msg.cmd)
		{
			case CMD_DEV_VAL:
			{
				dev_val_t *val = (dev_val_t *)msg.data;

				imcu->val.mvolt = val->mvolt;		//# XX.xx V format
				imcu->val.svolt = val->svolt;		//# XX.xx V format
				imcu->val.temp  = val->temp;		//# (+/-) XXX.x 'C format
				imcu->val.acc   = val->acc;

				if(imcu->view) {
					printf("[%3d] mpwr: %d.%d V, spwr:%d.%d V, temp: %d.%d V, acc %s\n", msg.param,
						(imcu->val.mvolt/100), (imcu->val.mvolt%100), (imcu->val.svolt/100), (imcu->val.svolt%100),
						(imcu->val.temp/10), (imcu->val.temp%10),
						imcu->val.acc?"ON":"OFF");
				}

				break;
			}
			case CMD_ACC_EVT:
			{
				dprintf("[evt] acc event %s\n", msg.data[0]?"on":"off");
				break;
			}
			case CMD_DAT_STOP:		//# response data send stop
			{
				dprintf("[evt] data stop event\n");
				exit = 1;
				break;
			}
			default:
				break;
		}
	}

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    micom thread start/stop function
* @section  [desc]
*****************************************************************************/
int app_mcu_start(void)
{
	app_thr_obj *tObj;

	//# static config clear
	memset((void *)imcu, 0x0, sizeof(app_mcu_t));

	//#--- create dio thread
	tObj = &imcu->cObj;
	if(thread_create(tObj, THR_micom, APP_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	return SOK;
}

void app_mcu_stop(void)
{
	app_thr_obj *tObj;

	//#--- stop thread
	tObj = &imcu->cObj;
	//event_send(tObj, UBX_CMD_STOP, 0, 0);		//# need not
	mic_data_send(0, 0);		//# data send stop
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);
}

/*****************************************************************************
* @brief    micom init/exit function
* @section  [desc]
*****************************************************************************/
int app_mcu_init(void)
{
	int ret;

	ret = mic_msg_init();
	if(ret < 0) {
		return -1;
	}
	mic_send_ready();

	mic_exit_state(OFF_NONE, 0);	//# for test - no power off

	return 0;
}

int app_mcu_exit(void)
{
    mic_msg_exit();

	return 0;
}

/*----------------------------------------------------------------------------
 watchdog test
-----------------------------------------------------------------------------*/
static void test_watchdog(void)
{
	int i, cnt;
	int t_wdog, t_alive;

	printf(" watchdog time? (sec): ");
	t_wdog = menu_get_data();
	printf(" how long keek alive? (min): ");
	t_alive = menu_get_data();

	cnt = (t_alive*60)/t_wdog;
	printf(" watchdog %d sec, alive cnt = %d\n", t_wdog, cnt);

	mic_set_watchdog(ENA, t_wdog);

	for(i=0; i<cnt; i++) {
		sleep(t_wdog-1);
		mic_keep_alive();
		printf("send keep alive\n");
	}

	printf("will reset after watchdog time\n");
}

/*****************************************************************************
* @brief    demo micom function
* @section  [desc]
*****************************************************************************/
const char micom_menu[] = {
	"\r\n ============="
	"\r\n MICOM Menu"
	"\r\n ============="
	"\r\n"
	"\r\n 0: exit"
	"\r\n 1: view data"
	"\r\n 2: watchdog test"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_micom(void)
{
	app_thr_obj *tObj;
	int ret, done = 0;
	char cmd = 0;
	int volt, temp, acc;

	app_mcu_start();

	while (!done)
	{
		printf(micom_menu);
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
				imcu->view = 1 - imcu->view;
				break;
			case '2':
				test_watchdog();
				break;
		}
	}

	app_mcu_stop();

	//mic_exit_state(OFF_NORMAL, 0);	//# power off

	return 0;
}
