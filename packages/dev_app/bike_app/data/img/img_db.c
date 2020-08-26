/******************************************************************************
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    font_db.c
 * @brief
 * @author  phoong
 * @section MODIFY history
 *     - 2013.01.01 : First Created
 */
/*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "img.h"

img_info_t *get_img_db(int img_idx)
{
	if(img_idx > (IMG_DB_MAX-1))
		return 0;

	#if 0
	{
		int i;
		for(i=0; i<IMG_DB_MAX; i++)
			printf("%s: %d->0x%x, %d, %d\n", __func__, i, (int)idb[i].p, idb[i].w, idb[i].h);
	}
	#endif

	//printf("%s: (%d) %d, %d\n", __func__, img_idx, idb[img_idx].w, idb[img_idx].h);

	return &idb[img_idx];
}
