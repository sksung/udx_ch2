/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_dev.h
 * @brief
 * @author	phoong
 * @section	MODIFY history
 */
/*****************************************************************************/

#ifndef _APP_DEV_H_
#define _APP_DEV_H_

#include "dev_gps.h"
#include "dev_accel.h"
#include "ucx_main.h"

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
//# gpio
#define GPIO_N(b, n)		((32*b) + n)

#define TVOUT_DET_GIO		GPIO_N(2, 30)

#define HDSENS0_DET_GIO		GPIO_N(3, 14)
#define HDSENS1_DET_GIO		GPIO_N(3, 17)
#define SERDES_LOCK_GIO		GPIO_N(3, 18)

#define HDSENS0_PWR_GIO		GPIO_N(2, 29)
#define HDSENS1_PWR_GIO 	GPIO_N(3, 16)

#define STATUS_LED_1		GPIO_N(3, 1) /* act_low */
#define STATUS_LED_2		GPIO_N(3, 2) /* act_low */
#define STATUS_LED_3		GPIO_N(3, 3) /* act_low */

#define GSENSOR_CNT_MAX     10

/* Wi-Fi Module Path */
#define RTL_8188E_PATH		"/lib/modules/8188eu.ko"
#define RTL_8188C_PATH		"/lib/modules/8192cu.ko"
#define RTL_8821A_PATH		"/lib/modules/8821au.ko"
#define RTL_8192E_PATH		"/lib/modules/8192eu.ko"

/* Wi-Fi Module name */
#define RTL_8188E_NAME		"8188eu"
#define RTL_8188C_NAME		"8192cu"
#define RTL_8821A_NAME		"8821au"
#define RTL_8192E_NAME		"8192eu"

#define SYSTEM_NONE     0
#define SYSTEM_OPER     1
#define SYSTEM_ERR      2
#define SYSTEM_ONOFF	3

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
typedef struct {
	unsigned int gps_Enable;			//0: invalid, 1:valid
	unsigned int gps_UTC_Year;
	unsigned int gps_UTC_Month;
	unsigned int gps_UTC_Day;
	unsigned int gps_UTC_Hour;
	unsigned int gps_UTC_Min;
	unsigned int gps_UTC_Sec;
	unsigned int gps_UTC_Msec;
	unsigned int gps_Speed;

	double gps_LAT; //Latitude		gps_LAT > 0: N, gps_LAT < 0: S
	double gps_LOT; //Longitude 	gps_LOT > 0: E, gps_LOT < 0: W
	double gps_Dir; //Forward direction (degree)

} GPS_RMC_DATA;

typedef struct{
	int acc_sec;
	int acc_msec;
	accel_data_t acc_level;
}app_gs_t;

typedef struct {
	GPS_RMC_DATA gps;
	app_gs_t gsensor[GSENSOR_CNT_MAX];
}app_meta_t;

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
void app_dev_start(void);
void app_dev_stop(void);

int app_dev_gpio_init(void);
void app_dev_gpio_exit(void);

void pwr_led_run(int on);
void rec_led_run(int on);
void ac_led_run(int on);
int rec_state_led(void);

int dev_led_default(void);

void app_dev_get_gps(void* gps);
void app_dev_get_gsv(void* gsv);
void app_dev_get_gsa(void* gsa);

int app_dev_get_volt_val(void);
int app_dev_get_temp_val(void);

int app_tvout_status(void);
int app_dev_hdsens_status(int ch);

int app_micom_init(void);
int app_micom_exit(void);
void app_watchdog_init(int en, short sec);
void app_watchdog_keep_alive(void);
void app_keep_alive(void);

void dev_system_reboot(int update);
void dev_menu_stop(void);
void dev_system_stop(void);
int system_buzzer(int state);

void app_dev_set_shutdown_timer(int on);

#endif	/* _APP_DEV_H_ */
