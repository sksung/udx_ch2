/******************************************************************************
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_rec.h
 * @brief
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
#if 0
#define DIR_DISK			"/mmc"
#define DIR_REC				"/mmc/data"
#else
#define DIR_DISK			"/"
#define DIR_REC				"/opt/d16/_data"
#endif

//# TRUE/FALSE
#define EN_REC_AUD		FALSE
#define EN_REC_META		FALSE

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int app_rec_init(void);
int app_rec_exit(void);
int app_rec_start(int ch);
int app_rec_stop(void);

int app_save_jpeg(int ch, void *addr, int size, unsigned int sec);

#endif	/* _APP_REC_H_ */
