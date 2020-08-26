/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_ctrl.h
 * @brief
 * @author	phoong
 * @section	MODIFY history
 */
/*****************************************************************************/

#ifndef _APP_CTRL_H_
#define _APP_CTRL_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#define DISP_SWMS_ONE   1
#define DISP_SWMS_ALL   2

#define DISP_CHANNEL_FRONT  0
#define DISP_CHANNEL_REAR   1

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define ERR_MMC_HAVE_MULTI_PART		0x01
#define ERR_MMC_HAVE_ERRORS			0x02

typedef enum {
    SERDES_EQ_LV0,		//# B, 0.5m~15m
    SERDES_EQ_LV1,		//# D, 3m~25m
    SERDES_EQ_LV2,		//# C, 0.5m~20m
    SERDES_EQ_LV3,		//# E, 3m~30m
    SERDES_EQ_LV4,		//# A, 0.15m~15m
    MAX_SERDES_EQ_LV
} serdes_eq_e;

typedef enum {
	SYS_OFF_NORMAL = 900,
	SYS_OFF_LOWPWR,
	SYS_OFF_LOWBATT,
	SYS_OFF_HITEMP,
	SYS_OFF_TIMER,
	SYS_OFF_RESET,
	SYS_OFF_MAX
} sys_off_type_e;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//             LCD               //
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void ctrl_tvo_enable(int enable);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//           Display             //
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int ctrl_swMs_set(int win_num, int ch, int ch_swap);
void ctrl_swMs_reset();

void ctrl_swosd_enable(int idx, int ch, int draw);
void ctrl_swosd_speed(int value, int draw);
void ctrl_swosd_voltage(int value, int draw);
void ctrl_swosd_gsensor(int x, int y, int z, int draw);
void ctrl_swosd_userstr(char *str, int draw);
void ctrl_swosd_temperature(int value, int draw);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//          Capture              //
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int ctrl_hdcam_state(int ch);
int ctrl_hdcam_frame_set(int ch, int frame);
int ctrl_hdcam_mirror(int ch, int value);
int ctrl_hdcam_pwroff(void);
int ctrl_hdcam_pwron(void);
int ctrl_hdcam_brightness(int dev, int value);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            Codec              //
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int ctrl_enc_br_set(int ch, int bitrate);
int ctrl_enc_fr_set(int ch, int framerate);
int ctrl_enc_gop_set(int ch, int gop);
int ctrl_enc_rc_set(int ch, int rc, int br);
int ctrl_enc_motion_set(int ch, int enable);

int ctrl_set_enc_prm(int mode, int fps_idx, int bps_idx);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            System             //
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int ctrl_mmc_state(void);
int ctrl_mmc_check_fsck(void);
int ctrl_mmc_run_fsck(void);
int ctrl_mmc_check_partitions(void);
int ctrl_mmc_check_exfat(unsigned long *size);
int ctrl_exfat_format(unsigned long size);
int ctrl_mode_change(int mode);
int ctrl_time_set(int year, int mon, int day, int hour, int min, int sec, int utc);
int ctrl_sd_format(void);
int check_fw();
void check_nand_update();
void delete_nand_update();
int ctrl_get_isp_version(char *version);
int ctrl_get_hw_version(char *version);
void ctrl_system_shutdown(int off_type);


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            WIFI              //
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int ctrl_wifi_set(int on);
int ctrl_set_ssid(char* ssid);
int ctrl_set_ap_pwd(char* pwd);

#endif	/* _APP_CTRL_H_ */
