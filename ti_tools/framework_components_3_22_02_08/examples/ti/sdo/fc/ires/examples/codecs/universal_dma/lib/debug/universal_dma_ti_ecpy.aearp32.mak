#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.arp32.ARP32{1,0,1.0,0,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oearp32.dep
endif

package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oearp32: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oearp32: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/debug/universal_dma_ti_ecpy.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c  -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy/package -fr=./package/lib/lib/debug/universal_dma_ti_ecpy/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/universal_dma_ti_ecpy/package -s oearp32 $< -C   -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy/package -fr=./package/lib/lib/debug/universal_dma_ti_ecpy/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oearp32: export C_DIR=
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oearp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.searp32: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.searp32: package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.c lib/debug/universal_dma_ti_ecpy.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 -n $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy/package -fr=./package/lib/lib/debug/universal_dma_ti_ecpy/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/universal_dma_ti_ecpy/package -s oearp32 $< -C  -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy/package -fr=./package/lib/lib/debug/universal_dma_ti_ecpy/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.searp32: export C_DIR=
package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.searp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.oearp32.dep
endif

package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.oearp32: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.oearp32: universal_dma_ti.c lib/debug/universal_dma_ti_ecpy.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c  -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy -fr=./package/lib/lib/debug/universal_dma_ti_ecpy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/universal_dma_ti_ecpy -s oearp32 $< -C   -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy -fr=./package/lib/lib/debug/universal_dma_ti_ecpy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.oearp32: export C_DIR=
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.oearp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.searp32: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.searp32: universal_dma_ti.c lib/debug/universal_dma_ti_ecpy.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 -n $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy -fr=./package/lib/lib/debug/universal_dma_ti_ecpy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/universal_dma_ti_ecpy -s oearp32 $< -C  -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy -fr=./package/lib/lib/debug/universal_dma_ti_ecpy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.searp32: export C_DIR=
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.searp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.oearp32.dep
endif

package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.oearp32: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.oearp32: universal_dma_ti_ires.c lib/debug/universal_dma_ti_ecpy.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c  -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy -fr=./package/lib/lib/debug/universal_dma_ti_ecpy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/universal_dma_ti_ecpy -s oearp32 $< -C   -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy -fr=./package/lib/lib/debug/universal_dma_ti_ecpy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.oearp32: export C_DIR=
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.oearp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.searp32: | .interfaces
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.searp32: universal_dma_ti_ires.c lib/debug/universal_dma_ti_ecpy.aearp32.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clearp32 -n $< ...
	$(ti.targets.elf.arp32.ARP32.rootDir)/bin/cl-arp32 -c -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy -fr=./package/lib/lib/debug/universal_dma_ti_ecpy -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/universal_dma_ti_ecpy -s oearp32 $< -C  -n -s --symdebug:none -qq -pdsw225 --silicon_version=v210 -eo.oearp32 -ea.searp32  -D_DEBUG_=1 -DDBC_ASSERTS=1  -DXDAIS_TRACE_ASSERT=0 -DXDAIS_TRACE_OUT=0  -Dxdc_target_name__=ARP32 -Dxdc_target_types__=ti/targets/elf/arp32/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_1_0_0_1 --symdebug:dwarf --gen_func_subsections   $(XDCINCS) -I$(ti.targets.elf.arp32.ARP32.rootDir)/include -fs=./package/lib/lib/debug/universal_dma_ti_ecpy -fr=./package/lib/lib/debug/universal_dma_ti_ecpy
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.searp32: export C_DIR=
package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.searp32: PATH:=$(ti.targets.elf.arp32.ARP32.rootDir)/bin/:$(PATH)

clean,earp32 ::
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oearp32
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.oearp32
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.oearp32
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.searp32
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.searp32
	-$(RM) package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.searp32

lib/debug/universal_dma_ti_ecpy.aearp32: package/lib/lib/debug/universal_dma_ti_ecpy/package/package_ti.sdo.fc.ires.examples.codecs.universal_dma.oearp32 package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti.oearp32 package/lib/lib/debug/universal_dma_ti_ecpy/universal_dma_ti_ires.oearp32 lib/debug/universal_dma_ti_ecpy.aearp32.mak

clean::
	-$(RM) lib/debug/universal_dma_ti_ecpy.aearp32.mak
