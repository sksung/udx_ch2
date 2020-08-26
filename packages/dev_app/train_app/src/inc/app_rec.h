/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_rec.h
 * @brief
 * @author	phoong
 * @section	MODIFY history
 */
/*****************************************************************************/

#ifndef _APP_REC_H_
#define _APP_REC_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define EN_REC_PROCESS	0

#define META_REC_FPS	1

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int app_rec_start(void);// *g_mem_info);
void app_rec_stop(void);
void app_rec_notify(void);

void app_snap_shoot(void);
void app_change_file(void);
void app_rec_change_dur(int dur);	//# dur: refer to app_rec_dur_e
void app_rec_file_close(void);		//# force close. when all cam disconnected 

#endif	/* _APP_REC_H_ */

