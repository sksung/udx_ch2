#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C674{1,0,7.3,5
#
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.oe674.dep
endif

package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.oe674: | .interfaces
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.oe674: RingIOApp.c package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp.xe674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo --gcc -DSYSLINK_BUILD_RTOS  -D_DEBUG_=1  -Dxdc_cfg__header__='ti/syslink/samples/rtos/ringIO/package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp_pe674.h'  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_5 --symdebug:dwarf  -DOS_DSPBIOS -DSYSLINK_PLATFORM_TI81XX    $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp -fr=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo --gcc -DSYSLINK_BUILD_RTOS  -D_DEBUG_=1  -Dxdc_cfg__header__='ti/syslink/samples/rtos/ringIO/package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp_pe674.h'  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_5 --symdebug:dwarf  -DOS_DSPBIOS -DSYSLINK_PLATFORM_TI81XX    $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp -fr=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.oe674: export C_DIR=
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.se674: | .interfaces
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.se674: RingIOApp.c package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp.xe674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo --gcc -DSYSLINK_BUILD_RTOS  -D_DEBUG_=1  -Dxdc_cfg__header__='ti/syslink/samples/rtos/ringIO/package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp_pe674.h'  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_5 --symdebug:dwarf  -DOS_DSPBIOS -DSYSLINK_PLATFORM_TI81XX    $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp -fr=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp -fc $<
	$(MKDEP) -a $@.dep -p package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -mi10 -mo --gcc -DSYSLINK_BUILD_RTOS  -D_DEBUG_=1  -Dxdc_cfg__header__='ti/syslink/samples/rtos/ringIO/package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp_pe674.h'  -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_5 --symdebug:dwarf  -DOS_DSPBIOS -DSYSLINK_PLATFORM_TI81XX    $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp -fr=./package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.se674: export C_DIR=
package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 ::
	-$(RM) package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.oe674
	-$(RM) package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.se674

ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp.xe674: package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp/RingIOApp.oe674 package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp.xe674.mak

clean::
	-$(RM) package/cfg/ti_syslink_samples_rtos_platforms_ti814x_dsp/debug/ringio_ti81xx_dsp.xe674.mak
