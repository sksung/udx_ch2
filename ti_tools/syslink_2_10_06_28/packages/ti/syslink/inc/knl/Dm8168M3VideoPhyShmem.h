/** 
 *  @file   Dm8168M3VideoPhyShmem.h
 *
 *  @brief      Physical Interface Abstraction Layer for DM8168VIDEOM3.
 *
 *              This file contains the definitions for shared memory physical
 *              link being used with DM8168VIDEOM3.
 *              The implementation is specific to DM8168VIDEOM3.
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


#ifndef DM8168VIDEOM3PHYSHMEM_H_0xbbed
#define DM8168VIDEOM3PHYSHMEM_H_0xbbed


/* Module level headers */
#include <_ProcDefs.h>


#if defined (__cplusplus)
extern "C" {
#endif


/* =============================================================================
 *  Macros and types
 *  See _ProcDefs.h
 * =============================================================================
 */
/*!
 *  @brief  Base addresses of L2_RAM for Ducati.
 */
#define GENERAL_CONTROL_BASE   0x55020000

#define VIDEOM3_BOOT_ADDR       (GENERAL_CONTROL_BASE + 0x4)

#define VIDEOM3_BOOT_ADDR_SIZE  0x4
/*!
 *  @brief  Base addresses of PRCM module.
 */
#define PRCM_BASE_ADDR         0x48180000
/*!
 *  @brief  Base addresses of different peripherals.
 */

#define PRCM_SIZE              0x00002FFF


/* =============================================================================
 *  APIs
 * =============================================================================
 */
/* Initializes Shared Driver/device. */
Int DM8168VIDEOM3_phyShmemInit (Ptr halObj);

/* Finalizes Shared Driver/device. */
Int DM8168VIDEOM3_phyShmemExit (Ptr halObj);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif /* dm8168_phy_shmem_H_0xbbec */
