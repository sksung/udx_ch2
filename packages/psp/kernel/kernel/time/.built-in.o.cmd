cmd_kernel/time/built-in.o :=  /home/sksung/work/udx/ch2/packages/../ti_tools/linux_devkit/bin/arm-arago-linux-gnueabi-ld -EL    -r -o kernel/time/built-in.o kernel/time/timekeeping.o kernel/time/ntp.o kernel/time/clocksource.o kernel/time/jiffies.o kernel/time/timer_list.o kernel/time/timecompare.o kernel/time/timeconv.o kernel/time/posix-clock.o kernel/time/clockevents.o kernel/time/tick-common.o kernel/time/tick-oneshot.o kernel/time/tick-sched.o 