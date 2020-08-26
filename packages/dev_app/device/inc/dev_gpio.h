/*
 * dev_gpio.h
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
 */
#ifndef __DEV_GPIO_H__
#define __DEV_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define GPIO_BASE_PATH 			"/sys/class/gpio"
#define GPIO_PATH_MAX			64

/* set gpio direction */
#define GPIO_INPUT				0
#define GPIO_OUTPUT				1

#define GPIO_ACTIVE_HIGH		0
#define GPIO_ACTIVE_LOW			1

#define GPIO_OUTPUT_HIGH		1
#define GPIO_OUTPUT_LOW			0

/* set gpio irq mode */
#define GPIO_IRQ_NONE			0
#define GPIO_IRQ_RISING			1
#define GPIO_IRQ_FALLING		2
#define GPIO_IRQ_BOTH			3

int gpio_init(int n_gpio, int dir, int irq_type, int def_val);
int gpio_free(int n_gpio);
int gpio_set_value(int n_gpio, int value);
int gpio_get_value(int n_gpio, int *value);
int gpio_set_active_low(int n_gpio, int active_low);
int gpio_irq_read(int n_gpio, int *value, int timeout);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __DEV_GPIO_H__ */
