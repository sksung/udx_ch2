#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.M3{1,0,4.9,0
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oem3.dep
endif

package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oem3: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oem3: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/release/universal_dma_ti_TRACE_ecpy.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oem3: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sem3: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sem3: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/release/universal_dma_ti_TRACE_ecpy.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sem3: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.oem3.dep
endif

package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.oem3: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.oem3: universal_dma_ti.c lib/release/universal_dma_ti_TRACE_ecpy.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE_ecpy -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.oem3: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.sem3: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.sem3: universal_dma_ti.c lib/release/universal_dma_ti_TRACE_ecpy.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE_ecpy -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.sem3: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.oem3.dep
endif

package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.oem3: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.oem3: universal_dma_ti_ires.c lib/release/universal_dma_ti_TRACE_ecpy.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE_ecpy -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.oem3: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.sem3: | .interfaces
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.sem3: universal_dma_ti_ires.c lib/release/universal_dma_ti_TRACE_ecpy.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/release/universal_dma_ti_TRACE_ecpy -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -pdr -pden -pds=880 -pds=238 -pds=452 -pds=195  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=1 -DXDAIS_TRACE_OUT=1 -DDMACHECK  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_0 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy -fr=./package/lib/lib/release/universal_dma_ti_TRACE_ecpy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.sem3: export C_DIR=
package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 ::
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oem3
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.oem3
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.oem3
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.sem3
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.sem3
	-$(RM) package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.sem3

lib/release/universal_dma_ti_TRACE_ecpy.aem3: package/lib/lib/release/universal_dma_ti_TRACE_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oem3 package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti.oem3 package/lib/lib/release/universal_dma_ti_TRACE_ecpy/universal_dma_ti_ires.oem3 lib/release/universal_dma_ti_TRACE_ecpy.aem3.mak

clean::
	-$(RM) lib/release/universal_dma_ti_TRACE_ecpy.aem3.mak
