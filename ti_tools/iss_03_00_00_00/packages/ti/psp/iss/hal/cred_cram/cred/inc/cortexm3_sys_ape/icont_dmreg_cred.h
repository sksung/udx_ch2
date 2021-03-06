/** ==================================================================
 *  @file   icont_dmreg_cred.h                                                  
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
 *  @Component:   ICONT_DMREG
 *
 *  @Filename:    icont_dmreg_cred.h
 *
 *  @Description: ICONT Data Mover module registers 
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __ICONT_DMREG_CRED_H
#define __ICONT_DMREG_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance ICONT1_MMR__DM of component ICONT_DMREG mapped in MONICA at address 0x5A070800
     * Instance ICONT2_MMR__DM of component ICONT_DMREG mapped in MONICA at address 0x5A071800
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
     *  List of Register arrays for component ICONT_DMREG
     *
     */

    /* 
     *  List of bundle arrays for component ICONT_DMREG
     *
     */
                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__DMCONFIG
 *
 * @BRIEF        Bundle description is not available
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__DMCONFIG                              0x40ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__DMCONFIG__ELSIZE
 *
 * @BRIEF        DMCONFIG bundle array element size in Bytes
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__DMCONFIG__ELSIZE                      0x20ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__DMCONFIG__NELEMS
 *
 * @BRIEF        DMCONFIG bundle array number of elements
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__DMCONFIG__NELEMS                      4

    /* 
     *  List of bundles for component ICONT_DMREG
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMSOURCEADD__OFFSET
 *
 * @BRIEF        Register ICONT_DMSOURCEADD offset in bundle DMCONFIG 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMSOURCEADD__OFFSET             0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMDESTADD__OFFSET
 *
 * @BRIEF        Register ICONT_DMDESTADD offset in bundle DMCONFIG 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMDESTADD__OFFSET               0x4ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__OFFSET
 *
 * @BRIEF        Register ICONT_DMCONTEXT offset in bundle DMCONFIG 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__OFFSET               0x8ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMSTATUS__OFFSET
 *
 * @BRIEF        Register ICONT_DMSTATUS offset in bundle DMCONFIG 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMSTATUS__OFFSET                0xCul

    /* 
     * List of registers for component ICONT_DMREG
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQ_EOI
 *
 * @BRIEF        End Of Interrupt number specification 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQ_EOI                      0x20ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQSTATUS_RAW
 *
 * @BRIEF        Per-event raw interrupt status vector (DM interrupt). 
 *               Raw status is set even if event is not enabled. 
 *               Write 1 to set the (raw) status, mostly for debug. 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQSTATUS_RAW                0x24ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQSTATUS
 *
 * @BRIEF        Per-event "enabled" interrupt status vector (DM interrupt). 
 *               Enabled status isn't set unless event is enabled. 
 *               Write 1 to clear the status after interrupt has been 
 *               serviced (raw status gets cleared, i.e. even if not 
 *               enabled). 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQSTATUS                    0x28ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQENABLE_SET
 *
 * @BRIEF        Per-event interrupt enable bit vector (DM interrupt).  
 *               Write 1 to set (enable interrupt). 
 *               Readout equal to corresponding _CLR register. 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQENABLE_SET                0x2Cul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQENABLE_CLR
 *
 * @BRIEF        Per-event interrupt enable bit vector (DM interrupt).  
 *               Write 1 to clear (disable interrupt). 
 *               Readout equal to corresponding _SET register. 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQENABLE_CLR                0x30ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMSOURCEADD
 *
 * @BRIEF        Data mover source address for context n (Byte address, must 
 *               be aligned on 128-bit boundary) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMSOURCEADD                     0x40ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMDESTADD
 *
 * @BRIEF        Data mover destination address for context n (byte address, 
 *               must be aligned on 128-bit boundary) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMDESTADD                       0x44ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT
 *
 * @BRIEF        Data Mover Context n. 
 *               A new DM transfer can be scheduled only if this register has 
 *               been written by SW. 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT                       0x48ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMSTATUS
 *
 * @BRIEF        Data Mover status register for context n. 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMSTATUS                        0x4Cul

    /* 
     * List of register bitfields for component ICONT_DMREG
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQ_EOI__LINE_NUMBER   
 *
 * @BRIEF        Software End Of Interrupt (EOI) control. Write number of 
 *               interrupt output. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQ_EOI__LINE_NUMBER    BITFIELD(0, 0)
#define ICONT_DMREG__ICONT_DM_IRQ_EOI__LINE_NUMBER__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQSTATUS_RAW__LCHN_0   
 *
 * @BRIEF        Settable raw status for Logical Channel n to 0 
 *               (n=NB_DM_LCH-1) 
 *               For each bit of the bitfield: 
 *                 Read 0: No event pending  
 *                 Read 1: Event pending  
 *                 Write 0: No action  
 *                 Write 1: Set event (debug) - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQSTATUS_RAW__LCHN_0   BITFIELD(3, 0)
#define ICONT_DMREG__ICONT_DM_IRQSTATUS_RAW__LCHN_0__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQSTATUS__LCHN_0   
 *
 * @BRIEF        Clearable, enabled status for Logical Channel n to 0 
 *               (n=NB_DM_LCH-1) 
 *               For each bit of the bitfield: 
 *                 Read 0: No (enabled) event pending  
 *                 Read 1: Event pending  
 *                 Write 0: No action  
 *                 Write 1: Clear (raw) event - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQSTATUS__LCHN_0       BITFIELD(3, 0)
#define ICONT_DMREG__ICONT_DM_IRQSTATUS__LCHN_0__POS  0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQENABLE_SET__LCHN_0   
 *
 * @BRIEF        Enable for Logical Channel n to 0 (n=NB_DM_LCH-1) 
 *               For each bit of the bitfield: 
 *                 Read 0: Interrupt disabled (masked)  
 *                 Read 1: Interrupt enabled  
 *                 Write 0: No action  
 *                 Write 1: Enable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQENABLE_SET__LCHN_0   BITFIELD(3, 0)
#define ICONT_DMREG__ICONT_DM_IRQENABLE_SET__LCHN_0__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQENABLE_CLR__LCHN_0   
 *
 * @BRIEF        Enable for Logical Channel n to 0 (n=NB_DM_LCH-1) 
 *               For each bit of the bitfiled: 
 *                 Read 0: Interrupt disabled (masked)  
 *                 Read 1: Interrupt enabled  
 *                 Write 0: No action  
 *                 Write 1: Disable interrupt - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQENABLE_CLR__LCHN_0   BITFIELD(3, 0)
#define ICONT_DMREG__ICONT_DM_IRQENABLE_CLR__LCHN_0__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMSOURCEADD__SOURCEADDR   
 *
 * @BRIEF        Source address of transfer - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMSOURCEADD__SOURCEADDR    BITFIELD(17, 0)
#define ICONT_DMREG__ICONT_DMSOURCEADD__SOURCEADDR__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMDESTADD__DESTADDR   
 *
 * @BRIEF        Destination address of transfer - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMDESTADD__DESTADDR        BITFIELD(17, 0)
#define ICONT_DMREG__ICONT_DMDESTADD__DESTADDR__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__END_TYPE   
 *
 * @BRIEF        1: Send End Of Logical channel notification on transfer 
 *               completion 
 *               0: Do not send End Of Task notification on transfer 
 *               completion - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__END_TYPE        BITFIELD(20, 20)
#define ICONT_DMREG__ICONT_DMCONTEXT__END_TYPE__POS   20

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__START_TYPE   
 *
 * @BRIEF        1: Transfer is scheduled on logical channel start 
 *               notification 
 *               0: Transfer is scheduled on write to ICONT_DMCONTEXT 
 *               register - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__START_TYPE      BITFIELD(19, 19)
#define ICONT_DMREG__ICONT_DMCONTEXT__START_TYPE__POS 19

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE   
 *
 * @BRIEF        Type of transfer - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE        BITFIELD(18, 16)
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__POS   16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__NB_BYTE   
 *
 * @BRIEF        Number of bytes to transfer (must be a multiple of 128b) - 
 *               (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__NB_BYTE         BITFIELD(15, 0)
#define ICONT_DMREG__ICONT_DMCONTEXT__NB_BYTE__POS    0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMSTATUS__STATUS   
 *
 * @BRIEF        00: LCHn is in IDLE state. 
 *                      Descriptor is free to be programmed (or transfer 
 *               completed). 
 *               01: LCHn is in WAIT FOR HW EVENT state. 
 *                      Descriptor is programmed and is waiting for a HW 
 *               event in order to be queued. 
 *               10: LCHn is in either QUEUED state, in ON GOING state, or in 
 *               COMPLETED state. 
 *               11: Reserved. - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMSTATUS__STATUS           BITFIELD(1, 0)
#define ICONT_DMREG__ICONT_DMSTATUS__STATUS__POS      0

    /* 
     * List of register bitfields values for component ICONT_DMREG
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQ_EOI__LINE_NUMBER__EOI0
 *
 * @BRIEF        EOI for DM interrupt output - (Write) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQ_EOI__LINE_NUMBER__EOI0 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DM_IRQ_EOI__LINE_NUMBER__READ0
 *
 * @BRIEF        Reads always 0 (no EOI memory) - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DM_IRQ_EOI__LINE_NUMBER__READ0 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__SL2TODTCM
 *
 * @BRIEF        Transfer from SL2 to DTCM - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__SL2TODTCM 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__SL2TOITCM
 *
 * @BRIEF        Transfer from SL2 to ITCM - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__SL2TOITCM 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__DTCMTOTDMA
 *
 * @BRIEF        Transfer from DTCM to transversal port of VDMA - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__DTCMTOTDMA 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__SL2TOTDMA
 *
 * @BRIEF        Transfer from SL2 to Transversal port of VDMA - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__SL2TOTDMA 0x3ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__DTCMTOSL2
 *
 * @BRIEF        Transfer from DTCM to SL2 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__DTCMTOSL2 0x4ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__RESERVED
 *
 * @BRIEF        reserved - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__RESERVED 0x5ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__RESERVED1
 *
 * @BRIEF        reserved - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__RESERVED1 0x6ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__RESERVED2
 *
 * @BRIEF        reserved - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ICONT_DMREG__ICONT_DMCONTEXT__CMD_TYPE__RESERVED2 0x7ul

#ifdef __cplusplus
}
#endif
#endif                                                     /* __ICONT_DMREG_CRED_H 
                                                            */
