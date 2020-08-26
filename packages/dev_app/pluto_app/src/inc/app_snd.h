/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_sound.h
 * @brief
 * @author	phoong
 * @section	MODIFY history
 *      -2013.08.20 Modified by sksung
 */
/*****************************************************************************/

#ifndef _APP_SND_H_
#define _APP_SND_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#include "ucx_db_snd.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
typedef enum {
	AUD_CODEC_G711 = 1,

	MAX_AUD_CODEC
} aud_codec_e;

#define AUD_SAMPLE_LATE		16000
#define MAX_G711_BUF_SIZE	8000
#define MAX_AENC_BUF_SIZE	MAX_G711_BUF_SIZE

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int app_aud_capt_init(int buf_time);
int app_aud_capt_exit(void);
int app_aud_capt(unsigned char *buf);
int app_snd_enable_live(int enable);
void app_snd_init(void);

#endif	/* _APP_SOUND_H_ */
