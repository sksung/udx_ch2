#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.C64P{1,0,7.0,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o64P.dep
endif

package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o64P: | .interfaces
package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o64P: package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.c lib/debug/edmacodec1_ti_TRACE.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE/package -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/edmacodec1_ti_TRACE/package -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE/package -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o64P: export C_DIR=
package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s64P: | .interfaces
package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s64P: package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.c lib/debug/edmacodec1_ti_TRACE.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE/package -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/edmacodec1_ti_TRACE/package -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE/package -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s64P: export C_DIR=
package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.o64P.dep
endif

package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.o64P: | .interfaces
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.o64P: edmacodec1_ti.c lib/debug/edmacodec1_ti_TRACE.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/edmacodec1_ti_TRACE -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.o64P: export C_DIR=
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.s64P: | .interfaces
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.s64P: edmacodec1_ti.c lib/debug/edmacodec1_ti_TRACE.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/edmacodec1_ti_TRACE -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.s64P: export C_DIR=
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.o64P.dep
endif

package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.o64P: | .interfaces
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.o64P: edmacodec1_ti_ires.c lib/debug/edmacodec1_ti_TRACE.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/edmacodec1_ti_TRACE -s o64P $< -C   -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.o64P: export C_DIR=
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.o64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.s64P: | .interfaces
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.s64P: edmacodec1_ti_ires.c lib/debug/edmacodec1_ti_TRACE.a64P.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl64P -n $< ...
	$(ti.targets.C64P.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/edmacodec1_ti_TRACE -s o64P $< -C  -n -s --symdebug:none -qq -pdsw225 -mv64p -eo.o64P -ea.s64P -mi10 -mo  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_0_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.C64P.rootDir)/include -fs=./package/lib/lib/debug/edmacodec1_ti_TRACE -fr=./package/lib/lib/debug/edmacodec1_ti_TRACE
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.s64P: export C_DIR=
package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.s64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

clean,64P ::
	-$(RM) package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o64P
	-$(RM) package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.o64P
	-$(RM) package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.o64P
	-$(RM) package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s64P
	-$(RM) package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.s64P
	-$(RM) package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.s64P

lib/debug/edmacodec1_ti_TRACE.a64P: package/lib/lib/debug/edmacodec1_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o64P package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti.o64P package/lib/lib/debug/edmacodec1_ti_TRACE/edmacodec1_ti_ires.o64P lib/debug/edmacodec1_ti_TRACE.a64P.mak

clean::
	-$(RM) lib/debug/edmacodec1_ti_TRACE.a64P.mak
