/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y21
 */

#define __nested__
#define __config__

#include <xdc/std.h>

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     MODULE INCLUDES
 *     
 *     <module-name> INTERNALS
 *     <module-name> INHERITS
 *     <module-name> VTABLE
 *     <module-name> PATCH TABLE
 *     <module-name> DECLARATIONS
 *     <module-name> OBJECT OFFSETS
 *     <module-name> TEMPLATES
 *     <module-name> INITIALIZERS
 *     <module-name> FUNCTION STUBS
 *     <module-name> PROXY BODY
 *     <module-name> OBJECT DESCRIPTOR
 *     <module-name> SYSTEM FUNCTIONS
 *     <module-name> PRAGMAS
 *     
 *     INITIALIZATION ENTRY POINT
 *     PROGRAM GLOBALS
 *     CLINK DIRECTIVES
 */


/*
 * ======== MODULE INCLUDES ========
 */

#include <ti/sdo/utils/NameServerRemoteNull.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/family/c62/IntrinsicsSupport.h>
#include <ti/sysbios/family/c62/TaskSupport.h>
#include <ti/sysbios/family/c64p/Exception.h>
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/TimestampProvider.h>
#include <ti/sysbios/family/c64p/tesla/TimerSupport.h>
#include <ti/sysbios/family/c64p/tesla/Wugen.h>
#include <ti/sysbios/gates/GateHwi.h>
#include <ti/sysbios/gates/GateMutex.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/hal/Timer.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Idle.h>
#include <ti/sysbios/knl/Intrinsics.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/timers/dmtimer/Timer.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Core.h>
#include <xdc/runtime/Defaults.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Gate.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Main.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/SysMin.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Text.h>
#include <xdc/runtime/Timestamp.h>


/*
 * ======== ti.sdo.utils.NameServerRemoteNull INTERNALS ========
 */

/* Module__ */
typedef struct ti_sdo_utils_NameServerRemoteNull_Module__ {
    xdc_runtime_Types_Link link;
} ti_sdo_utils_NameServerRemoteNull_Module__;

/* Module__root__V */
extern ti_sdo_utils_NameServerRemoteNull_Module__ ti_sdo_utils_NameServerRemoteNull_Module__root__V;

/* Object__ */
typedef struct ti_sdo_utils_NameServerRemoteNull_Object__ {
    const ti_sdo_utils_NameServerRemoteNull_Fxns__* __fxns;
} ti_sdo_utils_NameServerRemoteNull_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sdo_utils_NameServerRemoteNull_Object__ obj;
} ti_sdo_utils_NameServerRemoteNull_Object2__;

/* __ParamsPtr */
#ifdef ti_sdo_utils_NameServerRemoteNull___VERS
    #define ti_sdo_utils_NameServerRemoteNull___ParamsPtr xdc_UChar*
#else
    #define ti_sdo_utils_NameServerRemoteNull___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.BIOS INTERNALS ========
 */


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_BIOS_RtsGateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_BIOS_RtsGateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_BIOS_RtsGateProxy_Module__ ti_sysbios_BIOS_RtsGateProxy_Module__root__V;

/* @@@ ti_sysbios_knl_Queue_Object__ */
typedef struct ti_sysbios_knl_Queue_Object__ {
    ti_sysbios_knl_Queue_Elem elem;
} ti_sysbios_knl_Queue_Object__;

/* @@@ ti_sysbios_knl_Queue_Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Queue_Object__ obj;
} ti_sysbios_knl_Queue_Object2__;

/* @@@ ti_sysbios_knl_Semaphore_Object__ */
typedef struct ti_sysbios_knl_Semaphore_Object__ {
    ti_sysbios_knl_Event_Handle event;
    xdc_UInt eventId;
    ti_sysbios_knl_Semaphore_Mode mode;
    volatile xdc_UInt16 count;
    ti_sysbios_knl_Queue_Object__ Object_field_pendQ;
} ti_sysbios_knl_Semaphore_Object__;

/* @@@ ti_sysbios_knl_Semaphore_Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Semaphore_Object__ obj;
} ti_sysbios_knl_Semaphore_Object2__;

/* Object__ */
typedef struct ti_sysbios_gates_GateMutex_Object__ {
    const ti_sysbios_gates_GateMutex_Fxns__* __fxns;
    ti_sysbios_knl_Task_Handle owner;
    ti_sysbios_knl_Semaphore_Object__ Object_field_sem;
} ti_sysbios_gates_GateMutex_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_gates_GateMutex_Object__ obj;
} ti_sysbios_gates_GateMutex_Object2__;

/* Object */
typedef ti_sysbios_gates_GateMutex_Object__ ti_sysbios_BIOS_RtsGateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_BIOS_RtsGateProxy_Object__ obj;
} ti_sysbios_BIOS_RtsGateProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_BIOS_RtsGateProxy___VERS
    #define ti_sysbios_BIOS_RtsGateProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_BIOS_RtsGateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.c62.IntrinsicsSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c62.TaskSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.Exception INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_c64p_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_c64p_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_family_c64p_Hwi_Module__ ti_sysbios_family_c64p_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_c64p_Hwi_Object__ {
    const ti_sysbios_family_c64p_Hwi_Fxns__* __fxns;
    xdc_Bits16 disableMask;
    xdc_Bits16 restoreMask;
    xdc_UArg arg;
    ti_sysbios_family_c64p_Hwi_FuncPtr fxn;
    ti_sysbios_family_c64p_Hwi_Irp irp;
    __TA_ti_sysbios_family_c64p_Hwi_Instance_State__hookEnv hookEnv;
} ti_sysbios_family_c64p_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_c64p_Hwi_Object__ obj;
} ti_sysbios_family_c64p_Hwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_family_c64p_Hwi___VERS
    #define ti_sysbios_family_c64p_Hwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_family_c64p_Hwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.tesla.TimerSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c64p.tesla.Wugen INTERNALS ========
 */


/*
 * ======== ti.sysbios.gates.GateHwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_gates_GateHwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_gates_GateHwi_Module__;

/* Module__root__V */
extern ti_sysbios_gates_GateHwi_Module__ ti_sysbios_gates_GateHwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_gates_GateHwi_Object__ {
    const ti_sysbios_gates_GateHwi_Fxns__* __fxns;
} ti_sysbios_gates_GateHwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_gates_GateHwi_Object__ obj;
} ti_sysbios_gates_GateHwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_gates_GateHwi___VERS
    #define ti_sysbios_gates_GateHwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_gates_GateHwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.gates.GateMutex INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_gates_GateMutex_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_gates_GateMutex_Module__;

/* Module__root__V */
extern ti_sysbios_gates_GateMutex_Module__ ti_sysbios_gates_GateMutex_Module__root__V;

/* <-- ti_sysbios_gates_GateMutex_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_gates_GateMutex___VERS
    #define ti_sysbios_gates_GateMutex___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_gates_GateMutex___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Hwi_Module__ ti_sysbios_hal_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_hal_Hwi_Object__ {
    const ti_sysbios_hal_Hwi_Fxns__* __fxns;
    ti_sysbios_hal_Hwi_HwiProxy_Handle pi;
} ti_sysbios_hal_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Hwi_Object__ obj;
} ti_sysbios_hal_Hwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Hwi___VERS
    #define ti_sysbios_hal_Hwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Hwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Hwi_HwiProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Hwi_HwiProxy_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Hwi_HwiProxy_Module__ ti_sysbios_hal_Hwi_HwiProxy_Module__root__V;

/* <-- ti_sysbios_family_c64p_Hwi_Object */

/* Object */
typedef ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_hal_Hwi_HwiProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Hwi_HwiProxy_Object__ obj;
} ti_sysbios_hal_Hwi_HwiProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Hwi_HwiProxy___VERS
    #define ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Timer INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Timer_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Timer_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Timer_Module__ ti_sysbios_hal_Timer_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_hal_Timer_Object__ {
    const ti_sysbios_hal_Timer_Fxns__* __fxns;
    ti_sysbios_hal_Timer_TimerProxy_Handle pi;
} ti_sysbios_hal_Timer_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Timer_Object__ obj;
} ti_sysbios_hal_Timer_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Timer___VERS
    #define ti_sysbios_hal_Timer___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Timer___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Timer_TimerProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Timer_TimerProxy_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Timer_TimerProxy_Module__ ti_sysbios_hal_Timer_TimerProxy_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_timers_dmtimer_Timer_Object__ {
    const ti_sysbios_timers_dmtimer_Timer_Fxns__* __fxns;
    xdc_Bool staticInst;
    xdc_Int id;
    xdc_UInt tiocpCfg;
    xdc_UInt tmar;
    xdc_UInt tier;
    xdc_UInt twer;
    xdc_UInt tclr;
    xdc_UInt tsicr;
    ti_sysbios_interfaces_ITimer_RunMode runMode;
    ti_sysbios_interfaces_ITimer_StartMode startMode;
    xdc_UInt period;
    ti_sysbios_interfaces_ITimer_PeriodType periodType;
    xdc_UInt intNum;
    xdc_UArg arg;
    ti_sysbios_hal_Hwi_FuncPtr tickFxn;
    xdc_runtime_Types_FreqHz extFreq;
    ti_sysbios_hal_Hwi_Handle hwi;
    xdc_UInt prevThreshold;
    xdc_UInt rollovers;
} ti_sysbios_timers_dmtimer_Timer_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_timers_dmtimer_Timer_Object__ obj;
} ti_sysbios_timers_dmtimer_Timer_Object2__;

/* Object */
typedef ti_sysbios_timers_dmtimer_Timer_Object__ ti_sysbios_hal_Timer_TimerProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Timer_TimerProxy_Object__ obj;
} ti_sysbios_hal_Timer_TimerProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_hal_Timer_TimerProxy___VERS
    #define ti_sysbios_hal_Timer_TimerProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_hal_Timer_TimerProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.heaps.HeapMem INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_heaps_HeapMem_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_heaps_HeapMem_Module__;

/* Module__root__V */
extern ti_sysbios_heaps_HeapMem_Module__ ti_sysbios_heaps_HeapMem_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_heaps_HeapMem_Object__ {
    const ti_sysbios_heaps_HeapMem_Fxns__* __fxns;
    xdc_runtime_Memory_Size align;
    __TA_ti_sysbios_heaps_HeapMem_Instance_State__buf buf;
    ti_sysbios_heaps_HeapMem_Header head;
} ti_sysbios_heaps_HeapMem_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_heaps_HeapMem_Object__ obj;
} ti_sysbios_heaps_HeapMem_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_heaps_HeapMem___VERS
    #define ti_sysbios_heaps_HeapMem___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_heaps_HeapMem___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateMutex_Object */

/* Object */
typedef ti_sysbios_gates_GateMutex_Object__ ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__ obj;
} ti_sysbios_heaps_HeapMem_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_heaps_HeapMem_Module_GateProxy___VERS
    #define ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Clock INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Clock_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Clock_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Clock_Module__ ti_sysbios_knl_Clock_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* Object__ */
typedef struct ti_sysbios_knl_Clock_Object__ {
    ti_sysbios_knl_Queue_Elem elem;
    xdc_UInt32 timeout;
    xdc_UInt32 currTimeout;
    xdc_UInt32 period;
    volatile xdc_Bool active;
    ti_sysbios_knl_Clock_FuncPtr fxn;
    xdc_UArg arg;
} ti_sysbios_knl_Clock_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Clock_Object__ obj;
} ti_sysbios_knl_Clock_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Clock___VERS
    #define ti_sysbios_knl_Clock___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Clock___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Idle INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Queue INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Queue_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Queue_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Queue_Module__ ti_sysbios_knl_Queue_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Queue___VERS
    #define ti_sysbios_knl_Queue___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Queue___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Semaphore INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Semaphore_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Semaphore_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Semaphore_Module__ ti_sysbios_knl_Semaphore_Module__root__V;

/* <-- ti_sysbios_knl_Semaphore_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Semaphore___VERS
    #define ti_sysbios_knl_Semaphore___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Semaphore___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Swi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Swi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Swi_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Swi_Module__ ti_sysbios_knl_Swi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_knl_Swi_Object__ {
    ti_sysbios_knl_Queue_Elem qElem;
    ti_sysbios_knl_Swi_FuncPtr fxn;
    xdc_UArg arg0;
    xdc_UArg arg1;
    xdc_UInt priority;
    xdc_UInt mask;
    xdc_Bool posted;
    xdc_UInt initTrigger;
    xdc_UInt trigger;
    ti_sysbios_knl_Queue_Handle readyQ;
    __TA_ti_sysbios_knl_Swi_Instance_State__hookEnv hookEnv;
} ti_sysbios_knl_Swi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Swi_Object__ obj;
} ti_sysbios_knl_Swi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Swi___VERS
    #define ti_sysbios_knl_Swi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Swi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Task INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Task_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Task_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Task_Module__ ti_sysbios_knl_Task_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* Object__ */
typedef struct ti_sysbios_knl_Task_Object__ {
    ti_sysbios_knl_Queue_Elem qElem;
    volatile xdc_Int priority;
    xdc_UInt mask;
    xdc_Ptr context;
    ti_sysbios_knl_Task_Mode mode;
    ti_sysbios_knl_Task_PendElem* pendElem;
    xdc_SizeT stackSize;
    __TA_ti_sysbios_knl_Task_Instance_State__stack stack;
    xdc_runtime_IHeap_Handle stackHeap;
    ti_sysbios_knl_Task_FuncPtr fxn;
    xdc_UArg arg0;
    xdc_UArg arg1;
    xdc_Ptr env;
    __TA_ti_sysbios_knl_Task_Instance_State__hookEnv hookEnv;
    xdc_Bool vitalTaskFlag;
    ti_sysbios_knl_Queue_Handle readyQ;
} ti_sysbios_knl_Task_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Task_Object__ obj;
} ti_sysbios_knl_Task_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_knl_Task___VERS
    #define ti_sysbios_knl_Task___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_knl_Task___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.knl.Task_SupportProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.timers.dmtimer.Timer INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_timers_dmtimer_Timer_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_timers_dmtimer_Timer_Module__;

/* Module__root__V */
extern ti_sysbios_timers_dmtimer_Timer_Module__ ti_sysbios_timers_dmtimer_Timer_Module__root__V;

/* <-- ti_sysbios_timers_dmtimer_Timer_Object */

/* __ParamsPtr */
#ifdef ti_sysbios_timers_dmtimer_Timer___VERS
    #define ti_sysbios_timers_dmtimer_Timer___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_timers_dmtimer_Timer___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Assert INTERNALS ========
 */


/*
 * ======== xdc.runtime.Core INTERNALS ========
 */


/*
 * ======== xdc.runtime.Defaults INTERNALS ========
 */


/*
 * ======== xdc.runtime.Diags INTERNALS ========
 */


/*
 * ======== xdc.runtime.Error INTERNALS ========
 */


/*
 * ======== xdc.runtime.Gate INTERNALS ========
 */


/*
 * ======== xdc.runtime.Log INTERNALS ========
 */


/*
 * ======== xdc.runtime.Main INTERNALS ========
 */


/*
 * ======== xdc.runtime.Main_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_Main_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_Main_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_Main_Module_GateProxy_Module__ xdc_runtime_Main_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_Main_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_Main_Module_GateProxy_Object__ obj;
} xdc_runtime_Main_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_Main_Module_GateProxy___VERS
    #define xdc_runtime_Main_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_Main_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.Memory INTERNALS ========
 */


/*
 * ======== xdc.runtime.Memory_HeapProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_Memory_HeapProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_Memory_HeapProxy_Module__;

/* Module__root__V */
extern xdc_runtime_Memory_HeapProxy_Module__ xdc_runtime_Memory_HeapProxy_Module__root__V;

/* <-- ti_sysbios_heaps_HeapMem_Object */

/* Object */
typedef ti_sysbios_heaps_HeapMem_Object__ xdc_runtime_Memory_HeapProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_Memory_HeapProxy_Object__ obj;
} xdc_runtime_Memory_HeapProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_Memory_HeapProxy___VERS
    #define xdc_runtime_Memory_HeapProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_Memory_HeapProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.Registry INTERNALS ========
 */


/*
 * ======== xdc.runtime.Startup INTERNALS ========
 */


/*
 * ======== xdc.runtime.SysMin INTERNALS ========
 */


/*
 * ======== xdc.runtime.System INTERNALS ========
 */


/*
 * ======== xdc.runtime.System_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_System_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_System_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_System_Module_GateProxy_Module__ xdc_runtime_System_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_System_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_System_Module_GateProxy_Object__ obj;
} xdc_runtime_System_Module_GateProxy_Object2__;

/* __ParamsPtr */
#ifdef xdc_runtime_System_Module_GateProxy___VERS
    #define xdc_runtime_System_Module_GateProxy___ParamsPtr xdc_UChar*
#else
    #define xdc_runtime_System_Module_GateProxy___ParamsPtr xdc_Ptr
#endif


/*
 * ======== xdc.runtime.System_SupportProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Text INTERNALS ========
 */


/*
 * ======== xdc.runtime.Timestamp INTERNALS ========
 */


/*
 * ======== xdc.runtime.Timestamp_SupportProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.gates.GateHwi INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
__FAR__ const xdc_runtime_Types_Base xdc_runtime_IGateProvider_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== ti.sysbios.gates.GateMutex INHERITS ========
 */



/*
 * ======== ti.sysbios.heaps.HeapMem INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IHeap_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== xdc.runtime.SysMin INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_ISystemSupport_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== xdc.runtime.Timestamp INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_ITimestampClient_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== ti.sysbios.gates.GateHwi VTABLE ========
 */

/* Module__FXNS__C */
const ti_sysbios_gates_GateHwi_Fxns__ ti_sysbios_gates_GateHwi_Module__FXNS__C = {
    (void*)&xdc_runtime_IGateProvider_Interface__BASE__C, /* base__ */
    &ti_sysbios_gates_GateHwi_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_gates_GateHwi_query__E,
    ti_sysbios_gates_GateHwi_enter__E,
    ti_sysbios_gates_GateHwi_leave__E,
    {
        ti_sysbios_gates_GateHwi_Object__create__S,
        ti_sysbios_gates_GateHwi_Object__delete__S,
        ti_sysbios_gates_GateHwi_Handle__label__S,
        0x8023, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.gates.GateMutex VTABLE ========
 */

/* Module__FXNS__C */
const ti_sysbios_gates_GateMutex_Fxns__ ti_sysbios_gates_GateMutex_Module__FXNS__C = {
    (void*)&xdc_runtime_IGateProvider_Interface__BASE__C, /* base__ */
    &ti_sysbios_gates_GateMutex_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_gates_GateMutex_query__E,
    ti_sysbios_gates_GateMutex_enter__E,
    ti_sysbios_gates_GateMutex_leave__E,
    {
        ti_sysbios_gates_GateMutex_Object__create__S,
        ti_sysbios_gates_GateMutex_Object__delete__S,
        ti_sysbios_gates_GateMutex_Handle__label__S,
        0x8024, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.heaps.HeapMem VTABLE ========
 */

/* Module__FXNS__C */
const ti_sysbios_heaps_HeapMem_Fxns__ ti_sysbios_heaps_HeapMem_Module__FXNS__C = {
    (void*)&xdc_runtime_IHeap_Interface__BASE__C, /* base__ */
    &ti_sysbios_heaps_HeapMem_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_heaps_HeapMem_alloc__E,
    ti_sysbios_heaps_HeapMem_free__E,
    ti_sysbios_heaps_HeapMem_isBlocking__E,
    ti_sysbios_heaps_HeapMem_getStats__E,
    {
        ti_sysbios_heaps_HeapMem_Object__create__S,
        ti_sysbios_heaps_HeapMem_Object__delete__S,
        ti_sysbios_heaps_HeapMem_Handle__label__S,
        0x8033, /* __mid */
    } /* __sfxns */
};


/*
 * ======== xdc.runtime.SysMin VTABLE ========
 */

/* Module__FXNS__C */
const xdc_runtime_SysMin_Fxns__ xdc_runtime_SysMin_Module__FXNS__C = {
    (void*)&xdc_runtime_ISystemSupport_Interface__BASE__C, /* base__ */
    &xdc_runtime_SysMin_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_SysMin_abort__E,
    xdc_runtime_SysMin_exit__E,
    xdc_runtime_SysMin_flush__E,
    xdc_runtime_SysMin_putch__E,
    xdc_runtime_SysMin_ready__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x800e, /* __mid */
    } /* __sfxns */
};


/*
 * ======== xdc.runtime.Timestamp VTABLE ========
 */

/* Module__FXNS__C */
const xdc_runtime_Timestamp_Fxns__ xdc_runtime_Timestamp_Module__FXNS__C = {
    (void*)&xdc_runtime_ITimestampClient_Interface__BASE__C, /* base__ */
    &xdc_runtime_Timestamp_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_Timestamp_get32__E,
    xdc_runtime_Timestamp_get64__E,
    xdc_runtime_Timestamp_getFreq__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x8010, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sdo.utils.NameServerRemoteNull DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.BIOS DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_BIOS_Module_State__ {
    xdc_runtime_Types_FreqHz cpuFreq;
    xdc_UInt rtsGateCount;
    xdc_IArg rtsGateKey;
    ti_sysbios_BIOS_RtsGateProxy_Handle rtsGate;
    ti_sysbios_BIOS_ThreadType threadType;
    ti_sysbios_BIOS_StartFuncPtr startFunc;
} ti_sysbios_BIOS_Module_State__;

/* --> ti_sysbios_BIOS_startFunc */
extern xdc_Void ti_sysbios_BIOS_startFunc(xdc_Void);

/* Module__state__V */
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V;


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c62.IntrinsicsSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c62.TaskSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c64p.Exception DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_Exception_Module_State__ {
    xdc_Bits32 efr;
    xdc_Bits32 nrp;
    xdc_Bits32 ntsr;
    xdc_Bits32 ierr;
    ti_sysbios_family_c64p_Exception_FuncPtr returnHook;
    ti_sysbios_family_c64p_Exception_Context* excContext;
    __TA_ti_sysbios_family_c64p_Exception_Module_State__scratch scratch;
    xdc_Char* isrStack;
} ti_sysbios_family_c64p_Exception_Module_State__;

/* Module__state__V */
ti_sysbios_family_c64p_Exception_Module_State__ ti_sysbios_family_c64p_Exception_Module__state__V;


/*
 * ======== ti.sysbios.family.c64p.Hwi DECLARATIONS ========
 */

/* --> ti_sysbios_family_c64p_Hwi_Instance_State_0_hookEnv__A */
__T1_ti_sysbios_family_c64p_Hwi_Instance_State__hookEnv ti_sysbios_family_c64p_Hwi_Instance_State_0_hookEnv__A[1];

/* Object__table__V */
ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_family_c64p_Hwi_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_Hwi_Module_State__ {
    __TA_ti_sysbios_family_c64p_Hwi_Module_State__intEvents intEvents;
    xdc_Bits16 ierMask;
    volatile xdc_Int intNum;
    xdc_Char* taskSP;
    xdc_Char* isrStack;
    xdc_Ptr vectorTableBase;
    xdc_Ptr bss;
    __TA_ti_sysbios_family_c64p_Hwi_Module_State__dispatchTable dispatchTable;
} ti_sysbios_family_c64p_Hwi_Module_State__;

/* --> ti_sysbios_family_c64p_Hwi0 */
extern void* ti_sysbios_family_c64p_Hwi0;

/* --> __TI_STATIC_BASE */
extern void* __TI_STATIC_BASE;

/* Module__state__V */
ti_sysbios_family_c64p_Hwi_Module_State__ ti_sysbios_family_c64p_Hwi_Module__state__V;

/* --> ti_sysbios_knl_Swi_disable__E */
extern xdc_UInt ti_sysbios_knl_Swi_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Swi_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Swi_restoreHwi__E(xdc_UInt);

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Task_restoreHwi__E(xdc_UInt);

/* --> ti_sysbios_family_c64p_Hwi_hooks__A */
const __T1_ti_sysbios_family_c64p_Hwi_hooks ti_sysbios_family_c64p_Hwi_hooks__A[1];


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c64p.tesla.TimerSupport DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_tesla_TimerSupport_Module_State__ {
    __TA_ti_sysbios_family_c64p_tesla_TimerSupport_Module_State__suspSrc suspSrc;
} ti_sysbios_family_c64p_tesla_TimerSupport_Module_State__;

/* --> ti_sysbios_family_c64p_tesla_TimerSupport_Module_State_0_suspSrc__A */
__T1_ti_sysbios_family_c64p_tesla_TimerSupport_Module_State__suspSrc ti_sysbios_family_c64p_tesla_TimerSupport_Module_State_0_suspSrc__A[4];

/* Module__state__V */
ti_sysbios_family_c64p_tesla_TimerSupport_Module_State__ ti_sysbios_family_c64p_tesla_TimerSupport_Module__state__V;

/* --> ti_sysbios_family_c64p_tesla_TimerSupport_timer__A */
const __T1_ti_sysbios_family_c64p_tesla_TimerSupport_timer ti_sysbios_family_c64p_tesla_TimerSupport_timer__A[4];


/*
 * ======== ti.sysbios.family.c64p.tesla.Wugen DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_family_c64p_tesla_Wugen_Module_State__ {
    xdc_Int hwiHookId;
} ti_sysbios_family_c64p_tesla_Wugen_Module_State__;

/* Module__state__V */
ti_sysbios_family_c64p_tesla_Wugen_Module_State__ ti_sysbios_family_c64p_tesla_Wugen_Module__state__V;


/*
 * ======== ti.sysbios.gates.GateHwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_gates_GateHwi_Object__ ti_sysbios_gates_GateHwi_Object__table__V[1];


/*
 * ======== ti.sysbios.gates.GateMutex DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_gates_GateMutex_Object__ ti_sysbios_gates_GateMutex_Object__table__V[2];


/*
 * ======== ti.sysbios.hal.Hwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_hal_Hwi_Object__ ti_sysbios_hal_Hwi_Object__table__V[1];


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.Timer DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_hal_Timer_Object__ ti_sysbios_hal_Timer_Object__table__V[1];


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem DECLARATIONS ========
 */

/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096];
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A, 8);
#endif
#ifdef __GNUC__
#if __GNUC__ >= 4
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096] __attribute__ ((aligned(8)));
#endif
#endif

/* Object__table__V */
ti_sysbios_heaps_HeapMem_Object__ ti_sysbios_heaps_HeapMem_Object__table__V[1];


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Clock DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_knl_Clock_Module_State__ {
    volatile xdc_UInt32 ticks;
    xdc_UInt swiCount;
    ti_sysbios_hal_Timer_Handle timer;
    xdc_Void (*doTickFunc)(xdc_UArg);
    ti_sysbios_knl_Swi_Handle swi;
    xdc_UInt32 periodCounts;
    volatile xdc_UInt numTickSkip;
    xdc_UInt skipsWorkFunc;
    xdc_Bool inWorkFunc;
    ti_sysbios_knl_Queue_Object__ Object_field_clockQ;
} ti_sysbios_knl_Clock_Module_State__;

/* Module__state__V */
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V;


/*
 * ======== ti.sysbios.knl.Idle DECLARATIONS ========
 */

/* --> ti_sysbios_hal_Hwi_checkStack */
extern xdc_Void ti_sysbios_hal_Hwi_checkStack(xdc_Void);

/* --> ti_sysbios_knl_Idle_funcList__A */
const __T1_ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__A[1];


/*
 * ======== ti.sysbios.knl.Intrinsics DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Queue DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Semaphore DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Swi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Swi_Module_State__ {
    xdc_Bool locked;
    xdc_UInt curSet;
    xdc_UInt curTrigger;
    ti_sysbios_knl_Swi_Handle curSwi;
    ti_sysbios_knl_Queue_Handle curQ;
    __TA_ti_sysbios_knl_Swi_Module_State__readyQ readyQ;
    __TA_ti_sysbios_knl_Swi_Module_State__constructedSwis constructedSwis;
} ti_sysbios_knl_Swi_Module_State__;

/* --> ti_sysbios_knl_Swi_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Swi_Module_State__readyQ ti_sysbios_knl_Swi_Module_State_0_readyQ__A[16];

/* Module__state__V */
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V;

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restore__E */
extern xdc_Void ti_sysbios_knl_Task_restore__E(xdc_UInt);


/*
 * ======== ti.sysbios.knl.Task DECLARATIONS ========
 */

/* --> ti_sysbios_knl_Task_Instance_State_0_stack__A */
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048];
#ifdef __ti__sect
    #pragma DATA_SECTION(ti_sysbios_knl_Task_Instance_State_0_stack__A, ".far:taskStackSection");
#endif
#ifdef __GNUC__
#if __GNUC__ >= 4
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048] __attribute__ ((section(".far:taskStackSection")));
#endif
#endif
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_knl_Task_Instance_State_0_stack__A, 8);
#endif
#ifdef __GNUC__
#if __GNUC__ >= 4
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048] __attribute__ ((aligned(8)));
#endif
#endif

/* --> ti_sysbios_knl_Task_Instance_State_0_hookEnv__A */
__T1_ti_sysbios_knl_Task_Instance_State__hookEnv ti_sysbios_knl_Task_Instance_State_0_hookEnv__A[1];

/* Object__table__V */
ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Task_Module_State__ {
    xdc_Bool locked;
    volatile xdc_UInt curSet;
    xdc_Bool workFlag;
    xdc_UInt vitalTasks;
    ti_sysbios_knl_Task_Handle curTask;
    ti_sysbios_knl_Queue_Handle curQ;
    __TA_ti_sysbios_knl_Task_Module_State__readyQ readyQ;
    ti_sysbios_knl_Task_Handle idleTask;
    __TA_ti_sysbios_knl_Task_Module_State__constructedTasks constructedTasks;
    ti_sysbios_knl_Queue_Object__ Object_field_inactiveQ;
    ti_sysbios_knl_Queue_Object__ Object_field_terminatedQ;
} ti_sysbios_knl_Task_Module_State__;

/* --> ti_sysbios_knl_Task_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Task_Module_State__readyQ ti_sysbios_knl_Task_Module_State_0_readyQ__A[16];

/* Module__state__V */
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V;

/* --> ti_sysbios_knl_Task_checkStacks */
extern xdc_Void ti_sysbios_knl_Task_checkStacks(ti_sysbios_knl_Task_Handle,ti_sysbios_knl_Task_Handle);

/* --> ti_sysbios_knl_Task_hooks__A */
const __T1_ti_sysbios_knl_Task_hooks ti_sysbios_knl_Task_hooks__A[1];


/*
 * ======== ti.sysbios.knl.Task_SupportProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.timers.dmtimer.Timer DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_timers_dmtimer_Timer_Object__ ti_sysbios_timers_dmtimer_Timer_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_timers_dmtimer_Timer_Module_State__ {
    xdc_Bits32 availMask;
    xdc_runtime_Types_FreqHz intFreq;
    __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__device device;
    __TA_ti_sysbios_timers_dmtimer_Timer_Module_State__handles handles;
    xdc_Bool firstInit;
} ti_sysbios_timers_dmtimer_Timer_Module_State__;

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__device ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A[4];

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__handles ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A[4];

/* Module__state__V */
ti_sysbios_timers_dmtimer_Timer_Module_State__ ti_sysbios_timers_dmtimer_Timer_Module__state__V;


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Assert DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Core DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Defaults DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Diags DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Error DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Error_Module_State__ {
    xdc_UInt16 count;
} xdc_runtime_Error_Module_State__;

/* Module__state__V */
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V;


/*
 * ======== xdc.runtime.Gate DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Log DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Main DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Main_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Memory DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Memory_Module_State__ {
    xdc_SizeT maxDefaultTypeAlign;
} xdc_runtime_Memory_Module_State__;

/* Module__state__V */
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V;


/*
 * ======== xdc.runtime.Memory_HeapProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Registry DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Registry_Module_State__ {
    xdc_runtime_Registry_Desc* listHead;
    xdc_runtime_Types_ModuleId curId;
} xdc_runtime_Registry_Module_State__;

/* Module__state__V */
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V;


/*
 * ======== xdc.runtime.Startup DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Startup_Module_State__ {
    xdc_Int* stateTab;
    xdc_Bool execFlag;
    xdc_Bool rtsDoneFlag;
} xdc_runtime_Startup_Module_State__;

/* Module__state__V */
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V;

/* --> ti_sysbios_hal_Hwi_initStack */
extern xdc_Void ti_sysbios_hal_Hwi_initStack(xdc_Void);

/* --> xdc_runtime_Startup_firstFxns__A */
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[2];

/* --> xdc_runtime_Startup_lastFxns__A */
const __T1_xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__A[1];

/* --> xdc_runtime_System_Module_startup__E */
extern xdc_Int xdc_runtime_System_Module_startup__E(xdc_Int);

/* --> xdc_runtime_SysMin_Module_startup__E */
extern xdc_Int xdc_runtime_SysMin_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_Exception_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_Exception_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_TimestampProvider_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_TimestampProvider_Module_startup__E(xdc_Int);

/* --> ti_sysbios_hal_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_hal_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_hal_Timer_Module_startup__E */
extern xdc_Int ti_sysbios_hal_Timer_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Clock_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Clock_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Swi_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Swi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_knl_Task_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Task_Module_startup__E(xdc_Int);

/* --> ti_sysbios_timers_dmtimer_Timer_Module_startup__E */
extern xdc_Int ti_sysbios_timers_dmtimer_Timer_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_tesla_TimerSupport_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_tesla_TimerSupport_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_c64p_tesla_Wugen_Module_startup__E */
extern xdc_Int ti_sysbios_family_c64p_tesla_Wugen_Module_startup__E(xdc_Int);

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[13];

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[13];


/*
 * ======== xdc.runtime.SysMin DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_SysMin_Module_State__ {
    __TA_xdc_runtime_SysMin_Module_State__outbuf outbuf;
    xdc_UInt outidx;
    xdc_Bool wrapped;
} xdc_runtime_SysMin_Module_State__;

/* --> xdc_runtime_SysMin_Module_State_0_outbuf__A */
__T1_xdc_runtime_SysMin_Module_State__outbuf xdc_runtime_SysMin_Module_State_0_outbuf__A[1024];

/* Module__state__V */
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V;

/* --> xdc_runtime_SysMin_output__I */
extern xdc_Void xdc_runtime_SysMin_output__I(xdc_Char*,xdc_UInt);


/*
 * ======== xdc.runtime.System DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_System_Module_State__ {
    __TA_xdc_runtime_System_Module_State__atexitHandlers atexitHandlers;
    xdc_Int numAtexitHandlers;
    xdc_Int exitStatus;
} xdc_runtime_System_Module_State__;

/* --> xdc_runtime_System_Module_State_0_atexitHandlers__A */
__T1_xdc_runtime_System_Module_State__atexitHandlers xdc_runtime_System_Module_State_0_atexitHandlers__A[8];

/* Module__state__V */
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V;

/* --> xdc_runtime_System_printfExtend__I */
extern xdc_Int xdc_runtime_System_printfExtend__I(xdc_Char**,xdc_Char**,xdc_VaList*,xdc_runtime_System_ParseData*);


/*
 * ======== xdc.runtime.System_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.System_SupportProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Text DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Text_Module_State__ {
    xdc_Ptr charBase;
    xdc_Ptr nodeBase;
} xdc_runtime_Text_Module_State__;

/* Module__state__V */
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V;

/* --> xdc_runtime_Text_charTab__A */
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[6886];

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[52];


/*
 * ======== xdc.runtime.Timestamp DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Timestamp_SupportProxy DECLARATIONS ========
 */


/*
 * ======== OBJECT OFFSETS ========
 */

__FAR__ const xdc_SizeT ti_sysbios_gates_GateMutex_Instance_State_sem__O = offsetof(ti_sysbios_gates_GateMutex_Object__, Object_field_sem);


/*
 * ======== OBJECT OFFSETS ========
 */

__FAR__ const xdc_SizeT ti_sysbios_knl_Clock_Module_State_clockQ__O = offsetof(ti_sysbios_knl_Clock_Module_State__, Object_field_clockQ);


/*
 * ======== OBJECT OFFSETS ========
 */

__FAR__ const xdc_SizeT ti_sysbios_knl_Semaphore_Instance_State_pendQ__O = offsetof(ti_sysbios_knl_Semaphore_Object__, Object_field_pendQ);


/*
 * ======== OBJECT OFFSETS ========
 */

__FAR__ const xdc_SizeT ti_sysbios_knl_Task_Module_State_inactiveQ__O = offsetof(ti_sysbios_knl_Task_Module_State__, Object_field_inactiveQ);
__FAR__ const xdc_SizeT ti_sysbios_knl_Task_Module_State_terminatedQ__O = offsetof(ti_sysbios_knl_Task_Module_State__, Object_field_terminatedQ);


/*
 * ======== xdc.cfg.Program TEMPLATE ========
 */

/*
 *  ======== __ASM__ ========
 *  Define absolute path prefix for this executable's
 *  configuration generated files.
 */
xdc__META(__ASM__, "@(#)__ASM__ = /db/vtree/library/trees/ipc/ipc-h27/src/ti/sdo/ipc/package/cfg/nonInstrumented_pe64T");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = 64T");

/*
 *  ======== __PLAT__ ========
 *  Define the name of the platform that can run this executable.  This
 *  symbol is used by platform independent "exec" commands
 */
xdc__META(__PLAT__, "@(#)__PLAT__ = ti.sdo.ipc.examples.platforms.omap4430.dsp");

/*
 *  ======== __TARG__ ========
 *  Define the name of the target used to build this executable.
 */
xdc__META(__TARG__, "@(#)__TARG__ = ti.targets.elf.C64T");

/*
 *  ======== __TRDR__ ========
 *  Define the name of the class that can read/parse this executable.
 */
xdc__META(__TRDR__, "@(#)__TRDR__ = ti.targets.omf.elf.Elf32");


/*
 * ======== xdc.cfg.SourceDir TEMPLATE ========
 */



/*
 * ======== xdc.runtime.Diags TEMPLATE ========
 */



/*
 * ======== xdc.runtime.Startup TEMPLATE ========
 */

/*
 *  ======== MODULE STARTUP DONE FUNCTIONS ========
 */
xdc_Bool xdc_runtime_System_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[0] < 0;
}
xdc_Bool xdc_runtime_SysMin_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[1] < 0;
}
xdc_Bool ti_sysbios_family_c64p_Exception_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[2] < 0;
}
xdc_Bool ti_sysbios_family_c64p_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[3] < 0;
}
xdc_Bool ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[4] < 0;
}
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[5] < 0;
}
xdc_Bool ti_sysbios_hal_Timer_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[6] < 0;
}
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[7] < 0;
}
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[8] < 0;
}
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[9] < 0;
}
xdc_Bool ti_sysbios_timers_dmtimer_Timer_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[10] < 0;
}
xdc_Bool ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[11] < 0;
}
xdc_Bool ti_sysbios_family_c64p_tesla_Wugen_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[12] < 0;
}

/* 
 * Startup_exec__I is an internal entry point called by target/platform
 * boot code. Boot code is not brought into a partial-link assembly. So,
 * without this pragma, whole program optimizers would otherwise optimize-out
 * this function.
 */
#ifdef __ti__
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_exec__I);
#endif

#ifdef __GNUC__
#if __GNUC__ >= 4
xdc_Void xdc_runtime_Startup_exec__I(void) __attribute__ ((externally_visible));
#endif
#endif

/*
 *  ======== xdc_runtime_Startup_exec__I ========
 *  Initialize all used modules that have startup functions
 */
xdc_Void xdc_runtime_Startup_exec__I(void)
{
    xdc_Int state[13];
    xdc_runtime_Startup_startModsFxn__C(state, 13);
}

/*
 * ======== xdc.runtime.Reset TEMPLATE ========
 */

/* 
 * Startup_reset__I is an internal entry point called by target/platform
 * boot code. Boot code is not brought into a partial-link assembly. So,
 * without this pragma, whole program optimizers would otherwise optimize-out
 * this function.
 */
#ifdef __ti__
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_reset__I);
#endif

#ifdef __GNUC__
#if __GNUC__ >= 4
xdc_Void xdc_runtime_Startup_reset__I(void) __attribute__ ((externally_visible));
#endif
#endif


/*
 *  ======== xdc_runtime_Startup_reset__I ========
 *  This function is called by bootstrap initialization code as early as
 *  possible in the startup process.  This function calls all functions in
 *  the Reset.fxns array _as well as_ Startup.resetFxn (if it's non-NULL)
 */
xdc_Void xdc_runtime_Startup_reset__I(void)
{
}

/*
 * ======== xdc.runtime.System TEMPLATE ========
 */


#include <xdc/std.h>
#include <limits.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Text.h>
#include <xdc/runtime/Assert.h>

/*
 *  ======== System_printfExtend__I ========
 *  This function processes optional extended formats of printf.
 *  
 *  It returns the number of characters added to the result.
 *
 *  Precision (maximum string length) is not supported for %$S.
 *
 *  Right-justified (which is default) minimum width is not supported
 *  for %$L, %$S, or %$F.
 */
Int xdc_runtime_System_printfExtend__I(Char **pbuf, Char **pfmt, 
    VaList *pva, xdc_runtime_System_ParseData *parse)
{
    Char    *fmt = *pfmt;
    Int     res;
    Char    c;
    Bool    found = FALSE;
    
    /* 
     * Create a local variable 'va' to ensure that the dereference of
     * pva only occurs once.
     */
    va_list va = *pva;
    
    res = 0;

    c = *fmt++;
    *pfmt = *pfmt + 1;

    
    if (c == '$') {
        c = *fmt++;
        *pfmt = *pfmt + 1;
        
        if (c == 'L') {
            xdc_runtime_Types_Label *lab = parse->aFlag ? 
                (xdc_runtime_Types_Label *)iargToPtr(va_arg(va, IArg)) :
                (xdc_runtime_Types_Label *)va_arg(va, void *);
            
            /* 
             * Call Text_putLab to write out the label, taking the precision 
             * into account.
             */
            res = xdc_runtime_Text_putLab(lab, pbuf, parse->precis);
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr.
             */
            parse->len = 0;
            
            /* Update the minimum width field. */
            parse->width -= res;
            
            found = TRUE;
        }
        
        if (c == 'F') {
            xdc_runtime_Types_Site site;
            
            /* Retrieve the file name string from the argument list */
            site.file = parse->aFlag ? (Char *) iargToPtr(va_arg(va, IArg)) :
                                       (Char *) va_arg(va, Char *);
            
            /* Retrieve the line number from the argument list. */
            site.line = parse->aFlag ? (Int) va_arg(va, IArg) : 
                                       (Int) va_arg(va, Int);
            
            /* 
             * Omit the 'mod' field, set it to 0.
             * '0' is a safe sentinel value - the IDs for named modules are 
             * 0x8000 and higher, and the IDs for unnamed modules go from 0x1
             * to 0x7fff.
             */
            site.mod = 0;
            
            /* 
             * Call putSite to format the file and line number.
             * If a precision was specified, it will be used as the maximum
             * string lengrth.
             */
            res = xdc_runtime_Text_putSite(&site, pbuf, parse->precis);
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr.
             */
            parse->len = 0;
       
            /* Update the minimum width field */
            parse->width -= res;
            
            found = TRUE;
        }
        
        if (c == 'S') {
            /* Retrieve the format string from the argument list */
            parse->ptr = parse->aFlag ? 
                (Char *) iargToPtr(va_arg(va, IArg)) :
                (Char *) va_arg(va, Char *);
            
            /* Update pva before passing it to doPrint. */
            *pva = va;
            
            /* Perform the recursive format. System_doPrint does not advance
             * the buffer pointer, so it has to be done explicitly.
             */
            res = xdc_runtime_System_doPrint__I(*pbuf, parse->ptr, pva, parse->aFlag);
            if (*pbuf) {
                *pbuf += res;
            }
            
            /* Update the temporary variable with any changes to *pva */
            va = *pva;
            
            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr
             */
            parse->len = 0;

            /* Update the minimum width field */
            parse->width -= res;
            
            /* Indicate that we were able to interpret the specifier */
            found = TRUE;
        }
        
    }

    if (c == 'f') {
        /* support arguments _after_ optional float support */
        if (parse->aFlag) {
            (void)va_arg(va, IArg);
        }
        else {
            (void)va_arg(va, double);
        }
    }    

    if (found == FALSE) {
        /* other character (like %) copy to output */
        *(parse->ptr) = c;
        parse->len = 1;
    }

    /*
     * Before returning, we must update the value of pva. We use a label here
     * so that all return points will go through this update.
     * The 'goto end' is here to ensure that there is always a reference to the
     * label (to avoid the compiler complaining). 
     */
    goto end; 
end:
    *pva = va;
    return (res);
}

/*
 * ======== xdc.runtime.SysMin TEMPLATE ========
 */


#if defined(__ti__) || (defined(gnu_targets_STD_) && defined(xdc_target__os_undefined))
extern int HOSTwrite(int, const char *, unsigned);
#else
#include <stdio.h>
#endif

/*
 *  ======== SysMin_output__I ========
 *  HOSTWrite only writes a max of N chars at a time. The amount it writes
 *  is returned. This function loops until the entire buffer is written.
 *  Being a static function allows it to conditionally compile out.
 */
Void xdc_runtime_SysMin_output__I(Char *buf, UInt size)
{
#if defined(__ti__) || (defined(gnu_targets_STD_) && defined(xdc_target__os_undefined))
    Int printCount;
    
    while (size != 0) {
        printCount = HOSTwrite(1, buf, size);
        if ((printCount <= 0) || (printCount > size)) {
            break;  /* ensure we never get stuck in an infinite loop */
        }
        size -= printCount;
        buf = buf + printCount;
    }    
#else
    fwrite(buf, 1, size, stdout);
#endif
}

/*
 * ======== xdc.runtime.Text TEMPLATE ========
 */


/*
 *  ======== xdc_runtime_Text_visitRope__I ========
 *  This function is indirectly called within Text.c through
 *  the visitRopeFxn configuration parameter of xdc.runtime.Text.
 */
Void xdc_runtime_Text_visitRope__I(xdc_runtime_Text_RopeId rope,
    xdc_Fxn visFxn, xdc_Ptr visState)
{
    xdc_String stack[6];
    xdc_runtime_Text_visitRope2__I(rope, visFxn, visState, stack);
}


/*
 * ======== ti.sysbios.family.c64p.Hwi TEMPLATE ========
 */


asm("           .sect \".vecs\"         ");
asm("           .align 0x400            ");
asm("           .nocmp                  ");
asm("           .global ti_sysbios_family_c64p_Hwi0         ");
asm("           .global _c_int00         ");
asm("ti_sysbios_family_c64p_Hwi0:                           ");
asm("           nop                     ");
asm("           nop                     ");
asm("           nop                     ");
asm("           mvkl    _c_int00, b0     ");
asm("           mvkh    _c_int00, b0     ");
asm("           b       b0              ");
asm("           nop                     ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi1         ");
asm("           .global ti_sysbios_family_c64p_Exception_dispatch__E         ");
asm("ti_sysbios_family_c64p_Hwi1:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     1, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Exception_dispatch__E, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Exception_dispatch__E, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi2         ");
asm("           .global ti_sysbios_family_c64p_Hwi2         ");
asm("ti_sysbios_family_c64p_Hwi2:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     2, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi2, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi2, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi3         ");
asm("           .global ti_sysbios_family_c64p_Hwi3         ");
asm("ti_sysbios_family_c64p_Hwi3:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     3, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi3, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi3, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi4         ");
asm("           .global ti_sysbios_family_c64p_Hwi4         ");
asm("ti_sysbios_family_c64p_Hwi4:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     4, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi4, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi4, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi5         ");
asm("           .global ti_sysbios_family_c64p_Hwi5         ");
asm("ti_sysbios_family_c64p_Hwi5:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     5, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi5, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi5, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi6         ");
asm("           .global ti_sysbios_family_c64p_Hwi6         ");
asm("ti_sysbios_family_c64p_Hwi6:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     6, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi6, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi6, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi7         ");
asm("           .global ti_sysbios_family_c64p_Hwi7         ");
asm("ti_sysbios_family_c64p_Hwi7:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     7, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi7, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi7, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi8         ");
asm("           .global ti_sysbios_family_c64p_Hwi8         ");
asm("ti_sysbios_family_c64p_Hwi8:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     8, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi8, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi8, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi9         ");
asm("           .global ti_sysbios_family_c64p_Hwi9         ");
asm("ti_sysbios_family_c64p_Hwi9:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     9, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi9, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi9, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi10         ");
asm("           .global ti_sysbios_family_c64p_Hwi10         ");
asm("ti_sysbios_family_c64p_Hwi10:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     10, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi10, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi10, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi11         ");
asm("           .global ti_sysbios_family_c64p_Hwi11         ");
asm("ti_sysbios_family_c64p_Hwi11:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     11, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi11, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi11, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi12         ");
asm("           .global ti_sysbios_family_c64p_Hwi12         ");
asm("ti_sysbios_family_c64p_Hwi12:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     12, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi12, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi12, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi13         ");
asm("           .global ti_sysbios_family_c64p_Hwi13         ");
asm("ti_sysbios_family_c64p_Hwi13:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     13, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi13, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi13, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi14         ");
asm("           .global ti_sysbios_family_c64p_Hwi_dispatchAlways         ");
asm("ti_sysbios_family_c64p_Hwi14:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     14, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi_dispatchAlways, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");

asm("           .global ti_sysbios_family_c64p_Hwi15         ");
asm("           .global ti_sysbios_family_c64p_Hwi15         ");
asm("ti_sysbios_family_c64p_Hwi15:                           ");
asm("           stw     b0, *b15--      ");
asm("           mvk     15, b0         ");
asm("           stw     b0, *b15        ");
asm("           mvkl    ti_sysbios_family_c64p_Hwi15, b0     ");
asm("           mvkh    ti_sysbios_family_c64p_Hwi15, b0     ");
asm("           b       b0              ");
asm("           ldw     *++b15, b0      ");
asm("           nop     4               ");




/*
 * ======== ti.sysbios.hal.Hwi TEMPLATE ========
 */

#ifdef __ti__
    #pragma FUNC_EXT_CALLED(ti_sysbios_hal_Hwi_HwiProxy_disable__E);
    #pragma FUNC_EXT_CALLED(ti_sysbios_hal_Hwi_HwiProxy_enable__E);
    #pragma FUNC_EXT_CALLED(ti_sysbios_hal_Hwi_HwiProxy_restore__E);
#endif

/*
 * ======== ti.sysbios.knl.Clock TEMPLATE ========
 */

Void ti_sysbios_knl_Clock_doTick__I(UArg arg) 
{
    /* update system time */
    (&ti_sysbios_knl_Clock_Module__state__V)->ticks++;

    (&ti_sysbios_knl_Clock_Module__state__V)->swiCount++;

    ti_sysbios_knl_Clock_logTick__E();

    if (!ti_sysbios_knl_Queue_empty(ti_sysbios_knl_Clock_Module_State_clockQ())) {

        ti_sysbios_knl_Swi_post((&ti_sysbios_knl_Clock_Module__state__V)->swi);

    }
}

/*
 * ======== ti.sdo.utils.Build TEMPLATE ========
 */



/*
 * ======== ti.sdo.ipc.Build TEMPLATE ========
 */



/*
 * ======== ti.sysbios.BIOS TEMPLATE ========
 */

Void ti_sysbios_BIOS_exitFunc__I(Int);

extern Void ti_sysbios_BIOS_registerRTSLock();

Void ti_sysbios_BIOS_startFunc__I()
{
    xdc_runtime_System_atexit(
	(xdc_runtime_System_AtexitHandler)ti_sysbios_BIOS_exitFunc__I);
    ti_sysbios_BIOS_registerRTSLock();
    ti_sysbios_hal_Hwi_startup();
    ti_sysbios_hal_Timer_startup();
    ti_sysbios_knl_Swi_startup();
    ti_sysbios_knl_Task_startup();
}

#if defined(__ti__)
#include <_lock.h>
#endif

Void ti_sysbios_BIOS_exitFunc__I(Int notused)
{
    ti_sysbios_knl_Swi_disable();
    ti_sysbios_knl_Task_disable();
    ti_sysbios_BIOS_setThreadType(ti_sysbios_BIOS_ThreadType_Main);

#if defined(__ti__)
    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGate != NULL) {
	_register_lock(_nop);
	_register_unlock(_nop);
    }
#endif
}




#if defined(__ti__)

#pragma FUNC_EXT_CALLED(malloc);
#pragma FUNC_EXT_CALLED(memalign);
#pragma FUNC_EXT_CALLED(free);
#pragma FUNC_EXT_CALLED(calloc);
#pragma FUNC_EXT_CALLED(realloc);

#define ATTRIBUTE

#else

#define ATTRIBUTE __attribute__ ((used))

#endif

#include <xdc/std.h>

#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <stdlib.h>
#include <string.h>

/* malloc header */
typedef struct Header {
    Ptr   actualBuf;
    UArg  size;
} Header;

/*
 *  ======== malloc ========
 */
Void ATTRIBUTE *malloc(SizeT size)
{
    Header *packet;
    xdc_runtime_Error_Block eb;

    xdc_runtime_Error_init(&eb);

    if (size == 0) {
	return (NULL);
    }

    packet = (Header *)xdc_runtime_Memory_alloc(NULL,
	(SizeT)(size + sizeof(Header)), 0, &eb);

    if (packet == NULL) {
	return (NULL);
    }

    packet->actualBuf = (Ptr)packet;
    packet->size = size + sizeof(Header);

    return (packet + 1);
}

/*
 *  ======== memalign ========
 *  mirrors the memalign() function from the TI run-time library
 */
Void ATTRIBUTE *memalign(SizeT alignment, SizeT size)
{
    Header                      *packet;
    Void                        *tmp;
    xdc_runtime_Error_Block     eb;

    xdc_runtime_Error_init(&eb);

    if (size == 0) {
	return (NULL);
    }

    /*
     * If alignment is not a power of two or is less than the minimum
     * alignment of malloc(), then simply return what malloc() returns.
     * (same as behaviour as RTS library's memalign())
     * Note: HeapMem's header is the same as this header after it is raised
     * to a power of 2.
     */
    if (alignment <= sizeof(Header) || (alignment & (alignment-1))) {
	return malloc(size);
    }

    /*
     * Allocate 'align + size' so that we have room for the 'packet'
     * and can return an aligned buffer.
     */
    tmp = xdc_runtime_Memory_alloc(NULL, alignment + size,
	(SizeT)alignment, &eb);

    if (tmp == NULL) {
	return (NULL);
    }

    packet = (Header *)((char *)tmp + alignment - sizeof(Header));

    packet->actualBuf = tmp;
    packet->size = size + sizeof(Header);

    return (packet + 1);
}

/*
 *  ======== calloc ========
 */
Void ATTRIBUTE *calloc(SizeT nmemb, SizeT size)
{
    SizeT       nbytes;
    Ptr         retval;

    nbytes = nmemb * size;

    retval = malloc(nbytes);
    if (retval != NULL) {
	(Void)memset(retval, (Int)'\0', nbytes);
    }

    return (retval);
}

/*
 *  ======== free ========
 */
Void ATTRIBUTE free(Void *ptr)
{
    Header      *packet;

    if (ptr != NULL) {
	packet = ((Header *)ptr) - 1;

	xdc_runtime_Memory_free(NULL, (Ptr)packet->actualBuf,
	    (packet->size + ((char*)packet - (char*)packet->actualBuf)));
    }
}

/*
 *  ======== realloc ========
 */
Void ATTRIBUTE *realloc(Void *ptr, SizeT size)
{
    Ptr         retval;
    Header      *packet;
    SizeT       oldSize;

    if (ptr == NULL) {
	retval = malloc(size);
    }
    else if (size == 0) {
	free(ptr);
	retval = NULL;
    }
    else {
	packet = (Header *)ptr - 1;
	retval = malloc(size);
	if (retval != NULL) {
	    oldSize = packet->size - sizeof(Header);
	    (Void)memcpy(retval, ptr, (size < oldSize) ? size : oldSize);
	    free(ptr);
	}
    }

    return (retval);
}


/*
 * ======== ti.sdo.utils.NameServerRemoteNull INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sdo_utils_NameServerRemoteNull_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sdo_utils_NameServerRemoteNull_Params ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C = {
    sizeof (ti_sdo_utils_NameServerRemoteNull_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sdo_utils_NameServerRemoteNull_Module__ ti_sdo_utils_NameServerRemoteNull_Module__root__V = {
    {&ti_sdo_utils_NameServerRemoteNull_Module__root__V.link,  /* link.next */
    &ti_sdo_utils_NameServerRemoteNull_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__diagsEnabled ti_sdo_utils_NameServerRemoteNull_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__diagsIncluded ti_sdo_utils_NameServerRemoteNull_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__diagsMask ti_sdo_utils_NameServerRemoteNull_Module__diagsMask__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__gateObj ti_sdo_utils_NameServerRemoteNull_Module__gateObj__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__gatePrms ti_sdo_utils_NameServerRemoteNull_Module__gatePrms__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__id ti_sdo_utils_NameServerRemoteNull_Module__id__C = (xdc_Bits16)0x8027;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerDefined ti_sdo_utils_NameServerRemoteNull_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerObj ti_sdo_utils_NameServerRemoteNull_Module__loggerObj__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn0 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn0__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn1 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn1__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn2 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn2__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn4 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn4__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn8 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn8__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__startupDoneFxn ti_sdo_utils_NameServerRemoteNull_Module__startupDoneFxn__C = ((CT__ti_sdo_utils_NameServerRemoteNull_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Object__count ti_sdo_utils_NameServerRemoteNull_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Object__heap ti_sdo_utils_NameServerRemoteNull_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Object__sizeof ti_sdo_utils_NameServerRemoteNull_Object__sizeof__C = sizeof(ti_sdo_utils_NameServerRemoteNull_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Object__table ti_sdo_utils_NameServerRemoteNull_Object__table__C = 0;


/*
 * ======== ti.sysbios.BIOS INITIALIZERS ========
 */

/* Module__state__V */
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V = {
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x1bc69880,  /* lo */
    },  /* cpuFreq */
    (xdc_UInt)0x0,  /* rtsGateCount */
    ((xdc_IArg)(0x0)),  /* rtsGateKey */
    (ti_sysbios_BIOS_RtsGateProxy_Handle)&ti_sysbios_gates_GateMutex_Object__table__V[1],  /* rtsGate */
    ti_sysbios_BIOS_ThreadType_Main,  /* threadType */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_BIOS_startFunc)),  /* startFunc */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsEnabled ti_sysbios_BIOS_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsIncluded ti_sysbios_BIOS_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__diagsMask ti_sysbios_BIOS_Module__diagsMask__C = ((CT__ti_sysbios_BIOS_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__gateObj ti_sysbios_BIOS_Module__gateObj__C = ((CT__ti_sysbios_BIOS_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__gatePrms ti_sysbios_BIOS_Module__gatePrms__C = ((CT__ti_sysbios_BIOS_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__id ti_sysbios_BIOS_Module__id__C = (xdc_Bits16)0x8028;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerDefined ti_sysbios_BIOS_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerObj ti_sysbios_BIOS_Module__loggerObj__C = ((CT__ti_sysbios_BIOS_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn0 ti_sysbios_BIOS_Module__loggerFxn0__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn1 ti_sysbios_BIOS_Module__loggerFxn1__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn2 ti_sysbios_BIOS_Module__loggerFxn2__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn4 ti_sysbios_BIOS_Module__loggerFxn4__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn8 ti_sysbios_BIOS_Module__loggerFxn8__C = ((CT__ti_sysbios_BIOS_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_BIOS_Module__startupDoneFxn ti_sysbios_BIOS_Module__startupDoneFxn__C = ((CT__ti_sysbios_BIOS_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_BIOS_Object__count ti_sysbios_BIOS_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_BIOS_Object__heap ti_sysbios_BIOS_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_BIOS_Object__sizeof ti_sysbios_BIOS_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_BIOS_Object__table ti_sysbios_BIOS_Object__table__C = 0;

/* cpuFreq__C */
__FAR__ const CT__ti_sysbios_BIOS_cpuFreq ti_sysbios_BIOS_cpuFreq__C = {
    (xdc_Bits32)0x0,  /* hi */
    (xdc_Bits32)0x1bc69880,  /* lo */
};

/* taskEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_taskEnabled ti_sysbios_BIOS_taskEnabled__C = 1;

/* swiEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_swiEnabled ti_sysbios_BIOS_swiEnabled__C = 1;

/* clockEnabled__C */
__FAR__ const CT__ti_sysbios_BIOS_clockEnabled ti_sysbios_BIOS_clockEnabled__C = 1;

/* heapSize__C */
__FAR__ const CT__ti_sysbios_BIOS_heapSize ti_sysbios_BIOS_heapSize__C = (xdc_SizeT)0x1000;

/* heapSection__C */
__FAR__ const CT__ti_sysbios_BIOS_heapSection ti_sysbios_BIOS_heapSection__C = 0;

/* installedErrorHook__C */
__FAR__ const CT__ti_sysbios_BIOS_installedErrorHook ti_sysbios_BIOS_installedErrorHook__C = ((CT__ti_sysbios_BIOS_installedErrorHook)((xdc_Fxn)xdc_runtime_Error_print__E));


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.family.c62.IntrinsicsSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__id ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C = (xdc_Bits16)0x802b;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8 ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__count ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__heap ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c62_IntrinsicsSupport_Object__table ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.c62.TaskSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__diagsMask ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__gateObj ti_sysbios_family_c62_TaskSupport_Module__gateObj__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__gatePrms ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__id ti_sysbios_family_c62_TaskSupport_Module__id__C = (xdc_Bits16)0x802a;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerDefined ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerObj ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8 ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__count ti_sysbios_family_c62_TaskSupport_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__heap ti_sysbios_family_c62_TaskSupport_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__sizeof ti_sysbios_family_c62_TaskSupport_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_Object__table ti_sysbios_family_c62_TaskSupport_Object__table__C = 0;

/* defaultStackSize__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_defaultStackSize ti_sysbios_family_c62_TaskSupport_defaultStackSize__C = (xdc_SizeT)0x800;

/* stackAlignment__C */
__FAR__ const CT__ti_sysbios_family_c62_TaskSupport_stackAlignment ti_sysbios_family_c62_TaskSupport_stackAlignment__C = (xdc_UInt)0x8;


/*
 * ======== ti.sysbios.family.c64p.Exception INITIALIZERS ========
 */

/* Module__state__V */
ti_sysbios_family_c64p_Exception_Module_State__ ti_sysbios_family_c64p_Exception_Module__state__V = {
    (xdc_Bits32)0x0,  /* efr */
    (xdc_Bits32)0x0,  /* nrp */
    (xdc_Bits32)0x0,  /* ntsr */
    (xdc_Bits32)0x0,  /* ierr */
    ((xdc_Void(*)(xdc_Void))0),  /* returnHook */
    ((ti_sysbios_family_c64p_Exception_Context*)0),  /* excContext */
    {
        (xdc_Char)0x0,  /* [0] */
        (xdc_Char)0x0,  /* [1] */
        (xdc_Char)0x0,  /* [2] */
        (xdc_Char)0x0,  /* [3] */
        (xdc_Char)0x0,  /* [4] */
        (xdc_Char)0x0,  /* [5] */
        (xdc_Char)0x0,  /* [6] */
        (xdc_Char)0x0,  /* [7] */
        (xdc_Char)0x0,  /* [8] */
        (xdc_Char)0x0,  /* [9] */
        (xdc_Char)0x0,  /* [10] */
        (xdc_Char)0x0,  /* [11] */
        (xdc_Char)0x0,  /* [12] */
        (xdc_Char)0x0,  /* [13] */
        (xdc_Char)0x0,  /* [14] */
        (xdc_Char)0x0,  /* [15] */
    },  /* scratch */
    ((xdc_Char*)0),  /* isrStack */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsEnabled ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C = (xdc_Bits32)0x190;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsIncluded ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C = (xdc_Bits32)0x190;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__diagsMask ti_sysbios_family_c64p_Exception_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_Exception_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__gateObj ti_sysbios_family_c64p_Exception_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_Exception_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__gatePrms ti_sysbios_family_c64p_Exception_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_Exception_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__id ti_sysbios_family_c64p_Exception_Module__id__C = (xdc_Bits16)0x8014;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerDefined ti_sysbios_family_c64p_Exception_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerObj ti_sysbios_family_c64p_Exception_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn0 ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn1 ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn2 ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn4 ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn8 ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_Exception_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Module__startupDoneFxn ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_Exception_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__count ti_sysbios_family_c64p_Exception_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__heap ti_sysbios_family_c64p_Exception_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__sizeof ti_sysbios_family_c64p_Exception_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_Object__table ti_sysbios_family_c64p_Exception_Object__table__C = 0;

/* E_exceptionMin__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_E_exceptionMin ti_sysbios_family_c64p_Exception_E_exceptionMin__C = (((xdc_runtime_Error_Id)4376) << 16 | 0);

/* E_exceptionMax__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_E_exceptionMax ti_sysbios_family_c64p_Exception_E_exceptionMax__C = (((xdc_runtime_Error_Id)4518) << 16 | 0);

/* enableExternalMPC__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_enableExternalMPC ti_sysbios_family_c64p_Exception_enableExternalMPC__C = 0;

/* enablePrint__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_enablePrint ti_sysbios_family_c64p_Exception_enablePrint__C = 1;

/* exceptionHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_exceptionHook ti_sysbios_family_c64p_Exception_exceptionHook__C = ((CT__ti_sysbios_family_c64p_Exception_exceptionHook)0);

/* internalHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_internalHook ti_sysbios_family_c64p_Exception_internalHook__C = ((CT__ti_sysbios_family_c64p_Exception_internalHook)0);

/* externalHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_externalHook ti_sysbios_family_c64p_Exception_externalHook__C = ((CT__ti_sysbios_family_c64p_Exception_externalHook)0);

/* nmiHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_nmiHook ti_sysbios_family_c64p_Exception_nmiHook__C = ((CT__ti_sysbios_family_c64p_Exception_nmiHook)0);

/* returnHook__C */
__FAR__ const CT__ti_sysbios_family_c64p_Exception_returnHook ti_sysbios_family_c64p_Exception_returnHook__C = ((CT__ti_sysbios_family_c64p_Exception_returnHook)0);


/*
 * ======== ti.sysbios.family.c64p.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c64p_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_family_c64p_Hwi_Params ti_sysbios_family_c64p_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_c64p_Hwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_c64p_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)0x0,  /* priority */
    (xdc_Bits16)0x0,  /* disableMask */
    (xdc_Bits16)0x0,  /* restoreMask */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_family_c64p_Hwi_Instance_State_0_hookEnv__A */
__T1_ti_sysbios_family_c64p_Hwi_Instance_State__hookEnv ti_sysbios_family_c64p_Hwi_Instance_State_0_hookEnv__A[1];

/* Module__root__V */
ti_sysbios_family_c64p_Hwi_Module__ ti_sysbios_family_c64p_Hwi_Module__root__V = {
    {&ti_sysbios_family_c64p_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_c64p_Hwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_c64p_Hwi_Object__ ti_sysbios_family_c64p_Hwi_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (xdc_Bits16)0x4000,  /* disableMask */
        (xdc_Bits16)0x4000,  /* restoreMask */
        ((xdc_UArg)((void*)(ti_sysbios_timers_dmtimer_Timer_Handle)&ti_sysbios_timers_dmtimer_Timer_Object__table__V[0])),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_stub__E)),  /* fxn */
        ((xdc_UArg)0),  /* irp */
        ((void*)ti_sysbios_family_c64p_Hwi_Instance_State_0_hookEnv__A),  /* hookEnv */
    },
};

/* Module__state__V */
ti_sysbios_family_c64p_Hwi_Module_State__ ti_sysbios_family_c64p_Hwi_Module__state__V = {
    {
        (xdc_Char)(-0x0 - 1),  /* [0] */
        (xdc_Char)(-0x0 - 1),  /* [1] */
        (xdc_Char)(-0x0 - 1),  /* [2] */
        (xdc_Char)(-0x0 - 1),  /* [3] */
        (xdc_Char)(-0x0 - 1),  /* [4] */
        (xdc_Char)(-0x0 - 1),  /* [5] */
        (xdc_Char)(-0x0 - 1),  /* [6] */
        (xdc_Char)(-0x0 - 1),  /* [7] */
        (xdc_Char)(-0x0 - 1),  /* [8] */
        (xdc_Char)(-0x0 - 1),  /* [9] */
        (xdc_Char)0x33,  /* [10] */
        (xdc_Char)(-0x0 - 1),  /* [11] */
    },  /* intEvents */
    (xdc_Bits16)0x4003,  /* ierMask */
    (xdc_Int)0x0,  /* intNum */
    ((xdc_Char*)0),  /* taskSP */
    ((xdc_Char*)0),  /* isrStack */
    ((xdc_Ptr)((void*)&ti_sysbios_family_c64p_Hwi0)),  /* vectorTableBase */
    ((xdc_Ptr)((void*)&__TI_STATIC_BASE)),  /* bss */
    {
        0,  /* [0] */
        0,  /* [1] */
        0,  /* [2] */
        0,  /* [3] */
        0,  /* [4] */
        0,  /* [5] */
        0,  /* [6] */
        0,  /* [7] */
        0,  /* [8] */
        0,  /* [9] */
        0,  /* [10] */
        0,  /* [11] */
        0,  /* [12] */
        0,  /* [13] */
        (ti_sysbios_family_c64p_Hwi_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[0],  /* [14] */
        0,  /* [15] */
    },  /* dispatchTable */
};

/* --> ti_sysbios_family_c64p_Hwi_hooks__A */
const __T1_ti_sysbios_family_c64p_Hwi_hooks ti_sysbios_family_c64p_Hwi_hooks__A[1] = {
    {
        ((xdc_Void(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_tesla_Wugen_hwiRegisterHook__I)),  /* registerFxn */
        ((xdc_Void(*)(ti_sysbios_interfaces_IHwi_Handle,xdc_runtime_Error_Block*))((xdc_Fxn)ti_sysbios_family_c64p_tesla_Wugen_hwiCreateHook__I)),  /* createFxn */
        ((xdc_Void(*)(ti_sysbios_interfaces_IHwi_Handle))0),  /* beginFxn */
        ((xdc_Void(*)(ti_sysbios_interfaces_IHwi_Handle))((xdc_Fxn)ti_sysbios_family_c64p_tesla_Wugen_hwiBeginHook__I)),  /* endFxn */
        ((xdc_Void(*)(ti_sysbios_interfaces_IHwi_Handle))0),  /* deleteFxn */
    },  /* [0] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsEnabled ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsIncluded ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__diagsMask ti_sysbios_family_c64p_Hwi_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__gateObj ti_sysbios_family_c64p_Hwi_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__gatePrms ti_sysbios_family_c64p_Hwi_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__id ti_sysbios_family_c64p_Hwi_Module__id__C = (xdc_Bits16)0x8015;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerDefined ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerObj ti_sysbios_family_c64p_Hwi_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn0 ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn1 ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn2 ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn4 ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn8 ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__count ti_sysbios_family_c64p_Hwi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__heap ti_sysbios_family_c64p_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__sizeof ti_sysbios_family_c64p_Hwi_Object__sizeof__C = sizeof(ti_sysbios_family_c64p_Hwi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_Object__table ti_sysbios_family_c64p_Hwi_Object__table__C = ti_sysbios_family_c64p_Hwi_Object__table__V;

/* dispatcherAutoNestingSupport__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* E_alreadyDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_E_alreadyDefined ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C = (((xdc_runtime_Error_Id)4560) << 16 | 0);

/* LM_begin__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_LM_begin ti_sysbios_family_c64p_Hwi_LM_begin__C = (((xdc_runtime_Log_Event)5806) << 16 | 768);

/* LD_end__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_LD_end ti_sysbios_family_c64p_Hwi_LD_end__C = (((xdc_runtime_Log_Event)5876) << 16 | 512);

/* enableException__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_enableException ti_sysbios_family_c64p_Hwi_enableException__C = 1;

/* swiDisable__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_swiDisable ti_sysbios_family_c64p_Hwi_swiDisable__C = ((CT__ti_sysbios_family_c64p_Hwi_swiDisable)((xdc_Fxn)ti_sysbios_knl_Swi_disable__E));

/* swiRestoreHwi__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_swiRestoreHwi ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C = ((CT__ti_sysbios_family_c64p_Hwi_swiRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Swi_restoreHwi__E));

/* taskDisable__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_taskDisable ti_sysbios_family_c64p_Hwi_taskDisable__C = ((CT__ti_sysbios_family_c64p_Hwi_taskDisable)((xdc_Fxn)ti_sysbios_knl_Task_disable__E));

/* taskRestoreHwi__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_taskRestoreHwi ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C = ((CT__ti_sysbios_family_c64p_Hwi_taskRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Task_restoreHwi__E));

/* hooks__C */
__FAR__ const CT__ti_sysbios_family_c64p_Hwi_hooks ti_sysbios_family_c64p_Hwi_hooks__C = {1, ((__T1_ti_sysbios_family_c64p_Hwi_hooks*)ti_sysbios_family_c64p_Hwi_hooks__A)};


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__gateObj ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__id ti_sysbios_family_c64p_TimestampProvider_Module__id__C = (xdc_Bits16)0x8016;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8 ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__count ti_sysbios_family_c64p_TimestampProvider_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__heap ti_sysbios_family_c64p_TimestampProvider_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__sizeof ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_TimestampProvider_Object__table ti_sysbios_family_c64p_TimestampProvider_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.c64p.tesla.TimerSupport INITIALIZERS ========
 */

/* --> ti_sysbios_family_c64p_tesla_TimerSupport_Module_State_0_suspSrc__A */
__T1_ti_sysbios_family_c64p_tesla_TimerSupport_Module_State__suspSrc ti_sysbios_family_c64p_tesla_TimerSupport_Module_State_0_suspSrc__A[4] = {
    ti_sysbios_family_c64p_tesla_TimerSupport_SuspSrc_DSP,  /* [0] */
    ti_sysbios_family_c64p_tesla_TimerSupport_SuspSrc_DSP,  /* [1] */
    ti_sysbios_family_c64p_tesla_TimerSupport_SuspSrc_DSP,  /* [2] */
    ti_sysbios_family_c64p_tesla_TimerSupport_SuspSrc_DSP,  /* [3] */
};

/* Module__state__V */
ti_sysbios_family_c64p_tesla_TimerSupport_Module_State__ ti_sysbios_family_c64p_tesla_TimerSupport_Module__state__V = {
    ((void*)ti_sysbios_family_c64p_tesla_TimerSupport_Module_State_0_suspSrc__A),  /* suspSrc */
};

/* --> ti_sysbios_family_c64p_tesla_TimerSupport_timer__A */
const __T1_ti_sysbios_family_c64p_tesla_TimerSupport_timer ti_sysbios_family_c64p_tesla_TimerSupport_timer__A[4] = {
    {
        ti_sysbios_family_c64p_tesla_TimerSupport_SuspSrc_DSP,  /* suspSrc */
    },  /* [0] */
    {
        ti_sysbios_family_c64p_tesla_TimerSupport_SuspSrc_DSP,  /* suspSrc */
    },  /* [1] */
    {
        ti_sysbios_family_c64p_tesla_TimerSupport_SuspSrc_DSP,  /* suspSrc */
    },  /* [2] */
    {
        ti_sysbios_family_c64p_tesla_TimerSupport_SuspSrc_DSP,  /* suspSrc */
    },  /* [3] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsEnabled ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsIncluded ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsMask ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__gateObj ti_sysbios_family_c64p_tesla_TimerSupport_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__gatePrms ti_sysbios_family_c64p_tesla_TimerSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__id ti_sysbios_family_c64p_tesla_TimerSupport_Module__id__C = (xdc_Bits16)0x8030;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerDefined ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerObj ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn0 ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn1 ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn2 ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn4 ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn8 ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDoneFxn ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Object__count ti_sysbios_family_c64p_tesla_TimerSupport_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Object__heap ti_sysbios_family_c64p_tesla_TimerSupport_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Object__sizeof ti_sysbios_family_c64p_tesla_TimerSupport_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_Object__table ti_sysbios_family_c64p_tesla_TimerSupport_Object__table__C = 0;

/* timer__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_timer ti_sysbios_family_c64p_tesla_TimerSupport_timer__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_timer)ti_sysbios_family_c64p_tesla_TimerSupport_timer__A);

/* controlMsuspendMux1Addr__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_TimerSupport_controlMsuspendMux1Addr ti_sysbios_family_c64p_tesla_TimerSupport_controlMsuspendMux1Addr__C = ((CT__ti_sysbios_family_c64p_tesla_TimerSupport_controlMsuspendMux1Addr)((void*)0x49002294));


/*
 * ======== ti.sysbios.family.c64p.tesla.Wugen INITIALIZERS ========
 */

/* Module__state__V */
ti_sysbios_family_c64p_tesla_Wugen_Module_State__ ti_sysbios_family_c64p_tesla_Wugen_Module__state__V = {
    (xdc_Int)0x0,  /* hwiHookId */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__diagsEnabled ti_sysbios_family_c64p_tesla_Wugen_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__diagsIncluded ti_sysbios_family_c64p_tesla_Wugen_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__diagsMask ti_sysbios_family_c64p_tesla_Wugen_Module__diagsMask__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__gateObj ti_sysbios_family_c64p_tesla_Wugen_Module__gateObj__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__gatePrms ti_sysbios_family_c64p_tesla_Wugen_Module__gatePrms__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__id ti_sysbios_family_c64p_tesla_Wugen_Module__id__C = (xdc_Bits16)0x8031;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerDefined ti_sysbios_family_c64p_tesla_Wugen_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerObj ti_sysbios_family_c64p_tesla_Wugen_Module__loggerObj__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn0 ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn0__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn1 ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn1__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn2 ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn2__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn4 ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn4__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn8 ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn8__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Module__startupDoneFxn ti_sysbios_family_c64p_tesla_Wugen_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_c64p_tesla_Wugen_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Object__count ti_sysbios_family_c64p_tesla_Wugen_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Object__heap ti_sysbios_family_c64p_tesla_Wugen_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Object__sizeof ti_sysbios_family_c64p_tesla_Wugen_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_c64p_tesla_Wugen_Object__table ti_sysbios_family_c64p_tesla_Wugen_Object__table__C = 0;


/*
 * ======== ti.sysbios.gates.GateHwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateHwi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_gates_GateHwi_Params ti_sysbios_gates_GateHwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_gates_GateHwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_gates_GateHwi_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_gates_GateHwi_Module__ ti_sysbios_gates_GateHwi_Module__root__V = {
    {&ti_sysbios_gates_GateHwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_gates_GateHwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_gates_GateHwi_Object__ ti_sysbios_gates_GateHwi_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_gates_GateHwi_Module__FXNS__C,
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsEnabled ti_sysbios_gates_GateHwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsIncluded ti_sysbios_gates_GateHwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsMask ti_sysbios_gates_GateHwi_Module__diagsMask__C = ((CT__ti_sysbios_gates_GateHwi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__gateObj ti_sysbios_gates_GateHwi_Module__gateObj__C = ((CT__ti_sysbios_gates_GateHwi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__gatePrms ti_sysbios_gates_GateHwi_Module__gatePrms__C = ((CT__ti_sysbios_gates_GateHwi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__id ti_sysbios_gates_GateHwi_Module__id__C = (xdc_Bits16)0x8023;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerDefined ti_sysbios_gates_GateHwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerObj ti_sysbios_gates_GateHwi_Module__loggerObj__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn0 ti_sysbios_gates_GateHwi_Module__loggerFxn0__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn1 ti_sysbios_gates_GateHwi_Module__loggerFxn1__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn2 ti_sysbios_gates_GateHwi_Module__loggerFxn2__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn4 ti_sysbios_gates_GateHwi_Module__loggerFxn4__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn8 ti_sysbios_gates_GateHwi_Module__loggerFxn8__C = ((CT__ti_sysbios_gates_GateHwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__startupDoneFxn ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_gates_GateHwi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__count ti_sysbios_gates_GateHwi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__heap ti_sysbios_gates_GateHwi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__sizeof ti_sysbios_gates_GateHwi_Object__sizeof__C = sizeof(ti_sysbios_gates_GateHwi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__table ti_sysbios_gates_GateHwi_Object__table__C = ti_sysbios_gates_GateHwi_Object__table__V;


/*
 * ======== ti.sysbios.gates.GateMutex INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateMutex_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_gates_GateMutex_Params ti_sysbios_gates_GateMutex_Object__PARAMS__C = {
    sizeof (ti_sysbios_gates_GateMutex_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_gates_GateMutex_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_gates_GateMutex_Module__ ti_sysbios_gates_GateMutex_Module__root__V = {
    {&ti_sysbios_gates_GateMutex_Module__root__V.link,  /* link.next */
    &ti_sysbios_gates_GateMutex_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_gates_GateMutex_Object__ ti_sysbios_gates_GateMutex_Object__table__V[2] = {
    {/* instance#0 */
        &ti_sysbios_gates_GateMutex_Module__FXNS__C,
        0,  /* owner */
        {
            0,  /* event */
            (xdc_UInt)0x1,  /* eventId */
            ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
            (xdc_UInt16)0x1,  /* count */
            {
                {
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[0].Object_field_sem.Object_field_pendQ.elem)),  /* next */
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[0].Object_field_sem.Object_field_pendQ.elem)),  /* prev */
                },  /* elem */
            },  /* Object_field_pendQ */
        },  /* Object_field_sem */
    },
    {/* instance#1 */
        &ti_sysbios_gates_GateMutex_Module__FXNS__C,
        0,  /* owner */
        {
            0,  /* event */
            (xdc_UInt)0x1,  /* eventId */
            ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
            (xdc_UInt16)0x1,  /* count */
            {
                {
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[1].Object_field_sem.Object_field_pendQ.elem)),  /* next */
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[1].Object_field_sem.Object_field_pendQ.elem)),  /* prev */
                },  /* elem */
            },  /* Object_field_pendQ */
        },  /* Object_field_sem */
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsEnabled ti_sysbios_gates_GateMutex_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsIncluded ti_sysbios_gates_GateMutex_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsMask ti_sysbios_gates_GateMutex_Module__diagsMask__C = ((CT__ti_sysbios_gates_GateMutex_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__gateObj ti_sysbios_gates_GateMutex_Module__gateObj__C = ((CT__ti_sysbios_gates_GateMutex_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__gatePrms ti_sysbios_gates_GateMutex_Module__gatePrms__C = ((CT__ti_sysbios_gates_GateMutex_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__id ti_sysbios_gates_GateMutex_Module__id__C = (xdc_Bits16)0x8024;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerDefined ti_sysbios_gates_GateMutex_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerObj ti_sysbios_gates_GateMutex_Module__loggerObj__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn0 ti_sysbios_gates_GateMutex_Module__loggerFxn0__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn1 ti_sysbios_gates_GateMutex_Module__loggerFxn1__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn2 ti_sysbios_gates_GateMutex_Module__loggerFxn2__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn4 ti_sysbios_gates_GateMutex_Module__loggerFxn4__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn8 ti_sysbios_gates_GateMutex_Module__loggerFxn8__C = ((CT__ti_sysbios_gates_GateMutex_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__startupDoneFxn ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C = ((CT__ti_sysbios_gates_GateMutex_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__count ti_sysbios_gates_GateMutex_Object__count__C = 2;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__heap ti_sysbios_gates_GateMutex_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__sizeof ti_sysbios_gates_GateMutex_Object__sizeof__C = sizeof(ti_sysbios_gates_GateMutex_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__table ti_sysbios_gates_GateMutex_Object__table__C = ti_sysbios_gates_GateMutex_Object__table__V;

/* A_badContext__C */
__FAR__ const CT__ti_sysbios_gates_GateMutex_A_badContext ti_sysbios_gates_GateMutex_A_badContext__C = (((xdc_runtime_Assert_Id)1568) << 16 | 16);


/*
 * ======== ti.sysbios.hal.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_hal_Hwi_Params ti_sysbios_hal_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_hal_Hwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_hal_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)(-0x0 - 1),  /* priority */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_hal_Hwi_Module__ ti_sysbios_hal_Hwi_Module__root__V = {
    {&ti_sysbios_hal_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_hal_Hwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_hal_Hwi_Object__ ti_sysbios_hal_Hwi_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (ti_sysbios_hal_Hwi_HwiProxy_Handle)&ti_sysbios_family_c64p_Hwi_Object__table__V[0],  /* pi */
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsEnabled ti_sysbios_hal_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsIncluded ti_sysbios_hal_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsMask ti_sysbios_hal_Hwi_Module__diagsMask__C = ((CT__ti_sysbios_hal_Hwi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__gateObj ti_sysbios_hal_Hwi_Module__gateObj__C = ((CT__ti_sysbios_hal_Hwi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__gatePrms ti_sysbios_hal_Hwi_Module__gatePrms__C = ((CT__ti_sysbios_hal_Hwi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__id ti_sysbios_hal_Hwi_Module__id__C = (xdc_Bits16)0x8018;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerDefined ti_sysbios_hal_Hwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerObj ti_sysbios_hal_Hwi_Module__loggerObj__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_Hwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__startupDoneFxn ti_sysbios_hal_Hwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_Hwi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__count ti_sysbios_hal_Hwi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__heap ti_sysbios_hal_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__sizeof ti_sysbios_hal_Hwi_Object__sizeof__C = sizeof(ti_sysbios_hal_Hwi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__table ti_sysbios_hal_Hwi_Object__table__C = ti_sysbios_hal_Hwi_Object__table__V;

/* dispatcherAutoNestingSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherSwiSupport ti_sysbios_hal_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherTaskSupport ti_sysbios_hal_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* E_stackOverflow__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_E_stackOverflow ti_sysbios_hal_Hwi_E_stackOverflow__C = (((xdc_runtime_Error_Id)4608) << 16 | 0);


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.hal.Timer INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Timer_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_hal_Timer_Params ti_sysbios_hal_Timer_Object__PARAMS__C = {
    sizeof (ti_sysbios_hal_Timer_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_hal_Timer_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)0),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_hal_Timer_Module__ ti_sysbios_hal_Timer_Module__root__V = {
    {&ti_sysbios_hal_Timer_Module__root__V.link,  /* link.next */
    &ti_sysbios_hal_Timer_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_hal_Timer_Object__ ti_sysbios_hal_Timer_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (ti_sysbios_hal_Timer_TimerProxy_Handle)&ti_sysbios_timers_dmtimer_Timer_Object__table__V[0],  /* pi */
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__diagsEnabled ti_sysbios_hal_Timer_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__diagsIncluded ti_sysbios_hal_Timer_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__diagsMask ti_sysbios_hal_Timer_Module__diagsMask__C = ((CT__ti_sysbios_hal_Timer_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__gateObj ti_sysbios_hal_Timer_Module__gateObj__C = ((CT__ti_sysbios_hal_Timer_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__gatePrms ti_sysbios_hal_Timer_Module__gatePrms__C = ((CT__ti_sysbios_hal_Timer_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__id ti_sysbios_hal_Timer_Module__id__C = (xdc_Bits16)0x8019;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerDefined ti_sysbios_hal_Timer_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerObj ti_sysbios_hal_Timer_Module__loggerObj__C = ((CT__ti_sysbios_hal_Timer_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn0 ti_sysbios_hal_Timer_Module__loggerFxn0__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn1 ti_sysbios_hal_Timer_Module__loggerFxn1__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn2 ti_sysbios_hal_Timer_Module__loggerFxn2__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn4 ti_sysbios_hal_Timer_Module__loggerFxn4__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__loggerFxn8 ti_sysbios_hal_Timer_Module__loggerFxn8__C = ((CT__ti_sysbios_hal_Timer_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Module__startupDoneFxn ti_sysbios_hal_Timer_Module__startupDoneFxn__C = ((CT__ti_sysbios_hal_Timer_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Object__count ti_sysbios_hal_Timer_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Object__heap ti_sysbios_hal_Timer_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Object__sizeof ti_sysbios_hal_Timer_Object__sizeof__C = sizeof(ti_sysbios_hal_Timer_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_hal_Timer_Object__table ti_sysbios_hal_Timer_Object__table__C = ti_sysbios_hal_Timer_Object__table__V;


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_heaps_HeapMem_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_heaps_HeapMem_Params ti_sysbios_heaps_HeapMem_Object__PARAMS__C = {
    sizeof (ti_sysbios_heaps_HeapMem_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_heaps_HeapMem_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_Ptr)(0x0)),  /* buf */
    ((xdc_UArg)(0x0)),  /* size */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[4096];

/* Module__root__V */
ti_sysbios_heaps_HeapMem_Module__ ti_sysbios_heaps_HeapMem_Module__root__V = {
    {&ti_sysbios_heaps_HeapMem_Module__root__V.link,  /* link.next */
    &ti_sysbios_heaps_HeapMem_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_heaps_HeapMem_Object__ ti_sysbios_heaps_HeapMem_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_heaps_HeapMem_Module__FXNS__C,
        ((xdc_UArg)(0x8)),  /* align */
        ((void*)ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A),  /* buf */
        {
            ((ti_sysbios_heaps_HeapMem_Header*)0),  /* next */
            ((xdc_UArg)(0x1000)),  /* size */
        },  /* head */
    },
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsEnabled ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsIncluded ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsMask ti_sysbios_heaps_HeapMem_Module__diagsMask__C = ((CT__ti_sysbios_heaps_HeapMem_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gateObj ti_sysbios_heaps_HeapMem_Module__gateObj__C = ((CT__ti_sysbios_heaps_HeapMem_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateMutex_Object__table__V[0]));

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gatePrms ti_sysbios_heaps_HeapMem_Module__gatePrms__C = ((CT__ti_sysbios_heaps_HeapMem_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module__id__C = (xdc_Bits16)0x8033;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerDefined ti_sysbios_heaps_HeapMem_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerObj ti_sysbios_heaps_HeapMem_Module__loggerObj__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C = ((CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__startupDoneFxn ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C = ((CT__ti_sysbios_heaps_HeapMem_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__count ti_sysbios_heaps_HeapMem_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__heap ti_sysbios_heaps_HeapMem_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__sizeof ti_sysbios_heaps_HeapMem_Object__sizeof__C = sizeof(ti_sysbios_heaps_HeapMem_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__table ti_sysbios_heaps_HeapMem_Object__table__C = ti_sysbios_heaps_HeapMem_Object__table__V;

/* A_zeroBlock__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_zeroBlock ti_sysbios_heaps_HeapMem_A_zeroBlock__C = (((xdc_runtime_Assert_Id)3899) << 16 | 16);

/* A_heapSize__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_heapSize ti_sysbios_heaps_HeapMem_A_heapSize__C = (((xdc_runtime_Assert_Id)3935) << 16 | 16);

/* A_align__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_align ti_sysbios_heaps_HeapMem_A_align__C = (((xdc_runtime_Assert_Id)3980) << 16 | 16);

/* E_memory__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_E_memory ti_sysbios_heaps_HeapMem_E_memory__C = (((xdc_runtime_Error_Id)5594) << 16 | 0);

/* A_invalidFree__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_invalidFree ti_sysbios_heaps_HeapMem_A_invalidFree__C = (((xdc_runtime_Assert_Id)3871) << 16 | 16);

/* reqAlign__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_reqAlign ti_sysbios_heaps_HeapMem_reqAlign__C = (xdc_Int)0x8;

/* reqAlignMask__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_reqAlignMask ti_sysbios_heaps_HeapMem_reqAlignMask__C = (xdc_Int)0x7;


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Clock INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Clock_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Clock_Params ti_sysbios_knl_Clock_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Clock_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Clock_Object__PARAMS__C.__iprms, /* instance */
    0,  /* startFlag */
    (xdc_UInt)0x0,  /* period */
    ((xdc_UArg)0),  /* arg */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Clock_Module__ ti_sysbios_knl_Clock_Module__root__V = {
    {&ti_sysbios_knl_Clock_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Clock_Module__root__V.link},  /* link.prev */
};

/* Module__state__V */
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V = {
    (xdc_UInt32)0x0,  /* ticks */
    (xdc_UInt)0x0,  /* swiCount */
    (ti_sysbios_hal_Timer_Handle)&ti_sysbios_hal_Timer_Object__table__V[0],  /* timer */
    ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_doTick__I)),  /* doTickFunc */
    (ti_sysbios_knl_Swi_Handle)&ti_sysbios_knl_Swi_Object__table__V[0],  /* swi */
    (xdc_UInt32)0x0,  /* periodCounts */
    (xdc_UInt)0x0,  /* numTickSkip */
    (xdc_UInt)0x0,  /* skipsWorkFunc */
    0,  /* inWorkFunc */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Module__state__V.Object_field_clockQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Module__state__V.Object_field_clockQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_clockQ */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsEnabled ti_sysbios_knl_Clock_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsIncluded ti_sysbios_knl_Clock_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsMask ti_sysbios_knl_Clock_Module__diagsMask__C = ((CT__ti_sysbios_knl_Clock_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__gateObj ti_sysbios_knl_Clock_Module__gateObj__C = ((CT__ti_sysbios_knl_Clock_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__gatePrms ti_sysbios_knl_Clock_Module__gatePrms__C = ((CT__ti_sysbios_knl_Clock_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__id ti_sysbios_knl_Clock_Module__id__C = (xdc_Bits16)0x801b;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerDefined ti_sysbios_knl_Clock_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerObj ti_sysbios_knl_Clock_Module__loggerObj__C = ((CT__ti_sysbios_knl_Clock_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn0 ti_sysbios_knl_Clock_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn1 ti_sysbios_knl_Clock_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn2 ti_sysbios_knl_Clock_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn4 ti_sysbios_knl_Clock_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn8 ti_sysbios_knl_Clock_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Clock_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Module__startupDoneFxn ti_sysbios_knl_Clock_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Clock_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Object__count ti_sysbios_knl_Clock_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Object__heap ti_sysbios_knl_Clock_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Object__sizeof ti_sysbios_knl_Clock_Object__sizeof__C = sizeof(ti_sysbios_knl_Clock_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Clock_Object__table ti_sysbios_knl_Clock_Object__table__C = 0;

/* LW_delayed__C */
__FAR__ const CT__ti_sysbios_knl_Clock_LW_delayed ti_sysbios_knl_Clock_LW_delayed__C = (((xdc_runtime_Log_Event)5894) << 16 | 1024);

/* LM_tick__C */
__FAR__ const CT__ti_sysbios_knl_Clock_LM_tick ti_sysbios_knl_Clock_LM_tick__C = (((xdc_runtime_Log_Event)5916) << 16 | 768);

/* LM_begin__C */
__FAR__ const CT__ti_sysbios_knl_Clock_LM_begin ti_sysbios_knl_Clock_LM_begin__C = (((xdc_runtime_Log_Event)5934) << 16 | 768);

/* A_clockDisabled__C */
__FAR__ const CT__ti_sysbios_knl_Clock_A_clockDisabled ti_sysbios_knl_Clock_A_clockDisabled__C = (((xdc_runtime_Assert_Id)355) << 16 | 16);

/* A_badThreadType__C */
__FAR__ const CT__ti_sysbios_knl_Clock_A_badThreadType ti_sysbios_knl_Clock_A_badThreadType__C = (((xdc_runtime_Assert_Id)436) << 16 | 16);

/* tickSource__C */
__FAR__ const CT__ti_sysbios_knl_Clock_tickSource ti_sysbios_knl_Clock_tickSource__C = ti_sysbios_knl_Clock_TickSource_TIMER;

/* tickMode__C */
__FAR__ const CT__ti_sysbios_knl_Clock_tickMode ti_sysbios_knl_Clock_tickMode__C = ti_sysbios_knl_Clock_TickMode_PERIODIC;

/* timerId__C */
__FAR__ const CT__ti_sysbios_knl_Clock_timerId ti_sysbios_knl_Clock_timerId__C = (xdc_UInt)(-0x0 - 1);

/* tickPeriod__C */
__FAR__ const CT__ti_sysbios_knl_Clock_tickPeriod ti_sysbios_knl_Clock_tickPeriod__C = (xdc_UInt32)0x3e8;


/*
 * ======== ti.sysbios.knl.Idle INITIALIZERS ========
 */

/* --> ti_sysbios_knl_Idle_funcList__A */
const __T1_ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__A[1] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_hal_Hwi_checkStack)),  /* [0] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsEnabled ti_sysbios_knl_Idle_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsIncluded ti_sysbios_knl_Idle_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsMask ti_sysbios_knl_Idle_Module__diagsMask__C = ((CT__ti_sysbios_knl_Idle_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__gateObj ti_sysbios_knl_Idle_Module__gateObj__C = ((CT__ti_sysbios_knl_Idle_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__gatePrms ti_sysbios_knl_Idle_Module__gatePrms__C = ((CT__ti_sysbios_knl_Idle_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__id ti_sysbios_knl_Idle_Module__id__C = (xdc_Bits16)0x801c;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerDefined ti_sysbios_knl_Idle_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerObj ti_sysbios_knl_Idle_Module__loggerObj__C = ((CT__ti_sysbios_knl_Idle_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn0 ti_sysbios_knl_Idle_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn1 ti_sysbios_knl_Idle_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn2 ti_sysbios_knl_Idle_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn4 ti_sysbios_knl_Idle_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn8 ti_sysbios_knl_Idle_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Idle_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Module__startupDoneFxn ti_sysbios_knl_Idle_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Idle_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Object__count ti_sysbios_knl_Idle_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Object__heap ti_sysbios_knl_Idle_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Object__sizeof ti_sysbios_knl_Idle_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Idle_Object__table ti_sysbios_knl_Idle_Object__table__C = 0;

/* funcList__C */
__FAR__ const CT__ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__C = {1, ((__T1_ti_sysbios_knl_Idle_funcList*)ti_sysbios_knl_Idle_funcList__A)};


/*
 * ======== ti.sysbios.knl.Intrinsics INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsEnabled ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsIncluded ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsMask ti_sysbios_knl_Intrinsics_Module__diagsMask__C = ((CT__ti_sysbios_knl_Intrinsics_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__gateObj ti_sysbios_knl_Intrinsics_Module__gateObj__C = ((CT__ti_sysbios_knl_Intrinsics_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__gatePrms ti_sysbios_knl_Intrinsics_Module__gatePrms__C = ((CT__ti_sysbios_knl_Intrinsics_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__id ti_sysbios_knl_Intrinsics_Module__id__C = (xdc_Bits16)0x801d;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerDefined ti_sysbios_knl_Intrinsics_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerObj ti_sysbios_knl_Intrinsics_Module__loggerObj__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn0 ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn1 ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn2 ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn4 ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn8 ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__startupDoneFxn ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Intrinsics_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__count ti_sysbios_knl_Intrinsics_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__heap ti_sysbios_knl_Intrinsics_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__sizeof ti_sysbios_knl_Intrinsics_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__table ti_sysbios_knl_Intrinsics_Object__table__C = 0;


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Queue INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Queue_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Queue_Params ti_sysbios_knl_Queue_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Queue_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Queue_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Queue_Module__ ti_sysbios_knl_Queue_Module__root__V = {
    {&ti_sysbios_knl_Queue_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Queue_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsEnabled ti_sysbios_knl_Queue_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsIncluded ti_sysbios_knl_Queue_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsMask ti_sysbios_knl_Queue_Module__diagsMask__C = ((CT__ti_sysbios_knl_Queue_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__gateObj ti_sysbios_knl_Queue_Module__gateObj__C = ((CT__ti_sysbios_knl_Queue_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__gatePrms ti_sysbios_knl_Queue_Module__gatePrms__C = ((CT__ti_sysbios_knl_Queue_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__id ti_sysbios_knl_Queue_Module__id__C = (xdc_Bits16)0x801e;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerDefined ti_sysbios_knl_Queue_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerObj ti_sysbios_knl_Queue_Module__loggerObj__C = ((CT__ti_sysbios_knl_Queue_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn0 ti_sysbios_knl_Queue_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn1 ti_sysbios_knl_Queue_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn2 ti_sysbios_knl_Queue_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn4 ti_sysbios_knl_Queue_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn8 ti_sysbios_knl_Queue_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Queue_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Module__startupDoneFxn ti_sysbios_knl_Queue_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Queue_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Object__count ti_sysbios_knl_Queue_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Object__heap ti_sysbios_knl_Queue_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Object__sizeof ti_sysbios_knl_Queue_Object__sizeof__C = sizeof(ti_sysbios_knl_Queue_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Queue_Object__table ti_sysbios_knl_Queue_Object__table__C = 0;


/*
 * ======== ti.sysbios.knl.Semaphore INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Semaphore_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Semaphore_Params ti_sysbios_knl_Semaphore_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Semaphore_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Semaphore_Object__PARAMS__C.__iprms, /* instance */
    0,  /* event */
    (xdc_UInt)0x1,  /* eventId */
    ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Semaphore_Module__ ti_sysbios_knl_Semaphore_Module__root__V = {
    {&ti_sysbios_knl_Semaphore_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Semaphore_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsEnabled ti_sysbios_knl_Semaphore_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsIncluded ti_sysbios_knl_Semaphore_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsMask ti_sysbios_knl_Semaphore_Module__diagsMask__C = ((CT__ti_sysbios_knl_Semaphore_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gateObj ti_sysbios_knl_Semaphore_Module__gateObj__C = ((CT__ti_sysbios_knl_Semaphore_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gatePrms ti_sysbios_knl_Semaphore_Module__gatePrms__C = ((CT__ti_sysbios_knl_Semaphore_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__id ti_sysbios_knl_Semaphore_Module__id__C = (xdc_Bits16)0x801f;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerDefined ti_sysbios_knl_Semaphore_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerObj ti_sysbios_knl_Semaphore_Module__loggerObj__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__startupDoneFxn ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Semaphore_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__count ti_sysbios_knl_Semaphore_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__heap ti_sysbios_knl_Semaphore_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__sizeof ti_sysbios_knl_Semaphore_Object__sizeof__C = sizeof(ti_sysbios_knl_Semaphore_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__table ti_sysbios_knl_Semaphore_Object__table__C = 0;

/* LM_post__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_post ti_sysbios_knl_Semaphore_LM_post__C = (((xdc_runtime_Log_Event)5966) << 16 | 768);

/* LM_pend__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_pend ti_sysbios_knl_Semaphore_LM_pend__C = (((xdc_runtime_Log_Event)5996) << 16 | 768);

/* A_noEvents__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_noEvents ti_sysbios_knl_Semaphore_A_noEvents__C = (((xdc_runtime_Assert_Id)756) << 16 | 16);

/* A_invTimeout__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_invTimeout ti_sysbios_knl_Semaphore_A_invTimeout__C = (((xdc_runtime_Assert_Id)811) << 16 | 16);

/* A_badContext__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_A_badContext ti_sysbios_knl_Semaphore_A_badContext__C = (((xdc_runtime_Assert_Id)635) << 16 | 16);

/* supportsEvents__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_supportsEvents ti_sysbios_knl_Semaphore_supportsEvents__C = 0;

/* eventPost__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_eventPost ti_sysbios_knl_Semaphore_eventPost__C = ((CT__ti_sysbios_knl_Semaphore_eventPost)0);

/* eventSync__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_eventSync ti_sysbios_knl_Semaphore_eventSync__C = ((CT__ti_sysbios_knl_Semaphore_eventSync)0);


/*
 * ======== ti.sysbios.knl.Swi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Swi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Swi_Params ti_sysbios_knl_Swi_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Swi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Swi_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_UArg)(0x0)),  /* arg0 */
    ((xdc_UArg)(0x0)),  /* arg1 */
    (xdc_UInt)(-0x0 - 1),  /* priority */
    (xdc_UInt)0x0,  /* trigger */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Swi_Module__ ti_sysbios_knl_Swi_Module__root__V = {
    {&ti_sysbios_knl_Swi_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Swi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Object__table__V[0].qElem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Object__table__V[0].qElem)),  /* prev */
        },  /* qElem */
        ((xdc_Void(*)(xdc_UArg,xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_workFunc__E)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg0 */
        ((xdc_UArg)(0x0)),  /* arg1 */
        (xdc_UInt)0xf,  /* priority */
        (xdc_UInt)0x8000,  /* mask */
        0,  /* posted */
        (xdc_UInt)0x0,  /* initTrigger */
        (xdc_UInt)0x0,  /* trigger */
        (ti_sysbios_knl_Queue_Handle)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15],  /* readyQ */
        ((void*)0),  /* hookEnv */
    },
};

/* --> ti_sysbios_knl_Swi_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Swi_Module_State__readyQ ti_sysbios_knl_Swi_Module_State_0_readyQ__A[16] = {
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[0].elem)),  /* prev */
        },  /* elem */
    },  /* [0] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[1].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[1].elem)),  /* prev */
        },  /* elem */
    },  /* [1] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[2].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[2].elem)),  /* prev */
        },  /* elem */
    },  /* [2] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[3].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[3].elem)),  /* prev */
        },  /* elem */
    },  /* [3] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[4].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[4].elem)),  /* prev */
        },  /* elem */
    },  /* [4] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[5].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[5].elem)),  /* prev */
        },  /* elem */
    },  /* [5] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[6].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[6].elem)),  /* prev */
        },  /* elem */
    },  /* [6] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[7].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[7].elem)),  /* prev */
        },  /* elem */
    },  /* [7] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[8].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[8].elem)),  /* prev */
        },  /* elem */
    },  /* [8] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[9].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[9].elem)),  /* prev */
        },  /* elem */
    },  /* [9] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[10].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[10].elem)),  /* prev */
        },  /* elem */
    },  /* [10] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[11].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[11].elem)),  /* prev */
        },  /* elem */
    },  /* [11] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[12].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[12].elem)),  /* prev */
        },  /* elem */
    },  /* [12] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[13].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[13].elem)),  /* prev */
        },  /* elem */
    },  /* [13] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[14].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[14].elem)),  /* prev */
        },  /* elem */
    },  /* [14] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15].elem)),  /* prev */
        },  /* elem */
    },  /* [15] */
};

/* Module__state__V */
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V = {
    1,  /* locked */
    (xdc_UInt)0x0,  /* curSet */
    (xdc_UInt)0x0,  /* curTrigger */
    0,  /* curSwi */
    0,  /* curQ */
    ((void*)ti_sysbios_knl_Swi_Module_State_0_readyQ__A),  /* readyQ */
    ((void*)0),  /* constructedSwis */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsEnabled ti_sysbios_knl_Swi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsIncluded ti_sysbios_knl_Swi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsMask ti_sysbios_knl_Swi_Module__diagsMask__C = ((CT__ti_sysbios_knl_Swi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__gateObj ti_sysbios_knl_Swi_Module__gateObj__C = ((CT__ti_sysbios_knl_Swi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__gatePrms ti_sysbios_knl_Swi_Module__gatePrms__C = ((CT__ti_sysbios_knl_Swi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__id ti_sysbios_knl_Swi_Module__id__C = (xdc_Bits16)0x8020;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerDefined ti_sysbios_knl_Swi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerObj ti_sysbios_knl_Swi_Module__loggerObj__C = ((CT__ti_sysbios_knl_Swi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn0 ti_sysbios_knl_Swi_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn1 ti_sysbios_knl_Swi_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn2 ti_sysbios_knl_Swi_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn4 ti_sysbios_knl_Swi_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn8 ti_sysbios_knl_Swi_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Swi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Module__startupDoneFxn ti_sysbios_knl_Swi_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Swi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Object__count ti_sysbios_knl_Swi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Object__heap ti_sysbios_knl_Swi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Object__sizeof ti_sysbios_knl_Swi_Object__sizeof__C = sizeof(ti_sysbios_knl_Swi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Swi_Object__table ti_sysbios_knl_Swi_Object__table__C = ti_sysbios_knl_Swi_Object__table__V;

/* LM_begin__C */
__FAR__ const CT__ti_sysbios_knl_Swi_LM_begin ti_sysbios_knl_Swi_LM_begin__C = (((xdc_runtime_Log_Event)6039) << 16 | 768);

/* LD_end__C */
__FAR__ const CT__ti_sysbios_knl_Swi_LD_end ti_sysbios_knl_Swi_LD_end__C = (((xdc_runtime_Log_Event)6086) << 16 | 512);

/* LM_post__C */
__FAR__ const CT__ti_sysbios_knl_Swi_LM_post ti_sysbios_knl_Swi_LM_post__C = (((xdc_runtime_Log_Event)6104) << 16 | 768);

/* A_swiDisabled__C */
__FAR__ const CT__ti_sysbios_knl_Swi_A_swiDisabled ti_sysbios_knl_Swi_A_swiDisabled__C = (((xdc_runtime_Assert_Id)876) << 16 | 16);

/* A_badPriority__C */
__FAR__ const CT__ti_sysbios_knl_Swi_A_badPriority ti_sysbios_knl_Swi_A_badPriority__C = (((xdc_runtime_Assert_Id)933) << 16 | 16);

/* numPriorities__C */
__FAR__ const CT__ti_sysbios_knl_Swi_numPriorities ti_sysbios_knl_Swi_numPriorities__C = (xdc_UInt)0x10;

/* hooks__C */
__FAR__ const CT__ti_sysbios_knl_Swi_hooks ti_sysbios_knl_Swi_hooks__C = {0, 0};

/* taskDisable__C */
__FAR__ const CT__ti_sysbios_knl_Swi_taskDisable ti_sysbios_knl_Swi_taskDisable__C = ((CT__ti_sysbios_knl_Swi_taskDisable)((xdc_Fxn)ti_sysbios_knl_Task_disable__E));

/* taskRestore__C */
__FAR__ const CT__ti_sysbios_knl_Swi_taskRestore ti_sysbios_knl_Swi_taskRestore__C = ((CT__ti_sysbios_knl_Swi_taskRestore)((xdc_Fxn)ti_sysbios_knl_Task_restore__E));

/* numConstructedSwis__C */
__FAR__ const CT__ti_sysbios_knl_Swi_numConstructedSwis ti_sysbios_knl_Swi_numConstructedSwis__C = (xdc_UInt)0x0;


/*
 * ======== ti.sysbios.knl.Task INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Task_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_knl_Task_Params ti_sysbios_knl_Task_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Task_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Task_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_UArg)(0x0)),  /* arg0 */
    ((xdc_UArg)(0x0)),  /* arg1 */
    (xdc_Int)0x1,  /* priority */
    ((xdc_Ptr)0),  /* stack */
    (xdc_SizeT)0x0,  /* stackSize */
    0,  /* stackHeap */
    ((xdc_Ptr)0),  /* env */
    1,  /* vitalTaskFlag */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_knl_Task_Instance_State_0_stack__A */
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048];

/* --> ti_sysbios_knl_Task_Instance_State_0_hookEnv__A */
__T1_ti_sysbios_knl_Task_Instance_State__hookEnv ti_sysbios_knl_Task_Instance_State_0_hookEnv__A[1];

/* Module__root__V */
ti_sysbios_knl_Task_Module__ ti_sysbios_knl_Task_Module__root__V = {
    {&ti_sysbios_knl_Task_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Task_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Object__table__V[0].qElem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Object__table__V[0].qElem)),  /* prev */
        },  /* qElem */
        (xdc_Int)0x0,  /* priority */
        (xdc_UInt)0x1,  /* mask */
        ((xdc_Ptr)0),  /* context */
        ti_sysbios_knl_Task_Mode_READY,  /* mode */
        ((ti_sysbios_knl_Task_PendElem*)0),  /* pendElem */
        (xdc_SizeT)0x800,  /* stackSize */
        ((void*)ti_sysbios_knl_Task_Instance_State_0_stack__A),  /* stack */
        0,  /* stackHeap */
        ((xdc_Void(*)(xdc_UArg,xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Idle_loop__E)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg0 */
        ((xdc_UArg)(0x0)),  /* arg1 */
        ((xdc_Ptr)0),  /* env */
        ((void*)ti_sysbios_knl_Task_Instance_State_0_hookEnv__A),  /* hookEnv */
        1,  /* vitalTaskFlag */
        0,  /* readyQ */
    },
};

/* --> ti_sysbios_knl_Task_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Task_Module_State__readyQ ti_sysbios_knl_Task_Module_State_0_readyQ__A[16] = {
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[0].elem)),  /* prev */
        },  /* elem */
    },  /* [0] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[1].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[1].elem)),  /* prev */
        },  /* elem */
    },  /* [1] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[2].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[2].elem)),  /* prev */
        },  /* elem */
    },  /* [2] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[3].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[3].elem)),  /* prev */
        },  /* elem */
    },  /* [3] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[4].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[4].elem)),  /* prev */
        },  /* elem */
    },  /* [4] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[5].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[5].elem)),  /* prev */
        },  /* elem */
    },  /* [5] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[6].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[6].elem)),  /* prev */
        },  /* elem */
    },  /* [6] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[7].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[7].elem)),  /* prev */
        },  /* elem */
    },  /* [7] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[8].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[8].elem)),  /* prev */
        },  /* elem */
    },  /* [8] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[9].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[9].elem)),  /* prev */
        },  /* elem */
    },  /* [9] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[10].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[10].elem)),  /* prev */
        },  /* elem */
    },  /* [10] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[11].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[11].elem)),  /* prev */
        },  /* elem */
    },  /* [11] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[12].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[12].elem)),  /* prev */
        },  /* elem */
    },  /* [12] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[13].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[13].elem)),  /* prev */
        },  /* elem */
    },  /* [13] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[14].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[14].elem)),  /* prev */
        },  /* elem */
    },  /* [14] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[15].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[15].elem)),  /* prev */
        },  /* elem */
    },  /* [15] */
};

/* Module__state__V */
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V = {
    1,  /* locked */
    (xdc_UInt)0x0,  /* curSet */
    0,  /* workFlag */
    (xdc_UInt)0x1,  /* vitalTasks */
    0,  /* curTask */
    0,  /* curQ */
    ((void*)ti_sysbios_knl_Task_Module_State_0_readyQ__A),  /* readyQ */
    (ti_sysbios_knl_Task_Handle)&ti_sysbios_knl_Task_Object__table__V[0],  /* idleTask */
    ((void*)0),  /* constructedTasks */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_inactiveQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_inactiveQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_inactiveQ */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_terminatedQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_terminatedQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_terminatedQ */
};

/* --> ti_sysbios_knl_Task_hooks__A */
const __T1_ti_sysbios_knl_Task_hooks ti_sysbios_knl_Task_hooks__A[1] = {
    {
        ((xdc_Void(*)(xdc_Int))0),  /* registerFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle,xdc_runtime_Error_Block*))0),  /* createFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle))0),  /* readyFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle,ti_sysbios_knl_Task_Handle))((xdc_Fxn)ti_sysbios_knl_Task_checkStacks)),  /* switchFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle))0),  /* exitFxn */
        ((xdc_Void(*)(ti_sysbios_knl_Task_Handle))0),  /* deleteFxn */
    },  /* [0] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsEnabled ti_sysbios_knl_Task_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsIncluded ti_sysbios_knl_Task_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsMask ti_sysbios_knl_Task_Module__diagsMask__C = ((CT__ti_sysbios_knl_Task_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__gateObj ti_sysbios_knl_Task_Module__gateObj__C = ((CT__ti_sysbios_knl_Task_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__gatePrms ti_sysbios_knl_Task_Module__gatePrms__C = ((CT__ti_sysbios_knl_Task_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__id ti_sysbios_knl_Task_Module__id__C = (xdc_Bits16)0x8021;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerDefined ti_sysbios_knl_Task_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerObj ti_sysbios_knl_Task_Module__loggerObj__C = ((CT__ti_sysbios_knl_Task_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn0 ti_sysbios_knl_Task_Module__loggerFxn0__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn1 ti_sysbios_knl_Task_Module__loggerFxn1__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn2 ti_sysbios_knl_Task_Module__loggerFxn2__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn4 ti_sysbios_knl_Task_Module__loggerFxn4__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn8 ti_sysbios_knl_Task_Module__loggerFxn8__C = ((CT__ti_sysbios_knl_Task_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_knl_Task_Module__startupDoneFxn ti_sysbios_knl_Task_Module__startupDoneFxn__C = ((CT__ti_sysbios_knl_Task_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_knl_Task_Object__count ti_sysbios_knl_Task_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_knl_Task_Object__heap ti_sysbios_knl_Task_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_knl_Task_Object__sizeof ti_sysbios_knl_Task_Object__sizeof__C = sizeof(ti_sysbios_knl_Task_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_knl_Task_Object__table ti_sysbios_knl_Task_Object__table__C = ti_sysbios_knl_Task_Object__table__V;

/* LM_switch__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_switch ti_sysbios_knl_Task_LM_switch__C = (((xdc_runtime_Log_Event)6144) << 16 | 768);

/* LM_sleep__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_sleep ti_sysbios_knl_Task_LM_sleep__C = (((xdc_runtime_Log_Event)6212) << 16 | 768);

/* LD_ready__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_ready ti_sysbios_knl_Task_LD_ready__C = (((xdc_runtime_Log_Event)6257) << 16 | 512);

/* LD_block__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_block ti_sysbios_knl_Task_LD_block__C = (((xdc_runtime_Log_Event)6298) << 16 | 512);

/* LM_yield__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_yield ti_sysbios_knl_Task_LM_yield__C = (((xdc_runtime_Log_Event)6330) << 16 | 768);

/* LM_setPri__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_setPri ti_sysbios_knl_Task_LM_setPri__C = (((xdc_runtime_Log_Event)6378) << 16 | 768);

/* LD_exit__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_exit ti_sysbios_knl_Task_LD_exit__C = (((xdc_runtime_Log_Event)6434) << 16 | 512);

/* E_stackOverflow__C */
__FAR__ const CT__ti_sysbios_knl_Task_E_stackOverflow ti_sysbios_knl_Task_E_stackOverflow__C = (((xdc_runtime_Error_Id)4645) << 16 | 0);

/* E_spOutOfBounds__C */
__FAR__ const CT__ti_sysbios_knl_Task_E_spOutOfBounds ti_sysbios_knl_Task_E_spOutOfBounds__C = (((xdc_runtime_Error_Id)4688) << 16 | 0);

/* A_badThreadType__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badThreadType ti_sysbios_knl_Task_A_badThreadType__C = (((xdc_runtime_Assert_Id)982) << 16 | 16);

/* A_badTaskState__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badTaskState ti_sysbios_knl_Task_A_badTaskState__C = (((xdc_runtime_Assert_Id)1051) << 16 | 16);

/* A_noPendElem__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_noPendElem ti_sysbios_knl_Task_A_noPendElem__C = (((xdc_runtime_Assert_Id)1105) << 16 | 16);

/* A_taskDisabled__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_taskDisabled ti_sysbios_knl_Task_A_taskDisabled__C = (((xdc_runtime_Assert_Id)1159) << 16 | 16);

/* A_badPriority__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badPriority ti_sysbios_knl_Task_A_badPriority__C = (((xdc_runtime_Assert_Id)1222) << 16 | 16);

/* A_badTimeout__C */
__FAR__ const CT__ti_sysbios_knl_Task_A_badTimeout ti_sysbios_knl_Task_A_badTimeout__C = (((xdc_runtime_Assert_Id)1272) << 16 | 16);

/* numPriorities__C */
__FAR__ const CT__ti_sysbios_knl_Task_numPriorities ti_sysbios_knl_Task_numPriorities__C = (xdc_UInt)0x10;

/* defaultStackSize__C */
__FAR__ const CT__ti_sysbios_knl_Task_defaultStackSize ti_sysbios_knl_Task_defaultStackSize__C = (xdc_SizeT)0x800;

/* defaultStackHeap__C */
__FAR__ const CT__ti_sysbios_knl_Task_defaultStackHeap ti_sysbios_knl_Task_defaultStackHeap__C = 0;

/* allBlockedFunc__C */
__FAR__ const CT__ti_sysbios_knl_Task_allBlockedFunc ti_sysbios_knl_Task_allBlockedFunc__C = ((CT__ti_sysbios_knl_Task_allBlockedFunc)((xdc_Fxn)ti_sysbios_knl_Task_allBlockedFunction__I));

/* initStackFlag__C */
__FAR__ const CT__ti_sysbios_knl_Task_initStackFlag ti_sysbios_knl_Task_initStackFlag__C = 1;

/* deleteTerminatedTasks__C */
__FAR__ const CT__ti_sysbios_knl_Task_deleteTerminatedTasks ti_sysbios_knl_Task_deleteTerminatedTasks__C = 0;

/* hooks__C */
__FAR__ const CT__ti_sysbios_knl_Task_hooks ti_sysbios_knl_Task_hooks__C = {1, ((__T1_ti_sysbios_knl_Task_hooks*)ti_sysbios_knl_Task_hooks__A)};

/* numConstructedTasks__C */
__FAR__ const CT__ti_sysbios_knl_Task_numConstructedTasks ti_sysbios_knl_Task_numConstructedTasks__C = (xdc_UInt)0x0;


/*
 * ======== ti.sysbios.knl.Task_SupportProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.timers.dmtimer.Timer INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_timers_dmtimer_Timer_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_timers_dmtimer_Timer_Params ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C = {
    sizeof (ti_sysbios_timers_dmtimer_Timer_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)0),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    {
        (xdc_Bits8)0x0,  /* idlemode */
        (xdc_Bits8)0x0,  /* emufree */
        (xdc_Bits8)0x1,  /* softreset */
    },  /* tiocpCfg */
    {
        (xdc_Bits8)0x0,  /* mat_it_ena */
        (xdc_Bits8)0x1,  /* ovf_it_ena */
        (xdc_Bits8)0x0,  /* tcar_it_ena */
    },  /* tier */
    {
        (xdc_Bits8)0x0,  /* mat_wup_ena */
        (xdc_Bits8)0x0,  /* ovf_wup_ena */
        (xdc_Bits8)0x0,  /* tcar_wup_ena */
    },  /* twer */
    {
        (xdc_Bits32)0x0,  /* ptv */
        (xdc_Bits8)0x0,  /* pre */
        (xdc_Bits8)0x0,  /* ce */
        (xdc_Bits8)0x0,  /* scpwm */
        (xdc_Bits16)0x0,  /* tcm */
        (xdc_Bits16)0x0,  /* trg */
        (xdc_Bits8)0x0,  /* pt */
        (xdc_Bits8)0x0,  /* captmode */
        (xdc_Bits8)0x0,  /* gpocfg */
    },  /* tclr */
    {
        (xdc_Bits8)0x0,  /* sft */
        (xdc_Bits8)0x1,  /* posted */
    },  /* tsicr */
    (xdc_UInt32)0x0,  /* tmar */
    ((ti_sysbios_hal_Hwi_Params*)0),  /* hwiParams */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_timers_dmtimer_Timer_Module__ ti_sysbios_timers_dmtimer_Timer_Module__root__V = {
    {&ti_sysbios_timers_dmtimer_Timer_Module__root__V.link,  /* link.next */
    &ti_sysbios_timers_dmtimer_Timer_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_timers_dmtimer_Timer_Object__ ti_sysbios_timers_dmtimer_Timer_Object__table__V[1] = {
    {/* instance#0 */
        0,
        1,  /* staticInst */
        (xdc_Int)0x0,  /* id */
        (xdc_UInt)0x1,  /* tiocpCfg */
        (xdc_UInt)0x0,  /* tmar */
        (xdc_UInt)0x2,  /* tier */
        (xdc_UInt)0x0,  /* twer */
        (xdc_UInt)0x0,  /* tclr */
        (xdc_UInt)0x4,  /* tsicr */
        ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
        ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
        (xdc_UInt)0x3e8,  /* period */
        ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
        (xdc_UInt)0xe,  /* intNum */
        ((xdc_UArg)0),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_doTick__I)),  /* tickFxn */
        {
            (xdc_Bits32)0x0,  /* hi */
            (xdc_Bits32)0x0,  /* lo */
        },  /* extFreq */
        (ti_sysbios_hal_Hwi_Handle)&ti_sysbios_hal_Hwi_Object__table__V[0],  /* hwi */
        (xdc_UInt)0x0,  /* prevThreshold */
        (xdc_UInt)0x0,  /* rollovers */
    },
};

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__device ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A[4] = {
    {
        (xdc_UInt)0xe,  /* intNum */
        (xdc_UInt)0x33,  /* eventId */
        ((xdc_Ptr)((void*)0x1d38000)),  /* baseAddr */
    },  /* [0] */
    {
        (xdc_UInt)0xf,  /* intNum */
        (xdc_UInt)0x34,  /* eventId */
        ((xdc_Ptr)((void*)0x1d3a000)),  /* baseAddr */
    },  /* [1] */
    {
        (xdc_UInt)0x4,  /* intNum */
        (xdc_UInt)0x35,  /* eventId */
        ((xdc_Ptr)((void*)0x1d3c000)),  /* baseAddr */
    },  /* [2] */
    {
        (xdc_UInt)0x5,  /* intNum */
        (xdc_UInt)0x36,  /* eventId */
        ((xdc_Ptr)((void*)0x1d3e000)),  /* baseAddr */
    },  /* [3] */
};

/* --> ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A */
__T1_ti_sysbios_timers_dmtimer_Timer_Module_State__handles ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A[4] = {
    (ti_sysbios_timers_dmtimer_Timer_Handle)&ti_sysbios_timers_dmtimer_Timer_Object__table__V[0],  /* [0] */
    0,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
};

/* Module__state__V */
ti_sysbios_timers_dmtimer_Timer_Module_State__ ti_sysbios_timers_dmtimer_Timer_Module__state__V = {
    (xdc_Bits32)0xe,  /* availMask */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x249f000,  /* lo */
    },  /* intFreq */
    ((void*)ti_sysbios_timers_dmtimer_Timer_Module_State_0_device__A),  /* device */
    ((void*)ti_sysbios_timers_dmtimer_Timer_Module_State_0_handles__A),  /* handles */
    1,  /* firstInit */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsMask ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__gateObj ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__gatePrms ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__id ti_sysbios_timers_dmtimer_Timer_Module__id__C = (xdc_Bits16)0x802e;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerObj ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn__C = ((CT__ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__count ti_sysbios_timers_dmtimer_Timer_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__heap ti_sysbios_timers_dmtimer_Timer_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__sizeof ti_sysbios_timers_dmtimer_Timer_Object__sizeof__C = sizeof(ti_sysbios_timers_dmtimer_Timer_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_Object__table ti_sysbios_timers_dmtimer_Timer_Object__table__C = ti_sysbios_timers_dmtimer_Timer_Object__table__V;

/* E_invalidTimer__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_invalidTimer ti_sysbios_timers_dmtimer_Timer_E_invalidTimer__C = (((xdc_runtime_Error_Id)5278) << 16 | 0);

/* E_notAvailable__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_notAvailable ti_sysbios_timers_dmtimer_Timer_E_notAvailable__C = (((xdc_runtime_Error_Id)5314) << 16 | 0);

/* E_cannotSupport__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_cannotSupport ti_sysbios_timers_dmtimer_Timer_E_cannotSupport__C = (((xdc_runtime_Error_Id)5353) << 16 | 0);

/* E_freqMismatch__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_E_freqMismatch ti_sysbios_timers_dmtimer_Timer_E_freqMismatch__C = (((xdc_runtime_Error_Id)5411) << 16 | 0);

/* anyMask__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_anyMask ti_sysbios_timers_dmtimer_Timer_anyMask__C = (xdc_Bits32)0xf;

/* checkFrequency__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_checkFrequency ti_sysbios_timers_dmtimer_Timer_checkFrequency__C = 1;

/* startupNeeded__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_startupNeeded ti_sysbios_timers_dmtimer_Timer_startupNeeded__C = 1;

/* numTimerDevices__C */
__FAR__ const CT__ti_sysbios_timers_dmtimer_Timer_numTimerDevices ti_sysbios_timers_dmtimer_Timer_numTimerDevices__C = (xdc_Int)0x4;


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Assert INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Assert_Module__diagsEnabled xdc_runtime_Assert_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Assert_Module__diagsIncluded xdc_runtime_Assert_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Assert_Module__diagsMask xdc_runtime_Assert_Module__diagsMask__C = ((CT__xdc_runtime_Assert_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Assert_Module__gateObj xdc_runtime_Assert_Module__gateObj__C = ((CT__xdc_runtime_Assert_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Assert_Module__gatePrms xdc_runtime_Assert_Module__gatePrms__C = ((CT__xdc_runtime_Assert_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Assert_Module__id xdc_runtime_Assert_Module__id__C = (xdc_Bits16)0x8002;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerDefined xdc_runtime_Assert_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerObj xdc_runtime_Assert_Module__loggerObj__C = ((CT__xdc_runtime_Assert_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn0 xdc_runtime_Assert_Module__loggerFxn0__C = ((CT__xdc_runtime_Assert_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn1 xdc_runtime_Assert_Module__loggerFxn1__C = ((CT__xdc_runtime_Assert_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn2 xdc_runtime_Assert_Module__loggerFxn2__C = ((CT__xdc_runtime_Assert_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn4 xdc_runtime_Assert_Module__loggerFxn4__C = ((CT__xdc_runtime_Assert_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn8 xdc_runtime_Assert_Module__loggerFxn8__C = ((CT__xdc_runtime_Assert_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Assert_Module__startupDoneFxn xdc_runtime_Assert_Module__startupDoneFxn__C = ((CT__xdc_runtime_Assert_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Assert_Object__count xdc_runtime_Assert_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Assert_Object__heap xdc_runtime_Assert_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Assert_Object__sizeof xdc_runtime_Assert_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Assert_Object__table xdc_runtime_Assert_Object__table__C = 0;

/* E_assertFailed__C */
__FAR__ const CT__xdc_runtime_Assert_E_assertFailed xdc_runtime_Assert_E_assertFailed__C = (((xdc_runtime_Error_Id)4095) << 16 | 0);


/*
 * ======== xdc.runtime.Core INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Core_Module__diagsEnabled xdc_runtime_Core_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Core_Module__diagsIncluded xdc_runtime_Core_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Core_Module__diagsMask xdc_runtime_Core_Module__diagsMask__C = ((CT__xdc_runtime_Core_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Core_Module__gateObj xdc_runtime_Core_Module__gateObj__C = ((CT__xdc_runtime_Core_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Core_Module__gatePrms xdc_runtime_Core_Module__gatePrms__C = ((CT__xdc_runtime_Core_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Core_Module__id xdc_runtime_Core_Module__id__C = (xdc_Bits16)0x8003;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerDefined xdc_runtime_Core_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerObj xdc_runtime_Core_Module__loggerObj__C = ((CT__xdc_runtime_Core_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn0 xdc_runtime_Core_Module__loggerFxn0__C = ((CT__xdc_runtime_Core_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn1 xdc_runtime_Core_Module__loggerFxn1__C = ((CT__xdc_runtime_Core_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn2 xdc_runtime_Core_Module__loggerFxn2__C = ((CT__xdc_runtime_Core_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn4 xdc_runtime_Core_Module__loggerFxn4__C = ((CT__xdc_runtime_Core_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn8 xdc_runtime_Core_Module__loggerFxn8__C = ((CT__xdc_runtime_Core_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Core_Module__startupDoneFxn xdc_runtime_Core_Module__startupDoneFxn__C = ((CT__xdc_runtime_Core_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Core_Object__count xdc_runtime_Core_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Core_Object__heap xdc_runtime_Core_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Core_Object__sizeof xdc_runtime_Core_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Core_Object__table xdc_runtime_Core_Object__table__C = 0;

/* A_initializedParams__C */
__FAR__ const CT__xdc_runtime_Core_A_initializedParams xdc_runtime_Core_A_initializedParams__C = (((xdc_runtime_Assert_Id)1) << 16 | 16);


/*
 * ======== xdc.runtime.Defaults INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsEnabled xdc_runtime_Defaults_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsIncluded xdc_runtime_Defaults_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__diagsMask xdc_runtime_Defaults_Module__diagsMask__C = ((CT__xdc_runtime_Defaults_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__gateObj xdc_runtime_Defaults_Module__gateObj__C = ((CT__xdc_runtime_Defaults_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__gatePrms xdc_runtime_Defaults_Module__gatePrms__C = ((CT__xdc_runtime_Defaults_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__id xdc_runtime_Defaults_Module__id__C = (xdc_Bits16)0x8004;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerDefined xdc_runtime_Defaults_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerObj xdc_runtime_Defaults_Module__loggerObj__C = ((CT__xdc_runtime_Defaults_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn0 xdc_runtime_Defaults_Module__loggerFxn0__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn1 xdc_runtime_Defaults_Module__loggerFxn1__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn2 xdc_runtime_Defaults_Module__loggerFxn2__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn4 xdc_runtime_Defaults_Module__loggerFxn4__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn8 xdc_runtime_Defaults_Module__loggerFxn8__C = ((CT__xdc_runtime_Defaults_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Defaults_Module__startupDoneFxn xdc_runtime_Defaults_Module__startupDoneFxn__C = ((CT__xdc_runtime_Defaults_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Defaults_Object__count xdc_runtime_Defaults_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Defaults_Object__heap xdc_runtime_Defaults_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Defaults_Object__sizeof xdc_runtime_Defaults_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Defaults_Object__table xdc_runtime_Defaults_Object__table__C = 0;


/*
 * ======== xdc.runtime.Diags INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Diags_Module__diagsEnabled xdc_runtime_Diags_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Diags_Module__diagsIncluded xdc_runtime_Diags_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Diags_Module__diagsMask xdc_runtime_Diags_Module__diagsMask__C = ((CT__xdc_runtime_Diags_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Diags_Module__gateObj xdc_runtime_Diags_Module__gateObj__C = ((CT__xdc_runtime_Diags_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Diags_Module__gatePrms xdc_runtime_Diags_Module__gatePrms__C = ((CT__xdc_runtime_Diags_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Diags_Module__id xdc_runtime_Diags_Module__id__C = (xdc_Bits16)0x8005;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerDefined xdc_runtime_Diags_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerObj xdc_runtime_Diags_Module__loggerObj__C = ((CT__xdc_runtime_Diags_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn0 xdc_runtime_Diags_Module__loggerFxn0__C = ((CT__xdc_runtime_Diags_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn1 xdc_runtime_Diags_Module__loggerFxn1__C = ((CT__xdc_runtime_Diags_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn2 xdc_runtime_Diags_Module__loggerFxn2__C = ((CT__xdc_runtime_Diags_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn4 xdc_runtime_Diags_Module__loggerFxn4__C = ((CT__xdc_runtime_Diags_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn8 xdc_runtime_Diags_Module__loggerFxn8__C = ((CT__xdc_runtime_Diags_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Diags_Module__startupDoneFxn xdc_runtime_Diags_Module__startupDoneFxn__C = ((CT__xdc_runtime_Diags_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Diags_Object__count xdc_runtime_Diags_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Diags_Object__heap xdc_runtime_Diags_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Diags_Object__sizeof xdc_runtime_Diags_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Diags_Object__table xdc_runtime_Diags_Object__table__C = 0;

/* setMaskEnabled__C */
__FAR__ const CT__xdc_runtime_Diags_setMaskEnabled xdc_runtime_Diags_setMaskEnabled__C = 0;

/* dictBase__C */
__FAR__ const CT__xdc_runtime_Diags_dictBase xdc_runtime_Diags_dictBase__C = ((CT__xdc_runtime_Diags_dictBase)0);


/*
 * ======== xdc.runtime.Error INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V = {
    (xdc_UInt16)0x0,  /* count */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Error_Module__diagsEnabled xdc_runtime_Error_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Error_Module__diagsIncluded xdc_runtime_Error_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Error_Module__diagsMask xdc_runtime_Error_Module__diagsMask__C = ((CT__xdc_runtime_Error_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Error_Module__gateObj xdc_runtime_Error_Module__gateObj__C = ((CT__xdc_runtime_Error_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Error_Module__gatePrms xdc_runtime_Error_Module__gatePrms__C = ((CT__xdc_runtime_Error_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Error_Module__id xdc_runtime_Error_Module__id__C = (xdc_Bits16)0x8006;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerDefined xdc_runtime_Error_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerObj xdc_runtime_Error_Module__loggerObj__C = ((CT__xdc_runtime_Error_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn0 xdc_runtime_Error_Module__loggerFxn0__C = ((CT__xdc_runtime_Error_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn1 xdc_runtime_Error_Module__loggerFxn1__C = ((CT__xdc_runtime_Error_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn2 xdc_runtime_Error_Module__loggerFxn2__C = ((CT__xdc_runtime_Error_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn4 xdc_runtime_Error_Module__loggerFxn4__C = ((CT__xdc_runtime_Error_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn8 xdc_runtime_Error_Module__loggerFxn8__C = ((CT__xdc_runtime_Error_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Error_Module__startupDoneFxn xdc_runtime_Error_Module__startupDoneFxn__C = ((CT__xdc_runtime_Error_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Error_Object__count xdc_runtime_Error_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Error_Object__heap xdc_runtime_Error_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Error_Object__sizeof xdc_runtime_Error_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Error_Object__table xdc_runtime_Error_Object__table__C = 0;

/* E_generic__C */
__FAR__ const CT__xdc_runtime_Error_E_generic xdc_runtime_Error_E_generic__C = (((xdc_runtime_Error_Id)4117) << 16 | 0);

/* E_memory__C */
__FAR__ const CT__xdc_runtime_Error_E_memory xdc_runtime_Error_E_memory__C = (((xdc_runtime_Error_Id)4121) << 16 | 0);

/* E_msgCode__C */
__FAR__ const CT__xdc_runtime_Error_E_msgCode xdc_runtime_Error_E_msgCode__C = (((xdc_runtime_Error_Id)4155) << 16 | 0);

/* policy__C */
__FAR__ const CT__xdc_runtime_Error_policy xdc_runtime_Error_policy__C = xdc_runtime_Error_UNWIND;

/* raiseHook__C */
__FAR__ const CT__xdc_runtime_Error_raiseHook xdc_runtime_Error_raiseHook__C = ((CT__xdc_runtime_Error_raiseHook)((xdc_Fxn)ti_sysbios_BIOS_errorRaiseHook__I));

/* maxDepth__C */
__FAR__ const CT__xdc_runtime_Error_maxDepth xdc_runtime_Error_maxDepth__C = (xdc_UInt16)0x10;


/*
 * ======== xdc.runtime.Gate INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Gate_Module__diagsEnabled xdc_runtime_Gate_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Gate_Module__diagsIncluded xdc_runtime_Gate_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Gate_Module__diagsMask xdc_runtime_Gate_Module__diagsMask__C = ((CT__xdc_runtime_Gate_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Gate_Module__gateObj xdc_runtime_Gate_Module__gateObj__C = ((CT__xdc_runtime_Gate_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Gate_Module__gatePrms xdc_runtime_Gate_Module__gatePrms__C = ((CT__xdc_runtime_Gate_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Gate_Module__id xdc_runtime_Gate_Module__id__C = (xdc_Bits16)0x8007;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerDefined xdc_runtime_Gate_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerObj xdc_runtime_Gate_Module__loggerObj__C = ((CT__xdc_runtime_Gate_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn0 xdc_runtime_Gate_Module__loggerFxn0__C = ((CT__xdc_runtime_Gate_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn1 xdc_runtime_Gate_Module__loggerFxn1__C = ((CT__xdc_runtime_Gate_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn2 xdc_runtime_Gate_Module__loggerFxn2__C = ((CT__xdc_runtime_Gate_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn4 xdc_runtime_Gate_Module__loggerFxn4__C = ((CT__xdc_runtime_Gate_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn8 xdc_runtime_Gate_Module__loggerFxn8__C = ((CT__xdc_runtime_Gate_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Gate_Module__startupDoneFxn xdc_runtime_Gate_Module__startupDoneFxn__C = ((CT__xdc_runtime_Gate_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Gate_Object__count xdc_runtime_Gate_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Gate_Object__heap xdc_runtime_Gate_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Gate_Object__sizeof xdc_runtime_Gate_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Gate_Object__table xdc_runtime_Gate_Object__table__C = 0;


/*
 * ======== xdc.runtime.Log INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Log_Module__diagsEnabled xdc_runtime_Log_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Log_Module__diagsIncluded xdc_runtime_Log_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Log_Module__diagsMask xdc_runtime_Log_Module__diagsMask__C = ((CT__xdc_runtime_Log_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Log_Module__gateObj xdc_runtime_Log_Module__gateObj__C = ((CT__xdc_runtime_Log_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Log_Module__gatePrms xdc_runtime_Log_Module__gatePrms__C = ((CT__xdc_runtime_Log_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Log_Module__id xdc_runtime_Log_Module__id__C = (xdc_Bits16)0x8008;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerDefined xdc_runtime_Log_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerObj xdc_runtime_Log_Module__loggerObj__C = ((CT__xdc_runtime_Log_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn0 xdc_runtime_Log_Module__loggerFxn0__C = ((CT__xdc_runtime_Log_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn1 xdc_runtime_Log_Module__loggerFxn1__C = ((CT__xdc_runtime_Log_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn2 xdc_runtime_Log_Module__loggerFxn2__C = ((CT__xdc_runtime_Log_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn4 xdc_runtime_Log_Module__loggerFxn4__C = ((CT__xdc_runtime_Log_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn8 xdc_runtime_Log_Module__loggerFxn8__C = ((CT__xdc_runtime_Log_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Log_Module__startupDoneFxn xdc_runtime_Log_Module__startupDoneFxn__C = ((CT__xdc_runtime_Log_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Log_Object__count xdc_runtime_Log_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Log_Object__heap xdc_runtime_Log_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Log_Object__sizeof xdc_runtime_Log_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Log_Object__table xdc_runtime_Log_Object__table__C = 0;

/* L_construct__C */
__FAR__ const CT__xdc_runtime_Log_L_construct xdc_runtime_Log_L_construct__C = (((xdc_runtime_Log_Event)5630) << 16 | 4);

/* L_create__C */
__FAR__ const CT__xdc_runtime_Log_L_create xdc_runtime_Log_L_create__C = (((xdc_runtime_Log_Event)5654) << 16 | 4);

/* L_destruct__C */
__FAR__ const CT__xdc_runtime_Log_L_destruct xdc_runtime_Log_L_destruct__C = (((xdc_runtime_Log_Event)5675) << 16 | 4);

/* L_delete__C */
__FAR__ const CT__xdc_runtime_Log_L_delete xdc_runtime_Log_L_delete__C = (((xdc_runtime_Log_Event)5694) << 16 | 4);

/* L_error__C */
__FAR__ const CT__xdc_runtime_Log_L_error xdc_runtime_Log_L_error__C = (((xdc_runtime_Log_Event)5711) << 16 | 192);

/* L_warning__C */
__FAR__ const CT__xdc_runtime_Log_L_warning xdc_runtime_Log_L_warning__C = (((xdc_runtime_Log_Event)5725) << 16 | 224);

/* L_info__C */
__FAR__ const CT__xdc_runtime_Log_L_info xdc_runtime_Log_L_info__C = (((xdc_runtime_Log_Event)5741) << 16 | 16384);

/* L_start__C */
__FAR__ const CT__xdc_runtime_Log_L_start xdc_runtime_Log_L_start__C = (((xdc_runtime_Log_Event)5748) << 16 | 32768);

/* L_stop__C */
__FAR__ const CT__xdc_runtime_Log_L_stop xdc_runtime_Log_L_stop__C = (((xdc_runtime_Log_Event)5759) << 16 | 32768);

/* L_startInstance__C */
__FAR__ const CT__xdc_runtime_Log_L_startInstance xdc_runtime_Log_L_startInstance__C = (((xdc_runtime_Log_Event)5769) << 16 | 32768);

/* L_stopInstance__C */
__FAR__ const CT__xdc_runtime_Log_L_stopInstance xdc_runtime_Log_L_stopInstance__C = (((xdc_runtime_Log_Event)5788) << 16 | 32768);


/*
 * ======== xdc.runtime.Main INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Main_Module__diagsEnabled xdc_runtime_Main_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Main_Module__diagsIncluded xdc_runtime_Main_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Main_Module__diagsMask xdc_runtime_Main_Module__diagsMask__C = ((CT__xdc_runtime_Main_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Main_Module__gateObj xdc_runtime_Main_Module__gateObj__C = ((CT__xdc_runtime_Main_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Main_Module__gatePrms xdc_runtime_Main_Module__gatePrms__C = ((CT__xdc_runtime_Main_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Main_Module__id xdc_runtime_Main_Module__id__C = (xdc_Bits16)0x8009;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerDefined xdc_runtime_Main_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerObj xdc_runtime_Main_Module__loggerObj__C = ((CT__xdc_runtime_Main_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn0 xdc_runtime_Main_Module__loggerFxn0__C = ((CT__xdc_runtime_Main_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn1 xdc_runtime_Main_Module__loggerFxn1__C = ((CT__xdc_runtime_Main_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn2 xdc_runtime_Main_Module__loggerFxn2__C = ((CT__xdc_runtime_Main_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn4 xdc_runtime_Main_Module__loggerFxn4__C = ((CT__xdc_runtime_Main_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn8 xdc_runtime_Main_Module__loggerFxn8__C = ((CT__xdc_runtime_Main_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Main_Module__startupDoneFxn xdc_runtime_Main_Module__startupDoneFxn__C = ((CT__xdc_runtime_Main_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Main_Object__count xdc_runtime_Main_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Main_Object__heap xdc_runtime_Main_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Main_Object__sizeof xdc_runtime_Main_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Main_Object__table xdc_runtime_Main_Object__table__C = 0;


/*
 * ======== xdc.runtime.Main_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Memory INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V = {
    (xdc_SizeT)0x8,  /* maxDefaultTypeAlign */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Memory_Module__diagsEnabled xdc_runtime_Memory_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Memory_Module__diagsIncluded xdc_runtime_Memory_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Memory_Module__diagsMask xdc_runtime_Memory_Module__diagsMask__C = ((CT__xdc_runtime_Memory_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Memory_Module__gateObj xdc_runtime_Memory_Module__gateObj__C = ((CT__xdc_runtime_Memory_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Memory_Module__gatePrms xdc_runtime_Memory_Module__gatePrms__C = ((CT__xdc_runtime_Memory_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Memory_Module__id xdc_runtime_Memory_Module__id__C = (xdc_Bits16)0x800a;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerDefined xdc_runtime_Memory_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerObj xdc_runtime_Memory_Module__loggerObj__C = ((CT__xdc_runtime_Memory_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn0 xdc_runtime_Memory_Module__loggerFxn0__C = ((CT__xdc_runtime_Memory_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn1 xdc_runtime_Memory_Module__loggerFxn1__C = ((CT__xdc_runtime_Memory_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn2 xdc_runtime_Memory_Module__loggerFxn2__C = ((CT__xdc_runtime_Memory_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn4 xdc_runtime_Memory_Module__loggerFxn4__C = ((CT__xdc_runtime_Memory_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn8 xdc_runtime_Memory_Module__loggerFxn8__C = ((CT__xdc_runtime_Memory_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Memory_Module__startupDoneFxn xdc_runtime_Memory_Module__startupDoneFxn__C = ((CT__xdc_runtime_Memory_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Memory_Object__count xdc_runtime_Memory_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Memory_Object__heap xdc_runtime_Memory_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Memory_Object__sizeof xdc_runtime_Memory_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Memory_Object__table xdc_runtime_Memory_Object__table__C = 0;

/* defaultHeapInstance__C */
__FAR__ const CT__xdc_runtime_Memory_defaultHeapInstance xdc_runtime_Memory_defaultHeapInstance__C = (xdc_runtime_IHeap_Handle)&ti_sysbios_heaps_HeapMem_Object__table__V[0];


/*
 * ======== xdc.runtime.Memory_HeapProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Registry INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V = {
    ((xdc_runtime_Types_RegDesc*)0),  /* listHead */
    (xdc_Bits16)0x7fff,  /* curId */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Registry_Module__diagsEnabled xdc_runtime_Registry_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Registry_Module__diagsIncluded xdc_runtime_Registry_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Registry_Module__diagsMask xdc_runtime_Registry_Module__diagsMask__C = ((CT__xdc_runtime_Registry_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Registry_Module__gateObj xdc_runtime_Registry_Module__gateObj__C = ((CT__xdc_runtime_Registry_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Registry_Module__gatePrms xdc_runtime_Registry_Module__gatePrms__C = ((CT__xdc_runtime_Registry_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Registry_Module__id xdc_runtime_Registry_Module__id__C = (xdc_Bits16)0x800b;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerDefined xdc_runtime_Registry_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerObj xdc_runtime_Registry_Module__loggerObj__C = ((CT__xdc_runtime_Registry_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn0 xdc_runtime_Registry_Module__loggerFxn0__C = ((CT__xdc_runtime_Registry_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn1 xdc_runtime_Registry_Module__loggerFxn1__C = ((CT__xdc_runtime_Registry_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn2 xdc_runtime_Registry_Module__loggerFxn2__C = ((CT__xdc_runtime_Registry_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn4 xdc_runtime_Registry_Module__loggerFxn4__C = ((CT__xdc_runtime_Registry_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn8 xdc_runtime_Registry_Module__loggerFxn8__C = ((CT__xdc_runtime_Registry_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Registry_Module__startupDoneFxn xdc_runtime_Registry_Module__startupDoneFxn__C = ((CT__xdc_runtime_Registry_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Registry_Object__count xdc_runtime_Registry_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Registry_Object__heap xdc_runtime_Registry_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Registry_Object__sizeof xdc_runtime_Registry_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Registry_Object__table xdc_runtime_Registry_Object__table__C = 0;


/*
 * ======== xdc.runtime.Startup INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V = {
    ((xdc_Int*)0),  /* stateTab */
    0,  /* execFlag */
    0,  /* rtsDoneFlag */
};

/* --> xdc_runtime_Startup_firstFxns__A */
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[2] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_heaps_HeapMem_init__I)),  /* [0] */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_hal_Hwi_initStack)),  /* [1] */
};

/* --> xdc_runtime_Startup_lastFxns__A */
const __T1_xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__A[1] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)xdc_runtime_System_lastFxn__I)),  /* [0] */
};

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[13] = {
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_System_Module_startup__E)),  /* [0] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_SysMin_Module_startup__E)),  /* [1] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_Exception_Module_startup__E)),  /* [2] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_Hwi_Module_startup__E)),  /* [3] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_TimestampProvider_Module_startup__E)),  /* [4] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_hal_Hwi_Module_startup__E)),  /* [5] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_hal_Timer_Module_startup__E)),  /* [6] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Clock_Module_startup__E)),  /* [7] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Swi_Module_startup__E)),  /* [8] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Task_Module_startup__E)),  /* [9] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Module_startup__E)),  /* [10] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_tesla_TimerSupport_Module_startup__E)),  /* [11] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_c64p_tesla_Wugen_Module_startup__E)),  /* [12] */
};

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[13] = {
    1,  /* [0] */
    1,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
    1,  /* [4] */
    0,  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    0,  /* [8] */
    0,  /* [9] */
    0,  /* [10] */
    0,  /* [11] */
    0,  /* [12] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Startup_Module__diagsEnabled xdc_runtime_Startup_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Startup_Module__diagsIncluded xdc_runtime_Startup_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Startup_Module__diagsMask xdc_runtime_Startup_Module__diagsMask__C = ((CT__xdc_runtime_Startup_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Startup_Module__gateObj xdc_runtime_Startup_Module__gateObj__C = ((CT__xdc_runtime_Startup_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Startup_Module__gatePrms xdc_runtime_Startup_Module__gatePrms__C = ((CT__xdc_runtime_Startup_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Startup_Module__id xdc_runtime_Startup_Module__id__C = (xdc_Bits16)0x800c;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerDefined xdc_runtime_Startup_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerObj xdc_runtime_Startup_Module__loggerObj__C = ((CT__xdc_runtime_Startup_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn0 xdc_runtime_Startup_Module__loggerFxn0__C = ((CT__xdc_runtime_Startup_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn1 xdc_runtime_Startup_Module__loggerFxn1__C = ((CT__xdc_runtime_Startup_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn2 xdc_runtime_Startup_Module__loggerFxn2__C = ((CT__xdc_runtime_Startup_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn4 xdc_runtime_Startup_Module__loggerFxn4__C = ((CT__xdc_runtime_Startup_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn8 xdc_runtime_Startup_Module__loggerFxn8__C = ((CT__xdc_runtime_Startup_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Startup_Module__startupDoneFxn xdc_runtime_Startup_Module__startupDoneFxn__C = ((CT__xdc_runtime_Startup_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Startup_Object__count xdc_runtime_Startup_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Startup_Object__heap xdc_runtime_Startup_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Startup_Object__sizeof xdc_runtime_Startup_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Startup_Object__table xdc_runtime_Startup_Object__table__C = 0;

/* maxPasses__C */
__FAR__ const CT__xdc_runtime_Startup_maxPasses xdc_runtime_Startup_maxPasses__C = (xdc_Int)0x20;

/* firstFxns__C */
__FAR__ const CT__xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__C = {2, ((__T1_xdc_runtime_Startup_firstFxns*)xdc_runtime_Startup_firstFxns__A)};

/* lastFxns__C */
__FAR__ const CT__xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__C = {1, ((__T1_xdc_runtime_Startup_lastFxns*)xdc_runtime_Startup_lastFxns__A)};

/* startModsFxn__C */
__FAR__ const CT__xdc_runtime_Startup_startModsFxn xdc_runtime_Startup_startModsFxn__C = ((CT__xdc_runtime_Startup_startModsFxn)((xdc_Fxn)xdc_runtime_Startup_startMods__I));

/* execImpl__C */
__FAR__ const CT__xdc_runtime_Startup_execImpl xdc_runtime_Startup_execImpl__C = ((CT__xdc_runtime_Startup_execImpl)((xdc_Fxn)xdc_runtime_Startup_exec__I));

/* sfxnTab__C */
__FAR__ const CT__xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__C = ((CT__xdc_runtime_Startup_sfxnTab)xdc_runtime_Startup_sfxnTab__A);

/* sfxnRts__C */
__FAR__ const CT__xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__C = ((CT__xdc_runtime_Startup_sfxnRts)xdc_runtime_Startup_sfxnRts__A);


/*
 * ======== xdc.runtime.SysMin INITIALIZERS ========
 */

/* --> xdc_runtime_SysMin_Module_State_0_outbuf__A */
__T1_xdc_runtime_SysMin_Module_State__outbuf xdc_runtime_SysMin_Module_State_0_outbuf__A[1024];

/* Module__state__V */
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V = {
    ((void*)xdc_runtime_SysMin_Module_State_0_outbuf__A),  /* outbuf */
    (xdc_UInt)0x0,  /* outidx */
    0,  /* wrapped */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsEnabled xdc_runtime_SysMin_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsIncluded xdc_runtime_SysMin_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__diagsMask xdc_runtime_SysMin_Module__diagsMask__C = ((CT__xdc_runtime_SysMin_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__gateObj xdc_runtime_SysMin_Module__gateObj__C = ((CT__xdc_runtime_SysMin_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__gatePrms xdc_runtime_SysMin_Module__gatePrms__C = ((CT__xdc_runtime_SysMin_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__id xdc_runtime_SysMin_Module__id__C = (xdc_Bits16)0x800e;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerDefined xdc_runtime_SysMin_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerObj xdc_runtime_SysMin_Module__loggerObj__C = ((CT__xdc_runtime_SysMin_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn0 xdc_runtime_SysMin_Module__loggerFxn0__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn1 xdc_runtime_SysMin_Module__loggerFxn1__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn2 xdc_runtime_SysMin_Module__loggerFxn2__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn4 xdc_runtime_SysMin_Module__loggerFxn4__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn8 xdc_runtime_SysMin_Module__loggerFxn8__C = ((CT__xdc_runtime_SysMin_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_SysMin_Module__startupDoneFxn xdc_runtime_SysMin_Module__startupDoneFxn__C = ((CT__xdc_runtime_SysMin_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_SysMin_Object__count xdc_runtime_SysMin_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_SysMin_Object__heap xdc_runtime_SysMin_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_SysMin_Object__sizeof xdc_runtime_SysMin_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_SysMin_Object__table xdc_runtime_SysMin_Object__table__C = 0;

/* bufSize__C */
__FAR__ const CT__xdc_runtime_SysMin_bufSize xdc_runtime_SysMin_bufSize__C = (xdc_SizeT)0x400;

/* flushAtExit__C */
__FAR__ const CT__xdc_runtime_SysMin_flushAtExit xdc_runtime_SysMin_flushAtExit__C = 1;

/* outputFxn__C */
__FAR__ const CT__xdc_runtime_SysMin_outputFxn xdc_runtime_SysMin_outputFxn__C = ((CT__xdc_runtime_SysMin_outputFxn)0);

/* outputFunc__C */
__FAR__ const CT__xdc_runtime_SysMin_outputFunc xdc_runtime_SysMin_outputFunc__C = ((CT__xdc_runtime_SysMin_outputFunc)((xdc_Fxn)xdc_runtime_SysMin_output__I));


/*
 * ======== xdc.runtime.System INITIALIZERS ========
 */

/* --> xdc_runtime_System_Module_State_0_atexitHandlers__A */
__T1_xdc_runtime_System_Module_State__atexitHandlers xdc_runtime_System_Module_State_0_atexitHandlers__A[8] = {
    ((xdc_Void(*)(xdc_Int))0),  /* [0] */
    ((xdc_Void(*)(xdc_Int))0),  /* [1] */
    ((xdc_Void(*)(xdc_Int))0),  /* [2] */
    ((xdc_Void(*)(xdc_Int))0),  /* [3] */
    ((xdc_Void(*)(xdc_Int))0),  /* [4] */
    ((xdc_Void(*)(xdc_Int))0),  /* [5] */
    ((xdc_Void(*)(xdc_Int))0),  /* [6] */
    ((xdc_Void(*)(xdc_Int))0),  /* [7] */
};

/* Module__state__V */
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V = {
    ((void*)xdc_runtime_System_Module_State_0_atexitHandlers__A),  /* atexitHandlers */
    (xdc_Int)0x0,  /* numAtexitHandlers */
    (xdc_Int)0xcafe,  /* exitStatus */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_System_Module__diagsEnabled xdc_runtime_System_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_System_Module__diagsIncluded xdc_runtime_System_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_System_Module__diagsMask xdc_runtime_System_Module__diagsMask__C = ((CT__xdc_runtime_System_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_System_Module__gateObj xdc_runtime_System_Module__gateObj__C = ((CT__xdc_runtime_System_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_System_Module__gatePrms xdc_runtime_System_Module__gatePrms__C = ((CT__xdc_runtime_System_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_System_Module__id xdc_runtime_System_Module__id__C = (xdc_Bits16)0x800d;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerDefined xdc_runtime_System_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerObj xdc_runtime_System_Module__loggerObj__C = ((CT__xdc_runtime_System_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn0 xdc_runtime_System_Module__loggerFxn0__C = ((CT__xdc_runtime_System_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn1 xdc_runtime_System_Module__loggerFxn1__C = ((CT__xdc_runtime_System_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn2 xdc_runtime_System_Module__loggerFxn2__C = ((CT__xdc_runtime_System_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn4 xdc_runtime_System_Module__loggerFxn4__C = ((CT__xdc_runtime_System_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_System_Module__loggerFxn8 xdc_runtime_System_Module__loggerFxn8__C = ((CT__xdc_runtime_System_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_System_Module__startupDoneFxn xdc_runtime_System_Module__startupDoneFxn__C = ((CT__xdc_runtime_System_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_System_Object__count xdc_runtime_System_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_System_Object__heap xdc_runtime_System_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_System_Object__sizeof xdc_runtime_System_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_System_Object__table xdc_runtime_System_Object__table__C = 0;

/* A_cannotFitIntoArg__C */
__FAR__ const CT__xdc_runtime_System_A_cannotFitIntoArg xdc_runtime_System_A_cannotFitIntoArg__C = (((xdc_runtime_Assert_Id)307) << 16 | 16);

/* maxAtexitHandlers__C */
__FAR__ const CT__xdc_runtime_System_maxAtexitHandlers xdc_runtime_System_maxAtexitHandlers__C = (xdc_Int)0x8;

/* extendFxn__C */
__FAR__ const CT__xdc_runtime_System_extendFxn xdc_runtime_System_extendFxn__C = ((CT__xdc_runtime_System_extendFxn)((xdc_Fxn)xdc_runtime_System_printfExtend__I));


/*
 * ======== xdc.runtime.System_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.System_SupportProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Text INITIALIZERS ========
 */

/* Module__state__V */
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V = {
    ((xdc_Ptr)((void*)&xdc_runtime_Text_charTab__A[0])),  /* charBase */
    ((xdc_Ptr)((void*)&xdc_runtime_Text_nodeTab__A[0])),  /* nodeBase */
};

/* --> xdc_runtime_Text_charTab__A */
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[6886] = {
    (xdc_Char)0x0,  /* [0] */
    (xdc_Char)0x41,  /* [1] */
    (xdc_Char)0x5f,  /* [2] */
    (xdc_Char)0x69,  /* [3] */
    (xdc_Char)0x6e,  /* [4] */
    (xdc_Char)0x69,  /* [5] */
    (xdc_Char)0x74,  /* [6] */
    (xdc_Char)0x69,  /* [7] */
    (xdc_Char)0x61,  /* [8] */
    (xdc_Char)0x6c,  /* [9] */
    (xdc_Char)0x69,  /* [10] */
    (xdc_Char)0x7a,  /* [11] */
    (xdc_Char)0x65,  /* [12] */
    (xdc_Char)0x64,  /* [13] */
    (xdc_Char)0x50,  /* [14] */
    (xdc_Char)0x61,  /* [15] */
    (xdc_Char)0x72,  /* [16] */
    (xdc_Char)0x61,  /* [17] */
    (xdc_Char)0x6d,  /* [18] */
    (xdc_Char)0x73,  /* [19] */
    (xdc_Char)0x3a,  /* [20] */
    (xdc_Char)0x20,  /* [21] */
    (xdc_Char)0x75,  /* [22] */
    (xdc_Char)0x6e,  /* [23] */
    (xdc_Char)0x69,  /* [24] */
    (xdc_Char)0x6e,  /* [25] */
    (xdc_Char)0x69,  /* [26] */
    (xdc_Char)0x74,  /* [27] */
    (xdc_Char)0x69,  /* [28] */
    (xdc_Char)0x61,  /* [29] */
    (xdc_Char)0x6c,  /* [30] */
    (xdc_Char)0x69,  /* [31] */
    (xdc_Char)0x7a,  /* [32] */
    (xdc_Char)0x65,  /* [33] */
    (xdc_Char)0x64,  /* [34] */
    (xdc_Char)0x20,  /* [35] */
    (xdc_Char)0x50,  /* [36] */
    (xdc_Char)0x61,  /* [37] */
    (xdc_Char)0x72,  /* [38] */
    (xdc_Char)0x61,  /* [39] */
    (xdc_Char)0x6d,  /* [40] */
    (xdc_Char)0x73,  /* [41] */
    (xdc_Char)0x20,  /* [42] */
    (xdc_Char)0x73,  /* [43] */
    (xdc_Char)0x74,  /* [44] */
    (xdc_Char)0x72,  /* [45] */
    (xdc_Char)0x75,  /* [46] */
    (xdc_Char)0x63,  /* [47] */
    (xdc_Char)0x74,  /* [48] */
    (xdc_Char)0x0,  /* [49] */
    (xdc_Char)0x48,  /* [50] */
    (xdc_Char)0x65,  /* [51] */
    (xdc_Char)0x61,  /* [52] */
    (xdc_Char)0x70,  /* [53] */
    (xdc_Char)0x4d,  /* [54] */
    (xdc_Char)0x69,  /* [55] */
    (xdc_Char)0x6e,  /* [56] */
    (xdc_Char)0x5f,  /* [57] */
    (xdc_Char)0x63,  /* [58] */
    (xdc_Char)0x72,  /* [59] */
    (xdc_Char)0x65,  /* [60] */
    (xdc_Char)0x61,  /* [61] */
    (xdc_Char)0x74,  /* [62] */
    (xdc_Char)0x65,  /* [63] */
    (xdc_Char)0x20,  /* [64] */
    (xdc_Char)0x63,  /* [65] */
    (xdc_Char)0x61,  /* [66] */
    (xdc_Char)0x6e,  /* [67] */
    (xdc_Char)0x6e,  /* [68] */
    (xdc_Char)0x6f,  /* [69] */
    (xdc_Char)0x74,  /* [70] */
    (xdc_Char)0x20,  /* [71] */
    (xdc_Char)0x68,  /* [72] */
    (xdc_Char)0x61,  /* [73] */
    (xdc_Char)0x76,  /* [74] */
    (xdc_Char)0x65,  /* [75] */
    (xdc_Char)0x20,  /* [76] */
    (xdc_Char)0x61,  /* [77] */
    (xdc_Char)0x20,  /* [78] */
    (xdc_Char)0x7a,  /* [79] */
    (xdc_Char)0x65,  /* [80] */
    (xdc_Char)0x72,  /* [81] */
    (xdc_Char)0x6f,  /* [82] */
    (xdc_Char)0x20,  /* [83] */
    (xdc_Char)0x73,  /* [84] */
    (xdc_Char)0x69,  /* [85] */
    (xdc_Char)0x7a,  /* [86] */
    (xdc_Char)0x65,  /* [87] */
    (xdc_Char)0x20,  /* [88] */
    (xdc_Char)0x76,  /* [89] */
    (xdc_Char)0x61,  /* [90] */
    (xdc_Char)0x6c,  /* [91] */
    (xdc_Char)0x75,  /* [92] */
    (xdc_Char)0x65,  /* [93] */
    (xdc_Char)0x0,  /* [94] */
    (xdc_Char)0x48,  /* [95] */
    (xdc_Char)0x65,  /* [96] */
    (xdc_Char)0x61,  /* [97] */
    (xdc_Char)0x70,  /* [98] */
    (xdc_Char)0x53,  /* [99] */
    (xdc_Char)0x74,  /* [100] */
    (xdc_Char)0x64,  /* [101] */
    (xdc_Char)0x5f,  /* [102] */
    (xdc_Char)0x63,  /* [103] */
    (xdc_Char)0x72,  /* [104] */
    (xdc_Char)0x65,  /* [105] */
    (xdc_Char)0x61,  /* [106] */
    (xdc_Char)0x74,  /* [107] */
    (xdc_Char)0x65,  /* [108] */
    (xdc_Char)0x20,  /* [109] */
    (xdc_Char)0x63,  /* [110] */
    (xdc_Char)0x61,  /* [111] */
    (xdc_Char)0x6e,  /* [112] */
    (xdc_Char)0x6e,  /* [113] */
    (xdc_Char)0x6f,  /* [114] */
    (xdc_Char)0x74,  /* [115] */
    (xdc_Char)0x20,  /* [116] */
    (xdc_Char)0x68,  /* [117] */
    (xdc_Char)0x61,  /* [118] */
    (xdc_Char)0x76,  /* [119] */
    (xdc_Char)0x65,  /* [120] */
    (xdc_Char)0x20,  /* [121] */
    (xdc_Char)0x61,  /* [122] */
    (xdc_Char)0x20,  /* [123] */
    (xdc_Char)0x7a,  /* [124] */
    (xdc_Char)0x65,  /* [125] */
    (xdc_Char)0x72,  /* [126] */
    (xdc_Char)0x6f,  /* [127] */
    (xdc_Char)0x20,  /* [128] */
    (xdc_Char)0x73,  /* [129] */
    (xdc_Char)0x69,  /* [130] */
    (xdc_Char)0x7a,  /* [131] */
    (xdc_Char)0x65,  /* [132] */
    (xdc_Char)0x20,  /* [133] */
    (xdc_Char)0x76,  /* [134] */
    (xdc_Char)0x61,  /* [135] */
    (xdc_Char)0x6c,  /* [136] */
    (xdc_Char)0x75,  /* [137] */
    (xdc_Char)0x65,  /* [138] */
    (xdc_Char)0x0,  /* [139] */
    (xdc_Char)0x48,  /* [140] */
    (xdc_Char)0x65,  /* [141] */
    (xdc_Char)0x61,  /* [142] */
    (xdc_Char)0x70,  /* [143] */
    (xdc_Char)0x53,  /* [144] */
    (xdc_Char)0x74,  /* [145] */
    (xdc_Char)0x64,  /* [146] */
    (xdc_Char)0x20,  /* [147] */
    (xdc_Char)0x69,  /* [148] */
    (xdc_Char)0x6e,  /* [149] */
    (xdc_Char)0x73,  /* [150] */
    (xdc_Char)0x74,  /* [151] */
    (xdc_Char)0x61,  /* [152] */
    (xdc_Char)0x6e,  /* [153] */
    (xdc_Char)0x63,  /* [154] */
    (xdc_Char)0x65,  /* [155] */
    (xdc_Char)0x20,  /* [156] */
    (xdc_Char)0x74,  /* [157] */
    (xdc_Char)0x6f,  /* [158] */
    (xdc_Char)0x74,  /* [159] */
    (xdc_Char)0x61,  /* [160] */
    (xdc_Char)0x6c,  /* [161] */
    (xdc_Char)0x46,  /* [162] */
    (xdc_Char)0x72,  /* [163] */
    (xdc_Char)0x65,  /* [164] */
    (xdc_Char)0x65,  /* [165] */
    (xdc_Char)0x53,  /* [166] */
    (xdc_Char)0x69,  /* [167] */
    (xdc_Char)0x7a,  /* [168] */
    (xdc_Char)0x65,  /* [169] */
    (xdc_Char)0x20,  /* [170] */
    (xdc_Char)0x69,  /* [171] */
    (xdc_Char)0x73,  /* [172] */
    (xdc_Char)0x20,  /* [173] */
    (xdc_Char)0x67,  /* [174] */
    (xdc_Char)0x72,  /* [175] */
    (xdc_Char)0x65,  /* [176] */
    (xdc_Char)0x61,  /* [177] */
    (xdc_Char)0x74,  /* [178] */
    (xdc_Char)0x65,  /* [179] */
    (xdc_Char)0x72,  /* [180] */
    (xdc_Char)0x20,  /* [181] */
    (xdc_Char)0x74,  /* [182] */
    (xdc_Char)0x68,  /* [183] */
    (xdc_Char)0x61,  /* [184] */
    (xdc_Char)0x6e,  /* [185] */
    (xdc_Char)0x20,  /* [186] */
    (xdc_Char)0x73,  /* [187] */
    (xdc_Char)0x74,  /* [188] */
    (xdc_Char)0x61,  /* [189] */
    (xdc_Char)0x72,  /* [190] */
    (xdc_Char)0x74,  /* [191] */
    (xdc_Char)0x69,  /* [192] */
    (xdc_Char)0x6e,  /* [193] */
    (xdc_Char)0x67,  /* [194] */
    (xdc_Char)0x20,  /* [195] */
    (xdc_Char)0x73,  /* [196] */
    (xdc_Char)0x69,  /* [197] */
    (xdc_Char)0x7a,  /* [198] */
    (xdc_Char)0x65,  /* [199] */
    (xdc_Char)0x0,  /* [200] */
    (xdc_Char)0x48,  /* [201] */
    (xdc_Char)0x65,  /* [202] */
    (xdc_Char)0x61,  /* [203] */
    (xdc_Char)0x70,  /* [204] */
    (xdc_Char)0x53,  /* [205] */
    (xdc_Char)0x74,  /* [206] */
    (xdc_Char)0x64,  /* [207] */
    (xdc_Char)0x5f,  /* [208] */
    (xdc_Char)0x61,  /* [209] */
    (xdc_Char)0x6c,  /* [210] */
    (xdc_Char)0x6c,  /* [211] */
    (xdc_Char)0x6f,  /* [212] */
    (xdc_Char)0x63,  /* [213] */
    (xdc_Char)0x20,  /* [214] */
    (xdc_Char)0x2d,  /* [215] */
    (xdc_Char)0x20,  /* [216] */
    (xdc_Char)0x72,  /* [217] */
    (xdc_Char)0x65,  /* [218] */
    (xdc_Char)0x71,  /* [219] */
    (xdc_Char)0x75,  /* [220] */
    (xdc_Char)0x65,  /* [221] */
    (xdc_Char)0x73,  /* [222] */
    (xdc_Char)0x74,  /* [223] */
    (xdc_Char)0x65,  /* [224] */
    (xdc_Char)0x64,  /* [225] */
    (xdc_Char)0x20,  /* [226] */
    (xdc_Char)0x61,  /* [227] */
    (xdc_Char)0x6c,  /* [228] */
    (xdc_Char)0x69,  /* [229] */
    (xdc_Char)0x67,  /* [230] */
    (xdc_Char)0x6e,  /* [231] */
    (xdc_Char)0x6d,  /* [232] */
    (xdc_Char)0x65,  /* [233] */
    (xdc_Char)0x6e,  /* [234] */
    (xdc_Char)0x74,  /* [235] */
    (xdc_Char)0x20,  /* [236] */
    (xdc_Char)0x69,  /* [237] */
    (xdc_Char)0x73,  /* [238] */
    (xdc_Char)0x20,  /* [239] */
    (xdc_Char)0x67,  /* [240] */
    (xdc_Char)0x72,  /* [241] */
    (xdc_Char)0x65,  /* [242] */
    (xdc_Char)0x61,  /* [243] */
    (xdc_Char)0x74,  /* [244] */
    (xdc_Char)0x65,  /* [245] */
    (xdc_Char)0x72,  /* [246] */
    (xdc_Char)0x20,  /* [247] */
    (xdc_Char)0x74,  /* [248] */
    (xdc_Char)0x68,  /* [249] */
    (xdc_Char)0x61,  /* [250] */
    (xdc_Char)0x6e,  /* [251] */
    (xdc_Char)0x20,  /* [252] */
    (xdc_Char)0x61,  /* [253] */
    (xdc_Char)0x6c,  /* [254] */
    (xdc_Char)0x6c,  /* [255] */
    (xdc_Char)0x6f,  /* [256] */
    (xdc_Char)0x77,  /* [257] */
    (xdc_Char)0x65,  /* [258] */
    (xdc_Char)0x64,  /* [259] */
    (xdc_Char)0x0,  /* [260] */
    (xdc_Char)0x41,  /* [261] */
    (xdc_Char)0x5f,  /* [262] */
    (xdc_Char)0x69,  /* [263] */
    (xdc_Char)0x6e,  /* [264] */
    (xdc_Char)0x76,  /* [265] */
    (xdc_Char)0x61,  /* [266] */
    (xdc_Char)0x6c,  /* [267] */
    (xdc_Char)0x69,  /* [268] */
    (xdc_Char)0x64,  /* [269] */
    (xdc_Char)0x4c,  /* [270] */
    (xdc_Char)0x6f,  /* [271] */
    (xdc_Char)0x67,  /* [272] */
    (xdc_Char)0x67,  /* [273] */
    (xdc_Char)0x65,  /* [274] */
    (xdc_Char)0x72,  /* [275] */
    (xdc_Char)0x3a,  /* [276] */
    (xdc_Char)0x20,  /* [277] */
    (xdc_Char)0x54,  /* [278] */
    (xdc_Char)0x68,  /* [279] */
    (xdc_Char)0x65,  /* [280] */
    (xdc_Char)0x20,  /* [281] */
    (xdc_Char)0x6c,  /* [282] */
    (xdc_Char)0x6f,  /* [283] */
    (xdc_Char)0x67,  /* [284] */
    (xdc_Char)0x67,  /* [285] */
    (xdc_Char)0x65,  /* [286] */
    (xdc_Char)0x72,  /* [287] */
    (xdc_Char)0x20,  /* [288] */
    (xdc_Char)0x69,  /* [289] */
    (xdc_Char)0x64,  /* [290] */
    (xdc_Char)0x20,  /* [291] */
    (xdc_Char)0x25,  /* [292] */
    (xdc_Char)0x64,  /* [293] */
    (xdc_Char)0x20,  /* [294] */
    (xdc_Char)0x69,  /* [295] */
    (xdc_Char)0x73,  /* [296] */
    (xdc_Char)0x20,  /* [297] */
    (xdc_Char)0x69,  /* [298] */
    (xdc_Char)0x6e,  /* [299] */
    (xdc_Char)0x76,  /* [300] */
    (xdc_Char)0x61,  /* [301] */
    (xdc_Char)0x6c,  /* [302] */
    (xdc_Char)0x69,  /* [303] */
    (xdc_Char)0x64,  /* [304] */
    (xdc_Char)0x2e,  /* [305] */
    (xdc_Char)0x0,  /* [306] */
    (xdc_Char)0x41,  /* [307] */
    (xdc_Char)0x5f,  /* [308] */
    (xdc_Char)0x63,  /* [309] */
    (xdc_Char)0x61,  /* [310] */
    (xdc_Char)0x6e,  /* [311] */
    (xdc_Char)0x6e,  /* [312] */
    (xdc_Char)0x6f,  /* [313] */
    (xdc_Char)0x74,  /* [314] */
    (xdc_Char)0x46,  /* [315] */
    (xdc_Char)0x69,  /* [316] */
    (xdc_Char)0x74,  /* [317] */
    (xdc_Char)0x49,  /* [318] */
    (xdc_Char)0x6e,  /* [319] */
    (xdc_Char)0x74,  /* [320] */
    (xdc_Char)0x6f,  /* [321] */
    (xdc_Char)0x41,  /* [322] */
    (xdc_Char)0x72,  /* [323] */
    (xdc_Char)0x67,  /* [324] */
    (xdc_Char)0x3a,  /* [325] */
    (xdc_Char)0x20,  /* [326] */
    (xdc_Char)0x73,  /* [327] */
    (xdc_Char)0x69,  /* [328] */
    (xdc_Char)0x7a,  /* [329] */
    (xdc_Char)0x65,  /* [330] */
    (xdc_Char)0x6f,  /* [331] */
    (xdc_Char)0x66,  /* [332] */
    (xdc_Char)0x28,  /* [333] */
    (xdc_Char)0x46,  /* [334] */
    (xdc_Char)0x6c,  /* [335] */
    (xdc_Char)0x6f,  /* [336] */
    (xdc_Char)0x61,  /* [337] */
    (xdc_Char)0x74,  /* [338] */
    (xdc_Char)0x29,  /* [339] */
    (xdc_Char)0x20,  /* [340] */
    (xdc_Char)0x3e,  /* [341] */
    (xdc_Char)0x20,  /* [342] */
    (xdc_Char)0x73,  /* [343] */
    (xdc_Char)0x69,  /* [344] */
    (xdc_Char)0x7a,  /* [345] */
    (xdc_Char)0x65,  /* [346] */
    (xdc_Char)0x6f,  /* [347] */
    (xdc_Char)0x66,  /* [348] */
    (xdc_Char)0x28,  /* [349] */
    (xdc_Char)0x41,  /* [350] */
    (xdc_Char)0x72,  /* [351] */
    (xdc_Char)0x67,  /* [352] */
    (xdc_Char)0x29,  /* [353] */
    (xdc_Char)0x0,  /* [354] */
    (xdc_Char)0x41,  /* [355] */
    (xdc_Char)0x5f,  /* [356] */
    (xdc_Char)0x63,  /* [357] */
    (xdc_Char)0x6c,  /* [358] */
    (xdc_Char)0x6f,  /* [359] */
    (xdc_Char)0x63,  /* [360] */
    (xdc_Char)0x6b,  /* [361] */
    (xdc_Char)0x44,  /* [362] */
    (xdc_Char)0x69,  /* [363] */
    (xdc_Char)0x73,  /* [364] */
    (xdc_Char)0x61,  /* [365] */
    (xdc_Char)0x62,  /* [366] */
    (xdc_Char)0x6c,  /* [367] */
    (xdc_Char)0x65,  /* [368] */
    (xdc_Char)0x64,  /* [369] */
    (xdc_Char)0x3a,  /* [370] */
    (xdc_Char)0x20,  /* [371] */
    (xdc_Char)0x43,  /* [372] */
    (xdc_Char)0x61,  /* [373] */
    (xdc_Char)0x6e,  /* [374] */
    (xdc_Char)0x6e,  /* [375] */
    (xdc_Char)0x6f,  /* [376] */
    (xdc_Char)0x74,  /* [377] */
    (xdc_Char)0x20,  /* [378] */
    (xdc_Char)0x63,  /* [379] */
    (xdc_Char)0x72,  /* [380] */
    (xdc_Char)0x65,  /* [381] */
    (xdc_Char)0x61,  /* [382] */
    (xdc_Char)0x74,  /* [383] */
    (xdc_Char)0x65,  /* [384] */
    (xdc_Char)0x20,  /* [385] */
    (xdc_Char)0x61,  /* [386] */
    (xdc_Char)0x20,  /* [387] */
    (xdc_Char)0x63,  /* [388] */
    (xdc_Char)0x6c,  /* [389] */
    (xdc_Char)0x6f,  /* [390] */
    (xdc_Char)0x63,  /* [391] */
    (xdc_Char)0x6b,  /* [392] */
    (xdc_Char)0x20,  /* [393] */
    (xdc_Char)0x69,  /* [394] */
    (xdc_Char)0x6e,  /* [395] */
    (xdc_Char)0x73,  /* [396] */
    (xdc_Char)0x74,  /* [397] */
    (xdc_Char)0x61,  /* [398] */
    (xdc_Char)0x6e,  /* [399] */
    (xdc_Char)0x63,  /* [400] */
    (xdc_Char)0x65,  /* [401] */
    (xdc_Char)0x20,  /* [402] */
    (xdc_Char)0x77,  /* [403] */
    (xdc_Char)0x68,  /* [404] */
    (xdc_Char)0x65,  /* [405] */
    (xdc_Char)0x6e,  /* [406] */
    (xdc_Char)0x20,  /* [407] */
    (xdc_Char)0x42,  /* [408] */
    (xdc_Char)0x49,  /* [409] */
    (xdc_Char)0x4f,  /* [410] */
    (xdc_Char)0x53,  /* [411] */
    (xdc_Char)0x2e,  /* [412] */
    (xdc_Char)0x63,  /* [413] */
    (xdc_Char)0x6c,  /* [414] */
    (xdc_Char)0x6f,  /* [415] */
    (xdc_Char)0x63,  /* [416] */
    (xdc_Char)0x6b,  /* [417] */
    (xdc_Char)0x45,  /* [418] */
    (xdc_Char)0x6e,  /* [419] */
    (xdc_Char)0x61,  /* [420] */
    (xdc_Char)0x62,  /* [421] */
    (xdc_Char)0x6c,  /* [422] */
    (xdc_Char)0x65,  /* [423] */
    (xdc_Char)0x64,  /* [424] */
    (xdc_Char)0x20,  /* [425] */
    (xdc_Char)0x69,  /* [426] */
    (xdc_Char)0x73,  /* [427] */
    (xdc_Char)0x20,  /* [428] */
    (xdc_Char)0x66,  /* [429] */
    (xdc_Char)0x61,  /* [430] */
    (xdc_Char)0x6c,  /* [431] */
    (xdc_Char)0x73,  /* [432] */
    (xdc_Char)0x65,  /* [433] */
    (xdc_Char)0x2e,  /* [434] */
    (xdc_Char)0x0,  /* [435] */
    (xdc_Char)0x41,  /* [436] */
    (xdc_Char)0x5f,  /* [437] */
    (xdc_Char)0x62,  /* [438] */
    (xdc_Char)0x61,  /* [439] */
    (xdc_Char)0x64,  /* [440] */
    (xdc_Char)0x54,  /* [441] */
    (xdc_Char)0x68,  /* [442] */
    (xdc_Char)0x72,  /* [443] */
    (xdc_Char)0x65,  /* [444] */
    (xdc_Char)0x61,  /* [445] */
    (xdc_Char)0x64,  /* [446] */
    (xdc_Char)0x54,  /* [447] */
    (xdc_Char)0x79,  /* [448] */
    (xdc_Char)0x70,  /* [449] */
    (xdc_Char)0x65,  /* [450] */
    (xdc_Char)0x3a,  /* [451] */
    (xdc_Char)0x20,  /* [452] */
    (xdc_Char)0x43,  /* [453] */
    (xdc_Char)0x61,  /* [454] */
    (xdc_Char)0x6e,  /* [455] */
    (xdc_Char)0x6e,  /* [456] */
    (xdc_Char)0x6f,  /* [457] */
    (xdc_Char)0x74,  /* [458] */
    (xdc_Char)0x20,  /* [459] */
    (xdc_Char)0x63,  /* [460] */
    (xdc_Char)0x72,  /* [461] */
    (xdc_Char)0x65,  /* [462] */
    (xdc_Char)0x61,  /* [463] */
    (xdc_Char)0x74,  /* [464] */
    (xdc_Char)0x65,  /* [465] */
    (xdc_Char)0x2f,  /* [466] */
    (xdc_Char)0x64,  /* [467] */
    (xdc_Char)0x65,  /* [468] */
    (xdc_Char)0x6c,  /* [469] */
    (xdc_Char)0x65,  /* [470] */
    (xdc_Char)0x74,  /* [471] */
    (xdc_Char)0x65,  /* [472] */
    (xdc_Char)0x20,  /* [473] */
    (xdc_Char)0x61,  /* [474] */
    (xdc_Char)0x20,  /* [475] */
    (xdc_Char)0x43,  /* [476] */
    (xdc_Char)0x6c,  /* [477] */
    (xdc_Char)0x6f,  /* [478] */
    (xdc_Char)0x63,  /* [479] */
    (xdc_Char)0x6b,  /* [480] */
    (xdc_Char)0x20,  /* [481] */
    (xdc_Char)0x66,  /* [482] */
    (xdc_Char)0x72,  /* [483] */
    (xdc_Char)0x6f,  /* [484] */
    (xdc_Char)0x6d,  /* [485] */
    (xdc_Char)0x20,  /* [486] */
    (xdc_Char)0x48,  /* [487] */
    (xdc_Char)0x77,  /* [488] */
    (xdc_Char)0x69,  /* [489] */
    (xdc_Char)0x20,  /* [490] */
    (xdc_Char)0x6f,  /* [491] */
    (xdc_Char)0x72,  /* [492] */
    (xdc_Char)0x20,  /* [493] */
    (xdc_Char)0x53,  /* [494] */
    (xdc_Char)0x77,  /* [495] */
    (xdc_Char)0x69,  /* [496] */
    (xdc_Char)0x20,  /* [497] */
    (xdc_Char)0x74,  /* [498] */
    (xdc_Char)0x68,  /* [499] */
    (xdc_Char)0x72,  /* [500] */
    (xdc_Char)0x65,  /* [501] */
    (xdc_Char)0x61,  /* [502] */
    (xdc_Char)0x64,  /* [503] */
    (xdc_Char)0x2e,  /* [504] */
    (xdc_Char)0x0,  /* [505] */
    (xdc_Char)0x41,  /* [506] */
    (xdc_Char)0x5f,  /* [507] */
    (xdc_Char)0x6e,  /* [508] */
    (xdc_Char)0x75,  /* [509] */
    (xdc_Char)0x6c,  /* [510] */
    (xdc_Char)0x6c,  /* [511] */
    (xdc_Char)0x45,  /* [512] */
    (xdc_Char)0x76,  /* [513] */
    (xdc_Char)0x65,  /* [514] */
    (xdc_Char)0x6e,  /* [515] */
    (xdc_Char)0x74,  /* [516] */
    (xdc_Char)0x4d,  /* [517] */
    (xdc_Char)0x61,  /* [518] */
    (xdc_Char)0x73,  /* [519] */
    (xdc_Char)0x6b,  /* [520] */
    (xdc_Char)0x73,  /* [521] */
    (xdc_Char)0x3a,  /* [522] */
    (xdc_Char)0x20,  /* [523] */
    (xdc_Char)0x6f,  /* [524] */
    (xdc_Char)0x72,  /* [525] */
    (xdc_Char)0x4d,  /* [526] */
    (xdc_Char)0x61,  /* [527] */
    (xdc_Char)0x73,  /* [528] */
    (xdc_Char)0x6b,  /* [529] */
    (xdc_Char)0x20,  /* [530] */
    (xdc_Char)0x61,  /* [531] */
    (xdc_Char)0x6e,  /* [532] */
    (xdc_Char)0x64,  /* [533] */
    (xdc_Char)0x20,  /* [534] */
    (xdc_Char)0x61,  /* [535] */
    (xdc_Char)0x6e,  /* [536] */
    (xdc_Char)0x64,  /* [537] */
    (xdc_Char)0x4d,  /* [538] */
    (xdc_Char)0x61,  /* [539] */
    (xdc_Char)0x73,  /* [540] */
    (xdc_Char)0x6b,  /* [541] */
    (xdc_Char)0x20,  /* [542] */
    (xdc_Char)0x61,  /* [543] */
    (xdc_Char)0x72,  /* [544] */
    (xdc_Char)0x65,  /* [545] */
    (xdc_Char)0x20,  /* [546] */
    (xdc_Char)0x6e,  /* [547] */
    (xdc_Char)0x75,  /* [548] */
    (xdc_Char)0x6c,  /* [549] */
    (xdc_Char)0x6c,  /* [550] */
    (xdc_Char)0x2e,  /* [551] */
    (xdc_Char)0x0,  /* [552] */
    (xdc_Char)0x41,  /* [553] */
    (xdc_Char)0x5f,  /* [554] */
    (xdc_Char)0x6e,  /* [555] */
    (xdc_Char)0x75,  /* [556] */
    (xdc_Char)0x6c,  /* [557] */
    (xdc_Char)0x6c,  /* [558] */
    (xdc_Char)0x45,  /* [559] */
    (xdc_Char)0x76,  /* [560] */
    (xdc_Char)0x65,  /* [561] */
    (xdc_Char)0x6e,  /* [562] */
    (xdc_Char)0x74,  /* [563] */
    (xdc_Char)0x49,  /* [564] */
    (xdc_Char)0x64,  /* [565] */
    (xdc_Char)0x3a,  /* [566] */
    (xdc_Char)0x20,  /* [567] */
    (xdc_Char)0x70,  /* [568] */
    (xdc_Char)0x6f,  /* [569] */
    (xdc_Char)0x73,  /* [570] */
    (xdc_Char)0x74,  /* [571] */
    (xdc_Char)0x65,  /* [572] */
    (xdc_Char)0x64,  /* [573] */
    (xdc_Char)0x20,  /* [574] */
    (xdc_Char)0x65,  /* [575] */
    (xdc_Char)0x76,  /* [576] */
    (xdc_Char)0x65,  /* [577] */
    (xdc_Char)0x6e,  /* [578] */
    (xdc_Char)0x74,  /* [579] */
    (xdc_Char)0x49,  /* [580] */
    (xdc_Char)0x64,  /* [581] */
    (xdc_Char)0x20,  /* [582] */
    (xdc_Char)0x69,  /* [583] */
    (xdc_Char)0x73,  /* [584] */
    (xdc_Char)0x20,  /* [585] */
    (xdc_Char)0x6e,  /* [586] */
    (xdc_Char)0x75,  /* [587] */
    (xdc_Char)0x6c,  /* [588] */
    (xdc_Char)0x6c,  /* [589] */
    (xdc_Char)0x2e,  /* [590] */
    (xdc_Char)0x0,  /* [591] */
    (xdc_Char)0x41,  /* [592] */
    (xdc_Char)0x5f,  /* [593] */
    (xdc_Char)0x65,  /* [594] */
    (xdc_Char)0x76,  /* [595] */
    (xdc_Char)0x65,  /* [596] */
    (xdc_Char)0x6e,  /* [597] */
    (xdc_Char)0x74,  /* [598] */
    (xdc_Char)0x49,  /* [599] */
    (xdc_Char)0x6e,  /* [600] */
    (xdc_Char)0x55,  /* [601] */
    (xdc_Char)0x73,  /* [602] */
    (xdc_Char)0x65,  /* [603] */
    (xdc_Char)0x3a,  /* [604] */
    (xdc_Char)0x20,  /* [605] */
    (xdc_Char)0x45,  /* [606] */
    (xdc_Char)0x76,  /* [607] */
    (xdc_Char)0x65,  /* [608] */
    (xdc_Char)0x6e,  /* [609] */
    (xdc_Char)0x74,  /* [610] */
    (xdc_Char)0x20,  /* [611] */
    (xdc_Char)0x6f,  /* [612] */
    (xdc_Char)0x62,  /* [613] */
    (xdc_Char)0x6a,  /* [614] */
    (xdc_Char)0x65,  /* [615] */
    (xdc_Char)0x63,  /* [616] */
    (xdc_Char)0x74,  /* [617] */
    (xdc_Char)0x20,  /* [618] */
    (xdc_Char)0x61,  /* [619] */
    (xdc_Char)0x6c,  /* [620] */
    (xdc_Char)0x72,  /* [621] */
    (xdc_Char)0x65,  /* [622] */
    (xdc_Char)0x61,  /* [623] */
    (xdc_Char)0x64,  /* [624] */
    (xdc_Char)0x79,  /* [625] */
    (xdc_Char)0x20,  /* [626] */
    (xdc_Char)0x69,  /* [627] */
    (xdc_Char)0x6e,  /* [628] */
    (xdc_Char)0x20,  /* [629] */
    (xdc_Char)0x75,  /* [630] */
    (xdc_Char)0x73,  /* [631] */
    (xdc_Char)0x65,  /* [632] */
    (xdc_Char)0x2e,  /* [633] */
    (xdc_Char)0x0,  /* [634] */
    (xdc_Char)0x41,  /* [635] */
    (xdc_Char)0x5f,  /* [636] */
    (xdc_Char)0x62,  /* [637] */
    (xdc_Char)0x61,  /* [638] */
    (xdc_Char)0x64,  /* [639] */
    (xdc_Char)0x43,  /* [640] */
    (xdc_Char)0x6f,  /* [641] */
    (xdc_Char)0x6e,  /* [642] */
    (xdc_Char)0x74,  /* [643] */
    (xdc_Char)0x65,  /* [644] */
    (xdc_Char)0x78,  /* [645] */
    (xdc_Char)0x74,  /* [646] */
    (xdc_Char)0x3a,  /* [647] */
    (xdc_Char)0x20,  /* [648] */
    (xdc_Char)0x62,  /* [649] */
    (xdc_Char)0x61,  /* [650] */
    (xdc_Char)0x64,  /* [651] */
    (xdc_Char)0x20,  /* [652] */
    (xdc_Char)0x63,  /* [653] */
    (xdc_Char)0x61,  /* [654] */
    (xdc_Char)0x6c,  /* [655] */
    (xdc_Char)0x6c,  /* [656] */
    (xdc_Char)0x69,  /* [657] */
    (xdc_Char)0x6e,  /* [658] */
    (xdc_Char)0x67,  /* [659] */
    (xdc_Char)0x20,  /* [660] */
    (xdc_Char)0x63,  /* [661] */
    (xdc_Char)0x6f,  /* [662] */
    (xdc_Char)0x6e,  /* [663] */
    (xdc_Char)0x74,  /* [664] */
    (xdc_Char)0x65,  /* [665] */
    (xdc_Char)0x78,  /* [666] */
    (xdc_Char)0x74,  /* [667] */
    (xdc_Char)0x2e,  /* [668] */
    (xdc_Char)0x20,  /* [669] */
    (xdc_Char)0x4d,  /* [670] */
    (xdc_Char)0x75,  /* [671] */
    (xdc_Char)0x73,  /* [672] */
    (xdc_Char)0x74,  /* [673] */
    (xdc_Char)0x20,  /* [674] */
    (xdc_Char)0x62,  /* [675] */
    (xdc_Char)0x65,  /* [676] */
    (xdc_Char)0x20,  /* [677] */
    (xdc_Char)0x63,  /* [678] */
    (xdc_Char)0x61,  /* [679] */
    (xdc_Char)0x6c,  /* [680] */
    (xdc_Char)0x6c,  /* [681] */
    (xdc_Char)0x65,  /* [682] */
    (xdc_Char)0x64,  /* [683] */
    (xdc_Char)0x20,  /* [684] */
    (xdc_Char)0x66,  /* [685] */
    (xdc_Char)0x72,  /* [686] */
    (xdc_Char)0x6f,  /* [687] */
    (xdc_Char)0x6d,  /* [688] */
    (xdc_Char)0x20,  /* [689] */
    (xdc_Char)0x61,  /* [690] */
    (xdc_Char)0x20,  /* [691] */
    (xdc_Char)0x54,  /* [692] */
    (xdc_Char)0x61,  /* [693] */
    (xdc_Char)0x73,  /* [694] */
    (xdc_Char)0x6b,  /* [695] */
    (xdc_Char)0x2e,  /* [696] */
    (xdc_Char)0x0,  /* [697] */
    (xdc_Char)0x4d,  /* [698] */
    (xdc_Char)0x61,  /* [699] */
    (xdc_Char)0x69,  /* [700] */
    (xdc_Char)0x6c,  /* [701] */
    (xdc_Char)0x62,  /* [702] */
    (xdc_Char)0x6f,  /* [703] */
    (xdc_Char)0x78,  /* [704] */
    (xdc_Char)0x5f,  /* [705] */
    (xdc_Char)0x63,  /* [706] */
    (xdc_Char)0x72,  /* [707] */
    (xdc_Char)0x65,  /* [708] */
    (xdc_Char)0x61,  /* [709] */
    (xdc_Char)0x74,  /* [710] */
    (xdc_Char)0x65,  /* [711] */
    (xdc_Char)0x27,  /* [712] */
    (xdc_Char)0x73,  /* [713] */
    (xdc_Char)0x20,  /* [714] */
    (xdc_Char)0x62,  /* [715] */
    (xdc_Char)0x75,  /* [716] */
    (xdc_Char)0x66,  /* [717] */
    (xdc_Char)0x53,  /* [718] */
    (xdc_Char)0x69,  /* [719] */
    (xdc_Char)0x7a,  /* [720] */
    (xdc_Char)0x65,  /* [721] */
    (xdc_Char)0x20,  /* [722] */
    (xdc_Char)0x70,  /* [723] */
    (xdc_Char)0x61,  /* [724] */
    (xdc_Char)0x72,  /* [725] */
    (xdc_Char)0x61,  /* [726] */
    (xdc_Char)0x6d,  /* [727] */
    (xdc_Char)0x65,  /* [728] */
    (xdc_Char)0x74,  /* [729] */
    (xdc_Char)0x65,  /* [730] */
    (xdc_Char)0x72,  /* [731] */
    (xdc_Char)0x20,  /* [732] */
    (xdc_Char)0x69,  /* [733] */
    (xdc_Char)0x73,  /* [734] */
    (xdc_Char)0x20,  /* [735] */
    (xdc_Char)0x69,  /* [736] */
    (xdc_Char)0x6e,  /* [737] */
    (xdc_Char)0x76,  /* [738] */
    (xdc_Char)0x61,  /* [739] */
    (xdc_Char)0x6c,  /* [740] */
    (xdc_Char)0x69,  /* [741] */
    (xdc_Char)0x64,  /* [742] */
    (xdc_Char)0x20,  /* [743] */
    (xdc_Char)0x28,  /* [744] */
    (xdc_Char)0x74,  /* [745] */
    (xdc_Char)0x6f,  /* [746] */
    (xdc_Char)0x6f,  /* [747] */
    (xdc_Char)0x20,  /* [748] */
    (xdc_Char)0x73,  /* [749] */
    (xdc_Char)0x6d,  /* [750] */
    (xdc_Char)0x61,  /* [751] */
    (xdc_Char)0x6c,  /* [752] */
    (xdc_Char)0x6c,  /* [753] */
    (xdc_Char)0x29,  /* [754] */
    (xdc_Char)0x0,  /* [755] */
    (xdc_Char)0x41,  /* [756] */
    (xdc_Char)0x5f,  /* [757] */
    (xdc_Char)0x6e,  /* [758] */
    (xdc_Char)0x6f,  /* [759] */
    (xdc_Char)0x45,  /* [760] */
    (xdc_Char)0x76,  /* [761] */
    (xdc_Char)0x65,  /* [762] */
    (xdc_Char)0x6e,  /* [763] */
    (xdc_Char)0x74,  /* [764] */
    (xdc_Char)0x73,  /* [765] */
    (xdc_Char)0x3a,  /* [766] */
    (xdc_Char)0x20,  /* [767] */
    (xdc_Char)0x54,  /* [768] */
    (xdc_Char)0x68,  /* [769] */
    (xdc_Char)0x65,  /* [770] */
    (xdc_Char)0x20,  /* [771] */
    (xdc_Char)0x45,  /* [772] */
    (xdc_Char)0x76,  /* [773] */
    (xdc_Char)0x65,  /* [774] */
    (xdc_Char)0x6e,  /* [775] */
    (xdc_Char)0x74,  /* [776] */
    (xdc_Char)0x2e,  /* [777] */
    (xdc_Char)0x73,  /* [778] */
    (xdc_Char)0x75,  /* [779] */
    (xdc_Char)0x70,  /* [780] */
    (xdc_Char)0x70,  /* [781] */
    (xdc_Char)0x6f,  /* [782] */
    (xdc_Char)0x72,  /* [783] */
    (xdc_Char)0x74,  /* [784] */
    (xdc_Char)0x73,  /* [785] */
    (xdc_Char)0x45,  /* [786] */
    (xdc_Char)0x76,  /* [787] */
    (xdc_Char)0x65,  /* [788] */
    (xdc_Char)0x6e,  /* [789] */
    (xdc_Char)0x74,  /* [790] */
    (xdc_Char)0x73,  /* [791] */
    (xdc_Char)0x20,  /* [792] */
    (xdc_Char)0x66,  /* [793] */
    (xdc_Char)0x6c,  /* [794] */
    (xdc_Char)0x61,  /* [795] */
    (xdc_Char)0x67,  /* [796] */
    (xdc_Char)0x20,  /* [797] */
    (xdc_Char)0x69,  /* [798] */
    (xdc_Char)0x73,  /* [799] */
    (xdc_Char)0x20,  /* [800] */
    (xdc_Char)0x64,  /* [801] */
    (xdc_Char)0x69,  /* [802] */
    (xdc_Char)0x73,  /* [803] */
    (xdc_Char)0x61,  /* [804] */
    (xdc_Char)0x62,  /* [805] */
    (xdc_Char)0x6c,  /* [806] */
    (xdc_Char)0x65,  /* [807] */
    (xdc_Char)0x64,  /* [808] */
    (xdc_Char)0x2e,  /* [809] */
    (xdc_Char)0x0,  /* [810] */
    (xdc_Char)0x41,  /* [811] */
    (xdc_Char)0x5f,  /* [812] */
    (xdc_Char)0x69,  /* [813] */
    (xdc_Char)0x6e,  /* [814] */
    (xdc_Char)0x76,  /* [815] */
    (xdc_Char)0x54,  /* [816] */
    (xdc_Char)0x69,  /* [817] */
    (xdc_Char)0x6d,  /* [818] */
    (xdc_Char)0x65,  /* [819] */
    (xdc_Char)0x6f,  /* [820] */
    (xdc_Char)0x75,  /* [821] */
    (xdc_Char)0x74,  /* [822] */
    (xdc_Char)0x3a,  /* [823] */
    (xdc_Char)0x20,  /* [824] */
    (xdc_Char)0x43,  /* [825] */
    (xdc_Char)0x61,  /* [826] */
    (xdc_Char)0x6e,  /* [827] */
    (xdc_Char)0x27,  /* [828] */
    (xdc_Char)0x74,  /* [829] */
    (xdc_Char)0x20,  /* [830] */
    (xdc_Char)0x75,  /* [831] */
    (xdc_Char)0x73,  /* [832] */
    (xdc_Char)0x65,  /* [833] */
    (xdc_Char)0x20,  /* [834] */
    (xdc_Char)0x42,  /* [835] */
    (xdc_Char)0x49,  /* [836] */
    (xdc_Char)0x4f,  /* [837] */
    (xdc_Char)0x53,  /* [838] */
    (xdc_Char)0x5f,  /* [839] */
    (xdc_Char)0x45,  /* [840] */
    (xdc_Char)0x56,  /* [841] */
    (xdc_Char)0x45,  /* [842] */
    (xdc_Char)0x4e,  /* [843] */
    (xdc_Char)0x54,  /* [844] */
    (xdc_Char)0x5f,  /* [845] */
    (xdc_Char)0x41,  /* [846] */
    (xdc_Char)0x43,  /* [847] */
    (xdc_Char)0x51,  /* [848] */
    (xdc_Char)0x55,  /* [849] */
    (xdc_Char)0x49,  /* [850] */
    (xdc_Char)0x52,  /* [851] */
    (xdc_Char)0x45,  /* [852] */
    (xdc_Char)0x44,  /* [853] */
    (xdc_Char)0x20,  /* [854] */
    (xdc_Char)0x77,  /* [855] */
    (xdc_Char)0x69,  /* [856] */
    (xdc_Char)0x74,  /* [857] */
    (xdc_Char)0x68,  /* [858] */
    (xdc_Char)0x20,  /* [859] */
    (xdc_Char)0x74,  /* [860] */
    (xdc_Char)0x68,  /* [861] */
    (xdc_Char)0x69,  /* [862] */
    (xdc_Char)0x73,  /* [863] */
    (xdc_Char)0x20,  /* [864] */
    (xdc_Char)0x53,  /* [865] */
    (xdc_Char)0x65,  /* [866] */
    (xdc_Char)0x6d,  /* [867] */
    (xdc_Char)0x61,  /* [868] */
    (xdc_Char)0x70,  /* [869] */
    (xdc_Char)0x68,  /* [870] */
    (xdc_Char)0x6f,  /* [871] */
    (xdc_Char)0x72,  /* [872] */
    (xdc_Char)0x65,  /* [873] */
    (xdc_Char)0x2e,  /* [874] */
    (xdc_Char)0x0,  /* [875] */
    (xdc_Char)0x41,  /* [876] */
    (xdc_Char)0x5f,  /* [877] */
    (xdc_Char)0x73,  /* [878] */
    (xdc_Char)0x77,  /* [879] */
    (xdc_Char)0x69,  /* [880] */
    (xdc_Char)0x44,  /* [881] */
    (xdc_Char)0x69,  /* [882] */
    (xdc_Char)0x73,  /* [883] */
    (xdc_Char)0x61,  /* [884] */
    (xdc_Char)0x62,  /* [885] */
    (xdc_Char)0x6c,  /* [886] */
    (xdc_Char)0x65,  /* [887] */
    (xdc_Char)0x64,  /* [888] */
    (xdc_Char)0x3a,  /* [889] */
    (xdc_Char)0x20,  /* [890] */
    (xdc_Char)0x43,  /* [891] */
    (xdc_Char)0x61,  /* [892] */
    (xdc_Char)0x6e,  /* [893] */
    (xdc_Char)0x6e,  /* [894] */
    (xdc_Char)0x6f,  /* [895] */
    (xdc_Char)0x74,  /* [896] */
    (xdc_Char)0x20,  /* [897] */
    (xdc_Char)0x63,  /* [898] */
    (xdc_Char)0x72,  /* [899] */
    (xdc_Char)0x65,  /* [900] */
    (xdc_Char)0x61,  /* [901] */
    (xdc_Char)0x74,  /* [902] */
    (xdc_Char)0x65,  /* [903] */
    (xdc_Char)0x20,  /* [904] */
    (xdc_Char)0x61,  /* [905] */
    (xdc_Char)0x20,  /* [906] */
    (xdc_Char)0x53,  /* [907] */
    (xdc_Char)0x77,  /* [908] */
    (xdc_Char)0x69,  /* [909] */
    (xdc_Char)0x20,  /* [910] */
    (xdc_Char)0x77,  /* [911] */
    (xdc_Char)0x68,  /* [912] */
    (xdc_Char)0x65,  /* [913] */
    (xdc_Char)0x6e,  /* [914] */
    (xdc_Char)0x20,  /* [915] */
    (xdc_Char)0x53,  /* [916] */
    (xdc_Char)0x77,  /* [917] */
    (xdc_Char)0x69,  /* [918] */
    (xdc_Char)0x20,  /* [919] */
    (xdc_Char)0x69,  /* [920] */
    (xdc_Char)0x73,  /* [921] */
    (xdc_Char)0x20,  /* [922] */
    (xdc_Char)0x64,  /* [923] */
    (xdc_Char)0x69,  /* [924] */
    (xdc_Char)0x73,  /* [925] */
    (xdc_Char)0x61,  /* [926] */
    (xdc_Char)0x62,  /* [927] */
    (xdc_Char)0x6c,  /* [928] */
    (xdc_Char)0x65,  /* [929] */
    (xdc_Char)0x64,  /* [930] */
    (xdc_Char)0x2e,  /* [931] */
    (xdc_Char)0x0,  /* [932] */
    (xdc_Char)0x41,  /* [933] */
    (xdc_Char)0x5f,  /* [934] */
    (xdc_Char)0x62,  /* [935] */
    (xdc_Char)0x61,  /* [936] */
    (xdc_Char)0x64,  /* [937] */
    (xdc_Char)0x50,  /* [938] */
    (xdc_Char)0x72,  /* [939] */
    (xdc_Char)0x69,  /* [940] */
    (xdc_Char)0x6f,  /* [941] */
    (xdc_Char)0x72,  /* [942] */
    (xdc_Char)0x69,  /* [943] */
    (xdc_Char)0x74,  /* [944] */
    (xdc_Char)0x79,  /* [945] */
    (xdc_Char)0x3a,  /* [946] */
    (xdc_Char)0x20,  /* [947] */
    (xdc_Char)0x41,  /* [948] */
    (xdc_Char)0x6e,  /* [949] */
    (xdc_Char)0x20,  /* [950] */
    (xdc_Char)0x69,  /* [951] */
    (xdc_Char)0x6e,  /* [952] */
    (xdc_Char)0x76,  /* [953] */
    (xdc_Char)0x61,  /* [954] */
    (xdc_Char)0x6c,  /* [955] */
    (xdc_Char)0x69,  /* [956] */
    (xdc_Char)0x64,  /* [957] */
    (xdc_Char)0x20,  /* [958] */
    (xdc_Char)0x53,  /* [959] */
    (xdc_Char)0x77,  /* [960] */
    (xdc_Char)0x69,  /* [961] */
    (xdc_Char)0x20,  /* [962] */
    (xdc_Char)0x70,  /* [963] */
    (xdc_Char)0x72,  /* [964] */
    (xdc_Char)0x69,  /* [965] */
    (xdc_Char)0x6f,  /* [966] */
    (xdc_Char)0x72,  /* [967] */
    (xdc_Char)0x69,  /* [968] */
    (xdc_Char)0x74,  /* [969] */
    (xdc_Char)0x79,  /* [970] */
    (xdc_Char)0x20,  /* [971] */
    (xdc_Char)0x77,  /* [972] */
    (xdc_Char)0x61,  /* [973] */
    (xdc_Char)0x73,  /* [974] */
    (xdc_Char)0x20,  /* [975] */
    (xdc_Char)0x75,  /* [976] */
    (xdc_Char)0x73,  /* [977] */
    (xdc_Char)0x65,  /* [978] */
    (xdc_Char)0x64,  /* [979] */
    (xdc_Char)0x2e,  /* [980] */
    (xdc_Char)0x0,  /* [981] */
    (xdc_Char)0x41,  /* [982] */
    (xdc_Char)0x5f,  /* [983] */
    (xdc_Char)0x62,  /* [984] */
    (xdc_Char)0x61,  /* [985] */
    (xdc_Char)0x64,  /* [986] */
    (xdc_Char)0x54,  /* [987] */
    (xdc_Char)0x68,  /* [988] */
    (xdc_Char)0x72,  /* [989] */
    (xdc_Char)0x65,  /* [990] */
    (xdc_Char)0x61,  /* [991] */
    (xdc_Char)0x64,  /* [992] */
    (xdc_Char)0x54,  /* [993] */
    (xdc_Char)0x79,  /* [994] */
    (xdc_Char)0x70,  /* [995] */
    (xdc_Char)0x65,  /* [996] */
    (xdc_Char)0x3a,  /* [997] */
    (xdc_Char)0x20,  /* [998] */
    (xdc_Char)0x43,  /* [999] */
    (xdc_Char)0x61,  /* [1000] */
    (xdc_Char)0x6e,  /* [1001] */
    (xdc_Char)0x6e,  /* [1002] */
    (xdc_Char)0x6f,  /* [1003] */
    (xdc_Char)0x74,  /* [1004] */
    (xdc_Char)0x20,  /* [1005] */
    (xdc_Char)0x63,  /* [1006] */
    (xdc_Char)0x72,  /* [1007] */
    (xdc_Char)0x65,  /* [1008] */
    (xdc_Char)0x61,  /* [1009] */
    (xdc_Char)0x74,  /* [1010] */
    (xdc_Char)0x65,  /* [1011] */
    (xdc_Char)0x2f,  /* [1012] */
    (xdc_Char)0x64,  /* [1013] */
    (xdc_Char)0x65,  /* [1014] */
    (xdc_Char)0x6c,  /* [1015] */
    (xdc_Char)0x65,  /* [1016] */
    (xdc_Char)0x74,  /* [1017] */
    (xdc_Char)0x65,  /* [1018] */
    (xdc_Char)0x20,  /* [1019] */
    (xdc_Char)0x61,  /* [1020] */
    (xdc_Char)0x20,  /* [1021] */
    (xdc_Char)0x74,  /* [1022] */
    (xdc_Char)0x61,  /* [1023] */
    (xdc_Char)0x73,  /* [1024] */
    (xdc_Char)0x6b,  /* [1025] */
    (xdc_Char)0x20,  /* [1026] */
    (xdc_Char)0x66,  /* [1027] */
    (xdc_Char)0x72,  /* [1028] */
    (xdc_Char)0x6f,  /* [1029] */
    (xdc_Char)0x6d,  /* [1030] */
    (xdc_Char)0x20,  /* [1031] */
    (xdc_Char)0x48,  /* [1032] */
    (xdc_Char)0x77,  /* [1033] */
    (xdc_Char)0x69,  /* [1034] */
    (xdc_Char)0x20,  /* [1035] */
    (xdc_Char)0x6f,  /* [1036] */
    (xdc_Char)0x72,  /* [1037] */
    (xdc_Char)0x20,  /* [1038] */
    (xdc_Char)0x53,  /* [1039] */
    (xdc_Char)0x77,  /* [1040] */
    (xdc_Char)0x69,  /* [1041] */
    (xdc_Char)0x20,  /* [1042] */
    (xdc_Char)0x74,  /* [1043] */
    (xdc_Char)0x68,  /* [1044] */
    (xdc_Char)0x72,  /* [1045] */
    (xdc_Char)0x65,  /* [1046] */
    (xdc_Char)0x61,  /* [1047] */
    (xdc_Char)0x64,  /* [1048] */
    (xdc_Char)0x2e,  /* [1049] */
    (xdc_Char)0x0,  /* [1050] */
    (xdc_Char)0x41,  /* [1051] */
    (xdc_Char)0x5f,  /* [1052] */
    (xdc_Char)0x62,  /* [1053] */
    (xdc_Char)0x61,  /* [1054] */
    (xdc_Char)0x64,  /* [1055] */
    (xdc_Char)0x54,  /* [1056] */
    (xdc_Char)0x61,  /* [1057] */
    (xdc_Char)0x73,  /* [1058] */
    (xdc_Char)0x6b,  /* [1059] */
    (xdc_Char)0x53,  /* [1060] */
    (xdc_Char)0x74,  /* [1061] */
    (xdc_Char)0x61,  /* [1062] */
    (xdc_Char)0x74,  /* [1063] */
    (xdc_Char)0x65,  /* [1064] */
    (xdc_Char)0x3a,  /* [1065] */
    (xdc_Char)0x20,  /* [1066] */
    (xdc_Char)0x43,  /* [1067] */
    (xdc_Char)0x61,  /* [1068] */
    (xdc_Char)0x6e,  /* [1069] */
    (xdc_Char)0x27,  /* [1070] */
    (xdc_Char)0x74,  /* [1071] */
    (xdc_Char)0x20,  /* [1072] */
    (xdc_Char)0x64,  /* [1073] */
    (xdc_Char)0x65,  /* [1074] */
    (xdc_Char)0x6c,  /* [1075] */
    (xdc_Char)0x65,  /* [1076] */
    (xdc_Char)0x74,  /* [1077] */
    (xdc_Char)0x65,  /* [1078] */
    (xdc_Char)0x20,  /* [1079] */
    (xdc_Char)0x61,  /* [1080] */
    (xdc_Char)0x20,  /* [1081] */
    (xdc_Char)0x74,  /* [1082] */
    (xdc_Char)0x61,  /* [1083] */
    (xdc_Char)0x73,  /* [1084] */
    (xdc_Char)0x6b,  /* [1085] */
    (xdc_Char)0x20,  /* [1086] */
    (xdc_Char)0x69,  /* [1087] */
    (xdc_Char)0x6e,  /* [1088] */
    (xdc_Char)0x20,  /* [1089] */
    (xdc_Char)0x52,  /* [1090] */
    (xdc_Char)0x55,  /* [1091] */
    (xdc_Char)0x4e,  /* [1092] */
    (xdc_Char)0x4e,  /* [1093] */
    (xdc_Char)0x49,  /* [1094] */
    (xdc_Char)0x4e,  /* [1095] */
    (xdc_Char)0x47,  /* [1096] */
    (xdc_Char)0x20,  /* [1097] */
    (xdc_Char)0x73,  /* [1098] */
    (xdc_Char)0x74,  /* [1099] */
    (xdc_Char)0x61,  /* [1100] */
    (xdc_Char)0x74,  /* [1101] */
    (xdc_Char)0x65,  /* [1102] */
    (xdc_Char)0x2e,  /* [1103] */
    (xdc_Char)0x0,  /* [1104] */
    (xdc_Char)0x41,  /* [1105] */
    (xdc_Char)0x5f,  /* [1106] */
    (xdc_Char)0x6e,  /* [1107] */
    (xdc_Char)0x6f,  /* [1108] */
    (xdc_Char)0x50,  /* [1109] */
    (xdc_Char)0x65,  /* [1110] */
    (xdc_Char)0x6e,  /* [1111] */
    (xdc_Char)0x64,  /* [1112] */
    (xdc_Char)0x45,  /* [1113] */
    (xdc_Char)0x6c,  /* [1114] */
    (xdc_Char)0x65,  /* [1115] */
    (xdc_Char)0x6d,  /* [1116] */
    (xdc_Char)0x3a,  /* [1117] */
    (xdc_Char)0x20,  /* [1118] */
    (xdc_Char)0x4e,  /* [1119] */
    (xdc_Char)0x6f,  /* [1120] */
    (xdc_Char)0x74,  /* [1121] */
    (xdc_Char)0x20,  /* [1122] */
    (xdc_Char)0x65,  /* [1123] */
    (xdc_Char)0x6e,  /* [1124] */
    (xdc_Char)0x6f,  /* [1125] */
    (xdc_Char)0x75,  /* [1126] */
    (xdc_Char)0x67,  /* [1127] */
    (xdc_Char)0x68,  /* [1128] */
    (xdc_Char)0x20,  /* [1129] */
    (xdc_Char)0x69,  /* [1130] */
    (xdc_Char)0x6e,  /* [1131] */
    (xdc_Char)0x66,  /* [1132] */
    (xdc_Char)0x6f,  /* [1133] */
    (xdc_Char)0x20,  /* [1134] */
    (xdc_Char)0x74,  /* [1135] */
    (xdc_Char)0x6f,  /* [1136] */
    (xdc_Char)0x20,  /* [1137] */
    (xdc_Char)0x64,  /* [1138] */
    (xdc_Char)0x65,  /* [1139] */
    (xdc_Char)0x6c,  /* [1140] */
    (xdc_Char)0x65,  /* [1141] */
    (xdc_Char)0x74,  /* [1142] */
    (xdc_Char)0x65,  /* [1143] */
    (xdc_Char)0x20,  /* [1144] */
    (xdc_Char)0x42,  /* [1145] */
    (xdc_Char)0x4c,  /* [1146] */
    (xdc_Char)0x4f,  /* [1147] */
    (xdc_Char)0x43,  /* [1148] */
    (xdc_Char)0x4b,  /* [1149] */
    (xdc_Char)0x45,  /* [1150] */
    (xdc_Char)0x44,  /* [1151] */
    (xdc_Char)0x20,  /* [1152] */
    (xdc_Char)0x74,  /* [1153] */
    (xdc_Char)0x61,  /* [1154] */
    (xdc_Char)0x73,  /* [1155] */
    (xdc_Char)0x6b,  /* [1156] */
    (xdc_Char)0x2e,  /* [1157] */
    (xdc_Char)0x0,  /* [1158] */
    (xdc_Char)0x41,  /* [1159] */
    (xdc_Char)0x5f,  /* [1160] */
    (xdc_Char)0x74,  /* [1161] */
    (xdc_Char)0x61,  /* [1162] */
    (xdc_Char)0x73,  /* [1163] */
    (xdc_Char)0x6b,  /* [1164] */
    (xdc_Char)0x44,  /* [1165] */
    (xdc_Char)0x69,  /* [1166] */
    (xdc_Char)0x73,  /* [1167] */
    (xdc_Char)0x61,  /* [1168] */
    (xdc_Char)0x62,  /* [1169] */
    (xdc_Char)0x6c,  /* [1170] */
    (xdc_Char)0x65,  /* [1171] */
    (xdc_Char)0x64,  /* [1172] */
    (xdc_Char)0x3a,  /* [1173] */
    (xdc_Char)0x20,  /* [1174] */
    (xdc_Char)0x43,  /* [1175] */
    (xdc_Char)0x61,  /* [1176] */
    (xdc_Char)0x6e,  /* [1177] */
    (xdc_Char)0x6e,  /* [1178] */
    (xdc_Char)0x6f,  /* [1179] */
    (xdc_Char)0x74,  /* [1180] */
    (xdc_Char)0x20,  /* [1181] */
    (xdc_Char)0x63,  /* [1182] */
    (xdc_Char)0x72,  /* [1183] */
    (xdc_Char)0x65,  /* [1184] */
    (xdc_Char)0x61,  /* [1185] */
    (xdc_Char)0x74,  /* [1186] */
    (xdc_Char)0x65,  /* [1187] */
    (xdc_Char)0x20,  /* [1188] */
    (xdc_Char)0x61,  /* [1189] */
    (xdc_Char)0x20,  /* [1190] */
    (xdc_Char)0x74,  /* [1191] */
    (xdc_Char)0x61,  /* [1192] */
    (xdc_Char)0x73,  /* [1193] */
    (xdc_Char)0x6b,  /* [1194] */
    (xdc_Char)0x20,  /* [1195] */
    (xdc_Char)0x77,  /* [1196] */
    (xdc_Char)0x68,  /* [1197] */
    (xdc_Char)0x65,  /* [1198] */
    (xdc_Char)0x6e,  /* [1199] */
    (xdc_Char)0x20,  /* [1200] */
    (xdc_Char)0x74,  /* [1201] */
    (xdc_Char)0x61,  /* [1202] */
    (xdc_Char)0x73,  /* [1203] */
    (xdc_Char)0x6b,  /* [1204] */
    (xdc_Char)0x69,  /* [1205] */
    (xdc_Char)0x6e,  /* [1206] */
    (xdc_Char)0x67,  /* [1207] */
    (xdc_Char)0x20,  /* [1208] */
    (xdc_Char)0x69,  /* [1209] */
    (xdc_Char)0x73,  /* [1210] */
    (xdc_Char)0x20,  /* [1211] */
    (xdc_Char)0x64,  /* [1212] */
    (xdc_Char)0x69,  /* [1213] */
    (xdc_Char)0x73,  /* [1214] */
    (xdc_Char)0x61,  /* [1215] */
    (xdc_Char)0x62,  /* [1216] */
    (xdc_Char)0x6c,  /* [1217] */
    (xdc_Char)0x65,  /* [1218] */
    (xdc_Char)0x64,  /* [1219] */
    (xdc_Char)0x2e,  /* [1220] */
    (xdc_Char)0x0,  /* [1221] */
    (xdc_Char)0x41,  /* [1222] */
    (xdc_Char)0x5f,  /* [1223] */
    (xdc_Char)0x62,  /* [1224] */
    (xdc_Char)0x61,  /* [1225] */
    (xdc_Char)0x64,  /* [1226] */
    (xdc_Char)0x50,  /* [1227] */
    (xdc_Char)0x72,  /* [1228] */
    (xdc_Char)0x69,  /* [1229] */
    (xdc_Char)0x6f,  /* [1230] */
    (xdc_Char)0x72,  /* [1231] */
    (xdc_Char)0x69,  /* [1232] */
    (xdc_Char)0x74,  /* [1233] */
    (xdc_Char)0x79,  /* [1234] */
    (xdc_Char)0x3a,  /* [1235] */
    (xdc_Char)0x20,  /* [1236] */
    (xdc_Char)0x41,  /* [1237] */
    (xdc_Char)0x6e,  /* [1238] */
    (xdc_Char)0x20,  /* [1239] */
    (xdc_Char)0x69,  /* [1240] */
    (xdc_Char)0x6e,  /* [1241] */
    (xdc_Char)0x76,  /* [1242] */
    (xdc_Char)0x61,  /* [1243] */
    (xdc_Char)0x6c,  /* [1244] */
    (xdc_Char)0x69,  /* [1245] */
    (xdc_Char)0x64,  /* [1246] */
    (xdc_Char)0x20,  /* [1247] */
    (xdc_Char)0x74,  /* [1248] */
    (xdc_Char)0x61,  /* [1249] */
    (xdc_Char)0x73,  /* [1250] */
    (xdc_Char)0x6b,  /* [1251] */
    (xdc_Char)0x20,  /* [1252] */
    (xdc_Char)0x70,  /* [1253] */
    (xdc_Char)0x72,  /* [1254] */
    (xdc_Char)0x69,  /* [1255] */
    (xdc_Char)0x6f,  /* [1256] */
    (xdc_Char)0x72,  /* [1257] */
    (xdc_Char)0x69,  /* [1258] */
    (xdc_Char)0x74,  /* [1259] */
    (xdc_Char)0x79,  /* [1260] */
    (xdc_Char)0x20,  /* [1261] */
    (xdc_Char)0x77,  /* [1262] */
    (xdc_Char)0x61,  /* [1263] */
    (xdc_Char)0x73,  /* [1264] */
    (xdc_Char)0x20,  /* [1265] */
    (xdc_Char)0x75,  /* [1266] */
    (xdc_Char)0x73,  /* [1267] */
    (xdc_Char)0x65,  /* [1268] */
    (xdc_Char)0x64,  /* [1269] */
    (xdc_Char)0x2e,  /* [1270] */
    (xdc_Char)0x0,  /* [1271] */
    (xdc_Char)0x41,  /* [1272] */
    (xdc_Char)0x5f,  /* [1273] */
    (xdc_Char)0x62,  /* [1274] */
    (xdc_Char)0x61,  /* [1275] */
    (xdc_Char)0x64,  /* [1276] */
    (xdc_Char)0x54,  /* [1277] */
    (xdc_Char)0x69,  /* [1278] */
    (xdc_Char)0x6d,  /* [1279] */
    (xdc_Char)0x65,  /* [1280] */
    (xdc_Char)0x6f,  /* [1281] */
    (xdc_Char)0x75,  /* [1282] */
    (xdc_Char)0x74,  /* [1283] */
    (xdc_Char)0x3a,  /* [1284] */
    (xdc_Char)0x20,  /* [1285] */
    (xdc_Char)0x43,  /* [1286] */
    (xdc_Char)0x61,  /* [1287] */
    (xdc_Char)0x6e,  /* [1288] */
    (xdc_Char)0x27,  /* [1289] */
    (xdc_Char)0x74,  /* [1290] */
    (xdc_Char)0x20,  /* [1291] */
    (xdc_Char)0x73,  /* [1292] */
    (xdc_Char)0x6c,  /* [1293] */
    (xdc_Char)0x65,  /* [1294] */
    (xdc_Char)0x65,  /* [1295] */
    (xdc_Char)0x70,  /* [1296] */
    (xdc_Char)0x20,  /* [1297] */
    (xdc_Char)0x46,  /* [1298] */
    (xdc_Char)0x4f,  /* [1299] */
    (xdc_Char)0x52,  /* [1300] */
    (xdc_Char)0x45,  /* [1301] */
    (xdc_Char)0x56,  /* [1302] */
    (xdc_Char)0x45,  /* [1303] */
    (xdc_Char)0x52,  /* [1304] */
    (xdc_Char)0x2e,  /* [1305] */
    (xdc_Char)0x0,  /* [1306] */
    (xdc_Char)0x41,  /* [1307] */
    (xdc_Char)0x5f,  /* [1308] */
    (xdc_Char)0x62,  /* [1309] */
    (xdc_Char)0x61,  /* [1310] */
    (xdc_Char)0x64,  /* [1311] */
    (xdc_Char)0x43,  /* [1312] */
    (xdc_Char)0x6f,  /* [1313] */
    (xdc_Char)0x6e,  /* [1314] */
    (xdc_Char)0x74,  /* [1315] */
    (xdc_Char)0x65,  /* [1316] */
    (xdc_Char)0x78,  /* [1317] */
    (xdc_Char)0x74,  /* [1318] */
    (xdc_Char)0x3a,  /* [1319] */
    (xdc_Char)0x20,  /* [1320] */
    (xdc_Char)0x62,  /* [1321] */
    (xdc_Char)0x61,  /* [1322] */
    (xdc_Char)0x64,  /* [1323] */
    (xdc_Char)0x20,  /* [1324] */
    (xdc_Char)0x63,  /* [1325] */
    (xdc_Char)0x61,  /* [1326] */
    (xdc_Char)0x6c,  /* [1327] */
    (xdc_Char)0x6c,  /* [1328] */
    (xdc_Char)0x69,  /* [1329] */
    (xdc_Char)0x6e,  /* [1330] */
    (xdc_Char)0x67,  /* [1331] */
    (xdc_Char)0x20,  /* [1332] */
    (xdc_Char)0x63,  /* [1333] */
    (xdc_Char)0x6f,  /* [1334] */
    (xdc_Char)0x6e,  /* [1335] */
    (xdc_Char)0x74,  /* [1336] */
    (xdc_Char)0x65,  /* [1337] */
    (xdc_Char)0x78,  /* [1338] */
    (xdc_Char)0x74,  /* [1339] */
    (xdc_Char)0x2e,  /* [1340] */
    (xdc_Char)0x20,  /* [1341] */
    (xdc_Char)0x4d,  /* [1342] */
    (xdc_Char)0x61,  /* [1343] */
    (xdc_Char)0x79,  /* [1344] */
    (xdc_Char)0x20,  /* [1345] */
    (xdc_Char)0x6e,  /* [1346] */
    (xdc_Char)0x6f,  /* [1347] */
    (xdc_Char)0x74,  /* [1348] */
    (xdc_Char)0x20,  /* [1349] */
    (xdc_Char)0x62,  /* [1350] */
    (xdc_Char)0x65,  /* [1351] */
    (xdc_Char)0x20,  /* [1352] */
    (xdc_Char)0x65,  /* [1353] */
    (xdc_Char)0x6e,  /* [1354] */
    (xdc_Char)0x74,  /* [1355] */
    (xdc_Char)0x65,  /* [1356] */
    (xdc_Char)0x72,  /* [1357] */
    (xdc_Char)0x65,  /* [1358] */
    (xdc_Char)0x64,  /* [1359] */
    (xdc_Char)0x20,  /* [1360] */
    (xdc_Char)0x66,  /* [1361] */
    (xdc_Char)0x72,  /* [1362] */
    (xdc_Char)0x6f,  /* [1363] */
    (xdc_Char)0x6d,  /* [1364] */
    (xdc_Char)0x20,  /* [1365] */
    (xdc_Char)0x61,  /* [1366] */
    (xdc_Char)0x20,  /* [1367] */
    (xdc_Char)0x68,  /* [1368] */
    (xdc_Char)0x61,  /* [1369] */
    (xdc_Char)0x72,  /* [1370] */
    (xdc_Char)0x64,  /* [1371] */
    (xdc_Char)0x77,  /* [1372] */
    (xdc_Char)0x61,  /* [1373] */
    (xdc_Char)0x72,  /* [1374] */
    (xdc_Char)0x65,  /* [1375] */
    (xdc_Char)0x20,  /* [1376] */
    (xdc_Char)0x69,  /* [1377] */
    (xdc_Char)0x6e,  /* [1378] */
    (xdc_Char)0x74,  /* [1379] */
    (xdc_Char)0x65,  /* [1380] */
    (xdc_Char)0x72,  /* [1381] */
    (xdc_Char)0x72,  /* [1382] */
    (xdc_Char)0x75,  /* [1383] */
    (xdc_Char)0x70,  /* [1384] */
    (xdc_Char)0x74,  /* [1385] */
    (xdc_Char)0x20,  /* [1386] */
    (xdc_Char)0x74,  /* [1387] */
    (xdc_Char)0x68,  /* [1388] */
    (xdc_Char)0x72,  /* [1389] */
    (xdc_Char)0x65,  /* [1390] */
    (xdc_Char)0x61,  /* [1391] */
    (xdc_Char)0x64,  /* [1392] */
    (xdc_Char)0x2e,  /* [1393] */
    (xdc_Char)0x0,  /* [1394] */
    (xdc_Char)0x41,  /* [1395] */
    (xdc_Char)0x5f,  /* [1396] */
    (xdc_Char)0x62,  /* [1397] */
    (xdc_Char)0x61,  /* [1398] */
    (xdc_Char)0x64,  /* [1399] */
    (xdc_Char)0x43,  /* [1400] */
    (xdc_Char)0x6f,  /* [1401] */
    (xdc_Char)0x6e,  /* [1402] */
    (xdc_Char)0x74,  /* [1403] */
    (xdc_Char)0x65,  /* [1404] */
    (xdc_Char)0x78,  /* [1405] */
    (xdc_Char)0x74,  /* [1406] */
    (xdc_Char)0x3a,  /* [1407] */
    (xdc_Char)0x20,  /* [1408] */
    (xdc_Char)0x62,  /* [1409] */
    (xdc_Char)0x61,  /* [1410] */
    (xdc_Char)0x64,  /* [1411] */
    (xdc_Char)0x20,  /* [1412] */
    (xdc_Char)0x63,  /* [1413] */
    (xdc_Char)0x61,  /* [1414] */
    (xdc_Char)0x6c,  /* [1415] */
    (xdc_Char)0x6c,  /* [1416] */
    (xdc_Char)0x69,  /* [1417] */
    (xdc_Char)0x6e,  /* [1418] */
    (xdc_Char)0x67,  /* [1419] */
    (xdc_Char)0x20,  /* [1420] */
    (xdc_Char)0x63,  /* [1421] */
    (xdc_Char)0x6f,  /* [1422] */
    (xdc_Char)0x6e,  /* [1423] */
    (xdc_Char)0x74,  /* [1424] */
    (xdc_Char)0x65,  /* [1425] */
    (xdc_Char)0x78,  /* [1426] */
    (xdc_Char)0x74,  /* [1427] */
    (xdc_Char)0x2e,  /* [1428] */
    (xdc_Char)0x20,  /* [1429] */
    (xdc_Char)0x4d,  /* [1430] */
    (xdc_Char)0x61,  /* [1431] */
    (xdc_Char)0x79,  /* [1432] */
    (xdc_Char)0x20,  /* [1433] */
    (xdc_Char)0x6e,  /* [1434] */
    (xdc_Char)0x6f,  /* [1435] */
    (xdc_Char)0x74,  /* [1436] */
    (xdc_Char)0x20,  /* [1437] */
    (xdc_Char)0x62,  /* [1438] */
    (xdc_Char)0x65,  /* [1439] */
    (xdc_Char)0x20,  /* [1440] */
    (xdc_Char)0x65,  /* [1441] */
    (xdc_Char)0x6e,  /* [1442] */
    (xdc_Char)0x74,  /* [1443] */
    (xdc_Char)0x65,  /* [1444] */
    (xdc_Char)0x72,  /* [1445] */
    (xdc_Char)0x65,  /* [1446] */
    (xdc_Char)0x64,  /* [1447] */
    (xdc_Char)0x20,  /* [1448] */
    (xdc_Char)0x66,  /* [1449] */
    (xdc_Char)0x72,  /* [1450] */
    (xdc_Char)0x6f,  /* [1451] */
    (xdc_Char)0x6d,  /* [1452] */
    (xdc_Char)0x20,  /* [1453] */
    (xdc_Char)0x61,  /* [1454] */
    (xdc_Char)0x20,  /* [1455] */
    (xdc_Char)0x73,  /* [1456] */
    (xdc_Char)0x6f,  /* [1457] */
    (xdc_Char)0x66,  /* [1458] */
    (xdc_Char)0x74,  /* [1459] */
    (xdc_Char)0x77,  /* [1460] */
    (xdc_Char)0x61,  /* [1461] */
    (xdc_Char)0x72,  /* [1462] */
    (xdc_Char)0x65,  /* [1463] */
    (xdc_Char)0x20,  /* [1464] */
    (xdc_Char)0x6f,  /* [1465] */
    (xdc_Char)0x72,  /* [1466] */
    (xdc_Char)0x20,  /* [1467] */
    (xdc_Char)0x68,  /* [1468] */
    (xdc_Char)0x61,  /* [1469] */
    (xdc_Char)0x72,  /* [1470] */
    (xdc_Char)0x64,  /* [1471] */
    (xdc_Char)0x77,  /* [1472] */
    (xdc_Char)0x61,  /* [1473] */
    (xdc_Char)0x72,  /* [1474] */
    (xdc_Char)0x65,  /* [1475] */
    (xdc_Char)0x20,  /* [1476] */
    (xdc_Char)0x69,  /* [1477] */
    (xdc_Char)0x6e,  /* [1478] */
    (xdc_Char)0x74,  /* [1479] */
    (xdc_Char)0x65,  /* [1480] */
    (xdc_Char)0x72,  /* [1481] */
    (xdc_Char)0x72,  /* [1482] */
    (xdc_Char)0x75,  /* [1483] */
    (xdc_Char)0x70,  /* [1484] */
    (xdc_Char)0x74,  /* [1485] */
    (xdc_Char)0x20,  /* [1486] */
    (xdc_Char)0x74,  /* [1487] */
    (xdc_Char)0x68,  /* [1488] */
    (xdc_Char)0x72,  /* [1489] */
    (xdc_Char)0x65,  /* [1490] */
    (xdc_Char)0x61,  /* [1491] */
    (xdc_Char)0x64,  /* [1492] */
    (xdc_Char)0x2e,  /* [1493] */
    (xdc_Char)0x0,  /* [1494] */
    (xdc_Char)0x41,  /* [1495] */
    (xdc_Char)0x5f,  /* [1496] */
    (xdc_Char)0x62,  /* [1497] */
    (xdc_Char)0x61,  /* [1498] */
    (xdc_Char)0x64,  /* [1499] */
    (xdc_Char)0x43,  /* [1500] */
    (xdc_Char)0x6f,  /* [1501] */
    (xdc_Char)0x6e,  /* [1502] */
    (xdc_Char)0x74,  /* [1503] */
    (xdc_Char)0x65,  /* [1504] */
    (xdc_Char)0x78,  /* [1505] */
    (xdc_Char)0x74,  /* [1506] */
    (xdc_Char)0x3a,  /* [1507] */
    (xdc_Char)0x20,  /* [1508] */
    (xdc_Char)0x62,  /* [1509] */
    (xdc_Char)0x61,  /* [1510] */
    (xdc_Char)0x64,  /* [1511] */
    (xdc_Char)0x20,  /* [1512] */
    (xdc_Char)0x63,  /* [1513] */
    (xdc_Char)0x61,  /* [1514] */
    (xdc_Char)0x6c,  /* [1515] */
    (xdc_Char)0x6c,  /* [1516] */
    (xdc_Char)0x69,  /* [1517] */
    (xdc_Char)0x6e,  /* [1518] */
    (xdc_Char)0x67,  /* [1519] */
    (xdc_Char)0x20,  /* [1520] */
    (xdc_Char)0x63,  /* [1521] */
    (xdc_Char)0x6f,  /* [1522] */
    (xdc_Char)0x6e,  /* [1523] */
    (xdc_Char)0x74,  /* [1524] */
    (xdc_Char)0x65,  /* [1525] */
    (xdc_Char)0x78,  /* [1526] */
    (xdc_Char)0x74,  /* [1527] */
    (xdc_Char)0x2e,  /* [1528] */
    (xdc_Char)0x20,  /* [1529] */
    (xdc_Char)0x53,  /* [1530] */
    (xdc_Char)0x65,  /* [1531] */
    (xdc_Char)0x65,  /* [1532] */
    (xdc_Char)0x20,  /* [1533] */
    (xdc_Char)0x47,  /* [1534] */
    (xdc_Char)0x61,  /* [1535] */
    (xdc_Char)0x74,  /* [1536] */
    (xdc_Char)0x65,  /* [1537] */
    (xdc_Char)0x4d,  /* [1538] */
    (xdc_Char)0x75,  /* [1539] */
    (xdc_Char)0x74,  /* [1540] */
    (xdc_Char)0x65,  /* [1541] */
    (xdc_Char)0x78,  /* [1542] */
    (xdc_Char)0x50,  /* [1543] */
    (xdc_Char)0x72,  /* [1544] */
    (xdc_Char)0x69,  /* [1545] */
    (xdc_Char)0x20,  /* [1546] */
    (xdc_Char)0x41,  /* [1547] */
    (xdc_Char)0x50,  /* [1548] */
    (xdc_Char)0x49,  /* [1549] */
    (xdc_Char)0x20,  /* [1550] */
    (xdc_Char)0x64,  /* [1551] */
    (xdc_Char)0x6f,  /* [1552] */
    (xdc_Char)0x63,  /* [1553] */
    (xdc_Char)0x20,  /* [1554] */
    (xdc_Char)0x66,  /* [1555] */
    (xdc_Char)0x6f,  /* [1556] */
    (xdc_Char)0x72,  /* [1557] */
    (xdc_Char)0x20,  /* [1558] */
    (xdc_Char)0x64,  /* [1559] */
    (xdc_Char)0x65,  /* [1560] */
    (xdc_Char)0x74,  /* [1561] */
    (xdc_Char)0x61,  /* [1562] */
    (xdc_Char)0x69,  /* [1563] */
    (xdc_Char)0x6c,  /* [1564] */
    (xdc_Char)0x73,  /* [1565] */
    (xdc_Char)0x2e,  /* [1566] */
    (xdc_Char)0x0,  /* [1567] */
    (xdc_Char)0x41,  /* [1568] */
    (xdc_Char)0x5f,  /* [1569] */
    (xdc_Char)0x62,  /* [1570] */
    (xdc_Char)0x61,  /* [1571] */
    (xdc_Char)0x64,  /* [1572] */
    (xdc_Char)0x43,  /* [1573] */
    (xdc_Char)0x6f,  /* [1574] */
    (xdc_Char)0x6e,  /* [1575] */
    (xdc_Char)0x74,  /* [1576] */
    (xdc_Char)0x65,  /* [1577] */
    (xdc_Char)0x78,  /* [1578] */
    (xdc_Char)0x74,  /* [1579] */
    (xdc_Char)0x3a,  /* [1580] */
    (xdc_Char)0x20,  /* [1581] */
    (xdc_Char)0x62,  /* [1582] */
    (xdc_Char)0x61,  /* [1583] */
    (xdc_Char)0x64,  /* [1584] */
    (xdc_Char)0x20,  /* [1585] */
    (xdc_Char)0x63,  /* [1586] */
    (xdc_Char)0x61,  /* [1587] */
    (xdc_Char)0x6c,  /* [1588] */
    (xdc_Char)0x6c,  /* [1589] */
    (xdc_Char)0x69,  /* [1590] */
    (xdc_Char)0x6e,  /* [1591] */
    (xdc_Char)0x67,  /* [1592] */
    (xdc_Char)0x20,  /* [1593] */
    (xdc_Char)0x63,  /* [1594] */
    (xdc_Char)0x6f,  /* [1595] */
    (xdc_Char)0x6e,  /* [1596] */
    (xdc_Char)0x74,  /* [1597] */
    (xdc_Char)0x65,  /* [1598] */
    (xdc_Char)0x78,  /* [1599] */
    (xdc_Char)0x74,  /* [1600] */
    (xdc_Char)0x2e,  /* [1601] */
    (xdc_Char)0x20,  /* [1602] */
    (xdc_Char)0x53,  /* [1603] */
    (xdc_Char)0x65,  /* [1604] */
    (xdc_Char)0x65,  /* [1605] */
    (xdc_Char)0x20,  /* [1606] */
    (xdc_Char)0x47,  /* [1607] */
    (xdc_Char)0x61,  /* [1608] */
    (xdc_Char)0x74,  /* [1609] */
    (xdc_Char)0x65,  /* [1610] */
    (xdc_Char)0x4d,  /* [1611] */
    (xdc_Char)0x75,  /* [1612] */
    (xdc_Char)0x74,  /* [1613] */
    (xdc_Char)0x65,  /* [1614] */
    (xdc_Char)0x78,  /* [1615] */
    (xdc_Char)0x20,  /* [1616] */
    (xdc_Char)0x41,  /* [1617] */
    (xdc_Char)0x50,  /* [1618] */
    (xdc_Char)0x49,  /* [1619] */
    (xdc_Char)0x20,  /* [1620] */
    (xdc_Char)0x64,  /* [1621] */
    (xdc_Char)0x6f,  /* [1622] */
    (xdc_Char)0x63,  /* [1623] */
    (xdc_Char)0x20,  /* [1624] */
    (xdc_Char)0x66,  /* [1625] */
    (xdc_Char)0x6f,  /* [1626] */
    (xdc_Char)0x72,  /* [1627] */
    (xdc_Char)0x20,  /* [1628] */
    (xdc_Char)0x64,  /* [1629] */
    (xdc_Char)0x65,  /* [1630] */
    (xdc_Char)0x74,  /* [1631] */
    (xdc_Char)0x61,  /* [1632] */
    (xdc_Char)0x69,  /* [1633] */
    (xdc_Char)0x6c,  /* [1634] */
    (xdc_Char)0x73,  /* [1635] */
    (xdc_Char)0x2e,  /* [1636] */
    (xdc_Char)0x0,  /* [1637] */
    (xdc_Char)0x41,  /* [1638] */
    (xdc_Char)0x5f,  /* [1639] */
    (xdc_Char)0x7a,  /* [1640] */
    (xdc_Char)0x65,  /* [1641] */
    (xdc_Char)0x72,  /* [1642] */
    (xdc_Char)0x6f,  /* [1643] */
    (xdc_Char)0x54,  /* [1644] */
    (xdc_Char)0x69,  /* [1645] */
    (xdc_Char)0x6d,  /* [1646] */
    (xdc_Char)0x65,  /* [1647] */
    (xdc_Char)0x6f,  /* [1648] */
    (xdc_Char)0x75,  /* [1649] */
    (xdc_Char)0x74,  /* [1650] */
    (xdc_Char)0x3a,  /* [1651] */
    (xdc_Char)0x20,  /* [1652] */
    (xdc_Char)0x54,  /* [1653] */
    (xdc_Char)0x69,  /* [1654] */
    (xdc_Char)0x6d,  /* [1655] */
    (xdc_Char)0x65,  /* [1656] */
    (xdc_Char)0x6f,  /* [1657] */
    (xdc_Char)0x75,  /* [1658] */
    (xdc_Char)0x74,  /* [1659] */
    (xdc_Char)0x20,  /* [1660] */
    (xdc_Char)0x76,  /* [1661] */
    (xdc_Char)0x61,  /* [1662] */
    (xdc_Char)0x6c,  /* [1663] */
    (xdc_Char)0x75,  /* [1664] */
    (xdc_Char)0x65,  /* [1665] */
    (xdc_Char)0x20,  /* [1666] */
    (xdc_Char)0x61,  /* [1667] */
    (xdc_Char)0x6e,  /* [1668] */
    (xdc_Char)0x6e,  /* [1669] */
    (xdc_Char)0x6f,  /* [1670] */
    (xdc_Char)0x74,  /* [1671] */
    (xdc_Char)0x20,  /* [1672] */
    (xdc_Char)0x62,  /* [1673] */
    (xdc_Char)0x65,  /* [1674] */
    (xdc_Char)0x20,  /* [1675] */
    (xdc_Char)0x7a,  /* [1676] */
    (xdc_Char)0x65,  /* [1677] */
    (xdc_Char)0x72,  /* [1678] */
    (xdc_Char)0x6f,  /* [1679] */
    (xdc_Char)0x0,  /* [1680] */
    (xdc_Char)0x41,  /* [1681] */
    (xdc_Char)0x5f,  /* [1682] */
    (xdc_Char)0x69,  /* [1683] */
    (xdc_Char)0x6e,  /* [1684] */
    (xdc_Char)0x76,  /* [1685] */
    (xdc_Char)0x61,  /* [1686] */
    (xdc_Char)0x6c,  /* [1687] */
    (xdc_Char)0x69,  /* [1688] */
    (xdc_Char)0x64,  /* [1689] */
    (xdc_Char)0x4b,  /* [1690] */
    (xdc_Char)0x65,  /* [1691] */
    (xdc_Char)0x79,  /* [1692] */
    (xdc_Char)0x3a,  /* [1693] */
    (xdc_Char)0x20,  /* [1694] */
    (xdc_Char)0x74,  /* [1695] */
    (xdc_Char)0x68,  /* [1696] */
    (xdc_Char)0x65,  /* [1697] */
    (xdc_Char)0x20,  /* [1698] */
    (xdc_Char)0x6b,  /* [1699] */
    (xdc_Char)0x65,  /* [1700] */
    (xdc_Char)0x79,  /* [1701] */
    (xdc_Char)0x20,  /* [1702] */
    (xdc_Char)0x6d,  /* [1703] */
    (xdc_Char)0x75,  /* [1704] */
    (xdc_Char)0x73,  /* [1705] */
    (xdc_Char)0x74,  /* [1706] */
    (xdc_Char)0x20,  /* [1707] */
    (xdc_Char)0x62,  /* [1708] */
    (xdc_Char)0x65,  /* [1709] */
    (xdc_Char)0x20,  /* [1710] */
    (xdc_Char)0x73,  /* [1711] */
    (xdc_Char)0x65,  /* [1712] */
    (xdc_Char)0x74,  /* [1713] */
    (xdc_Char)0x20,  /* [1714] */
    (xdc_Char)0x74,  /* [1715] */
    (xdc_Char)0x6f,  /* [1716] */
    (xdc_Char)0x20,  /* [1717] */
    (xdc_Char)0x61,  /* [1718] */
    (xdc_Char)0x20,  /* [1719] */
    (xdc_Char)0x6e,  /* [1720] */
    (xdc_Char)0x6f,  /* [1721] */
    (xdc_Char)0x6e,  /* [1722] */
    (xdc_Char)0x2d,  /* [1723] */
    (xdc_Char)0x64,  /* [1724] */
    (xdc_Char)0x65,  /* [1725] */
    (xdc_Char)0x66,  /* [1726] */
    (xdc_Char)0x61,  /* [1727] */
    (xdc_Char)0x75,  /* [1728] */
    (xdc_Char)0x6c,  /* [1729] */
    (xdc_Char)0x74,  /* [1730] */
    (xdc_Char)0x20,  /* [1731] */
    (xdc_Char)0x76,  /* [1732] */
    (xdc_Char)0x61,  /* [1733] */
    (xdc_Char)0x6c,  /* [1734] */
    (xdc_Char)0x75,  /* [1735] */
    (xdc_Char)0x65,  /* [1736] */
    (xdc_Char)0x0,  /* [1737] */
    (xdc_Char)0x41,  /* [1738] */
    (xdc_Char)0x5f,  /* [1739] */
    (xdc_Char)0x69,  /* [1740] */
    (xdc_Char)0x6e,  /* [1741] */
    (xdc_Char)0x76,  /* [1742] */
    (xdc_Char)0x61,  /* [1743] */
    (xdc_Char)0x6c,  /* [1744] */
    (xdc_Char)0x69,  /* [1745] */
    (xdc_Char)0x64,  /* [1746] */
    (xdc_Char)0x4c,  /* [1747] */
    (xdc_Char)0x65,  /* [1748] */
    (xdc_Char)0x6e,  /* [1749] */
    (xdc_Char)0x3a,  /* [1750] */
    (xdc_Char)0x20,  /* [1751] */
    (xdc_Char)0x49,  /* [1752] */
    (xdc_Char)0x6e,  /* [1753] */
    (xdc_Char)0x76,  /* [1754] */
    (xdc_Char)0x61,  /* [1755] */
    (xdc_Char)0x6c,  /* [1756] */
    (xdc_Char)0x69,  /* [1757] */
    (xdc_Char)0x64,  /* [1758] */
    (xdc_Char)0x20,  /* [1759] */
    (xdc_Char)0x6c,  /* [1760] */
    (xdc_Char)0x65,  /* [1761] */
    (xdc_Char)0x6e,  /* [1762] */
    (xdc_Char)0x67,  /* [1763] */
    (xdc_Char)0x74,  /* [1764] */
    (xdc_Char)0x68,  /* [1765] */
    (xdc_Char)0x0,  /* [1766] */
    (xdc_Char)0x41,  /* [1767] */
    (xdc_Char)0x5f,  /* [1768] */
    (xdc_Char)0x69,  /* [1769] */
    (xdc_Char)0x6e,  /* [1770] */
    (xdc_Char)0x76,  /* [1771] */
    (xdc_Char)0x41,  /* [1772] */
    (xdc_Char)0x72,  /* [1773] */
    (xdc_Char)0x67,  /* [1774] */
    (xdc_Char)0x75,  /* [1775] */
    (xdc_Char)0x6d,  /* [1776] */
    (xdc_Char)0x65,  /* [1777] */
    (xdc_Char)0x6e,  /* [1778] */
    (xdc_Char)0x74,  /* [1779] */
    (xdc_Char)0x3a,  /* [1780] */
    (xdc_Char)0x20,  /* [1781] */
    (xdc_Char)0x49,  /* [1782] */
    (xdc_Char)0x6e,  /* [1783] */
    (xdc_Char)0x76,  /* [1784] */
    (xdc_Char)0x61,  /* [1785] */
    (xdc_Char)0x6c,  /* [1786] */
    (xdc_Char)0x69,  /* [1787] */
    (xdc_Char)0x64,  /* [1788] */
    (xdc_Char)0x20,  /* [1789] */
    (xdc_Char)0x61,  /* [1790] */
    (xdc_Char)0x72,  /* [1791] */
    (xdc_Char)0x67,  /* [1792] */
    (xdc_Char)0x75,  /* [1793] */
    (xdc_Char)0x6d,  /* [1794] */
    (xdc_Char)0x65,  /* [1795] */
    (xdc_Char)0x6e,  /* [1796] */
    (xdc_Char)0x74,  /* [1797] */
    (xdc_Char)0x20,  /* [1798] */
    (xdc_Char)0x73,  /* [1799] */
    (xdc_Char)0x75,  /* [1800] */
    (xdc_Char)0x70,  /* [1801] */
    (xdc_Char)0x70,  /* [1802] */
    (xdc_Char)0x6c,  /* [1803] */
    (xdc_Char)0x69,  /* [1804] */
    (xdc_Char)0x65,  /* [1805] */
    (xdc_Char)0x64,  /* [1806] */
    (xdc_Char)0x0,  /* [1807] */
    (xdc_Char)0x41,  /* [1808] */
    (xdc_Char)0x5f,  /* [1809] */
    (xdc_Char)0x69,  /* [1810] */
    (xdc_Char)0x6e,  /* [1811] */
    (xdc_Char)0x76,  /* [1812] */
    (xdc_Char)0x61,  /* [1813] */
    (xdc_Char)0x6c,  /* [1814] */
    (xdc_Char)0x69,  /* [1815] */
    (xdc_Char)0x64,  /* [1816] */
    (xdc_Char)0x4d,  /* [1817] */
    (xdc_Char)0x75,  /* [1818] */
    (xdc_Char)0x6c,  /* [1819] */
    (xdc_Char)0x74,  /* [1820] */
    (xdc_Char)0x69,  /* [1821] */
    (xdc_Char)0x50,  /* [1822] */
    (xdc_Char)0x72,  /* [1823] */
    (xdc_Char)0x6f,  /* [1824] */
    (xdc_Char)0x63,  /* [1825] */
    (xdc_Char)0x49,  /* [1826] */
    (xdc_Char)0x64,  /* [1827] */
    (xdc_Char)0x3a,  /* [1828] */
    (xdc_Char)0x20,  /* [1829] */
    (xdc_Char)0x49,  /* [1830] */
    (xdc_Char)0x6e,  /* [1831] */
    (xdc_Char)0x76,  /* [1832] */
    (xdc_Char)0x61,  /* [1833] */
    (xdc_Char)0x6c,  /* [1834] */
    (xdc_Char)0x69,  /* [1835] */
    (xdc_Char)0x64,  /* [1836] */
    (xdc_Char)0x20,  /* [1837] */
    (xdc_Char)0x4d,  /* [1838] */
    (xdc_Char)0x75,  /* [1839] */
    (xdc_Char)0x6c,  /* [1840] */
    (xdc_Char)0x74,  /* [1841] */
    (xdc_Char)0x69,  /* [1842] */
    (xdc_Char)0x50,  /* [1843] */
    (xdc_Char)0x72,  /* [1844] */
    (xdc_Char)0x6f,  /* [1845] */
    (xdc_Char)0x63,  /* [1846] */
    (xdc_Char)0x20,  /* [1847] */
    (xdc_Char)0x69,  /* [1848] */
    (xdc_Char)0x64,  /* [1849] */
    (xdc_Char)0x0,  /* [1850] */
    (xdc_Char)0x41,  /* [1851] */
    (xdc_Char)0x5f,  /* [1852] */
    (xdc_Char)0x69,  /* [1853] */
    (xdc_Char)0x6e,  /* [1854] */
    (xdc_Char)0x76,  /* [1855] */
    (xdc_Char)0x61,  /* [1856] */
    (xdc_Char)0x6c,  /* [1857] */
    (xdc_Char)0x69,  /* [1858] */
    (xdc_Char)0x64,  /* [1859] */
    (xdc_Char)0x50,  /* [1860] */
    (xdc_Char)0x72,  /* [1861] */
    (xdc_Char)0x6f,  /* [1862] */
    (xdc_Char)0x63,  /* [1863] */
    (xdc_Char)0x4e,  /* [1864] */
    (xdc_Char)0x61,  /* [1865] */
    (xdc_Char)0x6d,  /* [1866] */
    (xdc_Char)0x65,  /* [1867] */
    (xdc_Char)0x3a,  /* [1868] */
    (xdc_Char)0x20,  /* [1869] */
    (xdc_Char)0x4e,  /* [1870] */
    (xdc_Char)0x55,  /* [1871] */
    (xdc_Char)0x4c,  /* [1872] */
    (xdc_Char)0x4c,  /* [1873] */
    (xdc_Char)0x20,  /* [1874] */
    (xdc_Char)0x4d,  /* [1875] */
    (xdc_Char)0x75,  /* [1876] */
    (xdc_Char)0x6c,  /* [1877] */
    (xdc_Char)0x74,  /* [1878] */
    (xdc_Char)0x69,  /* [1879] */
    (xdc_Char)0x50,  /* [1880] */
    (xdc_Char)0x72,  /* [1881] */
    (xdc_Char)0x6f,  /* [1882] */
    (xdc_Char)0x63,  /* [1883] */
    (xdc_Char)0x20,  /* [1884] */
    (xdc_Char)0x6e,  /* [1885] */
    (xdc_Char)0x61,  /* [1886] */
    (xdc_Char)0x6d,  /* [1887] */
    (xdc_Char)0x65,  /* [1888] */
    (xdc_Char)0x20,  /* [1889] */
    (xdc_Char)0x65,  /* [1890] */
    (xdc_Char)0x6e,  /* [1891] */
    (xdc_Char)0x63,  /* [1892] */
    (xdc_Char)0x6f,  /* [1893] */
    (xdc_Char)0x75,  /* [1894] */
    (xdc_Char)0x6e,  /* [1895] */
    (xdc_Char)0x74,  /* [1896] */
    (xdc_Char)0x65,  /* [1897] */
    (xdc_Char)0x72,  /* [1898] */
    (xdc_Char)0x65,  /* [1899] */
    (xdc_Char)0x64,  /* [1900] */
    (xdc_Char)0x0,  /* [1901] */
    (xdc_Char)0x41,  /* [1902] */
    (xdc_Char)0x5f,  /* [1903] */
    (xdc_Char)0x6e,  /* [1904] */
    (xdc_Char)0x75,  /* [1905] */
    (xdc_Char)0x6c,  /* [1906] */
    (xdc_Char)0x6c,  /* [1907] */
    (xdc_Char)0x48,  /* [1908] */
    (xdc_Char)0x61,  /* [1909] */
    (xdc_Char)0x6e,  /* [1910] */
    (xdc_Char)0x64,  /* [1911] */
    (xdc_Char)0x6c,  /* [1912] */
    (xdc_Char)0x65,  /* [1913] */
    (xdc_Char)0x3a,  /* [1914] */
    (xdc_Char)0x20,  /* [1915] */
    (xdc_Char)0x4e,  /* [1916] */
    (xdc_Char)0x75,  /* [1917] */
    (xdc_Char)0x6c,  /* [1918] */
    (xdc_Char)0x6c,  /* [1919] */
    (xdc_Char)0x20,  /* [1920] */
    (xdc_Char)0x68,  /* [1921] */
    (xdc_Char)0x61,  /* [1922] */
    (xdc_Char)0x6e,  /* [1923] */
    (xdc_Char)0x64,  /* [1924] */
    (xdc_Char)0x6c,  /* [1925] */
    (xdc_Char)0x65,  /* [1926] */
    (xdc_Char)0x20,  /* [1927] */
    (xdc_Char)0x70,  /* [1928] */
    (xdc_Char)0x61,  /* [1929] */
    (xdc_Char)0x73,  /* [1930] */
    (xdc_Char)0x73,  /* [1931] */
    (xdc_Char)0x65,  /* [1932] */
    (xdc_Char)0x64,  /* [1933] */
    (xdc_Char)0x20,  /* [1934] */
    (xdc_Char)0x74,  /* [1935] */
    (xdc_Char)0x6f,  /* [1936] */
    (xdc_Char)0x20,  /* [1937] */
    (xdc_Char)0x63,  /* [1938] */
    (xdc_Char)0x72,  /* [1939] */
    (xdc_Char)0x65,  /* [1940] */
    (xdc_Char)0x61,  /* [1941] */
    (xdc_Char)0x74,  /* [1942] */
    (xdc_Char)0x65,  /* [1943] */
    (xdc_Char)0x0,  /* [1944] */
    (xdc_Char)0x41,  /* [1945] */
    (xdc_Char)0x5f,  /* [1946] */
    (xdc_Char)0x69,  /* [1947] */
    (xdc_Char)0x6e,  /* [1948] */
    (xdc_Char)0x76,  /* [1949] */
    (xdc_Char)0x61,  /* [1950] */
    (xdc_Char)0x6c,  /* [1951] */
    (xdc_Char)0x69,  /* [1952] */
    (xdc_Char)0x64,  /* [1953] */
    (xdc_Char)0x43,  /* [1954] */
    (xdc_Char)0x6f,  /* [1955] */
    (xdc_Char)0x6e,  /* [1956] */
    (xdc_Char)0x74,  /* [1957] */
    (xdc_Char)0x65,  /* [1958] */
    (xdc_Char)0x78,  /* [1959] */
    (xdc_Char)0x74,  /* [1960] */
    (xdc_Char)0x3a,  /* [1961] */
    (xdc_Char)0x20,  /* [1962] */
    (xdc_Char)0x43,  /* [1963] */
    (xdc_Char)0x61,  /* [1964] */
    (xdc_Char)0x6c,  /* [1965] */
    (xdc_Char)0x6c,  /* [1966] */
    (xdc_Char)0x69,  /* [1967] */
    (xdc_Char)0x6e,  /* [1968] */
    (xdc_Char)0x67,  /* [1969] */
    (xdc_Char)0x20,  /* [1970] */
    (xdc_Char)0x47,  /* [1971] */
    (xdc_Char)0x61,  /* [1972] */
    (xdc_Char)0x74,  /* [1973] */
    (xdc_Char)0x65,  /* [1974] */
    (xdc_Char)0x4d,  /* [1975] */
    (xdc_Char)0x50,  /* [1976] */
    (xdc_Char)0x5f,  /* [1977] */
    (xdc_Char)0x63,  /* [1978] */
    (xdc_Char)0x6c,  /* [1979] */
    (xdc_Char)0x6f,  /* [1980] */
    (xdc_Char)0x73,  /* [1981] */
    (xdc_Char)0x65,  /* [1982] */
    (xdc_Char)0x20,  /* [1983] */
    (xdc_Char)0x77,  /* [1984] */
    (xdc_Char)0x69,  /* [1985] */
    (xdc_Char)0x74,  /* [1986] */
    (xdc_Char)0x68,  /* [1987] */
    (xdc_Char)0x20,  /* [1988] */
    (xdc_Char)0x74,  /* [1989] */
    (xdc_Char)0x68,  /* [1990] */
    (xdc_Char)0x65,  /* [1991] */
    (xdc_Char)0x20,  /* [1992] */
    (xdc_Char)0x77,  /* [1993] */
    (xdc_Char)0x72,  /* [1994] */
    (xdc_Char)0x6f,  /* [1995] */
    (xdc_Char)0x6e,  /* [1996] */
    (xdc_Char)0x67,  /* [1997] */
    (xdc_Char)0x20,  /* [1998] */
    (xdc_Char)0x68,  /* [1999] */
    (xdc_Char)0x61,  /* [2000] */
    (xdc_Char)0x6e,  /* [2001] */
    (xdc_Char)0x64,  /* [2002] */
    (xdc_Char)0x6c,  /* [2003] */
    (xdc_Char)0x65,  /* [2004] */
    (xdc_Char)0x0,  /* [2005] */
    (xdc_Char)0x41,  /* [2006] */
    (xdc_Char)0x5f,  /* [2007] */
    (xdc_Char)0x69,  /* [2008] */
    (xdc_Char)0x6e,  /* [2009] */
    (xdc_Char)0x76,  /* [2010] */
    (xdc_Char)0x61,  /* [2011] */
    (xdc_Char)0x6c,  /* [2012] */
    (xdc_Char)0x69,  /* [2013] */
    (xdc_Char)0x64,  /* [2014] */
    (xdc_Char)0x44,  /* [2015] */
    (xdc_Char)0x65,  /* [2016] */
    (xdc_Char)0x6c,  /* [2017] */
    (xdc_Char)0x65,  /* [2018] */
    (xdc_Char)0x74,  /* [2019] */
    (xdc_Char)0x65,  /* [2020] */
    (xdc_Char)0x3a,  /* [2021] */
    (xdc_Char)0x20,  /* [2022] */
    (xdc_Char)0x43,  /* [2023] */
    (xdc_Char)0x61,  /* [2024] */
    (xdc_Char)0x6c,  /* [2025] */
    (xdc_Char)0x6c,  /* [2026] */
    (xdc_Char)0x69,  /* [2027] */
    (xdc_Char)0x6e,  /* [2028] */
    (xdc_Char)0x67,  /* [2029] */
    (xdc_Char)0x20,  /* [2030] */
    (xdc_Char)0x47,  /* [2031] */
    (xdc_Char)0x61,  /* [2032] */
    (xdc_Char)0x74,  /* [2033] */
    (xdc_Char)0x65,  /* [2034] */
    (xdc_Char)0x4d,  /* [2035] */
    (xdc_Char)0x50,  /* [2036] */
    (xdc_Char)0x5f,  /* [2037] */
    (xdc_Char)0x64,  /* [2038] */
    (xdc_Char)0x65,  /* [2039] */
    (xdc_Char)0x6c,  /* [2040] */
    (xdc_Char)0x65,  /* [2041] */
    (xdc_Char)0x74,  /* [2042] */
    (xdc_Char)0x65,  /* [2043] */
    (xdc_Char)0x20,  /* [2044] */
    (xdc_Char)0x69,  /* [2045] */
    (xdc_Char)0x6e,  /* [2046] */
    (xdc_Char)0x63,  /* [2047] */
    (xdc_Char)0x6f,  /* [2048] */
    (xdc_Char)0x72,  /* [2049] */
    (xdc_Char)0x72,  /* [2050] */
    (xdc_Char)0x65,  /* [2051] */
    (xdc_Char)0x63,  /* [2052] */
    (xdc_Char)0x74,  /* [2053] */
    (xdc_Char)0x6c,  /* [2054] */
    (xdc_Char)0x79,  /* [2055] */
    (xdc_Char)0x0,  /* [2056] */
    (xdc_Char)0x41,  /* [2057] */
    (xdc_Char)0x5f,  /* [2058] */
    (xdc_Char)0x69,  /* [2059] */
    (xdc_Char)0x6e,  /* [2060] */
    (xdc_Char)0x76,  /* [2061] */
    (xdc_Char)0x61,  /* [2062] */
    (xdc_Char)0x6c,  /* [2063] */
    (xdc_Char)0x69,  /* [2064] */
    (xdc_Char)0x64,  /* [2065] */
    (xdc_Char)0x43,  /* [2066] */
    (xdc_Char)0x6f,  /* [2067] */
    (xdc_Char)0x6e,  /* [2068] */
    (xdc_Char)0x74,  /* [2069] */
    (xdc_Char)0x65,  /* [2070] */
    (xdc_Char)0x78,  /* [2071] */
    (xdc_Char)0x74,  /* [2072] */
    (xdc_Char)0x3a,  /* [2073] */
    (xdc_Char)0x20,  /* [2074] */
    (xdc_Char)0x43,  /* [2075] */
    (xdc_Char)0x61,  /* [2076] */
    (xdc_Char)0x6e,  /* [2077] */
    (xdc_Char)0x6e,  /* [2078] */
    (xdc_Char)0x6f,  /* [2079] */
    (xdc_Char)0x74,  /* [2080] */
    (xdc_Char)0x20,  /* [2081] */
    (xdc_Char)0x63,  /* [2082] */
    (xdc_Char)0x61,  /* [2083] */
    (xdc_Char)0x6c,  /* [2084] */
    (xdc_Char)0x6c,  /* [2085] */
    (xdc_Char)0x20,  /* [2086] */
    (xdc_Char)0x77,  /* [2087] */
    (xdc_Char)0x69,  /* [2088] */
    (xdc_Char)0x74,  /* [2089] */
    (xdc_Char)0x68,  /* [2090] */
    (xdc_Char)0x20,  /* [2091] */
    (xdc_Char)0x61,  /* [2092] */
    (xdc_Char)0x6e,  /* [2093] */
    (xdc_Char)0x20,  /* [2094] */
    (xdc_Char)0x6f,  /* [2095] */
    (xdc_Char)0x70,  /* [2096] */
    (xdc_Char)0x65,  /* [2097] */
    (xdc_Char)0x6e,  /* [2098] */
    (xdc_Char)0x2f,  /* [2099] */
    (xdc_Char)0x63,  /* [2100] */
    (xdc_Char)0x72,  /* [2101] */
    (xdc_Char)0x65,  /* [2102] */
    (xdc_Char)0x61,  /* [2103] */
    (xdc_Char)0x74,  /* [2104] */
    (xdc_Char)0x65,  /* [2105] */
    (xdc_Char)0x20,  /* [2106] */
    (xdc_Char)0x68,  /* [2107] */
    (xdc_Char)0x61,  /* [2108] */
    (xdc_Char)0x6e,  /* [2109] */
    (xdc_Char)0x64,  /* [2110] */
    (xdc_Char)0x6c,  /* [2111] */
    (xdc_Char)0x65,  /* [2112] */
    (xdc_Char)0x0,  /* [2113] */
    (xdc_Char)0x41,  /* [2114] */
    (xdc_Char)0x5f,  /* [2115] */
    (xdc_Char)0x63,  /* [2116] */
    (xdc_Char)0x61,  /* [2117] */
    (xdc_Char)0x6e,  /* [2118] */
    (xdc_Char)0x6e,  /* [2119] */
    (xdc_Char)0x6f,  /* [2120] */
    (xdc_Char)0x74,  /* [2121] */
    (xdc_Char)0x46,  /* [2122] */
    (xdc_Char)0x72,  /* [2123] */
    (xdc_Char)0x65,  /* [2124] */
    (xdc_Char)0x65,  /* [2125] */
    (xdc_Char)0x53,  /* [2126] */
    (xdc_Char)0x74,  /* [2127] */
    (xdc_Char)0x61,  /* [2128] */
    (xdc_Char)0x74,  /* [2129] */
    (xdc_Char)0x69,  /* [2130] */
    (xdc_Char)0x63,  /* [2131] */
    (xdc_Char)0x4d,  /* [2132] */
    (xdc_Char)0x73,  /* [2133] */
    (xdc_Char)0x67,  /* [2134] */
    (xdc_Char)0x3a,  /* [2135] */
    (xdc_Char)0x20,  /* [2136] */
    (xdc_Char)0x43,  /* [2137] */
    (xdc_Char)0x61,  /* [2138] */
    (xdc_Char)0x6e,  /* [2139] */
    (xdc_Char)0x6e,  /* [2140] */
    (xdc_Char)0x6f,  /* [2141] */
    (xdc_Char)0x74,  /* [2142] */
    (xdc_Char)0x20,  /* [2143] */
    (xdc_Char)0x63,  /* [2144] */
    (xdc_Char)0x61,  /* [2145] */
    (xdc_Char)0x6c,  /* [2146] */
    (xdc_Char)0x6c,  /* [2147] */
    (xdc_Char)0x20,  /* [2148] */
    (xdc_Char)0x4d,  /* [2149] */
    (xdc_Char)0x65,  /* [2150] */
    (xdc_Char)0x73,  /* [2151] */
    (xdc_Char)0x73,  /* [2152] */
    (xdc_Char)0x61,  /* [2153] */
    (xdc_Char)0x67,  /* [2154] */
    (xdc_Char)0x65,  /* [2155] */
    (xdc_Char)0x51,  /* [2156] */
    (xdc_Char)0x5f,  /* [2157] */
    (xdc_Char)0x66,  /* [2158] */
    (xdc_Char)0x72,  /* [2159] */
    (xdc_Char)0x65,  /* [2160] */
    (xdc_Char)0x65,  /* [2161] */
    (xdc_Char)0x20,  /* [2162] */
    (xdc_Char)0x77,  /* [2163] */
    (xdc_Char)0x69,  /* [2164] */
    (xdc_Char)0x74,  /* [2165] */
    (xdc_Char)0x68,  /* [2166] */
    (xdc_Char)0x20,  /* [2167] */
    (xdc_Char)0x73,  /* [2168] */
    (xdc_Char)0x74,  /* [2169] */
    (xdc_Char)0x61,  /* [2170] */
    (xdc_Char)0x74,  /* [2171] */
    (xdc_Char)0x69,  /* [2172] */
    (xdc_Char)0x63,  /* [2173] */
    (xdc_Char)0x20,  /* [2174] */
    (xdc_Char)0x6d,  /* [2175] */
    (xdc_Char)0x73,  /* [2176] */
    (xdc_Char)0x67,  /* [2177] */
    (xdc_Char)0x0,  /* [2178] */
    (xdc_Char)0x41,  /* [2179] */
    (xdc_Char)0x5f,  /* [2180] */
    (xdc_Char)0x69,  /* [2181] */
    (xdc_Char)0x6e,  /* [2182] */
    (xdc_Char)0x76,  /* [2183] */
    (xdc_Char)0x61,  /* [2184] */
    (xdc_Char)0x6c,  /* [2185] */
    (xdc_Char)0x69,  /* [2186] */
    (xdc_Char)0x64,  /* [2187] */
    (xdc_Char)0x4d,  /* [2188] */
    (xdc_Char)0x73,  /* [2189] */
    (xdc_Char)0x67,  /* [2190] */
    (xdc_Char)0x3a,  /* [2191] */
    (xdc_Char)0x20,  /* [2192] */
    (xdc_Char)0x49,  /* [2193] */
    (xdc_Char)0x6e,  /* [2194] */
    (xdc_Char)0x76,  /* [2195] */
    (xdc_Char)0x61,  /* [2196] */
    (xdc_Char)0x6c,  /* [2197] */
    (xdc_Char)0x69,  /* [2198] */
    (xdc_Char)0x64,  /* [2199] */
    (xdc_Char)0x20,  /* [2200] */
    (xdc_Char)0x6d,  /* [2201] */
    (xdc_Char)0x65,  /* [2202] */
    (xdc_Char)0x73,  /* [2203] */
    (xdc_Char)0x73,  /* [2204] */
    (xdc_Char)0x61,  /* [2205] */
    (xdc_Char)0x67,  /* [2206] */
    (xdc_Char)0x65,  /* [2207] */
    (xdc_Char)0x0,  /* [2208] */
    (xdc_Char)0x41,  /* [2209] */
    (xdc_Char)0x5f,  /* [2210] */
    (xdc_Char)0x69,  /* [2211] */
    (xdc_Char)0x6e,  /* [2212] */
    (xdc_Char)0x76,  /* [2213] */
    (xdc_Char)0x61,  /* [2214] */
    (xdc_Char)0x6c,  /* [2215] */
    (xdc_Char)0x69,  /* [2216] */
    (xdc_Char)0x64,  /* [2217] */
    (xdc_Char)0x51,  /* [2218] */
    (xdc_Char)0x75,  /* [2219] */
    (xdc_Char)0x65,  /* [2220] */
    (xdc_Char)0x75,  /* [2221] */
    (xdc_Char)0x65,  /* [2222] */
    (xdc_Char)0x49,  /* [2223] */
    (xdc_Char)0x64,  /* [2224] */
    (xdc_Char)0x3a,  /* [2225] */
    (xdc_Char)0x20,  /* [2226] */
    (xdc_Char)0x49,  /* [2227] */
    (xdc_Char)0x6e,  /* [2228] */
    (xdc_Char)0x76,  /* [2229] */
    (xdc_Char)0x61,  /* [2230] */
    (xdc_Char)0x6c,  /* [2231] */
    (xdc_Char)0x69,  /* [2232] */
    (xdc_Char)0x64,  /* [2233] */
    (xdc_Char)0x20,  /* [2234] */
    (xdc_Char)0x71,  /* [2235] */
    (xdc_Char)0x75,  /* [2236] */
    (xdc_Char)0x65,  /* [2237] */
    (xdc_Char)0x75,  /* [2238] */
    (xdc_Char)0x65,  /* [2239] */
    (xdc_Char)0x49,  /* [2240] */
    (xdc_Char)0x64,  /* [2241] */
    (xdc_Char)0x20,  /* [2242] */
    (xdc_Char)0x69,  /* [2243] */
    (xdc_Char)0x73,  /* [2244] */
    (xdc_Char)0x20,  /* [2245] */
    (xdc_Char)0x75,  /* [2246] */
    (xdc_Char)0x73,  /* [2247] */
    (xdc_Char)0x65,  /* [2248] */
    (xdc_Char)0x64,  /* [2249] */
    (xdc_Char)0x0,  /* [2250] */
    (xdc_Char)0x41,  /* [2251] */
    (xdc_Char)0x5f,  /* [2252] */
    (xdc_Char)0x68,  /* [2253] */
    (xdc_Char)0x65,  /* [2254] */
    (xdc_Char)0x61,  /* [2255] */
    (xdc_Char)0x70,  /* [2256] */
    (xdc_Char)0x49,  /* [2257] */
    (xdc_Char)0x64,  /* [2258] */
    (xdc_Char)0x49,  /* [2259] */
    (xdc_Char)0x6e,  /* [2260] */
    (xdc_Char)0x76,  /* [2261] */
    (xdc_Char)0x61,  /* [2262] */
    (xdc_Char)0x6c,  /* [2263] */
    (xdc_Char)0x69,  /* [2264] */
    (xdc_Char)0x64,  /* [2265] */
    (xdc_Char)0x3a,  /* [2266] */
    (xdc_Char)0x20,  /* [2267] */
    (xdc_Char)0x68,  /* [2268] */
    (xdc_Char)0x65,  /* [2269] */
    (xdc_Char)0x61,  /* [2270] */
    (xdc_Char)0x70,  /* [2271] */
    (xdc_Char)0x49,  /* [2272] */
    (xdc_Char)0x64,  /* [2273] */
    (xdc_Char)0x20,  /* [2274] */
    (xdc_Char)0x69,  /* [2275] */
    (xdc_Char)0x73,  /* [2276] */
    (xdc_Char)0x20,  /* [2277] */
    (xdc_Char)0x69,  /* [2278] */
    (xdc_Char)0x6e,  /* [2279] */
    (xdc_Char)0x76,  /* [2280] */
    (xdc_Char)0x61,  /* [2281] */
    (xdc_Char)0x6c,  /* [2282] */
    (xdc_Char)0x69,  /* [2283] */
    (xdc_Char)0x64,  /* [2284] */
    (xdc_Char)0x0,  /* [2285] */
    (xdc_Char)0x41,  /* [2286] */
    (xdc_Char)0x5f,  /* [2287] */
    (xdc_Char)0x70,  /* [2288] */
    (xdc_Char)0x72,  /* [2289] */
    (xdc_Char)0x6f,  /* [2290] */
    (xdc_Char)0x63,  /* [2291] */
    (xdc_Char)0x49,  /* [2292] */
    (xdc_Char)0x64,  /* [2293] */
    (xdc_Char)0x49,  /* [2294] */
    (xdc_Char)0x6e,  /* [2295] */
    (xdc_Char)0x76,  /* [2296] */
    (xdc_Char)0x61,  /* [2297] */
    (xdc_Char)0x6c,  /* [2298] */
    (xdc_Char)0x69,  /* [2299] */
    (xdc_Char)0x64,  /* [2300] */
    (xdc_Char)0x3a,  /* [2301] */
    (xdc_Char)0x20,  /* [2302] */
    (xdc_Char)0x70,  /* [2303] */
    (xdc_Char)0x72,  /* [2304] */
    (xdc_Char)0x6f,  /* [2305] */
    (xdc_Char)0x63,  /* [2306] */
    (xdc_Char)0x49,  /* [2307] */
    (xdc_Char)0x64,  /* [2308] */
    (xdc_Char)0x20,  /* [2309] */
    (xdc_Char)0x69,  /* [2310] */
    (xdc_Char)0x73,  /* [2311] */
    (xdc_Char)0x20,  /* [2312] */
    (xdc_Char)0x69,  /* [2313] */
    (xdc_Char)0x6e,  /* [2314] */
    (xdc_Char)0x76,  /* [2315] */
    (xdc_Char)0x61,  /* [2316] */
    (xdc_Char)0x6c,  /* [2317] */
    (xdc_Char)0x69,  /* [2318] */
    (xdc_Char)0x64,  /* [2319] */
    (xdc_Char)0x0,  /* [2320] */
    (xdc_Char)0x41,  /* [2321] */
    (xdc_Char)0x5f,  /* [2322] */
    (xdc_Char)0x69,  /* [2323] */
    (xdc_Char)0x6e,  /* [2324] */
    (xdc_Char)0x76,  /* [2325] */
    (xdc_Char)0x61,  /* [2326] */
    (xdc_Char)0x6c,  /* [2327] */
    (xdc_Char)0x69,  /* [2328] */
    (xdc_Char)0x64,  /* [2329] */
    (xdc_Char)0x4f,  /* [2330] */
    (xdc_Char)0x62,  /* [2331] */
    (xdc_Char)0x6a,  /* [2332] */
    (xdc_Char)0x3a,  /* [2333] */
    (xdc_Char)0x20,  /* [2334] */
    (xdc_Char)0x61,  /* [2335] */
    (xdc_Char)0x6e,  /* [2336] */
    (xdc_Char)0x20,  /* [2337] */
    (xdc_Char)0x69,  /* [2338] */
    (xdc_Char)0x6e,  /* [2339] */
    (xdc_Char)0x76,  /* [2340] */
    (xdc_Char)0x61,  /* [2341] */
    (xdc_Char)0x6c,  /* [2342] */
    (xdc_Char)0x69,  /* [2343] */
    (xdc_Char)0x64,  /* [2344] */
    (xdc_Char)0x20,  /* [2345] */
    (xdc_Char)0x6f,  /* [2346] */
    (xdc_Char)0x62,  /* [2347] */
    (xdc_Char)0x6a,  /* [2348] */
    (xdc_Char)0x20,  /* [2349] */
    (xdc_Char)0x69,  /* [2350] */
    (xdc_Char)0x73,  /* [2351] */
    (xdc_Char)0x20,  /* [2352] */
    (xdc_Char)0x75,  /* [2353] */
    (xdc_Char)0x73,  /* [2354] */
    (xdc_Char)0x65,  /* [2355] */
    (xdc_Char)0x64,  /* [2356] */
    (xdc_Char)0x0,  /* [2357] */
    (xdc_Char)0x41,  /* [2358] */
    (xdc_Char)0x5f,  /* [2359] */
    (xdc_Char)0x69,  /* [2360] */
    (xdc_Char)0x6e,  /* [2361] */
    (xdc_Char)0x76,  /* [2362] */
    (xdc_Char)0x61,  /* [2363] */
    (xdc_Char)0x6c,  /* [2364] */
    (xdc_Char)0x69,  /* [2365] */
    (xdc_Char)0x64,  /* [2366] */
    (xdc_Char)0x50,  /* [2367] */
    (xdc_Char)0x61,  /* [2368] */
    (xdc_Char)0x72,  /* [2369] */
    (xdc_Char)0x61,  /* [2370] */
    (xdc_Char)0x6d,  /* [2371] */
    (xdc_Char)0x3a,  /* [2372] */
    (xdc_Char)0x20,  /* [2373] */
    (xdc_Char)0x61,  /* [2374] */
    (xdc_Char)0x6e,  /* [2375] */
    (xdc_Char)0x20,  /* [2376] */
    (xdc_Char)0x69,  /* [2377] */
    (xdc_Char)0x6e,  /* [2378] */
    (xdc_Char)0x76,  /* [2379] */
    (xdc_Char)0x61,  /* [2380] */
    (xdc_Char)0x6c,  /* [2381] */
    (xdc_Char)0x69,  /* [2382] */
    (xdc_Char)0x64,  /* [2383] */
    (xdc_Char)0x20,  /* [2384] */
    (xdc_Char)0x70,  /* [2385] */
    (xdc_Char)0x61,  /* [2386] */
    (xdc_Char)0x72,  /* [2387] */
    (xdc_Char)0x61,  /* [2388] */
    (xdc_Char)0x6d,  /* [2389] */
    (xdc_Char)0x65,  /* [2390] */
    (xdc_Char)0x74,  /* [2391] */
    (xdc_Char)0x65,  /* [2392] */
    (xdc_Char)0x72,  /* [2393] */
    (xdc_Char)0x20,  /* [2394] */
    (xdc_Char)0x77,  /* [2395] */
    (xdc_Char)0x61,  /* [2396] */
    (xdc_Char)0x73,  /* [2397] */
    (xdc_Char)0x20,  /* [2398] */
    (xdc_Char)0x70,  /* [2399] */
    (xdc_Char)0x61,  /* [2400] */
    (xdc_Char)0x73,  /* [2401] */
    (xdc_Char)0x73,  /* [2402] */
    (xdc_Char)0x65,  /* [2403] */
    (xdc_Char)0x64,  /* [2404] */
    (xdc_Char)0x20,  /* [2405] */
    (xdc_Char)0x69,  /* [2406] */
    (xdc_Char)0x6e,  /* [2407] */
    (xdc_Char)0x0,  /* [2408] */
    (xdc_Char)0x41,  /* [2409] */
    (xdc_Char)0x5f,  /* [2410] */
    (xdc_Char)0x75,  /* [2411] */
    (xdc_Char)0x6e,  /* [2412] */
    (xdc_Char)0x72,  /* [2413] */
    (xdc_Char)0x65,  /* [2414] */
    (xdc_Char)0x67,  /* [2415] */
    (xdc_Char)0x69,  /* [2416] */
    (xdc_Char)0x73,  /* [2417] */
    (xdc_Char)0x74,  /* [2418] */
    (xdc_Char)0x65,  /* [2419] */
    (xdc_Char)0x72,  /* [2420] */
    (xdc_Char)0x65,  /* [2421] */
    (xdc_Char)0x64,  /* [2422] */
    (xdc_Char)0x54,  /* [2423] */
    (xdc_Char)0x72,  /* [2424] */
    (xdc_Char)0x61,  /* [2425] */
    (xdc_Char)0x6e,  /* [2426] */
    (xdc_Char)0x73,  /* [2427] */
    (xdc_Char)0x70,  /* [2428] */
    (xdc_Char)0x6f,  /* [2429] */
    (xdc_Char)0x72,  /* [2430] */
    (xdc_Char)0x74,  /* [2431] */
    (xdc_Char)0x3a,  /* [2432] */
    (xdc_Char)0x20,  /* [2433] */
    (xdc_Char)0x74,  /* [2434] */
    (xdc_Char)0x72,  /* [2435] */
    (xdc_Char)0x61,  /* [2436] */
    (xdc_Char)0x6e,  /* [2437] */
    (xdc_Char)0x73,  /* [2438] */
    (xdc_Char)0x70,  /* [2439] */
    (xdc_Char)0x6f,  /* [2440] */
    (xdc_Char)0x72,  /* [2441] */
    (xdc_Char)0x74,  /* [2442] */
    (xdc_Char)0x20,  /* [2443] */
    (xdc_Char)0x69,  /* [2444] */
    (xdc_Char)0x73,  /* [2445] */
    (xdc_Char)0x20,  /* [2446] */
    (xdc_Char)0x6e,  /* [2447] */
    (xdc_Char)0x6f,  /* [2448] */
    (xdc_Char)0x74,  /* [2449] */
    (xdc_Char)0x20,  /* [2450] */
    (xdc_Char)0x72,  /* [2451] */
    (xdc_Char)0x65,  /* [2452] */
    (xdc_Char)0x67,  /* [2453] */
    (xdc_Char)0x69,  /* [2454] */
    (xdc_Char)0x73,  /* [2455] */
    (xdc_Char)0x74,  /* [2456] */
    (xdc_Char)0x65,  /* [2457] */
    (xdc_Char)0x72,  /* [2458] */
    (xdc_Char)0x65,  /* [2459] */
    (xdc_Char)0x64,  /* [2460] */
    (xdc_Char)0x0,  /* [2461] */
    (xdc_Char)0x41,  /* [2462] */
    (xdc_Char)0x5f,  /* [2463] */
    (xdc_Char)0x69,  /* [2464] */
    (xdc_Char)0x6e,  /* [2465] */
    (xdc_Char)0x76,  /* [2466] */
    (xdc_Char)0x61,  /* [2467] */
    (xdc_Char)0x6c,  /* [2468] */
    (xdc_Char)0x69,  /* [2469] */
    (xdc_Char)0x64,  /* [2470] */
    (xdc_Char)0x55,  /* [2471] */
    (xdc_Char)0x6e,  /* [2472] */
    (xdc_Char)0x62,  /* [2473] */
    (xdc_Char)0x6c,  /* [2474] */
    (xdc_Char)0x6f,  /* [2475] */
    (xdc_Char)0x63,  /* [2476] */
    (xdc_Char)0x6b,  /* [2477] */
    (xdc_Char)0x3a,  /* [2478] */
    (xdc_Char)0x20,  /* [2479] */
    (xdc_Char)0x54,  /* [2480] */
    (xdc_Char)0x72,  /* [2481] */
    (xdc_Char)0x79,  /* [2482] */
    (xdc_Char)0x69,  /* [2483] */
    (xdc_Char)0x6e,  /* [2484] */
    (xdc_Char)0x67,  /* [2485] */
    (xdc_Char)0x20,  /* [2486] */
    (xdc_Char)0x74,  /* [2487] */
    (xdc_Char)0x6f,  /* [2488] */
    (xdc_Char)0x20,  /* [2489] */
    (xdc_Char)0x75,  /* [2490] */
    (xdc_Char)0x6e,  /* [2491] */
    (xdc_Char)0x62,  /* [2492] */
    (xdc_Char)0x6c,  /* [2493] */
    (xdc_Char)0x6f,  /* [2494] */
    (xdc_Char)0x63,  /* [2495] */
    (xdc_Char)0x6b,  /* [2496] */
    (xdc_Char)0x20,  /* [2497] */
    (xdc_Char)0x61,  /* [2498] */
    (xdc_Char)0x20,  /* [2499] */
    (xdc_Char)0x72,  /* [2500] */
    (xdc_Char)0x65,  /* [2501] */
    (xdc_Char)0x6d,  /* [2502] */
    (xdc_Char)0x6f,  /* [2503] */
    (xdc_Char)0x74,  /* [2504] */
    (xdc_Char)0x65,  /* [2505] */
    (xdc_Char)0x20,  /* [2506] */
    (xdc_Char)0x4d,  /* [2507] */
    (xdc_Char)0x65,  /* [2508] */
    (xdc_Char)0x73,  /* [2509] */
    (xdc_Char)0x73,  /* [2510] */
    (xdc_Char)0x61,  /* [2511] */
    (xdc_Char)0x67,  /* [2512] */
    (xdc_Char)0x65,  /* [2513] */
    (xdc_Char)0x51,  /* [2514] */
    (xdc_Char)0x20,  /* [2515] */
    (xdc_Char)0x6f,  /* [2516] */
    (xdc_Char)0x72,  /* [2517] */
    (xdc_Char)0x20,  /* [2518] */
    (xdc_Char)0x61,  /* [2519] */
    (xdc_Char)0x20,  /* [2520] */
    (xdc_Char)0x71,  /* [2521] */
    (xdc_Char)0x75,  /* [2522] */
    (xdc_Char)0x65,  /* [2523] */
    (xdc_Char)0x75,  /* [2524] */
    (xdc_Char)0x65,  /* [2525] */
    (xdc_Char)0x20,  /* [2526] */
    (xdc_Char)0x77,  /* [2527] */
    (xdc_Char)0x69,  /* [2528] */
    (xdc_Char)0x74,  /* [2529] */
    (xdc_Char)0x68,  /* [2530] */
    (xdc_Char)0x20,  /* [2531] */
    (xdc_Char)0x6e,  /* [2532] */
    (xdc_Char)0x6f,  /* [2533] */
    (xdc_Char)0x6e,  /* [2534] */
    (xdc_Char)0x2d,  /* [2535] */
    (xdc_Char)0x62,  /* [2536] */
    (xdc_Char)0x6c,  /* [2537] */
    (xdc_Char)0x6f,  /* [2538] */
    (xdc_Char)0x63,  /* [2539] */
    (xdc_Char)0x6b,  /* [2540] */
    (xdc_Char)0x69,  /* [2541] */
    (xdc_Char)0x6e,  /* [2542] */
    (xdc_Char)0x67,  /* [2543] */
    (xdc_Char)0x20,  /* [2544] */
    (xdc_Char)0x73,  /* [2545] */
    (xdc_Char)0x79,  /* [2546] */
    (xdc_Char)0x6e,  /* [2547] */
    (xdc_Char)0x63,  /* [2548] */
    (xdc_Char)0x68,  /* [2549] */
    (xdc_Char)0x72,  /* [2550] */
    (xdc_Char)0x6f,  /* [2551] */
    (xdc_Char)0x6e,  /* [2552] */
    (xdc_Char)0x69,  /* [2553] */
    (xdc_Char)0x7a,  /* [2554] */
    (xdc_Char)0x65,  /* [2555] */
    (xdc_Char)0x72,  /* [2556] */
    (xdc_Char)0x0,  /* [2557] */
    (xdc_Char)0x41,  /* [2558] */
    (xdc_Char)0x5f,  /* [2559] */
    (xdc_Char)0x69,  /* [2560] */
    (xdc_Char)0x64,  /* [2561] */
    (xdc_Char)0x54,  /* [2562] */
    (xdc_Char)0x6f,  /* [2563] */
    (xdc_Char)0x6f,  /* [2564] */
    (xdc_Char)0x4c,  /* [2565] */
    (xdc_Char)0x61,  /* [2566] */
    (xdc_Char)0x72,  /* [2567] */
    (xdc_Char)0x67,  /* [2568] */
    (xdc_Char)0x65,  /* [2569] */
    (xdc_Char)0x3a,  /* [2570] */
    (xdc_Char)0x20,  /* [2571] */
    (xdc_Char)0x69,  /* [2572] */
    (xdc_Char)0x64,  /* [2573] */
    (xdc_Char)0x20,  /* [2574] */
    (xdc_Char)0x63,  /* [2575] */
    (xdc_Char)0x61,  /* [2576] */
    (xdc_Char)0x6e,  /* [2577] */
    (xdc_Char)0x6e,  /* [2578] */
    (xdc_Char)0x6f,  /* [2579] */
    (xdc_Char)0x74,  /* [2580] */
    (xdc_Char)0x20,  /* [2581] */
    (xdc_Char)0x62,  /* [2582] */
    (xdc_Char)0x65,  /* [2583] */
    (xdc_Char)0x20,  /* [2584] */
    (xdc_Char)0x6c,  /* [2585] */
    (xdc_Char)0x61,  /* [2586] */
    (xdc_Char)0x72,  /* [2587] */
    (xdc_Char)0x67,  /* [2588] */
    (xdc_Char)0x65,  /* [2589] */
    (xdc_Char)0x72,  /* [2590] */
    (xdc_Char)0x20,  /* [2591] */
    (xdc_Char)0x74,  /* [2592] */
    (xdc_Char)0x68,  /* [2593] */
    (xdc_Char)0x61,  /* [2594] */
    (xdc_Char)0x6e,  /* [2595] */
    (xdc_Char)0x20,  /* [2596] */
    (xdc_Char)0x6e,  /* [2597] */
    (xdc_Char)0x75,  /* [2598] */
    (xdc_Char)0x6d,  /* [2599] */
    (xdc_Char)0x45,  /* [2600] */
    (xdc_Char)0x6e,  /* [2601] */
    (xdc_Char)0x74,  /* [2602] */
    (xdc_Char)0x72,  /* [2603] */
    (xdc_Char)0x69,  /* [2604] */
    (xdc_Char)0x65,  /* [2605] */
    (xdc_Char)0x73,  /* [2606] */
    (xdc_Char)0x0,  /* [2607] */
    (xdc_Char)0x41,  /* [2608] */
    (xdc_Char)0x5f,  /* [2609] */
    (xdc_Char)0x61,  /* [2610] */
    (xdc_Char)0x64,  /* [2611] */
    (xdc_Char)0x64,  /* [2612] */
    (xdc_Char)0x72,  /* [2613] */
    (xdc_Char)0x4f,  /* [2614] */
    (xdc_Char)0x75,  /* [2615] */
    (xdc_Char)0x74,  /* [2616] */
    (xdc_Char)0x4f,  /* [2617] */
    (xdc_Char)0x66,  /* [2618] */
    (xdc_Char)0x52,  /* [2619] */
    (xdc_Char)0x61,  /* [2620] */
    (xdc_Char)0x6e,  /* [2621] */
    (xdc_Char)0x67,  /* [2622] */
    (xdc_Char)0x65,  /* [2623] */
    (xdc_Char)0x3a,  /* [2624] */
    (xdc_Char)0x20,  /* [2625] */
    (xdc_Char)0x41,  /* [2626] */
    (xdc_Char)0x64,  /* [2627] */
    (xdc_Char)0x64,  /* [2628] */
    (xdc_Char)0x72,  /* [2629] */
    (xdc_Char)0x65,  /* [2630] */
    (xdc_Char)0x73,  /* [2631] */
    (xdc_Char)0x73,  /* [2632] */
    (xdc_Char)0x20,  /* [2633] */
    (xdc_Char)0x69,  /* [2634] */
    (xdc_Char)0x73,  /* [2635] */
    (xdc_Char)0x20,  /* [2636] */
    (xdc_Char)0x6f,  /* [2637] */
    (xdc_Char)0x75,  /* [2638] */
    (xdc_Char)0x74,  /* [2639] */
    (xdc_Char)0x20,  /* [2640] */
    (xdc_Char)0x6f,  /* [2641] */
    (xdc_Char)0x66,  /* [2642] */
    (xdc_Char)0x20,  /* [2643] */
    (xdc_Char)0x72,  /* [2644] */
    (xdc_Char)0x65,  /* [2645] */
    (xdc_Char)0x67,  /* [2646] */
    (xdc_Char)0x69,  /* [2647] */
    (xdc_Char)0x6f,  /* [2648] */
    (xdc_Char)0x6e,  /* [2649] */
    (xdc_Char)0x20,  /* [2650] */
    (xdc_Char)0x69,  /* [2651] */
    (xdc_Char)0x64,  /* [2652] */
    (xdc_Char)0x27,  /* [2653] */
    (xdc_Char)0x73,  /* [2654] */
    (xdc_Char)0x20,  /* [2655] */
    (xdc_Char)0x72,  /* [2656] */
    (xdc_Char)0x61,  /* [2657] */
    (xdc_Char)0x6e,  /* [2658] */
    (xdc_Char)0x67,  /* [2659] */
    (xdc_Char)0x65,  /* [2660] */
    (xdc_Char)0x0,  /* [2661] */
    (xdc_Char)0x41,  /* [2662] */
    (xdc_Char)0x5f,  /* [2663] */
    (xdc_Char)0x72,  /* [2664] */
    (xdc_Char)0x65,  /* [2665] */
    (xdc_Char)0x67,  /* [2666] */
    (xdc_Char)0x69,  /* [2667] */
    (xdc_Char)0x6f,  /* [2668] */
    (xdc_Char)0x6e,  /* [2669] */
    (xdc_Char)0x30,  /* [2670] */
    (xdc_Char)0x43,  /* [2671] */
    (xdc_Char)0x6c,  /* [2672] */
    (xdc_Char)0x65,  /* [2673] */
    (xdc_Char)0x61,  /* [2674] */
    (xdc_Char)0x72,  /* [2675] */
    (xdc_Char)0x3a,  /* [2676] */
    (xdc_Char)0x20,  /* [2677] */
    (xdc_Char)0x52,  /* [2678] */
    (xdc_Char)0x65,  /* [2679] */
    (xdc_Char)0x67,  /* [2680] */
    (xdc_Char)0x69,  /* [2681] */
    (xdc_Char)0x6f,  /* [2682] */
    (xdc_Char)0x6e,  /* [2683] */
    (xdc_Char)0x20,  /* [2684] */
    (xdc_Char)0x30,  /* [2685] */
    (xdc_Char)0x20,  /* [2686] */
    (xdc_Char)0x63,  /* [2687] */
    (xdc_Char)0x61,  /* [2688] */
    (xdc_Char)0x6e,  /* [2689] */
    (xdc_Char)0x6e,  /* [2690] */
    (xdc_Char)0x6f,  /* [2691] */
    (xdc_Char)0x74,  /* [2692] */
    (xdc_Char)0x20,  /* [2693] */
    (xdc_Char)0x62,  /* [2694] */
    (xdc_Char)0x65,  /* [2695] */
    (xdc_Char)0x20,  /* [2696] */
    (xdc_Char)0x63,  /* [2697] */
    (xdc_Char)0x6c,  /* [2698] */
    (xdc_Char)0x65,  /* [2699] */
    (xdc_Char)0x61,  /* [2700] */
    (xdc_Char)0x72,  /* [2701] */
    (xdc_Char)0x65,  /* [2702] */
    (xdc_Char)0x64,  /* [2703] */
    (xdc_Char)0x0,  /* [2704] */
    (xdc_Char)0x41,  /* [2705] */
    (xdc_Char)0x5f,  /* [2706] */
    (xdc_Char)0x72,  /* [2707] */
    (xdc_Char)0x65,  /* [2708] */
    (xdc_Char)0x67,  /* [2709] */
    (xdc_Char)0x69,  /* [2710] */
    (xdc_Char)0x6f,  /* [2711] */
    (xdc_Char)0x6e,  /* [2712] */
    (xdc_Char)0x30,  /* [2713] */
    (xdc_Char)0x49,  /* [2714] */
    (xdc_Char)0x6e,  /* [2715] */
    (xdc_Char)0x76,  /* [2716] */
    (xdc_Char)0x61,  /* [2717] */
    (xdc_Char)0x6c,  /* [2718] */
    (xdc_Char)0x69,  /* [2719] */
    (xdc_Char)0x64,  /* [2720] */
    (xdc_Char)0x3a,  /* [2721] */
    (xdc_Char)0x20,  /* [2722] */
    (xdc_Char)0x52,  /* [2723] */
    (xdc_Char)0x65,  /* [2724] */
    (xdc_Char)0x67,  /* [2725] */
    (xdc_Char)0x69,  /* [2726] */
    (xdc_Char)0x6f,  /* [2727] */
    (xdc_Char)0x6e,  /* [2728] */
    (xdc_Char)0x20,  /* [2729] */
    (xdc_Char)0x7a,  /* [2730] */
    (xdc_Char)0x65,  /* [2731] */
    (xdc_Char)0x72,  /* [2732] */
    (xdc_Char)0x6f,  /* [2733] */
    (xdc_Char)0x20,  /* [2734] */
    (xdc_Char)0x69,  /* [2735] */
    (xdc_Char)0x73,  /* [2736] */
    (xdc_Char)0x20,  /* [2737] */
    (xdc_Char)0x69,  /* [2738] */
    (xdc_Char)0x6e,  /* [2739] */
    (xdc_Char)0x76,  /* [2740] */
    (xdc_Char)0x61,  /* [2741] */
    (xdc_Char)0x6c,  /* [2742] */
    (xdc_Char)0x69,  /* [2743] */
    (xdc_Char)0x64,  /* [2744] */
    (xdc_Char)0x0,  /* [2745] */
    (xdc_Char)0x41,  /* [2746] */
    (xdc_Char)0x5f,  /* [2747] */
    (xdc_Char)0x72,  /* [2748] */
    (xdc_Char)0x65,  /* [2749] */
    (xdc_Char)0x67,  /* [2750] */
    (xdc_Char)0x69,  /* [2751] */
    (xdc_Char)0x6f,  /* [2752] */
    (xdc_Char)0x6e,  /* [2753] */
    (xdc_Char)0x49,  /* [2754] */
    (xdc_Char)0x6e,  /* [2755] */
    (xdc_Char)0x76,  /* [2756] */
    (xdc_Char)0x61,  /* [2757] */
    (xdc_Char)0x6c,  /* [2758] */
    (xdc_Char)0x69,  /* [2759] */
    (xdc_Char)0x64,  /* [2760] */
    (xdc_Char)0x3a,  /* [2761] */
    (xdc_Char)0x20,  /* [2762] */
    (xdc_Char)0x52,  /* [2763] */
    (xdc_Char)0x65,  /* [2764] */
    (xdc_Char)0x67,  /* [2765] */
    (xdc_Char)0x69,  /* [2766] */
    (xdc_Char)0x6f,  /* [2767] */
    (xdc_Char)0x6e,  /* [2768] */
    (xdc_Char)0x20,  /* [2769] */
    (xdc_Char)0x69,  /* [2770] */
    (xdc_Char)0x73,  /* [2771] */
    (xdc_Char)0x20,  /* [2772] */
    (xdc_Char)0x69,  /* [2773] */
    (xdc_Char)0x6e,  /* [2774] */
    (xdc_Char)0x76,  /* [2775] */
    (xdc_Char)0x61,  /* [2776] */
    (xdc_Char)0x6c,  /* [2777] */
    (xdc_Char)0x69,  /* [2778] */
    (xdc_Char)0x64,  /* [2779] */
    (xdc_Char)0x0,  /* [2780] */
    (xdc_Char)0x41,  /* [2781] */
    (xdc_Char)0x5f,  /* [2782] */
    (xdc_Char)0x72,  /* [2783] */
    (xdc_Char)0x65,  /* [2784] */
    (xdc_Char)0x73,  /* [2785] */
    (xdc_Char)0x65,  /* [2786] */
    (xdc_Char)0x72,  /* [2787] */
    (xdc_Char)0x76,  /* [2788] */
    (xdc_Char)0x65,  /* [2789] */
    (xdc_Char)0x54,  /* [2790] */
    (xdc_Char)0x6f,  /* [2791] */
    (xdc_Char)0x6f,  /* [2792] */
    (xdc_Char)0x4d,  /* [2793] */
    (xdc_Char)0x75,  /* [2794] */
    (xdc_Char)0x63,  /* [2795] */
    (xdc_Char)0x68,  /* [2796] */
    (xdc_Char)0x3a,  /* [2797] */
    (xdc_Char)0x20,  /* [2798] */
    (xdc_Char)0x54,  /* [2799] */
    (xdc_Char)0x72,  /* [2800] */
    (xdc_Char)0x79,  /* [2801] */
    (xdc_Char)0x69,  /* [2802] */
    (xdc_Char)0x6e,  /* [2803] */
    (xdc_Char)0x67,  /* [2804] */
    (xdc_Char)0x20,  /* [2805] */
    (xdc_Char)0x74,  /* [2806] */
    (xdc_Char)0x6f,  /* [2807] */
    (xdc_Char)0x20,  /* [2808] */
    (xdc_Char)0x72,  /* [2809] */
    (xdc_Char)0x65,  /* [2810] */
    (xdc_Char)0x73,  /* [2811] */
    (xdc_Char)0x65,  /* [2812] */
    (xdc_Char)0x72,  /* [2813] */
    (xdc_Char)0x76,  /* [2814] */
    (xdc_Char)0x65,  /* [2815] */
    (xdc_Char)0x20,  /* [2816] */
    (xdc_Char)0x74,  /* [2817] */
    (xdc_Char)0x6f,  /* [2818] */
    (xdc_Char)0x6f,  /* [2819] */
    (xdc_Char)0x20,  /* [2820] */
    (xdc_Char)0x6d,  /* [2821] */
    (xdc_Char)0x75,  /* [2822] */
    (xdc_Char)0x63,  /* [2823] */
    (xdc_Char)0x68,  /* [2824] */
    (xdc_Char)0x20,  /* [2825] */
    (xdc_Char)0x6d,  /* [2826] */
    (xdc_Char)0x65,  /* [2827] */
    (xdc_Char)0x6d,  /* [2828] */
    (xdc_Char)0x6f,  /* [2829] */
    (xdc_Char)0x72,  /* [2830] */
    (xdc_Char)0x79,  /* [2831] */
    (xdc_Char)0x0,  /* [2832] */
    (xdc_Char)0x41,  /* [2833] */
    (xdc_Char)0x5f,  /* [2834] */
    (xdc_Char)0x63,  /* [2835] */
    (xdc_Char)0x61,  /* [2836] */
    (xdc_Char)0x63,  /* [2837] */
    (xdc_Char)0x68,  /* [2838] */
    (xdc_Char)0x65,  /* [2839] */
    (xdc_Char)0x4c,  /* [2840] */
    (xdc_Char)0x69,  /* [2841] */
    (xdc_Char)0x6e,  /* [2842] */
    (xdc_Char)0x65,  /* [2843] */
    (xdc_Char)0x53,  /* [2844] */
    (xdc_Char)0x69,  /* [2845] */
    (xdc_Char)0x7a,  /* [2846] */
    (xdc_Char)0x65,  /* [2847] */
    (xdc_Char)0x49,  /* [2848] */
    (xdc_Char)0x73,  /* [2849] */
    (xdc_Char)0x5a,  /* [2850] */
    (xdc_Char)0x65,  /* [2851] */
    (xdc_Char)0x72,  /* [2852] */
    (xdc_Char)0x6f,  /* [2853] */
    (xdc_Char)0x3a,  /* [2854] */
    (xdc_Char)0x20,  /* [2855] */
    (xdc_Char)0x63,  /* [2856] */
    (xdc_Char)0x61,  /* [2857] */
    (xdc_Char)0x63,  /* [2858] */
    (xdc_Char)0x68,  /* [2859] */
    (xdc_Char)0x65,  /* [2860] */
    (xdc_Char)0x20,  /* [2861] */
    (xdc_Char)0x6c,  /* [2862] */
    (xdc_Char)0x69,  /* [2863] */
    (xdc_Char)0x6e,  /* [2864] */
    (xdc_Char)0x65,  /* [2865] */
    (xdc_Char)0x20,  /* [2866] */
    (xdc_Char)0x73,  /* [2867] */
    (xdc_Char)0x69,  /* [2868] */
    (xdc_Char)0x7a,  /* [2869] */
    (xdc_Char)0x65,  /* [2870] */
    (xdc_Char)0x20,  /* [2871] */
    (xdc_Char)0x63,  /* [2872] */
    (xdc_Char)0x61,  /* [2873] */
    (xdc_Char)0x6e,  /* [2874] */
    (xdc_Char)0x6e,  /* [2875] */
    (xdc_Char)0x6f,  /* [2876] */
    (xdc_Char)0x74,  /* [2877] */
    (xdc_Char)0x20,  /* [2878] */
    (xdc_Char)0x62,  /* [2879] */
    (xdc_Char)0x65,  /* [2880] */
    (xdc_Char)0x20,  /* [2881] */
    (xdc_Char)0x7a,  /* [2882] */
    (xdc_Char)0x65,  /* [2883] */
    (xdc_Char)0x72,  /* [2884] */
    (xdc_Char)0x6f,  /* [2885] */
    (xdc_Char)0x0,  /* [2886] */
    (xdc_Char)0x41,  /* [2887] */
    (xdc_Char)0x5f,  /* [2888] */
    (xdc_Char)0x6f,  /* [2889] */
    (xdc_Char)0x76,  /* [2890] */
    (xdc_Char)0x65,  /* [2891] */
    (xdc_Char)0x72,  /* [2892] */
    (xdc_Char)0x6c,  /* [2893] */
    (xdc_Char)0x61,  /* [2894] */
    (xdc_Char)0x70,  /* [2895] */
    (xdc_Char)0x3a,  /* [2896] */
    (xdc_Char)0x20,  /* [2897] */
    (xdc_Char)0x53,  /* [2898] */
    (xdc_Char)0x68,  /* [2899] */
    (xdc_Char)0x61,  /* [2900] */
    (xdc_Char)0x72,  /* [2901] */
    (xdc_Char)0x65,  /* [2902] */
    (xdc_Char)0x64,  /* [2903] */
    (xdc_Char)0x20,  /* [2904] */
    (xdc_Char)0x72,  /* [2905] */
    (xdc_Char)0x65,  /* [2906] */
    (xdc_Char)0x67,  /* [2907] */
    (xdc_Char)0x69,  /* [2908] */
    (xdc_Char)0x6f,  /* [2909] */
    (xdc_Char)0x6e,  /* [2910] */
    (xdc_Char)0x20,  /* [2911] */
    (xdc_Char)0x6f,  /* [2912] */
    (xdc_Char)0x76,  /* [2913] */
    (xdc_Char)0x65,  /* [2914] */
    (xdc_Char)0x72,  /* [2915] */
    (xdc_Char)0x6c,  /* [2916] */
    (xdc_Char)0x61,  /* [2917] */
    (xdc_Char)0x70,  /* [2918] */
    (xdc_Char)0x73,  /* [2919] */
    (xdc_Char)0x0,  /* [2920] */
    (xdc_Char)0x41,  /* [2921] */
    (xdc_Char)0x5f,  /* [2922] */
    (xdc_Char)0x61,  /* [2923] */
    (xdc_Char)0x6c,  /* [2924] */
    (xdc_Char)0x72,  /* [2925] */
    (xdc_Char)0x65,  /* [2926] */
    (xdc_Char)0x61,  /* [2927] */
    (xdc_Char)0x64,  /* [2928] */
    (xdc_Char)0x79,  /* [2929] */
    (xdc_Char)0x45,  /* [2930] */
    (xdc_Char)0x78,  /* [2931] */
    (xdc_Char)0x69,  /* [2932] */
    (xdc_Char)0x73,  /* [2933] */
    (xdc_Char)0x74,  /* [2934] */
    (xdc_Char)0x73,  /* [2935] */
    (xdc_Char)0x3a,  /* [2936] */
    (xdc_Char)0x20,  /* [2937] */
    (xdc_Char)0x54,  /* [2938] */
    (xdc_Char)0x72,  /* [2939] */
    (xdc_Char)0x79,  /* [2940] */
    (xdc_Char)0x69,  /* [2941] */
    (xdc_Char)0x6e,  /* [2942] */
    (xdc_Char)0x67,  /* [2943] */
    (xdc_Char)0x20,  /* [2944] */
    (xdc_Char)0x74,  /* [2945] */
    (xdc_Char)0x6f,  /* [2946] */
    (xdc_Char)0x20,  /* [2947] */
    (xdc_Char)0x6f,  /* [2948] */
    (xdc_Char)0x76,  /* [2949] */
    (xdc_Char)0x65,  /* [2950] */
    (xdc_Char)0x72,  /* [2951] */
    (xdc_Char)0x77,  /* [2952] */
    (xdc_Char)0x72,  /* [2953] */
    (xdc_Char)0x69,  /* [2954] */
    (xdc_Char)0x74,  /* [2955] */
    (xdc_Char)0x65,  /* [2956] */
    (xdc_Char)0x20,  /* [2957] */
    (xdc_Char)0x61,  /* [2958] */
    (xdc_Char)0x6e,  /* [2959] */
    (xdc_Char)0x20,  /* [2960] */
    (xdc_Char)0x65,  /* [2961] */
    (xdc_Char)0x78,  /* [2962] */
    (xdc_Char)0x69,  /* [2963] */
    (xdc_Char)0x73,  /* [2964] */
    (xdc_Char)0x74,  /* [2965] */
    (xdc_Char)0x69,  /* [2966] */
    (xdc_Char)0x6e,  /* [2967] */
    (xdc_Char)0x67,  /* [2968] */
    (xdc_Char)0x20,  /* [2969] */
    (xdc_Char)0x76,  /* [2970] */
    (xdc_Char)0x61,  /* [2971] */
    (xdc_Char)0x6c,  /* [2972] */
    (xdc_Char)0x69,  /* [2973] */
    (xdc_Char)0x64,  /* [2974] */
    (xdc_Char)0x20,  /* [2975] */
    (xdc_Char)0x65,  /* [2976] */
    (xdc_Char)0x6e,  /* [2977] */
    (xdc_Char)0x74,  /* [2978] */
    (xdc_Char)0x72,  /* [2979] */
    (xdc_Char)0x79,  /* [2980] */
    (xdc_Char)0x0,  /* [2981] */
    (xdc_Char)0x41,  /* [2982] */
    (xdc_Char)0x5f,  /* [2983] */
    (xdc_Char)0x6e,  /* [2984] */
    (xdc_Char)0x6f,  /* [2985] */
    (xdc_Char)0x48,  /* [2986] */
    (xdc_Char)0x65,  /* [2987] */
    (xdc_Char)0x61,  /* [2988] */
    (xdc_Char)0x70,  /* [2989] */
    (xdc_Char)0x3a,  /* [2990] */
    (xdc_Char)0x20,  /* [2991] */
    (xdc_Char)0x52,  /* [2992] */
    (xdc_Char)0x65,  /* [2993] */
    (xdc_Char)0x67,  /* [2994] */
    (xdc_Char)0x69,  /* [2995] */
    (xdc_Char)0x6f,  /* [2996] */
    (xdc_Char)0x6e,  /* [2997] */
    (xdc_Char)0x20,  /* [2998] */
    (xdc_Char)0x68,  /* [2999] */
    (xdc_Char)0x61,  /* [3000] */
    (xdc_Char)0x73,  /* [3001] */
    (xdc_Char)0x20,  /* [3002] */
    (xdc_Char)0x6e,  /* [3003] */
    (xdc_Char)0x6f,  /* [3004] */
    (xdc_Char)0x20,  /* [3005] */
    (xdc_Char)0x68,  /* [3006] */
    (xdc_Char)0x65,  /* [3007] */
    (xdc_Char)0x61,  /* [3008] */
    (xdc_Char)0x70,  /* [3009] */
    (xdc_Char)0x0,  /* [3010] */
    (xdc_Char)0x41,  /* [3011] */
    (xdc_Char)0x5f,  /* [3012] */
    (xdc_Char)0x61,  /* [3013] */
    (xdc_Char)0x64,  /* [3014] */
    (xdc_Char)0x64,  /* [3015] */
    (xdc_Char)0x72,  /* [3016] */
    (xdc_Char)0x4e,  /* [3017] */
    (xdc_Char)0x6f,  /* [3018] */
    (xdc_Char)0x74,  /* [3019] */
    (xdc_Char)0x49,  /* [3020] */
    (xdc_Char)0x6e,  /* [3021] */
    (xdc_Char)0x53,  /* [3022] */
    (xdc_Char)0x68,  /* [3023] */
    (xdc_Char)0x61,  /* [3024] */
    (xdc_Char)0x72,  /* [3025] */
    (xdc_Char)0x65,  /* [3026] */
    (xdc_Char)0x64,  /* [3027] */
    (xdc_Char)0x52,  /* [3028] */
    (xdc_Char)0x65,  /* [3029] */
    (xdc_Char)0x67,  /* [3030] */
    (xdc_Char)0x69,  /* [3031] */
    (xdc_Char)0x6f,  /* [3032] */
    (xdc_Char)0x6e,  /* [3033] */
    (xdc_Char)0x3a,  /* [3034] */
    (xdc_Char)0x20,  /* [3035] */
    (xdc_Char)0x41,  /* [3036] */
    (xdc_Char)0x64,  /* [3037] */
    (xdc_Char)0x64,  /* [3038] */
    (xdc_Char)0x72,  /* [3039] */
    (xdc_Char)0x65,  /* [3040] */
    (xdc_Char)0x73,  /* [3041] */
    (xdc_Char)0x73,  /* [3042] */
    (xdc_Char)0x20,  /* [3043] */
    (xdc_Char)0x6e,  /* [3044] */
    (xdc_Char)0x6f,  /* [3045] */
    (xdc_Char)0x74,  /* [3046] */
    (xdc_Char)0x20,  /* [3047] */
    (xdc_Char)0x69,  /* [3048] */
    (xdc_Char)0x6e,  /* [3049] */
    (xdc_Char)0x20,  /* [3050] */
    (xdc_Char)0x61,  /* [3051] */
    (xdc_Char)0x6e,  /* [3052] */
    (xdc_Char)0x79,  /* [3053] */
    (xdc_Char)0x20,  /* [3054] */
    (xdc_Char)0x73,  /* [3055] */
    (xdc_Char)0x68,  /* [3056] */
    (xdc_Char)0x61,  /* [3057] */
    (xdc_Char)0x72,  /* [3058] */
    (xdc_Char)0x65,  /* [3059] */
    (xdc_Char)0x64,  /* [3060] */
    (xdc_Char)0x20,  /* [3061] */
    (xdc_Char)0x72,  /* [3062] */
    (xdc_Char)0x65,  /* [3063] */
    (xdc_Char)0x67,  /* [3064] */
    (xdc_Char)0x69,  /* [3065] */
    (xdc_Char)0x6f,  /* [3066] */
    (xdc_Char)0x6e,  /* [3067] */
    (xdc_Char)0x0,  /* [3068] */
    (xdc_Char)0x41,  /* [3069] */
    (xdc_Char)0x5f,  /* [3070] */
    (xdc_Char)0x61,  /* [3071] */
    (xdc_Char)0x64,  /* [3072] */
    (xdc_Char)0x64,  /* [3073] */
    (xdc_Char)0x72,  /* [3074] */
    (xdc_Char)0x4e,  /* [3075] */
    (xdc_Char)0x6f,  /* [3076] */
    (xdc_Char)0x74,  /* [3077] */
    (xdc_Char)0x43,  /* [3078] */
    (xdc_Char)0x61,  /* [3079] */
    (xdc_Char)0x63,  /* [3080] */
    (xdc_Char)0x68,  /* [3081] */
    (xdc_Char)0x65,  /* [3082] */
    (xdc_Char)0x41,  /* [3083] */
    (xdc_Char)0x6c,  /* [3084] */
    (xdc_Char)0x69,  /* [3085] */
    (xdc_Char)0x67,  /* [3086] */
    (xdc_Char)0x6e,  /* [3087] */
    (xdc_Char)0x65,  /* [3088] */
    (xdc_Char)0x64,  /* [3089] */
    (xdc_Char)0x3a,  /* [3090] */
    (xdc_Char)0x20,  /* [3091] */
    (xdc_Char)0x41,  /* [3092] */
    (xdc_Char)0x64,  /* [3093] */
    (xdc_Char)0x64,  /* [3094] */
    (xdc_Char)0x72,  /* [3095] */
    (xdc_Char)0x65,  /* [3096] */
    (xdc_Char)0x73,  /* [3097] */
    (xdc_Char)0x73,  /* [3098] */
    (xdc_Char)0x20,  /* [3099] */
    (xdc_Char)0x69,  /* [3100] */
    (xdc_Char)0x73,  /* [3101] */
    (xdc_Char)0x20,  /* [3102] */
    (xdc_Char)0x6e,  /* [3103] */
    (xdc_Char)0x6f,  /* [3104] */
    (xdc_Char)0x74,  /* [3105] */
    (xdc_Char)0x20,  /* [3106] */
    (xdc_Char)0x63,  /* [3107] */
    (xdc_Char)0x61,  /* [3108] */
    (xdc_Char)0x63,  /* [3109] */
    (xdc_Char)0x68,  /* [3110] */
    (xdc_Char)0x65,  /* [3111] */
    (xdc_Char)0x20,  /* [3112] */
    (xdc_Char)0x61,  /* [3113] */
    (xdc_Char)0x6c,  /* [3114] */
    (xdc_Char)0x69,  /* [3115] */
    (xdc_Char)0x67,  /* [3116] */
    (xdc_Char)0x6e,  /* [3117] */
    (xdc_Char)0x65,  /* [3118] */
    (xdc_Char)0x64,  /* [3119] */
    (xdc_Char)0x0,  /* [3120] */
    (xdc_Char)0x41,  /* [3121] */
    (xdc_Char)0x5f,  /* [3122] */
    (xdc_Char)0x6e,  /* [3123] */
    (xdc_Char)0x75,  /* [3124] */
    (xdc_Char)0x6c,  /* [3125] */
    (xdc_Char)0x6c,  /* [3126] */
    (xdc_Char)0x41,  /* [3127] */
    (xdc_Char)0x72,  /* [3128] */
    (xdc_Char)0x67,  /* [3129] */
    (xdc_Char)0x75,  /* [3130] */
    (xdc_Char)0x6d,  /* [3131] */
    (xdc_Char)0x65,  /* [3132] */
    (xdc_Char)0x6e,  /* [3133] */
    (xdc_Char)0x74,  /* [3134] */
    (xdc_Char)0x3a,  /* [3135] */
    (xdc_Char)0x20,  /* [3136] */
    (xdc_Char)0x52,  /* [3137] */
    (xdc_Char)0x65,  /* [3138] */
    (xdc_Char)0x71,  /* [3139] */
    (xdc_Char)0x75,  /* [3140] */
    (xdc_Char)0x69,  /* [3141] */
    (xdc_Char)0x72,  /* [3142] */
    (xdc_Char)0x65,  /* [3143] */
    (xdc_Char)0x64,  /* [3144] */
    (xdc_Char)0x20,  /* [3145] */
    (xdc_Char)0x61,  /* [3146] */
    (xdc_Char)0x72,  /* [3147] */
    (xdc_Char)0x67,  /* [3148] */
    (xdc_Char)0x75,  /* [3149] */
    (xdc_Char)0x6d,  /* [3150] */
    (xdc_Char)0x65,  /* [3151] */
    (xdc_Char)0x6e,  /* [3152] */
    (xdc_Char)0x74,  /* [3153] */
    (xdc_Char)0x20,  /* [3154] */
    (xdc_Char)0x69,  /* [3155] */
    (xdc_Char)0x73,  /* [3156] */
    (xdc_Char)0x20,  /* [3157] */
    (xdc_Char)0x6e,  /* [3158] */
    (xdc_Char)0x75,  /* [3159] */
    (xdc_Char)0x6c,  /* [3160] */
    (xdc_Char)0x6c,  /* [3161] */
    (xdc_Char)0x0,  /* [3162] */
    (xdc_Char)0x41,  /* [3163] */
    (xdc_Char)0x5f,  /* [3164] */
    (xdc_Char)0x6e,  /* [3165] */
    (xdc_Char)0x75,  /* [3166] */
    (xdc_Char)0x6c,  /* [3167] */
    (xdc_Char)0x6c,  /* [3168] */
    (xdc_Char)0x50,  /* [3169] */
    (xdc_Char)0x6f,  /* [3170] */
    (xdc_Char)0x69,  /* [3171] */
    (xdc_Char)0x6e,  /* [3172] */
    (xdc_Char)0x74,  /* [3173] */
    (xdc_Char)0x65,  /* [3174] */
    (xdc_Char)0x72,  /* [3175] */
    (xdc_Char)0x3a,  /* [3176] */
    (xdc_Char)0x20,  /* [3177] */
    (xdc_Char)0x50,  /* [3178] */
    (xdc_Char)0x6f,  /* [3179] */
    (xdc_Char)0x69,  /* [3180] */
    (xdc_Char)0x6e,  /* [3181] */
    (xdc_Char)0x74,  /* [3182] */
    (xdc_Char)0x65,  /* [3183] */
    (xdc_Char)0x72,  /* [3184] */
    (xdc_Char)0x20,  /* [3185] */
    (xdc_Char)0x69,  /* [3186] */
    (xdc_Char)0x73,  /* [3187] */
    (xdc_Char)0x20,  /* [3188] */
    (xdc_Char)0x6e,  /* [3189] */
    (xdc_Char)0x75,  /* [3190] */
    (xdc_Char)0x6c,  /* [3191] */
    (xdc_Char)0x6c,  /* [3192] */
    (xdc_Char)0x0,  /* [3193] */
    (xdc_Char)0x41,  /* [3194] */
    (xdc_Char)0x5f,  /* [3195] */
    (xdc_Char)0x69,  /* [3196] */
    (xdc_Char)0x6e,  /* [3197] */
    (xdc_Char)0x76,  /* [3198] */
    (xdc_Char)0x50,  /* [3199] */
    (xdc_Char)0x61,  /* [3200] */
    (xdc_Char)0x72,  /* [3201] */
    (xdc_Char)0x61,  /* [3202] */
    (xdc_Char)0x6d,  /* [3203] */
    (xdc_Char)0x3a,  /* [3204] */
    (xdc_Char)0x20,  /* [3205] */
    (xdc_Char)0x49,  /* [3206] */
    (xdc_Char)0x6e,  /* [3207] */
    (xdc_Char)0x76,  /* [3208] */
    (xdc_Char)0x61,  /* [3209] */
    (xdc_Char)0x6c,  /* [3210] */
    (xdc_Char)0x69,  /* [3211] */
    (xdc_Char)0x64,  /* [3212] */
    (xdc_Char)0x20,  /* [3213] */
    (xdc_Char)0x63,  /* [3214] */
    (xdc_Char)0x6f,  /* [3215] */
    (xdc_Char)0x6e,  /* [3216] */
    (xdc_Char)0x66,  /* [3217] */
    (xdc_Char)0x69,  /* [3218] */
    (xdc_Char)0x67,  /* [3219] */
    (xdc_Char)0x75,  /* [3220] */
    (xdc_Char)0x72,  /* [3221] */
    (xdc_Char)0x61,  /* [3222] */
    (xdc_Char)0x74,  /* [3223] */
    (xdc_Char)0x69,  /* [3224] */
    (xdc_Char)0x6f,  /* [3225] */
    (xdc_Char)0x6e,  /* [3226] */
    (xdc_Char)0x20,  /* [3227] */
    (xdc_Char)0x70,  /* [3228] */
    (xdc_Char)0x61,  /* [3229] */
    (xdc_Char)0x72,  /* [3230] */
    (xdc_Char)0x61,  /* [3231] */
    (xdc_Char)0x6d,  /* [3232] */
    (xdc_Char)0x65,  /* [3233] */
    (xdc_Char)0x74,  /* [3234] */
    (xdc_Char)0x65,  /* [3235] */
    (xdc_Char)0x72,  /* [3236] */
    (xdc_Char)0x20,  /* [3237] */
    (xdc_Char)0x73,  /* [3238] */
    (xdc_Char)0x75,  /* [3239] */
    (xdc_Char)0x70,  /* [3240] */
    (xdc_Char)0x70,  /* [3241] */
    (xdc_Char)0x6c,  /* [3242] */
    (xdc_Char)0x69,  /* [3243] */
    (xdc_Char)0x65,  /* [3244] */
    (xdc_Char)0x64,  /* [3245] */
    (xdc_Char)0x0,  /* [3246] */
    (xdc_Char)0x41,  /* [3247] */
    (xdc_Char)0x5f,  /* [3248] */
    (xdc_Char)0x69,  /* [3249] */
    (xdc_Char)0x6e,  /* [3250] */
    (xdc_Char)0x74,  /* [3251] */
    (xdc_Char)0x65,  /* [3252] */
    (xdc_Char)0x72,  /* [3253] */
    (xdc_Char)0x6e,  /* [3254] */
    (xdc_Char)0x61,  /* [3255] */
    (xdc_Char)0x6c,  /* [3256] */
    (xdc_Char)0x3a,  /* [3257] */
    (xdc_Char)0x20,  /* [3258] */
    (xdc_Char)0x41,  /* [3259] */
    (xdc_Char)0x6e,  /* [3260] */
    (xdc_Char)0x20,  /* [3261] */
    (xdc_Char)0x69,  /* [3262] */
    (xdc_Char)0x6e,  /* [3263] */
    (xdc_Char)0x74,  /* [3264] */
    (xdc_Char)0x65,  /* [3265] */
    (xdc_Char)0x72,  /* [3266] */
    (xdc_Char)0x6e,  /* [3267] */
    (xdc_Char)0x61,  /* [3268] */
    (xdc_Char)0x6c,  /* [3269] */
    (xdc_Char)0x20,  /* [3270] */
    (xdc_Char)0x65,  /* [3271] */
    (xdc_Char)0x72,  /* [3272] */
    (xdc_Char)0x72,  /* [3273] */
    (xdc_Char)0x6f,  /* [3274] */
    (xdc_Char)0x72,  /* [3275] */
    (xdc_Char)0x20,  /* [3276] */
    (xdc_Char)0x68,  /* [3277] */
    (xdc_Char)0x61,  /* [3278] */
    (xdc_Char)0x73,  /* [3279] */
    (xdc_Char)0x20,  /* [3280] */
    (xdc_Char)0x6f,  /* [3281] */
    (xdc_Char)0x63,  /* [3282] */
    (xdc_Char)0x63,  /* [3283] */
    (xdc_Char)0x75,  /* [3284] */
    (xdc_Char)0x72,  /* [3285] */
    (xdc_Char)0x72,  /* [3286] */
    (xdc_Char)0x65,  /* [3287] */
    (xdc_Char)0x64,  /* [3288] */
    (xdc_Char)0x0,  /* [3289] */
    (xdc_Char)0x41,  /* [3290] */
    (xdc_Char)0x5f,  /* [3291] */
    (xdc_Char)0x61,  /* [3292] */
    (xdc_Char)0x6c,  /* [3293] */
    (xdc_Char)0x72,  /* [3294] */
    (xdc_Char)0x65,  /* [3295] */
    (xdc_Char)0x61,  /* [3296] */
    (xdc_Char)0x64,  /* [3297] */
    (xdc_Char)0x79,  /* [3298] */
    (xdc_Char)0x52,  /* [3299] */
    (xdc_Char)0x65,  /* [3300] */
    (xdc_Char)0x67,  /* [3301] */
    (xdc_Char)0x69,  /* [3302] */
    (xdc_Char)0x73,  /* [3303] */
    (xdc_Char)0x74,  /* [3304] */
    (xdc_Char)0x65,  /* [3305] */
    (xdc_Char)0x72,  /* [3306] */
    (xdc_Char)0x65,  /* [3307] */
    (xdc_Char)0x64,  /* [3308] */
    (xdc_Char)0x3a,  /* [3309] */
    (xdc_Char)0x20,  /* [3310] */
    (xdc_Char)0x4e,  /* [3311] */
    (xdc_Char)0x6f,  /* [3312] */
    (xdc_Char)0x74,  /* [3313] */
    (xdc_Char)0x69,  /* [3314] */
    (xdc_Char)0x66,  /* [3315] */
    (xdc_Char)0x79,  /* [3316] */
    (xdc_Char)0x20,  /* [3317] */
    (xdc_Char)0x69,  /* [3318] */
    (xdc_Char)0x6e,  /* [3319] */
    (xdc_Char)0x73,  /* [3320] */
    (xdc_Char)0x74,  /* [3321] */
    (xdc_Char)0x61,  /* [3322] */
    (xdc_Char)0x6e,  /* [3323] */
    (xdc_Char)0x63,  /* [3324] */
    (xdc_Char)0x65,  /* [3325] */
    (xdc_Char)0x20,  /* [3326] */
    (xdc_Char)0x66,  /* [3327] */
    (xdc_Char)0x6f,  /* [3328] */
    (xdc_Char)0x72,  /* [3329] */
    (xdc_Char)0x20,  /* [3330] */
    (xdc_Char)0x74,  /* [3331] */
    (xdc_Char)0x68,  /* [3332] */
    (xdc_Char)0x65,  /* [3333] */
    (xdc_Char)0x20,  /* [3334] */
    (xdc_Char)0x70,  /* [3335] */
    (xdc_Char)0x72,  /* [3336] */
    (xdc_Char)0x6f,  /* [3337] */
    (xdc_Char)0x63,  /* [3338] */
    (xdc_Char)0x65,  /* [3339] */
    (xdc_Char)0x73,  /* [3340] */
    (xdc_Char)0x73,  /* [3341] */
    (xdc_Char)0x6f,  /* [3342] */
    (xdc_Char)0x72,  /* [3343] */
    (xdc_Char)0x2f,  /* [3344] */
    (xdc_Char)0x6c,  /* [3345] */
    (xdc_Char)0x69,  /* [3346] */
    (xdc_Char)0x6e,  /* [3347] */
    (xdc_Char)0x65,  /* [3348] */
    (xdc_Char)0x20,  /* [3349] */
    (xdc_Char)0x61,  /* [3350] */
    (xdc_Char)0x6c,  /* [3351] */
    (xdc_Char)0x72,  /* [3352] */
    (xdc_Char)0x65,  /* [3353] */
    (xdc_Char)0x61,  /* [3354] */
    (xdc_Char)0x64,  /* [3355] */
    (xdc_Char)0x79,  /* [3356] */
    (xdc_Char)0x20,  /* [3357] */
    (xdc_Char)0x72,  /* [3358] */
    (xdc_Char)0x65,  /* [3359] */
    (xdc_Char)0x67,  /* [3360] */
    (xdc_Char)0x69,  /* [3361] */
    (xdc_Char)0x73,  /* [3362] */
    (xdc_Char)0x74,  /* [3363] */
    (xdc_Char)0x65,  /* [3364] */
    (xdc_Char)0x72,  /* [3365] */
    (xdc_Char)0x65,  /* [3366] */
    (xdc_Char)0x64,  /* [3367] */
    (xdc_Char)0x0,  /* [3368] */
    (xdc_Char)0x41,  /* [3369] */
    (xdc_Char)0x5f,  /* [3370] */
    (xdc_Char)0x6e,  /* [3371] */
    (xdc_Char)0x6f,  /* [3372] */
    (xdc_Char)0x74,  /* [3373] */
    (xdc_Char)0x52,  /* [3374] */
    (xdc_Char)0x65,  /* [3375] */
    (xdc_Char)0x67,  /* [3376] */
    (xdc_Char)0x69,  /* [3377] */
    (xdc_Char)0x73,  /* [3378] */
    (xdc_Char)0x74,  /* [3379] */
    (xdc_Char)0x65,  /* [3380] */
    (xdc_Char)0x72,  /* [3381] */
    (xdc_Char)0x65,  /* [3382] */
    (xdc_Char)0x64,  /* [3383] */
    (xdc_Char)0x3a,  /* [3384] */
    (xdc_Char)0x20,  /* [3385] */
    (xdc_Char)0x4e,  /* [3386] */
    (xdc_Char)0x6f,  /* [3387] */
    (xdc_Char)0x74,  /* [3388] */
    (xdc_Char)0x69,  /* [3389] */
    (xdc_Char)0x66,  /* [3390] */
    (xdc_Char)0x79,  /* [3391] */
    (xdc_Char)0x20,  /* [3392] */
    (xdc_Char)0x69,  /* [3393] */
    (xdc_Char)0x6e,  /* [3394] */
    (xdc_Char)0x73,  /* [3395] */
    (xdc_Char)0x74,  /* [3396] */
    (xdc_Char)0x61,  /* [3397] */
    (xdc_Char)0x6e,  /* [3398] */
    (xdc_Char)0x63,  /* [3399] */
    (xdc_Char)0x65,  /* [3400] */
    (xdc_Char)0x20,  /* [3401] */
    (xdc_Char)0x6e,  /* [3402] */
    (xdc_Char)0x6f,  /* [3403] */
    (xdc_Char)0x74,  /* [3404] */
    (xdc_Char)0x20,  /* [3405] */
    (xdc_Char)0x79,  /* [3406] */
    (xdc_Char)0x65,  /* [3407] */
    (xdc_Char)0x74,  /* [3408] */
    (xdc_Char)0x20,  /* [3409] */
    (xdc_Char)0x72,  /* [3410] */
    (xdc_Char)0x65,  /* [3411] */
    (xdc_Char)0x67,  /* [3412] */
    (xdc_Char)0x69,  /* [3413] */
    (xdc_Char)0x73,  /* [3414] */
    (xdc_Char)0x74,  /* [3415] */
    (xdc_Char)0x65,  /* [3416] */
    (xdc_Char)0x72,  /* [3417] */
    (xdc_Char)0x65,  /* [3418] */
    (xdc_Char)0x64,  /* [3419] */
    (xdc_Char)0x20,  /* [3420] */
    (xdc_Char)0x66,  /* [3421] */
    (xdc_Char)0x6f,  /* [3422] */
    (xdc_Char)0x72,  /* [3423] */
    (xdc_Char)0x20,  /* [3424] */
    (xdc_Char)0x74,  /* [3425] */
    (xdc_Char)0x68,  /* [3426] */
    (xdc_Char)0x65,  /* [3427] */
    (xdc_Char)0x20,  /* [3428] */
    (xdc_Char)0x70,  /* [3429] */
    (xdc_Char)0x72,  /* [3430] */
    (xdc_Char)0x6f,  /* [3431] */
    (xdc_Char)0x63,  /* [3432] */
    (xdc_Char)0x65,  /* [3433] */
    (xdc_Char)0x73,  /* [3434] */
    (xdc_Char)0x73,  /* [3435] */
    (xdc_Char)0x6f,  /* [3436] */
    (xdc_Char)0x72,  /* [3437] */
    (xdc_Char)0x2f,  /* [3438] */
    (xdc_Char)0x6c,  /* [3439] */
    (xdc_Char)0x69,  /* [3440] */
    (xdc_Char)0x6e,  /* [3441] */
    (xdc_Char)0x65,  /* [3442] */
    (xdc_Char)0x0,  /* [3443] */
    (xdc_Char)0x41,  /* [3444] */
    (xdc_Char)0x5f,  /* [3445] */
    (xdc_Char)0x72,  /* [3446] */
    (xdc_Char)0x65,  /* [3447] */
    (xdc_Char)0x73,  /* [3448] */
    (xdc_Char)0x65,  /* [3449] */
    (xdc_Char)0x72,  /* [3450] */
    (xdc_Char)0x76,  /* [3451] */
    (xdc_Char)0x65,  /* [3452] */
    (xdc_Char)0x64,  /* [3453] */
    (xdc_Char)0x45,  /* [3454] */
    (xdc_Char)0x76,  /* [3455] */
    (xdc_Char)0x65,  /* [3456] */
    (xdc_Char)0x6e,  /* [3457] */
    (xdc_Char)0x74,  /* [3458] */
    (xdc_Char)0x3a,  /* [3459] */
    (xdc_Char)0x20,  /* [3460] */
    (xdc_Char)0x49,  /* [3461] */
    (xdc_Char)0x6d,  /* [3462] */
    (xdc_Char)0x70,  /* [3463] */
    (xdc_Char)0x72,  /* [3464] */
    (xdc_Char)0x6f,  /* [3465] */
    (xdc_Char)0x70,  /* [3466] */
    (xdc_Char)0x65,  /* [3467] */
    (xdc_Char)0x72,  /* [3468] */
    (xdc_Char)0x20,  /* [3469] */
    (xdc_Char)0x75,  /* [3470] */
    (xdc_Char)0x73,  /* [3471] */
    (xdc_Char)0x65,  /* [3472] */
    (xdc_Char)0x20,  /* [3473] */
    (xdc_Char)0x6f,  /* [3474] */
    (xdc_Char)0x66,  /* [3475] */
    (xdc_Char)0x20,  /* [3476] */
    (xdc_Char)0x61,  /* [3477] */
    (xdc_Char)0x20,  /* [3478] */
    (xdc_Char)0x72,  /* [3479] */
    (xdc_Char)0x65,  /* [3480] */
    (xdc_Char)0x73,  /* [3481] */
    (xdc_Char)0x65,  /* [3482] */
    (xdc_Char)0x72,  /* [3483] */
    (xdc_Char)0x76,  /* [3484] */
    (xdc_Char)0x65,  /* [3485] */
    (xdc_Char)0x64,  /* [3486] */
    (xdc_Char)0x20,  /* [3487] */
    (xdc_Char)0x65,  /* [3488] */
    (xdc_Char)0x76,  /* [3489] */
    (xdc_Char)0x65,  /* [3490] */
    (xdc_Char)0x6e,  /* [3491] */
    (xdc_Char)0x74,  /* [3492] */
    (xdc_Char)0x0,  /* [3493] */
    (xdc_Char)0x41,  /* [3494] */
    (xdc_Char)0x5f,  /* [3495] */
    (xdc_Char)0x6f,  /* [3496] */
    (xdc_Char)0x75,  /* [3497] */
    (xdc_Char)0x74,  /* [3498] */
    (xdc_Char)0x4f,  /* [3499] */
    (xdc_Char)0x66,  /* [3500] */
    (xdc_Char)0x4f,  /* [3501] */
    (xdc_Char)0x72,  /* [3502] */
    (xdc_Char)0x64,  /* [3503] */
    (xdc_Char)0x65,  /* [3504] */
    (xdc_Char)0x72,  /* [3505] */
    (xdc_Char)0x4e,  /* [3506] */
    (xdc_Char)0x65,  /* [3507] */
    (xdc_Char)0x73,  /* [3508] */
    (xdc_Char)0x74,  /* [3509] */
    (xdc_Char)0x69,  /* [3510] */
    (xdc_Char)0x6e,  /* [3511] */
    (xdc_Char)0x67,  /* [3512] */
    (xdc_Char)0x3a,  /* [3513] */
    (xdc_Char)0x20,  /* [3514] */
    (xdc_Char)0x4f,  /* [3515] */
    (xdc_Char)0x75,  /* [3516] */
    (xdc_Char)0x74,  /* [3517] */
    (xdc_Char)0x20,  /* [3518] */
    (xdc_Char)0x6f,  /* [3519] */
    (xdc_Char)0x66,  /* [3520] */
    (xdc_Char)0x20,  /* [3521] */
    (xdc_Char)0x6f,  /* [3522] */
    (xdc_Char)0x72,  /* [3523] */
    (xdc_Char)0x64,  /* [3524] */
    (xdc_Char)0x65,  /* [3525] */
    (xdc_Char)0x72,  /* [3526] */
    (xdc_Char)0x20,  /* [3527] */
    (xdc_Char)0x6e,  /* [3528] */
    (xdc_Char)0x65,  /* [3529] */
    (xdc_Char)0x73,  /* [3530] */
    (xdc_Char)0x74,  /* [3531] */
    (xdc_Char)0x69,  /* [3532] */
    (xdc_Char)0x6e,  /* [3533] */
    (xdc_Char)0x67,  /* [3534] */
    (xdc_Char)0x0,  /* [3535] */
    (xdc_Char)0x62,  /* [3536] */
    (xdc_Char)0x75,  /* [3537] */
    (xdc_Char)0x66,  /* [3538] */
    (xdc_Char)0x20,  /* [3539] */
    (xdc_Char)0x70,  /* [3540] */
    (xdc_Char)0x61,  /* [3541] */
    (xdc_Char)0x72,  /* [3542] */
    (xdc_Char)0x61,  /* [3543] */
    (xdc_Char)0x6d,  /* [3544] */
    (xdc_Char)0x65,  /* [3545] */
    (xdc_Char)0x74,  /* [3546] */
    (xdc_Char)0x65,  /* [3547] */
    (xdc_Char)0x72,  /* [3548] */
    (xdc_Char)0x20,  /* [3549] */
    (xdc_Char)0x63,  /* [3550] */
    (xdc_Char)0x61,  /* [3551] */
    (xdc_Char)0x6e,  /* [3552] */
    (xdc_Char)0x6e,  /* [3553] */
    (xdc_Char)0x6f,  /* [3554] */
    (xdc_Char)0x74,  /* [3555] */
    (xdc_Char)0x20,  /* [3556] */
    (xdc_Char)0x62,  /* [3557] */
    (xdc_Char)0x65,  /* [3558] */
    (xdc_Char)0x20,  /* [3559] */
    (xdc_Char)0x6e,  /* [3560] */
    (xdc_Char)0x75,  /* [3561] */
    (xdc_Char)0x6c,  /* [3562] */
    (xdc_Char)0x6c,  /* [3563] */
    (xdc_Char)0x0,  /* [3564] */
    (xdc_Char)0x62,  /* [3565] */
    (xdc_Char)0x75,  /* [3566] */
    (xdc_Char)0x66,  /* [3567] */
    (xdc_Char)0x20,  /* [3568] */
    (xdc_Char)0x6e,  /* [3569] */
    (xdc_Char)0x6f,  /* [3570] */
    (xdc_Char)0x74,  /* [3571] */
    (xdc_Char)0x20,  /* [3572] */
    (xdc_Char)0x70,  /* [3573] */
    (xdc_Char)0x72,  /* [3574] */
    (xdc_Char)0x6f,  /* [3575] */
    (xdc_Char)0x70,  /* [3576] */
    (xdc_Char)0x65,  /* [3577] */
    (xdc_Char)0x72,  /* [3578] */
    (xdc_Char)0x6c,  /* [3579] */
    (xdc_Char)0x79,  /* [3580] */
    (xdc_Char)0x20,  /* [3581] */
    (xdc_Char)0x61,  /* [3582] */
    (xdc_Char)0x6c,  /* [3583] */
    (xdc_Char)0x69,  /* [3584] */
    (xdc_Char)0x67,  /* [3585] */
    (xdc_Char)0x6e,  /* [3586] */
    (xdc_Char)0x65,  /* [3587] */
    (xdc_Char)0x64,  /* [3588] */
    (xdc_Char)0x0,  /* [3589] */
    (xdc_Char)0x61,  /* [3590] */
    (xdc_Char)0x6c,  /* [3591] */
    (xdc_Char)0x69,  /* [3592] */
    (xdc_Char)0x67,  /* [3593] */
    (xdc_Char)0x6e,  /* [3594] */
    (xdc_Char)0x20,  /* [3595] */
    (xdc_Char)0x70,  /* [3596] */
    (xdc_Char)0x61,  /* [3597] */
    (xdc_Char)0x72,  /* [3598] */
    (xdc_Char)0x61,  /* [3599] */
    (xdc_Char)0x6d,  /* [3600] */
    (xdc_Char)0x65,  /* [3601] */
    (xdc_Char)0x74,  /* [3602] */
    (xdc_Char)0x65,  /* [3603] */
    (xdc_Char)0x72,  /* [3604] */
    (xdc_Char)0x20,  /* [3605] */
    (xdc_Char)0x6d,  /* [3606] */
    (xdc_Char)0x75,  /* [3607] */
    (xdc_Char)0x73,  /* [3608] */
    (xdc_Char)0x74,  /* [3609] */
    (xdc_Char)0x20,  /* [3610] */
    (xdc_Char)0x62,  /* [3611] */
    (xdc_Char)0x65,  /* [3612] */
    (xdc_Char)0x20,  /* [3613] */
    (xdc_Char)0x30,  /* [3614] */
    (xdc_Char)0x20,  /* [3615] */
    (xdc_Char)0x6f,  /* [3616] */
    (xdc_Char)0x72,  /* [3617] */
    (xdc_Char)0x20,  /* [3618] */
    (xdc_Char)0x61,  /* [3619] */
    (xdc_Char)0x20,  /* [3620] */
    (xdc_Char)0x70,  /* [3621] */
    (xdc_Char)0x6f,  /* [3622] */
    (xdc_Char)0x77,  /* [3623] */
    (xdc_Char)0x65,  /* [3624] */
    (xdc_Char)0x72,  /* [3625] */
    (xdc_Char)0x20,  /* [3626] */
    (xdc_Char)0x6f,  /* [3627] */
    (xdc_Char)0x66,  /* [3628] */
    (xdc_Char)0x20,  /* [3629] */
    (xdc_Char)0x32,  /* [3630] */
    (xdc_Char)0x20,  /* [3631] */
    (xdc_Char)0x3e,  /* [3632] */
    (xdc_Char)0x3d,  /* [3633] */
    (xdc_Char)0x20,  /* [3634] */
    (xdc_Char)0x74,  /* [3635] */
    (xdc_Char)0x68,  /* [3636] */
    (xdc_Char)0x65,  /* [3637] */
    (xdc_Char)0x20,  /* [3638] */
    (xdc_Char)0x76,  /* [3639] */
    (xdc_Char)0x61,  /* [3640] */
    (xdc_Char)0x6c,  /* [3641] */
    (xdc_Char)0x75,  /* [3642] */
    (xdc_Char)0x65,  /* [3643] */
    (xdc_Char)0x20,  /* [3644] */
    (xdc_Char)0x6f,  /* [3645] */
    (xdc_Char)0x66,  /* [3646] */
    (xdc_Char)0x20,  /* [3647] */
    (xdc_Char)0x4d,  /* [3648] */
    (xdc_Char)0x65,  /* [3649] */
    (xdc_Char)0x6d,  /* [3650] */
    (xdc_Char)0x6f,  /* [3651] */
    (xdc_Char)0x72,  /* [3652] */
    (xdc_Char)0x79,  /* [3653] */
    (xdc_Char)0x5f,  /* [3654] */
    (xdc_Char)0x67,  /* [3655] */
    (xdc_Char)0x65,  /* [3656] */
    (xdc_Char)0x74,  /* [3657] */
    (xdc_Char)0x4d,  /* [3658] */
    (xdc_Char)0x61,  /* [3659] */
    (xdc_Char)0x78,  /* [3660] */
    (xdc_Char)0x44,  /* [3661] */
    (xdc_Char)0x65,  /* [3662] */
    (xdc_Char)0x66,  /* [3663] */
    (xdc_Char)0x61,  /* [3664] */
    (xdc_Char)0x75,  /* [3665] */
    (xdc_Char)0x6c,  /* [3666] */
    (xdc_Char)0x74,  /* [3667] */
    (xdc_Char)0x54,  /* [3668] */
    (xdc_Char)0x79,  /* [3669] */
    (xdc_Char)0x70,  /* [3670] */
    (xdc_Char)0x65,  /* [3671] */
    (xdc_Char)0x41,  /* [3672] */
    (xdc_Char)0x6c,  /* [3673] */
    (xdc_Char)0x69,  /* [3674] */
    (xdc_Char)0x67,  /* [3675] */
    (xdc_Char)0x6e,  /* [3676] */
    (xdc_Char)0x28,  /* [3677] */
    (xdc_Char)0x29,  /* [3678] */
    (xdc_Char)0x0,  /* [3679] */
    (xdc_Char)0x62,  /* [3680] */
    (xdc_Char)0x6c,  /* [3681] */
    (xdc_Char)0x6f,  /* [3682] */
    (xdc_Char)0x63,  /* [3683] */
    (xdc_Char)0x6b,  /* [3684] */
    (xdc_Char)0x53,  /* [3685] */
    (xdc_Char)0x69,  /* [3686] */
    (xdc_Char)0x7a,  /* [3687] */
    (xdc_Char)0x65,  /* [3688] */
    (xdc_Char)0x20,  /* [3689] */
    (xdc_Char)0x63,  /* [3690] */
    (xdc_Char)0x61,  /* [3691] */
    (xdc_Char)0x6e,  /* [3692] */
    (xdc_Char)0x6e,  /* [3693] */
    (xdc_Char)0x6f,  /* [3694] */
    (xdc_Char)0x74,  /* [3695] */
    (xdc_Char)0x20,  /* [3696] */
    (xdc_Char)0x62,  /* [3697] */
    (xdc_Char)0x65,  /* [3698] */
    (xdc_Char)0x20,  /* [3699] */
    (xdc_Char)0x7a,  /* [3700] */
    (xdc_Char)0x65,  /* [3701] */
    (xdc_Char)0x72,  /* [3702] */
    (xdc_Char)0x6f,  /* [3703] */
    (xdc_Char)0x0,  /* [3704] */
    (xdc_Char)0x6e,  /* [3705] */
    (xdc_Char)0x75,  /* [3706] */
    (xdc_Char)0x6d,  /* [3707] */
    (xdc_Char)0x42,  /* [3708] */
    (xdc_Char)0x6c,  /* [3709] */
    (xdc_Char)0x6f,  /* [3710] */
    (xdc_Char)0x63,  /* [3711] */
    (xdc_Char)0x6b,  /* [3712] */
    (xdc_Char)0x73,  /* [3713] */
    (xdc_Char)0x20,  /* [3714] */
    (xdc_Char)0x63,  /* [3715] */
    (xdc_Char)0x61,  /* [3716] */
    (xdc_Char)0x6e,  /* [3717] */
    (xdc_Char)0x6e,  /* [3718] */
    (xdc_Char)0x6f,  /* [3719] */
    (xdc_Char)0x74,  /* [3720] */
    (xdc_Char)0x20,  /* [3721] */
    (xdc_Char)0x62,  /* [3722] */
    (xdc_Char)0x65,  /* [3723] */
    (xdc_Char)0x20,  /* [3724] */
    (xdc_Char)0x7a,  /* [3725] */
    (xdc_Char)0x65,  /* [3726] */
    (xdc_Char)0x72,  /* [3727] */
    (xdc_Char)0x6f,  /* [3728] */
    (xdc_Char)0x0,  /* [3729] */
    (xdc_Char)0x62,  /* [3730] */
    (xdc_Char)0x75,  /* [3731] */
    (xdc_Char)0x66,  /* [3732] */
    (xdc_Char)0x53,  /* [3733] */
    (xdc_Char)0x69,  /* [3734] */
    (xdc_Char)0x7a,  /* [3735] */
    (xdc_Char)0x65,  /* [3736] */
    (xdc_Char)0x20,  /* [3737] */
    (xdc_Char)0x63,  /* [3738] */
    (xdc_Char)0x61,  /* [3739] */
    (xdc_Char)0x6e,  /* [3740] */
    (xdc_Char)0x6e,  /* [3741] */
    (xdc_Char)0x6f,  /* [3742] */
    (xdc_Char)0x74,  /* [3743] */
    (xdc_Char)0x20,  /* [3744] */
    (xdc_Char)0x62,  /* [3745] */
    (xdc_Char)0x65,  /* [3746] */
    (xdc_Char)0x20,  /* [3747] */
    (xdc_Char)0x7a,  /* [3748] */
    (xdc_Char)0x65,  /* [3749] */
    (xdc_Char)0x72,  /* [3750] */
    (xdc_Char)0x6f,  /* [3751] */
    (xdc_Char)0x0,  /* [3752] */
    (xdc_Char)0x48,  /* [3753] */
    (xdc_Char)0x65,  /* [3754] */
    (xdc_Char)0x61,  /* [3755] */
    (xdc_Char)0x70,  /* [3756] */
    (xdc_Char)0x42,  /* [3757] */
    (xdc_Char)0x75,  /* [3758] */
    (xdc_Char)0x66,  /* [3759] */
    (xdc_Char)0x5f,  /* [3760] */
    (xdc_Char)0x63,  /* [3761] */
    (xdc_Char)0x72,  /* [3762] */
    (xdc_Char)0x65,  /* [3763] */
    (xdc_Char)0x61,  /* [3764] */
    (xdc_Char)0x74,  /* [3765] */
    (xdc_Char)0x65,  /* [3766] */
    (xdc_Char)0x27,  /* [3767] */
    (xdc_Char)0x73,  /* [3768] */
    (xdc_Char)0x20,  /* [3769] */
    (xdc_Char)0x62,  /* [3770] */
    (xdc_Char)0x75,  /* [3771] */
    (xdc_Char)0x66,  /* [3772] */
    (xdc_Char)0x53,  /* [3773] */
    (xdc_Char)0x69,  /* [3774] */
    (xdc_Char)0x7a,  /* [3775] */
    (xdc_Char)0x65,  /* [3776] */
    (xdc_Char)0x20,  /* [3777] */
    (xdc_Char)0x70,  /* [3778] */
    (xdc_Char)0x61,  /* [3779] */
    (xdc_Char)0x72,  /* [3780] */
    (xdc_Char)0x61,  /* [3781] */
    (xdc_Char)0x6d,  /* [3782] */
    (xdc_Char)0x65,  /* [3783] */
    (xdc_Char)0x74,  /* [3784] */
    (xdc_Char)0x65,  /* [3785] */
    (xdc_Char)0x72,  /* [3786] */
    (xdc_Char)0x20,  /* [3787] */
    (xdc_Char)0x69,  /* [3788] */
    (xdc_Char)0x73,  /* [3789] */
    (xdc_Char)0x20,  /* [3790] */
    (xdc_Char)0x69,  /* [3791] */
    (xdc_Char)0x6e,  /* [3792] */
    (xdc_Char)0x76,  /* [3793] */
    (xdc_Char)0x61,  /* [3794] */
    (xdc_Char)0x6c,  /* [3795] */
    (xdc_Char)0x69,  /* [3796] */
    (xdc_Char)0x64,  /* [3797] */
    (xdc_Char)0x20,  /* [3798] */
    (xdc_Char)0x28,  /* [3799] */
    (xdc_Char)0x74,  /* [3800] */
    (xdc_Char)0x6f,  /* [3801] */
    (xdc_Char)0x6f,  /* [3802] */
    (xdc_Char)0x20,  /* [3803] */
    (xdc_Char)0x73,  /* [3804] */
    (xdc_Char)0x6d,  /* [3805] */
    (xdc_Char)0x61,  /* [3806] */
    (xdc_Char)0x6c,  /* [3807] */
    (xdc_Char)0x6c,  /* [3808] */
    (xdc_Char)0x29,  /* [3809] */
    (xdc_Char)0x0,  /* [3810] */
    (xdc_Char)0x43,  /* [3811] */
    (xdc_Char)0x61,  /* [3812] */
    (xdc_Char)0x6e,  /* [3813] */
    (xdc_Char)0x6e,  /* [3814] */
    (xdc_Char)0x6f,  /* [3815] */
    (xdc_Char)0x74,  /* [3816] */
    (xdc_Char)0x20,  /* [3817] */
    (xdc_Char)0x63,  /* [3818] */
    (xdc_Char)0x61,  /* [3819] */
    (xdc_Char)0x6c,  /* [3820] */
    (xdc_Char)0x6c,  /* [3821] */
    (xdc_Char)0x20,  /* [3822] */
    (xdc_Char)0x48,  /* [3823] */
    (xdc_Char)0x65,  /* [3824] */
    (xdc_Char)0x61,  /* [3825] */
    (xdc_Char)0x70,  /* [3826] */
    (xdc_Char)0x42,  /* [3827] */
    (xdc_Char)0x75,  /* [3828] */
    (xdc_Char)0x66,  /* [3829] */
    (xdc_Char)0x5f,  /* [3830] */
    (xdc_Char)0x66,  /* [3831] */
    (xdc_Char)0x72,  /* [3832] */
    (xdc_Char)0x65,  /* [3833] */
    (xdc_Char)0x65,  /* [3834] */
    (xdc_Char)0x20,  /* [3835] */
    (xdc_Char)0x77,  /* [3836] */
    (xdc_Char)0x68,  /* [3837] */
    (xdc_Char)0x65,  /* [3838] */
    (xdc_Char)0x6e,  /* [3839] */
    (xdc_Char)0x20,  /* [3840] */
    (xdc_Char)0x6e,  /* [3841] */
    (xdc_Char)0x6f,  /* [3842] */
    (xdc_Char)0x20,  /* [3843] */
    (xdc_Char)0x62,  /* [3844] */
    (xdc_Char)0x6c,  /* [3845] */
    (xdc_Char)0x6f,  /* [3846] */
    (xdc_Char)0x63,  /* [3847] */
    (xdc_Char)0x6b,  /* [3848] */
    (xdc_Char)0x73,  /* [3849] */
    (xdc_Char)0x20,  /* [3850] */
    (xdc_Char)0x68,  /* [3851] */
    (xdc_Char)0x61,  /* [3852] */
    (xdc_Char)0x76,  /* [3853] */
    (xdc_Char)0x65,  /* [3854] */
    (xdc_Char)0x20,  /* [3855] */
    (xdc_Char)0x62,  /* [3856] */
    (xdc_Char)0x65,  /* [3857] */
    (xdc_Char)0x65,  /* [3858] */
    (xdc_Char)0x6e,  /* [3859] */
    (xdc_Char)0x20,  /* [3860] */
    (xdc_Char)0x61,  /* [3861] */
    (xdc_Char)0x6c,  /* [3862] */
    (xdc_Char)0x6c,  /* [3863] */
    (xdc_Char)0x6f,  /* [3864] */
    (xdc_Char)0x63,  /* [3865] */
    (xdc_Char)0x61,  /* [3866] */
    (xdc_Char)0x74,  /* [3867] */
    (xdc_Char)0x65,  /* [3868] */
    (xdc_Char)0x64,  /* [3869] */
    (xdc_Char)0x0,  /* [3870] */
    (xdc_Char)0x41,  /* [3871] */
    (xdc_Char)0x5f,  /* [3872] */
    (xdc_Char)0x69,  /* [3873] */
    (xdc_Char)0x6e,  /* [3874] */
    (xdc_Char)0x76,  /* [3875] */
    (xdc_Char)0x61,  /* [3876] */
    (xdc_Char)0x6c,  /* [3877] */
    (xdc_Char)0x69,  /* [3878] */
    (xdc_Char)0x64,  /* [3879] */
    (xdc_Char)0x46,  /* [3880] */
    (xdc_Char)0x72,  /* [3881] */
    (xdc_Char)0x65,  /* [3882] */
    (xdc_Char)0x65,  /* [3883] */
    (xdc_Char)0x3a,  /* [3884] */
    (xdc_Char)0x20,  /* [3885] */
    (xdc_Char)0x49,  /* [3886] */
    (xdc_Char)0x6e,  /* [3887] */
    (xdc_Char)0x76,  /* [3888] */
    (xdc_Char)0x61,  /* [3889] */
    (xdc_Char)0x6c,  /* [3890] */
    (xdc_Char)0x69,  /* [3891] */
    (xdc_Char)0x64,  /* [3892] */
    (xdc_Char)0x20,  /* [3893] */
    (xdc_Char)0x66,  /* [3894] */
    (xdc_Char)0x72,  /* [3895] */
    (xdc_Char)0x65,  /* [3896] */
    (xdc_Char)0x65,  /* [3897] */
    (xdc_Char)0x0,  /* [3898] */
    (xdc_Char)0x41,  /* [3899] */
    (xdc_Char)0x5f,  /* [3900] */
    (xdc_Char)0x7a,  /* [3901] */
    (xdc_Char)0x65,  /* [3902] */
    (xdc_Char)0x72,  /* [3903] */
    (xdc_Char)0x6f,  /* [3904] */
    (xdc_Char)0x42,  /* [3905] */
    (xdc_Char)0x6c,  /* [3906] */
    (xdc_Char)0x6f,  /* [3907] */
    (xdc_Char)0x63,  /* [3908] */
    (xdc_Char)0x6b,  /* [3909] */
    (xdc_Char)0x3a,  /* [3910] */
    (xdc_Char)0x20,  /* [3911] */
    (xdc_Char)0x43,  /* [3912] */
    (xdc_Char)0x61,  /* [3913] */
    (xdc_Char)0x6e,  /* [3914] */
    (xdc_Char)0x6e,  /* [3915] */
    (xdc_Char)0x6f,  /* [3916] */
    (xdc_Char)0x74,  /* [3917] */
    (xdc_Char)0x20,  /* [3918] */
    (xdc_Char)0x61,  /* [3919] */
    (xdc_Char)0x6c,  /* [3920] */
    (xdc_Char)0x6c,  /* [3921] */
    (xdc_Char)0x6f,  /* [3922] */
    (xdc_Char)0x63,  /* [3923] */
    (xdc_Char)0x61,  /* [3924] */
    (xdc_Char)0x74,  /* [3925] */
    (xdc_Char)0x65,  /* [3926] */
    (xdc_Char)0x20,  /* [3927] */
    (xdc_Char)0x73,  /* [3928] */
    (xdc_Char)0x69,  /* [3929] */
    (xdc_Char)0x7a,  /* [3930] */
    (xdc_Char)0x65,  /* [3931] */
    (xdc_Char)0x20,  /* [3932] */
    (xdc_Char)0x30,  /* [3933] */
    (xdc_Char)0x0,  /* [3934] */
    (xdc_Char)0x41,  /* [3935] */
    (xdc_Char)0x5f,  /* [3936] */
    (xdc_Char)0x68,  /* [3937] */
    (xdc_Char)0x65,  /* [3938] */
    (xdc_Char)0x61,  /* [3939] */
    (xdc_Char)0x70,  /* [3940] */
    (xdc_Char)0x53,  /* [3941] */
    (xdc_Char)0x69,  /* [3942] */
    (xdc_Char)0x7a,  /* [3943] */
    (xdc_Char)0x65,  /* [3944] */
    (xdc_Char)0x3a,  /* [3945] */
    (xdc_Char)0x20,  /* [3946] */
    (xdc_Char)0x52,  /* [3947] */
    (xdc_Char)0x65,  /* [3948] */
    (xdc_Char)0x71,  /* [3949] */
    (xdc_Char)0x75,  /* [3950] */
    (xdc_Char)0x65,  /* [3951] */
    (xdc_Char)0x73,  /* [3952] */
    (xdc_Char)0x74,  /* [3953] */
    (xdc_Char)0x65,  /* [3954] */
    (xdc_Char)0x64,  /* [3955] */
    (xdc_Char)0x20,  /* [3956] */
    (xdc_Char)0x68,  /* [3957] */
    (xdc_Char)0x65,  /* [3958] */
    (xdc_Char)0x61,  /* [3959] */
    (xdc_Char)0x70,  /* [3960] */
    (xdc_Char)0x20,  /* [3961] */
    (xdc_Char)0x73,  /* [3962] */
    (xdc_Char)0x69,  /* [3963] */
    (xdc_Char)0x7a,  /* [3964] */
    (xdc_Char)0x65,  /* [3965] */
    (xdc_Char)0x20,  /* [3966] */
    (xdc_Char)0x69,  /* [3967] */
    (xdc_Char)0x73,  /* [3968] */
    (xdc_Char)0x20,  /* [3969] */
    (xdc_Char)0x74,  /* [3970] */
    (xdc_Char)0x6f,  /* [3971] */
    (xdc_Char)0x6f,  /* [3972] */
    (xdc_Char)0x20,  /* [3973] */
    (xdc_Char)0x73,  /* [3974] */
    (xdc_Char)0x6d,  /* [3975] */
    (xdc_Char)0x61,  /* [3976] */
    (xdc_Char)0x6c,  /* [3977] */
    (xdc_Char)0x6c,  /* [3978] */
    (xdc_Char)0x0,  /* [3979] */
    (xdc_Char)0x41,  /* [3980] */
    (xdc_Char)0x5f,  /* [3981] */
    (xdc_Char)0x61,  /* [3982] */
    (xdc_Char)0x6c,  /* [3983] */
    (xdc_Char)0x69,  /* [3984] */
    (xdc_Char)0x67,  /* [3985] */
    (xdc_Char)0x6e,  /* [3986] */
    (xdc_Char)0x3a,  /* [3987] */
    (xdc_Char)0x20,  /* [3988] */
    (xdc_Char)0x52,  /* [3989] */
    (xdc_Char)0x65,  /* [3990] */
    (xdc_Char)0x71,  /* [3991] */
    (xdc_Char)0x75,  /* [3992] */
    (xdc_Char)0x65,  /* [3993] */
    (xdc_Char)0x73,  /* [3994] */
    (xdc_Char)0x74,  /* [3995] */
    (xdc_Char)0x65,  /* [3996] */
    (xdc_Char)0x64,  /* [3997] */
    (xdc_Char)0x20,  /* [3998] */
    (xdc_Char)0x61,  /* [3999] */
    (xdc_Char)0x6c,  /* [4000] */
    (xdc_Char)0x69,  /* [4001] */
    (xdc_Char)0x67,  /* [4002] */
    (xdc_Char)0x6e,  /* [4003] */
    (xdc_Char)0x20,  /* [4004] */
    (xdc_Char)0x69,  /* [4005] */
    (xdc_Char)0x73,  /* [4006] */
    (xdc_Char)0x20,  /* [4007] */
    (xdc_Char)0x6e,  /* [4008] */
    (xdc_Char)0x6f,  /* [4009] */
    (xdc_Char)0x74,  /* [4010] */
    (xdc_Char)0x20,  /* [4011] */
    (xdc_Char)0x61,  /* [4012] */
    (xdc_Char)0x20,  /* [4013] */
    (xdc_Char)0x70,  /* [4014] */
    (xdc_Char)0x6f,  /* [4015] */
    (xdc_Char)0x77,  /* [4016] */
    (xdc_Char)0x65,  /* [4017] */
    (xdc_Char)0x72,  /* [4018] */
    (xdc_Char)0x20,  /* [4019] */
    (xdc_Char)0x6f,  /* [4020] */
    (xdc_Char)0x66,  /* [4021] */
    (xdc_Char)0x20,  /* [4022] */
    (xdc_Char)0x32,  /* [4023] */
    (xdc_Char)0x0,  /* [4024] */
    (xdc_Char)0x49,  /* [4025] */
    (xdc_Char)0x6e,  /* [4026] */
    (xdc_Char)0x76,  /* [4027] */
    (xdc_Char)0x61,  /* [4028] */
    (xdc_Char)0x6c,  /* [4029] */
    (xdc_Char)0x69,  /* [4030] */
    (xdc_Char)0x64,  /* [4031] */
    (xdc_Char)0x20,  /* [4032] */
    (xdc_Char)0x62,  /* [4033] */
    (xdc_Char)0x6c,  /* [4034] */
    (xdc_Char)0x6f,  /* [4035] */
    (xdc_Char)0x63,  /* [4036] */
    (xdc_Char)0x6b,  /* [4037] */
    (xdc_Char)0x20,  /* [4038] */
    (xdc_Char)0x61,  /* [4039] */
    (xdc_Char)0x64,  /* [4040] */
    (xdc_Char)0x64,  /* [4041] */
    (xdc_Char)0x72,  /* [4042] */
    (xdc_Char)0x65,  /* [4043] */
    (xdc_Char)0x73,  /* [4044] */
    (xdc_Char)0x73,  /* [4045] */
    (xdc_Char)0x20,  /* [4046] */
    (xdc_Char)0x6f,  /* [4047] */
    (xdc_Char)0x6e,  /* [4048] */
    (xdc_Char)0x20,  /* [4049] */
    (xdc_Char)0x74,  /* [4050] */
    (xdc_Char)0x68,  /* [4051] */
    (xdc_Char)0x65,  /* [4052] */
    (xdc_Char)0x20,  /* [4053] */
    (xdc_Char)0x66,  /* [4054] */
    (xdc_Char)0x72,  /* [4055] */
    (xdc_Char)0x65,  /* [4056] */
    (xdc_Char)0x65,  /* [4057] */
    (xdc_Char)0x2e,  /* [4058] */
    (xdc_Char)0x20,  /* [4059] */
    (xdc_Char)0x46,  /* [4060] */
    (xdc_Char)0x61,  /* [4061] */
    (xdc_Char)0x69,  /* [4062] */
    (xdc_Char)0x6c,  /* [4063] */
    (xdc_Char)0x65,  /* [4064] */
    (xdc_Char)0x64,  /* [4065] */
    (xdc_Char)0x20,  /* [4066] */
    (xdc_Char)0x74,  /* [4067] */
    (xdc_Char)0x6f,  /* [4068] */
    (xdc_Char)0x20,  /* [4069] */
    (xdc_Char)0x66,  /* [4070] */
    (xdc_Char)0x72,  /* [4071] */
    (xdc_Char)0x65,  /* [4072] */
    (xdc_Char)0x65,  /* [4073] */
    (xdc_Char)0x20,  /* [4074] */
    (xdc_Char)0x62,  /* [4075] */
    (xdc_Char)0x6c,  /* [4076] */
    (xdc_Char)0x6f,  /* [4077] */
    (xdc_Char)0x63,  /* [4078] */
    (xdc_Char)0x6b,  /* [4079] */
    (xdc_Char)0x20,  /* [4080] */
    (xdc_Char)0x62,  /* [4081] */
    (xdc_Char)0x61,  /* [4082] */
    (xdc_Char)0x63,  /* [4083] */
    (xdc_Char)0x6b,  /* [4084] */
    (xdc_Char)0x20,  /* [4085] */
    (xdc_Char)0x74,  /* [4086] */
    (xdc_Char)0x6f,  /* [4087] */
    (xdc_Char)0x20,  /* [4088] */
    (xdc_Char)0x68,  /* [4089] */
    (xdc_Char)0x65,  /* [4090] */
    (xdc_Char)0x61,  /* [4091] */
    (xdc_Char)0x70,  /* [4092] */
    (xdc_Char)0x2e,  /* [4093] */
    (xdc_Char)0x0,  /* [4094] */
    (xdc_Char)0x61,  /* [4095] */
    (xdc_Char)0x73,  /* [4096] */
    (xdc_Char)0x73,  /* [4097] */
    (xdc_Char)0x65,  /* [4098] */
    (xdc_Char)0x72,  /* [4099] */
    (xdc_Char)0x74,  /* [4100] */
    (xdc_Char)0x69,  /* [4101] */
    (xdc_Char)0x6f,  /* [4102] */
    (xdc_Char)0x6e,  /* [4103] */
    (xdc_Char)0x20,  /* [4104] */
    (xdc_Char)0x66,  /* [4105] */
    (xdc_Char)0x61,  /* [4106] */
    (xdc_Char)0x69,  /* [4107] */
    (xdc_Char)0x6c,  /* [4108] */
    (xdc_Char)0x75,  /* [4109] */
    (xdc_Char)0x72,  /* [4110] */
    (xdc_Char)0x65,  /* [4111] */
    (xdc_Char)0x25,  /* [4112] */
    (xdc_Char)0x73,  /* [4113] */
    (xdc_Char)0x25,  /* [4114] */
    (xdc_Char)0x73,  /* [4115] */
    (xdc_Char)0x0,  /* [4116] */
    (xdc_Char)0x25,  /* [4117] */
    (xdc_Char)0x24,  /* [4118] */
    (xdc_Char)0x53,  /* [4119] */
    (xdc_Char)0x0,  /* [4120] */
    (xdc_Char)0x6f,  /* [4121] */
    (xdc_Char)0x75,  /* [4122] */
    (xdc_Char)0x74,  /* [4123] */
    (xdc_Char)0x20,  /* [4124] */
    (xdc_Char)0x6f,  /* [4125] */
    (xdc_Char)0x66,  /* [4126] */
    (xdc_Char)0x20,  /* [4127] */
    (xdc_Char)0x6d,  /* [4128] */
    (xdc_Char)0x65,  /* [4129] */
    (xdc_Char)0x6d,  /* [4130] */
    (xdc_Char)0x6f,  /* [4131] */
    (xdc_Char)0x72,  /* [4132] */
    (xdc_Char)0x79,  /* [4133] */
    (xdc_Char)0x3a,  /* [4134] */
    (xdc_Char)0x20,  /* [4135] */
    (xdc_Char)0x68,  /* [4136] */
    (xdc_Char)0x65,  /* [4137] */
    (xdc_Char)0x61,  /* [4138] */
    (xdc_Char)0x70,  /* [4139] */
    (xdc_Char)0x3d,  /* [4140] */
    (xdc_Char)0x30,  /* [4141] */
    (xdc_Char)0x78,  /* [4142] */
    (xdc_Char)0x25,  /* [4143] */
    (xdc_Char)0x78,  /* [4144] */
    (xdc_Char)0x2c,  /* [4145] */
    (xdc_Char)0x20,  /* [4146] */
    (xdc_Char)0x73,  /* [4147] */
    (xdc_Char)0x69,  /* [4148] */
    (xdc_Char)0x7a,  /* [4149] */
    (xdc_Char)0x65,  /* [4150] */
    (xdc_Char)0x3d,  /* [4151] */
    (xdc_Char)0x25,  /* [4152] */
    (xdc_Char)0x75,  /* [4153] */
    (xdc_Char)0x0,  /* [4154] */
    (xdc_Char)0x25,  /* [4155] */
    (xdc_Char)0x73,  /* [4156] */
    (xdc_Char)0x20,  /* [4157] */
    (xdc_Char)0x30,  /* [4158] */
    (xdc_Char)0x78,  /* [4159] */
    (xdc_Char)0x25,  /* [4160] */
    (xdc_Char)0x78,  /* [4161] */
    (xdc_Char)0x0,  /* [4162] */
    (xdc_Char)0x45,  /* [4163] */
    (xdc_Char)0x5f,  /* [4164] */
    (xdc_Char)0x62,  /* [4165] */
    (xdc_Char)0x61,  /* [4166] */
    (xdc_Char)0x64,  /* [4167] */
    (xdc_Char)0x4c,  /* [4168] */
    (xdc_Char)0x65,  /* [4169] */
    (xdc_Char)0x76,  /* [4170] */
    (xdc_Char)0x65,  /* [4171] */
    (xdc_Char)0x6c,  /* [4172] */
    (xdc_Char)0x3a,  /* [4173] */
    (xdc_Char)0x20,  /* [4174] */
    (xdc_Char)0x42,  /* [4175] */
    (xdc_Char)0x61,  /* [4176] */
    (xdc_Char)0x64,  /* [4177] */
    (xdc_Char)0x20,  /* [4178] */
    (xdc_Char)0x66,  /* [4179] */
    (xdc_Char)0x69,  /* [4180] */
    (xdc_Char)0x6c,  /* [4181] */
    (xdc_Char)0x74,  /* [4182] */
    (xdc_Char)0x65,  /* [4183] */
    (xdc_Char)0x72,  /* [4184] */
    (xdc_Char)0x20,  /* [4185] */
    (xdc_Char)0x6c,  /* [4186] */
    (xdc_Char)0x65,  /* [4187] */
    (xdc_Char)0x76,  /* [4188] */
    (xdc_Char)0x65,  /* [4189] */
    (xdc_Char)0x6c,  /* [4190] */
    (xdc_Char)0x20,  /* [4191] */
    (xdc_Char)0x76,  /* [4192] */
    (xdc_Char)0x61,  /* [4193] */
    (xdc_Char)0x6c,  /* [4194] */
    (xdc_Char)0x75,  /* [4195] */
    (xdc_Char)0x65,  /* [4196] */
    (xdc_Char)0x3a,  /* [4197] */
    (xdc_Char)0x20,  /* [4198] */
    (xdc_Char)0x25,  /* [4199] */
    (xdc_Char)0x64,  /* [4200] */
    (xdc_Char)0x0,  /* [4201] */
    (xdc_Char)0x66,  /* [4202] */
    (xdc_Char)0x72,  /* [4203] */
    (xdc_Char)0x65,  /* [4204] */
    (xdc_Char)0x65,  /* [4205] */
    (xdc_Char)0x28,  /* [4206] */
    (xdc_Char)0x29,  /* [4207] */
    (xdc_Char)0x20,  /* [4208] */
    (xdc_Char)0x69,  /* [4209] */
    (xdc_Char)0x6e,  /* [4210] */
    (xdc_Char)0x76,  /* [4211] */
    (xdc_Char)0x61,  /* [4212] */
    (xdc_Char)0x6c,  /* [4213] */
    (xdc_Char)0x69,  /* [4214] */
    (xdc_Char)0x64,  /* [4215] */
    (xdc_Char)0x20,  /* [4216] */
    (xdc_Char)0x69,  /* [4217] */
    (xdc_Char)0x6e,  /* [4218] */
    (xdc_Char)0x20,  /* [4219] */
    (xdc_Char)0x67,  /* [4220] */
    (xdc_Char)0x72,  /* [4221] */
    (xdc_Char)0x6f,  /* [4222] */
    (xdc_Char)0x77,  /* [4223] */
    (xdc_Char)0x74,  /* [4224] */
    (xdc_Char)0x68,  /* [4225] */
    (xdc_Char)0x2d,  /* [4226] */
    (xdc_Char)0x6f,  /* [4227] */
    (xdc_Char)0x6e,  /* [4228] */
    (xdc_Char)0x6c,  /* [4229] */
    (xdc_Char)0x79,  /* [4230] */
    (xdc_Char)0x20,  /* [4231] */
    (xdc_Char)0x48,  /* [4232] */
    (xdc_Char)0x65,  /* [4233] */
    (xdc_Char)0x61,  /* [4234] */
    (xdc_Char)0x70,  /* [4235] */
    (xdc_Char)0x4d,  /* [4236] */
    (xdc_Char)0x69,  /* [4237] */
    (xdc_Char)0x6e,  /* [4238] */
    (xdc_Char)0x0,  /* [4239] */
    (xdc_Char)0x54,  /* [4240] */
    (xdc_Char)0x68,  /* [4241] */
    (xdc_Char)0x65,  /* [4242] */
    (xdc_Char)0x20,  /* [4243] */
    (xdc_Char)0x52,  /* [4244] */
    (xdc_Char)0x54,  /* [4245] */
    (xdc_Char)0x53,  /* [4246] */
    (xdc_Char)0x20,  /* [4247] */
    (xdc_Char)0x68,  /* [4248] */
    (xdc_Char)0x65,  /* [4249] */
    (xdc_Char)0x61,  /* [4250] */
    (xdc_Char)0x70,  /* [4251] */
    (xdc_Char)0x20,  /* [4252] */
    (xdc_Char)0x69,  /* [4253] */
    (xdc_Char)0x73,  /* [4254] */
    (xdc_Char)0x20,  /* [4255] */
    (xdc_Char)0x75,  /* [4256] */
    (xdc_Char)0x73,  /* [4257] */
    (xdc_Char)0x65,  /* [4258] */
    (xdc_Char)0x64,  /* [4259] */
    (xdc_Char)0x20,  /* [4260] */
    (xdc_Char)0x75,  /* [4261] */
    (xdc_Char)0x70,  /* [4262] */
    (xdc_Char)0x2e,  /* [4263] */
    (xdc_Char)0x20,  /* [4264] */
    (xdc_Char)0x45,  /* [4265] */
    (xdc_Char)0x78,  /* [4266] */
    (xdc_Char)0x61,  /* [4267] */
    (xdc_Char)0x6d,  /* [4268] */
    (xdc_Char)0x69,  /* [4269] */
    (xdc_Char)0x6e,  /* [4270] */
    (xdc_Char)0x65,  /* [4271] */
    (xdc_Char)0x20,  /* [4272] */
    (xdc_Char)0x50,  /* [4273] */
    (xdc_Char)0x72,  /* [4274] */
    (xdc_Char)0x6f,  /* [4275] */
    (xdc_Char)0x67,  /* [4276] */
    (xdc_Char)0x72,  /* [4277] */
    (xdc_Char)0x61,  /* [4278] */
    (xdc_Char)0x6d,  /* [4279] */
    (xdc_Char)0x2e,  /* [4280] */
    (xdc_Char)0x68,  /* [4281] */
    (xdc_Char)0x65,  /* [4282] */
    (xdc_Char)0x61,  /* [4283] */
    (xdc_Char)0x70,  /* [4284] */
    (xdc_Char)0x2e,  /* [4285] */
    (xdc_Char)0x0,  /* [4286] */
    (xdc_Char)0x45,  /* [4287] */
    (xdc_Char)0x5f,  /* [4288] */
    (xdc_Char)0x62,  /* [4289] */
    (xdc_Char)0x61,  /* [4290] */
    (xdc_Char)0x64,  /* [4291] */
    (xdc_Char)0x43,  /* [4292] */
    (xdc_Char)0x6f,  /* [4293] */
    (xdc_Char)0x6d,  /* [4294] */
    (xdc_Char)0x6d,  /* [4295] */
    (xdc_Char)0x61,  /* [4296] */
    (xdc_Char)0x6e,  /* [4297] */
    (xdc_Char)0x64,  /* [4298] */
    (xdc_Char)0x3a,  /* [4299] */
    (xdc_Char)0x20,  /* [4300] */
    (xdc_Char)0x52,  /* [4301] */
    (xdc_Char)0x65,  /* [4302] */
    (xdc_Char)0x63,  /* [4303] */
    (xdc_Char)0x65,  /* [4304] */
    (xdc_Char)0x69,  /* [4305] */
    (xdc_Char)0x76,  /* [4306] */
    (xdc_Char)0x65,  /* [4307] */
    (xdc_Char)0x64,  /* [4308] */
    (xdc_Char)0x20,  /* [4309] */
    (xdc_Char)0x69,  /* [4310] */
    (xdc_Char)0x6e,  /* [4311] */
    (xdc_Char)0x76,  /* [4312] */
    (xdc_Char)0x61,  /* [4313] */
    (xdc_Char)0x6c,  /* [4314] */
    (xdc_Char)0x69,  /* [4315] */
    (xdc_Char)0x64,  /* [4316] */
    (xdc_Char)0x20,  /* [4317] */
    (xdc_Char)0x63,  /* [4318] */
    (xdc_Char)0x6f,  /* [4319] */
    (xdc_Char)0x6d,  /* [4320] */
    (xdc_Char)0x6d,  /* [4321] */
    (xdc_Char)0x61,  /* [4322] */
    (xdc_Char)0x6e,  /* [4323] */
    (xdc_Char)0x64,  /* [4324] */
    (xdc_Char)0x2c,  /* [4325] */
    (xdc_Char)0x20,  /* [4326] */
    (xdc_Char)0x69,  /* [4327] */
    (xdc_Char)0x64,  /* [4328] */
    (xdc_Char)0x3a,  /* [4329] */
    (xdc_Char)0x20,  /* [4330] */
    (xdc_Char)0x25,  /* [4331] */
    (xdc_Char)0x64,  /* [4332] */
    (xdc_Char)0x2e,  /* [4333] */
    (xdc_Char)0x0,  /* [4334] */
    (xdc_Char)0x45,  /* [4335] */
    (xdc_Char)0x5f,  /* [4336] */
    (xdc_Char)0x75,  /* [4337] */
    (xdc_Char)0x6e,  /* [4338] */
    (xdc_Char)0x70,  /* [4339] */
    (xdc_Char)0x6c,  /* [4340] */
    (xdc_Char)0x75,  /* [4341] */
    (xdc_Char)0x67,  /* [4342] */
    (xdc_Char)0x67,  /* [4343] */
    (xdc_Char)0x65,  /* [4344] */
    (xdc_Char)0x64,  /* [4345] */
    (xdc_Char)0x45,  /* [4346] */
    (xdc_Char)0x76,  /* [4347] */
    (xdc_Char)0x65,  /* [4348] */
    (xdc_Char)0x6e,  /* [4349] */
    (xdc_Char)0x74,  /* [4350] */
    (xdc_Char)0x3a,  /* [4351] */
    (xdc_Char)0x20,  /* [4352] */
    (xdc_Char)0x45,  /* [4353] */
    (xdc_Char)0x76,  /* [4354] */
    (xdc_Char)0x65,  /* [4355] */
    (xdc_Char)0x6e,  /* [4356] */
    (xdc_Char)0x74,  /* [4357] */
    (xdc_Char)0x23,  /* [4358] */
    (xdc_Char)0x20,  /* [4359] */
    (xdc_Char)0x25,  /* [4360] */
    (xdc_Char)0x64,  /* [4361] */
    (xdc_Char)0x20,  /* [4362] */
    (xdc_Char)0x69,  /* [4363] */
    (xdc_Char)0x73,  /* [4364] */
    (xdc_Char)0x20,  /* [4365] */
    (xdc_Char)0x75,  /* [4366] */
    (xdc_Char)0x6e,  /* [4367] */
    (xdc_Char)0x70,  /* [4368] */
    (xdc_Char)0x6c,  /* [4369] */
    (xdc_Char)0x75,  /* [4370] */
    (xdc_Char)0x67,  /* [4371] */
    (xdc_Char)0x67,  /* [4372] */
    (xdc_Char)0x65,  /* [4373] */
    (xdc_Char)0x64,  /* [4374] */
    (xdc_Char)0x0,  /* [4375] */
    (xdc_Char)0x45,  /* [4376] */
    (xdc_Char)0x5f,  /* [4377] */
    (xdc_Char)0x65,  /* [4378] */
    (xdc_Char)0x78,  /* [4379] */
    (xdc_Char)0x63,  /* [4380] */
    (xdc_Char)0x65,  /* [4381] */
    (xdc_Char)0x70,  /* [4382] */
    (xdc_Char)0x74,  /* [4383] */
    (xdc_Char)0x69,  /* [4384] */
    (xdc_Char)0x6f,  /* [4385] */
    (xdc_Char)0x6e,  /* [4386] */
    (xdc_Char)0x4d,  /* [4387] */
    (xdc_Char)0x69,  /* [4388] */
    (xdc_Char)0x6e,  /* [4389] */
    (xdc_Char)0x3a,  /* [4390] */
    (xdc_Char)0x20,  /* [4391] */
    (xdc_Char)0x70,  /* [4392] */
    (xdc_Char)0x63,  /* [4393] */
    (xdc_Char)0x20,  /* [4394] */
    (xdc_Char)0x3d,  /* [4395] */
    (xdc_Char)0x20,  /* [4396] */
    (xdc_Char)0x30,  /* [4397] */
    (xdc_Char)0x78,  /* [4398] */
    (xdc_Char)0x25,  /* [4399] */
    (xdc_Char)0x30,  /* [4400] */
    (xdc_Char)0x38,  /* [4401] */
    (xdc_Char)0x78,  /* [4402] */
    (xdc_Char)0x2c,  /* [4403] */
    (xdc_Char)0x20,  /* [4404] */
    (xdc_Char)0x73,  /* [4405] */
    (xdc_Char)0x70,  /* [4406] */
    (xdc_Char)0x20,  /* [4407] */
    (xdc_Char)0x3d,  /* [4408] */
    (xdc_Char)0x20,  /* [4409] */
    (xdc_Char)0x30,  /* [4410] */
    (xdc_Char)0x78,  /* [4411] */
    (xdc_Char)0x25,  /* [4412] */
    (xdc_Char)0x30,  /* [4413] */
    (xdc_Char)0x38,  /* [4414] */
    (xdc_Char)0x78,  /* [4415] */
    (xdc_Char)0x2e,  /* [4416] */
    (xdc_Char)0xa,  /* [4417] */
    (xdc_Char)0x54,  /* [4418] */
    (xdc_Char)0x6f,  /* [4419] */
    (xdc_Char)0x20,  /* [4420] */
    (xdc_Char)0x73,  /* [4421] */
    (xdc_Char)0x65,  /* [4422] */
    (xdc_Char)0x65,  /* [4423] */
    (xdc_Char)0x20,  /* [4424] */
    (xdc_Char)0x6d,  /* [4425] */
    (xdc_Char)0x6f,  /* [4426] */
    (xdc_Char)0x72,  /* [4427] */
    (xdc_Char)0x65,  /* [4428] */
    (xdc_Char)0x20,  /* [4429] */
    (xdc_Char)0x65,  /* [4430] */
    (xdc_Char)0x78,  /* [4431] */
    (xdc_Char)0x63,  /* [4432] */
    (xdc_Char)0x65,  /* [4433] */
    (xdc_Char)0x70,  /* [4434] */
    (xdc_Char)0x74,  /* [4435] */
    (xdc_Char)0x69,  /* [4436] */
    (xdc_Char)0x6f,  /* [4437] */
    (xdc_Char)0x6e,  /* [4438] */
    (xdc_Char)0x20,  /* [4439] */
    (xdc_Char)0x64,  /* [4440] */
    (xdc_Char)0x65,  /* [4441] */
    (xdc_Char)0x74,  /* [4442] */
    (xdc_Char)0x61,  /* [4443] */
    (xdc_Char)0x69,  /* [4444] */
    (xdc_Char)0x6c,  /* [4445] */
    (xdc_Char)0x2c,  /* [4446] */
    (xdc_Char)0x20,  /* [4447] */
    (xdc_Char)0x75,  /* [4448] */
    (xdc_Char)0x73,  /* [4449] */
    (xdc_Char)0x65,  /* [4450] */
    (xdc_Char)0x20,  /* [4451] */
    (xdc_Char)0x52,  /* [4452] */
    (xdc_Char)0x4f,  /* [4453] */
    (xdc_Char)0x56,  /* [4454] */
    (xdc_Char)0x20,  /* [4455] */
    (xdc_Char)0x6f,  /* [4456] */
    (xdc_Char)0x72,  /* [4457] */
    (xdc_Char)0x20,  /* [4458] */
    (xdc_Char)0x73,  /* [4459] */
    (xdc_Char)0x65,  /* [4460] */
    (xdc_Char)0x74,  /* [4461] */
    (xdc_Char)0x20,  /* [4462] */
    (xdc_Char)0x27,  /* [4463] */
    (xdc_Char)0x74,  /* [4464] */
    (xdc_Char)0x69,  /* [4465] */
    (xdc_Char)0x2e,  /* [4466] */
    (xdc_Char)0x73,  /* [4467] */
    (xdc_Char)0x79,  /* [4468] */
    (xdc_Char)0x73,  /* [4469] */
    (xdc_Char)0x62,  /* [4470] */
    (xdc_Char)0x69,  /* [4471] */
    (xdc_Char)0x6f,  /* [4472] */
    (xdc_Char)0x73,  /* [4473] */
    (xdc_Char)0x2e,  /* [4474] */
    (xdc_Char)0x66,  /* [4475] */
    (xdc_Char)0x61,  /* [4476] */
    (xdc_Char)0x6d,  /* [4477] */
    (xdc_Char)0x69,  /* [4478] */
    (xdc_Char)0x6c,  /* [4479] */
    (xdc_Char)0x79,  /* [4480] */
    (xdc_Char)0x2e,  /* [4481] */
    (xdc_Char)0x63,  /* [4482] */
    (xdc_Char)0x36,  /* [4483] */
    (xdc_Char)0x34,  /* [4484] */
    (xdc_Char)0x70,  /* [4485] */
    (xdc_Char)0x2e,  /* [4486] */
    (xdc_Char)0x45,  /* [4487] */
    (xdc_Char)0x78,  /* [4488] */
    (xdc_Char)0x63,  /* [4489] */
    (xdc_Char)0x65,  /* [4490] */
    (xdc_Char)0x70,  /* [4491] */
    (xdc_Char)0x74,  /* [4492] */
    (xdc_Char)0x69,  /* [4493] */
    (xdc_Char)0x6f,  /* [4494] */
    (xdc_Char)0x6e,  /* [4495] */
    (xdc_Char)0x2e,  /* [4496] */
    (xdc_Char)0x65,  /* [4497] */
    (xdc_Char)0x6e,  /* [4498] */
    (xdc_Char)0x61,  /* [4499] */
    (xdc_Char)0x62,  /* [4500] */
    (xdc_Char)0x6c,  /* [4501] */
    (xdc_Char)0x65,  /* [4502] */
    (xdc_Char)0x50,  /* [4503] */
    (xdc_Char)0x72,  /* [4504] */
    (xdc_Char)0x69,  /* [4505] */
    (xdc_Char)0x6e,  /* [4506] */
    (xdc_Char)0x74,  /* [4507] */
    (xdc_Char)0x20,  /* [4508] */
    (xdc_Char)0x3d,  /* [4509] */
    (xdc_Char)0x20,  /* [4510] */
    (xdc_Char)0x74,  /* [4511] */
    (xdc_Char)0x72,  /* [4512] */
    (xdc_Char)0x75,  /* [4513] */
    (xdc_Char)0x65,  /* [4514] */
    (xdc_Char)0x3b,  /* [4515] */
    (xdc_Char)0x27,  /* [4516] */
    (xdc_Char)0x0,  /* [4517] */
    (xdc_Char)0x45,  /* [4518] */
    (xdc_Char)0x5f,  /* [4519] */
    (xdc_Char)0x65,  /* [4520] */
    (xdc_Char)0x78,  /* [4521] */
    (xdc_Char)0x63,  /* [4522] */
    (xdc_Char)0x65,  /* [4523] */
    (xdc_Char)0x70,  /* [4524] */
    (xdc_Char)0x74,  /* [4525] */
    (xdc_Char)0x69,  /* [4526] */
    (xdc_Char)0x6f,  /* [4527] */
    (xdc_Char)0x6e,  /* [4528] */
    (xdc_Char)0x4d,  /* [4529] */
    (xdc_Char)0x61,  /* [4530] */
    (xdc_Char)0x78,  /* [4531] */
    (xdc_Char)0x3a,  /* [4532] */
    (xdc_Char)0x20,  /* [4533] */
    (xdc_Char)0x70,  /* [4534] */
    (xdc_Char)0x63,  /* [4535] */
    (xdc_Char)0x20,  /* [4536] */
    (xdc_Char)0x3d,  /* [4537] */
    (xdc_Char)0x20,  /* [4538] */
    (xdc_Char)0x30,  /* [4539] */
    (xdc_Char)0x78,  /* [4540] */
    (xdc_Char)0x25,  /* [4541] */
    (xdc_Char)0x30,  /* [4542] */
    (xdc_Char)0x38,  /* [4543] */
    (xdc_Char)0x78,  /* [4544] */
    (xdc_Char)0x2c,  /* [4545] */
    (xdc_Char)0x20,  /* [4546] */
    (xdc_Char)0x73,  /* [4547] */
    (xdc_Char)0x70,  /* [4548] */
    (xdc_Char)0x20,  /* [4549] */
    (xdc_Char)0x3d,  /* [4550] */
    (xdc_Char)0x20,  /* [4551] */
    (xdc_Char)0x30,  /* [4552] */
    (xdc_Char)0x78,  /* [4553] */
    (xdc_Char)0x25,  /* [4554] */
    (xdc_Char)0x30,  /* [4555] */
    (xdc_Char)0x38,  /* [4556] */
    (xdc_Char)0x78,  /* [4557] */
    (xdc_Char)0x2e,  /* [4558] */
    (xdc_Char)0x0,  /* [4559] */
    (xdc_Char)0x45,  /* [4560] */
    (xdc_Char)0x5f,  /* [4561] */
    (xdc_Char)0x61,  /* [4562] */
    (xdc_Char)0x6c,  /* [4563] */
    (xdc_Char)0x72,  /* [4564] */
    (xdc_Char)0x65,  /* [4565] */
    (xdc_Char)0x61,  /* [4566] */
    (xdc_Char)0x64,  /* [4567] */
    (xdc_Char)0x79,  /* [4568] */
    (xdc_Char)0x44,  /* [4569] */
    (xdc_Char)0x65,  /* [4570] */
    (xdc_Char)0x66,  /* [4571] */
    (xdc_Char)0x69,  /* [4572] */
    (xdc_Char)0x6e,  /* [4573] */
    (xdc_Char)0x65,  /* [4574] */
    (xdc_Char)0x64,  /* [4575] */
    (xdc_Char)0x3a,  /* [4576] */
    (xdc_Char)0x20,  /* [4577] */
    (xdc_Char)0x48,  /* [4578] */
    (xdc_Char)0x77,  /* [4579] */
    (xdc_Char)0x69,  /* [4580] */
    (xdc_Char)0x20,  /* [4581] */
    (xdc_Char)0x61,  /* [4582] */
    (xdc_Char)0x6c,  /* [4583] */
    (xdc_Char)0x72,  /* [4584] */
    (xdc_Char)0x65,  /* [4585] */
    (xdc_Char)0x61,  /* [4586] */
    (xdc_Char)0x64,  /* [4587] */
    (xdc_Char)0x79,  /* [4588] */
    (xdc_Char)0x20,  /* [4589] */
    (xdc_Char)0x64,  /* [4590] */
    (xdc_Char)0x65,  /* [4591] */
    (xdc_Char)0x66,  /* [4592] */
    (xdc_Char)0x69,  /* [4593] */
    (xdc_Char)0x6e,  /* [4594] */
    (xdc_Char)0x65,  /* [4595] */
    (xdc_Char)0x64,  /* [4596] */
    (xdc_Char)0x3a,  /* [4597] */
    (xdc_Char)0x20,  /* [4598] */
    (xdc_Char)0x69,  /* [4599] */
    (xdc_Char)0x6e,  /* [4600] */
    (xdc_Char)0x74,  /* [4601] */
    (xdc_Char)0x72,  /* [4602] */
    (xdc_Char)0x23,  /* [4603] */
    (xdc_Char)0x20,  /* [4604] */
    (xdc_Char)0x25,  /* [4605] */
    (xdc_Char)0x64,  /* [4606] */
    (xdc_Char)0x0,  /* [4607] */
    (xdc_Char)0x45,  /* [4608] */
    (xdc_Char)0x5f,  /* [4609] */
    (xdc_Char)0x73,  /* [4610] */
    (xdc_Char)0x74,  /* [4611] */
    (xdc_Char)0x61,  /* [4612] */
    (xdc_Char)0x63,  /* [4613] */
    (xdc_Char)0x6b,  /* [4614] */
    (xdc_Char)0x4f,  /* [4615] */
    (xdc_Char)0x76,  /* [4616] */
    (xdc_Char)0x65,  /* [4617] */
    (xdc_Char)0x72,  /* [4618] */
    (xdc_Char)0x66,  /* [4619] */
    (xdc_Char)0x6c,  /* [4620] */
    (xdc_Char)0x6f,  /* [4621] */
    (xdc_Char)0x77,  /* [4622] */
    (xdc_Char)0x3a,  /* [4623] */
    (xdc_Char)0x20,  /* [4624] */
    (xdc_Char)0x49,  /* [4625] */
    (xdc_Char)0x53,  /* [4626] */
    (xdc_Char)0x52,  /* [4627] */
    (xdc_Char)0x20,  /* [4628] */
    (xdc_Char)0x73,  /* [4629] */
    (xdc_Char)0x74,  /* [4630] */
    (xdc_Char)0x61,  /* [4631] */
    (xdc_Char)0x63,  /* [4632] */
    (xdc_Char)0x6b,  /* [4633] */
    (xdc_Char)0x20,  /* [4634] */
    (xdc_Char)0x6f,  /* [4635] */
    (xdc_Char)0x76,  /* [4636] */
    (xdc_Char)0x65,  /* [4637] */
    (xdc_Char)0x72,  /* [4638] */
    (xdc_Char)0x66,  /* [4639] */
    (xdc_Char)0x6c,  /* [4640] */
    (xdc_Char)0x6f,  /* [4641] */
    (xdc_Char)0x77,  /* [4642] */
    (xdc_Char)0x2e,  /* [4643] */
    (xdc_Char)0x0,  /* [4644] */
    (xdc_Char)0x45,  /* [4645] */
    (xdc_Char)0x5f,  /* [4646] */
    (xdc_Char)0x73,  /* [4647] */
    (xdc_Char)0x74,  /* [4648] */
    (xdc_Char)0x61,  /* [4649] */
    (xdc_Char)0x63,  /* [4650] */
    (xdc_Char)0x6b,  /* [4651] */
    (xdc_Char)0x4f,  /* [4652] */
    (xdc_Char)0x76,  /* [4653] */
    (xdc_Char)0x65,  /* [4654] */
    (xdc_Char)0x72,  /* [4655] */
    (xdc_Char)0x66,  /* [4656] */
    (xdc_Char)0x6c,  /* [4657] */
    (xdc_Char)0x6f,  /* [4658] */
    (xdc_Char)0x77,  /* [4659] */
    (xdc_Char)0x3a,  /* [4660] */
    (xdc_Char)0x20,  /* [4661] */
    (xdc_Char)0x54,  /* [4662] */
    (xdc_Char)0x61,  /* [4663] */
    (xdc_Char)0x73,  /* [4664] */
    (xdc_Char)0x6b,  /* [4665] */
    (xdc_Char)0x20,  /* [4666] */
    (xdc_Char)0x30,  /* [4667] */
    (xdc_Char)0x78,  /* [4668] */
    (xdc_Char)0x25,  /* [4669] */
    (xdc_Char)0x78,  /* [4670] */
    (xdc_Char)0x20,  /* [4671] */
    (xdc_Char)0x73,  /* [4672] */
    (xdc_Char)0x74,  /* [4673] */
    (xdc_Char)0x61,  /* [4674] */
    (xdc_Char)0x63,  /* [4675] */
    (xdc_Char)0x6b,  /* [4676] */
    (xdc_Char)0x20,  /* [4677] */
    (xdc_Char)0x6f,  /* [4678] */
    (xdc_Char)0x76,  /* [4679] */
    (xdc_Char)0x65,  /* [4680] */
    (xdc_Char)0x72,  /* [4681] */
    (xdc_Char)0x66,  /* [4682] */
    (xdc_Char)0x6c,  /* [4683] */
    (xdc_Char)0x6f,  /* [4684] */
    (xdc_Char)0x77,  /* [4685] */
    (xdc_Char)0x2e,  /* [4686] */
    (xdc_Char)0x0,  /* [4687] */
    (xdc_Char)0x45,  /* [4688] */
    (xdc_Char)0x5f,  /* [4689] */
    (xdc_Char)0x73,  /* [4690] */
    (xdc_Char)0x70,  /* [4691] */
    (xdc_Char)0x4f,  /* [4692] */
    (xdc_Char)0x75,  /* [4693] */
    (xdc_Char)0x74,  /* [4694] */
    (xdc_Char)0x4f,  /* [4695] */
    (xdc_Char)0x66,  /* [4696] */
    (xdc_Char)0x42,  /* [4697] */
    (xdc_Char)0x6f,  /* [4698] */
    (xdc_Char)0x75,  /* [4699] */
    (xdc_Char)0x6e,  /* [4700] */
    (xdc_Char)0x64,  /* [4701] */
    (xdc_Char)0x73,  /* [4702] */
    (xdc_Char)0x3a,  /* [4703] */
    (xdc_Char)0x20,  /* [4704] */
    (xdc_Char)0x54,  /* [4705] */
    (xdc_Char)0x61,  /* [4706] */
    (xdc_Char)0x73,  /* [4707] */
    (xdc_Char)0x6b,  /* [4708] */
    (xdc_Char)0x20,  /* [4709] */
    (xdc_Char)0x30,  /* [4710] */
    (xdc_Char)0x78,  /* [4711] */
    (xdc_Char)0x25,  /* [4712] */
    (xdc_Char)0x78,  /* [4713] */
    (xdc_Char)0x20,  /* [4714] */
    (xdc_Char)0x73,  /* [4715] */
    (xdc_Char)0x74,  /* [4716] */
    (xdc_Char)0x61,  /* [4717] */
    (xdc_Char)0x63,  /* [4718] */
    (xdc_Char)0x6b,  /* [4719] */
    (xdc_Char)0x20,  /* [4720] */
    (xdc_Char)0x65,  /* [4721] */
    (xdc_Char)0x72,  /* [4722] */
    (xdc_Char)0x72,  /* [4723] */
    (xdc_Char)0x6f,  /* [4724] */
    (xdc_Char)0x72,  /* [4725] */
    (xdc_Char)0x2c,  /* [4726] */
    (xdc_Char)0x20,  /* [4727] */
    (xdc_Char)0x53,  /* [4728] */
    (xdc_Char)0x50,  /* [4729] */
    (xdc_Char)0x20,  /* [4730] */
    (xdc_Char)0x3d,  /* [4731] */
    (xdc_Char)0x20,  /* [4732] */
    (xdc_Char)0x30,  /* [4733] */
    (xdc_Char)0x78,  /* [4734] */
    (xdc_Char)0x25,  /* [4735] */
    (xdc_Char)0x78,  /* [4736] */
    (xdc_Char)0x2e,  /* [4737] */
    (xdc_Char)0x0,  /* [4738] */
    (xdc_Char)0x45,  /* [4739] */
    (xdc_Char)0x5f,  /* [4740] */
    (xdc_Char)0x6d,  /* [4741] */
    (xdc_Char)0x61,  /* [4742] */
    (xdc_Char)0x78,  /* [4743] */
    (xdc_Char)0x52,  /* [4744] */
    (xdc_Char)0x65,  /* [4745] */
    (xdc_Char)0x61,  /* [4746] */
    (xdc_Char)0x63,  /* [4747] */
    (xdc_Char)0x68,  /* [4748] */
    (xdc_Char)0x65,  /* [4749] */
    (xdc_Char)0x64,  /* [4750] */
    (xdc_Char)0x3a,  /* [4751] */
    (xdc_Char)0x20,  /* [4752] */
    (xdc_Char)0x41,  /* [4753] */
    (xdc_Char)0x6c,  /* [4754] */
    (xdc_Char)0x6c,  /* [4755] */
    (xdc_Char)0x20,  /* [4756] */
    (xdc_Char)0x65,  /* [4757] */
    (xdc_Char)0x6e,  /* [4758] */
    (xdc_Char)0x74,  /* [4759] */
    (xdc_Char)0x72,  /* [4760] */
    (xdc_Char)0x69,  /* [4761] */
    (xdc_Char)0x65,  /* [4762] */
    (xdc_Char)0x73,  /* [4763] */
    (xdc_Char)0x20,  /* [4764] */
    (xdc_Char)0x69,  /* [4765] */
    (xdc_Char)0x6e,  /* [4766] */
    (xdc_Char)0x20,  /* [4767] */
    (xdc_Char)0x75,  /* [4768] */
    (xdc_Char)0x73,  /* [4769] */
    (xdc_Char)0x65,  /* [4770] */
    (xdc_Char)0x2e,  /* [4771] */
    (xdc_Char)0x20,  /* [4772] */
    (xdc_Char)0x4e,  /* [4773] */
    (xdc_Char)0x61,  /* [4774] */
    (xdc_Char)0x6d,  /* [4775] */
    (xdc_Char)0x65,  /* [4776] */
    (xdc_Char)0x53,  /* [4777] */
    (xdc_Char)0x65,  /* [4778] */
    (xdc_Char)0x72,  /* [4779] */
    (xdc_Char)0x76,  /* [4780] */
    (xdc_Char)0x65,  /* [4781] */
    (xdc_Char)0x72,  /* [4782] */
    (xdc_Char)0x2e,  /* [4783] */
    (xdc_Char)0x6d,  /* [4784] */
    (xdc_Char)0x61,  /* [4785] */
    (xdc_Char)0x78,  /* [4786] */
    (xdc_Char)0x52,  /* [4787] */
    (xdc_Char)0x75,  /* [4788] */
    (xdc_Char)0x6e,  /* [4789] */
    (xdc_Char)0x74,  /* [4790] */
    (xdc_Char)0x69,  /* [4791] */
    (xdc_Char)0x6d,  /* [4792] */
    (xdc_Char)0x65,  /* [4793] */
    (xdc_Char)0x45,  /* [4794] */
    (xdc_Char)0x6e,  /* [4795] */
    (xdc_Char)0x74,  /* [4796] */
    (xdc_Char)0x72,  /* [4797] */
    (xdc_Char)0x69,  /* [4798] */
    (xdc_Char)0x65,  /* [4799] */
    (xdc_Char)0x73,  /* [4800] */
    (xdc_Char)0x20,  /* [4801] */
    (xdc_Char)0x69,  /* [4802] */
    (xdc_Char)0x73,  /* [4803] */
    (xdc_Char)0x20,  /* [4804] */
    (xdc_Char)0x25,  /* [4805] */
    (xdc_Char)0x64,  /* [4806] */
    (xdc_Char)0x0,  /* [4807] */
    (xdc_Char)0x45,  /* [4808] */
    (xdc_Char)0x5f,  /* [4809] */
    (xdc_Char)0x65,  /* [4810] */
    (xdc_Char)0x6e,  /* [4811] */
    (xdc_Char)0x74,  /* [4812] */
    (xdc_Char)0x72,  /* [4813] */
    (xdc_Char)0x79,  /* [4814] */
    (xdc_Char)0x45,  /* [4815] */
    (xdc_Char)0x78,  /* [4816] */
    (xdc_Char)0x69,  /* [4817] */
    (xdc_Char)0x73,  /* [4818] */
    (xdc_Char)0x74,  /* [4819] */
    (xdc_Char)0x73,  /* [4820] */
    (xdc_Char)0x3a,  /* [4821] */
    (xdc_Char)0x20,  /* [4822] */
    (xdc_Char)0x25,  /* [4823] */
    (xdc_Char)0x73,  /* [4824] */
    (xdc_Char)0x20,  /* [4825] */
    (xdc_Char)0x6e,  /* [4826] */
    (xdc_Char)0x61,  /* [4827] */
    (xdc_Char)0x6d,  /* [4828] */
    (xdc_Char)0x65,  /* [4829] */
    (xdc_Char)0x20,  /* [4830] */
    (xdc_Char)0x61,  /* [4831] */
    (xdc_Char)0x6c,  /* [4832] */
    (xdc_Char)0x72,  /* [4833] */
    (xdc_Char)0x65,  /* [4834] */
    (xdc_Char)0x61,  /* [4835] */
    (xdc_Char)0x64,  /* [4836] */
    (xdc_Char)0x79,  /* [4837] */
    (xdc_Char)0x20,  /* [4838] */
    (xdc_Char)0x69,  /* [4839] */
    (xdc_Char)0x6e,  /* [4840] */
    (xdc_Char)0x20,  /* [4841] */
    (xdc_Char)0x74,  /* [4842] */
    (xdc_Char)0x61,  /* [4843] */
    (xdc_Char)0x62,  /* [4844] */
    (xdc_Char)0x6c,  /* [4845] */
    (xdc_Char)0x65,  /* [4846] */
    (xdc_Char)0x20,  /* [4847] */
    (xdc_Char)0x0,  /* [4848] */
    (xdc_Char)0x45,  /* [4849] */
    (xdc_Char)0x5f,  /* [4850] */
    (xdc_Char)0x67,  /* [4851] */
    (xdc_Char)0x61,  /* [4852] */
    (xdc_Char)0x74,  /* [4853] */
    (xdc_Char)0x65,  /* [4854] */
    (xdc_Char)0x55,  /* [4855] */
    (xdc_Char)0x6e,  /* [4856] */
    (xdc_Char)0x61,  /* [4857] */
    (xdc_Char)0x76,  /* [4858] */
    (xdc_Char)0x61,  /* [4859] */
    (xdc_Char)0x69,  /* [4860] */
    (xdc_Char)0x6c,  /* [4861] */
    (xdc_Char)0x61,  /* [4862] */
    (xdc_Char)0x62,  /* [4863] */
    (xdc_Char)0x6c,  /* [4864] */
    (xdc_Char)0x65,  /* [4865] */
    (xdc_Char)0x3a,  /* [4866] */
    (xdc_Char)0x20,  /* [4867] */
    (xdc_Char)0x4e,  /* [4868] */
    (xdc_Char)0x6f,  /* [4869] */
    (xdc_Char)0x20,  /* [4870] */
    (xdc_Char)0x67,  /* [4871] */
    (xdc_Char)0x61,  /* [4872] */
    (xdc_Char)0x74,  /* [4873] */
    (xdc_Char)0x65,  /* [4874] */
    (xdc_Char)0x73,  /* [4875] */
    (xdc_Char)0x20,  /* [4876] */
    (xdc_Char)0x6f,  /* [4877] */
    (xdc_Char)0x66,  /* [4878] */
    (xdc_Char)0x20,  /* [4879] */
    (xdc_Char)0x72,  /* [4880] */
    (xdc_Char)0x65,  /* [4881] */
    (xdc_Char)0x71,  /* [4882] */
    (xdc_Char)0x75,  /* [4883] */
    (xdc_Char)0x65,  /* [4884] */
    (xdc_Char)0x73,  /* [4885] */
    (xdc_Char)0x74,  /* [4886] */
    (xdc_Char)0x65,  /* [4887] */
    (xdc_Char)0x64,  /* [4888] */
    (xdc_Char)0x20,  /* [4889] */
    (xdc_Char)0x74,  /* [4890] */
    (xdc_Char)0x79,  /* [4891] */
    (xdc_Char)0x70,  /* [4892] */
    (xdc_Char)0x65,  /* [4893] */
    (xdc_Char)0x20,  /* [4894] */
    (xdc_Char)0x61,  /* [4895] */
    (xdc_Char)0x72,  /* [4896] */
    (xdc_Char)0x65,  /* [4897] */
    (xdc_Char)0x20,  /* [4898] */
    (xdc_Char)0x61,  /* [4899] */
    (xdc_Char)0x76,  /* [4900] */
    (xdc_Char)0x61,  /* [4901] */
    (xdc_Char)0x69,  /* [4902] */
    (xdc_Char)0x6c,  /* [4903] */
    (xdc_Char)0x61,  /* [4904] */
    (xdc_Char)0x62,  /* [4905] */
    (xdc_Char)0x6c,  /* [4906] */
    (xdc_Char)0x65,  /* [4907] */
    (xdc_Char)0x0,  /* [4908] */
    (xdc_Char)0x45,  /* [4909] */
    (xdc_Char)0x5f,  /* [4910] */
    (xdc_Char)0x6c,  /* [4911] */
    (xdc_Char)0x6f,  /* [4912] */
    (xdc_Char)0x63,  /* [4913] */
    (xdc_Char)0x61,  /* [4914] */
    (xdc_Char)0x6c,  /* [4915] */
    (xdc_Char)0x47,  /* [4916] */
    (xdc_Char)0x61,  /* [4917] */
    (xdc_Char)0x74,  /* [4918] */
    (xdc_Char)0x65,  /* [4919] */
    (xdc_Char)0x3a,  /* [4920] */
    (xdc_Char)0x20,  /* [4921] */
    (xdc_Char)0x4f,  /* [4922] */
    (xdc_Char)0x6e,  /* [4923] */
    (xdc_Char)0x6c,  /* [4924] */
    (xdc_Char)0x79,  /* [4925] */
    (xdc_Char)0x20,  /* [4926] */
    (xdc_Char)0x63,  /* [4927] */
    (xdc_Char)0x72,  /* [4928] */
    (xdc_Char)0x65,  /* [4929] */
    (xdc_Char)0x61,  /* [4930] */
    (xdc_Char)0x74,  /* [4931] */
    (xdc_Char)0x6f,  /* [4932] */
    (xdc_Char)0x72,  /* [4933] */
    (xdc_Char)0x20,  /* [4934] */
    (xdc_Char)0x63,  /* [4935] */
    (xdc_Char)0x61,  /* [4936] */
    (xdc_Char)0x6e,  /* [4937] */
    (xdc_Char)0x20,  /* [4938] */
    (xdc_Char)0x6f,  /* [4939] */
    (xdc_Char)0x70,  /* [4940] */
    (xdc_Char)0x65,  /* [4941] */
    (xdc_Char)0x6e,  /* [4942] */
    (xdc_Char)0x20,  /* [4943] */
    (xdc_Char)0x6c,  /* [4944] */
    (xdc_Char)0x6f,  /* [4945] */
    (xdc_Char)0x63,  /* [4946] */
    (xdc_Char)0x61,  /* [4947] */
    (xdc_Char)0x6c,  /* [4948] */
    (xdc_Char)0x20,  /* [4949] */
    (xdc_Char)0x47,  /* [4950] */
    (xdc_Char)0x61,  /* [4951] */
    (xdc_Char)0x74,  /* [4952] */
    (xdc_Char)0x65,  /* [4953] */
    (xdc_Char)0x0,  /* [4954] */
    (xdc_Char)0x45,  /* [4955] */
    (xdc_Char)0x5f,  /* [4956] */
    (xdc_Char)0x6d,  /* [4957] */
    (xdc_Char)0x61,  /* [4958] */
    (xdc_Char)0x78,  /* [4959] */
    (xdc_Char)0x52,  /* [4960] */
    (xdc_Char)0x65,  /* [4961] */
    (xdc_Char)0x61,  /* [4962] */
    (xdc_Char)0x63,  /* [4963] */
    (xdc_Char)0x68,  /* [4964] */
    (xdc_Char)0x65,  /* [4965] */
    (xdc_Char)0x64,  /* [4966] */
    (xdc_Char)0x3a,  /* [4967] */
    (xdc_Char)0x20,  /* [4968] */
    (xdc_Char)0x41,  /* [4969] */
    (xdc_Char)0x6c,  /* [4970] */
    (xdc_Char)0x6c,  /* [4971] */
    (xdc_Char)0x20,  /* [4972] */
    (xdc_Char)0x6f,  /* [4973] */
    (xdc_Char)0x62,  /* [4974] */
    (xdc_Char)0x6a,  /* [4975] */
    (xdc_Char)0x65,  /* [4976] */
    (xdc_Char)0x63,  /* [4977] */
    (xdc_Char)0x74,  /* [4978] */
    (xdc_Char)0x73,  /* [4979] */
    (xdc_Char)0x20,  /* [4980] */
    (xdc_Char)0x69,  /* [4981] */
    (xdc_Char)0x6e,  /* [4982] */
    (xdc_Char)0x20,  /* [4983] */
    (xdc_Char)0x75,  /* [4984] */
    (xdc_Char)0x73,  /* [4985] */
    (xdc_Char)0x65,  /* [4986] */
    (xdc_Char)0x2e,  /* [4987] */
    (xdc_Char)0x20,  /* [4988] */
    (xdc_Char)0x4d,  /* [4989] */
    (xdc_Char)0x65,  /* [4990] */
    (xdc_Char)0x73,  /* [4991] */
    (xdc_Char)0x73,  /* [4992] */
    (xdc_Char)0x61,  /* [4993] */
    (xdc_Char)0x67,  /* [4994] */
    (xdc_Char)0x65,  /* [4995] */
    (xdc_Char)0x51,  /* [4996] */
    (xdc_Char)0x2e,  /* [4997] */
    (xdc_Char)0x6d,  /* [4998] */
    (xdc_Char)0x61,  /* [4999] */
    (xdc_Char)0x78,  /* [5000] */
    (xdc_Char)0x52,  /* [5001] */
    (xdc_Char)0x75,  /* [5002] */
    (xdc_Char)0x6e,  /* [5003] */
    (xdc_Char)0x74,  /* [5004] */
    (xdc_Char)0x69,  /* [5005] */
    (xdc_Char)0x6d,  /* [5006] */
    (xdc_Char)0x65,  /* [5007] */
    (xdc_Char)0x45,  /* [5008] */
    (xdc_Char)0x6e,  /* [5009] */
    (xdc_Char)0x74,  /* [5010] */
    (xdc_Char)0x72,  /* [5011] */
    (xdc_Char)0x69,  /* [5012] */
    (xdc_Char)0x65,  /* [5013] */
    (xdc_Char)0x73,  /* [5014] */
    (xdc_Char)0x20,  /* [5015] */
    (xdc_Char)0x69,  /* [5016] */
    (xdc_Char)0x73,  /* [5017] */
    (xdc_Char)0x20,  /* [5018] */
    (xdc_Char)0x25,  /* [5019] */
    (xdc_Char)0x64,  /* [5020] */
    (xdc_Char)0x0,  /* [5021] */
    (xdc_Char)0x45,  /* [5022] */
    (xdc_Char)0x5f,  /* [5023] */
    (xdc_Char)0x75,  /* [5024] */
    (xdc_Char)0x6e,  /* [5025] */
    (xdc_Char)0x72,  /* [5026] */
    (xdc_Char)0x65,  /* [5027] */
    (xdc_Char)0x67,  /* [5028] */
    (xdc_Char)0x69,  /* [5029] */
    (xdc_Char)0x73,  /* [5030] */
    (xdc_Char)0x74,  /* [5031] */
    (xdc_Char)0x65,  /* [5032] */
    (xdc_Char)0x72,  /* [5033] */
    (xdc_Char)0x48,  /* [5034] */
    (xdc_Char)0x65,  /* [5035] */
    (xdc_Char)0x61,  /* [5036] */
    (xdc_Char)0x70,  /* [5037] */
    (xdc_Char)0x49,  /* [5038] */
    (xdc_Char)0x64,  /* [5039] */
    (xdc_Char)0x3a,  /* [5040] */
    (xdc_Char)0x20,  /* [5041] */
    (xdc_Char)0x48,  /* [5042] */
    (xdc_Char)0x65,  /* [5043] */
    (xdc_Char)0x61,  /* [5044] */
    (xdc_Char)0x70,  /* [5045] */
    (xdc_Char)0x20,  /* [5046] */
    (xdc_Char)0x69,  /* [5047] */
    (xdc_Char)0x64,  /* [5048] */
    (xdc_Char)0x20,  /* [5049] */
    (xdc_Char)0x25,  /* [5050] */
    (xdc_Char)0x64,  /* [5051] */
    (xdc_Char)0x20,  /* [5052] */
    (xdc_Char)0x6e,  /* [5053] */
    (xdc_Char)0x6f,  /* [5054] */
    (xdc_Char)0x74,  /* [5055] */
    (xdc_Char)0x20,  /* [5056] */
    (xdc_Char)0x72,  /* [5057] */
    (xdc_Char)0x65,  /* [5058] */
    (xdc_Char)0x67,  /* [5059] */
    (xdc_Char)0x69,  /* [5060] */
    (xdc_Char)0x73,  /* [5061] */
    (xdc_Char)0x74,  /* [5062] */
    (xdc_Char)0x65,  /* [5063] */
    (xdc_Char)0x72,  /* [5064] */
    (xdc_Char)0x65,  /* [5065] */
    (xdc_Char)0x64,  /* [5066] */
    (xdc_Char)0x0,  /* [5067] */
    (xdc_Char)0x45,  /* [5068] */
    (xdc_Char)0x5f,  /* [5069] */
    (xdc_Char)0x6e,  /* [5070] */
    (xdc_Char)0x61,  /* [5071] */
    (xdc_Char)0x6d,  /* [5072] */
    (xdc_Char)0x65,  /* [5073] */
    (xdc_Char)0x46,  /* [5074] */
    (xdc_Char)0x61,  /* [5075] */
    (xdc_Char)0x69,  /* [5076] */
    (xdc_Char)0x6c,  /* [5077] */
    (xdc_Char)0x65,  /* [5078] */
    (xdc_Char)0x64,  /* [5079] */
    (xdc_Char)0x3a,  /* [5080] */
    (xdc_Char)0x20,  /* [5081] */
    (xdc_Char)0x27,  /* [5082] */
    (xdc_Char)0x25,  /* [5083] */
    (xdc_Char)0x73,  /* [5084] */
    (xdc_Char)0x27,  /* [5085] */
    (xdc_Char)0x20,  /* [5086] */
    (xdc_Char)0x6e,  /* [5087] */
    (xdc_Char)0x61,  /* [5088] */
    (xdc_Char)0x6d,  /* [5089] */
    (xdc_Char)0x65,  /* [5090] */
    (xdc_Char)0x20,  /* [5091] */
    (xdc_Char)0x66,  /* [5092] */
    (xdc_Char)0x61,  /* [5093] */
    (xdc_Char)0x69,  /* [5094] */
    (xdc_Char)0x6c,  /* [5095] */
    (xdc_Char)0x65,  /* [5096] */
    (xdc_Char)0x64,  /* [5097] */
    (xdc_Char)0x20,  /* [5098] */
    (xdc_Char)0x74,  /* [5099] */
    (xdc_Char)0x6f,  /* [5100] */
    (xdc_Char)0x20,  /* [5101] */
    (xdc_Char)0x62,  /* [5102] */
    (xdc_Char)0x65,  /* [5103] */
    (xdc_Char)0x20,  /* [5104] */
    (xdc_Char)0x61,  /* [5105] */
    (xdc_Char)0x64,  /* [5106] */
    (xdc_Char)0x64,  /* [5107] */
    (xdc_Char)0x65,  /* [5108] */
    (xdc_Char)0x64,  /* [5109] */
    (xdc_Char)0x20,  /* [5110] */
    (xdc_Char)0x74,  /* [5111] */
    (xdc_Char)0x6f,  /* [5112] */
    (xdc_Char)0x20,  /* [5113] */
    (xdc_Char)0x4e,  /* [5114] */
    (xdc_Char)0x61,  /* [5115] */
    (xdc_Char)0x6d,  /* [5116] */
    (xdc_Char)0x65,  /* [5117] */
    (xdc_Char)0x53,  /* [5118] */
    (xdc_Char)0x65,  /* [5119] */
    (xdc_Char)0x72,  /* [5120] */
    (xdc_Char)0x76,  /* [5121] */
    (xdc_Char)0x65,  /* [5122] */
    (xdc_Char)0x72,  /* [5123] */
    (xdc_Char)0x0,  /* [5124] */
    (xdc_Char)0x45,  /* [5125] */
    (xdc_Char)0x5f,  /* [5126] */
    (xdc_Char)0x69,  /* [5127] */
    (xdc_Char)0x6e,  /* [5128] */
    (xdc_Char)0x74,  /* [5129] */
    (xdc_Char)0x65,  /* [5130] */
    (xdc_Char)0x72,  /* [5131] */
    (xdc_Char)0x6e,  /* [5132] */
    (xdc_Char)0x61,  /* [5133] */
    (xdc_Char)0x6c,  /* [5134] */
    (xdc_Char)0x3a,  /* [5135] */
    (xdc_Char)0x20,  /* [5136] */
    (xdc_Char)0x41,  /* [5137] */
    (xdc_Char)0x6e,  /* [5138] */
    (xdc_Char)0x20,  /* [5139] */
    (xdc_Char)0x69,  /* [5140] */
    (xdc_Char)0x6e,  /* [5141] */
    (xdc_Char)0x74,  /* [5142] */
    (xdc_Char)0x65,  /* [5143] */
    (xdc_Char)0x72,  /* [5144] */
    (xdc_Char)0x6e,  /* [5145] */
    (xdc_Char)0x61,  /* [5146] */
    (xdc_Char)0x6c,  /* [5147] */
    (xdc_Char)0x20,  /* [5148] */
    (xdc_Char)0x65,  /* [5149] */
    (xdc_Char)0x72,  /* [5150] */
    (xdc_Char)0x72,  /* [5151] */
    (xdc_Char)0x6f,  /* [5152] */
    (xdc_Char)0x72,  /* [5153] */
    (xdc_Char)0x20,  /* [5154] */
    (xdc_Char)0x6f,  /* [5155] */
    (xdc_Char)0x63,  /* [5156] */
    (xdc_Char)0x63,  /* [5157] */
    (xdc_Char)0x75,  /* [5158] */
    (xdc_Char)0x72,  /* [5159] */
    (xdc_Char)0x72,  /* [5160] */
    (xdc_Char)0x65,  /* [5161] */
    (xdc_Char)0x64,  /* [5162] */
    (xdc_Char)0x0,  /* [5163] */
    (xdc_Char)0x45,  /* [5164] */
    (xdc_Char)0x5f,  /* [5165] */
    (xdc_Char)0x76,  /* [5166] */
    (xdc_Char)0x65,  /* [5167] */
    (xdc_Char)0x72,  /* [5168] */
    (xdc_Char)0x73,  /* [5169] */
    (xdc_Char)0x69,  /* [5170] */
    (xdc_Char)0x6f,  /* [5171] */
    (xdc_Char)0x6e,  /* [5172] */
    (xdc_Char)0x4d,  /* [5173] */
    (xdc_Char)0x69,  /* [5174] */
    (xdc_Char)0x73,  /* [5175] */
    (xdc_Char)0x6d,  /* [5176] */
    (xdc_Char)0x61,  /* [5177] */
    (xdc_Char)0x74,  /* [5178] */
    (xdc_Char)0x63,  /* [5179] */
    (xdc_Char)0x68,  /* [5180] */
    (xdc_Char)0x3a,  /* [5181] */
    (xdc_Char)0x20,  /* [5182] */
    (xdc_Char)0x49,  /* [5183] */
    (xdc_Char)0x50,  /* [5184] */
    (xdc_Char)0x43,  /* [5185] */
    (xdc_Char)0x20,  /* [5186] */
    (xdc_Char)0x4d,  /* [5187] */
    (xdc_Char)0x6f,  /* [5188] */
    (xdc_Char)0x64,  /* [5189] */
    (xdc_Char)0x75,  /* [5190] */
    (xdc_Char)0x6c,  /* [5191] */
    (xdc_Char)0x65,  /* [5192] */
    (xdc_Char)0x20,  /* [5193] */
    (xdc_Char)0x76,  /* [5194] */
    (xdc_Char)0x65,  /* [5195] */
    (xdc_Char)0x72,  /* [5196] */
    (xdc_Char)0x73,  /* [5197] */
    (xdc_Char)0x69,  /* [5198] */
    (xdc_Char)0x6f,  /* [5199] */
    (xdc_Char)0x6e,  /* [5200] */
    (xdc_Char)0x20,  /* [5201] */
    (xdc_Char)0x6d,  /* [5202] */
    (xdc_Char)0x69,  /* [5203] */
    (xdc_Char)0x73,  /* [5204] */
    (xdc_Char)0x6d,  /* [5205] */
    (xdc_Char)0x61,  /* [5206] */
    (xdc_Char)0x74,  /* [5207] */
    (xdc_Char)0x63,  /* [5208] */
    (xdc_Char)0x68,  /* [5209] */
    (xdc_Char)0x3a,  /* [5210] */
    (xdc_Char)0x20,  /* [5211] */
    (xdc_Char)0x63,  /* [5212] */
    (xdc_Char)0x72,  /* [5213] */
    (xdc_Char)0x65,  /* [5214] */
    (xdc_Char)0x61,  /* [5215] */
    (xdc_Char)0x74,  /* [5216] */
    (xdc_Char)0x6f,  /* [5217] */
    (xdc_Char)0x72,  /* [5218] */
    (xdc_Char)0x3a,  /* [5219] */
    (xdc_Char)0x20,  /* [5220] */
    (xdc_Char)0x25,  /* [5221] */
    (xdc_Char)0x64,  /* [5222] */
    (xdc_Char)0x2c,  /* [5223] */
    (xdc_Char)0x20,  /* [5224] */
    (xdc_Char)0x6f,  /* [5225] */
    (xdc_Char)0x70,  /* [5226] */
    (xdc_Char)0x65,  /* [5227] */
    (xdc_Char)0x6e,  /* [5228] */
    (xdc_Char)0x65,  /* [5229] */
    (xdc_Char)0x72,  /* [5230] */
    (xdc_Char)0x3a,  /* [5231] */
    (xdc_Char)0x20,  /* [5232] */
    (xdc_Char)0x25,  /* [5233] */
    (xdc_Char)0x64,  /* [5234] */
    (xdc_Char)0x0,  /* [5235] */
    (xdc_Char)0x45,  /* [5236] */
    (xdc_Char)0x5f,  /* [5237] */
    (xdc_Char)0x70,  /* [5238] */
    (xdc_Char)0x72,  /* [5239] */
    (xdc_Char)0x69,  /* [5240] */
    (xdc_Char)0x6f,  /* [5241] */
    (xdc_Char)0x72,  /* [5242] */
    (xdc_Char)0x69,  /* [5243] */
    (xdc_Char)0x74,  /* [5244] */
    (xdc_Char)0x79,  /* [5245] */
    (xdc_Char)0x3a,  /* [5246] */
    (xdc_Char)0x20,  /* [5247] */
    (xdc_Char)0x54,  /* [5248] */
    (xdc_Char)0x68,  /* [5249] */
    (xdc_Char)0x72,  /* [5250] */
    (xdc_Char)0x65,  /* [5251] */
    (xdc_Char)0x61,  /* [5252] */
    (xdc_Char)0x64,  /* [5253] */
    (xdc_Char)0x20,  /* [5254] */
    (xdc_Char)0x70,  /* [5255] */
    (xdc_Char)0x72,  /* [5256] */
    (xdc_Char)0x69,  /* [5257] */
    (xdc_Char)0x6f,  /* [5258] */
    (xdc_Char)0x72,  /* [5259] */
    (xdc_Char)0x69,  /* [5260] */
    (xdc_Char)0x74,  /* [5261] */
    (xdc_Char)0x79,  /* [5262] */
    (xdc_Char)0x20,  /* [5263] */
    (xdc_Char)0x69,  /* [5264] */
    (xdc_Char)0x73,  /* [5265] */
    (xdc_Char)0x20,  /* [5266] */
    (xdc_Char)0x69,  /* [5267] */
    (xdc_Char)0x6e,  /* [5268] */
    (xdc_Char)0x76,  /* [5269] */
    (xdc_Char)0x61,  /* [5270] */
    (xdc_Char)0x6c,  /* [5271] */
    (xdc_Char)0x69,  /* [5272] */
    (xdc_Char)0x64,  /* [5273] */
    (xdc_Char)0x20,  /* [5274] */
    (xdc_Char)0x25,  /* [5275] */
    (xdc_Char)0x64,  /* [5276] */
    (xdc_Char)0x0,  /* [5277] */
    (xdc_Char)0x45,  /* [5278] */
    (xdc_Char)0x5f,  /* [5279] */
    (xdc_Char)0x69,  /* [5280] */
    (xdc_Char)0x6e,  /* [5281] */
    (xdc_Char)0x76,  /* [5282] */
    (xdc_Char)0x61,  /* [5283] */
    (xdc_Char)0x6c,  /* [5284] */
    (xdc_Char)0x69,  /* [5285] */
    (xdc_Char)0x64,  /* [5286] */
    (xdc_Char)0x54,  /* [5287] */
    (xdc_Char)0x69,  /* [5288] */
    (xdc_Char)0x6d,  /* [5289] */
    (xdc_Char)0x65,  /* [5290] */
    (xdc_Char)0x72,  /* [5291] */
    (xdc_Char)0x3a,  /* [5292] */
    (xdc_Char)0x20,  /* [5293] */
    (xdc_Char)0x49,  /* [5294] */
    (xdc_Char)0x6e,  /* [5295] */
    (xdc_Char)0x76,  /* [5296] */
    (xdc_Char)0x61,  /* [5297] */
    (xdc_Char)0x6c,  /* [5298] */
    (xdc_Char)0x69,  /* [5299] */
    (xdc_Char)0x64,  /* [5300] */
    (xdc_Char)0x20,  /* [5301] */
    (xdc_Char)0x54,  /* [5302] */
    (xdc_Char)0x69,  /* [5303] */
    (xdc_Char)0x6d,  /* [5304] */
    (xdc_Char)0x65,  /* [5305] */
    (xdc_Char)0x72,  /* [5306] */
    (xdc_Char)0x20,  /* [5307] */
    (xdc_Char)0x49,  /* [5308] */
    (xdc_Char)0x64,  /* [5309] */
    (xdc_Char)0x20,  /* [5310] */
    (xdc_Char)0x25,  /* [5311] */
    (xdc_Char)0x64,  /* [5312] */
    (xdc_Char)0x0,  /* [5313] */
    (xdc_Char)0x45,  /* [5314] */
    (xdc_Char)0x5f,  /* [5315] */
    (xdc_Char)0x6e,  /* [5316] */
    (xdc_Char)0x6f,  /* [5317] */
    (xdc_Char)0x74,  /* [5318] */
    (xdc_Char)0x41,  /* [5319] */
    (xdc_Char)0x76,  /* [5320] */
    (xdc_Char)0x61,  /* [5321] */
    (xdc_Char)0x69,  /* [5322] */
    (xdc_Char)0x6c,  /* [5323] */
    (xdc_Char)0x61,  /* [5324] */
    (xdc_Char)0x62,  /* [5325] */
    (xdc_Char)0x6c,  /* [5326] */
    (xdc_Char)0x65,  /* [5327] */
    (xdc_Char)0x3a,  /* [5328] */
    (xdc_Char)0x20,  /* [5329] */
    (xdc_Char)0x54,  /* [5330] */
    (xdc_Char)0x69,  /* [5331] */
    (xdc_Char)0x6d,  /* [5332] */
    (xdc_Char)0x65,  /* [5333] */
    (xdc_Char)0x72,  /* [5334] */
    (xdc_Char)0x20,  /* [5335] */
    (xdc_Char)0x6e,  /* [5336] */
    (xdc_Char)0x6f,  /* [5337] */
    (xdc_Char)0x74,  /* [5338] */
    (xdc_Char)0x20,  /* [5339] */
    (xdc_Char)0x61,  /* [5340] */
    (xdc_Char)0x76,  /* [5341] */
    (xdc_Char)0x61,  /* [5342] */
    (xdc_Char)0x69,  /* [5343] */
    (xdc_Char)0x6c,  /* [5344] */
    (xdc_Char)0x61,  /* [5345] */
    (xdc_Char)0x62,  /* [5346] */
    (xdc_Char)0x6c,  /* [5347] */
    (xdc_Char)0x65,  /* [5348] */
    (xdc_Char)0x20,  /* [5349] */
    (xdc_Char)0x25,  /* [5350] */
    (xdc_Char)0x64,  /* [5351] */
    (xdc_Char)0x0,  /* [5352] */
    (xdc_Char)0x45,  /* [5353] */
    (xdc_Char)0x5f,  /* [5354] */
    (xdc_Char)0x63,  /* [5355] */
    (xdc_Char)0x61,  /* [5356] */
    (xdc_Char)0x6e,  /* [5357] */
    (xdc_Char)0x6e,  /* [5358] */
    (xdc_Char)0x6f,  /* [5359] */
    (xdc_Char)0x74,  /* [5360] */
    (xdc_Char)0x53,  /* [5361] */
    (xdc_Char)0x75,  /* [5362] */
    (xdc_Char)0x70,  /* [5363] */
    (xdc_Char)0x70,  /* [5364] */
    (xdc_Char)0x6f,  /* [5365] */
    (xdc_Char)0x72,  /* [5366] */
    (xdc_Char)0x74,  /* [5367] */
    (xdc_Char)0x3a,  /* [5368] */
    (xdc_Char)0x20,  /* [5369] */
    (xdc_Char)0x54,  /* [5370] */
    (xdc_Char)0x69,  /* [5371] */
    (xdc_Char)0x6d,  /* [5372] */
    (xdc_Char)0x65,  /* [5373] */
    (xdc_Char)0x72,  /* [5374] */
    (xdc_Char)0x20,  /* [5375] */
    (xdc_Char)0x63,  /* [5376] */
    (xdc_Char)0x61,  /* [5377] */
    (xdc_Char)0x6e,  /* [5378] */
    (xdc_Char)0x6e,  /* [5379] */
    (xdc_Char)0x6f,  /* [5380] */
    (xdc_Char)0x74,  /* [5381] */
    (xdc_Char)0x20,  /* [5382] */
    (xdc_Char)0x73,  /* [5383] */
    (xdc_Char)0x75,  /* [5384] */
    (xdc_Char)0x70,  /* [5385] */
    (xdc_Char)0x70,  /* [5386] */
    (xdc_Char)0x6f,  /* [5387] */
    (xdc_Char)0x72,  /* [5388] */
    (xdc_Char)0x74,  /* [5389] */
    (xdc_Char)0x20,  /* [5390] */
    (xdc_Char)0x72,  /* [5391] */
    (xdc_Char)0x65,  /* [5392] */
    (xdc_Char)0x71,  /* [5393] */
    (xdc_Char)0x75,  /* [5394] */
    (xdc_Char)0x65,  /* [5395] */
    (xdc_Char)0x73,  /* [5396] */
    (xdc_Char)0x74,  /* [5397] */
    (xdc_Char)0x65,  /* [5398] */
    (xdc_Char)0x64,  /* [5399] */
    (xdc_Char)0x20,  /* [5400] */
    (xdc_Char)0x70,  /* [5401] */
    (xdc_Char)0x65,  /* [5402] */
    (xdc_Char)0x72,  /* [5403] */
    (xdc_Char)0x69,  /* [5404] */
    (xdc_Char)0x6f,  /* [5405] */
    (xdc_Char)0x64,  /* [5406] */
    (xdc_Char)0x20,  /* [5407] */
    (xdc_Char)0x25,  /* [5408] */
    (xdc_Char)0x64,  /* [5409] */
    (xdc_Char)0x0,  /* [5410] */
    (xdc_Char)0x45,  /* [5411] */
    (xdc_Char)0x5f,  /* [5412] */
    (xdc_Char)0x66,  /* [5413] */
    (xdc_Char)0x72,  /* [5414] */
    (xdc_Char)0x65,  /* [5415] */
    (xdc_Char)0x71,  /* [5416] */
    (xdc_Char)0x4d,  /* [5417] */
    (xdc_Char)0x69,  /* [5418] */
    (xdc_Char)0x73,  /* [5419] */
    (xdc_Char)0x6d,  /* [5420] */
    (xdc_Char)0x61,  /* [5421] */
    (xdc_Char)0x74,  /* [5422] */
    (xdc_Char)0x63,  /* [5423] */
    (xdc_Char)0x68,  /* [5424] */
    (xdc_Char)0x3a,  /* [5425] */
    (xdc_Char)0x20,  /* [5426] */
    (xdc_Char)0x46,  /* [5427] */
    (xdc_Char)0x72,  /* [5428] */
    (xdc_Char)0x65,  /* [5429] */
    (xdc_Char)0x71,  /* [5430] */
    (xdc_Char)0x75,  /* [5431] */
    (xdc_Char)0x65,  /* [5432] */
    (xdc_Char)0x6e,  /* [5433] */
    (xdc_Char)0x63,  /* [5434] */
    (xdc_Char)0x79,  /* [5435] */
    (xdc_Char)0x20,  /* [5436] */
    (xdc_Char)0x6d,  /* [5437] */
    (xdc_Char)0x69,  /* [5438] */
    (xdc_Char)0x73,  /* [5439] */
    (xdc_Char)0x6d,  /* [5440] */
    (xdc_Char)0x61,  /* [5441] */
    (xdc_Char)0x74,  /* [5442] */
    (xdc_Char)0x63,  /* [5443] */
    (xdc_Char)0x68,  /* [5444] */
    (xdc_Char)0x3a,  /* [5445] */
    (xdc_Char)0x20,  /* [5446] */
    (xdc_Char)0x45,  /* [5447] */
    (xdc_Char)0x78,  /* [5448] */
    (xdc_Char)0x70,  /* [5449] */
    (xdc_Char)0x65,  /* [5450] */
    (xdc_Char)0x63,  /* [5451] */
    (xdc_Char)0x74,  /* [5452] */
    (xdc_Char)0x65,  /* [5453] */
    (xdc_Char)0x64,  /* [5454] */
    (xdc_Char)0x20,  /* [5455] */
    (xdc_Char)0x25,  /* [5456] */
    (xdc_Char)0x64,  /* [5457] */
    (xdc_Char)0x20,  /* [5458] */
    (xdc_Char)0x48,  /* [5459] */
    (xdc_Char)0x7a,  /* [5460] */
    (xdc_Char)0x2c,  /* [5461] */
    (xdc_Char)0x20,  /* [5462] */
    (xdc_Char)0x61,  /* [5463] */
    (xdc_Char)0x63,  /* [5464] */
    (xdc_Char)0x74,  /* [5465] */
    (xdc_Char)0x75,  /* [5466] */
    (xdc_Char)0x61,  /* [5467] */
    (xdc_Char)0x6c,  /* [5468] */
    (xdc_Char)0x3a,  /* [5469] */
    (xdc_Char)0x20,  /* [5470] */
    (xdc_Char)0x25,  /* [5471] */
    (xdc_Char)0x64,  /* [5472] */
    (xdc_Char)0x20,  /* [5473] */
    (xdc_Char)0x48,  /* [5474] */
    (xdc_Char)0x7a,  /* [5475] */
    (xdc_Char)0x2e,  /* [5476] */
    (xdc_Char)0x20,  /* [5477] */
    (xdc_Char)0x20,  /* [5478] */
    (xdc_Char)0x59,  /* [5479] */
    (xdc_Char)0x6f,  /* [5480] */
    (xdc_Char)0x75,  /* [5481] */
    (xdc_Char)0x20,  /* [5482] */
    (xdc_Char)0x6e,  /* [5483] */
    (xdc_Char)0x65,  /* [5484] */
    (xdc_Char)0x65,  /* [5485] */
    (xdc_Char)0x64,  /* [5486] */
    (xdc_Char)0x20,  /* [5487] */
    (xdc_Char)0x74,  /* [5488] */
    (xdc_Char)0x6f,  /* [5489] */
    (xdc_Char)0x20,  /* [5490] */
    (xdc_Char)0x6d,  /* [5491] */
    (xdc_Char)0x6f,  /* [5492] */
    (xdc_Char)0x64,  /* [5493] */
    (xdc_Char)0x69,  /* [5494] */
    (xdc_Char)0x66,  /* [5495] */
    (xdc_Char)0x79,  /* [5496] */
    (xdc_Char)0x20,  /* [5497] */
    (xdc_Char)0x54,  /* [5498] */
    (xdc_Char)0x69,  /* [5499] */
    (xdc_Char)0x6d,  /* [5500] */
    (xdc_Char)0x65,  /* [5501] */
    (xdc_Char)0x72,  /* [5502] */
    (xdc_Char)0x2e,  /* [5503] */
    (xdc_Char)0x69,  /* [5504] */
    (xdc_Char)0x6e,  /* [5505] */
    (xdc_Char)0x74,  /* [5506] */
    (xdc_Char)0x46,  /* [5507] */
    (xdc_Char)0x72,  /* [5508] */
    (xdc_Char)0x65,  /* [5509] */
    (xdc_Char)0x71,  /* [5510] */
    (xdc_Char)0x2e,  /* [5511] */
    (xdc_Char)0x6c,  /* [5512] */
    (xdc_Char)0x6f,  /* [5513] */
    (xdc_Char)0x20,  /* [5514] */
    (xdc_Char)0x74,  /* [5515] */
    (xdc_Char)0x6f,  /* [5516] */
    (xdc_Char)0x20,  /* [5517] */
    (xdc_Char)0x6d,  /* [5518] */
    (xdc_Char)0x61,  /* [5519] */
    (xdc_Char)0x74,  /* [5520] */
    (xdc_Char)0x63,  /* [5521] */
    (xdc_Char)0x68,  /* [5522] */
    (xdc_Char)0x20,  /* [5523] */
    (xdc_Char)0x74,  /* [5524] */
    (xdc_Char)0x68,  /* [5525] */
    (xdc_Char)0x65,  /* [5526] */
    (xdc_Char)0x20,  /* [5527] */
    (xdc_Char)0x61,  /* [5528] */
    (xdc_Char)0x63,  /* [5529] */
    (xdc_Char)0x74,  /* [5530] */
    (xdc_Char)0x75,  /* [5531] */
    (xdc_Char)0x61,  /* [5532] */
    (xdc_Char)0x6c,  /* [5533] */
    (xdc_Char)0x20,  /* [5534] */
    (xdc_Char)0x66,  /* [5535] */
    (xdc_Char)0x72,  /* [5536] */
    (xdc_Char)0x65,  /* [5537] */
    (xdc_Char)0x71,  /* [5538] */
    (xdc_Char)0x75,  /* [5539] */
    (xdc_Char)0x65,  /* [5540] */
    (xdc_Char)0x6e,  /* [5541] */
    (xdc_Char)0x63,  /* [5542] */
    (xdc_Char)0x79,  /* [5543] */
    (xdc_Char)0x2e,  /* [5544] */
    (xdc_Char)0x0,  /* [5545] */
    (xdc_Char)0x72,  /* [5546] */
    (xdc_Char)0x65,  /* [5547] */
    (xdc_Char)0x71,  /* [5548] */
    (xdc_Char)0x75,  /* [5549] */
    (xdc_Char)0x65,  /* [5550] */
    (xdc_Char)0x73,  /* [5551] */
    (xdc_Char)0x74,  /* [5552] */
    (xdc_Char)0x65,  /* [5553] */
    (xdc_Char)0x64,  /* [5554] */
    (xdc_Char)0x20,  /* [5555] */
    (xdc_Char)0x73,  /* [5556] */
    (xdc_Char)0x69,  /* [5557] */
    (xdc_Char)0x7a,  /* [5558] */
    (xdc_Char)0x65,  /* [5559] */
    (xdc_Char)0x20,  /* [5560] */
    (xdc_Char)0x69,  /* [5561] */
    (xdc_Char)0x73,  /* [5562] */
    (xdc_Char)0x20,  /* [5563] */
    (xdc_Char)0x74,  /* [5564] */
    (xdc_Char)0x6f,  /* [5565] */
    (xdc_Char)0x6f,  /* [5566] */
    (xdc_Char)0x20,  /* [5567] */
    (xdc_Char)0x62,  /* [5568] */
    (xdc_Char)0x69,  /* [5569] */
    (xdc_Char)0x67,  /* [5570] */
    (xdc_Char)0x3a,  /* [5571] */
    (xdc_Char)0x20,  /* [5572] */
    (xdc_Char)0x68,  /* [5573] */
    (xdc_Char)0x61,  /* [5574] */
    (xdc_Char)0x6e,  /* [5575] */
    (xdc_Char)0x64,  /* [5576] */
    (xdc_Char)0x6c,  /* [5577] */
    (xdc_Char)0x65,  /* [5578] */
    (xdc_Char)0x3d,  /* [5579] */
    (xdc_Char)0x30,  /* [5580] */
    (xdc_Char)0x78,  /* [5581] */
    (xdc_Char)0x25,  /* [5582] */
    (xdc_Char)0x78,  /* [5583] */
    (xdc_Char)0x2c,  /* [5584] */
    (xdc_Char)0x20,  /* [5585] */
    (xdc_Char)0x73,  /* [5586] */
    (xdc_Char)0x69,  /* [5587] */
    (xdc_Char)0x7a,  /* [5588] */
    (xdc_Char)0x65,  /* [5589] */
    (xdc_Char)0x3d,  /* [5590] */
    (xdc_Char)0x25,  /* [5591] */
    (xdc_Char)0x75,  /* [5592] */
    (xdc_Char)0x0,  /* [5593] */
    (xdc_Char)0x6f,  /* [5594] */
    (xdc_Char)0x75,  /* [5595] */
    (xdc_Char)0x74,  /* [5596] */
    (xdc_Char)0x20,  /* [5597] */
    (xdc_Char)0x6f,  /* [5598] */
    (xdc_Char)0x66,  /* [5599] */
    (xdc_Char)0x20,  /* [5600] */
    (xdc_Char)0x6d,  /* [5601] */
    (xdc_Char)0x65,  /* [5602] */
    (xdc_Char)0x6d,  /* [5603] */
    (xdc_Char)0x6f,  /* [5604] */
    (xdc_Char)0x72,  /* [5605] */
    (xdc_Char)0x79,  /* [5606] */
    (xdc_Char)0x3a,  /* [5607] */
    (xdc_Char)0x20,  /* [5608] */
    (xdc_Char)0x68,  /* [5609] */
    (xdc_Char)0x61,  /* [5610] */
    (xdc_Char)0x6e,  /* [5611] */
    (xdc_Char)0x64,  /* [5612] */
    (xdc_Char)0x6c,  /* [5613] */
    (xdc_Char)0x65,  /* [5614] */
    (xdc_Char)0x3d,  /* [5615] */
    (xdc_Char)0x30,  /* [5616] */
    (xdc_Char)0x78,  /* [5617] */
    (xdc_Char)0x25,  /* [5618] */
    (xdc_Char)0x78,  /* [5619] */
    (xdc_Char)0x2c,  /* [5620] */
    (xdc_Char)0x20,  /* [5621] */
    (xdc_Char)0x73,  /* [5622] */
    (xdc_Char)0x69,  /* [5623] */
    (xdc_Char)0x7a,  /* [5624] */
    (xdc_Char)0x65,  /* [5625] */
    (xdc_Char)0x3d,  /* [5626] */
    (xdc_Char)0x25,  /* [5627] */
    (xdc_Char)0x75,  /* [5628] */
    (xdc_Char)0x0,  /* [5629] */
    (xdc_Char)0x3c,  /* [5630] */
    (xdc_Char)0x2d,  /* [5631] */
    (xdc_Char)0x2d,  /* [5632] */
    (xdc_Char)0x20,  /* [5633] */
    (xdc_Char)0x63,  /* [5634] */
    (xdc_Char)0x6f,  /* [5635] */
    (xdc_Char)0x6e,  /* [5636] */
    (xdc_Char)0x73,  /* [5637] */
    (xdc_Char)0x74,  /* [5638] */
    (xdc_Char)0x72,  /* [5639] */
    (xdc_Char)0x75,  /* [5640] */
    (xdc_Char)0x63,  /* [5641] */
    (xdc_Char)0x74,  /* [5642] */
    (xdc_Char)0x3a,  /* [5643] */
    (xdc_Char)0x20,  /* [5644] */
    (xdc_Char)0x25,  /* [5645] */
    (xdc_Char)0x70,  /* [5646] */
    (xdc_Char)0x28,  /* [5647] */
    (xdc_Char)0x27,  /* [5648] */
    (xdc_Char)0x25,  /* [5649] */
    (xdc_Char)0x73,  /* [5650] */
    (xdc_Char)0x27,  /* [5651] */
    (xdc_Char)0x29,  /* [5652] */
    (xdc_Char)0x0,  /* [5653] */
    (xdc_Char)0x3c,  /* [5654] */
    (xdc_Char)0x2d,  /* [5655] */
    (xdc_Char)0x2d,  /* [5656] */
    (xdc_Char)0x20,  /* [5657] */
    (xdc_Char)0x63,  /* [5658] */
    (xdc_Char)0x72,  /* [5659] */
    (xdc_Char)0x65,  /* [5660] */
    (xdc_Char)0x61,  /* [5661] */
    (xdc_Char)0x74,  /* [5662] */
    (xdc_Char)0x65,  /* [5663] */
    (xdc_Char)0x3a,  /* [5664] */
    (xdc_Char)0x20,  /* [5665] */
    (xdc_Char)0x25,  /* [5666] */
    (xdc_Char)0x70,  /* [5667] */
    (xdc_Char)0x28,  /* [5668] */
    (xdc_Char)0x27,  /* [5669] */
    (xdc_Char)0x25,  /* [5670] */
    (xdc_Char)0x73,  /* [5671] */
    (xdc_Char)0x27,  /* [5672] */
    (xdc_Char)0x29,  /* [5673] */
    (xdc_Char)0x0,  /* [5674] */
    (xdc_Char)0x2d,  /* [5675] */
    (xdc_Char)0x2d,  /* [5676] */
    (xdc_Char)0x3e,  /* [5677] */
    (xdc_Char)0x20,  /* [5678] */
    (xdc_Char)0x64,  /* [5679] */
    (xdc_Char)0x65,  /* [5680] */
    (xdc_Char)0x73,  /* [5681] */
    (xdc_Char)0x74,  /* [5682] */
    (xdc_Char)0x72,  /* [5683] */
    (xdc_Char)0x75,  /* [5684] */
    (xdc_Char)0x63,  /* [5685] */
    (xdc_Char)0x74,  /* [5686] */
    (xdc_Char)0x3a,  /* [5687] */
    (xdc_Char)0x20,  /* [5688] */
    (xdc_Char)0x28,  /* [5689] */
    (xdc_Char)0x25,  /* [5690] */
    (xdc_Char)0x70,  /* [5691] */
    (xdc_Char)0x29,  /* [5692] */
    (xdc_Char)0x0,  /* [5693] */
    (xdc_Char)0x2d,  /* [5694] */
    (xdc_Char)0x2d,  /* [5695] */
    (xdc_Char)0x3e,  /* [5696] */
    (xdc_Char)0x20,  /* [5697] */
    (xdc_Char)0x64,  /* [5698] */
    (xdc_Char)0x65,  /* [5699] */
    (xdc_Char)0x6c,  /* [5700] */
    (xdc_Char)0x65,  /* [5701] */
    (xdc_Char)0x74,  /* [5702] */
    (xdc_Char)0x65,  /* [5703] */
    (xdc_Char)0x3a,  /* [5704] */
    (xdc_Char)0x20,  /* [5705] */
    (xdc_Char)0x28,  /* [5706] */
    (xdc_Char)0x25,  /* [5707] */
    (xdc_Char)0x70,  /* [5708] */
    (xdc_Char)0x29,  /* [5709] */
    (xdc_Char)0x0,  /* [5710] */
    (xdc_Char)0x45,  /* [5711] */
    (xdc_Char)0x52,  /* [5712] */
    (xdc_Char)0x52,  /* [5713] */
    (xdc_Char)0x4f,  /* [5714] */
    (xdc_Char)0x52,  /* [5715] */
    (xdc_Char)0x3a,  /* [5716] */
    (xdc_Char)0x20,  /* [5717] */
    (xdc_Char)0x25,  /* [5718] */
    (xdc_Char)0x24,  /* [5719] */
    (xdc_Char)0x46,  /* [5720] */
    (xdc_Char)0x25,  /* [5721] */
    (xdc_Char)0x24,  /* [5722] */
    (xdc_Char)0x53,  /* [5723] */
    (xdc_Char)0x0,  /* [5724] */
    (xdc_Char)0x57,  /* [5725] */
    (xdc_Char)0x41,  /* [5726] */
    (xdc_Char)0x52,  /* [5727] */
    (xdc_Char)0x4e,  /* [5728] */
    (xdc_Char)0x49,  /* [5729] */
    (xdc_Char)0x4e,  /* [5730] */
    (xdc_Char)0x47,  /* [5731] */
    (xdc_Char)0x3a,  /* [5732] */
    (xdc_Char)0x20,  /* [5733] */
    (xdc_Char)0x25,  /* [5734] */
    (xdc_Char)0x24,  /* [5735] */
    (xdc_Char)0x46,  /* [5736] */
    (xdc_Char)0x25,  /* [5737] */
    (xdc_Char)0x24,  /* [5738] */
    (xdc_Char)0x53,  /* [5739] */
    (xdc_Char)0x0,  /* [5740] */
    (xdc_Char)0x25,  /* [5741] */
    (xdc_Char)0x24,  /* [5742] */
    (xdc_Char)0x46,  /* [5743] */
    (xdc_Char)0x25,  /* [5744] */
    (xdc_Char)0x24,  /* [5745] */
    (xdc_Char)0x53,  /* [5746] */
    (xdc_Char)0x0,  /* [5747] */
    (xdc_Char)0x53,  /* [5748] */
    (xdc_Char)0x74,  /* [5749] */
    (xdc_Char)0x61,  /* [5750] */
    (xdc_Char)0x72,  /* [5751] */
    (xdc_Char)0x74,  /* [5752] */
    (xdc_Char)0x3a,  /* [5753] */
    (xdc_Char)0x20,  /* [5754] */
    (xdc_Char)0x25,  /* [5755] */
    (xdc_Char)0x24,  /* [5756] */
    (xdc_Char)0x53,  /* [5757] */
    (xdc_Char)0x0,  /* [5758] */
    (xdc_Char)0x53,  /* [5759] */
    (xdc_Char)0x74,  /* [5760] */
    (xdc_Char)0x6f,  /* [5761] */
    (xdc_Char)0x70,  /* [5762] */
    (xdc_Char)0x3a,  /* [5763] */
    (xdc_Char)0x20,  /* [5764] */
    (xdc_Char)0x25,  /* [5765] */
    (xdc_Char)0x24,  /* [5766] */
    (xdc_Char)0x53,  /* [5767] */
    (xdc_Char)0x0,  /* [5768] */
    (xdc_Char)0x53,  /* [5769] */
    (xdc_Char)0x74,  /* [5770] */
    (xdc_Char)0x61,  /* [5771] */
    (xdc_Char)0x72,  /* [5772] */
    (xdc_Char)0x74,  /* [5773] */
    (xdc_Char)0x49,  /* [5774] */
    (xdc_Char)0x6e,  /* [5775] */
    (xdc_Char)0x73,  /* [5776] */
    (xdc_Char)0x74,  /* [5777] */
    (xdc_Char)0x61,  /* [5778] */
    (xdc_Char)0x6e,  /* [5779] */
    (xdc_Char)0x63,  /* [5780] */
    (xdc_Char)0x65,  /* [5781] */
    (xdc_Char)0x3a,  /* [5782] */
    (xdc_Char)0x20,  /* [5783] */
    (xdc_Char)0x25,  /* [5784] */
    (xdc_Char)0x24,  /* [5785] */
    (xdc_Char)0x53,  /* [5786] */
    (xdc_Char)0x0,  /* [5787] */
    (xdc_Char)0x53,  /* [5788] */
    (xdc_Char)0x74,  /* [5789] */
    (xdc_Char)0x6f,  /* [5790] */
    (xdc_Char)0x70,  /* [5791] */
    (xdc_Char)0x49,  /* [5792] */
    (xdc_Char)0x6e,  /* [5793] */
    (xdc_Char)0x73,  /* [5794] */
    (xdc_Char)0x74,  /* [5795] */
    (xdc_Char)0x61,  /* [5796] */
    (xdc_Char)0x6e,  /* [5797] */
    (xdc_Char)0x63,  /* [5798] */
    (xdc_Char)0x65,  /* [5799] */
    (xdc_Char)0x3a,  /* [5800] */
    (xdc_Char)0x20,  /* [5801] */
    (xdc_Char)0x25,  /* [5802] */
    (xdc_Char)0x24,  /* [5803] */
    (xdc_Char)0x53,  /* [5804] */
    (xdc_Char)0x0,  /* [5805] */
    (xdc_Char)0x4c,  /* [5806] */
    (xdc_Char)0x4d,  /* [5807] */
    (xdc_Char)0x5f,  /* [5808] */
    (xdc_Char)0x62,  /* [5809] */
    (xdc_Char)0x65,  /* [5810] */
    (xdc_Char)0x67,  /* [5811] */
    (xdc_Char)0x69,  /* [5812] */
    (xdc_Char)0x6e,  /* [5813] */
    (xdc_Char)0x3a,  /* [5814] */
    (xdc_Char)0x20,  /* [5815] */
    (xdc_Char)0x68,  /* [5816] */
    (xdc_Char)0x77,  /* [5817] */
    (xdc_Char)0x69,  /* [5818] */
    (xdc_Char)0x3a,  /* [5819] */
    (xdc_Char)0x20,  /* [5820] */
    (xdc_Char)0x30,  /* [5821] */
    (xdc_Char)0x78,  /* [5822] */
    (xdc_Char)0x25,  /* [5823] */
    (xdc_Char)0x78,  /* [5824] */
    (xdc_Char)0x2c,  /* [5825] */
    (xdc_Char)0x20,  /* [5826] */
    (xdc_Char)0x66,  /* [5827] */
    (xdc_Char)0x75,  /* [5828] */
    (xdc_Char)0x6e,  /* [5829] */
    (xdc_Char)0x63,  /* [5830] */
    (xdc_Char)0x3a,  /* [5831] */
    (xdc_Char)0x20,  /* [5832] */
    (xdc_Char)0x30,  /* [5833] */
    (xdc_Char)0x78,  /* [5834] */
    (xdc_Char)0x25,  /* [5835] */
    (xdc_Char)0x78,  /* [5836] */
    (xdc_Char)0x2c,  /* [5837] */
    (xdc_Char)0x20,  /* [5838] */
    (xdc_Char)0x70,  /* [5839] */
    (xdc_Char)0x72,  /* [5840] */
    (xdc_Char)0x65,  /* [5841] */
    (xdc_Char)0x54,  /* [5842] */
    (xdc_Char)0x68,  /* [5843] */
    (xdc_Char)0x72,  /* [5844] */
    (xdc_Char)0x65,  /* [5845] */
    (xdc_Char)0x61,  /* [5846] */
    (xdc_Char)0x64,  /* [5847] */
    (xdc_Char)0x3a,  /* [5848] */
    (xdc_Char)0x20,  /* [5849] */
    (xdc_Char)0x25,  /* [5850] */
    (xdc_Char)0x64,  /* [5851] */
    (xdc_Char)0x2c,  /* [5852] */
    (xdc_Char)0x20,  /* [5853] */
    (xdc_Char)0x69,  /* [5854] */
    (xdc_Char)0x6e,  /* [5855] */
    (xdc_Char)0x74,  /* [5856] */
    (xdc_Char)0x4e,  /* [5857] */
    (xdc_Char)0x75,  /* [5858] */
    (xdc_Char)0x6d,  /* [5859] */
    (xdc_Char)0x3a,  /* [5860] */
    (xdc_Char)0x20,  /* [5861] */
    (xdc_Char)0x25,  /* [5862] */
    (xdc_Char)0x64,  /* [5863] */
    (xdc_Char)0x2c,  /* [5864] */
    (xdc_Char)0x20,  /* [5865] */
    (xdc_Char)0x69,  /* [5866] */
    (xdc_Char)0x72,  /* [5867] */
    (xdc_Char)0x70,  /* [5868] */
    (xdc_Char)0x3a,  /* [5869] */
    (xdc_Char)0x20,  /* [5870] */
    (xdc_Char)0x30,  /* [5871] */
    (xdc_Char)0x78,  /* [5872] */
    (xdc_Char)0x25,  /* [5873] */
    (xdc_Char)0x78,  /* [5874] */
    (xdc_Char)0x0,  /* [5875] */
    (xdc_Char)0x4c,  /* [5876] */
    (xdc_Char)0x44,  /* [5877] */
    (xdc_Char)0x5f,  /* [5878] */
    (xdc_Char)0x65,  /* [5879] */
    (xdc_Char)0x6e,  /* [5880] */
    (xdc_Char)0x64,  /* [5881] */
    (xdc_Char)0x3a,  /* [5882] */
    (xdc_Char)0x20,  /* [5883] */
    (xdc_Char)0x68,  /* [5884] */
    (xdc_Char)0x77,  /* [5885] */
    (xdc_Char)0x69,  /* [5886] */
    (xdc_Char)0x3a,  /* [5887] */
    (xdc_Char)0x20,  /* [5888] */
    (xdc_Char)0x30,  /* [5889] */
    (xdc_Char)0x78,  /* [5890] */
    (xdc_Char)0x25,  /* [5891] */
    (xdc_Char)0x78,  /* [5892] */
    (xdc_Char)0x0,  /* [5893] */
    (xdc_Char)0x4c,  /* [5894] */
    (xdc_Char)0x57,  /* [5895] */
    (xdc_Char)0x5f,  /* [5896] */
    (xdc_Char)0x64,  /* [5897] */
    (xdc_Char)0x65,  /* [5898] */
    (xdc_Char)0x6c,  /* [5899] */
    (xdc_Char)0x61,  /* [5900] */
    (xdc_Char)0x79,  /* [5901] */
    (xdc_Char)0x65,  /* [5902] */
    (xdc_Char)0x64,  /* [5903] */
    (xdc_Char)0x3a,  /* [5904] */
    (xdc_Char)0x20,  /* [5905] */
    (xdc_Char)0x64,  /* [5906] */
    (xdc_Char)0x65,  /* [5907] */
    (xdc_Char)0x6c,  /* [5908] */
    (xdc_Char)0x61,  /* [5909] */
    (xdc_Char)0x79,  /* [5910] */
    (xdc_Char)0x3a,  /* [5911] */
    (xdc_Char)0x20,  /* [5912] */
    (xdc_Char)0x25,  /* [5913] */
    (xdc_Char)0x64,  /* [5914] */
    (xdc_Char)0x0,  /* [5915] */
    (xdc_Char)0x4c,  /* [5916] */
    (xdc_Char)0x4d,  /* [5917] */
    (xdc_Char)0x5f,  /* [5918] */
    (xdc_Char)0x74,  /* [5919] */
    (xdc_Char)0x69,  /* [5920] */
    (xdc_Char)0x63,  /* [5921] */
    (xdc_Char)0x6b,  /* [5922] */
    (xdc_Char)0x3a,  /* [5923] */
    (xdc_Char)0x20,  /* [5924] */
    (xdc_Char)0x74,  /* [5925] */
    (xdc_Char)0x69,  /* [5926] */
    (xdc_Char)0x63,  /* [5927] */
    (xdc_Char)0x6b,  /* [5928] */
    (xdc_Char)0x3a,  /* [5929] */
    (xdc_Char)0x20,  /* [5930] */
    (xdc_Char)0x25,  /* [5931] */
    (xdc_Char)0x64,  /* [5932] */
    (xdc_Char)0x0,  /* [5933] */
    (xdc_Char)0x4c,  /* [5934] */
    (xdc_Char)0x4d,  /* [5935] */
    (xdc_Char)0x5f,  /* [5936] */
    (xdc_Char)0x62,  /* [5937] */
    (xdc_Char)0x65,  /* [5938] */
    (xdc_Char)0x67,  /* [5939] */
    (xdc_Char)0x69,  /* [5940] */
    (xdc_Char)0x6e,  /* [5941] */
    (xdc_Char)0x3a,  /* [5942] */
    (xdc_Char)0x20,  /* [5943] */
    (xdc_Char)0x63,  /* [5944] */
    (xdc_Char)0x6c,  /* [5945] */
    (xdc_Char)0x6b,  /* [5946] */
    (xdc_Char)0x3a,  /* [5947] */
    (xdc_Char)0x20,  /* [5948] */
    (xdc_Char)0x30,  /* [5949] */
    (xdc_Char)0x78,  /* [5950] */
    (xdc_Char)0x25,  /* [5951] */
    (xdc_Char)0x78,  /* [5952] */
    (xdc_Char)0x2c,  /* [5953] */
    (xdc_Char)0x20,  /* [5954] */
    (xdc_Char)0x66,  /* [5955] */
    (xdc_Char)0x75,  /* [5956] */
    (xdc_Char)0x6e,  /* [5957] */
    (xdc_Char)0x63,  /* [5958] */
    (xdc_Char)0x3a,  /* [5959] */
    (xdc_Char)0x20,  /* [5960] */
    (xdc_Char)0x30,  /* [5961] */
    (xdc_Char)0x78,  /* [5962] */
    (xdc_Char)0x25,  /* [5963] */
    (xdc_Char)0x78,  /* [5964] */
    (xdc_Char)0x0,  /* [5965] */
    (xdc_Char)0x4c,  /* [5966] */
    (xdc_Char)0x4d,  /* [5967] */
    (xdc_Char)0x5f,  /* [5968] */
    (xdc_Char)0x70,  /* [5969] */
    (xdc_Char)0x6f,  /* [5970] */
    (xdc_Char)0x73,  /* [5971] */
    (xdc_Char)0x74,  /* [5972] */
    (xdc_Char)0x3a,  /* [5973] */
    (xdc_Char)0x20,  /* [5974] */
    (xdc_Char)0x73,  /* [5975] */
    (xdc_Char)0x65,  /* [5976] */
    (xdc_Char)0x6d,  /* [5977] */
    (xdc_Char)0x3a,  /* [5978] */
    (xdc_Char)0x20,  /* [5979] */
    (xdc_Char)0x30,  /* [5980] */
    (xdc_Char)0x78,  /* [5981] */
    (xdc_Char)0x25,  /* [5982] */
    (xdc_Char)0x78,  /* [5983] */
    (xdc_Char)0x2c,  /* [5984] */
    (xdc_Char)0x20,  /* [5985] */
    (xdc_Char)0x63,  /* [5986] */
    (xdc_Char)0x6f,  /* [5987] */
    (xdc_Char)0x75,  /* [5988] */
    (xdc_Char)0x6e,  /* [5989] */
    (xdc_Char)0x74,  /* [5990] */
    (xdc_Char)0x3a,  /* [5991] */
    (xdc_Char)0x20,  /* [5992] */
    (xdc_Char)0x25,  /* [5993] */
    (xdc_Char)0x64,  /* [5994] */
    (xdc_Char)0x0,  /* [5995] */
    (xdc_Char)0x4c,  /* [5996] */
    (xdc_Char)0x4d,  /* [5997] */
    (xdc_Char)0x5f,  /* [5998] */
    (xdc_Char)0x70,  /* [5999] */
    (xdc_Char)0x65,  /* [6000] */
    (xdc_Char)0x6e,  /* [6001] */
    (xdc_Char)0x64,  /* [6002] */
    (xdc_Char)0x3a,  /* [6003] */
    (xdc_Char)0x20,  /* [6004] */
    (xdc_Char)0x73,  /* [6005] */
    (xdc_Char)0x65,  /* [6006] */
    (xdc_Char)0x6d,  /* [6007] */
    (xdc_Char)0x3a,  /* [6008] */
    (xdc_Char)0x20,  /* [6009] */
    (xdc_Char)0x30,  /* [6010] */
    (xdc_Char)0x78,  /* [6011] */
    (xdc_Char)0x25,  /* [6012] */
    (xdc_Char)0x78,  /* [6013] */
    (xdc_Char)0x2c,  /* [6014] */
    (xdc_Char)0x20,  /* [6015] */
    (xdc_Char)0x63,  /* [6016] */
    (xdc_Char)0x6f,  /* [6017] */
    (xdc_Char)0x75,  /* [6018] */
    (xdc_Char)0x6e,  /* [6019] */
    (xdc_Char)0x74,  /* [6020] */
    (xdc_Char)0x3a,  /* [6021] */
    (xdc_Char)0x20,  /* [6022] */
    (xdc_Char)0x25,  /* [6023] */
    (xdc_Char)0x64,  /* [6024] */
    (xdc_Char)0x2c,  /* [6025] */
    (xdc_Char)0x20,  /* [6026] */
    (xdc_Char)0x74,  /* [6027] */
    (xdc_Char)0x69,  /* [6028] */
    (xdc_Char)0x6d,  /* [6029] */
    (xdc_Char)0x65,  /* [6030] */
    (xdc_Char)0x6f,  /* [6031] */
    (xdc_Char)0x75,  /* [6032] */
    (xdc_Char)0x74,  /* [6033] */
    (xdc_Char)0x3a,  /* [6034] */
    (xdc_Char)0x20,  /* [6035] */
    (xdc_Char)0x25,  /* [6036] */
    (xdc_Char)0x64,  /* [6037] */
    (xdc_Char)0x0,  /* [6038] */
    (xdc_Char)0x4c,  /* [6039] */
    (xdc_Char)0x4d,  /* [6040] */
    (xdc_Char)0x5f,  /* [6041] */
    (xdc_Char)0x62,  /* [6042] */
    (xdc_Char)0x65,  /* [6043] */
    (xdc_Char)0x67,  /* [6044] */
    (xdc_Char)0x69,  /* [6045] */
    (xdc_Char)0x6e,  /* [6046] */
    (xdc_Char)0x3a,  /* [6047] */
    (xdc_Char)0x20,  /* [6048] */
    (xdc_Char)0x73,  /* [6049] */
    (xdc_Char)0x77,  /* [6050] */
    (xdc_Char)0x69,  /* [6051] */
    (xdc_Char)0x3a,  /* [6052] */
    (xdc_Char)0x20,  /* [6053] */
    (xdc_Char)0x30,  /* [6054] */
    (xdc_Char)0x78,  /* [6055] */
    (xdc_Char)0x25,  /* [6056] */
    (xdc_Char)0x78,  /* [6057] */
    (xdc_Char)0x2c,  /* [6058] */
    (xdc_Char)0x20,  /* [6059] */
    (xdc_Char)0x66,  /* [6060] */
    (xdc_Char)0x75,  /* [6061] */
    (xdc_Char)0x6e,  /* [6062] */
    (xdc_Char)0x63,  /* [6063] */
    (xdc_Char)0x3a,  /* [6064] */
    (xdc_Char)0x20,  /* [6065] */
    (xdc_Char)0x30,  /* [6066] */
    (xdc_Char)0x78,  /* [6067] */
    (xdc_Char)0x25,  /* [6068] */
    (xdc_Char)0x78,  /* [6069] */
    (xdc_Char)0x2c,  /* [6070] */
    (xdc_Char)0x20,  /* [6071] */
    (xdc_Char)0x70,  /* [6072] */
    (xdc_Char)0x72,  /* [6073] */
    (xdc_Char)0x65,  /* [6074] */
    (xdc_Char)0x54,  /* [6075] */
    (xdc_Char)0x68,  /* [6076] */
    (xdc_Char)0x72,  /* [6077] */
    (xdc_Char)0x65,  /* [6078] */
    (xdc_Char)0x61,  /* [6079] */
    (xdc_Char)0x64,  /* [6080] */
    (xdc_Char)0x3a,  /* [6081] */
    (xdc_Char)0x20,  /* [6082] */
    (xdc_Char)0x25,  /* [6083] */
    (xdc_Char)0x64,  /* [6084] */
    (xdc_Char)0x0,  /* [6085] */
    (xdc_Char)0x4c,  /* [6086] */
    (xdc_Char)0x44,  /* [6087] */
    (xdc_Char)0x5f,  /* [6088] */
    (xdc_Char)0x65,  /* [6089] */
    (xdc_Char)0x6e,  /* [6090] */
    (xdc_Char)0x64,  /* [6091] */
    (xdc_Char)0x3a,  /* [6092] */
    (xdc_Char)0x20,  /* [6093] */
    (xdc_Char)0x73,  /* [6094] */
    (xdc_Char)0x77,  /* [6095] */
    (xdc_Char)0x69,  /* [6096] */
    (xdc_Char)0x3a,  /* [6097] */
    (xdc_Char)0x20,  /* [6098] */
    (xdc_Char)0x30,  /* [6099] */
    (xdc_Char)0x78,  /* [6100] */
    (xdc_Char)0x25,  /* [6101] */
    (xdc_Char)0x78,  /* [6102] */
    (xdc_Char)0x0,  /* [6103] */
    (xdc_Char)0x4c,  /* [6104] */
    (xdc_Char)0x4d,  /* [6105] */
    (xdc_Char)0x5f,  /* [6106] */
    (xdc_Char)0x70,  /* [6107] */
    (xdc_Char)0x6f,  /* [6108] */
    (xdc_Char)0x73,  /* [6109] */
    (xdc_Char)0x74,  /* [6110] */
    (xdc_Char)0x3a,  /* [6111] */
    (xdc_Char)0x20,  /* [6112] */
    (xdc_Char)0x73,  /* [6113] */
    (xdc_Char)0x77,  /* [6114] */
    (xdc_Char)0x69,  /* [6115] */
    (xdc_Char)0x3a,  /* [6116] */
    (xdc_Char)0x20,  /* [6117] */
    (xdc_Char)0x30,  /* [6118] */
    (xdc_Char)0x78,  /* [6119] */
    (xdc_Char)0x25,  /* [6120] */
    (xdc_Char)0x78,  /* [6121] */
    (xdc_Char)0x2c,  /* [6122] */
    (xdc_Char)0x20,  /* [6123] */
    (xdc_Char)0x66,  /* [6124] */
    (xdc_Char)0x75,  /* [6125] */
    (xdc_Char)0x6e,  /* [6126] */
    (xdc_Char)0x63,  /* [6127] */
    (xdc_Char)0x3a,  /* [6128] */
    (xdc_Char)0x20,  /* [6129] */
    (xdc_Char)0x30,  /* [6130] */
    (xdc_Char)0x78,  /* [6131] */
    (xdc_Char)0x25,  /* [6132] */
    (xdc_Char)0x78,  /* [6133] */
    (xdc_Char)0x2c,  /* [6134] */
    (xdc_Char)0x20,  /* [6135] */
    (xdc_Char)0x70,  /* [6136] */
    (xdc_Char)0x72,  /* [6137] */
    (xdc_Char)0x69,  /* [6138] */
    (xdc_Char)0x3a,  /* [6139] */
    (xdc_Char)0x20,  /* [6140] */
    (xdc_Char)0x25,  /* [6141] */
    (xdc_Char)0x64,  /* [6142] */
    (xdc_Char)0x0,  /* [6143] */
    (xdc_Char)0x4c,  /* [6144] */
    (xdc_Char)0x4d,  /* [6145] */
    (xdc_Char)0x5f,  /* [6146] */
    (xdc_Char)0x73,  /* [6147] */
    (xdc_Char)0x77,  /* [6148] */
    (xdc_Char)0x69,  /* [6149] */
    (xdc_Char)0x74,  /* [6150] */
    (xdc_Char)0x63,  /* [6151] */
    (xdc_Char)0x68,  /* [6152] */
    (xdc_Char)0x3a,  /* [6153] */
    (xdc_Char)0x20,  /* [6154] */
    (xdc_Char)0x6f,  /* [6155] */
    (xdc_Char)0x6c,  /* [6156] */
    (xdc_Char)0x64,  /* [6157] */
    (xdc_Char)0x74,  /* [6158] */
    (xdc_Char)0x73,  /* [6159] */
    (xdc_Char)0x6b,  /* [6160] */
    (xdc_Char)0x3a,  /* [6161] */
    (xdc_Char)0x20,  /* [6162] */
    (xdc_Char)0x30,  /* [6163] */
    (xdc_Char)0x78,  /* [6164] */
    (xdc_Char)0x25,  /* [6165] */
    (xdc_Char)0x78,  /* [6166] */
    (xdc_Char)0x2c,  /* [6167] */
    (xdc_Char)0x20,  /* [6168] */
    (xdc_Char)0x6f,  /* [6169] */
    (xdc_Char)0x6c,  /* [6170] */
    (xdc_Char)0x64,  /* [6171] */
    (xdc_Char)0x66,  /* [6172] */
    (xdc_Char)0x75,  /* [6173] */
    (xdc_Char)0x6e,  /* [6174] */
    (xdc_Char)0x63,  /* [6175] */
    (xdc_Char)0x3a,  /* [6176] */
    (xdc_Char)0x20,  /* [6177] */
    (xdc_Char)0x30,  /* [6178] */
    (xdc_Char)0x78,  /* [6179] */
    (xdc_Char)0x25,  /* [6180] */
    (xdc_Char)0x78,  /* [6181] */
    (xdc_Char)0x2c,  /* [6182] */
    (xdc_Char)0x20,  /* [6183] */
    (xdc_Char)0x6e,  /* [6184] */
    (xdc_Char)0x65,  /* [6185] */
    (xdc_Char)0x77,  /* [6186] */
    (xdc_Char)0x74,  /* [6187] */
    (xdc_Char)0x73,  /* [6188] */
    (xdc_Char)0x6b,  /* [6189] */
    (xdc_Char)0x3a,  /* [6190] */
    (xdc_Char)0x20,  /* [6191] */
    (xdc_Char)0x30,  /* [6192] */
    (xdc_Char)0x78,  /* [6193] */
    (xdc_Char)0x25,  /* [6194] */
    (xdc_Char)0x78,  /* [6195] */
    (xdc_Char)0x2c,  /* [6196] */
    (xdc_Char)0x20,  /* [6197] */
    (xdc_Char)0x6e,  /* [6198] */
    (xdc_Char)0x65,  /* [6199] */
    (xdc_Char)0x77,  /* [6200] */
    (xdc_Char)0x66,  /* [6201] */
    (xdc_Char)0x75,  /* [6202] */
    (xdc_Char)0x6e,  /* [6203] */
    (xdc_Char)0x63,  /* [6204] */
    (xdc_Char)0x3a,  /* [6205] */
    (xdc_Char)0x20,  /* [6206] */
    (xdc_Char)0x30,  /* [6207] */
    (xdc_Char)0x78,  /* [6208] */
    (xdc_Char)0x25,  /* [6209] */
    (xdc_Char)0x78,  /* [6210] */
    (xdc_Char)0x0,  /* [6211] */
    (xdc_Char)0x4c,  /* [6212] */
    (xdc_Char)0x4d,  /* [6213] */
    (xdc_Char)0x5f,  /* [6214] */
    (xdc_Char)0x73,  /* [6215] */
    (xdc_Char)0x6c,  /* [6216] */
    (xdc_Char)0x65,  /* [6217] */
    (xdc_Char)0x65,  /* [6218] */
    (xdc_Char)0x70,  /* [6219] */
    (xdc_Char)0x3a,  /* [6220] */
    (xdc_Char)0x20,  /* [6221] */
    (xdc_Char)0x74,  /* [6222] */
    (xdc_Char)0x73,  /* [6223] */
    (xdc_Char)0x6b,  /* [6224] */
    (xdc_Char)0x3a,  /* [6225] */
    (xdc_Char)0x20,  /* [6226] */
    (xdc_Char)0x30,  /* [6227] */
    (xdc_Char)0x78,  /* [6228] */
    (xdc_Char)0x25,  /* [6229] */
    (xdc_Char)0x78,  /* [6230] */
    (xdc_Char)0x2c,  /* [6231] */
    (xdc_Char)0x20,  /* [6232] */
    (xdc_Char)0x66,  /* [6233] */
    (xdc_Char)0x75,  /* [6234] */
    (xdc_Char)0x6e,  /* [6235] */
    (xdc_Char)0x63,  /* [6236] */
    (xdc_Char)0x3a,  /* [6237] */
    (xdc_Char)0x20,  /* [6238] */
    (xdc_Char)0x30,  /* [6239] */
    (xdc_Char)0x78,  /* [6240] */
    (xdc_Char)0x25,  /* [6241] */
    (xdc_Char)0x78,  /* [6242] */
    (xdc_Char)0x2c,  /* [6243] */
    (xdc_Char)0x20,  /* [6244] */
    (xdc_Char)0x74,  /* [6245] */
    (xdc_Char)0x69,  /* [6246] */
    (xdc_Char)0x6d,  /* [6247] */
    (xdc_Char)0x65,  /* [6248] */
    (xdc_Char)0x6f,  /* [6249] */
    (xdc_Char)0x75,  /* [6250] */
    (xdc_Char)0x74,  /* [6251] */
    (xdc_Char)0x3a,  /* [6252] */
    (xdc_Char)0x20,  /* [6253] */
    (xdc_Char)0x25,  /* [6254] */
    (xdc_Char)0x64,  /* [6255] */
    (xdc_Char)0x0,  /* [6256] */
    (xdc_Char)0x4c,  /* [6257] */
    (xdc_Char)0x44,  /* [6258] */
    (xdc_Char)0x5f,  /* [6259] */
    (xdc_Char)0x72,  /* [6260] */
    (xdc_Char)0x65,  /* [6261] */
    (xdc_Char)0x61,  /* [6262] */
    (xdc_Char)0x64,  /* [6263] */
    (xdc_Char)0x79,  /* [6264] */
    (xdc_Char)0x3a,  /* [6265] */
    (xdc_Char)0x20,  /* [6266] */
    (xdc_Char)0x74,  /* [6267] */
    (xdc_Char)0x73,  /* [6268] */
    (xdc_Char)0x6b,  /* [6269] */
    (xdc_Char)0x3a,  /* [6270] */
    (xdc_Char)0x20,  /* [6271] */
    (xdc_Char)0x30,  /* [6272] */
    (xdc_Char)0x78,  /* [6273] */
    (xdc_Char)0x25,  /* [6274] */
    (xdc_Char)0x78,  /* [6275] */
    (xdc_Char)0x2c,  /* [6276] */
    (xdc_Char)0x20,  /* [6277] */
    (xdc_Char)0x66,  /* [6278] */
    (xdc_Char)0x75,  /* [6279] */
    (xdc_Char)0x6e,  /* [6280] */
    (xdc_Char)0x63,  /* [6281] */
    (xdc_Char)0x3a,  /* [6282] */
    (xdc_Char)0x20,  /* [6283] */
    (xdc_Char)0x30,  /* [6284] */
    (xdc_Char)0x78,  /* [6285] */
    (xdc_Char)0x25,  /* [6286] */
    (xdc_Char)0x78,  /* [6287] */
    (xdc_Char)0x2c,  /* [6288] */
    (xdc_Char)0x20,  /* [6289] */
    (xdc_Char)0x70,  /* [6290] */
    (xdc_Char)0x72,  /* [6291] */
    (xdc_Char)0x69,  /* [6292] */
    (xdc_Char)0x3a,  /* [6293] */
    (xdc_Char)0x20,  /* [6294] */
    (xdc_Char)0x25,  /* [6295] */
    (xdc_Char)0x64,  /* [6296] */
    (xdc_Char)0x0,  /* [6297] */
    (xdc_Char)0x4c,  /* [6298] */
    (xdc_Char)0x44,  /* [6299] */
    (xdc_Char)0x5f,  /* [6300] */
    (xdc_Char)0x62,  /* [6301] */
    (xdc_Char)0x6c,  /* [6302] */
    (xdc_Char)0x6f,  /* [6303] */
    (xdc_Char)0x63,  /* [6304] */
    (xdc_Char)0x6b,  /* [6305] */
    (xdc_Char)0x3a,  /* [6306] */
    (xdc_Char)0x20,  /* [6307] */
    (xdc_Char)0x74,  /* [6308] */
    (xdc_Char)0x73,  /* [6309] */
    (xdc_Char)0x6b,  /* [6310] */
    (xdc_Char)0x3a,  /* [6311] */
    (xdc_Char)0x20,  /* [6312] */
    (xdc_Char)0x30,  /* [6313] */
    (xdc_Char)0x78,  /* [6314] */
    (xdc_Char)0x25,  /* [6315] */
    (xdc_Char)0x78,  /* [6316] */
    (xdc_Char)0x2c,  /* [6317] */
    (xdc_Char)0x20,  /* [6318] */
    (xdc_Char)0x66,  /* [6319] */
    (xdc_Char)0x75,  /* [6320] */
    (xdc_Char)0x6e,  /* [6321] */
    (xdc_Char)0x63,  /* [6322] */
    (xdc_Char)0x3a,  /* [6323] */
    (xdc_Char)0x20,  /* [6324] */
    (xdc_Char)0x30,  /* [6325] */
    (xdc_Char)0x78,  /* [6326] */
    (xdc_Char)0x25,  /* [6327] */
    (xdc_Char)0x78,  /* [6328] */
    (xdc_Char)0x0,  /* [6329] */
    (xdc_Char)0x4c,  /* [6330] */
    (xdc_Char)0x4d,  /* [6331] */
    (xdc_Char)0x5f,  /* [6332] */
    (xdc_Char)0x79,  /* [6333] */
    (xdc_Char)0x69,  /* [6334] */
    (xdc_Char)0x65,  /* [6335] */
    (xdc_Char)0x6c,  /* [6336] */
    (xdc_Char)0x64,  /* [6337] */
    (xdc_Char)0x3a,  /* [6338] */
    (xdc_Char)0x20,  /* [6339] */
    (xdc_Char)0x74,  /* [6340] */
    (xdc_Char)0x73,  /* [6341] */
    (xdc_Char)0x6b,  /* [6342] */
    (xdc_Char)0x3a,  /* [6343] */
    (xdc_Char)0x20,  /* [6344] */
    (xdc_Char)0x30,  /* [6345] */
    (xdc_Char)0x78,  /* [6346] */
    (xdc_Char)0x25,  /* [6347] */
    (xdc_Char)0x78,  /* [6348] */
    (xdc_Char)0x2c,  /* [6349] */
    (xdc_Char)0x20,  /* [6350] */
    (xdc_Char)0x66,  /* [6351] */
    (xdc_Char)0x75,  /* [6352] */
    (xdc_Char)0x6e,  /* [6353] */
    (xdc_Char)0x63,  /* [6354] */
    (xdc_Char)0x3a,  /* [6355] */
    (xdc_Char)0x20,  /* [6356] */
    (xdc_Char)0x30,  /* [6357] */
    (xdc_Char)0x78,  /* [6358] */
    (xdc_Char)0x25,  /* [6359] */
    (xdc_Char)0x78,  /* [6360] */
    (xdc_Char)0x2c,  /* [6361] */
    (xdc_Char)0x20,  /* [6362] */
    (xdc_Char)0x63,  /* [6363] */
    (xdc_Char)0x75,  /* [6364] */
    (xdc_Char)0x72,  /* [6365] */
    (xdc_Char)0x72,  /* [6366] */
    (xdc_Char)0x54,  /* [6367] */
    (xdc_Char)0x68,  /* [6368] */
    (xdc_Char)0x72,  /* [6369] */
    (xdc_Char)0x65,  /* [6370] */
    (xdc_Char)0x61,  /* [6371] */
    (xdc_Char)0x64,  /* [6372] */
    (xdc_Char)0x3a,  /* [6373] */
    (xdc_Char)0x20,  /* [6374] */
    (xdc_Char)0x25,  /* [6375] */
    (xdc_Char)0x64,  /* [6376] */
    (xdc_Char)0x0,  /* [6377] */
    (xdc_Char)0x4c,  /* [6378] */
    (xdc_Char)0x4d,  /* [6379] */
    (xdc_Char)0x5f,  /* [6380] */
    (xdc_Char)0x73,  /* [6381] */
    (xdc_Char)0x65,  /* [6382] */
    (xdc_Char)0x74,  /* [6383] */
    (xdc_Char)0x50,  /* [6384] */
    (xdc_Char)0x72,  /* [6385] */
    (xdc_Char)0x69,  /* [6386] */
    (xdc_Char)0x3a,  /* [6387] */
    (xdc_Char)0x20,  /* [6388] */
    (xdc_Char)0x74,  /* [6389] */
    (xdc_Char)0x73,  /* [6390] */
    (xdc_Char)0x6b,  /* [6391] */
    (xdc_Char)0x3a,  /* [6392] */
    (xdc_Char)0x20,  /* [6393] */
    (xdc_Char)0x30,  /* [6394] */
    (xdc_Char)0x78,  /* [6395] */
    (xdc_Char)0x25,  /* [6396] */
    (xdc_Char)0x78,  /* [6397] */
    (xdc_Char)0x2c,  /* [6398] */
    (xdc_Char)0x20,  /* [6399] */
    (xdc_Char)0x66,  /* [6400] */
    (xdc_Char)0x75,  /* [6401] */
    (xdc_Char)0x6e,  /* [6402] */
    (xdc_Char)0x63,  /* [6403] */
    (xdc_Char)0x3a,  /* [6404] */
    (xdc_Char)0x20,  /* [6405] */
    (xdc_Char)0x30,  /* [6406] */
    (xdc_Char)0x78,  /* [6407] */
    (xdc_Char)0x25,  /* [6408] */
    (xdc_Char)0x78,  /* [6409] */
    (xdc_Char)0x2c,  /* [6410] */
    (xdc_Char)0x20,  /* [6411] */
    (xdc_Char)0x6f,  /* [6412] */
    (xdc_Char)0x6c,  /* [6413] */
    (xdc_Char)0x64,  /* [6414] */
    (xdc_Char)0x50,  /* [6415] */
    (xdc_Char)0x72,  /* [6416] */
    (xdc_Char)0x69,  /* [6417] */
    (xdc_Char)0x3a,  /* [6418] */
    (xdc_Char)0x20,  /* [6419] */
    (xdc_Char)0x25,  /* [6420] */
    (xdc_Char)0x64,  /* [6421] */
    (xdc_Char)0x2c,  /* [6422] */
    (xdc_Char)0x20,  /* [6423] */
    (xdc_Char)0x6e,  /* [6424] */
    (xdc_Char)0x65,  /* [6425] */
    (xdc_Char)0x77,  /* [6426] */
    (xdc_Char)0x50,  /* [6427] */
    (xdc_Char)0x72,  /* [6428] */
    (xdc_Char)0x69,  /* [6429] */
    (xdc_Char)0x20,  /* [6430] */
    (xdc_Char)0x25,  /* [6431] */
    (xdc_Char)0x64,  /* [6432] */
    (xdc_Char)0x0,  /* [6433] */
    (xdc_Char)0x4c,  /* [6434] */
    (xdc_Char)0x44,  /* [6435] */
    (xdc_Char)0x5f,  /* [6436] */
    (xdc_Char)0x65,  /* [6437] */
    (xdc_Char)0x78,  /* [6438] */
    (xdc_Char)0x69,  /* [6439] */
    (xdc_Char)0x74,  /* [6440] */
    (xdc_Char)0x3a,  /* [6441] */
    (xdc_Char)0x20,  /* [6442] */
    (xdc_Char)0x74,  /* [6443] */
    (xdc_Char)0x73,  /* [6444] */
    (xdc_Char)0x6b,  /* [6445] */
    (xdc_Char)0x3a,  /* [6446] */
    (xdc_Char)0x20,  /* [6447] */
    (xdc_Char)0x30,  /* [6448] */
    (xdc_Char)0x78,  /* [6449] */
    (xdc_Char)0x25,  /* [6450] */
    (xdc_Char)0x78,  /* [6451] */
    (xdc_Char)0x2c,  /* [6452] */
    (xdc_Char)0x20,  /* [6453] */
    (xdc_Char)0x66,  /* [6454] */
    (xdc_Char)0x75,  /* [6455] */
    (xdc_Char)0x6e,  /* [6456] */
    (xdc_Char)0x63,  /* [6457] */
    (xdc_Char)0x3a,  /* [6458] */
    (xdc_Char)0x20,  /* [6459] */
    (xdc_Char)0x30,  /* [6460] */
    (xdc_Char)0x78,  /* [6461] */
    (xdc_Char)0x25,  /* [6462] */
    (xdc_Char)0x78,  /* [6463] */
    (xdc_Char)0x0,  /* [6464] */
    (xdc_Char)0x78,  /* [6465] */
    (xdc_Char)0x64,  /* [6466] */
    (xdc_Char)0x63,  /* [6467] */
    (xdc_Char)0x2e,  /* [6468] */
    (xdc_Char)0x0,  /* [6469] */
    (xdc_Char)0x72,  /* [6470] */
    (xdc_Char)0x75,  /* [6471] */
    (xdc_Char)0x6e,  /* [6472] */
    (xdc_Char)0x74,  /* [6473] */
    (xdc_Char)0x69,  /* [6474] */
    (xdc_Char)0x6d,  /* [6475] */
    (xdc_Char)0x65,  /* [6476] */
    (xdc_Char)0x2e,  /* [6477] */
    (xdc_Char)0x0,  /* [6478] */
    (xdc_Char)0x41,  /* [6479] */
    (xdc_Char)0x73,  /* [6480] */
    (xdc_Char)0x73,  /* [6481] */
    (xdc_Char)0x65,  /* [6482] */
    (xdc_Char)0x72,  /* [6483] */
    (xdc_Char)0x74,  /* [6484] */
    (xdc_Char)0x0,  /* [6485] */
    (xdc_Char)0x43,  /* [6486] */
    (xdc_Char)0x6f,  /* [6487] */
    (xdc_Char)0x72,  /* [6488] */
    (xdc_Char)0x65,  /* [6489] */
    (xdc_Char)0x0,  /* [6490] */
    (xdc_Char)0x44,  /* [6491] */
    (xdc_Char)0x65,  /* [6492] */
    (xdc_Char)0x66,  /* [6493] */
    (xdc_Char)0x61,  /* [6494] */
    (xdc_Char)0x75,  /* [6495] */
    (xdc_Char)0x6c,  /* [6496] */
    (xdc_Char)0x74,  /* [6497] */
    (xdc_Char)0x73,  /* [6498] */
    (xdc_Char)0x0,  /* [6499] */
    (xdc_Char)0x44,  /* [6500] */
    (xdc_Char)0x69,  /* [6501] */
    (xdc_Char)0x61,  /* [6502] */
    (xdc_Char)0x67,  /* [6503] */
    (xdc_Char)0x73,  /* [6504] */
    (xdc_Char)0x0,  /* [6505] */
    (xdc_Char)0x45,  /* [6506] */
    (xdc_Char)0x72,  /* [6507] */
    (xdc_Char)0x72,  /* [6508] */
    (xdc_Char)0x6f,  /* [6509] */
    (xdc_Char)0x72,  /* [6510] */
    (xdc_Char)0x0,  /* [6511] */
    (xdc_Char)0x47,  /* [6512] */
    (xdc_Char)0x61,  /* [6513] */
    (xdc_Char)0x74,  /* [6514] */
    (xdc_Char)0x65,  /* [6515] */
    (xdc_Char)0x0,  /* [6516] */
    (xdc_Char)0x4c,  /* [6517] */
    (xdc_Char)0x6f,  /* [6518] */
    (xdc_Char)0x67,  /* [6519] */
    (xdc_Char)0x0,  /* [6520] */
    (xdc_Char)0x4d,  /* [6521] */
    (xdc_Char)0x61,  /* [6522] */
    (xdc_Char)0x69,  /* [6523] */
    (xdc_Char)0x6e,  /* [6524] */
    (xdc_Char)0x0,  /* [6525] */
    (xdc_Char)0x4d,  /* [6526] */
    (xdc_Char)0x65,  /* [6527] */
    (xdc_Char)0x6d,  /* [6528] */
    (xdc_Char)0x6f,  /* [6529] */
    (xdc_Char)0x72,  /* [6530] */
    (xdc_Char)0x79,  /* [6531] */
    (xdc_Char)0x0,  /* [6532] */
    (xdc_Char)0x52,  /* [6533] */
    (xdc_Char)0x65,  /* [6534] */
    (xdc_Char)0x67,  /* [6535] */
    (xdc_Char)0x69,  /* [6536] */
    (xdc_Char)0x73,  /* [6537] */
    (xdc_Char)0x74,  /* [6538] */
    (xdc_Char)0x72,  /* [6539] */
    (xdc_Char)0x79,  /* [6540] */
    (xdc_Char)0x0,  /* [6541] */
    (xdc_Char)0x53,  /* [6542] */
    (xdc_Char)0x74,  /* [6543] */
    (xdc_Char)0x61,  /* [6544] */
    (xdc_Char)0x72,  /* [6545] */
    (xdc_Char)0x74,  /* [6546] */
    (xdc_Char)0x75,  /* [6547] */
    (xdc_Char)0x70,  /* [6548] */
    (xdc_Char)0x0,  /* [6549] */
    (xdc_Char)0x53,  /* [6550] */
    (xdc_Char)0x79,  /* [6551] */
    (xdc_Char)0x73,  /* [6552] */
    (xdc_Char)0x74,  /* [6553] */
    (xdc_Char)0x65,  /* [6554] */
    (xdc_Char)0x6d,  /* [6555] */
    (xdc_Char)0x0,  /* [6556] */
    (xdc_Char)0x53,  /* [6557] */
    (xdc_Char)0x79,  /* [6558] */
    (xdc_Char)0x73,  /* [6559] */
    (xdc_Char)0x4d,  /* [6560] */
    (xdc_Char)0x69,  /* [6561] */
    (xdc_Char)0x6e,  /* [6562] */
    (xdc_Char)0x0,  /* [6563] */
    (xdc_Char)0x54,  /* [6564] */
    (xdc_Char)0x65,  /* [6565] */
    (xdc_Char)0x78,  /* [6566] */
    (xdc_Char)0x74,  /* [6567] */
    (xdc_Char)0x0,  /* [6568] */
    (xdc_Char)0x54,  /* [6569] */
    (xdc_Char)0x69,  /* [6570] */
    (xdc_Char)0x6d,  /* [6571] */
    (xdc_Char)0x65,  /* [6572] */
    (xdc_Char)0x73,  /* [6573] */
    (xdc_Char)0x74,  /* [6574] */
    (xdc_Char)0x61,  /* [6575] */
    (xdc_Char)0x6d,  /* [6576] */
    (xdc_Char)0x70,  /* [6577] */
    (xdc_Char)0x0,  /* [6578] */
    (xdc_Char)0x74,  /* [6579] */
    (xdc_Char)0x69,  /* [6580] */
    (xdc_Char)0x2e,  /* [6581] */
    (xdc_Char)0x0,  /* [6582] */
    (xdc_Char)0x73,  /* [6583] */
    (xdc_Char)0x79,  /* [6584] */
    (xdc_Char)0x73,  /* [6585] */
    (xdc_Char)0x62,  /* [6586] */
    (xdc_Char)0x69,  /* [6587] */
    (xdc_Char)0x6f,  /* [6588] */
    (xdc_Char)0x73,  /* [6589] */
    (xdc_Char)0x2e,  /* [6590] */
    (xdc_Char)0x0,  /* [6591] */
    (xdc_Char)0x66,  /* [6592] */
    (xdc_Char)0x61,  /* [6593] */
    (xdc_Char)0x6d,  /* [6594] */
    (xdc_Char)0x69,  /* [6595] */
    (xdc_Char)0x6c,  /* [6596] */
    (xdc_Char)0x79,  /* [6597] */
    (xdc_Char)0x2e,  /* [6598] */
    (xdc_Char)0x0,  /* [6599] */
    (xdc_Char)0x63,  /* [6600] */
    (xdc_Char)0x36,  /* [6601] */
    (xdc_Char)0x34,  /* [6602] */
    (xdc_Char)0x70,  /* [6603] */
    (xdc_Char)0x2e,  /* [6604] */
    (xdc_Char)0x0,  /* [6605] */
    (xdc_Char)0x45,  /* [6606] */
    (xdc_Char)0x78,  /* [6607] */
    (xdc_Char)0x63,  /* [6608] */
    (xdc_Char)0x65,  /* [6609] */
    (xdc_Char)0x70,  /* [6610] */
    (xdc_Char)0x74,  /* [6611] */
    (xdc_Char)0x69,  /* [6612] */
    (xdc_Char)0x6f,  /* [6613] */
    (xdc_Char)0x6e,  /* [6614] */
    (xdc_Char)0x0,  /* [6615] */
    (xdc_Char)0x48,  /* [6616] */
    (xdc_Char)0x77,  /* [6617] */
    (xdc_Char)0x69,  /* [6618] */
    (xdc_Char)0x0,  /* [6619] */
    (xdc_Char)0x54,  /* [6620] */
    (xdc_Char)0x69,  /* [6621] */
    (xdc_Char)0x6d,  /* [6622] */
    (xdc_Char)0x65,  /* [6623] */
    (xdc_Char)0x73,  /* [6624] */
    (xdc_Char)0x74,  /* [6625] */
    (xdc_Char)0x61,  /* [6626] */
    (xdc_Char)0x6d,  /* [6627] */
    (xdc_Char)0x70,  /* [6628] */
    (xdc_Char)0x50,  /* [6629] */
    (xdc_Char)0x72,  /* [6630] */
    (xdc_Char)0x6f,  /* [6631] */
    (xdc_Char)0x76,  /* [6632] */
    (xdc_Char)0x69,  /* [6633] */
    (xdc_Char)0x64,  /* [6634] */
    (xdc_Char)0x65,  /* [6635] */
    (xdc_Char)0x72,  /* [6636] */
    (xdc_Char)0x0,  /* [6637] */
    (xdc_Char)0x68,  /* [6638] */
    (xdc_Char)0x61,  /* [6639] */
    (xdc_Char)0x6c,  /* [6640] */
    (xdc_Char)0x2e,  /* [6641] */
    (xdc_Char)0x0,  /* [6642] */
    (xdc_Char)0x54,  /* [6643] */
    (xdc_Char)0x69,  /* [6644] */
    (xdc_Char)0x6d,  /* [6645] */
    (xdc_Char)0x65,  /* [6646] */
    (xdc_Char)0x72,  /* [6647] */
    (xdc_Char)0x0,  /* [6648] */
    (xdc_Char)0x6b,  /* [6649] */
    (xdc_Char)0x6e,  /* [6650] */
    (xdc_Char)0x6c,  /* [6651] */
    (xdc_Char)0x2e,  /* [6652] */
    (xdc_Char)0x0,  /* [6653] */
    (xdc_Char)0x43,  /* [6654] */
    (xdc_Char)0x6c,  /* [6655] */
    (xdc_Char)0x6f,  /* [6656] */
    (xdc_Char)0x63,  /* [6657] */
    (xdc_Char)0x6b,  /* [6658] */
    (xdc_Char)0x0,  /* [6659] */
    (xdc_Char)0x49,  /* [6660] */
    (xdc_Char)0x64,  /* [6661] */
    (xdc_Char)0x6c,  /* [6662] */
    (xdc_Char)0x65,  /* [6663] */
    (xdc_Char)0x0,  /* [6664] */
    (xdc_Char)0x49,  /* [6665] */
    (xdc_Char)0x6e,  /* [6666] */
    (xdc_Char)0x74,  /* [6667] */
    (xdc_Char)0x72,  /* [6668] */
    (xdc_Char)0x69,  /* [6669] */
    (xdc_Char)0x6e,  /* [6670] */
    (xdc_Char)0x73,  /* [6671] */
    (xdc_Char)0x69,  /* [6672] */
    (xdc_Char)0x63,  /* [6673] */
    (xdc_Char)0x73,  /* [6674] */
    (xdc_Char)0x0,  /* [6675] */
    (xdc_Char)0x51,  /* [6676] */
    (xdc_Char)0x75,  /* [6677] */
    (xdc_Char)0x65,  /* [6678] */
    (xdc_Char)0x75,  /* [6679] */
    (xdc_Char)0x65,  /* [6680] */
    (xdc_Char)0x0,  /* [6681] */
    (xdc_Char)0x53,  /* [6682] */
    (xdc_Char)0x65,  /* [6683] */
    (xdc_Char)0x6d,  /* [6684] */
    (xdc_Char)0x61,  /* [6685] */
    (xdc_Char)0x70,  /* [6686] */
    (xdc_Char)0x68,  /* [6687] */
    (xdc_Char)0x6f,  /* [6688] */
    (xdc_Char)0x72,  /* [6689] */
    (xdc_Char)0x65,  /* [6690] */
    (xdc_Char)0x0,  /* [6691] */
    (xdc_Char)0x53,  /* [6692] */
    (xdc_Char)0x77,  /* [6693] */
    (xdc_Char)0x69,  /* [6694] */
    (xdc_Char)0x0,  /* [6695] */
    (xdc_Char)0x54,  /* [6696] */
    (xdc_Char)0x61,  /* [6697] */
    (xdc_Char)0x73,  /* [6698] */
    (xdc_Char)0x6b,  /* [6699] */
    (xdc_Char)0x0,  /* [6700] */
    (xdc_Char)0x67,  /* [6701] */
    (xdc_Char)0x61,  /* [6702] */
    (xdc_Char)0x74,  /* [6703] */
    (xdc_Char)0x65,  /* [6704] */
    (xdc_Char)0x73,  /* [6705] */
    (xdc_Char)0x2e,  /* [6706] */
    (xdc_Char)0x0,  /* [6707] */
    (xdc_Char)0x47,  /* [6708] */
    (xdc_Char)0x61,  /* [6709] */
    (xdc_Char)0x74,  /* [6710] */
    (xdc_Char)0x65,  /* [6711] */
    (xdc_Char)0x48,  /* [6712] */
    (xdc_Char)0x77,  /* [6713] */
    (xdc_Char)0x69,  /* [6714] */
    (xdc_Char)0x0,  /* [6715] */
    (xdc_Char)0x47,  /* [6716] */
    (xdc_Char)0x61,  /* [6717] */
    (xdc_Char)0x74,  /* [6718] */
    (xdc_Char)0x65,  /* [6719] */
    (xdc_Char)0x4d,  /* [6720] */
    (xdc_Char)0x75,  /* [6721] */
    (xdc_Char)0x74,  /* [6722] */
    (xdc_Char)0x65,  /* [6723] */
    (xdc_Char)0x78,  /* [6724] */
    (xdc_Char)0x0,  /* [6725] */
    (xdc_Char)0x73,  /* [6726] */
    (xdc_Char)0x64,  /* [6727] */
    (xdc_Char)0x6f,  /* [6728] */
    (xdc_Char)0x2e,  /* [6729] */
    (xdc_Char)0x0,  /* [6730] */
    (xdc_Char)0x75,  /* [6731] */
    (xdc_Char)0x74,  /* [6732] */
    (xdc_Char)0x69,  /* [6733] */
    (xdc_Char)0x6c,  /* [6734] */
    (xdc_Char)0x73,  /* [6735] */
    (xdc_Char)0x2e,  /* [6736] */
    (xdc_Char)0x0,  /* [6737] */
    (xdc_Char)0x4e,  /* [6738] */
    (xdc_Char)0x61,  /* [6739] */
    (xdc_Char)0x6d,  /* [6740] */
    (xdc_Char)0x65,  /* [6741] */
    (xdc_Char)0x53,  /* [6742] */
    (xdc_Char)0x65,  /* [6743] */
    (xdc_Char)0x72,  /* [6744] */
    (xdc_Char)0x76,  /* [6745] */
    (xdc_Char)0x65,  /* [6746] */
    (xdc_Char)0x72,  /* [6747] */
    (xdc_Char)0x52,  /* [6748] */
    (xdc_Char)0x65,  /* [6749] */
    (xdc_Char)0x6d,  /* [6750] */
    (xdc_Char)0x6f,  /* [6751] */
    (xdc_Char)0x74,  /* [6752] */
    (xdc_Char)0x65,  /* [6753] */
    (xdc_Char)0x4e,  /* [6754] */
    (xdc_Char)0x75,  /* [6755] */
    (xdc_Char)0x6c,  /* [6756] */
    (xdc_Char)0x6c,  /* [6757] */
    (xdc_Char)0x0,  /* [6758] */
    (xdc_Char)0x42,  /* [6759] */
    (xdc_Char)0x49,  /* [6760] */
    (xdc_Char)0x4f,  /* [6761] */
    (xdc_Char)0x53,  /* [6762] */
    (xdc_Char)0x0,  /* [6763] */
    (xdc_Char)0x63,  /* [6764] */
    (xdc_Char)0x36,  /* [6765] */
    (xdc_Char)0x32,  /* [6766] */
    (xdc_Char)0x2e,  /* [6767] */
    (xdc_Char)0x0,  /* [6768] */
    (xdc_Char)0x54,  /* [6769] */
    (xdc_Char)0x61,  /* [6770] */
    (xdc_Char)0x73,  /* [6771] */
    (xdc_Char)0x6b,  /* [6772] */
    (xdc_Char)0x53,  /* [6773] */
    (xdc_Char)0x75,  /* [6774] */
    (xdc_Char)0x70,  /* [6775] */
    (xdc_Char)0x70,  /* [6776] */
    (xdc_Char)0x6f,  /* [6777] */
    (xdc_Char)0x72,  /* [6778] */
    (xdc_Char)0x74,  /* [6779] */
    (xdc_Char)0x0,  /* [6780] */
    (xdc_Char)0x49,  /* [6781] */
    (xdc_Char)0x6e,  /* [6782] */
    (xdc_Char)0x74,  /* [6783] */
    (xdc_Char)0x72,  /* [6784] */
    (xdc_Char)0x69,  /* [6785] */
    (xdc_Char)0x6e,  /* [6786] */
    (xdc_Char)0x73,  /* [6787] */
    (xdc_Char)0x69,  /* [6788] */
    (xdc_Char)0x63,  /* [6789] */
    (xdc_Char)0x73,  /* [6790] */
    (xdc_Char)0x53,  /* [6791] */
    (xdc_Char)0x75,  /* [6792] */
    (xdc_Char)0x70,  /* [6793] */
    (xdc_Char)0x70,  /* [6794] */
    (xdc_Char)0x6f,  /* [6795] */
    (xdc_Char)0x72,  /* [6796] */
    (xdc_Char)0x74,  /* [6797] */
    (xdc_Char)0x0,  /* [6798] */
    (xdc_Char)0x74,  /* [6799] */
    (xdc_Char)0x69,  /* [6800] */
    (xdc_Char)0x6d,  /* [6801] */
    (xdc_Char)0x65,  /* [6802] */
    (xdc_Char)0x72,  /* [6803] */
    (xdc_Char)0x73,  /* [6804] */
    (xdc_Char)0x2e,  /* [6805] */
    (xdc_Char)0x0,  /* [6806] */
    (xdc_Char)0x64,  /* [6807] */
    (xdc_Char)0x6d,  /* [6808] */
    (xdc_Char)0x74,  /* [6809] */
    (xdc_Char)0x69,  /* [6810] */
    (xdc_Char)0x6d,  /* [6811] */
    (xdc_Char)0x65,  /* [6812] */
    (xdc_Char)0x72,  /* [6813] */
    (xdc_Char)0x2e,  /* [6814] */
    (xdc_Char)0x0,  /* [6815] */
    (xdc_Char)0x74,  /* [6816] */
    (xdc_Char)0x65,  /* [6817] */
    (xdc_Char)0x73,  /* [6818] */
    (xdc_Char)0x6c,  /* [6819] */
    (xdc_Char)0x61,  /* [6820] */
    (xdc_Char)0x2e,  /* [6821] */
    (xdc_Char)0x0,  /* [6822] */
    (xdc_Char)0x54,  /* [6823] */
    (xdc_Char)0x69,  /* [6824] */
    (xdc_Char)0x6d,  /* [6825] */
    (xdc_Char)0x65,  /* [6826] */
    (xdc_Char)0x72,  /* [6827] */
    (xdc_Char)0x53,  /* [6828] */
    (xdc_Char)0x75,  /* [6829] */
    (xdc_Char)0x70,  /* [6830] */
    (xdc_Char)0x70,  /* [6831] */
    (xdc_Char)0x6f,  /* [6832] */
    (xdc_Char)0x72,  /* [6833] */
    (xdc_Char)0x74,  /* [6834] */
    (xdc_Char)0x0,  /* [6835] */
    (xdc_Char)0x57,  /* [6836] */
    (xdc_Char)0x75,  /* [6837] */
    (xdc_Char)0x67,  /* [6838] */
    (xdc_Char)0x65,  /* [6839] */
    (xdc_Char)0x6e,  /* [6840] */
    (xdc_Char)0x0,  /* [6841] */
    (xdc_Char)0x68,  /* [6842] */
    (xdc_Char)0x65,  /* [6843] */
    (xdc_Char)0x61,  /* [6844] */
    (xdc_Char)0x70,  /* [6845] */
    (xdc_Char)0x73,  /* [6846] */
    (xdc_Char)0x2e,  /* [6847] */
    (xdc_Char)0x0,  /* [6848] */
    (xdc_Char)0x48,  /* [6849] */
    (xdc_Char)0x65,  /* [6850] */
    (xdc_Char)0x61,  /* [6851] */
    (xdc_Char)0x70,  /* [6852] */
    (xdc_Char)0x4d,  /* [6853] */
    (xdc_Char)0x65,  /* [6854] */
    (xdc_Char)0x6d,  /* [6855] */
    (xdc_Char)0x0,  /* [6856] */
    (xdc_Char)0x74,  /* [6857] */
    (xdc_Char)0x69,  /* [6858] */
    (xdc_Char)0x2e,  /* [6859] */
    (xdc_Char)0x73,  /* [6860] */
    (xdc_Char)0x79,  /* [6861] */
    (xdc_Char)0x73,  /* [6862] */
    (xdc_Char)0x62,  /* [6863] */
    (xdc_Char)0x69,  /* [6864] */
    (xdc_Char)0x6f,  /* [6865] */
    (xdc_Char)0x73,  /* [6866] */
    (xdc_Char)0x2e,  /* [6867] */
    (xdc_Char)0x6b,  /* [6868] */
    (xdc_Char)0x6e,  /* [6869] */
    (xdc_Char)0x6c,  /* [6870] */
    (xdc_Char)0x2e,  /* [6871] */
    (xdc_Char)0x54,  /* [6872] */
    (xdc_Char)0x61,  /* [6873] */
    (xdc_Char)0x73,  /* [6874] */
    (xdc_Char)0x6b,  /* [6875] */
    (xdc_Char)0x2e,  /* [6876] */
    (xdc_Char)0x49,  /* [6877] */
    (xdc_Char)0x64,  /* [6878] */
    (xdc_Char)0x6c,  /* [6879] */
    (xdc_Char)0x65,  /* [6880] */
    (xdc_Char)0x54,  /* [6881] */
    (xdc_Char)0x61,  /* [6882] */
    (xdc_Char)0x73,  /* [6883] */
    (xdc_Char)0x6b,  /* [6884] */
    (xdc_Char)0x0,  /* [6885] */
};

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[52] = {
    {
        (xdc_Bits16)0x0,  /* left */
        (xdc_Bits16)0x0,  /* right */
    },  /* [0] */
    {
        (xdc_Bits16)0x1941,  /* left */
        (xdc_Bits16)0x1946,  /* right */
    },  /* [1] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x194f,  /* right */
    },  /* [2] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1956,  /* right */
    },  /* [3] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x195b,  /* right */
    },  /* [4] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1964,  /* right */
    },  /* [5] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x196a,  /* right */
    },  /* [6] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1970,  /* right */
    },  /* [7] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1975,  /* right */
    },  /* [8] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1979,  /* right */
    },  /* [9] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x197e,  /* right */
    },  /* [10] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1985,  /* right */
    },  /* [11] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x198e,  /* right */
    },  /* [12] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1996,  /* right */
    },  /* [13] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x199d,  /* right */
    },  /* [14] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x19a4,  /* right */
    },  /* [15] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x19a9,  /* right */
    },  /* [16] */
    {
        (xdc_Bits16)0x19b3,  /* left */
        (xdc_Bits16)0x19b7,  /* right */
    },  /* [17] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x19c0,  /* right */
    },  /* [18] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x19c8,  /* right */
    },  /* [19] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x19ce,  /* right */
    },  /* [20] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x19d8,  /* right */
    },  /* [21] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x19dc,  /* right */
    },  /* [22] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x19ee,  /* right */
    },  /* [23] */
    {
        (xdc_Bits16)0x8017,  /* left */
        (xdc_Bits16)0x19d8,  /* right */
    },  /* [24] */
    {
        (xdc_Bits16)0x8017,  /* left */
        (xdc_Bits16)0x19f3,  /* right */
    },  /* [25] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x19f9,  /* right */
    },  /* [26] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x19fe,  /* right */
    },  /* [27] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1a04,  /* right */
    },  /* [28] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1a09,  /* right */
    },  /* [29] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1a14,  /* right */
    },  /* [30] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1a1a,  /* right */
    },  /* [31] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1a24,  /* right */
    },  /* [32] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1a28,  /* right */
    },  /* [33] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1a2d,  /* right */
    },  /* [34] */
    {
        (xdc_Bits16)0x8022,  /* left */
        (xdc_Bits16)0x1a34,  /* right */
    },  /* [35] */
    {
        (xdc_Bits16)0x8022,  /* left */
        (xdc_Bits16)0x1a3c,  /* right */
    },  /* [36] */
    {
        (xdc_Bits16)0x19b3,  /* left */
        (xdc_Bits16)0x1a46,  /* right */
    },  /* [37] */
    {
        (xdc_Bits16)0x8025,  /* left */
        (xdc_Bits16)0x1a4b,  /* right */
    },  /* [38] */
    {
        (xdc_Bits16)0x8026,  /* left */
        (xdc_Bits16)0x1a52,  /* right */
    },  /* [39] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1a67,  /* right */
    },  /* [40] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1a6c,  /* right */
    },  /* [41] */
    {
        (xdc_Bits16)0x8029,  /* left */
        (xdc_Bits16)0x1a71,  /* right */
    },  /* [42] */
    {
        (xdc_Bits16)0x8029,  /* left */
        (xdc_Bits16)0x1a7d,  /* right */
    },  /* [43] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1a8f,  /* right */
    },  /* [44] */
    {
        (xdc_Bits16)0x802c,  /* left */
        (xdc_Bits16)0x1a97,  /* right */
    },  /* [45] */
    {
        (xdc_Bits16)0x802d,  /* left */
        (xdc_Bits16)0x19f3,  /* right */
    },  /* [46] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x1aa0,  /* right */
    },  /* [47] */
    {
        (xdc_Bits16)0x802f,  /* left */
        (xdc_Bits16)0x1aa7,  /* right */
    },  /* [48] */
    {
        (xdc_Bits16)0x802f,  /* left */
        (xdc_Bits16)0x1ab4,  /* right */
    },  /* [49] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1aba,  /* right */
    },  /* [50] */
    {
        (xdc_Bits16)0x8032,  /* left */
        (xdc_Bits16)0x1ac1,  /* right */
    },  /* [51] */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Text_Module__diagsEnabled xdc_runtime_Text_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Text_Module__diagsIncluded xdc_runtime_Text_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Text_Module__diagsMask xdc_runtime_Text_Module__diagsMask__C = ((CT__xdc_runtime_Text_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Text_Module__gateObj xdc_runtime_Text_Module__gateObj__C = ((CT__xdc_runtime_Text_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Text_Module__gatePrms xdc_runtime_Text_Module__gatePrms__C = ((CT__xdc_runtime_Text_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Text_Module__id xdc_runtime_Text_Module__id__C = (xdc_Bits16)0x800f;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerDefined xdc_runtime_Text_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerObj xdc_runtime_Text_Module__loggerObj__C = ((CT__xdc_runtime_Text_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn0 xdc_runtime_Text_Module__loggerFxn0__C = ((CT__xdc_runtime_Text_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn1 xdc_runtime_Text_Module__loggerFxn1__C = ((CT__xdc_runtime_Text_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn2 xdc_runtime_Text_Module__loggerFxn2__C = ((CT__xdc_runtime_Text_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn4 xdc_runtime_Text_Module__loggerFxn4__C = ((CT__xdc_runtime_Text_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn8 xdc_runtime_Text_Module__loggerFxn8__C = ((CT__xdc_runtime_Text_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Text_Module__startupDoneFxn xdc_runtime_Text_Module__startupDoneFxn__C = ((CT__xdc_runtime_Text_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Text_Object__count xdc_runtime_Text_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Text_Object__heap xdc_runtime_Text_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Text_Object__sizeof xdc_runtime_Text_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Text_Object__table xdc_runtime_Text_Object__table__C = 0;

/* nameUnknown__C */
__FAR__ const CT__xdc_runtime_Text_nameUnknown xdc_runtime_Text_nameUnknown__C = "{unknown-instance-name}";

/* nameEmpty__C */
__FAR__ const CT__xdc_runtime_Text_nameEmpty xdc_runtime_Text_nameEmpty__C = "{empty-instance-name}";

/* nameStatic__C */
__FAR__ const CT__xdc_runtime_Text_nameStatic xdc_runtime_Text_nameStatic__C = "{static-instance-name}";

/* isLoaded__C */
__FAR__ const CT__xdc_runtime_Text_isLoaded xdc_runtime_Text_isLoaded__C = 1;

/* charTab__C */
__FAR__ const CT__xdc_runtime_Text_charTab xdc_runtime_Text_charTab__C = ((CT__xdc_runtime_Text_charTab)xdc_runtime_Text_charTab__A);

/* nodeTab__C */
__FAR__ const CT__xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__C = ((CT__xdc_runtime_Text_nodeTab)xdc_runtime_Text_nodeTab__A);

/* charCnt__C */
__FAR__ const CT__xdc_runtime_Text_charCnt xdc_runtime_Text_charCnt__C = (xdc_Int16)0x1ae6;

/* nodeCnt__C */
__FAR__ const CT__xdc_runtime_Text_nodeCnt xdc_runtime_Text_nodeCnt__C = (xdc_Int16)0x34;

/* unnamedModsLastId__C */
__FAR__ const CT__xdc_runtime_Text_unnamedModsLastId xdc_runtime_Text_unnamedModsLastId__C = (xdc_UInt16)0x4000;

/* registryModsLastId__C */
__FAR__ const CT__xdc_runtime_Text_registryModsLastId xdc_runtime_Text_registryModsLastId__C = (xdc_UInt16)0x7fff;

/* visitRopeFxn__C */
__FAR__ const CT__xdc_runtime_Text_visitRopeFxn xdc_runtime_Text_visitRopeFxn__C = ((CT__xdc_runtime_Text_visitRopeFxn)((xdc_Fxn)xdc_runtime_Text_visitRope__I));

/* visitRopeFxn2__C */
__FAR__ const CT__xdc_runtime_Text_visitRopeFxn2 xdc_runtime_Text_visitRopeFxn2__C = ((CT__xdc_runtime_Text_visitRopeFxn2)((xdc_Fxn)xdc_runtime_Text_visitRope2__I));


/*
 * ======== xdc.runtime.Timestamp INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsEnabled xdc_runtime_Timestamp_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsIncluded xdc_runtime_Timestamp_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__diagsMask xdc_runtime_Timestamp_Module__diagsMask__C = ((CT__xdc_runtime_Timestamp_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__gateObj xdc_runtime_Timestamp_Module__gateObj__C = ((CT__xdc_runtime_Timestamp_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__gatePrms xdc_runtime_Timestamp_Module__gatePrms__C = ((CT__xdc_runtime_Timestamp_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__id xdc_runtime_Timestamp_Module__id__C = (xdc_Bits16)0x8010;

/* Module__loggerDefined__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerDefined xdc_runtime_Timestamp_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerObj xdc_runtime_Timestamp_Module__loggerObj__C = ((CT__xdc_runtime_Timestamp_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn0 xdc_runtime_Timestamp_Module__loggerFxn0__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn1 xdc_runtime_Timestamp_Module__loggerFxn1__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn2 xdc_runtime_Timestamp_Module__loggerFxn2__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn4 xdc_runtime_Timestamp_Module__loggerFxn4__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__loggerFxn8 xdc_runtime_Timestamp_Module__loggerFxn8__C = ((CT__xdc_runtime_Timestamp_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__xdc_runtime_Timestamp_Module__startupDoneFxn xdc_runtime_Timestamp_Module__startupDoneFxn__C = ((CT__xdc_runtime_Timestamp_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__xdc_runtime_Timestamp_Object__count xdc_runtime_Timestamp_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__xdc_runtime_Timestamp_Object__heap xdc_runtime_Timestamp_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__xdc_runtime_Timestamp_Object__sizeof xdc_runtime_Timestamp_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__xdc_runtime_Timestamp_Object__table xdc_runtime_Timestamp_Object__table__C = 0;


/*
 * ======== xdc.runtime.Timestamp_SupportProxy INITIALIZERS ========
 */


/*
 * ======== ti.sdo.utils.NameServerRemoteNull FUNCTION STUBS ========
 */

/* get__E */
xdc_Int ti_sdo_utils_NameServerRemoteNull_get__E( ti_sdo_utils_NameServerRemoteNull_Handle __inst, xdc_String instanceName, xdc_String name, xdc_Ptr value, xdc_UInt32* valueLen, xdc_runtime_knl_ISync_Handle syncHandle, xdc_runtime_Error_Block* eb ) 
{
    return ti_sdo_utils_NameServerRemoteNull_get__F((void*)__inst, instanceName, name, value, valueLen, syncHandle, eb);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_Exception_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_Exception_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_Hwi_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_Hwi_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_TimestampProvider_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_TimestampProvider_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_tesla_TimerSupport_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_tesla_TimerSupport_Module_startup__F(state);
}


/*
 * ======== ti.sysbios.family.c64p.tesla.Wugen FUNCTION STUBS ========
 */

/* applyMasks__E */
xdc_Void ti_sysbios_family_c64p_tesla_Wugen_applyMasks__E( xdc_UInt32 mask[] ) 
{
    ti_sysbios_family_c64p_tesla_Wugen_applyMasks__F(mask);
}

/* disableDma__E */
xdc_Void ti_sysbios_family_c64p_tesla_Wugen_disableDma__E( xdc_UInt dmaid ) 
{
    ti_sysbios_family_c64p_tesla_Wugen_disableDma__F(dmaid);
}

/* disableEvent__E */
xdc_Void ti_sysbios_family_c64p_tesla_Wugen_disableEvent__E( xdc_UInt eventid ) 
{
    ti_sysbios_family_c64p_tesla_Wugen_disableEvent__F(eventid);
}

/* enableDma__E */
xdc_Void ti_sysbios_family_c64p_tesla_Wugen_enableDma__E( xdc_UInt dmaid ) 
{
    ti_sysbios_family_c64p_tesla_Wugen_enableDma__F(dmaid);
}

/* enableEvent__E */
xdc_Void ti_sysbios_family_c64p_tesla_Wugen_enableEvent__E( xdc_UInt eventid ) 
{
    ti_sysbios_family_c64p_tesla_Wugen_enableEvent__F(eventid);
}

/* getMasks__E */
xdc_Void ti_sysbios_family_c64p_tesla_Wugen_getMasks__E( xdc_UInt32 mask[] ) 
{
    ti_sysbios_family_c64p_tesla_Wugen_getMasks__F(mask);
}

/* ierToMasks__E */
xdc_Void ti_sysbios_family_c64p_tesla_Wugen_ierToMasks__E( xdc_UInt32 mask[] ) 
{
    ti_sysbios_family_c64p_tesla_Wugen_ierToMasks__F(mask);
}

/* Module_startup */
xdc_Int ti_sysbios_family_c64p_tesla_Wugen_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_c64p_tesla_Wugen_Module_startup__F(state);
}


/*
 * ======== ti.sysbios.gates.GateHwi FUNCTION STUBS ========
 */

/* query__E */
xdc_Bool ti_sysbios_gates_GateHwi_query__E( xdc_Int qual ) 
{
    return ti_sysbios_gates_GateHwi_query__F(qual);
}


/*
 * ======== ti.sysbios.gates.GateMutex FUNCTION STUBS ========
 */

/* query__E */
xdc_Bool ti_sysbios_gates_GateMutex_query__E( xdc_Int qual ) 
{
    return ti_sysbios_gates_GateMutex_query__F(qual);
}

/* Module_startup */
xdc_Int ti_sysbios_hal_Hwi_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_hal_Hwi_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_hal_Timer_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_hal_Timer_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_knl_Clock_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_knl_Clock_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_knl_Swi_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_knl_Swi_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_knl_Task_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_knl_Task_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_timers_dmtimer_Timer_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_timers_dmtimer_Timer_Module_startup__F(state);
}


/*
 * ======== xdc.runtime.Diags FUNCTION STUBS ========
 */

/* setMask__E */
xdc_Void xdc_runtime_Diags_setMask__E( xdc_String control ) 
{
    xdc_runtime_Diags_setMask__F(control);
}


/*
 * ======== xdc.runtime.Error FUNCTION STUBS ========
 */

/* check__E */
xdc_Bool xdc_runtime_Error_check__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_check__F(eb);
}

/* getData__E */
xdc_runtime_Error_Data* xdc_runtime_Error_getData__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getData__F(eb);
}

/* getCode__E */
xdc_UInt16 xdc_runtime_Error_getCode__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getCode__F(eb);
}

/* getId__E */
xdc_runtime_Error_Id xdc_runtime_Error_getId__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getId__F(eb);
}

/* getMsg__E */
xdc_String xdc_runtime_Error_getMsg__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getMsg__F(eb);
}

/* getSite__E */
xdc_runtime_Types_Site* xdc_runtime_Error_getSite__E( xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Error_getSite__F(eb);
}

/* init__E */
xdc_Void xdc_runtime_Error_init__E( xdc_runtime_Error_Block* eb ) 
{
    xdc_runtime_Error_init__F(eb);
}

/* print__E */
xdc_Void xdc_runtime_Error_print__E( xdc_runtime_Error_Block* eb ) 
{
    xdc_runtime_Error_print__F(eb);
}

/* raiseX__E */
xdc_Void xdc_runtime_Error_raiseX__E( xdc_runtime_Error_Block* eb, xdc_runtime_Types_ModuleId mod, xdc_String file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 ) 
{
    xdc_runtime_Error_raiseX__F(eb, mod, file, line, id, arg1, arg2);
}


/*
 * ======== xdc.runtime.Gate FUNCTION STUBS ========
 */

/* enterSystem__E */
xdc_IArg xdc_runtime_Gate_enterSystem__E( void ) 
{
    return xdc_runtime_Gate_enterSystem__F();
}

/* leaveSystem__E */
xdc_Void xdc_runtime_Gate_leaveSystem__E( xdc_IArg key ) 
{
    xdc_runtime_Gate_leaveSystem__F(key);
}


/*
 * ======== xdc.runtime.Log FUNCTION STUBS ========
 */

/* doPrint__E */
xdc_Void xdc_runtime_Log_doPrint__E( xdc_runtime_Log_EventRec* evRec ) 
{
    xdc_runtime_Log_doPrint__F(evRec);
}


/*
 * ======== xdc.runtime.Memory FUNCTION STUBS ========
 */

/* alloc__E */
xdc_Ptr xdc_runtime_Memory_alloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Memory_alloc__F(heap, size, align, eb);
}

/* calloc__E */
xdc_Ptr xdc_runtime_Memory_calloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Memory_calloc__F(heap, size, align, eb);
}

/* free__E */
xdc_Void xdc_runtime_Memory_free__E( xdc_runtime_IHeap_Handle heap, xdc_Ptr block, xdc_SizeT size ) 
{
    xdc_runtime_Memory_free__F(heap, block, size);
}

/* getStats__E */
xdc_Void xdc_runtime_Memory_getStats__E( xdc_runtime_IHeap_Handle heap, xdc_runtime_Memory_Stats* stats ) 
{
    xdc_runtime_Memory_getStats__F(heap, stats);
}

/* query__E */
xdc_Bool xdc_runtime_Memory_query__E( xdc_runtime_IHeap_Handle heap, xdc_Int qual ) 
{
    return xdc_runtime_Memory_query__F(heap, qual);
}

/* getMaxDefaultTypeAlign__E */
xdc_SizeT xdc_runtime_Memory_getMaxDefaultTypeAlign__E( void ) 
{
    return xdc_runtime_Memory_getMaxDefaultTypeAlign__F();
}

/* valloc__E */
xdc_Ptr xdc_runtime_Memory_valloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_Char value, xdc_runtime_Error_Block* eb ) 
{
    return xdc_runtime_Memory_valloc__F(heap, size, align, value, eb);
}


/*
 * ======== xdc.runtime.Registry FUNCTION STUBS ========
 */

/* addModule__E */
xdc_runtime_Registry_Result xdc_runtime_Registry_addModule__E( xdc_runtime_Registry_Desc* desc, xdc_String modName ) 
{
    return xdc_runtime_Registry_addModule__F(desc, modName);
}

/* findByName__E */
xdc_runtime_Registry_Desc* xdc_runtime_Registry_findByName__E( xdc_String modName ) 
{
    return xdc_runtime_Registry_findByName__F(modName);
}

/* findByNamePattern__E */
xdc_runtime_Registry_Desc* xdc_runtime_Registry_findByNamePattern__E( xdc_String namePat, xdc_Int len, xdc_runtime_Registry_Desc* prev ) 
{
    return xdc_runtime_Registry_findByNamePattern__F(namePat, len, prev);
}

/* findById__E */
xdc_runtime_Registry_Desc* xdc_runtime_Registry_findById__E( xdc_runtime_Types_ModuleId mid ) 
{
    return xdc_runtime_Registry_findById__F(mid);
}

/* getMask__E */
xdc_Bool xdc_runtime_Registry_getMask__E( xdc_String name, xdc_runtime_Types_DiagsMask* mask ) 
{
    return xdc_runtime_Registry_getMask__F(name, mask);
}

/* isMember__E */
xdc_Bool xdc_runtime_Registry_isMember__E( xdc_runtime_Types_ModuleId mid ) 
{
    return xdc_runtime_Registry_isMember__F(mid);
}

/* getNextModule__E */
xdc_runtime_Registry_Desc* xdc_runtime_Registry_getNextModule__E( xdc_runtime_Registry_Desc* desc ) 
{
    return xdc_runtime_Registry_getNextModule__F(desc);
}

/* getModuleName__E */
xdc_String xdc_runtime_Registry_getModuleName__E( xdc_runtime_Registry_Desc* desc ) 
{
    return xdc_runtime_Registry_getModuleName__F(desc);
}

/* getModuleId__E */
xdc_runtime_Types_ModuleId xdc_runtime_Registry_getModuleId__E( xdc_runtime_Registry_Desc* desc ) 
{
    return xdc_runtime_Registry_getModuleId__F(desc);
}


/*
 * ======== xdc.runtime.Startup FUNCTION STUBS ========
 */

/* exec__E */
xdc_Void xdc_runtime_Startup_exec__E( void ) 
{
    xdc_runtime_Startup_exec__F();
}

/* rtsDone__E */
xdc_Bool xdc_runtime_Startup_rtsDone__E( void ) 
{
    return xdc_runtime_Startup_rtsDone__F();
}


/*
 * ======== xdc.runtime.SysMin FUNCTION STUBS ========
 */

/* abort__E */
xdc_Void xdc_runtime_SysMin_abort__E( xdc_String str ) 
{
    xdc_runtime_SysMin_abort__F(str);
}

/* exit__E */
xdc_Void xdc_runtime_SysMin_exit__E( xdc_Int stat ) 
{
    xdc_runtime_SysMin_exit__F(stat);
}

/* flush__E */
xdc_Void xdc_runtime_SysMin_flush__E( void ) 
{
    xdc_runtime_SysMin_flush__F();
}

/* putch__E */
xdc_Void xdc_runtime_SysMin_putch__E( xdc_Char ch ) 
{
    xdc_runtime_SysMin_putch__F(ch);
}

/* ready__E */
xdc_Bool xdc_runtime_SysMin_ready__E( void ) 
{
    return xdc_runtime_SysMin_ready__F();
}

/* Module_startup */
xdc_Int xdc_runtime_SysMin_Module_startup__E( xdc_Int state )
{
    return xdc_runtime_SysMin_Module_startup__F(state);
}


/*
 * ======== xdc.runtime.System FUNCTION STUBS ========
 */

/* abort__E */
xdc_Void xdc_runtime_System_abort__E( xdc_String str ) 
{
    xdc_runtime_System_abort__F(str);
}

/* atexit__E */
xdc_Bool xdc_runtime_System_atexit__E( xdc_runtime_System_AtexitHandler handler ) 
{
    return xdc_runtime_System_atexit__F(handler);
}

/* exit__E */
xdc_Void xdc_runtime_System_exit__E( xdc_Int stat ) 
{
    xdc_runtime_System_exit__F(stat);
}

/* putch__E */
xdc_Void xdc_runtime_System_putch__E( xdc_Char ch ) 
{
    xdc_runtime_System_putch__F(ch);
}

/* flush__E */
xdc_Void xdc_runtime_System_flush__E( void ) 
{
    xdc_runtime_System_flush__F();
}

/* printf_va__E */
xdc_Int xdc_runtime_System_printf_va__E( xdc_String fmt, va_list __va ) 
{
    return xdc_runtime_System_printf_va__F(fmt, __va);
}

/* printf__E */
xdc_Int xdc_runtime_System_printf__E( xdc_String fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_printf_va__F(fmt, __va);

    va_end(__va);
    return __ret;
}

/* aprintf_va__E */
xdc_Int xdc_runtime_System_aprintf_va__E( xdc_String fmt, va_list __va ) 
{
    return xdc_runtime_System_aprintf_va__F(fmt, __va);
}

/* aprintf__E */
xdc_Int xdc_runtime_System_aprintf__E( xdc_String fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_aprintf_va__F(fmt, __va);

    va_end(__va);
    return __ret;
}

/* sprintf_va__E */
xdc_Int xdc_runtime_System_sprintf_va__E( xdc_Char buf[], xdc_String fmt, va_list __va ) 
{
    return xdc_runtime_System_sprintf_va__F(buf, fmt, __va);
}

/* sprintf__E */
xdc_Int xdc_runtime_System_sprintf__E( xdc_Char buf[], xdc_String fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_sprintf_va__F(buf, fmt, __va);

    va_end(__va);
    return __ret;
}

/* asprintf_va__E */
xdc_Int xdc_runtime_System_asprintf_va__E( xdc_Char buf[], xdc_String fmt, va_list __va ) 
{
    return xdc_runtime_System_asprintf_va__F(buf, fmt, __va);
}

/* asprintf__E */
xdc_Int xdc_runtime_System_asprintf__E( xdc_Char buf[], xdc_String fmt, ... ) 
{
    xdc_Int __ret;

    va_list __va; va_start(__va, fmt);
    __ret = xdc_runtime_System_asprintf_va__F(buf, fmt, __va);

    va_end(__va);
    return __ret;
}

/* vprintf__E */
xdc_Int xdc_runtime_System_vprintf__E( xdc_String fmt, xdc_VaList va ) 
{
    return xdc_runtime_System_vprintf__F(fmt, va);
}

/* avprintf__E */
xdc_Int xdc_runtime_System_avprintf__E( xdc_String fmt, xdc_VaList va ) 
{
    return xdc_runtime_System_avprintf__F(fmt, va);
}

/* vsprintf__E */
xdc_Int xdc_runtime_System_vsprintf__E( xdc_Char buf[], xdc_String fmt, xdc_VaList va ) 
{
    return xdc_runtime_System_vsprintf__F(buf, fmt, va);
}

/* avsprintf__E */
xdc_Int xdc_runtime_System_avsprintf__E( xdc_Char buf[], xdc_String fmt, xdc_VaList va ) 
{
    return xdc_runtime_System_avsprintf__F(buf, fmt, va);
}

/* Module_startup */
xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state )
{
    return xdc_runtime_System_Module_startup__F(state);
}


/*
 * ======== xdc.runtime.Text FUNCTION STUBS ========
 */

/* cordText__E */
xdc_String xdc_runtime_Text_cordText__E( xdc_runtime_Text_CordAddr cord ) 
{
    return xdc_runtime_Text_cordText__F(cord);
}

/* ropeText__E */
xdc_String xdc_runtime_Text_ropeText__E( xdc_runtime_Text_RopeId rope ) 
{
    return xdc_runtime_Text_ropeText__F(rope);
}

/* matchRope__E */
xdc_Int xdc_runtime_Text_matchRope__E( xdc_runtime_Text_RopeId rope, xdc_String pat, xdc_Int* lenp ) 
{
    return xdc_runtime_Text_matchRope__F(rope, pat, lenp);
}

/* putLab__E */
xdc_Int xdc_runtime_Text_putLab__E( xdc_runtime_Types_Label* lab, xdc_Char** bufp, xdc_Int len ) 
{
    return xdc_runtime_Text_putLab__F(lab, bufp, len);
}

/* putMod__E */
xdc_Int xdc_runtime_Text_putMod__E( xdc_runtime_Types_ModuleId mid, xdc_Char** bufp, xdc_Int len ) 
{
    return xdc_runtime_Text_putMod__F(mid, bufp, len);
}

/* putSite__E */
xdc_Int xdc_runtime_Text_putSite__E( xdc_runtime_Types_Site* site, xdc_Char** bufp, xdc_Int len ) 
{
    return xdc_runtime_Text_putSite__F(site, bufp, len);
}


/*
 * ======== xdc.runtime.Timestamp FUNCTION STUBS ========
 */

/* get32__E */
xdc_Bits32 xdc_runtime_Timestamp_get32__E( void ) 
{
    return xdc_runtime_Timestamp_get32__F();
}

/* get64__E */
xdc_Void xdc_runtime_Timestamp_get64__E( xdc_runtime_Types_Timestamp64* result ) 
{
    xdc_runtime_Timestamp_get64__F(result);
}

/* getFreq__E */
xdc_Void xdc_runtime_Timestamp_getFreq__E( xdc_runtime_Types_FreqHz* freq ) 
{
    xdc_runtime_Timestamp_getFreq__F(freq);
}


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateMutex */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateMutex_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_BIOS_RtsGateProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_BIOS_RtsGateProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_gates_GateMutex_Object__create__S(oa, osz, aa, (ti_sysbios_gates_GateMutex___ParamsPtr)pa, sizeof(xdc_runtime_IGateProvider_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_BIOS_RtsGateProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_BIOS_RtsGateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateMutex_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_BIOS_RtsGateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_gates_GateMutex_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateMutex_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_BIOS_RtsGateProxy_enter__E( ti_sysbios_BIOS_RtsGateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateMutex_enter((ti_sysbios_gates_GateMutex_Handle)__inst);
}

/* leave__E */
xdc_Void ti_sysbios_BIOS_RtsGateProxy_leave__E( ti_sysbios_BIOS_RtsGateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateMutex_leave((ti_sysbios_gates_GateMutex_Handle)__inst, key);
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c64p.Hwi */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_Hwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_hal_Hwi_HwiProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_family_c64p_Hwi_Object__create__S(oa, osz, aa, (ti_sysbios_family_c64p_Hwi___ParamsPtr)pa, sizeof(ti_sysbios_interfaces_IHwi_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_family_c64p_Hwi_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Hwi_HwiProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_c64p_Hwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_family_c64p_Hwi_Handle__label__S(obj, lab);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_startup__E( void )
{
    ti_sysbios_family_c64p_Hwi_startup();
}

/* disable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disable__E( void )
{
    return ti_sysbios_family_c64p_Hwi_disable();
}

/* enable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enable__E( void )
{
    return ti_sysbios_family_c64p_Hwi_enable();
}

/* restore__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restore__E( xdc_UInt key )
{
    ti_sysbios_family_c64p_Hwi_restore(key);
}

/* switchFromBootStack__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E( void )
{
    ti_sysbios_family_c64p_Hwi_switchFromBootStack();
}

/* post__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_post__E( xdc_UInt intNum )
{
    ti_sysbios_family_c64p_Hwi_post(intNum);
}

/* getTaskSP__E */
xdc_Char* ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E( void )
{
    return ti_sysbios_family_c64p_Hwi_getTaskSP();
}

/* disableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_c64p_Hwi_disableInterrupt(intNum);
}

/* enableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_c64p_Hwi_enableInterrupt(intNum);
}

/* restoreInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key )
{
    ti_sysbios_family_c64p_Hwi_restoreInterrupt(intNum, key);
}

/* clearInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E( xdc_UInt intNum )
{
    ti_sysbios_family_c64p_Hwi_clearInterrupt(intNum);
}

/* getFunc__E */
ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_getFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_UArg* arg )
{
    return ti_sysbios_family_c64p_Hwi_getFunc((ti_sysbios_family_c64p_Hwi_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_c64p_Hwi_setFunc((ti_sysbios_family_c64p_Hwi_Handle)__inst, fxn, arg);
}

/* getHookContext__E */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id )
{
    return ti_sysbios_family_c64p_Hwi_getHookContext((ti_sysbios_family_c64p_Hwi_Handle)__inst, id);
}

/* setHookContext__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id, xdc_Ptr hookContext )
{
    ti_sysbios_family_c64p_Hwi_setHookContext((ti_sysbios_family_c64p_Hwi_Handle)__inst, id, hookContext);
}

/* getIrp__E */
ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_HwiProxy_getIrp__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst )
{
    return ti_sysbios_family_c64p_Hwi_getIrp((ti_sysbios_family_c64p_Hwi_Handle)__inst);
}


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.timers.dmtimer.Timer */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Timer_TimerProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_timers_dmtimer_Timer_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Timer_TimerProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_hal_Timer_TimerProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_timers_dmtimer_Timer_Object__create__S(oa, osz, aa, (ti_sysbios_timers_dmtimer_Timer___ParamsPtr)pa, sizeof(ti_sysbios_interfaces_ITimer_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_hal_Timer_TimerProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_timers_dmtimer_Timer_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Timer_TimerProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_timers_dmtimer_Timer_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Timer_TimerProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_timers_dmtimer_Timer_Handle__label__S(obj, lab);
}

/* getNumTimers__E */
xdc_UInt ti_sysbios_hal_Timer_TimerProxy_getNumTimers__E( void )
{
    return ti_sysbios_timers_dmtimer_Timer_getNumTimers();
}

/* getStatus__E */
ti_sysbios_interfaces_ITimer_Status ti_sysbios_hal_Timer_TimerProxy_getStatus__E( xdc_UInt id )
{
    return ti_sysbios_timers_dmtimer_Timer_getStatus(id);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_startup__E( void )
{
    ti_sysbios_timers_dmtimer_Timer_startup();
}

/* getMaxTicks__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getMaxTicks__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 periodCounts )
{
    return ti_sysbios_timers_dmtimer_Timer_getMaxTicks((ti_sysbios_timers_dmtimer_Timer_Handle)__inst, periodCounts);
}

/* setNextTick__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setNextTick__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 newPeriod, xdc_UInt32 countsPerTick )
{
    ti_sysbios_timers_dmtimer_Timer_setNextTick((ti_sysbios_timers_dmtimer_Timer_Handle)__inst, newPeriod, countsPerTick);
}

/* start__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_start__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    ti_sysbios_timers_dmtimer_Timer_start((ti_sysbios_timers_dmtimer_Timer_Handle)__inst);
}

/* stop__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_stop__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    ti_sysbios_timers_dmtimer_Timer_stop((ti_sysbios_timers_dmtimer_Timer_Handle)__inst);
}

/* setPeriod__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setPeriod__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 period )
{
    ti_sysbios_timers_dmtimer_Timer_setPeriod((ti_sysbios_timers_dmtimer_Timer_Handle)__inst, period);
}

/* setPeriodMicroSecs__E */
xdc_Bool ti_sysbios_hal_Timer_TimerProxy_setPeriodMicroSecs__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 microsecs )
{
    return ti_sysbios_timers_dmtimer_Timer_setPeriodMicroSecs((ti_sysbios_timers_dmtimer_Timer_Handle)__inst, microsecs);
}

/* getPeriod__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getPeriod__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_timers_dmtimer_Timer_getPeriod((ti_sysbios_timers_dmtimer_Timer_Handle)__inst);
}

/* getCount__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getCount__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_timers_dmtimer_Timer_getCount((ti_sysbios_timers_dmtimer_Timer_Handle)__inst);
}

/* getFreq__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_getFreq__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_runtime_Types_FreqHz* freq )
{
    ti_sysbios_timers_dmtimer_Timer_getFreq((ti_sysbios_timers_dmtimer_Timer_Handle)__inst, freq);
}

/* getFunc__E */
ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_hal_Timer_TimerProxy_getFunc__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UArg* arg )
{
    return ti_sysbios_timers_dmtimer_Timer_getFunc((ti_sysbios_timers_dmtimer_Timer_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setFunc__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_timers_dmtimer_Timer_setFunc((ti_sysbios_timers_dmtimer_Timer_Handle)__inst, fxn, arg);
}

/* trigger__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_trigger__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 cycles )
{
    ti_sysbios_timers_dmtimer_Timer_trigger((ti_sysbios_timers_dmtimer_Timer_Handle)__inst, cycles);
}

/* getExpiredCounts__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getExpiredCounts__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_timers_dmtimer_Timer_getExpiredCounts((ti_sysbios_timers_dmtimer_Timer_Handle)__inst);
}


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateMutex */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateMutex_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_heaps_HeapMem_Module_GateProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_gates_GateMutex_Object__create__S(oa, osz, aa, (ti_sysbios_gates_GateMutex___ParamsPtr)pa, sizeof(xdc_runtime_IGateProvider_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateMutex_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_gates_GateMutex_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateMutex_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_heaps_HeapMem_Module_GateProxy_enter__E( ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateMutex_enter((ti_sysbios_gates_GateMutex_Handle)__inst);
}

/* leave__E */
xdc_Void ti_sysbios_heaps_HeapMem_Module_GateProxy_leave__E( ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateMutex_leave((ti_sysbios_gates_GateMutex_Handle)__inst, key);
}


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c62.IntrinsicsSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDone__S();
}

/* maxbit__E */
xdc_UInt ti_sysbios_knl_Intrinsics_SupportProxy_maxbit__E( xdc_UInt bits )
{
    return ti_sysbios_family_c62_IntrinsicsSupport_maxbit(bits);
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c62.TaskSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c62_TaskSupport_Module__startupDone__S();
}

/* start__E */
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_start__E( xdc_Ptr curTask, ti_sysbios_interfaces_ITaskSupport_FuncPtr enter, ti_sysbios_interfaces_ITaskSupport_FuncPtr exit, xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_family_c62_TaskSupport_start(curTask, enter, exit, eb);
}

/* swap__E */
xdc_Void ti_sysbios_knl_Task_SupportProxy_swap__E( xdc_Ptr* oldtskContext, xdc_Ptr* newtskContext )
{
    ti_sysbios_family_c62_TaskSupport_swap(oldtskContext, newtskContext);
}

/* checkStack__E */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_checkStack__E( xdc_Char* stack, xdc_SizeT size )
{
    return ti_sysbios_family_c62_TaskSupport_checkStack(stack, size);
}

/* stackUsed__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_stackUsed__E( xdc_Char* stack, xdc_SizeT size )
{
    return ti_sysbios_family_c62_TaskSupport_stackUsed(stack, size);
}

/* getStackAlignment__E */
xdc_UInt ti_sysbios_knl_Task_SupportProxy_getStackAlignment__E( void )
{
    return ti_sysbios_family_c62_TaskSupport_getStackAlignment();
}

/* getDefaultStackSize__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_getDefaultStackSize__E( void )
{
    return ti_sysbios_family_c62_TaskSupport_getDefaultStackSize();
}


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c64p.tesla.TimerSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_timers_dmtimer_Timer_TimerSupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDone__S();
}

/* enable__E */
xdc_Void ti_sysbios_timers_dmtimer_Timer_TimerSupportProxy_enable__E( xdc_UInt timerId, xdc_runtime_Error_Block* eb )
{
    ti_sysbios_family_c64p_tesla_TimerSupport_enable(timerId, eb);
}


/*
 * ======== xdc.runtime.Main_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Main_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const xdc_runtime_Main_Module_GateProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_gates_GateHwi_Object__create__S(oa, osz, aa, (ti_sysbios_gates_GateHwi___ParamsPtr)pa, sizeof(xdc_runtime_IGateProvider_Params), eb);
}

/* Object__delete__S */
void xdc_runtime_Main_Module_GateProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_Main_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* xdc_runtime_Main_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_Main_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E( xdc_runtime_Main_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)__inst);
}

/* leave__E */
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E( xdc_runtime_Main_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)__inst, key);
}


/*
 * ======== xdc.runtime.Memory_HeapProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.heaps.HeapMem */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Memory_HeapProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_heaps_HeapMem_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const xdc_runtime_Memory_HeapProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_heaps_HeapMem_Object__create__S(oa, osz, aa, (ti_sysbios_heaps_HeapMem___ParamsPtr)pa, sizeof(xdc_runtime_IHeap_Params), eb);
}

/* Object__delete__S */
void xdc_runtime_Memory_HeapProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_heaps_HeapMem_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_Memory_HeapProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_heaps_HeapMem_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* xdc_runtime_Memory_HeapProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_heaps_HeapMem_Handle__label__S(obj, lab);
}

/* alloc__E */
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block* eb )
{
    return xdc_runtime_IHeap_alloc((xdc_runtime_IHeap_Handle)__inst, size, align, eb);
}

/* free__E */
xdc_Void xdc_runtime_Memory_HeapProxy_free__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_Ptr block, xdc_SizeT size )
{
    xdc_runtime_IHeap_free((xdc_runtime_IHeap_Handle)__inst, block, size);
}

/* isBlocking__E */
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E( xdc_runtime_Memory_HeapProxy_Handle __inst )
{
    return xdc_runtime_IHeap_isBlocking((xdc_runtime_IHeap_Handle)__inst);
}

/* getStats__E */
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_runtime_Memory_Stats* stats )
{
    xdc_runtime_IHeap_getStats((xdc_runtime_IHeap_Handle)__inst, stats);
}


/*
 * ======== xdc.runtime.System_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_Module_GateProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* Object__create__S */
xdc_Ptr xdc_runtime_System_Module_GateProxy_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const xdc_runtime_System_Module_GateProxy___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_gates_GateHwi_Object__create__S(oa, osz, aa, (ti_sysbios_gates_GateHwi___ParamsPtr)pa, sizeof(xdc_runtime_IGateProvider_Params), eb);
}

/* Object__delete__S */
void xdc_runtime_System_Module_GateProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_System_Module_GateProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* xdc_runtime_System_Module_GateProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_System_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E( xdc_runtime_System_Module_GateProxy_Handle __inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)__inst);
}

/* leave__E */
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E( xdc_runtime_System_Module_GateProxy_Handle __inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)__inst, key);
}


/*
 * ======== xdc.runtime.System_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO xdc.runtime.SysMin */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_SupportProxy_Module__startupDone__S( void ) 
{
    return xdc_runtime_SysMin_Module__startupDone__S();
}

/* abort__E */
xdc_Void xdc_runtime_System_SupportProxy_abort__E( xdc_String str )
{
    xdc_runtime_SysMin_abort(str);
}

/* exit__E */
xdc_Void xdc_runtime_System_SupportProxy_exit__E( xdc_Int stat )
{
    xdc_runtime_SysMin_exit(stat);
}

/* flush__E */
xdc_Void xdc_runtime_System_SupportProxy_flush__E( void )
{
    xdc_runtime_SysMin_flush();
}

/* putch__E */
xdc_Void xdc_runtime_System_SupportProxy_putch__E( xdc_Char ch )
{
    xdc_runtime_SysMin_putch(ch);
}

/* ready__E */
xdc_Bool xdc_runtime_System_SupportProxy_ready__E( void )
{
    return xdc_runtime_SysMin_ready();
}


/*
 * ======== xdc.runtime.Timestamp_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c64p.TimestampProvider */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__S();
}

/* get32__E */
xdc_Bits32 xdc_runtime_Timestamp_SupportProxy_get32__E( void )
{
    return ti_sysbios_family_c64p_TimestampProvider_get32();
}

/* get64__E */
xdc_Void xdc_runtime_Timestamp_SupportProxy_get64__E( xdc_runtime_Types_Timestamp64* result )
{
    ti_sysbios_family_c64p_TimestampProvider_get64(result);
}

/* getFreq__E */
xdc_Void xdc_runtime_Timestamp_SupportProxy_getFreq__E( xdc_runtime_Types_FreqHz* freq )
{
    ti_sysbios_family_c64p_TimestampProvider_getFreq(freq);
}


/*
 * ======== ti.sdo.utils.NameServerRemoteNull OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sdo_utils_NameServerRemoteNull_Object2__ s0; char c; } ti_sdo_utils_NameServerRemoteNull___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sdo_utils_NameServerRemoteNull_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sdo_utils_NameServerRemoteNull_Module__root__V.link, /* modLink */
    sizeof(ti_sdo_utils_NameServerRemoteNull___S1) - sizeof(ti_sdo_utils_NameServerRemoteNull_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sdo_utils_NameServerRemoteNull_Object2__), /* objSize */
    (Ptr)&ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sdo_utils_NameServerRemoteNull_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.family.c64p.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_c64p_Hwi_Object2__ s0; char c; } ti_sysbios_family_c64p_Hwi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c64p_Hwi_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_family_c64p_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_c64p_Hwi___S1) - sizeof(ti_sysbios_family_c64p_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_c64p_Hwi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_family_c64p_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_c64p_Hwi_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.gates.GateHwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_gates_GateHwi_Object2__ s0; char c; } ti_sysbios_gates_GateHwi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateHwi_Object__DESC__C = {
    (Ptr)&ti_sysbios_gates_GateHwi_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_gates_GateHwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_gates_GateHwi___S1) - sizeof(ti_sysbios_gates_GateHwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_gates_GateHwi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_gates_GateHwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_gates_GateHwi_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.gates.GateMutex OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_gates_GateMutex_Object2__ s0; char c; } ti_sysbios_gates_GateMutex___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateMutex_Object__DESC__C = {
    (Ptr)&ti_sysbios_gates_GateMutex_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_gates_GateMutex_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_gates_GateMutex___S1) - sizeof(ti_sysbios_gates_GateMutex_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_gates_GateMutex_Object2__), /* objSize */
    (Ptr)&ti_sysbios_gates_GateMutex_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_gates_GateMutex_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.hal.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_hal_Hwi_Object2__ s0; char c; } ti_sysbios_hal_Hwi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Hwi_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_hal_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_hal_Hwi___S1) - sizeof(ti_sysbios_hal_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_hal_Hwi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_hal_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_hal_Hwi_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.hal.Timer OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_hal_Timer_Object2__ s0; char c; } ti_sysbios_hal_Timer___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Timer_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_hal_Timer_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_hal_Timer___S1) - sizeof(ti_sysbios_hal_Timer_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_hal_Timer_Object2__), /* objSize */
    (Ptr)&ti_sysbios_hal_Timer_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_hal_Timer_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.heaps.HeapMem OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_heaps_HeapMem_Object2__ s0; char c; } ti_sysbios_heaps_HeapMem___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_heaps_HeapMem_Object__DESC__C = {
    (Ptr)&ti_sysbios_heaps_HeapMem_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_heaps_HeapMem_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_heaps_HeapMem___S1) - sizeof(ti_sysbios_heaps_HeapMem_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_heaps_HeapMem_Object2__), /* objSize */
    (Ptr)&ti_sysbios_heaps_HeapMem_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_heaps_HeapMem_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Clock OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Clock_Object2__ s0; char c; } ti_sysbios_knl_Clock___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Clock_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Clock_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Clock___S1) - sizeof(ti_sysbios_knl_Clock_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Clock_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Clock_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Clock_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Queue OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Queue_Object2__ s0; char c; } ti_sysbios_knl_Queue___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Queue_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Queue_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Queue___S1) - sizeof(ti_sysbios_knl_Queue_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Queue_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Queue_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Queue_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Semaphore OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Semaphore_Object2__ s0; char c; } ti_sysbios_knl_Semaphore___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Semaphore_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Semaphore_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Semaphore___S1) - sizeof(ti_sysbios_knl_Semaphore_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Semaphore_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Semaphore_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Semaphore_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Swi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Swi_Object2__ s0; char c; } ti_sysbios_knl_Swi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Swi_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Swi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Swi___S1) - sizeof(ti_sysbios_knl_Swi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Swi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Swi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Swi_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.knl.Task OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Task_Object2__ s0; char c; } ti_sysbios_knl_Task___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Task_Object__DESC__C = {
    (Ptr)-1, /* fxnTab */
    &ti_sysbios_knl_Task_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Task___S1) - sizeof(ti_sysbios_knl_Task_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Task_Object2__), /* objSize */
    (Ptr)&ti_sysbios_knl_Task_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Task_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.timers.dmtimer.Timer OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_timers_dmtimer_Timer_Object2__ s0; char c; } ti_sysbios_timers_dmtimer_Timer___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_timers_dmtimer_Timer_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_timers_dmtimer_Timer_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_timers_dmtimer_Timer___S1) - sizeof(ti_sysbios_timers_dmtimer_Timer_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_timers_dmtimer_Timer_Object2__), /* objSize */
    (Ptr)&ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_timers_dmtimer_Timer_Params), /* prmsSize */
};



/*
 * ======== ti.sdo.utils.NameServerRemoteNull SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sdo_utils_NameServerRemoteNull_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sdo_utils_NameServerRemoteNull_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sdo_utils_NameServerRemoteNull_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sdo_utils_NameServerRemoteNull_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sdo_utils_NameServerRemoteNull_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sdo_utils_NameServerRemoteNull_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sdo_utils_NameServerRemoteNull_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sdo_utils_NameServerRemoteNull_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sdo_utils_NameServerRemoteNull_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sdo_utils_NameServerRemoteNull_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sdo_utils_NameServerRemoteNull_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sdo_utils_NameServerRemoteNull_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sdo_utils_NameServerRemoteNull_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sdo_utils_NameServerRemoteNull_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sdo_utils_NameServerRemoteNull_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32807;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sdo_utils_NameServerRemoteNull_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sdo_utils_NameServerRemoteNull_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sdo_utils_NameServerRemoteNull_Object__*)oa) + i;
    }

    if (ti_sdo_utils_NameServerRemoteNull_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sdo_utils_NameServerRemoteNull_Object__*)ti_sdo_utils_NameServerRemoteNull_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sdo_utils_NameServerRemoteNull_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sdo_utils_NameServerRemoteNull_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sdo_utils_NameServerRemoteNull_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sdo_utils_NameServerRemoteNull_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sdo_utils_NameServerRemoteNull_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sdo_utils_NameServerRemoteNull_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sdo_utils_NameServerRemoteNull___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sdo_utils_NameServerRemoteNull_Params prms;
    ti_sdo_utils_NameServerRemoteNull_Object* obj;

    ti_sdo_utils_NameServerRemoteNull_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sdo_utils_NameServerRemoteNull_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sdo_utils_NameServerRemoteNull_Instance_init__F(obj, args->procId, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sdo_utils_NameServerRemoteNull_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sdo_utils_NameServerRemoteNull_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sdo_utils_NameServerRemoteNull_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sdo_utils_NameServerRemoteNull_Object__DESC__C, *((ti_sdo_utils_NameServerRemoteNull_Object**)instp), NULL, -1, FALSE);
    *((ti_sdo_utils_NameServerRemoteNull_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.BIOS SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_BIOS_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.BIOS_RtsGateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_BIOS_RtsGateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_BIOS_RtsGateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_BIOS_RtsGateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_BIOS_RtsGateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_BIOS_RtsGateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_BIOS_RtsGateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_BIOS_RtsGateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_BIOS_RtsGateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_query
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_BIOS_RtsGateProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_gates_GateMutex_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.family.c62.IntrinsicsSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c62.TaskSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c62_TaskSupport_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c64p.Exception SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_Exception_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_Exception_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c64p.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_c64p_Hwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_c64p_Hwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_c64p_Hwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_c64p_Hwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_c64p_Hwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_c64p_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_c64p_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_c64p_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_c64p_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_c64p_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_Hwi_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_family_c64p_Hwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32789;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_family_c64p_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_family_c64p_Hwi_Object__*)oa) + i;
    }

    if (ti_sysbios_family_c64p_Hwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_family_c64p_Hwi_Object__*)ti_sysbios_family_c64p_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_c64p_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_c64p_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_c64p_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_c64p_Hwi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_family_c64p_Hwi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_family_c64p_Hwi_Params prms;
    ti_sysbios_family_c64p_Hwi_Object* obj;
    int iStat;

    ti_sysbios_family_c64p_Hwi_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_c64p_Hwi_Instance_init__F(obj, args->intNum, args->hwiFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_c64p_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c64p_Hwi_Object__DESC__C, *((ti_sysbios_family_c64p_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_family_c64p_Hwi_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_family_c64p_Hwi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.family.c64p.TimestampProvider SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_TimestampProvider_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c64p.tesla.TimerSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.c64p.tesla.Wugen SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c64p_tesla_Wugen_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_c64p_tesla_Wugen_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.gates.GateHwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_gates_GateHwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_gates_GateHwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_gates_GateHwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_gates_GateHwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_gates_GateHwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_gates_GateHwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_gates_GateHwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_gates_GateHwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_gates_GateHwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_gates_GateHwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_gates_GateHwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_gates_GateHwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_gates_GateHwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_gates_GateHwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_gates_GateHwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_gates_GateHwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_gates_GateHwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_gates_GateHwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_gates_GateHwi_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_gates_GateHwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32803;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_gates_GateHwi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_gates_GateHwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_gates_GateHwi_Object__*)oa) + i;
    }

    if (ti_sysbios_gates_GateHwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_gates_GateHwi_Object__*)ti_sysbios_gates_GateHwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_gates_GateHwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_gates_GateHwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_gates_GateHwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_gates_GateHwi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_gates_GateHwi_Params prms;
    ti_sysbios_gates_GateHwi_Object* obj;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateHwi_Instance_init__F(obj, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_gates_GateHwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_gates_GateHwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, *((ti_sysbios_gates_GateHwi_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_gates_GateHwi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.gates.GateMutex SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_gates_GateMutex_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_gates_GateMutex_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_gates_GateMutex_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_gates_GateMutex_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_gates_GateMutex_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_gates_GateMutex_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_gates_GateMutex_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_gates_GateMutex_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_gates_GateMutex_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_gates_GateMutex_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_gates_GateMutex_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_gates_GateMutex_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_gates_GateMutex_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_gates_GateMutex_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_gates_GateMutex_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_gates_GateMutex_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_gates_GateMutex_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_gates_GateMutex_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_gates_GateMutex_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_gates_GateMutex_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32804;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_gates_GateMutex_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_gates_GateMutex_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_gates_GateMutex_Object__*)oa) + i;
    }

    if (ti_sysbios_gates_GateMutex_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_gates_GateMutex_Object__*)ti_sysbios_gates_GateMutex_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_gates_GateMutex_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_gates_GateMutex_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_gates_GateMutex_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_gates_GateMutex___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_gates_GateMutex_Params prms;
    ti_sysbios_gates_GateMutex_Object* obj;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateMutex_Instance_init__F(obj, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_gates_GateMutex_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_gates_GateMutex_Instance_finalize__F, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_gates_GateMutex_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, *((ti_sysbios_gates_GateMutex_Object**)instp), (xdc_Fxn)ti_sysbios_gates_GateMutex_Instance_finalize__F, -1, FALSE);
    *((ti_sysbios_gates_GateMutex_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.hal.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Hwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Hwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Hwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Hwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Hwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Hwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Hwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Hwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__S( void ) 
{
    return ti_sysbios_hal_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Hwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32792;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_hal_Hwi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_hal_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_hal_Hwi_Object__*)oa) + i;
    }

    if (ti_sysbios_hal_Hwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_hal_Hwi_Object__*)ti_sysbios_hal_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_hal_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_hal_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_hal_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_hal_Hwi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_hal_Hwi_Params prms;
    ti_sysbios_hal_Hwi_Object* obj;
    int iStat;

    ti_sysbios_hal_Hwi_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_hal_Hwi_Instance_init__F(obj, args->intNum, args->hwiFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_hal_Hwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_hal_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, *((ti_sysbios_hal_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_hal_Hwi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Hwi_HwiProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Hwi_HwiProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Hwi_HwiProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Hwi_HwiProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Hwi_HwiProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Hwi_HwiProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Hwi_HwiProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Hwi_HwiProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_query
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S( void )
{
    return 0;
}



/*
 * ======== ti.sysbios.hal.Timer SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Timer_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Timer_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Timer_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Timer_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Timer_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Timer_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Timer_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Timer_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Timer_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Timer_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Timer_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Timer_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Timer_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Timer_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Timer_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Timer_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Timer_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Timer_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Timer_Module__startupDone__S( void ) 
{
    return ti_sysbios_hal_Timer_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Timer_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32793;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_hal_Timer_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_hal_Timer_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_hal_Timer_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_hal_Timer_Object__*)oa) + i;
    }

    if (ti_sysbios_hal_Timer_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_hal_Timer_Object__*)ti_sysbios_hal_Timer_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_hal_Timer_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_hal_Timer_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_hal_Timer_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_hal_Timer_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_hal_Timer_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Timer_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_hal_Timer___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_hal_Timer_Params prms;
    ti_sysbios_hal_Timer_Object* obj;
    int iStat;

    ti_sysbios_hal_Timer_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_Timer_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_hal_Timer_Instance_init__F(obj, args->id, args->tickFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Timer_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_hal_Timer_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Timer_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_hal_Timer_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Timer_Object__DESC__C, *((ti_sysbios_hal_Timer_Object**)instp), (xdc_Fxn)ti_sysbios_hal_Timer_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_hal_Timer_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Timer_TimerProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Timer_TimerProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Timer_TimerProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Timer_TimerProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Timer_TimerProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Timer_TimerProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Timer_TimerProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Timer_TimerProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Timer_TimerProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Timer_TimerProxy_Module_GateProxy_query
xdc_Bool ti_sysbios_hal_Timer_TimerProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_hal_Timer_TimerProxy_Proxy__delegate__S( void )
{
    return 0;
}



/*
 * ======== ti.sysbios.heaps.HeapMem SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_heaps_HeapMem_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_heaps_HeapMem_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_heaps_HeapMem_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_heaps_HeapMem_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_heaps_HeapMem_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_heaps_HeapMem_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_heaps_HeapMem_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_heaps_HeapMem_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_heaps_HeapMem_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_heaps_HeapMem_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_heaps_HeapMem_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_heaps_HeapMem_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_heaps_HeapMem_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32819;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_heaps_HeapMem_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_heaps_HeapMem_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_heaps_HeapMem_Object__*)oa) + i;
    }

    if (ti_sysbios_heaps_HeapMem_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_heaps_HeapMem_Object__*)ti_sysbios_heaps_HeapMem_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_heaps_HeapMem_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_heaps_HeapMem_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_heaps_HeapMem_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_heaps_HeapMem___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_heaps_HeapMem_Params prms;
    ti_sysbios_heaps_HeapMem_Object* obj;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_heaps_HeapMem_Instance_init__F(obj, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_heaps_HeapMem_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_heaps_HeapMem_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, *((ti_sysbios_heaps_HeapMem_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_heaps_HeapMem_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_query
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_heaps_HeapMem_Module_GateProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_gates_GateMutex_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.knl.Clock SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Clock_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Clock_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Clock_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Clock_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Clock_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Clock_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Clock_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Clock_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Clock_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Clock_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Clock_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Clock_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Clock_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Clock_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Clock_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Clock_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Clock_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Clock_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__S( void ) 
{
    return ti_sysbios_knl_Clock_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Clock_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32795;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Clock_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Clock_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Clock_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Clock_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Clock_Object__*)ti_sysbios_knl_Clock_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Clock_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Clock_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Clock_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Clock___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Clock_Params prms;
    ti_sysbios_knl_Clock_Object* obj;

    ti_sysbios_knl_Clock_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Clock_Instance_init__F(obj, args->clockFxn, args->timeout, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Clock_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Clock_Instance_finalize__F, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Clock_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, *((ti_sysbios_knl_Clock_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Clock_Instance_finalize__F, -1, FALSE);
    *((ti_sysbios_knl_Clock_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Idle SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Idle_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.knl.Intrinsics SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_knl_Intrinsics_SupportProxy_Proxy__delegate__S( void )
{
    return 0;
}


/*
 * ======== ti.sysbios.knl.Queue SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Queue_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Queue_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Queue_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Queue_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Queue_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Queue_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Queue_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Queue_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Queue_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Queue_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Queue_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Queue_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Queue_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Queue_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Queue_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Queue_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Queue_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Queue_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Queue_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Queue_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32798;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Queue_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Queue_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Queue_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Queue_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Queue_Object__*)ti_sysbios_knl_Queue_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Queue_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Queue_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Queue_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Queue___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Queue_Params prms;
    ti_sysbios_knl_Queue_Object* obj;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Queue_Instance_init__F(obj, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Queue_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Queue_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, *((ti_sysbios_knl_Queue_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_knl_Queue_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Semaphore SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Semaphore_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Semaphore_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Semaphore_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Semaphore_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Semaphore_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Semaphore_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Semaphore_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Semaphore_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Semaphore_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Semaphore_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Semaphore_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Semaphore_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Semaphore_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Semaphore_Module__startupDone__S( void ) 
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Semaphore_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32799;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Semaphore_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Semaphore_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Semaphore_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Semaphore_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Semaphore_Object__*)ti_sysbios_knl_Semaphore_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Semaphore_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Semaphore_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Semaphore_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Semaphore___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Semaphore_Params prms;
    ti_sysbios_knl_Semaphore_Object* obj;

    ti_sysbios_knl_Semaphore_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Semaphore_Instance_init__F(obj, args->count, &prms);
    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Semaphore_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Semaphore_Instance_finalize__F, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Semaphore_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, *((ti_sysbios_knl_Semaphore_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Semaphore_Instance_finalize__F, -1, FALSE);
    *((ti_sysbios_knl_Semaphore_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Swi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Swi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Swi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Swi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Swi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Swi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Swi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Swi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Swi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Swi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Swi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Swi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Swi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Swi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Swi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Swi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Swi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Swi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Swi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__S( void ) 
{
    return ti_sysbios_knl_Swi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Swi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32800;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Swi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Swi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Swi_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Swi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Swi_Object__*)ti_sysbios_knl_Swi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Swi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Swi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Swi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Swi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Swi_Params prms;
    ti_sysbios_knl_Swi_Object* obj;
    int iStat;

    ti_sysbios_knl_Swi_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Swi_Instance_init__F(obj, args->fxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Swi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Swi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, *((ti_sysbios_knl_Swi_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_knl_Swi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Task SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Task_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Task_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Task_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Task_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Task_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Task_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Task_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Task_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Task_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Task_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Task_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Task_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Task_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Task_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Task_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Task_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Task_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Task_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__S( void ) 
{
    return ti_sysbios_knl_Task_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_knl_Task_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32801;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Task_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_knl_Task_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Task_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_knl_Task_Object__*)oa) + i;
    }

    if (ti_sysbios_knl_Task_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_knl_Task_Object__*)ti_sysbios_knl_Task_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Task_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Task_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Task_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Task_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Task_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Task_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_knl_Task___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_knl_Task_Params prms;
    ti_sysbios_knl_Task_Object* obj;
    int iStat;

    ti_sysbios_knl_Task_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Task_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Task_Instance_init__F(obj, args->fxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_knl_Task_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Task_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, *((ti_sysbios_knl_Task_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_knl_Task_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool ti_sysbios_knl_Task_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_Proxy__delegate__S( void )
{
    return 0;
}


/*
 * ======== ti.sysbios.timers.dmtimer.Timer SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_timers_dmtimer_Timer_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_timers_dmtimer_Timer_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_timers_dmtimer_Timer_Module__startupDone__S( void ) 
{
    return ti_sysbios_timers_dmtimer_Timer_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_timers_dmtimer_Timer_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32814;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_timers_dmtimer_Timer_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_timers_dmtimer_Timer_Object__*)oa) + i;
    }

    if (ti_sysbios_timers_dmtimer_Timer_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_timers_dmtimer_Timer_Object__*)ti_sysbios_timers_dmtimer_Timer_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_timers_dmtimer_Timer_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_timers_dmtimer_Timer_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_timers_dmtimer_Timer_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_timers_dmtimer_Timer___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_timers_dmtimer_Timer_Params prms;
    ti_sysbios_timers_dmtimer_Timer_Object* obj;
    int iStat;

    ti_sysbios_timers_dmtimer_Timer_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_timers_dmtimer_Timer_Instance_init__F(obj, args->id, args->tickFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_timers_dmtimer_Timer_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_timers_dmtimer_Timer_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, *((ti_sysbios_timers_dmtimer_Timer_Object**)instp), (xdc_Fxn)ti_sysbios_timers_dmtimer_Timer_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_timers_dmtimer_Timer_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.timers.dmtimer.Timer_TimerSupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool ti_sysbios_timers_dmtimer_Timer_TimerSupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr ti_sysbios_timers_dmtimer_Timer_TimerSupportProxy_Proxy__delegate__S( void )
{
    return 0;
}


/*
 * ======== xdc.runtime.Assert SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Assert_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Core SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Core_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Defaults SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Defaults_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Diags SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Diags_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Error SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Error_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Gate SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Gate_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Log SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Log_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Main SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Main_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Main_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Main_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Main_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Main_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Main_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Main_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Main_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Main_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Main_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Main_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Main_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Main_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Main_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Main_Module_GateProxy_Module_GateProxy_query
xdc_Bool xdc_runtime_Main_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_Main_Module_GateProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.Memory SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Memory_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Memory_HeapProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Memory_HeapProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Memory_HeapProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Memory_HeapProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Memory_HeapProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Memory_HeapProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Memory_HeapProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Memory_HeapProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Memory_HeapProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Memory_HeapProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Memory_HeapProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Memory_HeapProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Memory_HeapProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Memory_HeapProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Memory_HeapProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Memory_HeapProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Memory_HeapProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Memory_HeapProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Memory_HeapProxy_Module_GateProxy_query
xdc_Bool xdc_runtime_Memory_HeapProxy_Proxy__abstract__S( void )
{
    return 1;
}
xdc_Ptr xdc_runtime_Memory_HeapProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_heaps_HeapMem_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.Registry SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Registry_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Startup SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Startup_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.SysMin SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_SysMin_Module__startupDone__S( void ) 
{
    return xdc_runtime_SysMin_Module__startupDone__F();
}



/*
 * ======== xdc.runtime.System SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_Module__startupDone__S( void ) 
{
    return xdc_runtime_System_Module__startupDone__F();
}



/*
 * ======== xdc.runtime.System_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_System_Module_GateProxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_System_Module_GateProxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_System_Module_GateProxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_System_Module_GateProxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_System_Module_GateProxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_System_Module_GateProxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_System_Module_GateProxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_System_Module_GateProxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_System_Module_GateProxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_System_Module_GateProxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_System_Module_GateProxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_System_Module_GateProxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_System_Module_GateProxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_System_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_System_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_System_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_System_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_System_Module_GateProxy_Module_GateProxy_query
xdc_Bool xdc_runtime_System_Module_GateProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_System_Module_GateProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.System_SupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool xdc_runtime_System_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_System_SupportProxy_Proxy__delegate__S( void )
{
    return (xdc_Ptr)&xdc_runtime_SysMin_Module__FXNS__C;
}


/*
 * ======== xdc.runtime.Text SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Text_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Timestamp SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Timestamp_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== xdc.runtime.Timestamp_SupportProxy SYSTEM FUNCTIONS ========
 */

xdc_Bool xdc_runtime_Timestamp_SupportProxy_Proxy__abstract__S( void )
{
    return 0;
}
xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S( void )
{
    return 0;
}


/*
 * ======== INITIALIZATION ENTRY POINT ========
 */

extern int __xdc__init(void);
#ifdef __GNUC__
#if __GNUC__ >= 4
    __attribute__ ((externally_visible))
#endif
#endif
__FAR__ int (* volatile __xdc__init__addr)(void) = &__xdc__init;


/*
 * ======== PROGRAM GLOBALS ========
 */


/*
 * ======== CONSTANTS ========
 */

#pragma DATA_SECTION(xdc_runtime_IModule_Interface__BASE__C, ".const:xdc_runtime_IModule_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_IGateProvider_Interface__BASE__C, ".const:xdc_runtime_IGateProvider_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_IHeap_Interface__BASE__C, ".const:xdc_runtime_IHeap_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_ISystemSupport_Interface__BASE__C, ".const:xdc_runtime_ISystemSupport_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_ITimestampClient_Interface__BASE__C, ".const:xdc_runtime_ITimestampClient_Interface__BASE__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__FXNS__C, ".const:ti_sysbios_gates_GateHwi_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__FXNS__C, ".const:ti_sysbios_gates_GateMutex_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__FXNS__C, ".const:ti_sysbios_heaps_HeapMem_Module__FXNS__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__FXNS__C, ".const:xdc_runtime_SysMin_Module__FXNS__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__FXNS__C, ".const:xdc_runtime_Timestamp_Module__FXNS__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C, ".const:ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__PARAMS__C, ".const:ti_sysbios_family_c64p_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__PARAMS__C, ".const:ti_sysbios_gates_GateHwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__PARAMS__C, ".const:ti_sysbios_gates_GateMutex_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__PARAMS__C, ".const:ti_sysbios_hal_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__PARAMS__C, ".const:ti_sysbios_hal_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__PARAMS__C, ".const:ti_sysbios_heaps_HeapMem_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__PARAMS__C, ".const:ti_sysbios_knl_Clock_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__PARAMS__C, ".const:ti_sysbios_knl_Queue_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__PARAMS__C, ".const:ti_sysbios_knl_Semaphore_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__PARAMS__C, ".const:ti_sysbios_knl_Swi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__PARAMS__C, ".const:ti_sysbios_knl_Task_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Instance_State_sem__O, ".const:ti_sysbios_gates_GateMutex_Instance_State_sem__O");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module_State_clockQ__O, ".const:ti_sysbios_knl_Clock_Module_State_clockQ__O");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Instance_State_pendQ__O, ".const:ti_sysbios_knl_Semaphore_Instance_State_pendQ__O");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module_State_inactiveQ__O, ".const:ti_sysbios_knl_Task_Module_State_inactiveQ__O");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module_State_terminatedQ__O, ".const:ti_sysbios_knl_Task_Module_State_terminatedQ__O");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Object__DESC__C, ".const:ti_sdo_utils_NameServerRemoteNull_Object__DESC__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C, ".const:ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__diagsEnabled__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__diagsIncluded__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__diagsMask__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__gateObj__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__gateObj__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__gatePrms__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__id__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__id__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__loggerDefined__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__loggerObj__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn0__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn1__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn2__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn4__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn8__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Module__startupDoneFxn__C, ".const:ti_sdo_utils_NameServerRemoteNull_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Object__count__C, ".const:ti_sdo_utils_NameServerRemoteNull_Object__count__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Object__heap__C, ".const:ti_sdo_utils_NameServerRemoteNull_Object__heap__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Object__sizeof__C, ".const:ti_sdo_utils_NameServerRemoteNull_Object__sizeof__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Object__table__C, ".const:ti_sdo_utils_NameServerRemoteNull_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsEnabled__C, ".const:ti_sysbios_BIOS_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsIncluded__C, ".const:ti_sysbios_BIOS_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsMask__C, ".const:ti_sysbios_BIOS_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__gateObj__C, ".const:ti_sysbios_BIOS_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__gatePrms__C, ".const:ti_sysbios_BIOS_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__id__C, ".const:ti_sysbios_BIOS_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerDefined__C, ".const:ti_sysbios_BIOS_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerObj__C, ".const:ti_sysbios_BIOS_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn0__C, ".const:ti_sysbios_BIOS_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn1__C, ".const:ti_sysbios_BIOS_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn2__C, ".const:ti_sysbios_BIOS_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn4__C, ".const:ti_sysbios_BIOS_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn8__C, ".const:ti_sysbios_BIOS_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__startupDoneFxn__C, ".const:ti_sysbios_BIOS_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__count__C, ".const:ti_sysbios_BIOS_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__heap__C, ".const:ti_sysbios_BIOS_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__sizeof__C, ".const:ti_sysbios_BIOS_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__table__C, ".const:ti_sysbios_BIOS_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_cpuFreq__C, ".const:ti_sysbios_BIOS_cpuFreq__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_taskEnabled__C, ".const:ti_sysbios_BIOS_taskEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_swiEnabled__C, ".const:ti_sysbios_BIOS_swiEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_clockEnabled__C, ".const:ti_sysbios_BIOS_clockEnabled__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_heapSize__C, ".const:ti_sysbios_BIOS_heapSize__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_heapSection__C, ".const:ti_sysbios_BIOS_heapSection__C");
#pragma DATA_SECTION(ti_sysbios_BIOS_installedErrorHook__C, ".const:ti_sysbios_BIOS_installedErrorHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C, ".const:ti_sysbios_family_c62_IntrinsicsSupport_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__gateObj__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__id__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c62_TaskSupport_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__count__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__heap__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__sizeof__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_Object__table__C, ".const:ti_sysbios_family_c62_TaskSupport_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_defaultStackSize__C, ".const:ti_sysbios_family_c62_TaskSupport_defaultStackSize__C");
#pragma DATA_SECTION(ti_sysbios_family_c62_TaskSupport_stackAlignment__C, ".const:ti_sysbios_family_c62_TaskSupport_stackAlignment__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_Exception_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__gateObj__C, ".const:ti_sysbios_family_c64p_Exception_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_Exception_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__id__C, ".const:ti_sysbios_family_c64p_Exception_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_Exception_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_Exception_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__count__C, ".const:ti_sysbios_family_c64p_Exception_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__heap__C, ".const:ti_sysbios_family_c64p_Exception_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__sizeof__C, ".const:ti_sysbios_family_c64p_Exception_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_Object__table__C, ".const:ti_sysbios_family_c64p_Exception_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_E_exceptionMin__C, ".const:ti_sysbios_family_c64p_Exception_E_exceptionMin__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_E_exceptionMax__C, ".const:ti_sysbios_family_c64p_Exception_E_exceptionMax__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_enableExternalMPC__C, ".const:ti_sysbios_family_c64p_Exception_enableExternalMPC__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_enablePrint__C, ".const:ti_sysbios_family_c64p_Exception_enablePrint__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_exceptionHook__C, ".const:ti_sysbios_family_c64p_Exception_exceptionHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_internalHook__C, ".const:ti_sysbios_family_c64p_Exception_internalHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_externalHook__C, ".const:ti_sysbios_family_c64p_Exception_externalHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_nmiHook__C, ".const:ti_sysbios_family_c64p_Exception_nmiHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Exception_returnHook__C, ".const:ti_sysbios_family_c64p_Exception_returnHook__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__DESC__C, ".const:ti_sysbios_family_c64p_Hwi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__PARAMS__C, ".const:ti_sysbios_family_c64p_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_hooks__A, ".const:ti_sysbios_family_c64p_Hwi_hooks__A");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_Hwi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__gateObj__C, ".const:ti_sysbios_family_c64p_Hwi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_Hwi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__id__C, ".const:ti_sysbios_family_c64p_Hwi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_Hwi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_Hwi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__count__C, ".const:ti_sysbios_family_c64p_Hwi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__heap__C, ".const:ti_sysbios_family_c64p_Hwi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__sizeof__C, ".const:ti_sysbios_family_c64p_Hwi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_Object__table__C, ".const:ti_sysbios_family_c64p_Hwi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherAutoNestingSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherSwiSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherTaskSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C, ".const:ti_sysbios_family_c64p_Hwi_dispatcherIrpTrackingSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C, ".const:ti_sysbios_family_c64p_Hwi_E_alreadyDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_LM_begin__C, ".const:ti_sysbios_family_c64p_Hwi_LM_begin__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_LD_end__C, ".const:ti_sysbios_family_c64p_Hwi_LD_end__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_enableException__C, ".const:ti_sysbios_family_c64p_Hwi_enableException__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_swiDisable__C, ".const:ti_sysbios_family_c64p_Hwi_swiDisable__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C, ".const:ti_sysbios_family_c64p_Hwi_swiRestoreHwi__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_taskDisable__C, ".const:ti_sysbios_family_c64p_Hwi_taskDisable__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C, ".const:ti_sysbios_family_c64p_Hwi_taskRestoreHwi__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_Hwi_hooks__C, ".const:ti_sysbios_family_c64p_Hwi_hooks__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__id__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__count__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__heap__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_TimestampProvider_Object__table__C, ".const:ti_sysbios_family_c64p_TimestampProvider_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_timer__A, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_timer__A");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__gateObj__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__id__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Object__count__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Object__heap__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Object__sizeof__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_Object__table__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_timer__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_timer__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_TimerSupport_controlMsuspendMux1Addr__C, ".const:ti_sysbios_family_c64p_tesla_TimerSupport_controlMsuspendMux1Addr__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__diagsEnabled__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__diagsIncluded__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__diagsMask__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__gateObj__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__gatePrms__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__id__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__loggerDefined__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__loggerObj__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn0__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn1__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn2__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn4__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn8__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Module__startupDoneFxn__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Object__count__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Object__heap__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Object__sizeof__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_c64p_tesla_Wugen_Object__table__C, ".const:ti_sysbios_family_c64p_tesla_Wugen_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__DESC__C, ".const:ti_sysbios_gates_GateHwi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__PARAMS__C, ".const:ti_sysbios_gates_GateHwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsEnabled__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsIncluded__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsMask__C, ".const:ti_sysbios_gates_GateHwi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__gateObj__C, ".const:ti_sysbios_gates_GateHwi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__gatePrms__C, ".const:ti_sysbios_gates_GateHwi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__id__C, ".const:ti_sysbios_gates_GateHwi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerDefined__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerObj__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn0__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn1__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn2__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn4__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn8__C, ".const:ti_sysbios_gates_GateHwi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C, ".const:ti_sysbios_gates_GateHwi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__count__C, ".const:ti_sysbios_gates_GateHwi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__heap__C, ".const:ti_sysbios_gates_GateHwi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__sizeof__C, ".const:ti_sysbios_gates_GateHwi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__table__C, ".const:ti_sysbios_gates_GateHwi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__DESC__C, ".const:ti_sysbios_gates_GateMutex_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__PARAMS__C, ".const:ti_sysbios_gates_GateMutex_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsEnabled__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsIncluded__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsMask__C, ".const:ti_sysbios_gates_GateMutex_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__gateObj__C, ".const:ti_sysbios_gates_GateMutex_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__gatePrms__C, ".const:ti_sysbios_gates_GateMutex_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__id__C, ".const:ti_sysbios_gates_GateMutex_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerDefined__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerObj__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn0__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn1__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn2__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn4__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn8__C, ".const:ti_sysbios_gates_GateMutex_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C, ".const:ti_sysbios_gates_GateMutex_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__count__C, ".const:ti_sysbios_gates_GateMutex_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__heap__C, ".const:ti_sysbios_gates_GateMutex_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__sizeof__C, ".const:ti_sysbios_gates_GateMutex_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__table__C, ".const:ti_sysbios_gates_GateMutex_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_A_badContext__C, ".const:ti_sysbios_gates_GateMutex_A_badContext__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__DESC__C, ".const:ti_sysbios_hal_Hwi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__PARAMS__C, ".const:ti_sysbios_hal_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsEnabled__C, ".const:ti_sysbios_hal_Hwi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsIncluded__C, ".const:ti_sysbios_hal_Hwi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsMask__C, ".const:ti_sysbios_hal_Hwi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__gateObj__C, ".const:ti_sysbios_hal_Hwi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__gatePrms__C, ".const:ti_sysbios_hal_Hwi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__id__C, ".const:ti_sysbios_hal_Hwi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerDefined__C, ".const:ti_sysbios_hal_Hwi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerObj__C, ".const:ti_sysbios_hal_Hwi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn0__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn1__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn2__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn4__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn8__C, ".const:ti_sysbios_hal_Hwi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_Hwi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__count__C, ".const:ti_sysbios_hal_Hwi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__heap__C, ".const:ti_sysbios_hal_Hwi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__sizeof__C, ".const:ti_sysbios_hal_Hwi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__table__C, ".const:ti_sysbios_hal_Hwi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherSwiSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherSwiSupport__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherTaskSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherTaskSupport__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C, ".const:ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C");
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_E_stackOverflow__C, ".const:ti_sysbios_hal_Hwi_E_stackOverflow__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__DESC__C, ".const:ti_sysbios_hal_Timer_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__PARAMS__C, ".const:ti_sysbios_hal_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__diagsEnabled__C, ".const:ti_sysbios_hal_Timer_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__diagsIncluded__C, ".const:ti_sysbios_hal_Timer_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__diagsMask__C, ".const:ti_sysbios_hal_Timer_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__gateObj__C, ".const:ti_sysbios_hal_Timer_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__gatePrms__C, ".const:ti_sysbios_hal_Timer_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__id__C, ".const:ti_sysbios_hal_Timer_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerDefined__C, ".const:ti_sysbios_hal_Timer_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerObj__C, ".const:ti_sysbios_hal_Timer_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn0__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn1__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn2__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn4__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__loggerFxn8__C, ".const:ti_sysbios_hal_Timer_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Module__startupDoneFxn__C, ".const:ti_sysbios_hal_Timer_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__count__C, ".const:ti_sysbios_hal_Timer_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__heap__C, ".const:ti_sysbios_hal_Timer_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__sizeof__C, ".const:ti_sysbios_hal_Timer_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_hal_Timer_Object__table__C, ".const:ti_sysbios_hal_Timer_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__DESC__C, ".const:ti_sysbios_heaps_HeapMem_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__PARAMS__C, ".const:ti_sysbios_heaps_HeapMem_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsMask__C, ".const:ti_sysbios_heaps_HeapMem_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__gateObj__C, ".const:ti_sysbios_heaps_HeapMem_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__gatePrms__C, ".const:ti_sysbios_heaps_HeapMem_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__id__C, ".const:ti_sysbios_heaps_HeapMem_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerDefined__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerObj__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C, ".const:ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C, ".const:ti_sysbios_heaps_HeapMem_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__count__C, ".const:ti_sysbios_heaps_HeapMem_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__heap__C, ".const:ti_sysbios_heaps_HeapMem_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__sizeof__C, ".const:ti_sysbios_heaps_HeapMem_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__table__C, ".const:ti_sysbios_heaps_HeapMem_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_zeroBlock__C, ".const:ti_sysbios_heaps_HeapMem_A_zeroBlock__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_heapSize__C, ".const:ti_sysbios_heaps_HeapMem_A_heapSize__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_align__C, ".const:ti_sysbios_heaps_HeapMem_A_align__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_E_memory__C, ".const:ti_sysbios_heaps_HeapMem_E_memory__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_invalidFree__C, ".const:ti_sysbios_heaps_HeapMem_A_invalidFree__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_reqAlign__C, ".const:ti_sysbios_heaps_HeapMem_reqAlign__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_reqAlignMask__C, ".const:ti_sysbios_heaps_HeapMem_reqAlignMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__DESC__C, ".const:ti_sysbios_knl_Clock_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__PARAMS__C, ".const:ti_sysbios_knl_Clock_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Clock_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Clock_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsMask__C, ".const:ti_sysbios_knl_Clock_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__gateObj__C, ".const:ti_sysbios_knl_Clock_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__gatePrms__C, ".const:ti_sysbios_knl_Clock_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__id__C, ".const:ti_sysbios_knl_Clock_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerDefined__C, ".const:ti_sysbios_knl_Clock_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerObj__C, ".const:ti_sysbios_knl_Clock_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Clock_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Clock_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__count__C, ".const:ti_sysbios_knl_Clock_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__heap__C, ".const:ti_sysbios_knl_Clock_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__sizeof__C, ".const:ti_sysbios_knl_Clock_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__table__C, ".const:ti_sysbios_knl_Clock_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LW_delayed__C, ".const:ti_sysbios_knl_Clock_LW_delayed__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_tick__C, ".const:ti_sysbios_knl_Clock_LM_tick__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_begin__C, ".const:ti_sysbios_knl_Clock_LM_begin__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_clockDisabled__C, ".const:ti_sysbios_knl_Clock_A_clockDisabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_badThreadType__C, ".const:ti_sysbios_knl_Clock_A_badThreadType__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickSource__C, ".const:ti_sysbios_knl_Clock_tickSource__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickMode__C, ".const:ti_sysbios_knl_Clock_tickMode__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_timerId__C, ".const:ti_sysbios_knl_Clock_timerId__C");
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickPeriod__C, ".const:ti_sysbios_knl_Clock_tickPeriod__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_funcList__A, ".const:ti_sysbios_knl_Idle_funcList__A");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Idle_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Idle_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsMask__C, ".const:ti_sysbios_knl_Idle_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__gateObj__C, ".const:ti_sysbios_knl_Idle_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__gatePrms__C, ".const:ti_sysbios_knl_Idle_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__id__C, ".const:ti_sysbios_knl_Idle_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerDefined__C, ".const:ti_sysbios_knl_Idle_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerObj__C, ".const:ti_sysbios_knl_Idle_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Idle_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Idle_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__count__C, ".const:ti_sysbios_knl_Idle_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__heap__C, ".const:ti_sysbios_knl_Idle_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__sizeof__C, ".const:ti_sysbios_knl_Idle_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__table__C, ".const:ti_sysbios_knl_Idle_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Idle_funcList__C, ".const:ti_sysbios_knl_Idle_funcList__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsMask__C, ".const:ti_sysbios_knl_Intrinsics_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__gateObj__C, ".const:ti_sysbios_knl_Intrinsics_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__gatePrms__C, ".const:ti_sysbios_knl_Intrinsics_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__id__C, ".const:ti_sysbios_knl_Intrinsics_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerDefined__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerObj__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Intrinsics_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__count__C, ".const:ti_sysbios_knl_Intrinsics_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__heap__C, ".const:ti_sysbios_knl_Intrinsics_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__sizeof__C, ".const:ti_sysbios_knl_Intrinsics_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__table__C, ".const:ti_sysbios_knl_Intrinsics_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__DESC__C, ".const:ti_sysbios_knl_Queue_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__PARAMS__C, ".const:ti_sysbios_knl_Queue_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Queue_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Queue_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsMask__C, ".const:ti_sysbios_knl_Queue_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__gateObj__C, ".const:ti_sysbios_knl_Queue_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__gatePrms__C, ".const:ti_sysbios_knl_Queue_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__id__C, ".const:ti_sysbios_knl_Queue_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerDefined__C, ".const:ti_sysbios_knl_Queue_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerObj__C, ".const:ti_sysbios_knl_Queue_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Queue_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Queue_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__count__C, ".const:ti_sysbios_knl_Queue_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__heap__C, ".const:ti_sysbios_knl_Queue_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__sizeof__C, ".const:ti_sysbios_knl_Queue_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__table__C, ".const:ti_sysbios_knl_Queue_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__DESC__C, ".const:ti_sysbios_knl_Semaphore_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__PARAMS__C, ".const:ti_sysbios_knl_Semaphore_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsMask__C, ".const:ti_sysbios_knl_Semaphore_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__gateObj__C, ".const:ti_sysbios_knl_Semaphore_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__gatePrms__C, ".const:ti_sysbios_knl_Semaphore_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__id__C, ".const:ti_sysbios_knl_Semaphore_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerDefined__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerObj__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Semaphore_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__count__C, ".const:ti_sysbios_knl_Semaphore_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__heap__C, ".const:ti_sysbios_knl_Semaphore_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__sizeof__C, ".const:ti_sysbios_knl_Semaphore_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__table__C, ".const:ti_sysbios_knl_Semaphore_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_post__C, ".const:ti_sysbios_knl_Semaphore_LM_post__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_pend__C, ".const:ti_sysbios_knl_Semaphore_LM_pend__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_noEvents__C, ".const:ti_sysbios_knl_Semaphore_A_noEvents__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_invTimeout__C, ".const:ti_sysbios_knl_Semaphore_A_invTimeout__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_badContext__C, ".const:ti_sysbios_knl_Semaphore_A_badContext__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_supportsEvents__C, ".const:ti_sysbios_knl_Semaphore_supportsEvents__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_eventPost__C, ".const:ti_sysbios_knl_Semaphore_eventPost__C");
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_eventSync__C, ".const:ti_sysbios_knl_Semaphore_eventSync__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__DESC__C, ".const:ti_sysbios_knl_Swi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__PARAMS__C, ".const:ti_sysbios_knl_Swi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Swi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Swi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsMask__C, ".const:ti_sysbios_knl_Swi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__gateObj__C, ".const:ti_sysbios_knl_Swi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__gatePrms__C, ".const:ti_sysbios_knl_Swi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__id__C, ".const:ti_sysbios_knl_Swi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerDefined__C, ".const:ti_sysbios_knl_Swi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerObj__C, ".const:ti_sysbios_knl_Swi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Swi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Swi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__count__C, ".const:ti_sysbios_knl_Swi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__heap__C, ".const:ti_sysbios_knl_Swi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__sizeof__C, ".const:ti_sysbios_knl_Swi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__table__C, ".const:ti_sysbios_knl_Swi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_begin__C, ".const:ti_sysbios_knl_Swi_LM_begin__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LD_end__C, ".const:ti_sysbios_knl_Swi_LD_end__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_post__C, ".const:ti_sysbios_knl_Swi_LM_post__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_swiDisabled__C, ".const:ti_sysbios_knl_Swi_A_swiDisabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_badPriority__C, ".const:ti_sysbios_knl_Swi_A_badPriority__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_numPriorities__C, ".const:ti_sysbios_knl_Swi_numPriorities__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_hooks__C, ".const:ti_sysbios_knl_Swi_hooks__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_taskDisable__C, ".const:ti_sysbios_knl_Swi_taskDisable__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_taskRestore__C, ".const:ti_sysbios_knl_Swi_taskRestore__C");
#pragma DATA_SECTION(ti_sysbios_knl_Swi_numConstructedSwis__C, ".const:ti_sysbios_knl_Swi_numConstructedSwis__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__DESC__C, ".const:ti_sysbios_knl_Task_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__PARAMS__C, ".const:ti_sysbios_knl_Task_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_hooks__A, ".const:ti_sysbios_knl_Task_hooks__A");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsEnabled__C, ".const:ti_sysbios_knl_Task_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsIncluded__C, ".const:ti_sysbios_knl_Task_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsMask__C, ".const:ti_sysbios_knl_Task_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__gateObj__C, ".const:ti_sysbios_knl_Task_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__gatePrms__C, ".const:ti_sysbios_knl_Task_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__id__C, ".const:ti_sysbios_knl_Task_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerDefined__C, ".const:ti_sysbios_knl_Task_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerObj__C, ".const:ti_sysbios_knl_Task_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn0__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn1__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn2__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn4__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn8__C, ".const:ti_sysbios_knl_Task_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__startupDoneFxn__C, ".const:ti_sysbios_knl_Task_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__count__C, ".const:ti_sysbios_knl_Task_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__heap__C, ".const:ti_sysbios_knl_Task_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__sizeof__C, ".const:ti_sysbios_knl_Task_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__table__C, ".const:ti_sysbios_knl_Task_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_switch__C, ".const:ti_sysbios_knl_Task_LM_switch__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_sleep__C, ".const:ti_sysbios_knl_Task_LM_sleep__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_ready__C, ".const:ti_sysbios_knl_Task_LD_ready__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_block__C, ".const:ti_sysbios_knl_Task_LD_block__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_yield__C, ".const:ti_sysbios_knl_Task_LM_yield__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setPri__C, ".const:ti_sysbios_knl_Task_LM_setPri__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_exit__C, ".const:ti_sysbios_knl_Task_LD_exit__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_stackOverflow__C, ".const:ti_sysbios_knl_Task_E_stackOverflow__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_spOutOfBounds__C, ".const:ti_sysbios_knl_Task_E_spOutOfBounds__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badThreadType__C, ".const:ti_sysbios_knl_Task_A_badThreadType__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTaskState__C, ".const:ti_sysbios_knl_Task_A_badTaskState__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_noPendElem__C, ".const:ti_sysbios_knl_Task_A_noPendElem__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_taskDisabled__C, ".const:ti_sysbios_knl_Task_A_taskDisabled__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badPriority__C, ".const:ti_sysbios_knl_Task_A_badPriority__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTimeout__C, ".const:ti_sysbios_knl_Task_A_badTimeout__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_numPriorities__C, ".const:ti_sysbios_knl_Task_numPriorities__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_defaultStackSize__C, ".const:ti_sysbios_knl_Task_defaultStackSize__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_defaultStackHeap__C, ".const:ti_sysbios_knl_Task_defaultStackHeap__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_allBlockedFunc__C, ".const:ti_sysbios_knl_Task_allBlockedFunc__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_initStackFlag__C, ".const:ti_sysbios_knl_Task_initStackFlag__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_deleteTerminatedTasks__C, ".const:ti_sysbios_knl_Task_deleteTerminatedTasks__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_hooks__C, ".const:ti_sysbios_knl_Task_hooks__C");
#pragma DATA_SECTION(ti_sysbios_knl_Task_numConstructedTasks__C, ".const:ti_sysbios_knl_Task_numConstructedTasks__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__DESC__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__id__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn__C, ".const:ti_sysbios_timers_dmtimer_Timer_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__count__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__heap__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__sizeof__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_Object__table__C, ".const:ti_sysbios_timers_dmtimer_Timer_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_invalidTimer__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_invalidTimer__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_notAvailable__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_notAvailable__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_cannotSupport__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_cannotSupport__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_E_freqMismatch__C, ".const:ti_sysbios_timers_dmtimer_Timer_E_freqMismatch__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_anyMask__C, ".const:ti_sysbios_timers_dmtimer_Timer_anyMask__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_checkFrequency__C, ".const:ti_sysbios_timers_dmtimer_Timer_checkFrequency__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_startupNeeded__C, ".const:ti_sysbios_timers_dmtimer_Timer_startupNeeded__C");
#pragma DATA_SECTION(ti_sysbios_timers_dmtimer_Timer_numTimerDevices__C, ".const:ti_sysbios_timers_dmtimer_Timer_numTimerDevices__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsEnabled__C, ".const:xdc_runtime_Assert_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsIncluded__C, ".const:xdc_runtime_Assert_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsMask__C, ".const:xdc_runtime_Assert_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__gateObj__C, ".const:xdc_runtime_Assert_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__gatePrms__C, ".const:xdc_runtime_Assert_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__id__C, ".const:xdc_runtime_Assert_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerDefined__C, ".const:xdc_runtime_Assert_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerObj__C, ".const:xdc_runtime_Assert_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn0__C, ".const:xdc_runtime_Assert_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn1__C, ".const:xdc_runtime_Assert_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn2__C, ".const:xdc_runtime_Assert_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn4__C, ".const:xdc_runtime_Assert_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn8__C, ".const:xdc_runtime_Assert_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Module__startupDoneFxn__C, ".const:xdc_runtime_Assert_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Object__count__C, ".const:xdc_runtime_Assert_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Object__heap__C, ".const:xdc_runtime_Assert_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Object__sizeof__C, ".const:xdc_runtime_Assert_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Assert_Object__table__C, ".const:xdc_runtime_Assert_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Assert_E_assertFailed__C, ".const:xdc_runtime_Assert_E_assertFailed__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsEnabled__C, ".const:xdc_runtime_Core_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsIncluded__C, ".const:xdc_runtime_Core_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsMask__C, ".const:xdc_runtime_Core_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__gateObj__C, ".const:xdc_runtime_Core_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__gatePrms__C, ".const:xdc_runtime_Core_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__id__C, ".const:xdc_runtime_Core_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerDefined__C, ".const:xdc_runtime_Core_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerObj__C, ".const:xdc_runtime_Core_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn0__C, ".const:xdc_runtime_Core_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn1__C, ".const:xdc_runtime_Core_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn2__C, ".const:xdc_runtime_Core_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn4__C, ".const:xdc_runtime_Core_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn8__C, ".const:xdc_runtime_Core_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Core_Module__startupDoneFxn__C, ".const:xdc_runtime_Core_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Core_Object__count__C, ".const:xdc_runtime_Core_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Core_Object__heap__C, ".const:xdc_runtime_Core_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Core_Object__sizeof__C, ".const:xdc_runtime_Core_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Core_Object__table__C, ".const:xdc_runtime_Core_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Core_A_initializedParams__C, ".const:xdc_runtime_Core_A_initializedParams__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsEnabled__C, ".const:xdc_runtime_Defaults_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsIncluded__C, ".const:xdc_runtime_Defaults_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsMask__C, ".const:xdc_runtime_Defaults_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__gateObj__C, ".const:xdc_runtime_Defaults_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__gatePrms__C, ".const:xdc_runtime_Defaults_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__id__C, ".const:xdc_runtime_Defaults_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerDefined__C, ".const:xdc_runtime_Defaults_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerObj__C, ".const:xdc_runtime_Defaults_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn0__C, ".const:xdc_runtime_Defaults_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn1__C, ".const:xdc_runtime_Defaults_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn2__C, ".const:xdc_runtime_Defaults_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn4__C, ".const:xdc_runtime_Defaults_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn8__C, ".const:xdc_runtime_Defaults_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__startupDoneFxn__C, ".const:xdc_runtime_Defaults_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__count__C, ".const:xdc_runtime_Defaults_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__heap__C, ".const:xdc_runtime_Defaults_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__sizeof__C, ".const:xdc_runtime_Defaults_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__table__C, ".const:xdc_runtime_Defaults_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsEnabled__C, ".const:xdc_runtime_Diags_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsIncluded__C, ".const:xdc_runtime_Diags_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsMask__C, ".const:xdc_runtime_Diags_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__gateObj__C, ".const:xdc_runtime_Diags_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__gatePrms__C, ".const:xdc_runtime_Diags_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__id__C, ".const:xdc_runtime_Diags_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerDefined__C, ".const:xdc_runtime_Diags_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerObj__C, ".const:xdc_runtime_Diags_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn0__C, ".const:xdc_runtime_Diags_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn1__C, ".const:xdc_runtime_Diags_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn2__C, ".const:xdc_runtime_Diags_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn4__C, ".const:xdc_runtime_Diags_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn8__C, ".const:xdc_runtime_Diags_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Module__startupDoneFxn__C, ".const:xdc_runtime_Diags_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Object__count__C, ".const:xdc_runtime_Diags_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Object__heap__C, ".const:xdc_runtime_Diags_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Object__sizeof__C, ".const:xdc_runtime_Diags_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Diags_Object__table__C, ".const:xdc_runtime_Diags_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Diags_setMaskEnabled__C, ".const:xdc_runtime_Diags_setMaskEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Diags_dictBase__C, ".const:xdc_runtime_Diags_dictBase__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsEnabled__C, ".const:xdc_runtime_Error_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsIncluded__C, ".const:xdc_runtime_Error_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsMask__C, ".const:xdc_runtime_Error_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__gateObj__C, ".const:xdc_runtime_Error_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__gatePrms__C, ".const:xdc_runtime_Error_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__id__C, ".const:xdc_runtime_Error_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerDefined__C, ".const:xdc_runtime_Error_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerObj__C, ".const:xdc_runtime_Error_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn0__C, ".const:xdc_runtime_Error_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn1__C, ".const:xdc_runtime_Error_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn2__C, ".const:xdc_runtime_Error_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn4__C, ".const:xdc_runtime_Error_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn8__C, ".const:xdc_runtime_Error_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Error_Module__startupDoneFxn__C, ".const:xdc_runtime_Error_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Error_Object__count__C, ".const:xdc_runtime_Error_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Error_Object__heap__C, ".const:xdc_runtime_Error_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Error_Object__sizeof__C, ".const:xdc_runtime_Error_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Error_Object__table__C, ".const:xdc_runtime_Error_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Error_E_generic__C, ".const:xdc_runtime_Error_E_generic__C");
#pragma DATA_SECTION(xdc_runtime_Error_E_memory__C, ".const:xdc_runtime_Error_E_memory__C");
#pragma DATA_SECTION(xdc_runtime_Error_E_msgCode__C, ".const:xdc_runtime_Error_E_msgCode__C");
#pragma DATA_SECTION(xdc_runtime_Error_policy__C, ".const:xdc_runtime_Error_policy__C");
#pragma DATA_SECTION(xdc_runtime_Error_raiseHook__C, ".const:xdc_runtime_Error_raiseHook__C");
#pragma DATA_SECTION(xdc_runtime_Error_maxDepth__C, ".const:xdc_runtime_Error_maxDepth__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsEnabled__C, ".const:xdc_runtime_Gate_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsIncluded__C, ".const:xdc_runtime_Gate_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsMask__C, ".const:xdc_runtime_Gate_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__gateObj__C, ".const:xdc_runtime_Gate_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__gatePrms__C, ".const:xdc_runtime_Gate_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__id__C, ".const:xdc_runtime_Gate_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerDefined__C, ".const:xdc_runtime_Gate_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerObj__C, ".const:xdc_runtime_Gate_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn0__C, ".const:xdc_runtime_Gate_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn1__C, ".const:xdc_runtime_Gate_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn2__C, ".const:xdc_runtime_Gate_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn4__C, ".const:xdc_runtime_Gate_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn8__C, ".const:xdc_runtime_Gate_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Module__startupDoneFxn__C, ".const:xdc_runtime_Gate_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Object__count__C, ".const:xdc_runtime_Gate_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Object__heap__C, ".const:xdc_runtime_Gate_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Object__sizeof__C, ".const:xdc_runtime_Gate_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Gate_Object__table__C, ".const:xdc_runtime_Gate_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsEnabled__C, ".const:xdc_runtime_Log_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsIncluded__C, ".const:xdc_runtime_Log_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsMask__C, ".const:xdc_runtime_Log_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__gateObj__C, ".const:xdc_runtime_Log_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__gatePrms__C, ".const:xdc_runtime_Log_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__id__C, ".const:xdc_runtime_Log_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerDefined__C, ".const:xdc_runtime_Log_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerObj__C, ".const:xdc_runtime_Log_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn0__C, ".const:xdc_runtime_Log_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn1__C, ".const:xdc_runtime_Log_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn2__C, ".const:xdc_runtime_Log_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn4__C, ".const:xdc_runtime_Log_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn8__C, ".const:xdc_runtime_Log_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Log_Module__startupDoneFxn__C, ".const:xdc_runtime_Log_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Log_Object__count__C, ".const:xdc_runtime_Log_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Log_Object__heap__C, ".const:xdc_runtime_Log_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Log_Object__sizeof__C, ".const:xdc_runtime_Log_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Log_Object__table__C, ".const:xdc_runtime_Log_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_construct__C, ".const:xdc_runtime_Log_L_construct__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_create__C, ".const:xdc_runtime_Log_L_create__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_destruct__C, ".const:xdc_runtime_Log_L_destruct__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_delete__C, ".const:xdc_runtime_Log_L_delete__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_error__C, ".const:xdc_runtime_Log_L_error__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_warning__C, ".const:xdc_runtime_Log_L_warning__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_info__C, ".const:xdc_runtime_Log_L_info__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_start__C, ".const:xdc_runtime_Log_L_start__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_stop__C, ".const:xdc_runtime_Log_L_stop__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_startInstance__C, ".const:xdc_runtime_Log_L_startInstance__C");
#pragma DATA_SECTION(xdc_runtime_Log_L_stopInstance__C, ".const:xdc_runtime_Log_L_stopInstance__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsEnabled__C, ".const:xdc_runtime_Main_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsIncluded__C, ".const:xdc_runtime_Main_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsMask__C, ".const:xdc_runtime_Main_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__gateObj__C, ".const:xdc_runtime_Main_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__gatePrms__C, ".const:xdc_runtime_Main_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__id__C, ".const:xdc_runtime_Main_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerDefined__C, ".const:xdc_runtime_Main_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerObj__C, ".const:xdc_runtime_Main_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn0__C, ".const:xdc_runtime_Main_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn1__C, ".const:xdc_runtime_Main_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn2__C, ".const:xdc_runtime_Main_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn4__C, ".const:xdc_runtime_Main_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn8__C, ".const:xdc_runtime_Main_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Main_Module__startupDoneFxn__C, ".const:xdc_runtime_Main_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Main_Object__count__C, ".const:xdc_runtime_Main_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Main_Object__heap__C, ".const:xdc_runtime_Main_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Main_Object__sizeof__C, ".const:xdc_runtime_Main_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Main_Object__table__C, ".const:xdc_runtime_Main_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsEnabled__C, ".const:xdc_runtime_Memory_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsIncluded__C, ".const:xdc_runtime_Memory_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsMask__C, ".const:xdc_runtime_Memory_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__gateObj__C, ".const:xdc_runtime_Memory_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__gatePrms__C, ".const:xdc_runtime_Memory_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__id__C, ".const:xdc_runtime_Memory_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerDefined__C, ".const:xdc_runtime_Memory_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerObj__C, ".const:xdc_runtime_Memory_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn0__C, ".const:xdc_runtime_Memory_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn1__C, ".const:xdc_runtime_Memory_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn2__C, ".const:xdc_runtime_Memory_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn4__C, ".const:xdc_runtime_Memory_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn8__C, ".const:xdc_runtime_Memory_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Module__startupDoneFxn__C, ".const:xdc_runtime_Memory_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Object__count__C, ".const:xdc_runtime_Memory_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Object__heap__C, ".const:xdc_runtime_Memory_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Object__sizeof__C, ".const:xdc_runtime_Memory_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Memory_Object__table__C, ".const:xdc_runtime_Memory_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Memory_defaultHeapInstance__C, ".const:xdc_runtime_Memory_defaultHeapInstance__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsEnabled__C, ".const:xdc_runtime_Registry_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsIncluded__C, ".const:xdc_runtime_Registry_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsMask__C, ".const:xdc_runtime_Registry_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__gateObj__C, ".const:xdc_runtime_Registry_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__gatePrms__C, ".const:xdc_runtime_Registry_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__id__C, ".const:xdc_runtime_Registry_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerDefined__C, ".const:xdc_runtime_Registry_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerObj__C, ".const:xdc_runtime_Registry_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn0__C, ".const:xdc_runtime_Registry_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn1__C, ".const:xdc_runtime_Registry_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn2__C, ".const:xdc_runtime_Registry_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn4__C, ".const:xdc_runtime_Registry_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn8__C, ".const:xdc_runtime_Registry_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Module__startupDoneFxn__C, ".const:xdc_runtime_Registry_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Object__count__C, ".const:xdc_runtime_Registry_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Object__heap__C, ".const:xdc_runtime_Registry_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Object__sizeof__C, ".const:xdc_runtime_Registry_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Registry_Object__table__C, ".const:xdc_runtime_Registry_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Startup_firstFxns__A, ".const:xdc_runtime_Startup_firstFxns__A");
#pragma DATA_SECTION(xdc_runtime_Startup_lastFxns__A, ".const:xdc_runtime_Startup_lastFxns__A");
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__A, ".const:xdc_runtime_Startup_sfxnTab__A");
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__A, ".const:xdc_runtime_Startup_sfxnRts__A");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsEnabled__C, ".const:xdc_runtime_Startup_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsIncluded__C, ".const:xdc_runtime_Startup_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsMask__C, ".const:xdc_runtime_Startup_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__gateObj__C, ".const:xdc_runtime_Startup_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__gatePrms__C, ".const:xdc_runtime_Startup_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__id__C, ".const:xdc_runtime_Startup_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerDefined__C, ".const:xdc_runtime_Startup_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerObj__C, ".const:xdc_runtime_Startup_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn0__C, ".const:xdc_runtime_Startup_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn1__C, ".const:xdc_runtime_Startup_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn2__C, ".const:xdc_runtime_Startup_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn4__C, ".const:xdc_runtime_Startup_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn8__C, ".const:xdc_runtime_Startup_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Module__startupDoneFxn__C, ".const:xdc_runtime_Startup_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Object__count__C, ".const:xdc_runtime_Startup_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Object__heap__C, ".const:xdc_runtime_Startup_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Object__sizeof__C, ".const:xdc_runtime_Startup_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Startup_Object__table__C, ".const:xdc_runtime_Startup_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Startup_maxPasses__C, ".const:xdc_runtime_Startup_maxPasses__C");
#pragma DATA_SECTION(xdc_runtime_Startup_firstFxns__C, ".const:xdc_runtime_Startup_firstFxns__C");
#pragma DATA_SECTION(xdc_runtime_Startup_lastFxns__C, ".const:xdc_runtime_Startup_lastFxns__C");
#pragma DATA_SECTION(xdc_runtime_Startup_startModsFxn__C, ".const:xdc_runtime_Startup_startModsFxn__C");
#pragma DATA_SECTION(xdc_runtime_Startup_execImpl__C, ".const:xdc_runtime_Startup_execImpl__C");
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__C, ".const:xdc_runtime_Startup_sfxnTab__C");
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__C, ".const:xdc_runtime_Startup_sfxnRts__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsEnabled__C, ".const:xdc_runtime_SysMin_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsIncluded__C, ".const:xdc_runtime_SysMin_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsMask__C, ".const:xdc_runtime_SysMin_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__gateObj__C, ".const:xdc_runtime_SysMin_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__gatePrms__C, ".const:xdc_runtime_SysMin_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__id__C, ".const:xdc_runtime_SysMin_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerDefined__C, ".const:xdc_runtime_SysMin_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerObj__C, ".const:xdc_runtime_SysMin_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn0__C, ".const:xdc_runtime_SysMin_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn1__C, ".const:xdc_runtime_SysMin_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn2__C, ".const:xdc_runtime_SysMin_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn4__C, ".const:xdc_runtime_SysMin_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn8__C, ".const:xdc_runtime_SysMin_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__startupDoneFxn__C, ".const:xdc_runtime_SysMin_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__count__C, ".const:xdc_runtime_SysMin_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__heap__C, ".const:xdc_runtime_SysMin_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__sizeof__C, ".const:xdc_runtime_SysMin_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__table__C, ".const:xdc_runtime_SysMin_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_bufSize__C, ".const:xdc_runtime_SysMin_bufSize__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_flushAtExit__C, ".const:xdc_runtime_SysMin_flushAtExit__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_outputFxn__C, ".const:xdc_runtime_SysMin_outputFxn__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_outputFunc__C, ".const:xdc_runtime_SysMin_outputFunc__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsEnabled__C, ".const:xdc_runtime_System_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsIncluded__C, ".const:xdc_runtime_System_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsMask__C, ".const:xdc_runtime_System_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__gateObj__C, ".const:xdc_runtime_System_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__gatePrms__C, ".const:xdc_runtime_System_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__id__C, ".const:xdc_runtime_System_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerDefined__C, ".const:xdc_runtime_System_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerObj__C, ".const:xdc_runtime_System_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn0__C, ".const:xdc_runtime_System_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn1__C, ".const:xdc_runtime_System_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn2__C, ".const:xdc_runtime_System_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn4__C, ".const:xdc_runtime_System_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn8__C, ".const:xdc_runtime_System_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_System_Module__startupDoneFxn__C, ".const:xdc_runtime_System_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_System_Object__count__C, ".const:xdc_runtime_System_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_System_Object__heap__C, ".const:xdc_runtime_System_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_System_Object__sizeof__C, ".const:xdc_runtime_System_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_System_Object__table__C, ".const:xdc_runtime_System_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_System_A_cannotFitIntoArg__C, ".const:xdc_runtime_System_A_cannotFitIntoArg__C");
#pragma DATA_SECTION(xdc_runtime_System_maxAtexitHandlers__C, ".const:xdc_runtime_System_maxAtexitHandlers__C");
#pragma DATA_SECTION(xdc_runtime_System_extendFxn__C, ".const:xdc_runtime_System_extendFxn__C");
#pragma DATA_SECTION(xdc_runtime_Text_charTab__A, ".const:xdc_runtime_Text_charTab__A");
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__A, ".const:xdc_runtime_Text_nodeTab__A");
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsEnabled__C, ".const:xdc_runtime_Text_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsIncluded__C, ".const:xdc_runtime_Text_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsMask__C, ".const:xdc_runtime_Text_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__gateObj__C, ".const:xdc_runtime_Text_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__gatePrms__C, ".const:xdc_runtime_Text_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__id__C, ".const:xdc_runtime_Text_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerDefined__C, ".const:xdc_runtime_Text_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerObj__C, ".const:xdc_runtime_Text_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn0__C, ".const:xdc_runtime_Text_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn1__C, ".const:xdc_runtime_Text_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn2__C, ".const:xdc_runtime_Text_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn4__C, ".const:xdc_runtime_Text_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn8__C, ".const:xdc_runtime_Text_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Text_Module__startupDoneFxn__C, ".const:xdc_runtime_Text_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Text_Object__count__C, ".const:xdc_runtime_Text_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Text_Object__heap__C, ".const:xdc_runtime_Text_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Text_Object__sizeof__C, ".const:xdc_runtime_Text_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Text_Object__table__C, ".const:xdc_runtime_Text_Object__table__C");
#pragma DATA_SECTION(xdc_runtime_Text_nameUnknown__C, ".const:xdc_runtime_Text_nameUnknown__C");
#pragma DATA_SECTION(xdc_runtime_Text_nameEmpty__C, ".const:xdc_runtime_Text_nameEmpty__C");
#pragma DATA_SECTION(xdc_runtime_Text_nameStatic__C, ".const:xdc_runtime_Text_nameStatic__C");
#pragma DATA_SECTION(xdc_runtime_Text_isLoaded__C, ".const:xdc_runtime_Text_isLoaded__C");
#pragma DATA_SECTION(xdc_runtime_Text_charTab__C, ".const:xdc_runtime_Text_charTab__C");
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__C, ".const:xdc_runtime_Text_nodeTab__C");
#pragma DATA_SECTION(xdc_runtime_Text_charCnt__C, ".const:xdc_runtime_Text_charCnt__C");
#pragma DATA_SECTION(xdc_runtime_Text_nodeCnt__C, ".const:xdc_runtime_Text_nodeCnt__C");
#pragma DATA_SECTION(xdc_runtime_Text_unnamedModsLastId__C, ".const:xdc_runtime_Text_unnamedModsLastId__C");
#pragma DATA_SECTION(xdc_runtime_Text_registryModsLastId__C, ".const:xdc_runtime_Text_registryModsLastId__C");
#pragma DATA_SECTION(xdc_runtime_Text_visitRopeFxn__C, ".const:xdc_runtime_Text_visitRopeFxn__C");
#pragma DATA_SECTION(xdc_runtime_Text_visitRopeFxn2__C, ".const:xdc_runtime_Text_visitRopeFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsEnabled__C, ".const:xdc_runtime_Timestamp_Module__diagsEnabled__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsIncluded__C, ".const:xdc_runtime_Timestamp_Module__diagsIncluded__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__diagsMask__C, ".const:xdc_runtime_Timestamp_Module__diagsMask__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__gateObj__C, ".const:xdc_runtime_Timestamp_Module__gateObj__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__gatePrms__C, ".const:xdc_runtime_Timestamp_Module__gatePrms__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__id__C, ".const:xdc_runtime_Timestamp_Module__id__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerDefined__C, ".const:xdc_runtime_Timestamp_Module__loggerDefined__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerObj__C, ".const:xdc_runtime_Timestamp_Module__loggerObj__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn0__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn0__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn1__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn1__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn2__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn2__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn4__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn4__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__loggerFxn8__C, ".const:xdc_runtime_Timestamp_Module__loggerFxn8__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Module__startupDoneFxn__C, ".const:xdc_runtime_Timestamp_Module__startupDoneFxn__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__count__C, ".const:xdc_runtime_Timestamp_Object__count__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__heap__C, ".const:xdc_runtime_Timestamp_Object__heap__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__sizeof__C, ".const:xdc_runtime_Timestamp_Object__sizeof__C");
#pragma DATA_SECTION(xdc_runtime_Timestamp_Object__table__C, ".const:xdc_runtime_Timestamp_Object__table__C");
