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

#include <common.h>
#include "ti81xx.h"

/* MUSB platform configuration */
struct musb_config musb_cfg = {
	(struct	musb_regs *)MENTOR_BASE,
	MUSB_TIMEOUT,
	0,
	0
};

/*
 * Enable the USB phy
 */
static u8 phy_on(void)
{
	u32 usbphycfg;

	/*
	 * Start the on-chip PHY and its PLL.
	 */
	usbphycfg = readl(TI81XX_USBCTRL0);

	usbphycfg &= ~(TI814X_USBPHY_CM_PWRDN
				| TI814X_USBPHY_OTG_PWRDN
				| TI814X_USBPHY_DMPULLUP
				| TI814X_USBPHY_DPPULLUP
				| TI814X_USBPHY_DPINPUT
				| TI814X_USBPHY_DMINPUT
				| TI814X_USBPHY_DATA_POLARITY);
			usbphycfg |= (TI814X_USBPHY_SRCONDM
				| TI814X_USBPHY_SINKONDP
				| TI814X_USBPHY_CHGISINK_EN
				| TI814X_USBPHY_CHGVSRC_EN
				| TI814X_USBPHY_CDET_EXTCTL
				| TI814X_USBPHY_DPOPBUFCTL
				| TI814X_USBPHY_DMOPBUFCTL
				| TI814X_USBPHY_DPGPIO_PD
				| TI814X_USBPHY_DMGPIO_PD
				| TI814X_USBPHY_OTGVDET_EN
				| TI814X_USBPHY_OTGSESSEND_EN);

	writel(usbphycfg, TI81XX_USBCTRL0);

	/*
 	 * Give the PHY ~1ms to complete the power up operation.
 	 * Tests have shown unstable behaviour if other USB PHY related
 	 * registers are written too shortly after such a transition.
 	 */
	udelay(2000);

	return 1;
}

/*
 * Disable the USB phy
 */
static void phy_off(void)
{
	u32 usbphycfg;

	/*
	 * Power down the on-chip PHY.
	 */
	usbphycfg = readl(TI81XX_USBCTRL0);
	usbphycfg |= TI814X_USBPHY_CM_PWRDN
				| TI814X_USBPHY_OTG_PWRDN;

	writel(usbphycfg, TI81XX_USBCTRL0);
}

static void usb2phy_config(u8 config, u8 config_option)
{
	u32 regs_offset, val, sign, rx_calib, timeout = 0xfffff;
	u8 dac1, dac2, dac3;

	switch (config)	{
	case USBPHY_RX_CALIB:
		regs_offset = USB2PHY_RXCALIB_REG_OFFS;

		/* wait till rx_calib and squeltch calib done bit become true */
		do {
			val = readl(MUSB_CTRL0_BASE + regs_offset);
			udelay(5);
		} while (timeout-- && !((val & USB2PHY_RXCALIB_DONE)
			&& (val & USB2PHY_SQ_CAL_DONE)));

		printf("default rxcalib regval %08x\n", val);

		if (!((val & USB2PHY_RXCALIB_DONE) &&
			(val & USB2PHY_SQ_CAL_DONE))) {
			printf("usb2phy rxcalibration failed\n");
			return;
		}

		sign = (val >> 29) & 1;
		rx_calib = (val >> 24) & 0x1F;
		printf("musb0 sign %d current RXcalib %d\n", sign, rx_calib);

		dac3 = (val >> USB2PHY_DAC3_OFFS) & 0x1F;
		dac2 = (val >> USB2PHY_DAC2_OFFS) & 0x1F;
		dac1 = (val >> USB2PHY_DAC1_OFFS) & 0x3F;
		printf("initial value of DAC3 (%x) DAC2(%x) DAC1(%x)\n", dac3,
				dac2, dac1);

		/* add code of 2 for dac3/dac2 */
		dac3 += 2;
		if (dac3 > 0x1F)
			dac3 = 0x1F;

		dac2 += 2;
		if (dac2 > 0x1F)
			dac2 = 0x1F;

		/* Always reduce the threshold by 15 codes (~15mV
		 * If sign bit is .1., add 0xf to the magnitude bits
		 * new_mag = old_mag + 0xf;
		 * It will increase threshold in -ve direction
		 * If sign bit is .0. and magnitude >= 0xf;
		 * new_mag = old_mag . 0xf It will decrease threshold
		 * If sign bit is .0. and magnitude < 0xf;
		 * make sign bit = .1., new_mag = 0xf old_mag
		 */
		if (sign) {
			if (rx_calib > 16)
				rx_calib -= 15;
			else
				rx_calib += 15;
		} else {
			if (rx_calib >= 15)
				rx_calib -= 15;
			else {
				sign = 1;
				rx_calib = 15 - rx_calib;
			}
		}

		printf("usb2phy: computed values rxcalib(%d)"
			"DACs(%d %d %d)\n", rx_calib, dac1, dac2, dac3);

		switch (config_option) {
		case 1:
			/* the new computed values are not working
			 * causing interop issues with specifc mouse
			 * hence over-riding the new computed
			 * values of rxcalib register.
			 */
			rx_calib = 7;
			dac1 = 14;
			dac2 = 12;
			dac3 = 15;
			break;

		case 2:
			dac1 = 14;
			dac2 = dac2 - 1;
			dac3++;
			break;
			/* use new computed values */
		default:
			break;
		}

		printf("usb2phy: override computed values rxcalib(%d)"
				"DACs(%d %d %d)\n", rx_calib, dac1, dac2, dac3);

		val &= ~(0x3F << 24);
		val |= ((rx_calib << 24) | (sign << 29) | (1 << 30));

		/* override all DAC values */
		val &= ~((0x1F << USB2PHY_DAC3_OFFS)
			| (0x1F << USB2PHY_DAC2_OFFS)
			| (0x3F << USB2PHY_DAC1_OFFS));
		val |= ((dac3 << USB2PHY_DAC3_OFFS)
			| (dac2 << USB2PHY_DAC2_OFFS)
			| (dac1 << USB2PHY_DAC1_OFFS));
		val |= ((1 << USB2PHY_DAC3_EN_OFFS)
			| (1 << USB2PHY_DAC2_EN_OFFS)
			| (1 << USB2PHY_DAC1_EN_OFFS));

		printf("musb0 sign(%d) rxcalib(%d) dac3(%x) dac2(%x) "
			"written val %x\n", sign, rx_calib,
			dac3, dac2, val);

		writel(val, MUSB_CTRL0_BASE + regs_offset);
		udelay(1000);

		val = readl(MUSB_CTRL0_BASE + regs_offset);
		printf("musb0 rxcalib done, rxcalib read value %x\n", val);
	break;

	default:
		break;
	}
}
/*
 * This function performs platform specific initialization for usb0.
 */
int musb_platform_init(void)
{
	u32 revision;
	u32 timeout;
	u32 val;

	/* reset the usbss for usb0/usb1 */
	val = readl(MUSB_BASE + USBSS_SYSCONFIG);
	writel((val | USB_SOFT_RESET_MASK), MUSB_BASE + USBSS_SYSCONFIG);
	udelay(1);
	/* clear any USBSS interrupts */
	writel(0, MUSB_BASE + USBSS_IRQ_EOI);

	/* reset the controller */
	writel(USB_SOFT_RESET_MASK, MUSB_CTRL0_BASE + USB_CTRL_REG);
	/* wait till reset bit clears */
	timeout = 1000;
	while (timeout--) {
		if (!(readl(MUSB_CTRL0_BASE + USB_CTRL_REG) & 0x1))
			break;
		udelay(1000);
	}
	if (!timeout)
		return -1;

	if (!phy_on())
		return -1;

//	usb2phy_config(USBPHY_RX_CALIB, 0);

	/* Returns zero if e.g. not clocked */
	revision = readl(MUSB_CTRL0_BASE + USB_REVISION_REG);
	if (!revision)
		return -1;

	printf("MUSB controller-0 revision %08x\n", revision);

	/* Disable all interrupts */
	writel(0, (MUSB_CTRL0_BASE + USB_IRQ_EOI));

	return 0;
}

/*
 * This function performs platform specific deinitialization for usb0.
 */
void musb_platform_deinit(void)
{
	/* Turn of the phy */
	phy_off();
}
