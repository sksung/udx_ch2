#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C64P{1,0,7.2,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.oe64P.dep
endif

package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.oe64P: | .interfaces
package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.oe64P: package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.c lib/release/idma3codec1_ti.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti/package -fr=./package/lib/lib/release/idma3codec1_ti/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/idma3codec1_ti/package -s oe64P $< -C   -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti/package -fr=./package/lib/lib/release/idma3codec1_ti/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.oe64P: export C_DIR=
package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.oe64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.se64P: | .interfaces
package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.se64P: package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.c lib/release/idma3codec1_ti.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P -n $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti/package -fr=./package/lib/lib/release/idma3codec1_ti/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/idma3codec1_ti/package -s oe64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti/package -fr=./package/lib/lib/release/idma3codec1_ti/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.se64P: export C_DIR=
package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.se64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.oe64P.dep
endif

package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.oe64P: | .interfaces
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.oe64P: idma3codec1_ti.c lib/release/idma3codec1_ti.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti -fr=./package/lib/lib/release/idma3codec1_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/idma3codec1_ti -s oe64P $< -C   -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti -fr=./package/lib/lib/release/idma3codec1_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.oe64P: export C_DIR=
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.oe64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.se64P: | .interfaces
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.se64P: idma3codec1_ti.c lib/release/idma3codec1_ti.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P -n $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti -fr=./package/lib/lib/release/idma3codec1_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/idma3codec1_ti -s oe64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti -fr=./package/lib/lib/release/idma3codec1_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.se64P: export C_DIR=
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.se64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.oe64P.dep
endif

package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.oe64P: | .interfaces
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.oe64P: idma3codec1_ti_idma3.c lib/release/idma3codec1_ti.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti -fr=./package/lib/lib/release/idma3codec1_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/idma3codec1_ti -s oe64P $< -C   -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti -fr=./package/lib/lib/release/idma3codec1_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.oe64P: export C_DIR=
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.oe64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.se64P: | .interfaces
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.se64P: idma3codec1_ti_idma3.c lib/release/idma3codec1_ti.ae64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle64P -n $< ...
	$(ti.targets.elf.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti -fr=./package/lib/lib/release/idma3codec1_ti -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/idma3codec1_ti -s oe64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p --abi=eabi -eo.oe64P -ea.se64P   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -g --optimize_with_debug  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C64P.rootDir)/include -fs=./package/lib/lib/release/idma3codec1_ti -fr=./package/lib/lib/release/idma3codec1_ti
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.se64P: export C_DIR=
package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.se64P: PATH:=$(ti.targets.elf.C64P.rootDir)/bin/:$(PATH)

clean,e64P ::
	-$(RM) package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.oe64P
	-$(RM) package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.oe64P
	-$(RM) package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.oe64P
	-$(RM) package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.se64P
	-$(RM) package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.se64P
	-$(RM) package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.se64P

lib/release/idma3codec1_ti.ae64P: package/lib/lib/release/idma3codec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.idma3codec1.oe64P package/lib/lib/release/idma3codec1_ti/idma3codec1_ti.oe64P package/lib/lib/release/idma3codec1_ti/idma3codec1_ti_idma3.oe64P lib/release/idma3codec1_ti.ae64P.mak

clean::
	-$(RM) lib/release/idma3codec1_ti.ae64P.mak
