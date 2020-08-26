
#ifndef _APP_MICOM_MAIN_H_
#define _APP_MICOM_MAIN_H_

#include "dev_micom.h"

#define VOLT_24V_MIN        1800   //# 18.0V

#define VOLT_LOW            900     //#9V

#define ACC_ON				1
#define ACC_OFF				0

#define TIME_WATCHDOG       60   	//# sec

#define BUZZER_1000    1000 //1sec (ms)
#define BUZZER_200      200 //200ms
#define BUZZER_100      100 //100ms

#define START_VOLTAGE_09V   900
#define START_VOLTAGE_12V	1000//1100	//# 12.00V	//usb2 port+HDD에서 자동차 시동시에 동작을 안하는 현상이 발생해서 1초 내림 
#define START_VOLTAGE_24V   2100    //# 24.00V
#define START_TEMERATURE	600


typedef struct{
    app_thr_obj *micomObj;
    app_thr_obj *voltObj;
    OSA_MutexHndl mutex_3delay;
	
    dev_val_t val;

	int volt_level;
    int low_pwr_detect;	
	int micom_done;
}app_micom_t;

void *micom_main(void *prm);
void *volt_check_main(void *prm);
void delay_3sec_exit(void);

#endif	/* _APP_MICOM_MAIN_H_ */


