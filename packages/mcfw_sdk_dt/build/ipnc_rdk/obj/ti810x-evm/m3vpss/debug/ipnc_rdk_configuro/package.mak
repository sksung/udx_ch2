#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = ipnc_rdk_configuro
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/include/utils.tci:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/include/utils.tci
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/xdc.tci:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/xdc.tci
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/template.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/template.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/om2.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/om2.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/xmlgen.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/xmlgen.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/xmlgen2.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/xmlgen2.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/IPackage.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/IPackage.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/package.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/services/global/Clock.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/services/global/Clock.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/services/global/Trace.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/services/global/Trace.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/bld.js:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/bld.js
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/BuildEnvironment.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/BuildEnvironment.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/PackageContents.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/PackageContents.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/_gen.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/_gen.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Library.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Library.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Executable.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Executable.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Repository.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Repository.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Configuration.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Configuration.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Script.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Script.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Manifest.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Manifest.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Utils.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/Utils.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/ITarget.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/ITarget.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/ITarget2.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/ITarget2.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/ITargetFilter.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/ITargetFilter.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/bld/package.xs
package.mak: config.bld
/home/sksung/work/udx/ch2/packages/mcfw_sdk_dt/mcfw/src_bios6/cfg/ti810x/config_ucx_512M.bld:
package.mak: /home/sksung/work/udx/ch2/packages/mcfw_sdk_dt/mcfw/src_bios6/cfg/ti810x/config_ucx_512M.bld
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/ITarget.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/ITarget.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/C28_large.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/C28_large.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/C28_float.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/C28_float.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/package.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/IArm.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/IArm.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/package.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/IArm.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/IArm.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/package.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/ITarget.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/ITarget.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/TMS470.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/TMS470.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/package.xs
/home/sksung/work/udx/ch2/packages/mcfw_sdk_dt/mcfw/src_bios6/cfg/ti810x/genaddrinfo.xs:
package.mak: /home/sksung/work/udx/ch2/packages/mcfw_sdk_dt/mcfw/src_bios6/cfg/ti810x/genaddrinfo.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/services/io/File.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/services/io/File.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/services/io/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/services/io/package.xs
package.mak: package.bld
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/tools/configuro/template/compiler.opt.xdt:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/tools/configuro/template/compiler.opt.xdt
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/tools/configuro/template/custom.mak.exe.xdt:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/tools/configuro/template/custom.mak.exe.xdt
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/tools/configuro/template/package.xs.xdt:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/xdc/tools/configuro/template/package.xs.xdt
endif

ti.targets.arm.elf.M3.rootDir ?= /home/sksung/work/udx/ch2/packages/../ti_tools/cgt470_4_9_5
ti.targets.arm.elf.packageBase ?= /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/
.PRECIOUS: $(XDCCFGDIR)/%.oem3
.PHONY: all,em3 .dlls,em3 .executables,em3 test,em3
all,em3: .executables,em3
.executables,em3: .libraries,em3
.executables,em3: .dlls,em3
.dlls,em3: .libraries,em3
.libraries,em3: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,em3
	@$(ECHO) xdc .executables,em3
	@$(ECHO) xdc .libraries,em3
	@$(ECHO) xdc .dlls,em3


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_ipnc_rdk_configuro.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package ipnc_rdk_configuro" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

.dlls,em3 .dlls: MAIN_APP_m3vpss.pem3

-include package/cfg/MAIN_APP_m3vpss_pem3.mak
-include package/cfg/MAIN_APP_m3vpss_pem3.cfg.mak
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/MAIN_APP_m3vpss_pem3.dep
endif
MAIN_APP_m3vpss.pem3: package/cfg/MAIN_APP_m3vpss_pem3.xdl
	@


ifeq (,$(wildcard .libraries,em3))
MAIN_APP_m3vpss.pem3 package/cfg/MAIN_APP_m3vpss_pem3.c: .libraries,em3
endif

package/cfg/MAIN_APP_m3vpss_pem3.c package/cfg/MAIN_APP_m3vpss_pem3.h package/cfg/MAIN_APP_m3vpss_pem3.xdl: override _PROG_NAME := MAIN_APP_m3vpss.xem3
package/cfg/MAIN_APP_m3vpss_pem3.c: package/cfg/MAIN_APP_m3vpss_pem3.cfg

clean:: clean,em3
	-$(RM) package/cfg/MAIN_APP_m3vpss_pem3.cfg
	-$(RM) package/cfg/MAIN_APP_m3vpss_pem3.dep
	-$(RM) package/cfg/MAIN_APP_m3vpss_pem3.c
	-$(RM) package/cfg/MAIN_APP_m3vpss_pem3.xdc.inc

clean,em3::
	-$(RM) MAIN_APP_m3vpss.pem3
.executables,em3 .executables: MAIN_APP_m3vpss.xem3

MAIN_APP_m3vpss.xem3: |MAIN_APP_m3vpss.pem3

-include package/cfg/MAIN_APP_m3vpss.xem3.mak
MAIN_APP_m3vpss.xem3: package/cfg/MAIN_APP_m3vpss_pem3.oem3 
	$(RM) $@
	@$(MSG) lnkem3 $@ ...
	$(RM) $(XDCCFGDIR)/$@.map
	$(ti.targets.arm.elf.M3.rootDir)/bin/lnk470 -w -q -u _c_int00 -fs $(XDCCFGDIR)$(dir $@)  -q -o $@ package/cfg/MAIN_APP_m3vpss_pem3.oem3   package/cfg/MAIN_APP_m3vpss_pem3.xdl --silicon_version=7M3 --strict_compatibility=on -c -m $(XDCCFGDIR)/$@.map  --zero_init=off  --dynamic --retain=_Ipc_ResetVector -l $(ti.targets.arm.elf.M3.rootDir)/lib/rtsv7M3_T_le_eabi.lib
	
MAIN_APP_m3vpss.xem3: export C_DIR=
MAIN_APP_m3vpss.xem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

MAIN_APP_m3vpss.test test,em3 test: MAIN_APP_m3vpss.xem3.test

MAIN_APP_m3vpss.xem3.test:: MAIN_APP_m3vpss.xem3
ifeq (,$(_TESTLEVEL))
	@$(MAKE) -R -r --no-print-directory -f $(XDCROOT)/packages/xdc/bld/xdc.mak _TESTLEVEL=1 MAIN_APP_m3vpss.xem3.test
else
	@$(MSG) running $<  ...
	$(call EXEC.MAIN_APP_m3vpss.xem3, ) 
endif

clean,em3::
	-$(RM) .tmp,MAIN_APP_m3vpss.xem3,0,*


clean:: clean,em3

clean,em3::
	-$(RM) MAIN_APP_m3vpss.xem3
clean:: 
	-$(RM) package/cfg/MAIN_APP_m3vpss_pem3.pjt
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
MAIN_APP_m3vpss_pem3.oem3,copy : package/cfg/MAIN_APP_m3vpss_pem3.oem3
MAIN_APP_m3vpss_pem3.sem3,copy : package/cfg/MAIN_APP_m3vpss_pem3.sem3

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,ipnc_rdk_configuro
ipnc_rdk_configuro.tar: package/package.bld.xml
ipnc_rdk_configuro.tar: package/package.ext.xml
ipnc_rdk_configuro.tar: package/package.rel.dot
ipnc_rdk_configuro.tar: package/build.cfg
ipnc_rdk_configuro.tar: package/package.xdc.inc
ifeq (,$(MK_NOGENDEPS))
-include package/rel/ipnc_rdk_configuro.tar.dep
endif
package/rel/ipnc_rdk_configuro/ipnc_rdk_configuro/package/package.rel.xml:

ipnc_rdk_configuro.tar: package/rel/ipnc_rdk_configuro.xdc.inc package/rel/ipnc_rdk_configuro/ipnc_rdk_configuro/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/ipnc_rdk_configuro.xdc.inc,package/rel/ipnc_rdk_configuro.tar.dep)


release release,ipnc_rdk_configuro: all ipnc_rdk_configuro.tar
clean:: .clean
	-$(RM) ipnc_rdk_configuro.tar
	-$(RM) package/rel/ipnc_rdk_configuro.xdc.inc
	-$(RM) package/rel/ipnc_rdk_configuro.tar.dep

clean:: .clean
	-$(RM) .libraries .libraries,*
clean:: 
	-$(RM) .dlls .dlls,*
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
ifeq (,$(wildcard package/external))
    $(shell $(MKDIR) package/external)
endif
endif
clean::
	-$(RMDIR) package

include custom.mak
clean:: 
	-$(RM) package/ipnc_rdk_configuro.pjt
