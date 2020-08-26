/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    ucbx_set.c
 * @brief	ubx car main program
 * @author  phoong
 * @section MODIFY history
 *     - 2013.07.01 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <glob.h>

#include "osa_file.h"

#include "ucx_main.h"
#include "app_set.h"
#include "dev_common.h"
#include "app_ctrl.h"
#include "app_tzone.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
app_set_t* app_set;
app_set_t app_sys_set;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/
static int qbr[MAX_RESOL][MAX_QUALITY] = {
	{ 8000, 6000, 4000},	//# 1080p
	{ 4000, 3000, 2000},	//# 720p
	{ 3000, 2000, 1000}		//# 480p
};

static int MIN_VOLT_IDX[VOLT_LEVEL_MAX][VOLT_IDX_MAX] = {						//# Low voltage 12/24V  xxxx = xx.xx volt
	{1110, 1120, 1130, 1140, 1150, 1160, 1170, 1180},	//# 12V
	{2180, 2200, 2220, 2240, 2260, 2280, 2300, 2320}	//# 24V
};

static int HIGH_TEMP_IDX[TEMP_IDX_MAX]		= {80, 85, 90, 95, 100};					//# temparature
static int AUTOPRK_TIME[AUTOPARK_MAX]		= {0, 10, 15, 20}; 					//# auto change to parking mode
static int BAT_SAFE_TIME[BAT_SAFE_MAX]		= {0, 6, 12, 24, 36, 48}; 	        //# shutdown time on parking mode
static int SD_FORMAT_PERIOD[SD_FORMAT_MAX]	= {0, 2, 4, 8};						//# format time

#ifdef FLIKER
	#if FLIKER_MODE_60HZ
		static int FPS_IDX[FPS_MAX]				= {30, 15, 7, 5};
		static int P_FPS_IDX[FPS_MAX]			= {30, 15, 7, 5};
	#else
		static int FPS_IDX[FPS_MAX]				= {25, 20, 12, 5};
		static int P_FPS_IDX[FPS_MAX]			= {25, 20, 12, 5};
	#endif	//FLIKER_MODE_60HZ
#else
	static int FPS_IDX[FPS_MAX]					= {30, 20, 15, 10};
	static int P_FPS_IDX[FPS_MAX]				= {30, 20, 15, 10};
#endif

static int SUMMER_IDX[SUMMER_TIME_MAX]      = {-2, -1, 0, 1, 2};

static int VOLUME_IDX[AUDIO_VOL_MAX]		= {65, 75, 80, 85, 90, 95};
static int SERDES_LV[SERDES_LV_MAX]			= {SERDES_EQ_LV4, SERDES_EQ_LV2, SERDES_EQ_LV3};

app_set_t app_default_set = {
	.set_time			= 0,
	.lang 				= LANG_ENGLISH,	//# 0:Korean, 1:English
	.rec_type			= REC_TYPE_NOR,	//# 0:Normal, 1:Motion
	.lcd = {
		.sub_mirror   	= MIRROR_OFF,		//# REAR CAM MIRROR
	},
	.aud = {
		.mic_on    = ON,			//# MIC
		.snd_on    = ON,			//# SOUND ON LIVE
	},
	//# drive_ch 0
	.ch[0] = {
		.resol     = RESOL_720P,   //# resolution
#ifdef DTC_BIKE		
		.framerate = FPS_30,		//# frame
		.quality   = Q_MID,			//# bitrate(Kbps)		
#endif
#ifdef DTC_DRIVE
		.framerate = FPS_15,		//# frame	fliker mode 7fps
		.quality   = Q_LOW,			//# bitrate(Kbps)
#endif

		.rate_ctrl = RATE_CTRL_VBR, //# rate_ctl
		.motion    = 0,
	},
	//# drive_ch 1
	.ch[1] = {
		.resol     = RESOL_720P,   //# resolution
#ifdef DTC_BIKE		
		.framerate = FPS_30,		//# frame
		.quality   = Q_MID,			//# bitrate(Kbps)		
#endif
#ifdef DTC_DRIVE
		.framerate = FPS_15,		//# frame	fliker mode 7fps
		.quality   = Q_LOW,			//# bitrate(Kbps)
#endif

		.rate_ctrl = RATE_CTRL_VBR, //# rate_ctl
		.motion    = 0,
	},
	//# park_ch 0
	.ch_prk[0] = {
		.resol     = RESOL_720P,   //# resolution
		.framerate = FPS_15,		//# frame
		.quality   = Q_MID,			//# bitrate(Kbps)
		.rate_ctrl = RATE_CTRL_VBR, //# rate_ctl
		.motion    = 0,
	},
	//# park_ch 1
	.ch_prk[1] = {
		.resol     = RESOL_720P,   //# resolution
		.framerate = FPS_15,		//# frame
		.quality   = Q_MID,			//# bitrate(Kbps)
		.rate_ctrl = RATE_CTRL_VBR, //# rate_ctl
		.motion    = 0,
	},
	.fdur = {
		.weeks = SD_FORMAT_OFF,	//# sd format period
		.start = OFF,			//# sd format period start time
	},
	.wd = {
		.bat_safe  = BAT_SAFE_12,	//# shutdown time on parking mode
		.temp      = TEMP_IDX_3,		//# temparature
		.volt      = VOLT_IDX_1,		//# minimum voltage
		.auto_park = AUTOPARK_OFF,	//# auto parking time
		.motion    = MOTION_IDX_OFF,	//# motion sensitivity
		.gsn       = GSN_IDX_03,		//# g-sensor sensitivity
	},
	.net = {
		.use_wifi = ON,			//# use wifi
		.ssid     = "UCX-AP",
		.pwd      = "1234567890",
		.ip       = "192.168.0.1",
	},
	.info = {
		.pname   = "",
		.model   = TCX_MODEL,
		.hw_ver  = "",
		.sw_ver  = TCX_SW_VER,
	},
	.cam = {
	    .front_bright = CAM_BRIGHT_3,
        .rear_bright  = CAM_BRIGHT_3,
    },
	.tz = {
		.tz_idx = DEFAULT_TZ_IDX,
        .st_idx = SUMMER_TIME_3,
	},
	.sys = {
		.serdes_level = SERDES_LV_L,
	}	
};

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

#define CFG_RE       ".re" //setting default file

static char* find_reset(void) //setting default file search
{
	char path[255];
	static char	extPath[255];
	glob_t globbuf;

	memset(&globbuf, 0, sizeof(glob_t));

	sprintf(path, "%s/*%s", DIR_UPDATE, CFG_RE);
    if(glob(path, GLOB_DOOFFS, NULL, &globbuf) == 0)
   	{
   		if(globbuf.gl_pathc > 0)
		{
			strcpy(extPath,globbuf.gl_pathv[0]);
			globfree(&globbuf);
			return extPath;
		}
   	}

	globfree(&globbuf);

	return NULL;
}

static void wifi_ssid_create(void)
{
    struct timeval tv;
	Uint32 sec,randVal;
	gettimeofday(&tv, NULL);
	sec = (Uint32)(tv.tv_sec % 10000u);

	srand(sec);
	randVal = rand()%100000+1;
	sprintf(app_set->net.ssid, "%s-%05d",TCX_MODEL, randVal);
    dprintf("SSID CREATE DONE!! [%s]\n", app_set->net.ssid);
}


/*----------------------------------------------------------------------------
 get bitrate config function
-----------------------------------------------------------------------------*/
int get_bitrate_val(int quality, int resol)
{
	return qbr[resol][quality];
}

/*----------------------------------------------------------------------------
 get real value
 -----------------------------------------------------------------------------*/
int get_temp_val(app_temp_idx_e idx)
{
	return HIGH_TEMP_IDX[idx];
}

int get_auto_prk_val(app_aprk_e idx)
{
	return AUTOPRK_TIME[idx];
}

int get_bat_safe_val(app_bat_safe_e idx)
{
	return BAT_SAFE_TIME[idx];
}

unsigned long long get_sd_format_val(app_sformat_e idx)
{
#ifdef TIME_DEBUG
    return SD_FORMAT_PERIOD[idx] * MIN_SEC;
#else
	return SD_FORMAT_PERIOD[idx] * WEEK_SEC;
#endif
}

int get_fps_val(app_frate_e idx)
{
	int fps;

	if(app_cfg->state.park)
		fps = P_FPS_IDX[idx];
	else
		fps = FPS_IDX[idx];

	return fps;
}

int get_low_volt_val(app_secu_mode_e mode, app_volt_idx_e idx)
{
	return MIN_VOLT_IDX[mode][idx];
}

int get_summer_time_idx(app_summer_time_e idx)
{
	if(idx < SUMMER_TIME_1 && idx >= SUMMER_TIME_MAX)
		idx = SUMMER_TIME_3;
	
    return SUMMER_IDX[idx];
}


int get_serdes_lv(app_slevel_e idx)
{
	int level = SERDES_EQ_LV4;
	
	if(idx >= SERDES_LV_L && idx < SERDES_LV_MAX){
		level = SERDES_LV[idx];
	}

	return level;
}


/*****************************************************************************
* @brief    open/write config file function
* @section  DESC Description
*   - desc
*****************************************************************************/
static size_t get_file_size (const char * file_name)
{
    struct stat sb;
    if (stat(file_name, & sb) != 0) {
        eprintf("Failed the CFG file size.\n");
        return 0;
    }
    return sb.st_size;
}

static void cfg_param_check(app_set_t* pset)
{
	int i;
	if(pset->lang != LANG_KOREAN && pset->lang != LANG_ENGLISH )
		pset->lang = LANG_ENGLISH;

	if(pset->set_time <= 0)
		time(&pset->set_time);

	//if(pset->rec_type != REC_TYPE_NOR && pset->rec_type != REC_TYPE_MOT)
	if(pset->rec_type != REC_TYPE_NOR)
		pset->rec_type = REC_TYPE_NOR;
	
	if(pset->lcd.sub_mirror >= MIRROR_MAX || pset->lcd.sub_mirror < MIRROR_VH)
		pset->lcd.sub_mirror = MIRROR_OFF;

	if(pset->aud.mic_on != ON && pset->aud.mic_on != OFF)
		pset->aud.mic_on = ON;

	if(pset->aud.snd_on != ON && pset->aud.snd_on != OFF)
		pset->aud.snd_on = ON;

	for(i = 0; i < MAX_CH_NUM; i++){
		//# driving mode
		pset->ch[i].resol 		= RESOL_720P;
		pset->ch[i].rate_ctrl 	= RATE_CTRL_VBR;

		if(pset->ch[i].framerate >= FPS_MAX || pset->ch[i].framerate < FPS_30)
		{
#ifdef DTC_BIKE
			pset->ch[i].framerate = FPS_30;
#endif
#ifdef DTC_DRIVE
			pset->ch[i].framerate = FPS_15;
#endif
		}


		if(pset->ch[i].quality >= MAX_QUALITY || pset->ch[i].quality < Q_HIGH)
		{
#ifdef DTC_BIKE		
			pset->ch[i].quality = Q_MID;
#endif
#ifdef DTC_DRIVE
			pset->ch[i].quality = Q_LOW;
#endif
		}

		if(pset->ch[i].motion != ON && pset->ch[i].motion != OFF)
			pset->ch[i].motion = OFF;

		//# parking mode
		pset->ch_prk[i].resol 		= RESOL_720P;
		pset->ch_prk[i].rate_ctrl 	= RATE_CTRL_VBR;

		if(pset->ch_prk[i].framerate >= FPS_MAX || pset->ch_prk[i].framerate < FPS_30)
			pset->ch_prk[i].framerate = FPS_15;

		if(pset->ch_prk[i].quality >= MAX_QUALITY || pset->ch_prk[i].quality < Q_HIGH)
			pset->ch_prk[i].quality = Q_MID;

		if(pset->ch_prk[i].motion != ON && pset->ch_prk[i].motion != OFF)
			pset->ch_prk[i].motion = OFF;
	}

	if(pset->fdur.weeks >= SD_FORMAT_MAX || pset->fdur.weeks < SD_FORMAT_OFF)
		pset->fdur.weeks = SD_FORMAT_OFF;

	if(pset->fdur.start == CFG_INVALID)
		set_format_dur();	

	if(pset->wd.bat_safe >= BAT_SAFE_MAX || pset->wd.bat_safe < BAT_SAFE_OFF)
		pset->wd.bat_safe = BAT_SAFE_12;

	if(pset->wd.temp >= TEMP_IDX_MAX || pset->wd.temp < TEMP_IDX_1)
		pset->wd.temp = TEMP_IDX_3;

	if(pset->wd.volt >= VOLT_IDX_MAX|| pset->wd.volt < VOLT_IDX_1)
		pset->wd.volt = VOLT_IDX_1;

	if(pset->wd.motion >= MOTION_IDX_MAX|| pset->wd.motion < MOTION_IDX_OFF)
		pset->wd.motion = MOTION_IDX_OFF;

	if(pset->wd.gsn >= GSN_IDX_MAX|| pset->wd.gsn < GSN_IDX_01)
		pset->wd.gsn = GSN_IDX_03;

	if(pset->net.use_wifi != ON && pset->net.use_wifi != OFF)
		pset->net.use_wifi = ON;

	if(strcmp(pset->net.ssid, CHAR_MEMSET) == 0)
		wifi_ssid_create();
	
	if(strcmp(pset->net.pwd, CHAR_MEMSET) == 0)
		sprintf(pset->net.pwd, "%s", "1234567890");

    if(strlen(pset->net.pwd) < CHAR_8)
        sprintf(pset->net.pwd, "%s", "1234567890");
	
	sprintf(pset->net.ip, "%s", "192.168.0.1");

	sprintf(pset->info.sw_ver, "%s", TCX_SW_VER);
	sprintf(pset->info.model, "%s", TCX_MODEL);
	ctrl_get_hw_version(pset->info.hw_ver);
//	ctrl_get_isp_version(pset->info.)

	if(pset->cam.front_bright >= CAM_BRIGHT_MAX || pset->cam.front_bright < CAM_BRIGHT_1)
		pset->cam.front_bright = CAM_BRIGHT_3;

	if(pset->cam.rear_bright >= CAM_BRIGHT_MAX || pset->cam.rear_bright < CAM_BRIGHT_1)
		pset->cam.rear_bright = CAM_BRIGHT_3;

	if(pset->tz.tz_idx < 0 || pset->tz.tz_idx >= MAX_TZ_LIST)
		pset->tz.tz_idx = DEFAULT_TZ_IDX;

    if(pset->tz.st_idx >= SUMMER_TIME_MAX || pset->tz.st_idx < SUMMER_TIME_1)
        pset->tz.st_idx = SUMMER_TIME_3;

	if(pset->sys.serdes_level < SERDES_LV_L || pset->sys.serdes_level >= SERDES_LV_MAX){
		pset->sys.serdes_level = SERDES_LV_L;
	}	
}

void ubx_set_default(void)
{
    dprintf("default start!!\n");

	memcpy((void *)app_set, &app_default_set, sizeof(app_set_t));

	ubx_delete_cfg();

	set_format_dur();
	app_set_cfg_params();
	wifi_ssid_create();
}

static int get_cfg_mmc(void)
{
    int readSize=0, setSize=0;
    int cfg_size=0;
    char cmd[CHAR_64];
	
    setSize = sizeof(app_set_t);

	if(!app_cfg->state.mmc)
		return EFAIL;
	
    if(-1 == access(CFG_DIR_MMC, 0)) {
        mkdir(CFG_DIR_MMC, 0775);
        chmod(CFG_DIR_MMC, 0775);
		return EFAIL;
    }

    if(-1 == access(app_cfg->cfg_mmc_path, 0)){
		//# cpoy nand cfg file to SD
		printf("### NOT CFG FILE IN SD!! ###\n");
		return EFAIL;
	}

	//# cfg file size check.
	cfg_size = get_file_size(app_cfg->cfg_mmc_path);
	if(cfg_size != setSize){
		eprintf("\n ### CFG size defferent in MMC - Set Default ### \n");
		ubx_set_default();
	}
	else{
		//# read setting param
		OSA_fileReadFile(app_cfg->cfg_mmc_path, (Uint8*)app_set, setSize, (Uint32*)&readSize);
		if(readSize == 0 || readSize != setSize) return EFAIL;
	}

    cfg_param_check(app_set);
	ubx_write_setting(0);	

	return SOK;
}



static int get_cfg_nand(void)
{
    int readSize=0, setSize=0, cfg_size=0;
	
    setSize = sizeof(app_set_t);

	if(-1 == access(CFG_DIR_NAND, 0)) {
		mkdir(CFG_DIR_NAND, 0775);
		chmod(CFG_DIR_NAND, 0775);
	}

    if(-1 == access(app_cfg->cfg_nand_path, 0)){
		eprintf("\n ######## Nand CFG Not Access... Set Default ######## \n");
		goto default_nand;
   	}

	//# cfg file size check.
	cfg_size = get_file_size(app_cfg->cfg_nand_path);
	if(cfg_size != setSize){
		eprintf("\n ### NAND CFG size defferent... Set Default ### \n");
		goto default_nand;
	}	

	//# setting param check
	OSA_fileReadFile(app_cfg->cfg_nand_path, (Uint8*)app_set, setSize, (Uint32*)&readSize);
	if(readSize == 0 || readSize != setSize){
		eprintf("\n ######## Nand CFG Not Open failed!!! Set Default ######## \n");
		goto default_nand;		
	}
	
	cfg_param_check(app_set);
	ubx_write_setting(0);
	
	return SOK;

default_nand:
	ubx_set_default();
	ubx_write_setting(0);

	return 0;
}

static int char_memset()
{
    sprintf(app_set->net.ip, "%s",CHAR_MEMSET);
    sprintf(app_set->net.pwd, "%s",CHAR_MEMSET);
    sprintf(app_set->net.ssid, "%s",CHAR_MEMSET);
    sprintf(app_set->info.hw_ver, "%s",CHAR_MEMSET);
    sprintf(app_set->info.model, "%s",CHAR_MEMSET);
    sprintf(app_set->info.pname, "%s",CHAR_MEMSET);
    sprintf(app_set->info.sw_ver, "%s",CHAR_MEMSET);

    return 0;
}

void ubx_delete_cfg(void)
{
    char cmd[CHAR_128]={0,};

	sprintf(cmd, "rm -Rf %s", CFG_DIR_NAND );
	dev_execlp(cmd);

	if(app_cfg->state.mmc){
		sprintf(cmd, "rm -Rf %s", CFG_DIR_MMC );
		dev_execlp(cmd);
	}		

	sync();
}


int ubx_open_setting(void)
{
    int mmc_err=0;
    char* pFile = NULL;
    char cmd[CHAR_128];

    //".re" file find & delete cfg file
	pFile = find_reset();
    if (pFile != NULL)
	{
        sprintf(cmd, "rm -f %s", pFile);
        dev_execlp(cmd);

		ubx_delete_cfg();
        printf("[%s] CFG delete done!! \n", __func__);
    }

    //#--- ucx app setting param
	app_set     = (app_set_t *)&app_sys_set;
	memset(app_set, CFG_INVALID, sizeof(app_set_t));
    char_memset();

	//# set cfg path...
	sprintf(app_cfg->cfg_mmc_path, "%s/%s_%s.%s", CFG_DIR_MMC, CFG_MODEL, CFG_NAME, CFG_EXT);
	sprintf(app_cfg->cfg_nand_path, "%s/%s_%s.%s", CFG_DIR_NAND, CFG_MODEL, CFG_NAME, CFG_EXT);

	//# sd cfg check
	if(get_cfg_mmc() != SOK){
		//# nand cfg check
		get_cfg_nand();
	}
		
    return 0;
}

int ubx_write_setting(int en_sync)
{
	//# record time at cfg changed
	time(&app_set->set_time);

	//# save cfg in sd card.
    if(app_cfg->state.mmc)
	{
		if(-1 == access(CFG_DIR_MMC, 0)) {
			mkdir(CFG_DIR_MMC, 0775);
			chmod(CFG_DIR_MMC, 0775);
		}

		if (OSA_fileWriteFile(app_cfg->cfg_mmc_path, (Uint8*)app_set, sizeof(app_set_t)) != OSA_SOK) {
			eprintf("couldn't open %s file\n", app_cfg->cfg_mmc_path);
		}
   	}	

	//# save cfg in nand.
	if(-1 == access(CFG_DIR_NAND, 0)) {
		mkdir(CFG_DIR_NAND, 0775);
		chmod(CFG_DIR_NAND, 0775);
	}

	if (OSA_fileWriteFile(app_cfg->cfg_nand_path, (Uint8*)app_set, sizeof(app_set_t)) != OSA_SOK) {
		eprintf("couldn't open %s file\n", app_cfg->cfg_nand_path);
	}
	
	printf(" [app] %s done...!\n", __func__);

	sync();
	return 0;
}


int ubx_change_setting()
{
    char cmd[CHAR_64];

    if(app_cfg->state.mmc){
        ubx_write_setting(0);
        printf("\nsetting change!!!\n");
        sprintf(cmd, "cp %s %s", app_cfg->cfg_mmc_path, app_cfg->cfg_nand_path);
        dev_execlp(cmd);
        sync();
    }

    return 0;
}

void set_format_dur(void)
{
#ifdef TIME_DEBUG
    time_debug_clock(__func__, 1);
#endif

    if(app_set->fdur.weeks!= SD_FORMAT_OFF){
		app_set->fdur.start = 0;
        app_cfg->fdur_weeks = get_sd_format_val(app_set->fdur.weeks);
    }

    app_cfg->state.fdur = 0;
//    app_cfg->state.sd_buzzer = 0;
}

void app_set_cfg_params(void)
{
	app_cfg->bsafe_time	= get_bat_safe_val(app_set->wd.bat_safe);
	app_cfg->apark_time	= get_auto_prk_val(app_set->wd.auto_park);
	app_cfg->fdur_weeks = get_sd_format_val(app_set->fdur.weeks);
}



