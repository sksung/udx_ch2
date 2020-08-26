/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 */
#include <common.h>
#include <malloc.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/common_ud_defs.h>
#include <asm/gpio.h>
#include <i2c.h>
#include <bbx_pmic.h>

#if defined(CONFIG_UCX)
#define RTC_NVRAM_ADDR		0x07 /* ALARM 1 Register */
#define POWER_SW_IN			GPIO_N(3, 10) /* power switch */
#define POWER_HOLD			GPIO_N(3, 11) /* active high */
#define ACC_DET				GPIO_N(3, 31)
#define ACC_P_DET			GPIO_N(3, 9)
#define STATUS_LED_1		GPIO_N(3, 0) /* act_low */
#define STATUS_LED_2		GPIO_N(3, 1) /* act_low */
#define STATUS_LED_3		GPIO_N(3, 2) /* act_low */
#define STATUS_LED_4		GPIO_N(3, 3) /* act_low */
#define STATUS_LED_5		GPIO_N(3, 4) /* act_low */

#elif defined(CONFIG_TB8700)
#define RTC_NVRAM_ADDR		0x0A /* ALARM 1 Register */
#define POWER_SW_IN			GPIO_N(3, 10) /* power switch (active low 2s -input) */
#define POWER_HOLD			GPIO_N(3, 11) /* power hold (active high - output) */
#define ACC_DET				GPIO_N(3, 31) /* acc detect (active low - input) */
#define ACC_P_DET			GPIO_N(3, 9)  /* acc pulse (active low 2s -input) */
#define STATUS_LED_1		GPIO_N(3, 0) /* act_low */
#define STATUS_LED_2		GPIO_N(3, 1) /* act_low */
#define STATUS_LED_3		GPIO_N(3, 2) /* act_low */
#define STATUS_LED_4		GPIO_N(3, 3) /* act_low */
#define STATUS_LED_5		GPIO_N(3, 4) /* act_low */
#else
#errror "couldn't defined arch configuration"
#endif

/* Power off by powerkey? */
static int pmic_get_shutdown_status(void)
{
	int ret = 0;

	ret = i2c_reg_read(CONFIG_SYS_I2C_RTC_ADDR, RTC_NVRAM_ADDR);
	if (ret)
		return 1;

	return 0;
}

void pmic_reset_shutdown_status(void)
{
	i2c_reg_write(CONFIG_SYS_I2C_RTC_ADDR, RTC_NVRAM_ADDR, 0x00);
}

void pmic_set_shutdown_status(void)
{
	i2c_reg_write(CONFIG_SYS_I2C_RTC_ADDR, RTC_NVRAM_ADDR, 0x55);
}

static int pmic_get_acc_pulse_status(struct pmic *pm)
{
	return !gpio_get_value(pm->gpio_acc_p); /* active_low */
}

static int pmic_get_acc_status(struct pmic *pm)
{
	return !gpio_get_value(pm->gpio_acc); /* active_low */
}

static int pmic_get_switch_status(struct pmic *pm)
{
	return !gpio_get_value(pm->gpio_sw);
}

static void pmic_set_output(struct pmic *pm, int enable)
{
	gpio_set_value(pm->gpio_hold, (enable ? 1:0));
}

struct pmic *pmic_init(void)
{
	struct pmic *pm;

	pm = (struct power *)malloc(sizeof(*pm));
	if (pm == NULL) {
		return NULL;
	}

	memset(pm, 0, sizeof(*pm));

	pm->gpio_hold = POWER_HOLD;
	pm->gpio_acc = ACC_DET;
	pm->gpio_acc_p = ACC_P_DET;
	pm->gpio_sw = POWER_SW_IN;

	pm->count = 0;
	pm->state = STATE_INIT;

	return pm;
}

void pmic_free(struct pmic *pm)
{
	if (pm)
		free(pm);
}

int do_pmic(struct pmic *pm)
{
	int status = 0, ret;
	u32 time_start = 0;

	ret = PMIC_OFF;

	switch (pm->state) {
	case STATE_DONE:
		/* gpio HOLD to high */
		pmic_set_output(pm, PMIC_ON);
		/* clear flag in RTC */
		pmic_reset_shutdown_status();

		ret = PMIC_ON;
		break;
	case STATE_ACC_ON:
		status = pmic_get_acc_status(pm);
		if (!status) {
			/* return to poll state: unstable input */
			pm->state = STATE_POLL;
			return ret;
		}

		time_start = get_timer(0);
		/* wait 600ms */
		while (get_timer(time_start) < WAIT_FOR_ACC)
		;

		/* is acc on?? */
		status = pmic_get_acc_status(pm);
		__led_set(STATUS_LED_4,
				 (status ? STATUS_LED_ON : STATUS_LED_OFF));
		if (status) {
			pm->state = STATE_DONE;
		} else {
			/* return to poll state: unstable input */
			pm->state = STATE_POLL;
		}
		break;
	case STATE_KEY_ON:
		/* is power key pressed?? */
		status = pmic_get_switch_status(pm);
		if (!status) {
			/* return to poll state: unstable input */
			pm->state = STATE_POLL;
			return ret;
		}

		time_start = get_timer(0);
		/* wait 400ms */
		while (get_timer(time_start) < WAIT_FOR_KEY)
		;

		/* is power key pressed?? */
		status = pmic_get_switch_status(pm);
		__led_set(STATUS_LED_5,
				 (status ? STATUS_LED_ON : STATUS_LED_OFF));
		if (status) {
			pm->state = STATE_DONE;
		} else {
			/* return to poll state: unstable input */
			pm->state = STATE_POLL;
		}
		break;
	case STATE_POLL:
		/* priority : ACC_P -> POWER_KEY */
		if (pmic_get_switch_status(pm)) {
			/* is power key pressed?? */
			pm->state = STATE_KEY_ON;
			__led_set(STATUS_LED_2, STATUS_LED_OFF);
		}

		if (pmic_get_acc_pulse_status(pm)) {
			/* is detected acc_pulse */
			pm->state = STATE_ACC_ON;
			__led_set(STATUS_LED_2, STATUS_LED_ON);
		}

		break;
	case STATE_INIT:
	default:
		status = pmic_get_shutdown_status();
		__led_set(STATUS_LED_1,
				 (status ? STATUS_LED_ON : STATUS_LED_OFF));
		if (status)
			pm->state = STATE_POLL;
		else {
			/* reset or reboot pmic status
		 	 * Turn On the power
		 	 */
			pm->state = STATE_DONE;
		}
		break;
	}

	return ret;
}
