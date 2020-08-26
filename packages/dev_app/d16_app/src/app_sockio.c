/******************************************************************************
 * UBX Board
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    app_sockio.c
 * @brief
 * @author  hwjun
 * @section MODIFY history
 *    - 2013.09.23 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
   Defines referenced header files
-----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
//# remove warning: 'struct mmsghdr' declared inside parameter list
#define __USE_GNU
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>

#include <osa.h>
#include <osa_mutex.h>
#include <osa_thr.h>
#include <osa_pipe.h>

#include "app_message.h"
#include "app_msghandler.h"
#include "app_rawsock.h"
#include "app_process.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

#define SOCKWAIT                30000
#define SOCK_THRFXN_TSK_PRI     (3)

typedef struct
{
    OSA_MutexHndl       mutex_id;
    OSA_ThrHndl         thrHandleCsock;
    volatile Bool       exitCsockThread;
} CSock_ctrlThrObj ;

CSock_ctrlThrObj gSockObj ;

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/

void msg_process(MessageManager* manager)
{
    Message* msg = NULL ;
    int i = 0 ;
    unsigned short cmd  = 0 ;

    for (i=0; i<manager->cnt; i++)
    {
        msg = get_message(manager, i) ;
        cmd = htons((msg->buff[0]&0xff) | ((msg->buff[1]<<8)&0xff00)) ;

#ifdef NETWORK_DEBUG
      DEBUG_PRI("cmd = 0x%x\n", cmd) ;
#endif
        if (msgfunc[cmd])
        {
            (*msgfunc[cmd])(msg->channel, msg->buff+4, msg->len-4) ;
        }
    }
    zero_message_manager(manager) ;
}

void refresh_message()
{
    msg_process(gMessageManager) ;
}

static Void *csock_thrFxn(Void *prm)
{
    int ControlMainsock ;

    msginit () ;

    CSock_ctrlThrObj *thrObj = (CSock_ctrlThrObj *)prm ;

    gMessageManager = init_message_manager() ;
    zero_message_manager(gMessageManager) ;
    ControlMainsock = MainSocketListen() ;

    gSockObj.exitCsockThread = thrObj->exitCsockThread ;

    while(gSockObj.exitCsockThread == FALSE)
    {
        ProcessSocket(ControlMainsock) ;
        refresh_message() ;
        connect_control() ;
        usleep(SOCKWAIT) ;
    }
    close(ControlMainsock) ;
    release_message_manager(gMessageManager);
    pthread_exit(NULL) ;
}

int CSock_start()
{
    CSock_ctrlThrObj *thrObj = &gSockObj;
    memset(thrObj, 0, sizeof(CSock_ctrlThrObj)) ;

    init_UCX_ST_SET();
    OSA_thrCreate(&thrObj->thrHandleCsock, csock_thrFxn, SOCK_THRFXN_TSK_PRI,0, thrObj);

    return 0;
}

int CSock_stop()
{
    CSock_ctrlThrObj *thrObj = &gSockObj;
    free_UCX_ST_SET();

    thrObj->exitCsockThread = TRUE;
	return 0;
}
