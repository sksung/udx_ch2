#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C66_big_endian{1,0,7.2,0
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.oe66e.dep
endif

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.oe66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.oe66e: src/platforms/sample_c6670_cfg.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.oe66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.oe66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.se66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.se66e: src/platforms/sample_c6670_cfg.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.se66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.se66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.oe66e.dep
endif

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.oe66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.oe66e: src/platforms/sample_c6670_int_reg.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.oe66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.oe66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.se66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.se66e: src/platforms/sample_c6670_int_reg.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.se66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.se66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.oe66e.dep
endif

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.oe66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.oe66e: src/sample_init.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.oe66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.oe66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.se66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.se66e: src/sample_init.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.se66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.se66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66e.dep
endif

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66e: package/package_ti.sdo.edma3.drv.sample.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66e: package/package_ti.sdo.edma3.drv.sample.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.oe66e.dep
endif

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.oe66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.oe66e: src/sample_cs.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -s oe66e $< -C   -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.oe66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.oe66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.oe66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.se66e: | .interfaces
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.se66e: src/sample_cs.c lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66e -n $< ...
	$(ti.targets.elf.C66_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -s oe66e $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv6600 --abi=elfabi -eo.oe66e -ea.se66e  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C66_big_endian -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_2_0 -O2  $(XDCINCS) -I$(ti.targets.elf.C66_big_endian.rootDir)/include -fs=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src -fr=./package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.se66e:C_DIR=
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.se66e: PATH:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.se66e: Path:=$(ti.targets.elf.C66_big_endian.rootDir)/bin/;$(PATH)

clean,e66e ::
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.oe66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.oe66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.oe66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.oe66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.se66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.se66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.se66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.se66e
	-$(RM) package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.se66e

lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e: package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_cfg.oe66e package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/platforms/sample_c6670_int_reg.oe66e package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_init.oe66e package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/package/package_ti.sdo.edma3.drv.sample.oe66e package/lib/lib/c6670-evm/66release/ti.sdo.edma3.drv.sample/src/sample_cs.oe66e lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak

clean::
	-$(RM) lib/c6670-evm/66release/ti.sdo.edma3.drv.sample.ae66e.mak
