/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y25
 */

#include <xdc/std.h>

#define DSKT2_HEAP 0x0

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle ti_sdo_fc_ires_hdvicp_HDVICP2_hwi0;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle ti_sdo_fc_ires_hdvicp_HDVICP2_swi0;

#include <xdc/runtime/knl/SemThread.h>
extern const xdc_runtime_knl_SemThread_Handle ti_sdo_fc_ires_hdvicp_HDVICP2_sem0;

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

