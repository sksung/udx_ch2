#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C64P{1,0,7.0,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.o64P.dep
endif

package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.o64P: | .interfaces
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.o64P: package/package_ti.sdo.fc.ires.examples.codecs.template.c lib/release/template_ti.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti/package -fr=./package/lib/lib/release/template_ti/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti/package -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti/package -fr=./package/lib/lib/release/template_ti/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.o64P: export C_DIR=
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.s64P: | .interfaces
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.s64P: package/package_ti.sdo.fc.ires.examples.codecs.template.c lib/release/template_ti.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti/package -fr=./package/lib/lib/release/template_ti/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti/package -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti/package -fr=./package/lib/lib/release/template_ti/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.s64P: export C_DIR=
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/template_ti/template_ti.o64P.dep
endif

package/lib/lib/release/template_ti/template_ti.o64P: | .interfaces
package/lib/lib/release/template_ti/template_ti.o64P: template_ti.c lib/release/template_ti.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/template_ti.o64P: export C_DIR=
package/lib/lib/release/template_ti/template_ti.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/release/template_ti/template_ti.s64P: | .interfaces
package/lib/lib/release/template_ti/template_ti.s64P: template_ti.c lib/release/template_ti.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/template_ti.s64P: export C_DIR=
package/lib/lib/release/template_ti/template_ti.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/template_ti/template_ti_ires.o64P.dep
endif

package/lib/lib/release/template_ti/template_ti_ires.o64P: | .interfaces
package/lib/lib/release/template_ti/template_ti_ires.o64P: template_ti_ires.c lib/release/template_ti.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/template_ti_ires.o64P: export C_DIR=
package/lib/lib/release/template_ti/template_ti_ires.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/release/template_ti/template_ti_ires.s64P: | .interfaces
package/lib/lib/release/template_ti/template_ti_ires.s64P: template_ti_ires.c lib/release/template_ti.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_0 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/template_ti_ires.s64P: export C_DIR=
package/lib/lib/release/template_ti/template_ti_ires.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

clean,64P ::
	-$(RM) package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.o64P
	-$(RM) package/lib/lib/release/template_ti/template_ti.o64P
	-$(RM) package/lib/lib/release/template_ti/template_ti_ires.o64P
	-$(RM) package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.s64P
	-$(RM) package/lib/lib/release/template_ti/template_ti.s64P
	-$(RM) package/lib/lib/release/template_ti/template_ti_ires.s64P

lib/release/template_ti.a64P: package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.o64P package/lib/lib/release/template_ti/template_ti.o64P package/lib/lib/release/template_ti/template_ti_ires.o64P lib/release/template_ti.a64P.mak

clean::
	-$(RM) lib/release/template_ti.a64P.mak
