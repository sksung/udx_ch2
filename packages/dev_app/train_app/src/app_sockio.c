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
#include <errno.h>

#include <osa.h>
#include <osa_mutex.h>
#include <osa_thr.h>
#include <osa_pipe.h>

#include "app_message.h"
#include "app_msghandler.h"
#include "app_rawsock.h"
#include "app_process.h"
#include "app_sockio.h"
#include "app_fcommand.h"
#include "app_set.h"

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/

#define SOCKWAIT                5
#define SOCK_THRFXN_TSK_PRI     (3)
#define UDP_PORT                8402

static app_dtcObj dtc_obj ;
static app_dtcObj *d_obj = &dtc_obj ;


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

static Void *mainsock_thrFxn(Void *prm)
{
    int ControlMainsock ;

    msginit () ;

    app_nthr_obj *thrObj = &d_obj->gSockObj ;

    gMessageManager = init_message_manager() ;
    zero_message_manager(gMessageManager) ;
    ControlMainsock = MainSocketListen() ;

    while(thrObj->exitsockThread == FALSE)
    {
        ProcessSocket(ControlMainsock) ;
        refresh_message() ;
        connect_control() ;
        OSA_waitMsecs(SOCKWAIT) ;
    }
    close(ControlMainsock) ;
    release_message_manager(gMessageManager);
    pthread_exit(NULL) ;
}


int create_udpsock(int udp_sock)
{
    struct sockaddr_in addr ;

    if(udp_sock == SOCK_ERROR)
    {
        udp_sock = socket(PF_INET, SOCK_DGRAM, 0) ;

        memset(&addr, 0, sizeof(addr)) ;
        addr.sin_family = AF_INET ;
        addr.sin_addr.s_addr=htonl(INADDR_ANY) ;
        addr.sin_port= htons(UDP_PORT) ;
    }

    if(udp_sock != SOCK_ERROR)
    {     
        if(bind(udp_sock, (struct sockaddr*)&addr, sizeof(addr)) == SOCK_ERROR)
        {
            printf("binding error ...!! \n") ;
            udp_sock = SOCK_ERROR ;
        }
    }
    
    return udp_sock ;
}

int parse_udpsock(char *data)
{
    LOCATION_REQ *Locationreq ;
    LOCATION_RES Locationres ;
    
    Locationreq = (LOCATION_REQ *)data ;

    if(ntohs(Locationreq->cmd) == CMD_LOCATION_REQ)
    {
        printf("Locationreq->identifier = %x\n",ntohs(Locationreq->identifier)) ;
        return TRUE ;
    }
    else
        return FALSE ; 

}


int process_udpsock(int udp_sock)
{
    LOCATION_RES Locationres ;
    struct sockaddr_in client_addr ;

    int  client_addr_size, recv_len, binded_sock, sendlen = 0 ;
    
    char recvbuff[CHAR_8] ;   
    char sendbuff[CHAR_128] ;   

    if(udp_sock == SOCK_ERROR)
    {
        udp_sock = create_udpsock(udp_sock) ;
    }
    if(udp_sock != SOCK_ERROR)
    {
        client_addr_size = sizeof(client_addr) ;
        recv_len = recvfrom(udp_sock, recvbuff, 20, 0, (struct sockaddr*)&client_addr, &client_addr_size) ;
        
        if(recv_len > 0)
        {
            printf("recv_len = %d sockfd = %d\n",recv_len, udp_sock) ;
            if(parse_udpsock(recvbuff))
            {
                Locationres.identifier = htons(IDENTIFIER);
                Locationres.cmd = htons(CMD_LOCATION_RES);
                Locationres.length = htons(sizeof(LOCATION_RES));
                Locationres.port = htons(8551);
                sprintf(Locationres.ipaddress,"%s",app_set->srv_info.ipaddr) ;
                sprintf(Locationres.deviceID, "%s",app_set->srv_info.deviceID) ;

                memcpy(sendbuff, &Locationres, sizeof(LOCATION_RES)) ;

                sendlen = sendto(udp_sock, &sendbuff, sizeof(LOCATION_RES), 0, (struct sockaddr*)&client_addr, sizeof(client_addr)) ; 
                if(sendlen == SOCK_ERROR)
                { 
                    printf("errno = %d\n",errno) ;
                }
                else
                {
                    printf("Locationres sendlen = %d\n",sendlen) ;
                }
                close(udp_sock) ; 
                udp_sock = SOCK_ERROR ;
                    
            }
        }
    }
    return udp_sock ;
}


static Void *csock_thrFxn(Void *prm)
{
    int UdpMainsock = SOCK_ERROR; 
    app_nthr_obj *thrObj = &d_obj->gControlSockObj ;

    while(thrObj->exitsockThread == FALSE)
    {
        UdpMainsock = process_udpsock(UdpMainsock) ;
 
        OSA_waitMsecs(SOCKWAIT) ;
    }
    close(UdpMainsock) ;
    pthread_exit(NULL) ;
}


int Sock_start(void)
{
    app_nthr_obj *thrObj ;

    thrObj = &d_obj->gSockObj ;
    thrObj->exitsockThread = FALSE ;

    OSA_semCreate(&thrObj->sem, MAX_PENDING_SEM_COUNT, 0);
    OSA_thrCreate(&thrObj->thr, mainsock_thrFxn, SOCK_THRFXN_TSK_PRI,0, thrObj);
    OSA_mutexCreate(&thrObj->mutex);
/*
    thrObj = &d_obj->gControlSockObj ;
    thrObj->exitsockThread = FALSE ;

    OSA_semCreate(&thrObj->sem, MAX_PENDING_SEM_COUNT, 0);
    OSA_thrCreate(&thrObj->thr, csock_thrFxn, SOCK_THRFXN_TSK_PRI,0, thrObj);
    OSA_mutexCreate(&thrObj->mutex);
*/
    init_UCX_ST_SET();
    printf(" %s done!\n",__func__) ;    

    return 0;
}

int Sock_stop()
{
    app_nthr_obj *thrObj ;

    free_UCX_ST_SET();

    thrObj = &d_obj->gSockObj ;
    thrObj->exitsockThread = TRUE ;
    OSA_semDelete(&thrObj->sem);
    OSA_thrDelete(&thrObj->thr);
    OSA_mutexDelete(&thrObj->mutex);
/*
    thrObj = &d_obj->gControlSockObj ;
    thrObj->exitsockThread = TRUE ;
    OSA_semDelete(&thrObj->sem);
    OSA_thrDelete(&thrObj->thr);
    OSA_mutexDelete(&thrObj->mutex);
*/
    return 0;
}
