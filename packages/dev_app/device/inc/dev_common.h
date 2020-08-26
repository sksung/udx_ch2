/*
 * dev_common.h
 *
 * Copyright (C) 2013 UDWORKs.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Common Hardware library interface definitions.
 */

#ifndef _DEV_COMMON_H__
#define _DEV_COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <time.h> //# nanosleep()
//#define DEBUG

#define dev_err(fmt, arg...)  fprintf(stderr, "%s:%d: " fmt, __FILE__, __LINE__, ## arg)

/* Debugging */
#ifdef DEBUG
#define dev_dbg(fmt, arg...)  fprintf(stdout, "%s:%d: " fmt, __FILE__, __LINE__, ## arg)
#else
#define dev_dbg(fmt, arg...)  do { } while (0)
#endif

#define NAND_MOUNT_POINT	"/media/nand"
#define MMC_MOUNT_POINT		"/mmc"

#define INPUT_PROC_PATH	 	"/proc/bus/input/devices"
#define MOUNT_PROC_PATH 	"/proc/mounts"

#define BITS_PER_LONG 		(sizeof(long) * 8)
#define BIT_WORD(x)			((x) / BITS_PER_LONG)
#define BIT_MASK(x)  		(1UL << ((x) % BITS_PER_LONG))

#define NBITS(x) 			((((x)-1) / BITS_PER_LONG) + 1)

/*
 * test_bit - Determine whether a bit is set
 * nr : bit number to test
 * addr : Address to start counting from
 */
#define TEST_BIT(b, a)		((a[BIT_WORD(b)]>>(b&(BITS_PER_LONG-1)))&1UL)
#define ARRAY_SIZE(x) 		(sizeof(x) / sizeof(x[0]))

int dev_input_get_bus_num(const char *dev_name);
void dev_wait_for_msecs(unsigned int msecs);
int dev_get_board_info(void);
int dev_get_udx_info(void);
int dev_check_mount(const char *mount_point);
int dev_execlp(char *arg);
int dev_mmc_format(void);
int dev_usb_is_exist(int usb_v, int usb_p);
int dev_rtc_set_time(struct tm set_tm);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif //# _DEV_COMMON_H__
