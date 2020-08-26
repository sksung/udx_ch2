/*****************************************************************************/
/*                                                                           */
/*  Name:           device_version.c                                                 */
/*  Autor:          hw.huang                                            */
/*  Description:    device version                                           */
/*  Project:        IPNC DM814x					                              */
/*                                                                           */
/*****************************************************************************/

/**************************************************************************
 * Included Files
 **************************************************************************/
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/spinlock.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <plat/cpu.h>
#include "control.h"
#include <linux/io.h>
#include "device_version.h"

#ifdef CONFIG_PROC_FS

#define MAX_BUF	1024

static unsigned char mcu_options[20];

static int set_mcu_cmdline_value(char *options)
{
	/* The first char passed from the bootloader is '=', so ignore it */
	strcpy(mcu_options, options + 1);

	printk("mcu: kernel boot params mcu value: %s\n",
	       mcu_options);

	return 1;
}
__setup("mcu", set_mcu_cmdline_value);

int device_version_get(void)
{
#ifdef CONFIG_COMMON_UD_FEATURE
	u32 rev;
	rev = board_rev();
#else
	u32 id;
	u32 rev;

	id = omap_ctrl_readl(TI81XX_CONTROL_DEVICE_ID);
	rev = (id >> 28) & 0xF;

#ifdef CONFIG_MACH_TI8148IPNC
	/* PG2.1 devices should read 0x3 as chip rev
	 * Some PG2.1 devices have 0xc as chip rev
	 */
	if (0x3 == rev || 0xc == rev)
		return 1;	/*	PG2.1	*/
	else
		return 0;	/*	PG1.0	*/
#endif
#endif //# CONFIG_COMMON_UD_FEATURE

	return (int)rev;
}

static int proc_device_version(char *page, char **start, off_t off,
		       int count, int *eof, void *data)
{
	int len = 0;
	char buffer[MAX_BUF];

	len +=
	    sprintf(&buffer[len], "%d\n", device_version_get());

	if (count > len)
		count = len;

	memcpy(page, &buffer[off], count);

	*eof = 1;
	*start = NULL;
	return len;
}

int device_udx_get(void)
{
	unsigned long val;
	int ret = 0;

	ret = strict_strtoul(mcu_options, 0x10, &val);
	if (ret < 0)
		return 1;

	return (int)val;
}

static int proc_udx_version(char *page, char **start, off_t off,
		       int count, int *eof, void *data)
{
	int len = 0;
	char buffer[MAX_BUF];

	len +=
	    sprintf(&buffer[len], "%d\n", device_udx_get());

	if (count > len)
		count = len;

	memcpy(page, &buffer[off], count);

	*eof = 1;
	*start = NULL;
	return len;
}

int __init device_version_proc_client_create(void)
{
	create_proc_read_entry("device_version", 0, NULL, proc_device_version, NULL);
	create_proc_read_entry("udx_version", 0, NULL, proc_udx_version, NULL);

	return 0;
}
#else				/* CONFIG_PROC_FS */

#define device_version_proc_client_create() do {} while(0);

#endif				/* CONFIG_PROC_FS */

EXPORT_SYMBOL(device_version_get);
EXPORT_SYMBOL(device_udx_get);

module_init(device_version_proc_client_create);
