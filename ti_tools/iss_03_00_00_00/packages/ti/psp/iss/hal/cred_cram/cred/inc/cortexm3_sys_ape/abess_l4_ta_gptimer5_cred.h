/** ==================================================================
 *  @file   abess_l4_ta_gptimer5_cred.h                                                  
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
 *  @Component:   ABESS_L4_TA_GPTIMER5
 *
 *  @Filename:    abess_l4_ta_gptimer5_cred.h
 *
 *  @Description: Component description is not available
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __ABESS_L4_TA_GPTIMER5_CRED_H
#define __ABESS_L4_TA_GPTIMER5_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance ABESS_L4_TA_GPTIMER5 of component ABESS_L4_TA_GPTIMER5 mapped in MONICA at address 0x49002000
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
     *  List of Register arrays for component ABESS_L4_TA_GPTIMER5
     *
     */

    /* 
     *  List of bundle arrays for component ABESS_L4_TA_GPTIMER5
     *
     */

    /* 
     *  List of bundles for component ABESS_L4_TA_GPTIMER5
     *
     */

    /* 
     * List of registers for component ABESS_L4_TA_GPTIMER5
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__COMPONENT
 *
 * @BRIEF        ID of the component 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__COMPONENT                    0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__CORE
 *
 * @BRIEF        ID of the core 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__CORE                         0x18ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL
 *
 * @BRIEF        Core control register for a target agent 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL                0x20ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_STATUS
 *
 * @BRIEF        Core status register for a target agent 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_STATUS                 0x28ul

    /* 
     * List of register bitfields for component ABESS_L4_TA_GPTIMER5
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__COMPONENT__CODE   
 *
 * @BRIEF        Interconnect code - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__COMPONENT__CODE         BITFIELD(31, 16)
#define ABESS_L4_TA_GPTIMER5__COMPONENT__CODE__POS    16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__COMPONENT__REV   
 *
 * @BRIEF        Sonics3220 revision - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__COMPONENT__REV          BITFIELD(15, 0)
#define ABESS_L4_TA_GPTIMER5__COMPONENT__REV__POS     0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__CORE__VENDOR_CODE   
 *
 * @BRIEF        Vendor code - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__CORE__VENDOR_CODE       BITFIELD(47, 32)
#define ABESS_L4_TA_GPTIMER5__CORE__VENDOR_CODE__POS  32

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__CORE__CORE_CODE   
 *
 * @BRIEF        Core code - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__CORE__CORE_CODE         BITFIELD(31, 16)
#define ABESS_L4_TA_GPTIMER5__CORE__CORE_CODE__POS    16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__CORE__REV_CODE   
 *
 * @BRIEF        Revision code - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__CORE__REV_CODE          BITFIELD(15, 0)
#define ABESS_L4_TA_GPTIMER5__CORE__REV_CODE__POS     0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__EXT_CLOCK   
 *
 * @BRIEF        External clock control - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__EXT_CLOCK BITFIELD(40, 40)
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__EXT_CLOCK__POS 40

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__SERROR_REP   
 *
 * @BRIEF        SError reporting control - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__SERROR_REP BITFIELD(24, 24)
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__SERROR_REP__POS 24

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT   
 *
 * @BRIEF        Request timeout - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT BITFIELD(10, 8)
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__POS 8

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__OCP_RESET   
 *
 * @BRIEF        Reset OCP interface - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__OCP_RESET BITFIELD(0, 0)
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__OCP_RESET__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_STATUS__SERROR   
 *
 * @BRIEF        Value of OCP SError signal - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_STATUS__SERROR    BITFIELD(24, 24)
#define ABESS_L4_TA_GPTIMER5__AGENT_STATUS__SERROR__POS 24

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_STATUS__REQ_TIMEOUT   
 *
 * @BRIEF        Monitor timed-out requests - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_STATUS__REQ_TIMEOUT BITFIELD(8, 8)
#define ABESS_L4_TA_GPTIMER5__AGENT_STATUS__REQ_TIMEOUT__POS 8

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_STATUS__OCP_RESET   
 *
 * @BRIEF        Bitfield description is not available - (RO)
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_STATUS__OCP_RESET BITFIELD(0, 0)
#define ABESS_L4_TA_GPTIMER5__AGENT_STATUS__OCP_RESET__POS 0

    /* 
     * List of register bitfields values for component ABESS_L4_TA_GPTIMER5
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_0
 *
 * @BRIEF        no timeout - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_0 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_1
 *
 * @BRIEF        1x base cycles - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_1 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_2
 *
 * @BRIEF        4x base cycles - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_2 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_3
 *
 * @BRIEF        16x base cycles - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_3 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_4
 *
 * @BRIEF        64x base cycles - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ABESS_L4_TA_GPTIMER5__AGENT_CONTROL__REQ_TIMEOUT__TA_AGENT_CONTROL_REQ_TIMEOUT_4 0x4ul

#ifdef __cplusplus
}
#endif
#endif                                                     /* __ABESS_L4_TA_GPTIMER5_CRED_H 
                                                            */
