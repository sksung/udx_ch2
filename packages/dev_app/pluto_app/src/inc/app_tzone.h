/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_tzone.h
 * @brief
 * @author	sksung
 * @section	MODIFY history
 */
/*****************************************************************************/

#ifndef _APP_TZONE_H_
#define _APP_TZONE_H_

#include "ucx_main.h"

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define MAX_TZ_LIST		100
#define DEFAULT_TZ_IDX	34 	//# Coordinated Universal Time (+0)


typedef struct {
	int  tz_h;
	int  tz_m;
	char str[CHAR_128];
}time_zone_info_t;


/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/
extern time_zone_info_t tz_list[];


/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
void get_time_zone(int idx, int *h, int *m);




#endif	/* _APP_TZONE_H_ */
