cmd_arch/arm/lib/ashrdi3.o := /home/sksung/work/udx/ch2/packages/../ti_tools/linux_devkit/bin/arm-arago-linux-gnueabi-gcc -Wp,-MD,arch/arm/lib/.ashrdi3.o.d  -nostdinc -isystem /home/sksung/work/udx/ch2/ti_tools/linux_devkit/bin/../lib/gcc/arm-arago-linux-gnueabi/4.5.3/include -I/home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-omap2/include -Iarch/arm/plat-omap/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float        -c -o arch/arm/lib/ashrdi3.o arch/arm/lib/ashrdi3.S

deps_arch/arm/lib/ashrdi3.o := \
  arch/arm/lib/ashrdi3.S \
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

arch/arm/lib/ashrdi3.o: $(deps_arch/arm/lib/ashrdi3.o)

$(deps_arch/arm/lib/ashrdi3.o):
