/*
 * File : dev_gpio.c
 *
 * Copyright (C) 2014 UDWORKs
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
 * this implements a GPIO hardware library.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

#include <dev_common.h>
#include <dev_gpio.h>

#define MAX_GPIO		128 //# GP[0] ~ GP[3]
#define SZ_BUF			64

static int gpio_fd[MAX_GPIO] = {-1,};

/*
 * note: file descriptor 0(stdin), 1(stdout), 2(stderr)
 * so we assumed zero fd -> invalid fd
 */
/*************************************************************
 * NAME : int gpio_init(int n_gpio, int dir, int irq_type, int def_val)
 ************************************************************/
int gpio_init(int n_gpio, int dir, int irq_type, int def_val)
{
	char path[GPIO_PATH_MAX + 1];
	char buf[32 + 1] = {};

	int fd, len;

	if (n_gpio >= MAX_GPIO)
		return -1;

	gpio_fd[n_gpio] = -1;
	/* export gpio */
	fd = open(GPIO_BASE_PATH "/export", O_WRONLY);
	if (fd < 0) {
		dev_err("couldn't open %s\n", path);
		return fd;
	}

	len = snprintf(path, sizeof(path), "%d", n_gpio);
	write(fd, path, len);
	close(fd);

	memset(path, 0, sizeof(path));
	snprintf(path, sizeof(path), GPIO_BASE_PATH  "/gpio%d/direction", n_gpio);
	fd = open(path, O_WRONLY);
	if (fd < 0) {
		dev_err("couldn't open %s\n", path);
		return fd;
	}

	/* direction output */
	if (dir) {
		if (def_val) {
			snprintf(buf, sizeof(buf), "high");
		} else {
			snprintf(buf, sizeof(buf), "low");
		}
	} else {
		snprintf(buf, sizeof(buf), "in");
	}

	write(fd, buf, strlen(buf));
	close(fd);

	/* open irq flag */
	if (irq_type != GPIO_IRQ_NONE)
	{
		snprintf(path, sizeof(path), GPIO_BASE_PATH "/gpio%d/edge", n_gpio);
		fd = open(path, O_WRONLY);
		if (fd < 0) {
			dev_err("couldn't open %s\n", path);
			return fd;
		}

		memset(buf, 0, sizeof(buf));
		if (irq_type == GPIO_IRQ_RISING)
			strcpy(buf, "rising");
		else if (irq_type == GPIO_IRQ_FALLING)
			strcpy(buf, "falling");
		else if (irq_type == GPIO_IRQ_BOTH)
			strcpy(buf, "both");
		else
			strcpy(buf, "none");

		write(fd, buf, strlen(buf) + 1); //# add '\0'
		close(fd);
	}

	/* open gpio value (default : O_WRONLY, output value) */
	memset(path, 0, sizeof(path));
	snprintf(path, sizeof(path), GPIO_BASE_PATH "/gpio%d/value", n_gpio);
	fd = open(path, O_RDWR); /* For rw: (r)O_RDONLY, (w)O_WRONLY */
	if (fd < 0) {
		dev_err("couldn't open %s (ret = %d)\n", path, fd);
		return fd;
	}
	gpio_fd[n_gpio] = fd;

	/* dummy read : flush gpio */
	read(fd, buf, sizeof(buf) - 1);
	lseek(fd, 0, SEEK_SET);

	return 0;
}

/*************************************************************
 * NAME : int gpio_free(int n_gpio)
 ************************************************************/
int gpio_free(int n_gpio)
{
	char path[GPIO_PATH_MAX + 1];
	int fd, len;

	if (gpio_fd[n_gpio] >= 0)
		close(gpio_fd[n_gpio]);
#if 0
	/* set directio input */
	len = snprintf(path, sizeof(path), GPIO_BASE_PATH  "/gpio%d/direction", n_gpio);
	fd = open(path, O_WRONLY);
	if (fd < 0) {
		dev_err("couldn't open %s\n", path);
		return fd;
	}

	write(fd, "in", 3); //# add '\0'
	close(fd);
#endif

	/* unexport gpio */
	fd = open(GPIO_BASE_PATH "/unexport", O_WRONLY);
	if (fd < 0) {
		dev_err("couldn't open %s\n", path);
		return fd;
	}

	len = snprintf(path, sizeof(path), "%d", n_gpio);
	write(fd, path, len);
	close(fd);

	return 0;
}

/*************************************************************
 * NAME : int gpio_set_value(int n_gpio, int value)
 ************************************************************/
int gpio_set_value(int n_gpio, int value)
{
	int fd = -1;

	if (n_gpio >= MAX_GPIO || gpio_fd[n_gpio] < 0)
		return -1;

	fd = gpio_fd[n_gpio];
	lseek(fd, 0, SEEK_SET);
	if (value)
		write(fd, "1", 2); //# add '\0'
	else
		write(fd, "0", 2); //# add '\0'

	return 0;
}

/*************************************************************
 * NAME : int gpio_get_value(int n_gpio, int *value)
 ************************************************************/
int gpio_get_value(int n_gpio, int *value)
{
	char buffer[SZ_BUF + 1] = {};
	int res;

	int fd = -1;

	if (n_gpio >= MAX_GPIO || gpio_fd[n_gpio] < 0)
		return -1;

	fd = gpio_fd[n_gpio];
	lseek(fd, 0, SEEK_SET);
	res = read(fd, buffer, SZ_BUF);
	if (res == -1) {
		dev_err("Failed to read gpio[%d]\n", n_gpio);
		return -1; //# Failed to reading
	}

	/*
	 * return value: gpio + '\n' = 2byte
	 */
	*value = strtol(buffer, NULL, 10); //# atoi

	return 0;
}


/*************************************************************
 * NAME : int gpio_set_active_low(int n_gpio, int active_low)
 ************************************************************/
int gpio_set_active_low(int n_gpio, int active_low)
{
	char path[GPIO_PATH_MAX + 1];
	int fd = -1;

	snprintf(path, sizeof(path), GPIO_BASE_PATH  "/gpio%d/active_low", n_gpio);
	fd = open(path, O_WRONLY);
	if (fd < 0) {
		dev_err("couldn't open %s\n", path);
		return fd;
	}

	if (active_low)
		write(fd, "1", 2);

	close(fd);

	return 0;
}

/*************************************************************
 * NAME : int gpio_irq_read(int n_gpio, int *value, int timeout)
 ************************************************************/
int gpio_irq_read(int n_gpio, int *value, int timeout)
{
	char buffer[SZ_BUF + 1];
	struct pollfd fdset;

	int res, fd;
	int exit = 0;

	if (n_gpio >= MAX_GPIO || gpio_fd[n_gpio] < 0)
		return -1;

	fd = gpio_fd[n_gpio];

	while (!exit) {
		/* clear event */
		memset((void*)&fdset, 0, sizeof(fdset));

		fdset.fd     = fd;
		fdset.events = POLLPRI;

		res = poll(&fdset, 1, timeout);
		if (res < 0) {
			dev_err("[GPIO] generated poll error!..exit\n");
			return -1;
		}
		if (res == 0)
			/* timeout */
			return -1;

		/* check return event */
		if (fdset.revents & POLLPRI) {
			/* wait for 1 event */
			lseek(fd, 0, SEEK_SET);
			res = read(fd, buffer, SZ_BUF);
			if (res <= 0)
				return -1; //# Failed to reading
			/*
			 * return value: gpio + '\n' = 2byte
			 */
			*value = strtol(buffer, NULL, 10); //# atoi
			return 0;
		}
	}

	return (-1);
}
