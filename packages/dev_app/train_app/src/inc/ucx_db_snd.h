/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    snd_db.h
 * @brief
 * @author  phoong
 * @section MODIFY history
 */
/*****************************************************************************/
#if !defined (_SND_DB_H_)
#define _SND_DB_H_

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

typedef enum {
	WAV_CAUTION_ALARM,
	WAV_CONVERT_DRIVING_MODE,
	WAV_CONVERT_PARKING_MODE,
	WAV_EXCEED_SETTING_TEMPERATURE,
	WAV_INSERT_CARD,
	WAV_NOTIFY,
	WAV_REACH_FORMAT_PERIOD,
	WAV_RECORDING_START,
	WAV_RECORDING_STOP,
	WAV_RESTART_RECORDING,
	WAV_RESTART_SYSTEM,
	WAV_SD_FORMAT,
	WAV_SD_INSERTED,
	WAV_SD_REMOVED,
	WAV_SD_SIZE_ERR,
	WAV_SYSTEM_EXIT,
	WAV_SYSTEM_START,
	WAV_TOUCH,
	WAV_VOICE_GUIDE_OFF,
	WAV_VOICE_GUIDE_ON,
	WAV_VOLTAGE_INSTABILITY,

	SND_DB_MAX
} snd_db_e;

typedef struct {
	unsigned char *p;
	int sz;	//# size
	int ch;	//# channel
	int sr;	//# sample rate
	int bs;	//# bits_per_sample
} snd_info_t;

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

snd_info_t *get_snd_db(int snd_idx);

#endif	//_SND_DB_H_
