#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.M3{1,0,4.9,5
#
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.oem3.dep
endif

package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.oem3: | .interfaces
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.oem3: package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.c package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 -ms --fp_mode=strict --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS --embed_inline_assembly -D_DEBUG_=1  -Dxdc_cfg__header__='ti/syslink/samples/rtos/messageQ/package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.h'  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -DSYSLINK_PLATFORM_TI81XX   $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug -fr=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug -s oem3 $< -C   -qq -pdsw225 -ms --fp_mode=strict --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS --embed_inline_assembly -D_DEBUG_=1  -Dxdc_cfg__header__='ti/syslink/samples/rtos/messageQ/package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.h'  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -DSYSLINK_PLATFORM_TI81XX   $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug -fr=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.oem3: export C_DIR=
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.sem3: | .interfaces
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.sem3: package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.c package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1  -Dxdc_cfg__header__='ti/syslink/samples/rtos/messageQ/package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.h'  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -DSYSLINK_PLATFORM_TI81XX   $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug -fr=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1  -Dxdc_cfg__header__='ti/syslink/samples/rtos/messageQ/package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.h'  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -DSYSLINK_PLATFORM_TI81XX   $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug -fr=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.sem3: export C_DIR=
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 ::
	-$(RM) package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.oem3
	-$(RM) package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.sem3

ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3.pem3: package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.oem3 package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.mak

clean::
	-$(RM) package/cfg/ti_syslink_samples_rtos_platforms_ti814x_videom3/debug/messageq_ti81xx_videom3_pem3.mak
