/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_gfx.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.04.01 : First Created
 *     - 2013.08.22 : Modified by sksung
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include "linux/ti81xxfb.h"

#include "dev_common.h"
#include "dev_micom.h"
#include "draw_gui.h"
#include "ucx_db_img.h"
#include "font_db.h"
#include "draw_text.h"

#include "ucx_main.h"
#include "app_set.h"
#include "app_gui.h"
#include "app_util.h"
#include "app_ctrl.h"
#include "app_cap.h"
#include "app_dev.h"
#include "app_snd.h"
#include "dev_gfx.h"
#include "app_hotplug.h"
#include "app_log.h"
#include "app_micom_main.h"
#include "app_rec.h"
#include "app_file.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define	FBDEV1_NAME		"/dev/fb1"
#define	FBDEV2_NAME		"/dev/fb2"

#define UI_CYCLE_TIME		500	//# ms
#define UI_WATCHDOG_TIME	(UI_CYCLE_TIME*3)

#define WD_LOG_TIMEOUT	((TIME_WATCHDOG-10)*1000) //watcho dog log wrtite time out (ms)
#define WD_LOG_CNT		(WD_LOG_TIMEOUT / UI_WATCHDOG_TIME)

#define SYS_ERR_TIME	( 60*1000 )	//# 1MIN (ms)
#define SYS_ERR_CNT		( SYS_ERR_TIME / UI_CYCLE_TIME )

#define BUZZER_TIME     (5*1000) //5sec(ms)
#define BUZZER_CNT      (BUZZER_TIME/UI_CYCLE_TIME)


/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
app_gui_t *igui;
#ifdef DEBUG_GSV
static GPS_SENSITIVITY gps_sens;
#endif
/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*****************************************************************************
 @brief		All UI to disappear(clear display)
 @param		[IN]dest  1: DISP_TVO(TV out), 2: DISP_LCD(LCD out)
 @remark
 *****************************************************************************/
void ui_draw_clear(int dest)
{
	app_gfx_t *gfx = &igui->gfx_obj;

	if(dest == DISP_TVO) {
		draw_fill_color(gfx->tvo.buf, RGB_KEY);
	}
}

/*****************************************************************************
 @brief		Show logo on the display
 @param		[IN]dest  1: DISP_TVO(TV out), 2: DISP_LCD(LCD out)
 @remark    to do
 *****************************************************************************/
void ui_draw_logo(int dest)
{
	app_gfx_t *gfx = &igui->gfx_obj;
	img_info_t *iimg;
	ui_pos_t st;

	if(dest == DISP_TVO)
	{
		iimg = get_img_db(IMG_UDLOGO_TV);
		st.x=0; st.y=0; st.w=iimg->w; st.h=iimg->h;
		draw_img(gfx->tvo.buf, (Upix *)iimg->p, st);
	}
    else if(dest == DISP_FWUPDATE){
        iimg = get_img_db(IMG_FW_UPDATE);
		st.x=0; st.y=0; st.w=iimg->w; st.h=iimg->h;
		draw_img(gfx->tvo.buf, (Upix *)iimg->p, st);
    }
    else if(dest == DISP_FWDONE){
        iimg = get_img_db(IMG_FW_DONE);
		st.x=0; st.y=0; st.w=iimg->w; st.h=iimg->h;
		draw_img(gfx->tvo.buf, (Upix *)iimg->p, st);
    }
}

/*****************************************************************************
 @brief		Get the current time and draw time in LCD
 @remark
 *****************************************************************************/
static void ui_draw_time(void)
{
	time_t now;
	struct tm ts;
	char buf_date[64], buf_time[64];

	//# get current date & time
	now = time(NULL);
//	ts = localtime(&now);
	localtime_r((const time_t *)&now, &ts);

    strftime(buf_date, sizeof(buf_date), "%Y/%2m/%2d", &ts);
	strftime(buf_time, sizeof(buf_time), "%2H:%2M:%2S", &ts);
	//ui_draw_time_lcd(buf_date, buf_time);
}

/*----------------------------------------------------------------------------
 draw run time function
-----------------------------------------------------------------------------*/
static void ui_draw_disk_info(int draw)
{
#if 0
	disk_info_t idisk;
	int disk_use=0;

	if(draw)
	{
		//# check disk size
		util_disk_info(&idisk, DIR_DISK);
		#if 1	//# for debug
		disk_use = (idisk.used*100)/idisk.total;
		if(disk_use != igui->disk_use) {
			igui->disk_use = disk_use;
			ui_draw_disk_lcd(disk_use, draw);
		}
		#endif
		util_check_dir(idisk.total);
	}
	else {
		ui_draw_disk_lcd(disk_use, draw);
	}
#endif
}

/*****************************************************************************
 @brief		Layout change
 @param		[IN]layout  app_layout_e
 @remark    Layout change acording to app_layout_e
 *****************************************************************************/
void app_gui_layout(int layout)
{
	/*if(app_cfg->num_ch == 1) {
		ctrl_swMs_set(1, 0, 0);
		return;
	}*/

	if(layout==UBX_LAYOUT_M) {
		ctrl_swMs_set(1, 0, 0);
	}
	else if(layout==UBX_LAYOUT_S) {
		ctrl_swMs_set(1, 1, 0);
	}
	else if(layout==UBX_LAYOUT_D) {
        //ctrl_swMs_set(2, 1, 1);
		if(app_cfg->layout_swap)
			ctrl_swMs_set(2, 1, 1);
		else
			ctrl_swMs_set(2, 0, 0);
	}
}

/*****************************************************************************
 @brief		Large layout swap when M1+S1(UBX_LAYOUT_D) layout
 @remark
 *****************************************************************************/
void app_gui_layout_swap(void)
{

	if(app_cfg->layout == UBX_LAYOUT_D)
	{
		app_cfg->layout_swap = 1 - app_cfg->layout_swap;
		app_gui_layout(app_cfg->layout);
	}
}

static int cnt;
static int system_down;

static int critical_buzzer()
{
    if(app_cfg->state.sd_buzzer || app_cfg->state.cam_buzzer)
	{
        cnt++;

		//# not format duration or cam all disconnect
        if( app_cfg->state.sd_buzzer && app_cfg->state.fdur == 0 )
			system_down++;
		else if( app_cfg->state.cam_buzzer && app_cfg->num_ch == 0 ) 
            system_down++;
		
        if(cnt%BUZZER_CNT == 0) //every 5sec alarm(gui UI_CYCLE_TIME -> 500ms)
		{ 
            if(system_down > SYS_ERR_CNT) // 1minute timer
			{ 
	            app_log_write( MSG_LOG_SHUTDOWN, " >>>> SD or Camera buzzer shutdown!! " );
				app_rec_stop();
				app_file_stop();
			 	ubx_write_setting();
				
                OSA_waitMsecs(200);
    		    mic_exit_state(OFF_NORMAL, 0);
				app_micom_exit();
            }
            else{
                if(app_set->aud.snd_on)
                    mic_send_msg(CMD_BUZZER, 1, BUZZER_1000);
            }
       	}        
        
        if(cnt%2 == 0)
            rec_led_run(ON);
        else
            rec_led_run(OFF);
            
    }
    else{
        cnt = 0;
        system_down = 0;
        rec_state_led();
    }

    return 0;
}


/*****************************************************************************
* @brief    gui main function
* @section  DESC Description
*   - desc
*****************************************************************************/
static void *gui_tvo_init(void)
{
	int buf;

	dev_gfx_init(GFX2, &buf, 720, 480);

	return (void *)buf;
}

static void gui_tvo_exit(void)
{
	dev_gfx_exit(GFX2);
}

static void get_wd_name(char* name)
{
	if( !(app_cfg->wd_flags & WD_ENC ) )
		strcat(name, WD_ENC_NAME);
	if( !(app_cfg->wd_flags & WD_TMR ) )
		strcat(name, WD_TMR_NAME);	
	if( !(app_cfg->wd_flags & WD_DEV ) )
		strcat(name, WD_DEV_NAME);
	if( !(app_cfg->wd_flags & WD_FILE ) )
		strcat(name, WD_FILE_NAME);
	if( !(app_cfg->wd_flags & WD_MICOM ) )
		strcat(name, WD_MICOM_NAME);
}


static void *gui_main(void *prm)
{
	app_thr_obj *tObj = (app_thr_obj *)prm;


	int cmd, exit=0, led_ste=0;
	int mcnt0, mcnt1;
	int wd_cycle = 0, wd_detect=0, msg_dsp=0;
	char wd_name[CHAR_64], msg[CHAR_128];
	
	printf(" [task] %s start\n", __func__);
	tObj->done = 0;

    ui_draw_logo(DISP_TVO);

	mcnt0 = 0; mcnt1 = 0;

	while(!exit)
	{
		//# wait cmd
		cmd = tObj->cmd;
		if(cmd == UBX_CMD_STOP) {
			break;
		}

		switch(cmd)
		{
			case UBX_GUI_CAPT:		//# start draw
			{
                app_cfg->set_state = SETTING_NONE;
				OSA_waitMsecs(500);	//# protect garbage video data
				ui_draw_clear(DISP_TVO);

				app_cfg->state.ui_cap 	= 1;

				//# volt, temp write to log.
				sprintf(msg, " DEV Start done... Volt: %2.1fV, Temp: %d'C ",
					((float)app_dev_get_volt_val() / 100.), app_dev_get_temp_val());
				app_log_write(MSG_LOG_WRITE, msg);
					
				break;
        	}
			case UBX_GUI_LOGO:
			{
				app_cfg->state.ui_cap = 0;
                ui_draw_logo(DISP_TVO);

				break;
			}
			case UBX_GUI_MTIME0:
			{
				break;
			}
			case UBX_GUI_MOTION:
			{
				break;
			}
		}

        ui_draw_txt_tvo();
//        critical_buzzer();

        #ifdef DEBUG_GSV
        if(app_cfg->state.ui_cap)
            ui_draw_gsv();
        #endif

		//# watchdog
		if((wd_cycle != 0) && (wd_cycle%UI_WATCHDOG_TIME == 0))
		{
		    if(app_cfg->num_ch == 0)
                app_cfg->wd_flags |= WD_ENC;
            
			if(app_cfg->wd_flags == WD_TOT || app_cfg->wd_flags >= WD_FSCAN){
				app_watchdog_keep_alive();
				app_cfg->wd_flags = 0;
				wd_detect = 0;
				if(msg_dsp){
					msg_dsp = 0;
					app_log_write(MSG_LOG_WRITE, "WATCHDOG DETECTE FREE !!!");
				}
			}
			else {
				wd_detect++;
				memset( wd_name, 0, sizeof(wd_name) );
				get_wd_name( wd_name );
				sprintf(msg, " !!! WATCHDOG DETECTED flag[%x]: %s !!!", app_cfg->wd_flags, wd_name);
				printf("%s\n", msg);
				if(msg_dsp==0){
					app_log_write(MSG_LOG_WRITE, msg);
					msg_dsp = 1;
				}
				if( wd_detect == WD_LOG_CNT )
					app_log_write( MSG_LOG_SHUTDOWN, msg );
			}
		}

		if( app_cfg->wd_flags >= WD_FSCAN ) {
			pwr_led_run(led_ste);
			led_ste = !led_ste;
		}

		tObj->cmd = 0;
		wd_cycle += UI_CYCLE_TIME;
		OSA_waitMsecs(UI_CYCLE_TIME);
	}

	gui_tvo_exit();

	tObj->done = 1;
	printf(" [task] %s stop\n", __func__);

	return NULL;
}

/*****************************************************************************
* @brief    gui thread start/stop function
* @section  DESC Description
*   - desc
*****************************************************************************/
void app_gui_start(void)
{
	app_thr_obj *tObj;

	igui = app_malloc(sizeof(app_gui_t));
	if(igui == NULL) {
		eprintf("control obj malloc fail\n");
		return;
	}

	//# graphic buffer init
	igui->gfx_obj.tvo.buf = gui_tvo_init();

	//# create gui thread
	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj == NULL) {
		eprintf("thread obj malloc fail\n");
		return;
	}
	OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
	OSA_thrCreate(&tObj->thr, gui_main, FXN_TSK_PRI-1, 0, tObj);
	app_cfg->uObj = tObj;		//# resgister thread obj

	//# create ani thread
	tObj = app_malloc(sizeof(app_thr_obj));
	if(tObj == NULL) {
		eprintf("thread obj malloc fail\n");
		return;
	}
	OSA_semCreate(&tObj->sem, MAX_PENDING_SEM_CNT, 0);
	tObj->done = 1;
	app_cfg->iObj = tObj;		//# resgister thread obj
}

void app_gui_stop(void)
{
	app_thr_obj *tObj;

	tObj = app_cfg->uObj;
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

	tObj = app_cfg->iObj;
	if(tObj != NULL)
	{
		while(!tObj->done)
			OSA_waitMsecs(20);

		OSA_semDelete(&tObj->sem);

		app_mfree(tObj);
		tObj = NULL;
	}

	if(igui != NULL) {
		app_mfree(igui);
	}
}

/*****************************************************************************
* @brief    capture main function
* @section  DESC Description
*   - desc
*****************************************************************************/
int app_capt_main(void)
{
	app_thr_obj *tObj = app_cfg->mObj;
	int cmd, exit=0;
	int ret=0;

	printf(" [app ] %s start\n", __func__);

	//# video capture start
	ret = app_capt_start();
	if(ret < 0)
		return -1;

//    mic_send_msg(CMD_BUZZER, 1, BUZZER_100);
	while(!exit)
	{
		//# wait cmd
		cmd = event_wait(tObj);

		switch(cmd)
		{
			case UBX_CMD_RESTART:
			{
                event_send(app_cfg->uObj, UBX_GUI_LOGO, 0, 0);
				app_capt_stop();
				OSA_waitMsecs(500);

				app_capt_start();
				break;
			}
            case UBX_CMD_SD_REMOVE:
            {
                 break;
            }
            case UBX_CMD_SD_SIZE_ERR:
            {
                
                break;
            }
			case UBX_CMD_EXIT:
			{
                ubx_write_setting();
				exit = 1;
				break;
			}
			default:
				break;
		}
	}

	//# power off check point #1 -----
	if(app_cfg->state.pwroff) {
		ctrl_hdcam_pwroff();
	}

	//# video capture stop
	app_capt_stop();

	printf(" [task] %s stop!\n", __func__);

	return 0;
}

/*****************************************************************************
* @brief    playback main function
* @section  DESC Description
*   - desc
*****************************************************************************/
int app_pbk_main(void)
{
#if 0

	flist_t *flist[MAX_DIR_NUM];
	int i, ret;

	printf(" [app ] %s start\n", __func__);

	//# video decoder start
	app_dec_start();

	//# create file list
	flist[IDX_DIR_DRIVE] = util_flist_create(DIR_REC_DRIVE, "*.avi", 1);
	flist[DIR_REC_MOTION] = util_flist_create(DIR_REC_PARKING, "*.avi", 1);
	flist[IDX_DIR_EVENT] = util_flist_create(DIR_REC_EVENT, "*.avi", 1);
	flist[IDX_DIR_SNAPSHOOT] = util_flist_create(DIR_REC_SNAPSHOOT, "*.jpeg", 1);
	for(i=0; i<MAX_DIR_NUM; i++) {
		if(flist[i] == NULL) {
			eprintf("file list create!\n");
			return -1;
		}
	}

	//# file list menu
	//ui_menu_tvo_flist(flist);
	ret = ui_menu_ts_flist(flist);

	for(i=0; i<MAX_DIR_NUM; i++) {
		util_flist_delete(flist[i]);
	}

	//# video decoder stop
	app_dec_stop();

	OSA_waitMsecs(200);		//# wait m3 done
	dprintf("... stop!\n");

	return ret;
#endif
	return 0;
}

#define TVO_GAP_X	40
#define TVO_GAP_Y	25
#define GSV_Y       80

#define formREC		"NO REC"
#define formGPS		"GPS OFF"
#define formSSID	"000-00000"
#define formTemp	"000`C"
#define formVolt    "00.0V"
#define formMIC     "MIC 0"
#define formBUZZER  "BZ 0"
#define formERR		"ERR 000"
#define SPACE_W     20

void ui_draw_txt_tvo(void)
{
	char temp_str[10];
	char volt_str[10];
    char version[20];
    char item[20];
	float volt_val;
    ui_pos_t st, rect;
	int str_w=0, str_h=0;

	str_h 	= draw_font_height( ctrl_get_fw_ver(), FNT_SZ01 );	
	
    if(app_cfg->state.ui_cap){
		
		//# ----------------- Top positon ------------------ //
		
		//# Clear top info line
        rect.x=0, rect.y=TVO_GAP_Y, rect.w=UI_TVO_WI, rect.h=str_h;
		draw_fill_rect(igui->gfx_obj.tvo.buf, rect, RGB_KEY);

		//# WiFi
        if(app_cfg->state.wifi){
#ifdef EN_WIFI_CLIENT
			st.x = 210 + draw_string_len( formSSID, FNT_SZ01 ) + draw_string_len( formSSID, FNT_SZ01 ) + 10;
			draw_text(igui->gfx_obj.tvo.buf, app_set->srv_info.ipaddr, FNT_SZ01, st.x, TVO_GAP_Y, RGB_WHITE, RGB_BLACK);

#else
			st.x = 210 + draw_string_len( formSSID, FNT_SZ01 ) + draw_string_len( formSSID, FNT_SZ01 ) + 10;
			draw_text(igui->gfx_obj.tvo.buf, app_set->wifiap.ssid, FNT_SZ01, st.x, TVO_GAP_Y, RGB_WHITE, RGB_BLACK);
#endif
        }
		
		//# GPS
		st.x = 210 + draw_string_len( formSSID, FNT_SZ01 ) + 10;
        if(app_cfg->state.gps){
            draw_text(igui->gfx_obj.tvo.buf, "GPS ON", FNT_SZ01, st.x, TVO_GAP_Y, RGB_WHITE, RGB_BLACK);
        }
        else{
            draw_text(igui->gfx_obj.tvo.buf, "GPS OFF", FNT_SZ01, st.x, TVO_GAP_Y, RGB_WHITE, RGB_BLACK);
        }


		//# ----------------- Bottom positon ---------------- //
		st.y 	= UI_TVO_HE - ( str_h + TVO_GAP_Y );

		//# Clear bottom info line
		rect.y=st.y;
		draw_fill_rect(igui->gfx_obj.tvo.buf, rect, RGB_BLACK);

		//# Rec status
		st.x = TVO_GAP_X;
        if(app_cfg->tvo_flag & TVO_REC){
            if(app_cfg->state.rec && app_cfg->state.cam_buzzer == 0){
                draw_text(igui->gfx_obj.tvo.buf, "REC", FNT_SZ01, st.x, st.y, RGB_RED, RGB_BLACK);
            }
            else{
                draw_text(igui->gfx_obj.tvo.buf, "NO REC", FNT_SZ01, st.x, st.y, RGB_WHITE, RGB_BLACK);
            }
        }

        if(app_cfg->tvo_flag & TVO_TEMP){
        	if(app_cfg->state.cap){
    			st.x += draw_string_len( formREC, FNT_SZ01 ) + 5;
        		sprintf(temp_str, "%d'C", app_dev_get_temp_val());
        		draw_text(igui->gfx_obj.tvo.buf, temp_str, FNT_SZ01, st.x, st.y, RGB_WHITE, RGB_BLACK);
        	}
        }

        if(app_cfg->tvo_flag & TVO_VOLT){
            if(app_cfg->state.cap){
    			st.x += draw_string_len( formTemp, FNT_SZ01 ) + 5;
       			sprintf(volt_str, "%2.1fV", ( (float)app_dev_get_volt_val() / 100. ) );
       			draw_text(igui->gfx_obj.tvo.buf, volt_str, FNT_SZ01, st.x, st.y, RGB_WHITE, RGB_BLACK);
        	}
        }

        if(app_cfg->tvo_flag & TVO_MIC){
            st.x += draw_string_len(formVolt, FNT_SZ01) + SPACE_W;
            sprintf(item, "MIC %d", app_set->aud.mic_on);
            draw_text(igui->gfx_obj.tvo.buf, item, FNT_SZ01, st.x, st.y, RGB_WHITE, RGB_BLACK);
        }

        if(app_cfg->tvo_flag & TVO_BUZZER){
            st.x += draw_string_len(formMIC, FNT_SZ01) + SPACE_W;
            sprintf(item, "BZ %d", app_set->aud.snd_on);
            draw_text(igui->gfx_obj.tvo.buf, item, FNT_SZ01, st.x, st.y, RGB_WHITE, RGB_BLACK);
        }

		// serdes error gegister
		st.x += draw_string_len(formBUZZER, FNT_SZ01) + SPACE_W;


//		sprintf(item, "ERR %d", app_cfg->serdes_err_val);
//		draw_text(igui->gfx_obj.tvo.buf, item, FNT_SZ01, st.x, st.y, RGB_WHITE, RGB_BLACK);

		sprintf(item, "ERROR");
#ifdef FOR_CAM_TEST
			if(app_cfg->serdes_err_val > 0)
#else			
			if(app_cfg->serdes_err_val > SERDES_ERR_MIN_CNT)
#endif

			draw_text(igui->gfx_obj.tvo.buf, item, FNT_SZ01, st.x, st.y, RGB_WHITE, RGB_BLACK);
		else
			draw_text(igui->gfx_obj.tvo.buf, item, FNT_SZ01, st.x, st.y, RGB_BLACK, RGB_BLACK);

		
        if(app_cfg->tvo_flag & TVO_VERSION){
    		//# Ver. info
    		str_w	= draw_string_len( ctrl_get_fw_ver(), FNT_SZ01 );
            str_w   = str_w + draw_string_len( TCX_MODEL, FNT_SZ01 );
    		st.x 	= UI_TVO_WI - ( str_w + 60 );
            str_w   = draw_string_len(app_cfg->micom_ver, FNT_SZ01);
            st.x 	= st.x - str_w;

            sprintf(version, "%s_%s (%s)", TCX_MODEL, ctrl_get_fw_ver(), app_cfg->micom_ver);
            draw_text(igui->gfx_obj.tvo.buf, version, FNT_SZ01, st.x, st.y, RGB_WHITE, RGB_BLACK);
        }
    }
}

#ifdef DEBUG_GSV
void ui_draw_gsv()
{
    int gsv_size=0, i=0,j=0;
    unsigned int snr_temp[GPS_PRNMAX];
    unsigned int pnr_temp[GPS_PRNMAX];
    unsigned int temp=0, temp_p=0;
    int color=0;
    ui_pos_t st;
    int gsv_count=0;
    int r_cnt=0;

    char gsv_total[10], gsv_data[12][10];
    char gsa_id[12][10];

    gsv_size = sizeof(GPS_SENSITIVITY);
    memset(&gps_sens, 0, gsv_size);

    app_dev_gps_sensitivity((void*)&gps_sens);

    for(i=0; i<gps_sens.satellites_visible; i++){
        snr_temp[i] = 0;
        pnr_temp[i] = 0;
    }

    for(i=0; i<gps_sens.satellites_visible; i++){
        snr_temp[i] = gps_sens.ss[i];
        pnr_temp[i] = gps_sens.PRN[i];
    }

    for(i=0; i<gps_sens.satellites_visible; i++){
        for(j=i+1; j<gps_sens.satellites_visible; j++){
            if(snr_temp[i] < snr_temp[j]){
                temp   = snr_temp[i];
                temp_p = pnr_temp[i];
                snr_temp[i] = snr_temp[j];
                pnr_temp[i] = pnr_temp[j];
                snr_temp[j] = temp;
                pnr_temp[j] = temp_p;
            }
        }
    }

    for(i=0; i<gps_sens.satellites_visible; i++){
        if(snr_temp[i] != 0)
            r_cnt++;
    }

    
    //TOTAL
    if(r_cnt>12){
        gsv_count = 12;
    }
    else{
        gsv_count = r_cnt;
    }
    
    sprintf(gsv_total, "total : %02d", gsv_count);
    draw_text(igui->gfx_obj.tvo.buf, gsv_total, FNT_SZ01, 40, GSV_Y, RGB_WHITE, RGB_BLACK);

    draw_text(igui->gfx_obj.tvo.buf, "R.ID : ", FNT_SZ01, 40, GSV_Y+45, RGB_WHITE, RGB_BLACK);

    st.x=90, st.y=GSV_Y+40, st.w=520, st.h=90;
    draw_fill_rect(igui->gfx_obj.tvo.buf, st, RGB_KEY);
    draw_text(igui->gfx_obj.tvo.buf, "DB : ", FNT_SZ01, 40, GSV_Y+85, RGB_WHITE, RGB_BLACK);
    

    for(i=0; i<gsv_count; i++){
        sprintf(gsa_id[i], "%02u", pnr_temp[i]);
        draw_text(igui->gfx_obj.tvo.buf, gsa_id[i], FNT_SZ01, 100+(i*40), GSV_Y+45, RGB_WHITE, RGB_BLACK);

        sprintf(gsv_data[i], "%u", snr_temp[i]);
        if(snr_temp[i] < 25)
            color = RGB_RED;
        else if(snr_temp[i] > 24 && snr_temp[i] < 40)
            color = RGB_BLUE;
        else
            color = RGB_GREEN;
        draw_text(igui->gfx_obj.tvo.buf, gsv_data[i], FNT_SZ01, 100+(i*40), GSV_Y+85, color, RGB_BLACK);
    }

}
#endif


