#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.Linux86{1,0,4.1,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o86U.dep
endif

package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o86U: | .interfaces
package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o86U: package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.c lib/debug/edmacodec1_ti.a86U.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl86U $< ...
	$(gnu.targets.Linux86.rootDir)//bin/gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused  -Dfar= -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=Linux86 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_1_0 -g  $(XDCINCS) -isystem $(gnu.targets.Linux86.rootDir)/include -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o86U: export LD_LIBRARY_PATH=

package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s86U: | .interfaces
package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s86U: package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.c lib/debug/edmacodec1_ti.a86U.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl86U -S $< ...
	$(gnu.targets.Linux86.rootDir)//bin/gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused  -Dfar= -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=Linux86 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_1_0 -g  $(XDCINCS) -isystem $(gnu.targets.Linux86.rootDir)/include -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s86U: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.o86U.dep
endif

package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.o86U: | .interfaces
package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.o86U: edmacodec1_ti.c lib/debug/edmacodec1_ti.a86U.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl86U $< ...
	$(gnu.targets.Linux86.rootDir)//bin/gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused  -Dfar= -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=Linux86 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_1_0 -g  $(XDCINCS) -isystem $(gnu.targets.Linux86.rootDir)/include -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.o86U: export LD_LIBRARY_PATH=

package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.s86U: | .interfaces
package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.s86U: edmacodec1_ti.c lib/debug/edmacodec1_ti.a86U.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl86U -S $< ...
	$(gnu.targets.Linux86.rootDir)//bin/gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused  -Dfar= -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=Linux86 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_1_0 -g  $(XDCINCS) -isystem $(gnu.targets.Linux86.rootDir)/include -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.s86U: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.o86U.dep
endif

package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.o86U: | .interfaces
package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.o86U: edmacodec1_ti_ires.c lib/debug/edmacodec1_ti.a86U.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl86U $< ...
	$(gnu.targets.Linux86.rootDir)//bin/gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused  -Dfar= -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=Linux86 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_1_0 -g  $(XDCINCS) -isystem $(gnu.targets.Linux86.rootDir)/include -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.o86U: export LD_LIBRARY_PATH=

package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.s86U: | .interfaces
package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.s86U: edmacodec1_ti_ires.c lib/debug/edmacodec1_ti.a86U.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl86U -S $< ...
	$(gnu.targets.Linux86.rootDir)//bin/gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused  -Dfar= -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=Linux86 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_1_0 -g  $(XDCINCS) -isystem $(gnu.targets.Linux86.rootDir)/include -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.s86U: export LD_LIBRARY_PATH=

clean,86U ::
	-$(RM) package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o86U
	-$(RM) package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.o86U
	-$(RM) package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.o86U
	-$(RM) package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.s86U
	-$(RM) package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.s86U
	-$(RM) package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.s86U

lib/debug/edmacodec1_ti.a86U: package/lib/lib/debug/edmacodec1_ti/package/package_ti.sdo.fc.ires.examples.codecs.edmacodec1.o86U package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti.o86U package/lib/lib/debug/edmacodec1_ti/edmacodec1_ti_ires.o86U lib/debug/edmacodec1_ti.a86U.mak

clean::
	-$(RM) lib/debug/edmacodec1_ti.a86U.mak
