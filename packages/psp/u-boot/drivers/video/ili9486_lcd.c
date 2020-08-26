/*
 * ILI9486 lcd driver
 * 320RGBx480 Half VGA (262K) - 18Bit
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#include <common.h>
#include <spi.h>

#include <asm/gpio.h>
#include <asm/arch/common_ud_defs.h>
#include <ili9486_lcd.h>

#define BIT_SHIFT		7
#define SWAP16(x)	 	((((x) & 0x00ff) << 8) | ( (x) >> 8))
#define mdelay(n)		udelay((n)*1000)

#define REG_IDX		0
#define REG_CMD		1
#define REG_DELAY	2

struct lcd_regs_t {
	int type;
	u16 val;
};

#if 0
static struct lcd_regs_t init_regs[] = {
	{REG_CMD, 0xF1}, //# 0xF1 register write.
	{REG_IDX, 0x36},
	{REG_IDX, 0x04},
	{REG_IDX, 0x00},
	{REG_IDX, 0x3C},
	{REG_IDX, 0x0F},
	{REG_IDX, 0x8F},

	{REG_CMD, 0xF2},
	{REG_IDX, 0x18},
	{REG_IDX, 0xA3},
	{REG_IDX, 0x12},
	{REG_IDX, 0x02},
	{REG_IDX, 0xB2},
	{REG_IDX, 0x12},
	{REG_IDX, 0xFF},
	{REG_IDX, 0x10},
	{REG_IDX, 0x00},

	{REG_CMD, 0xF8},
	{REG_IDX, 0x21},
	{REG_IDX, 0x04},

	{REG_CMD, 0xF9},
	{REG_IDX, 0x00},
	{REG_IDX, 0x08},

	{REG_CMD, 0xC0},
	{REG_IDX, 0x0B},
	{REG_IDX, 0x0B},

	{REG_CMD, 0xC1}, /* POWER CONTROL 2 */
	{REG_IDX, 0x42},
	{REG_IDX, 0xC2},
	{REG_IDX, 0x22},

	{REG_CMD, 0xC5}, /* POWER CONTROL 3 */
	{REG_IDX, 0x00},
	{REG_IDX, 0x00},
	{REG_IDX, 0x80},

	{REG_CMD, 0xB1}, /* Frame Rate Control (In Normal Mode) */
	{REG_IDX, 0xB0}, /* FRS:70Hz DIVA:FOSC */
	{REG_IDX, 0x11},

	{REG_CMD, 0xB4},
	{REG_IDX, 0x02},

	{REG_CMD, 0xB6}, //# DISCTRL
	{REG_IDX, 0x22},
	{REG_IDX, 0x22},
	{REG_IDX, 0x3B}, //# 8*(0x3B+1)lines->480

	{REG_CMD, 0xB7}, //# Entry Mode Set.
	{REG_IDX, 0xC6}, //# EPF->11, GON/DTE(normal display)

	{REG_CMD, 0xE0}, /* Positive Gamma Control */
	{REG_IDX, 0x00},
	{REG_IDX, 0x1D},
	{REG_IDX, 0x19},
	{REG_IDX, 0x0C},
	{REG_IDX, 0x0F},
	{REG_IDX, 0x0A},
	{REG_IDX, 0x45},
	{REG_IDX, 0x95},
	{REG_IDX, 0x38},
	{REG_IDX, 0x0A},
	{REG_IDX, 0x12},
	{REG_IDX, 0x03},
	{REG_IDX, 0x09},
	{REG_IDX, 0x06},
	{REG_IDX, 0x00},

	{REG_CMD, 0xE1}, /* Positive Gamma Control */
	{REG_IDX, 0x0F},
	{REG_IDX, 0x3A},
	{REG_IDX, 0x36},
	{REG_IDX, 0x0C},
	{REG_IDX, 0x0D},
	{REG_IDX, 0x05},
	{REG_IDX, 0x4E},
	{REG_IDX, 0x0A},
	{REG_IDX, 0x38},
	{REG_IDX, 0x05},
	{REG_IDX, 0x0F},
	{REG_IDX, 0x03},
	{REG_IDX, 0x25},
	{REG_IDX, 0x22},
	{REG_IDX, 0x0F},

	{REG_CMD, 0x36}, //# Memory Access Control
	{REG_IDX, 0x48}, //# BGR (If lotate, MX->1 and MV->1)
	/*
	 * note. Power On ->EC=0x00EF(239)
	 *       H/W Reset ->EC=0x13F(319)
	 */
	{REG_CMD, 0x2A}, //# Column Address Set
	{REG_IDX, 0x00}, //# SC[15:8]
	{REG_IDX, 0x00}, //# SC[7:0]
	{REG_IDX, 0x01}, //# EC[15:8]
	{REG_IDX, 0x3f}, //# EC[7:0] -->479

	{REG_CMD, 0x2B}, //# Page Address Set
	{REG_IDX, 0x00}, //# SP[15:8]
	{REG_IDX, 0x00}, //# SP[7:0]
	{REG_IDX, 0x01}, //# EP[15:8]
	{REG_IDX, 0xdf}, //# EP[7:0] -->479

	{REG_CMD, 0x2c}, //# RAMWR(memory write)

	{REG_CMD, 0x3A}, /* Interface Pixel Format */
	{REG_IDX, 0x55}, //# 8&16Bit 0x55, 18Bit 0x66


	{REG_CMD, 0x20}, //# Sleep Out
	{REG_CMD, 0x11},

	{REG_DELAY, 120},

	{REG_CMD, 0x29}, //# Display ON.
};
#else
static struct lcd_regs_t init_regs[] = {
	{REG_CMD, 0xd0}, /* power setting */
	{REG_IDX, 0x07},
	{REG_IDX, 0x47},
	{REG_IDX, 0x19},
 	{REG_CMD, 0xD1}, /* VCOM Control */
 	{REG_IDX, 0x00},
 	{REG_IDX, 0x1C},//18
 	{REG_IDX, 0x1F},
	{REG_CMD, 0xd2}, /* Power Setting for Normal Mode */
	{REG_IDX, 0x01},
	{REG_IDX, 0x11},
	{REG_CMD, 0xE4}, /* Unknown Field */
	{REG_IDX, 0xa0},
	{REG_CMD, 0xf3}, /* Unknown Field */
	{REG_IDX, 0x00},
	{REG_IDX, 0x2a},
	{REG_CMD, 0xc0}, /* Panel Driving Setting */
	{REG_IDX, 0x10},
	{REG_IDX, 0x3C},
	{REG_IDX, 0x00},
	{REG_IDX, 0x02},
	{REG_IDX, 0x01},
	{REG_CMD, 0xc5}, /* frame rate inversion */
	{REG_IDX, 0x03}, /* 72Hz */

	/*
	 * Interface Control
	 * Bit[7]: SDA_EN: not used
	 * Bit[6]: fixed 0
	 * Bit[5]: fixed 0
	 * Bit[4]: VSPL, Set the signal polarity of VSYNC (0->Low, 1->High)
	 * Bit[3]: HSPL, Set the signal polarity of HSYNC (0->Low, 1->High)
	 * Bit[2]: fixed 0
	 * Bit[1]: Enable Polarity (0->Low, 1->High)
	 * Bit[0]: Data valid on Falling edge of PCLK
	 */
	{REG_CMD, 0xc6},
	{REG_IDX, 0x03},

	//*************GAMMA SETTING ***************
	{REG_CMD, 0xc8},
	{REG_IDX, 0x00},
	{REG_IDX, 0x26},
	{REG_IDX, 0x21},
	{REG_IDX, 0x00},
	{REG_IDX, 0x00},
	{REG_IDX, 0x1f},
	{REG_IDX, 0x65},
	{REG_IDX, 0x23},
	{REG_IDX, 0x77},
	{REG_IDX, 0x00},
	{REG_IDX, 0x0f},
	{REG_IDX, 0x00},
	//*******************************************
	{REG_CMD, 0x36}, /* set address mode */
	/*
	 * Bit[7] : Page Address Order (Bottom to top)
	 * Bit[6] : Column Address Order (Left To right)
	 * Bit[5] : Page/Column Order (Reverse)
	 * Bit[4] : Line Address Order (LCD Refresh Top to Bottom)
	 * Bit[3] : RGB/BGR Order (0->RGB, 1->BGR)
	 * Bit[2] : fixed 0
	 * Bit[1] : Horizontal Flip
	 * Bit[0] : Vertical Flip
	 */
#ifdef LCD_ROTATE
	{REG_IDX, 0xA0}, /* left to right, reverse mode (00 OK A0ºá) */
#else
	{REG_IDX, 0x0a}, /* left to right, reverse mode (00 OK A0ºá) */
#endif

	/*
	 * 0x66 -> RGB666 18bit, 0x55-> RGB565 16bit
	 */
	{REG_CMD, 0x3a}, /* Set pixel format */
	{REG_IDX, 0x55}, /* RGB565 16bit */

	{REG_CMD, 0x2a}, /* set column address */
	{REG_IDX, 0x00}, /* Low address (0, 0) */
	{REG_IDX, 0x00},
#ifdef LCD_ROTATE
	{REG_IDX, 0x01}, /* High address */
	{REG_IDX, 0xdF}, /* 479(0x1df, w = 480) */
#else
	{REG_IDX, 0x01}, /* High address */
	{REG_IDX, 0x3F}, /* 319(0x13f, w = 320) */
#endif

	{REG_CMD, 0x2b}, /* set page address */
	{REG_IDX, 0x00}, /* Low address (0, 0) */
	{REG_IDX, 0x00},
#ifdef LCD_ROTATE
	{REG_IDX, 0x01}, /* High address */
	{REG_IDX, 0x3f}, /* 319 (0x13f, w = 320) */
#else
	{REG_IDX, 0x01}, /* High address */
	{REG_IDX, 0xdf}, /* 479 (0x1df, w = 480) */
#endif
	{REG_CMD, 0x2c}, //# RAMWR(memory write)

	{REG_CMD, 0x20}, /* exit invert */
	{REG_CMD, 0x11}, /* exit sleep */
	{REG_DELAY,200},

	{REG_CMD, 0xB4}, /* Display Mode & Frame Memory Setting */
	{REG_IDX, 0x11}, /* RGB interface */
	{REG_DELAY,50},

	{REG_CMD, 0x29}, //# Display ON.
	{REG_DELAY,120},
};
#endif

static struct spi_slave *lcd_spi = NULL;

static int lcd_cmd_write(struct spi_slave *spi, u16 val)
{
	u16 params, data = 0;
	int err;

	spi_claim_bus(spi);

	/*
	 * The 9-bit looks like (binary):
	 * 1 bit(L->command, H->data)
	 * <D/CX><8bit data>
	 */
	data = (val << BIT_SHIFT);
	params = SWAP16(data);
	err = spi_xfer(spi, 9, &params, NULL, (SPI_XFER_BEGIN|SPI_XFER_END));
	if (err)
		return err;

	spi_release_bus(spi);

	return 0;
}

static int lcd_idx_write(struct spi_slave *spi, u16 val)
{
	u16 params, data = 0;
	int err;

	spi_claim_bus(spi);

	/*
	 * The 9-bit looks like (binary):
	 * 1 bit(L->command, H->data)
	 * <D/CX><8bit data>
	 */
	data = ((1 << 8 | val) << BIT_SHIFT);
	params = SWAP16(data);
	err = spi_xfer(spi, 9, &params, NULL, (SPI_XFER_BEGIN|SPI_XFER_END));
	if (err)
		return err;

	spi_release_bus(spi);

	return 0;
}

int ili9846_lcd_init(void)
{
	struct lcd_regs_t *regs = (struct lcd_regs_t *)init_regs;
	int i;

	lcd_spi = spi_setup_slave(0, 0, 1000000, SPI_MODE_3);
	if (lcd_spi == NULL) {
		printf("Invalid device giving up.\n");
		return 1;
	}

	//************* Start Initial Sequence **********//
	for (i = 0; i < ARRAY_SIZE(init_regs); i++, regs++) {
		if (regs->type == REG_DELAY) {
			mdelay(regs->val);
//			printf("[ILI9486] regs type delay, value 0x%02x\n", regs->val);
		} else if (regs->type == REG_CMD) {
			lcd_cmd_write(lcd_spi, regs->val);
//			printf("[ILI9486] regs type command, value 0x%02x\n", regs->val);
		} else {
			lcd_idx_write(lcd_spi, regs->val);
//			printf("[ILI9486] regs type index, value 0x%02x\n", regs->val);
		}
	}

	return 0;
}
