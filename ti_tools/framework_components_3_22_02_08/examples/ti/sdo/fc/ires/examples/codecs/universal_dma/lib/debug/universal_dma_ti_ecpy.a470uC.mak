#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.UCArm9{1,0,4.2,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o470uC.dep
endif

package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o470uC: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o470uC: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/debug/universal_dma_ti_ecpy.a470uC.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl470uC $< ...
	$(gnu.targets.arm.UCArm9.rootDir)//bin/arm-linux-gcc -c -MD -MF $@.dep -x c  -Wunused -D_REENTRANT   -Dfar=  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=UCArm9 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_2_1 -g  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o470uC: export LD_LIBRARY_PATH=

package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s470uC: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s470uC: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/debug/universal_dma_ti_ecpy.a470uC.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl470uC -S $< ...
	$(gnu.targets.arm.UCArm9.rootDir)//bin/arm-linux-gcc -c -MD -MF $@.dep -x c -S -Wunused -D_REENTRANT   -Dfar=  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=UCArm9 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_2_1 -g  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s470uC: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.o470uC.dep
endif

package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.o470uC: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.o470uC: universal_dma_ti.c lib/debug/universal_dma_ti_ecpy.a470uC.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl470uC $< ...
	$(gnu.targets.arm.UCArm9.rootDir)//bin/arm-linux-gcc -c -MD -MF $@.dep -x c  -Wunused -D_REENTRANT   -Dfar=  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=UCArm9 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_2_1 -g  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.o470uC: export LD_LIBRARY_PATH=

package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.s470uC: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.s470uC: universal_dma_ti.c lib/debug/universal_dma_ti_ecpy.a470uC.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl470uC -S $< ...
	$(gnu.targets.arm.UCArm9.rootDir)//bin/arm-linux-gcc -c -MD -MF $@.dep -x c -S -Wunused -D_REENTRANT   -Dfar=  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=UCArm9 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_2_1 -g  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.s470uC: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.o470uC.dep
endif

package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.o470uC: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.o470uC: universal_dma_ti_ires.c lib/debug/universal_dma_ti_ecpy.a470uC.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl470uC $< ...
	$(gnu.targets.arm.UCArm9.rootDir)//bin/arm-linux-gcc -c -MD -MF $@.dep -x c  -Wunused -D_REENTRANT   -Dfar=  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=UCArm9 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_2_1 -g  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.o470uC: export LD_LIBRARY_PATH=

package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.s470uC: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.s470uC: universal_dma_ti_ires.c lib/debug/universal_dma_ti_ecpy.a470uC.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cl470uC -S $< ...
	$(gnu.targets.arm.UCArm9.rootDir)//bin/arm-linux-gcc -c -MD -MF $@.dep -x c -S -Wunused -D_REENTRANT   -Dfar=  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=UCArm9 -Dxdc_target_types__=gnu/targets/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_2_1 -g  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.s470uC: export LD_LIBRARY_PATH=

clean,470uC ::
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o470uC
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.o470uC
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.o470uC
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.s470uC
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.s470uC
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.s470uC

lib/debug/universal_dma_ti_ecpy.a470uC: package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.o470uC package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.o470uC package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.o470uC lib/debug/universal_dma_ti_ecpy.a470uC.mak

clean::
	-$(RM) lib/debug/universal_dma_ti_ecpy.a470uC.mak