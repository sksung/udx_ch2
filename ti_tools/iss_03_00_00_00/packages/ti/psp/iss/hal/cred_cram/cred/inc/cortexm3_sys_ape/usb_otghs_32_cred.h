/** ==================================================================
 *  @file   usb_otghs_32_cred.h                                                  
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
 *  @Component:   USB_OTGHS_32
 *
 *  @Filename:    usb_otghs_32_cred.h
 *
 * *  @Description: This component represents the USB_OTGHS registers (32bit 
 *                registers) except ENDPOINT0 indexed registers 
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __USB_OTGHS_32_CRED_H
#define __USB_OTGHS_32_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance USB_OTGHS_32 of component USB_OTGHS_32 mapped in USB_OTGHS_32 at address 0x0
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
     *  List of Register arrays for component USB_OTGHS_32
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__FIFO
 *
 * @BRIEF        FIFO access for endpoint #N 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__FIFO                                 0x20ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__FIFO__ELSIZE
 *
 * @BRIEF        FIFO register array element size in Bytes
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__FIFO__ELSIZE                         0x4ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__FIFO__NELEMS
 *
 * @BRIEF        FIFO register array number of elements
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__FIFO__NELEMS                         16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__RQPKTCOUNT
 *
 * @BRIEF        HOST MODE ONLY REGISTER 
 *               This read/write register is used in Host mode to specify the 
 *               number of packets that are to be transferred in a block 
 *               transfer of one or more Bulk packets of length MaxP to Rx 
 *               Endpoint n. The core uses the value recorded in this 
 *               register to determine the number of requests to issue where 
 *               the AutoReq option (included in the RxCSR register) has been 
 *               set. 
 *               NOTE: this register is applicable only for EP 1 to 15 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__RQPKTCOUNT                           0x300ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__RQPKTCOUNT__ELSIZE
 *
 * @BRIEF        RQPKTCOUNT register array element size in Bytes
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__RQPKTCOUNT__ELSIZE                   0x4ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__RQPKTCOUNT__NELEMS
 *
 * @BRIEF        RQPKTCOUNT register array number of elements
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__RQPKTCOUNT__NELEMS                   16

    /* 
     *  List of bundle arrays for component USB_OTGHS_32
     *
     */
                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_32
 *
 * @BRIEF        Bundle description is not available
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_32                               0x208ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_32__ELSIZE
 *
 * @BRIEF        DMA_32 bundle array element size in Bytes
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_32__ELSIZE                       0x10ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_32__NELEMS
 *
 * @BRIEF        DMA_32 bundle array number of elements
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_32__NELEMS                       8

    /* 
     *  List of bundles for component USB_OTGHS_32
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_ADDR__OFFSET
 *
 * @BRIEF        Register DMA_ADDR offset in bundle DMA_32 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_ADDR__OFFSET                     0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_COUNT__OFFSET
 *
 * @BRIEF        Register DMA_COUNT offset in bundle DMA_32 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_COUNT__OFFSET                    0x4ul

    /* 
     * List of registers for component USB_OTGHS_32
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__VCTRL_VSTATUS
 *
 * @BRIEF        As per UMTI+ PHY specification 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__VCTRL_VSTATUS                        0x68ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_ADDR
 *
 * @BRIEF        DMA Address Register 
 *               32-bit address for DMA channel #N, Address: 208h + 
 *               (N-1)*10h; N=channel number 1 thru 8 
 *               This register identifies the current memory address of the 
 *               corresponding DMA channel. The Initial memory address 
 *               written to this register must have a value such that its 
 *               modulo 4 value is equal to 0. That is, DMA_ADDR[1:0] must be 
 *               equal to 2?b00. The lower two bits of this register are read 
 *               only and cannot be set by software. As the DMA transfer 
 *               progresses, the memory address will increment as bytes are 
 *               tranfered. 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_ADDR                             0x208ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_COUNT
 *
 * @BRIEF        DMA Count Register 
 *               32-bit byte count for DMA channel #N  
 *               Address: 20Ch + (N-1)*10h;N=channel number 1 thru 8 
 *               This register identifies the current DMA count of the 
 *               transfer. Software will set the initial count of the 
 *               transfer which identifies the entire transfer length. As the 
 *               count progresses this count is decremented as bytes are 
 *               transfered. 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_COUNT                            0x20Cul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_REVISION
 *
 * @BRIEF        OCP standard USB OTG HS core revision number 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_REVISION                         0x400ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG
 *
 * @BRIEF        OCP standard configuration 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG                        0x404ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSSTATUS
 *
 * @BRIEF        OCP standard status 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSSTATUS                        0x408ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_INTERFSEL
 *
 * @BRIEF        USB OTG HS interface selection 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_INTERFSEL                        0x40Cul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SIMENABLE
 *
 * @BRIEF        Enable simulation acceleration features. 
 *               WARNING: For simulations only, since those features have an 
 *               impact on USB protocol. 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SIMENABLE                        0x410ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_FORCESTDBY
 *
 * @BRIEF        Enabling MSTANDBY in FORCESTANDBY mode. 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_FORCESTDBY                       0x414ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_BIGENDIAN
 *
 * @BRIEF        Enable BIG ENDIANESS for OCP MASTER 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_BIGENDIAN                        0x418ul

    /* 
     * List of register bitfields for component USB_OTGHS_32
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__FIFO__DATA   
 *
 * @BRIEF        Bitfield description is not available - (RW)
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__FIFO__DATA                      BITFIELD(31, 0)
#define USB_OTGHS_32__FIFO__DATA__POS                 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__VCTRL_VSTATUS__VCONTROL_VSTATUS   
 *
 * @BRIEF        Write: V_control UMTI+ PHY input 
 *               Read: V_status UTMI+ PHY output - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__VCTRL_VSTATUS__VCONTROL_VSTATUS BITFIELD(31, 0)
#define USB_OTGHS_32__VCTRL_VSTATUS__VCONTROL_VSTATUS__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_ADDR__DMA_ADDR   
 *
 * @BRIEF        The DMA memory address. 
 *               Note that the initial memory address written to this 
 *               register must have a value such that it?s modulo 4 value is 
 *               equal to 0. That is, DMA_ADDR[1:0] must be equal to 2?b00. 
 *               The lower two bits of this register are read only and cannot 
 *               be set by software. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_ADDR__DMA_ADDR              BITFIELD(31, 0)
#define USB_OTGHS_32__DMA_ADDR__DMA_ADDR__POS         0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__DMA_COUNT__DMA_COUNT   
 *
 * @BRIEF        The DMA memory address for the corresponding DMA channel.  
 *               Note: If DMA is enabled with a count of 0, the bus will not 
 *               be requested and a DMA interrupt will be generated. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__DMA_COUNT__DMA_COUNT            BITFIELD(31, 0)
#define USB_OTGHS_32__DMA_COUNT__DMA_COUNT__POS       0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__RQPKTCOUNT__RQPKTCOUNT   
 *
 * @BRIEF        Sets the number of packets of size MaxP that are to be 
 *               transferred in a block transfer. Only used in Host mode when 
 *               AutoReq is set. Has no effect in Peripheral mode or when 
 *               AutoReq is not set. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__RQPKTCOUNT__RQPKTCOUNT          BITFIELD(15, 0)
#define USB_OTGHS_32__RQPKTCOUNT__RQPKTCOUNT__POS     0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_REVISION__OTG_REVISION   
 *
 * @BRIEF        Revision number, BCD-encoded - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_REVISION__OTG_REVISION      BITFIELD(7, 0)
#define USB_OTGHS_32__OTG_REVISION__OTG_REVISION__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE   
 *
 * @BRIEF        Master interface power management control. Standby/wait 
 *               control - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE        BITFIELD(13, 12)
#define USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE__POS   12

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE   
 *
 * @BRIEF        Slave interface power management control. Req/ack control - 
 *               (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE        BITFIELD(4, 3)
#define USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE__POS   3

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__ENABLEWAKEUP   
 *
 * @BRIEF        Enable wakeup capability - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__ENABLEWAKEUP     BITFIELD(2, 2)
#define USB_OTGHS_32__OTG_SYSCONFIG__ENABLEWAKEUP__POS 2

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__SOFTRESET   
 *
 * @BRIEF        Software reset bit - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__SOFTRESET        BITFIELD(1, 1)
#define USB_OTGHS_32__OTG_SYSCONFIG__SOFTRESET__POS   1

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__AUTOIDLE   
 *
 * @BRIEF        Autoidle bit - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__AUTOIDLE         BITFIELD(0, 0)
#define USB_OTGHS_32__OTG_SYSCONFIG__AUTOIDLE__POS    0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSSTATUS__RESETDONE   
 *
 * @BRIEF        resetdone - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSSTATUS__RESETDONE        BITFIELD(0, 0)
#define USB_OTGHS_32__OTG_SYSSTATUS__RESETDONE__POS   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_INTERFSEL__PHYSEL   
 *
 * @BRIEF        PHY interface selection - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_INTERFSEL__PHYSEL           BITFIELD(2, 0)
#define USB_OTGHS_32__OTG_INTERFSEL__PHYSEL__POS      0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SIMENABLE__TM1   
 *
 * @BRIEF        Test Mode 1 enabling (timer shortcuts) - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SIMENABLE__TM1              BITFIELD(0, 0)
#define USB_OTGHS_32__OTG_SIMENABLE__TM1__POS         0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_FORCESTDBY__ENABLEFORCE   
 *
 * @BRIEF        Enabling MSTANDBY to go high - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_FORCESTDBY__ENABLEFORCE     BITFIELD(0, 0)
#define USB_OTGHS_32__OTG_FORCESTDBY__ENABLEFORCE__POS 0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_BIGENDIAN__BIG_ENDIAN   
 *
 * @BRIEF        Enable BIG ENDIAN in OCP MASTER - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_BIGENDIAN__BIG_ENDIAN       BITFIELD(0, 0)
#define USB_OTGHS_32__OTG_BIGENDIAN__BIG_ENDIAN__POS  0

    /* 
     * List of register bitfields values for component USB_OTGHS_32
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE__FORCESTANDBY
 *
 * @BRIEF        Force Standby mode. Mstandby asserted unconditionally - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE__FORCESTANDBY 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE__NOSTANDBY
 *
 * @BRIEF        No standby mode. Mstandby never asserted. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE__NOSTANDBY 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE__SMARTSTANDBY
 *
 * @BRIEF        Smart standby mode. Mstandby asserted when no more activity 
 *               on the USB master. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__MIDLEMODE__SMARTSTANDBY 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE__FORCEIDLE
 *
 * @BRIEF        Force Idle mode. Sidleack asserted after Midlereq assertion 
 *               - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE__FORCEIDLE 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE__NOIDLE
 *
 * @BRIEF        No idle mode. Sidleack never asserted. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE__NOIDLE 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE__SMARTIDLE
 *
 * @BRIEF        SmartIdle mode. Sidleack asserted after Midlereq assertion 
 *               when no more activity on the USB. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__SIDLEMODE__SMARTIDLE 0x2ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__ENABLEWAKEUP__DISABLED
 *
 * @BRIEF        Wakeup disabled - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__ENABLEWAKEUP__DISABLED 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__ENABLEWAKEUP__ENABLED
 *
 * @BRIEF        Wakeup enabled - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__ENABLEWAKEUP__ENABLED 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__SOFTRESET__SOFTRESET
 *
 * @BRIEF        Starts softreset sequence. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__SOFTRESET__SOFTRESET 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__AUTOIDLE__DISABLED
 *
 * @BRIEF        Clock always runnning - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__AUTOIDLE__DISABLED 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSCONFIG__AUTOIDLE__ENABLED
 *
 * @BRIEF        When no activity on OCP, clock is cut off. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSCONFIG__AUTOIDLE__ENABLED 0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSSTATUS__RESETDONE__ONGOING
 *
 * @BRIEF        On going reset - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSSTATUS__RESETDONE__ONGOING 0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_SYSSTATUS__RESETDONE__DONE
 *
 * @BRIEF        Reset is finished. - (Read) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_SYSSTATUS__RESETDONE__DONE  0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_INTERFSEL__PHYSEL__UMTI
 *
 * @BRIEF        PHY interface is 8-bit, UMTI+ level 3 - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_INTERFSEL__PHYSEL__UMTI     0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_INTERFSEL__PHYSEL__ULPI12
 *
 * @BRIEF        PHY interface is 12-pin, 8-bit SDR ULPI - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_INTERFSEL__PHYSEL__ULPI12   0x1ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   USB_OTGHS_32__OTG_INTERFSEL__PHYSEL__ULPI8
 *
 * @BRIEF        PHY interface is 8-pin, 4-bit DDR ULPI - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define USB_OTGHS_32__OTG_INTERFSEL__PHYSEL__ULPI8    0x2ul

#ifdef __cplusplus
}
#endif
#endif                                                     /* __USB_OTGHS_32_CRED_H 
                                                            */
