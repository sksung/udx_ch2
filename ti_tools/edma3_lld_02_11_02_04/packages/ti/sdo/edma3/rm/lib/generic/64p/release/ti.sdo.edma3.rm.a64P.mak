#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C64P{1,0,7.0,4
#
ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64P.dep
endif

package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64P: | .interfaces
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64P: src/edma3resmgr.c lib/generic/64p/release/ti.sdo.edma3.rm.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64P:C_DIR=
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64P: | .interfaces
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64P: src/edma3resmgr.c lib/generic/64p/release/ti.sdo.edma3.rm.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64P:C_DIR=
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64P.dep
endif

package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64P: | .interfaces
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64P: src/edma3_rm_gbl_data.c lib/generic/64p/release/ti.sdo.edma3.rm.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64P:C_DIR=
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64P: | .interfaces
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64P: src/edma3_rm_gbl_data.c lib/generic/64p/release/ti.sdo.edma3.rm.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64P:C_DIR=
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

ifneq (clean,$(MAKECMDGOALS))
-include package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64P.dep
endif

package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64P: | .interfaces
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64P: package/package_ti.sdo.edma3.rm.c lib/generic/64p/release/ti.sdo.edma3.rm.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64P:C_DIR=
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64P: | .interfaces
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64P: package/package_ti.sdo.edma3.rm.c lib/generic/64p/release/ti.sdo.edma3.rm.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P  -mi10 -mo   -DGENERIC  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_0_4 -O2  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package -fr=./package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64P:C_DIR=
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)
package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64P: Path:=$(ti.targets.C64P.rootDir)/bin/;$(PATH)

clean,64P ::
	-$(RM) package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64P
	-$(RM) package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64P
	-$(RM) package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64P
	-$(RM) package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.s64P
	-$(RM) package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.s64P
	-$(RM) package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.s64P

lib/generic/64p/release/ti.sdo.edma3.rm.a64P: package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3resmgr.o64P package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/src/edma3_rm_gbl_data.o64P package/lib/lib/generic/64p/release/ti.sdo.edma3.rm/package/package_ti.sdo.edma3.rm.o64P lib/generic/64p/release/ti.sdo.edma3.rm.a64P.mak

clean::
	-$(RM) lib/generic/64p/release/ti.sdo.edma3.rm.a64P.mak
