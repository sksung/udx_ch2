/** ==================================================================
 *  @file   icont_imem_cred.h                                                  
 *                                                                    
 *  @path   /ti/psp/iss/hal/cred_cram/cred/inc/cortexm3_sys_ape/                                                  
 *                                                                    
 *  @desc   This  File contains.                                      
 * ===================================================================
 *  Copyright (c) Texas Instruments Inc 2011, 2012                    
 *                                                                    
 *  Use of this software is controlled by the terms and conditions found
 *  in the license agreement under which this software has been supplied
 * ===================================================================*/

/* ============================================================================ 
 * TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION Property of Texas
 * Instruments For Unrestricted Internal Use Only Unauthorized reproduction
 * and/or distribution is strictly prohibited.  This product is protected
 * under copyright law and trade secret law as an unpublished work.  Created
 * 2008, (C) Copyright 2008 Texas Instruments.  All rights reserved. */

/**
 *  @Component:   ICONT_IMEM
 *
 *  @Filename:    icont_imem_cred.h
 *
 *  @Description: ICONT Instruction Tightly Coupled Memory 
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __ICONT_IMEM_CRED_H
#define __ICONT_IMEM_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance ICONT1_IMEM of component ICONT_IMEM mapped in MONICA at address 0x5A008000
     * Instance ICONT2_IMEM of component ICONT_IMEM mapped in MONICA at address 0x5A018000
     */

                                                                              /*-------------------------------------------------------------------------*//**
 * @DEFINITION   BITFIELD
 *
 * @BRIEF        The bitfield must be defined according to register width
 *               of the component - 64/32/16/8
 *
    *//*------------------------------------------------------------------------ */
#undef BITFIELD
#define BITFIELD BITFIELD_32

    /* 
     *  List of Register arrays for component ICONT_IMEM
     *
     */

    /* 
     *  List of bundle arrays for component ICONT_IMEM
     *
     */

    /* 
     *  List of bundles for component ICONT_IMEM
     *
     */

    /* 
     * List of registers for component ICONT_IMEM
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_IMEM__ICONT_IMEM_START
 *
 * @BRIEF        ITCM start memory location 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_IMEM__ICONT_IMEM_START                       0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_IMEM__ICONT_IMEM_END
 *
 * @BRIEF        ITCM end memory location 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_IMEM__ICONT_IMEM_END                         0x7FFCul

    /* 
     * List of register bitfields for component ICONT_IMEM
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_IMEM__ICONT_IMEM_START__MEM   
 *
 * @BRIEF        Bitfield description is not available - (RW)
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_IMEM__ICONT_IMEM_START__MEM             BITFIELD(31, 0)
#define ICONT_IMEM__ICONT_IMEM_START__MEM__POS        0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_IMEM__ICONT_IMEM_END__MEM   
 *
 * @BRIEF        Bitfield description is not available - (RW)
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_IMEM__ICONT_IMEM_END__MEM               BITFIELD(31, 0)
#define ICONT_IMEM__ICONT_IMEM_END__MEM__POS          0

    /* 
     * List of register bitfields values for component ICONT_IMEM
     *
     */

#ifdef __cplusplus
}
#endif
#endif                                                     /* __ICONT_IMEM_CRED_H 
                                                            */
