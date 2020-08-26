#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/sksung/work/udx/ch2/packages/../ti_tools/ipc_1_24_03_32/packages;/home/sksung/work/udx/ch2/packages/../ti_tools/bios_6_33_05_46/packages;/home/sksung/work/udx/ch2/packages/../ti_tools/syslink_2_10_06_28/packages
override XDCROOT = /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53
override XDCBUILDCFG = /home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/_config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = DEVICE=TI814X CGT_C674_ELF_DIR=/home/sksung/work/udx/ch2/packages/../ti_tools/cgt6x_7_3_5 CGT_M3_ELF_DIR=/home/sksung/work/udx/ch2/packages/../ti_tools/cgt470_4_9_5 CGT_A8_ELF_DIR= DEVICE_VARIANT=TI814X
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/sksung/work/udx/ch2/packages/../ti_tools/ipc_1_24_03_32/packages;/home/sksung/work/udx/ch2/packages/../ti_tools/bios_6_33_05_46/packages;/home/sksung/work/udx/ch2/packages/../ti_tools/syslink_2_10_06_28/packages;/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages;../../../..
HOSTOS = Linux
endif
