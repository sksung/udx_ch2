#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C64P{1,0,7.0,4
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.o64P.dep
endif

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.o64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.o64P: src/platforms/sample_tci6486_int_reg.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.o64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.o64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.s64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.s64P: src/platforms/sample_tci6486_int_reg.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.s64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.s64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.o64P.dep
endif

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.o64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.o64P: package/package_ti.sdo.edma3.rm.sample.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.o64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.o64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.s64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.s64P: package/package_ti.sdo.edma3.rm.sample.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.s64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.s64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.o64P.dep
endif

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.o64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.o64P: src/sample_init.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.o64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.o64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.s64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.s64P: src/sample_init.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.s64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.s64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.o64P.dep
endif

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.o64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.o64P: src/platforms/sample_tci6486_cfg.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.o64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.o64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.s64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.s64P: src/platforms/sample_tci6486_cfg.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.s64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.s64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.o64P.dep
endif

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.o64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.o64P: src/sample_cs.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.o64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.o64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.s64P: | .interfaces
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.s64P: src/sample_cs.c lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo  -DCHIP_TCI6486 -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src -fr=./package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.s64P:C_DIR=
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.s64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

clean,64P ::
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.o64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.o64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.o64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.o64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.o64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.s64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.s64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.s64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.s64P
	-$(RM) package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.s64P

lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P: package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_int_reg.o64P package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/package/package_ti.sdo.edma3.rm.sample.o64P package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_init.o64P package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/platforms/sample_tci6486_cfg.o64P package/lib/lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample/src/sample_cs.o64P lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak

clean::
	-$(RM) lib/tci6486-evm/64p/release/ti.sdo.edma3.rm.sample.a64P.mak
