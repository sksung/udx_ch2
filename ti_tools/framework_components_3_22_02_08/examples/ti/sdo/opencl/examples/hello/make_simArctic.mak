# 
#  Copyright (c) 2012, Texas Instruments Incorporated
#  All rights reserved.
# 
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
# 
#  *  Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
# 
#  *  Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
# 
#  *  Neither the name of Texas Instruments Incorporated nor the names of
#     its contributors may be used to endorse or promote products derived
#     from this software without specific prior written permission.
# 
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
#  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 

#
#  ======== make_simArctic.mak ========
#
#  The following variables are used from the environment.
#
#  ECLIPSE_HOME         full path to the ccsv4 folder
#

#
#  ======== dependencies ========
#
CCS_DIR = $(subst /C:,C:,$(subst /ccsv4/eclipse/,,$(ECLIPSE_HOME)))

FC_INSTALL_DIR    = $(CCS_DIR)/framework_components_your_version_number
IPC_INSTALL_DIR   = $(CCS_DIR)/ipc_your_version_number
BIOS_INSTALL_DIR  = $(CCS_DIR)/bios_your_version_number
XDC_INSTALL_DIR   = $(CCS_DIR)/xdctools_your_version_number

CGT_CE674_INSTALL_DIR   ?= $(CCS_DIR)/ccsv4/tools/compiler/c6000
TI_ARP32_INSTALL_DIR    ?= $(CCS_DIR)/ccsv5/compiler/arp32

#
#  ======== include path ========
#
INCPATH =   $(FC_INSTALL_DIR)/packages \
            $(FC_INSTALL_DIR)/packages/khronos/opencl \
            $(IPC_INSTALL_DIR)/packages \
            $(BIOS_INSTALL_DIR)/packages \
            $(XDC_INSTALL_DIR)/packages

#
#  ======== toolchain macros ========
#
ifeq (e674,$(SUFFIX))
CGTOOLS = $(CGT_CE674_INSTALL_DIR)

CC = $(CGTOOLS)/bin/cl6x -c -mv6740 --abi=elfabi
AR = $(CGTOOLS)/bin/ar6x rq
LD = $(CGTOOLS)/bin/lnk6x --abi=elfabi

CPPFLAGS = -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h \
    -DPlatform_SystemCfg_h=systemcfg_$(PLAT)/SystemCfg.h
CFLAGS = -qq -pdsw225 $(CCPROFILE_$(PROFILE)) \
    -I. $(addprefix -I,$(INCPATH)) -I$(CGTOOLS)/include

LDFLAGS = -w -q -u _c_int00 -c -m $@.map
LDLIBS = -l $(CGTOOLS)/lib/rts6740_elf.lib

CCPROFILE_debug = -D_DEBUG_=1 --symdebug:dwarf
CCPROFILE_release = -O2
endif

ifeq (earp32,$(SUFFIX))
CGTOOLS = $(TI_ARP32_INSTALL_DIR)

CC = $(CGTOOLS)/bin/cl-arp32 -c --silicon_version=v210
AR = $(CGTOOLS)/bin/ar-arp32 rq
LD = $(CGTOOLS)/bin/lnk-arp32

CPPFLAGS = -Dxdc_target_name__=ARP32 \
    -Dxdc_target_types__=ti/targets/elf/arp32/std.h \
    -DPlatform_SystemCfg_h=systemcfg_$(PLAT)/SystemCfg.h
CFLAGS = -qq -pdsw225 $(CCPROFILE_$(PROFILE)) \
    -I. $(addprefix -I,$(INCPATH)) -I$(CGTOOLS)/include

LDFLAGS = -w -q -u _c_int00 -c -m $@.map -c
LDLIBS = -l $(CGTOOLS)/lib/rtsarp32_v200.lib

CCPROFILE_debug = -D_DEBUG_=1 -g
CCPROFILE_release = -O2
endif

#
#  ======== source files ========
#
PLAT = ti_platforms_simArctic

App_srcs = main_host_bios.c Hello.c
App_objs = \
    $(addprefix bin/$(PLAT)/$(PROFILE)/, \
    $(patsubst %.c,%.o$(SUFFIX),$(App_srcs)))
App_libs = \
    systemcfg_$(PLAT)/lib/$(PROFILE)/App_systemcfg.a$(SUFFIX) \
    systemcfg_$(PLAT)/configuro_App/linker.cmd

ComputeDevice_srcs = main_server_bios.c HelloKnl.c KernelTable.c
ComputeDevice_objs = \
    $(addprefix bin/$(PLAT)/$(PROFILE)/, \
    $(patsubst %.c,%.o$(SUFFIX),$(ComputeDevice_srcs)))
ComputeDevice_libs = \
    systemcfg_$(PLAT)/lib/$(PROFILE)/ComputeDevice_systemcfg.a$(SUFFIX) \
    systemcfg_$(PLAT)/configuro_ComputeDevice/linker.cmd

#
#  ======== make commands ========
#
.PHONY: all
.PHONY: systemcfg_ti_platforms_simArctic

all: systemcfg_ti_platforms_simArctic
	$(MAKE) -f make_simArctic.mak PROFILE=debug SUFFIX=e674 Hello.x
#	$(MAKE) -f make_simArctic.mak PROFILE=release SUFFIX=e674 Hello.x
	$(MAKE) -f make_simArctic.mak PROFILE=debug SUFFIX=earp32 ComputeDevice.x
#	$(MAKE) -f make_simArctic.mak PROFILE=release SUFFIX=earp32 ComputeDevice.x

#
#  ======== build rules ========
#
systemcfg_ti_platforms_simArctic:
	$(MAKE) -C $@ $(MAKEVARS) all

Hello.x: bin/$(PLAT)/$(PROFILE)/Hello.x$(SUFFIX)
bin/$(PLAT)/$(PROFILE)/Hello.x$(SUFFIX): $(App_objs) $(App_libs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

ComputeDevice.x: bin/$(PLAT)/$(PROFILE)/ComputeDevice.x$(SUFFIX)
bin/$(PLAT)/$(PROFILE)/ComputeDevice.x$(SUFFIX): $(ComputeDevice_objs) $(ComputeDevice_libs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

bin/$(PLAT)/$(PROFILE)/%.o$(SUFFIX): %.h
bin/$(PLAT)/$(PROFILE)/%.o$(SUFFIX): %.c
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) --output_file=$@ -fc $<

clean::
	$(RMDIR) bin

#
#  ======== standard macros ========
#  XDCtools provides commands for Windows; use native commands elsewhere.
#
ifneq (,$(wildcard $(XDC_INSTALL_DIR)/bin/echo.exe))
ECHO    = $(XDC_INSTALL_DIR)/bin/echo
MKDIR   = $(XDC_INSTALL_DIR)/bin/mkdir -p
RM      = $(XDC_INSTALL_DIR)/bin/rm -f
RMDIR   = $(XDC_INSTALL_DIR)/bin/rm -rf
else
ECHO    = echo
MKDIR   = mkdir -p
RM      = rm -f
RMDIR   = rm -rf
endif

# create the output directories
ifneq (clean,$(MAKECMDGOALS))
ifneq (,$(PROFILE))
ifeq (,$(wildcard bin/$(PLAT)/$(PROFILE)))
    $(shell $(MKDIR) -p bin/$(PLAT)/$(PROFILE))
endif
endif
endif
#
#  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,3; 4-16-2012 00:03:05; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

#

