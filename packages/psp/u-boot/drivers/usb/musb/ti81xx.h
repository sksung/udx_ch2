/*
 * TI's DM81xx platform specific USB wrapper functions.
 *
 * Copyright (c) 2009 Texas Instruments
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * Author: Ajay Kumar Gupta ajay.gupta@ti.com, Texas Instruments
 */

#ifndef __TI81XX_USB_H__
#define __TI81XX_USB_H__

#include "musb_core.h"

/* Base address of musb wrapper */
#define MUSB_BASE 					0x47400000
#define MUSB_CTRL0_BASE 			(MUSB_BASE+0x1000)
#define MUSB_CTRL1_BASE 			(MUSB_BASE+0x1800)

/* Base address of musb core (usb0) */
#define MENTOR_BASE 	   			(MUSB_BASE+0x1400) //# usb1->0x1c00

/* Base address of system control register used to program phy */
#define TI81XX_USBCTRL0				0x48140620 //# CTRL1->0x0628

#define USBSS_REVISION				0x0000
#define USBSS_SYSCONFIG				0x0010
#define USBSS_IRQ_EOI				0x0020

/*
 * TI81XX platform USB wrapper register overlay. Note: Only the required
 * registers are included in this structure. It can be expanded as required.
 */
#define USB_REVISION_REG        	0x0000
#define USB_CTRL_REG            	0x0014
#define USB_STAT_REG            	0x0018
#define	USB_IRQ_MERGED_STATUS		0x0020
#define USB_IRQ_EOI					0x0024
#define	USB_IRQ_STATUS_RAW_0		0x0028
#define	USB_IRQ_STATUS_RAW_1		0x002c
#define	USB_IRQ_STATUS_0			0x0030
#define	USB_IRQ_STATUS_1			0x0034
#define	USB_IRQ_ENABLE_SET_0		0x0038
#define	USB_IRQ_ENABLE_SET_1		0x003c
#define	USB_IRQ_ENABLE_CLR_0		0x0040
#define	USB_IRQ_ENABLE_CLR_1		0x0044

/* Control register bits */
#define USB_SOFT_RESET_MASK			1

/* Timeout for MUSB module */
#define MUSB_TIMEOUT 				0x3FFFFFF

/* TI814X PHY controls bits */
#define TI814X_USBPHY_CM_PWRDN		(1 << 0)
#define TI814X_USBPHY_OTG_PWRDN		(1 << 1)
#define TI814X_USBPHY_CHGDET_DIS	(1 << 2)
#define TI814X_USBPHY_CHGDET_RSTRT	(1 << 3)
#define TI814X_USBPHY_SRCONDM		(1 << 4)
#define TI814X_USBPHY_SINKONDP		(1 << 5)
#define TI814X_USBPHY_CHGISINK_EN	(1 << 6)
#define TI814X_USBPHY_CHGVSRC_EN	(1 << 7)
#define TI814X_USBPHY_DMPULLUP		(1 << 8)
#define TI814X_USBPHY_DPPULLUP		(1 << 9)
#define TI814X_USBPHY_CDET_EXTCTL	(1 << 10)
#define TI814X_USBPHY_GPIO_MODE		(1 << 12)
#define TI814X_USBPHY_DPOPBUFCTL	(1 << 13)
#define TI814X_USBPHY_DMOPBUFCTL	(1 << 14)
#define TI814X_USBPHY_DPINPUT		(1 << 15)
#define TI814X_USBPHY_DMINPUT		(1 << 16)
#define TI814X_USBPHY_DPGPIO_PD		(1 << 17)
#define TI814X_USBPHY_DMGPIO_PD		(1 << 18)
#define TI814X_USBPHY_OTGVDET_EN	(1 << 19)
#define TI814X_USBPHY_OTGSESSEND_EN	(1 << 20)
#define TI814X_USBPHY_DATA_POLARITY	(1 << 23)

#define USBPHY_RX_CALIB				1

#define USB2PHY_RXCALIB_REG_OFFS	0x304
#define USB2PHY_RXCALIB_DONE		(1 << 22)
#define USB2PHY_SQ_CAL_DONE			(1 << 1)
#define USB2PHY_DAC3_OFFS			3
#define USB2PHY_DAC2_OFFS			9
#define USB2PHY_DAC1_OFFS			15
#define USB2PHY_DAC1_EN_OFFS		21
#define USB2PHY_DAC2_EN_OFFS		14
#define USB2PHY_DAC3_EN_OFFS		8

#endif	/* __TI81XX_USB_H__ */
