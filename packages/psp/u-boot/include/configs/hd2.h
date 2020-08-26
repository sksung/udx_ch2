/*
 * Copyright (C) 2011, Texas Instruments, Incorporated
 *
 * See file CREDITS for list of people who contributed to this
 * project.
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

#ifndef __CONFIG_HD2_H
#define __CONFIG_HD2_H

/**
 * Board define
 */
#define USE_UBIFS

//# DDR3 - 400, 533
#define CONFIG_DM385_DDR3_400

#define CONFIG_OMAP_GPIO
#define CONFIG_GPIO_LED
#define CONFIG_USE_ARCH_IO
#define CONFIG_SYS_CACHELINE_SIZE	64	/* For ARM Cortex-A8 CPU */

/*----------- 1st stage we have just 110K -------------------------*/
#ifdef CONFIG_TI814X_MIN_CONFIG
/* enable d-cache only on 2nd stage */
# define CONFIG_SYS_DCACHE_OFF

# define CONFIG_CMD_MEMORY			/* for mtest */
# undef CONFIG_GZIP
# undef CONFIG_ZLIB
# undef CONFIG_SYS_HUSH_PARSER
# define CONFIG_CMD_LOADB			/* loadb */
# define CONFIG_CMD_LOADY			/* loady */
# define CONFIG_SETUP_PLL
# define CONFIG_TI814X_CONFIG_DDR
# define CONFIG_DISPLAY_CPUINFO		/* Display CPU info */

# define CONFIG_ENV_SIZE			0x400
# define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (8 * 1024))
# define CONFIG_SYS_PROMPT			"HD2-MIN # "
# define CONFIG_BOOTDELAY			0

# if defined(CONFIG_NAND_BOOT)		/* Autoload the 2nd stage from NAND (Total:640KB, read:192KB) */
#  define CONFIG_NAND				1
#  define CONFIG_EXTRA_ENV_SETTINGS \
	"verify=yes\0" \
	"bootcmd=nand read 0x80800000 0x00020000 0x30000; go 0x80800000\0" \

# elif defined(CONFIG_SD_BOOT)		/* Autoload the 2nd stage from SD */
#  define CONFIG_MMC				1
#  define CONFIG_EXTRA_ENV_SETTINGS \
	"verify=yes\0" \
	"bootcmd=mmc rescan; fatload mmc 0 0x80800000 u-boot_hd2.bin; go 0x80800000\0" \

# elif defined(CONFIG_UART_BOOT)		/* stop in the min prompt */
# define CONFIG_EXTRA_ENV_SETTINGS \
	"verify=yes\0" \
	"bootcmd=\0" \

# elif defined(CONFIG_ETH_BOOT)		/* Auto load 2nd stage from server */
#  define CONFIG_EXTRA_ENV_SETTINGS \
	"verify=yes\0" \
	"bootcmd=setenv autoload no;dhcp; tftp 0x81000000 u-boot_hd2.bin; go 0x81000000\0"
# endif

#else
/*----------- 2nd stage configs -----------------------------------*/
# include <config_cmd_default.h>
# define CONFIG_TI814X_LOGO
# define CONFIG_ENV_SIZE			0x20000
# define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (32 * 1024))
# define CONFIG_ENV_OVERWRITE
# undef CONFIG_SYS_LONGHELP         /* Avoid long help text for the u-boot commands */
# define CONFIG_SYS_PROMPT			"UBOOT # "
# define CONFIG_SYS_HUSH_PARSER			/* Use HUSH parser to allow command parsing */
# define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
# define CONFIG_CMDLINE_TAG        	1	/* enable passing of ATAGs  */
# define CONFIG_SETUP_MEMORY_TAGS  	1
# define CONFIG_INITRD_TAG	  		1	/* Required for ramdisk support */
# define CONFIG_BOOTDELAY			0	/* set to negative value for no autoboot */
# define CONFIG_SILENT_CONSOLE 		1   /* the prints off  */
# define CONFIG_NAND_UPDATE			1	/* from sd card via boot.scr */
//# define CONFIG_PHY_RESET_DELAY		30000  /* at least 20ms (for RTL8201FL) */
# define CONFIG_USE_ARCH_MEMSET
# define CONFIG_USE_ARCH_MEMCPY
# define __HAVE_ARCH_MEMSET
# define __HAVE_ARCH_MEMCPY
# define CONFIG_MMC
# define CONFIG_NAND
# define CONFIG_I2C
# define CONFIG_RTC
# define CONFIG_MCU_UPDATE
# define BOARD_LATE_INIT
# undef CONFIG_USB_TI81XX
# undef CONFIG_MUSB_HCD

# undef CONFIG_GZIP
# undef CONFIG_CMD_XIMG

# define CONFIG_EXTRA_ENV_SETTINGS \
	"script_addr=0x80900000\0" \
	"loadbootscript=fatload mmc 0 ${script_addr} boot.scr\0" \
	"bootscript= echo Running bootscript from MMC/SD to set the ENV...; " \
		"source ${script_addr}\0" \
	"showlogo=nand read 0x82100000 0x00120000 0xBB800;logo on 0x82000000;\0" \

# define CONFIG_BOOTCOMMAND \
	"run showlogo; " \
	"if test ${nand_update} -eq 1; then " \
		"if mmc rescan; then " \
			"if run loadbootscript; then " \
				"run bootscript; " \
			"fi; " \
		"fi; " \
	"else " \
		"nboot.e 0x81000000 0 0x00220000;bootm 0x81000000; " \
	"fi"

# define CONFIG_BOOTARGS \
	"mem=180M console=ttyO0,115200n8 noinitrd rw ubi.mtd=5,2048 rootfstype=ubifs root=ubi0:rootfs ip=off vram=3M notifyk.vpssm3_sva=0xBFD00000 eth=${ethaddr} mcu=${udxii}"

#define CONFIG_GATEWAYIP		192.168.1.1
#define CONFIG_SERVERIP			192.168.1.100
#define CONFIG_IPADDR			192.168.1.200
#define CONFIG_NETMASK			255.255.255.0

#endif	//# #ifdef CONFIG_TI814X_MIN_CONFIG

#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_SYS_GBL_DATA_SIZE		128
#define CONFIG_CMD_CACHE
#define CONFIG_CMD_ECHO

/*
 * Miscellaneous configurable options
 */

/* max number of command args */
#define CONFIG_SYS_MAXARGS			32
/* Console I/O Buffer Size */
#define CONFIG_SYS_CBSIZE			512
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE			(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE			CONFIG_SYS_CBSIZE
/* memtest works on 8 MB in DRAM after skipping 32MB from start addr of ram disk*/
#define CONFIG_SYS_MEMTEST_START	(PHYS_DRAM_1 + (64 *1024 *1024))
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_MEMTEST_START  + (8 * 1024 * 1024))

#undef  CONFIG_SYS_CLKS_IN_HZ		/* everything, incl board info, in Hz */
#define CONFIG_SYS_LOAD_ADDR		0x81000000  	/* Default load address */
#define CONFIG_SYS_HZ				1000        	/* 1ms clock */

/* Hardware related */
/**
 * Physical Memory Map
 */
/* we have 1 bank of DRAM */
#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_DRAM_1				0x80000000	/* DRAM Bank #1 */
#define PHYS_DRAM_1_SIZE		0x20000000	/* 512 MGB */

/**
 * Platform/Board specific defs
 */
#define CONFIG_SYS_CLK_FREQ		20000000
#define CONFIG_SYS_TIMERBASE	0x4802E000

/*
 * NS16550 Configuration
 */
#define CONFIG_SERIAL_MULTI
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		(48000000)
#define CONFIG_SYS_NS16550_COM1		0x48020000	/* Base EVM has UART0 */
#define CONFIG_SYS_NS16550_COM3		0x48024000	/* UART2 */

#define CONFIG_BAUDRATE		115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 110, 300, 600, 1200, 2400, \
4800, 9600, 14400, 19200, 28800, 38400, 56000, 57600, 115200 }

/*
 * select serial console configuration
 */
#define CONFIG_SERIAL1			1
#define CONFIG_CONS_INDEX		1
#define CONFIG_SYS_CONSOLE_INFO_QUIET

#if defined(CONFIG_NO_ETH)
# undef CONFIG_CMD_NET
#else
# define CONFIG_CMD_NET
# define CONFIG_CMD_DHCP
# define CONFIG_CMD_PING
#endif

#if defined(CONFIG_CMD_NET)
# define CONFIG_DRIVER_TI_CPSW
# define CONFIG_MII 				/* Actually, use RMII interface */
# define CONFIG_BOOTP_DEFAULT
# define CONFIG_BOOTP_DNS
# define CONFIG_BOOTP_DNS2
# define CONFIG_BOOTP_SEND_HOSTNAME
# define CONFIG_BOOTP_GATEWAY
# define CONFIG_BOOTP_SUBNETMASK
# define CONFIG_NET_RETRY_COUNT		10
# define CONFIG_NET_MULTI
# undef  CONFIG_PHY_GIGE 			/* UD8107 supported 10/100 */
/* increase network receive packet buffer count for reliable TFTP */
# define CONFIG_SYS_RX_ETH_BUFFER	16
#endif

#if defined(CONFIG_SYS_NO_FLASH)
# define CONFIG_ENV_IS_NOWHERE
#endif

/* NAND support */
#ifdef CONFIG_NAND
#define CONFIG_CMD_NAND
#define CONFIG_NAND_TI81XX
#define GPMC_NAND_ECC_LP_x16_LAYOUT	1
#define NAND_BASE				(0x08000000)
#define CONFIG_SYS_NAND_ADDR	NAND_BASE	/* physical address  to access nand */
#define CONFIG_SYS_NAND_BASE	NAND_BASE	/* physical address  to access nand at  CS0 */
#define CONFIG_SYS_MAX_NAND_DEVICE	1		/* Max number of NAND */
#define CONFIG_SYS_NAND_PREFETCH
#define CONFIG_SYS_NAND_WAIT_MONITOR
#endif

/* ENV in NAND */
#if defined(CONFIG_NAND_ENV)
# undef CONFIG_ENV_IS_NOWHERE
# define CONFIG_ENV_IS_IN_NAND		1
# ifdef CONFIG_ENV_IS_IN_NAND
#  define CONFIG_SYS_MAX_FLASH_SECT		520		/* max number of sectors in a chip */
#  define CONFIG_SYS_MAX_FLASH_BANKS	2		/* max number of flash banks */
#  define CONFIG_SYS_MONITOR_LEN	(256 << 10)	/* Reserve 2 sectors */
#  define CONFIG_SYS_FLASH_BASE		boot_flash_base
#  define CONFIG_SYS_MONITOR_BASE	CONFIG_SYS_FLASH_BASE
#  define MNAND_ENV_OFFSET			0xC0000		/* environment starts here */
#  define CONFIG_SYS_ENV_SECT_SIZE	boot_flash_sec
#  define CONFIG_ENV_OFFSET			boot_flash_off
#  define CONFIG_ENV_ADDR			MNAND_ENV_OFFSET
#  define CONFIG_ENV_RANGE			0x20000 * 3	/* block size * 3 */
# endif

# ifndef __ASSEMBLY__
extern unsigned int boot_flash_base;
extern volatile unsigned int boot_flash_env_addr;
extern unsigned int boot_flash_off;
extern unsigned int boot_flash_sec;
extern unsigned int boot_flash_type;
# endif
#endif /* NAND support */

/* ENV in MMC */
#if defined(CONFIG_MMC_ENV)
#undef CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_IS_IN_MMC	1
#define CONFIG_SYS_MMC_ENV_DEV	0
#undef CONFIG_ENV_SIZE
#undef CONFIG_ENV_OFFSET
#define CONFIG_ENV_OFFSET		(6 * 64 * 1024)
#define CONFIG_ENV_SIZE			(8 * 1024)
#endif /* MMC support */

#ifdef CONFIG_PWM
# define CONFIG_PWM_TI81XX
# define CONFIG_SYS_PWM_ID			7
#endif

/* No I2C support in 1st stage */
#ifdef CONFIG_I2C
# define CONFIG_CMD_I2C
# define CONFIG_HARD_I2C			1
# define CONFIG_SYS_I2C_SPEED		400000
# define CONFIG_SYS_I2C_SLAVE		1
# define CONFIG_SYS_I2C_BUS			0
# define CONFIG_SYS_I2C_BUS_SELECT	1
# define CONFIG_DRIVER_TI81XX_I2C	1
# define CONFIG_I2C_MULTI_BUS
# define CONFIG_I2C_ADC_BUS			1
# define CONFIG_I2C_REPEATED_START	1
#endif

/* SPI support */
#ifdef CONFIG_SPI
# define CONFIG_OMAP3_SPI
# define CONFIG_CMD_SPI
# define CONFIG_SF_DEFAULT_SPEED	(80000000)
# define CONFIG_LG4573B
#endif

/* HSMMC support */
#ifdef CONFIG_MMC
# define CONFIG_CMD_MMC				1
# define CONFIG_GENERIC_MMC
# define CONFIG_OMAP_HSMMC
# define CONFIG_DOS_PARTITION		1
# define CONFIG_CMD_FAT				1
# define CONFIG_FS_FAT				1
#endif

/* RTC Support */
#ifdef CONFIG_RTC
#define CONFIG_SYS_I2C_RTC_ADDR		0x6F
#define CONFIG_RTC_MCP7940			//# RTC definitions
#if defined(CONFIG_CMD_NET)
# define CONFIG_CMD_DATE
# define CONFIG_CMD_SNTP
# define CONFIG_TIMESTAMP
# define CONFIG_NTPSERVERIP		192.168.1.231
# define CONFIG_TIMEOFFSET		32400		//# (9*3600)
#endif
#endif /* RTC support */

#ifdef CONFIG_MUSB_HCD
# define CONFIG_CMD_USB			1
# define CONFIG_USB_STORAGE		1
# define CONFIG_DOS_PARTITION	1
# define CONFIG_CMD_FAT			1
# define CONFIG_FS_FAT			1
# define CONFIG_FAT_WRITE		1
#endif /* CONFIG_MUSB_HCD */

/* Unsupported features */
#undef CONFIG_USE_IRQ

#endif	  /* ! __CONFIG_HD2_H */
