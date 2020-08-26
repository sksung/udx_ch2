/******************************************************************************
 * LG4573B driver
 * Copyright by UDWorks, Incoporated. All Rights Reserved.
 *---------------------------------------------------------------------------*/
 /**
 * @file    lg4573b.c
 * @brief	ubx car main program
 * @author  phoong
 * @section MODIFY history
 *     - 2014.01.29 : First Created
 */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 Defines referenced header files
-----------------------------------------------------------------------------*/
#include <common.h>
#include <asm/arch/cpu.h>
#include <asm/arch/common_ud_defs.h>
#include <asm/gpio.h>
#include <spi.h>

/*----------------------------------------------------------------------------
 Definitions and macro
-----------------------------------------------------------------------------*/
#define LCD_RESET			GPIO_N(3, 22)
#define LCD_BACKLIGHT		GPIO_N(1, 30)

#define mdelay(n)	udelay((n)*1000)

#define LCD_CMD		0x70
#define LCD_DAT		0x72
#define LCD_DLY		0xfe
#define LCD_END		0xff

struct regval_list {
	unsigned char type;
	unsigned char val;
};

static struct regval_list lg4573b_init_reg[] = {
	{LCD_CMD, 0xC1}, // Power Control (1) ?Stand-by off
	{LCD_DAT, 0x00},

	{LCD_CMD, 0x11}, // Sleep Out Powers for the display are On

	{LCD_CMD, 0x3A}, // Interface Pixel format
	{LCD_DAT, 0x70}, // DIPF[2:0] - DBI pixel format [70:24B/60:18B/50:16B]

	{LCD_CMD, 0xB1}, // RGB Interface Setting
	{LCD_DAT, 0x00}, //- - -SYNC CKPL HSPL VSPL DEPL
	{LCD_DAT, 0x14},
	{LCD_DAT, 0x06},

	{LCD_CMD, 0xB2}, // Panel Characteristics Setting
	{LCD_DAT, 0x10},
	{LCD_DAT, 0xC8},

	{LCD_CMD, 0xB3}, // Panel Drive Setting (Column Inversion)[ 1-Dot Inversion : Set 0001h ]
	{LCD_DAT, 0x00},

	{LCD_CMD, 0xB4}, // Display Mode Control
	{LCD_DAT, 0x04},

	{LCD_CMD, 0xB5}, // Display Control (1)
	{LCD_DAT, 0x05},
	{LCD_DAT, 0x10},
	{LCD_DAT, 0x10},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},

	{LCD_CMD, 0xB6}, // Display Control (2)
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x02},
	{LCD_DAT, 0x40},
	{LCD_DAT, 0x02},
	{LCD_DAT, 0x00},

	//# ********************** OSC control **********************
	{LCD_CMD, 0xC0}, // Oscillator Control
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x1F},

	//# ********************** Power Control ********************
	{LCD_CMD, 0xC2}, // Power Control (2)
	{LCD_DAT, 0x00},

	{LCD_CMD, 0xC3}, // Power Control (3)
	{LCD_DAT, 0x03},
	{LCD_DAT, 0x04},
	{LCD_DAT, 0x05},
	{LCD_DAT, 0x06},
	{LCD_DAT, 0x01},

	{LCD_CMD, 0xC4}, // Power Control (4)
	{LCD_DAT, 0x02},
	{LCD_DAT, 0x23},
	{LCD_DAT, 0x16},
	{LCD_DAT, 0x16},
	{LCD_DAT, 0x02},
	{LCD_DAT, 0x7A},

	{LCD_CMD, 0xC5}, // Power Control (5)
	{LCD_DAT, 0x77},

	{LCD_CMD, 0xC6}, // Power Control (6)
	{LCD_DAT, 0x24},
	{LCD_DAT, 0x60},
	{LCD_DAT, 0x00},

	//# ********************** Gamma Control Start **************
	{LCD_CMD, 0xD0}, // Positive Gamma for Red
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x26},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x31},
	{LCD_DAT, 0x03},

	{LCD_CMD, 0xD1}, // Negative Gamma for Red
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x26},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x31},
	{LCD_DAT, 0x03},

	{LCD_CMD, 0xD2}, // Positive Gamma for Green
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x26},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x31},
	{LCD_DAT, 0x03},

	{LCD_CMD, 0xD3}, // Negative Gamma for Green
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x26},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x31},
	{LCD_DAT, 0x03},

	{LCD_CMD, 0xD4}, // Positive Gamma for Blue
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x26},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x31},
	{LCD_DAT, 0x03},

	{LCD_CMD, 0xD5}, // Negative Gamma for Blue
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x26},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x66},
	{LCD_DAT, 0x31},
	{LCD_DAT, 0x03},
	//# ********************** Gamma Control End ****************

	{LCD_CMD, 0x11}, // Sleep Out
	{LCD_CMD, 0x29}, // Display On

	{LCD_CMD, 0x2A}, // Column Address Set 0.
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x01},
	{LCD_DAT, 0x3F}, // 1DF = 479

	{LCD_CMD, 0x2B}, // Page Address Set 0.
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x00},
	{LCD_DAT, 0x03},
	{LCD_DAT, 0x1F}, // 31F = 799

	{LCD_END, 0x00}
};

/*----------------------------------------------------------------------------
 Declares variables
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 Declares a function prototype
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 local function
-----------------------------------------------------------------------------*/
static int lcd_send_word(struct spi_slave *spi, u8 cmd, u8 data)
{
	int ret;

	spi_claim_bus(spi);
	/*
	 * The transmit word (x:don't care)
	 * <R/W><DCX><H/L>XXXXX<D[8:0]>
	 */
	ret = spi_xfer(spi, 8, &cmd, NULL, SPI_XFER_BEGIN);
	if (ret)
		return ret;

	ret = spi_xfer(spi, 8, &data, NULL, SPI_XFER_END);
	if (ret)
		return ret;

	spi_release_bus(spi);

	return 0;
}

/*****************************************************************************
* @brief    lg4573b_lcd_init function
* @section  DESC Description
*   - desc
*****************************************************************************/
int lg4573b_lcd_init(void)
{
	int ret;
	static struct spi_slave *lcd_spi;
	struct regval_list *regs;

	//#--- lcd reset
	gpio_set_value(LCD_RESET, 0);
	udelay(50); /* wait for more than 10us */
	gpio_set_value(LCD_RESET, 1);

	mdelay(10);		//# wait for reset complete

	lcd_spi = spi_setup_slave(2, 0, 5000000, SPI_MODE_3);
	if (!lcd_spi)
		return -1;

	//#--- lcd initialize
	regs = (struct regval_list *)lg4573b_init_reg;
	while (regs->type != LCD_END)
	{
		if(regs->type == LCD_DLY) {
			mdelay(regs->val);
			regs++;
			continue;
		}

		ret = lcd_send_word(lcd_spi, regs->type, regs->val);
		if(ret)
			printf("write fail 0x%x, 0x%x\n", regs->type, regs->val);

		regs++;
	}

	if (lcd_spi) {
		spi_free_slave(lcd_spi);
		lcd_spi = NULL;
	}

	//#--- backlight on
	gpio_set_value(LCD_BACKLIGHT, 1);

	return 0;
}
