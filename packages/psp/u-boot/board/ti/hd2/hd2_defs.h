#ifndef _HD2_DEFS_H_
#define _HD2_DEFS_H_

#include <asm/arch/cpu.h>
#include <asm/arch/common_ud_defs.h>

/* defines gpio map */
#define B_REV_P1					GPIO_N(0, 1)
#define B_REV_P2					GPIO_N(0, 2)
#define B_REV_P3					GPIO_N(0, 3)
#define B_REV_P4					GPIO_N(0, 4)
#define USB0_EN						GPIO_N(0, 7)

#define SD_CD						GPIO_N(1, 6)
#define PHY_RESET					GPIO_N(1, 14)
#define NAND_WP						GPIO_N(1, 25)

//# only for applicable NewHD2 Board
#define MCU_BSL_RTS					GPIO_N(2, 21)
#define MICOM_HOLD					GPIO_N(2, 26)
#define VIN0B_PWR_EN				GPIO_N(2, 29)
#define TVOUT_DET					GPIO_N(2, 30)
#define VIN0A_LED					GPIO_N(2, 31)

#define VIN0B_PDN					GPIO_N(3, 0)
#define STATUS_LED_1				GPIO_N(3, 1)
#define STATUS_LED_2				GPIO_N(3, 2)
#define STATUS_LED_3				GPIO_N(3, 3)
#define VIN0B_LOCKN					GPIO_N(3, 4)
#define VIN0A_PDN					GPIO_N(3, 8)
#define MICOM_GPIO_1				GPIO_N(3, 9)
#define MCU_BSL_DTR					GPIO_N(3, 10)
#define VIN0B_LED					GPIO_N(3, 11)
#define G_SENOR_IRQ					GPIO_N(3, 12)
#define MICOM_GPIO_2				GPIO_N(3, 13)
#define VIN0B_CPU_LED				GPIO_N(3, 14)
#define VIN0A_PWR_EN				GPIO_N(3, 16)
#define VIN0A_CPU_LED				GPIO_N(3, 17)
#define VIN0A_LOCKN					GPIO_N(3, 18)
#define ETH_IRQ						GPIO_N(3, 19)
#define GPS_EN						GPIO_N(3, 21)

#endif /* _HD2_DEFS_H_*/
