/** ==================================================================
 *  @file   mc3_ipgw_cred.h                                                  
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
 *  @Component:   MC3_IPGW
 *
 *  @Filename:    mc3_ipgw_cred.h
 *
 *  @Description: Component description is not available
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __MC3_IPGW_CRED_H
#define __MC3_IPGW_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance MC3_CFG__IPGW of component MC3_IPGW mapped in MONICA at address 0x5A059400
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
     *  List of Register arrays for component MC3_IPGW
     *
     */

    /* 
     *  List of bundle arrays for component MC3_IPGW
     *
     */

    /* 
     *  List of bundles for component MC3_IPGW
     *
     */

    /* 
     * List of registers for component MC3_IPGW
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_SYSCONFIG
 *
 * @BRIEF        Clock management configuration 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_SYSCONFIG                            0x8ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQ_EOI
 *
 * @BRIEF        End Of Interrupt number specification 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQ_EOI                              0xCul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IPQSTATUS_RAW_0
 *
 * @BRIEF        Per-event raw interrupt status vector, line #0.  
 *               Raw status is set even if event is not enabled. 
 *               Write 1 to set the (raw) status, mostly for debug. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IPQSTATUS_RAW_0                      0x14ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IPQSTATUS_RAW_1
 *
 * @BRIEF        Per-event raw interrupt status vector, line #1.  
 *               Raw status is set even if event is not enabled. 
 *               Write 1 to set the (raw) status, mostly for debug. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IPQSTATUS_RAW_1                      0x18ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IPQSTATUS_RAW_2
 *
 * @BRIEF        Per-event raw interrupt status vector, line #2.  
 *               Raw status is set even if event is not enabled. 
 *               Write 1 to set the (raw) status, mostly for debug. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IPQSTATUS_RAW_2                      0x1Cul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IPQSTATUS_RAW_3
 *
 * @BRIEF        Per-event raw interrupt status vector, line #3.  
 *               Raw status is set even if event is not enabled. 
 *               Write 1 to set the (raw) status, mostly for debug. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IPQSTATUS_RAW_3                      0x20ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_0
 *
 * @BRIEF        Per-event "enabled" interrupt status vector, line #0. 
 *               Enabled status isn't set unless event is enabled. 
 *               Write 1 to clear the status after interrupt has been 
 *               serviced (raw status gets cleared, i.e. even if not 
 *               enabled). 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_0                          0x30ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_1
 *
 * @BRIEF        Per-event "enabled" interrupt status vector, line #1. 
 *               Enabled status isn't set unless event is enabled. 
 *               Write 1 to clear the status after interrupt has been 
 *               serviced (raw status gets cleared, i.e. even if not 
 *               enabled). 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_1                          0x34ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_2
 *
 * @BRIEF        Per-event "enabled" interrupt status vector, line #2. 
 *               Enabled status isn't set unless event is enabled. 
 *               Write 1 to clear the status after interrupt has been 
 *               serviced (raw status gets cleared, i.e. even if not 
 *               enabled). 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_2                          0x38ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_3
 *
 * @BRIEF        Per-event "enabled" interrupt status vector, line #3. 
 *               Enabled status isn't set unless event is enabled. 
 *               Write 1 to clear the status after interrupt has been 
 *               serviced (raw status gets cleared, i.e. even if not 
 *               enabled). 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_3                          0x3Cul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_SET_0
 *
 * @BRIEF        Per-event interrupt enable bit vector, line #0.  
 *               Write 1 to set (enable interrupt). 
 *               Readout equal to corresponding _CLR register. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_SET_0                      0x4Cul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_SET_1
 *
 * @BRIEF        Per-event interrupt enable bit vector, line #1.  
 *               Write 1 to set (enable interrupt). 
 *               Readout equal to corresponding _CLR register. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_SET_1                      0x50ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_SET_2
 *
 * @BRIEF        Per-event interrupt enable bit vector, line #2.  
 *               Write 1 to set (enable interrupt). 
 *               Readout equal to corresponding _CLR register. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_SET_2                      0x54ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_SET_3
 *
 * @BRIEF        Per-event interrupt enable bit vector, line #0.  
 *               Write 1 to set (enable interrupt). 
 *               Readout equal to corresponding _CLR register. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_SET_3                      0x58ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_CLR_0
 *
 * @BRIEF        Per-event interrupt enable bit vector, line #0.  
 *               Write 1 to clear (disable interrupt). 
 *               Readout equal to corresponding _SET register. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_CLR_0                      0x68ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_CLR_1
 *
 * @BRIEF        Per-event interrupt enable bit vector, line #1.  
 *               Write 1 to clear (disable interrupt). 
 *               Readout equal to corresponding _SET register. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_CLR_1                      0x6Cul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_CLR_2
 *
 * @BRIEF        Per-event interrupt enable bit vector, line #2.  
 *               Write 1 to clear (disable interrupt). 
 *               Readout equal to corresponding _SET register. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_CLR_2                      0x70ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_CLR_3
 *
 * @BRIEF        Per-event interrupt enable bit vector, line #2.  
 *               Write 1 to clear (disable interrupt). 
 *               Readout equal to corresponding _SET register. 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_CLR_3                      0x74ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_ACLREN
 *
 * @BRIEF        Auto Clear enable 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN                     0xC0ul

    /* 
     * List of register bitfields for component MC3_IPGW
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_SYSCONFIG__IDLEMODE   
 *
 * @BRIEF        Configuration of the local target state management mode. 
 *               By definition, target can handle read/write transaction as 
 *               long as it is out of IDLE state. 
 *               0: Force-idle mode: local target's idle state follows 
 *               (acknowledges) the system's idle requests unconditionally, 
 *               i.e. regardless of the IP module's internal requirements. 
 *               Backup mode, for debug only.  
 *               1: No-idle mode: local target never enters idle state. 
 *               Backup mode, for debug only.  
 *               2: Smart-idle mode: local target's idle state eventually 
 *               follows (acknowledges) the system's idle requests, depending 
 *               on the IP module's internal requirements. 
 *               IP module shall not generate (IRQ- or DMA-request-related) 
 *               wakeup events.  
 *               3: Smart-idle wakeup-capable mode: local target's idle state 
 *               eventually follows (acknowledges) the system's idle 
 *               requests, depending on the IP module's internal 
 *               requirements. 
 *               IP module may generate (IRQ- or DMA-request-related) wakeup 
 *               events when in idle state. 
 *               Mode is only relevant if the appropriate IP module "swakeup" 
 *               output(s) is (are) implemented. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_SYSCONFIG__IDLEMODE             BITFIELD(3, 2)
#define MC3_IPGW__MC3_SYSCONFIG__IDLEMODE__POS        2

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_SYSCONFIG__FREEEMU   
 *
 * @BRIEF        Sensitivity to emulation (debug) suspend input signal. 
 *               0: IP module is sensitive to emulation suspend  
 *               1: IP module is not sensitive to emulation suspend - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_SYSCONFIG__FREEEMU              BITFIELD(1, 1)
#define MC3_IPGW__MC3_SYSCONFIG__FREEEMU__POS         1

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_SYSCONFIG__SOFTRESET   
 *
 * @BRIEF        Software reset 
 *               Read0: Reset done, no pending action 
 *               Read1: Reset (software or other) on going 
 *               Write0: No action 
 *               Write1: Initiate software reset - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_SYSCONFIG__SOFTRESET            BITFIELD(0, 0)
#define MC3_IPGW__MC3_SYSCONFIG__SOFTRESET__POS       0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQ_EOI__LINE_NUMBER   
 *
 * @BRIEF        Software End Of Interrupt (EOI) control. Write number of 
 *               interrupt output. 
 *               Write 0x0:  EOI for interrupt output line #0  
 *               Write 0x1:  EOI for interrupt output line #1  
 *               Write 0x2:  EOI for interrupt output line #2 
 *               Write 0x3:  EOI for interrupt output line #3 
 *               Read 0x0:  Reads always 0 (no EOI memory) - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQ_EOI__LINE_NUMBER            BITFIELD(1, 0)
#define MC3_IPGW__MC3_IRQ_EOI__LINE_NUMBER__POS       0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IPQSTATUS_RAW_0__EVENT0   
 *
 * @BRIEF        settable raw status for event #0 
 *               Write 0:  No action  
 *               Read 0:  No event pending  
 *               Read 1:  Event pending  
 *               Write 1:  Set event (debug) - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IPQSTATUS_RAW_0__EVENT0         BITFIELD(0, 0)
#define MC3_IPGW__MC3_IPQSTATUS_RAW_0__EVENT0__POS    0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IPQSTATUS_RAW_1__EVENT0   
 *
 * @BRIEF        settable raw status for event #0 
 *               Write 0:  No action  
 *               Read 0:  No event pending  
 *               Read 1:  Event pending  
 *               Write 1:  Set event (debug) - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IPQSTATUS_RAW_1__EVENT0         BITFIELD(0, 0)
#define MC3_IPGW__MC3_IPQSTATUS_RAW_1__EVENT0__POS    0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IPQSTATUS_RAW_2__EVENT0   
 *
 * @BRIEF        settable raw status for event #0 
 *               Write 0:  No action  
 *               Read 0:  No event pending  
 *               Read 1:  Event pending  
 *               Write 1:  Set event (debug) - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IPQSTATUS_RAW_2__EVENT0         BITFIELD(0, 0)
#define MC3_IPGW__MC3_IPQSTATUS_RAW_2__EVENT0__POS    0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IPQSTATUS_RAW_3__EVENT0   
 *
 * @BRIEF        settable raw status for event #0 
 *               Write 0:  No action  
 *               Read 0:  No event pending  
 *               Read 1:  Event pending  
 *               Write 1:  Set event (debug) - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IPQSTATUS_RAW_3__EVENT0         BITFIELD(0, 0)
#define MC3_IPGW__MC3_IPQSTATUS_RAW_3__EVENT0__POS    0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_0__EVENT0   
 *
 * @BRIEF        clearable, enabled status for event #0 
 *               Write 0:  No action  
 *               Read 0:  No (enabled) event pending  
 *               Read 1:  Event pending  
 *               Write 1:  Clear (raw) event - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_0__EVENT0             BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQSTATUS_0__EVENT0__POS        0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_1__EVENT0   
 *
 * @BRIEF        clearable, enabled status for event #0 
 *               Write 0:  No action  
 *               Read 0:  No (enabled) event pending  
 *               Read 1:  Event pending  
 *               Write 1:  Clear (raw) event - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_1__EVENT0             BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQSTATUS_1__EVENT0__POS        0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_2__EVENT0   
 *
 * @BRIEF        clearable, enabled status for event #0 
 *               Write 0:  No action  
 *               Read 0:  No (enabled) event pending  
 *               Read 1:  Event pending  
 *               Write 1:  Clear (raw) event - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_2__EVENT0             BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQSTATUS_2__EVENT0__POS        0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_3__EVENT0   
 *
 * @BRIEF        clearable, enabled status for event #0 
 *               Write 0:  No action  
 *               Read 0:  No (enabled) event pending  
 *               Read 1:  Event pending  
 *               Write 1:  Clear (raw) event - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_3__EVENT0             BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQSTATUS_3__EVENT0__POS        0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_SET_0__ENABLE0   
 *
 * @BRIEF        enable for event #0 
 *               Write 0:  No action  
 *               Read 0:  Interrupt disabled (masked)  
 *               Read 1:  Interrupt enabled  
 *               Write 1:  Enable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_SET_0__ENABLE0        BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQENABLE_SET_0__ENABLE0__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_SET_1__ENABLE0   
 *
 * @BRIEF        enable for event #0 
 *               Write 0:  No action  
 *               Read 0:  Interrupt disabled (masked)  
 *               Read 1:  Interrupt enabled  
 *               Write 1:  Enable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_SET_1__ENABLE0        BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQENABLE_SET_1__ENABLE0__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_SET_2__ENABLE0   
 *
 * @BRIEF        enable for event #0 
 *               Write 0:  No action  
 *               Read 0:  Interrupt disabled (masked)  
 *               Read 1:  Interrupt enabled  
 *               Write 1:  Enable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_SET_2__ENABLE0        BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQENABLE_SET_2__ENABLE0__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_SET_3__ENABLE0   
 *
 * @BRIEF        enable for event #0 
 *               Write 0:  No action  
 *               Read 0:  Interrupt disabled (masked)  
 *               Read 1:  Interrupt enabled  
 *               Write 1:  Enable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_SET_3__ENABLE0        BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQENABLE_SET_3__ENABLE0__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_CLR_0__ENABLE0   
 *
 * @BRIEF        enable for event #0 
 *               Write 0:  No action  
 *               Read 0:  Interrupt disabled (masked)  
 *               Read 1:  Interrupt enabled  
 *               Write 1:  Disable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_CLR_0__ENABLE0        BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQENABLE_CLR_0__ENABLE0__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_CLR_1__ENABLE0   
 *
 * @BRIEF        enable for event #0 
 *               Write 0:  No action  
 *               Read 0:  Interrupt disabled (masked)  
 *               Read 1:  Interrupt enabled  
 *               Write 1:  Disable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_CLR_1__ENABLE0        BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQENABLE_CLR_1__ENABLE0__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_CLR_2__ENABLE0   
 *
 * @BRIEF        enable for event #0 
 *               Write 0:  No action  
 *               Read 0:  Interrupt disabled (masked)  
 *               Read 1:  Interrupt enabled  
 *               Write 1:  Disable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_CLR_2__ENABLE0        BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQENABLE_CLR_2__ENABLE0__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQENABLE_CLR_3__ENABLE0   
 *
 * @BRIEF        enable for event #0 
 *               Write 0:  No action  
 *               Read 0:  Interrupt disabled (masked)  
 *               Read 1:  Interrupt enabled  
 *               Write 1:  Disable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQENABLE_CLR_3__ENABLE0        BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQENABLE_CLR_3__ENABLE0__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN3   
 *
 * @BRIEF        for line3 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN3       BITFIELD(3, 3)
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN3__POS  3

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN2   
 *
 * @BRIEF        for line2 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN2       BITFIELD(2, 2)
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN2__POS  2

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN1   
 *
 * @BRIEF        for line1 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN1       BITFIELD(1, 1)
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN1__POS  1

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN0   
 *
 * @BRIEF        for line0 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN0       BITFIELD(0, 0)
#define MC3_IPGW__MC3_IRQSTATUS_ACLREN__ACLREN0__POS  0

    /* 
     * List of register bitfields values for component MC3_IPGW
     *
     */

#ifdef __cplusplus
}
#endif
#endif                                                     /* __MC3_IPGW_CRED_H 
                                                            */
