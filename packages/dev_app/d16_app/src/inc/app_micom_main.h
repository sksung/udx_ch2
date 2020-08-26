#ifndef _APP_MICOM_H_
#define _APP_MICOM_H_

#include "dev_micom.h"

#define VOLT_24V_MIN        1800   //# 18.0V

#define VOLT_LOW            900     //#9V

#define ACC_ON				1
#define ACC_OFF				0

#define TIME_WATCHDOG       60   	//# sec

#define BUZZER_1000    1000 //1sec (ms)
#define BUZZER_200      200 //200ms
#define BUZZER_100      100 //100ms

typedef struct{
    app_thr_obj *micomObj;
    
    dev_val_t val;

	int volt_level;
	int volt_min;		//# power on when off by OFF_LPWR_EXT1
	int low_detect;
    int low_pwr_detect;	
}app_micom_t;

void *micom_main(void *prm);
#endif	/* _APP_DEV_H_ */

