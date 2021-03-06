/** ==================================================================
 *  @file   always_on_cm2_cred.h                                                  
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
 *  @Component:   ALWAYS_ON_CM2
 *
 *  @Filename:    always_on_cm2_cred.h
 *
 *  @Description: Component description is not available
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __ALWAYS_ON_CM2_CRED_H
#define __ALWAYS_ON_CM2_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance ALWAYS_ON_CM2 of component ALWAYS_ON_CM2 mapped in MONICA at address 0x4A008600
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
     *  List of Register arrays for component ALWAYS_ON_CM2
     *
     */

    /* 
     *  List of bundle arrays for component ALWAYS_ON_CM2
     *
     */

    /* 
     *  List of bundles for component ALWAYS_ON_CM2
     *
     */

    /* 
     * List of registers for component ALWAYS_ON_CM2
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL
 *
 * @BRIEF        This register enables the domain power state transition. It 
 *               controls the HW supervised domain power state transition 
 *               between ON-ACTIVE and ON-INACTIVE states. It also hold one 
 *               status bit per clock input of the domain. 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL                  0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL
 *
 * @BRIEF        This register manages the MDMINTC clocks. 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL            0x20ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL
 *
 * @BRIEF        This register manages the SR_MPU clocks. 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL             0x28ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL
 *
 * @BRIEF        This register manages the SR_IVA clocks. 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL             0x30ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL
 *
 * @BRIEF        This register manages the SR_CORE clocks. 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL            0x38ul

    /* 
     * List of register bitfields for component ALWAYS_ON_CM2
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_CORE_SYSCLK   
 *
 * @BRIEF        This field indicates the state of the SR_CORE_SYSCLK clock 
 *               input of the domain. 
 *               [warm reset insensitive] - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_CORE_SYSCLK BITFIELD(11, 11)
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_CORE_SYSCLK__POS 11

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_IVA_SYSCLK   
 *
 * @BRIEF        This field indicates the state of the SR_IVA_SYSCLK clock 
 *               input of the domain. 
 *               [warm reset insensitive] - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_IVA_SYSCLK BITFIELD(10, 10)
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_IVA_SYSCLK__POS 10

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_MPU_SYSCLK   
 *
 * @BRIEF        This field indicates the state of the SR_MPU_SYSCLK clock 
 *               input of the domain. 
 *               [warm reset insensitive] - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_MPU_SYSCLK BITFIELD(9, 9)
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_MPU_SYSCLK__POS 9

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_L4_AO_ICLK   
 *
 * @BRIEF        This field indicates the state of the L4_AO_ICLK clock of 
 *               the domain. 
 *               [warm reset insensitive] - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_L4_AO_ICLK BITFIELD(8, 8)
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_L4_AO_ICLK__POS 8

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL   
 *
 * @BRIEF        Controls the clock state transition of the ALWONCORE clock 
 *               domain. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL  BITFIELD(1, 0)
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST   
 *
 * @BRIEF        Module idle status.  [warm reset insensitive] - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST BITFIELD(17, 16)
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__POS 16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__MODULEMODE   
 *
 * @BRIEF        Control the way mandatory clocks are managed. - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__MODULEMODE BITFIELD(1, 0)
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__MODULEMODE__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST   
 *
 * @BRIEF        Module idle status.  [warm reset insensitive] - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST BITFIELD(17, 16)
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__POS 16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE   
 *
 * @BRIEF        Control the way mandatory clocks are managed. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE BITFIELD(1, 0)
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST   
 *
 * @BRIEF        Module idle status.  [warm reset insensitive] - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST BITFIELD(17, 16)
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__POS 16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE   
 *
 * @BRIEF        Control the way mandatory clocks are managed. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE BITFIELD(1, 0)
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST   
 *
 * @BRIEF        Module idle status.  [warm reset insensitive] - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST BITFIELD(17, 16)
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__POS 16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE   
 *
 * @BRIEF        Control the way mandatory clocks are managed. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE BITFIELD(1, 0)
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__POS 0

    /* 
     * List of register bitfields values for component ALWAYS_ON_CM2
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_CORE_SYSCLK__INACT
 *
 * @BRIEF        Corresponding clock is definitely gated - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_CORE_SYSCLK__INACT 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_CORE_SYSCLK__ACT
 *
 * @BRIEF        Corresponding clock is running or gating/ungating transition 
 *               is on-going - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_CORE_SYSCLK__ACT 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_IVA_SYSCLK__INACT
 *
 * @BRIEF        Corresponding clock is definitely gated - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_IVA_SYSCLK__INACT 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_IVA_SYSCLK__ACT
 *
 * @BRIEF        Corresponding clock is running or gating/ungating transition 
 *               is on-going - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_IVA_SYSCLK__ACT 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_MPU_SYSCLK__INACT
 *
 * @BRIEF        Corresponding clock is definitely gated - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_MPU_SYSCLK__INACT 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_MPU_SYSCLK__ACT
 *
 * @BRIEF        Corresponding clock is running or gating/ungating transition 
 *               is on-going - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_SR_MPU_SYSCLK__ACT 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_L4_AO_ICLK__INACT
 *
 * @BRIEF        Corresponding clock is definitely gated - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_L4_AO_ICLK__INACT 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_L4_AO_ICLK__ACT
 *
 * @BRIEF        Corresponding clock is running or gating/ungating transition 
 *               is on-going - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKACTIVITY_L4_AO_ICLK__ACT 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__NO_SLEEP
 *
 * @BRIEF        NO_SLEEP: Sleep transition cannot be initiated. Wakeup 
 *               transition may however occur. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__NO_SLEEP 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__RESERVED
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__RESERVED 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__SW_WKUP
 *
 * @BRIEF        SW_WKUP: Start a software forced wake-up transition on the 
 *               domain. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__SW_WKUP 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__HW_AUTO
 *
 * @BRIEF        HW_AUTO: Automatic transition is enabled. Sleep and wakeup 
 *               transition are based upon hardware conditions. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_CLKSTCTRL__CLKTRCTRL__HW_AUTO 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__FUNC
 *
 * @BRIEF        Module is fully functional, including OCP - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__FUNC 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__TRANS
 *
 * @BRIEF        Module is performing transition: wakeup, or sleep, or sleep 
 *               abortion - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__TRANS 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__IDLE
 *
 * @BRIEF        Module is in Idle mode (only OCP part). It is functional if 
 *               using separate functional clock - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__IDLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__DISABLE
 *
 * @BRIEF        Module is disabled and cannot be accessed - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__IDLEST__DISABLE 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__MODULEMODE__DISABLED
 *
 * @BRIEF        Module is disabled (not present). - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_MDMINTC_CLKCTRL__MODULEMODE__DISABLED 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__FUNC
 *
 * @BRIEF        Module is fully functional, including OCP - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__FUNC 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__TRANS
 *
 * @BRIEF        Module is performing transition: wakeup, or sleep, or sleep 
 *               abortion - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__TRANS 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__IDLE
 *
 * @BRIEF        Module is in Idle mode (only OCP part). It is functional if 
 *               using separate functional clock - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__IDLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__DISABLE
 *
 * @BRIEF        Module is disabled and cannot be accessed - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__IDLEST__DISABLE 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__DISABLED
 *
 * @BRIEF        Module is disable by SW. Any OCP access to module results in 
 *               an error, except if resulting from a module wakeup 
 *               (asynchronous wakeup). - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__DISABLED 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__RESERVED_1
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__RESERVED_1 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__ENABLE
 *
 * @BRIEF        Module is explicitly enabled. Interface clock (if not used 
 *               for functions) may be gated according to the clock domain 
 *               state. Functional clocks are guarantied to stay present. As 
 *               long as in this configuration, power domain sleep transition 
 *               cannot happen. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__ENABLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__RESERVED
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_MPU_CLKCTRL__MODULEMODE__RESERVED 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__FUNC
 *
 * @BRIEF        Module is fully functional, including OCP - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__FUNC 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__TRANS
 *
 * @BRIEF        Module is performing transition: wakeup, or sleep, or sleep 
 *               abortion - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__TRANS 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__IDLE
 *
 * @BRIEF        Module is in Idle mode (only OCP part). It is functional if 
 *               using separate functional clock - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__IDLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__DISABLE
 *
 * @BRIEF        Module is disabled and cannot be accessed - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__IDLEST__DISABLE 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__DISABLED
 *
 * @BRIEF        Module is disable by SW. Any OCP access to module results in 
 *               an error, except if resulting from a module wakeup 
 *               (asynchronous wakeup). - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__DISABLED 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__RESERVED_1
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__RESERVED_1 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__ENABLE
 *
 * @BRIEF        Module is explicitly enabled. Interface clock (if not used 
 *               for functions) may be gated according to the clock domain 
 *               state. Functional clocks are guarantied to stay present. As 
 *               long as in this configuration, power domain sleep transition 
 *               cannot happen. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__ENABLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__RESERVED
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_IVA_CLKCTRL__MODULEMODE__RESERVED 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__FUNC
 *
 * @BRIEF        Module is fully functional, including OCP - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__FUNC 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__TRANS
 *
 * @BRIEF        Module is performing transition: wakeup, or sleep, or sleep 
 *               abortion - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__TRANS 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__IDLE
 *
 * @BRIEF        Module is in Idle mode (only OCP part). It is functional if 
 *               using separate functional clock - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__IDLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__DISABLE
 *
 * @BRIEF        Module is disabled and cannot be accessed - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__IDLEST__DISABLE 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__DISABLED
 *
 * @BRIEF        Module is disable by SW. Any OCP access to module results in 
 *               an error, except if resulting from a module wakeup 
 *               (asynchronous wakeup). - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__DISABLED 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__RESERVED_1
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__RESERVED_1 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__ENABLE
 *
 * @BRIEF        Module is explicitly enabled. Interface clock (if not used 
 *               for functions) may be gated according to the clock domain 
 *               state. Functional clocks are guarantied to stay present. As 
 *               long as in this configuration, power domain sleep transition 
 *               cannot happen. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__ENABLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__RESERVED
 *
 * @BRIEF        Reserved - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ALWAYS_ON_CM2__CM_ALWON_SR_CORE_CLKCTRL__MODULEMODE__RESERVED 0x3ul

#ifdef __cplusplus
}
#endif
#endif                                                     /* __ALWAYS_ON_CM2_CRED_H 
                                                            */
