/*******************************************************************************
 *                                                                             *
 * Copyright (c) 2009 Texas Instruments Incorporated - http://www.ti.com/      *
 *                        ALL RIGHTS RESERVED                                  *
 *                                                                             *
 ******************************************************************************/

/**
 * \ingroup VPS_DRV_FVID2_DEVICE_VID_ENC_API
 * \defgroup VPS_DRV_FVID2_DEVICE_VID_ENC_SII9022A_API SII9022A Video Encoder API
 *
 *  This modules define API specific to SII9022A video encoder device.
 *
 * @{
*/

/**
 *  \file vps_sii9022a.h
 *
 *  \brief SII9022A Video Encoder API
*/


#ifndef _VPS_SII_9022A_H_
#define _VPS_SII_9022A_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/psp/devices/vps_videoEncoder.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/**
  * \addtogroup VPS_DRV_FVID2_IOCTL_SII9022A
  * @{
*/

/**
  * \brief Query hot plug detect (HPD) for HDMI cable connect or disconnect.
  *
  *
  * \param cmdArgs       [OUT]  Vps_HdmiChipId *
  * \param cmdArgsStatus [OUT]  NULL
  *
  * \return FVID_SOK on success, else failure. Status= TRUE means cable
  * connected else not connected
  *
*/
#define IOCTL_VPS_SII9022A_GET_DETAILED_CHIP_ID      \
            (VPS_VID_ENC_IOCTL_BASE + 0x1000)


/**
  * \brief Query Hot Plug Detect status
  *
  *
  * \param cmdArgs       [OUT]   Pointer to UInt32 i.e. UInt32 * status
  * \param cmdArgsStatus [OUT]  NULL
  *
  * \return FVID_SOK on success, else failure.
  *
*/
#define IOCTL_VPS_SII9022A_QUERY_HPD      \
            (VPS_VID_ENC_IOCTL_BASE + 0x1001)

/**
  * \brief Set Configuration in HDMI 9022A
  *
  *
  * \param cmdArgs       [IN]   Pointer to Vps_SiI9022aPrms
  * \param cmdArgsStatus [OUT]  NULL
  *
  * \return FVID_SOK on success, else failure.
  *
*/
#define IOCTL_VPS_SII9022A_SET_PARAMS      \
            (VPS_VID_ENC_IOCTL_BASE + 0x1002)

/**
  * \brief Get Configuration in HDMI 9022A
  *
  *
  * \param cmdArgs       [IN]   Pointer to Vps_SiI9022aPrms
  * \param cmdArgsStatus [OUT]  NULL
  *
  * \return FVID_SOK on success, else failure.
  *
*/
#define IOCTL_VPS_SII9022A_GET_PARAMS      \
            (VPS_VID_ENC_IOCTL_BASE + 0x1003)


/**
 * \brief Enum defining output type
 */
typedef enum
{
    VPS_SII9022A_HDMI_RGB = 0,
    /**< Output format is RGB over HDMI interface */
    VPS_SII9022A_HDMI_YUV444,
    /**< Output format is YUV444 over HDMI interface */
    VPS_SII9022A_HDMI_YUV422,
    /**< Output format is YUV422 over HDMI interface */
    VPS_SII9022A_DVI_RGB,
    /**< Output format is RGB over DVI interface */
    VPS_SII9022A_MAX_FORMAT
    /**< Max output format */
} Vps_Sii9022AOutputFormat;

/* @} */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */


/**
 * \brief Structure for getting HDMI chip identification Id.
 */
typedef struct
{
    UInt32                  deviceId;
    /**< Device Id TPI */
    UInt32                  deviceProdRevId;
    /**< Device Production Revision Id TPI  */
    UInt32                  tpiRevId;
    /**< TPI Revision Id TPI */
    UInt32                  hdcpRevTpi;
    /**< HDCP revision TPI */
} Vps_HdmiChipId;

/**
 *  \brief Mode Information structure.
 *  This structure is used in setting mode in SiI9022A using
 *  IOCTL_VPS_VIDEO_ENCODER_SET_MODE IOCTL.
 */
typedef struct
{
    UInt32                  standard;
    /**< Video standard. For valid values see #FVID2_Standard. */
} Vps_SiI9022aModeParams;

/**
 * \brief Structure for hot plug detection parameters.
 *
 * It is used to get
 * the hpd parameters using IOCTL_VPS_SII9022A_QUERY_HPD ioctl.
 */
typedef struct
{
    UInt32                  hpdEvtPending;
    /**< Hot Plug Connection Event Pending */
    UInt32                  busError;
    /**< Receiver Sense Event Pending or CTRL Bus Error */
    UInt32                  hpdStatus;
    /**< Hot Plug Pin Current Status */
} Vps_SiI9022aHpdPrms;

typedef struct
{
    UInt32 outputFormat;
    /**< Type of the OUTPUT i.e. HDMI of DVI #Vps_Sii9022AOutputFormat */
} Vps_SiI9022aPrms;

#endif

/* @} */
