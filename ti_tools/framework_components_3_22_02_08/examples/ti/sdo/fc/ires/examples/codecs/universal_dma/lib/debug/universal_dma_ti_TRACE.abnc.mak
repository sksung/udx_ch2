#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = google.targets.arm.Bionic{1,0,4.4,3
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.obnc.dep
endif

package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.obnc: | .interfaces
package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.obnc: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/debug/universal_dma_ti_TRACE.abnc.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clbnc $< ...
	/db/rtree/install/trees/products/xdcprod/xdcprod-p43/product/Linux/xdctools_3_23_01_43/packages/google/targets/runh -h sanbud01.sanb.design.ti.com $(google.targets.arm.Bionic.rootDir)/bin/arm-eabi-gcc -c  -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/arch-arm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libstdc++/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/common -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/arch-arm -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include/arch/arm  $(XDCINCS)  -o $@ $<
	$(MKDEP) -o $@.dep -p package/lib/lib/debug/universal_dma_ti_TRACE/package/ -s obnc $< -C -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/arch-arm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libstdc++/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/common -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/arch-arm -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include/arch/arm  $(XDCINCS) 
	ls `dirname $@` > /dev/null
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.obnc: export LD_LIBRARY_PATH=

package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sbnc: | .interfaces
package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sbnc: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/debug/universal_dma_ti_TRACE.abnc.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clbnc -S $< ...
	/db/rtree/install/trees/products/xdcprod/xdcprod-p43/product/Linux/xdctools_3_23_01_43/packages/google/targets/runh -h sanbud01.sanb.design.ti.com $(google.targets.arm.Bionic.rootDir)/bin/arm-eabi-gcc -c  -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g  $(XDCINCS)  -o $@ $<
	$(MKDEP) -o $@.dep -p package/lib/lib/debug/universal_dma_ti_TRACE/package/ -s obnc $< -C -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g  $(XDCINCS) 
	ls `dirname $@` > /dev/null
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sbnc: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.obnc.dep
endif

package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.obnc: | .interfaces
package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.obnc: universal_dma_ti.c lib/debug/universal_dma_ti_TRACE.abnc.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clbnc $< ...
	/db/rtree/install/trees/products/xdcprod/xdcprod-p43/product/Linux/xdctools_3_23_01_43/packages/google/targets/runh -h sanbud01.sanb.design.ti.com $(google.targets.arm.Bionic.rootDir)/bin/arm-eabi-gcc -c  -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/arch-arm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libstdc++/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/common -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/arch-arm -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include/arch/arm  $(XDCINCS)  -o $@ $<
	$(MKDEP) -o $@.dep -p package/lib/lib/debug/universal_dma_ti_TRACE/ -s obnc $< -C -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/arch-arm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libstdc++/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/common -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/arch-arm -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include/arch/arm  $(XDCINCS) 
	ls `dirname $@` > /dev/null
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.obnc: export LD_LIBRARY_PATH=

package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.sbnc: | .interfaces
package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.sbnc: universal_dma_ti.c lib/debug/universal_dma_ti_TRACE.abnc.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clbnc -S $< ...
	/db/rtree/install/trees/products/xdcprod/xdcprod-p43/product/Linux/xdctools_3_23_01_43/packages/google/targets/runh -h sanbud01.sanb.design.ti.com $(google.targets.arm.Bionic.rootDir)/bin/arm-eabi-gcc -c  -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g  $(XDCINCS)  -o $@ $<
	$(MKDEP) -o $@.dep -p package/lib/lib/debug/universal_dma_ti_TRACE/ -s obnc $< -C -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g  $(XDCINCS) 
	ls `dirname $@` > /dev/null
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.sbnc: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.obnc.dep
endif

package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.obnc: | .interfaces
package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.obnc: universal_dma_ti_ires.c lib/debug/universal_dma_ti_TRACE.abnc.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clbnc $< ...
	/db/rtree/install/trees/products/xdcprod/xdcprod-p43/product/Linux/xdctools_3_23_01_43/packages/google/targets/runh -h sanbud01.sanb.design.ti.com $(google.targets.arm.Bionic.rootDir)/bin/arm-eabi-gcc -c  -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/arch-arm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libstdc++/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/common -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/arch-arm -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include/arch/arm  $(XDCINCS)  -o $@ $<
	$(MKDEP) -o $@.dep -p package/lib/lib/debug/universal_dma_ti_TRACE/ -s obnc $< -C -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/arch-arm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libstdc++/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/common -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libc/kernel/arch-arm -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include -I/db/toolsrc/library/tools/vendors/android/rowboat/ti814x/20111011/bionic/libm/include/arch/arm  $(XDCINCS) 
	ls `dirname $@` > /dev/null
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.obnc: export LD_LIBRARY_PATH=

package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.sbnc: | .interfaces
package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.sbnc: universal_dma_ti_ires.c lib/debug/universal_dma_ti_TRACE.abnc.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clbnc -S $< ...
	/db/rtree/install/trees/products/xdcprod/xdcprod-p43/product/Linux/xdctools_3_23_01_43/packages/google/targets/runh -h sanbud01.sanb.design.ti.com $(google.targets.arm.Bionic.rootDir)/bin/arm-eabi-gcc -c  -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g  $(XDCINCS)  -o $@ $<
	$(MKDEP) -o $@.dep -p package/lib/lib/debug/universal_dma_ti_TRACE/ -s obnc $< -C -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -fno-short-enums  -Dfar=  -D_ANDROID_ -D_DEBUG_=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK -DCUSTOM_EDMAXFERUTIL  -Dxdc_target_name__=Bionic -Dxdc_target_types__=google/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_4_3 -g  $(XDCINCS) 
	ls `dirname $@` > /dev/null
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.sbnc: export LD_LIBRARY_PATH=

clean,bnc ::
	-$(RM) package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.obnc
	-$(RM) package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.obnc
	-$(RM) package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.obnc
	-$(RM) package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sbnc
	-$(RM) package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.sbnc
	-$(RM) package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.sbnc

lib/debug/universal_dma_ti_TRACE.abnc: package/lib/lib/debug/universal_dma_ti_TRACE/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.obnc package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti.obnc package/lib/lib/debug/universal_dma_ti_TRACE/universal_dma_ti_ires.obnc lib/debug/universal_dma_ti_TRACE.abnc.mak

clean::
	-$(RM) lib/debug/universal_dma_ti_TRACE.abnc.mak
