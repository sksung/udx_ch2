/** ==================================================================
 *  @file   rot_cred.h                                                  
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
 *  @Component:   ROT
 *
 *  @Filename:    rot_cred.h
 *
 *  @Description: OCP port 
 *
 *  Generated by: Socrates CRED generator prototype
 *
    *//* ====================================================================== */

#ifndef __ROT_CRED_H
#define __ROT_CRED_H

#ifdef __cplusplus
extern "C" {
#endif

    /* 
     * Instance ROT of component ROT mapped in MONICA at address 0x55060700
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
     *  List of Register arrays for component ROT
     *
     */

    /* 
     *  List of bundle arrays for component ROT
     *
     */

    /* 
     *  List of bundles for component ROT
     *
     */

    /* 
     * List of registers for component ROT
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_REVISION
 *
 * @BRIEF        Module revision 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_REVISION                                  0x0ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CTRL
 *
 * @BRIEF        Control 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CTRL                                      0x4ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CFG
 *
 * @BRIEF        Configuration 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CFG                                       0x8ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_BLKSZ
 *
 * @BRIEF        Block size 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_BLKSZ                                     0xCul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_SRC_START1
 *
 * @BRIEF        Source starting address 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_SRC_START1                                0x10ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_SRC_LOFST
 *
 * @BRIEF        Source line offset 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_SRC_LOFST                                 0x14ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_DST_START1
 *
 * @BRIEF        Destination starting address 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_DST_START1                                0x18ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_DST_LOFST
 *
 * @BRIEF        Destination line offset 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_DST_LOFST                                 0x1Cul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_SRC_START2
 *
 * @BRIEF        Source starting address 2 (only form YUV420 FMT=2) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_SRC_START2                                0x20ul

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_DST_START2
 *
 * @BRIEF        Destination starting address 2 (only form YUV420 FMT=2) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_DST_START2                                0x24ul

    /* 
     * List of register bitfields for component ROT
     *
     */

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_REVISION__REV   
 *
 * @BRIEF        Module revision 
 *               [7:4] Major revision 
 *               [3:0] Minor revision - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_REVISION__REV                        BITFIELD(7, 0)
#define ROT__ROT_REVISION__REV__POS                   0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CTRL__BUSY   
 *
 * @BRIEF        Idle/busy status (read-only) 
 *               0 = idle, 1 = busy - (RO) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CTRL__BUSY                           BITFIELD(15, 15)
#define ROT__ROT_CTRL__BUSY__POS                      15

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CTRL__EN   
 *
 * @BRIEF        Module enable, writing 1 starts the module, reading back 0 
 *               always - (WO) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CTRL__EN                             BITFIELD(0, 0)
#define ROT__ROT_CTRL__EN__POS                        0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CFG__NBLKS   
 *
 * @BRIEF        Number of blocks minus 1 
 *               0: 1 block, 1: 2 blocks etc - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CFG__NBLKS                           BITFIELD(15, 12)
#define ROT__ROT_CFG__NBLKS__POS                      12

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CFG__AUTOGATING   
 *
 * @BRIEF        Internal OCP and functional clock gating 
 *               0: OCP and functional clocks are free-running 
 *               1: Automatic clock gating is applied, based on the OCP 
 *               interface activity for the interface clock, and on the 
 *               functional activity for the functional clocks. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CFG__AUTOGATING                      BITFIELD(9, 9)
#define ROT__ROT_CFG__AUTOGATING__POS                 9

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CFG__TRIG_SRC   
 *
 * @BRIEF        Trigger source 
 *               0 = MMR write 
 *               1 = hardware start signal - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CFG__TRIG_SRC                        BITFIELD(8, 8)
#define ROT__ROT_CFG__TRIG_SRC__POS                   8

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CFG__FMT   
 *
 * @BRIEF        Data format 
 *               0 = 8-bit data 
 *               1 = 16-bit data 
 *               2 = 32-bit data 
 *               3 = YUV 422 data 
 *               4 = YUV 420 data - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CFG__FMT                             BITFIELD(6, 4)
#define ROT__ROT_CFG__FMT__POS                        4

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_CFG__OP   
 *
 * @BRIEF        Operation 
 *               0 = rotate 0 degree 
 *               1 = rotate 90 degrees 
 *               2 = rotate 180 degrees 
 *               3 = rotate 270 degrees 
 *               4 = data shift (FMT=0) 
 *               5 = horizontal circular (FMT=0) shift - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_CFG__OP                              BITFIELD(2, 0)
#define ROT__ROT_CFG__OP__POS                         0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_BLKSZ__BLKH   
 *
 * @BRIEF        Block height, in pixels (YUV420/422) or number of rows 
 *               (8-/16-/32-bit). 
 *               Should be a multiple of 8, at least 8, for rotation. 
 *               Should be at least 1 for data shifting. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_BLKSZ__BLKH                          BITFIELD(27, 16)
#define ROT__ROT_BLKSZ__BLKH__POS                     16

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_BLKSZ__BLKW   
 *
 * @BRIEF        Block width, in pixels (YUV420/422) or data units 
 *               (8-/16-/32-bit). 
 *               Should be a multiple of 8, at least 8, for rotation. 
 *               Should be at least 4 for data shifting. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_BLKSZ__BLKW                          BITFIELD(11, 0)
#define ROT__ROT_BLKSZ__BLKW__POS                     0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_SRC_START1__ADDR   
 *
 * @BRIEF        Byte address. 
 *               Should be a multiple of 8 for rotation. 
 *               No constraint for data shifting. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_SRC_START1__ADDR                     BITFIELD(13, 0)
#define ROT__ROT_SRC_START1__ADDR__POS                0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_SRC_LOFST__LOFST   
 *
 * @BRIEF        Line offset in bytes 
 *               Should be a multiple of 8 for rotation and normal data 
 *               shifting. 
 *               Should be a power of 2 and at least 32 for horizontal 
 *               circular shifting. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_SRC_LOFST__LOFST                     BITFIELD(15, 0)
#define ROT__ROT_SRC_LOFST__LOFST__POS                0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_DST_START1__ADDR   
 *
 * @BRIEF        Byte address. 
 *               Should be a multiple of 8 for rotation. 
 *               No constraint for data shifting. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_DST_START1__ADDR                     BITFIELD(13, 0)
#define ROT__ROT_DST_START1__ADDR__POS                0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_DST_LOFST__LOFST   
 *
 * @BRIEF        Line offset in bytes 
 *               Should be a multiple of 8 for rotation and normal data 
 *               shifting. 
 *               Should be a power of 2 and at least 32 for horizontal 
 *               circular shifting. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_DST_LOFST__LOFST                     BITFIELD(15, 0)
#define ROT__ROT_DST_LOFST__LOFST__POS                0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_SRC_START2__ADDR   
 *
 * @BRIEF        Byte address, should be a multiple of 8. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_SRC_START2__ADDR                     BITFIELD(13, 0)
#define ROT__ROT_SRC_START2__ADDR__POS                0

                                                                             /*-------------------------------------------------------------------------*//**
 * @DEFINITION   ROT__ROT_DST_START2__ADDR   
 *
 * @BRIEF        Byte address, should be a multiple of 8. - (RW) 
 *
    *//*------------------------------------------------------------------------ */
#define ROT__ROT_DST_START2__ADDR                     BITFIELD(13, 0)
#define ROT__ROT_DST_START2__ADDR__POS                0

    /* 
     * List of register bitfields values for component ROT
     *
     */

#ifdef __cplusplus
}
#endif
#endif                                                     /* __ROT_CRED_H */
