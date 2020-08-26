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
//void app_save_jpeg(int ch, void *addr, int size, unsigned int sec);
void app_snap_shoot(void);
void app_change_file(void);
void app_evt_record(void);
void app_rec_file_close(void);

#endif	/* _APP_REC_H_ */

