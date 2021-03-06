/** 
 *  @file   CacheDrvDefs.h
 *
 *  @brief      Definitions of CacheDrv types and structures.
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



#ifndef __CACHE_DRV_DEFS_H__
#define __CACHE_DRV_DEFS_H__


#include <UtilsCmdBase.h>
#include <ti/syslink/inc/IoctlDefs.h>

#if defined (__cplusplus)
extern "C" {
#endif


/* =============================================================================
 *  Macros and types
 * =============================================================================
 */
/*  ----------------------------------------------------------------------------
 *  IOCTL command IDs for Cache
 *  ----------------------------------------------------------------------------
 */
/*!
 *    @brief    Base command ID for Cache
 */
#define CACHE_BASE_CMD                 0x130

/*!
 *    @brief    Command for Cache_inv
 */
#define CMD_CACHE_INV                   _IOWR(UTILSCMDBASE,\
                                            CACHE_BASE_CMD + 1u,\
                                            CacheDrv_CmdArgs)
/*!
 *    @brief    Command for Cache_wb
 */
#define CMD_CACHE_WB                    _IOWR(UTILSCMDBASE,\
                                            CACHE_BASE_CMD + 2u,\
                                            CacheDrv_CmdArgs)
/*!
 *    @brief    Command for Cache_wbinv
 */
#define CMD_CACHE_WBINV                 _IOWR(UTILSCMDBASE,\
                                            CACHE_BASE_CMD + 3u,\
                                            CacheDrv_CmdArgs)
/*!
 *    @brief    Command for Cache_wait
 */
#define CMD_CACHE_WAIT                 _IOWR(UTILSCMDBASE,\
                                            CACHE_BASE_CMD + 4u,\
                                            CacheDrv_CmdArgs)
/*!
 *    @brief    Command for Cache_setMode
 */
#define CMD_CACHE_SETMODE              _IOWR(UTILSCMDBASE,\
                                            CACHE_BASE_CMD + 5u,\
                                            CacheDrv_CmdArgs)

/*  ----------------------------------------------------------------------------
 *  Command arguments for Cache
 *  ----------------------------------------------------------------------------
 */
/*!
 *  @brief  Command arguments for Cache
 */
typedef struct CacheDrv_CmdArgs {
    Int32 apiStatus;

    union {
        struct {
            Ptr blockPtr;
            /*!< Block Pointer. */
            UInt32 byteCnt;
            /*!< Byte Count. */
            Bits16 type;
            /*!< Type. */
            Bool wait;
            /*!< wait flag. */
        } inv;

        struct {
            Ptr blockPtr;
            /*!< Block Pointer. */
            UInt32 byteCnt;
            /*!< Byte Count. */
            Bits16 type;
            /*!< Type. */
            Bool wait;
            /*!< wait flag. */
        } wb;

        struct {
            Ptr blockPtr;
            /*!< Block Pointer. */
            UInt32 byteCnt;
            /*!< Byte Count. */
            Bits16 type;
            /*!< Type. */
            Bool wait;
            /*!< wait flag. */
        } wbinv;

        struct {
            Bits16 type;
            /*!< Type. */
            enum Cache_Mode mode;
            /*!< cache mode. */
        } setmode;

        struct {
            Bits16 dummy;
            /* None dummy*/
        } wait;

    } args;
} CacheDrv_CmdArgs;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* __CACHE_DRV_DEFS_H__ */
