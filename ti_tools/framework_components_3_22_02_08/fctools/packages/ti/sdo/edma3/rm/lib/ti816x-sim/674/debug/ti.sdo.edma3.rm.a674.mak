#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C674{1,0,7.0,4
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o674.dep
endif

package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o674: | .interfaces
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o674: package/package_ti.sdo.edma3.rm.c lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package -s o674 $< -C   -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o674:C_DIR=
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o674: PATH:=$(ti.targets.C674.rootDir)/bin/;$(PATH)
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o674: Path:=$(ti.targets.C674.rootDir)/bin/;$(PATH)

package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s674: | .interfaces
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s674: package/package_ti.sdo.edma3.rm.c lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 -n $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package -s o674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s674:C_DIR=
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s674: PATH:=$(ti.targets.C674.rootDir)/bin/;$(PATH)
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s674: Path:=$(ti.targets.C674.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.o674.dep
endif

package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.o674: | .interfaces
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.o674: src/configs/edma3_ti816x_cfg.c lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs -s o674 $< -C   -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.o674:C_DIR=
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.o674: PATH:=$(ti.targets.C674.rootDir)/bin/;$(PATH)
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.o674: Path:=$(ti.targets.C674.rootDir)/bin/;$(PATH)

package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.s674: | .interfaces
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.s674: src/configs/edma3_ti816x_cfg.c lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 -n $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs -s o674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.s674:C_DIR=
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.s674: PATH:=$(ti.targets.C674.rootDir)/bin/;$(PATH)
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.s674: Path:=$(ti.targets.C674.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.o674.dep
endif

package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.o674: | .interfaces
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.o674: src/edma3resmgr.c lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -s o674 $< -C   -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.o674:C_DIR=
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.o674: PATH:=$(ti.targets.C674.rootDir)/bin/;$(PATH)
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.o674: Path:=$(ti.targets.C674.rootDir)/bin/;$(PATH)

package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.s674: | .interfaces
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.s674: src/edma3resmgr.c lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 -n $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -s o674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.s674:C_DIR=
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.s674: PATH:=$(ti.targets.C674.rootDir)/bin/;$(PATH)
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.s674: Path:=$(ti.targets.C674.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o674.dep
endif

package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o674: | .interfaces
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o674: src/edma3_rm_gbl_data.c lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -s o674 $< -C   -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o674:C_DIR=
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o674: PATH:=$(ti.targets.C674.rootDir)/bin/;$(PATH)
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o674: Path:=$(ti.targets.C674.rootDir)/bin/;$(PATH)

package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s674: | .interfaces
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s674: src/edma3_rm_gbl_data.c lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 -n $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -s o674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674  -mi10 -mo  -D_DEBUG_=1  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_4 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src -fr=./package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s674:C_DIR=
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s674: PATH:=$(ti.targets.C674.rootDir)/bin/;$(PATH)
package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s674: Path:=$(ti.targets.C674.rootDir)/bin/;$(PATH)

clean,674 ::
	-$(RM) package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o674
	-$(RM) package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.o674
	-$(RM) package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.o674
	-$(RM) package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o674
	-$(RM) package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s674
	-$(RM) package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.s674
	-$(RM) package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.s674
	-$(RM) package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s674

lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674: package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o674 package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/configs/edma3_ti816x_cfg.o674 package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3resmgr.o674 package/lib/lib/ti816x-sim/674/debug/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o674 lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak

clean::
	-$(RM) lib/ti816x-sim/674/debug/ti.sdo.edma3.rm.a674.mak
