/** ==================================================================
 *  @file   ocp_socket_cm1_cred.h                                                  
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
 *  @Component:   OCP_SOCKET_CM1
 *
 *  @Filename:    ocp_socket_cm1_cred.h
 *
 *  @Description: Component description is not available
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __OCP_SOCKET_CM1_CRED_H
#define __OCP_SOCKET_CM1_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance OCP_SOCKET_CM1 of component OCP_SOCKET_CM1 mapped in MONICA at address 0x4A004000
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
     *  List of Register arrays for component OCP_SOCKET_CM1
     *
     */

    /* 
     *  List of bundle arrays for component OCP_SOCKET_CM1
     *
     */

    /* 
     *  List of bundles for component OCP_SOCKET_CM1
     *
     */

    /* 
     * List of registers for component OCP_SOCKET_CM1
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__REVISION_CM1
 *
 * @BRIEF        This register contains the IP revision code for the CM1 part 
 *               of the PRCM 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__REVISION_CM1                       0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL
 *
 * @BRIEF        This register manages the CM1_PROFILING clock. 
 *               [warm reset insensitive] 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL           0x40ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM1_DEBUG_CFG
 *
 * @BRIEF        This register is used to configure the CM1's 32-bit debug 
 *               output. There is one 7-bit source select field for selecting 
 *               from a shared set of  8-bit internal signal blocks per byte. 
 *               The signals included in each block are specified in the PRCM 
 *               integration specification. 
 *               [warm reset insensitive] 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG                      0xF0ul

    /* 
     * List of register bitfields for component OCP_SOCKET_CM1
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__REVISION_CM1__REV   
 *
 * @BRIEF        IP revision 
 *               [7:4] 
 *               Major revision 
 *               [3:0] 
 *               Minor revision 
 *               Examples: 0x10 for 1.0, 0x21 for 2.1 - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__REVISION_CM1__REV             BITFIELD(7, 0)
#define OCP_SOCKET_CM1__REVISION_CM1__REV__POS        0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST   
 *
 * @BRIEF        Module idle status - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST BITFIELD(17, 16)
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__POS 16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE   
 *
 * @BRIEF        Control the way mandatory clocks are managed. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE BITFIELD(1, 0)
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL3   
 *
 * @BRIEF        Internal signal block select for debug word byte-3 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL3           BITFIELD(30, 24)
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL3__POS      24

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL2   
 *
 * @BRIEF        Internal signal block select for debug word byte-2 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL2           BITFIELD(22, 16)
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL2__POS      16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL1   
 *
 * @BRIEF        Internal signal block select for debug word byte-1 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL1           BITFIELD(14, 8)
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL1__POS      8

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL0   
 *
 * @BRIEF        Internal signal block select for debug word byte-0 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL0           BITFIELD(6, 0)
#define OCP_SOCKET_CM1__CM1_DEBUG_CFG__SEL0__POS      0

    /* 
     * List of register bitfields values for component OCP_SOCKET_CM1
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__FUNC
 *
 * @BRIEF        Module is fully functional - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__FUNC 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__TRANS
 *
 * @BRIEF        Module is performing transition: wakeup, or sleep, or sleep 
 *               abortion - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__TRANS 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__IDLE
 *
 * @BRIEF        Module is in Idle - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__IDLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__DISABLE
 *
 * @BRIEF        Module is disabled - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__IDLEST__DISABLE 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__DISABLED
 *
 * @BRIEF        Module is disabled by SW. OCP configuration port is not 
 *               accessible. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__DISABLED 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__AUTO
 *
 * @BRIEF        Module is managed automatically by HW along with CM1 and EMU 
 *               domain. OCP configuration port is accessible only when EMU 
 *               domain is on. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__AUTO 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__RESERVED_2
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__RESERVED_2 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__RESERVED
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define OCP_SOCKET_CM1__CM_CM1_PROFILING_CLKCTRL__MODULEMODE__RESERVED 0x3ul

#ifdef __cplusplus
}
#endif
#endif                                                     /* __OCP_SOCKET_CM1_CRED_H 
                                                            */
