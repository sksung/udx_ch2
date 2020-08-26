/*******************************************************************************
 * Copyright (c) 2009 Texas Instruments Incorporated - http://www.ti.com/      *
 *                        ALL RIGHTS RESERVED                                  *
 *                                                                             *
 ******************************************************************************/

/*********************************************************************
* file: cslr_vps_sc_h.h
*
* Brief: This file contains the Register Description for vps_sc_h
*
*********************************************************************/
#ifndef _CSLR_VPS_SC_H_H_
#define _CSLR_VPS_SC_H_H_



/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 CFG_SC0;
    volatile Uint32 CFG_SC1;
    volatile Uint32 CFG_SC2;
    volatile Uint32 CFG_SC3;
    volatile Uint32 CFG_SC4;
    volatile Uint32 CFG_SC5;
    volatile Uint32 CFG_SC6;
    volatile Uint32 CFG_SC7;
    volatile Uint32 CFG_SC8;
    volatile Uint32 CFG_SC9;
    volatile Uint32 CFG_SC10;
    volatile Uint32 CFG_SC11;
    volatile Uint32 CFG_SC12;
    volatile Uint32 CFG_SC13;
    volatile Uint32 CFG_SC14;
    volatile Uint32 CFG_SC15;
    volatile Uint32 CFG_SC16;
    volatile Uint32 CFG_SC17;
    volatile Uint32 CFG_SC18;
    volatile Uint32 CFG_SC19;
    volatile Uint32 CFG_SC20;
    volatile Uint32 CFG_SC21;
    volatile Uint32 CFG_SC22;
    volatile Uint32 CFG_SC23;
    volatile Uint32 CFG_SC24;
    volatile Uint32 CFG_SC25;
    volatile Uint32 CFG_SC26;
    volatile Uint32 CFG_SC27;
    volatile Uint32 CFG_SC28;
    volatile Uint32 CFG_SC29;
    volatile Uint32 CFG_SC30;
    volatile Uint32 CFG_SC31;
} CSL_Vps_sc_hRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_Vps_sc_hRegs           *CSL_VpsSchRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* cfg_sc0 */

#define CSL_VPS_SC_H_CFG_SC0_CFG_AUTO_HS_MASK (0x00000040u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_AUTO_HS_SHIFT (0x00000006u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_DCM_2X_MASK (0x00000080u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_DCM_2X_SHIFT (0x00000007u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_DCM_4X_MASK (0x00000100u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_DCM_4X_SHIFT (0x00000008u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_ENABLE_EV_MASK (0x00000020u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_ENABLE_EV_SHIFT (0x00000005u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_ENABLE_SIN2_VER_INTP_MASK (0x00000800u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_ENABLE_SIN2_VER_INTP_SHIFT (0x0000000Bu)

#define CSL_VPS_SC_H_CFG_SC0_CFG_HP_BYPASS_MASK (0x00000200u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_HP_BYPASS_SHIFT (0x00000009u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_INTERLACE_I_MASK (0x00000400u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_INTERLACE_I_SHIFT (0x0000000Au)

#define CSL_VPS_SC_H_CFG_SC0_CFG_INTERLACE_O_MASK (0x00000001u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_INTERLACE_O_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_INVT_FID_MASK (0x00000008u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_INVT_FID_SHIFT (0x00000003u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_LINEAR_MASK (0x00000002u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_LINEAR_SHIFT (0x00000001u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_SC_BYPASS_MASK (0x00000004u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_SC_BYPASS_SHIFT (0x00000002u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_TRIM_MASK (0x00008000u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_TRIM_SHIFT (0x0000000Fu)

#define CSL_VPS_SC_H_CFG_SC0_CFG_USE_RAV_MASK (0x00000010u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_USE_RAV_SHIFT (0x00000004u)

#define CSL_VPS_SC_H_CFG_SC0_CFG_Y_PK_EN_MASK (0x00004000u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_Y_PK_EN_SHIFT (0x0000000Eu)

#define CSL_VPS_SC_H_CFG_SC0_CFG_SELFGEN_FID_MASK (0x00010000u)
#define CSL_VPS_SC_H_CFG_SC0_CFG_SELFGEN_FID_SHIFT (0x00000010u)


/* cfg_sc1 */

#define CSL_VPS_SC_H_CFG_SC1_CFG_ROW_ACC_INC_MASK (0x07FFFFFFu)
#define CSL_VPS_SC_H_CFG_SC1_CFG_ROW_ACC_INC_SHIFT (0x00000000u)


/* cfg_sc2 */

#define CSL_VPS_SC_H_CFG_SC2_CFG_ROW_ACC_OFFSET_MASK (0x0FFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC2_CFG_ROW_ACC_OFFSET_SHIFT (0x00000000u)


/* cfg_sc3 */

#define CSL_VPS_SC_H_CFG_SC3_CFG_ROW_ACC_OFFSET_B_MASK (0x0FFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC3_CFG_ROW_ACC_OFFSET_B_SHIFT (0x00000000u)


/* cfg_sc4 */

#define CSL_VPS_SC_H_CFG_SC4_CFG_LIN_ACC_INC_U_MASK (0x07000000u)
#define CSL_VPS_SC_H_CFG_SC4_CFG_LIN_ACC_INC_U_SHIFT (0x00000018u)

#define CSL_VPS_SC_H_CFG_SC4_CFG_NLIN_ACC_INIT_U_MASK (0x70000000u)
#define CSL_VPS_SC_H_CFG_SC4_CFG_NLIN_ACC_INIT_U_SHIFT (0x0000001Cu)

#define CSL_VPS_SC_H_CFG_SC4_CFG_TAR_H_MASK (0x000007FFu)
#define CSL_VPS_SC_H_CFG_SC4_CFG_TAR_H_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC4_CFG_TAR_W_MASK (0x007FF000u)
#define CSL_VPS_SC_H_CFG_SC4_CFG_TAR_W_SHIFT (0x0000000Cu)


/* cfg_sc5 */

#define CSL_VPS_SC_H_CFG_SC5_CFG_NLIN_ACC_INC_U_MASK (0x07000000u)
#define CSL_VPS_SC_H_CFG_SC5_CFG_NLIN_ACC_INC_U_SHIFT (0x00000018u)

#define CSL_VPS_SC_H_CFG_SC5_CFG_SRC_H_MASK (0x000007FFu)
#define CSL_VPS_SC_H_CFG_SC5_CFG_SRC_H_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC5_CFG_SRC_W_MASK (0x007FF000u)
#define CSL_VPS_SC_H_CFG_SC5_CFG_SRC_W_SHIFT (0x0000000Cu)


/* cfg_sc6 */

#define CSL_VPS_SC_H_CFG_SC6_CFG_ROW_ACC_INIT_RAV_MASK (0x000003FFu)
#define CSL_VPS_SC_H_CFG_SC6_CFG_ROW_ACC_INIT_RAV_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC6_CFG_ROW_ACC_INIT_RAV_B_MASK (0x000FFC00u)
#define CSL_VPS_SC_H_CFG_SC6_CFG_ROW_ACC_INIT_RAV_B_SHIFT (0x0000000Au)


/* cfg_sc7 */

#define CSL_VPS_SC_H_CFG_SC7_CFG_SC7_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC7_CFG_SC7_SHIFT (0x00000000u)

/* cfg_sc8 */

#define CSL_VPS_SC_H_CFG_SC8_CFG_NLIN_LEFT_MASK (0x000007FFu)
#define CSL_VPS_SC_H_CFG_SC8_CFG_NLIN_LEFT_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC8_CFG_NLIN_RIGHT_MASK (0x007FF000u)
#define CSL_VPS_SC_H_CFG_SC8_CFG_NLIN_RIGHT_SHIFT (0x0000000Cu)


/* cfg_sc9 */

#define CSL_VPS_SC_H_CFG_SC9_CFG_LIN_ACC_INC_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC9_CFG_LIN_ACC_INC_SHIFT (0x00000000u)


/* cfg_sc10 */

#define CSL_VPS_SC_H_CFG_SC10_CFG_NLIN_ACC_INIT_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC10_CFG_NLIN_ACC_INIT_SHIFT (0x00000000u)


/* cfg_sc11 */

#define CSL_VPS_SC_H_CFG_SC11_CFG_NLIN_ACC_INC_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC11_CFG_NLIN_ACC_INC_SHIFT (0x00000000u)


/* cfg_sc12 */

#define CSL_VPS_SC_H_CFG_SC12_CFG_COL_ACC_OFFSET_MASK (0x01FFFFFFu)
#define CSL_VPS_SC_H_CFG_SC12_CFG_COL_ACC_OFFSET_SHIFT (0x00000000u)


/* cfg_sc13 */

#define CSL_VPS_SC_H_CFG_SC13_CFG_CHROMA_INTP_THR_MASK (0x003FF000u)
#define CSL_VPS_SC_H_CFG_SC13_CFG_CHROMA_INTP_THR_SHIFT (0x0000000Cu)

#define CSL_VPS_SC_H_CFG_SC13_CFG_DELTA_CHROMA_THR_MASK (0x0F000000u)
#define CSL_VPS_SC_H_CFG_SC13_CFG_DELTA_CHROMA_THR_SHIFT (0x00000018u)

#define CSL_VPS_SC_H_CFG_SC13_CFG_SC_FACTOR_RAV_MASK (0x000003FFu)
#define CSL_VPS_SC_H_CFG_SC13_CFG_SC_FACTOR_RAV_SHIFT (0x00000000u)


/* cfg_sc14 */

#define CSL_VPS_SC_H_CFG_SC14_CFG_SC14_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC14_CFG_SC14_SHIFT (0x00000000u)

/* cfg_sc15 */

#define CSL_VPS_SC_H_CFG_SC15_CFG_SC15_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC15_CFG_SC15_SHIFT (0x00000000u)

/* cfg_sc16 */

#define CSL_VPS_SC_H_CFG_SC16_CFG_SC16_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC16_CFG_SC16_SHIFT (0x00000000u)

/* cfg_sc17 */

#define CSL_VPS_SC_H_CFG_SC17_CFG_DELTA_EV_THR_MASK (0xF0000000u)
#define CSL_VPS_SC_H_CFG_SC17_CFG_DELTA_EV_THR_SHIFT (0x0000001Cu)

#define CSL_VPS_SC_H_CFG_SC17_CFG_DELTA_LUMA_THR_MASK (0x0F000000u)
#define CSL_VPS_SC_H_CFG_SC17_CFG_DELTA_LUMA_THR_SHIFT (0x00000018u)

#define CSL_VPS_SC_H_CFG_SC17_CFG_EV_THR_MASK (0x003FF000u)
#define CSL_VPS_SC_H_CFG_SC17_CFG_EV_THR_SHIFT (0x0000000Cu)


/* cfg_sc18 */

#define CSL_VPS_SC_H_CFG_SC18_CFG_CONF_DEFAULT_MASK (0x01FF0000u)
#define CSL_VPS_SC_H_CFG_SC18_CFG_CONF_DEFAULT_SHIFT (0x00000010u)

#define CSL_VPS_SC_H_CFG_SC18_CFG_HS_FACTOR_MASK (0x000003FFu)
#define CSL_VPS_SC_H_CFG_SC18_CFG_HS_FACTOR_SHIFT (0x00000000u)


/* cfg_sc19 */

#define CSL_VPS_SC_H_CFG_SC19_CFG_HPF_COEF0_MASK (0x000000FFu)
#define CSL_VPS_SC_H_CFG_SC19_CFG_HPF_COEF0_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC19_CFG_HPF_COEF1_MASK (0x0000FF00u)
#define CSL_VPS_SC_H_CFG_SC19_CFG_HPF_COEF1_SHIFT (0x00000008u)

#define CSL_VPS_SC_H_CFG_SC19_CFG_HPF_COEF2_MASK (0x00FF0000u)
#define CSL_VPS_SC_H_CFG_SC19_CFG_HPF_COEF2_SHIFT (0x00000010u)

#define CSL_VPS_SC_H_CFG_SC19_CFG_HPF_COEF3_MASK (0xFF000000u)
#define CSL_VPS_SC_H_CFG_SC19_CFG_HPF_COEF3_SHIFT (0x00000018u)


/* cfg_sc20 */

#define CSL_VPS_SC_H_CFG_SC20_CFG_HPF_COEF4_MASK (0x000000FFu)
#define CSL_VPS_SC_H_CFG_SC20_CFG_HPF_COEF4_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC20_CFG_HPF_COEF5_MASK (0x0000FF00u)
#define CSL_VPS_SC_H_CFG_SC20_CFG_HPF_COEF5_SHIFT (0x00000008u)

#define CSL_VPS_SC_H_CFG_SC20_CFG_HPF_NORM_SHIFT_MASK (0x00070000u)
#define CSL_VPS_SC_H_CFG_SC20_CFG_HPF_NORM_SHIFT_SHIFT (0x00000010u)

#define CSL_VPS_SC_H_CFG_SC20_CFG_NL_LIMIT_MASK (0x1FF00000u)
#define CSL_VPS_SC_H_CFG_SC20_CFG_NL_LIMIT_SHIFT (0x00000014u)


/* cfg_sc21 */

#define CSL_VPS_SC_H_CFG_SC21_CFG_NL_LO_SLOPE_MASK (0x00FF0000u)
#define CSL_VPS_SC_H_CFG_SC21_CFG_NL_LO_SLOPE_SHIFT (0x00000010u)

#define CSL_VPS_SC_H_CFG_SC21_CFG_NL_LO_THR_MASK (0x000001FFu)
#define CSL_VPS_SC_H_CFG_SC21_CFG_NL_LO_THR_SHIFT (0x00000000u)


/* cfg_sc22 */

#define CSL_VPS_SC_H_CFG_SC22_CFG_NL_HI_SLOPE_SHIFT_MASK (0x00070000u)
#define CSL_VPS_SC_H_CFG_SC22_CFG_NL_HI_SLOPE_SHIFT_SHIFT (0x00000010u)

#define CSL_VPS_SC_H_CFG_SC22_CFG_NL_HI_THR_MASK (0x000001FFu)
#define CSL_VPS_SC_H_CFG_SC22_CFG_NL_HI_THR_SHIFT (0x00000000u)


/* cfg_sc23 */

#define CSL_VPS_SC_H_CFG_SC23_CFG_GRADIENT_THR_MASK (0x000007FFu)
#define CSL_VPS_SC_H_CFG_SC23_CFG_GRADIENT_THR_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC23_CFG_GRADIENT_THR_RANGE_MASK (0x0000F000u)
#define CSL_VPS_SC_H_CFG_SC23_CFG_GRADIENT_THR_RANGE_SHIFT (0x0000000Cu)

#define CSL_VPS_SC_H_CFG_SC23_CFG_MIN_GY_THR_MASK (0x03FF0000u)
#define CSL_VPS_SC_H_CFG_SC23_CFG_MIN_GY_THR_SHIFT (0x00000010u)

#define CSL_VPS_SC_H_CFG_SC23_CFG_MIN_GY_THR_RANGE_MASK (0xF0000000u)
#define CSL_VPS_SC_H_CFG_SC23_CFG_MIN_GY_THR_RANGE_SHIFT (0x0000001Cu)


/* cfg_sc24 */

#define CSL_VPS_SC_H_CFG_SC24_CFG_ORG_H_MASK (0x000007FFu)
#define CSL_VPS_SC_H_CFG_SC24_CFG_ORG_H_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC24_CFG_ORG_W_MASK (0x07FF0000u)
#define CSL_VPS_SC_H_CFG_SC24_CFG_ORG_W_SHIFT (0x00000010u)


/* cfg_sc25 */

#define CSL_VPS_SC_H_CFG_SC25_CFG_OFF_H_MASK (0x000007FFu)
#define CSL_VPS_SC_H_CFG_SC25_CFG_OFF_H_SHIFT (0x00000000u)

#define CSL_VPS_SC_H_CFG_SC25_CFG_OFF_W_MASK (0x07FF0000u)
#define CSL_VPS_SC_H_CFG_SC25_CFG_OFF_W_SHIFT (0x00000010u)


/* cfg_sc26 */

#define CSL_VPS_SC_H_CFG_SC26_CFG_SC26_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC26_CFG_SC26_SHIFT (0x00000000u)

/* cfg_sc27 */

#define CSL_VPS_SC_H_CFG_SC27_CFG_SC27_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC27_CFG_SC27_SHIFT (0x00000000u)

/* cfg_sc28 */

#define CSL_VPS_SC_H_CFG_SC28_CFG_SC28_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC28_CFG_SC28_SHIFT (0x00000000u)

/* cfg_sc29 */

#define CSL_VPS_SC_H_CFG_SC29_CFG_SC29_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC29_CFG_SC29_SHIFT (0x00000000u)

/* cfg_sc30 */

#define CSL_VPS_SC_H_CFG_SC30_CFG_SC30_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC30_CFG_SC30_SHIFT (0x00000000u)

/* cfg_sc31 */

#define CSL_VPS_SC_H_CFG_SC31_CFG_SC31_MASK (0xFFFFFFFFu)
#define CSL_VPS_SC_H_CFG_SC31_CFG_SC31_SHIFT (0x00000000u)

#endif
