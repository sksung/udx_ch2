/*
 * Code for UCX.
 *
 * Copyright (C) 2010 Texas Instruments, Inc. - http://www.ti.com/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/partitions.h>
#include <linux/gpio.h>
#include <linux/i2c.h>
#include <linux/regulator/machine.h>
#include <linux/spi/spi.h>
#include <linux/input.h>
#include <linux/input/kxcj9.h>
#include <linux/gpio_keys.h>
#include <sound/tlv320aic3x.h>

#include <mach/hardware.h>
#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <asm/mach/map.h>

#include <plat/mcspi.h>
#include <plat/irqs.h>
#include <plat/board.h>
#include <plat/common.h>
#include <plat/asp.h>
#include <plat/usb.h>
#include <plat/mmc.h>
#include <plat/gpmc.h>
#include <plat/nand.h>

#include "board-flash.h"
#include "clock.h"
#include "mux.h"
#include "hsmmc.h"
#include "control.h"
#include "device_version.h"

#define BOARD_REV_OFFSET		(TI81XX_GPIO0_BASE+0x138)

#define ACC_IRQ					GIO(3, 12) /* accelerometer */
#define PWR_HOLD				GIO(2, 26)	//# power hold

#ifdef CONFIG_OMAP_MUX
static struct omap_board_mux board_mux[] __initdata = {
	{ .reg_offset = OMAP_MUX_TERMINATOR },
};
#else
#define board_mux     NULL
#endif

u32 board_rev(void)
{
	void __iomem *reg =
			TI81XX_L4_SLOW_IO_ADDRESS(BOARD_REV_OFFSET);

	/* get gpio bank0_(1,2,3,4) */
	return ((__raw_readl(reg)>>1)&0x0F);
}
EXPORT_SYMBOL(board_rev);

/* accelerometer init */
static int accel_init(void)
{
	int err = 0;

	/* pull disable & input enable */
	omap_mux_init_signal("vout1_g_y_yc8.gpio3_12", TI814X_PULL_DIS | (1 << 18));

	err = gpio_request(ACC_IRQ, "accel_irq");
	if (err) {
		printk(KERN_ERR "%s: failed to request GPIO for G_SENSOR"
			": %d\n", __func__, err);
		return err;
	}
	gpio_direction_input(ACC_IRQ);

	return err;
}

static void accel_exit(void)
{
	omap_mux_init_signal("vout1_g_y_yc8", 0);
	gpio_free(ACC_IRQ);
}

static struct kxcj9_platform_data kxcj9_pdata = {
	.min_interval		= 1,
	.init_interval		= 20, /* start-up time (50Hz) */

	.axis_map_x		= 0,
	.axis_map_y		= 1,
	.axis_map_z		= 2,

	.negate_x		= 0,
	.negate_y		= 0,
	.negate_z		= 0,

	.res_12bit		= RES_12BIT,
	.g_range		= KXCJ9_G_8G,
	.init			= accel_init,
	.exit			= accel_exit,
	.power_on		= NULL,
	.power_off		= NULL,
};

static struct aic3x_pdata audio_pdata = {
	.gpio_reset = 0, /* < 0 if not used */
	.setup = NULL,
};

static struct i2c_board_info __initdata i2c0_boardinfo[] = {
	{
		I2C_BOARD_INFO("tlv320aic3x", 0x18),
		.platform_data = &audio_pdata,
	},
	{
		I2C_BOARD_INFO("mcp7941x", 0x6F),
		.platform_data = NULL,
	},
};

static struct i2c_board_info __initdata i2c1_boardinfo[] = {
	{
		I2C_BOARD_INFO("kxcj9", 0x0E),
		.platform_data = &kxcj9_pdata,
		#ifdef CONFIG_INPUT_KXCJ9_POLLED_MODE
		.irq = 0,
		#else
		.irq = OMAP_GPIO_IRQ(ACC_IRQ)
		#endif
	},
};

static void __init hd2_i2c_init(void)
{
	/* There are 4 instances of I2C in TI814X but currently only one
	 * instance is being used on the TI8148 EVM
	 */
	if (device_udx_get()) {
		/* udx-ii */
		audio_pdata.gpio_reset = GIO(1, 21);
	} else {
		/* udx-i */
		audio_pdata.gpio_reset = GIO(1, 19);
	}
	omap_register_i2c_bus(1, 400, i2c0_boardinfo, ARRAY_SIZE(i2c0_boardinfo));
	omap_register_i2c_bus(2, 400, i2c1_boardinfo, ARRAY_SIZE(i2c1_boardinfo));
}

/* NAND flash information */
static struct mtd_partition hd2_nand_partitions[] = {
/* All the partition sizes are listed in terms of NAND block size */
	{
		.name           = "U-Boot-min",
		.offset         = 0,                   /* 0x000000000000-0x000000020000 */
		.size           = SZ_128K,
		.mask_flags	    = MTD_WRITEABLE,       /* force read-only */
	},
	{
		.name           = "U-Boot",
		.offset         = MTDPART_OFS_APPEND,  /* 0x000000020000-0x0000000c0000 */
		.size           = 5 * SZ_128K,
		.mask_flags	    = MTD_WRITEABLE,       /* force read-only */
	},
	{
		.name           = "U-Boot Env",
		.offset         = MTDPART_OFS_APPEND,   /* 0x0000000c0000-0x000000120000 */
		.size           = 3 * SZ_128K,
		.mask_flags		= 0,
	},
	{
		.name           = "boot logo",
		.offset         = MTDPART_OFS_APPEND,   /* 0x000000120000-0x000000220000 */
		.size           = 8 * SZ_128K,
		.mask_flags	    = MTD_WRITEABLE,       /* force read-only */
	},
	{
		.name           = "Kernel",
		.offset         = MTDPART_OFS_APPEND,   /* 0x000000220000-0x000000520000 */
		.size           = 24 * SZ_128K,         /* 3072KB */
		.mask_flags		= 0,
	},
	{
		.name           = "File System",
		.offset         = MTDPART_OFS_APPEND,   /* 0x000000520000-0x000003520000 */
		.size           = 384 * SZ_128K,        /* 48MB */
		.mask_flags		= 0,
	},
	{
		.name           = "Data",
		.offset         = MTDPART_OFS_APPEND,   /* 0x000003520000-0x000007c00000 */
		.size           = 567 * SZ_128K,        /* 70MB */
		.mask_flags		= 0,
	},
	{
		.name           = "Reserved",
		.offset         = MTDPART_OFS_APPEND,   /* 0x000007c00000-0x000008000000 */
		.size           = MTDPART_SIZ_FULL,     /* 4MB */
		.mask_flags		= 0,
	},
};

static struct omap_musb_board_data musb_board_data = {
	.interface_type		= MUSB_INTERFACE_ULPI,
#ifdef CONFIG_USB_MUSB_OTG
	.mode           = MUSB_OTG,
#elif defined(CONFIG_USB_MUSB_HDRC_HCD)
	.mode           = MUSB_HOST,
#elif defined(CONFIG_USB_GADGET_MUSB_HDRC)
	.mode           = MUSB_PERIPHERAL,
#endif
	.power		= 500,
	.instances	= 1,
};

static void __init hd2_init_irq(void)
{
	omap2_init_common_infrastructure();
	omap2_init_common_devices(NULL, NULL);
	omap_init_irq();
	gpmc_init();
}

/* audio initialize */
static u8 aic3x_iis_serializer_direction[] = {
	TX_MODE,	RX_MODE,	INACTIVE_MODE,	INACTIVE_MODE,
	INACTIVE_MODE,	INACTIVE_MODE,	INACTIVE_MODE,	INACTIVE_MODE,
	INACTIVE_MODE,	INACTIVE_MODE,	INACTIVE_MODE,	INACTIVE_MODE,
	INACTIVE_MODE,	INACTIVE_MODE,	INACTIVE_MODE,	INACTIVE_MODE,
};

/*
 * The McASP version 2 supports a hardware FIFO of 256bytes
 * each Tx/Rx which provides additional data buffering and allows
 * tolerance to variations in DMA controller response times.
 */
static struct snd_platform_data aic3x_snd_data = {
	.tx_dma_offset	= 0x46400000,
	.rx_dma_offset	= 0x46400000,
	.op_mode	= DAVINCI_MCASP_IIS_MODE,
	.num_serializer = ARRAY_SIZE(aic3x_iis_serializer_direction),
	.tdm_slots	= 2, /* number of channels */
	.serial_dir	= aic3x_iis_serializer_direction,
	.asp_chan_q	= EVENTQ_0, /* don't use Q2 */
	.version	= MCASP_VERSION_2,
	/*
     * Having Max number of channels as mcasp fifo / edma read depth.
     * For 4ch->32 this granularity is still 16 which is ok
     */
	.txnumevt = 32, //# total 256bytes (1 word 4byte)
	.rxnumevt = 32, //# total 256bytes (1 word 4byte)

	/* McASP21_AHCLKX out to feed CODEC CLK*/
	.clk_input_pin	= MCASP_AHCLKX_OUT,
};

static struct resource ti81xx_mcasp1_resource[] = {
    {
        .name = "mcasp1",
        .start = TI81XX_ASP1_BASE,
        .end = TI81XX_ASP1_BASE + (SZ_1K * 12) - 1,
        .flags = IORESOURCE_MEM,
    },
    /* TX event */
    {
        .start = TI81XX_DMA_MCASP1_AXEVT,
        .end = TI81XX_DMA_MCASP1_AXEVT,
        .flags = IORESOURCE_DMA,
    },
    /* RX event */
    {
        .start = TI81XX_DMA_MCASP1_AREVT,
        .end = TI81XX_DMA_MCASP1_AREVT,
        .flags = IORESOURCE_DMA,
    },
};

static struct platform_device audio_dev = {
    .name = "davinci-mcasp",
    .id = 1,
    .dev ={
		.platform_data = &aic3x_snd_data,
	},
    .num_resources = ARRAY_SIZE(ti81xx_mcasp1_resource),
    .resource = ti81xx_mcasp1_resource,
};

static struct omap2_hsmmc_info mmc[] = {
	{
		.mmc		= 1,
		.caps		= MMC_CAP_4_BIT_DATA,
		.gpio_cd	= GIO(1, 6),
		.gpio_wp	= -EINVAL,
		.ocr_mask	= MMC_VDD_33_34,
	},
	{}	/* Terminator */
};

static void __init hd2_mux_init(void)
{
	omap_mux_init_signal("xref_clk1.mcasp1_ahclkx", 0);	/* MCA[1]_ahclkx */
}

extern struct platform_device **omap_pwm_devices;

static void __init hd2_init(void)
{
	ti814x_mux_init(board_mux);
	omap_serial_init();

	/* For gpio_sdcd */
	omap_mux_init_signal("spi0_cs1.gpio1_6", TI814X_PIN_INPUT_PULL_UP);
	omap2_hsmmc_init(mmc);

	hd2_mux_init();
	hd2_i2c_init();

	/* nand initialisation */
	board_nand_init(hd2_nand_partitions,
					ARRAY_SIZE(hd2_nand_partitions), 0, 0);

	/* initialize usb */
	usb_musb_init(&musb_board_data);
	regulator_use_dummy_regulator();

	platform_device_register(&audio_dev);

	printk(KERN_INFO "HD2 Board Revision 0.%d\n", board_rev());
}

static int __init hd2_gpio_init(void)
{
	gpio_request(PWR_HOLD, "pwr_hold");
	gpio_direction_input(PWR_HOLD);		//# for control by mcu

	return 0;
}
/* GPIO setup should be as subsys_initcall() as gpio driver
 * is registered in arch_initcall() */
subsys_initcall(hd2_gpio_init);

static void __init hd2_map_io(void)
{
	omap2_set_globals_ti816x();
	ti81xx_map_common_io();
}

MACHINE_START(DM385EVM, "hd2")
	/* Maintainer: Texas Instruments */
	.boot_params	= 0x80000100,
	.map_io			= hd2_map_io,
	.reserve		= ti81xx_reserve,
	.init_irq		= hd2_init_irq,
	.init_machine	= hd2_init,
	.timer			= &omap_timer,
MACHINE_END
