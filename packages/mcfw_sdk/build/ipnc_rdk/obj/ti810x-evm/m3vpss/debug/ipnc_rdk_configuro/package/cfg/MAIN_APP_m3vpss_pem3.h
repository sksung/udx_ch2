/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y25
 */

#include <xdc/std.h>

#define XDC_CFG_TILER_MEM_BASE_ADDR 0xb0000000

#define XDC_CFG_TILER_MEM_8BIT_SIZE 0x2000000

#define XDC_CFG_TILER_MEM_16BIT_SIZE 0x2000000

#define XDC_CFG_TILER_MEM_32BIT_SIZE 0x0

#include <ti/sysbios/gates/GateMutexPri.h>
extern const ti_sysbios_gates_GateMutexPri_Handle gOSALgate;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle csi2_context_irq_swi_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle simcop_swi_handle;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle isp_swi_handle;

extern int xdc_runtime_Startup__EXECFXN__C;

extern int xdc_runtime_Startup__RESETFXN__C;

#ifndef ti_sysbios_knl_Task__include
#ifndef __nested__
#define __nested__
#include <ti/sysbios/knl/Task.h>
#undef __nested__
#else
#include <ti/sysbios/knl/Task.h>
#endif
#endif

extern ti_sysbios_knl_Task_Struct TSK_idle;

