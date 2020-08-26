#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.arp32.ARP32{1,0,1.0,0,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.oearp32.dep
endif

package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.oearp32: | .interfaces
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.oearp32: package/package_ti.sdo.fc.ires.examples.codecs.template.c lib/release/template_ti.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c  -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti/package -fr=./package/lib/lib/release/template_ti/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti/package -s oearp32 $< -C   -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti/package -fr=./package/lib/lib/release/template_ti/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.oearp32: export C_DIR=
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.oearp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.searp32: | .interfaces
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.searp32: package/package_ti.sdo.fc.ires.examples.codecs.template.c lib/release/template_ti.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 -n $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti/package -fr=./package/lib/lib/release/template_ti/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti/package -s oearp32 $< -C  -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti/package -fr=./package/lib/lib/release/template_ti/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.searp32: export C_DIR=
package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.searp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/template_ti/template_ti.oearp32.dep
endif

package/lib/lib/release/template_ti/template_ti.oearp32: | .interfaces
package/lib/lib/release/template_ti/template_ti.oearp32: template_ti.c lib/release/template_ti.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c  -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti -s oearp32 $< -C   -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/template_ti.oearp32: export C_DIR=
package/lib/lib/release/template_ti/template_ti.oearp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

package/lib/lib/release/template_ti/template_ti.searp32: | .interfaces
package/lib/lib/release/template_ti/template_ti.searp32: template_ti.c lib/release/template_ti.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 -n $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti -s oearp32 $< -C  -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/template_ti.searp32: export C_DIR=
package/lib/lib/release/template_ti/template_ti.searp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/template_ti/template_ti_ires.oearp32.dep
endif

package/lib/lib/release/template_ti/template_ti_ires.oearp32: | .interfaces
package/lib/lib/release/template_ti/template_ti_ires.oearp32: template_ti_ires.c lib/release/template_ti.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c  -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti -s oearp32 $< -C   -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/template_ti_ires.oearp32: export C_DIR=
package/lib/lib/release/template_ti/template_ti_ires.oearp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

package/lib/lib/release/template_ti/template_ti_ires.searp32: | .interfaces
package/lib/lib/release/template_ti/template_ti_ires.searp32: template_ti_ires.c lib/release/template_ti.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 -n $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/template_ti -s oearp32 $< -C  -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_1_0_0_1 -O2  $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/release/template_ti -fr=./package/lib/lib/release/template_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/template_ti/template_ti_ires.searp32: export C_DIR=
package/lib/lib/release/template_ti/template_ti_ires.searp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

clean,earp32 ::
	-$(RM) package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.oearp32
	-$(RM) package/lib/lib/release/template_ti/template_ti.oearp32
	-$(RM) package/lib/lib/release/template_ti/template_ti_ires.oearp32
	-$(RM) package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.searp32
	-$(RM) package/lib/lib/release/template_ti/template_ti.searp32
	-$(RM) package/lib/lib/release/template_ti/template_ti_ires.searp32

lib/release/template_ti.aearp32: package/lib/lib/release/template_ti/package/package_ti.sdo.fc.ires.examples.codecs.template.oearp32 package/lib/lib/release/template_ti/template_ti.oearp32 package/lib/lib/release/template_ti/template_ti_ires.oearp32 lib/release/template_ti.aearp32.mak

clean::
	-$(RM) lib/release/template_ti.aearp32.mak