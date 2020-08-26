/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_main.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2016.12.17 : fixed CWX application
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//# include mcfw_linux
#include "ti_vsys.h"
#include "ti_vcap.h"

#include "app_comm.h"
#include "app_gmem.h"
#include "app_cap.h"
#include "app_rec.h"
#include "app_key.h"
#include "app_dev.h"
#include "app_mcu.h"
#include "app_ctrl.h"
#include "gui_main.h"
#include "app_main.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
static app_cfg_t cfg_obj;
app_cfg_t *iapp=&cfg_obj;

static int no_menu=0;
static char auto_cmd='0';

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 main thread function - use only communication
-----------------------------------------------------------------------------*/
static int main_thread_init(void)
{
	app_thr_obj *tObj = &iapp->mObj;

	//#--- create thread
	if(thread_create(tObj, NULL, APP_THREAD_PRI, NULL) < 0) {
		eprintf("create thread\n");
		return -1;
	}

	return 0;
}

static void main_thread_exit(void)
{
	app_thr_obj *tObj = &iapp->mObj;

	//#--- stop thread
	thread_delete(tObj);
}

/*----------------------------------------------------------------------------
 m3 event handler function
-----------------------------------------------------------------------------*/
#define MAX_DET_CH		2
int vsys_event(unsigned int eventId, void *pPrm, void *appData)
{
	int video_detect[MAX_DET_CH];
	int i, ret;

	if(eventId==VSYS_EVENT_VIDEO_DETECT)
	{
		ret = Vcap_get_video_status(video_detect, MAX_DET_CH);
		for(i=0; i<ret; i++) {
			printf("CH%d : %s\n", i, video_detect[i]?"video detect":"no video");
		}
	}

	if (eventId==VSYS_EVENT_MOTION_DETECT)
	{
	    printf("CH%d : detected motion\n", *(int *)pPrm);
	}

	return 0;
}


/*****************************************************************************
* @brief    demo capture run function
* @section  [desc]
*****************************************************************************/
char menu_cap[] = {
	"\r\n ================"
	"\r\n Capture Run Menu"
	"\r\n ================"
	"\r\n"
	"\r\n 0: stop"
	"\r\n 1: sw mosaic"
	"\r\n 2: capture ctrl"
	"\r\n 3: encoder ctrl"
	"\r\n%s4: record start/stop"
	"\r\n 5: snapshoot"
	"\r\n"
	"\r\n Enter Choice: "
};

static int demo_cap_run(int demo_id)
{
	int ret = 0;
	char cmd, exit=0;
	int ste_rec=0;

	//# register event
	Vsys_registerEventHandler(vsys_event, NULL);

	//# start capture
	ret = app_cap_start(demo_id);
	if(ret < 0) {
		return -1;
	}
	app_msleep(200);		//# wait capture start

	gui_ctrl(GUI_DRAW_RUN, 0, 0);

	if(no_menu)
	{
		while(1)
		{
			//# wait cmd
			cmd = event_wait(&iapp->mObj);
			if(cmd == APP_CMD_EXIT)
				break;
		}
	}
	else
	{
		while(!exit)
		{
			printf(menu_cap, ste_rec?"*":" ");
			cmd = menu_get_cmd();

			switch(cmd)
			{
				case '0':		//# exit
					exit = 1;
					break;
				case '1':
					test_swms();
					break;
				case '2':
					test_cap_ctrl();
					break;
				case '3':
					test_enc_ctrl();
					break;
				case '4':
				{
					int ch, max_ch = iapp->num_ch;

					ste_rec = 1 - ste_rec;
					if(ste_rec)
					{
						printf("channel? (0~%d) : ", max_ch-1);
						ch = menu_get_data();
						if(ch > max_ch-1) {
							eprintf("\n invalid channel %d\n", ch);
							break;
						}
						ret = app_rec_start(ch);
						if(ret < 0) {
							ste_rec = 0;
						}
					}
					else {
						app_rec_stop();
					}

					break;
				}
				case '5':
				{
					int ch, max_ch = iapp->num_ch;

					printf("channel? (0~%d) : ", max_ch-1);
					ch = menu_get_data();
					if(ch > max_ch-1) {
						eprintf("\n invalid channel %d\n", ch);
						break;
					}
					iapp->snapshoot = ch + 1;	//# ch0->1, ch1->2...
					break;
				}
			}
		}
	}

	if(ste_rec) {
		app_rec_stop();
	}

	gui_ctrl(GUI_DRAW_STOP, 0, 0);

	//# stop capture
	app_cap_stop();

	sleep(1);	//# wait done of m3's printf

	return ret;
}

/*****************************************************************************
* @brief    app main function
* @section  [desc] console menu
*****************************************************************************/
char menu_main[] = {
	"\r\n ============="
	"\r\n Demo Menu"
	"\r\n ============="
	"\r\n"
	"\r\n 0: exit"
	"\r\n 1: 2HD"
	"\r\n"
	"\r\n 6: playback"
	"\r\n 7: sound"
	"\r\n 8: device test"
	"\r\n 9: micom test"
	"\r\n a: get version"
	"\r\n"
	"\r\n Enter Choice: "
};

int demo_main(void)
{
	app_thr_obj *tObj = &iapp->mObj;
	char cmd, exit=0;

	aprintf("enter...\n");
	tObj->active = 1;

	app_key_start();

	while(!exit)
	{
		if(auto_cmd != '0') {
			cmd = auto_cmd;
			auto_cmd = '0';
		} else {
			printf(menu_main);
			cmd = menu_get_cmd();
		}

		switch(cmd)
		{
			case '0':		//# exit
				exit = 1;
				break;
			case '1': case '2': case '3': case '4':
				demo_cap_run((int)(cmd-48));	//# '0'->48
				break;
			case '6':
				test_pbk();
				break;
			case '7':
				test_snd();
				break;
			case '8':
				test_device();
				break;
			case '9':
				test_micom();
				break;
			case 'a':
			{
				char ver[16];

				ctrl_get_hw_version(ver);
				printf(" H/W ver : %s\n", ver);

				ctrl_get_mcu_version(ver);
				printf(" MCU ver : %s\n", ver);
				break;
			}
			default:
				break;
		}
	}

	app_key_stop();

	tObj->active = 0;
	aprintf("exit\n");

	return SOK;
}

/*----------------------------------------------------------------------------
 application config function
-----------------------------------------------------------------------------*/
int app_cfg_init(void)
{
	char buf[16];

	memset((void *)iapp, 0, sizeof(app_cfg_t));

	//# h/w version
	ctrl_get_hw_version(buf);
	dprintf("H/W version %s\n", buf);

	//# module ctrl
	iapp->en_enc = 1;
	iapp->en_jpg = 1;
	iapp->en_dual = 0;
	iapp->en_rec = 1 & iapp->en_enc;

	//# display ctrl
	iapp->en_lcd = 0;
	iapp->en_tvo = 1;
	iapp->is_pal = 0 & iapp->en_tvo;	//# 0: NTSC, 1: PAL

	iapp->disp_dev = DISP_TVO;

	return SOK;
}

/*----------------------------------------------------------------------------
 parsing argv
-----------------------------------------------------------------------------*/
static void chk_arg(int argc, char **argv)
{
	if(argc > 1) {				//# execute no menu
		if(argv[1][0] != '0') {
			auto_cmd = argv[1][0];
			//no_menu = 1;
			dprintf("excute auto start %c\n", auto_cmd);
		}
	}
}

/*****************************************************************************
* @brief    main function
* @section  [desc]
*****************************************************************************/
int main(int argc, char **argv)
{
	int ret;

	printf("\n----- UDX demo start -----\n");

	chk_arg(argc, argv);

	app_cfg_init();
	app_mcu_init();

	//#--- system init
	ret = main_thread_init();
	if(ret < 0) {
		return -1;
	}
	mcfw_linux_init(iapp->is_pal);
	g_mem_init();

	app_dev_init();
	app_gui_init();
	app_rec_init();

	//#--- demo main -------------------
	demo_main();
	//#---------------------------------

	//#--- system de-init
	app_dev_exit();
	app_rec_exit();
	app_gui_exit();

	g_mem_exit();
	mcfw_linux_exit();
	main_thread_exit();

	app_mcu_exit();		//# will power off after 200mS

	printf("----- UDX demo end -----\n\n");

	return 0;
}
