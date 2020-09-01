/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_micom_main.c
 * @brief
 * @author  sungeun
 * @section MODIFY history
 *     - 2014.12.22 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

//# For htons...
//# remove warning: 'struct mmsghdr' declared inside parameter list
#define __USE_GNU
#include <arpa/inet.h>

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

#define MIC_CYCLE_TIME		 200	//# msec, voltage, temp, acc
#define TIME_PEEK_VOLT_CHK	 1000	//# peek low voltage check time
#define TIME_PWRSW_CHK		 800	//# msec, power switch press time
#define TIME_ACC_CHK		 500    //3000	//# acc check time
#define TIME_CHANGE_MODE	10000	//# change park mode after acc check
#define TIME_VOLT_SKIP		60000	//# protection time until the power off after start

#define TIME_TEMP_CHK		60000	//# high temperature check time
#define VAL_TEMP_LOW		80		//# 'C, temperature of system power on
#define TEMP_CHK_CNT        3		//# DEV_CYCLE_TIME * cnt

#define CNT_PEEK_VOLT_CHK	(TIME_PEEK_VOLT_CHK/MIC_CYCLE_TIME) //# 1sec
#define CNT_VOLT_SKIP		(TIME_VOLT_SKIP/MIC_CYCLE_TIME)     //# 60sec

#define CNT_MODE_CHANGE		(TIME_CHANGE_MODE/MIC_CYCLE_TIME)   //# 10sec
#define CNT_TEMP_CHK		(TIME_TEMP_CHK/MIC_CYCLE_TIME)      //# 60sec

#define START_VOLTAGE_12V	1100	//# 12.00V
#define START_VOLTAGE_24V   2100    //# 24.00V
#define START_TEMERATURE	600

//static int peek_low_volt[VOLT_LEVEL_MAX] = {VOLT_12V_LOW, VOLT_24V_LOW};
static int acc_evt_on=1;
static int adc_first_init=0;
static int adc_first=0;   //# adc first time flag
static int temp_first=0;
static int temp_first_init=0;

static float cable_drop_val_D[COMPEN_MODE_MAX] 	= {3.6, 4.5, 2.5};
static float cable_drop_val_P[COMPEN_MODE_MAX]  = {2.7, 3.6, 1.8};
static float diode_val01 				= 0.32;
static float diode_val02				= 0.002;

static float temp_comp_val				= 0.0014;

app_micom_t *imicom;

int app_dev_get_volt_val(void)
{
    return imicom->val.mvolt;
}

int app_dev_get_temp_val(void)
{
    return imicom->val.temp;
}

/*----------------------------------------------------------------------------
 check voltage
-----------------------------------------------------------------------------*/
#define MAX_TIME_GAP	2500	//msec
#define MIN_VOLT_VAL	420		//4.2V
static int volt_skip_cnt=0, volt_peek_cnt=0 ;
static int dev_check_volt(int volt)
{
	int volt_low;
	char msg[CHAR_128];
	memset(msg, 0, CHAR_128);

    adc_first_init++;

	//# check input voltage level (12V or 24V)
	if(volt >= VOLT_24V_MIN)
		app_cfg->volt_level = VOLT_LEVEL_24V;
	else
		app_cfg->volt_level = VOLT_LEVEL_12V;
 
	//#--- voltage alert at first time (max 1min.)
	if(app_cfg->state.cap)
	{
	    if(adc_first && volt_skip_cnt > 5)
	    {
	        adc_first = 0;
	    }
        else if(adc_first && adc_first_init > 30){
            adc_first = 0;
        }
	}

	//#--- peek low voltage ---//
	if(volt < VOLT_LOW) 
	{
		volt_peek_cnt++;
        if(volt_peek_cnt >= CNT_PEEK_VOLT_CHK && !imicom->low_pwr_detect)
        {
            imicom->low_pwr_detect = 1;
			app_cfg->state.pwroff = 1;
			volt_peek_cnt = 0;
			
			printf(msg, "<<<< Peek Low Voltage Detected(%d.%dV) >>>>", (volt/100), (volt%100));
			system_buzzer(SYSTEM_OPER);

			app_rec_stop();
			app_file_stop();
            app_capt_stop();
            ctrl_hdcam_pwroff();
            ctrl_tvo_enable(OFF);

			sprintf(msg, "<<<< Peek Low Voltage Detected(%d.%dV) >>>>", (volt/100), (volt%100));
			app_log_write(MSG_LOG_SHUTDOWN, msg);

            if(app_cfg->volt_level == VOLT_LEVEL_12V)
    		    mic_exit_state(OFF_LOWPWR, START_VOLTAGE_12V);
            else if(app_cfg->volt_level == VOLT_LEVEL_24V)
                mic_exit_state(OFF_LOWPWR, START_VOLTAGE_24V);      

			struct timeval tv1, tv2;
			long gap=0;
            gettimeofday(&tv1, NULL);
            
            while(gap < MAX_TIME_GAP && imicom->val.svolt > MIN_VOLT_VAL){
                 gettimeofday(&tv2, NULL);
                 gap = ((tv2.tv_sec*1000)+(tv2.tv_usec/1000))-((tv1.tv_sec*1000)+(tv1.tv_usec/1000));
                 OSA_waitMsecs(10);
            }

			printf(" \n [app] msec[%ld] >>>>>>>> EXIT Volt(%d.%dV) <<<<<<< \n",
			((tv2.tv_sec*1000)+(tv2.tv_usec/1000))-((tv1.tv_sec*1000)+(tv1.tv_usec/1000)), 
			  (imicom->val.svolt/100), (imicom->val.svolt%100) );

            app_micom_exit();            

    	    return 1;
        }
	}
    else{
        volt_peek_cnt = 0;
    }

	//#--- low voltage check until 1min ---//
	volt_low = get_low_volt_val(app_cfg->volt_level, app_set->wd.volt); //# xxxx V format	
	if(volt < volt_low) {
	    volt_skip_cnt++;
	} else {
	    volt_skip_cnt = 0;
	}

    if(imicom->low_pwr_detect)
        app_cfg->wd_flags |= WD_ENC;

	if(volt_skip_cnt > CNT_VOLT_SKIP)
	{
		system_buzzer(SYSTEM_OPER);
		
		app_rec_stop();
		app_file_stop();
        app_capt_stop();
        ctrl_tvo_enable(OFF);
        ctrl_hdcam_pwroff();
		
		sprintf( msg, "[APP_MICOM] Low voltage Time out (%d.%dV)", (volt/100), (volt%100) );
		app_log_write( MSG_LOG_SHUTDOWN, msg );
		
		mic_exit_state(OFF_NORMAL, 0);
		app_micom_exit();
		
	    return 1;
	}

	return 0;
}

/*----------------------------------------------------------------------------
 check temperature
-----------------------------------------------------------------------------*/
static int temp_cnt=0;
static int dev_check_temp(int temp)
{
	char msg[CHAR_128];

	if(app_cfg->state.cap)
	{
		app_cfg->temp_high 	= get_temp_val(app_set->wd.temp);
		temp_first_init++;
	//#--- temp alert at first time
        if(temp_first == 1 && temp_cnt > 1)
        {
            system_buzzer(SYSTEM_OPER);
			
			sprintf(msg, "[APP_MICOM] High Temp Detected at first time(%d'C)", temp);
			app_log_write( MSG_LOG_WRITE, msg );
            
            temp_first = 2; //If the temperature is kept 10 seconds...
            temp_first_init = 0;
        }              
        else if(temp_first == 2 && temp_cnt > CNT_TEMP_CHK/6) // maintain temp exceed during 10sec at the system start
		{ 
			system_buzzer(SYSTEM_OPER);
			sprintf(msg, "[APP_MICOM] High Temp Shut down at first time(%d'C)", temp);
			app_log_write( MSG_LOG_SHUTDOWN, msg );

			app_rec_stop();
			app_file_stop();
		 	ubx_change_setting();
            temp_first = 0;
			
			OSA_waitMsecs(300);
			mic_exit_state(OFF_HITEMP, START_TEMERATURE);
			app_micom_exit();
			
        }
        else if((temp_first == 1 || temp_first == 2) && temp_first_init > CNT_TEMP_CHK/6){
            temp_first = 0;
        }  

        //high temp detect
	    if(temp >= app_cfg->temp_high)
	    {
	        temp_cnt++;

			#ifndef DEBUG_TEMP_DISPLAY
	        if(temp_cnt > CNT_TEMP_CHK)
	        {
		        system_buzzer(SYSTEM_OPER);
				memset(msg, 0, CHAR_128);
				sprintf(msg, "[APP_MICOM] High Temp Detected Time Out (%d'C)", temp);
				app_log_write(MSG_LOG_SHUTDOWN, msg);

				app_rec_stop();
				app_file_stop();
				ubx_change_setting();
								
				dprintf("== HIGH TEMPERATURE DETECTED == (%d'C)\n", temp);
                
				OSA_waitMsecs(300);
				mic_exit_state(OFF_HITEMP, START_TEMERATURE);
				app_micom_exit();
				
				return 1;
	        }
			#endif
	    }
	    else
	    {
	        temp_cnt = 0;
	    }
	}

	return 0;
}

/*----------------------------------------------------------------------------
 check acc state
-----------------------------------------------------------------------------*/
static int pre_acc_val=100, acc_cnt=0;
static int dev_check_acc(int acc)
{
	if(acc_evt_on && app_set->sys.motion_only == OFF)
	{
		char msg[CHAR_128];
		memset(msg, 0, CHAR_128);

		if(pre_acc_val == 100){
			pre_acc_val = acc;
        }

		if(pre_acc_val == acc)
		{
			acc_cnt++;
			if(acc_cnt >= CNT_MODE_CHANGE)
			{
				acc_evt_on 	= 0;
				acc_cnt 	= 0;
				if(acc == ACC_ON){
					sprintf(msg, "[APP_MICOM] ACC On Detected!!");
					app_log_write(MSG_LOG_WRITE, msg);

   					ctrl_mode_change(MODE_DRIVING);
                    app_cfg->state.acc =0;
				}
				else if(acc == ACC_OFF)
				{
					sprintf(msg, "[APP_MICOM] ACC Off Detected!!");
					app_log_write(MSG_LOG_WRITE, msg);

				 	//# Not Use Parking mode on HTRV....System Shutdown!!
					system_buzzer(SYSTEM_OPER);
					app_log_write(MSG_LOG_SHUTDOWN, " >>>> ACC Off Detected!! System Shutdown!! <<<<");

					app_rec_stop();
					app_file_stop();
				 	ubx_change_setting();
                    event_send(app_cfg->uObj, UBX_GUI_LOGO, 0, 0);

					OSA_waitMsecs(300);
					mic_exit_state(OFF_NORMAL, 0);
					app_micom_exit(); 
				}
			}
		}
	}

	return 0;
}

/*----------------------------------------------------------------------------
 micom config
-----------------------------------------------------------------------------*/
static int mic_cfg_init(void)
{
	micom_cfg_t cfg;

	//# set config micom
	cfg.t_acc_chk = TIME_ACC_CHK;
	cfg.t_psw_chk = TIME_PWRSW_CHK;

	mic_set_config(&cfg);

	return 0;
}

/*****************************************************************************
 * @brief    micom message main function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
void *micom_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;
	mic_msg_t msg;
	int ret, exit=0;
    int state=0;
	char log[CHAR_128];
	
	printf(" [task] %s start...\n", __func__);
	tObj->done = 0;

	mic_cfg_init();

    adc_first = 1;
    temp_first = 1;

	mic_data_send(1, MIC_CYCLE_TIME);

	while(!exit)
	{
		app_cfg->wd_flags |= WD_MICOM;

		ret = mic_recv_msg((char*)&msg, sizeof(mic_msg_t));
		if(ret < 0) {
			continue;
		}

		switch(msg.cmd)
		{
			case CMD_DEV_VAL:
			{
				dev_val_t *val = (dev_val_t *)msg.data;

				#if 0
				dprintf("[%3d] mpwr: %d.%d V, spwr:%d.%d V, temp: %d.%d V, acc %s\n", msg.param,
					(val->mvolt/100), (val->mvolt%100), (val->svolt/100), (val->svolt%100),
					(val->temp/10), (val->temp%10),
					val->acc?"ON":"OFF" );
				#endif

				//# Voltage compensation ...
				float dv1, dv2;
				if(val->mvolt > 0){
					//# 1. cable-drop voltage 
                    if(app_cfg->state.park){
                        if(app_cfg->num_ch == 2 && app_cfg->state.wifi == 1)
                            state = COMPEN_MODE_2;
                        else if(app_cfg->num_ch == 1 && app_cfg->state.wifi == 0)
                            state = COMPEN_MODE_3;
                        else if(app_cfg->num_ch == 2 || app_cfg->state.wifi == 1)
                            state = COMPEN_MODE_1;
                        
                        val->mvolt += (int)((cable_drop_val_P[state]/(float)(val->mvolt/100.))*100);

                        dv1 = diode_val02*(float)(val->mvolt/100.);
    					dv2 = ((abs(60 - (val->temp/10)))*0.002) + (((val->temp/10) - 60)*0.0015);
    					val->mvolt += (int)((0.42-dv1+dv2)*100);
                        if(val->temp <= 150)
                            val->mvolt = val->mvolt - 5;
                    }
                    else{

                        if(app_cfg->num_ch == 2 && app_cfg->state.wifi == 1)
                            state = COMPEN_MODE_2;
                        else if(app_cfg->num_ch == 1 && app_cfg->state.wifi == 0)
                            state = COMPEN_MODE_3;
                        else if(app_cfg->num_ch == 2 || app_cfg->state.wifi == 1)
                            state = COMPEN_MODE_1;

    					val->mvolt += (int)((cable_drop_val_D[state]/(float)(val->mvolt/100.))*100);

                        dv1 = diode_val02*(float)(val->mvolt/100.);
    					dv2 = ((abs(60 - (val->temp/10)))*0.002) + (((val->temp/10) - 60)*0.0015);
    					val->mvolt += (int)((0.45-dv1+dv2)*100);
                        if(val->temp <= 150)
                            val->mvolt = val->mvolt - 5;
                    }
				}

				imicom->val.mvolt = val->mvolt;	//# XX.xx V format
				imicom->val.svolt = val->svolt;	//# XX.xx V format
				imicom->val.temp  = val->temp/10;	//# (+/-) XXX.x 'C format -> XXX format
				imicom->val.acc   = val->acc;

				//# --- check volt ---------------
				exit = dev_check_volt(imicom->val.mvolt);
				if(exit) {
					break;
				}

				//# --- check temp ----------------
				exit = dev_check_temp(imicom->val.temp);
				if(exit) {
					break;
				}

				//# --- check acc -----------------
				exit = dev_check_acc(imicom->val.acc);
                if(exit){
                    break;
                }

				break;
			}
			case CMD_ACC_EVT: //parking mode
			{
				if(!imicom->low_pwr_detect){
					printf("\n-----------------------------------------------\n");
					printf("ACC change detect %s\n", msg.data[0]?"ON":"OFF");

					acc_cnt		= 0;
					acc_evt_on 	= 1;
					pre_acc_val = msg.data[0];
					app_cfg->state.acc = 1;
//	                if(app_cfg->state.sub){
//	                    app_cfg->state.park = pre_acc_val;
//	                }
				}
				break;
			}
			case CMD_PSW_EVT:
			{
				if(!imicom->low_pwr_detect){
	                sprintf(log, "[APP_MICOM] --- Power Switch Press ---");
					app_log_write( MSG_LOG_WRITE, log );
					
					event_send(app_cfg->uObj, UBX_GUI_LOGO, 0, 0);
					dev_system_stop();

					dprintf("power switch press\n");
					mic_exit_state(OFF_NORMAL, 0);
					exit = 1;
				}
				break;
			}
			case CMD_RSW_EVT:
			{
				if(!imicom->low_pwr_detect){
	                printf(" [app] --- detect reset switch press ---\n\n");
					event_send(app_cfg->uObj, UBX_GUI_LOGO, 0, 0);
                    
					dev_system_stop();

					dprintf("reset switch press\n");
					mic_exit_state(OFF_RESET, 0);
					exit = 1;
				}
				break;
			}
			case CMD_DAT_STOP:		//# response data send stop
			{
				exit = 1;
				break;
			}
			case CMD_NONE:
			{
				continue;
			}
		}
	}

	tObj->done = 1;
	printf(" [task] %s stop...\n", __func__);

	return NULL;
}

/*****************************************************************************
* @brief    micom init/exit function
* @section  DESC Description
*   - desc
*****************************************************************************/
int app_micom_init(void)
{
	int ret;
	short mic_ver;

	ret = mic_msg_init();
	if(ret < 0) {
		return -1;
	}

	ret = mic_send_ready();
	if(ret < 0) {
		return -1;
	}

	mic_ver = mic_get_version();
    sprintf(app_cfg->micom_ver, "%02x.%02x", (mic_ver>>8) & 0xFF, mic_ver & 0xFF);

	app_watchdog_init(1, TIME_WATCHDOG);

	return 0;
}

int app_micom_exit(void)
{
    mic_msg_exit();

    return 0;
}

