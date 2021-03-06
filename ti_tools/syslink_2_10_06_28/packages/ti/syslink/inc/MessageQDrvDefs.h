/** 
 *  @file   MessageQDrvDefs.h
 *
 *  @brief      Definitions of MessageQDrv types and structures.
 *
 *
 */
/* 
 *  ============================================================================
 *
 *  Copyright (c) 2008-2012, Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  Contact information for paper mail:
 *  Texas Instruments
 *  Post Office Box 655303
 *  Dallas, Texas 75265
 *  Contact information: 
 *  http://www-k.ext.ti.com/sc/technical-support/product-information-centers.htm?
 *  DCMP=TIHomeTracking&HQS=Other+OT+home_d_contact
 *  ============================================================================
 *  
 */



#ifndef MESSAGEQ_DRVDEFS_H_0xf653
#define MESSAGEQ_DRVDEFS_H_0xf653


/* Osal and utils headers */

/* Module headers */
#include <ti/ipc/MessageQ.h>
#include <_MessageQ.h>
#include <ti/syslink/utils/IHeap.h>
#include <ti/ipc/SharedRegion.h>
#include <IpcCmdBase.h>
#include <ti/syslink/inc/IoctlDefs.h>

#if defined (__cplusplus)
extern "C" {
#endif


/* =============================================================================
 *  Macros and types
 * =============================================================================
 */
/*  ----------------------------------------------------------------------------
 *  IOCTL command IDs for MessageQ
 *  ----------------------------------------------------------------------------
 */
/*!
 *  @brief  Base command ID for MessageQ
 */
#define MESSAGEQ_BASE_CMD                 0x150

/*!
 *  @brief  Command for MessageQ_getConfig
 */
#define CMD_MESSAGEQ_GETCONFIG              _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 1u,\
                                            MessageQDrv_CmdArgs)


/*!
 *  @brief  Command for MessageQ_setup
 */
#define CMD_MESSAGEQ_SETUP                  _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 2u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_setup
 */
#define CMD_MESSAGEQ_DESTROY                _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 3u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_destroy
 */
#define CMD_MESSAGEQ_PARAMS_INIT            _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 4u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_create
 */
#define CMD_MESSAGEQ_CREATE                 _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 5u,\
                                            MessageQDrv_CmdArgs)

/*!
 *  @brief  Command for MessageQ_delete
 */
#define CMD_MESSAGEQ_DELETE                 _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 6u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_open
 */
#define CMD_MESSAGEQ_OPEN                   _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 7u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_close
 */
#define CMD_MESSAGEQ_CLOSE                  _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 8u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_count
 */
#define CMD_MESSAGEQ_COUNT                  _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 9u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_alloc
 */
#define CMD_MESSAGEQ_ALLOC                  _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 10u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_free
 */
#define CMD_MESSAGEQ_FREE                   _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 11u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_put
 */
#define CMD_MESSAGEQ_PUT                    _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 12u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_registerHeap
 */
#define CMD_MESSAGEQ_REGISTERHEAP           _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 13u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_unregisterHeap
 */
#define CMD_MESSAGEQ_UNREGISTERHEAP         _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 14u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_attach
 */
#define CMD_MESSAGEQ_ATTACH                 _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 15u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_detach
 */
#define CMD_MESSAGEQ_DETACH                 _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 16u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_get
 */
#define CMD_MESSAGEQ_GET                    _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 17u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_sharedMemReq
 */
#define CMD_MESSAGEQ_SHAREDMEMREQ           _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 18u,\
                                            MessageQDrv_CmdArgs)
/*!
 *  @brief  Command for MessageQ_unblock
 */
#define CMD_MESSAGEQ_UNBLOCK                _IOWR(IPCCMDBASE,\
                                            MESSAGEQ_BASE_CMD + 19u,\
                                            MessageQDrv_CmdArgs)

/*  ----------------------------------------------------------------------------
 *  Command arguments for MessageQ
 *  ----------------------------------------------------------------------------
 */
/*!
 *  @brief  Command arguments for MessageQ
 */
typedef struct MessageQDrv_CmdArgs_Tag {
    union {
        struct {
            Ptr                   handle;
            MessageQ_Params     * params;
        } ParamsInit;

        struct {
            MessageQ_Config     * config;
        } getConfig;

        struct {
            MessageQ_Config     * config;
        } setup;

        struct {
            Ptr                   handle;
            String                name;
            MessageQ_Params     * params;
            UInt32                nameLen;
            MessageQ_QueueId      queueId;
        } create;

        struct {
            Ptr                  handle;
        } deleteMessageQ;

        struct {
            String               name;
            MessageQ_QueueId     queueId;
            UInt32               nameLen;
        } open;

        struct {
            MessageQ_QueueId     queueId;
        } close;

        struct {
            Ptr                   handle;
            UInt                  timeout;
            SharedRegion_SRPtr    msgSrPtr;
        } get;

        struct {
            Ptr                   handle;
            Int                   count;
        } count;

        struct {
            UInt16                heapId;
            UInt32                size;
            SharedRegion_SRPtr    msgSrPtr;
        } alloc;

        struct {
            SharedRegion_SRPtr    msgSrPtr;
        } free;

        struct {
            MessageQ_QueueId      queueId;
            SharedRegion_SRPtr    msgSrPtr;
        } put;

        struct {
            IHeap_Handle          heap;
            UInt16                heapId;
        } registerHeap;

        struct {
            UInt16                heapId;
        } unregisterHeap;

        struct {
            SharedRegion_SRPtr    sharedAddrSrPtr;
            SizeT                 memReq;
        } sharedMemReq;

        struct {
            UInt16                remoteProcId;
            SharedRegion_SRPtr    sharedAddrSrPtr;
        } attach;

        struct {
            UInt16                remoteProcId;
        } detach;

        struct {
            Ptr                   handle;
        } unblock;
    } args;

    Int32 apiStatus;
} MessageQDrv_CmdArgs;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* MESSAGEQ_DRVDEFS_H_0xf653 */
