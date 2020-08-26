/*
 * dev_lcd.h
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
 * LCD Hardware library interface definitions.
 */

#ifndef _DEV_LCD_H_
#define _DEV_LCD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define LCD_DEV_NAME		"/dev/spidev3.0"
#define LCD_SYSFS_PATH	    "/sys/class/backlight/pwm-backlight/brightness"

typedef enum {
	LCD_DISP_OFF,
	LCD_DISP_ON,
	MAX_LCD_CMD
} lcd_cmd_e;

int dev_lcd_init(void);
void dev_lcd_exit(void);
int dev_lcd_ctrl(int cmd);
int dev_lcd_set_bright(int brightness);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _DEV_LCD_H_ */
