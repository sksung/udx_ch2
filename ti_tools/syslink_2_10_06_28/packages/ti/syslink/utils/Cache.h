/** 
 *  @file   Cache.h
 *
 *  @brief      Defines Cache API interface.
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



#ifndef CACHE_H
#define CACHE_H


#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */

/* =============================================================================
 *  All success and failure codes for the module
 * =============================================================================
 */

/*!
 *  @def    Cache_S_SUCCESS
 *  @brief  Operation is successful.
 */
#define Cache_S_SUCCESS              0

/*!
 *  @def    Cache_E_FAIL
 *  @brief  Generic failure.
 */
#define Cache_E_FAIL                -1


/* ================================
 *  Enums for the module
 * ================================
 */
/*! Lists of bitmask cache types */
enum Cache_Type {
    Cache_Type_L1P = 0x1,         /*! Level 1 Program cache */
    Cache_Type_L1D = 0x2,         /*! Level 1 Data cache */
    Cache_Type_L1  = 0x3,         /*! Level 1 caches */
    Cache_Type_L2P = 0x4,         /*! Level 2 Program cache */
    Cache_Type_L2D = 0x8,         /*! Level 2 Data cache */
    Cache_Type_L2  = 0xC,         /*! Level 2 caches */
    Cache_Type_ALL = 0xffff       /*! All caches */
};

/*! Lists of cache modes */
enum Cache_Mode {
    Cache_Mode_FREEZE,
    Cache_Mode_BYPASS,
    Cache_Mode_NORMAL
};

/*!
 *  @brief      Invalidate the Cache module.
 *
 *  @sa         Cache_inv
 */
Void Cache_inv(Ptr blockPtr, UInt32 byteCnt, Bits16 type, Bool wait);

/*!
 *  @brief      Writeback the Cache module.
 *
 *  @sa         Cache_wb
 */
Void Cache_wb(Ptr blockPtr, UInt32 byteCnt, Bits16 type, Bool wait);

/*!
 *  @brief      Write Back and Invalidate the Cache module.
 *
 *  @sa         Cache_wbInv
 */
Void Cache_wbInv(Ptr blockPtr, UInt32 byteCnt, Bits16 type, Bool wait);

/*!
 *  @brief      Wait for cache operation to complete.
 *
 *  @sa         Cache_wait
 */
Void Cache_wait(Void);

/*!
 *  @brief      Set the mode of Cache module.
 *
 *  @sa         Cache_setMode
 */
enum Cache_Mode Cache_setMode(Bits16 type, enum Cache_Mode mode);

#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* CACHE_H */
