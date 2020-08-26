/** ==================================================================
 *  @file   abess_l4_ia_ip0_cred.h                                                  
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
 *  @Component:   ABESS_L4_IA_IP0
 *
 *  @Filename:    abess_l4_ia_ip0_cred.h
 *
 *  @Description: Component description is not available
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __ABESS_L4_IA_IP0_CRED_H
#define __ABESS_L4_IA_IP0_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance ABESS_L4_IA_IP0 of component ABESS_L4_IA_IP0 mapped in MONICA at address 0x49000400
     */

                                                                              /*-------------------------------------------------------------------------*//**
 * @DEFINITION   BITFIELD
 *
 * @BRIEF        The bitfield must be defined according to register width
 *               of the component - 64/32/16/8
 *
    *//*------------------------------------------------------------------------ */
#undef BITFIELD
#define BITFIELD BITFIELD_64

    /* 
     *  List of Register arrays for component ABESS_L4_IA_IP0
     *
     */

    /* 
     *  List of bundle arrays for component ABESS_L4_IA_IP0
     *
     */

    /* 
     *  List of bundles for component ABESS_L4_IA_IP0
     *
     */

    /* 
     * List of registers for component ABESS_L4_IA_IP0
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__COMPONENT
 *
 * @BRIEF        ID of the component 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__COMPONENT                         0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__CORE
 *
 * @BRIEF        ID of the core 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__CORE                              0x18ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_CONTROL
 *
 * @BRIEF        Core control for an initiator OCP interface 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_CONTROL                     0x20ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_STATUS
 *
 * @BRIEF        Core status for an initiator OCP interface 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_STATUS                      0x28ul

    /* 
     * List of register bitfields for component ABESS_L4_IA_IP0
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__COMPONENT__CODE   
 *
 * @BRIEF        Interconnect code - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__COMPONENT__CODE              BITFIELD(31, 16)
#define ABESS_L4_IA_IP0__COMPONENT__CODE__POS         16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__COMPONENT__REV   
 *
 * @BRIEF        Sonics3220 revision - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__COMPONENT__REV               BITFIELD(15, 0)
#define ABESS_L4_IA_IP0__COMPONENT__REV__POS          0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__CORE__VENDOR_CODE   
 *
 * @BRIEF        Vendor code - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__CORE__VENDOR_CODE            BITFIELD(47, 32)
#define ABESS_L4_IA_IP0__CORE__VENDOR_CODE__POS       32

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__CORE__CORE_CODE   
 *
 * @BRIEF        Core code - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__CORE__CORE_CODE              BITFIELD(31, 16)
#define ABESS_L4_IA_IP0__CORE__CORE_CODE__POS         16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__CORE__REV_CODE   
 *
 * @BRIEF        Revision code - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__CORE__REV_CODE               BITFIELD(15, 0)
#define ABESS_L4_IA_IP0__CORE__REV_CODE__POS          0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_CONTROL__PROT_ERROR_SECONDARY_REP   
 *
 * @BRIEF        Out-of-band reporting of protection mechanism secondary 
 *               errors - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_CONTROL__PROT_ERROR_SECONDARY_REP BITFIELD(31, 31)
#define ABESS_L4_IA_IP0__AGENT_CONTROL__PROT_ERROR_SECONDARY_REP__POS 31

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_CONTROL__PROT_ERROR_PRIMARY_REP   
 *
 * @BRIEF        Out-of-band reporting of protection mechanism primary errors 
 *               - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_CONTROL__PROT_ERROR_PRIMARY_REP BITFIELD(30, 30)
#define ABESS_L4_IA_IP0__AGENT_CONTROL__PROT_ERROR_PRIMARY_REP__POS 30

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_CONTROL__INBAND_ERROR_REP   
 *
 * @BRIEF        Reporting of errors - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_CONTROL__INBAND_ERROR_REP BITFIELD(27, 27)
#define ABESS_L4_IA_IP0__AGENT_CONTROL__INBAND_ERROR_REP__POS 27

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_CONTROL__MERROR_REP   
 *
 * @BRIEF        OCP MError reporting control - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_CONTROL__MERROR_REP    BITFIELD(24, 24)
#define ABESS_L4_IA_IP0__AGENT_CONTROL__MERROR_REP__POS 24

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_STATUS__PROT_ERROR_SECONDARY   
 *
 * @BRIEF        Protection error status. MErrorSteer indicates a secondary 
 *               error. - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_STATUS__PROT_ERROR_SECONDARY BITFIELD(31, 31)
#define ABESS_L4_IA_IP0__AGENT_STATUS__PROT_ERROR_SECONDARY__POS 31

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_STATUS__PROT_ERROR_PRIMARY   
 *
 * @BRIEF        Protection error status. MErrorSteer indicates a primary 
 *               error (or is not enabled). - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_STATUS__PROT_ERROR_PRIMARY BITFIELD(30, 30)
#define ABESS_L4_IA_IP0__AGENT_STATUS__PROT_ERROR_PRIMARY__POS 30

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_STATUS__INBAND_ERROR   
 *
 * @BRIEF        Error status - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_STATUS__INBAND_ERROR   BITFIELD(27, 27)
#define ABESS_L4_IA_IP0__AGENT_STATUS__INBAND_ERROR__POS 27

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_IA_IP0__AGENT_STATUS__MERROR   
 *
 * @BRIEF        Value of the OCP MError signal - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_IA_IP0__AGENT_STATUS__MERROR         BITFIELD(24, 24)
#define ABESS_L4_IA_IP0__AGENT_STATUS__MERROR__POS    24

    /* 
     * List of register bitfields values for component ABESS_L4_IA_IP0
     *
     */

#ifdef __cplusplus
}
#endif
#endif                                                     /* __ABESS_L4_IA_IP0_CRED_H 
                                                            */
