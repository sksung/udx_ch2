#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.A8F{1,0,4.6,3
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.oea8f.dep
endif

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.oea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.oea8f: package/package_ti.sdo.edma3.rm.sample.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c  -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package -s oea8f $< -C   -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.oea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.oea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.oea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.sea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.sea8f: package/package_ti.sdo.edma3.rm.sample.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f -n $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package -s oea8f $< -C  -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.sea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.sea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.sea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.oea8f.dep
endif

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.oea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.oea8f: src/platforms/sample_ti814x_arm_int_reg.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c  -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -s oea8f $< -C   -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.oea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.oea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.oea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.sea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.sea8f: src/platforms/sample_ti814x_arm_int_reg.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f -n $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -s oea8f $< -C  -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.sea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.sea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.sea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.oea8f.dep
endif

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.oea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.oea8f: src/sample_arm_init.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c  -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -s oea8f $< -C   -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.oea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.oea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.oea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.sea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.sea8f: src/sample_arm_init.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f -n $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -s oea8f $< -C  -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.sea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.sea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.sea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.oea8f.dep
endif

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.oea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.oea8f: src/platforms/sample_ti814x_arm_cfg.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c  -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -s oea8f $< -C   -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.oea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.oea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.oea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.sea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.sea8f: src/platforms/sample_ti814x_arm_cfg.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f -n $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -s oea8f $< -C  -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.sea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.sea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.sea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.oea8f.dep
endif

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.oea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.oea8f: src/sample_arm_cs.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c  -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -s oea8f $< -C   -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.oea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.oea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.oea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.sea8f: | .interfaces
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.sea8f: src/sample_arm_cs.c lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clea8f -n $< ...
	$(ti.targets.arm.elf.A8F.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -s oea8f $< -C  -n -s --symdebug:none -qq -pdsw225 --neon --endian=little -mv7A8 --abi=eabi -eo.oea8f -ea.sea8f  -D_DEBUG_=1 -DCHIP_TI814X -Dxdc_target_name__=A8F -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_6_3 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.A8F.rootDir)/include/rts -I$(ti.targets.arm.elf.A8F.rootDir)/include  -fs=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.sea8f:C_DIR=
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.sea8f: PATH:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)
package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.sea8f: Path:=$(ti.targets.arm.elf.A8F.rootDir)/bin/;$(PATH)

clean,ea8f ::
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.oea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.oea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.oea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.oea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.oea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.sea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.sea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.sea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.sea8f
	-$(RM) package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.sea8f

lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f: package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.oea8f package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_int_reg.oea8f package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_init.oea8f package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/platforms/sample_ti814x_arm_cfg.oea8f package/lib/lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample/src/sample_arm_cs.oea8f lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak

clean::
	-$(RM) lib/ti814x-evm/a8/debug/ti.sdo.edma3.rm.sample.aea8f.mak