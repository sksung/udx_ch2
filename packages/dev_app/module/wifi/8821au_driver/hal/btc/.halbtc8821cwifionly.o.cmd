cmd_/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821cwifionly.o := /home/sksung/work/udx/ch2/packages/../ti_tools/linux_devkit/bin/arm-arago-linux-gnueabi-gcc -Wp,-MD,/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/.halbtc8821cwifionly.o.d  -nostdinc -isystem /home/sksung/work/udx/ch2/ti_tools/linux_devkit/bin/../lib/gcc/arm-arago-linux-gnueabi/4.5.3/include -I/home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-omap2/include -Iarch/arm/plat-omap/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -marm -fno-dwarf2-cfi-asm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -O1 -Wno-unused-variable -Wno-unused-value -Wno-unused-label -Wno-unused-parameter -Wno-unused-function -Wno-unused -I/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include -I/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/phydm -I/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/platform -I/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc -DCONFIG_RTL8821A -DCONFIG_MP_INCLUDED -DCONFIG_BT_COEXIST -DCONFIG_EFUSE_CONFIG_FILE -DEFUSE_MAP_PATH=\"/system/etc/wifi/wifi_efuse_8821au.map\" -DWIFIMAC_PATH=\"/data/wifimac.txt\" -DCONFIG_TRAFFIC_PROTECT -DCONFIG_LOAD_PHY_PARA_FROM_FILE -DREALTEK_CONFIG_PATH=\"\" -DCONFIG_TXPWR_BY_RATE_EN=0 -DCONFIG_TXPWR_LIMIT_EN=0 -DCONFIG_RTW_ADAPTIVITY_EN=0 -DCONFIG_RTW_ADAPTIVITY_MODE=0 -DCONFIG_BR_EXT '-DCONFIG_BR_EXT_BRNAME="'br0'"' -DCONFIG_RTW_NAPI -DCONFIG_RTW_GRO -DCONFIG_RTW_DEBUG -DRTW_LOG_LEVEL=4 -DDM_ODM_SUPPORT_TYPE=0x04 -DCONFIG_LITTLE_ENDIAN  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(halbtc8821cwifionly)"  -D"KBUILD_MODNAME=KBUILD_STR(8821au)" -c -o /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/.tmp_halbtc8821cwifionly.o /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821cwifionly.c

deps_/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821cwifionly.o := \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821cwifionly.c \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/mp_precomp.h \
    $(wildcard include/config/bt/coexist.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/drv_types.h \
    $(wildcard include/config/arp/keep/alive.h) \
    $(wildcard include/config/80211n/ht.h) \
    $(wildcard include/config/80211ac/vht.h) \
    $(wildcard include/config/intel/widi.h) \
    $(wildcard include/config/beamforming.h) \
    $(wildcard include/config/prealloc/rx/skb/buffer.h) \
    $(wildcard include/config/tdls.h) \
    $(wildcard include/config/wapi/support.h) \
    $(wildcard include/config/drvext.h) \
    $(wildcard include/config/mp/included.h) \
    $(wildcard include/config/br/ext.h) \
    $(wildcard include/config/iol.h) \
    $(wildcard include/config/mcc/mode.h) \
    $(wildcard include/config/1t1r.h) \
    $(wildcard include/config/2t2r.h) \
    $(wildcard include/config/rtw/customer/str.h) \
    $(wildcard include/config/tx/early/mode.h) \
    $(wildcard include/config/adaptor/info/caching/file.h) \
    $(wildcard include/config/layer2/roaming.h) \
    $(wildcard include/config/80211d.h) \
    $(wildcard include/config/special/setting/for/funai/tv.h) \
    $(wildcard include/config/ieee80211/band/5ghz.h) \
    $(wildcard include/config/load/phy/para/from/file.h) \
    $(wildcard include/config/concurrent/mode.h) \
    $(wildcard include/config/auto/chnl/sel/nhm.h) \
    $(wildcard include/config/dfs/master.h) \
    $(wildcard include/config/rtw/napi.h) \
    $(wildcard include/config/rtw/gro.h) \
    $(wildcard include/config/support/trx/shared.h) \
    $(wildcard include/config/sdio/hci.h) \
    $(wildcard include/config/gspi/hci.h) \
    $(wildcard include/config/pci/hci.h) \
    $(wildcard include/config/dbg/counter.h) \
    $(wildcard include/config/iface/number.h) \
    $(wildcard include/config/mbssid/cam.h) \
    $(wildcard include/config/sdio/indirect/access.h) \
    $(wildcard include/config/ap/mode.h) \
    $(wildcard include/config/ioctl/cfg80211.h) \
    $(wildcard include/config/swtimer/based/txbcn.h) \
    $(wildcard include/config/fw/multi/port/support.h) \
    $(wildcard include/config/usb/hci.h) \
    $(wildcard include/config/usb/vendor/req/mutex.h) \
    $(wildcard include/config/usb/vendor/req/buffer/prealloc.h) \
    $(wildcard include/config/intel/proxim.h) \
    $(wildcard include/config/mac/loopback/driver.h) \
    $(wildcard include/config/ieee80211w.h) \
    $(wildcard include/config/p2p.h) \
    $(wildcard include/config/wfd.h) \
    $(wildcard include/config/bt/coexist/socket/trx.h) \
    $(wildcard include/config/gpio/api.h) \
    $(wildcard include/config/autosuspend.h) \
    $(wildcard include/config/tx/amsdu.h) \
    $(wildcard include/config/pno/support.h) \
    $(wildcard include/config/pno/set/debug.h) \
    $(wildcard include/config/wowlan.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/drv_conf.h \
    $(wildcard include/config/rtw/80211r.h) \
    $(wildcard include/config/android.h) \
    $(wildcard include/config/platform/android.h) \
    $(wildcard include/config/validate/ssid.h) \
    $(wildcard include/config/signal/display/dbm.h) \
    $(wildcard include/config/has/earlysuspend.h) \
    $(wildcard include/config/resume/in/workqueue.h) \
    $(wildcard include/config/android/power.h) \
    $(wildcard include/config/wakelock.h) \
    $(wildcard include/config/vendor/req/retry.h) \
    $(wildcard include/config/rtw/hiq/filter.h) \
    $(wildcard include/config/rtw/force/igi/lb.h) \
    $(wildcard include/config/rtw/adaptivity/en.h) \
    $(wildcard include/config/rtw/adaptivity/mode.h) \
    $(wildcard include/config/rtw/adaptivity/dml.h) \
    $(wildcard include/config/rtw/adaptivity/dc/backoff.h) \
    $(wildcard include/config/rtw/adaptivity/th/l2h/ini.h) \
    $(wildcard include/config/rtw/adaptivity/th/edcca/hl/diff.h) \
    $(wildcard include/config/rtw/excl/chs.h) \
    $(wildcard include/config/rtw/dfs/region/domain.h) \
    $(wildcard include/config/txpwr/by/rate/en.h) \
    $(wildcard include/config/txpwr/limit/en.h) \
    $(wildcard include/config/calibrate/tx/power/by/regulatory.h) \
    $(wildcard include/config/calibrate/tx/power/to/max.h) \
    $(wildcard include/config/rtw/rx/ampdu/sz/limit/1ss.h) \
    $(wildcard include/config/rtw/rx/ampdu/sz/limit/2ss.h) \
    $(wildcard include/config/rtw/rx/ampdu/sz/limit/3ss.h) \
    $(wildcard include/config/rtw/rx/ampdu/sz/limit/4ss.h) \
    $(wildcard include/config/rtw/target/tx/pwr/2g/a.h) \
    $(wildcard include/config/rtw/target/tx/pwr/2g/b.h) \
    $(wildcard include/config/rtw/target/tx/pwr/2g/c.h) \
    $(wildcard include/config/rtw/target/tx/pwr/2g/d.h) \
    $(wildcard include/config/rtw/target/tx/pwr/5g/a.h) \
    $(wildcard include/config/rtw/target/tx/pwr/5g/b.h) \
    $(wildcard include/config/rtw/target/tx/pwr/5g/c.h) \
    $(wildcard include/config/rtw/target/tx/pwr/5g/d.h) \
    $(wildcard include/config/rtw/amplifier/type/2g.h) \
    $(wildcard include/config/rtw/amplifier/type/5g.h) \
    $(wildcard include/config/rtw/rfe/type.h) \
    $(wildcard include/config/rtw/glna/type.h) \
    $(wildcard include/config/rtw/pll/ref/clk/sel.h) \
    $(wildcard include/config/mi/with/mbssid/cam.h) \
    $(wildcard include/config/runtime/port/switch.h) \
    $(wildcard include/config/fw/based/bcn.h) \
    $(wildcard include/config/rtl8812a.h) \
    $(wildcard include/config/rtl8821a.h) \
    $(wildcard include/config/rtl8814a.h) \
    $(wildcard include/config/rtl8822b.h) \
    $(wildcard include/config/rtl8821c.h) \
    $(wildcard include/config/wow/pattern/hw/cam.h) \
    $(wildcard include/config/deauth/before/connect.h) \
    $(wildcard include/config/wext/dont/join/byssid.h) \
    $(wildcard include/config/doscan/in/busytraffic.h) \
    $(wildcard include/config/rtw/sdio/keep/irq.h) \
    $(wildcard include/config/usb/rx/aggregation.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/autoconf.h \
    $(wildcard include/config/single/img.h) \
    $(wildcard include/config/disable/odm.h) \
    $(wildcard include/config/cfg80211/force/compatible/2/6/37/under.h) \
    $(wildcard include/config/debug/cfg80211.h) \
    $(wildcard include/config/drv/issue/prov/req.h) \
    $(wildcard include/config/set/scan/deny/timer.h) \
    $(wildcard include/config/h2clbk.h) \
    $(wildcard include/config/embedded/fwimg.h) \
    $(wildcard include/config/file/fwimg.h) \
    $(wildcard include/config/xmit/ack.h) \
    $(wildcard include/config/active/keep/alive/check.h) \
    $(wildcard include/config/beamformer/fw/ndpa.h) \
    $(wildcard include/config/phydm/beamforming.h) \
    $(wildcard include/config/recv/reordering/ctrl.h) \
    $(wildcard include/config/tcp/csum/offload/rx.h) \
    $(wildcard include/config/dfs.h) \
    $(wildcard include/config/support/usb/int.h) \
    $(wildcard include/config/usb/interrupt/in/pipe.h) \
    $(wildcard include/config/ips.h) \
    $(wildcard include/config/ips/level/2.h) \
    $(wildcard include/config/ips/check/in/wd.h) \
    $(wildcard include/config/lps.h) \
    $(wildcard include/config/lps/lclk.h) \
    $(wildcard include/config/xmit/thread/mode.h) \
    $(wildcard include/config/antenna/diversity.h) \
    $(wildcard include/config/scan/backop.h) \
    $(wildcard include/config/tsf/reset/offload.h) \
    $(wildcard include/config/interrupt/based/txbcn.h) \
    $(wildcard include/config/interrupt/based/txbcn/early/int.h) \
    $(wildcard include/config/interrupt/based/txbcn/bcn/ok/err.h) \
    $(wildcard include/config/nativeap/mlme.h) \
    $(wildcard include/config/hostapd/mlme.h) \
    $(wildcard include/config/find/best/channel.h) \
    $(wildcard include/config/auto/ap/mode.h) \
    $(wildcard include/config/p2p/remove/group/info.h) \
    $(wildcard include/config/dbg/p2p.h) \
    $(wildcard include/config/p2p/ps.h) \
    $(wildcard include/config/p2p/op/chk/social/ch.h) \
    $(wildcard include/config/cfg80211/onechannel/under/concurrent.h) \
    $(wildcard include/config/p2p/chk/invite/ch/list.h) \
    $(wildcard include/config/p2p/invite/iot.h) \
    $(wildcard include/config/tdls/driver/setup.h) \
    $(wildcard include/config/tdls/autosetup.h) \
    $(wildcard include/config/tdls/autocheckalive.h) \
    $(wildcard include/config/tdls/ch/sw.h) \
    $(wildcard include/config/skb/copy.h) \
    $(wildcard include/config/led.h) \
    $(wildcard include/config/sw/led.h) \
    $(wildcard include/config/led/handled/by/cmd/thread.h) \
    $(wildcard include/config/global/ui/pid.h) \
    $(wildcard include/config/layer2/roaming/resume.h) \
    $(wildcard include/config/long/delay/issue.h) \
    $(wildcard include/config/new/signal/stat/process.h) \
    $(wildcard include/config/background/noise/monitor.h) \
    $(wildcard include/config/tx/mcast2uni.h) \
    $(wildcard include/config/check/ac/lifetime.h) \
    $(wildcard include/config/gtk/ol.h) \
    $(wildcard include/config/gpio/wakeup.h) \
    $(wildcard include/config/minimal/memory/usage.h) \
    $(wildcard include/config/usb/tx/aggregation.h) \
    $(wildcard include/config/reduce/usb/tx/int.h) \
    $(wildcard include/config/easy/replacement.h) \
    $(wildcard include/config/use/usb/buffer/alloc/xx.h) \
    $(wildcard include/config/use/usb/buffer/alloc/tx.h) \
    $(wildcard include/config/use/usb/buffer/alloc/rx.h) \
    $(wildcard include/config/prealloc/recv/skb.h) \
    $(wildcard include/config/fix/nr/bulkin/buffer.h) \
    $(wildcard include/config/usb/vendor/req/buffer/dynamic/allocate.h) \
    $(wildcard include/config/usb/support/async/vdn/req.h) \
    $(wildcard include/config/rx/packet/append/fcs.h) \
    $(wildcard include/config/only/one/out/ep/to/low.h) \
    $(wildcard include/config/out/ep/wifi/mode.h) \
    $(wildcard include/config/adhoc/workaround/setting.h) \
    $(wildcard include/config/mp/iwpriv/support.h) \
    $(wildcard include/config/platform/actions/atm702x.h) \
    $(wildcard include/config/attempt/to/fix/ap/beacon/error.h) \
    $(wildcard include/config/proc/debug.h) \
    $(wildcard include/config/error/detect.h) \
    $(wildcard include/config/error/detect/int.h) \
    $(wildcard include/config/error/reset.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_ic_cfg.h \
    $(wildcard include/config/multidrv.h) \
    $(wildcard include/config/rtl8188e.h) \
    $(wildcard include/config/get/raid/by/drv.h) \
    $(wildcard include/config/fw/c2h/pkt.h) \
    $(wildcard include/config/rtl8192e.h) \
    $(wildcard include/config/rtl8723b.h) \
    $(wildcard include/config/rtl8723d.h) \
    $(wildcard include/config/rtw/mac/hidden/rpt.h) \
    $(wildcard include/config/rtl8703b.h) \
    $(wildcard include/config/rtl8188f.h) \
    $(wildcard include/config/default/patterns/en.h) \
    $(wildcard include/config/ap/port/swap.h) \
    $(wildcard include/config/no/fw.h) \
    $(wildcard include/config/phy/capability/query.h) \
    $(wildcard include/config/support/fifo/dump.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/basic_types.h \
  include/linux/version.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/posix_types.h \
  include/linux/module.h \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/sysfs.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/prefetch.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/processor.h \
    $(wildcard include/config/have/hw/breakpoint.h) \
    $(wildcard include/config/mmu.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/hw_breakpoint.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/hwcap.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/cache.h \
    $(wildcard include/config/arm/l1/cache/shift.h) \
    $(wildcard include/config/aeabi.h) \
  include/linux/stat.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/stat.h \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/numa.h) \
  /home/sksung/work/udx/ch2/ti_tools/linux_devkit/bin/../lib/gcc/arm-arago-linux-gnueabi/4.5.3/include/stdarg.h \
  include/linux/linkage.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/linkage.h \
  include/linux/bitops.h \
    $(wildcard include/config/generic/find/last/bit.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/bitops.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/system.h \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/32v6k.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/irqflags.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  include/asm-generic/cmpxchg-local.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/dynamic_debug.h \
  include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
  include/linux/stringify.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  include/linux/spinlock_types_up.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/rwlock_types.h \
  include/linux/spinlock_up.h \
  include/linux/rwlock.h \
  include/linux/spinlock_api_up.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  include/asm-generic/atomic-long.h \
  include/linux/math64.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/div64.h \
  include/linux/kmod.h \
  include/linux/gfp.h \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/debug/vm.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/arch/populates/node/map.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/wait.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/current.h \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/init.h \
    $(wildcard include/config/hotplug.h) \
  include/linux/nodemask.h \
  include/linux/bitmap.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/string.h \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/generated/bounds.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v3.h) \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/glue.h \
    $(wildcard include/config/cpu/arm610.h) \
    $(wildcard include/config/cpu/arm710.h) \
    $(wildcard include/config/cpu/abrt/lv4t.h) \
    $(wildcard include/config/cpu/abrt/ev4.h) \
    $(wildcard include/config/cpu/abrt/ev4t.h) \
    $(wildcard include/config/cpu/abrt/ev5tj.h) \
    $(wildcard include/config/cpu/abrt/ev5t.h) \
    $(wildcard include/config/cpu/abrt/ev6.h) \
    $(wildcard include/config/cpu/abrt/ev7.h) \
    $(wildcard include/config/cpu/pabrt/legacy.h) \
    $(wildcard include/config/cpu/pabrt/v6.h) \
    $(wildcard include/config/cpu/pabrt/v7.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/arm/patch/phys/virt.h) \
    $(wildcard include/config/arm/patch/phys/virt/16bit.h) \
  include/linux/const.h \
  arch/arm/mach-omap2/include/mach/memory.h \
  arch/arm/plat-omap/include/plat/memory.h \
    $(wildcard include/config/arch/omap1.h) \
    $(wildcard include/config/arch/omap15xx.h) \
    $(wildcard include/config/fb/omap/consistent/dma/size.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/sizes.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  include/asm-generic/getorder.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
  include/linux/notifier.h \
  include/linux/errno.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/srcu.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/pfn.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/percpu.h \
  include/asm-generic/percpu.h \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/topology.h \
  include/asm-generic/topology.h \
  include/linux/mmdebug.h \
    $(wildcard include/config/debug/virtual.h) \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/jiffies.h \
  include/linux/timex.h \
  include/linux/param.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/param.h \
    $(wildcard include/config/hz.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/timex.h \
  arch/arm/mach-omap2/include/mach/timex.h \
  arch/arm/plat-omap/include/plat/timex.h \
    $(wildcard include/config/omap/32k/timer.h) \
    $(wildcard include/config/omap/32k/timer/hz.h) \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/elf.h \
  include/linux/elf-em.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/elf.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/user.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kobject_ns.h \
  include/linux/kref.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  include/linux/tracepoint.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/no/hz.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/preempt/rt.h) \
  include/linux/completion.h \
  include/linux/rcutiny.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/module.h \
    $(wildcard include/config/arm/unwind.h) \
  include/trace/events/module.h \
  include/trace/define_trace.h \
  include/linux/utsname.h \
    $(wildcard include/config/uts/ns.h) \
  include/linux/sched.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/lockup/detector.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/debug/stack/usage.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/mm/owner.h) \
  include/linux/capability.h \
  include/linux/rbtree.h \
  include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/mmu/notifier.h) \
  include/linux/auxvec.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/auxvec.h \
  include/linux/prio_tree.h \
  include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/mmu.h \
    $(wildcard include/config/cpu/has/asid.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/cputime.h \
  include/asm-generic/cputime.h \
  include/linux/sem.h \
  include/linux/ipc.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/ipcbuf.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/sembuf.h \
  include/linux/signal.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/signal.h \
  include/asm-generic/signal-defs.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/sigcontext.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/siginfo.h \
  include/asm-generic/siginfo.h \
  include/linux/path.h \
  include/linux/pid.h \
  include/linux/proportions.h \
  include/linux/percpu_counter.h \
  include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
  include/linux/rculist.h \
  include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  include/linux/resource.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/resource.h \
  include/asm-generic/resource.h \
  include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
  include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  include/linux/latencytop.h \
  include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/security.h) \
  include/linux/key.h \
    $(wildcard include/config/sysctl.h) \
  include/linux/sysctl.h \
  include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  include/linux/aio.h \
  include/linux/aio_abi.h \
  include/linux/uio.h \
  include/linux/nsproxy.h \
    $(wildcard include/config/cgroup/ns.h) \
  include/linux/err.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/osdep_service.h \
    $(wildcard include/config/use/vmalloc.h) \
    $(wildcard include/config/ap/wowlan.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/osdep_service_linux.h \
    $(wildcard include/config/net/radio.h) \
    $(wildcard include/config/wireless/ext.h) \
    $(wildcard include/config/tcp/csum/offload/tx.h) \
    $(wildcard include/config/efuse/config/file.h) \
    $(wildcard include/config/file.h) \
    $(wildcard include/config/usb/suspend.h) \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/slab.h) \
  include/linux/slub_def.h \
    $(wildcard include/config/slub/stats.h) \
    $(wildcard include/config/slub/debug.h) \
  include/linux/kmemleak.h \
    $(wildcard include/config/debug/kmemleak.h) \
  include/trace/events/kmem.h \
  include/trace/events/gfpflags.h \
  include/linux/netdevice.h \
    $(wildcard include/config/dcb.h) \
    $(wildcard include/config/wlan.h) \
    $(wildcard include/config/ax25.h) \
    $(wildcard include/config/mac80211/mesh.h) \
    $(wildcard include/config/tr.h) \
    $(wildcard include/config/net/ipip.h) \
    $(wildcard include/config/net/ipgre.h) \
    $(wildcard include/config/ipv6/sit.h) \
    $(wildcard include/config/ipv6/tunnel.h) \
    $(wildcard include/config/netpoll.h) \
    $(wildcard include/config/rps.h) \
    $(wildcard include/config/net/poll/controller.h) \
    $(wildcard include/config/fcoe.h) \
    $(wildcard include/config/vlan/8021q.h) \
    $(wildcard include/config/net/dsa.h) \
    $(wildcard include/config/net/ns.h) \
    $(wildcard include/config/net/dsa/tag/dsa.h) \
    $(wildcard include/config/net/dsa/tag/trailer.h) \
    $(wildcard include/config/netpoll/trap.h) \
  include/linux/if.h \
  include/linux/socket.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/socket.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/sockios.h \
  include/linux/sockios.h \
  include/linux/hdlc/ioctl.h \
  include/linux/if_ether.h \
  include/linux/skbuff.h \
    $(wildcard include/config/nf/conntrack.h) \
    $(wildcard include/config/bridge/netfilter.h) \
    $(wildcard include/config/xfrm.h) \
    $(wildcard include/config/net/sched.h) \
    $(wildcard include/config/net/cls/act.h) \
    $(wildcard include/config/ipv6/ndisc/nodetype.h) \
    $(wildcard include/config/net/dma.h) \
    $(wildcard include/config/network/secmark.h) \
    $(wildcard include/config/network/phy/timestamping.h) \
  include/linux/kmemcheck.h \
  include/linux/net.h \
  include/linux/random.h \
  include/linux/ioctl.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/ioctl.h \
  include/asm-generic/ioctl.h \
  include/linux/irqnr.h \
  include/linux/fcntl.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/fcntl.h \
  include/asm-generic/fcntl.h \
  include/linux/ratelimit.h \
  include/linux/textsearch.h \
  include/net/checksum.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/uaccess.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/checksum.h \
  include/linux/in6.h \
  include/linux/dmaengine.h \
    $(wildcard include/config/async/tx/enable/channel/switch.h) \
    $(wildcard include/config/dma/engine.h) \
    $(wildcard include/config/async/tx/dma.h) \
  include/linux/device.h \
    $(wildcard include/config/of.h) \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  include/linux/ioport.h \
  include/linux/klist.h \
  include/linux/pm.h \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/pm/runtime.h) \
    $(wildcard include/config/pm/ops.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/device.h \
    $(wildcard include/config/dmabounce.h) \
  include/linux/pm_wakeup.h \
  include/linux/dma-mapping.h \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/have/dma/attrs.h) \
    $(wildcard include/config/need/dma/map/state.h) \
  include/linux/dma-attrs.h \
  include/linux/bug.h \
  include/linux/scatterlist.h \
    $(wildcard include/config/debug/sg.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/scatterlist.h \
  include/asm-generic/scatterlist.h \
    $(wildcard include/config/need/sg/dma/length.h) \
  include/linux/mm.h \
    $(wildcard include/config/ksm.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/memory/failure.h) \
  include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  include/linux/range.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/pgtable.h \
    $(wildcard include/config/highpte.h) \
  include/asm-generic/4level-fixup.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/proc-fns.h \
    $(wildcard include/config/cpu/arm7tdmi.h) \
    $(wildcard include/config/cpu/arm720t.h) \
    $(wildcard include/config/cpu/arm740t.h) \
    $(wildcard include/config/cpu/arm9tdmi.h) \
    $(wildcard include/config/cpu/arm920t.h) \
    $(wildcard include/config/cpu/arm922t.h) \
    $(wildcard include/config/cpu/arm925t.h) \
    $(wildcard include/config/cpu/arm926t.h) \
    $(wildcard include/config/cpu/arm940t.h) \
    $(wildcard include/config/cpu/arm946e.h) \
    $(wildcard include/config/cpu/arm1020.h) \
    $(wildcard include/config/cpu/arm1020e.h) \
    $(wildcard include/config/cpu/arm1022.h) \
    $(wildcard include/config/cpu/arm1026.h) \
    $(wildcard include/config/cpu/mohawk.h) \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/cpu/v6.h) \
    $(wildcard include/config/cpu/v7.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/cpu-single.h \
  arch/arm/mach-omap2/include/mach/vmalloc.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/pgtable-hwdef.h \
  include/asm-generic/pgtable.h \
  include/linux/page-flags.h \
    $(wildcard include/config/pageflags/extended.h) \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/s390.h) \
  include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/io.h \
  arch/arm/mach-omap2/include/mach/io.h \
  arch/arm/plat-omap/include/plat/io.h \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/arch/omap2420.h) \
    $(wildcard include/config/arch/omap2430.h) \
    $(wildcard include/config/arch/omap3.h) \
    $(wildcard include/config/arch/omap4.h) \
    $(wildcard include/config/arch/ti81xx.h) \
  arch/arm/mach-omap2/include/mach/hardware.h \
  arch/arm/plat-omap/include/plat/hardware.h \
    $(wildcard include/config/reg/base.h) \
  arch/arm/plat-omap/include/plat/cpu.h \
    $(wildcard include/config/common/ud/feature.h) \
    $(wildcard include/config/arch/omap730.h) \
    $(wildcard include/config/arch/omap850.h) \
    $(wildcard include/config/arch/omap16xx.h) \
    $(wildcard include/config/arch/omap2.h) \
    $(wildcard include/config/arch/omap3430.h) \
  arch/arm/plat-omap/include/plat/multi.h \
    $(wildcard include/config/arch/omap2plus.h) \
  arch/arm/plat-omap/include/plat/serial.h \
  arch/arm/plat-omap/include/plat/omap7xx.h \
    $(wildcard include/config/base.h) \
  arch/arm/plat-omap/include/plat/omap1510.h \
  arch/arm/plat-omap/include/plat/omap16xx.h \
  arch/arm/plat-omap/include/plat/omap24xx.h \
  arch/arm/plat-omap/include/plat/omap34xx.h \
  arch/arm/plat-omap/include/plat/omap44xx.h \
  arch/arm/plat-omap/include/plat/ti81xx.h \
  arch/arm/mach-omap2/include/mach/pci.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/dma-mapping.h \
  include/asm-generic/dma-coherent.h \
    $(wildcard include/config/have/generic/dma/coherent.h) \
  include/linux/if_packet.h \
  include/linux/if_link.h \
  include/linux/netlink.h \
  include/linux/pm_qos_params.h \
  include/linux/miscdevice.h \
  include/linux/major.h \
  include/linux/delay.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/delay.h \
  include/linux/ethtool.h \
  include/linux/compat.h \
  include/net/net_namespace.h \
    $(wildcard include/config/ipv6.h) \
    $(wildcard include/config/ip/dccp.h) \
    $(wildcard include/config/netfilter.h) \
    $(wildcard include/config/wext/core.h) \
    $(wildcard include/config/net.h) \
  include/net/netns/core.h \
  include/net/netns/mib.h \
    $(wildcard include/config/xfrm/statistics.h) \
  include/net/snmp.h \
  include/linux/snmp.h \
  include/linux/u64_stats_sync.h \
  include/net/netns/unix.h \
  include/net/netns/packet.h \
  include/net/netns/ipv4.h \
    $(wildcard include/config/ip/multiple/tables.h) \
    $(wildcard include/config/ip/mroute.h) \
    $(wildcard include/config/ip/mroute/multiple/tables.h) \
  include/net/inet_frag.h \
  include/net/netns/ipv6.h \
    $(wildcard include/config/ipv6/multiple/tables.h) \
    $(wildcard include/config/ipv6/mroute.h) \
    $(wildcard include/config/ipv6/mroute/multiple/tables.h) \
  include/net/dst_ops.h \
  include/net/netns/dccp.h \
  include/net/netns/x_tables.h \
    $(wildcard include/config/bridge/nf/ebtables.h) \
  include/linux/netfilter.h \
    $(wildcard include/config/netfilter/debug.h) \
    $(wildcard include/config/nf/nat/needed.h) \
  include/linux/in.h \
  include/net/netns/xfrm.h \
  include/linux/xfrm.h \
  include/linux/seq_file_net.h \
  include/linux/seq_file.h \
  include/net/dsa.h \
  include/linux/interrupt.h \
    $(wildcard include/config/generic/irq/probe.h) \
  include/linux/irqreturn.h \
  include/linux/hardirq.h \
    $(wildcard include/config/bkl.h) \
  include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/hardirq.h \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/irq.h \
  arch/arm/mach-omap2/include/mach/irqs.h \
  arch/arm/plat-omap/include/plat/irqs.h \
    $(wildcard include/config/mach/omap/innovator.h) \
    $(wildcard include/config/twl4030/core.h) \
    $(wildcard include/config/gpio/twl4030.h) \
    $(wildcard include/config/pci/msi.h) \
    $(wildcard include/config/fiq.h) \
  arch/arm/plat-omap/include/plat/irqs-44xx.h \
  arch/arm/plat-omap/include/plat/irqs-ti81xx.h \
  include/linux/irq_cpustat.h \
  include/trace/events/irq.h \
  include/linux/circ_buf.h \
  include/linux/semaphore.h \
  include/linux/etherdevice.h \
    $(wildcard include/config/have/efficient/unaligned/access.h) \
  /home/sksung/work/udx/ch2/packages/psp/kernel/arch/arm/include/asm/unaligned.h \
  include/linux/unaligned/le_byteshift.h \
  include/linux/unaligned/be_byteshift.h \
  include/linux/unaligned/generic.h \
  include/linux/wireless.h \
  include/net/iw_handler.h \
    $(wildcard include/config/wext/priv.h) \
  include/linux/if_arp.h \
  include/linux/rtnetlink.h \
  include/linux/if_addr.h \
  include/linux/neighbour.h \
  include/linux/ip.h \
  include/linux/kthread.h \
  include/linux/vmalloc.h \
  include/linux/limits.h \
  include/net/ieee80211_radiotap.h \
  include/linux/ieee80211.h \
  include/linux/fs.h \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/debug/writecount.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/fs/xip.h) \
    $(wildcard include/config/migration.h) \
  include/linux/blk_types.h \
    $(wildcard include/config/blk/dev/integrity.h) \
  include/linux/kdev_t.h \
  include/linux/dcache.h \
  include/linux/radix-tree.h \
  include/linux/fiemap.h \
  include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  include/linux/dqblk_xfs.h \
  include/linux/dqblk_v1.h \
  include/linux/dqblk_v2.h \
  include/linux/dqblk_qtree.h \
  include/linux/nfs_fs_i.h \
  include/linux/nfs.h \
  include/linux/sunrpc/msg_prot.h \
  include/linux/inet.h \
  include/linux/usb.h \
    $(wildcard include/config/usb/devicefs.h) \
    $(wildcard include/config/usb/mon.h) \
    $(wildcard include/config/usb/device/class.h) \
  include/linux/mod_devicetable.h \
  include/linux/usb/ch9.h \
    $(wildcard include/config/size.h) \
    $(wildcard include/config/att/one.h) \
    $(wildcard include/config/att/selfpower.h) \
    $(wildcard include/config/att/wakeup.h) \
    $(wildcard include/config/att/battery.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_byteorder.h \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/platform/mstar389.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/byteorder/little_endian.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/wlan_bssdef.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/wifi.h \
    $(wildcard include/config/append/vendor/ie/enable.h) \
    $(wildcard include/config/rtl8712fw.h) \
    $(wildcard include/config/error.h) \
    $(wildcard include/config/method/flash.h) \
    $(wildcard include/config/method/ethernet.h) \
    $(wildcard include/config/method/label.h) \
    $(wildcard include/config/method/display.h) \
    $(wildcard include/config/method/e/nfc.h) \
    $(wildcard include/config/method/i/nfc.h) \
    $(wildcard include/config/method/nfc.h) \
    $(wildcard include/config/method/pbc.h) \
    $(wildcard include/config/method/keypad.h) \
    $(wildcard include/config/method/vpbc.h) \
    $(wildcard include/config/method/ppbc.h) \
    $(wildcard include/config/method/vdisplay.h) \
    $(wildcard include/config/method/pdisplay.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/ieee80211.h \
    $(wildcard include/config/rtl8711fw.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/drv_types_linux.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_debug.h \
    $(wildcard include/config/rtw/debug.h) \
    $(wildcard include/config/p2p/wowlan.h) \
    $(wildcard include/config/power/saving.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_rf.h \
    $(wildcard include/config/.h) \
    $(wildcard include/config/1t.h) \
    $(wildcard include/config/2t.h) \
    $(wildcard include/config/1r.h) \
    $(wildcard include/config/2r.h) \
    $(wildcard include/config/1t2r.h) \
    $(wildcard include/config/turbo.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_ht.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_vht.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_cmd.h \
    $(wildcard include/config/event/thread/mode.h) \
    $(wildcard include/config/fw/c2h/reg.h) \
    $(wildcard include/config/c2h/wk.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/cmd_osdep.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_security.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_xmit.h \
    $(wildcard include/config/tx/aggregation.h) \
    $(wildcard include/config/platform/arm/sunxi.h) \
    $(wildcard include/config/platform/arm/sun6i.h) \
    $(wildcard include/config/platform/arm/sun7i.h) \
    $(wildcard include/config/platform/arm/sun8i.h) \
    $(wildcard include/config/platform/arm/sun50iw1p1.h) \
    $(wildcard include/config/platform/mstar.h) \
    $(wildcard include/config/single/xmit/buf.h) \
    $(wildcard include/config/lps/poff.h) \
    $(wildcard include/config/trx/bd/arch.h) \
    $(wildcard include/config/64bit/dma.h) \
    $(wildcard include/config/sdio/tx/tasklet.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/xmit_osdep.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_recv.h \
    $(wildcard include/config/single/recv/buf.h) \
    $(wildcard include/config/recv/thread/mode.h) \
    $(wildcard include/config/rx/indicate/queue.h) \
    $(wildcard include/config/bsd/rx/use/mbuf.h) \
    $(wildcard include/config/signal/scale/mapping.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_beamforming.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/recv_osdep.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_efuse.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_sreset.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_intf.h \
    $(wildcard include/config/wmmps.h) \
    $(wildcard include/config/lps/pg.h) \
    $(wildcard include/config/lps/lclk/wd/timer.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_com.h \
    $(wildcard include/config/rf/power/trim.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/HalVerDef.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_pg.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_phy.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_phy_reg.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_com_reg.h \
    $(wildcard include/config/usedk.h) \
    $(wildcard include/config/no/usedk.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_com_phycfg.h \
    $(wildcard include/config/phydm/powertrack/by/tssi.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/hal_com_c2h.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_com_h2c.h \
    $(wildcard include/config/ra/dbg/cmd.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_com_led.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/hal_dm.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_qos.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_pwrctrl.h \
    $(wildcard include/config/platform/android/intel/x86.h) \
    $(wildcard include/config/lps/rpwm/timer.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_mlme.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/mlme_osdep.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_io.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_ioctl.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_ioctl_set.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_ioctl_query.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_ioctl_rtl.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/osdep_intf.h \
    $(wildcard include/config/r871x/test.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../os_dep/linux/rtw_proc.h \
  include/linux/proc_fs.h \
    $(wildcard include/config/proc/devicetree.h) \
    $(wildcard include/config/proc/kcore.h) \
  include/linux/magic.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_eeprom.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/sta_info.h \
    $(wildcard include/config/rtw/macaddr/acl.h) \
    $(wildcard include/config/rtw/pre/link/sta.h) \
    $(wildcard include/config/atmel/rc/patch.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_event.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_mlme_ext.h \
    $(wildcard include/config/rtw/wnm.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_mi.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_ap.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_version.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_odm.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_types.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_features.h \
    $(wildcard include/config/psd/tool.h) \
    $(wildcard include/config/phydm/debug/function.h) \
    $(wildcard include/config/phydm/antenna/diversity.h) \
    $(wildcard include/config/s0s1/sw/antenna/diversity.h) \
    $(wildcard include/config/hl/smart/antenna/type1.h) \
    $(wildcard include/config/fat/patch.h) \
    $(wildcard include/config/hl/smart/antenna/type2.h) \
    $(wildcard include/config/dynamic/rx/path.h) \
    $(wildcard include/config/path/diversity.h) \
    $(wildcard include/config/ra/dynamic/rty/limit.h) \
    $(wildcard include/config/ant/detection.h) \
    $(wildcard include/config/ra/fw/dbg/code.h) \
    $(wildcard include/config/phydm/rx/sniffer/parsing.h) \
    $(wildcard include/config/bb/power/saving.h) \
    $(wildcard include/config/bb/txbf/api.h) \
    $(wildcard include/config/disable/phydm/debug/function.h) \
    $(wildcard include/config/ra/dynamic/rate/id.h) \
    $(wildcard include/config/rtl/8881a/ant/switch.h) \
    $(wildcard include/config/slot/0/ant/switch.h) \
    $(wildcard include/config/slot/1/ant/switch.h) \
    $(wildcard include/config/no/2g/diversity.h) \
    $(wildcard include/config/2g5g/cg/trx/diversity/8881a.h) \
    $(wildcard include/config/2g/cgcs/rx/diversity.h) \
    $(wildcard include/config/2g/cg/trx/diversity.h) \
    $(wildcard include/config/2g/cg/smart/ant/diversity.h) \
    $(wildcard include/config/no/5g/diversity/8881a.h) \
    $(wildcard include/config/no/5g/diversity.h) \
    $(wildcard include/config/5g/cgcs/rx/diversity/8881a.h) \
    $(wildcard include/config/5g/cgcs/rx/diversity.h) \
    $(wildcard include/config/5g/cg/trx/diversity/8881a.h) \
    $(wildcard include/config/5g/cg/trx/diversity.h) \
    $(wildcard include/config/2g5g/cg/trx/diversity.h) \
    $(wildcard include/config/5g/cg/smart/ant/diversity.h) \
    $(wildcard include/config/not/support/antdiv.h) \
    $(wildcard include/config/2g/support/antdiv.h) \
    $(wildcard include/config/5g/support/antdiv.h) \
    $(wildcard include/config/2g5g/support/antdiv.h) \
    $(wildcard include/config/phydm/dfs/master.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_p2p.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_mp.h \
    $(wildcard include/config/txt.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_br_ext.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/ip.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/if_ether.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/ethernet.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/circ_buf.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_android.h \
    $(wildcard include/config/platform/intel/byt.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_btcoex_wifionly.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtw_btcoex.h \
    $(wildcard include/config/rf4ce/coexist.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/usb_osintf.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/usb_vendor_req.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/usb_ops.h \
    $(wildcard include/config/rtl8814.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/usb_ops_linux.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/usb_hal.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_data.h \
    $(wildcard include/config/ant/a.h) \
    $(wildcard include/config/ant/b.h) \
    $(wildcard include/config/pmpd/ant/a.h) \
    $(wildcard include/config/pmpd/ant/b.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_precomp.h \
    $(wildcard include/config/sfw/supported.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_types.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm.h \
    $(wildcard include/config/bb/rf.h) \
    $(wildcard include/config/bb/phy/reg.h) \
    $(wildcard include/config/bb/agc/tab.h) \
    $(wildcard include/config/bb/agc/tab/2g.h) \
    $(wildcard include/config/bb/agc/tab/5g.h) \
    $(wildcard include/config/bb/phy/reg/pg.h) \
    $(wildcard include/config/bb/phy/reg/mp.h) \
    $(wildcard include/config/bb/agc/tab/diff.h) \
    $(wildcard include/config/rf/radio.h) \
    $(wildcard include/config/rf/txpwr/lmt.h) \
    $(wildcard include/config/fw/nic.h) \
    $(wildcard include/config/fw/nic/2.h) \
    $(wildcard include/config/fw/ap.h) \
    $(wildcard include/config/fw/ap/2.h) \
    $(wildcard include/config/fw/mp.h) \
    $(wildcard include/config/fw/wowlan.h) \
    $(wildcard include/config/fw/wowlan/2.h) \
    $(wildcard include/config/fw/ap/wowlan.h) \
    $(wildcard include/config/fw/bt.h) \
    $(wildcard include/config/ram64x16.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_pre_define.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_dig.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_edcaturbocheck.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_pathdiv.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_antdiv.h \
    $(wildcard include/config/wlan/hal.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_antdect.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_dynamicbbpowersaving.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_rainfo.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_dynamictxpower.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_cfotracking.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_acs.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_adaptivity.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_iqk.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_dfs.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_ccx.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/txbf/phydm_hal_txbf_api.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_adc_sampling.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_dynamic_rx_path.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_psd.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_beamforming.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/txbf/halcomtxbf.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/txbf/haltxbfjaguar.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/txbf/haltxbf8192e.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/txbf/haltxbf8814a.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/txbf/haltxbf8822b.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/txbf/haltxbfinterface.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_noisemonitor.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/halphyrf_ce.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_kfree.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_powertracking_ce.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_hwconfig.h \
    $(wildcard include/config/mp.h) \
    $(wildcard include/config/tc.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_debug.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_regdefine11ac.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_regdefine11n.h \
    $(wildcard include/config/anta/11n.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_interface.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/phydm_reg.h \
    $(wildcard include/config/wlan/hal/8814ae.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/halhwimg8821a_mac.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/halhwimg8821a_rf.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/halhwimg8821a_bb.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/halhwimg8821a_fw.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/phydm_regconfig8821a.h \
    $(wildcard include/config/h/8821a.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/phydm_rtl8821a.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/version_rtl8821a.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/halphyrf_8821a_ce.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8821a/phydm_iqk_8821a_ce.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/../hal/phydm/rtl8812a/halphyrf_8812a_ce.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_hal.h \
    $(wildcard include/config/fw/c2h/debug.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_data.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_spec.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8821a_spec.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_com_reg.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_spec.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_rf.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_dm.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_recv.h \
    $(wildcard include/config/platform/novatek/nt72668.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_xmit.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8821a_xmit.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_cmd.h \
    $(wildcard include/config/fwlps/in/ips.h) \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_led.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/Hal8812PwrSeq.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/HalPwrSeqCmd.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/Hal8821APwrSeq.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/Hal8812PhyReg.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/Hal8812PhyCfg.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/rtl8812a_sreset.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_btcoex.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtcoutsrc.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8192e1ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8192e2ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8723b1ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8723b2ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8812a1ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8812a2ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821a1ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821a2ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8703b1ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8723d1ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8723d2ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8822b1ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8822b2ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821c1ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821c2ant.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/include/hal_btcoex_wifionly.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8723bwifionly.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8822bwifionly.h \
  /home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821cwifionly.h \

/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821cwifionly.o: $(deps_/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821cwifionly.o)

$(deps_/home/sksung/work/udx/ch2/packages/dev_app/module/wifi/8821au_driver/hal/btc/halbtc8821cwifionly.o):
