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
//#include "ucx_main.h"
#include "app_cap.h"
#include "dev_accel.h"
#include "app_snd.h"
#include "app_util.h"
#include "app_ctrl.h"
#include "app_dev.h"
#include "app_micom_main.h"
#include "app_set.h"
#include "app_rec.h"
#include "app_file.h"

#include "app_gui.h"
#include "dev_micom.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

//# ms --------------------------
#define DEV_1_SEC           1000
#define DEV_1_MINUTE        (60*DEV_1_SEC)
#define DEV_1_HOUR          (60*DEV_1_MINUTE)
#define DEV_1_DAY           (24*DEV_1_HOUR)

#define DRIVE_MODE_TIME     (30*DEV_1_SEC)

#define GSENS_CYCLE_TIME	100     //# g-sensor
#define DEV_CYCLE_TIME      500     //# temp, gps

#define GPIO_IRQ_CYCLE_TIME		300
#define GPIO_IRQ_DEBOUNCE_TIME	1500

#define GSENS_FIRST_DELAY_TIME	2000
#define GSENS_FIRST_DELAY_CNT	( GSENS_FIRST_DELAY_TIME / GSENS_CYCLE_TIME )

#define TIMER_INTERVAL      100

#define TIME_DEBOUNCING		  600	//# debouncing time for power switch or acc

//-------------------------------
#define CNT_GSENS_CHK		0//1
#define CNT_GPIO_IRQ_DEBOUNCE	(GPIO_IRQ_DEBOUNCE_TIME/GPIO_IRQ_CYCLE_TIME)

#define LSG					(255.0)	//-128 ~ 127	offset 0.064 (+/- 8G)

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
//float SENSITIVITY_TABLE[2][10] = { {0.6, 0.5, 0.4, 0.3, 0.2},			//# driving mode
//                                   {0.1, 0.08, 0.06, 0.04, 0.02} };		//# parking mode
float SENSITIVITY_TABLE[2][10] = { {1.2, 0.9, 0.6, 0.3, 0.1},			//# driving mode
                                   {0.1, 0.08, 0.06, 0.04, 0.02} };		//# parking mode

typedef struct{
    app_thr_obj *devObj;	//# device
    app_thr_obj *gsnObj;	//# G-sensor
    app_thr_obj *vltObj;	//# voltage
    app_thr_obj *dioObj;	//# DIO
    app_thr_obj *tmrObj;	//# timer
	app_thr_obj *tvObj; 	    //# tv_out detect thread

    OSA_MutexHndl mutex_gps;
    OSA_MutexHndl mutex_gsn;
#ifdef DEBUG_GSV
    OSA_MutexHndl mutex_gsv;
#endif

} app_dev_t;

static app_dev_t t_dev;
static app_dev_t *idev;
extern app_micom_t *imicom;
static app_micom_t t_micom;

static app_gs_t gs_meta[GSENSOR_CNT_MAX];
static int gs_cnt = 0;
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
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", HDSENS0_DET_GIO);
	}

	/* HD sensor1 cam pwr gpio */
	r = gpio_init(HDSENS1_PWR_GIO, GPIO_OUTPUT, GPIO_IRQ_NONE, 1);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", HDSENS1_DET_GIO);
	}

#if DETECT_EMG_GIO
	/* Emergency detect gpop */
	r = gpio_init(EMG_DET_GIO, GPIO_INPUT, GPIO_IRQ_NONE, 0);
	if (r) {
		dprintf("[NOTICE] Couldn't initizlie gpio %d\n", EMG_DET_GIO);
	}
#endif

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

	gpio_free(HDSENS0_DET_GIO);
	gpio_free(HDSENS1_DET_GIO);
	gpio_free(HDSENS0_PWR_GIO);
	gpio_free(HDSENS1_PWR_GIO);

#if DETECT_EMG_GIO
	gpio_free(EMG_DET_GIO);	
#endif
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
			app_cfg->state.mmc 			= 0; //# don't sync
			app_cfg->state.sd_buzzer 	= 1;

			sprintf( msg, " !!! SD card REMOVE !!!" );
			app_log_write( MSG_LOG_WRITE, msg );

			if (app_cfg->state.cap || app_cfg->state.rec)
				app_rec_stop();

			app_cfg->state.secu_on 	= 1;
            app_cfg->state.rec 		= 0;
		}
	} else {
		if (!app_cfg->state.format && !app_cfg->state.mmc) {

			sprintf( msg, " !!! SD card INSERT !!!");
			app_log_write( MSG_LOG_WRITE, msg );

			app_cfg->state.mmc 			= 1;
            app_cfg->state.sd_buzzer 	= 0;
			app_cfg->state.secu_on 		= 0;
            app_cfg->state.cam_buzzer 	= 0; //for reboot alarm

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

	if (gps_data.nmea.date.tm_sec == 59)
		sec = 0;
	else
		sec = gps_data.nmea.date.tm_sec + 1;

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
	struct tm *ts;

    now = time(NULL);
	ts = localtime(&now);

    if(ts->tm_year < 114){
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

static void gs_meta_reset()
{
    gs_cnt = 0;
    memset(gs_meta, 0, (sizeof(app_gs_t)*GSENSOR_CNT_MAX));
}

static void gs_meta_add(accel_data_t* acc)
{
    OSA_mutexLock(&idev->mutex_gsn);

    if(gs_cnt >= GSENSOR_CNT_MAX)
         gs_meta_reset();

    struct timeval tv;
    gettimeofday(&tv, NULL);

    gs_meta[gs_cnt].acc_sec       = tv.tv_sec;
    gs_meta[gs_cnt].acc_msec      = tv.tv_usec/1000;
    gs_meta[gs_cnt].acc_level.x   = acc->x;
    gs_meta[gs_cnt].acc_level.y   = acc->z;
    gs_meta[gs_cnt].acc_level.z   = acc->y;

    gs_cnt++;
    OSA_mutexUnlock(&idev->mutex_gsn);
}

static void *gsensor_main(void *prm)
{
    int cmd, exit = 0, first=GSENS_FIRST_DELAY_CNT;
    accel_data_t acc, level;
    float impact, threshold = 30.;
    accel_data_t acc_obj;
	int ret = 0;

	printf(" [task] %s start\n", __func__);

    app_thr_obj *tObj = (app_thr_obj *)prm;

    tObj->done = 0;
    memset(&acc, 0, sizeof(accel_data_t));

    gs_meta_reset();

	ret = dev_accel_init();
	if (ret < 0) {
		eprintf("Gsensor init\n");
		app_log_write( MSG_LOG_WRITE, "[APP_DEV] !!! G-Sensor Initialize failed !!!" );
		goto gsn_exit;
	}

	dev_accel_start();

    while (!exit) {

		app_cfg->wd_flags |= WD_GSN;

		cmd = tObj->cmd;
		if( (cmd == UBX_CMD_STOP) || app_cfg->state.pwroff) {
			break;
		}

        if(app_cfg->state.cap && app_set->sys.motion_only == OFF)
        {
            /* get accelerator sensor value*/
            if(dev_accel_read(&acc_obj, 100) == 0)
            {
				if(first > 0) {
					acc.x = acc_obj.x;
					acc.y = acc_obj.y;
					acc.z = acc_obj.z;
					first--;
				}
				else
				{
                    level.x = abs(acc_obj.x - acc.x);
                    level.y = abs(acc_obj.y - acc.y);
                    level.z = abs(acc_obj.z - acc.z);

					if(level.x > level.y)
                        impact = level.x;
                    else
                        impact = level.y;
                    if(level.z > impact)
                        impact = level.z;

					if( app_set->wd.gsn < GSN_IDX_OFF ){
						if( DETECT_EMG_GIO == 0)
						{
							//#--- accident!!
							threshold = SENSITIVITY_TABLE[app_cfg->state.park][app_set->wd.gsn] * LSG;
							if(impact > threshold)
							{
								dprintf("G_Sensor event(%f/%f)===\n", impact, threshold);
								app_cfg->state.shock  = 1;
								if(ATVS_MODE) {
									if(app_cfg->state.park){
										app_evt_record(REC_PARKING);
									}
								}
								else {
									#ifndef USE_HTRV
									if(app_cfg->state.park){
										app_evt_record(REC_PARKING);
									}
									else
								    #endif
										app_evt_record(REC_EVENT);
								}

#if 1
								printf("\n***********************************************\n");
								printf("Prev Data x[%03d] y[%03d] z[%03d]\n",acc.x, acc.y, acc.z);
								printf("Cur  Data x[%03d] y[%03d] z[%03d]\n",acc_obj.x, acc_obj.y, acc_obj.z);
								printf("LevelData x[%03d] y[%03d] z[%03d]\n",level.x ,level.y, level.z);
	
								printf("impact detect: Impact = %03f, Threshold = %03f\n", impact, threshold);
								printf("park[%d] gsensor_lvl[%d]===\n",app_cfg->state.park,app_set->wd.gsn);
								printf("***********************************************\n\n");
#endif
							}
						}
					}
                    if(app_cfg->state.mmc && app_cfg->state.rec)
                        gs_meta_add(&level);


                    //#--- auto parking mode check
                    threshold = SENSITIVITY_TABLE[MODE_PARKING][app_set->wd.gsn] * LSG;
                    if(impact > threshold)
                        app_cfg->state.gsn = 1;


					acc.x = acc_obj.x;
					acc.y = acc_obj.y;
					acc.z = acc_obj.z;
				}
			}
        }

        OSA_waitMsecs(GSENS_CYCLE_TIME);
    }

gsn_exit:
	dev_accel_stop();
	dev_accel_exit();
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
	int res = 0, val, mmc_fd;
	char msg[CHAR_128];

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

        /*if(app_cfg->state.rec == 1 && app_cfg->state.evt == 0){
            if(app_cfg->state.park)
                rec_led_run(OFF);
            else
                rec_led_run(ON);
        }
        else if(app_cfg->state.rec == 1 && app_cfg->state.evt == 1){
            rec_led_run(led_toggle);
        }
        else if(app_cfg->state.rec == 0){
            rec_led_run(OFF);
        }*/

		#ifdef DEBUG_AUTO_REBOOT
		if((timer_cycle != 0) && (timer_cycle%(DEV_1_MINUTE*20) == 0))
		{
			system_buzzer(SYSTEM_OPER);
			app_log_write( MSG_LOG_SHUTDOWN, "[DEBUG] ###### AUTO REBOOT SHUT DOWN!! ###### " );
			
			ubx_write_setting();
			app_rec_stop();
			app_file_stop();

			OSA_waitMsecs(200);
			mic_exit_state(OFF_RESET, 0);
			app_micom_exit();
		}
		#endif

		if((timer_cycle != 0) && (timer_cycle%DEV_1_MINUTE == 0))
		{
			if(app_cfg->state.mmc)
			{
				//------------------------------------//
				//#--- format duration check
				//------------------------------------//
				if(app_set->fdur.weeks != SD_FORMAT_OFF){
					unsigned long long dur_now;
					time((time_t*)&dur_now);

					if(app_set->fdur.start >= app_cfg->fdur_weeks)
					{
						#ifdef TIME_DEBUG
					    time_debug_clock(__func__, 1);
    	                #endif

						app_cfg->state.fdur = 1;
                        app_cfg->state.sd_buzzer = 1;
					}

					app_set->fdur.start += MIN_SEC;
				}

				//------------------------------------//
				//#--- Battery safe mode check
				//------------------------------------//
				if(app_cfg->state.park && app_cfg->bsafe_time > 0)
				{
					app_cfg->bsafe_start += DEV_1_MINUTE;
                    #ifdef TIME_DEBUG
					if(app_cfg->bsafe_start > (app_cfg->bsafe_time*DEV_1_MINUTE))
					{
					    time_debug_clock(__func__, 2);
                    #else
                    if(app_cfg->bsafe_start > (app_cfg->bsafe_time*DEV_1_HOUR))
					{
                    #endif
						system_buzzer(SYSTEM_OPER);
					
						sprintf(msg, "Battery safe shut down!! bat_timer[%d], set_time[%d]",
								app_cfg->bsafe_start, (app_cfg->bsafe_time*DEV_1_HOUR));
						app_log_write( MSG_LOG_SHUTDOWN, msg );
						printf("%s \n", msg);
						
						app_rec_stop();
						app_file_stop();

						OSA_waitMsecs(200);
						mic_exit_state(OFF_NORMAL, 0);
						app_micom_exit();
					}
				}
			}
		}

		if((timer_cycle != 0) && (timer_cycle%(DEV_1_SEC*5) == 0))
		{

			//#--- parking/driving mode check
			if(!app_cfg->state.acc && (app_set->wd.auto_park > AUTOPARK_OFF))
			{
				//printf("acc_detect[%d]===\n", app_cfg->state.acc);
				if(app_cfg->state.park)
				{
					//#--- added 5sec if triggered gsensor event.
					if(app_cfg->state.gsn){
						app_cfg->apark_start += DEV_1_SEC*5;
						dprintf(" --- [AP mode] gsensor detect...[%d] !!\n ",app_cfg->apark_start);
					}
					else
						app_cfg->apark_start = 0;

					//#--- change driving mode when threshold
					if(app_cfg->apark_start >= DRIVE_MODE_TIME)
					{
						dev_led_default();
						ctrl_mode_change(MODE_DRIVING);
						app_cfg->apark_start= 0;
					}
				}
				else //#--- driving mode currently.
				{
					if(app_cfg->state.gsn == 0){
						app_cfg->apark_start += DEV_1_SEC*5;
//						dprintf("APmode check... timer[%d] set_time[%d]====\n",
//							app_cfg->apark_start, (app_cfg->apark_time*DEV_1_MINUTE));
					}
					else
					{
						app_cfg->state.gsn		= 0;
						app_cfg->apark_start	= 0;
						dprintf("APmode check... G-sensor Detected!!!!\n");
//						dprintf("timer[%d] set_time[%d]====\n",
//							app_cfg->apark_start, (app_cfg->apark_time*DEV_1_MINUTE));
					}
					#ifdef TIME_DEBUG
					if(app_cfg->apark_start >= (app_cfg->apark_time*DEV_1_MINUTE)/10)
					{
					    time_debug_clock(__func__, 3);
                    #else
                    if(app_cfg->apark_start >= (app_cfg->apark_time*DEV_1_MINUTE))
					{
                    #endif

						dev_led_default();
						ctrl_mode_change(MODE_PARKING);
						app_cfg->apark_start = 0;
					}
				}

				app_cfg->state.gsn = 0;
			}
			else{
				app_cfg->apark_start = 0;
			}
		}

		/* mmc detect */
		lseek(mmc_fd, 0, SEEK_SET);
		res = read(mmc_fd, mmc_fd_buf, sizeof(mmc_fd_buf) - 1);
		if (res > 0)  {
			/* return value: gpio + '\n' = 2byte */
			val = strtol(mmc_fd_buf, NULL, 10);
			app_dev_mmc_main(val);
		}

#if DETECT_EMG_GIO
		if(app_cfg->state.cap){
			val = 0;
			res = gpio_get_value(EMG_DET_GIO, &val);
//			printf("emg_gpio: %02d, res: %02d ====\n", val, res);
			if(!val) app_evt_record(REC_EVENT);
		}
#endif

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

void app_dev_get_gs(void* gs)
{
    OSA_mutexLock(&idev->mutex_gsn);

    if(gs != NULL)
    {
        int size = 0;
        size = sizeof(app_gs_t)*GSENSOR_CNT_MAX;

        memset((app_gs_t*)gs, 0, size);

        memcpy((app_gs_t*)gs, gs_meta, size);
        gs_meta_reset();
    }

    OSA_mutexUnlock(&idev->mutex_gsn);
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
void app_dev_get_gsv(void* gsv)
{
    int i=0;

    GPS_GPGSV* pdata = (GPS_GPGSV*)gsv;

    pdata->gps_Total_SVs    = gps_data.gps_Satellites.gps_Total_SVs;
    for(i=0; i < pdata->gps_Total_SVs+1; i++){
    	pdata->gps_SV_PRN[i]    = gps_data.gps_Satellites.gps_SV_PRN[i];
    	pdata->gps_SV_SNR[i]	= gps_data.gps_Satellites.gps_SV_SNR[i];
    }
}

void app_dev_get_gsa(void* gsa)
{
    int i=0;

    GPS_GPGSA* pdata = (GPS_GPGSA*)gsa;

    pdata->gps_Auto    = gps_data.gps_Active.gps_Auto;
    pdata->gps_Mode    = gps_data.gps_Active.gps_Mode;
    pdata->gps_SA_Num  = gps_data.gps_Active.gps_SA_Num;
    for(i=0; i < GPS_MAX_SATELLITE_NUM; i++){
    	pdata->gps_Satellite_ID[i]    = gps_data.gps_Active.gps_Satellite_ID[i];
    }
    pdata->gps_PDOP    = gps_data.gps_Active.gps_PDOP;
    pdata->gps_HDOP    = gps_data.gps_Active.gps_HDOP;
    pdata->gps_VDOP    = gps_data.gps_Active.gps_VDOP;
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

    status = OSA_mutexCreate(&idev->mutex_gsn);
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

    //#--- Gsensor
 	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj != NULL)
	{
		OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
		OSA_thrCreate(&tObj->thr, gsensor_main, FXN_TSK_PRI+2, 0, tObj);
		idev->gsnObj = tObj;
	}
	else
	{
		eprintf("%s: gsensor thread obj malloc fail\n", __func__);
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

	//#--- gsensor stop
	tObj = (app_thr_obj *)idev->gsnObj;
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

    status = OSA_mutexDelete(&idev->mutex_gsn);
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
            mic_send_msg(CMD_BUZZER, 2, BUZZER_200);

        rec_state_led();
    }
    else if(state == SYSTEM_ERR){
        if(app_set->aud.snd_on)
            mic_send_msg(CMD_BUZZER, 2, BUZZER_200);

        rec_led_run(ON);
    }

    return 0;
}


