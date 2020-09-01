/******************************************************************************
 * UCX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
/**
 * @file	ucxmain.h
 * @brief
 * @author	sksung
 * @section	MODIFY history
 */
/*****************************************************************************/

#ifndef _UCXMAIN_H_
#define _UCXMAIN_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
 -----------------------------------------------------------------------------*/
#include "osa.h"
#include "osa_thr.h"
#include "osa_sem.h"
#include "osa_mutex.h"

#include "dev_gpio.h"
#include "app_log.h"

/*----------------------------------------------------------------------------
 Definitions and macro
 -----------------------------------------------------------------------------*/
#define DIR_DISK	        "/mmc"
#define DIR_REC				"/mmc/data"
#define DIR_REC_DRIVE		"/mmc/data/drive"
#define DIR_REC_EVENT		"/mmc/data/event"
#define DIR_REC_PARKING		"/mmc/data/parking"

#define NAND_ROOT			"/media/nand"

//#---- FOR DEBUG ----//
//#define TIME_DEBUG
//#define DEBUG_TEMP_DISPLAY
//#define DEBUG_DDR400
//#define DEBUG_META
//#define DEBUG_GSV
//#define DEBUG_AUTO_REBOOT

//# gpio event로10분 이벤트 녹화만 사용함//
#define DETECT_EMG_GIO	(0)

//######### VENDOR SETTING ########//
//#define USE_HTRV
//#################################//



//######### VERSIONING ########//
#ifdef USE_HTRV

	#define TCX_MODEL			"HTRV"
	#define CFG_MODEL			"htrv"
	#define TCX_SW_VER      	"3.05.02"
	
#else

 	//# D16	
	#define TCX_MODEL			"D16"
	#define CFG_MODEL			"d16"
	#define TCX_SW_VER  		"3.07.00"	
	
		#if DETECT_EMG_GIO
			#define TCX_SW_VER		"3.07.00E"
		#endif
	
#endif
//#################################//


//#---------------------

#define MAX_CH_NUM			(2)

#define ENC_D1_CHANNEL		(2)

#define REBOOT_NORMAL       0
#define REBOOT_UPDATE       1

#define ON					1
#define OFF					0

#define POWER_OFF           1

#define DISP_TVO			1
#define DISP_FWUPDATE       2
#define DISP_FWDONE         3
#define DISP_ERROR          4

#define JPEG_QUALITY		60	//# 1~100	100 is max.
#define JPEG_FPS			1	//# default fps of jpeg.

#define MAX_PENDING_SEM_CNT	(1)
#define FXN_TSK_PRI			(1)
#define FXN_TSK_STACK_SIZE	(0) /* 0 means system default will be used */

//# error type
#define SOK					(0)
#define EFAIL				(-1)
#define EPARAM				(-2)
#define EINVALID			(-3)
#define EMEM				(-4)

#define CHAR_8              8
#define CHAR_16             16
#define CHAR_32             32
#define CHAR_64             64
#define CHAR_128			128

#define MIN_SEC             60
#define HOUR_SEC			(MIN_SEC*60)
#define DAY_SEC				(HOUR_SEC*24)
#define WEEK_SEC			(DAY_SEC*7)

#define WD_ENC				(1<<0)
#define WD_TMR				(1<<1)
#define WD_GSN				(1<<2)
#define WD_DEV				(1<<3)
#define WD_FILE				(1<<4)
#define WD_MICOM            (1<<5)
#define WD_TOT				(WD_ENC+WD_TMR+WD_GSN+WD_DEV+WD_FILE+WD_MICOM)

#define WD_FSCAN			(0xDAAF)

#define WD_ENC_NAME		"ENCODER "
#define WD_TMR_NAME		"TIMMER "
#define WD_GSN_NAME		"G-SENSOR "
#define WD_DEV_NAME		"GPS "
#define WD_FILE_NAME	"FILE_MGR "
#define WD_MICOM_NAME	"MICOM "

#define TVO_REC		    (1<<0)
#define TVO_TEMP		(1<<1)
#define TVO_VOLT		(1<<2)
#define TVO_GSENSOR		(1<<3)
#define TVO_MOTION		(1<<4)
#define TVO_MIC         (1<<5)
#define TVO_BUZZER		(1<<6)
#define TVO_VERSION		(1<<7)

typedef enum {
	UBX_KEY_UP = 1,
	UBX_KEY_LEFT,
	UBX_KEY_SEL,
	UBX_KEY_RIGHT,
	UBX_KEY_DOWN,

	UBX_TS_SEL,
	UBX_TS_UP,
	UBX_TS_LEFT,
	UBX_TS_RIGHT,
	UBX_TS_DOWN,
	UBX_TS_LEFT_DN,

	UBX_GUI_LOGO,
	UBX_GUI_CAPT,
	UBX_GUI_MTIME0,		//# draw menu show time
	UBX_GUI_LCNT,
	UBX_GUI_MOTION,
	UBX_GUI_ANI_STOP,

	UBX_CMD_PLAY,
	UBX_CMD_PAUSE,
	UBX_CMD_FF,
	UBX_CMD_FR,
	UBX_CMD_DRAW_TIME,

	UBX_CMD_EVT,

	UBX_CMD_NOTY,
	UBX_CMD_CLEAR,
	UBX_CMD_START,
	UBX_CMD_STOP,
	UBX_CMD_RESTART,
	UBX_CMD_EXIT,

    UBX_CMD_SD_REMOVE,
    UBX_CMD_SD_SIZE_ERR,

    UBX_CMD_RTL_DETECTED,
    UBX_CMD_RTL_REMOVED,

	UBX_CMD_REC_ERR,
	UBX_CMD_SD_ERR,

	UBX_CMD_MAX
} app_cmd_e;

typedef enum {
	RE_PAGE1 = -100,
    RE_PAGE2,
    RE_PB_BACK,
    RE_PB_MAIN,
	RE_STOP,
	RE_EXIT,
	RE_RESTART,
	RE_REBOOT,
	RE_SD_REMOVE,
	RE_SD_INIT_ERR,
	RE_FW_ERR,

	RE_MAX
} re_val_e;

typedef enum {
	MSG_TYPE_UCX,
	MSG_TYPE_GUI,
	MSG_TYPE_LOG,

	MSG_TYPE_MAX
} ucx_msg_e;


typedef struct{
    int msgDes;
    int msgSrc;
    int msgCmd;
    int msgParm1;
    int msgParm2;
    int msgParm3;
    char msgstr[CHAR_128];
    int msgAck;
}ucx_msg_info;


typedef struct{
    int x;
    int y;
} ui_item_pos_t;

typedef	struct {
	unsigned int cap	: 1;
	unsigned int rec	: 1;
	unsigned int evt 	: 1;	//# event recording
	unsigned int snd	: 1;
	unsigned int mic	: 1;
	unsigned int nokey  : 1;	//# skip key input
	unsigned int tvo	: 1;
	unsigned int ui_cap	: 1;
	unsigned int mmc	: 1;
	unsigned int mmc_sz : 1;	//#	available size check in SD
	unsigned int gps	: 1;	//# gps detect
	unsigned int wifi	: 1;
	unsigned int acc	: 1;	//# acc detect
    unsigned int pwroff	: 1;	//# go to power off
	unsigned int park	: 1;	//# parking mode
	unsigned int format	: 1;
	unsigned int fdur	: 1;	//# time to sd format
	unsigned int tsync	: 1;	//# gps time sync
	unsigned int gsn	: 1;	//# gsensor threshold
	unsigned int popup  : 1;
	unsigned int rtsptx : 1;
	unsigned int secu_on: 1;	//# securiey led on
	unsigned int peek_low : 1;	//# down peek low voltage suddenly. -> if 1, no pwr hold.
    unsigned int micom  : 1;
    unsigned int rec_err: 1;  //# recording error
    unsigned int mmc_err    :1;  //# mmc error
	unsigned int log		:1; //#log file process
	unsigned int cam_buzzer :1;
    unsigned int sd_buzzer  :1;
    unsigned int shock      :1;
    unsigned int motion     :1;
} app_state; //# 30bits

typedef struct {
	OSA_ThrHndl thr;
	OSA_SemHndl sem;

	int cmd;
	int param0;
	int param1;
	int	done;
    int ani_done;
} app_thr_obj;

typedef struct {
	int wi;		//# frame width
	int he;		//# frame height
	int fr;		//# frame rate
	int br;		//# bitrate
} frm_info_t;

typedef struct {
	app_thr_obj *mObj;		//# main thread
	app_thr_obj *uObj;		//# gui thread
	app_thr_obj *iObj;		//# animation thread

	app_state	state;

	int usecase;
	int num_ch;						//# current channel number
	int layout;						//# layout(M1+S1->M1->S1)
	int layout_swap;

	frm_info_t	ifrm[MAX_CH_NUM];

	int volt_level;					//# 12/24V level
	int	volt_low;
	int temp_high;
	int bsafe_time;					//# battery safe time
	int bsafe_start;				//# battery safe start time
	int apark_time;					//# auto park change time
	int apark_start;				//# auto park mode start time
	unsigned long long fdur_weeks;	//# sd format weeks time

	int wd_flags;		//# watchdog flags - ui, rec, adc, temp, etc...
	int wd_tot;			//# watchdog total flag value;

	int set_state;		//# refer to app_set_state_e

	//# programmer setting param
    int en_enc;			//# encoder enable
	int en_jpg;			//# mjpeg enable
	int en_rec;			//# file write enable
	int en_dis;			//# display enable
	int en_tvo;			//# tv-out enable (not used)
    int en_rtsptx;  	//# rtsp_stream enable
    int en_dual;		//# dual straem enable
	int msgqId;
    char micom_ver[CHAR_32];
	char cfg_mmc_path[CHAR_128];
	char cfg_nand_path[CHAR_128];
    int tvo_flag;       //# tv-out display (ex: rec, gsensor level, motion level, mic on, buzzer on)
} app_cfg_t;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
extern app_cfg_t *app_cfg;

#define eprintf(x...) do { printf(" [app !err] %s: ", __func__); printf(x); } while(0)
#ifdef SYS_DEBUG
#define dprintf(x...) do { printf(" [app ] %s: ", __func__); printf(x); } while(0)
#else
#define dprintf(x...)
#endif

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int event_wait(app_thr_obj *tObj);
void event_send(app_thr_obj *tObj, int cmd, int param0, int param1);
#ifdef TIME_DEBUG
void time_debug_clock(char *func, int type);
#endif

#endif	/* _UCXMAIN_H_ */
