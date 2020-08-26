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

int ctrl_hdcam_err_state(int ch);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            Codec              //
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int ctrl_enc_br_set(int ch, int bitrate);
int ctrl_enc_fr_set(int ch, int framerate);
int ctrl_enc_gop_set(int ch, int gop);
int ctrl_enc_rc_set(int ch, int rc, int br);
int ctrl_enc_motion_set(int ch, int enable);

/**
 * @name	ctrl_set_enc_prm
 * @brief
 * @param	mode: refer to app_ch_type_e, 0:CH_TYPE_RECORDING, 1:CH_TYPE_STREAMING
 *			fps_idx: refer to app_frate_e
 *			bps_idx: refer to app_quality_e
 */
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
int ctrl_time_set(int year, int mon, int day, int hour, int min, int sec, int utc);
int ctrl_sd_format(void);
int check_fw();
void check_nand_update();
void delete_nand_update();
int ctrl_get_isp_version(char *version);
int ctrl_get_hw_version(char *version);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            WIFI              //
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int ctrl_wifi_set(int on);
int ctrl_set_ssid(char* ssid);
int ctrl_set_ap_pwd(char* pwd);

char* ctrl_get_fw_ver(void);
void app_ctrl_out_copy(void);


#endif	/* _APP_CTRL_H_ */
