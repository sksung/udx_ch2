#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C64P_big_endian{1,0,7.0,4
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64Pe.dep
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64Pe: package/package_ti.sdo.edma3.rm.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64Pe:C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64Pe: Path:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64Pe: package/package_ti.sdo.edma3.rm.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64Pe:C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64Pe: Path:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.o64Pe.dep
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.o64Pe: src/configs/edma3_c6472_cfg.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.o64Pe:C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.o64Pe: Path:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.s64Pe: src/configs/edma3_c6472_cfg.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.s64Pe:C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.s64Pe: Path:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64Pe.dep
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64Pe: src/edma3resmgr.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64Pe:C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64Pe: Path:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64Pe: src/edma3resmgr.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64Pe:C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64Pe: Path:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64Pe.dep
endif

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64Pe: src/edma3_rm_gbl_data.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c  -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -s o64Pe $< -C   -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64Pe:C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64Pe: Path:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)

package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64Pe: | .interfaces
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64Pe: src/edma3_rm_gbl_data.c lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64Pe -n $< ...
	$(ti.targets.C64P_big_endian.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -s o64Pe $< -C  -n -s --symdebug:none -qq -pdsw225 -me -mv64p -eo.o64Pe -ea.s64Pe  -mi10 -mo -me  -DBIG_ENDIAN_MODE -Dxdc_target_name__=C64P_big_endian -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P_big_endian.rootDir)/include -fs=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64Pe:C_DIR=
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64Pe: PATH:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)
package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64Pe: Path:=$(ti.targets.C64P_big_endian.rootDir)/bin/;$(PATH)

clean,64Pe ::
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.s64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64Pe
	-$(RM) package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64Pe

lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe: package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/configs/edma3_c6472_cfg.o64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64Pe package/lib/lib/c6472-evm/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64Pe lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak

clean::
	-$(RM) lib/c6472-evm/64p/release/ti.sdo.edma3.rm.a64Pe.mak
