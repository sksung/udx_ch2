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
#define DEFAULT_STR               "UNKNOWN"


/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
app_set_t* app_set;
app_set_t app_sys_set;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/
static int qbr[MAX_RESOL][MAX_QUALITY] = {
	{ 1000, 2000, 3000, 6000, 9000 },	//# 720p - Recording
	{ 256, 512, 1000, 0, 0 }			//# 480p - Streaming
};

static int MIN_VOLT_IDX[VOLT_LEVEL_MAX][VOLT_IDX_MAX] = {						//# Low voltage 12/24V  xxxx = xx.xx volt
	{1110, 1120, 1130, 1140, 1150, 1160, 1170, 1180},	//# 12V
	{2180, 2200, 2220, 2240, 2260, 2280, 2300, 2320}	//# 24V
};

static int HIGH_TEMP_IDX[TEMP_IDX_MAX]		= {80, 85, 90, 95, 100};			//# temparature
static int AUTOPRK_TIME[AUTOPARK_MAX]		= {0, 10, 15, 20}; 					//# auto change to parking mode
static int BAT_SAFE_TIME[BAT_SAFE_MAX]		= {0, 6, 12, 24, 36, 48}; 	        //# shutdown time on parking mode
static int SD_FORMAT_PERIOD[SD_FORMAT_MAX]	= {0, 2, 4, 8};						//# format time

#ifdef FLIKER
	#if FLIKER_MODE_60HZ
		static int FPS_IDX[FPS_MAX]				= {30, 15, 10, 5};
		static int P_FPS_IDX[FPS_MAX]			= {30, 15, 10, 5};
	#else
		static int FPS_IDX[FPS_MAX]				= {25, 20, 12, 5};
		static int P_FPS_IDX[FPS_MAX]			= {25, 20, 12, 5};
	#endif	//FLIKER_MODE_60HZ
#else
//	static int FPS_IDX[FPS_MAX]					= {30, 20, 10, 10};	//Not use
//	static int P_FPS_IDX[FPS_MAX]				= {30, 20, 10, 10};
#endif

static int SUMMER_IDX[SUMMER_TIME_MAX]      = {-2, -1, 0, 1, 2};

static int VOLUME_IDX[AUDIO_VOL_MAX]		= {65, 75, 80, 85, 90, 95};

static int REC_DUR[REC_DUR_MAX]				= {1, 5, 10, 20, 30, 60};

//# serdes values
static int SERDES_EQ[SERDES_EQ_MAX]				= {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B};
static int SERDES_PE[SERDES_PE_MAX]				= {0xA4, 0xA3, 0xA2, 0xA1, 0xA0, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF};
static serdes_val_t SERDES_IDX[SERDES_LV_MAX] 	= { { 3, 6 }, { 9, 7 }, { 9, 10}, };				//LOW, MEDIUM, HIGH

//static int SERDES_LV[SERDES_LV_MAX]				= {SERDES_EQ_LV4, SERDES_EQ_LV2, SERDES_EQ_LV3};	//LOW, MEDIUM, HIGH


app_set_t app_default_set = {
	.set_time			= 0,
	.lang 				= LANG_ENGLISH,	//# 0:Korean, 1:English
	.rec_type			= REC_TYPE_NOR,	//# 0:Normal, 1:Motion
	.lcd = {
		.sub_mirror   	= MIRROR_OFF,		//# REAR CAM MIRROR
	},
	.aud = {
		.mic_on    = OFF,			//# MIC
		.snd_on    = OFF,			//# SOUND ON LIVE
	},
	//# drive_ch 0
	.ch[0] = {
		.resol     = RESOL_720P,   //# resolution
		.framerate = FPS_05,		//# frame
		.quality   = Q_LV05,			//# bitrate(Kbps)		
		.rate_ctrl = RATE_CTRL_VBR, //# rate_ctl
		.motion    = 0,
	},
	//# drive_ch 1
	.ch[1] = {
		.resol     = RESOL_480P,   //# resolution
		.framerate = FPS_15,		//# frame
		.quality   = Q_LV03,			//# bitrate(Kbps)		
		.rate_ctrl = RATE_CTRL_VBR, //# rate_ctl
		.motion    = 0,
	},
	//# park_ch 0
	.ch_prk[0] = {
		.resol     = RESOL_720P,   //# resolution
		.framerate = FPS_05,		//# frame
		.quality   = Q_LV05,			//# bitrate(Kbps)
		.rate_ctrl = RATE_CTRL_VBR, //# rate_ctl
		.motion    = 0,
	},
	//# park_ch 1
	.ch_prk[1] = {
		.resol     = RESOL_480P,   //# resolution
		.framerate = FPS_15,		//# frame
		.quality   = Q_LV03,			//# bitrate(Kbps)
		.rate_ctrl = RATE_CTRL_VBR, //# rate_ctl
		.motion    = 0,
	},
	.fdur = {
		.weeks = SD_FORMAT_OFF,	//# sd format period
		.start = OFF,			//# sd format period start time
	},
	.wd = {
		.bat_safe  = BAT_SAFE_OFF,	//# shutdown time on parking mode
		.temp      = TEMP_IDX_3,		//# temparature
		.volt      = VOLT_IDX_1,		//# minimum voltage
		.auto_park = AUTOPARK_OFF,	//# auto parking time
		.motion    = MOTION_IDX_OFF,	//# motion sensitivity
		.gsn       = GSN_IDX_03,		//# g-sensor sensitivity
	},
	.net = {
		.use_wifi = ON,			//# use wifi
		.ssid     = "UCX-AP",
		.pwd      = "12345678",
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
    .wifiap = {
        .en_key = 1,
        .ssid = "SX062725_AHN",
        .pwd  = "12345678",
        .stealth = OFF,

    },
    .srv_info = {
        .ipaddr = "192.168.1.252",
        .subnet = "255.255.255.0",
        .gateway = "192.168.1.1",
        .deviceID = "DTC000001",
    },
	.sys = {
		.serdes_level = SERDES_LV_L,
		.rec_duration = REC_DUR_05,
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
	sprintf(app_set->wifiap.ssid, "SX-%05d", randVal);
    dprintf("SSID CREATE DONE!! [%s]\n", app_set->wifiap.ssid);
}

static void cfg_encoding(char* str, int len)
{
	int i;
	for(i = 0; i < len; i++)
		str[i] = ~(str[i]);
}


static void cfg_decoding(char* str, int len)
{
	int i;
	for(i = 0; i < len; i++)
		str[i] = ~(str[i]);
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

int get_serdes_lv(app_slevel_e idx, int* eq, int* pe)
{
	if(idx < SERDES_LV_L || idx >= SERDES_LV_MAX){
		idx = SERDES_LV_L;
	}

	*eq = SERDES_IDX[idx].eq_idx;
	*pe = SERDES_IDX[idx].pe_idx;

	return SOK;
}

int get_rec_dur_val(app_rec_dur_e idx)
{
	int dur_min = REC_DUR[REC_DUR_05];

	if(idx >= REC_DUR_01 && idx < REC_DUR_MAX)
		dur_min = REC_DUR[idx];

	return dur_min;
}



int get_serdes_eq(int eq_idx)
{
	int eq = EFAIL;
	if(eq_idx >= SERDES_EQ_0 && eq_idx < SERDES_EQ_MAX)
		eq = SERDES_EQ[eq_idx];

	return eq;
}

int get_serdes_pe(int pe_idx)
{
	int pe = EFAIL;
	if(pe_idx >= SERDES_PE_0 && pe_idx < SERDES_PE_MAX)
		pe = SERDES_PE[pe_idx];

	return pe;
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

	if(pset->aud.mic_on != ON && pset->aud.mic_on != OFF){
		pset->aud.mic_on = OFF;
	}
	if(pset->aud.snd_on != ON && pset->aud.snd_on != OFF){
		pset->aud.snd_on = OFF;
	}

	for(i = 0; i < MAX_CH_NUM; i++){
		//# driving mode
		pset->ch[i].resol 			= RESOL_720P;
		if(i==1) pset->ch[i].resol 	= RESOL_480P;
		
		pset->ch[i].rate_ctrl 		= RATE_CTRL_VBR;

		if(pset->ch[i].framerate >= FPS_MAX || pset->ch[i].framerate < FPS_30)
		{
			pset->ch[i].framerate = FPS_05;
			if(i==1) pset->ch[i].framerate = FPS_15;
		}


		if(pset->ch[i].quality >= MAX_QUALITY || pset->ch[i].quality < Q_LV01)
		{
			pset->ch[i].quality = Q_LV05;
			if(i==1)pset->ch[i].quality = Q_LV03;
		}

		if(pset->ch[i].motion != ON && pset->ch[i].motion != OFF)
			pset->ch[i].motion = OFF;

		//# parking mode
		pset->ch_prk[i].resol 		= RESOL_720P;
		pset->ch_prk[i].rate_ctrl 	= RATE_CTRL_VBR;

		if(pset->ch_prk[i].framerate >= FPS_MAX || pset->ch_prk[i].framerate < FPS_30)
			pset->ch_prk[i].framerate = FPS_10;

		if(pset->ch_prk[i].quality >= MAX_QUALITY || pset->ch_prk[i].quality < Q_LV01)
			pset->ch_prk[i].quality = Q_LV03;

		if(pset->ch_prk[i].motion != ON && pset->ch_prk[i].motion != OFF)
			pset->ch_prk[i].motion = OFF;
	}

	if(pset->fdur.weeks >= SD_FORMAT_MAX || pset->fdur.weeks < SD_FORMAT_OFF)
		pset->fdur.weeks = SD_FORMAT_OFF;

	if(pset->fdur.start == CFG_INVALID)
		set_format_dur();	

	if(pset->wd.bat_safe >= BAT_SAFE_MAX || pset->wd.bat_safe < BAT_SAFE_OFF)
		pset->wd.bat_safe = BAT_SAFE_OFF;

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

	sprintf(pset->net.ip, "%s", "192.168.0.1");

	sprintf(pset->info.sw_ver, "%s", ctrl_get_fw_ver());
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

	if(pset->sys.rec_duration < REC_DUR_01 || pset->sys.rec_duration >= REC_DUR_MAX) {
		pset->sys.rec_duration = REC_DUR_05;
	}

    if(pset->wifiap.en_key < 0)
        pset->wifiap.en_key = 1 ;

	if(pset->wifiap.stealth < 0)
		pset->wifiap.stealth = OFF;

#ifdef EN_WIFI_CLIENT
    if(strcmp(pset->wifiap.ssid, CHAR_MEMSET) == 0)
        sprintf(pset->wifiap.ssid, "%s","SX062725_AHN") ;    
#else	
	if(strcmp(pset->wifiap.ssid, CHAR_MEMSET) == 0)
		wifi_ssid_create();
#endif	

	if(strcmp(pset->wifiap.pwd, CHAR_MEMSET) == 0 || strlen(pset->wifiap.pwd) < CHAR_8)
		sprintf(pset->wifiap.pwd, "%s", "12345678");

    if( strcmp(pset->srv_info.ipaddr, CHAR_MEMSET) == 0 )
        sprintf(pset->srv_info.ipaddr, "%s", "192.168.1.252");

    if( strcmp(pset->srv_info.subnet, CHAR_MEMSET) == 0 )
        sprintf(pset->srv_info.subnet, "%s", "255.255.255.0");

    if( strcmp(pset->srv_info.gateway, CHAR_MEMSET) == 0 )
        sprintf(pset->srv_info.gateway, "%s", "192.168.1.1");

    if( strcmp(pset->srv_info.deviceID, CHAR_MEMSET) == 0 )
        sprintf(pset->srv_info.deviceID, "%s", "DTC000001");
}

void ubx_set_default(void)
{
    dprintf("default start!!\n");

	ubx_delete_cfg();
	
	memcpy((void *)app_set, &app_default_set, sizeof(app_set_t));

	set_format_dur();
	app_set_cfg_params();
	
#ifndef EN_WIFI_CLIENT	
	wifi_ssid_create();
#endif
}

static int get_cfg_mmc(void)
{
    int readSize=0, setSize=0;
    int cfg_size=0;

	if(!app_cfg->state.mmc)	
		return EFAIL;
	
    if(-1 == access(CFG_DIR_MMC, 0)) {
        mkdir(CFG_DIR_MMC, 0775);
        chmod(CFG_DIR_MMC, 0775);
		return EFAIL;
    }

    if(-1 == access(app_cfg->cfg_mmc_path, 0)){
		//# cpoy nand cfg file to SD
		eprintf("NOT CFG FILE IN SD!!\n");
		return EFAIL;
	}

    setSize 	= sizeof(app_set_t);					//# current version cfg_size
	cfg_size 	= get_file_size(app_cfg->cfg_mmc_path);	//# sd cfg_size (old version)
	if(cfg_size != setSize){
		//# cfg is different
		printf("\n ######## SD_CFG size NOT same read:%d/set:%d -> SET DEFAULT!!! ######## \n", cfg_size, setSize);
		ubx_set_default();
	}
	else{
		//#--- ucx app setting param
		OSA_fileReadFile(app_cfg->cfg_mmc_path, (Uint8*)app_set, setSize, (Uint32*)&readSize);
		if(readSize == 0 || readSize != setSize) return EFAIL;

		//# pwd decoding...
		cfg_decoding(app_set->wifiap.pwd, sizeof(app_set->wifiap.pwd));
		
		printf("@@@@ pwd dec @@@@@\n");
		printf(" wifi_pwd:%s \n", app_set->wifiap.pwd);
		printf("@@@@@@@@@@@@@@@@@@\n");
	}

	cfg_param_check(app_set);
	return SOK;
}


static int get_cfg_nand(void)
{
    int readSize=0, setSize=0;
	int cfg_size=0;

	if(-1 == access(CFG_DIR_NAND, 0)) {
		mkdir(CFG_DIR_NAND, 0775);
		chmod(CFG_DIR_NAND, 0775);
	}

    if(-1 == access(app_cfg->cfg_nand_path, 0)){
		eprintf("\n ######## Nand CFG Not Access... Set Default ######## \n");
		goto default_nand;
   	}

	setSize     = sizeof(app_set_t);
	cfg_size	= get_file_size(app_cfg->cfg_nand_path);
	
	if(cfg_size != setSize){
		//# cfg is different
		printf("\n ######## NAND_CFG size NOT same read:%d/set:%d -> SET DEFAULT!!! ######## \n", cfg_size, setSize);
		goto default_nand;
	}
	else{
		//# setting param check
		OSA_fileReadFile(app_cfg->cfg_nand_path, (Uint8*)app_set, setSize, (Uint32*)&readSize);
		if(readSize == 0 || readSize != setSize){
			eprintf("\n ######## Nand CFG Not Open failed!!! Set Default ######## \n");
			goto default_nand;		
		}

		//# pwd decoding...
		cfg_decoding(app_set->wifiap.pwd, sizeof(app_set->wifiap.pwd));
		
		printf("@@@@ pwd dec @@@@@\n");
		printf(" wifi_pwd:%s \n", app_set->wifiap.pwd);
		printf("@@@@@@@@@@@@@@@@@@\n");
		
		cfg_param_check(app_set);
	}

	return SOK;


default_nand:
	
	ubx_set_default();
	cfg_param_check(app_set);

	return SOK;
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

    sprintf(app_set->wifiap.ssid, "%s",CHAR_MEMSET);
    sprintf(app_set->wifiap.pwd, "%s",CHAR_MEMSET);
    sprintf(app_set->srv_info.ipaddr, "%s",CHAR_MEMSET);
    sprintf(app_set->srv_info.subnet, "%s",CHAR_MEMSET);
    sprintf(app_set->srv_info.gateway, "%s",CHAR_MEMSET);
    sprintf(app_set->srv_info.deviceID, "%s",CHAR_MEMSET);
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
	int ret = SOK;
    char* pFile = NULL;
    char cmd[CHAR_128]={0,};

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
	app_set = (app_set_t *)&app_sys_set;
	memset(app_set, CFG_INVALID, sizeof(app_set_t));
    char_memset();

	//# set cfg path...
	sprintf(app_cfg->cfg_mmc_path, "%s/%s_%s.%s", CFG_DIR_MMC, CFG_MODEL, CFG_NAME, CFG_EXT);
	sprintf(app_cfg->cfg_nand_path, "%s/%s_%s.%s", CFG_DIR_NAND, CFG_MODEL, CFG_NAME, CFG_EXT);

	//# sd cfg check
	if(get_cfg_mmc() != SOK) {
		//# nand cfg check
		ret = get_cfg_nand();
	}

	//# force setting because not use.
	app_set->aud.mic_on = OFF;
	app_set->aud.snd_on = OFF;
	
	if(ret == SOK)
		ubx_write_setting();
		
    return 0;
}

int ubx_write_setting(void)
{
	//# record time at cfg changed
	time(&app_set->set_time);

	//# encoding cfg...#//
	app_set_t* enc_cfg = (app_set_t*)malloc(sizeof(app_set_t));
	memcpy(enc_cfg, app_set, sizeof(app_set_t));

	cfg_encoding(enc_cfg->wifiap.pwd, sizeof(enc_cfg->wifiap.pwd));
	/////////////////////
	
	//# save cfg in sd card.
    if(app_cfg->state.mmc)
	{
		if(-1 == access(CFG_DIR_MMC, 0)) {
			mkdir(CFG_DIR_MMC, 0775);
			chmod(CFG_DIR_MMC, 0775);
		}

		if (OSA_fileWriteFile(app_cfg->cfg_mmc_path, (Uint8*)enc_cfg, sizeof(app_set_t)) != OSA_SOK) {
			eprintf("couldn't open %s file\n", app_cfg->cfg_mmc_path);
		}
   	}	

	//# save cfg in nand.
	if(-1 == access(CFG_DIR_NAND, 0)) {
		mkdir(CFG_DIR_NAND, 0775);
		chmod(CFG_DIR_NAND, 0775);
	}

	if (OSA_fileWriteFile(app_cfg->cfg_nand_path, (Uint8*)enc_cfg, sizeof(app_set_t)) != OSA_SOK) {
		eprintf("couldn't open %s file\n", app_cfg->cfg_nand_path);
	}
	
	printf(" [app] %s done...!\n", __func__);

	sync();
	free(enc_cfg);
	return 0;
}


int ubx_change_setting()
{
    char cmd[CHAR_64];

    if(app_cfg->state.mmc){
        ubx_write_setting();
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



