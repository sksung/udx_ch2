#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/sksung/work/udx/ch2/ti_tools/bios_6_33_05_46/packages;/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages;/home/sksung/work/udx/ch2/ti_tools/ipc_1_24_03_32/packages;/home/sksung/work/udx/ch2/ti_tools/hdvpss_01_00_01_37/packages;/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages;/home/sksung/work/udx/ch2/packages/mcfw_sdk;/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages;/home/sksung/work/udx/ch2/ti_tools/xdais_7_22_00_03/packages;/home/sksung/work/udx/ch2/ti_tools/edma3_lld_02_11_02_04/packages
override XDCROOT = /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/sksung/work/udx/ch2/ti_tools/bios_6_33_05_46/packages;/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages;/home/sksung/work/udx/ch2/ti_tools/ipc_1_24_03_32/packages;/home/sksung/work/udx/ch2/ti_tools/hdvpss_01_00_01_37/packages;/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages;/home/sksung/work/udx/ch2/packages/mcfw_sdk;/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages;/home/sksung/work/udx/ch2/ti_tools/xdais_7_22_00_03/packages;/home/sksung/work/udx/ch2/ti_tools/edma3_lld_02_11_02_04/packages;/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages;..
HOSTOS = Linux
endif
