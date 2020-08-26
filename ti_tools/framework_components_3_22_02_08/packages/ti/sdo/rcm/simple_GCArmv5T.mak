#
#  Copyright 2012 by Texas Instruments Incorporated.
#  
#

# Generated by build.filter.Make on Sun Apr 15 2012 23:11:20 GMT-0700 (PDT)
#
# SEARCHPATH is a semicolon-delimited directory list of dependencies
#
SEARCHPATH ?= $(PKG_PATH)

#
# Set LIBDIR to the directory where libraries are created
#
LIBDIR ?= .objs

#
# Macro definitions referenced below
#
empty =
space =$(empty) $(empty)
INCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(SEARCHPATH))))
RM = rm -f
MKDIR = mkdir -p
RMDIR = rm -rf

.PHONY: all clean initialize

all: initialize
initialize:
	-@$(MKDIR) .objs
ifneq (.objs,$(LIBDIR))
	-@$(MKDIR) $(LIBDIR)
endif

clean::
	-$(RMDIR) .objs
clean::
	-$(RMDIR) $(LIBDIR)
gnu.targets.arm.GCArmv5T.rootDir ?= $(CGT_ARM_INSTALL_DIR)

.objs/rcm_syslink_RcmClient.ov5T: RcmClient.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -DRCM_ti_syslink -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/rcm_syslink_RcmClient.ov5T
clean::
	-$(RM) .objs/rcm_syslink_RcmClient.ov5T

.objs/rcm_syslink_RcmServer.ov5T: RcmServer.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -DRCM_ti_syslink -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/rcm_syslink_RcmServer.ov5T
clean::
	-$(RM) .objs/rcm_syslink_RcmServer.ov5T

.objs/rcm_syslink_RcmUtils.ov5T: RcmUtils.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -DRCM_ti_syslink -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/rcm_syslink_RcmUtils.ov5T
clean::
	-$(RM) .objs/rcm_syslink_RcmUtils.ov5T

$(LIBDIR)/rcm_syslink.av5T: .objs/rcm_syslink_RcmClient.ov5T .objs/rcm_syslink_RcmServer.ov5T .objs/rcm_syslink_RcmUtils.ov5T 
	 $(CGTOOLS_V5T)/$(AR_V5T) cr $@ $^
all: $(LIBDIR)/rcm_syslink.av5T
clean::
	-$(RM) $(LIBDIR)/rcm_syslink.av5T
#
#  @(#) ti.sdo.rcm; 2, 0, 0,3; 4-16-2012 00:03:16; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

#
