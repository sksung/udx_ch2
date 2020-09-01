/******************************************************************************
 * UCX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
/**
 * @file    tru_main.c
 * @brief	ubx car main program
 * @author  sksung
 * @section MODIFY history
 *     - 2013.09.03 : First Created
 */
/*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//# include mcfw_linux
#include "ti_vsys.h"
#include "ti_vcap.h"

#include "dev_env.h"
#include "dev_lcd.h"
#include "dev_micom.h"

#include "ucx_main.h"
#include "app_set.h"
#include "app_util.h"
#include "app_key.h"
#include "app_ctrl.h"
#include "app_gui.h"

#include "app_cap.h"
#include "app_snd.h"
#include "app_dev.h"
#include "app_rec.h"
#include "app_file.h"
#include "app_sockio.h"
#include "app_hotplug.h"

#include "app_rtsptx.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
app_set_t *app_set;
app_cfg_t *app_cfg;

/*****************************************************************************
 @brief		m3 event handler function
 @param		[IN]eventId     VSYS_EVENT_VIDEO_DETECT, VSYS_EVENT_MOTION_DETECT
 @param		[IN]*pPrm       Ptr pPrm (data pointer)
 @param		[IN]*appData
 @return
 @remark
 *****************************************************************************/
int vsys_event(unsigned int eventId, void *pPrm, void *appData)
{
	int video_detect[2];
	int i, ret;
    int layout=0;
    int num_ch_before=0; //for camera remove or detect state
	char msg[CHAR_128] = {0,};
	if(app_cfg->state.pwroff || !app_cfg->state.cap)
		return 0;

	if(eventId==VSYS_EVENT_VIDEO_DETECT)
	{
	    num_ch_before = app_cfg->num_ch;
		app_cfg->state.cam_buzzer = 0;

	    dprintf("VSYS_EVENT_VIDEO_DETECT!!\n");
		Vcap_get_video_status((Int32*)&video_detect, MAX_CH_NUM);

		for(i=0; i<MAX_CH_NUM; i++)
			printf("CH%d : %s\n", i, video_detect[i]?"video detect":"no video");

		if(video_detect[0] && video_detect[1]) {
			app_cfg->num_ch = MAX_CH_NUM;
			app_gui_layout(UBX_LAYOUT_D);
			app_cfg->layout = UBX_LAYOUT_D;
			
            for(i=0; i<MAX_CH_NUM; i++){
				ctrl_hdcam_frame_set(i, DEFAULT_FPS);
            }
			
            ctrl_hdcam_brightness(0, app_set->cam.front_bright);
            ctrl_hdcam_brightness(1, app_set->cam.rear_bright);

			ctrl_hdcam_mirror(0, app_set->front_mirror);
			ctrl_hdcam_mirror(1, app_set->lcd.sub_mirror);
		}
        else if(video_detect[0] == 0 && video_detect[1] == 0){
            app_cfg->num_ch = 0;
			app_rec_file_close();
        }
		else {
			app_cfg->num_ch = 1;
            if(video_detect[0]){
                layout = UBX_LAYOUT_M;
				ctrl_hdcam_mirror(1, app_set->front_mirror); //force change to front cam.
           	}
            else{
                layout = UBX_LAYOUT_S;
           	}

			app_gui_layout(layout);
			app_cfg->layout = layout;
		}

		//# Disconnected some camera!!
        if( num_ch_before > app_cfg->num_ch ){//|| app_cfg->num_ch == 1 ){
			app_cfg->state.cam_buzzer = 1;
        }

		app_change_file();

		sprintf( msg, " Camera Detected Count: %d", app_cfg->num_ch );
		app_log_write( MSG_LOG_WRITE, msg );
	}

	return 0;
}


/*****************************************************************************
 @brief		Thread init function
 @return
 @remark
 *****************************************************************************/
static int main_thrd_init(void)
{
    memset((void *)app_cfg, 0, sizeof(app_cfg_t));

	app_cfg->mObj = app_malloc(sizeof(app_thr_obj));
	if(app_cfg->mObj == NULL) {
		eprintf("main thread obj malloc fail\n");
		return -1;
	}
	OSA_semCreate(&app_cfg->mObj->sem, MAX_PENDING_SEM_CNT, 0);

	return 0;
}
/*****************************************************************************
 @brief		Thread exit function
 @return
 @remark
 *****************************************************************************/
static void main_thrd_exit(void)
{
	if(app_cfg->mObj != NULL) {
		OSA_semDelete(&app_cfg->mObj->sem);
		app_mfree(app_cfg->mObj);
	}
}

/*****************************************************************************
* @brief    event function
* @section  DESC Description
*   - desc
*****************************************************************************/
int event_wait(app_thr_obj *tObj)
{
	if(tObj == NULL)
		return -1;

	OSA_semWait(&tObj->sem, OSA_TIMEOUT_FOREVER);

	return tObj->cmd;
}

void event_send(app_thr_obj *tObj, int cmd, int param0, int param1)
{
	if(tObj == NULL)
		return;

	tObj->cmd = cmd;
	tObj->param0 = param0;
	tObj->param1 = param1;
	OSA_semSignal(&tObj->sem);
}


/*****************************************************************************
* @brief    app main function
* @section  DESC Description
*   - desc
*****************************************************************************/
static void app_main(void)
{
	printf(" [task] %s start\n", __func__);

	//# register event
	Vsys_registerEventHandler(vsys_event, NULL);

	app_capt_main();

	printf(" [task] %s stop\n", __func__);
}

/*****************************************************************************
* @brief    Default setting function
* @section  DESC Description
*   - desc
*****************************************************************************/
static void tvo_flag_input()
{
    app_cfg->tvo_flag |= TVO_REC;
    app_cfg->tvo_flag |= TVO_TEMP;
    app_cfg->tvo_flag |= TVO_VOLT;
    app_cfg->tvo_flag |= TVO_GSENSOR;
    app_cfg->tvo_flag |= TVO_MOTION;
    app_cfg->tvo_flag |= TVO_MIC;
    app_cfg->tvo_flag |= TVO_BUZZER;
    app_cfg->tvo_flag |= TVO_VERSION;
}
static void ubx_init_config(int argc, char **argv)
{
	//memset((void *)app_cfg, 0, sizeof(app_cfg_t));

	//# default setting
	app_cfg->en_enc		= 1;
	app_cfg->en_jpg		= 1;
	app_cfg->en_rec 	= 1;
	app_cfg->en_dis		= 1;

	app_cfg->num_ch 	= 2;

	//# read config file
	app_cfg->state.mmc = ctrl_mmc_state();
	app_cfg->state.secu_on = !app_cfg->state.mmc;

	ubx_open_setting();
	app_set_cfg_params();

	//# check i/o device
	app_cfg->state.tvo = 1; 	//# default on

    tvo_flag_input();
}
#ifdef TIME_DEBUG
void time_debug_clock(char *func, int type)
{
    char str[60];
    time_t the_time;
    struct tm date;
    time(&the_time);
    localtime_r(&the_time, &date);
    sprintf(str," %04d/%02d/%02d %02d:%02d:%02d ",
        date.tm_year + 1900,
        date.tm_mon  + 1,
        date.tm_mday,
        date.tm_hour,
        date.tm_min,
        date.tm_sec);

    printf("====TIME DEBUG func = %s, turn = %d time = %s =====\n", func, type, str);
}
#endif

/*****************************************************************************
* @brief    main function
* @section  DESC Description
*   - desc
*****************************************************************************/
int main(int argc, char **argv)
{
	int ret=0;
	int sd_res = 0;
    int exfat_done=0;
	char msg[255]={0,};
    unsigned long part_size;

	printf("\n--- UBX CAR start ---\n");

	app_cfg = app_malloc(sizeof(app_cfg_t));
	if(app_cfg == NULL)
		return -1;

	//#--- System init
	mcfw_linux_init(0);

	//#--- app thread start
	ret = main_thrd_init();		//# use only communication
	if(ret < 0) {
		mcfw_linux_exit();
		return -1;
	}

	app_dev_gpio_init();
	dev_led_default();

	//# micom init
	app_micom_init();

	//# check sd over 32GB (64 ~ 128 GB)
	part_size = 0;
	ret = ctrl_mmc_check_exfat(&part_size);
	if (ret > 0) {
		printf("founded exFAT SD card!!!\n");
		app_watchdog_keep_alive();
		exfat_done = ctrl_exfat_format(part_size);
		if(exfat_done != 0){
            app_cfg->state.sd_buzzer =1;
        }
        printf("\n exfat_done = %d \n", exfat_done);
        app_watchdog_keep_alive();
	} else if (ret < 0) {
		printf(" Not supported SD card(wrong size or partition !!!\n");
        app_cfg->state.mmc_err = 1;
        app_cfg->state.sd_buzzer = 1;
	}

	//# check logical error of sd card
	if (!ctrl_mmc_check_partitions()) {
		/* umount mmcblk0 */
		system("/bin/umount /mmc");
		ret = ctrl_mmc_check_fsck();
		if (ret)
		{
//			printf("mmc detected recoverable errors(ret %d)!\n", ret);
			ctrl_mmc_run_fsck(); //# auto repair..
			if (ctrl_mmc_check_fsck() == 0) {
//				printf("mmc errors repaired!\n");
				sd_res = 0;
			} else {
				printf("!!! Warning: the mmc is damaged. couldn't repaired !!!\n");
				sd_res |= ERR_MMC_HAVE_ERRORS;
			}
		}
		system("/bin/mount -t vfat /dev/mmcblk0p1 /mmc");
		//# To remove recovery file!! FSCK****.REC
		system("/bin/rm -rf /mmc/*.REC");
	} else {
		sd_res |= ERR_MMC_HAVE_MULTI_PART;
		printf("!!! Logical error check : Multi partition !!!\n");
	}

    //# check sd card inserted
    app_cfg->state.mmc = ctrl_mmc_state();
    app_cfg->state.secu_on = !app_cfg->state.mmc;

    if((sd_res && app_cfg->state.mmc) || (!app_cfg->state.mmc)){
        printf("state.mmc_err = 1 \n");
        app_cfg->state.mmc_err = 1;
        app_cfg->state.sd_buzzer = 1;
    }

	app_ctrl_out_copy();


    init_g_mem();
	if(app_rtsptx_start() ==0)
	    app_cfg->state.rtsptx = 1;

	//# start log system
	app_log_start();

	sprintf(msg, ">>>>> %s_SYSTEM STARTED!! <<<<<", TCX_MODEL);
	app_log_write(MSG_LOG_WRITE, msg);

	sprintf(msg, "SW_Ver: %s, MICOM_Ver: %s",TCX_SW_VER, app_cfg->micom_ver);
	app_log_write(MSG_LOG_WRITE, msg);

	printf("\n\n=======================================\n");
	printf("=         %s SYSTEM START       =\n", TCX_MODEL);
	printf( "%s\n",msg );
	printf("=======================================\n\n");

	app_gui_start();

	//# read config file
	ubx_init_config(argc, argv);

	app_log_write( MSG_LOG_WRITE, "[UCX_MAIN] Setting param load done....");

	app_file_start();
    app_snd_init();
	app_dev_start();
	app_key_start(); //# rec-key detect
	app_hotplug_start(); //# mmc/tvout event.

    if(dev_fw_printenv("nand_update")==2){	//# done firmware updated.
    	app_log_write( MSG_LOG_WRITE, "[APP_UCX] Firmware update done....");
        check_nand_update();
        dev_fw_setenv("nand_update", "0", 0);
    }
    else{
        if(check_fw() != SOK){
            check_nand_update();
        }
        else{
            ui_draw_logo(DISP_FWUPDATE);
            OSA_waitMsecs(200);
        }
    }

    CSock_start();

    //app_set->aud.mic_on = ON;
    //printf("\n mic = %s \n", app_set->aud.mic_on?"on":"off");
    app_aud_capt_ctrl(app_set->aud.mic_on);

	//#--- main --------------
	app_main();
	//#-----------------------

	app_log_write( MSG_LOG_WRITE, "[APP_UCX] app_main() EXIT...." );

	//#--- app thread stop
	if(app_cfg->state.rtsptx){
		app_rtsptx_stop();
		app_cfg->state.rtsptx = 0;
	}

    CSock_stop();
    app_log_stop();
    //# micom exit - will power off after 500mS
	app_micom_exit();

    exit_g_mem();

	app_key_stop();
	app_gui_stop();
	app_dev_stop();
    app_snd_exit();
	app_file_stop();

	app_hotplug_stop();
	app_dev_gpio_exit();

	main_thrd_exit();

	//#--- system de-init
	mcfw_linux_exit();

	//# micom exit - will power off after 500mS
	//app_micom_exit();

	app_mfree(app_cfg);
	app_cfg = NULL;

	printf("--- UBX CAR end ---\n\n");

	return 0;
}

