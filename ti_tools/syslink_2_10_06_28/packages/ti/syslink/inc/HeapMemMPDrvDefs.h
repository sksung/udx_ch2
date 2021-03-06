/** 
 *  @file   HeapMemMPDrvDefs.h
 *
 *  @brief      Definitions of HeapMemMPDrv types and structures.
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



#ifndef HEAPMEMMP_DRVDEFS_H_0xb9a8
#define HEAPMEMMP_DRVDEFS_H_0xb9a8


/* Utilities headers */
#include <ti/ipc/HeapMemMP.h>
#include <_HeapMemMP.h>
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
 *  IOCTL command IDs for HeapMemMP
 *  ----------------------------------------------------------------------------
 */
/*!
 *  @brief  Base command ID for HeapMemMP
 */
#define HEAPMEMMP_BASE_CMD                 (0x150)

/*!
 *  @brief  Command for HeapMemMP_getConfig
 */
#define CMD_HEAPMEMMP_GETCONFIG         _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 1u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_setup
 */
#define CMD_HEAPMEMMP_SETUP             _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 2u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_setup
 */
#define CMD_HEAPMEMMP_DESTROY           _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 3u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_destroy
 */
#define CMD_HEAPMEMMP_PARAMS_INIT         _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 4u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_create
 */
#define CMD_HEAPMEMMP_CREATE            _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 5u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_delete
 */
#define CMD_HEAPMEMMP_DELETE            _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 6u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_open
 */
#define CMD_HEAPMEMMP_OPEN              _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 7u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_close
 */
#define CMD_HEAPMEMMP_CLOSE             _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 8u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_alloc
 */
#define CMD_HEAPMEMMP_ALLOC             _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 9u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_free
 */
#define CMD_HEAPMEMMP_FREE              _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 10u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_sharedMemReq
 */
#define CMD_HEAPMEMMP_SHAREDMEMREQ      _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 11u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_getStats
 */
#define CMD_HEAPMEMMP_GETSTATS          _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 12u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_getExtendedStats
 */
#define CMD_HEAPMEMMP_GETEXTENDEDSTATS  _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 13u,\
                                      HeapMemMPDrv_CmdArgs)
/*!
 *  @brief  Command for HeapMemMP_restore
 */
#define CMD_HEAPMEMMP_RESTORE           _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 14u,\
                                      HeapMemMPDrv_CmdArgs)

/*!
 *  @brief  Command for HeapMemMP_openByAddr
 */
#define CMD_HEAPMEMMP_OPENBYADDR       _IOWR(IPCCMDBASE,\
                                      HEAPMEMMP_BASE_CMD + 15u,\
                                      HeapMemMPDrv_CmdArgs)
/*  ----------------------------------------------------------------------------
 *  Command arguments for HeapMemMP
 *  ----------------------------------------------------------------------------
 */
/*!
 *  @brief  Command arguments for HeapMemMP
 */
typedef struct HeapMemMPDrv_CmdArgs {
    union {
        struct {
            HeapMemMP_Params     * params;
        } ParamsInit;

        struct {
            HeapMemMP_Config     * config;
        } getConfig;

        struct {
            HeapMemMP_Config     * config;
        } setup;

        struct {
            Ptr                   handle;
            HeapMemMP_Params      * params;
            UInt32                nameLen;
            SharedRegion_SRPtr    sharedAddrSrPtr;
            SharedRegion_SRPtr    sharedBufSrPtr;
#ifdef SYSLINK_BUILDOS_QNX
            SharedRegion_SRPtr    gateAttrs;
#else
            Ptr                   knlGate;
#endif
        } create;

        struct {
            Ptr                   handle;
        } deleteInstance;

        struct {
            Ptr                   handle;
            String                name;
            UInt32                nameLen;
        } open;

        struct {
            Ptr                   handle;
            SharedRegion_SRPtr    sharedAddrSrPtr;
        } openByAddr;

        struct {
            Ptr                   handle;
        } close;

        struct {
            Ptr                   handle;
            UInt32                size;
            UInt32                align;
            SharedRegion_SRPtr    blockSrPtr;
        } alloc;

        struct {
            Ptr                   handle;
            SharedRegion_SRPtr    blockSrPtr;
            UInt32                size;
        } free;

        struct {
            Ptr                   handle;
            Memory_Stats       *  stats;
        } getStats;

        struct {
            Ptr                   handle;
        } restore;

        struct {
            Ptr                        handle;
            HeapMemMP_ExtendedStats *  stats;
        } getExtendedStats;

        struct {
            HeapMemMP_Params    * params;
            SharedRegion_SRPtr    sharedAddrSrPtr;
            SizeT                 bytes;
        } sharedMemReq;

    } args;

    Int32 apiStatus;
} HeapMemMPDrv_CmdArgs;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* HEAPMEMMP_DRVDEFS_H_0xb9a8 */
