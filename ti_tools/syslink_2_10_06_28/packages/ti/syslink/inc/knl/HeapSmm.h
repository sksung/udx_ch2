/** 
 *  @file   HeapSmm.h
 *
 *  @brief      Cache line sized memory manager.
 *
 *              This module manages an shared region entry by providing
 *              application/modules to allocate/de-allocate memory. It requires
 *              one entry in the shared region to be reserved for it.
 *              CReator of this module should allocate required amount of memory
 *              either from SysMemMgr or from some other resource and passed to
 *              it.<br>
 *              Allocation and de-allocation is done through buddy page
 *              allocator with page size defined as cache line size. since the
 *              main purpose of this module is to allocate memory for sharing it
 *              with slave processors. It provides functionality such as
 *              @li allocate memory chunks
 *              @li de-allocate memory chunks
 *              @li getSRPtr for an address
 *              @li getPtr from a SRPtr.
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



#ifndef HEAPSMM_H_0X5711
#define HEAPSMM_H_0X5711


/* Module level headers */
#include <ti/ipc/SharedRegion.h>
#include <BuddyPageAllocator.h>


#if defined (__cplusplus)
extern "C" {
#endif


/*!
 *  @def    HEAPSMM_MODULEID
 *  @brief  Unique module ID.
 */
#define HEAPSMM_MODULEID      (0x5711)

/*!
 *  @def    SMM_STATUSCODEBASE
 *  @brief  Error code base for SMM.
 */
#define HEAPSMM_STATUSCODEBASE      (HEAPSMM_MODULEID << 12u)

/*!
 *  @def    SMM_MAKE_FAILURE
 *  @brief  Macro to make error code.
 */
#define HEAPSMM_MAKE_FAILURE(x)    ((Int)(  0x80000000                         \
                                          + (HEAPSMM_STATUSCODEBASE            \
                                          + (x))))

/*!
 *  @def    HEAPSMM_MAKE_SUCCESS
 *  @brief  Macro to make success code.
 */
#define HEAPSMM_MAKE_SUCCESS(x)    (HEAPSMM_STATUSCODEBASE + (x))

/*!
 *  @def    HEAPSMM_E_INVALIDARG
 *  @brief  Argument passed to a function is invalid.
 */
#define HEAPSMM_E_INVALIDARG       HEAPSMM_MAKE_FAILURE(1)

/*!
 *  @def    HEAPSMM_E_MEMORY
 *  @brief  Memory allocation failed.
 */
#define HEAPSMM_E_MEMORY           HEAPSMM_MAKE_FAILURE(2)

/*!
 *  @def    HEAPSMM_E_BUSY
 *  @brief  the name is already registered or not.
 */
#define HEAPSMM_E_BUSY             HEAPSMM_MAKE_FAILURE(3)

/*!
 *  @def    HEAPSMM_E_FAIL
 *  @brief  Generic failure.
 */
#define HEAPSMM_E_FAIL             HEAPSMM_MAKE_FAILURE(4)

/*!
 *  @def    HEAPSMM_E_NOTFOUND
 *  @brief  name not found in the SharedRegion.
 */
#define HEAPSMM_E_NOTFOUND         HEAPSMM_MAKE_FAILURE(4)

/*!
 *  @def    HEAPSMM_E_ALREADYEXIST
 *  @brief  Entry already exists.
 */
#define HEAPSMM_E_ALREADYEXIST     HEAPSMM_MAKE_FAILURE(5)

/*!
 *  @def    HEAPSMM_E_INVALIDSTATE
 *  @brief  Module is in invalid state.
 */
#define HEAPSMM_E_INVALIDSTATE     HEAPSMM_MAKE_FAILURE(6)

/*!
 *  @def    HEAPHEAPSMM_E_OVERLAP
 *  @brief  Entries overlaps.
 */
#define HEAPSMM_E_OVERLAP          HEAPSMM_MAKE_FAILURE(7)

/*!
 *  @def    HEAPSMM_SUCCESS
 *  @brief  Operation successful.
 */
#define HEAPSMM_SUCCESS            HEAPSMM_MAKE_SUCCESS(0)


/*!
 *  @brief  Module configuration structure.
 */
typedef struct HeapSmm_Config {
    UInt32  srIndex;       /*!< Shared region entry index */
    UInt32  vBaseAddress;  /*!< Virtual address of memory block */
    UInt32  pBaseAddress;  /*!< Physical address of memory block */
    UInt32  size;          /*!< Size of the shared region */
    UInt32  cacheSize;     /*!< Size of cache line */
} HeapSmm_Config;


/* Function to get the current configuration values. */
Int HeapSmm_getConfig (HeapSmm_Config * config);
/* Function to setup the SMM. */
Int HeapSmm_setup (HeapSmm_Config * config);
/* Function to destroy the SMM. */
Int HeapSmm_destroy (void);
/* Function to allocate memory from SMM.*/
Ptr HeapSmm_alloc (UInt32 size);
/* Function to de-allocate memory to SMM. */
Int HeapSmm_free (Ptr buf, UInt32 size);
/* Function to get a SRPtr for the address. */
SharedRegion_SRPtr HeapSmm_getSRPtr (Ptr addr);
/* Function to get a ptr from SRPtr. */
Ptr HeapSmm_getPtr (SharedRegion_SRPtr srPtr);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* HEAPSMM_H */
