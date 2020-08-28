/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_rtsptx.c
 * @brief
 * @author  sksung
 * @section MODIFY history
 *     - 2013.08.26 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "app_cap.h"
#include "stream.h"
#include "app_rtsptx.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define RTSP_STREAMER "./bin/wis-streamer &"

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

/*****************************************************************************
 * @brief    rtsptx write function
 * @section  DESC Description
 *   - desc
 *****************************************************************************/
int app_rtsptx_write(void *addr, int offset, int size, int frametype, int strmtype, unsigned int timestamp)
{
#ifdef USE_GMEM
    stream_write(offset, size, frametype, strmtype, timestamp);
#else
    stream_write(addr, size, frametype, strmtype, timestamp);
#endif

    return 0;
}

/*****************************************************************************
* @brief    rtsptx start/stop function
* @section  DESC Description
*   - desc
*****************************************************************************/
int app_rtsptx_start(void)
{
	STREAM_SET streamSet;
	FILE *fd = NULL;

	streamSet.stream_wi[0] = 1920;
	streamSet.stream_he[0] = 1080;
	streamSet.stream_wi[1] = 1280;
	streamSet.stream_he[1] =  720;

	if(stream_init(&streamSet) < 0){
        eprintf("rtsptx stream init failed!!!\n");
        return -1;
    }

    fd = popen(RTSP_STREAMER, "r");
	if(fd == NULL) {
		return -1;
	}
	pclose(fd);

    return 0;
}

int app_rtsptx_stop(void)
{
	FILE *fd = NULL;

	stream_end();

    fd = popen("killall wis-streamer", "r");
	if(fd == NULL)
		return -1;
	pclose(fd);

    return 0;
}
