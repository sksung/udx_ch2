# Copyright (c) Texas Instruments Inc 2012
DIR=default
FILE=default
CPU_NUM=16

include Rules.make
include $(ROOTDIR)/makerules/build_config.mk
include $(ROOTDIR)/makerules/env.mk
include $(ROOTDIR)/makerules/platform.mk
include $(ROOTDIR)/component.mk

##### McFW BUILD #####

mcfw: m3 cmem ubxapp_all scrip fsupdate

mcfw_clean: m3_clean ubxapp_clean
ifeq ($(APP_BUILD_CFG), release)
	rm -rf $(MCFW_ROOT_PATH)/mcfw/src_bios6/main_app/*.asm
endif

mcfw_all: mcfw_clean mcfw

##### APP BUILD #####
app:
	make -j$(CPU_NUM) -fMAKEFILE.MK -C$(MCFW_ROOT_PATH)/mcfw/src_linux
	make -j$(CPU_NUM) -fMAKEFILE.MK -C$(APP_DIR)
	@echo -e "\n--- make app done! (`date +'%H:%M:%S'`)---\n"

app_clean:
	make -fMAKEFILE.MK -C$(MCFW_ROOT_PATH)/mcfw/src_linux clean
	make -fMAKEFILE.MK -C$(APP_DIR) clean
rfs_unzip:
	sudo tar zxvf $(TARGET_ROOT)/rfs.tar.gz -C $(TARGET_ROOT)/
rfs_clean:
	sudo rm -rf $(TARGET_ROOT)/rfs
	rm -rf $(TARGET_FS)/opt/*

ubxapp: app fsupdate
bigfile_unzip:
ifneq (exist, $(shell [ -e $(linuxdevkit_PATH)/usr/lib/libc.a ] && echo exist))
	echo "extracting libc.tar.gz..."
	tar zxvf $(linuxdevkit_PATH)/usr/lib/libc.tar.gz -C $(linuxdevkit_PATH)/usr/lib/
endif

ubxapp_clean: app_clean
ubxapp_all: app_clean iwscan_clean db_img iwscan ubxapp

scan_app:
	make -fMAKEFILE.MK -C$(IWSCAN_DIR)

scan_clean:
	make -fMAKEFILE.MK -C$(IWSCAN_DIR) clean

iwscan: scan_app

iwscan_clean: scan_clean
iwscan_all: iwscan_clean iwscan

cgi:
	make -fMAKEFILE.MK -C$(APP_DIR)/$(BRANCH_DIR)_app/cgi_src
#	rm -rf $(APP_DIR)/ubx_bus/cgi/*.cgi

cgi_clean:
	make -fMAKEFILE.MK -C$(APP_DIR)/$(BRANCH_DIR)_app/cgi_src clean
#	rm -rf $(APP_DIR)/ubx_bus/cgi/*.cgi

cgi_all: cgi_clean cgi

appgui:
	make -j$(CPU_NUM) -fMAKEFILE.MK -C$(APP_DIR)/ubx_gui
	@echo "\n# --- make ubxapp done! (`date +'%H:%M:%S'`)---\n"

appgui_clean:
	make -fMAKEFILE.MK -C$(APP_DIR)/ubx_gui clean

ubxgui: appgui fsupdate

ubxgui_clean: appgui_clean
ubxgui_all: appgui_clean ubxgui

live555:
	make -fMakefile -C $(LIVE555_DIR)/BasicUsageEnvironment
	make -fMakefile -C $(LIVE555_DIR)/UsageEnvironment
	make -fMakefile -C $(LIVE555_DIR)/groupsock
	make -fMakefile -C $(LIVE555_DIR)/liveMedia
	make -fMakefile -C $(LIVE555_DIR)/netra_streamer/netra_interface
	make -fMakefile -C $(LIVE555_DIR)/netra_streamer

live555_clean:
	make -fMakefile -C $(LIVE555_DIR)/BasicUsageEnvironment clean
	make -fMakefile -C $(LIVE555_DIR)/liveMedia clean
	make -fMakefile -C $(LIVE555_DIR)/UsageEnvironment clean
	make -fMakefile -C $(LIVE555_DIR)/groupsock clean
	make -fMakefile -C $(LIVE555_DIR)/netra_streamer/netra_interface clean
	make -fMakefile -C $(LIVE555_DIR)/netra_streamer clean

live555_all: live555_clean live555

#### M3 BUILD #####

m3vpss:
	$(MAKE) -fMAKEFILE.MK -C $(MCFW_ROOT_PATH)/mcfw/src_bios6 $@
	$(STRIP470) $(TARGET_MCFW_DIR)/firmware/sdk_fw_m3vpss.xem3
	@echo -e "\n--- make m3vpss done! (`date +'%H:%M:%S'`)---\n"

m3video:
	$(MAKE) -j$(CPU_NUM) -fMAKEFILE.MK -C $(MCFW_ROOT_PATH)/mcfw/src_bios6 $@
	$(STRIP470) $(TARGET_MCFW_DIR)/firmware/sdk_fw_m3video.xem3
	@echo -e "\n--- make m3video done! (`date +'%H:%M:%S'`)---\n"

m3vpss_clean:
	$(MAKE) -fMAKEFILE.MK -C $(MCFW_ROOT_PATH)/mcfw/src_bios6 $@

m3video_clean:
	$(MAKE) -fMAKEFILE.MK -C $(MCFW_ROOT_PATH)/mcfw/src_bios6 $@

m3: m3vpss m3video
m3_clean: m3vpss_clean m3video_clean
m3_all: m3_clean m3

##### XDC BUILD #####

XDC_BUILD_PKG_LIST  = $(fc_PATH)/packages/ti.sdo.fc.ires.hdvicp
#XDC_BUILD_PKG_LIST += $(fc_PATH)/packages/ti.sdo.fc.memutils

xdcpkgs:
	$(xdc_PATH)/xdc XDCBUILDCFG=$(CONFIG_BLD_XDC_$(ISA)) -PD $(subst .,/,$(XDC_BUILD_PKG_LIST))

xdcpkgs_clean:
	$(xdc_PATH)/xdc XDCBUILDCFG=$(CONFIG_BLD_XDC_$(ISA)) clean -PD $(subst .,/,$(XDC_BUILD_PKG_LIST))

##### ISS BUILD #####

iss:
	$(MAKE) -j$(CPU_NUM) -C $(iss_PATH)/packages/ti/psp/iss $(TARGET) CORE=m3vpss
	@echo -e "\n--- make iss done! (`date +'%H:%M:%S'`)---\n"

iss_clean:
	$(MAKE) iss TARGET=clean

iss_all: iss_clean iss

##### HDVPSS BUILD #####

hdvpss:
	$(MAKE) -j$(CPU_NUM) -C $(hdvpss_PATH)/packages/ti/psp/vps $(TARGET) CORE=m3vpss
	$(MAKE) -j$(CPU_NUM) -C $(hdvpss_PATH)/packages/ti/psp/i2c $(TARGET) CORE=m3vpss
	$(MAKE) -j$(CPU_NUM) -C $(hdvpss_PATH)/packages/ti/psp/devices $(TARGET) CORE=m3vpss
	$(MAKE) -j$(CPU_NUM) -C $(hdvpss_PATH)/packages/ti/psp/platforms $(TARGET) CORE=m3vpss
	$(MAKE) -j$(CPU_NUM) -C $(hdvpss_PATH)/packages/ti/psp/proxyServer $(TARGET) CORE=m3vpss
	@echo -e "\n--- make hdvpss done! (`date +'%H:%M:%S'`)---\n"

hdvpss_clean:
	$(MAKE) hdvpss TARGET=clean

hdvpss_all: hdvpss_clean hdvpss

##### U-BOOT BUILD #####

ubootbuild:
	$(MAKE) -j$(CPU_NUM) -C$(UBOOTDIR) ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) $(MAKE_TARGET)

ubootminsd:
	$(MAKE) uboot_clean
	$(MAKE) ubootbuild MAKE_TARGET=$(SYSTEM_CFG)_min_sd
	$(MAKE) ubootbuild MAKE_TARGET=u-boot.ti
	mv $(UBOOTDIR)/u-boot.min.sd $(TFTP_HOME)/MLO

ubootminnand:
	$(MAKE) uboot_clean
	$(MAKE) ubootbuild MAKE_TARGET=$(SYSTEM_CFG)_min_nand
	$(MAKE) ubootbuild MAKE_TARGET=u-boot.ti
	mv $(UBOOTDIR)/u-boot.min.nand $(TFTP_HOME)/u-boot_$(SYSTEM_CFG).min.nand

ubootbin:
	$(MAKE) uboot_clean
	$(MAKE) ubootbuild MAKE_TARGET=$(SYSTEM_CFG)_config_nand
	$(MAKE) ubootbuild MAKE_TARGET=u-boot.ti
	mv $(UBOOTDIR)/u-boot.bin $(TFTP_HOME)/u-boot_$(SYSTEM_CFG).bin

uboot_clean:
	$(MAKE) ubootbuild MAKE_TARGET=distclean

uboot:
	$(MAKE) ubootminsd
	$(MAKE) ubootminnand
	$(MAKE) ubootbin
	$(MAKE) ubootscr
	@echo -e "\n--- make uboot done! (`date +'%H:%M:%S'`)---\n"

ubootscr:
	mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n 'Execute Boot Script' -d $(UBOOTDIR)/bootscript_$(SYSTEM_CFG).sh $(UBOOTDIR)/boot.scr
	mv $(UBOOTDIR)/boot.scr $(TFTP_HOME)/boot.scr

uboot_all: uboot_clean uboot ubootscr

##### LSP BUILD #####

lspbuild:
	make -j$(CPU_NUM) -C$(KERNELDIR) ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) $(MAKE_TARGET)

lspmenu:
	make lspbuild MAKE_TARGET=menuconfig

lspcfg:
	make lspbuild MAKE_TARGET=$(SYSTEM_CFG)_defconfig

lsp:
	make lspcfg
	make lspbuild MAKE_TARGET=uImage
	make lspbuild MAKE_TARGET=modules
	make lspbuild MAKE_TARGET=headers_install
	mv $(KERNELDIR)/arch/arm/boot/uImage $(TFTP_HOME)/uImage_$(SYSTEM_CFG)
	-mkdir -p $(TARGET_MCFW_DIR)/kermod
	cp $(KERNELDIR)/drivers/video/ti81xx/vpss/vpss.ko $(TARGET_MCFW_DIR)/kermod/.
	cp $(KERNELDIR)/drivers/video/ti81xx/ti81xxfb/ti81xxfb.ko $(TARGET_MCFW_DIR)/kermod/.
	@echo -e "\n--- make lsp done! (`date +'%H:%M:%S'`)---\n"

lsp_clean:
	make lspbuild MAKE_TARGET=distclean
	-rm -f $(TARGET_MCFW_DIR)/kermod/*

lsp_all: lsp_clean lsp

wifi_all: wifi_clean wifi

wifi:
ifeq ($(USE_WIFI),YES)
	make ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) KSRC=$(KERNELDIR) -C$(APP_DIR)/module/wifi/8188eu_driver modules
	make ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) KSRC=$(KERNELDIR) -C$(APP_DIR)/module/wifi/8188cu_driver modules
	make ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) KSRC=$(KERNELDIR) -C$(APP_DIR)/module/wifi/8821au_driver modules
#	make ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) KSRC=$(KERNELDIR) -C$(APP_DIR)/module/wifi/8192eu_driver modules
endif

wifi_clean:
ifeq ($(USE_WIFI), YES)
	-rm -f $(TARGET_FS)/lib/modules/8188eu.ko
	make ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) KSRC=$(KERNELDIR) -C$(APP_DIR)/module/wifi/8188eu_driver clean
	-rm -f $(TARGET_FS)/lib/modules/8192cu.ko
	make ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) KSRC=$(KERNELDIR) -C$(APP_DIR)/module/wifi/8188cu_driver clean
	-rm -f $(TARGET_FS)/lib/modules/8821au.ko
	make ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) KSRC=$(KERNELDIR) -C$(APP_DIR)/module/wifi/8821au_driver clean
#	-rm -f $(TARGET_FS)/lib/modules/8192eu.ko
#	make ARCH=arm CROSS_COMPILE=$(BUILD_TOOL_PREFIX) KSRC=$(KERNELDIR) -C$(APP_DIR)/module/wifi/8192eu_driver clean
endif
##### SYSLINK BUILD #####

SYSLINK_BUILD_OPT = USE_SYSLINK_NOTIFY=0 SYSLINK_PLATFORM=TI81XX SYSLINK_VARIANT=TI814X

syslinkbuild:
	cp $(MCFW_ROOT_PATH)/makerules/syslink_products.mak $(syslink_PATH)/products.mak
	make -j$(CPU_NUM) -C$(syslink_PATH) $(SYSLINK_BUILD_OPT) $(TARGET)

syslink:
	make syslinkbuild DEVICE=TI814X TARGET=syslink
	-mkdir -p $(TARGET_MCFW_DIR)/kermod
	cp $(syslink_OUT_DIR)/syslink.ko $(TARGET_MCFW_DIR)/kermod/.
	@echo -e "\n--- make syslink done! (`date +'%H:%M:%S'`)---\n"

syslink_clean:
	make syslinkbuild DEVICE=TI814X TARGET=clean

syslink_all: syslink_clean syslink

##### CMEM MAKE #####

cmem:
	make -C $(linuxutils_PATH)/packages/ti/sdo/linuxutils/cmem/src/interface \
	LINUXKERNEL_INSTALL_DIR=$(KERNELDIR) MVTOOL_PREFIX=$(BUILD_TOOL_PREFIX)
	make -C $(linuxutils_PATH)/packages/ti/sdo/linuxutils/cmem/src/module \
	LINUXKERNEL_INSTALL_DIR=$(KERNELDIR) MVTOOL_PREFIX=$(BUILD_TOOL_PREFIX)
	cp $(linuxutils_PATH)/packages/ti/sdo/linuxutils/cmem/src/module/cmemk.ko \
	$(TARGET_MCFW_DIR)/kermod/.
	@echo -e "\n--- make cmem done! (`date +'%H:%M:%S'`)---\n"

cmem_clean:
	make -C$(linuxutils_PATH)/packages/ti/sdo/linuxutils/cmem/src/module clean

cmemall: cmem_clean cmem

db_img:
	chmod 755 $(APP_IMG_DIR)/bmp2db.out
	make -fMakefile -C $(APP_IMG_DIR)

db_snd:
	chmod 755 $(APP_SND_DIR)/wav2db.out
	make -fMakefile -C $(APP_SND_DIR)


##### FILESYS MAKE #####

ubifs:
	$(TARGET_ROOT)/mkfs.ubifs -r $(TARGET_FS) -F -o ubifs.img -m 2KiB -e 124KiB -c 330
	$(TARGET_ROOT)/ubinize -o $(TFTP_HOME)/rfs_$(SYSTEM_CFG).ubifs -m 2048 -p 128KiB -s 512 -O 2048 $(TARGET_ROOT)/ubinize.cfg
	rm -rf ubifs.img

scrip:
ifeq ($(APP_BUILD_CFG), release)
	$(STRIP470) $(TARGET_MCFW_DIR)/firmware/sdk_fw_m3video.xem3
	$(STRIP470) $(TARGET_MCFW_DIR)/firmware/sdk_fw_m3vpss.xem3
	chmod 755   $(TARGET_MCFW_DIR)/firmware/*.*
endif

fsupdate:
	-mkdir -p $(EXEC_DIR)
	-mkdir -p $(EXEC_DIR)/bin	
	-mkdir -p $(TFTP_HOME)/release
	chmod -Rf 755 $(TARGET_MCFW_DIR)/
	cp $(APP_DIR)/lib/libfont_db.so $(TARGET_FS)/usr/lib/.
	cp -Rp $(TARGET_MCFW_DIR)/* $(EXEC_DIR)/.
	cp -f $(TARGET_MCFW_DIR)/wis-streamer $(EXEC_DIR)/bin/.
	cp -f $(IWSCAN_DIR)/iw_scan.out $(EXEC_DIR)/bin/.	
	cp -f $(TARGET_MCFW_DIR)/scripts/start_app.sh $(TARGET_FS)/opt/.
	chmod 755 $(EXEC_DIR)/*.sh
	chmod 755 $(EXEC_DIR)/scripts/*.sh
ifeq ($(USE_WIFI),YES)
	cp $(APP_DIR)/module/wifi/8188eu_driver/8188eu.ko $(TARGET_FS)/lib/modules/.
	cp $(APP_DIR)/module/wifi/8188cu_driver/8192cu.ko $(TARGET_FS)/lib/modules/.
	cp $(APP_DIR)/module/wifi/8821au_driver/8821au.ko $(TARGET_FS)/lib/modules/.
#	cp $(APP_DIR)/module/wifi/8192eu_driver/8192eu.ko $(TARGET_FS)/lib/modules/.
endif
	@echo "# -------- Build Completed for $(DVR_RDK_BOARD_TYPE) -- ( `date +'%H:%M:%S'`) -------\n"

##### SYSTEM BUILD #####

sys: uboot lsp wifi syslink iss hdvpss mcfw

sys_clean: uboot_clean lsp_clean wifi_clean syslink_clean iss_clean hdvpss_clean mcfw_clean
	rm -rf $(MCFW_ROOT_PATH)/build
	@echo -e "\n--- make sysclean done! (`date +'%H:%M:%S'`)---\n"

sys_all: sys_clean rfs_unzip bigfile_unzip sys fsupdate
	@echo "--------------------------------------------------------------"
	@echo "******** Build completed for following configuration *********"
	@echo "--------------------------------------------------------------"
	@echo "Hardware Platform  : $(RDK_BOARD_TYPE)"
	@echo "Build Mode         : $(APP_BUILD_CFG)"
	@echo "Filesystem Mode    : $(FS_CFG)"
	@echo "Memory Config      : $(MEMORY_CONFIG)"
	@echo "--------------------------------------------------------------"
	@echo -e "\n--- make sys_all done! (`date +'%H:%M:%S'`)---\n"

