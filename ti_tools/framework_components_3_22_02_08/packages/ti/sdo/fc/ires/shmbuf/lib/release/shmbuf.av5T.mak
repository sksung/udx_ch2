#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.GCArmv5T{1,0,4.2,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.ov5T.dep
endif

package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.ov5T: | .interfaces
package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.ov5T: package/package_ti.sdo.fc.ires.shmbuf.c lib/release/shmbuf.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm_v5t_le-gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.ov5T: export LD_LIBRARY_PATH=

package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.sv5T: | .interfaces
package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.sv5T: package/package_ti.sdo.fc.ires.shmbuf.c lib/release/shmbuf.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm_v5t_le-gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.sv5T: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/shmbuf/shmbuf.ov5T.dep
endif

package/lib/lib/release/shmbuf/shmbuf.ov5T: | .interfaces
package/lib/lib/release/shmbuf/shmbuf.ov5T: shmbuf.c lib/release/shmbuf.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm_v5t_le-gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/shmbuf/shmbuf.ov5T: export LD_LIBRARY_PATH=

package/lib/lib/release/shmbuf/shmbuf.sv5T: | .interfaces
package/lib/lib/release/shmbuf/shmbuf.sv5T: shmbuf.c lib/release/shmbuf.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm_v5t_le-gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/shmbuf/shmbuf.sv5T: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/shmbuf/shmbuf_params.ov5T.dep
endif

package/lib/lib/release/shmbuf/shmbuf_params.ov5T: | .interfaces
package/lib/lib/release/shmbuf/shmbuf_params.ov5T: shmbuf_params.c lib/release/shmbuf.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm_v5t_le-gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/shmbuf/shmbuf_params.ov5T: export LD_LIBRARY_PATH=

package/lib/lib/release/shmbuf/shmbuf_params.sv5T: | .interfaces
package/lib/lib/release/shmbuf/shmbuf_params.sv5T: shmbuf_params.c lib/release/shmbuf.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm_v5t_le-gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/shmbuf/shmbuf_params.sv5T: export LD_LIBRARY_PATH=

clean,v5T ::
	-$(RM) package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.ov5T
	-$(RM) package/lib/lib/release/shmbuf/shmbuf.ov5T
	-$(RM) package/lib/lib/release/shmbuf/shmbuf_params.ov5T
	-$(RM) package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.sv5T
	-$(RM) package/lib/lib/release/shmbuf/shmbuf.sv5T
	-$(RM) package/lib/lib/release/shmbuf/shmbuf_params.sv5T

lib/release/shmbuf.av5T: package/lib/lib/release/shmbuf/package/package_ti.sdo.fc.ires.shmbuf.ov5T package/lib/lib/release/shmbuf/shmbuf.ov5T package/lib/lib/release/shmbuf/shmbuf_params.ov5T lib/release/shmbuf.av5T.mak

clean::
	-$(RM) lib/release/shmbuf.av5T.mak
