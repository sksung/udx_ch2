#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C66{1,0,7.2,0
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.oe66.dep
endif

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.oe66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.oe66: src/platforms/sample_tci6608_int_reg.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe66 $< -C   -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.oe66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.oe66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.se66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.se66: src/platforms/sample_tci6608_int_reg.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe66 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.se66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.se66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe66.dep
endif

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe66: src/sample_init.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -s oe66 $< -C   -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.se66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.se66: src/sample_init.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -s oe66 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.se66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.se66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66.dep
endif

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66: package/package_ti.sdo.edma3.drv.sample.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package -s oe66 $< -C   -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66: package/package_ti.sdo.edma3.drv.sample.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package -s oe66 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.oe66.dep
endif

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.oe66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.oe66: src/platforms/sample_tci6608_cfg.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe66 $< -C   -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.oe66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.oe66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.se66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.se66: src/platforms/sample_tci6608_cfg.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -s oe66 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.se66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.se66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe66.dep
endif

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe66: src/sample_cs.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -s oe66 $< -C   -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se66: | .interfaces
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se66: src/sample_cs.c lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -s oe66 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6600 --abi=elfabi -eo.oe66 -ea.se66  -mi10 -mo  -D_DEBUG_=1 -DSIMTCI6608 -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_2_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se66:C_DIR=
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)
package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se66: Path:=$(ti.targets.elf.C66.rootDir)/bin/;$(PATH)

clean,e66 ::
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.oe66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.oe66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.se66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.se66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.se66
	-$(RM) package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.se66

lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66: package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_int_reg.oe66 package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_init.oe66 package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66 package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/platforms/sample_tci6608_cfg.oe66 package/lib/lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample/src/sample_cs.oe66 lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak

clean::
	-$(RM) lib/tci6608-sim/66/debug/ti.sdo.edma3.drv.sample.ae66.mak
