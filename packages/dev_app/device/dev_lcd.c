/*
 * File : dev_lcd.c
 *
 * Copyright (C) 2013 UDWORKs
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
 * License along with this library
 *
 * this implements a lcd hardware library for UBX.
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "dev_common.h"
#include "dev_lcd.h"

#define LCD_LG4573B

#define SPI_SPEED				5000000
#define LCD_RESX_PATH			"/sys/class/leds/resx/brightness"

#define LCD_CMD		0x70
#define LCD_DAT		0x72
#define LCD_DLY		0xfe
#define LCD_END		0xff

struct regval_list {
	unsigned char type;
	unsigned char val;
};

static struct regval_list lcd_disp_on[] = {
	{LCD_CMD, 0x11}, 	//# Sleep Out
	{LCD_CMD, 0x29}, 	//# Display On
	{LCD_END, 0x00}
};

static struct regval_list lcd_disp_off[] = {
	{LCD_CMD, 0x10}, 	//# Sleep in
	{LCD_CMD, 0x28}, 	//# Display Off
	{LCD_END, 0x00}
};

static int spi_fd = -1;

/*****************************************************************************
* @brief    lcd function
* @section  DESC Description
*   - desc
*****************************************************************************/
static int lcd_write(unsigned char cmd, unsigned char data)
{
    int ret = 0;
    unsigned char tx_buf[2];

    struct spi_ioc_transfer trans = {
        .tx_buf = (unsigned long)&tx_buf,
        .rx_buf = (unsigned long)0,
        .len = 2,
        .delay_usecs = 0,
        .speed_hz = SPI_SPEED,
        .bits_per_word = 8,
    };

    tx_buf[0] = cmd;
    tx_buf[1] = data;
    ret = ioctl(spi_fd, SPI_IOC_MESSAGE(1), &trans);

    return ret;
}

/****************************************************
 * NAME : int dev_lcd_init(void)
 *
 * Desc   : Initialize lcd Hadrdware
 *
 * INPUT  :
 *   PARAMETERS: none
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values:  0  (succeed)
 *               -1  (failure)
 ****************************************************/
int dev_lcd_init(void)
{
	uint8_t mode = SPI_MODE_3;
	uint8_t bits = 8;
	uint32_t speed = SPI_SPEED;

	int ret = 0;

	spi_fd = open(LCD_DEV_NAME, O_RDWR);
	if (spi_fd < 0) {
		dev_err("can't open device\n");
		return -1;
	}

	/* set spi mode = mode_3 */
	ret = ioctl(spi_fd, SPI_IOC_WR_MODE, &mode);
	if (ret < 0) {
		dev_err("can't set spi mode\n");
		goto exit_spi;
	}

	/* set bits per word */
	ret = ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret < 0) {
		dev_err("can't set bits per word\n");
		goto exit_spi;
	}

	/* set max speed hz */
	ret = ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret < 0) {
		dev_err("can't set max speed hz\n");
		goto exit_spi;
	}

	return 0;

exit_spi:
	if (spi_fd >= 0) {
		close(spi_fd);
		spi_fd = -1;
	}

	return -1;
}

/****************************************************
 * NAME : void dev_lcd_exit(void)
 *
 * Desc   : Deinitialize lcd Hadrdware
 *
 * INPUT  :
 *   PARAMETERS: none
 *
 * OUTPUT :
 *   RETURN : none
 ****************************************************/
void dev_lcd_exit(void)
{
	if (spi_fd >= 0) {
		close(spi_fd);
		spi_fd = -1;
	}
}

/****************************************************
 * NAME : void dev_lcd_ctrl(void)
 *
 * Desc   : lcd Hadrdware Controls
 *
 * INPUT  :
 *   PARAMETERS: none
 *          int cmd  : command for lcd control.
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values:  0  (succeed)
 *               -1  (failure)
 ****************************************************/
int dev_lcd_ctrl(int cmd)
{
	int ret;
	struct regval_list *regs;

	if (spi_fd < 0)
		return -1;

	if (cmd == LCD_DISP_OFF)
		regs = (struct regval_list *)lcd_disp_off;
	else if(cmd == LCD_DISP_ON)
		regs = (struct regval_list *)lcd_disp_on;
	else
		return -1;

	while (regs->type != LCD_END)
	{
		if(regs->type == LCD_DLY) {
			usleep(regs->val*1000);		//# msec
			regs++;
			continue;
		}

		ret = lcd_write(regs->type, regs->val);
		if(ret < 0)
			printf("write fail 0x%x, 0x%x\n", regs->type, regs->val);

		regs++;
	}

	return 0;
}

/****************************************************
 * NAME : int dev_lcd_set_bright(int brightness)
 *
 * Desc   : controls lcd brightness
 *
 * INPUT  :
 *   PARAMETERS: none
 *          int brightness  : lcd brightness
 *
 * OUTPUT :
 *   RETURN : Error Code
 *       Type  : int
 *       Values:  0  (succeed)
 *               -1  (failure)
 ****************************************************/
int dev_lcd_set_bright(int brightness)
{
	int fd, length;
	char buffer[256] = {};

	if (brightness <= 0)
		brightness = 0;
	else if (brightness > 100)
		brightness = 100;

//	memset(buffer, 0, 256);
	length = snprintf(buffer, sizeof(buffer), "%d", brightness);
	if (length <= 0)
		return -1;

	if ((fd = open(LCD_SYSFS_PATH, O_WRONLY)) < 0) {
		dev_err("Error open %s\n", LCD_SYSFS_PATH);
		return -1;
	}

	write(fd, buffer, length);
	close(fd);

	return 0;
}
