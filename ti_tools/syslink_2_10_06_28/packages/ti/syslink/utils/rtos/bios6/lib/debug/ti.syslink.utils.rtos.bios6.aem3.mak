#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.M3{1,0,4.9,5
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.oem3.dep
endif

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.oem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.oem3: package/package_ti.syslink.utils.rtos.bios6.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.oem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.sem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.sem3: package/package_ti.syslink.utils.rtos.bios6.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.sem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.oem3.dep
endif

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.oem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.oem3: ../osal/bios6/OsalPrint.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.oem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.sem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.sem3: ../osal/bios6/OsalPrint.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.sem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.oem3.dep
endif

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.oem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.oem3: ../osal/bios6/OsalKfile.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.oem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.sem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.sem3: ../osal/bios6/OsalKfile.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.sem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.oem3.dep
endif

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.oem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.oem3: ../osal/bios6/MemoryOS.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.oem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.sem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.sem3: ../osal/bios6/MemoryOS.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.sem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.oem3.dep
endif

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.oem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.oem3: ../../common/Trace.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.oem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.sem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.sem3: ../../common/Trace.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.sem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.oem3.dep
endif

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.oem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.oem3: ../../common/Cfg.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.oem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.sem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.sem3: ../../common/Cfg.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.sem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.oem3.dep
endif

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.oem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.oem3: TraceDrv.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6 -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.oem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.sem3: | .interfaces
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.sem3: TraceDrv.c lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/ti.syslink.utils.rtos.bios6 -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms  -DOS_DSPBIOS -g --gcc -s -DSYSLINK_BUILD_RTOS -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_5 --symdebug:dwarf  -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/inc/knl -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils -I/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6 -fr=./package/lib/lib/debug/ti.syslink.utils.rtos.bios6
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.sem3: export C_DIR=
package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 ::
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.oem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.oem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.oem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.oem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.oem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.oem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.oem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.sem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.sem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.sem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.sem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.sem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.sem3
	-$(RM) package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.sem3

lib/debug/ti.syslink.utils.rtos.bios6.aem3: package/lib/lib/debug/ti.syslink.utils.rtos.bios6/package/package_ti.syslink.utils.rtos.bios6.oem3 package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalPrint.oem3 package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/OsalKfile.oem3 package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../osal/bios6/MemoryOS.oem3 package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Trace.oem3 package/lib/lib/debug/ti.syslink.utils.rtos.bios6/../../common/Cfg.oem3 package/lib/lib/debug/ti.syslink.utils.rtos.bios6/TraceDrv.oem3 lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak

clean::
	-$(RM) lib/debug/ti.syslink.utils.rtos.bios6.aem3.mak
