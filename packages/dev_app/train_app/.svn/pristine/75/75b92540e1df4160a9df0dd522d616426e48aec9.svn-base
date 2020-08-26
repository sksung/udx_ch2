/******************************************************************************
 * UBX Board
 * Copyright by	UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file	app_sockio.h
 * @brief
 * @author	hwjun
 * @section	MODIFY history
 */
/*****************************************************************************/

#ifndef _APP_SOCKIO_H_
#define _APP_SOCKIO_H_

/*----------------------------------------------------------------------------
 Defines referenced	header files
-----------------------------------------------------------------------------*/
#include <osa.h>
#include <osa_mutex.h>
#include <osa_thr.h>
#include <osa_pipe.h>
#include <osa_sem.h>
#include <osa_que.h>
#include <osa_buf.h>

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

#define MAX_PENDING_SEM_COUNT   (10)

typedef struct
{
    OSA_ThrHndl         thr;
    OSA_SemHndl         sem ;
    OSA_MutexHndl       mutex;
    int      exitsockThread;
} app_nthr_obj ;

typedef struct {
    app_nthr_obj gControlSockObj ;
    app_nthr_obj gSockObj ;
} app_dtcObj ;


/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 Declares a	function prototype
-----------------------------------------------------------------------------*/
int Sock_start(void);
int Sock_stop(void) ;

#endif	/* _APP_SOCKIO_H_ */
