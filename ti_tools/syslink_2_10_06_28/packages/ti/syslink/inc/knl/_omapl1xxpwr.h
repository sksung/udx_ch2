/** 
 *  @file   _omapl1xxpwr.h
 *
 *  @brief      Internal header for Power Manager interface for omapl1xxdsp.
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



#ifndef _OMAPL1XXPWR_H_0xa860
#define _OMAPL1XXPWR_H_0xa860


/* Module level headers */
#include <PwrDefs.h>
#include <ti/syslink/ProcMgr.h>


#if defined (__cplusplus)
extern "C" {
#endif


/* =============================================================================
 *  Macros and types
 *  See PwrDefs.h and omapl1xxpwr.h
 * =============================================================================
 */


/* =============================================================================
 *  Internal functions accessed through function table
 * =============================================================================
 */
/* Function to attach to the PwrMgr. */
Int OMAPL1XXPWR_attach (PwrMgr_Handle handle, PwrMgr_AttachParams * params);

/* Function to detach from the PwrMgr. */
Int OMAPL1XXPWR_detach (PwrMgr_Handle handle);

/* Function to power on the slave processor. */
Int OMAPL1XXPWR_on (PwrMgr_Handle handle);

/* Function to power off the slave processor. */
Int OMAPL1XXPWR_off (PwrMgr_Handle handle, Bool force);

/* TBD: Other functions. */


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif /* _OMAPL1XXPWR_H_0xa860 */
