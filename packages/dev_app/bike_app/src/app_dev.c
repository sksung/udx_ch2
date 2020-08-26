/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_dev.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.04.01 : First Created
 *     - 2013.09.03 : Modified by sksung
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>

#include "osa.h"
#include "osa_thr.h"
#include "osa_sem.h"
#include "osa_mutex.h"

#include "ti_media_std.h"
#include "ti_vcap.h"

#include "dev_common.h"
#include "dev_gpio.h"
#include "dev_micom.h"
#include "dev_accel.h"


#include "app_cap.h"
#include "app_snd.h"
#include "app_util.h"
#include "app_ctrl.h"
#include "app_dev.h"
#include "app_micom_main.h"
#include "app_set.h"
#include "app_rec.h"
#include "app_file.h"
#include "app_tzone.h"
#include "app_gui.h"


/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

//# ms --------------------------
#define DEV_1_SEC           1000
#define DEV_1_MINUTE        (60*DEV_1_SEC)
#define DEV_1_HOUR          (60*DEV_1_MINUTE)
#define DEV_1_DAY           (24*DEV_1_HOUR)

#define DRIVE_MODE_TIME     (30*DEV_1_SEC)

#define DEV_CYCLE_TIME      500     //# temp, gps

#define GPIO_IRQ_CYCLE_TIME		300
#define GPIO_IRQ_DEBOUNCE_TIME	1500

#define TIMER_INTERVAL      100
//-------------------------------
#define CNT_GPIO_IRQ_DEBOUNCE	(GPIO_IRQ_DEBOUNCE_TIME/GPIO_IRQ_CYCLE_TIME)

typedef struct{
    app_thr_obj *devObj;	//# device
    app_thr_obj *vltObj;	//# voltage
    app_thr_obj *tmrObj;	//# timer
	app_thr_obj *tvObj; 	    //# tv_out detect thread

    OSA_MutexHndl mutex_gps;
} app_dev_t;

static app_dev_t t_dev;
static app_dev_t *idev;
extern app_micom_t *imicom;
static app_micom_t t_micom;

static int led_toggle=0;

struct gps_data_t gps_data;
static char mmc_fd_buf[32 + 1];

extern app_cfg_t *app_cfg;
/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 menu stop function
-----------------------------------------------------------------------------*/
void dev_system_stop(void)
{
    system_buzzer(SYSTEM_OPER);
    ubx_change_setting(); 
	
	app_cfg->state.pwroff = 1;
    event_send(app_cfg->uObj, UBX_GUI_LOGO, 0, 0);
	event_send(app_cfg->mObj, UBX_CMD_EXIT, 0, 0);
}

void dev_system_reboot(int update)
{
    if(update == REBOOT_NORMAL)
        system_buzzer(SYSTEM_OPER);
    else
        mic_send_msg(CMD_BUZZER, 3, BUZZER_100);

	app_log_write(MSG_LOG_SHUTDOWN, " >>>> System Reboot!!! <<<<");

	event_send(app_cfg->uObj, UBX_GUI_LOGO, 0, 0);
    app_rec_stop();
	app_file_stop();
    OSA_waitMsecs(100);

	mic_exit_state(OFF_RESET, 0);
	app_micom_exit();
}

/*****************************************************************************
 * @brief    secure led main function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
 //status LED
void rec_led_run(int on)
{
    gpio_set_value(STATUS_LED_1, on);
}

//power LED
void pwr_led_run(int on)
{
    gpio_set_value(STATUS_LED_2, on);
}

//AC LED (GPS)
void ac_led_run(int on)
{
    gpio_set_value(STATUS_LED_3, on);
}

int rec_state_led()
{
    if(!app_cfg->state.park){
		rec_led_run(app_cfg->state.rec);
    }
    else{
		rec_led_run(app_cfg->state.evt);
    }
    
    return 0;    
}

/*----------------------------------------------------------------------------
 gpio init function for D16
-----------------------------------------------------------------------------*/
int app_dev_gpio_init(void)
{
	int r = 0;

	/* initialize gpio status1 led (default high output) */
	r = gpio_init(STATUS_LED_1, GPIO_OUTPUT, GPIO_IRQ_NONE, 1);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", STATUS_LED_1);
	}
	gpio_set_active_low(STATUS_LED_1, 1); /* set active_low */

	/* initialize gpio status2 led (default high output) */
	r = gpio_init(STATUS_LED_2, GPIO_OUTPUT, GPIO_IRQ_NONE, 1);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", STATUS_LED_2);
	}
	gpio_set_active_low(STATUS_LED_2, 1); /* set active_low */

	/* initialize gpio status3 led (default high output) */
	r = gpio_init(STATUS_LED_3, GPIO_OUTPUT, GPIO_IRQ_NONE, 1);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", STATUS_LED_3);
	}
	gpio_set_active_low(STATUS_LED_3, 1); /* set active_low */

	/* tvout-detection gpio (active high) */
	r = gpio_init(TVOUT_DET_GIO, GPIO_INPUT, GPIO_IRQ_BOTH, 0);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", TVOUT_DET_GIO);
	}

	/* gpio record key (active low) */
	r = gpio_init(REC_KEY_GIO, GPIO_INPUT, GPIO_IRQ_FALLING, 0);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", REC_KEY_GIO);
	}

	/* HD sensor0 detection gpio */
	r = gpio_init(HDSENS0_DET_GIO, GPIO_INPUT, GPIO_IRQ_NONE, 0);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", HDSENS0_DET_GIO);
	}

	/* HD sensor1 detection gpio */
	r = gpio_init(HDSENS1_DET_GIO, GPIO_INPUT, GPIO_IRQ_NONE, 0);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", HDSENS1_DET_GIO);
	}

	/* HD sensor0 cam pwr gpio */
	r = gpio_init(HDSENS0_PWR_GIO, GPIO_OUTPUT, GPIO_IRQ_NONE, 1);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", HDSENS0_PWR_GIO);
	}

	/* HD sensor1 cam pwr gpio */
	r = gpio_init(HDSENS1_PWR_GIO, GPIO_OUTPUT, GPIO_IRQ_NONE, 1);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", HDSENS1_PWR_GIO);
	}

	return r;
}

/*----------------------------------------------------------------------------
 gpio exit function for ucx
-----------------------------------------------------------------------------*/
void app_dev_gpio_exit(void)
{
	gpio_free(STATUS_LED_1);
	gpio_free(STATUS_LED_2);
	gpio_free(STATUS_LED_3);

	gpio_free(TVOUT_DET_GIO); //# interrupt driven
	gpio_free(REC_KEY_GIO);   //# interrupt driven

	gpio_free(HDSENS0_DET_GIO);
	gpio_free(HDSENS1_DET_GIO);
	gpio_free(HDSENS0_PWR_GIO);
	gpio_free(HDSENS1_PWR_GIO);
}

/*----------------------------------------------------------------------------
 watchdog init/keep alive function
-----------------------------------------------------------------------------*/
void app_watchdog_init(int en, short sec)
{
	mic_set_watchdog(en, sec);
}

void app_watchdog_keep_alive(void)
{
	mic_keep_alive();
}

/*----------------------------------------------------------------------------
 set led default state function
 -----------------------------------------------------------------------------*/
int dev_led_default(void)
{
    led_toggle = ON;
	rec_led_run(OFF);
	pwr_led_run(led_toggle);
	ac_led_run(OFF);

	return 0;
}

static int dev_led_all_off(void)
{
	gpio_set_value(STATUS_LED_1, 0);
	gpio_set_value(STATUS_LED_2, 0);
	gpio_set_value(STATUS_LED_3, 0);

	return 0;
}

static void app_dev_mmc_main(int notify)
{
	char msg[CHAR_128];
	
	if (notify)
	{
		if (app_cfg->state.mmc) {
			app_cfg->state.mmc = 0; //# don't sync			
			sprintf( msg, " !!! SD card REMOVE !!!" );
			app_log_write( MSG_LOG_WRITE, msg );
			app_cfg->state.sd_buzzer = 1;
			dprintf("SD card REMOVE!!!\n");
			if (app_cfg->state.cap || app_cfg->state.rec)
				app_rec_stop();

			app_cfg->state.secu_on = 1;
            app_cfg->state.rec = 0;
		}
	} else {
		if (!app_cfg->state.format && !app_cfg->state.mmc) {
			sprintf( msg, " !!! SD card INSERT !!!");
			app_log_write( MSG_LOG_WRITE, msg );
			app_cfg->state.mmc = 1;
            app_cfg->state.sd_buzzer = 0;
			app_cfg->state.secu_on = 0;

            app_cfg->state.cam_buzzer = 0; //for reboot alarm

            dev_system_reboot(REBOOT_NORMAL);
		}
	}
}

/*****************************************************************************
 * @brief    time sync function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
static void set_gpstime_to_systime(void)
{
	app_log_write( MSG_LOG_WRITE, "[APP_DEV] GPS Time sync..." ); 

    int year, mon, day, hour, min, sec;
	///// GPS UTC change to local time	/////
	year    = (gps_data.nmea.date.tm_year + 1900); //# (-1900) in ctrl_time_set
	mon     = (gps_data.nmea.date.tm_mon + 1); //# (-1) in ctrl_time_set
	day     = gps_data.nmea.date.tm_mday;
	hour    = gps_data.nmea.date.tm_hour;
	min     = gps_data.nmea.date.tm_min;
	sec 	= gps_data.nmea.date.tm_sec;

#if 0
	if (gps_data.nmea.date.tm_sec == 59)
		sec = 0;
	else
		sec = gps_data.nmea.date.tm_sec + 1;
#endif
    ctrl_time_set(year, mon, day, hour, min, sec, 1);
}

/*****************************************************************************
 * @brief    device main function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
static void *dev_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	int cmd, exit=0;
	int ret;
    int gps_cycle=1000;
    time_t now;
	struct tm ts;

    now = time(NULL);
	//ts = localtime(&now);
	localtime_r((const time_t *)&now, &ts);

    if(ts.tm_year < 114){
        ctrl_time_set(2014, 1, 1, 0, 0, 0, 0); // time default when the year under 2014...
    }

	printf(" [task] %s start\n", __func__);
	tObj->done = 0;

	if(dev_gps_init() != SOK){
		eprintf("gps init\n");
		app_log_write( MSG_LOG_WRITE, "[APP_DEV] !!! GPS Initialize failed !!!" );
		goto dev_exit;
	}

	memset(&gps_data, 0, sizeof(struct gps_data_t));

	while(!exit)
	{
		app_cfg->wd_flags |= WD_DEV;

		//# wait cmd
		//cmd = event_wait(tObj);
		cmd = tObj->cmd;
		if( (cmd == UBX_CMD_STOP) || app_cfg->state.pwroff) {
			break;
		}

        if(app_cfg->state.cap && gps_cycle > 1000)
		{
		    gps_cycle = 0;

			/* get gps value*/
			ret = dev_gps_get_data(&gps_data);
			if (ret == GPS_ONLINE)
			{
				#if 0
            	dprintf("GPS - UTC DATE %04d-%02d-%02d, UTC TIME %02d:%02d:%02d, "
            	        "speed = %.2f, (LAT:%.2f, LOT:%.2f)\n",
                    		gps_data.nmea.date.tm_year + 1900,
                    		gps_data.nmea.date.tm_mon + 1,
                    		gps_data.nmea.date.tm_mday,
                    		gps_data.nmea.date.tm_hour,
                    		gps_data.nmea.date.tm_min,
                    		gps_data.nmea.date.tm_sec,
                    		gps_data.nmea.speed,
                    		gps_data.nmea.latitude,
                    		gps_data.nmea.longitude);

				dprintf("ret_val[%02d] gps rmc status[%02d]======\n", ret, gps_data.rmc_status);
				#endif

				/* To check status mask */
				if (gps_data.set & G_STATUS_SET)
				{
					/* 0->STATUS_NO_FIX ('V'), 1->STATUS_FIX('A') */
	                app_cfg->state.gps = gps_data.rmc_status;

                    ac_led_run(app_cfg->state.gps);
					if (gps_data.set & G_TIME_SET) {
	                    if (app_cfg->state.tsync) {
	                        set_gpstime_to_systime();
	                        app_cfg->state.tsync = 0;
	                    }
					}
				}
			}
			else	//# disconnect
			{
                app_cfg->state.gps = 0;
				ac_led_run(app_cfg->state.gps);
			}
		}

		OSA_waitMsecs(DEV_CYCLE_TIME);
        gps_cycle+=DEV_CYCLE_TIME;
	}

dev_exit:
	dev_gps_close();

	tObj->done = 1;
	printf(" [task] %s stop\n", __func__);

	return NULL;
}

static void *timer_main(void *prm)
{
	unsigned int timer_cycle = 0;
	int cmd = 0;
	int exit = 0;
	int led_speed = 0;
	int val, mmc_fd, res = 0;
	char msg[CHAR_128]={0,};
	
	app_thr_obj *tObj = (app_thr_obj *)prm;

	memset(mmc_fd_buf, 0, sizeof(mmc_fd_buf));
	mmc_fd = open("/sys/class/gpio/gpio38/value", O_RDWR);
	if (mmc_fd < 0) {
		dprintf("couldn't open /sys/class/gpio/gpio38/value!!\n");
		return NULL;
	}

	/* dummy read : flush gpio */
	read(mmc_fd, mmc_fd_buf, sizeof(mmc_fd_buf) - 1);

	tObj->done = 0;
	while (!exit)
	{
		app_cfg->wd_flags |= WD_TMR;

		cmd = tObj->cmd;
		if( (cmd == UBX_CMD_STOP) || app_cfg->state.pwroff) {
			break;
		}

		//------------------------------------//
		//#--- secu-led display
		//------------------------------------//
		if(app_cfg->state.park)
		    led_speed = DEV_CYCLE_TIME*2;
        else
            led_speed = DEV_CYCLE_TIME;

		if(app_cfg->state.evt || app_cfg->state.secu_on)
			led_speed = TIMER_INTERVAL*2;

		if((!app_cfg->state.secu_on) && (timer_cycle != 0) && (timer_cycle%led_speed == 0))
		{
			led_toggle = !led_toggle;
		}

		if(app_cfg->state.secu_on && (timer_cycle != 0) && (timer_cycle%led_speed == 0)){
			led_toggle = !led_toggle;
		}

		if((timer_cycle != 0) && (timer_cycle%DEV_1_MINUTE == 0))
		{
			//------------------------------------//
			//#--- Battery safe mode check
			//------------------------------------//
			if(app_cfg->state.park && app_set->wd.bat_safe> BAT_SAFE_OFF)
			{
				app_cfg->bsafe_start += DEV_1_MINUTE;
                if(app_cfg->bsafe_start >= (app_cfg->bsafe_time*DEV_1_HOUR))
				{
					system_buzzer(SYSTEM_OPER);
					sprintf(msg, "Battery safe shut down!! bat_timer[%d], set_time[%d]",
							app_cfg->bsafe_start, (app_cfg->bsafe_time*DEV_1_HOUR));
					app_log_write( MSG_LOG_SHUTDOWN, msg );
					
					app_rec_stop();
					app_file_stop();

					OSA_waitMsecs(200);
					mic_exit_state(OFF_NORMAL, 0);
					app_micom_exit();
				}
			}
		}

		if((timer_cycle != 0) && (timer_cycle%(DEV_1_SEC*5) == 0))
		{
		}


		/* mmc detect */
		lseek(mmc_fd, 0, SEEK_SET);
		res = read(mmc_fd, mmc_fd_buf, sizeof(mmc_fd_buf) - 1);
		if (res > 0)  {
			/* return value: gpio + '\n' = 2byte */
			val = strtol(mmc_fd_buf, NULL, 10);
			app_dev_mmc_main(val);
		}

		timer_cycle += TIMER_INTERVAL;
		OSA_waitMsecs(TIMER_INTERVAL);
	}

	if (mmc_fd >= 0)
		close(mmc_fd);

	tObj->done = 1;

	dev_led_all_off();
	printf(" [task] %s stop\n", __func__);
	return NULL;

}



/*****************************************************************************
 * @brief    get device data
 * @section  DESC Description
 *   - desc   POWER_HOLD pin to Low(Power OFF)
 *****************************************************************************/
void app_dev_get_gps(void *gps)
{
    GPS_RMC_DATA *pdata = (GPS_RMC_DATA *)gps;

    OSA_mutexLock(&idev->mutex_gps);

    pdata->gps_Enable		= (unsigned int)gps_data.rmc_status;
	pdata->gps_UTC_Year		= (unsigned int)gps_data.nmea.date.tm_year;
	pdata->gps_UTC_Month	= (unsigned int)gps_data.nmea.date.tm_mon;
	pdata->gps_UTC_Day		= (unsigned int)gps_data.nmea.date.tm_mday;
	pdata->gps_UTC_Hour		= (unsigned int)gps_data.nmea.date.tm_hour;
	pdata->gps_UTC_Min		= (unsigned int)gps_data.nmea.date.tm_min;
	pdata->gps_UTC_Sec		= (unsigned int)gps_data.nmea.date.tm_sec;
	pdata->gps_Speed  	    = (unsigned int)gps_data.nmea.speed;

	pdata->gps_LAT  = gps_data.nmea.latitude;
	pdata->gps_LOT 	= gps_data.nmea.longitude;
	pdata->gps_Dir	= gps_data.nmea.track;

    OSA_mutexUnlock(&idev->mutex_gps);
}

#ifdef DEBUG_GSV
void app_dev_gps_sensitivity(void* gps_sens)
{
    int i=0;

    GPS_SENSITIVITY* pdata = (GPS_SENSITIVITY*)gps_sens;

    pdata->satellites_visible = gps_data.satellites_visible;
    
    for(i=0; i < gps_data.satellites_visible; i++){
         pdata->ss[i] = gps_data.ss[i];
         pdata->PRN[i] = gps_data.PRN[i];
    }
}
#endif

/*****************************************************************************
 * @brief    input dio status
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int app_tvout_status(void)
{
	int val, ret = 0;

	//# switch value: 1 connect, 0 disconnect
	/*
	 * gpio initialize with hotplug thread..
	 * don't call before hotplug thread init.
	 */
	ret = gpio_get_value(TVOUT_DET_GIO, &val);
	if (ret) {
		/* failed to get gpio value */
		dprintf("Failed to read gpio(TV_OUT not connected!!)\n");
		return 0;
	}

//	dprintf("Default tv-out jack is %s\n", val?"disconnect":"connect");
	return !val; //# active_low
}

int app_dev_hdsens_status(int ch)
{
	int ret = 0, value;

	if (ch == 0) {
		ret = gpio_get_value(HDSENS0_DET_GIO, &value);
	} else if (ch == 1) {
		ret = gpio_get_value(HDSENS1_DET_GIO, &value);
	}

	if (ret < 0) {
		/* failed to read */
		value = 0;
	}

	return value;
}

/*****************************************************************************
 * @brief    monitor tv_out main function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
static void *mon_tvout_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	int ret, cmd;

	int value = 0;
	int exit = 0;
	int lastv = 0;

	int dcnt = CNT_GPIO_IRQ_DEBOUNCE; //# deboung count
	int irq_flag = 0; //# irq start event

	printf(" [task] %s start...\n", __func__);
	tObj->done = 0;

	while(!exit)
	{
		cmd = tObj->cmd;
        if (cmd == UBX_CMD_STOP || app_cfg->state.pwroff)
            break;

		//# wait event
		ret = gpio_irq_read(TVOUT_DET_GIO, &value, GPIO_IRQ_CYCLE_TIME);
		if (ret == 0) {
			if (!irq_flag)
				irq_flag = 1; //# start irq event.

			lastv = !value;
		} else {
			//dprintf("Failed to read tv-out jack %d\n", ret);
			//# To check tv-out state after debounce.
			if (irq_flag) {
				if (!dcnt) {
					//dprintf("tv-out jack %s\n", lastv ? "connected":"disconnected");
				   /*
	 				* High->Low: connected
	 				* Low->High: disconnected
	 				*/
					ctrl_tvo_enable(lastv);
					dcnt = CNT_GPIO_IRQ_DEBOUNCE;  irq_flag = 0;
				} else
					dcnt--;
			}
		}
	}
	tObj->done = 1;

	printf(" [task] %s stop\n", __func__);

	return NULL;
}

/*****************************************************************************
* @brief    device thread start/stop function
* @section  DESC Description
*   - desc
*****************************************************************************/
void app_dev_start(void)
{
    int status;
    app_thr_obj *tObj;

	printf(" [app] %s start\n", __func__);

    idev = &t_dev;
	memset(idev, 0, sizeof(app_dev_t));
    imicom = &t_micom;
    memset(imicom, 0, sizeof(app_micom_t));

    status = OSA_mutexCreate(&(idev->mutex_gps));
    OSA_assert(status == OSA_SOK);

	dev_led_default();
	ctrl_hdcam_pwron();

    //#--- micom message thread
 	tObj = malloc(sizeof(app_thr_obj));
	if(tObj != NULL) {
		OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
		OSA_thrCreate(&tObj->thr, micom_main, FXN_TSK_PRI+1, 0, tObj);
		imicom->micomObj = tObj;
	}
	else
		eprintf("%s: MICOM thread obj malloc fail\n", __func__);

    //#--- volt message thread
 	tObj = malloc(sizeof(app_thr_obj));
	if(tObj != NULL) {
		OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
		OSA_thrCreate(&tObj->thr, volt_check_main, FXN_TSK_PRI+1, 0, tObj);
		imicom->voltObj= tObj;
	}
	else
		eprintf("%s: VOLT check thread obj malloc fail\n", __func__);

    //#--- gps, led
	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj != NULL)
	{
		OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
		OSA_thrCreate(&tObj->thr, dev_main, FXN_TSK_PRI+2, 0, tObj);
		idev->devObj = tObj;
	}
	else
	{
		eprintf("gps thread obj malloc fail\n");
	}


	//#--- timer, auto park, led, format duration
    //#--- power key, acc check
 	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj != NULL)
	{
		OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
		OSA_thrCreate(&tObj->thr, timer_main, FXN_TSK_PRI+2, 0, tObj);
		idev->tmrObj = tObj;
	}
	else
	{
		eprintf("%s: gps thread obj malloc fail\n", __func__);
	}

	//# tvout detect
	tObj = app_malloc(sizeof(app_thr_obj));
	if (tObj != NULL) {
		OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
		OSA_thrCreate(&tObj->thr, mon_tvout_main, FXN_TSK_PRI+2, 0, tObj);
		//# resgister thread obj
		idev->tvObj = tObj;
	}
	else
	{
		eprintf("%s: tv-out detect thread obj malloc fail\n", __func__);
	}
}

void app_dev_stop(void)
{
    int status;
    app_thr_obj *tObj;

	if(idev == NULL)
		return;

	//#--- dev_stop
	tObj = (app_thr_obj *)idev->devObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);
		while(!tObj->done)
			OSA_waitMsecs(10);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
	}


    //# micom exit
	mic_data_send(0, 0);		//# data send stop
	tObj = (app_thr_obj *)imicom->micomObj;
	if(tObj != NULL)
	{
		//event_send(tObj, UBX_CMD_STOP, 0, 0);		//# need not
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		free(tObj);
		tObj = NULL;
	}

    //#-- volt check stop
	tObj = imicom->voltObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);

		while(!tObj->done)
			OSA_waitMsecs(10);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
	}

	//#-- timer stop
	tObj = idev->tmrObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);

		while(!tObj->done)
			OSA_waitMsecs(10);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
	}


    //#-- tv-out detect stop
	tObj = idev->tvObj;
	if(tObj != NULL)
	{
		event_send(tObj, UBX_CMD_STOP, 0, 0);
		while(!tObj->done)
			OSA_waitMsecs(10);

		OSA_semDelete(&tObj->sem);
		OSA_thrDelete(&tObj->thr);

		app_mfree(tObj);
		tObj = NULL;
	}

    status = OSA_mutexDelete(&(idev->mutex_gps));
    OSA_assert(status == OSA_SOK);

	idev = NULL;
    printf(" [app] %s done!\n", __func__);
}


int system_buzzer(int state){

    if(state == SYSTEM_NONE){
        rec_state_led();
    }
    
    if(app_cfg->state.sd_buzzer || app_cfg->state.cam_buzzer)
        return -1;

    if(state == SYSTEM_OPER){
        if(app_set->aud.snd_on)
            mic_send_msg(CMD_BUZZER, 2, BUZZER_100);

        rec_state_led();
    }
    else if(state == SYSTEM_ERR){
        if(app_set->aud.snd_on)
            mic_send_msg(CMD_BUZZER, 2, BUZZER_100);
        
        rec_led_run(ON);
    }

    return 0;
}


