#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C674{1,0,7.0,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o674.dep
endif

package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o674: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o674: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/release/universal_dma_ti_TRACE.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE/package -fr=./package/lib/lib/release/universal_dma_ti_TRACE/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE/package -s o674 $< -C   -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE/package -fr=./package/lib/lib/release/universal_dma_ti_TRACE/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o674: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o674: PATH:=$(ti.targets.C674.rootDir)/bin/:$(PATH)

package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s674: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s674: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/release/universal_dma_ti_TRACE.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 -n $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE/package -fr=./package/lib/lib/release/universal_dma_ti_TRACE/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE/package -s o674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE/package -fr=./package/lib/lib/release/universal_dma_ti_TRACE/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s674: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s674: PATH:=$(ti.targets.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.o674.dep
endif

package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.o674: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.o674: universal_dma_ti.c lib/release/universal_dma_ti_TRACE.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE -fr=./package/lib/lib/release/universal_dma_ti_TRACE -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE -s o674 $< -C   -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE -fr=./package/lib/lib/release/universal_dma_ti_TRACE
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.o674: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.o674: PATH:=$(ti.targets.C674.rootDir)/bin/:$(PATH)

package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.s674: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.s674: universal_dma_ti.c lib/release/universal_dma_ti_TRACE.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 -n $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE -fr=./package/lib/lib/release/universal_dma_ti_TRACE -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE -s o674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE -fr=./package/lib/lib/release/universal_dma_ti_TRACE
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.s674: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.s674: PATH:=$(ti.targets.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.o674.dep
endif

package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.o674: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.o674: universal_dma_ti_ires.c lib/release/universal_dma_ti_TRACE.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE -fr=./package/lib/lib/release/universal_dma_ti_TRACE -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE -s o674 $< -C   -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE -fr=./package/lib/lib/release/universal_dma_ti_TRACE
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.o674: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.o674: PATH:=$(ti.targets.C674.rootDir)/bin/:$(PATH)

package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.s674: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.s674: universal_dma_ti_ires.c lib/release/universal_dma_ti_TRACE.a674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl674 -n $< ...
	$(ti.targets.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE -fr=./package/lib/lib/release/universal_dma_ti_TRACE -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE -s o674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 -eo.o674 -ea.s674 -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C674.rootDir)/include -fs=./package/lib/lib/release/universal_dma_ti_TRACE -fr=./package/lib/lib/release/universal_dma_ti_TRACE
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.s674: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.s674: PATH:=$(ti.targets.C674.rootDir)/bin/:$(PATH)

clean,674 ::
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o674
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.o674
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.o674
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s674
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.s674
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.s674

lib/release/universal_dma_ti_TRACE.a674: package/lib/lib/release/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o674 package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti.o674 package/lib/lib/release/universal_dma_ti_TRACE/universal_dma_ti_ires.o674 lib/release/universal_dma_ti_TRACE.a674.mak

clean::
	-$(RM) lib/release/universal_dma_ti_TRACE.a674.mak
