/*******************************************************************************
 *                                                                             *
 * Copyright (c) 2009 Texas Instruments Incorporated - http://www.ti.com/      *
 *                        ALL RIGHTS RESERVED                                  *
 *                                                                             *
 ******************************************************************************/

/*********************************************************************
* file: cslr_vps_sd_venc.h
*
* Brief: This file contains the Register Description for vps_sd_venc
*
*********************************************************************/
#ifndef _CSLR_VPS_SD_VENC_H_
#define _CSLR_VPS_SD_VENC_H_



/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint32 VMOD;
    volatile Uint32 SLAVE;
    volatile Uint32 SIZE;
    volatile Uint32 POL;
    volatile Uint32 DTVS0;
    volatile Uint32 DTVS1;
    volatile Uint32 DTVS2;
    volatile Uint32 DTVS3;
    volatile Uint32 DTVS4;
    volatile Uint32 DTVS5;
    volatile Uint32 DTVS6;
    volatile Uint32 DTVS7;
    volatile Uint32 DVOS0;
    volatile Uint32 DVOS1;
    volatile Uint32 DVOS2;
    volatile Uint32 DVOS3;
    volatile Uint32 DVOS4;
    volatile Uint32 DVOS5;
    volatile Uint32 DVOS6;
    volatile Uint32 DVOS7;
    volatile Uint32 TVDETGP0;
    volatile Uint32 TVDETGP1;
    volatile Uint32 IRQ0;
    volatile Uint8 RSVD0[32];
    volatile Uint32 ESTAT;
    volatile Uint32 ECTL;
    volatile Uint32 ETMG0;
    volatile Uint32 ETMG1;
    volatile Uint32 ETMG2;
    volatile Uint32 ETMG3;
    volatile Uint32 ETMG4;
    volatile Uint32 CVBS0;
    volatile Uint32 CVBS1;
    volatile Uint32 CMPNT0;
    volatile Uint32 CMPNT1;
    volatile Uint32 CCSC0;
    volatile Uint32 CCSC1;
    volatile Uint32 CCSC2;
    volatile Uint32 CCSC3;
    volatile Uint32 CCSC4;
    volatile Uint32 CCSC5;
    volatile Uint32 CCSC6;
    volatile Uint32 CCSC7;
    volatile Uint32 CCSC8;
    volatile Uint32 MCSC0;
    volatile Uint32 MCSC1;
    volatile Uint32 MCSC2;
    volatile Uint32 MCSC3;
    volatile Uint32 MCSC4;
    volatile Uint32 MCSC5;
    volatile Uint32 MCSC6;
    volatile Uint32 MCSC7;
    volatile Uint32 MCSC8;
    volatile Uint32 CYGCLP;
    volatile Uint32 CUBCLP;
    volatile Uint32 CVRCLP;
    volatile Uint32 MYGCLP;
    volatile Uint32 MUBCLP;
    volatile Uint32 MVRCLP;
    volatile Uint32 YLPF0;
    volatile Uint32 YLPF1;
    volatile Uint32 CLPF0;
    volatile Uint32 CLPF1;
    volatile Uint32 UPF0;
    volatile Uint32 UPF1;
    volatile Uint32 L21CTL;
    volatile Uint32 L21DO;
    volatile Uint32 L21DE;
    volatile Uint32 WSS;
    volatile Uint32 VIDBCTL;
    volatile Uint32 VIDBDATA0;
    volatile Uint32 VIDBDATA1;
    volatile Uint32 VIDBDATA2;
    volatile Uint32 VIDBDATA3;
    volatile Uint32 SCCTL0;
    volatile Uint32 SCCTL1;
    volatile Uint32 DACSEL;
    volatile Uint32 DUPF0;
    volatile Uint32 DUPF1;
    volatile Uint32 DACTST;
    volatile Uint8 RSVD1[128];
    volatile Uint32 MACR00;
    volatile Uint32 MACR01;
    volatile Uint32 MACR02;
    volatile Uint32 MACR03;
    volatile Uint32 MACR04;
    volatile Uint32 MACR05;
    volatile Uint8 RSVD2[4];
    volatile Uint32 VTEST;
} CSL_Vps_sd_vencRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_Vps_sd_vencRegs        *CSL_VpsSdVencRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* pid */

#define CSL_VPS_SD_VENC_PID_PID_MASK     (0xFFFFFFFFu)
#define CSL_VPS_SD_VENC_PID_PID_SHIFT    (0x00000000u)


/* vmod */

#define CSL_VPS_SD_VENC_VMOD_CBAR_MASK   (0x00000010u)
#define CSL_VPS_SD_VENC_VMOD_CBAR_SHIFT  (0x00000004u)

#define CSL_VPS_SD_VENC_VMOD_DIIV_MASK   (0x00000020u)
#define CSL_VPS_SD_VENC_VMOD_DIIV_SHIFT  (0x00000005u)

#define CSL_VPS_SD_VENC_VMOD_ITLC_MASK   (0x00000004u)
#define CSL_VPS_SD_VENC_VMOD_ITLC_SHIFT  (0x00000002u)

#define CSL_VPS_SD_VENC_VMOD_RSV_MASK    (0x00000002u)
#define CSL_VPS_SD_VENC_VMOD_RSV_SHIFT   (0x00000001u)

#define CSL_VPS_SD_VENC_VMOD_UEL_MASK    (0x00000008u)
#define CSL_VPS_SD_VENC_VMOD_UEL_SHIFT   (0x00000003u)

#define CSL_VPS_SD_VENC_VMOD_VIEN_MASK   (0x00000001u)
#define CSL_VPS_SD_VENC_VMOD_VIEN_SHIFT  (0x00000000u)


/* slave */

#define CSL_VPS_SD_VENC_SLAVE_FIP_MASK   (0x00000008u)
#define CSL_VPS_SD_VENC_SLAVE_FIP_SHIFT  (0x00000003u)

#define CSL_VPS_SD_VENC_SLAVE_FMD_MASK   (0x00000030u)
#define CSL_VPS_SD_VENC_SLAVE_FMD_SHIFT  (0x00000004u)

#define CSL_VPS_SD_VENC_SLAVE_HIP_MASK   (0x00000002u)
#define CSL_VPS_SD_VENC_SLAVE_HIP_SHIFT  (0x00000001u)

#define CSL_VPS_SD_VENC_SLAVE_SLV_MASK   (0x00000001u)
#define CSL_VPS_SD_VENC_SLAVE_SLV_SHIFT  (0x00000000u)

#define CSL_VPS_SD_VENC_SLAVE_VIP_MASK   (0x00000004u)
#define CSL_VPS_SD_VENC_SLAVE_VIP_SHIFT  (0x00000002u)


/* size */

#define CSL_VPS_SD_VENC_SIZE_HITV_MASK   (0x00001FFFu)
#define CSL_VPS_SD_VENC_SIZE_HITV_SHIFT  (0x00000000u)

#define CSL_VPS_SD_VENC_SIZE_VITV_MASK   (0x1FFF0000u)
#define CSL_VPS_SD_VENC_SIZE_VITV_SHIFT  (0x00000010u)


/* pol */

#define CSL_VPS_SD_VENC_POL_DTV_AVID_POL_MASK (0x00000008u)
#define CSL_VPS_SD_VENC_POL_DTV_AVID_POL_SHIFT (0x00000003u)

#define CSL_VPS_SD_VENC_POL_DTV_FID_POL_MASK (0x00000004u)
#define CSL_VPS_SD_VENC_POL_DTV_FID_POL_SHIFT (0x00000002u)

#define CSL_VPS_SD_VENC_POL_DTV_HS_POL_MASK (0x00000001u)
#define CSL_VPS_SD_VENC_POL_DTV_HS_POL_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_POL_DTV_VS_POL_MASK (0x00000002u)
#define CSL_VPS_SD_VENC_POL_DTV_VS_POL_SHIFT (0x00000001u)

#define CSL_VPS_SD_VENC_POL_DVO_AVID_POL_MASK (0x00000080u)
#define CSL_VPS_SD_VENC_POL_DVO_AVID_POL_SHIFT (0x00000007u)

#define CSL_VPS_SD_VENC_POL_DVO_FID_POL_MASK (0x00000040u)
#define CSL_VPS_SD_VENC_POL_DVO_FID_POL_SHIFT (0x00000006u)

#define CSL_VPS_SD_VENC_POL_DVO_HS_POL_MASK (0x00000010u)
#define CSL_VPS_SD_VENC_POL_DVO_HS_POL_SHIFT (0x00000004u)

#define CSL_VPS_SD_VENC_POL_DVO_VS_POL_MASK (0x00000020u)
#define CSL_VPS_SD_VENC_POL_DVO_VS_POL_SHIFT (0x00000005u)

#define CSL_VPS_SD_VENC_POL_TVDETGP_POL_MASK (0x00000100u)
#define CSL_VPS_SD_VENC_POL_TVDETGP_POL_SHIFT (0x00000008u)


/* dtvs0 */

#define CSL_VPS_SD_VENC_DTVS0_DTV_HS_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DTVS0_DTV_HS_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DTVS0_DTV_HS_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DTVS0_DTV_HS_H_STP_SHIFT (0x00000010u)


/* dtvs1 */

#define CSL_VPS_SD_VENC_DTVS1_DTV_VS_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DTVS1_DTV_VS_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DTVS1_DTV_VS_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DTVS1_DTV_VS_H_STP_SHIFT (0x00000010u)


/* dtvs2 */

#define CSL_VPS_SD_VENC_DTVS2_DTV_VS_V_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DTVS2_DTV_VS_V_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DTVS2_DTV_VS_V_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DTVS2_DTV_VS_V_STP_SHIFT (0x00000010u)


/* dtvs3 */

#define CSL_VPS_SD_VENC_DTVS3_DTV_FID_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DTVS3_DTV_FID_H_STA_SHIFT (0x00000000u)


/* dtvs4 */

#define CSL_VPS_SD_VENC_DTVS4_DTV_FID_F_STA0_MASK (0x00002000u)
#define CSL_VPS_SD_VENC_DTVS4_DTV_FID_F_STA0_SHIFT (0x0000000Du)

#define CSL_VPS_SD_VENC_DTVS4_DTV_FID_F_STA1_MASK (0x20000000u)
#define CSL_VPS_SD_VENC_DTVS4_DTV_FID_F_STA1_SHIFT (0x0000001Du)

#define CSL_VPS_SD_VENC_DTVS4_DTV_FID_V_STA0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DTVS4_DTV_FID_V_STA0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DTVS4_DTV_FID_V_STA1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DTVS4_DTV_FID_V_STA1_SHIFT (0x00000010u)


/* dtvs5 */

#define CSL_VPS_SD_VENC_DTVS5_DTV_AVID_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DTVS5_DTV_AVID_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DTVS5_DTV_AVID_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DTVS5_DTV_AVID_H_STP_SHIFT (0x00000010u)


/* dtvs6 */

#define CSL_VPS_SD_VENC_DTVS6_DTV_AVID_V_STA0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DTVS6_DTV_AVID_V_STA0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DTVS6_DTV_AVID_V_STP0_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DTVS6_DTV_AVID_V_STP0_SHIFT (0x00000010u)


/* dtvs7 */

#define CSL_VPS_SD_VENC_DTVS7_DTV_AVID_V_STA1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DTVS7_DTV_AVID_V_STA1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DTVS7_DTV_AVID_V_STP1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DTVS7_DTV_AVID_V_STP1_SHIFT (0x00000010u)


/* dvos0 */

#define CSL_VPS_SD_VENC_DVOS0_DVO_HS_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DVOS0_DVO_HS_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DVOS0_DVO_HS_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DVOS0_DVO_HS_H_STP_SHIFT (0x00000010u)


/* dvos1 */

#define CSL_VPS_SD_VENC_DVOS1_DVO_VS_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DVOS1_DVO_VS_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DVOS1_DVO_VS_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DVOS1_DVO_VS_H_STP_SHIFT (0x00000010u)


/* dvos2 */

#define CSL_VPS_SD_VENC_DVOS2_DVO_VS_V_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DVOS2_DVO_VS_V_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DVOS2_DVO_VS_V_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DVOS2_DVO_VS_V_STP_SHIFT (0x00000010u)


/* dvos3 */

#define CSL_VPS_SD_VENC_DVOS3_DVO_DELAY_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DVOS3_DVO_DELAY_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_DVOS3_DVO_FID_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DVOS3_DVO_FID_H_STA_SHIFT (0x00000000u)


/* dvos4 */

#define CSL_VPS_SD_VENC_DVOS4_DVO_FID_F_STA0_MASK (0x00002000u)
#define CSL_VPS_SD_VENC_DVOS4_DVO_FID_F_STA0_SHIFT (0x0000000Du)

#define CSL_VPS_SD_VENC_DVOS4_DVO_FID_F_STA1_MASK (0x20000000u)
#define CSL_VPS_SD_VENC_DVOS4_DVO_FID_F_STA1_SHIFT (0x0000001Du)

#define CSL_VPS_SD_VENC_DVOS4_DVO_FID_V_STA0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DVOS4_DVO_FID_V_STA0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DVOS4_DVO_FID_V_STA1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DVOS4_DVO_FID_V_STA1_SHIFT (0x00000010u)


/* dvos5 */

#define CSL_VPS_SD_VENC_DVOS5_DVO_AVID_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DVOS5_DVO_AVID_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DVOS5_DVO_AVID_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DVOS5_DVO_AVID_H_STP_SHIFT (0x00000010u)


/* dvos6 */

#define CSL_VPS_SD_VENC_DVOS6_DVO_AVID_V_STA0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DVOS6_DVO_AVID_V_STA0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DVOS6_DVO_AVID_V_STP0_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DVOS6_DVO_AVID_V_STP0_SHIFT (0x00000010u)


/* dvos7 */

#define CSL_VPS_SD_VENC_DVOS7_DVO_AVID_V_STA1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_DVOS7_DVO_AVID_V_STA1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DVOS7_DVO_AVID_V_STP1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_DVOS7_DVO_AVID_V_STP1_SHIFT (0x00000010u)


/* tvdetgp0 */

#define CSL_VPS_SD_VENC_TVDETGP0_TVDETGP_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_TVDETGP0_TVDETGP_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_TVDETGP0_TVDETGP_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_TVDETGP0_TVDETGP_H_STP_SHIFT (0x00000010u)


/* tvdetgp1 */

#define CSL_VPS_SD_VENC_TVDETGP1_TVDETGP_V_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_TVDETGP1_TVDETGP_V_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_TVDETGP1_TVDETGP_V_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_TVDETGP1_TVDETGP_V_STP_SHIFT (0x00000010u)


/* irq0 */

#define CSL_VPS_SD_VENC_IRQ0_IRQ_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_IRQ0_IRQ_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_IRQ0_IRQ_V_STA_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_IRQ0_IRQ_V_STA_SHIFT (0x00000010u)


/* estat */

#define CSL_VPS_SD_VENC_ESTAT_CAEST_MASK (0x00000002u)
#define CSL_VPS_SD_VENC_ESTAT_CAEST_SHIFT (0x00000001u)

#define CSL_VPS_SD_VENC_ESTAT_CAOST_MASK (0x00000001u)
#define CSL_VPS_SD_VENC_ESTAT_CAOST_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_ESTAT_FIDST_MASK (0x00000010u)
#define CSL_VPS_SD_VENC_ESTAT_FIDST_SHIFT (0x00000004u)


/* ectl */

#define CSL_VPS_SD_VENC_ECTL_BLS_MASK    (0x00000010u)
#define CSL_VPS_SD_VENC_ECTL_BLS_SHIFT   (0x00000004u)

#define CSL_VPS_SD_VENC_ECTL_DUPS_MASK   (0x00000004u)
#define CSL_VPS_SD_VENC_ECTL_DUPS_SHIFT  (0x00000002u)

#define CSL_VPS_SD_VENC_ECTL_FMT_MASK    (0x00000F00u)
#define CSL_VPS_SD_VENC_ECTL_FMT_SHIFT   (0x00000008u)

#define CSL_VPS_SD_VENC_ECTL_GAM_MASK    (0x00000001u)
#define CSL_VPS_SD_VENC_ECTL_GAM_SHIFT   (0x00000000u)

#define CSL_VPS_SD_VENC_ECTL_PXLR_MASK   (0x00000040u)
#define CSL_VPS_SD_VENC_ECTL_PXLR_SHIFT  (0x00000006u)

#define CSL_VPS_SD_VENC_ECTL_SVSW_MASK   (0x00000008u)
#define CSL_VPS_SD_VENC_ECTL_SVSW_SHIFT  (0x00000003u)

#define CSL_VPS_SD_VENC_ECTL_UPS_MASK    (0x00000002u)
#define CSL_VPS_SD_VENC_ECTL_UPS_SHIFT   (0x00000001u)

#define CSL_VPS_SD_VENC_ECTL_VBIEN_MASK  (0x00000020u)
#define CSL_VPS_SD_VENC_ECTL_VBIEN_SHIFT (0x00000005u)


/* etmg0 */

#define CSL_VPS_SD_VENC_ETMG0_AV_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_ETMG0_AV_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_ETMG0_AV_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_ETMG0_AV_H_STP_SHIFT (0x00000010u)


/* etmg1 */

#define CSL_VPS_SD_VENC_ETMG1_AV_V_STA0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_ETMG1_AV_V_STA0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_ETMG1_AV_V_STP0_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_ETMG1_AV_V_STP0_SHIFT (0x00000010u)


/* etmg2 */

#define CSL_VPS_SD_VENC_ETMG2_AV_V_STA1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_ETMG2_AV_V_STA1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_ETMG2_AV_V_STP1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_ETMG2_AV_V_STP1_SHIFT (0x00000010u)


/* etmg3 */

#define CSL_VPS_SD_VENC_ETMG3_BST_H_STA_MASK (0x000001FFu)
#define CSL_VPS_SD_VENC_ETMG3_BST_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_ETMG3_BST_H_STP_MASK (0x01FF0000u)
#define CSL_VPS_SD_VENC_ETMG3_BST_H_STP_SHIFT (0x00000010u)


/* etmg4 */

#define CSL_VPS_SD_VENC_ETMG4_VBI_H_STA_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_ETMG4_VBI_H_STA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_ETMG4_VBI_H_STP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_ETMG4_VBI_H_STP_SHIFT (0x00000010u)


/* cvbs0 */

#define CSL_VPS_SD_VENC_CVBS0_CSLVL_MASK (0x0FFF0000u)
#define CSL_VPS_SD_VENC_CVBS0_CSLVL_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_CVBS0_CTLVL_MASK (0x00000FFFu)
#define CSL_VPS_SD_VENC_CVBS0_CTLVL_SHIFT (0x00000000u)


/* cvbs1 */

#define CSL_VPS_SD_VENC_CVBS1_CBLVL_MASK (0x0FFF0000u)
#define CSL_VPS_SD_VENC_CVBS1_CBLVL_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_CVBS1_CCM_MASK   (0x00000030u)
#define CSL_VPS_SD_VENC_CVBS1_CCM_SHIFT  (0x00000004u)

#define CSL_VPS_SD_VENC_CVBS1_CLPF_MASK  (0x00000004u)
#define CSL_VPS_SD_VENC_CVBS1_CLPF_SHIFT (0x00000002u)

#define CSL_VPS_SD_VENC_CVBS1_CPSR_MASK  (0x00000001u)
#define CSL_VPS_SD_VENC_CVBS1_CPSR_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CVBS1_CYDLY_MASK (0x00000F00u)
#define CSL_VPS_SD_VENC_CVBS1_CYDLY_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_CVBS1_YLPF_MASK  (0x00000002u)
#define CSL_VPS_SD_VENC_CVBS1_YLPF_SHIFT (0x00000001u)


/* cmpnt0 */

#define CSL_VPS_SD_VENC_CMPNT0_MSLVL_MASK (0x0FFF0000u)
#define CSL_VPS_SD_VENC_CMPNT0_MSLVL_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_CMPNT0_MTLVL_MASK (0x00000FFFu)
#define CSL_VPS_SD_VENC_CMPNT0_MTLVL_SHIFT (0x00000000u)


/* cmpnt1 */

#define CSL_VPS_SD_VENC_CMPNT1_MPSR_MASK (0x00000001u)
#define CSL_VPS_SD_VENC_CMPNT1_MPSR_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CMPNT1_MRGB_MASK (0x00000002u)
#define CSL_VPS_SD_VENC_CMPNT1_MRGB_SHIFT (0x00000001u)

#define CSL_VPS_SD_VENC_CMPNT1_MSOUB_MASK (0x00000020u)
#define CSL_VPS_SD_VENC_CMPNT1_MSOUB_SHIFT (0x00000005u)

#define CSL_VPS_SD_VENC_CMPNT1_MSOVR_MASK (0x00000040u)
#define CSL_VPS_SD_VENC_CMPNT1_MSOVR_SHIFT (0x00000006u)

#define CSL_VPS_SD_VENC_CMPNT1_MSOYG_MASK (0x00000010u)
#define CSL_VPS_SD_VENC_CMPNT1_MSOYG_SHIFT (0x00000004u)


/* ccsc0 */

#define CSL_VPS_SD_VENC_CCSC0_CCSCA0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC0_CCSCA0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CCSC0_CCSCB0_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CCSC0_CCSCB0_SHIFT (0x00000010u)


/* ccsc1 */

#define CSL_VPS_SD_VENC_CCSC1_CCSCC0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC1_CCSCC0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CCSC1_CCSCD0_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CCSC1_CCSCD0_SHIFT (0x00000010u)


/* ccsc2 */

#define CSL_VPS_SD_VENC_CCSC2_CCSCE0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC2_CCSCE0_SHIFT (0x00000000u)


/* ccsc3 */

#define CSL_VPS_SD_VENC_CCSC3_CCSCA1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC3_CCSCA1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CCSC3_CCSCB1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CCSC3_CCSCB1_SHIFT (0x00000010u)


/* ccsc4 */

#define CSL_VPS_SD_VENC_CCSC4_CCSCC1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC4_CCSCC1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CCSC4_CCSCD1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CCSC4_CCSCD1_SHIFT (0x00000010u)


/* ccsc5 */

#define CSL_VPS_SD_VENC_CCSC5_CCSCE1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC5_CCSCE1_SHIFT (0x00000000u)


/* ccsc6 */

#define CSL_VPS_SD_VENC_CCSC6_CCSCA2_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC6_CCSCA2_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CCSC6_CCSCB2_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CCSC6_CCSCB2_SHIFT (0x00000010u)


/* ccsc7 */

#define CSL_VPS_SD_VENC_CCSC7_CCSCC2_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC7_CCSCC2_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CCSC7_CCSCD2_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CCSC7_CCSCD2_SHIFT (0x00000010u)


/* ccsc8 */

#define CSL_VPS_SD_VENC_CCSC8_CCSCE2_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CCSC8_CCSCE2_SHIFT (0x00000000u)


/* mcsc0 */

#define CSL_VPS_SD_VENC_MCSC0_MCSCA0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC0_MCSCA0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MCSC0_MCSCB0_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MCSC0_MCSCB0_SHIFT (0x00000010u)


/* mcsc1 */

#define CSL_VPS_SD_VENC_MCSC1_MCSCC0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC1_MCSCC0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MCSC1_MCSCD0_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MCSC1_MCSCD0_SHIFT (0x00000010u)


/* mcsc2 */

#define CSL_VPS_SD_VENC_MCSC2_MCSCE0_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC2_MCSCE0_SHIFT (0x00000000u)


/* mcsc3 */

#define CSL_VPS_SD_VENC_MCSC3_MCSCA1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC3_MCSCA1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MCSC3_MCSCB1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MCSC3_MCSCB1_SHIFT (0x00000010u)


/* mcsc4 */

#define CSL_VPS_SD_VENC_MCSC4_MCSCC1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC4_MCSCC1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MCSC4_MCSCD1_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MCSC4_MCSCD1_SHIFT (0x00000010u)


/* mcsc5 */

#define CSL_VPS_SD_VENC_MCSC5_MCSCE1_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC5_MCSCE1_SHIFT (0x00000000u)


/* mcsc6 */

#define CSL_VPS_SD_VENC_MCSC6_MCSCA2_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC6_MCSCA2_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MCSC6_MCSCB2_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MCSC6_MCSCB2_SHIFT (0x00000010u)


/* mcsc7 */

#define CSL_VPS_SD_VENC_MCSC7_MCSCC2_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC7_MCSCC2_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MCSC7_MCSCD2_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MCSC7_MCSCD2_SHIFT (0x00000010u)


/* mcsc8 */

#define CSL_VPS_SD_VENC_MCSC8_MCSCE2_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MCSC8_MCSCE2_SHIFT (0x00000000u)


/* cygclp */

#define CSL_VPS_SD_VENC_CYGCLP_CYLCLP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CYGCLP_CYLCLP_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_CYGCLP_CYUCLP_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CYGCLP_CYUCLP_SHIFT (0x00000000u)


/* cubclp */

#define CSL_VPS_SD_VENC_CUBCLP_CULCLP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CUBCLP_CULCLP_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_CUBCLP_CUUCLP_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CUBCLP_CUUCLP_SHIFT (0x00000000u)


/* cvrclp */

#define CSL_VPS_SD_VENC_CVRCLP_CVLCLP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_CVRCLP_CVLCLP_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_CVRCLP_CVUCLP_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_CVRCLP_CVUCLP_SHIFT (0x00000000u)


/* mygclp */

#define CSL_VPS_SD_VENC_MYGCLP_MYGLCLP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MYGCLP_MYGLCLP_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_MYGCLP_MYGUCLP_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MYGCLP_MYGUCLP_SHIFT (0x00000000u)


/* mubclp */

#define CSL_VPS_SD_VENC_MUBCLP_MUBLCLP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MUBCLP_MUBLCLP_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_MUBCLP_MUBUCLP_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MUBCLP_MUBUCLP_SHIFT (0x00000000u)


/* mvrclp */

#define CSL_VPS_SD_VENC_MVRCLP_MVRLCLP_MASK (0x1FFF0000u)
#define CSL_VPS_SD_VENC_MVRCLP_MVRLCLP_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_MVRCLP_MVRUCLP_MASK (0x00001FFFu)
#define CSL_VPS_SD_VENC_MVRCLP_MVRUCLP_SHIFT (0x00000000u)


/* ylpf0 */

#define CSL_VPS_SD_VENC_YLPF0_YLPFC0_MASK (0x000000FFu)
#define CSL_VPS_SD_VENC_YLPF0_YLPFC0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_YLPF0_YLPFC1_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_YLPF0_YLPFC1_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_YLPF0_YLPFC2_MASK (0x00FF0000u)
#define CSL_VPS_SD_VENC_YLPF0_YLPFC2_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_YLPF0_YLPFC3_MASK (0xFF000000u)
#define CSL_VPS_SD_VENC_YLPF0_YLPFC3_SHIFT (0x00000018u)


/* ylpf1 */

#define CSL_VPS_SD_VENC_YLPF1_YLPFC4_MASK (0x000000FFu)
#define CSL_VPS_SD_VENC_YLPF1_YLPFC4_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_YLPF1_YLPFC5_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_YLPF1_YLPFC5_SHIFT (0x00000008u)


/* clpf0 */

#define CSL_VPS_SD_VENC_CLPF0_CLPFC0_MASK (0x000000FFu)
#define CSL_VPS_SD_VENC_CLPF0_CLPFC0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CLPF0_CLPFC1_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_CLPF0_CLPFC1_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_CLPF0_CLPFC2_MASK (0x00FF0000u)
#define CSL_VPS_SD_VENC_CLPF0_CLPFC2_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_CLPF0_CLPFC3_MASK (0xFF000000u)
#define CSL_VPS_SD_VENC_CLPF0_CLPFC3_SHIFT (0x00000018u)


/* clpf1 */

#define CSL_VPS_SD_VENC_CLPF1_CLPFC4_MASK (0x000000FFu)
#define CSL_VPS_SD_VENC_CLPF1_CLPFC4_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_CLPF1_CLPFC5_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_CLPF1_CLPFC5_SHIFT (0x00000008u)


/* upf0 */

#define CSL_VPS_SD_VENC_UPF0_UPFC0_MASK  (0x000000FFu)
#define CSL_VPS_SD_VENC_UPF0_UPFC0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_UPF0_UPFC1_MASK  (0x0000FF00u)
#define CSL_VPS_SD_VENC_UPF0_UPFC1_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_UPF0_UPFC2_MASK  (0x00FF0000u)
#define CSL_VPS_SD_VENC_UPF0_UPFC2_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_UPF0_UPFC3_MASK  (0xFF000000u)
#define CSL_VPS_SD_VENC_UPF0_UPFC3_SHIFT (0x00000018u)


/* upf1 */

#define CSL_VPS_SD_VENC_UPF1_UPFC4_MASK  (0x000000FFu)
#define CSL_VPS_SD_VENC_UPF1_UPFC4_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_UPF1_UPFC5_MASK  (0x0000FF00u)
#define CSL_VPS_SD_VENC_UPF1_UPFC5_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_UPF1_UPFC6_MASK  (0x00FF0000u)
#define CSL_VPS_SD_VENC_UPF1_UPFC6_SHIFT (0x00000010u)


/* l21ctl */

#define CSL_VPS_SD_VENC_L21CTL_L21DF_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_L21CTL_L21DF_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_L21CTL_L21EN_MASK (0x00000003u)
#define CSL_VPS_SD_VENC_L21CTL_L21EN_SHIFT (0x00000000u)


/* l21do */

#define CSL_VPS_SD_VENC_L21DO_L21DO0_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_L21DO_L21DO0_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_L21DO_L21DO1_MASK (0x000000FFu)
#define CSL_VPS_SD_VENC_L21DO_L21DO1_SHIFT (0x00000000u)


/* l21de */

#define CSL_VPS_SD_VENC_L21DE_L21DE0_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_L21DE_L21DE0_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_L21DE_L21DE1_MASK (0x000000FFu)
#define CSL_VPS_SD_VENC_L21DE_L21DE1_SHIFT (0x00000000u)


/* wss */

#define CSL_VPS_SD_VENC_WSS_WSS_DATA_MASK (0x000FFFFFu)
#define CSL_VPS_SD_VENC_WSS_WSS_DATA_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_WSS_WSS_EN_MASK  (0x10000000u)
#define CSL_VPS_SD_VENC_WSS_WSS_EN_SHIFT (0x0000001Cu)


/* vidbctl */

#define CSL_VPS_SD_VENC_VIDBCTL_VIDBH_MASK (0x0000003Fu)
#define CSL_VPS_SD_VENC_VIDBCTL_VIDBH_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_VIDBCTL_VIDB_EN_MASK (0x10000000u)
#define CSL_VPS_SD_VENC_VIDBCTL_VIDB_EN_SHIFT (0x0000001Cu)


/* vidbdata0 */

#define CSL_VPS_SD_VENC_VIDBDATA0_VIDBP_MASK (0xFFFFFFFFu)
#define CSL_VPS_SD_VENC_VIDBDATA0_VIDBP_SHIFT (0x00000000u)


/* vidbdata1 */

#define CSL_VPS_SD_VENC_VIDBDATA1_VIDBP_MASK (0xFFFFFFFFu)
#define CSL_VPS_SD_VENC_VIDBDATA1_VIDBP_SHIFT (0x00000000u)


/* vidbdata2 */

#define CSL_VPS_SD_VENC_VIDBDATA2_VIDBP_MASK (0xFFFFFFFFu)
#define CSL_VPS_SD_VENC_VIDBDATA2_VIDBP_SHIFT (0x00000000u)


/* vidbdata3 */

#define CSL_VPS_SD_VENC_VIDBDATA3_VIDBP_MASK (0xFFFFFFFFu)
#define CSL_VPS_SD_VENC_VIDBDATA3_VIDBP_SHIFT (0x00000000u)


/* scctl0 */

#define CSL_VPS_SD_VENC_SCCTL0_SCP0_MASK (0x00FF0000u)
#define CSL_VPS_SD_VENC_SCCTL0_SCP0_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_SCCTL0_SCSD_MASK (0x000003FFu)
#define CSL_VPS_SD_VENC_SCCTL0_SCSD_SHIFT (0x00000000u)


/* scctl1 */

#define CSL_VPS_SD_VENC_SCCTL1_SCP1_MASK (0x0000FFFFu)
#define CSL_VPS_SD_VENC_SCCTL1_SCP1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_SCCTL1_SCP2_MASK (0xFFFF0000u)
#define CSL_VPS_SD_VENC_SCCTL1_SCP2_SHIFT (0x00000010u)


/* dacsel */

#define CSL_VPS_SD_VENC_DACSEL_DA0E_MASK (0x01000000u)
#define CSL_VPS_SD_VENC_DACSEL_DA0E_SHIFT (0x00000018u)

#define CSL_VPS_SD_VENC_DACSEL_DA0S_MASK (0x0000000Fu)
#define CSL_VPS_SD_VENC_DACSEL_DA0S_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DACSEL_DA1E_MASK (0x02000000u)
#define CSL_VPS_SD_VENC_DACSEL_DA1E_SHIFT (0x00000019u)

#define CSL_VPS_SD_VENC_DACSEL_DA1S_MASK (0x000000F0u)
#define CSL_VPS_SD_VENC_DACSEL_DA1S_SHIFT (0x00000004u)

#define CSL_VPS_SD_VENC_DACSEL_DA2E_MASK (0x04000000u)
#define CSL_VPS_SD_VENC_DACSEL_DA2E_SHIFT (0x0000001Au)

#define CSL_VPS_SD_VENC_DACSEL_DA2S_MASK (0x00000F00u)
#define CSL_VPS_SD_VENC_DACSEL_DA2S_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_DACSEL_DA3E_MASK (0x08000000u)
#define CSL_VPS_SD_VENC_DACSEL_DA3E_SHIFT (0x0000001Bu)

#define CSL_VPS_SD_VENC_DACSEL_DA3S_MASK (0x0000F000u)
#define CSL_VPS_SD_VENC_DACSEL_DA3S_SHIFT (0x0000000Cu)


/* dupf0 */

#define CSL_VPS_SD_VENC_DUPF0_DUPFC0_MASK (0x000000FFu)
#define CSL_VPS_SD_VENC_DUPF0_DUPFC0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DUPF0_DUPFC1_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_DUPF0_DUPFC1_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_DUPF0_DUPFC2_MASK (0x00FF0000u)
#define CSL_VPS_SD_VENC_DUPF0_DUPFC2_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_DUPF0_DUPFC3_MASK (0xFF000000u)
#define CSL_VPS_SD_VENC_DUPF0_DUPFC3_SHIFT (0x00000018u)


/* dupf1 */

#define CSL_VPS_SD_VENC_DUPF1_DUPFC4_MASK (0x000000FFu)
#define CSL_VPS_SD_VENC_DUPF1_DUPFC4_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_DUPF1_DUPFC5_MASK (0x0000FF00u)
#define CSL_VPS_SD_VENC_DUPF1_DUPFC5_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_DUPF1_DUPFC6_MASK (0x00FF0000u)
#define CSL_VPS_SD_VENC_DUPF1_DUPFC6_SHIFT (0x00000010u)


/* dactst */

#define CSL_VPS_SD_VENC_DACTST_DADC_MASK (0x00010000u)
#define CSL_VPS_SD_VENC_DACTST_DADC_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_DACTST_DAIV_MASK (0x00020000u)
#define CSL_VPS_SD_VENC_DACTST_DAIV_SHIFT (0x00000011u)

#define CSL_VPS_SD_VENC_DACTST_DALVL_MASK (0x00000FFFu)
#define CSL_VPS_SD_VENC_DACTST_DALVL_SHIFT (0x00000000u)


/* macr00 */

#define CSL_VPS_SD_VENC_MACR00_N0_0_MASK (0x00000001u)
#define CSL_VPS_SD_VENC_MACR00_N0_0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MACR00_N0_1_MASK (0x00000002u)
#define CSL_VPS_SD_VENC_MACR00_N0_1_SHIFT (0x00000001u)

#define CSL_VPS_SD_VENC_MACR00_N0_2_MASK (0x00000004u)
#define CSL_VPS_SD_VENC_MACR00_N0_2_SHIFT (0x00000002u)

#define CSL_VPS_SD_VENC_MACR00_N0_3_MASK (0x00000008u)
#define CSL_VPS_SD_VENC_MACR00_N0_3_SHIFT (0x00000003u)

#define CSL_VPS_SD_VENC_MACR00_N0_4_MASK (0x00000010u)
#define CSL_VPS_SD_VENC_MACR00_N0_4_SHIFT (0x00000004u)

#define CSL_VPS_SD_VENC_MACR00_N0_5_MASK (0x00000020u)
#define CSL_VPS_SD_VENC_MACR00_N0_5_SHIFT (0x00000005u)


/* macr01 */

#define CSL_VPS_SD_VENC_MACR01_N1_5_0_MASK (0xFC000000u)
#define CSL_VPS_SD_VENC_MACR01_N1_5_0_SHIFT (0x0000001Au)

#define CSL_VPS_SD_VENC_MACR01_N2_5_0_MASK (0x03F00000u)
#define CSL_VPS_SD_VENC_MACR01_N2_5_0_SHIFT (0x00000014u)

#define CSL_VPS_SD_VENC_MACR01_N3_5_0_MASK (0x000FC000u)
#define CSL_VPS_SD_VENC_MACR01_N3_5_0_SHIFT (0x0000000Eu)

#define CSL_VPS_SD_VENC_MACR01_N4_5_0_MASK (0x00003F00u)
#define CSL_VPS_SD_VENC_MACR01_N4_5_0_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_MACR01_N5_2_0_MASK (0x000000E0u)
#define CSL_VPS_SD_VENC_MACR01_N5_2_0_SHIFT (0x00000005u)

#define CSL_VPS_SD_VENC_MACR01_N6_2_0_MASK (0x0000001Cu)
#define CSL_VPS_SD_VENC_MACR01_N6_2_0_SHIFT (0x00000002u)

#define CSL_VPS_SD_VENC_MACR01_N7_1_0_MASK (0x00000003u)
#define CSL_VPS_SD_VENC_MACR01_N7_1_0_SHIFT (0x00000000u)


/* macr02 */

#define CSL_VPS_SD_VENC_MACR02_N10_2_0_MASK (0x0001C000u)
#define CSL_VPS_SD_VENC_MACR02_N10_2_0_SHIFT (0x0000000Eu)

#define CSL_VPS_SD_VENC_MACR02_N10_5_3_MASK (0x000E0000u)
#define CSL_VPS_SD_VENC_MACR02_N10_5_3_SHIFT (0x00000011u)

#define CSL_VPS_SD_VENC_MACR02_N11_1_MASK (0x00000001u)
#define CSL_VPS_SD_VENC_MACR02_N11_1_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MACR02_N11_10_MASK (0x00000200u)
#define CSL_VPS_SD_VENC_MACR02_N11_10_SHIFT (0x00000009u)

#define CSL_VPS_SD_VENC_MACR02_N11_11_MASK (0x00000400u)
#define CSL_VPS_SD_VENC_MACR02_N11_11_SHIFT (0x0000000Au)

#define CSL_VPS_SD_VENC_MACR02_N11_12_MASK (0x00000800u)
#define CSL_VPS_SD_VENC_MACR02_N11_12_SHIFT (0x0000000Bu)

#define CSL_VPS_SD_VENC_MACR02_N11_13_MASK (0x00001000u)
#define CSL_VPS_SD_VENC_MACR02_N11_13_SHIFT (0x0000000Cu)

#define CSL_VPS_SD_VENC_MACR02_N11_14_MASK (0x00002000u)
#define CSL_VPS_SD_VENC_MACR02_N11_14_SHIFT (0x0000000Du)

#define CSL_VPS_SD_VENC_MACR02_N11_2_MASK (0x00000002u)
#define CSL_VPS_SD_VENC_MACR02_N11_2_SHIFT (0x00000001u)

#define CSL_VPS_SD_VENC_MACR02_N11_3_MASK (0x00000004u)
#define CSL_VPS_SD_VENC_MACR02_N11_3_SHIFT (0x00000002u)

#define CSL_VPS_SD_VENC_MACR02_N11_4_MASK (0x00000008u)
#define CSL_VPS_SD_VENC_MACR02_N11_4_SHIFT (0x00000003u)

#define CSL_VPS_SD_VENC_MACR02_N11_5_MASK (0x00000010u)
#define CSL_VPS_SD_VENC_MACR02_N11_5_SHIFT (0x00000004u)

#define CSL_VPS_SD_VENC_MACR02_N11_6_MASK (0x00000020u)
#define CSL_VPS_SD_VENC_MACR02_N11_6_SHIFT (0x00000005u)

#define CSL_VPS_SD_VENC_MACR02_N11_7_MASK (0x00000040u)
#define CSL_VPS_SD_VENC_MACR02_N11_7_SHIFT (0x00000006u)

#define CSL_VPS_SD_VENC_MACR02_N11_8_MASK (0x00000080u)
#define CSL_VPS_SD_VENC_MACR02_N11_8_SHIFT (0x00000007u)

#define CSL_VPS_SD_VENC_MACR02_N11_9_MASK (0x00000100u)
#define CSL_VPS_SD_VENC_MACR02_N11_9_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_MACR02_N8_2_0_MASK (0x1C000000u)
#define CSL_VPS_SD_VENC_MACR02_N8_2_0_SHIFT (0x0000001Au)

#define CSL_VPS_SD_VENC_MACR02_N8_5_3_MASK (0xE0000000u)
#define CSL_VPS_SD_VENC_MACR02_N8_5_3_SHIFT (0x0000001Du)

#define CSL_VPS_SD_VENC_MACR02_N9_2_0_MASK (0x00700000u)
#define CSL_VPS_SD_VENC_MACR02_N9_2_0_SHIFT (0x00000014u)

#define CSL_VPS_SD_VENC_MACR02_N9_5_3_MASK (0x03800000u)
#define CSL_VPS_SD_VENC_MACR02_N9_5_3_SHIFT (0x00000017u)


/* macr03 */

#define CSL_VPS_SD_VENC_MACR03_N11_0_MASK (0x80000000u)
#define CSL_VPS_SD_VENC_MACR03_N11_0_SHIFT (0x0000001Fu)

#define CSL_VPS_SD_VENC_MACR03_N12_0_MASK (0x00010000u)
#define CSL_VPS_SD_VENC_MACR03_N12_0_SHIFT (0x00000010u)

#define CSL_VPS_SD_VENC_MACR03_N12_1_MASK (0x00020000u)
#define CSL_VPS_SD_VENC_MACR03_N12_1_SHIFT (0x00000011u)

#define CSL_VPS_SD_VENC_MACR03_N12_10_MASK (0x04000000u)
#define CSL_VPS_SD_VENC_MACR03_N12_10_SHIFT (0x0000001Au)

#define CSL_VPS_SD_VENC_MACR03_N12_11_MASK (0x08000000u)
#define CSL_VPS_SD_VENC_MACR03_N12_11_SHIFT (0x0000001Bu)

#define CSL_VPS_SD_VENC_MACR03_N12_12_MASK (0x10000000u)
#define CSL_VPS_SD_VENC_MACR03_N12_12_SHIFT (0x0000001Cu)

#define CSL_VPS_SD_VENC_MACR03_N12_13_MASK (0x20000000u)
#define CSL_VPS_SD_VENC_MACR03_N12_13_SHIFT (0x0000001Du)

#define CSL_VPS_SD_VENC_MACR03_N12_14_MASK (0x40000000u)
#define CSL_VPS_SD_VENC_MACR03_N12_14_SHIFT (0x0000001Eu)

#define CSL_VPS_SD_VENC_MACR03_N12_2_MASK (0x00040000u)
#define CSL_VPS_SD_VENC_MACR03_N12_2_SHIFT (0x00000012u)

#define CSL_VPS_SD_VENC_MACR03_N12_3_MASK (0x00080000u)
#define CSL_VPS_SD_VENC_MACR03_N12_3_SHIFT (0x00000013u)

#define CSL_VPS_SD_VENC_MACR03_N12_4_MASK (0x00100000u)
#define CSL_VPS_SD_VENC_MACR03_N12_4_SHIFT (0x00000014u)

#define CSL_VPS_SD_VENC_MACR03_N12_5_MASK (0x00200000u)
#define CSL_VPS_SD_VENC_MACR03_N12_5_SHIFT (0x00000015u)

#define CSL_VPS_SD_VENC_MACR03_N12_6_MASK (0x00400000u)
#define CSL_VPS_SD_VENC_MACR03_N12_6_SHIFT (0x00000016u)

#define CSL_VPS_SD_VENC_MACR03_N12_7_MASK (0x00800000u)
#define CSL_VPS_SD_VENC_MACR03_N12_7_SHIFT (0x00000017u)

#define CSL_VPS_SD_VENC_MACR03_N12_8_MASK (0x01000000u)
#define CSL_VPS_SD_VENC_MACR03_N12_8_SHIFT (0x00000018u)

#define CSL_VPS_SD_VENC_MACR03_N12_9_MASK (0x02000000u)
#define CSL_VPS_SD_VENC_MACR03_N12_9_SHIFT (0x00000019u)

#define CSL_VPS_SD_VENC_MACR03_N13_0_MASK (0x00000100u)
#define CSL_VPS_SD_VENC_MACR03_N13_0_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_MACR03_N13_1_MASK (0x00000200u)
#define CSL_VPS_SD_VENC_MACR03_N13_1_SHIFT (0x00000009u)

#define CSL_VPS_SD_VENC_MACR03_N13_2_MASK (0x00000400u)
#define CSL_VPS_SD_VENC_MACR03_N13_2_SHIFT (0x0000000Au)

#define CSL_VPS_SD_VENC_MACR03_N13_3_MASK (0x00000800u)
#define CSL_VPS_SD_VENC_MACR03_N13_3_SHIFT (0x0000000Bu)

#define CSL_VPS_SD_VENC_MACR03_N13_4_MASK (0x00001000u)
#define CSL_VPS_SD_VENC_MACR03_N13_4_SHIFT (0x0000000Cu)

#define CSL_VPS_SD_VENC_MACR03_N13_5_MASK (0x00002000u)
#define CSL_VPS_SD_VENC_MACR03_N13_5_SHIFT (0x0000000Du)

#define CSL_VPS_SD_VENC_MACR03_N13_6_MASK (0x00004000u)
#define CSL_VPS_SD_VENC_MACR03_N13_6_SHIFT (0x0000000Eu)

#define CSL_VPS_SD_VENC_MACR03_N13_7_MASK (0x00008000u)
#define CSL_VPS_SD_VENC_MACR03_N13_7_SHIFT (0x0000000Fu)

#define CSL_VPS_SD_VENC_MACR03_N14_0_MASK (0x00000001u)
#define CSL_VPS_SD_VENC_MACR03_N14_0_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MACR03_N14_1_MASK (0x00000002u)
#define CSL_VPS_SD_VENC_MACR03_N14_1_SHIFT (0x00000001u)

#define CSL_VPS_SD_VENC_MACR03_N14_2_MASK (0x00000004u)
#define CSL_VPS_SD_VENC_MACR03_N14_2_SHIFT (0x00000002u)

#define CSL_VPS_SD_VENC_MACR03_N14_3_MASK (0x00000008u)
#define CSL_VPS_SD_VENC_MACR03_N14_3_SHIFT (0x00000003u)

#define CSL_VPS_SD_VENC_MACR03_N14_4_MASK (0x00000010u)
#define CSL_VPS_SD_VENC_MACR03_N14_4_SHIFT (0x00000004u)

#define CSL_VPS_SD_VENC_MACR03_N14_5_MASK (0x00000020u)
#define CSL_VPS_SD_VENC_MACR03_N14_5_SHIFT (0x00000005u)

#define CSL_VPS_SD_VENC_MACR03_N14_6_MASK (0x00000040u)
#define CSL_VPS_SD_VENC_MACR03_N14_6_SHIFT (0x00000006u)

#define CSL_VPS_SD_VENC_MACR03_N14_7_MASK (0x00000080u)
#define CSL_VPS_SD_VENC_MACR03_N14_7_SHIFT (0x00000007u)


/* macr04 */

#define CSL_VPS_SD_VENC_MACR04_N15_3_0_MASK (0x0F000000u)
#define CSL_VPS_SD_VENC_MACR04_N15_3_0_SHIFT (0x00000018u)

#define CSL_VPS_SD_VENC_MACR04_N15_7_4_MASK (0xF0000000u)
#define CSL_VPS_SD_VENC_MACR04_N15_7_4_SHIFT (0x0000001Cu)

#define CSL_VPS_SD_VENC_MACR04_N16_0_MASK (0x00800000u)
#define CSL_VPS_SD_VENC_MACR04_N16_0_SHIFT (0x00000017u)

#define CSL_VPS_SD_VENC_MACR04_N17_3_0_MASK (0x00780000u)
#define CSL_VPS_SD_VENC_MACR04_N17_3_0_SHIFT (0x00000013u)

#define CSL_VPS_SD_VENC_MACR04_N18_3_0_MASK (0x00078000u)
#define CSL_VPS_SD_VENC_MACR04_N18_3_0_SHIFT (0x0000000Fu)

#define CSL_VPS_SD_VENC_MACR04_N19_3_0_MASK (0x00007800u)
#define CSL_VPS_SD_VENC_MACR04_N19_3_0_SHIFT (0x0000000Bu)

#define CSL_VPS_SD_VENC_MACR04_N20_0_MASK (0x00000100u)
#define CSL_VPS_SD_VENC_MACR04_N20_0_SHIFT (0x00000008u)

#define CSL_VPS_SD_VENC_MACR04_N20_1_MASK (0x00000200u)
#define CSL_VPS_SD_VENC_MACR04_N20_1_SHIFT (0x00000009u)

#define CSL_VPS_SD_VENC_MACR04_N20_2_MASK (0x00000400u)
#define CSL_VPS_SD_VENC_MACR04_N20_2_SHIFT (0x0000000Au)

#define CSL_VPS_SD_VENC_MACR04_N21_3_2_MASK (0x00000003u)
#define CSL_VPS_SD_VENC_MACR04_N21_3_2_SHIFT (0x00000000u)

#define CSL_VPS_SD_VENC_MACR04_N21_5_4_MASK (0x0000000Cu)
#define CSL_VPS_SD_VENC_MACR04_N21_5_4_SHIFT (0x00000002u)

#define CSL_VPS_SD_VENC_MACR04_N21_7_6_MASK (0x00000030u)
#define CSL_VPS_SD_VENC_MACR04_N21_7_6_SHIFT (0x00000004u)

#define CSL_VPS_SD_VENC_MACR04_N21_9_8_MASK (0x000000C0u)
#define CSL_VPS_SD_VENC_MACR04_N21_9_8_SHIFT (0x00000006u)


/* macr05 */

#define CSL_VPS_SD_VENC_MACR05_N21_1_0_MASK (0xC0000000u)
#define CSL_VPS_SD_VENC_MACR05_N21_1_0_SHIFT (0x0000001Eu)

#define CSL_VPS_SD_VENC_MACR05_N22_MASK  (0x20000000u)
#define CSL_VPS_SD_VENC_MACR05_N22_SHIFT (0x0000001Du)


/* vtest */

#define CSL_VPS_SD_VENC_VTEST_VTST_MASK  (0xFFFFFFFFu)
#define CSL_VPS_SD_VENC_VTEST_VTST_SHIFT (0x00000000u)


#endif
