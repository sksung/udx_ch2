/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    snd_db.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.07.01 : First Created
 */
/*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wav.h"

snd_info_t *get_snd_db(int snd_idx)
{
	if(snd_idx > (SND_DB_MAX-1))
		return 0;

	//printf("%s: (%d) size %d\n", __func__, snd_idx, sdb[snd_idx].sz);

	return &sdb[snd_idx];
}
