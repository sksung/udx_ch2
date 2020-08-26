/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"/home/sksung/work/udx/ch2/packages/mcfw_sdk_dt/build/ipnc_rdk/obj/ti810x-evm/m3video/debug/ipnc_rdk_configuro/package/cfg/MAIN_APP_m3video_pem3.oem3"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/fc/ires/tiledmemory/lib/release/tiledmemory.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/tiler/lib/debug/tiler_stub.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/rcm/lib/debug/rcm.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/ipc/rtos/lib/debug/ti.syslink.ipc.rtos.aem3"
-l"/home/sksung/work/udx/ch2/packages/mcfw_sdk_dt/build/ipnc_rdk/obj/ti810x-evm/m3video/debug/ipnc_rdk_configuro/package/cfg/MAIN_APP_m3video_pem3.src/ipc/ipc.lib"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/fc/rman/lib/debug/rman.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/fc/ires/hdvicp/lib/debug/hdvicp2.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/fc/dskt2/lib/debug/dskt2.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/fc/memutils/lib/release/memutils.aem3"
-l"/home/sksung/work/udx/ch2/packages/mcfw_sdk_dt/build/ipnc_rdk/obj/ti810x-evm/m3video/debug/ipnc_rdk_configuro/package/cfg/MAIN_APP_m3video_pem3.src/sysbios/sysbios.lib"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/fc/ires/nullresource/lib/debug/nullres.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/fc/utils/osalsupport/lib/debug/osal_support.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/framework_components_3_22_02_08/packages/ti/sdo/fc/global/lib/debug/fcsettings.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/syslink_2_10_06_28/packages/ti/syslink/utils/rtos/bios6/lib/debug/ti.syslink.utils.rtos.bios6.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/edma3_lld_02_11_02_04/packages/ti/sdo/edma3/drv/lib/m3/release/edma3_lld_drv.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/edma3_lld_02_11_02_04/packages/ti/sdo/edma3/rm/lib/ti814x-evm/m3/release/edma3_lld_rm.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/rtsarm/lib/ti.targets.arm.rtsarm.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/rtsarm/lib/boot.aem3"
-l"/home/sksung/work/udx/ch2/ti_tools/xdctools_3_23_03_53/packages/ti/targets/arm/rtsarm/lib/auto_init.aem3"

--retain="*(xdc.meta)"

/* C6x Elf symbols */
--symbol_map __TI_STACK_SIZE=__STACK_SIZE
--symbol_map __TI_STACK_BASE=__stack
--symbol_map _stack=__stack



--args 0x0
-heap  0x0
-stack 0xa000

MEMORY
{
    LINUX_MEM : org = 0x80000000, len = 0xb400000
    SR1 : org = 0xbb400000, len = 0x4500000
    VIDEO_M3_CODE_MEM : org = 0x8df00000, len = 0x200000
    DDR3_M3 : org = 0x8e100000, len = 0x900000
    DSS_M3_CODE_MEM : org = 0x8ea00000, len = 0x200000
    DSS_M3_DATA_MEM : org = 0x8ec00000, len = 0x13ff800
    DSP_CODE_MEM : org = 0x8ffff800, len = 0x400
    DDR3_DSP : org = 0x8ffffc00, len = 0x400
    TILER_MEM : org = 0xb0000000, len = 0x4000000
    SR2_FRAME_BUFFER_MEM : org = 0xb4000000, len = 0x6400000
    SR0 : org = 0xba400000, len = 0x1000000
    HDVPSS_DESC_MEM : org = 0xbf900000, len = 0x200000
    HDVPSS_SHARED_MEM : org = 0xbfb00000, len = 0x200000
    HOST_VPSS_NOTIFYMEM : org = 0xbfd00000, len = 0x200000
    REMOTE_DEBUG_MEM : org = 0xbff00000, len = 0x100000
    L2_RAM : org = 0x20004000, len = 0x10000
    L2_ROM : org = 0x0, len = 0x4000
    OCMC0_RAM : org = 0x40300000, len = 0x40000
    OCMC1_RAM : org = 0x40400000, len = 0x40000
}

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from ti.targets.arm (null): */

/* Content from ti.targets.arm.elf (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from ti.targets.arm.rtsarm (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from ti.sysbios.family.arm (ti/sysbios/family/arm/linkcmd.xdt): */
--retain "*(.vecs)"

/* Content from xdc.services.getset (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sdo.edma3.rm (null): */

/* Content from ti.sdo.edma3.drv (null): */

/* Content from ti.sdo.ipc.interfaces (null): */

/* Content from ti.sdo.ipc.family (null): */

/* Content from ti.syslink.utils.rtos.bios6 (null): */

/* Content from ti.xdais (null): */

/* Content from ti.sdo.fc.ires (null): */

/* Content from ti.sdo.fc.global (null): */

/* Content from ti.sdo.fc.utils.osalsupport (null): */

/* Content from ti.sdo.fc.ires.nullresource (null): */

/* Content from ti.sysbios.hal.ammu (ti/sysbios/hal/ammu/linkcmd.xdt): */
ti_sysbios_hal_ammu_AMMU_mmu = 1073743872;

/* Content from ti.catalog.arm.cortexm3 (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.arm.peripherals.timers (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog.arm.cortexa8 (null): */

/* Content from ti.platforms.evmTI814X (null): */

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.arm.m3 (ti/sysbios/family/arm/m3/linkcmd.xdt): */

/* Content from ti.sysbios.timers.dmtimer (null): */

/* Content from ti.sysbios.family.arm.ducati (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from ti.sysbios.syncs (null): */

/* Content from ti.sdo.utils (null): */

/* Content from ti.sdo.fc.memutils (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sdo.fc.dskt2 (null): */

/* Content from ti.sdo.fc.ires.hdvicp (null): */

/* Content from ti.sdo.fc.rman (null): */

/* Content from ti.sysbios.hal.unicache (ti/sysbios/hal/unicache/linkcmd.xdt): */
ti_sysbios_hal_unicache_Cache_cache = 1073741824;

/* Content from ti.sdo.ipc (ti/sdo/ipc/linkcmd.xdt): */

SECTIONS
{
    ti.sdo.ipc.SharedRegion_0:  { . += 0x1000000;} run > 0xba400000, type = NOLOAD
    ti.sdo.ipc.SharedRegion_1:  { . += 0x4500000;} run > 0xbb400000, type = NOLOAD

    ti_sdo_ipc_init: load > DDR3_M3, type = NOINIT 
}


/* Content from ti.sdo.ipc.transports (null): */

/* Content from ti.sdo.ipc.family.ti81xx (null): */

/* Content from ti.sdo.ipc.notifyDrivers (null): */

/* Content from ti.sdo.ipc.nsremote (null): */

/* Content from ti.sdo.ipc.heaps (null): */

/* Content from ti.syslink.ipc.rtos (ti/syslink/ipc/rtos/linkcmd.xdt): */



/* Add the flags needed for SysLink ELF build. */
    --dynamic
    --retain=_Ipc_ResetVector

/* Content from ti.sdo.rcm (null): */

/* Content from ti.sdo.tiler (null): */

/* Content from ti.sdo.fc.ires.tiledmemory (null): */

/* Content from ti.sdo.ipc.gates (null): */

/* Content from ipnc_rdk_configuro (null): */

/* Content from xdc.services.io (null): */


/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;
TSK_idle = ti_sysbios_knl_Task_Object__table__V + 0;

SECTIONS
{
    .text: load >> VIDEO_M3_CODE_MEM
    .stack: load > DDR3_M3
    GROUP: load > DDR3_M3
    {
        .bss:
        .neardata:
        .rodata:
    }
    .cinit: load > DDR3_M3
    .init_array: load > DDR3_M3
    .const: load >> VIDEO_M3_CODE_MEM
    .data: load >> DDR3_M3
    .fardata: load >> DDR3_M3
    .switch: load >> DDR3_M3
    .sysmem: load > DDR3_M3
    .far: load >> DDR3_M3
    .args: load > DDR3_M3 align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> DDR3_M3
    .bootVecs:  type = DSECT
    .vecs: load > 0x400, type = DSECT
    .resetVecs: load > 0x400
    .bss:extMemNonCache:remoteDebugCoreShm: load >> REMOTE_DEBUG_MEM
    .plt: load >> VIDEO_M3_CODE_MEM
    .ducatiBoot: load > 0x0
    .ducatiGates: load > 0x7f0, type = NOINIT
    xdc.meta: load >> VIDEO_M3_CODE_MEM, type = COPY

}
