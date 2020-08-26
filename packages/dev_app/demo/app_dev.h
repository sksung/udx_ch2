/******************************************************************************
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_dev.h
 * @brief
 */
/*****************************************************************************/

#ifndef _APP_DEV_H_
#define _APP_DEV_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define GPIO_N(b, n)		((32*b) + n)

//# led defines
#define MAX_LEDS		3
#define LED_ON			0	//# act_low
#define LED_OFF			1

#define STE_LED_1		GPIO_N(3, 1)	//# red, power
#define STE_LED_2		GPIO_N(3, 2)	//# green
#define STE_LED_3		GPIO_N(3, 3)	//# green

//# gio input
#define TVOUT_DET		GPIO_N(2, 30)
#define HDCAM0_DET		GPIO_N(3, 14)
#define HDCAM1_DET		GPIO_N(3, 17)

//# gio output
#define HDCAM0_PWR		GPIO_N(2, 29)
#define HDCAM1_PWR		GPIO_N(3, 16)

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int app_dev_init(void);
void app_dev_exit(void);

void ctrl_hdcam_pwr(int on);

int ste_mmc(void);
int ste_tvout(void);
int ste_hdcam(int ch);

int test_device(void);

#endif	/* _APP_DEV_H_ */
