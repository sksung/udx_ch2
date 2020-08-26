cmd_arch/arm/mach-omap2/sleep814x.o := /home/sksung/work/udx/ch2/packages/../ti_tools/linux_devkit/bin/arm-arago-linux-gnueabi-gcc -Wp,-MD,arch/arm/mach-omap2/.sleep814x.o.d  -nostdinc -isystem /home/sksung/work/udx/ch2/ti_tools/linux_devkit/bin/../lib/gcc/arm-arago-linux-gnueabi/4.5.3/include -I/home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-omap2/include -Iarch/arm/plat-omap/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float     -Wa,-march=armv7-a   -c -o arch/arm/mach-omap2/sleep814x.o arch/arm/mach-omap2/sleep814x.S

deps_arch/arm/mach-omap2/sleep814x.o := \
  arch/arm/mach-omap2/sleep814x.S \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/linkage.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/smp.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/hwcap.h \
  arch/arm/plat-omap/include/plat/sram.h \
    $(wildcard include/config/pm.h) \
  arch/arm/plat-omap/include/plat/ti81xx.h \
  arch/arm/mach-omap2/cm2xxx_3xxx.h \
  arch/arm/mach-omap2/prcm-common.h \
  arch/arm/mach-omap2/prm2xxx_3xxx.h \
    $(wildcard include/config/offset.h) \
    $(wildcard include/config/arch/omap4.h) \
    $(wildcard include/config/arch/omap2.h) \
    $(wildcard include/config/arch/omap3.h) \
    $(wildcard include/config/arch/ti816x.h) \
  arch/arm/mach-omap2/prm.h \
  arch/arm/mach-omap2/cm-regbits-81xx.h \
  arch/arm/mach-omap2/cm.h \
  arch/arm/mach-omap2/cm81xx.h \
    $(wildcard include/config/arch/ti814x.h) \

arch/arm/mach-omap2/sleep814x.o: $(deps_arch/arm/mach-omap2/sleep814x.o)

$(deps_arch/arm/mach-omap2/sleep814x.o):
