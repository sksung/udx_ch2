/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_dev.c
 * @brief	app device functions
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <time.h>		//# for gps

#include "dev_gpio.h"
#include "dev_gps.h"
#include "dev_accel.h"
#include "dev_micom.h"

#include "app_comm.h"
#include "app_main.h"
#include "app_disk.h"
#include "app_dev.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define TIME_DEV_CYCLE		  100		//# msec
#define TIME_GPS_CYCLE		  500		//# msec
#define TIME_GSN_CYCLE		  250		//# msec

typedef struct {
	app_thr_obj dObj;	//# dev thread
	app_thr_obj gObj;	//# gps thread
	app_thr_obj sObj;	//# g-sensor thread
	app_thr_obj bObj;	//# buzzer thread
} app_dev_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_dev_t dev_obj;
static app_dev_t *idev=&dev_obj;

static const int leds[] = {
	STE_LED_1, STE_LED_2, STE_LED_3
};

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 gpio init/exit functions
-----------------------------------------------------------------------------*/
static int dev_gpio_init(void)
{
	int i, ret=0;

	//# led init
	for(i=0; i<MAX_LEDS; i++) {
		ret |= gpio_init(leds[i], GPIO_OUTPUT, GPIO_IRQ_NONE, LED_OFF);
	}
	//# output control
	ret |= gpio_init(HDCAM0_PWR, GPIO_OUTPUT, GPIO_IRQ_NONE, ON);
	ret |= gpio_init(HDCAM1_PWR, GPIO_OUTPUT, GPIO_IRQ_NONE, ON);
	if(ret < 0) {
		eprintf("input gpio init\n");
	}

	//# input control
	ret  = gpio_init(TVOUT_DET, GPIO_INPUT, GPIO_IRQ_NONE, 0);
	ret |= gpio_init(HDCAM0_DET, GPIO_INPUT, GPIO_IRQ_NONE, 0);
	ret |= gpio_init(HDCAM1_DET, GPIO_INPUT, GPIO_IRQ_NONE, 0);
	if(ret < 0) {
		eprintf("output gpio init\n");
	}

	return ret;
}

static void dev_gpio_exit(void)
{
	int i;

	gpio_free(TVOUT_DET);
	gpio_free(HDCAM0_DET);
	gpio_free(HDCAM1_DET);

	gpio_free(HDCAM0_PWR);
	gpio_free(HDCAM1_PWR);

	//# led exit
	for(i=0; i<MAX_LEDS; i++) {
		gpio_free(leds[i]);		//# led off
	}
}

/*----------------------------------------------------------------------------
 control gpio functions
-----------------------------------------------------------------------------*/
static void ctrl_led_all(int on)
{
	int i;

	if(on) {		//# all led on
		for(i=0; i<MAX_LEDS; i++) {
			gpio_set_value(leds[i], LED_ON);
		}
	}
	else {			//# all led off
		for(i=0; i<MAX_LEDS; i++) {
			gpio_set_value(leds[i], LED_OFF);
		}
	}
}

void ctrl_hdcam_pwr(int on)
{
	if(on) {
		gpio_set_value(HDCAM0_PWR, ON);
		gpio_set_value(HDCAM1_PWR, ON);
	} else {
		gpio_set_value(HDCAM0_PWR, OFF);
		gpio_set_value(HDCAM1_PWR, OFF);
	}
}

/*----------------------------------------------------------------------------
 input check functions
-----------------------------------------------------------------------------*/
int ste_mmc(void)
{
	int status;

	status = disk_check_mount("/dev/mmcblk0");
	//dprintf("--- value %d\n", status);

	return status;
}

int ste_tvout(void)
{
	int status;

	gpio_get_value(TVOUT_DET, &status);

	return !status;		//# low active -> convert
}

int ste_hdcam(int ch)
{
	int status;

	if(ch == 0) {
		gpio_get_value(HDCAM0_DET, &status);
	} else {
		gpio_get_value(HDCAM1_DET, &status);
	}

	return status;
}

/*****************************************************************************
* @brief	buzzer thread function
* @section  [desc]
*****************************************************************************/
static void *THR_buzz(void *prm)
{
	app_thr_obj *tObj = &idev->bObj;
	int cmd, exit=0;
	int time, cnt;

	aprintf("enter...\n");
	tObj->active = 1;

	while(!exit)
	{
		cmd = event_wait(tObj);
		if(cmd == APP_CMD_EXIT) {
			break;
		}
		time = tObj->param0;
		cnt = tObj->param1;

		mic_send_msg(CMD_BUZZER, cnt, time);
	}

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    dev thread function
* @section  [desc]
*****************************************************************************/
static accel_data_t acc={0,};

static void *THR_gsn(void *prm)
{
	app_thr_obj *tObj = &idev->sObj;
	int ret, exit=0;
	accel_data_t acc_obj;

	aprintf("enter...\n");
	tObj->active = 1;

	//# g-sensor open
	ret = dev_accel_init();
	if(ret < 0) {
		eprintf("device open fail\n");
		return NULL;
	}
	dev_accel_start();

	while(!exit)
	{
		if(tObj->cmd == APP_CMD_EXIT) {
			break;
		}

		//# get accelerator sensor value
		ret = dev_accel_read(&acc_obj, TIME_GSN_CYCLE);
	    if(ret == 0)
	    {
			if( (abs(acc.x-acc_obj.x) > 5) || (abs(acc.y-acc_obj.y) > 5) || (abs(acc.z-acc_obj.z) > 5) ) {
				dprintf("x:%3d, y:%3d, z:%3d\n", acc_obj.x, acc_obj.y, acc_obj.z);
			}

			acc.x = acc_obj.x;	//# forward-backword
			acc.y = acc_obj.y;	//# up-down
			acc.z = acc_obj.z;	//# left-right
	    }
	}

    //# device close
	dev_accel_stop();
	dev_accel_exit();

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    dev thread function
* @section  [desc]
*****************************************************************************/
static void *THR_gps(void *prm)
{
	app_thr_obj *tObj = &idev->gObj;
	int ret, exit=0;
	struct gps_data_t gps_data;

	aprintf("enter...\n");
	tObj->active = 1;

	ret = dev_gps_init();
	if (ret < 0) {
		eprintf("gps init\n");
		return NULL;
	}

	while(!exit)
	{
		if(tObj->cmd == APP_CMD_EXIT) {
			break;
		}

		//# get gps value
		ret = dev_gps_get_data(&gps_data);
		if(ret == GPS_ONLINE)
		{
			//# check status mask
			if (gps_data.rmc_status == STATUS_FIX)
			{
				dprintf("GPS - DATE %04d-%02d-%02d, UTC %02d:%02d:%02d, speed=%.2f, (LAT:%.2f, LOT:%.2f) \n",
					gps_data.nmea.date.tm_year+1900, gps_data.nmea.date.tm_mon+1, gps_data.nmea.date.tm_mday,
					gps_data.nmea.date.tm_hour, gps_data.nmea.date.tm_min, gps_data.nmea.date.tm_sec,
					gps_data.nmea.speed, gps_data.nmea.latitude, gps_data.nmea.longitude
				);
			}
		}

		app_msleep(TIME_GPS_CYCLE);
	}

	dev_gps_close();

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    dev thread function
* @section  [desc]
*****************************************************************************/
static void *THR_dev(void *prm)
{
	app_thr_obj *tObj = &idev->dObj;
	int exit=0;
	int pre_mmc, mmc;
	int pre_tvo, tvo;

	aprintf("enter...\n");
	tObj->active = 1;

	pre_mmc = ste_mmc();
	tvo = ste_tvout();
	while(!exit)
	{
		if(tObj->cmd == APP_CMD_EXIT) {
			break;
		}

		//# check mmc card
		mmc = ste_mmc();
		if(mmc != pre_mmc) {
			pre_mmc = mmc;
			dprintf("SD Card %s\n", mmc?"insert":"remove");
		}

		//# check tvout connect
		tvo = ste_tvout();
		if(tvo != pre_tvo) {
			pre_tvo = tvo;
			dprintf("TVO Conn. %s\n", tvo?"insert":"remove");
		}

		app_msleep(TIME_DEV_CYCLE);
	}

	tObj->active = 0;
	aprintf("...exit\n");

	return NULL;
}

/*****************************************************************************
* @brief    device thread start/stop function
* @section  [desc]
*****************************************************************************/
int app_dev_start(void)
{
	app_thr_obj *tObj;

	//#--- create dev thread
	tObj = &idev->dObj;
	if(thread_create(tObj, THR_dev, APP_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	return SOK;
}

void app_dev_stop(void)
{
	app_thr_obj *tObj;

	//#--- stop dev thread
	tObj = &idev->dObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);
}

int app_gps_start(void)
{
	app_thr_obj *tObj;

	//#--- create dev thread
	tObj = &idev->gObj;
	if(thread_create(tObj, THR_gps, APP_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	return SOK;
}

void app_gps_stop(void)
{
	app_thr_obj *tObj;

	//#--- stop dev thread
	tObj = &idev->gObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);
}

int app_gsn_start(void)
{
	app_thr_obj *tObj;

	//#--- create dev thread
	tObj = &idev->sObj;
	if(thread_create(tObj, THR_gsn, APP_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	return SOK;
}

void app_gsn_stop(void)
{
	app_thr_obj *tObj;

	//#--- stop dev thread
	tObj = &idev->sObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);
}

int app_buzz_start(void)
{
	app_thr_obj *tObj;

	//#--- create dev thread
	tObj = &idev->bObj;
	if(thread_create(tObj, THR_buzz, APP_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return EFAIL;
	}

	return SOK;
}

void app_buzz_stop(void)
{
	app_thr_obj *tObj;

	//#--- stop dev thread
	tObj = &idev->bObj;
	event_send(tObj, APP_CMD_EXIT, 0, 0);
	while(tObj->active) {
		OSA_waitMsecs(10);
	}
	thread_delete(tObj);
}

/*****************************************************************************
* @brief    device init/exit function
* @section  [desc]
*****************************************************************************/
int app_dev_init(void)
{
	//# static config clear
	memset((void *)idev, 0x0, sizeof(app_dev_t));

	dev_gpio_init();

	app_dev_start();

	return SOK;
}

void app_dev_exit(void)
{
	app_dev_stop();

	dev_gpio_exit();
}

/*****************************************************************************
* @brief    buzzer demo function
* @section  [desc]
*****************************************************************************/
const char menu_buz[] = {
	"\r\n -------------"
	"\r\n Buzzer Menu"
	"\r\n -------------"
	"\r\n 0: stop"
	"\r\n 1: buzzer"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_buzz(void)
{
	int done = 0;
	char cmd = 0;

	app_buzz_start();

	while (!done)
	{
		printf(menu_buz);
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
				event_send(&idev->bObj, APP_CMD_NOTY, 100, 2);		//# 100ms, 2times
				break;
		}
	}

	app_buzz_stop();

	return 0;
}

/*****************************************************************************
* @brief    g-sensor demo function
* @section  [desc]
*****************************************************************************/
const char menu_gsn[] = {
	"\r\n -------------"
	"\r\n G-Sensor Menu"
	"\r\n -------------"
	"\r\n 0: stop"
	"\r\n%s1: g-sensor start/stop"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_gsn(void)
{
	int done = 0;
	char cmd = 0;
	int ste_gsn=0;

	while (!done)
	{
		printf(menu_gsn, ste_gsn?"*":" ");
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
				ste_gsn = 1 - ste_gsn;
				if(ste_gsn) {
					app_gsn_start();
				} else {
					app_gsn_stop();
				}
				break;
		}
	}

	if(ste_gsn) {
		app_gsn_stop();
	}

	return 0;
}

/*****************************************************************************
* @brief    gps demo function
* @section  [desc]
*****************************************************************************/
const char menu_gps[] = {
	"\r\n -------------"
	"\r\n GPS Menu"
	"\r\n -------------"
	"\r\n 0: stop"
	"\r\n%s1: gps start/stop"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_gps(void)
{
	int done = 0;
	char cmd = 0;
	int ste_gps=0;

	while (!done)
	{
		printf(menu_gps, ste_gps?"*":" ");
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
				ste_gps = 1 - ste_gps;
				if(ste_gps) {
					app_gps_start();
				} else {
					app_gps_stop();
				}
				break;
		}
	}

	if(ste_gps) {
		app_gps_stop();
	}

	return 0;
}

/*****************************************************************************
* @brief    gpio demo function
* @section  [desc]
*****************************************************************************/
const char menu_led[] = {
	"\r\n -------------"
	"\r\n GPIO Menu"
	"\r\n -------------"
	"\r\n 0: stop"
	"\r\n%s1: led on/off"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_gpio(void)
{
	int done = 0;
	char cmd = 0;
	int ste_led=0;

	while (!done)
	{
		printf(menu_led, ste_led?"*":" ");
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
				ste_led = 1 - ste_led;
				ctrl_led_all(ste_led);
				break;
			case '2':

				break;
		}
	}

	return 0;
}

/*****************************************************************************
* @brief    device demo function
* @section  [desc]
*****************************************************************************/
const char menu_device[] = {
	"\r\n ============="
	"\r\n Device Menu"
	"\r\n ============="
	"\r\n"
	"\r\n 0: stop"
	"\r\n 1: gpio test"
	"\r\n 2: gps test"
	"\r\n 3: g-sensor test"
	"\r\n 4: buzzer test"
	"\r\n"
	"\r\n Enter Choice: "
};

int test_device(void)
{
	int done = 0;
	char cmd = 0;

	while (!done)
	{
		printf(menu_device);
		cmd = menu_get_cmd();

		switch(cmd)
		{
			case '0':
				done = 1;
				break;
			case '1':
				test_gpio();
				break;
			case '2':
				test_gps();
				break;
			case '3':
				test_gsn();
				break;
			case '4':
				test_buzz();
				break;
		}
	}

	return 0;
}
