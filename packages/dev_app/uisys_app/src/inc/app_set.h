/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_set.h
 * @brief
 * @author	phoong
 * @section	MODIFY history
 *      - 2013.08.21 : Modified by sksung
 */
/*****************************************************************************/

#ifndef _APP_SET_H_
#define _APP_SET_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#include "ucx_main.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define CFG_DIR_MMC				"/mmc/cfg"
#define CFG_DIR_NAND            "/media/nand/cfg"

#define CFG_NAME				"cfg"
#define CFG_EXT					"ini"

#define CFG_INVALID     -1
#define CHAR_MEMSET     "UNKNOWN"

#define LANG_KOREAN		0
#define LANG_ENGLISH	1


#define DEFAULT_FPS		30

#define RATE_CTRL_VBR	0
#define RATE_CTRL_CBR	1


typedef enum {
	MODE_DRIVING=0,
	MODE_PARKING,
	MODE_MAX
} app_secu_mode_e;

typedef enum {
    COMPEN_MODE_1=0, // driving 2, parking 2
	COMPEN_MODE_2,   // driving 3, parking 1
	COMPEN_MODE_3,   // driving 4, parking 3

    COMPEN_MODE_MAX
} app_volt_compen_e;

typedef enum {
	UBX_LAYOUT_D=0,		//# main + sub
	//UBX_LAYOUT_D_S,     //# sub + main
	UBX_LAYOUT_M,		//# main only
	UBX_LAYOUT_S,		//# sub only
	UBX_LAYOUT_MAX
} app_layout_e;

typedef enum {
	RESOL_1080P=0,
	RESOL_720P,
	RESOL_480P,
	MAX_RESOL
} app_resol_e;

/*typedef enum {
	Q_LOWEST=0,
	Q_LOW,
	Q_MID,
	Q_HIGH,
	MAX_QUALITY
} app_quality_e;*/

typedef enum {
    Q_HIGH=0,
	Q_MID,
	Q_LOW,
	
	MAX_QUALITY
} app_quality_e;


typedef enum {
    MIRROR_VH=0,
    MIRROR_V,
    MIRROR_H,    
    MIRROR_OFF,
    MIRROR_MAX
}app_mirror_e;

typedef enum {
    AUDIO_VOL_1=1,
    AUDIO_VOL_2,
    AUDIO_VOL_3,
    AUDIO_VOL_4,
    AUDIO_VOL_5,
    AUDIO_VOL_MAX
}app_volume_e;


typedef enum {
	BAT_SAFE_OFF=0, //# not use battery safe in parking mode
    BAT_SAFE_06,    //# 6hour later system off in parking mode
    BAT_SAFE_12,    //# 12hour later system off in parking mode
    BAT_SAFE_24,    //# 24hour later system off in parking mode
    BAT_SAFE_36,    //# 36hour later system off in parking mode
    BAT_SAFE_48,    //# 48hour later system off in parking mode
    BAT_SAFE_MAX
}app_bat_safe_e;


typedef enum {
    TEMP_IDX_1=0,
    TEMP_IDX_2,
    TEMP_IDX_3,
    TEMP_IDX_4,
    TEMP_IDX_5,
    TEMP_IDX_MAX
}app_temp_idx_e;


typedef enum {
    VOLT_LEVEL_12V=0,
    VOLT_LEVEL_24V,
    VOLT_LEVEL_MAX
}app_volt_level_e;


typedef enum {
    VOLT_IDX_1=0,   //#11.1V, 21.8V
    VOLT_IDX_2,     //#11.2V, 22.0V
    VOLT_IDX_3,     //#11.3V, 22.2V
    VOLT_IDX_4,     //#11.4V, 22.4V
    VOLT_IDX_5,     //#11.5V, 22.6V
    VOLT_IDX_6,     //#11.6V, 22.8V
    VOLT_IDX_7,     //#11.7V, 23.0V
    VOLT_IDX_8,     //#11.8V, 23.2V
    VOLT_IDX_MAX
}app_volt_idx_e;


typedef enum {
    MOTION_IDX_OFF=0,
    MOTION_IDX_01,
    MOTION_IDX_02,
    MOTION_IDX_03,
    
    MOTION_IDX_MAX
}app_mot_idx_e;

typedef enum {
    GSN_IDX_01=0,
    GSN_IDX_02,
    GSN_IDX_03,
    GSN_IDX_04,
    GSN_IDX_05,
    GSN_IDX_OFF,
    GSN_IDX_MAX
}app_gsn_idx_e;


typedef enum {
	AUTOPARK_OFF=0,
    AUTOPARK_10,
    AUTOPARK_15,
    AUTOPARK_20,
    AUTOPARK_MAX
}app_aprk_e;


typedef enum {
    FPS_30=0,
    FPS_25,
    FPS_20,
    FPS_15,
    FPS_10,
    FPS_MAX
}app_frate_e;

typedef enum{
    CAM_BRIGHT_1 = 1,
    CAM_BRIGHT_2,
    CAM_BRIGHT_3,
    CAM_BRIGHT_4,
    CAM_BRIGHT_5,

    CAM_BRIGHT_MAX
}app_cam_bright_e;


typedef enum {
    SD_FORMAT_OFF=0,
    SD_FORMAT_2W,
    SD_FORMAT_4W,
    SD_FORMAT_8W,
    SD_FORMAT_MAX
}app_sformat_e;


typedef enum {
	SETTING_NONE = 99,
	SETTING_LOCAL,
	SETTING_REMOTE,
	SETTING_MAX
}app_set_flag_e;

typedef enum{
    SUMMER_TIME_1 = 0,
    SUMMER_TIME_2,
    SUMMER_TIME_3,
    SUMMER_TIME_4,
    SUMMER_TIME_5,

    SUMMER_TIME_MAX
}app_summer_time_e;

typedef enum{
	SERDES_LV_L = 0,
	SERDES_LV_M,
	SERDES_LV_H,
	SERDES_LV_MAX
}app_slevel_e;


typedef struct {
    int sub_mirror;	
} app_lcd_t;


typedef struct {
    int mic_on;
	int snd_on;
} app_aud_t;


typedef struct {
	int resol;
	int framerate;
	int quality;
	int rate_ctrl;
	int motion;
} app_ch_cfg_t;

typedef struct {
	unsigned long long weeks;		//sec, app_sformat_e type
	unsigned long long start;		// time_t value
} app_sd_format_t;

typedef struct {
    int bat_safe;   //auto battary safe mode 12/24/36/48/60/72  (hour)
    int temp;     	//tamparature check
    int volt;     	//voltage check level
    int auto_park; 	//auto parking mode sensitivity
    int motion;   	//motion sensitivity
    int gsn;  		//Gsensor sensitivity	
} app_watchdog_t;

typedef struct {
    int  use_wifi;
    char ssid[CHAR_32];
    char pwd[CHAR_16];
    char ip[CHAR_16];
} app_network_t;

typedef struct {
    char pname[CHAR_32];
    char model[CHAR_32];
    char hw_ver[CHAR_32];
    char sw_ver[CHAR_32];
} app_info_t;

typedef struct {
    int motion;
    int gsensor;
    int status;
} app_event_t;

typedef struct{
    int front_bright;
    int rear_bright;
} app_cam_bright_t;

typedef struct{
    int tz_idx;
    int st_idx; //summer time idx
}app_time_zone_t;

typedef struct {
	int cinfo_use;
	char cinfo_car_num[CHAR_32];
}app_car_info_t;

typedef struct {
	int serdes_level;
	int motion_only;
	unsigned char reserved[32];
}app_sys_t;


typedef struct {
	int 			lang;				//# 0:Korean, 1:English
	int			 	set_change;     		//# setting change flag
	app_lcd_t 		lcd;
	app_aud_t 		aud;
	app_ch_cfg_t 	ch[MAX_CH_NUM];
	app_ch_cfg_t 	ch_prk[MAX_CH_NUM];
	app_sd_format_t	fdur;
	app_watchdog_t	wd;
	app_network_t	net;
	app_info_t		info;
    app_cam_bright_t cam;
	app_time_zone_t  tz;
	app_car_info_t	car;
	app_sys_t		sys;
	int 			front_mirror;
	unsigned char reserved[1020];
}app_set_t;


/*------------------------------------------------
 String Index
------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
extern app_set_t *app_set;

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
void ubx_set_default(void);
int ubx_open_setting(void);
int ubx_write_setting(void);
int ubx_change_setting();
void app_set_cfg_params(void);
void ubx_delete_cfg(void);

int get_bitrate_val(int quality, int resol);
int get_temp_val(app_temp_idx_e idx);
int get_auto_prk_val(app_aprk_e idx);
int get_bat_safe_val(app_bat_safe_e idx);
int get_fps_val(app_frate_e idx);
int get_low_volt_val(app_secu_mode_e mode, app_volt_idx_e idx);
int get_summer_time_idx(app_summer_time_e idx);
int get_serdes_lv(app_slevel_e idx);

unsigned long long get_sd_format_val(app_sformat_e idx);
void set_format_dur(void);

#endif	/* _APP_SET_H_ */
