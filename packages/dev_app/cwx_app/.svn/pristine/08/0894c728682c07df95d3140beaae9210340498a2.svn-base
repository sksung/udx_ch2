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

#define MIC_CYCLE_TIME		 100	//# msec, voltage, temp, acc
#define VOLT_CYCLE_TIME      100
#define TIME_PEEK_VOLT_CHK	 400//1000	//# peek low voltage check time
#define TIME_PWRSW_CHK		 800	//# msec, power switch press time
#define TIME_ACC_CHK		 500    //3000	//# acc check time
#define TIME_CHANGE_MODE	10000	//# change park mode after acc check
#define TIME_VOLT_SKIP		60000	//# protection time until the power off after start

#define TIME_TEMP_CHK		60000	//# high temperature check time
#define VAL_TEMP_LOW		80		//# 'C, temperature of system power on
#define TEMP_CHK_CNT        3		//# DEV_CYCLE_TIME * cnt

#define CNT_PEEK_VOLT_CHK	(TIME_PEEK_VOLT_CHK/VOLT_CYCLE_TIME) //# 1sec
#define CNT_VOLT_SKIP		(TIME_VOLT_SKIP/VOLT_CYCLE_TIME)     //# 60sec

#define CNT_MODE_CHANGE		(TIME_CHANGE_MODE/MIC_CYCLE_TIME)   //# 10sec
#define CNT_TEMP_CHK		(TIME_TEMP_CHK/MIC_CYCLE_TIME)      //# 60sec


//static int peek_low_volt[VOLT_LEVEL_MAX] = {VOLT_12V_LOW, VOLT_24V_LOW};
static int acc_evt_on=1;
static int adc_first=0;   //# adc first time flag
static int temp_first=0;

static int min_svolt_val[REC_STOR_MAX] = {420, 360};
static float cable_drop_val_D[COMPEN_MODE_MAX] 	= {3.6, 4.5, 2.5};
static float cable_drop_val_P[COMPEN_MODE_MAX]  = {2.7, 3.6, 1.8};
static float diode_val01 				= 0.32;
static float diode_val02				= 0.002;

static float temp_comp_val				= 0.0014;

//# Writer sopt 3sec delay...
#define MAX_TIME_GAP		3000	//3sec
//#define MIN_VOLT_VAL		360//420		//4.2V

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
static int volt_level_chk = 1, volt_skip_cnt=0, volt_peek_cnt=0;
static int dev_check_volt(int volt)
{
	int volt_low;
	struct timeval t1, t2;
	
	char msg[CHAR_128];
	memset(msg, 0, CHAR_128);

	if(volt_level_chk) {		//# check input voltage level (12V or 24V)
		if(volt >= VOLT_24V_MIN)
			app_cfg->volt_level = VOLT_LEVEL_24V;
		else
			app_cfg->volt_level = VOLT_LEVEL_12V;
		volt_level_chk = 0;
	}

	//#--- peek low voltage ---//
	if(volt < VOLT_LOW)
	{
		volt_peek_cnt++;
        if(volt_peek_cnt >= CNT_PEEK_VOLT_CHK && imicom->low_pwr_detect == 0)
        {
	        app_cfg->state.pwroff = 1;
            imicom->low_pwr_detect = 1;
			volt_peek_cnt = 0;

			sprintf(msg, "<<<< Peek Low Voltage Detected(%d.%dV) >>>>", (volt/100), (volt%100));
			app_log_write(MSG_LOG_SHUTDOWN, msg);

            ctrl_tvo_enable(OFF);
            ctrl_hdcam_pwroff();

			gettimeofday(&t1, NULL);

			app_rec_stop();

			gettimeofday(&t2, NULL);
        	printf(" [app] Record stop msec[%ld], SYS_LOW-PEEK Volt(%d.%dV)\n",
        	((t2.tv_sec*1000)+(t2.tv_usec/1000))-((t1.tv_sec*1000)+(t1.tv_usec/1000)), (volt/100), (volt%100));			
			
//            app_capt_stop();
//            ctrl_tvo_enable(OFF);
//            ctrl_hdcam_pwroff();

            if(app_cfg->volt_level == VOLT_LEVEL_12V)
    		    mic_exit_state(OFF_LOWPWR, START_VOLTAGE_09V);
            else if(app_cfg->volt_level == VOLT_LEVEL_24V)
                mic_exit_state(OFF_LOWPWR, START_VOLTAGE_09V);      

            mic_send_msg(CMD_BUZZER, 2, BUZZER_100);

			printf(" [app] >>>>>>>> EXIT Peek Low Volt(%d.%dV) <<<<<<< \n", (imicom->val.svolt/100), (imicom->val.svolt%100) );
			delay_3sec_exit();

    	    return 1;
        }
	}
    else{
        volt_peek_cnt = 0;
    }


    if(imicom->low_pwr_detect)
        app_cfg->wd_flags |= WD_ENC;


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

        //high temp detect
	    if(temp >= app_cfg->temp_high)
	    {
	        temp_cnt++;

	        if(temp_cnt > CNT_TEMP_CHK)
	        {
	        	temp_cnt = 0;
				memset(msg, 0, CHAR_128);
				sprintf(msg, "[APP_MICOM] High Temp Detected Time Out (%d'C)", temp);
				app_log_write(MSG_LOG_SHUTDOWN, msg);

				app_rec_stop();
				app_file_stop();
				ubx_write_setting(0);
				mic_exit_state(OFF_HITEMP, START_TEMERATURE);

				printf("== HIGH TEMPERATURE DETECTED == (%d'C)\n", temp);
                delay_3sec_exit();

				return 1;
	        }
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
	if(acc_evt_on && !app_cfg->state.sub)
	{
		char msg[CHAR_128];
		memset(msg, 0, CHAR_128);

		if(imicom->low_pwr_detect)
			return 0;

		if(pre_acc_val == 100){
			pre_acc_val = acc;
        }

		if(pre_acc_val == acc)
		{
			acc_cnt++;
//			if(acc_cnt >= CNT_MODE_CHANGE)
			{
				acc_evt_on 	= 0;
				acc_cnt 	= 0;
				if(acc == ACC_OFF){
					sprintf(msg, "[APP_MICOM] ACC Off Detected!!");
					app_log_write(MSG_LOG_SHUTDOWN, msg);

					app_rec_stop();
					app_file_stop();
					ubx_write_setting(0);
					
					mic_exit_state(OFF_LOWPWR, START_VOLTAGE_09V);
					mic_send_msg(CMD_BUZZER, 2, BUZZER_100);

					printf("%s\n", msg);
	                delay_3sec_exit();					
				}				
#if 0				
				if(acc == ACC_ON){
					sprintf(msg, "[APP_MICOM] ACC On Detected!!");
					app_log_write(MSG_LOG_WRITE, msg);

   					ctrl_mode_change(MODE_DRIVING);
                    app_cfg->state.acc =0;
				}
				else if(acc == ACC_OFF){
					sprintf(msg, "[APP_MICOM] ACC Off Detected!!");
					app_log_write(MSG_LOG_WRITE, msg);

					app_cfg->state.acc = 1;
					ctrl_mode_change(MODE_PARKING);
                    app_cfg->state.acc = 0;
                    if(app_cfg->state.popup)
                        app_cfg->state.popup = 0;
				}
#endif				
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
void *volt_check_main(void *prm)
{
	int i, cmd, exit = 0;

	app_thr_obj *tObj = (app_thr_obj *)prm;

	printf(" [task] %s start...\n", __func__);

	tObj->done = 0;
	while (!exit)
	{
		cmd = tObj->cmd;
		if ((cmd == UBX_CMD_STOP) || app_cfg->state.pwroff) {
			break;
		}
		
		if(imicom->micom_done != 1){
			OSA_waitMsecs(VOLT_CYCLE_TIME);
			continue;
		}

        if(imicom->val.mvolt > 0){
            //# --- check volt ---------------
    		exit = dev_check_volt(imicom->val.mvolt);
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
	

		OSA_waitMsecs(VOLT_CYCLE_TIME);
	}

	tObj->done = 1;
	printf(" [task] %s stop!\n", __func__);

	return NULL;
}

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

				if(imicom->micom_done == 0)
					imicom->micom_done = 1;
				
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
				}
				break;
			}
			case CMD_PSW_EVT:
			{
				if(!imicom->low_pwr_detect){
	                sprintf(log, "[APP_MICOM] --- Power Switch Press ---");
					app_log_write( MSG_LOG_SHUTDOWN, log );

					app_rec_stop();
					ubx_write_setting(0);

					event_send(app_cfg->uObj, UBX_GUI_LOGO, 0, 0);
					mic_exit_state(OFF_NORMAL, 0);
					mic_send_msg(CMD_BUZZER, 2, BUZZER_100);

					printf("%s\n", log);
					delay_3sec_exit();

					exit = 1;
				}
				break;
			}
			case CMD_RSW_EVT:
			{
				if(!imicom->low_pwr_detect)
				{
					sprintf(log, "[APP_MICOM] --- Reset Switch Press ---");
					app_log_write( MSG_LOG_SHUTDOWN, log );
	                printf("%s\n\n", log);
					
					app_rec_stop();
					ubx_write_setting(0);
					
					event_send(app_cfg->uObj, UBX_GUI_LOGO, 0, 0);
					mic_exit_state(OFF_RESET, 0);

					printf(" [app] >>>>>>>> SYSTEM Reset!! <<<<<<< \n");
					delay_3sec_exit();
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

void delay_3sec_exit()
{
	struct timeval t1, t2;
	int tgap=0;
	int min_svolt = min_svolt_val[0];
	int root_idx = 0;
	OSA_mutexLock(&imicom->mutex_3delay);

	root_idx = get_root_idx();
	if(root_idx != EFAIL)
		min_svolt = min_svolt_val[root_idx];

	gettimeofday(&t1, NULL);
	if(app_cfg->state.hdd || app_cfg->state.mmc)
	{
        while(tgap < MAX_TIME_GAP && imicom->val.svolt > min_svolt){
			gettimeofday(&t2, NULL);
			tgap = ((t2.tv_sec*1000)+(t2.tv_usec/1000))-((t1.tv_sec*1000)+(t1.tv_usec/1000));
			OSA_waitMsecs(1);
        }
	}
	gettimeofday(&t2, NULL);

	printf(" [app] msec[%ld] >>>>>>>> DELAY EXIT  <<<<<<< \n",
	((t2.tv_sec*1000)+(t2.tv_usec/1000))-((t1.tv_sec*1000)+(t1.tv_usec/1000)));

	OSA_mutexUnlock(&imicom->mutex_3delay);

	app_micom_exit();

}



