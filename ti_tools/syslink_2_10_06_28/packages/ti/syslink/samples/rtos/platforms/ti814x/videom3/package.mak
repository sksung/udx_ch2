#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = ti/syslink/samples/rtos/platforms/ti814x/videom3
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
/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/_config.bld:
package.mak: /home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/_config.bld
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/ITarget.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/ITarget.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/C28_large.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/C28_large.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/C28_float.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/C28_float.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/package.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/ITarget.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/ITarget.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/TMS470.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/TMS470.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/elf/package.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/IArm.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/IArm.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/package.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/IArm.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/IArm.xs
/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/package.xs:
package.mak: /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/elf/package.xs
package.mak: package.bld
endif

all,e674 .libraries,e674 .dlls,e674 .executables,e674 test,e674:;
all,em3 .libraries,em3 .dlls,em3 .executables,em3 test,em3:;

all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_ti.syslink.samples.rtos.platforms.ti814x.videom3.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package ti.syslink.samples.rtos.platforms.ti814x.videom3" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

ifeq (,$(MK_NOGENDEPS))
-include package/package.cfg.dep
endif

package/package.ext.xml: package/package.cfg.xdc.inc
package/package.cfg.xdc.inc: $(XDCROOT)/packages/xdc/cfg/cfginc.js package.xdc
	@$(MSG) generating schema include file list ...
	$(CONFIG) -f $(XDCROOT)/packages/xdc/cfg/cfginc.js ti.syslink.samples.rtos.platforms.ti814x.videom3 $@

test:;
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,ti_syslink_samples_rtos_platforms_ti814x_videom3
ti_syslink_samples_rtos_platforms_ti814x_videom3.zip: package/package.bld.xml
ti_syslink_samples_rtos_platforms_ti814x_videom3.zip: package/package.ext.xml
ti_syslink_samples_rtos_platforms_ti814x_videom3.zip: package/package.rel.dot
ti_syslink_samples_rtos_platforms_ti814x_videom3.zip: package/build.cfg
ti_syslink_samples_rtos_platforms_ti814x_videom3.zip: package/package.xdc.inc
ti_syslink_samples_rtos_platforms_ti814x_videom3.zip: package/package.cfg.xdc.inc
ifeq (,$(MK_NOGENDEPS))
-include package/rel/ti_syslink_samples_rtos_platforms_ti814x_videom3.zip.dep
endif
package/rel/ti_syslink_samples_rtos_platforms_ti814x_videom3/ti/syslink/samples/rtos/platforms/ti814x/videom3/package/package.rel.xml:

ti_syslink_samples_rtos_platforms_ti814x_videom3.zip: package/rel/ti_syslink_samples_rtos_platforms_ti814x_videom3.xdc.inc package/rel/ti_syslink_samples_rtos_platforms_ti814x_videom3/ti/syslink/samples/rtos/platforms/ti814x/videom3/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELZIP,package/rel/ti_syslink_samples_rtos_platforms_ti814x_videom3.xdc.inc,package/rel/ti_syslink_samples_rtos_platforms_ti814x_videom3.zip.dep)


release release,ti_syslink_samples_rtos_platforms_ti814x_videom3: all ti_syslink_samples_rtos_platforms_ti814x_videom3.zip
clean:: .clean
	-$(RM) ti_syslink_samples_rtos_platforms_ti814x_videom3.zip
	-$(RM) package/rel/ti_syslink_samples_rtos_platforms_ti814x_videom3.xdc.inc
	-$(RM) package/rel/ti_syslink_samples_rtos_platforms_ti814x_videom3.zip.dep

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


