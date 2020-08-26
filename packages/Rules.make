# ============================================================================
# Copyright (c) Texas Instruments Inc 2012
#
# Use of this software is controlled by the terms and conditions found in the
# license agreement under which this software has been supplied or provided.
# ============================================================================

# Default build environment, windows or linux
ifeq ($(OS), )
  OS := Linux
endif

#####################################################################################
#CONFIGURATION
#####################################################################################

#--- Build Type (debug/release)
APP_BUILD_CFG 	 := debug

#----- select board type -------------------------
RDK_BOARD_TYPE := DM8107_UBX
#-------------------------------------------------

#--- UBX Target UBX_CAR
UBX_TARGET := UBX_CAR

#--- Default platform
PLATFORM := ti810x-evm

#--- System platform
SYSTEM_CFG := hd2

#--- app source dir
BRANCH_DIR := d16
#BRANCH_DIR := bike
#BRANCH_DIR := bikefms
#BRANCH_DIR := cwx
#BRANCH_DIR := train
#BRANCH_DIR := pluto

#--- Filesystem Mode
FS_CFG := ubifs

#--- Wi-Fi Feature (YES/NO)
USE_WIFI  := YES

#--- Memory foot print (256M/512M)
MEMORY_CONFIG := 512M

ifeq ($(MEMORY_CONFIG), 256M)
    MEMORY_256MB := YES
else
    MEMORY_256MB := NO
endif

#--- ISP Feature (YES/NO)
USE_ISP := NO

#--- Image Sensor (IMGS_SONY_IMX122/IMGS_MICRON_AR0331)
IMGS_ID := IMGS_SONY_IMX122

#--- SWOSD Operation Configuration (IMX_BASED/NON_IMX_BASED)
OSD_MODE := NON_IMX_BASED

#--- Noise Filter Configaration (DSS_NF/ISS_NF)
NOISE_FILTER_MODE := DSS_NF

#--- Remember is TNF2 is used HDMI Display would not be enabled (YES/NO)
USE_TNF2_FILTER := NO

# Set this flag to "YUV" = YUV frames (secondary stream only) will do a round trip M3-A8-M3 to reach the SD display
# Set this flag to "RAW" = RAW frames will be sent to A8 and then back to M3
FRAMES_TO_A8 := NO

#--- Option to speed up GLBCE by offloading tonalcurve calculation on A8 (YES/NO)
USE_A8_FOR_TC_CALC := YES

#--- Option where from the BoxCar comes from ISS or calculated by iMX (YES/NO)
USE_ISS_BOXCAR := NO

#---- TILER Memory enable (YES/NO)
TILER_ENABLE := YES
BTE_ENABLE := YES

#--- Teardown method (YES/NO)
TEARDOWN_LOAD_UNLOAD := YES

################################################################################
################################################################################

BASE_INSTALL_DIR  := $(shell pwd)/..
CGI_INSTALL_DIR  := $(shell pwd)/../../../..
##CGI_INSTALL_DIR  := $(shell pwd)/../../../../..

# Defining the install base directory for IPNC RDK
RDK_INSTALL_DIR   := $(BASE_INSTALL_DIR)/packages
TOOLS_INSTALL_DIR := $(BASE_INSTALL_DIR)/ti_tools

# Defining the build tools directory for IPNC RDK
BUILD_TOOL_DIR    := $(TOOLS_INSTALL_DIR)/linux_devkit
BUILD_TOOL_PREFIX := $(BUILD_TOOL_DIR)/bin/arm-arago-linux-gnueabi-
CODEGEN_PATH_A8   := $(BUILD_TOOL_DIR)

# Defining all the tools that are required for IPNC RDK
CODEGEN_PATH_DSP  := $(TOOLS_INSTALL_DIR)/cgt6x_7_3_5
CODEGEN_PATH_M3   := $(TOOLS_INSTALL_DIR)/cgt470_4_9_5
edma3lld_PATH     := $(TOOLS_INSTALL_DIR)/edma3_lld_02_11_02_04
fc_PATH           := $(TOOLS_INSTALL_DIR)/framework_components_3_22_02_08
ipc_PATH          := $(TOOLS_INSTALL_DIR)/ipc_1_24_03_32
hdvicplib_PATH    := $(TOOLS_INSTALL_DIR)/ivahd-hdvicp20api_01_00_00_19
linuxdevkit_PATH  := $(TOOLS_INSTALL_DIR)/linux_devkit/arm-arago-linux-gnueabi
bios_PATH         := $(TOOLS_INSTALL_DIR)/bios_6_33_05_46
xdais_PATH        := $(TOOLS_INSTALL_DIR)/xdais_7_22_00_03
xdc_PATH          := $(TOOLS_INSTALL_DIR)/xdctools_3_23_03_53

# Defining all the build components that are required for RDK
syslink_PATH      := $(TOOLS_INSTALL_DIR)/syslink_2_10_06_28
linuxutils_PATH   := $(TOOLS_INSTALL_DIR)/linuxutils_3_22_00_02
iss_PATH       	  := $(TOOLS_INSTALL_DIR)/iss_03_00_00_00
codecs_DIR        := $(TOOLS_INSTALL_DIR)/codecs-dm814x

ifeq ($(BRANCH_DIR), train)
hdvpss_PATH       := $(TOOLS_INSTALL_DIR)/hdvpss_dt_01_00_01_37
else
hdvpss_PATH       := $(TOOLS_INSTALL_DIR)/hdvpss_01_00_01_37
endif


h264enc_DIR       := $(codecs_DIR)/REL.500.V.H264AVC.E.IVAHD.02.00.04.01
h264dec_DIR       := $(codecs_DIR)/REL.500.V.H264AVC.D.HP.IVAHD.02.00.08.00
jpegenc_DIR       := $(codecs_DIR)/REL.500.V.MJPEG.E.IVAHD.01.00.04.00
jpegdec_DIR       := $(codecs_DIR)/REL.500.V.MJPEG.D.IVAHD.01.00.06.00
h264enc_PATH      := $(h264enc_DIR)/500.V.H264AVC.E.IVAHD.02.00/IVAHD_001
h264dec_PATH      := $(h264dec_DIR)/500.V.H264AVC.D.HP.IVAHD.02.00/IVAHD_001
jpegenc_PATH      := $(jpegenc_DIR)/500.V.MJPEG.E.IVAHD.01.00/IVAHD_001
jpegdec_PATH      := $(jpegdec_DIR)/500.V.MJPEG.D.IVAHD.01.00/IVAHD_001

# The directory that points to the Linux Support Package
lsp_PATH          := $(RDK_INSTALL_DIR)/psp
KERNELDIR         := $(lsp_PATH)/kernel
UBOOTDIR          := $(lsp_PATH)/u-boot

# The directory that points to where filesystem is mounted
TARGET_ROOT       := $(BASE_INSTALL_DIR)/target
TARGET_FS         := $(TARGET_ROOT)/rfs
TARGET_FS_DIR     := $(TARGET_FS)/opt/bin
TARGET_FS_WWW     := $(CGI_INSTALL_DIR)/target/rfs/srv/www

# The directory that points IPNC RDK source code

ifeq ($(BRANCH_DIR), train)
MCFW_ROOT_PATH    := $(RDK_INSTALL_DIR)/mcfw_sdk_dt
else
MCFW_ROOT_PATH    := $(RDK_INSTALL_DIR)/mcfw_sdk
endif

TFTP_HOME     	  := $(RDK_INSTALL_DIR)/build
APP_DIR           := $(RDK_INSTALL_DIR)/dev_app
APP_INC_DIR       := $(APP_DIR)/$(BRANCH_DIR)_app/src/inc
APP_IMG_DIR       := $(APP_DIR)/$(BRANCH_DIR)_app/data/img
APP_SND_DIR       := $(APP_DIR)/$(BRANCH_DIR)_app/data/snd
LIVE555_DIR       := $(APP_DIR)/module/live555
IWSCAN_DIR	  := $(APP_DIR)/module/iw_scan

# IPC
ipc_INCLUDE 	  := $(ipc_PATH)/packages

# SYSLINK
syslink_INCLUDE   := $(syslink_PATH)/packages
syslink_LIB_DIR   := $(syslink_INCLUDE)/ti/syslink/lib
syslink_OUT_DIR   := $(syslink_PATH)/packages/ti/syslink/bin/TI814X/

# The directory to MCFW binaries
TARGET_MCFW_DIR:= $(TFTP_HOME)/$(BRANCH_DIR)

# The directory to CMEM library
CMEM_LIB_DIR:=$(linuxutils_PATH)/packages/ti/sdo/linuxutils/cmem/lib
CMEM_INC_DIR:=$(linuxutils_PATH)/packages/ti/sdo/linuxutils/cmem/include

# The directory to root file system
ROOT_FILE_SYS:= $(TARGET_FS)

# Where to copy the resulting executables and data to (when executing 'make
# install') in a proper file structure. This EXEC_DIR should either be visible
# from the target, or you will have to copy this (whole) directory onto the
# target filesystem.
EXEC_DIR:=$(TARGET_FS)/opt/$(BRANCH_DIR)

# Values are "NO" and "YES"
POWER_OPT_DSP_OFF := YES
POWER_OPT_DSS_OFF := NO

USE_SYSLINK_NOTIFY=0

# Default profile
ifeq ($(PROFILE_m3video), )
  PROFILE_m3video := $(APP_BUILD_CFG)
endif

ifeq ($(PROFILE_m3vpss), )
  PROFILE_m3vpss := $(APP_BUILD_CFG)
endif

# Default klockwork build flag
ifeq ($(KW_BUILD), )
  KW_BUILD := no
endif

XDCPATH = $(bios_PATH)/packages;$(xdc_PATH)/packages;$(ipc_PATH)/packages;$(hdvpss_PATH)/packages;$(fc_PATH)/packages;$(MCFW_ROOT_PATH);$(syslink_PATH)/packages;$(xdais_PATH)/packages;$(edma3lld_PATH)/packages

ifeq (, $(findstring $(UBOOTDIR)/tools, $(PATH)))
export PATH:=$(UBOOTDIR)/tools:$(PATH)
endif

TREAT_WARNINGS_AS_ERROR=no

ROOTDIR := $(MCFW_ROOT_PATH)

export OS
export PLATFORM
export CORE
export SYSTEM_CFG
export BRANCH_DIR
export FS_CFG
export APP_BUILD_CFG
export PROFILE_m3vpss
export PROFILE_m3video
export CODEGEN_PATH_M3
export CODEGEN_PATH_A8
export CODEGEN_PATH_DSP
export ROOTDIR
export bios_PATH
export xdc_PATH
export iss_PATH
export hdvpss_PATH
export ipc_PATH
export fc_PATH
export xdais_PATH
export h264dec_PATH
export h264enc_PATH
export jpegenc_PATH
export jpegdec_PATH
export hdvicplib_PATH
export linuxdevkit_PATH
export edma3lld_PATH
export XDCPATH
export KW_BUILD
export syslink_PATH
export KERNELDIR
export TARGET_ROOT
export TARGET_FS
export TARGET_FS_WWW
export TARGET_MCFW_DIR
export ROOT_FILE_SYS
export MCFW_ROOT_PATH
export UBOOTDIR
export RDK_BOARD_TYPE
export USE_SYSLINK_NOTIFY
export DEST_ROOT
export RDK_INSTALL_DIR
export TFTP_HOME
export BUILD_TOOL_DIR
export BUILD_TOOL_PREFIX
export EXEC_DIR
export syslink_INCLUDE
export syslink_LIB_DIR
export ipc_INCLUDE
export linuxutils_PATH
export POWER_OPT_DSP_OFF
export POWER_OPT_DSS_OFF
export RDK_FILE_SYSTEM
export IMGS_ID
export NOISE_FILTER_MODE
export OSD_MODE
export TREAT_WARNINGS_AS_ERROR
export CMEM_LIB_DIR
export CMEM_INC_DIR
export FRAMES_TO_A8
export MEMORY_256MB
export TILER_ENABLE
export BTE_ENABLE
export TARGET_FS_DIR
export USE_A8_FOR_TC_CALC
export USE_ISS_BOXCAR
export USE_TNF2_FILTER
export TEARDOWN_LOAD_UNLOAD
export APP_DIR
export APP_INC_DIR
export USE_ISP
export UBX_TARGET
export USE_WIFI
export LIVE555_DIR
export IWSCAN_DIR
