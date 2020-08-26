vpath % /home/sksung/work/udx/ch2/ti_tools/ipc_1_24_03_32/packages/ti/sdo/
vpath %.c /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/

CCOPTS ?= --endian=little -mv7M3 --abi=eabi -q -ms --opt_for_speed=2  --program_level_compile -o3 -g --optimize_with_debug

XDC_ROOT  = /home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/

IPC_ROOT = /home/sksung/work/udx/ch2/ti_tools/ipc_1_24_03_32/packages/ti/sdo/

BUILD_DEFS =  -Dti_sdo_ipc_MessageQ_traceFlag__D=FALSE -Dti_sdo_ipc_family_ti81xx_InterruptDucati_videoProcId__D=1 -Dti_sdo_ipc_family_ti81xx_InterruptDucati_hostProcId__D=3 -Dti_sdo_ipc_family_ti81xx_InterruptDucati_vpssProcId__D=2 -Dti_sdo_ipc_family_ti81xx_InterruptDucati_dspProcId__D=0 -Dti_sdo_ipc_family_ti81xx_InterruptDucati_ducatiCtrlBaseAddr__D=1073745920 -Dti_sdo_ipc_family_ti81xx_InterruptDucati_mailboxBaseAddr__D=1208778752

BIOS_INC  = -I"/home/sksung/work/udx/ch2/ti_tools/bios_6_33_05_46/packages"

IPC_INC    = -I"/home/sksung/work/udx/ch2/ti_tools/ipc_1_24_03_32/packages"

IO_INC    = -I"/home/sksung/work/udx/ch2/ti_tools/ipc_1_24_03_32/packages"

UTILS_INC    = -I"/home/sksung/work/udx/ch2/ti_tools/ipc_1_24_03_32/packages"

CC = /home/sksung/work/udx/ch2/packages/../ti_tools/cgt470_4_9_5/bin/cl470 -c $(CCOPTS) -I /home/sksung/work/udx/ch2/packages/../ti_tools/cgt470_4_9_5/include

ASM = /home/sksung/work/udx/ch2/packages/../ti_tools/cgt470_4_9_5/bin/cl470 -c $(CCOPTS) -I /home/sksung/work/udx/ch2/packages/../ti_tools/cgt470_4_9_5/include

AR = /home/sksung/work/udx/ch2/packages/../ti_tools/cgt470_4_9_5/bin/ar470 rq

DEL = rm -f

define RM
	$(if $(wildcard $1),$(DEL) $1,:)
endef

define ASSEMBLE
	@@echo asmem3 $< ...
	@$(ASM) $(BUILD_DEFS) -I "/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/" -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_target_name__=M3 $(IPC_INC) $<
endef

all: ipc.lib


Ipc.obj: ipc/Ipc.c utils/NameServer.c utils/NameServerRemoteNull.c utils/MultiProc.c utils/List.c ipc/GateMP.c ipc/MessageQ.c ipc/SharedRegion.c ipc/ListMP.c ipc/Notify.c ipc/gates/GateHWSpinlock.c ipc/gates/GatePeterson.c ipc/gates/GateMPSupportNull.c ipc/heaps/HeapMemMP.c ipc/notifyDrivers/NotifyDriverShm.c ipc/family/ti81xx/NotifySetup.c ipc/family/ti81xx/InterruptDucati.c ipc/transports/TransportShm.c ipc/transports/TransportShmSetup.c ipc/nsremote/NameServerRemoteNotify.c makefile
	@-$(call RM, $@)
	@echo clem3 $< ...
	@$(CC) $(BUILD_DEFS) -I "/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/" -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_target_name__=M3 $(BIOS_INC) $(IO_INC) \
	$(IPC_INC) $(UTILS_INC) \
	$(IPC_ROOT)ipc/Ipc.c \
	$(IPC_ROOT)utils/NameServer.c \
	$(IPC_ROOT)utils/NameServerRemoteNull.c \
	$(IPC_ROOT)utils/MultiProc.c \
	$(IPC_ROOT)utils/List.c \
	$(IPC_ROOT)ipc/GateMP.c \
	$(IPC_ROOT)ipc/MessageQ.c \
	$(IPC_ROOT)ipc/SharedRegion.c \
	$(IPC_ROOT)ipc/ListMP.c \
	$(IPC_ROOT)ipc/Notify.c \
	$(IPC_ROOT)ipc/gates/GateHWSpinlock.c \
	$(IPC_ROOT)ipc/gates/GatePeterson.c \
	$(IPC_ROOT)ipc/gates/GateMPSupportNull.c \
	$(IPC_ROOT)ipc/heaps/HeapMemMP.c \
	$(IPC_ROOT)ipc/notifyDrivers/NotifyDriverShm.c \
	$(IPC_ROOT)ipc/family/ti81xx/NotifySetup.c \
	$(IPC_ROOT)ipc/family/ti81xx/InterruptDucati.c \
	$(IPC_ROOT)ipc/transports/TransportShm.c \
	$(IPC_ROOT)ipc/transports/TransportShmSetup.c \
	$(IPC_ROOT)ipc/nsremote/NameServerRemoteNotify.c \

ipc.lib: Ipc.obj 
	@echo arem3 $^ ...
	@-$(call RM, $@)
	@$(AR) $@ $^

clean:
	@-$(call RM, ipc.lib)
	@-$(call RM, Ipc.obj)
