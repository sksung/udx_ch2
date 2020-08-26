CONFIG_OMAP_HSMMC=y
CONFIG_USE_ARCH_MEMSET=y
CONFIG_CMD_FAT=y
CONFIG_BOOTM_NETBSD=y
CONFIG_HARD_I2C=y
CONFIG_SYS_CLK_FREQ=20000000
CONFIG_CMD_ITEST=y
CONFIG_CMD_EDITENV=y
CONFIG_SYS_MAX_NAND_DEVICE=y
CONFIG_SYS_GBL_DATA_SIZE=128
CONFIG_SYS_LOAD_ADDR="0x81000000"
CONFIG_CMD_CACHE=y
CONFIG_BOOTDELAY=0
CONFIG_SYS_NAND_BASE="NAND_BASE"
CONFIG_NAND_UPDATE=y
CONFIG_SYS_HELP_CMD_WIDTH=8
CONFIG_NR_DRAM_BANKS=y
CONFIG_FS_FAT=y
CONFIG_BOOTM_RTEMS=y
CONFIG_SYS_CBSIZE=512
CONFIG_SKIP_LOWLEVEL_INIT=y
CONFIG_SYS_MONITOR_LEN="(256 << 10)"
CONFIG_ENV_RANGE="0x20000 * 3"
CONFIG_BOOTM_LINUX=y
CONFIG_BOOTP_SEND_HOSTNAME=y
CONFIG_CMD_CONSOLE=y
CONFIG_MII=y
CONFIG_GATEWAYIP="192.168.1.1"
CONFIG_SYS_CACHELINE_SIZE=64
CONFIG_MMC=y
CONFIG_CMD_MISC=y
CONFIG_ZERO_BOOTDELAY_CHECK=y
CONFIG_TI814X_LOGO=y
CONFIG_ENV_OFFSET="boot_flash_off"
CONFIG_RELOC_FIXUP_WORKS=y
CONFIG_ENV_OVERWRITE=y
CONFIG_CMD_NET=y
CONFIG_CMD_NFS=y
CONFIG_ENV_SIZE="0x20000"
CONFIG_CMD_PING=y
CONFIG_SYS_MALLOC_LEN="(CONFIG_ENV_SIZE + (32 * 1024))"
CONFIG_INITRD_TAG=y
CONFIG_SYS_I2C_SPEED=400000
CONFIG_CMD_SAVEENV=y
CONFIG_TIMEOFFSET=32400
CONFIG_SYS_NS16550_SERIAL=y
CONFIG_I2C_MULTI_BUS=y
CONFIG_SYS_CONSOLE_INFO_QUIET=y
CONFIG_CMD_NAND=y
CONFIG_ENV_ADDR="MNAND_ENV_OFFSET"
CONFIG_SYS_NAND_PREFETCH=y
CONFIG_BOOTARGS="mem=180M console=ttyO0,115200n8 noinitrd rw ubi.mtd=5,2048 rootfstype=ubifs root=ubi0:rootfs ip=off vram=3M notifyk.vpssm3_sva=0xBFD00000 eth=${ethaddr} mcu=${udxii}"
CONFIG_MCU_UPDATE=y
CONFIG_BOOTP_DNS=y
CONFIG_CMD_MEMORY=y
CONFIG_SYS_MAXARGS=32
CONFIG_CMD_RUN=y
CONFIG_SYS_I2C_RTC_ADDR="0x6F"
CONFIG_IPADDR="192.168.1.200"
CONFIG_SYS_PBSIZE="(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)"
CONFIG_BOARDDIR="board/ti/hd2"
CONFIG_TI_DUMMY_HEADER=y
CONFIG_DRIVER_TI81XX_I2C=y
CONFIG_BOOTCOMMAND="run showlogo; if test ${nand_update} -eq 1; then if mmc rescan; then if run loadbootscript; then run bootscript; fi; fi; else nboot.e 0x81000000 0 0x00220000;bootm 0x81000000; fi"
CONFIG_TIMESTAMP=y
CONFIG_CMD_SETGETDCR=y
CONFIG_SYS_NAND_WAIT_MONITOR=y
CONFIG_NET_RETRY_COUNT=10
CONFIG_TI814X=y
CONFIG_ZLIB=y
CONFIG_BOOTP_DNS2=y
CONFIG_CMD_BOOTD=y
CONFIG_SYS_NAND_ADDR="NAND_BASE"
CONFIG_NET_MULTI=y
CONFIG_SYS_NS16550=y
CONFIG_SYS_BARGSIZE="CONFIG_SYS_CBSIZE"
CONFIG_SYS_RX_ETH_BUFFER=16
CONFIG_I2C_REPEATED_START=y
CONFIG_SYS_HZ=1000
CONFIG_SYS_NS16550_CLK="(48000000)"
CONFIG_DOS_PARTITION=y
CONFIG_NAND_ENV=y
CONFIG_CMD_FPGA=y
CONFIG_RTC=y
CONFIG_SYS_BAUDRATE_TABLE="{ 110, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 56000, 57600, 115200 }"
CONFIG_SYS_NS16550_COM1="0x48020000"
CONFIG_SYS_NS16550_COM3="0x48024000"
CONFIG_SYS_HUSH_PARSER=y
CONFIG_USE_ARCH_IO=y
CONFIG_DM385_DDR3_400=y
CONFIG_DRIVER_TI_CPSW=y
CONFIG_TI81XX=y
CONFIG_CMD_DHCP=y
CONFIG_ENV_IS_IN_NAND=y
CONFIG_DM385=y
CONFIG_SYS_PROMPT_HUSH_PS2="> "
CONFIG_CMD_ECHO=y
CONFIG_GENERIC_MMC=y
CONFIG_SYS_TIMERBASE="0x4802E000"
CONFIG_USE_ARCH_MEMCPY=y
CONFIG_BOOTP_GATEWAY=y
CONFIG_SYS_MONITOR_BASE="CONFIG_SYS_FLASH_BASE"
CONFIG_BOOTP_DEFAULT=y
CONFIG_EXTRA_ENV_SETTINGS="script_addr=0x80900000\0loadbootscript=fatload mmc 0 ${script_addr} boot.scr\0bootscript= echo Running bootscript from MMC/SD to set the ENV...; source ${script_addr}\0showlogo=nand read 0x82100000 0x00120000 0xBB800;logo on 0x82000000;\0"
CONFIG_SYS_I2C_BUS_SELECT=y
CONFIG_CMD_SNTP=y
CONFIG_SYS_ENV_SECT_SIZE="boot_flash_sec"
CONFIG_RTC_MCP7940=y
CONFIG_BAUDRATE=115200
CONFIG_NETMASK="255.255.255.0"
CONFIG_NTPSERVERIP="192.168.1.231"
CONFIG_CMDLINE_TAG=y
CONFIG_PARTITIONS=y
CONFIG_HD2=y
CONFIG_OMAP_GPIO=y
CONFIG_SERIAL_MULTI=y
CONFIG_SYS_NS16550_REG_SIZE="(-4)"
CONFIG_SYS_MEMTEST_END="(CONFIG_SYS_MEMTEST_START + (8 * 1024 * 1024))"
CONFIG_CMD_I2C=y
CONFIG_GPIO_LED=y
CONFIG_CMD_DATE=y
CONFIG_SYS_NO_FLASH=y
CONFIG_NAND=y
CONFIG_SYS_DEF_EEPROM_ADDR=0
CONFIG_SYS_FLASH_BASE="boot_flash_base"
CONFIG_SYS_I2C_SLAVE=y
CONFIG_SYS_MAX_FLASH_BANKS=2
CONFIG_CMD_SOURCE=y
CONFIG_SYS_PROMPT="UBOOT # "
CONFIG_SETUP_MEMORY_TAGS=y
CONFIG_SERIAL1=y
CONFIG_SYS_MEMTEST_START="(PHYS_DRAM_1 + (64 *1024 *1024))"
CONFIG_CMD_LOADB=y
CONFIG_CMD_LOADS=y
CONFIG_NAND_TI81XX=y
CONFIG_SILENT_CONSOLE=y
CONFIG_CMD_IMI=y
CONFIG_SYS_I2C_BUS=0
CONFIG_CONS_INDEX=y
CONFIG_ARM=y
CONFIG_SYS_MAX_FLASH_SECT=520
CONFIG_CMD_BDI=y
CONFIG_SERVERIP="192.168.1.100"
CONFIG_BOOTP_SUBNETMASK=y
CONFIG_I2C=y
CONFIG_CMD_MMC=y
CONFIG_I2C_ADC_BUS=y