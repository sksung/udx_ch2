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
#include <ti/sysbios/family/arm/ducati/CTM.h>
#include <ti/sysbios/family/arm/ducati/Core.h>
#include <ti/sysbios/family/arm/ducati/Timer.h>
#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/family/arm/m3/IntrinsicsSupport.h>
#include <ti/sysbios/family/arm/m3/TaskSupport.h>
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
 * ======== ti.sysbios.family.arm.ducati.CTM INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.Core INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.Timer INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_arm_ducati_Timer_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_arm_ducati_Timer_Module__;

/* Module__root__V */
extern ti_sysbios_family_arm_ducati_Timer_Module__ ti_sysbios_family_arm_ducati_Timer_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_arm_ducati_Timer_Object__ {
    const ti_sysbios_family_arm_ducati_Timer_Fxns__* __fxns;
    xdc_Bool staticInst;
    xdc_Int id;
    xdc_Int ctmid;
    ti_sysbios_family_arm_ducati_Timer_RunMode runMode;
    ti_sysbios_family_arm_ducati_Timer_StartMode startMode;
    xdc_UInt period;
    ti_sysbios_family_arm_ducati_Timer_PeriodType periodType;
    xdc_UInt intNum;
    xdc_UArg arg;
    ti_sysbios_family_arm_m3_Hwi_FuncPtr tickFxn;
    xdc_runtime_Types_FreqHz extFreq;
    ti_sysbios_family_arm_m3_Hwi_Handle hwi;
} ti_sysbios_family_arm_ducati_Timer_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_arm_ducati_Timer_Object__ obj;
} ti_sysbios_family_arm_ducati_Timer_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_family_arm_ducati_Timer___VERS
    #define ti_sysbios_family_arm_ducati_Timer___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_family_arm_ducati_Timer___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.arm.m3.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_arm_m3_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_arm_m3_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_family_arm_m3_Hwi_Module__ ti_sysbios_family_arm_m3_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_arm_m3_Hwi_Object__ {
    const ti_sysbios_family_arm_m3_Hwi_Fxns__* __fxns;
    xdc_UArg arg;
    ti_sysbios_family_arm_m3_Hwi_FuncPtr fxn;
    xdc_Int intNum;
    ti_sysbios_family_arm_m3_Hwi_Irp irp;
    __TA_ti_sysbios_family_arm_m3_Hwi_Instance_State__hookEnv hookEnv;
} ti_sysbios_family_arm_m3_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_arm_m3_Hwi_Object__ obj;
} ti_sysbios_family_arm_m3_Hwi_Object2__;

/* __ParamsPtr */
#ifdef ti_sysbios_family_arm_m3_Hwi___VERS
    #define ti_sysbios_family_arm_m3_Hwi___ParamsPtr xdc_UChar*
#else
    #define ti_sysbios_family_arm_m3_Hwi___ParamsPtr xdc_Ptr
#endif


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.arm.m3.TaskSupport INTERNALS ========
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

/* <-- ti_sysbios_family_arm_m3_Hwi_Object */

/* Object */
typedef ti_sysbios_family_arm_m3_Hwi_Object__ ti_sysbios_hal_Hwi_HwiProxy_Object__;

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

/* <-- ti_sysbios_family_arm_ducati_Timer_Object */

/* Object */
typedef ti_sysbios_family_arm_ducati_Timer_Object__ ti_sysbios_hal_Timer_TimerProxy_Object__;

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
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport INHERITS ========
 */

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {0};
__FAR__ const xdc_runtime_Types_Base ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C = {(void*)&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== ti.sysbios.gates.GateHwi INHERITS ========
 */

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
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport VTABLE ========
 */

/* Module__FXNS__C */
const ti_sysbios_family_arm_m3_IntrinsicsSupport_Fxns__ ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C = {
    (void*)&ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C, /* base__ */
    &ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_family_arm_m3_IntrinsicsSupport_maxbit__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x8021, /* __mid */
    } /* __sfxns */
};


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
        0x8028, /* __mid */
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
        0x8029, /* __mid */
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
        0x802e, /* __mid */
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
 * ======== ti.sysbios.family.arm.ducati.CTM DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.Core DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.arm.ducati.Timer DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_family_arm_ducati_Timer_Object__ ti_sysbios_family_arm_ducati_Timer_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_family_arm_ducati_Timer_Module_State__ {
    xdc_UInt availMask;
    __TA_ti_sysbios_family_arm_ducati_Timer_Module_State__handles handles;
} ti_sysbios_family_arm_ducati_Timer_Module_State__;

/* Module__state__V */
ti_sysbios_family_arm_ducati_Timer_Module_State__ ti_sysbios_family_arm_ducati_Timer_Module__state__V;


/*
 * ======== ti.sysbios.family.arm.m3.Hwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_family_arm_m3_Hwi_Object__ ti_sysbios_family_arm_m3_Hwi_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_family_arm_m3_Hwi_Module_State__ {
    xdc_Bits16 enables;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__iser iser;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__priorities priorities;
    xdc_Char* taskSP;
    xdc_Bool excActive;
    ti_sysbios_family_arm_m3_Hwi_ExcContext* excContext;
    xdc_Ptr excStack;
    xdc_Ptr isrStack;
    xdc_Ptr isrStackBase;
    xdc_SizeT isrStackSize;
    xdc_Ptr vectorTableBase;
    __TA_ti_sysbios_family_arm_m3_Hwi_Module_State__dispatchTable dispatchTable;
} ti_sysbios_family_arm_m3_Hwi_Module_State__;

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_priorities__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__priorities ti_sysbios_family_arm_m3_Hwi_Module_State_0_priorities__A[80];

/* --> __TI_STACK_BASE */
extern void* __TI_STACK_BASE;

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_dispatchTable__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__dispatchTable ti_sysbios_family_arm_m3_Hwi_Module_State_0_dispatchTable__A[80];

/* Module__state__V */
ti_sysbios_family_arm_m3_Hwi_Module_State__ ti_sysbios_family_arm_m3_Hwi_Module__state__V;

/* --> ti_sysbios_knl_Swi_disable__E */
extern xdc_UInt ti_sysbios_knl_Swi_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Swi_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Swi_restoreHwi__E(xdc_UInt);

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Task_restoreHwi__E(xdc_UInt);


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.arm.m3.TaskSupport DECLARATIONS ========
 */


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
    #pragma DATA_SECTION(ti_sysbios_knl_Task_Instance_State_0_stack__A, ".bss:taskStackSection");
#endif
#ifdef __GNUC__
#if __GNUC__ >= 4
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[2048] __attribute__ ((section(".bss:taskStackSection")));
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
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[3];

/* --> xdc_runtime_Startup_lastFxns__A */
const __T1_xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__A[1];

/* --> xdc_runtime_System_Module_startup__E */
extern xdc_Int xdc_runtime_System_Module_startup__E(xdc_Int);

/* --> xdc_runtime_SysMin_Module_startup__E */
extern xdc_Int xdc_runtime_SysMin_Module_startup__E(xdc_Int);

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

/* --> ti_sysbios_family_arm_m3_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_family_arm_m3_Hwi_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_arm_ducati_Core_Module_startup__E */
extern xdc_Int ti_sysbios_family_arm_ducati_Core_Module_startup__E(xdc_Int);

/* --> ti_sysbios_family_arm_ducati_Timer_Module_startup__E */
extern xdc_Int ti_sysbios_family_arm_ducati_Timer_Module_startup__E(xdc_Int);

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[10];

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[10];


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
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[7007];

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[47];


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
xdc__META(__ASM__, "@(#)__ASM__ = /db/vtree/library/trees/ipc/ipc-h27/src/ti/sdo/ipc/package/cfg/instrumented_pem3");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = v7M");

/*
 *  ======== __PLAT__ ========
 *  Define the name of the platform that can run this executable.  This
 *  symbol is used by platform independent "exec" commands
 */
xdc__META(__PLAT__, "@(#)__PLAT__ = ti.sdo.ipc.examples.platforms.evmTI816X.video");

/*
 *  ======== __TARG__ ========
 *  Define the name of the target used to build this executable.
 */
xdc__META(__TARG__, "@(#)__TARG__ = ti.targets.arm.elf.M3");

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
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[2] < 0;
}
xdc_Bool ti_sysbios_hal_Timer_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[3] < 0;
}
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[4] < 0;
}
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[5] < 0;
}
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[6] < 0;
}
xdc_Bool ti_sysbios_family_arm_m3_Hwi_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[7] < 0;
}
xdc_Bool ti_sysbios_family_arm_ducati_Core_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[8] < 0;
}
xdc_Bool ti_sysbios_family_arm_ducati_Timer_Module__startupDone__F(void) {
    return (&xdc_runtime_Startup_Module__state__V)->stateTab == 0 || (&xdc_runtime_Startup_Module__state__V)->stateTab[9] < 0;
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
    xdc_Int state[10];
    xdc_runtime_Startup_startModsFxn__C(state, 10);
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
 * ======== ti.sysbios.family.arm.m3.Hwi TEMPLATE ========
 */

extern Void _c_int00();

#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_resetVectors, ".resetVecs");

/* const because it is meant to be placed in ROM */
const UInt32 ti_sysbios_family_arm_m3_Hwi_resetVectors[] = {
    (UInt32)(&__TI_STACK_BASE),
    (UInt32)(&_c_int00),
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),            /* NMI */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),      /* Hard Fault */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* Mem Fault */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* Bus Fault */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),     /* Usage Fault */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),         /* SVCall */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* Debug Mon */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),       /* reserved */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_pendSV__I),  /* pendSV */
    (UInt32)(ti_sysbios_family_arm_m3_Hwi_dispatch__I),  /* intNum = 15 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 16 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 17 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 18 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 19 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 20 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 21 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 22 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 23 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 24 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 25 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 26 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 27 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 28 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 29 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 30 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 31 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 32 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 33 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 34 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 35 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 36 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 37 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 38 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 39 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 40 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 41 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 42 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 43 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 44 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 45 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 46 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 47 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 48 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 49 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 50 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 51 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 52 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 53 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 54 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 55 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 56 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 57 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 58 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 59 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 60 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 61 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 62 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 63 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 64 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 65 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 66 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 67 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 68 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 69 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 70 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 71 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 72 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 73 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 74 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 75 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 76 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 77 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 78 */
    (UInt32)(&ti_sysbios_family_arm_m3_Hwi_excHandlerAsm__I),  /* intNum = 79 */
};


#define Hwi_nvic ti_sysbios_family_arm_m3_Hwi_nvic

/*
 *  ======== Hwi_disableInterrupt ========
 */
UInt ti_sysbios_family_arm_m3_Hwi_disableInterrupt__E(UInt intNum)
{
    UInt oldEnableState, index, mask;

    if (intNum >= 16) {

	index = (intNum-16) >> 5;

	mask = 1 << ((intNum-16) & 0x1f);

	oldEnableState = Hwi_nvic.ISER[index] & mask;

	Hwi_nvic.ICER[index] = mask;
    }
    else if (intNum == 15) {
	oldEnableState = Hwi_nvic.STCSR & 0x00000002;
	Hwi_nvic.STCSR &= ~0x00000002;  /* disable SysTick Int */
    }

    return oldEnableState;
}

/*
 *  ======== Hwi_enableInterrupt ========
 */
UInt ti_sysbios_family_arm_m3_Hwi_enableInterrupt__E(UInt intNum)
{
    UInt oldEnableState, index, mask;

    if (intNum >= 16) {

	index = (intNum-16) >> 5;

	mask = 1 << ((intNum-16) & 0x1f);

	oldEnableState = Hwi_nvic.ISER[index] & mask;

	Hwi_nvic.ISER[index] = mask;
    }
    else if (intNum == 15) {
	oldEnableState = Hwi_nvic.STCSR & 0x00000002;
	Hwi_nvic.STCSR |= 0x00000002;   /* enable SysTick Int */
    }

    return oldEnableState;
}

/*
 *  ======== Hwi_restoreInterrupt ========
 */
Void ti_sysbios_family_arm_m3_Hwi_restoreInterrupt__E(UInt intNum, UInt key)
{
    UInt index, mask;

    if (intNum >= 16) {

	index = (intNum-16) >> 5;

	mask = 1 << ((intNum-16) & 0x1f);

	if (key) {
	    Hwi_nvic.ISER[index] = mask;
	}
	else {
	    Hwi_nvic.ICER[index] = mask;
	}
    }
    else if (intNum == 15) {
	if (key) {
	    Hwi_nvic.STCSR |= 0x00000002;       /* enable SysTick Int */
	}
	else {
	    Hwi_nvic.STCSR &= ~0x00000002;      /* disable SysTick Int */
	}
    }
}
#undef Hwi_nvic

/*
 * ======== ti.sdo.utils.Build TEMPLATE ========
 */



/*
 * ======== ti.sdo.ipc.Build TEMPLATE ========
 */



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
__FAR__ const CT__ti_sdo_utils_NameServerRemoteNull_Module__id ti_sdo_utils_NameServerRemoteNull_Module__id__C = (xdc_Bits16)0x802c;

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
        (xdc_Bits32)0xee6b280,  /* lo */
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
__FAR__ const CT__ti_sysbios_BIOS_Module__id ti_sysbios_BIOS_Module__id__C = (xdc_Bits16)0x801c;

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
    (xdc_Bits32)0xee6b280,  /* lo */
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
 * ======== ti.sysbios.family.arm.ducati.CTM INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__diagsEnabled ti_sysbios_family_arm_ducati_CTM_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__diagsIncluded ti_sysbios_family_arm_ducati_CTM_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__diagsMask ti_sysbios_family_arm_ducati_CTM_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__gateObj ti_sysbios_family_arm_ducati_CTM_Module__gateObj__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__gatePrms ti_sysbios_family_arm_ducati_CTM_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__id ti_sysbios_family_arm_ducati_CTM_Module__id__C = (xdc_Bits16)0x8025;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerDefined ti_sysbios_family_arm_ducati_CTM_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerObj ti_sysbios_family_arm_ducati_CTM_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8 ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Object__count ti_sysbios_family_arm_ducati_CTM_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Object__heap ti_sysbios_family_arm_ducati_CTM_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Object__sizeof ti_sysbios_family_arm_ducati_CTM_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_CTM_Object__table ti_sysbios_family_arm_ducati_CTM_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.arm.ducati.Core INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__diagsEnabled ti_sysbios_family_arm_ducati_Core_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__diagsIncluded ti_sysbios_family_arm_ducati_Core_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__diagsMask ti_sysbios_family_arm_ducati_Core_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__gateObj ti_sysbios_family_arm_ducati_Core_Module__gateObj__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__gatePrms ti_sysbios_family_arm_ducati_Core_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__id ti_sysbios_family_arm_ducati_Core_Module__id__C = (xdc_Bits16)0x8024;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerDefined ti_sysbios_family_arm_ducati_Core_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerObj ti_sysbios_family_arm_ducati_Core_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8 ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Object__count ti_sysbios_family_arm_ducati_Core_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Object__heap ti_sysbios_family_arm_ducati_Core_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Object__sizeof ti_sysbios_family_arm_ducati_Core_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_Object__table ti_sysbios_family_arm_ducati_Core_Object__table__C = 0;

/* id__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_id ti_sysbios_family_arm_ducati_Core_id__C = (xdc_UInt)0x0;

/* E_mismatchedIds__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Core_E_mismatchedIds ti_sysbios_family_arm_ducati_Core_E_mismatchedIds__C = (((xdc_runtime_Error_Id)5101) << 16 | 0);


/*
 * ======== ti.sysbios.family.arm.ducati.Timer INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_ducati_Timer_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_family_arm_ducati_Timer_Params ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_arm_ducati_Timer_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)0),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    ((ti_sysbios_family_arm_m3_Hwi_Params*)0),  /* hwiParams */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_arm_ducati_Timer_Module__ ti_sysbios_family_arm_ducati_Timer_Module__root__V = {
    {&ti_sysbios_family_arm_ducati_Timer_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_arm_ducati_Timer_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_arm_ducati_Timer_Object__ ti_sysbios_family_arm_ducati_Timer_Object__table__V[1] = {
    {/* instance#0 */
        0,
        1,  /* staticInst */
        (xdc_Int)0x0,  /* id */
        (xdc_Int)0x0,  /* ctmid */
        ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
        ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
        (xdc_UInt)0x3d090,  /* period */
        ti_sysbios_interfaces_ITimer_PeriodType_COUNTS,  /* periodType */
        (xdc_UInt)0xf,  /* intNum */
        ((xdc_UArg)0),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_knl_Clock_doTick__I)),  /* tickFxn */
        {
            (xdc_Bits32)0x0,  /* hi */
            (xdc_Bits32)0x0,  /* lo */
        },  /* extFreq */
        (ti_sysbios_family_arm_m3_Hwi_Handle)&ti_sysbios_family_arm_m3_Hwi_Object__table__V[0],  /* hwi */
    },
};

/* Module__state__V */
ti_sysbios_family_arm_ducati_Timer_Module_State__ ti_sysbios_family_arm_ducati_Timer_Module__state__V = {
    (xdc_UInt)0x2,  /* availMask */
    {
        (ti_sysbios_family_arm_ducati_Timer_Handle)&ti_sysbios_family_arm_ducati_Timer_Object__table__V[0],  /* [0] */
        0,  /* [1] */
    },  /* handles */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__diagsMask ti_sysbios_family_arm_ducati_Timer_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__gateObj ti_sysbios_family_arm_ducati_Timer_Module__gateObj__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__gatePrms ti_sysbios_family_arm_ducati_Timer_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__id ti_sysbios_family_arm_ducati_Timer_Module__id__C = (xdc_Bits16)0x8026;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerObj ti_sysbios_family_arm_ducati_Timer_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Object__count ti_sysbios_family_arm_ducati_Timer_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Object__heap ti_sysbios_family_arm_ducati_Timer_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Object__sizeof ti_sysbios_family_arm_ducati_Timer_Object__sizeof__C = sizeof(ti_sysbios_family_arm_ducati_Timer_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_Object__table ti_sysbios_family_arm_ducati_Timer_Object__table__C = ti_sysbios_family_arm_ducati_Timer_Object__table__V;

/* E_invalidTimer__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_E_invalidTimer ti_sysbios_family_arm_ducati_Timer_E_invalidTimer__C = (((xdc_runtime_Error_Id)4968) << 16 | 0);

/* E_notAvailable__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_E_notAvailable ti_sysbios_family_arm_ducati_Timer_E_notAvailable__C = (((xdc_runtime_Error_Id)5004) << 16 | 0);

/* E_cannotSupport__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_E_cannotSupport ti_sysbios_family_arm_ducati_Timer_E_cannotSupport__C = (((xdc_runtime_Error_Id)5043) << 16 | 0);

/* anyMask__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_anyMask ti_sysbios_family_arm_ducati_Timer_anyMask__C = (xdc_UInt)0x3;

/* startupNeeded__C */
__FAR__ const CT__ti_sysbios_family_arm_ducati_Timer_startupNeeded ti_sysbios_family_arm_ducati_Timer_startupNeeded__C = (xdc_UInt)0x1;


/*
 * ======== ti.sysbios.family.arm.m3.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_m3_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
__FAR__ const ti_sysbios_family_arm_m3_Hwi_Params ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_arm_m3_Hwi_Params), /* __size */
    0, /* __self */
    0, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_LOWER,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)0xff,  /* priority */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_arm_m3_Hwi_Module__ ti_sysbios_family_arm_m3_Hwi_Module__root__V = {
    {&ti_sysbios_family_arm_m3_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_arm_m3_Hwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_arm_m3_Hwi_Object__ ti_sysbios_family_arm_m3_Hwi_Object__table__V[1] = {
    {/* instance#0 */
        0,
        ((xdc_UArg)((void*)(ti_sysbios_family_arm_ducati_Timer_Handle)&ti_sysbios_family_arm_ducati_Timer_Object__table__V[0])),  /* arg */
        ((xdc_Void(*)(xdc_UArg))((xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_periodicStub__E)),  /* fxn */
        (xdc_Int)0xf,  /* intNum */
        ((xdc_UArg)0),  /* irp */
        ((void*)0),  /* hookEnv */
    },
};

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_priorities__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__priorities ti_sysbios_family_arm_m3_Hwi_Module_State_0_priorities__A[80] = {
    (xdc_UInt8)0x0,  /* [0] */
    (xdc_UInt8)0x0,  /* [1] */
    (xdc_UInt8)0x0,  /* [2] */
    (xdc_UInt8)0x0,  /* [3] */
    (xdc_UInt8)0x0,  /* [4] */
    (xdc_UInt8)0x0,  /* [5] */
    (xdc_UInt8)0x0,  /* [6] */
    (xdc_UInt8)0x0,  /* [7] */
    (xdc_UInt8)0x0,  /* [8] */
    (xdc_UInt8)0x0,  /* [9] */
    (xdc_UInt8)0x0,  /* [10] */
    (xdc_UInt8)0x0,  /* [11] */
    (xdc_UInt8)0x0,  /* [12] */
    (xdc_UInt8)0x0,  /* [13] */
    (xdc_UInt8)0x0,  /* [14] */
    (xdc_UInt8)0xff,  /* [15] */
    (xdc_UInt8)0xff,  /* [16] */
    (xdc_UInt8)0xff,  /* [17] */
    (xdc_UInt8)0xff,  /* [18] */
    (xdc_UInt8)0xff,  /* [19] */
    (xdc_UInt8)0xff,  /* [20] */
    (xdc_UInt8)0xff,  /* [21] */
    (xdc_UInt8)0xff,  /* [22] */
    (xdc_UInt8)0xff,  /* [23] */
    (xdc_UInt8)0xff,  /* [24] */
    (xdc_UInt8)0xff,  /* [25] */
    (xdc_UInt8)0xff,  /* [26] */
    (xdc_UInt8)0xff,  /* [27] */
    (xdc_UInt8)0xff,  /* [28] */
    (xdc_UInt8)0xff,  /* [29] */
    (xdc_UInt8)0xff,  /* [30] */
    (xdc_UInt8)0xff,  /* [31] */
    (xdc_UInt8)0xff,  /* [32] */
    (xdc_UInt8)0xff,  /* [33] */
    (xdc_UInt8)0xff,  /* [34] */
    (xdc_UInt8)0xff,  /* [35] */
    (xdc_UInt8)0xff,  /* [36] */
    (xdc_UInt8)0xff,  /* [37] */
    (xdc_UInt8)0xff,  /* [38] */
    (xdc_UInt8)0xff,  /* [39] */
    (xdc_UInt8)0xff,  /* [40] */
    (xdc_UInt8)0xff,  /* [41] */
    (xdc_UInt8)0xff,  /* [42] */
    (xdc_UInt8)0xff,  /* [43] */
    (xdc_UInt8)0xff,  /* [44] */
    (xdc_UInt8)0xff,  /* [45] */
    (xdc_UInt8)0xff,  /* [46] */
    (xdc_UInt8)0xff,  /* [47] */
    (xdc_UInt8)0xff,  /* [48] */
    (xdc_UInt8)0xff,  /* [49] */
    (xdc_UInt8)0xff,  /* [50] */
    (xdc_UInt8)0xff,  /* [51] */
    (xdc_UInt8)0xff,  /* [52] */
    (xdc_UInt8)0xff,  /* [53] */
    (xdc_UInt8)0xff,  /* [54] */
    (xdc_UInt8)0xff,  /* [55] */
    (xdc_UInt8)0xff,  /* [56] */
    (xdc_UInt8)0xff,  /* [57] */
    (xdc_UInt8)0xff,  /* [58] */
    (xdc_UInt8)0xff,  /* [59] */
    (xdc_UInt8)0xff,  /* [60] */
    (xdc_UInt8)0xff,  /* [61] */
    (xdc_UInt8)0xff,  /* [62] */
    (xdc_UInt8)0xff,  /* [63] */
    (xdc_UInt8)0xff,  /* [64] */
    (xdc_UInt8)0xff,  /* [65] */
    (xdc_UInt8)0xff,  /* [66] */
    (xdc_UInt8)0xff,  /* [67] */
    (xdc_UInt8)0xff,  /* [68] */
    (xdc_UInt8)0xff,  /* [69] */
    (xdc_UInt8)0xff,  /* [70] */
    (xdc_UInt8)0xff,  /* [71] */
    (xdc_UInt8)0xff,  /* [72] */
    (xdc_UInt8)0xff,  /* [73] */
    (xdc_UInt8)0xff,  /* [74] */
    (xdc_UInt8)0xff,  /* [75] */
    (xdc_UInt8)0xff,  /* [76] */
    (xdc_UInt8)0xff,  /* [77] */
    (xdc_UInt8)0xff,  /* [78] */
    (xdc_UInt8)0xff,  /* [79] */
};

/* --> ti_sysbios_family_arm_m3_Hwi_Module_State_0_dispatchTable__A */
__T1_ti_sysbios_family_arm_m3_Hwi_Module_State__dispatchTable ti_sysbios_family_arm_m3_Hwi_Module_State_0_dispatchTable__A[80] = {
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
    0,  /* [14] */
    (ti_sysbios_family_arm_m3_Hwi_Handle)&ti_sysbios_family_arm_m3_Hwi_Object__table__V[0],  /* [15] */
    0,  /* [16] */
    0,  /* [17] */
    0,  /* [18] */
    0,  /* [19] */
    0,  /* [20] */
    0,  /* [21] */
    0,  /* [22] */
    0,  /* [23] */
    0,  /* [24] */
    0,  /* [25] */
    0,  /* [26] */
    0,  /* [27] */
    0,  /* [28] */
    0,  /* [29] */
    0,  /* [30] */
    0,  /* [31] */
    0,  /* [32] */
    0,  /* [33] */
    0,  /* [34] */
    0,  /* [35] */
    0,  /* [36] */
    0,  /* [37] */
    0,  /* [38] */
    0,  /* [39] */
    0,  /* [40] */
    0,  /* [41] */
    0,  /* [42] */
    0,  /* [43] */
    0,  /* [44] */
    0,  /* [45] */
    0,  /* [46] */
    0,  /* [47] */
    0,  /* [48] */
    0,  /* [49] */
    0,  /* [50] */
    0,  /* [51] */
    0,  /* [52] */
    0,  /* [53] */
    0,  /* [54] */
    0,  /* [55] */
    0,  /* [56] */
    0,  /* [57] */
    0,  /* [58] */
    0,  /* [59] */
    0,  /* [60] */
    0,  /* [61] */
    0,  /* [62] */
    0,  /* [63] */
    0,  /* [64] */
    0,  /* [65] */
    0,  /* [66] */
    0,  /* [67] */
    0,  /* [68] */
    0,  /* [69] */
    0,  /* [70] */
    0,  /* [71] */
    0,  /* [72] */
    0,  /* [73] */
    0,  /* [74] */
    0,  /* [75] */
    0,  /* [76] */
    0,  /* [77] */
    0,  /* [78] */
    0,  /* [79] */
};

/* Module__state__V */
ti_sysbios_family_arm_m3_Hwi_Module_State__ ti_sysbios_family_arm_m3_Hwi_Module__state__V = {
    (xdc_Bits16)0x8000,  /* enables */
    {
        (xdc_Bits32)0x0,  /* [0] */
        (xdc_Bits32)0x0,  /* [1] */
        (xdc_Bits32)0x0,  /* [2] */
        (xdc_Bits32)0x0,  /* [3] */
        (xdc_Bits32)0x0,  /* [4] */
        (xdc_Bits32)0x0,  /* [5] */
        (xdc_Bits32)0x0,  /* [6] */
        (xdc_Bits32)0x0,  /* [7] */
    },  /* iser */
    ((void*)ti_sysbios_family_arm_m3_Hwi_Module_State_0_priorities__A),  /* priorities */
    ((xdc_Char*)0),  /* taskSP */
    0,  /* excActive */
    ((ti_sysbios_family_arm_m3_Hwi_ExcContext*)0),  /* excContext */
    ((xdc_Ptr)0),  /* excStack */
    ((xdc_Ptr)0),  /* isrStack */
    ((xdc_Ptr)((void*)&__TI_STACK_BASE)),  /* isrStackBase */
    (xdc_SizeT)0x1000,  /* isrStackSize */
    ((xdc_Ptr)(0x400)),  /* vectorTableBase */
    ((void*)ti_sysbios_family_arm_m3_Hwi_Module_State_0_dispatchTable__A),  /* dispatchTable */
};

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsMask ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__gateObj ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__gatePrms ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__id ti_sysbios_family_arm_m3_Hwi_Module__id__C = (xdc_Bits16)0x8020;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerObj ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__count ti_sysbios_family_arm_m3_Hwi_Object__count__C = 1;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__heap ti_sysbios_family_arm_m3_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__sizeof ti_sysbios_family_arm_m3_Hwi_Object__sizeof__C = sizeof(ti_sysbios_family_arm_m3_Hwi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_Object__table ti_sysbios_family_arm_m3_Hwi_Object__table__C = ti_sysbios_family_arm_m3_Hwi_Object__table__V;

/* dispatcherAutoNestingSupport__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* NUM_INTERRUPTS__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__C = (xdc_Int)0x50;

/* NUM_PRIORITIES__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__C = (xdc_Int)0x10;

/* LM_begin__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_LM_begin ti_sysbios_family_arm_m3_Hwi_LM_begin__C = (((xdc_runtime_Log_Event)6569) << 16 | 768);

/* LD_end__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_LD_end ti_sysbios_family_arm_m3_Hwi_LD_end__C = (((xdc_runtime_Log_Event)6639) << 16 | 512);

/* A_unsupportedMaskingOption__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption__C = (((xdc_runtime_Assert_Id)1307) << 16 | 16);

/* E_alreadyDefined__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined__C = (((xdc_runtime_Error_Id)4560) << 16 | 0);

/* E_exception__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_exception ti_sysbios_family_arm_m3_Hwi_E_exception__C = (((xdc_runtime_Error_Id)4608) << 16 | 0);

/* E_noIsr__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_noIsr ti_sysbios_family_arm_m3_Hwi_E_noIsr__C = (((xdc_runtime_Error_Id)4813) << 16 | 0);

/* E_NMI__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_NMI ti_sysbios_family_arm_m3_Hwi_E_NMI__C = (((xdc_runtime_Error_Id)4841) << 16 | 0);

/* E_hardFault__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_hardFault ti_sysbios_family_arm_m3_Hwi_E_hardFault__C = (((xdc_runtime_Error_Id)4851) << 16 | 0);

/* E_memFault__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_memFault ti_sysbios_family_arm_m3_Hwi_E_memFault__C = (((xdc_runtime_Error_Id)4867) << 16 | 0);

/* E_busFault__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_busFault ti_sysbios_family_arm_m3_Hwi_E_busFault__C = (((xdc_runtime_Error_Id)4882) << 16 | 0);

/* E_usageFault__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_usageFault ti_sysbios_family_arm_m3_Hwi_E_usageFault__C = (((xdc_runtime_Error_Id)4897) << 16 | 0);

/* E_svCall__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_svCall ti_sysbios_family_arm_m3_Hwi_E_svCall__C = (((xdc_runtime_Error_Id)4914) << 16 | 0);

/* E_debugMon__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_debugMon ti_sysbios_family_arm_m3_Hwi_E_debugMon__C = (((xdc_runtime_Error_Id)4935) << 16 | 0);

/* E_reserved__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_E_reserved ti_sysbios_family_arm_m3_Hwi_E_reserved__C = (((xdc_runtime_Error_Id)4950) << 16 | 0);

/* excHookFunc__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_excHookFunc ti_sysbios_family_arm_m3_Hwi_excHookFunc__C = ((CT__ti_sysbios_family_arm_m3_Hwi_excHookFunc)0);

/* disablePriority__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_disablePriority ti_sysbios_family_arm_m3_Hwi_disablePriority__C = (xdc_UInt)0x10;

/* priGroup__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_priGroup ti_sysbios_family_arm_m3_Hwi_priGroup__C = (xdc_UInt)0x0;

/* swiDisable__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_swiDisable ti_sysbios_family_arm_m3_Hwi_swiDisable__C = ((CT__ti_sysbios_family_arm_m3_Hwi_swiDisable)((xdc_Fxn)ti_sysbios_knl_Swi_disable__E));

/* swiRestoreHwi__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi__C = ((CT__ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Swi_restoreHwi__E));

/* taskDisable__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_taskDisable ti_sysbios_family_arm_m3_Hwi_taskDisable__C = ((CT__ti_sysbios_family_arm_m3_Hwi_taskDisable)((xdc_Fxn)ti_sysbios_knl_Task_disable__E));

/* taskRestoreHwi__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi__C = ((CT__ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi)((xdc_Fxn)ti_sysbios_knl_Task_restoreHwi__E));

/* ccr__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_ccr ti_sysbios_family_arm_m3_Hwi_ccr__C = (xdc_UInt32)0x200;

/* hooks__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_hooks ti_sysbios_family_arm_m3_Hwi_hooks__C = {0, 0};

/* excHandlerFunc__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_Hwi_excHandlerFunc ti_sysbios_family_arm_m3_Hwi_excHandlerFunc__C = ((CT__ti_sysbios_family_arm_m3_Hwi_excHandlerFunc)((xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_excHandlerMax__I));


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsEnabled ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsIncluded ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__id ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__id__C = (xdc_Bits16)0x8021;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerDefined ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8 ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__count ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__heap ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__sizeof ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__table ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__table__C = 0;


/*
 * ======== ti.sysbios.family.arm.m3.TaskSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__diagsEnabled ti_sysbios_family_arm_m3_TaskSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__diagsIncluded ti_sysbios_family_arm_m3_TaskSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask)0);

/* Module__gateObj__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj)0);

/* Module__gatePrms__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms)0);

/* Module__id__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__id ti_sysbios_family_arm_m3_TaskSupport_Module__id__C = (xdc_Bits16)0x8022;

/* Module__loggerDefined__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerDefined ti_sysbios_family_arm_m3_TaskSupport_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj)0);

/* Module__loggerFxn0__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0)0);

/* Module__loggerFxn1__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1)0);

/* Module__loggerFxn2__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2)0);

/* Module__loggerFxn4__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4)0);

/* Module__loggerFxn8__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8 ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8)0);

/* Module__startupDoneFxn__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn__C = ((CT__ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn)0);

/* Object__count__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Object__count ti_sysbios_family_arm_m3_TaskSupport_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Object__heap ti_sysbios_family_arm_m3_TaskSupport_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Object__sizeof ti_sysbios_family_arm_m3_TaskSupport_Object__sizeof__C = 0;

/* Object__table__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_Object__table ti_sysbios_family_arm_m3_TaskSupport_Object__table__C = 0;

/* defaultStackSize__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_defaultStackSize ti_sysbios_family_arm_m3_TaskSupport_defaultStackSize__C = (xdc_SizeT)0x800;

/* stackAlignment__C */
__FAR__ const CT__ti_sysbios_family_arm_m3_TaskSupport_stackAlignment ti_sysbios_family_arm_m3_TaskSupport_stackAlignment__C = (xdc_UInt)0x8;


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
__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__id ti_sysbios_gates_GateHwi_Module__id__C = (xdc_Bits16)0x8028;

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
__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__id ti_sysbios_gates_GateMutex_Module__id__C = (xdc_Bits16)0x8029;

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
__FAR__ const CT__ti_sysbios_gates_GateMutex_A_badContext ti_sysbios_gates_GateMutex_A_badContext__C = (((xdc_runtime_Assert_Id)1662) << 16 | 16);


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
    ti_sysbios_interfaces_IHwi_MaskingOption_LOWER,  /* maskSetting */
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
__FAR__ const CT__ti_sysbios_hal_Hwi_Module__id ti_sysbios_hal_Hwi_Module__id__C = (xdc_Bits16)0x8012;

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
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__count ti_sysbios_hal_Hwi_Object__count__C = 0;

/* Object__heap__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__heap ti_sysbios_hal_Hwi_Object__heap__C = 0;

/* Object__sizeof__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__sizeof ti_sysbios_hal_Hwi_Object__sizeof__C = sizeof(ti_sysbios_hal_Hwi_Object__);

/* Object__table__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_Object__table ti_sysbios_hal_Hwi_Object__table__C = 0;

/* dispatcherAutoNestingSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherSwiSupport ti_sysbios_hal_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherTaskSupport ti_sysbios_hal_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* E_stackOverflow__C */
__FAR__ const CT__ti_sysbios_hal_Hwi_E_stackOverflow ti_sysbios_hal_Hwi_E_stackOverflow__C = (((xdc_runtime_Error_Id)4429) << 16 | 0);


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
        (ti_sysbios_hal_Timer_TimerProxy_Handle)&ti_sysbios_family_arm_ducati_Timer_Object__table__V[0],  /* pi */
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
__FAR__ const CT__ti_sysbios_hal_Timer_Module__id ti_sysbios_hal_Timer_Module__id__C = (xdc_Bits16)0x8013;

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
__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module__id__C = (xdc_Bits16)0x802e;

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
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_zeroBlock ti_sysbios_heaps_HeapMem_A_zeroBlock__C = (((xdc_runtime_Assert_Id)3993) << 16 | 16);

/* A_heapSize__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_heapSize ti_sysbios_heaps_HeapMem_A_heapSize__C = (((xdc_runtime_Assert_Id)4029) << 16 | 16);

/* A_align__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_align ti_sysbios_heaps_HeapMem_A_align__C = (((xdc_runtime_Assert_Id)4074) << 16 | 16);

/* E_memory__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_E_memory ti_sysbios_heaps_HeapMem_E_memory__C = (((xdc_runtime_Error_Id)5786) << 16 | 0);

/* A_invalidFree__C */
__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_invalidFree ti_sysbios_heaps_HeapMem_A_invalidFree__C = (((xdc_runtime_Assert_Id)3965) << 16 | 16);

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
__FAR__ const CT__ti_sysbios_knl_Clock_Module__id ti_sysbios_knl_Clock_Module__id__C = (xdc_Bits16)0x8015;

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
__FAR__ const CT__ti_sysbios_knl_Clock_LW_delayed ti_sysbios_knl_Clock_LW_delayed__C = (((xdc_runtime_Log_Event)5998) << 16 | 1024);

/* LM_tick__C */
__FAR__ const CT__ti_sysbios_knl_Clock_LM_tick ti_sysbios_knl_Clock_LM_tick__C = (((xdc_runtime_Log_Event)6020) << 16 | 768);

/* LM_begin__C */
__FAR__ const CT__ti_sysbios_knl_Clock_LM_begin ti_sysbios_knl_Clock_LM_begin__C = (((xdc_runtime_Log_Event)6038) << 16 | 768);

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
__FAR__ const CT__ti_sysbios_knl_Idle_Module__id ti_sysbios_knl_Idle_Module__id__C = (xdc_Bits16)0x8016;

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
__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__id ti_sysbios_knl_Intrinsics_Module__id__C = (xdc_Bits16)0x8017;

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
__FAR__ const CT__ti_sysbios_knl_Queue_Module__id ti_sysbios_knl_Queue_Module__id__C = (xdc_Bits16)0x8018;

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
__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__id ti_sysbios_knl_Semaphore_Module__id__C = (xdc_Bits16)0x8019;

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
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_post ti_sysbios_knl_Semaphore_LM_post__C = (((xdc_runtime_Log_Event)6070) << 16 | 768);

/* LM_pend__C */
__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_pend ti_sysbios_knl_Semaphore_LM_pend__C = (((xdc_runtime_Log_Event)6100) << 16 | 768);

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
__FAR__ const CT__ti_sysbios_knl_Swi_Module__id ti_sysbios_knl_Swi_Module__id__C = (xdc_Bits16)0x801a;

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
__FAR__ const CT__ti_sysbios_knl_Swi_LM_begin ti_sysbios_knl_Swi_LM_begin__C = (((xdc_runtime_Log_Event)6143) << 16 | 768);

/* LD_end__C */
__FAR__ const CT__ti_sysbios_knl_Swi_LD_end ti_sysbios_knl_Swi_LD_end__C = (((xdc_runtime_Log_Event)6190) << 16 | 512);

/* LM_post__C */
__FAR__ const CT__ti_sysbios_knl_Swi_LM_post ti_sysbios_knl_Swi_LM_post__C = (((xdc_runtime_Log_Event)6208) << 16 | 768);

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
__FAR__ const CT__ti_sysbios_knl_Task_Module__id ti_sysbios_knl_Task_Module__id__C = (xdc_Bits16)0x801b;

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
__FAR__ const CT__ti_sysbios_knl_Task_LM_switch ti_sysbios_knl_Task_LM_switch__C = (((xdc_runtime_Log_Event)6248) << 16 | 768);

/* LM_sleep__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_sleep ti_sysbios_knl_Task_LM_sleep__C = (((xdc_runtime_Log_Event)6316) << 16 | 768);

/* LD_ready__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_ready ti_sysbios_knl_Task_LD_ready__C = (((xdc_runtime_Log_Event)6361) << 16 | 512);

/* LD_block__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_block ti_sysbios_knl_Task_LD_block__C = (((xdc_runtime_Log_Event)6402) << 16 | 512);

/* LM_yield__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_yield ti_sysbios_knl_Task_LM_yield__C = (((xdc_runtime_Log_Event)6434) << 16 | 768);

/* LM_setPri__C */
__FAR__ const CT__ti_sysbios_knl_Task_LM_setPri ti_sysbios_knl_Task_LM_setPri__C = (((xdc_runtime_Log_Event)6482) << 16 | 768);

/* LD_exit__C */
__FAR__ const CT__ti_sysbios_knl_Task_LD_exit ti_sysbios_knl_Task_LD_exit__C = (((xdc_runtime_Log_Event)6538) << 16 | 512);

/* E_stackOverflow__C */
__FAR__ const CT__ti_sysbios_knl_Task_E_stackOverflow ti_sysbios_knl_Task_E_stackOverflow__C = (((xdc_runtime_Error_Id)4466) << 16 | 0);

/* E_spOutOfBounds__C */
__FAR__ const CT__ti_sysbios_knl_Task_E_spOutOfBounds ti_sysbios_knl_Task_E_spOutOfBounds__C = (((xdc_runtime_Error_Id)4509) << 16 | 0);

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
__FAR__ const CT__xdc_runtime_Assert_E_assertFailed xdc_runtime_Assert_E_assertFailed__C = (((xdc_runtime_Error_Id)4189) << 16 | 0);


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
__FAR__ const CT__xdc_runtime_Error_E_generic xdc_runtime_Error_E_generic__C = (((xdc_runtime_Error_Id)4211) << 16 | 0);

/* E_memory__C */
__FAR__ const CT__xdc_runtime_Error_E_memory xdc_runtime_Error_E_memory__C = (((xdc_runtime_Error_Id)4215) << 16 | 0);

/* E_msgCode__C */
__FAR__ const CT__xdc_runtime_Error_E_msgCode xdc_runtime_Error_E_msgCode__C = (((xdc_runtime_Error_Id)4249) << 16 | 0);

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
__FAR__ const CT__xdc_runtime_Log_L_construct xdc_runtime_Log_L_construct__C = (((xdc_runtime_Log_Event)5822) << 16 | 4);

/* L_create__C */
__FAR__ const CT__xdc_runtime_Log_L_create xdc_runtime_Log_L_create__C = (((xdc_runtime_Log_Event)5846) << 16 | 4);

/* L_destruct__C */
__FAR__ const CT__xdc_runtime_Log_L_destruct xdc_runtime_Log_L_destruct__C = (((xdc_runtime_Log_Event)5867) << 16 | 4);

/* L_delete__C */
__FAR__ const CT__xdc_runtime_Log_L_delete xdc_runtime_Log_L_delete__C = (((xdc_runtime_Log_Event)5886) << 16 | 4);

/* L_error__C */
__FAR__ const CT__xdc_runtime_Log_L_error xdc_runtime_Log_L_error__C = (((xdc_runtime_Log_Event)5903) << 16 | 192);

/* L_warning__C */
__FAR__ const CT__xdc_runtime_Log_L_warning xdc_runtime_Log_L_warning__C = (((xdc_runtime_Log_Event)5917) << 16 | 224);

/* L_info__C */
__FAR__ const CT__xdc_runtime_Log_L_info xdc_runtime_Log_L_info__C = (((xdc_runtime_Log_Event)5933) << 16 | 16384);

/* L_start__C */
__FAR__ const CT__xdc_runtime_Log_L_start xdc_runtime_Log_L_start__C = (((xdc_runtime_Log_Event)5940) << 16 | 32768);

/* L_stop__C */
__FAR__ const CT__xdc_runtime_Log_L_stop xdc_runtime_Log_L_stop__C = (((xdc_runtime_Log_Event)5951) << 16 | 32768);

/* L_startInstance__C */
__FAR__ const CT__xdc_runtime_Log_L_startInstance xdc_runtime_Log_L_startInstance__C = (((xdc_runtime_Log_Event)5961) << 16 | 32768);

/* L_stopInstance__C */
__FAR__ const CT__xdc_runtime_Log_L_stopInstance xdc_runtime_Log_L_stopInstance__C = (((xdc_runtime_Log_Event)5980) << 16 | 32768);


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
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[3] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_heaps_HeapMem_init__I)),  /* [0] */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_hal_Hwi_initStack)),  /* [1] */
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_initVTOR__I)),  /* [2] */
};

/* --> xdc_runtime_Startup_lastFxns__A */
const __T1_xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__A[1] = {
    ((xdc_Void(*)(xdc_Void))((xdc_Fxn)xdc_runtime_System_lastFxn__I)),  /* [0] */
};

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[10] = {
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_System_Module_startup__E)),  /* [0] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)xdc_runtime_SysMin_Module_startup__E)),  /* [1] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_hal_Hwi_Module_startup__E)),  /* [2] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_hal_Timer_Module_startup__E)),  /* [3] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Clock_Module_startup__E)),  /* [4] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Swi_Module_startup__E)),  /* [5] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_knl_Task_Module_startup__E)),  /* [6] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Module_startup__E)),  /* [7] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_arm_ducati_Core_Module_startup__E)),  /* [8] */
    ((xdc_Int(*)(xdc_Int))((xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Module_startup__E)),  /* [9] */
};

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[10] = {
    1,  /* [0] */
    1,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
    0,  /* [4] */
    0,  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    0,  /* [8] */
    0,  /* [9] */
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
__FAR__ const CT__xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__C = {3, ((__T1_xdc_runtime_Startup_firstFxns*)xdc_runtime_Startup_firstFxns__A)};

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
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[7007] = {
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
    (xdc_Char)0x75,  /* [1309] */
    (xdc_Char)0x6e,  /* [1310] */
    (xdc_Char)0x73,  /* [1311] */
    (xdc_Char)0x75,  /* [1312] */
    (xdc_Char)0x70,  /* [1313] */
    (xdc_Char)0x70,  /* [1314] */
    (xdc_Char)0x6f,  /* [1315] */
    (xdc_Char)0x72,  /* [1316] */
    (xdc_Char)0x74,  /* [1317] */
    (xdc_Char)0x65,  /* [1318] */
    (xdc_Char)0x64,  /* [1319] */
    (xdc_Char)0x4d,  /* [1320] */
    (xdc_Char)0x61,  /* [1321] */
    (xdc_Char)0x73,  /* [1322] */
    (xdc_Char)0x6b,  /* [1323] */
    (xdc_Char)0x69,  /* [1324] */
    (xdc_Char)0x6e,  /* [1325] */
    (xdc_Char)0x67,  /* [1326] */
    (xdc_Char)0x4f,  /* [1327] */
    (xdc_Char)0x70,  /* [1328] */
    (xdc_Char)0x74,  /* [1329] */
    (xdc_Char)0x69,  /* [1330] */
    (xdc_Char)0x6f,  /* [1331] */
    (xdc_Char)0x6e,  /* [1332] */
    (xdc_Char)0x3a,  /* [1333] */
    (xdc_Char)0x20,  /* [1334] */
    (xdc_Char)0x75,  /* [1335] */
    (xdc_Char)0x6e,  /* [1336] */
    (xdc_Char)0x73,  /* [1337] */
    (xdc_Char)0x75,  /* [1338] */
    (xdc_Char)0x70,  /* [1339] */
    (xdc_Char)0x70,  /* [1340] */
    (xdc_Char)0x6f,  /* [1341] */
    (xdc_Char)0x72,  /* [1342] */
    (xdc_Char)0x74,  /* [1343] */
    (xdc_Char)0x65,  /* [1344] */
    (xdc_Char)0x64,  /* [1345] */
    (xdc_Char)0x20,  /* [1346] */
    (xdc_Char)0x6d,  /* [1347] */
    (xdc_Char)0x61,  /* [1348] */
    (xdc_Char)0x73,  /* [1349] */
    (xdc_Char)0x6b,  /* [1350] */
    (xdc_Char)0x53,  /* [1351] */
    (xdc_Char)0x65,  /* [1352] */
    (xdc_Char)0x74,  /* [1353] */
    (xdc_Char)0x74,  /* [1354] */
    (xdc_Char)0x69,  /* [1355] */
    (xdc_Char)0x6e,  /* [1356] */
    (xdc_Char)0x67,  /* [1357] */
    (xdc_Char)0x2e,  /* [1358] */
    (xdc_Char)0x0,  /* [1359] */
    (xdc_Char)0x41,  /* [1360] */
    (xdc_Char)0x5f,  /* [1361] */
    (xdc_Char)0x6e,  /* [1362] */
    (xdc_Char)0x65,  /* [1363] */
    (xdc_Char)0x73,  /* [1364] */
    (xdc_Char)0x74,  /* [1365] */
    (xdc_Char)0x65,  /* [1366] */
    (xdc_Char)0x64,  /* [1367] */
    (xdc_Char)0x45,  /* [1368] */
    (xdc_Char)0x6e,  /* [1369] */
    (xdc_Char)0x74,  /* [1370] */
    (xdc_Char)0x65,  /* [1371] */
    (xdc_Char)0x72,  /* [1372] */
    (xdc_Char)0x3a,  /* [1373] */
    (xdc_Char)0x20,  /* [1374] */
    (xdc_Char)0x43,  /* [1375] */
    (xdc_Char)0x61,  /* [1376] */
    (xdc_Char)0x6e,  /* [1377] */
    (xdc_Char)0x27,  /* [1378] */
    (xdc_Char)0x74,  /* [1379] */
    (xdc_Char)0x20,  /* [1380] */
    (xdc_Char)0x6e,  /* [1381] */
    (xdc_Char)0x65,  /* [1382] */
    (xdc_Char)0x73,  /* [1383] */
    (xdc_Char)0x74,  /* [1384] */
    (xdc_Char)0x20,  /* [1385] */
    (xdc_Char)0x27,  /* [1386] */
    (xdc_Char)0x65,  /* [1387] */
    (xdc_Char)0x6e,  /* [1388] */
    (xdc_Char)0x74,  /* [1389] */
    (xdc_Char)0x65,  /* [1390] */
    (xdc_Char)0x72,  /* [1391] */
    (xdc_Char)0x27,  /* [1392] */
    (xdc_Char)0x20,  /* [1393] */
    (xdc_Char)0x63,  /* [1394] */
    (xdc_Char)0x61,  /* [1395] */
    (xdc_Char)0x6c,  /* [1396] */
    (xdc_Char)0x6c,  /* [1397] */
    (xdc_Char)0x73,  /* [1398] */
    (xdc_Char)0x2e,  /* [1399] */
    (xdc_Char)0x0,  /* [1400] */
    (xdc_Char)0x41,  /* [1401] */
    (xdc_Char)0x5f,  /* [1402] */
    (xdc_Char)0x62,  /* [1403] */
    (xdc_Char)0x61,  /* [1404] */
    (xdc_Char)0x64,  /* [1405] */
    (xdc_Char)0x43,  /* [1406] */
    (xdc_Char)0x6f,  /* [1407] */
    (xdc_Char)0x6e,  /* [1408] */
    (xdc_Char)0x74,  /* [1409] */
    (xdc_Char)0x65,  /* [1410] */
    (xdc_Char)0x78,  /* [1411] */
    (xdc_Char)0x74,  /* [1412] */
    (xdc_Char)0x3a,  /* [1413] */
    (xdc_Char)0x20,  /* [1414] */
    (xdc_Char)0x62,  /* [1415] */
    (xdc_Char)0x61,  /* [1416] */
    (xdc_Char)0x64,  /* [1417] */
    (xdc_Char)0x20,  /* [1418] */
    (xdc_Char)0x63,  /* [1419] */
    (xdc_Char)0x61,  /* [1420] */
    (xdc_Char)0x6c,  /* [1421] */
    (xdc_Char)0x6c,  /* [1422] */
    (xdc_Char)0x69,  /* [1423] */
    (xdc_Char)0x6e,  /* [1424] */
    (xdc_Char)0x67,  /* [1425] */
    (xdc_Char)0x20,  /* [1426] */
    (xdc_Char)0x63,  /* [1427] */
    (xdc_Char)0x6f,  /* [1428] */
    (xdc_Char)0x6e,  /* [1429] */
    (xdc_Char)0x74,  /* [1430] */
    (xdc_Char)0x65,  /* [1431] */
    (xdc_Char)0x78,  /* [1432] */
    (xdc_Char)0x74,  /* [1433] */
    (xdc_Char)0x2e,  /* [1434] */
    (xdc_Char)0x20,  /* [1435] */
    (xdc_Char)0x4d,  /* [1436] */
    (xdc_Char)0x61,  /* [1437] */
    (xdc_Char)0x79,  /* [1438] */
    (xdc_Char)0x20,  /* [1439] */
    (xdc_Char)0x6e,  /* [1440] */
    (xdc_Char)0x6f,  /* [1441] */
    (xdc_Char)0x74,  /* [1442] */
    (xdc_Char)0x20,  /* [1443] */
    (xdc_Char)0x62,  /* [1444] */
    (xdc_Char)0x65,  /* [1445] */
    (xdc_Char)0x20,  /* [1446] */
    (xdc_Char)0x65,  /* [1447] */
    (xdc_Char)0x6e,  /* [1448] */
    (xdc_Char)0x74,  /* [1449] */
    (xdc_Char)0x65,  /* [1450] */
    (xdc_Char)0x72,  /* [1451] */
    (xdc_Char)0x65,  /* [1452] */
    (xdc_Char)0x64,  /* [1453] */
    (xdc_Char)0x20,  /* [1454] */
    (xdc_Char)0x66,  /* [1455] */
    (xdc_Char)0x72,  /* [1456] */
    (xdc_Char)0x6f,  /* [1457] */
    (xdc_Char)0x6d,  /* [1458] */
    (xdc_Char)0x20,  /* [1459] */
    (xdc_Char)0x61,  /* [1460] */
    (xdc_Char)0x20,  /* [1461] */
    (xdc_Char)0x68,  /* [1462] */
    (xdc_Char)0x61,  /* [1463] */
    (xdc_Char)0x72,  /* [1464] */
    (xdc_Char)0x64,  /* [1465] */
    (xdc_Char)0x77,  /* [1466] */
    (xdc_Char)0x61,  /* [1467] */
    (xdc_Char)0x72,  /* [1468] */
    (xdc_Char)0x65,  /* [1469] */
    (xdc_Char)0x20,  /* [1470] */
    (xdc_Char)0x69,  /* [1471] */
    (xdc_Char)0x6e,  /* [1472] */
    (xdc_Char)0x74,  /* [1473] */
    (xdc_Char)0x65,  /* [1474] */
    (xdc_Char)0x72,  /* [1475] */
    (xdc_Char)0x72,  /* [1476] */
    (xdc_Char)0x75,  /* [1477] */
    (xdc_Char)0x70,  /* [1478] */
    (xdc_Char)0x74,  /* [1479] */
    (xdc_Char)0x20,  /* [1480] */
    (xdc_Char)0x74,  /* [1481] */
    (xdc_Char)0x68,  /* [1482] */
    (xdc_Char)0x72,  /* [1483] */
    (xdc_Char)0x65,  /* [1484] */
    (xdc_Char)0x61,  /* [1485] */
    (xdc_Char)0x64,  /* [1486] */
    (xdc_Char)0x2e,  /* [1487] */
    (xdc_Char)0x0,  /* [1488] */
    (xdc_Char)0x41,  /* [1489] */
    (xdc_Char)0x5f,  /* [1490] */
    (xdc_Char)0x62,  /* [1491] */
    (xdc_Char)0x61,  /* [1492] */
    (xdc_Char)0x64,  /* [1493] */
    (xdc_Char)0x43,  /* [1494] */
    (xdc_Char)0x6f,  /* [1495] */
    (xdc_Char)0x6e,  /* [1496] */
    (xdc_Char)0x74,  /* [1497] */
    (xdc_Char)0x65,  /* [1498] */
    (xdc_Char)0x78,  /* [1499] */
    (xdc_Char)0x74,  /* [1500] */
    (xdc_Char)0x3a,  /* [1501] */
    (xdc_Char)0x20,  /* [1502] */
    (xdc_Char)0x62,  /* [1503] */
    (xdc_Char)0x61,  /* [1504] */
    (xdc_Char)0x64,  /* [1505] */
    (xdc_Char)0x20,  /* [1506] */
    (xdc_Char)0x63,  /* [1507] */
    (xdc_Char)0x61,  /* [1508] */
    (xdc_Char)0x6c,  /* [1509] */
    (xdc_Char)0x6c,  /* [1510] */
    (xdc_Char)0x69,  /* [1511] */
    (xdc_Char)0x6e,  /* [1512] */
    (xdc_Char)0x67,  /* [1513] */
    (xdc_Char)0x20,  /* [1514] */
    (xdc_Char)0x63,  /* [1515] */
    (xdc_Char)0x6f,  /* [1516] */
    (xdc_Char)0x6e,  /* [1517] */
    (xdc_Char)0x74,  /* [1518] */
    (xdc_Char)0x65,  /* [1519] */
    (xdc_Char)0x78,  /* [1520] */
    (xdc_Char)0x74,  /* [1521] */
    (xdc_Char)0x2e,  /* [1522] */
    (xdc_Char)0x20,  /* [1523] */
    (xdc_Char)0x4d,  /* [1524] */
    (xdc_Char)0x61,  /* [1525] */
    (xdc_Char)0x79,  /* [1526] */
    (xdc_Char)0x20,  /* [1527] */
    (xdc_Char)0x6e,  /* [1528] */
    (xdc_Char)0x6f,  /* [1529] */
    (xdc_Char)0x74,  /* [1530] */
    (xdc_Char)0x20,  /* [1531] */
    (xdc_Char)0x62,  /* [1532] */
    (xdc_Char)0x65,  /* [1533] */
    (xdc_Char)0x20,  /* [1534] */
    (xdc_Char)0x65,  /* [1535] */
    (xdc_Char)0x6e,  /* [1536] */
    (xdc_Char)0x74,  /* [1537] */
    (xdc_Char)0x65,  /* [1538] */
    (xdc_Char)0x72,  /* [1539] */
    (xdc_Char)0x65,  /* [1540] */
    (xdc_Char)0x64,  /* [1541] */
    (xdc_Char)0x20,  /* [1542] */
    (xdc_Char)0x66,  /* [1543] */
    (xdc_Char)0x72,  /* [1544] */
    (xdc_Char)0x6f,  /* [1545] */
    (xdc_Char)0x6d,  /* [1546] */
    (xdc_Char)0x20,  /* [1547] */
    (xdc_Char)0x61,  /* [1548] */
    (xdc_Char)0x20,  /* [1549] */
    (xdc_Char)0x73,  /* [1550] */
    (xdc_Char)0x6f,  /* [1551] */
    (xdc_Char)0x66,  /* [1552] */
    (xdc_Char)0x74,  /* [1553] */
    (xdc_Char)0x77,  /* [1554] */
    (xdc_Char)0x61,  /* [1555] */
    (xdc_Char)0x72,  /* [1556] */
    (xdc_Char)0x65,  /* [1557] */
    (xdc_Char)0x20,  /* [1558] */
    (xdc_Char)0x6f,  /* [1559] */
    (xdc_Char)0x72,  /* [1560] */
    (xdc_Char)0x20,  /* [1561] */
    (xdc_Char)0x68,  /* [1562] */
    (xdc_Char)0x61,  /* [1563] */
    (xdc_Char)0x72,  /* [1564] */
    (xdc_Char)0x64,  /* [1565] */
    (xdc_Char)0x77,  /* [1566] */
    (xdc_Char)0x61,  /* [1567] */
    (xdc_Char)0x72,  /* [1568] */
    (xdc_Char)0x65,  /* [1569] */
    (xdc_Char)0x20,  /* [1570] */
    (xdc_Char)0x69,  /* [1571] */
    (xdc_Char)0x6e,  /* [1572] */
    (xdc_Char)0x74,  /* [1573] */
    (xdc_Char)0x65,  /* [1574] */
    (xdc_Char)0x72,  /* [1575] */
    (xdc_Char)0x72,  /* [1576] */
    (xdc_Char)0x75,  /* [1577] */
    (xdc_Char)0x70,  /* [1578] */
    (xdc_Char)0x74,  /* [1579] */
    (xdc_Char)0x20,  /* [1580] */
    (xdc_Char)0x74,  /* [1581] */
    (xdc_Char)0x68,  /* [1582] */
    (xdc_Char)0x72,  /* [1583] */
    (xdc_Char)0x65,  /* [1584] */
    (xdc_Char)0x61,  /* [1585] */
    (xdc_Char)0x64,  /* [1586] */
    (xdc_Char)0x2e,  /* [1587] */
    (xdc_Char)0x0,  /* [1588] */
    (xdc_Char)0x41,  /* [1589] */
    (xdc_Char)0x5f,  /* [1590] */
    (xdc_Char)0x62,  /* [1591] */
    (xdc_Char)0x61,  /* [1592] */
    (xdc_Char)0x64,  /* [1593] */
    (xdc_Char)0x43,  /* [1594] */
    (xdc_Char)0x6f,  /* [1595] */
    (xdc_Char)0x6e,  /* [1596] */
    (xdc_Char)0x74,  /* [1597] */
    (xdc_Char)0x65,  /* [1598] */
    (xdc_Char)0x78,  /* [1599] */
    (xdc_Char)0x74,  /* [1600] */
    (xdc_Char)0x3a,  /* [1601] */
    (xdc_Char)0x20,  /* [1602] */
    (xdc_Char)0x62,  /* [1603] */
    (xdc_Char)0x61,  /* [1604] */
    (xdc_Char)0x64,  /* [1605] */
    (xdc_Char)0x20,  /* [1606] */
    (xdc_Char)0x63,  /* [1607] */
    (xdc_Char)0x61,  /* [1608] */
    (xdc_Char)0x6c,  /* [1609] */
    (xdc_Char)0x6c,  /* [1610] */
    (xdc_Char)0x69,  /* [1611] */
    (xdc_Char)0x6e,  /* [1612] */
    (xdc_Char)0x67,  /* [1613] */
    (xdc_Char)0x20,  /* [1614] */
    (xdc_Char)0x63,  /* [1615] */
    (xdc_Char)0x6f,  /* [1616] */
    (xdc_Char)0x6e,  /* [1617] */
    (xdc_Char)0x74,  /* [1618] */
    (xdc_Char)0x65,  /* [1619] */
    (xdc_Char)0x78,  /* [1620] */
    (xdc_Char)0x74,  /* [1621] */
    (xdc_Char)0x2e,  /* [1622] */
    (xdc_Char)0x20,  /* [1623] */
    (xdc_Char)0x53,  /* [1624] */
    (xdc_Char)0x65,  /* [1625] */
    (xdc_Char)0x65,  /* [1626] */
    (xdc_Char)0x20,  /* [1627] */
    (xdc_Char)0x47,  /* [1628] */
    (xdc_Char)0x61,  /* [1629] */
    (xdc_Char)0x74,  /* [1630] */
    (xdc_Char)0x65,  /* [1631] */
    (xdc_Char)0x4d,  /* [1632] */
    (xdc_Char)0x75,  /* [1633] */
    (xdc_Char)0x74,  /* [1634] */
    (xdc_Char)0x65,  /* [1635] */
    (xdc_Char)0x78,  /* [1636] */
    (xdc_Char)0x50,  /* [1637] */
    (xdc_Char)0x72,  /* [1638] */
    (xdc_Char)0x69,  /* [1639] */
    (xdc_Char)0x20,  /* [1640] */
    (xdc_Char)0x41,  /* [1641] */
    (xdc_Char)0x50,  /* [1642] */
    (xdc_Char)0x49,  /* [1643] */
    (xdc_Char)0x20,  /* [1644] */
    (xdc_Char)0x64,  /* [1645] */
    (xdc_Char)0x6f,  /* [1646] */
    (xdc_Char)0x63,  /* [1647] */
    (xdc_Char)0x20,  /* [1648] */
    (xdc_Char)0x66,  /* [1649] */
    (xdc_Char)0x6f,  /* [1650] */
    (xdc_Char)0x72,  /* [1651] */
    (xdc_Char)0x20,  /* [1652] */
    (xdc_Char)0x64,  /* [1653] */
    (xdc_Char)0x65,  /* [1654] */
    (xdc_Char)0x74,  /* [1655] */
    (xdc_Char)0x61,  /* [1656] */
    (xdc_Char)0x69,  /* [1657] */
    (xdc_Char)0x6c,  /* [1658] */
    (xdc_Char)0x73,  /* [1659] */
    (xdc_Char)0x2e,  /* [1660] */
    (xdc_Char)0x0,  /* [1661] */
    (xdc_Char)0x41,  /* [1662] */
    (xdc_Char)0x5f,  /* [1663] */
    (xdc_Char)0x62,  /* [1664] */
    (xdc_Char)0x61,  /* [1665] */
    (xdc_Char)0x64,  /* [1666] */
    (xdc_Char)0x43,  /* [1667] */
    (xdc_Char)0x6f,  /* [1668] */
    (xdc_Char)0x6e,  /* [1669] */
    (xdc_Char)0x74,  /* [1670] */
    (xdc_Char)0x65,  /* [1671] */
    (xdc_Char)0x78,  /* [1672] */
    (xdc_Char)0x74,  /* [1673] */
    (xdc_Char)0x3a,  /* [1674] */
    (xdc_Char)0x20,  /* [1675] */
    (xdc_Char)0x62,  /* [1676] */
    (xdc_Char)0x61,  /* [1677] */
    (xdc_Char)0x64,  /* [1678] */
    (xdc_Char)0x20,  /* [1679] */
    (xdc_Char)0x63,  /* [1680] */
    (xdc_Char)0x61,  /* [1681] */
    (xdc_Char)0x6c,  /* [1682] */
    (xdc_Char)0x6c,  /* [1683] */
    (xdc_Char)0x69,  /* [1684] */
    (xdc_Char)0x6e,  /* [1685] */
    (xdc_Char)0x67,  /* [1686] */
    (xdc_Char)0x20,  /* [1687] */
    (xdc_Char)0x63,  /* [1688] */
    (xdc_Char)0x6f,  /* [1689] */
    (xdc_Char)0x6e,  /* [1690] */
    (xdc_Char)0x74,  /* [1691] */
    (xdc_Char)0x65,  /* [1692] */
    (xdc_Char)0x78,  /* [1693] */
    (xdc_Char)0x74,  /* [1694] */
    (xdc_Char)0x2e,  /* [1695] */
    (xdc_Char)0x20,  /* [1696] */
    (xdc_Char)0x53,  /* [1697] */
    (xdc_Char)0x65,  /* [1698] */
    (xdc_Char)0x65,  /* [1699] */
    (xdc_Char)0x20,  /* [1700] */
    (xdc_Char)0x47,  /* [1701] */
    (xdc_Char)0x61,  /* [1702] */
    (xdc_Char)0x74,  /* [1703] */
    (xdc_Char)0x65,  /* [1704] */
    (xdc_Char)0x4d,  /* [1705] */
    (xdc_Char)0x75,  /* [1706] */
    (xdc_Char)0x74,  /* [1707] */
    (xdc_Char)0x65,  /* [1708] */
    (xdc_Char)0x78,  /* [1709] */
    (xdc_Char)0x20,  /* [1710] */
    (xdc_Char)0x41,  /* [1711] */
    (xdc_Char)0x50,  /* [1712] */
    (xdc_Char)0x49,  /* [1713] */
    (xdc_Char)0x20,  /* [1714] */
    (xdc_Char)0x64,  /* [1715] */
    (xdc_Char)0x6f,  /* [1716] */
    (xdc_Char)0x63,  /* [1717] */
    (xdc_Char)0x20,  /* [1718] */
    (xdc_Char)0x66,  /* [1719] */
    (xdc_Char)0x6f,  /* [1720] */
    (xdc_Char)0x72,  /* [1721] */
    (xdc_Char)0x20,  /* [1722] */
    (xdc_Char)0x64,  /* [1723] */
    (xdc_Char)0x65,  /* [1724] */
    (xdc_Char)0x74,  /* [1725] */
    (xdc_Char)0x61,  /* [1726] */
    (xdc_Char)0x69,  /* [1727] */
    (xdc_Char)0x6c,  /* [1728] */
    (xdc_Char)0x73,  /* [1729] */
    (xdc_Char)0x2e,  /* [1730] */
    (xdc_Char)0x0,  /* [1731] */
    (xdc_Char)0x41,  /* [1732] */
    (xdc_Char)0x5f,  /* [1733] */
    (xdc_Char)0x7a,  /* [1734] */
    (xdc_Char)0x65,  /* [1735] */
    (xdc_Char)0x72,  /* [1736] */
    (xdc_Char)0x6f,  /* [1737] */
    (xdc_Char)0x54,  /* [1738] */
    (xdc_Char)0x69,  /* [1739] */
    (xdc_Char)0x6d,  /* [1740] */
    (xdc_Char)0x65,  /* [1741] */
    (xdc_Char)0x6f,  /* [1742] */
    (xdc_Char)0x75,  /* [1743] */
    (xdc_Char)0x74,  /* [1744] */
    (xdc_Char)0x3a,  /* [1745] */
    (xdc_Char)0x20,  /* [1746] */
    (xdc_Char)0x54,  /* [1747] */
    (xdc_Char)0x69,  /* [1748] */
    (xdc_Char)0x6d,  /* [1749] */
    (xdc_Char)0x65,  /* [1750] */
    (xdc_Char)0x6f,  /* [1751] */
    (xdc_Char)0x75,  /* [1752] */
    (xdc_Char)0x74,  /* [1753] */
    (xdc_Char)0x20,  /* [1754] */
    (xdc_Char)0x76,  /* [1755] */
    (xdc_Char)0x61,  /* [1756] */
    (xdc_Char)0x6c,  /* [1757] */
    (xdc_Char)0x75,  /* [1758] */
    (xdc_Char)0x65,  /* [1759] */
    (xdc_Char)0x20,  /* [1760] */
    (xdc_Char)0x61,  /* [1761] */
    (xdc_Char)0x6e,  /* [1762] */
    (xdc_Char)0x6e,  /* [1763] */
    (xdc_Char)0x6f,  /* [1764] */
    (xdc_Char)0x74,  /* [1765] */
    (xdc_Char)0x20,  /* [1766] */
    (xdc_Char)0x62,  /* [1767] */
    (xdc_Char)0x65,  /* [1768] */
    (xdc_Char)0x20,  /* [1769] */
    (xdc_Char)0x7a,  /* [1770] */
    (xdc_Char)0x65,  /* [1771] */
    (xdc_Char)0x72,  /* [1772] */
    (xdc_Char)0x6f,  /* [1773] */
    (xdc_Char)0x0,  /* [1774] */
    (xdc_Char)0x41,  /* [1775] */
    (xdc_Char)0x5f,  /* [1776] */
    (xdc_Char)0x69,  /* [1777] */
    (xdc_Char)0x6e,  /* [1778] */
    (xdc_Char)0x76,  /* [1779] */
    (xdc_Char)0x61,  /* [1780] */
    (xdc_Char)0x6c,  /* [1781] */
    (xdc_Char)0x69,  /* [1782] */
    (xdc_Char)0x64,  /* [1783] */
    (xdc_Char)0x4b,  /* [1784] */
    (xdc_Char)0x65,  /* [1785] */
    (xdc_Char)0x79,  /* [1786] */
    (xdc_Char)0x3a,  /* [1787] */
    (xdc_Char)0x20,  /* [1788] */
    (xdc_Char)0x74,  /* [1789] */
    (xdc_Char)0x68,  /* [1790] */
    (xdc_Char)0x65,  /* [1791] */
    (xdc_Char)0x20,  /* [1792] */
    (xdc_Char)0x6b,  /* [1793] */
    (xdc_Char)0x65,  /* [1794] */
    (xdc_Char)0x79,  /* [1795] */
    (xdc_Char)0x20,  /* [1796] */
    (xdc_Char)0x6d,  /* [1797] */
    (xdc_Char)0x75,  /* [1798] */
    (xdc_Char)0x73,  /* [1799] */
    (xdc_Char)0x74,  /* [1800] */
    (xdc_Char)0x20,  /* [1801] */
    (xdc_Char)0x62,  /* [1802] */
    (xdc_Char)0x65,  /* [1803] */
    (xdc_Char)0x20,  /* [1804] */
    (xdc_Char)0x73,  /* [1805] */
    (xdc_Char)0x65,  /* [1806] */
    (xdc_Char)0x74,  /* [1807] */
    (xdc_Char)0x20,  /* [1808] */
    (xdc_Char)0x74,  /* [1809] */
    (xdc_Char)0x6f,  /* [1810] */
    (xdc_Char)0x20,  /* [1811] */
    (xdc_Char)0x61,  /* [1812] */
    (xdc_Char)0x20,  /* [1813] */
    (xdc_Char)0x6e,  /* [1814] */
    (xdc_Char)0x6f,  /* [1815] */
    (xdc_Char)0x6e,  /* [1816] */
    (xdc_Char)0x2d,  /* [1817] */
    (xdc_Char)0x64,  /* [1818] */
    (xdc_Char)0x65,  /* [1819] */
    (xdc_Char)0x66,  /* [1820] */
    (xdc_Char)0x61,  /* [1821] */
    (xdc_Char)0x75,  /* [1822] */
    (xdc_Char)0x6c,  /* [1823] */
    (xdc_Char)0x74,  /* [1824] */
    (xdc_Char)0x20,  /* [1825] */
    (xdc_Char)0x76,  /* [1826] */
    (xdc_Char)0x61,  /* [1827] */
    (xdc_Char)0x6c,  /* [1828] */
    (xdc_Char)0x75,  /* [1829] */
    (xdc_Char)0x65,  /* [1830] */
    (xdc_Char)0x0,  /* [1831] */
    (xdc_Char)0x41,  /* [1832] */
    (xdc_Char)0x5f,  /* [1833] */
    (xdc_Char)0x69,  /* [1834] */
    (xdc_Char)0x6e,  /* [1835] */
    (xdc_Char)0x76,  /* [1836] */
    (xdc_Char)0x61,  /* [1837] */
    (xdc_Char)0x6c,  /* [1838] */
    (xdc_Char)0x69,  /* [1839] */
    (xdc_Char)0x64,  /* [1840] */
    (xdc_Char)0x4c,  /* [1841] */
    (xdc_Char)0x65,  /* [1842] */
    (xdc_Char)0x6e,  /* [1843] */
    (xdc_Char)0x3a,  /* [1844] */
    (xdc_Char)0x20,  /* [1845] */
    (xdc_Char)0x49,  /* [1846] */
    (xdc_Char)0x6e,  /* [1847] */
    (xdc_Char)0x76,  /* [1848] */
    (xdc_Char)0x61,  /* [1849] */
    (xdc_Char)0x6c,  /* [1850] */
    (xdc_Char)0x69,  /* [1851] */
    (xdc_Char)0x64,  /* [1852] */
    (xdc_Char)0x20,  /* [1853] */
    (xdc_Char)0x6c,  /* [1854] */
    (xdc_Char)0x65,  /* [1855] */
    (xdc_Char)0x6e,  /* [1856] */
    (xdc_Char)0x67,  /* [1857] */
    (xdc_Char)0x74,  /* [1858] */
    (xdc_Char)0x68,  /* [1859] */
    (xdc_Char)0x0,  /* [1860] */
    (xdc_Char)0x41,  /* [1861] */
    (xdc_Char)0x5f,  /* [1862] */
    (xdc_Char)0x69,  /* [1863] */
    (xdc_Char)0x6e,  /* [1864] */
    (xdc_Char)0x76,  /* [1865] */
    (xdc_Char)0x41,  /* [1866] */
    (xdc_Char)0x72,  /* [1867] */
    (xdc_Char)0x67,  /* [1868] */
    (xdc_Char)0x75,  /* [1869] */
    (xdc_Char)0x6d,  /* [1870] */
    (xdc_Char)0x65,  /* [1871] */
    (xdc_Char)0x6e,  /* [1872] */
    (xdc_Char)0x74,  /* [1873] */
    (xdc_Char)0x3a,  /* [1874] */
    (xdc_Char)0x20,  /* [1875] */
    (xdc_Char)0x49,  /* [1876] */
    (xdc_Char)0x6e,  /* [1877] */
    (xdc_Char)0x76,  /* [1878] */
    (xdc_Char)0x61,  /* [1879] */
    (xdc_Char)0x6c,  /* [1880] */
    (xdc_Char)0x69,  /* [1881] */
    (xdc_Char)0x64,  /* [1882] */
    (xdc_Char)0x20,  /* [1883] */
    (xdc_Char)0x61,  /* [1884] */
    (xdc_Char)0x72,  /* [1885] */
    (xdc_Char)0x67,  /* [1886] */
    (xdc_Char)0x75,  /* [1887] */
    (xdc_Char)0x6d,  /* [1888] */
    (xdc_Char)0x65,  /* [1889] */
    (xdc_Char)0x6e,  /* [1890] */
    (xdc_Char)0x74,  /* [1891] */
    (xdc_Char)0x20,  /* [1892] */
    (xdc_Char)0x73,  /* [1893] */
    (xdc_Char)0x75,  /* [1894] */
    (xdc_Char)0x70,  /* [1895] */
    (xdc_Char)0x70,  /* [1896] */
    (xdc_Char)0x6c,  /* [1897] */
    (xdc_Char)0x69,  /* [1898] */
    (xdc_Char)0x65,  /* [1899] */
    (xdc_Char)0x64,  /* [1900] */
    (xdc_Char)0x0,  /* [1901] */
    (xdc_Char)0x41,  /* [1902] */
    (xdc_Char)0x5f,  /* [1903] */
    (xdc_Char)0x69,  /* [1904] */
    (xdc_Char)0x6e,  /* [1905] */
    (xdc_Char)0x76,  /* [1906] */
    (xdc_Char)0x61,  /* [1907] */
    (xdc_Char)0x6c,  /* [1908] */
    (xdc_Char)0x69,  /* [1909] */
    (xdc_Char)0x64,  /* [1910] */
    (xdc_Char)0x4d,  /* [1911] */
    (xdc_Char)0x75,  /* [1912] */
    (xdc_Char)0x6c,  /* [1913] */
    (xdc_Char)0x74,  /* [1914] */
    (xdc_Char)0x69,  /* [1915] */
    (xdc_Char)0x50,  /* [1916] */
    (xdc_Char)0x72,  /* [1917] */
    (xdc_Char)0x6f,  /* [1918] */
    (xdc_Char)0x63,  /* [1919] */
    (xdc_Char)0x49,  /* [1920] */
    (xdc_Char)0x64,  /* [1921] */
    (xdc_Char)0x3a,  /* [1922] */
    (xdc_Char)0x20,  /* [1923] */
    (xdc_Char)0x49,  /* [1924] */
    (xdc_Char)0x6e,  /* [1925] */
    (xdc_Char)0x76,  /* [1926] */
    (xdc_Char)0x61,  /* [1927] */
    (xdc_Char)0x6c,  /* [1928] */
    (xdc_Char)0x69,  /* [1929] */
    (xdc_Char)0x64,  /* [1930] */
    (xdc_Char)0x20,  /* [1931] */
    (xdc_Char)0x4d,  /* [1932] */
    (xdc_Char)0x75,  /* [1933] */
    (xdc_Char)0x6c,  /* [1934] */
    (xdc_Char)0x74,  /* [1935] */
    (xdc_Char)0x69,  /* [1936] */
    (xdc_Char)0x50,  /* [1937] */
    (xdc_Char)0x72,  /* [1938] */
    (xdc_Char)0x6f,  /* [1939] */
    (xdc_Char)0x63,  /* [1940] */
    (xdc_Char)0x20,  /* [1941] */
    (xdc_Char)0x69,  /* [1942] */
    (xdc_Char)0x64,  /* [1943] */
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
    (xdc_Char)0x50,  /* [1954] */
    (xdc_Char)0x72,  /* [1955] */
    (xdc_Char)0x6f,  /* [1956] */
    (xdc_Char)0x63,  /* [1957] */
    (xdc_Char)0x4e,  /* [1958] */
    (xdc_Char)0x61,  /* [1959] */
    (xdc_Char)0x6d,  /* [1960] */
    (xdc_Char)0x65,  /* [1961] */
    (xdc_Char)0x3a,  /* [1962] */
    (xdc_Char)0x20,  /* [1963] */
    (xdc_Char)0x4e,  /* [1964] */
    (xdc_Char)0x55,  /* [1965] */
    (xdc_Char)0x4c,  /* [1966] */
    (xdc_Char)0x4c,  /* [1967] */
    (xdc_Char)0x20,  /* [1968] */
    (xdc_Char)0x4d,  /* [1969] */
    (xdc_Char)0x75,  /* [1970] */
    (xdc_Char)0x6c,  /* [1971] */
    (xdc_Char)0x74,  /* [1972] */
    (xdc_Char)0x69,  /* [1973] */
    (xdc_Char)0x50,  /* [1974] */
    (xdc_Char)0x72,  /* [1975] */
    (xdc_Char)0x6f,  /* [1976] */
    (xdc_Char)0x63,  /* [1977] */
    (xdc_Char)0x20,  /* [1978] */
    (xdc_Char)0x6e,  /* [1979] */
    (xdc_Char)0x61,  /* [1980] */
    (xdc_Char)0x6d,  /* [1981] */
    (xdc_Char)0x65,  /* [1982] */
    (xdc_Char)0x20,  /* [1983] */
    (xdc_Char)0x65,  /* [1984] */
    (xdc_Char)0x6e,  /* [1985] */
    (xdc_Char)0x63,  /* [1986] */
    (xdc_Char)0x6f,  /* [1987] */
    (xdc_Char)0x75,  /* [1988] */
    (xdc_Char)0x6e,  /* [1989] */
    (xdc_Char)0x74,  /* [1990] */
    (xdc_Char)0x65,  /* [1991] */
    (xdc_Char)0x72,  /* [1992] */
    (xdc_Char)0x65,  /* [1993] */
    (xdc_Char)0x64,  /* [1994] */
    (xdc_Char)0x0,  /* [1995] */
    (xdc_Char)0x41,  /* [1996] */
    (xdc_Char)0x5f,  /* [1997] */
    (xdc_Char)0x6e,  /* [1998] */
    (xdc_Char)0x75,  /* [1999] */
    (xdc_Char)0x6c,  /* [2000] */
    (xdc_Char)0x6c,  /* [2001] */
    (xdc_Char)0x48,  /* [2002] */
    (xdc_Char)0x61,  /* [2003] */
    (xdc_Char)0x6e,  /* [2004] */
    (xdc_Char)0x64,  /* [2005] */
    (xdc_Char)0x6c,  /* [2006] */
    (xdc_Char)0x65,  /* [2007] */
    (xdc_Char)0x3a,  /* [2008] */
    (xdc_Char)0x20,  /* [2009] */
    (xdc_Char)0x4e,  /* [2010] */
    (xdc_Char)0x75,  /* [2011] */
    (xdc_Char)0x6c,  /* [2012] */
    (xdc_Char)0x6c,  /* [2013] */
    (xdc_Char)0x20,  /* [2014] */
    (xdc_Char)0x68,  /* [2015] */
    (xdc_Char)0x61,  /* [2016] */
    (xdc_Char)0x6e,  /* [2017] */
    (xdc_Char)0x64,  /* [2018] */
    (xdc_Char)0x6c,  /* [2019] */
    (xdc_Char)0x65,  /* [2020] */
    (xdc_Char)0x20,  /* [2021] */
    (xdc_Char)0x70,  /* [2022] */
    (xdc_Char)0x61,  /* [2023] */
    (xdc_Char)0x73,  /* [2024] */
    (xdc_Char)0x73,  /* [2025] */
    (xdc_Char)0x65,  /* [2026] */
    (xdc_Char)0x64,  /* [2027] */
    (xdc_Char)0x20,  /* [2028] */
    (xdc_Char)0x74,  /* [2029] */
    (xdc_Char)0x6f,  /* [2030] */
    (xdc_Char)0x20,  /* [2031] */
    (xdc_Char)0x63,  /* [2032] */
    (xdc_Char)0x72,  /* [2033] */
    (xdc_Char)0x65,  /* [2034] */
    (xdc_Char)0x61,  /* [2035] */
    (xdc_Char)0x74,  /* [2036] */
    (xdc_Char)0x65,  /* [2037] */
    (xdc_Char)0x0,  /* [2038] */
    (xdc_Char)0x41,  /* [2039] */
    (xdc_Char)0x5f,  /* [2040] */
    (xdc_Char)0x69,  /* [2041] */
    (xdc_Char)0x6e,  /* [2042] */
    (xdc_Char)0x76,  /* [2043] */
    (xdc_Char)0x61,  /* [2044] */
    (xdc_Char)0x6c,  /* [2045] */
    (xdc_Char)0x69,  /* [2046] */
    (xdc_Char)0x64,  /* [2047] */
    (xdc_Char)0x43,  /* [2048] */
    (xdc_Char)0x6f,  /* [2049] */
    (xdc_Char)0x6e,  /* [2050] */
    (xdc_Char)0x74,  /* [2051] */
    (xdc_Char)0x65,  /* [2052] */
    (xdc_Char)0x78,  /* [2053] */
    (xdc_Char)0x74,  /* [2054] */
    (xdc_Char)0x3a,  /* [2055] */
    (xdc_Char)0x20,  /* [2056] */
    (xdc_Char)0x43,  /* [2057] */
    (xdc_Char)0x61,  /* [2058] */
    (xdc_Char)0x6c,  /* [2059] */
    (xdc_Char)0x6c,  /* [2060] */
    (xdc_Char)0x69,  /* [2061] */
    (xdc_Char)0x6e,  /* [2062] */
    (xdc_Char)0x67,  /* [2063] */
    (xdc_Char)0x20,  /* [2064] */
    (xdc_Char)0x47,  /* [2065] */
    (xdc_Char)0x61,  /* [2066] */
    (xdc_Char)0x74,  /* [2067] */
    (xdc_Char)0x65,  /* [2068] */
    (xdc_Char)0x4d,  /* [2069] */
    (xdc_Char)0x50,  /* [2070] */
    (xdc_Char)0x5f,  /* [2071] */
    (xdc_Char)0x63,  /* [2072] */
    (xdc_Char)0x6c,  /* [2073] */
    (xdc_Char)0x6f,  /* [2074] */
    (xdc_Char)0x73,  /* [2075] */
    (xdc_Char)0x65,  /* [2076] */
    (xdc_Char)0x20,  /* [2077] */
    (xdc_Char)0x77,  /* [2078] */
    (xdc_Char)0x69,  /* [2079] */
    (xdc_Char)0x74,  /* [2080] */
    (xdc_Char)0x68,  /* [2081] */
    (xdc_Char)0x20,  /* [2082] */
    (xdc_Char)0x74,  /* [2083] */
    (xdc_Char)0x68,  /* [2084] */
    (xdc_Char)0x65,  /* [2085] */
    (xdc_Char)0x20,  /* [2086] */
    (xdc_Char)0x77,  /* [2087] */
    (xdc_Char)0x72,  /* [2088] */
    (xdc_Char)0x6f,  /* [2089] */
    (xdc_Char)0x6e,  /* [2090] */
    (xdc_Char)0x67,  /* [2091] */
    (xdc_Char)0x20,  /* [2092] */
    (xdc_Char)0x68,  /* [2093] */
    (xdc_Char)0x61,  /* [2094] */
    (xdc_Char)0x6e,  /* [2095] */
    (xdc_Char)0x64,  /* [2096] */
    (xdc_Char)0x6c,  /* [2097] */
    (xdc_Char)0x65,  /* [2098] */
    (xdc_Char)0x0,  /* [2099] */
    (xdc_Char)0x41,  /* [2100] */
    (xdc_Char)0x5f,  /* [2101] */
    (xdc_Char)0x69,  /* [2102] */
    (xdc_Char)0x6e,  /* [2103] */
    (xdc_Char)0x76,  /* [2104] */
    (xdc_Char)0x61,  /* [2105] */
    (xdc_Char)0x6c,  /* [2106] */
    (xdc_Char)0x69,  /* [2107] */
    (xdc_Char)0x64,  /* [2108] */
    (xdc_Char)0x44,  /* [2109] */
    (xdc_Char)0x65,  /* [2110] */
    (xdc_Char)0x6c,  /* [2111] */
    (xdc_Char)0x65,  /* [2112] */
    (xdc_Char)0x74,  /* [2113] */
    (xdc_Char)0x65,  /* [2114] */
    (xdc_Char)0x3a,  /* [2115] */
    (xdc_Char)0x20,  /* [2116] */
    (xdc_Char)0x43,  /* [2117] */
    (xdc_Char)0x61,  /* [2118] */
    (xdc_Char)0x6c,  /* [2119] */
    (xdc_Char)0x6c,  /* [2120] */
    (xdc_Char)0x69,  /* [2121] */
    (xdc_Char)0x6e,  /* [2122] */
    (xdc_Char)0x67,  /* [2123] */
    (xdc_Char)0x20,  /* [2124] */
    (xdc_Char)0x47,  /* [2125] */
    (xdc_Char)0x61,  /* [2126] */
    (xdc_Char)0x74,  /* [2127] */
    (xdc_Char)0x65,  /* [2128] */
    (xdc_Char)0x4d,  /* [2129] */
    (xdc_Char)0x50,  /* [2130] */
    (xdc_Char)0x5f,  /* [2131] */
    (xdc_Char)0x64,  /* [2132] */
    (xdc_Char)0x65,  /* [2133] */
    (xdc_Char)0x6c,  /* [2134] */
    (xdc_Char)0x65,  /* [2135] */
    (xdc_Char)0x74,  /* [2136] */
    (xdc_Char)0x65,  /* [2137] */
    (xdc_Char)0x20,  /* [2138] */
    (xdc_Char)0x69,  /* [2139] */
    (xdc_Char)0x6e,  /* [2140] */
    (xdc_Char)0x63,  /* [2141] */
    (xdc_Char)0x6f,  /* [2142] */
    (xdc_Char)0x72,  /* [2143] */
    (xdc_Char)0x72,  /* [2144] */
    (xdc_Char)0x65,  /* [2145] */
    (xdc_Char)0x63,  /* [2146] */
    (xdc_Char)0x74,  /* [2147] */
    (xdc_Char)0x6c,  /* [2148] */
    (xdc_Char)0x79,  /* [2149] */
    (xdc_Char)0x0,  /* [2150] */
    (xdc_Char)0x41,  /* [2151] */
    (xdc_Char)0x5f,  /* [2152] */
    (xdc_Char)0x69,  /* [2153] */
    (xdc_Char)0x6e,  /* [2154] */
    (xdc_Char)0x76,  /* [2155] */
    (xdc_Char)0x61,  /* [2156] */
    (xdc_Char)0x6c,  /* [2157] */
    (xdc_Char)0x69,  /* [2158] */
    (xdc_Char)0x64,  /* [2159] */
    (xdc_Char)0x43,  /* [2160] */
    (xdc_Char)0x6f,  /* [2161] */
    (xdc_Char)0x6e,  /* [2162] */
    (xdc_Char)0x74,  /* [2163] */
    (xdc_Char)0x65,  /* [2164] */
    (xdc_Char)0x78,  /* [2165] */
    (xdc_Char)0x74,  /* [2166] */
    (xdc_Char)0x3a,  /* [2167] */
    (xdc_Char)0x20,  /* [2168] */
    (xdc_Char)0x43,  /* [2169] */
    (xdc_Char)0x61,  /* [2170] */
    (xdc_Char)0x6e,  /* [2171] */
    (xdc_Char)0x6e,  /* [2172] */
    (xdc_Char)0x6f,  /* [2173] */
    (xdc_Char)0x74,  /* [2174] */
    (xdc_Char)0x20,  /* [2175] */
    (xdc_Char)0x63,  /* [2176] */
    (xdc_Char)0x61,  /* [2177] */
    (xdc_Char)0x6c,  /* [2178] */
    (xdc_Char)0x6c,  /* [2179] */
    (xdc_Char)0x20,  /* [2180] */
    (xdc_Char)0x77,  /* [2181] */
    (xdc_Char)0x69,  /* [2182] */
    (xdc_Char)0x74,  /* [2183] */
    (xdc_Char)0x68,  /* [2184] */
    (xdc_Char)0x20,  /* [2185] */
    (xdc_Char)0x61,  /* [2186] */
    (xdc_Char)0x6e,  /* [2187] */
    (xdc_Char)0x20,  /* [2188] */
    (xdc_Char)0x6f,  /* [2189] */
    (xdc_Char)0x70,  /* [2190] */
    (xdc_Char)0x65,  /* [2191] */
    (xdc_Char)0x6e,  /* [2192] */
    (xdc_Char)0x2f,  /* [2193] */
    (xdc_Char)0x63,  /* [2194] */
    (xdc_Char)0x72,  /* [2195] */
    (xdc_Char)0x65,  /* [2196] */
    (xdc_Char)0x61,  /* [2197] */
    (xdc_Char)0x74,  /* [2198] */
    (xdc_Char)0x65,  /* [2199] */
    (xdc_Char)0x20,  /* [2200] */
    (xdc_Char)0x68,  /* [2201] */
    (xdc_Char)0x61,  /* [2202] */
    (xdc_Char)0x6e,  /* [2203] */
    (xdc_Char)0x64,  /* [2204] */
    (xdc_Char)0x6c,  /* [2205] */
    (xdc_Char)0x65,  /* [2206] */
    (xdc_Char)0x0,  /* [2207] */
    (xdc_Char)0x41,  /* [2208] */
    (xdc_Char)0x5f,  /* [2209] */
    (xdc_Char)0x63,  /* [2210] */
    (xdc_Char)0x61,  /* [2211] */
    (xdc_Char)0x6e,  /* [2212] */
    (xdc_Char)0x6e,  /* [2213] */
    (xdc_Char)0x6f,  /* [2214] */
    (xdc_Char)0x74,  /* [2215] */
    (xdc_Char)0x46,  /* [2216] */
    (xdc_Char)0x72,  /* [2217] */
    (xdc_Char)0x65,  /* [2218] */
    (xdc_Char)0x65,  /* [2219] */
    (xdc_Char)0x53,  /* [2220] */
    (xdc_Char)0x74,  /* [2221] */
    (xdc_Char)0x61,  /* [2222] */
    (xdc_Char)0x74,  /* [2223] */
    (xdc_Char)0x69,  /* [2224] */
    (xdc_Char)0x63,  /* [2225] */
    (xdc_Char)0x4d,  /* [2226] */
    (xdc_Char)0x73,  /* [2227] */
    (xdc_Char)0x67,  /* [2228] */
    (xdc_Char)0x3a,  /* [2229] */
    (xdc_Char)0x20,  /* [2230] */
    (xdc_Char)0x43,  /* [2231] */
    (xdc_Char)0x61,  /* [2232] */
    (xdc_Char)0x6e,  /* [2233] */
    (xdc_Char)0x6e,  /* [2234] */
    (xdc_Char)0x6f,  /* [2235] */
    (xdc_Char)0x74,  /* [2236] */
    (xdc_Char)0x20,  /* [2237] */
    (xdc_Char)0x63,  /* [2238] */
    (xdc_Char)0x61,  /* [2239] */
    (xdc_Char)0x6c,  /* [2240] */
    (xdc_Char)0x6c,  /* [2241] */
    (xdc_Char)0x20,  /* [2242] */
    (xdc_Char)0x4d,  /* [2243] */
    (xdc_Char)0x65,  /* [2244] */
    (xdc_Char)0x73,  /* [2245] */
    (xdc_Char)0x73,  /* [2246] */
    (xdc_Char)0x61,  /* [2247] */
    (xdc_Char)0x67,  /* [2248] */
    (xdc_Char)0x65,  /* [2249] */
    (xdc_Char)0x51,  /* [2250] */
    (xdc_Char)0x5f,  /* [2251] */
    (xdc_Char)0x66,  /* [2252] */
    (xdc_Char)0x72,  /* [2253] */
    (xdc_Char)0x65,  /* [2254] */
    (xdc_Char)0x65,  /* [2255] */
    (xdc_Char)0x20,  /* [2256] */
    (xdc_Char)0x77,  /* [2257] */
    (xdc_Char)0x69,  /* [2258] */
    (xdc_Char)0x74,  /* [2259] */
    (xdc_Char)0x68,  /* [2260] */
    (xdc_Char)0x20,  /* [2261] */
    (xdc_Char)0x73,  /* [2262] */
    (xdc_Char)0x74,  /* [2263] */
    (xdc_Char)0x61,  /* [2264] */
    (xdc_Char)0x74,  /* [2265] */
    (xdc_Char)0x69,  /* [2266] */
    (xdc_Char)0x63,  /* [2267] */
    (xdc_Char)0x20,  /* [2268] */
    (xdc_Char)0x6d,  /* [2269] */
    (xdc_Char)0x73,  /* [2270] */
    (xdc_Char)0x67,  /* [2271] */
    (xdc_Char)0x0,  /* [2272] */
    (xdc_Char)0x41,  /* [2273] */
    (xdc_Char)0x5f,  /* [2274] */
    (xdc_Char)0x69,  /* [2275] */
    (xdc_Char)0x6e,  /* [2276] */
    (xdc_Char)0x76,  /* [2277] */
    (xdc_Char)0x61,  /* [2278] */
    (xdc_Char)0x6c,  /* [2279] */
    (xdc_Char)0x69,  /* [2280] */
    (xdc_Char)0x64,  /* [2281] */
    (xdc_Char)0x4d,  /* [2282] */
    (xdc_Char)0x73,  /* [2283] */
    (xdc_Char)0x67,  /* [2284] */
    (xdc_Char)0x3a,  /* [2285] */
    (xdc_Char)0x20,  /* [2286] */
    (xdc_Char)0x49,  /* [2287] */
    (xdc_Char)0x6e,  /* [2288] */
    (xdc_Char)0x76,  /* [2289] */
    (xdc_Char)0x61,  /* [2290] */
    (xdc_Char)0x6c,  /* [2291] */
    (xdc_Char)0x69,  /* [2292] */
    (xdc_Char)0x64,  /* [2293] */
    (xdc_Char)0x20,  /* [2294] */
    (xdc_Char)0x6d,  /* [2295] */
    (xdc_Char)0x65,  /* [2296] */
    (xdc_Char)0x73,  /* [2297] */
    (xdc_Char)0x73,  /* [2298] */
    (xdc_Char)0x61,  /* [2299] */
    (xdc_Char)0x67,  /* [2300] */
    (xdc_Char)0x65,  /* [2301] */
    (xdc_Char)0x0,  /* [2302] */
    (xdc_Char)0x41,  /* [2303] */
    (xdc_Char)0x5f,  /* [2304] */
    (xdc_Char)0x69,  /* [2305] */
    (xdc_Char)0x6e,  /* [2306] */
    (xdc_Char)0x76,  /* [2307] */
    (xdc_Char)0x61,  /* [2308] */
    (xdc_Char)0x6c,  /* [2309] */
    (xdc_Char)0x69,  /* [2310] */
    (xdc_Char)0x64,  /* [2311] */
    (xdc_Char)0x51,  /* [2312] */
    (xdc_Char)0x75,  /* [2313] */
    (xdc_Char)0x65,  /* [2314] */
    (xdc_Char)0x75,  /* [2315] */
    (xdc_Char)0x65,  /* [2316] */
    (xdc_Char)0x49,  /* [2317] */
    (xdc_Char)0x64,  /* [2318] */
    (xdc_Char)0x3a,  /* [2319] */
    (xdc_Char)0x20,  /* [2320] */
    (xdc_Char)0x49,  /* [2321] */
    (xdc_Char)0x6e,  /* [2322] */
    (xdc_Char)0x76,  /* [2323] */
    (xdc_Char)0x61,  /* [2324] */
    (xdc_Char)0x6c,  /* [2325] */
    (xdc_Char)0x69,  /* [2326] */
    (xdc_Char)0x64,  /* [2327] */
    (xdc_Char)0x20,  /* [2328] */
    (xdc_Char)0x71,  /* [2329] */
    (xdc_Char)0x75,  /* [2330] */
    (xdc_Char)0x65,  /* [2331] */
    (xdc_Char)0x75,  /* [2332] */
    (xdc_Char)0x65,  /* [2333] */
    (xdc_Char)0x49,  /* [2334] */
    (xdc_Char)0x64,  /* [2335] */
    (xdc_Char)0x20,  /* [2336] */
    (xdc_Char)0x69,  /* [2337] */
    (xdc_Char)0x73,  /* [2338] */
    (xdc_Char)0x20,  /* [2339] */
    (xdc_Char)0x75,  /* [2340] */
    (xdc_Char)0x73,  /* [2341] */
    (xdc_Char)0x65,  /* [2342] */
    (xdc_Char)0x64,  /* [2343] */
    (xdc_Char)0x0,  /* [2344] */
    (xdc_Char)0x41,  /* [2345] */
    (xdc_Char)0x5f,  /* [2346] */
    (xdc_Char)0x68,  /* [2347] */
    (xdc_Char)0x65,  /* [2348] */
    (xdc_Char)0x61,  /* [2349] */
    (xdc_Char)0x70,  /* [2350] */
    (xdc_Char)0x49,  /* [2351] */
    (xdc_Char)0x64,  /* [2352] */
    (xdc_Char)0x49,  /* [2353] */
    (xdc_Char)0x6e,  /* [2354] */
    (xdc_Char)0x76,  /* [2355] */
    (xdc_Char)0x61,  /* [2356] */
    (xdc_Char)0x6c,  /* [2357] */
    (xdc_Char)0x69,  /* [2358] */
    (xdc_Char)0x64,  /* [2359] */
    (xdc_Char)0x3a,  /* [2360] */
    (xdc_Char)0x20,  /* [2361] */
    (xdc_Char)0x68,  /* [2362] */
    (xdc_Char)0x65,  /* [2363] */
    (xdc_Char)0x61,  /* [2364] */
    (xdc_Char)0x70,  /* [2365] */
    (xdc_Char)0x49,  /* [2366] */
    (xdc_Char)0x64,  /* [2367] */
    (xdc_Char)0x20,  /* [2368] */
    (xdc_Char)0x69,  /* [2369] */
    (xdc_Char)0x73,  /* [2370] */
    (xdc_Char)0x20,  /* [2371] */
    (xdc_Char)0x69,  /* [2372] */
    (xdc_Char)0x6e,  /* [2373] */
    (xdc_Char)0x76,  /* [2374] */
    (xdc_Char)0x61,  /* [2375] */
    (xdc_Char)0x6c,  /* [2376] */
    (xdc_Char)0x69,  /* [2377] */
    (xdc_Char)0x64,  /* [2378] */
    (xdc_Char)0x0,  /* [2379] */
    (xdc_Char)0x41,  /* [2380] */
    (xdc_Char)0x5f,  /* [2381] */
    (xdc_Char)0x70,  /* [2382] */
    (xdc_Char)0x72,  /* [2383] */
    (xdc_Char)0x6f,  /* [2384] */
    (xdc_Char)0x63,  /* [2385] */
    (xdc_Char)0x49,  /* [2386] */
    (xdc_Char)0x64,  /* [2387] */
    (xdc_Char)0x49,  /* [2388] */
    (xdc_Char)0x6e,  /* [2389] */
    (xdc_Char)0x76,  /* [2390] */
    (xdc_Char)0x61,  /* [2391] */
    (xdc_Char)0x6c,  /* [2392] */
    (xdc_Char)0x69,  /* [2393] */
    (xdc_Char)0x64,  /* [2394] */
    (xdc_Char)0x3a,  /* [2395] */
    (xdc_Char)0x20,  /* [2396] */
    (xdc_Char)0x70,  /* [2397] */
    (xdc_Char)0x72,  /* [2398] */
    (xdc_Char)0x6f,  /* [2399] */
    (xdc_Char)0x63,  /* [2400] */
    (xdc_Char)0x49,  /* [2401] */
    (xdc_Char)0x64,  /* [2402] */
    (xdc_Char)0x20,  /* [2403] */
    (xdc_Char)0x69,  /* [2404] */
    (xdc_Char)0x73,  /* [2405] */
    (xdc_Char)0x20,  /* [2406] */
    (xdc_Char)0x69,  /* [2407] */
    (xdc_Char)0x6e,  /* [2408] */
    (xdc_Char)0x76,  /* [2409] */
    (xdc_Char)0x61,  /* [2410] */
    (xdc_Char)0x6c,  /* [2411] */
    (xdc_Char)0x69,  /* [2412] */
    (xdc_Char)0x64,  /* [2413] */
    (xdc_Char)0x0,  /* [2414] */
    (xdc_Char)0x41,  /* [2415] */
    (xdc_Char)0x5f,  /* [2416] */
    (xdc_Char)0x69,  /* [2417] */
    (xdc_Char)0x6e,  /* [2418] */
    (xdc_Char)0x76,  /* [2419] */
    (xdc_Char)0x61,  /* [2420] */
    (xdc_Char)0x6c,  /* [2421] */
    (xdc_Char)0x69,  /* [2422] */
    (xdc_Char)0x64,  /* [2423] */
    (xdc_Char)0x4f,  /* [2424] */
    (xdc_Char)0x62,  /* [2425] */
    (xdc_Char)0x6a,  /* [2426] */
    (xdc_Char)0x3a,  /* [2427] */
    (xdc_Char)0x20,  /* [2428] */
    (xdc_Char)0x61,  /* [2429] */
    (xdc_Char)0x6e,  /* [2430] */
    (xdc_Char)0x20,  /* [2431] */
    (xdc_Char)0x69,  /* [2432] */
    (xdc_Char)0x6e,  /* [2433] */
    (xdc_Char)0x76,  /* [2434] */
    (xdc_Char)0x61,  /* [2435] */
    (xdc_Char)0x6c,  /* [2436] */
    (xdc_Char)0x69,  /* [2437] */
    (xdc_Char)0x64,  /* [2438] */
    (xdc_Char)0x20,  /* [2439] */
    (xdc_Char)0x6f,  /* [2440] */
    (xdc_Char)0x62,  /* [2441] */
    (xdc_Char)0x6a,  /* [2442] */
    (xdc_Char)0x20,  /* [2443] */
    (xdc_Char)0x69,  /* [2444] */
    (xdc_Char)0x73,  /* [2445] */
    (xdc_Char)0x20,  /* [2446] */
    (xdc_Char)0x75,  /* [2447] */
    (xdc_Char)0x73,  /* [2448] */
    (xdc_Char)0x65,  /* [2449] */
    (xdc_Char)0x64,  /* [2450] */
    (xdc_Char)0x0,  /* [2451] */
    (xdc_Char)0x41,  /* [2452] */
    (xdc_Char)0x5f,  /* [2453] */
    (xdc_Char)0x69,  /* [2454] */
    (xdc_Char)0x6e,  /* [2455] */
    (xdc_Char)0x76,  /* [2456] */
    (xdc_Char)0x61,  /* [2457] */
    (xdc_Char)0x6c,  /* [2458] */
    (xdc_Char)0x69,  /* [2459] */
    (xdc_Char)0x64,  /* [2460] */
    (xdc_Char)0x50,  /* [2461] */
    (xdc_Char)0x61,  /* [2462] */
    (xdc_Char)0x72,  /* [2463] */
    (xdc_Char)0x61,  /* [2464] */
    (xdc_Char)0x6d,  /* [2465] */
    (xdc_Char)0x3a,  /* [2466] */
    (xdc_Char)0x20,  /* [2467] */
    (xdc_Char)0x61,  /* [2468] */
    (xdc_Char)0x6e,  /* [2469] */
    (xdc_Char)0x20,  /* [2470] */
    (xdc_Char)0x69,  /* [2471] */
    (xdc_Char)0x6e,  /* [2472] */
    (xdc_Char)0x76,  /* [2473] */
    (xdc_Char)0x61,  /* [2474] */
    (xdc_Char)0x6c,  /* [2475] */
    (xdc_Char)0x69,  /* [2476] */
    (xdc_Char)0x64,  /* [2477] */
    (xdc_Char)0x20,  /* [2478] */
    (xdc_Char)0x70,  /* [2479] */
    (xdc_Char)0x61,  /* [2480] */
    (xdc_Char)0x72,  /* [2481] */
    (xdc_Char)0x61,  /* [2482] */
    (xdc_Char)0x6d,  /* [2483] */
    (xdc_Char)0x65,  /* [2484] */
    (xdc_Char)0x74,  /* [2485] */
    (xdc_Char)0x65,  /* [2486] */
    (xdc_Char)0x72,  /* [2487] */
    (xdc_Char)0x20,  /* [2488] */
    (xdc_Char)0x77,  /* [2489] */
    (xdc_Char)0x61,  /* [2490] */
    (xdc_Char)0x73,  /* [2491] */
    (xdc_Char)0x20,  /* [2492] */
    (xdc_Char)0x70,  /* [2493] */
    (xdc_Char)0x61,  /* [2494] */
    (xdc_Char)0x73,  /* [2495] */
    (xdc_Char)0x73,  /* [2496] */
    (xdc_Char)0x65,  /* [2497] */
    (xdc_Char)0x64,  /* [2498] */
    (xdc_Char)0x20,  /* [2499] */
    (xdc_Char)0x69,  /* [2500] */
    (xdc_Char)0x6e,  /* [2501] */
    (xdc_Char)0x0,  /* [2502] */
    (xdc_Char)0x41,  /* [2503] */
    (xdc_Char)0x5f,  /* [2504] */
    (xdc_Char)0x75,  /* [2505] */
    (xdc_Char)0x6e,  /* [2506] */
    (xdc_Char)0x72,  /* [2507] */
    (xdc_Char)0x65,  /* [2508] */
    (xdc_Char)0x67,  /* [2509] */
    (xdc_Char)0x69,  /* [2510] */
    (xdc_Char)0x73,  /* [2511] */
    (xdc_Char)0x74,  /* [2512] */
    (xdc_Char)0x65,  /* [2513] */
    (xdc_Char)0x72,  /* [2514] */
    (xdc_Char)0x65,  /* [2515] */
    (xdc_Char)0x64,  /* [2516] */
    (xdc_Char)0x54,  /* [2517] */
    (xdc_Char)0x72,  /* [2518] */
    (xdc_Char)0x61,  /* [2519] */
    (xdc_Char)0x6e,  /* [2520] */
    (xdc_Char)0x73,  /* [2521] */
    (xdc_Char)0x70,  /* [2522] */
    (xdc_Char)0x6f,  /* [2523] */
    (xdc_Char)0x72,  /* [2524] */
    (xdc_Char)0x74,  /* [2525] */
    (xdc_Char)0x3a,  /* [2526] */
    (xdc_Char)0x20,  /* [2527] */
    (xdc_Char)0x74,  /* [2528] */
    (xdc_Char)0x72,  /* [2529] */
    (xdc_Char)0x61,  /* [2530] */
    (xdc_Char)0x6e,  /* [2531] */
    (xdc_Char)0x73,  /* [2532] */
    (xdc_Char)0x70,  /* [2533] */
    (xdc_Char)0x6f,  /* [2534] */
    (xdc_Char)0x72,  /* [2535] */
    (xdc_Char)0x74,  /* [2536] */
    (xdc_Char)0x20,  /* [2537] */
    (xdc_Char)0x69,  /* [2538] */
    (xdc_Char)0x73,  /* [2539] */
    (xdc_Char)0x20,  /* [2540] */
    (xdc_Char)0x6e,  /* [2541] */
    (xdc_Char)0x6f,  /* [2542] */
    (xdc_Char)0x74,  /* [2543] */
    (xdc_Char)0x20,  /* [2544] */
    (xdc_Char)0x72,  /* [2545] */
    (xdc_Char)0x65,  /* [2546] */
    (xdc_Char)0x67,  /* [2547] */
    (xdc_Char)0x69,  /* [2548] */
    (xdc_Char)0x73,  /* [2549] */
    (xdc_Char)0x74,  /* [2550] */
    (xdc_Char)0x65,  /* [2551] */
    (xdc_Char)0x72,  /* [2552] */
    (xdc_Char)0x65,  /* [2553] */
    (xdc_Char)0x64,  /* [2554] */
    (xdc_Char)0x0,  /* [2555] */
    (xdc_Char)0x41,  /* [2556] */
    (xdc_Char)0x5f,  /* [2557] */
    (xdc_Char)0x69,  /* [2558] */
    (xdc_Char)0x6e,  /* [2559] */
    (xdc_Char)0x76,  /* [2560] */
    (xdc_Char)0x61,  /* [2561] */
    (xdc_Char)0x6c,  /* [2562] */
    (xdc_Char)0x69,  /* [2563] */
    (xdc_Char)0x64,  /* [2564] */
    (xdc_Char)0x55,  /* [2565] */
    (xdc_Char)0x6e,  /* [2566] */
    (xdc_Char)0x62,  /* [2567] */
    (xdc_Char)0x6c,  /* [2568] */
    (xdc_Char)0x6f,  /* [2569] */
    (xdc_Char)0x63,  /* [2570] */
    (xdc_Char)0x6b,  /* [2571] */
    (xdc_Char)0x3a,  /* [2572] */
    (xdc_Char)0x20,  /* [2573] */
    (xdc_Char)0x54,  /* [2574] */
    (xdc_Char)0x72,  /* [2575] */
    (xdc_Char)0x79,  /* [2576] */
    (xdc_Char)0x69,  /* [2577] */
    (xdc_Char)0x6e,  /* [2578] */
    (xdc_Char)0x67,  /* [2579] */
    (xdc_Char)0x20,  /* [2580] */
    (xdc_Char)0x74,  /* [2581] */
    (xdc_Char)0x6f,  /* [2582] */
    (xdc_Char)0x20,  /* [2583] */
    (xdc_Char)0x75,  /* [2584] */
    (xdc_Char)0x6e,  /* [2585] */
    (xdc_Char)0x62,  /* [2586] */
    (xdc_Char)0x6c,  /* [2587] */
    (xdc_Char)0x6f,  /* [2588] */
    (xdc_Char)0x63,  /* [2589] */
    (xdc_Char)0x6b,  /* [2590] */
    (xdc_Char)0x20,  /* [2591] */
    (xdc_Char)0x61,  /* [2592] */
    (xdc_Char)0x20,  /* [2593] */
    (xdc_Char)0x72,  /* [2594] */
    (xdc_Char)0x65,  /* [2595] */
    (xdc_Char)0x6d,  /* [2596] */
    (xdc_Char)0x6f,  /* [2597] */
    (xdc_Char)0x74,  /* [2598] */
    (xdc_Char)0x65,  /* [2599] */
    (xdc_Char)0x20,  /* [2600] */
    (xdc_Char)0x4d,  /* [2601] */
    (xdc_Char)0x65,  /* [2602] */
    (xdc_Char)0x73,  /* [2603] */
    (xdc_Char)0x73,  /* [2604] */
    (xdc_Char)0x61,  /* [2605] */
    (xdc_Char)0x67,  /* [2606] */
    (xdc_Char)0x65,  /* [2607] */
    (xdc_Char)0x51,  /* [2608] */
    (xdc_Char)0x20,  /* [2609] */
    (xdc_Char)0x6f,  /* [2610] */
    (xdc_Char)0x72,  /* [2611] */
    (xdc_Char)0x20,  /* [2612] */
    (xdc_Char)0x61,  /* [2613] */
    (xdc_Char)0x20,  /* [2614] */
    (xdc_Char)0x71,  /* [2615] */
    (xdc_Char)0x75,  /* [2616] */
    (xdc_Char)0x65,  /* [2617] */
    (xdc_Char)0x75,  /* [2618] */
    (xdc_Char)0x65,  /* [2619] */
    (xdc_Char)0x20,  /* [2620] */
    (xdc_Char)0x77,  /* [2621] */
    (xdc_Char)0x69,  /* [2622] */
    (xdc_Char)0x74,  /* [2623] */
    (xdc_Char)0x68,  /* [2624] */
    (xdc_Char)0x20,  /* [2625] */
    (xdc_Char)0x6e,  /* [2626] */
    (xdc_Char)0x6f,  /* [2627] */
    (xdc_Char)0x6e,  /* [2628] */
    (xdc_Char)0x2d,  /* [2629] */
    (xdc_Char)0x62,  /* [2630] */
    (xdc_Char)0x6c,  /* [2631] */
    (xdc_Char)0x6f,  /* [2632] */
    (xdc_Char)0x63,  /* [2633] */
    (xdc_Char)0x6b,  /* [2634] */
    (xdc_Char)0x69,  /* [2635] */
    (xdc_Char)0x6e,  /* [2636] */
    (xdc_Char)0x67,  /* [2637] */
    (xdc_Char)0x20,  /* [2638] */
    (xdc_Char)0x73,  /* [2639] */
    (xdc_Char)0x79,  /* [2640] */
    (xdc_Char)0x6e,  /* [2641] */
    (xdc_Char)0x63,  /* [2642] */
    (xdc_Char)0x68,  /* [2643] */
    (xdc_Char)0x72,  /* [2644] */
    (xdc_Char)0x6f,  /* [2645] */
    (xdc_Char)0x6e,  /* [2646] */
    (xdc_Char)0x69,  /* [2647] */
    (xdc_Char)0x7a,  /* [2648] */
    (xdc_Char)0x65,  /* [2649] */
    (xdc_Char)0x72,  /* [2650] */
    (xdc_Char)0x0,  /* [2651] */
    (xdc_Char)0x41,  /* [2652] */
    (xdc_Char)0x5f,  /* [2653] */
    (xdc_Char)0x69,  /* [2654] */
    (xdc_Char)0x64,  /* [2655] */
    (xdc_Char)0x54,  /* [2656] */
    (xdc_Char)0x6f,  /* [2657] */
    (xdc_Char)0x6f,  /* [2658] */
    (xdc_Char)0x4c,  /* [2659] */
    (xdc_Char)0x61,  /* [2660] */
    (xdc_Char)0x72,  /* [2661] */
    (xdc_Char)0x67,  /* [2662] */
    (xdc_Char)0x65,  /* [2663] */
    (xdc_Char)0x3a,  /* [2664] */
    (xdc_Char)0x20,  /* [2665] */
    (xdc_Char)0x69,  /* [2666] */
    (xdc_Char)0x64,  /* [2667] */
    (xdc_Char)0x20,  /* [2668] */
    (xdc_Char)0x63,  /* [2669] */
    (xdc_Char)0x61,  /* [2670] */
    (xdc_Char)0x6e,  /* [2671] */
    (xdc_Char)0x6e,  /* [2672] */
    (xdc_Char)0x6f,  /* [2673] */
    (xdc_Char)0x74,  /* [2674] */
    (xdc_Char)0x20,  /* [2675] */
    (xdc_Char)0x62,  /* [2676] */
    (xdc_Char)0x65,  /* [2677] */
    (xdc_Char)0x20,  /* [2678] */
    (xdc_Char)0x6c,  /* [2679] */
    (xdc_Char)0x61,  /* [2680] */
    (xdc_Char)0x72,  /* [2681] */
    (xdc_Char)0x67,  /* [2682] */
    (xdc_Char)0x65,  /* [2683] */
    (xdc_Char)0x72,  /* [2684] */
    (xdc_Char)0x20,  /* [2685] */
    (xdc_Char)0x74,  /* [2686] */
    (xdc_Char)0x68,  /* [2687] */
    (xdc_Char)0x61,  /* [2688] */
    (xdc_Char)0x6e,  /* [2689] */
    (xdc_Char)0x20,  /* [2690] */
    (xdc_Char)0x6e,  /* [2691] */
    (xdc_Char)0x75,  /* [2692] */
    (xdc_Char)0x6d,  /* [2693] */
    (xdc_Char)0x45,  /* [2694] */
    (xdc_Char)0x6e,  /* [2695] */
    (xdc_Char)0x74,  /* [2696] */
    (xdc_Char)0x72,  /* [2697] */
    (xdc_Char)0x69,  /* [2698] */
    (xdc_Char)0x65,  /* [2699] */
    (xdc_Char)0x73,  /* [2700] */
    (xdc_Char)0x0,  /* [2701] */
    (xdc_Char)0x41,  /* [2702] */
    (xdc_Char)0x5f,  /* [2703] */
    (xdc_Char)0x61,  /* [2704] */
    (xdc_Char)0x64,  /* [2705] */
    (xdc_Char)0x64,  /* [2706] */
    (xdc_Char)0x72,  /* [2707] */
    (xdc_Char)0x4f,  /* [2708] */
    (xdc_Char)0x75,  /* [2709] */
    (xdc_Char)0x74,  /* [2710] */
    (xdc_Char)0x4f,  /* [2711] */
    (xdc_Char)0x66,  /* [2712] */
    (xdc_Char)0x52,  /* [2713] */
    (xdc_Char)0x61,  /* [2714] */
    (xdc_Char)0x6e,  /* [2715] */
    (xdc_Char)0x67,  /* [2716] */
    (xdc_Char)0x65,  /* [2717] */
    (xdc_Char)0x3a,  /* [2718] */
    (xdc_Char)0x20,  /* [2719] */
    (xdc_Char)0x41,  /* [2720] */
    (xdc_Char)0x64,  /* [2721] */
    (xdc_Char)0x64,  /* [2722] */
    (xdc_Char)0x72,  /* [2723] */
    (xdc_Char)0x65,  /* [2724] */
    (xdc_Char)0x73,  /* [2725] */
    (xdc_Char)0x73,  /* [2726] */
    (xdc_Char)0x20,  /* [2727] */
    (xdc_Char)0x69,  /* [2728] */
    (xdc_Char)0x73,  /* [2729] */
    (xdc_Char)0x20,  /* [2730] */
    (xdc_Char)0x6f,  /* [2731] */
    (xdc_Char)0x75,  /* [2732] */
    (xdc_Char)0x74,  /* [2733] */
    (xdc_Char)0x20,  /* [2734] */
    (xdc_Char)0x6f,  /* [2735] */
    (xdc_Char)0x66,  /* [2736] */
    (xdc_Char)0x20,  /* [2737] */
    (xdc_Char)0x72,  /* [2738] */
    (xdc_Char)0x65,  /* [2739] */
    (xdc_Char)0x67,  /* [2740] */
    (xdc_Char)0x69,  /* [2741] */
    (xdc_Char)0x6f,  /* [2742] */
    (xdc_Char)0x6e,  /* [2743] */
    (xdc_Char)0x20,  /* [2744] */
    (xdc_Char)0x69,  /* [2745] */
    (xdc_Char)0x64,  /* [2746] */
    (xdc_Char)0x27,  /* [2747] */
    (xdc_Char)0x73,  /* [2748] */
    (xdc_Char)0x20,  /* [2749] */
    (xdc_Char)0x72,  /* [2750] */
    (xdc_Char)0x61,  /* [2751] */
    (xdc_Char)0x6e,  /* [2752] */
    (xdc_Char)0x67,  /* [2753] */
    (xdc_Char)0x65,  /* [2754] */
    (xdc_Char)0x0,  /* [2755] */
    (xdc_Char)0x41,  /* [2756] */
    (xdc_Char)0x5f,  /* [2757] */
    (xdc_Char)0x72,  /* [2758] */
    (xdc_Char)0x65,  /* [2759] */
    (xdc_Char)0x67,  /* [2760] */
    (xdc_Char)0x69,  /* [2761] */
    (xdc_Char)0x6f,  /* [2762] */
    (xdc_Char)0x6e,  /* [2763] */
    (xdc_Char)0x30,  /* [2764] */
    (xdc_Char)0x43,  /* [2765] */
    (xdc_Char)0x6c,  /* [2766] */
    (xdc_Char)0x65,  /* [2767] */
    (xdc_Char)0x61,  /* [2768] */
    (xdc_Char)0x72,  /* [2769] */
    (xdc_Char)0x3a,  /* [2770] */
    (xdc_Char)0x20,  /* [2771] */
    (xdc_Char)0x52,  /* [2772] */
    (xdc_Char)0x65,  /* [2773] */
    (xdc_Char)0x67,  /* [2774] */
    (xdc_Char)0x69,  /* [2775] */
    (xdc_Char)0x6f,  /* [2776] */
    (xdc_Char)0x6e,  /* [2777] */
    (xdc_Char)0x20,  /* [2778] */
    (xdc_Char)0x30,  /* [2779] */
    (xdc_Char)0x20,  /* [2780] */
    (xdc_Char)0x63,  /* [2781] */
    (xdc_Char)0x61,  /* [2782] */
    (xdc_Char)0x6e,  /* [2783] */
    (xdc_Char)0x6e,  /* [2784] */
    (xdc_Char)0x6f,  /* [2785] */
    (xdc_Char)0x74,  /* [2786] */
    (xdc_Char)0x20,  /* [2787] */
    (xdc_Char)0x62,  /* [2788] */
    (xdc_Char)0x65,  /* [2789] */
    (xdc_Char)0x20,  /* [2790] */
    (xdc_Char)0x63,  /* [2791] */
    (xdc_Char)0x6c,  /* [2792] */
    (xdc_Char)0x65,  /* [2793] */
    (xdc_Char)0x61,  /* [2794] */
    (xdc_Char)0x72,  /* [2795] */
    (xdc_Char)0x65,  /* [2796] */
    (xdc_Char)0x64,  /* [2797] */
    (xdc_Char)0x0,  /* [2798] */
    (xdc_Char)0x41,  /* [2799] */
    (xdc_Char)0x5f,  /* [2800] */
    (xdc_Char)0x72,  /* [2801] */
    (xdc_Char)0x65,  /* [2802] */
    (xdc_Char)0x67,  /* [2803] */
    (xdc_Char)0x69,  /* [2804] */
    (xdc_Char)0x6f,  /* [2805] */
    (xdc_Char)0x6e,  /* [2806] */
    (xdc_Char)0x30,  /* [2807] */
    (xdc_Char)0x49,  /* [2808] */
    (xdc_Char)0x6e,  /* [2809] */
    (xdc_Char)0x76,  /* [2810] */
    (xdc_Char)0x61,  /* [2811] */
    (xdc_Char)0x6c,  /* [2812] */
    (xdc_Char)0x69,  /* [2813] */
    (xdc_Char)0x64,  /* [2814] */
    (xdc_Char)0x3a,  /* [2815] */
    (xdc_Char)0x20,  /* [2816] */
    (xdc_Char)0x52,  /* [2817] */
    (xdc_Char)0x65,  /* [2818] */
    (xdc_Char)0x67,  /* [2819] */
    (xdc_Char)0x69,  /* [2820] */
    (xdc_Char)0x6f,  /* [2821] */
    (xdc_Char)0x6e,  /* [2822] */
    (xdc_Char)0x20,  /* [2823] */
    (xdc_Char)0x7a,  /* [2824] */
    (xdc_Char)0x65,  /* [2825] */
    (xdc_Char)0x72,  /* [2826] */
    (xdc_Char)0x6f,  /* [2827] */
    (xdc_Char)0x20,  /* [2828] */
    (xdc_Char)0x69,  /* [2829] */
    (xdc_Char)0x73,  /* [2830] */
    (xdc_Char)0x20,  /* [2831] */
    (xdc_Char)0x69,  /* [2832] */
    (xdc_Char)0x6e,  /* [2833] */
    (xdc_Char)0x76,  /* [2834] */
    (xdc_Char)0x61,  /* [2835] */
    (xdc_Char)0x6c,  /* [2836] */
    (xdc_Char)0x69,  /* [2837] */
    (xdc_Char)0x64,  /* [2838] */
    (xdc_Char)0x0,  /* [2839] */
    (xdc_Char)0x41,  /* [2840] */
    (xdc_Char)0x5f,  /* [2841] */
    (xdc_Char)0x72,  /* [2842] */
    (xdc_Char)0x65,  /* [2843] */
    (xdc_Char)0x67,  /* [2844] */
    (xdc_Char)0x69,  /* [2845] */
    (xdc_Char)0x6f,  /* [2846] */
    (xdc_Char)0x6e,  /* [2847] */
    (xdc_Char)0x49,  /* [2848] */
    (xdc_Char)0x6e,  /* [2849] */
    (xdc_Char)0x76,  /* [2850] */
    (xdc_Char)0x61,  /* [2851] */
    (xdc_Char)0x6c,  /* [2852] */
    (xdc_Char)0x69,  /* [2853] */
    (xdc_Char)0x64,  /* [2854] */
    (xdc_Char)0x3a,  /* [2855] */
    (xdc_Char)0x20,  /* [2856] */
    (xdc_Char)0x52,  /* [2857] */
    (xdc_Char)0x65,  /* [2858] */
    (xdc_Char)0x67,  /* [2859] */
    (xdc_Char)0x69,  /* [2860] */
    (xdc_Char)0x6f,  /* [2861] */
    (xdc_Char)0x6e,  /* [2862] */
    (xdc_Char)0x20,  /* [2863] */
    (xdc_Char)0x69,  /* [2864] */
    (xdc_Char)0x73,  /* [2865] */
    (xdc_Char)0x20,  /* [2866] */
    (xdc_Char)0x69,  /* [2867] */
    (xdc_Char)0x6e,  /* [2868] */
    (xdc_Char)0x76,  /* [2869] */
    (xdc_Char)0x61,  /* [2870] */
    (xdc_Char)0x6c,  /* [2871] */
    (xdc_Char)0x69,  /* [2872] */
    (xdc_Char)0x64,  /* [2873] */
    (xdc_Char)0x0,  /* [2874] */
    (xdc_Char)0x41,  /* [2875] */
    (xdc_Char)0x5f,  /* [2876] */
    (xdc_Char)0x72,  /* [2877] */
    (xdc_Char)0x65,  /* [2878] */
    (xdc_Char)0x73,  /* [2879] */
    (xdc_Char)0x65,  /* [2880] */
    (xdc_Char)0x72,  /* [2881] */
    (xdc_Char)0x76,  /* [2882] */
    (xdc_Char)0x65,  /* [2883] */
    (xdc_Char)0x54,  /* [2884] */
    (xdc_Char)0x6f,  /* [2885] */
    (xdc_Char)0x6f,  /* [2886] */
    (xdc_Char)0x4d,  /* [2887] */
    (xdc_Char)0x75,  /* [2888] */
    (xdc_Char)0x63,  /* [2889] */
    (xdc_Char)0x68,  /* [2890] */
    (xdc_Char)0x3a,  /* [2891] */
    (xdc_Char)0x20,  /* [2892] */
    (xdc_Char)0x54,  /* [2893] */
    (xdc_Char)0x72,  /* [2894] */
    (xdc_Char)0x79,  /* [2895] */
    (xdc_Char)0x69,  /* [2896] */
    (xdc_Char)0x6e,  /* [2897] */
    (xdc_Char)0x67,  /* [2898] */
    (xdc_Char)0x20,  /* [2899] */
    (xdc_Char)0x74,  /* [2900] */
    (xdc_Char)0x6f,  /* [2901] */
    (xdc_Char)0x20,  /* [2902] */
    (xdc_Char)0x72,  /* [2903] */
    (xdc_Char)0x65,  /* [2904] */
    (xdc_Char)0x73,  /* [2905] */
    (xdc_Char)0x65,  /* [2906] */
    (xdc_Char)0x72,  /* [2907] */
    (xdc_Char)0x76,  /* [2908] */
    (xdc_Char)0x65,  /* [2909] */
    (xdc_Char)0x20,  /* [2910] */
    (xdc_Char)0x74,  /* [2911] */
    (xdc_Char)0x6f,  /* [2912] */
    (xdc_Char)0x6f,  /* [2913] */
    (xdc_Char)0x20,  /* [2914] */
    (xdc_Char)0x6d,  /* [2915] */
    (xdc_Char)0x75,  /* [2916] */
    (xdc_Char)0x63,  /* [2917] */
    (xdc_Char)0x68,  /* [2918] */
    (xdc_Char)0x20,  /* [2919] */
    (xdc_Char)0x6d,  /* [2920] */
    (xdc_Char)0x65,  /* [2921] */
    (xdc_Char)0x6d,  /* [2922] */
    (xdc_Char)0x6f,  /* [2923] */
    (xdc_Char)0x72,  /* [2924] */
    (xdc_Char)0x79,  /* [2925] */
    (xdc_Char)0x0,  /* [2926] */
    (xdc_Char)0x41,  /* [2927] */
    (xdc_Char)0x5f,  /* [2928] */
    (xdc_Char)0x63,  /* [2929] */
    (xdc_Char)0x61,  /* [2930] */
    (xdc_Char)0x63,  /* [2931] */
    (xdc_Char)0x68,  /* [2932] */
    (xdc_Char)0x65,  /* [2933] */
    (xdc_Char)0x4c,  /* [2934] */
    (xdc_Char)0x69,  /* [2935] */
    (xdc_Char)0x6e,  /* [2936] */
    (xdc_Char)0x65,  /* [2937] */
    (xdc_Char)0x53,  /* [2938] */
    (xdc_Char)0x69,  /* [2939] */
    (xdc_Char)0x7a,  /* [2940] */
    (xdc_Char)0x65,  /* [2941] */
    (xdc_Char)0x49,  /* [2942] */
    (xdc_Char)0x73,  /* [2943] */
    (xdc_Char)0x5a,  /* [2944] */
    (xdc_Char)0x65,  /* [2945] */
    (xdc_Char)0x72,  /* [2946] */
    (xdc_Char)0x6f,  /* [2947] */
    (xdc_Char)0x3a,  /* [2948] */
    (xdc_Char)0x20,  /* [2949] */
    (xdc_Char)0x63,  /* [2950] */
    (xdc_Char)0x61,  /* [2951] */
    (xdc_Char)0x63,  /* [2952] */
    (xdc_Char)0x68,  /* [2953] */
    (xdc_Char)0x65,  /* [2954] */
    (xdc_Char)0x20,  /* [2955] */
    (xdc_Char)0x6c,  /* [2956] */
    (xdc_Char)0x69,  /* [2957] */
    (xdc_Char)0x6e,  /* [2958] */
    (xdc_Char)0x65,  /* [2959] */
    (xdc_Char)0x20,  /* [2960] */
    (xdc_Char)0x73,  /* [2961] */
    (xdc_Char)0x69,  /* [2962] */
    (xdc_Char)0x7a,  /* [2963] */
    (xdc_Char)0x65,  /* [2964] */
    (xdc_Char)0x20,  /* [2965] */
    (xdc_Char)0x63,  /* [2966] */
    (xdc_Char)0x61,  /* [2967] */
    (xdc_Char)0x6e,  /* [2968] */
    (xdc_Char)0x6e,  /* [2969] */
    (xdc_Char)0x6f,  /* [2970] */
    (xdc_Char)0x74,  /* [2971] */
    (xdc_Char)0x20,  /* [2972] */
    (xdc_Char)0x62,  /* [2973] */
    (xdc_Char)0x65,  /* [2974] */
    (xdc_Char)0x20,  /* [2975] */
    (xdc_Char)0x7a,  /* [2976] */
    (xdc_Char)0x65,  /* [2977] */
    (xdc_Char)0x72,  /* [2978] */
    (xdc_Char)0x6f,  /* [2979] */
    (xdc_Char)0x0,  /* [2980] */
    (xdc_Char)0x41,  /* [2981] */
    (xdc_Char)0x5f,  /* [2982] */
    (xdc_Char)0x6f,  /* [2983] */
    (xdc_Char)0x76,  /* [2984] */
    (xdc_Char)0x65,  /* [2985] */
    (xdc_Char)0x72,  /* [2986] */
    (xdc_Char)0x6c,  /* [2987] */
    (xdc_Char)0x61,  /* [2988] */
    (xdc_Char)0x70,  /* [2989] */
    (xdc_Char)0x3a,  /* [2990] */
    (xdc_Char)0x20,  /* [2991] */
    (xdc_Char)0x53,  /* [2992] */
    (xdc_Char)0x68,  /* [2993] */
    (xdc_Char)0x61,  /* [2994] */
    (xdc_Char)0x72,  /* [2995] */
    (xdc_Char)0x65,  /* [2996] */
    (xdc_Char)0x64,  /* [2997] */
    (xdc_Char)0x20,  /* [2998] */
    (xdc_Char)0x72,  /* [2999] */
    (xdc_Char)0x65,  /* [3000] */
    (xdc_Char)0x67,  /* [3001] */
    (xdc_Char)0x69,  /* [3002] */
    (xdc_Char)0x6f,  /* [3003] */
    (xdc_Char)0x6e,  /* [3004] */
    (xdc_Char)0x20,  /* [3005] */
    (xdc_Char)0x6f,  /* [3006] */
    (xdc_Char)0x76,  /* [3007] */
    (xdc_Char)0x65,  /* [3008] */
    (xdc_Char)0x72,  /* [3009] */
    (xdc_Char)0x6c,  /* [3010] */
    (xdc_Char)0x61,  /* [3011] */
    (xdc_Char)0x70,  /* [3012] */
    (xdc_Char)0x73,  /* [3013] */
    (xdc_Char)0x0,  /* [3014] */
    (xdc_Char)0x41,  /* [3015] */
    (xdc_Char)0x5f,  /* [3016] */
    (xdc_Char)0x61,  /* [3017] */
    (xdc_Char)0x6c,  /* [3018] */
    (xdc_Char)0x72,  /* [3019] */
    (xdc_Char)0x65,  /* [3020] */
    (xdc_Char)0x61,  /* [3021] */
    (xdc_Char)0x64,  /* [3022] */
    (xdc_Char)0x79,  /* [3023] */
    (xdc_Char)0x45,  /* [3024] */
    (xdc_Char)0x78,  /* [3025] */
    (xdc_Char)0x69,  /* [3026] */
    (xdc_Char)0x73,  /* [3027] */
    (xdc_Char)0x74,  /* [3028] */
    (xdc_Char)0x73,  /* [3029] */
    (xdc_Char)0x3a,  /* [3030] */
    (xdc_Char)0x20,  /* [3031] */
    (xdc_Char)0x54,  /* [3032] */
    (xdc_Char)0x72,  /* [3033] */
    (xdc_Char)0x79,  /* [3034] */
    (xdc_Char)0x69,  /* [3035] */
    (xdc_Char)0x6e,  /* [3036] */
    (xdc_Char)0x67,  /* [3037] */
    (xdc_Char)0x20,  /* [3038] */
    (xdc_Char)0x74,  /* [3039] */
    (xdc_Char)0x6f,  /* [3040] */
    (xdc_Char)0x20,  /* [3041] */
    (xdc_Char)0x6f,  /* [3042] */
    (xdc_Char)0x76,  /* [3043] */
    (xdc_Char)0x65,  /* [3044] */
    (xdc_Char)0x72,  /* [3045] */
    (xdc_Char)0x77,  /* [3046] */
    (xdc_Char)0x72,  /* [3047] */
    (xdc_Char)0x69,  /* [3048] */
    (xdc_Char)0x74,  /* [3049] */
    (xdc_Char)0x65,  /* [3050] */
    (xdc_Char)0x20,  /* [3051] */
    (xdc_Char)0x61,  /* [3052] */
    (xdc_Char)0x6e,  /* [3053] */
    (xdc_Char)0x20,  /* [3054] */
    (xdc_Char)0x65,  /* [3055] */
    (xdc_Char)0x78,  /* [3056] */
    (xdc_Char)0x69,  /* [3057] */
    (xdc_Char)0x73,  /* [3058] */
    (xdc_Char)0x74,  /* [3059] */
    (xdc_Char)0x69,  /* [3060] */
    (xdc_Char)0x6e,  /* [3061] */
    (xdc_Char)0x67,  /* [3062] */
    (xdc_Char)0x20,  /* [3063] */
    (xdc_Char)0x76,  /* [3064] */
    (xdc_Char)0x61,  /* [3065] */
    (xdc_Char)0x6c,  /* [3066] */
    (xdc_Char)0x69,  /* [3067] */
    (xdc_Char)0x64,  /* [3068] */
    (xdc_Char)0x20,  /* [3069] */
    (xdc_Char)0x65,  /* [3070] */
    (xdc_Char)0x6e,  /* [3071] */
    (xdc_Char)0x74,  /* [3072] */
    (xdc_Char)0x72,  /* [3073] */
    (xdc_Char)0x79,  /* [3074] */
    (xdc_Char)0x0,  /* [3075] */
    (xdc_Char)0x41,  /* [3076] */
    (xdc_Char)0x5f,  /* [3077] */
    (xdc_Char)0x6e,  /* [3078] */
    (xdc_Char)0x6f,  /* [3079] */
    (xdc_Char)0x48,  /* [3080] */
    (xdc_Char)0x65,  /* [3081] */
    (xdc_Char)0x61,  /* [3082] */
    (xdc_Char)0x70,  /* [3083] */
    (xdc_Char)0x3a,  /* [3084] */
    (xdc_Char)0x20,  /* [3085] */
    (xdc_Char)0x52,  /* [3086] */
    (xdc_Char)0x65,  /* [3087] */
    (xdc_Char)0x67,  /* [3088] */
    (xdc_Char)0x69,  /* [3089] */
    (xdc_Char)0x6f,  /* [3090] */
    (xdc_Char)0x6e,  /* [3091] */
    (xdc_Char)0x20,  /* [3092] */
    (xdc_Char)0x68,  /* [3093] */
    (xdc_Char)0x61,  /* [3094] */
    (xdc_Char)0x73,  /* [3095] */
    (xdc_Char)0x20,  /* [3096] */
    (xdc_Char)0x6e,  /* [3097] */
    (xdc_Char)0x6f,  /* [3098] */
    (xdc_Char)0x20,  /* [3099] */
    (xdc_Char)0x68,  /* [3100] */
    (xdc_Char)0x65,  /* [3101] */
    (xdc_Char)0x61,  /* [3102] */
    (xdc_Char)0x70,  /* [3103] */
    (xdc_Char)0x0,  /* [3104] */
    (xdc_Char)0x41,  /* [3105] */
    (xdc_Char)0x5f,  /* [3106] */
    (xdc_Char)0x61,  /* [3107] */
    (xdc_Char)0x64,  /* [3108] */
    (xdc_Char)0x64,  /* [3109] */
    (xdc_Char)0x72,  /* [3110] */
    (xdc_Char)0x4e,  /* [3111] */
    (xdc_Char)0x6f,  /* [3112] */
    (xdc_Char)0x74,  /* [3113] */
    (xdc_Char)0x49,  /* [3114] */
    (xdc_Char)0x6e,  /* [3115] */
    (xdc_Char)0x53,  /* [3116] */
    (xdc_Char)0x68,  /* [3117] */
    (xdc_Char)0x61,  /* [3118] */
    (xdc_Char)0x72,  /* [3119] */
    (xdc_Char)0x65,  /* [3120] */
    (xdc_Char)0x64,  /* [3121] */
    (xdc_Char)0x52,  /* [3122] */
    (xdc_Char)0x65,  /* [3123] */
    (xdc_Char)0x67,  /* [3124] */
    (xdc_Char)0x69,  /* [3125] */
    (xdc_Char)0x6f,  /* [3126] */
    (xdc_Char)0x6e,  /* [3127] */
    (xdc_Char)0x3a,  /* [3128] */
    (xdc_Char)0x20,  /* [3129] */
    (xdc_Char)0x41,  /* [3130] */
    (xdc_Char)0x64,  /* [3131] */
    (xdc_Char)0x64,  /* [3132] */
    (xdc_Char)0x72,  /* [3133] */
    (xdc_Char)0x65,  /* [3134] */
    (xdc_Char)0x73,  /* [3135] */
    (xdc_Char)0x73,  /* [3136] */
    (xdc_Char)0x20,  /* [3137] */
    (xdc_Char)0x6e,  /* [3138] */
    (xdc_Char)0x6f,  /* [3139] */
    (xdc_Char)0x74,  /* [3140] */
    (xdc_Char)0x20,  /* [3141] */
    (xdc_Char)0x69,  /* [3142] */
    (xdc_Char)0x6e,  /* [3143] */
    (xdc_Char)0x20,  /* [3144] */
    (xdc_Char)0x61,  /* [3145] */
    (xdc_Char)0x6e,  /* [3146] */
    (xdc_Char)0x79,  /* [3147] */
    (xdc_Char)0x20,  /* [3148] */
    (xdc_Char)0x73,  /* [3149] */
    (xdc_Char)0x68,  /* [3150] */
    (xdc_Char)0x61,  /* [3151] */
    (xdc_Char)0x72,  /* [3152] */
    (xdc_Char)0x65,  /* [3153] */
    (xdc_Char)0x64,  /* [3154] */
    (xdc_Char)0x20,  /* [3155] */
    (xdc_Char)0x72,  /* [3156] */
    (xdc_Char)0x65,  /* [3157] */
    (xdc_Char)0x67,  /* [3158] */
    (xdc_Char)0x69,  /* [3159] */
    (xdc_Char)0x6f,  /* [3160] */
    (xdc_Char)0x6e,  /* [3161] */
    (xdc_Char)0x0,  /* [3162] */
    (xdc_Char)0x41,  /* [3163] */
    (xdc_Char)0x5f,  /* [3164] */
    (xdc_Char)0x61,  /* [3165] */
    (xdc_Char)0x64,  /* [3166] */
    (xdc_Char)0x64,  /* [3167] */
    (xdc_Char)0x72,  /* [3168] */
    (xdc_Char)0x4e,  /* [3169] */
    (xdc_Char)0x6f,  /* [3170] */
    (xdc_Char)0x74,  /* [3171] */
    (xdc_Char)0x43,  /* [3172] */
    (xdc_Char)0x61,  /* [3173] */
    (xdc_Char)0x63,  /* [3174] */
    (xdc_Char)0x68,  /* [3175] */
    (xdc_Char)0x65,  /* [3176] */
    (xdc_Char)0x41,  /* [3177] */
    (xdc_Char)0x6c,  /* [3178] */
    (xdc_Char)0x69,  /* [3179] */
    (xdc_Char)0x67,  /* [3180] */
    (xdc_Char)0x6e,  /* [3181] */
    (xdc_Char)0x65,  /* [3182] */
    (xdc_Char)0x64,  /* [3183] */
    (xdc_Char)0x3a,  /* [3184] */
    (xdc_Char)0x20,  /* [3185] */
    (xdc_Char)0x41,  /* [3186] */
    (xdc_Char)0x64,  /* [3187] */
    (xdc_Char)0x64,  /* [3188] */
    (xdc_Char)0x72,  /* [3189] */
    (xdc_Char)0x65,  /* [3190] */
    (xdc_Char)0x73,  /* [3191] */
    (xdc_Char)0x73,  /* [3192] */
    (xdc_Char)0x20,  /* [3193] */
    (xdc_Char)0x69,  /* [3194] */
    (xdc_Char)0x73,  /* [3195] */
    (xdc_Char)0x20,  /* [3196] */
    (xdc_Char)0x6e,  /* [3197] */
    (xdc_Char)0x6f,  /* [3198] */
    (xdc_Char)0x74,  /* [3199] */
    (xdc_Char)0x20,  /* [3200] */
    (xdc_Char)0x63,  /* [3201] */
    (xdc_Char)0x61,  /* [3202] */
    (xdc_Char)0x63,  /* [3203] */
    (xdc_Char)0x68,  /* [3204] */
    (xdc_Char)0x65,  /* [3205] */
    (xdc_Char)0x20,  /* [3206] */
    (xdc_Char)0x61,  /* [3207] */
    (xdc_Char)0x6c,  /* [3208] */
    (xdc_Char)0x69,  /* [3209] */
    (xdc_Char)0x67,  /* [3210] */
    (xdc_Char)0x6e,  /* [3211] */
    (xdc_Char)0x65,  /* [3212] */
    (xdc_Char)0x64,  /* [3213] */
    (xdc_Char)0x0,  /* [3214] */
    (xdc_Char)0x41,  /* [3215] */
    (xdc_Char)0x5f,  /* [3216] */
    (xdc_Char)0x6e,  /* [3217] */
    (xdc_Char)0x75,  /* [3218] */
    (xdc_Char)0x6c,  /* [3219] */
    (xdc_Char)0x6c,  /* [3220] */
    (xdc_Char)0x41,  /* [3221] */
    (xdc_Char)0x72,  /* [3222] */
    (xdc_Char)0x67,  /* [3223] */
    (xdc_Char)0x75,  /* [3224] */
    (xdc_Char)0x6d,  /* [3225] */
    (xdc_Char)0x65,  /* [3226] */
    (xdc_Char)0x6e,  /* [3227] */
    (xdc_Char)0x74,  /* [3228] */
    (xdc_Char)0x3a,  /* [3229] */
    (xdc_Char)0x20,  /* [3230] */
    (xdc_Char)0x52,  /* [3231] */
    (xdc_Char)0x65,  /* [3232] */
    (xdc_Char)0x71,  /* [3233] */
    (xdc_Char)0x75,  /* [3234] */
    (xdc_Char)0x69,  /* [3235] */
    (xdc_Char)0x72,  /* [3236] */
    (xdc_Char)0x65,  /* [3237] */
    (xdc_Char)0x64,  /* [3238] */
    (xdc_Char)0x20,  /* [3239] */
    (xdc_Char)0x61,  /* [3240] */
    (xdc_Char)0x72,  /* [3241] */
    (xdc_Char)0x67,  /* [3242] */
    (xdc_Char)0x75,  /* [3243] */
    (xdc_Char)0x6d,  /* [3244] */
    (xdc_Char)0x65,  /* [3245] */
    (xdc_Char)0x6e,  /* [3246] */
    (xdc_Char)0x74,  /* [3247] */
    (xdc_Char)0x20,  /* [3248] */
    (xdc_Char)0x69,  /* [3249] */
    (xdc_Char)0x73,  /* [3250] */
    (xdc_Char)0x20,  /* [3251] */
    (xdc_Char)0x6e,  /* [3252] */
    (xdc_Char)0x75,  /* [3253] */
    (xdc_Char)0x6c,  /* [3254] */
    (xdc_Char)0x6c,  /* [3255] */
    (xdc_Char)0x0,  /* [3256] */
    (xdc_Char)0x41,  /* [3257] */
    (xdc_Char)0x5f,  /* [3258] */
    (xdc_Char)0x6e,  /* [3259] */
    (xdc_Char)0x75,  /* [3260] */
    (xdc_Char)0x6c,  /* [3261] */
    (xdc_Char)0x6c,  /* [3262] */
    (xdc_Char)0x50,  /* [3263] */
    (xdc_Char)0x6f,  /* [3264] */
    (xdc_Char)0x69,  /* [3265] */
    (xdc_Char)0x6e,  /* [3266] */
    (xdc_Char)0x74,  /* [3267] */
    (xdc_Char)0x65,  /* [3268] */
    (xdc_Char)0x72,  /* [3269] */
    (xdc_Char)0x3a,  /* [3270] */
    (xdc_Char)0x20,  /* [3271] */
    (xdc_Char)0x50,  /* [3272] */
    (xdc_Char)0x6f,  /* [3273] */
    (xdc_Char)0x69,  /* [3274] */
    (xdc_Char)0x6e,  /* [3275] */
    (xdc_Char)0x74,  /* [3276] */
    (xdc_Char)0x65,  /* [3277] */
    (xdc_Char)0x72,  /* [3278] */
    (xdc_Char)0x20,  /* [3279] */
    (xdc_Char)0x69,  /* [3280] */
    (xdc_Char)0x73,  /* [3281] */
    (xdc_Char)0x20,  /* [3282] */
    (xdc_Char)0x6e,  /* [3283] */
    (xdc_Char)0x75,  /* [3284] */
    (xdc_Char)0x6c,  /* [3285] */
    (xdc_Char)0x6c,  /* [3286] */
    (xdc_Char)0x0,  /* [3287] */
    (xdc_Char)0x41,  /* [3288] */
    (xdc_Char)0x5f,  /* [3289] */
    (xdc_Char)0x69,  /* [3290] */
    (xdc_Char)0x6e,  /* [3291] */
    (xdc_Char)0x76,  /* [3292] */
    (xdc_Char)0x50,  /* [3293] */
    (xdc_Char)0x61,  /* [3294] */
    (xdc_Char)0x72,  /* [3295] */
    (xdc_Char)0x61,  /* [3296] */
    (xdc_Char)0x6d,  /* [3297] */
    (xdc_Char)0x3a,  /* [3298] */
    (xdc_Char)0x20,  /* [3299] */
    (xdc_Char)0x49,  /* [3300] */
    (xdc_Char)0x6e,  /* [3301] */
    (xdc_Char)0x76,  /* [3302] */
    (xdc_Char)0x61,  /* [3303] */
    (xdc_Char)0x6c,  /* [3304] */
    (xdc_Char)0x69,  /* [3305] */
    (xdc_Char)0x64,  /* [3306] */
    (xdc_Char)0x20,  /* [3307] */
    (xdc_Char)0x63,  /* [3308] */
    (xdc_Char)0x6f,  /* [3309] */
    (xdc_Char)0x6e,  /* [3310] */
    (xdc_Char)0x66,  /* [3311] */
    (xdc_Char)0x69,  /* [3312] */
    (xdc_Char)0x67,  /* [3313] */
    (xdc_Char)0x75,  /* [3314] */
    (xdc_Char)0x72,  /* [3315] */
    (xdc_Char)0x61,  /* [3316] */
    (xdc_Char)0x74,  /* [3317] */
    (xdc_Char)0x69,  /* [3318] */
    (xdc_Char)0x6f,  /* [3319] */
    (xdc_Char)0x6e,  /* [3320] */
    (xdc_Char)0x20,  /* [3321] */
    (xdc_Char)0x70,  /* [3322] */
    (xdc_Char)0x61,  /* [3323] */
    (xdc_Char)0x72,  /* [3324] */
    (xdc_Char)0x61,  /* [3325] */
    (xdc_Char)0x6d,  /* [3326] */
    (xdc_Char)0x65,  /* [3327] */
    (xdc_Char)0x74,  /* [3328] */
    (xdc_Char)0x65,  /* [3329] */
    (xdc_Char)0x72,  /* [3330] */
    (xdc_Char)0x20,  /* [3331] */
    (xdc_Char)0x73,  /* [3332] */
    (xdc_Char)0x75,  /* [3333] */
    (xdc_Char)0x70,  /* [3334] */
    (xdc_Char)0x70,  /* [3335] */
    (xdc_Char)0x6c,  /* [3336] */
    (xdc_Char)0x69,  /* [3337] */
    (xdc_Char)0x65,  /* [3338] */
    (xdc_Char)0x64,  /* [3339] */
    (xdc_Char)0x0,  /* [3340] */
    (xdc_Char)0x41,  /* [3341] */
    (xdc_Char)0x5f,  /* [3342] */
    (xdc_Char)0x69,  /* [3343] */
    (xdc_Char)0x6e,  /* [3344] */
    (xdc_Char)0x74,  /* [3345] */
    (xdc_Char)0x65,  /* [3346] */
    (xdc_Char)0x72,  /* [3347] */
    (xdc_Char)0x6e,  /* [3348] */
    (xdc_Char)0x61,  /* [3349] */
    (xdc_Char)0x6c,  /* [3350] */
    (xdc_Char)0x3a,  /* [3351] */
    (xdc_Char)0x20,  /* [3352] */
    (xdc_Char)0x41,  /* [3353] */
    (xdc_Char)0x6e,  /* [3354] */
    (xdc_Char)0x20,  /* [3355] */
    (xdc_Char)0x69,  /* [3356] */
    (xdc_Char)0x6e,  /* [3357] */
    (xdc_Char)0x74,  /* [3358] */
    (xdc_Char)0x65,  /* [3359] */
    (xdc_Char)0x72,  /* [3360] */
    (xdc_Char)0x6e,  /* [3361] */
    (xdc_Char)0x61,  /* [3362] */
    (xdc_Char)0x6c,  /* [3363] */
    (xdc_Char)0x20,  /* [3364] */
    (xdc_Char)0x65,  /* [3365] */
    (xdc_Char)0x72,  /* [3366] */
    (xdc_Char)0x72,  /* [3367] */
    (xdc_Char)0x6f,  /* [3368] */
    (xdc_Char)0x72,  /* [3369] */
    (xdc_Char)0x20,  /* [3370] */
    (xdc_Char)0x68,  /* [3371] */
    (xdc_Char)0x61,  /* [3372] */
    (xdc_Char)0x73,  /* [3373] */
    (xdc_Char)0x20,  /* [3374] */
    (xdc_Char)0x6f,  /* [3375] */
    (xdc_Char)0x63,  /* [3376] */
    (xdc_Char)0x63,  /* [3377] */
    (xdc_Char)0x75,  /* [3378] */
    (xdc_Char)0x72,  /* [3379] */
    (xdc_Char)0x72,  /* [3380] */
    (xdc_Char)0x65,  /* [3381] */
    (xdc_Char)0x64,  /* [3382] */
    (xdc_Char)0x0,  /* [3383] */
    (xdc_Char)0x41,  /* [3384] */
    (xdc_Char)0x5f,  /* [3385] */
    (xdc_Char)0x61,  /* [3386] */
    (xdc_Char)0x6c,  /* [3387] */
    (xdc_Char)0x72,  /* [3388] */
    (xdc_Char)0x65,  /* [3389] */
    (xdc_Char)0x61,  /* [3390] */
    (xdc_Char)0x64,  /* [3391] */
    (xdc_Char)0x79,  /* [3392] */
    (xdc_Char)0x52,  /* [3393] */
    (xdc_Char)0x65,  /* [3394] */
    (xdc_Char)0x67,  /* [3395] */
    (xdc_Char)0x69,  /* [3396] */
    (xdc_Char)0x73,  /* [3397] */
    (xdc_Char)0x74,  /* [3398] */
    (xdc_Char)0x65,  /* [3399] */
    (xdc_Char)0x72,  /* [3400] */
    (xdc_Char)0x65,  /* [3401] */
    (xdc_Char)0x64,  /* [3402] */
    (xdc_Char)0x3a,  /* [3403] */
    (xdc_Char)0x20,  /* [3404] */
    (xdc_Char)0x4e,  /* [3405] */
    (xdc_Char)0x6f,  /* [3406] */
    (xdc_Char)0x74,  /* [3407] */
    (xdc_Char)0x69,  /* [3408] */
    (xdc_Char)0x66,  /* [3409] */
    (xdc_Char)0x79,  /* [3410] */
    (xdc_Char)0x20,  /* [3411] */
    (xdc_Char)0x69,  /* [3412] */
    (xdc_Char)0x6e,  /* [3413] */
    (xdc_Char)0x73,  /* [3414] */
    (xdc_Char)0x74,  /* [3415] */
    (xdc_Char)0x61,  /* [3416] */
    (xdc_Char)0x6e,  /* [3417] */
    (xdc_Char)0x63,  /* [3418] */
    (xdc_Char)0x65,  /* [3419] */
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
    (xdc_Char)0x20,  /* [3443] */
    (xdc_Char)0x61,  /* [3444] */
    (xdc_Char)0x6c,  /* [3445] */
    (xdc_Char)0x72,  /* [3446] */
    (xdc_Char)0x65,  /* [3447] */
    (xdc_Char)0x61,  /* [3448] */
    (xdc_Char)0x64,  /* [3449] */
    (xdc_Char)0x79,  /* [3450] */
    (xdc_Char)0x20,  /* [3451] */
    (xdc_Char)0x72,  /* [3452] */
    (xdc_Char)0x65,  /* [3453] */
    (xdc_Char)0x67,  /* [3454] */
    (xdc_Char)0x69,  /* [3455] */
    (xdc_Char)0x73,  /* [3456] */
    (xdc_Char)0x74,  /* [3457] */
    (xdc_Char)0x65,  /* [3458] */
    (xdc_Char)0x72,  /* [3459] */
    (xdc_Char)0x65,  /* [3460] */
    (xdc_Char)0x64,  /* [3461] */
    (xdc_Char)0x0,  /* [3462] */
    (xdc_Char)0x41,  /* [3463] */
    (xdc_Char)0x5f,  /* [3464] */
    (xdc_Char)0x6e,  /* [3465] */
    (xdc_Char)0x6f,  /* [3466] */
    (xdc_Char)0x74,  /* [3467] */
    (xdc_Char)0x52,  /* [3468] */
    (xdc_Char)0x65,  /* [3469] */
    (xdc_Char)0x67,  /* [3470] */
    (xdc_Char)0x69,  /* [3471] */
    (xdc_Char)0x73,  /* [3472] */
    (xdc_Char)0x74,  /* [3473] */
    (xdc_Char)0x65,  /* [3474] */
    (xdc_Char)0x72,  /* [3475] */
    (xdc_Char)0x65,  /* [3476] */
    (xdc_Char)0x64,  /* [3477] */
    (xdc_Char)0x3a,  /* [3478] */
    (xdc_Char)0x20,  /* [3479] */
    (xdc_Char)0x4e,  /* [3480] */
    (xdc_Char)0x6f,  /* [3481] */
    (xdc_Char)0x74,  /* [3482] */
    (xdc_Char)0x69,  /* [3483] */
    (xdc_Char)0x66,  /* [3484] */
    (xdc_Char)0x79,  /* [3485] */
    (xdc_Char)0x20,  /* [3486] */
    (xdc_Char)0x69,  /* [3487] */
    (xdc_Char)0x6e,  /* [3488] */
    (xdc_Char)0x73,  /* [3489] */
    (xdc_Char)0x74,  /* [3490] */
    (xdc_Char)0x61,  /* [3491] */
    (xdc_Char)0x6e,  /* [3492] */
    (xdc_Char)0x63,  /* [3493] */
    (xdc_Char)0x65,  /* [3494] */
    (xdc_Char)0x20,  /* [3495] */
    (xdc_Char)0x6e,  /* [3496] */
    (xdc_Char)0x6f,  /* [3497] */
    (xdc_Char)0x74,  /* [3498] */
    (xdc_Char)0x20,  /* [3499] */
    (xdc_Char)0x79,  /* [3500] */
    (xdc_Char)0x65,  /* [3501] */
    (xdc_Char)0x74,  /* [3502] */
    (xdc_Char)0x20,  /* [3503] */
    (xdc_Char)0x72,  /* [3504] */
    (xdc_Char)0x65,  /* [3505] */
    (xdc_Char)0x67,  /* [3506] */
    (xdc_Char)0x69,  /* [3507] */
    (xdc_Char)0x73,  /* [3508] */
    (xdc_Char)0x74,  /* [3509] */
    (xdc_Char)0x65,  /* [3510] */
    (xdc_Char)0x72,  /* [3511] */
    (xdc_Char)0x65,  /* [3512] */
    (xdc_Char)0x64,  /* [3513] */
    (xdc_Char)0x20,  /* [3514] */
    (xdc_Char)0x66,  /* [3515] */
    (xdc_Char)0x6f,  /* [3516] */
    (xdc_Char)0x72,  /* [3517] */
    (xdc_Char)0x20,  /* [3518] */
    (xdc_Char)0x74,  /* [3519] */
    (xdc_Char)0x68,  /* [3520] */
    (xdc_Char)0x65,  /* [3521] */
    (xdc_Char)0x20,  /* [3522] */
    (xdc_Char)0x70,  /* [3523] */
    (xdc_Char)0x72,  /* [3524] */
    (xdc_Char)0x6f,  /* [3525] */
    (xdc_Char)0x63,  /* [3526] */
    (xdc_Char)0x65,  /* [3527] */
    (xdc_Char)0x73,  /* [3528] */
    (xdc_Char)0x73,  /* [3529] */
    (xdc_Char)0x6f,  /* [3530] */
    (xdc_Char)0x72,  /* [3531] */
    (xdc_Char)0x2f,  /* [3532] */
    (xdc_Char)0x6c,  /* [3533] */
    (xdc_Char)0x69,  /* [3534] */
    (xdc_Char)0x6e,  /* [3535] */
    (xdc_Char)0x65,  /* [3536] */
    (xdc_Char)0x0,  /* [3537] */
    (xdc_Char)0x41,  /* [3538] */
    (xdc_Char)0x5f,  /* [3539] */
    (xdc_Char)0x72,  /* [3540] */
    (xdc_Char)0x65,  /* [3541] */
    (xdc_Char)0x73,  /* [3542] */
    (xdc_Char)0x65,  /* [3543] */
    (xdc_Char)0x72,  /* [3544] */
    (xdc_Char)0x76,  /* [3545] */
    (xdc_Char)0x65,  /* [3546] */
    (xdc_Char)0x64,  /* [3547] */
    (xdc_Char)0x45,  /* [3548] */
    (xdc_Char)0x76,  /* [3549] */
    (xdc_Char)0x65,  /* [3550] */
    (xdc_Char)0x6e,  /* [3551] */
    (xdc_Char)0x74,  /* [3552] */
    (xdc_Char)0x3a,  /* [3553] */
    (xdc_Char)0x20,  /* [3554] */
    (xdc_Char)0x49,  /* [3555] */
    (xdc_Char)0x6d,  /* [3556] */
    (xdc_Char)0x70,  /* [3557] */
    (xdc_Char)0x72,  /* [3558] */
    (xdc_Char)0x6f,  /* [3559] */
    (xdc_Char)0x70,  /* [3560] */
    (xdc_Char)0x65,  /* [3561] */
    (xdc_Char)0x72,  /* [3562] */
    (xdc_Char)0x20,  /* [3563] */
    (xdc_Char)0x75,  /* [3564] */
    (xdc_Char)0x73,  /* [3565] */
    (xdc_Char)0x65,  /* [3566] */
    (xdc_Char)0x20,  /* [3567] */
    (xdc_Char)0x6f,  /* [3568] */
    (xdc_Char)0x66,  /* [3569] */
    (xdc_Char)0x20,  /* [3570] */
    (xdc_Char)0x61,  /* [3571] */
    (xdc_Char)0x20,  /* [3572] */
    (xdc_Char)0x72,  /* [3573] */
    (xdc_Char)0x65,  /* [3574] */
    (xdc_Char)0x73,  /* [3575] */
    (xdc_Char)0x65,  /* [3576] */
    (xdc_Char)0x72,  /* [3577] */
    (xdc_Char)0x76,  /* [3578] */
    (xdc_Char)0x65,  /* [3579] */
    (xdc_Char)0x64,  /* [3580] */
    (xdc_Char)0x20,  /* [3581] */
    (xdc_Char)0x65,  /* [3582] */
    (xdc_Char)0x76,  /* [3583] */
    (xdc_Char)0x65,  /* [3584] */
    (xdc_Char)0x6e,  /* [3585] */
    (xdc_Char)0x74,  /* [3586] */
    (xdc_Char)0x0,  /* [3587] */
    (xdc_Char)0x41,  /* [3588] */
    (xdc_Char)0x5f,  /* [3589] */
    (xdc_Char)0x6f,  /* [3590] */
    (xdc_Char)0x75,  /* [3591] */
    (xdc_Char)0x74,  /* [3592] */
    (xdc_Char)0x4f,  /* [3593] */
    (xdc_Char)0x66,  /* [3594] */
    (xdc_Char)0x4f,  /* [3595] */
    (xdc_Char)0x72,  /* [3596] */
    (xdc_Char)0x64,  /* [3597] */
    (xdc_Char)0x65,  /* [3598] */
    (xdc_Char)0x72,  /* [3599] */
    (xdc_Char)0x4e,  /* [3600] */
    (xdc_Char)0x65,  /* [3601] */
    (xdc_Char)0x73,  /* [3602] */
    (xdc_Char)0x74,  /* [3603] */
    (xdc_Char)0x69,  /* [3604] */
    (xdc_Char)0x6e,  /* [3605] */
    (xdc_Char)0x67,  /* [3606] */
    (xdc_Char)0x3a,  /* [3607] */
    (xdc_Char)0x20,  /* [3608] */
    (xdc_Char)0x4f,  /* [3609] */
    (xdc_Char)0x75,  /* [3610] */
    (xdc_Char)0x74,  /* [3611] */
    (xdc_Char)0x20,  /* [3612] */
    (xdc_Char)0x6f,  /* [3613] */
    (xdc_Char)0x66,  /* [3614] */
    (xdc_Char)0x20,  /* [3615] */
    (xdc_Char)0x6f,  /* [3616] */
    (xdc_Char)0x72,  /* [3617] */
    (xdc_Char)0x64,  /* [3618] */
    (xdc_Char)0x65,  /* [3619] */
    (xdc_Char)0x72,  /* [3620] */
    (xdc_Char)0x20,  /* [3621] */
    (xdc_Char)0x6e,  /* [3622] */
    (xdc_Char)0x65,  /* [3623] */
    (xdc_Char)0x73,  /* [3624] */
    (xdc_Char)0x74,  /* [3625] */
    (xdc_Char)0x69,  /* [3626] */
    (xdc_Char)0x6e,  /* [3627] */
    (xdc_Char)0x67,  /* [3628] */
    (xdc_Char)0x0,  /* [3629] */
    (xdc_Char)0x62,  /* [3630] */
    (xdc_Char)0x75,  /* [3631] */
    (xdc_Char)0x66,  /* [3632] */
    (xdc_Char)0x20,  /* [3633] */
    (xdc_Char)0x70,  /* [3634] */
    (xdc_Char)0x61,  /* [3635] */
    (xdc_Char)0x72,  /* [3636] */
    (xdc_Char)0x61,  /* [3637] */
    (xdc_Char)0x6d,  /* [3638] */
    (xdc_Char)0x65,  /* [3639] */
    (xdc_Char)0x74,  /* [3640] */
    (xdc_Char)0x65,  /* [3641] */
    (xdc_Char)0x72,  /* [3642] */
    (xdc_Char)0x20,  /* [3643] */
    (xdc_Char)0x63,  /* [3644] */
    (xdc_Char)0x61,  /* [3645] */
    (xdc_Char)0x6e,  /* [3646] */
    (xdc_Char)0x6e,  /* [3647] */
    (xdc_Char)0x6f,  /* [3648] */
    (xdc_Char)0x74,  /* [3649] */
    (xdc_Char)0x20,  /* [3650] */
    (xdc_Char)0x62,  /* [3651] */
    (xdc_Char)0x65,  /* [3652] */
    (xdc_Char)0x20,  /* [3653] */
    (xdc_Char)0x6e,  /* [3654] */
    (xdc_Char)0x75,  /* [3655] */
    (xdc_Char)0x6c,  /* [3656] */
    (xdc_Char)0x6c,  /* [3657] */
    (xdc_Char)0x0,  /* [3658] */
    (xdc_Char)0x62,  /* [3659] */
    (xdc_Char)0x75,  /* [3660] */
    (xdc_Char)0x66,  /* [3661] */
    (xdc_Char)0x20,  /* [3662] */
    (xdc_Char)0x6e,  /* [3663] */
    (xdc_Char)0x6f,  /* [3664] */
    (xdc_Char)0x74,  /* [3665] */
    (xdc_Char)0x20,  /* [3666] */
    (xdc_Char)0x70,  /* [3667] */
    (xdc_Char)0x72,  /* [3668] */
    (xdc_Char)0x6f,  /* [3669] */
    (xdc_Char)0x70,  /* [3670] */
    (xdc_Char)0x65,  /* [3671] */
    (xdc_Char)0x72,  /* [3672] */
    (xdc_Char)0x6c,  /* [3673] */
    (xdc_Char)0x79,  /* [3674] */
    (xdc_Char)0x20,  /* [3675] */
    (xdc_Char)0x61,  /* [3676] */
    (xdc_Char)0x6c,  /* [3677] */
    (xdc_Char)0x69,  /* [3678] */
    (xdc_Char)0x67,  /* [3679] */
    (xdc_Char)0x6e,  /* [3680] */
    (xdc_Char)0x65,  /* [3681] */
    (xdc_Char)0x64,  /* [3682] */
    (xdc_Char)0x0,  /* [3683] */
    (xdc_Char)0x61,  /* [3684] */
    (xdc_Char)0x6c,  /* [3685] */
    (xdc_Char)0x69,  /* [3686] */
    (xdc_Char)0x67,  /* [3687] */
    (xdc_Char)0x6e,  /* [3688] */
    (xdc_Char)0x20,  /* [3689] */
    (xdc_Char)0x70,  /* [3690] */
    (xdc_Char)0x61,  /* [3691] */
    (xdc_Char)0x72,  /* [3692] */
    (xdc_Char)0x61,  /* [3693] */
    (xdc_Char)0x6d,  /* [3694] */
    (xdc_Char)0x65,  /* [3695] */
    (xdc_Char)0x74,  /* [3696] */
    (xdc_Char)0x65,  /* [3697] */
    (xdc_Char)0x72,  /* [3698] */
    (xdc_Char)0x20,  /* [3699] */
    (xdc_Char)0x6d,  /* [3700] */
    (xdc_Char)0x75,  /* [3701] */
    (xdc_Char)0x73,  /* [3702] */
    (xdc_Char)0x74,  /* [3703] */
    (xdc_Char)0x20,  /* [3704] */
    (xdc_Char)0x62,  /* [3705] */
    (xdc_Char)0x65,  /* [3706] */
    (xdc_Char)0x20,  /* [3707] */
    (xdc_Char)0x30,  /* [3708] */
    (xdc_Char)0x20,  /* [3709] */
    (xdc_Char)0x6f,  /* [3710] */
    (xdc_Char)0x72,  /* [3711] */
    (xdc_Char)0x20,  /* [3712] */
    (xdc_Char)0x61,  /* [3713] */
    (xdc_Char)0x20,  /* [3714] */
    (xdc_Char)0x70,  /* [3715] */
    (xdc_Char)0x6f,  /* [3716] */
    (xdc_Char)0x77,  /* [3717] */
    (xdc_Char)0x65,  /* [3718] */
    (xdc_Char)0x72,  /* [3719] */
    (xdc_Char)0x20,  /* [3720] */
    (xdc_Char)0x6f,  /* [3721] */
    (xdc_Char)0x66,  /* [3722] */
    (xdc_Char)0x20,  /* [3723] */
    (xdc_Char)0x32,  /* [3724] */
    (xdc_Char)0x20,  /* [3725] */
    (xdc_Char)0x3e,  /* [3726] */
    (xdc_Char)0x3d,  /* [3727] */
    (xdc_Char)0x20,  /* [3728] */
    (xdc_Char)0x74,  /* [3729] */
    (xdc_Char)0x68,  /* [3730] */
    (xdc_Char)0x65,  /* [3731] */
    (xdc_Char)0x20,  /* [3732] */
    (xdc_Char)0x76,  /* [3733] */
    (xdc_Char)0x61,  /* [3734] */
    (xdc_Char)0x6c,  /* [3735] */
    (xdc_Char)0x75,  /* [3736] */
    (xdc_Char)0x65,  /* [3737] */
    (xdc_Char)0x20,  /* [3738] */
    (xdc_Char)0x6f,  /* [3739] */
    (xdc_Char)0x66,  /* [3740] */
    (xdc_Char)0x20,  /* [3741] */
    (xdc_Char)0x4d,  /* [3742] */
    (xdc_Char)0x65,  /* [3743] */
    (xdc_Char)0x6d,  /* [3744] */
    (xdc_Char)0x6f,  /* [3745] */
    (xdc_Char)0x72,  /* [3746] */
    (xdc_Char)0x79,  /* [3747] */
    (xdc_Char)0x5f,  /* [3748] */
    (xdc_Char)0x67,  /* [3749] */
    (xdc_Char)0x65,  /* [3750] */
    (xdc_Char)0x74,  /* [3751] */
    (xdc_Char)0x4d,  /* [3752] */
    (xdc_Char)0x61,  /* [3753] */
    (xdc_Char)0x78,  /* [3754] */
    (xdc_Char)0x44,  /* [3755] */
    (xdc_Char)0x65,  /* [3756] */
    (xdc_Char)0x66,  /* [3757] */
    (xdc_Char)0x61,  /* [3758] */
    (xdc_Char)0x75,  /* [3759] */
    (xdc_Char)0x6c,  /* [3760] */
    (xdc_Char)0x74,  /* [3761] */
    (xdc_Char)0x54,  /* [3762] */
    (xdc_Char)0x79,  /* [3763] */
    (xdc_Char)0x70,  /* [3764] */
    (xdc_Char)0x65,  /* [3765] */
    (xdc_Char)0x41,  /* [3766] */
    (xdc_Char)0x6c,  /* [3767] */
    (xdc_Char)0x69,  /* [3768] */
    (xdc_Char)0x67,  /* [3769] */
    (xdc_Char)0x6e,  /* [3770] */
    (xdc_Char)0x28,  /* [3771] */
    (xdc_Char)0x29,  /* [3772] */
    (xdc_Char)0x0,  /* [3773] */
    (xdc_Char)0x62,  /* [3774] */
    (xdc_Char)0x6c,  /* [3775] */
    (xdc_Char)0x6f,  /* [3776] */
    (xdc_Char)0x63,  /* [3777] */
    (xdc_Char)0x6b,  /* [3778] */
    (xdc_Char)0x53,  /* [3779] */
    (xdc_Char)0x69,  /* [3780] */
    (xdc_Char)0x7a,  /* [3781] */
    (xdc_Char)0x65,  /* [3782] */
    (xdc_Char)0x20,  /* [3783] */
    (xdc_Char)0x63,  /* [3784] */
    (xdc_Char)0x61,  /* [3785] */
    (xdc_Char)0x6e,  /* [3786] */
    (xdc_Char)0x6e,  /* [3787] */
    (xdc_Char)0x6f,  /* [3788] */
    (xdc_Char)0x74,  /* [3789] */
    (xdc_Char)0x20,  /* [3790] */
    (xdc_Char)0x62,  /* [3791] */
    (xdc_Char)0x65,  /* [3792] */
    (xdc_Char)0x20,  /* [3793] */
    (xdc_Char)0x7a,  /* [3794] */
    (xdc_Char)0x65,  /* [3795] */
    (xdc_Char)0x72,  /* [3796] */
    (xdc_Char)0x6f,  /* [3797] */
    (xdc_Char)0x0,  /* [3798] */
    (xdc_Char)0x6e,  /* [3799] */
    (xdc_Char)0x75,  /* [3800] */
    (xdc_Char)0x6d,  /* [3801] */
    (xdc_Char)0x42,  /* [3802] */
    (xdc_Char)0x6c,  /* [3803] */
    (xdc_Char)0x6f,  /* [3804] */
    (xdc_Char)0x63,  /* [3805] */
    (xdc_Char)0x6b,  /* [3806] */
    (xdc_Char)0x73,  /* [3807] */
    (xdc_Char)0x20,  /* [3808] */
    (xdc_Char)0x63,  /* [3809] */
    (xdc_Char)0x61,  /* [3810] */
    (xdc_Char)0x6e,  /* [3811] */
    (xdc_Char)0x6e,  /* [3812] */
    (xdc_Char)0x6f,  /* [3813] */
    (xdc_Char)0x74,  /* [3814] */
    (xdc_Char)0x20,  /* [3815] */
    (xdc_Char)0x62,  /* [3816] */
    (xdc_Char)0x65,  /* [3817] */
    (xdc_Char)0x20,  /* [3818] */
    (xdc_Char)0x7a,  /* [3819] */
    (xdc_Char)0x65,  /* [3820] */
    (xdc_Char)0x72,  /* [3821] */
    (xdc_Char)0x6f,  /* [3822] */
    (xdc_Char)0x0,  /* [3823] */
    (xdc_Char)0x62,  /* [3824] */
    (xdc_Char)0x75,  /* [3825] */
    (xdc_Char)0x66,  /* [3826] */
    (xdc_Char)0x53,  /* [3827] */
    (xdc_Char)0x69,  /* [3828] */
    (xdc_Char)0x7a,  /* [3829] */
    (xdc_Char)0x65,  /* [3830] */
    (xdc_Char)0x20,  /* [3831] */
    (xdc_Char)0x63,  /* [3832] */
    (xdc_Char)0x61,  /* [3833] */
    (xdc_Char)0x6e,  /* [3834] */
    (xdc_Char)0x6e,  /* [3835] */
    (xdc_Char)0x6f,  /* [3836] */
    (xdc_Char)0x74,  /* [3837] */
    (xdc_Char)0x20,  /* [3838] */
    (xdc_Char)0x62,  /* [3839] */
    (xdc_Char)0x65,  /* [3840] */
    (xdc_Char)0x20,  /* [3841] */
    (xdc_Char)0x7a,  /* [3842] */
    (xdc_Char)0x65,  /* [3843] */
    (xdc_Char)0x72,  /* [3844] */
    (xdc_Char)0x6f,  /* [3845] */
    (xdc_Char)0x0,  /* [3846] */
    (xdc_Char)0x48,  /* [3847] */
    (xdc_Char)0x65,  /* [3848] */
    (xdc_Char)0x61,  /* [3849] */
    (xdc_Char)0x70,  /* [3850] */
    (xdc_Char)0x42,  /* [3851] */
    (xdc_Char)0x75,  /* [3852] */
    (xdc_Char)0x66,  /* [3853] */
    (xdc_Char)0x5f,  /* [3854] */
    (xdc_Char)0x63,  /* [3855] */
    (xdc_Char)0x72,  /* [3856] */
    (xdc_Char)0x65,  /* [3857] */
    (xdc_Char)0x61,  /* [3858] */
    (xdc_Char)0x74,  /* [3859] */
    (xdc_Char)0x65,  /* [3860] */
    (xdc_Char)0x27,  /* [3861] */
    (xdc_Char)0x73,  /* [3862] */
    (xdc_Char)0x20,  /* [3863] */
    (xdc_Char)0x62,  /* [3864] */
    (xdc_Char)0x75,  /* [3865] */
    (xdc_Char)0x66,  /* [3866] */
    (xdc_Char)0x53,  /* [3867] */
    (xdc_Char)0x69,  /* [3868] */
    (xdc_Char)0x7a,  /* [3869] */
    (xdc_Char)0x65,  /* [3870] */
    (xdc_Char)0x20,  /* [3871] */
    (xdc_Char)0x70,  /* [3872] */
    (xdc_Char)0x61,  /* [3873] */
    (xdc_Char)0x72,  /* [3874] */
    (xdc_Char)0x61,  /* [3875] */
    (xdc_Char)0x6d,  /* [3876] */
    (xdc_Char)0x65,  /* [3877] */
    (xdc_Char)0x74,  /* [3878] */
    (xdc_Char)0x65,  /* [3879] */
    (xdc_Char)0x72,  /* [3880] */
    (xdc_Char)0x20,  /* [3881] */
    (xdc_Char)0x69,  /* [3882] */
    (xdc_Char)0x73,  /* [3883] */
    (xdc_Char)0x20,  /* [3884] */
    (xdc_Char)0x69,  /* [3885] */
    (xdc_Char)0x6e,  /* [3886] */
    (xdc_Char)0x76,  /* [3887] */
    (xdc_Char)0x61,  /* [3888] */
    (xdc_Char)0x6c,  /* [3889] */
    (xdc_Char)0x69,  /* [3890] */
    (xdc_Char)0x64,  /* [3891] */
    (xdc_Char)0x20,  /* [3892] */
    (xdc_Char)0x28,  /* [3893] */
    (xdc_Char)0x74,  /* [3894] */
    (xdc_Char)0x6f,  /* [3895] */
    (xdc_Char)0x6f,  /* [3896] */
    (xdc_Char)0x20,  /* [3897] */
    (xdc_Char)0x73,  /* [3898] */
    (xdc_Char)0x6d,  /* [3899] */
    (xdc_Char)0x61,  /* [3900] */
    (xdc_Char)0x6c,  /* [3901] */
    (xdc_Char)0x6c,  /* [3902] */
    (xdc_Char)0x29,  /* [3903] */
    (xdc_Char)0x0,  /* [3904] */
    (xdc_Char)0x43,  /* [3905] */
    (xdc_Char)0x61,  /* [3906] */
    (xdc_Char)0x6e,  /* [3907] */
    (xdc_Char)0x6e,  /* [3908] */
    (xdc_Char)0x6f,  /* [3909] */
    (xdc_Char)0x74,  /* [3910] */
    (xdc_Char)0x20,  /* [3911] */
    (xdc_Char)0x63,  /* [3912] */
    (xdc_Char)0x61,  /* [3913] */
    (xdc_Char)0x6c,  /* [3914] */
    (xdc_Char)0x6c,  /* [3915] */
    (xdc_Char)0x20,  /* [3916] */
    (xdc_Char)0x48,  /* [3917] */
    (xdc_Char)0x65,  /* [3918] */
    (xdc_Char)0x61,  /* [3919] */
    (xdc_Char)0x70,  /* [3920] */
    (xdc_Char)0x42,  /* [3921] */
    (xdc_Char)0x75,  /* [3922] */
    (xdc_Char)0x66,  /* [3923] */
    (xdc_Char)0x5f,  /* [3924] */
    (xdc_Char)0x66,  /* [3925] */
    (xdc_Char)0x72,  /* [3926] */
    (xdc_Char)0x65,  /* [3927] */
    (xdc_Char)0x65,  /* [3928] */
    (xdc_Char)0x20,  /* [3929] */
    (xdc_Char)0x77,  /* [3930] */
    (xdc_Char)0x68,  /* [3931] */
    (xdc_Char)0x65,  /* [3932] */
    (xdc_Char)0x6e,  /* [3933] */
    (xdc_Char)0x20,  /* [3934] */
    (xdc_Char)0x6e,  /* [3935] */
    (xdc_Char)0x6f,  /* [3936] */
    (xdc_Char)0x20,  /* [3937] */
    (xdc_Char)0x62,  /* [3938] */
    (xdc_Char)0x6c,  /* [3939] */
    (xdc_Char)0x6f,  /* [3940] */
    (xdc_Char)0x63,  /* [3941] */
    (xdc_Char)0x6b,  /* [3942] */
    (xdc_Char)0x73,  /* [3943] */
    (xdc_Char)0x20,  /* [3944] */
    (xdc_Char)0x68,  /* [3945] */
    (xdc_Char)0x61,  /* [3946] */
    (xdc_Char)0x76,  /* [3947] */
    (xdc_Char)0x65,  /* [3948] */
    (xdc_Char)0x20,  /* [3949] */
    (xdc_Char)0x62,  /* [3950] */
    (xdc_Char)0x65,  /* [3951] */
    (xdc_Char)0x65,  /* [3952] */
    (xdc_Char)0x6e,  /* [3953] */
    (xdc_Char)0x20,  /* [3954] */
    (xdc_Char)0x61,  /* [3955] */
    (xdc_Char)0x6c,  /* [3956] */
    (xdc_Char)0x6c,  /* [3957] */
    (xdc_Char)0x6f,  /* [3958] */
    (xdc_Char)0x63,  /* [3959] */
    (xdc_Char)0x61,  /* [3960] */
    (xdc_Char)0x74,  /* [3961] */
    (xdc_Char)0x65,  /* [3962] */
    (xdc_Char)0x64,  /* [3963] */
    (xdc_Char)0x0,  /* [3964] */
    (xdc_Char)0x41,  /* [3965] */
    (xdc_Char)0x5f,  /* [3966] */
    (xdc_Char)0x69,  /* [3967] */
    (xdc_Char)0x6e,  /* [3968] */
    (xdc_Char)0x76,  /* [3969] */
    (xdc_Char)0x61,  /* [3970] */
    (xdc_Char)0x6c,  /* [3971] */
    (xdc_Char)0x69,  /* [3972] */
    (xdc_Char)0x64,  /* [3973] */
    (xdc_Char)0x46,  /* [3974] */
    (xdc_Char)0x72,  /* [3975] */
    (xdc_Char)0x65,  /* [3976] */
    (xdc_Char)0x65,  /* [3977] */
    (xdc_Char)0x3a,  /* [3978] */
    (xdc_Char)0x20,  /* [3979] */
    (xdc_Char)0x49,  /* [3980] */
    (xdc_Char)0x6e,  /* [3981] */
    (xdc_Char)0x76,  /* [3982] */
    (xdc_Char)0x61,  /* [3983] */
    (xdc_Char)0x6c,  /* [3984] */
    (xdc_Char)0x69,  /* [3985] */
    (xdc_Char)0x64,  /* [3986] */
    (xdc_Char)0x20,  /* [3987] */
    (xdc_Char)0x66,  /* [3988] */
    (xdc_Char)0x72,  /* [3989] */
    (xdc_Char)0x65,  /* [3990] */
    (xdc_Char)0x65,  /* [3991] */
    (xdc_Char)0x0,  /* [3992] */
    (xdc_Char)0x41,  /* [3993] */
    (xdc_Char)0x5f,  /* [3994] */
    (xdc_Char)0x7a,  /* [3995] */
    (xdc_Char)0x65,  /* [3996] */
    (xdc_Char)0x72,  /* [3997] */
    (xdc_Char)0x6f,  /* [3998] */
    (xdc_Char)0x42,  /* [3999] */
    (xdc_Char)0x6c,  /* [4000] */
    (xdc_Char)0x6f,  /* [4001] */
    (xdc_Char)0x63,  /* [4002] */
    (xdc_Char)0x6b,  /* [4003] */
    (xdc_Char)0x3a,  /* [4004] */
    (xdc_Char)0x20,  /* [4005] */
    (xdc_Char)0x43,  /* [4006] */
    (xdc_Char)0x61,  /* [4007] */
    (xdc_Char)0x6e,  /* [4008] */
    (xdc_Char)0x6e,  /* [4009] */
    (xdc_Char)0x6f,  /* [4010] */
    (xdc_Char)0x74,  /* [4011] */
    (xdc_Char)0x20,  /* [4012] */
    (xdc_Char)0x61,  /* [4013] */
    (xdc_Char)0x6c,  /* [4014] */
    (xdc_Char)0x6c,  /* [4015] */
    (xdc_Char)0x6f,  /* [4016] */
    (xdc_Char)0x63,  /* [4017] */
    (xdc_Char)0x61,  /* [4018] */
    (xdc_Char)0x74,  /* [4019] */
    (xdc_Char)0x65,  /* [4020] */
    (xdc_Char)0x20,  /* [4021] */
    (xdc_Char)0x73,  /* [4022] */
    (xdc_Char)0x69,  /* [4023] */
    (xdc_Char)0x7a,  /* [4024] */
    (xdc_Char)0x65,  /* [4025] */
    (xdc_Char)0x20,  /* [4026] */
    (xdc_Char)0x30,  /* [4027] */
    (xdc_Char)0x0,  /* [4028] */
    (xdc_Char)0x41,  /* [4029] */
    (xdc_Char)0x5f,  /* [4030] */
    (xdc_Char)0x68,  /* [4031] */
    (xdc_Char)0x65,  /* [4032] */
    (xdc_Char)0x61,  /* [4033] */
    (xdc_Char)0x70,  /* [4034] */
    (xdc_Char)0x53,  /* [4035] */
    (xdc_Char)0x69,  /* [4036] */
    (xdc_Char)0x7a,  /* [4037] */
    (xdc_Char)0x65,  /* [4038] */
    (xdc_Char)0x3a,  /* [4039] */
    (xdc_Char)0x20,  /* [4040] */
    (xdc_Char)0x52,  /* [4041] */
    (xdc_Char)0x65,  /* [4042] */
    (xdc_Char)0x71,  /* [4043] */
    (xdc_Char)0x75,  /* [4044] */
    (xdc_Char)0x65,  /* [4045] */
    (xdc_Char)0x73,  /* [4046] */
    (xdc_Char)0x74,  /* [4047] */
    (xdc_Char)0x65,  /* [4048] */
    (xdc_Char)0x64,  /* [4049] */
    (xdc_Char)0x20,  /* [4050] */
    (xdc_Char)0x68,  /* [4051] */
    (xdc_Char)0x65,  /* [4052] */
    (xdc_Char)0x61,  /* [4053] */
    (xdc_Char)0x70,  /* [4054] */
    (xdc_Char)0x20,  /* [4055] */
    (xdc_Char)0x73,  /* [4056] */
    (xdc_Char)0x69,  /* [4057] */
    (xdc_Char)0x7a,  /* [4058] */
    (xdc_Char)0x65,  /* [4059] */
    (xdc_Char)0x20,  /* [4060] */
    (xdc_Char)0x69,  /* [4061] */
    (xdc_Char)0x73,  /* [4062] */
    (xdc_Char)0x20,  /* [4063] */
    (xdc_Char)0x74,  /* [4064] */
    (xdc_Char)0x6f,  /* [4065] */
    (xdc_Char)0x6f,  /* [4066] */
    (xdc_Char)0x20,  /* [4067] */
    (xdc_Char)0x73,  /* [4068] */
    (xdc_Char)0x6d,  /* [4069] */
    (xdc_Char)0x61,  /* [4070] */
    (xdc_Char)0x6c,  /* [4071] */
    (xdc_Char)0x6c,  /* [4072] */
    (xdc_Char)0x0,  /* [4073] */
    (xdc_Char)0x41,  /* [4074] */
    (xdc_Char)0x5f,  /* [4075] */
    (xdc_Char)0x61,  /* [4076] */
    (xdc_Char)0x6c,  /* [4077] */
    (xdc_Char)0x69,  /* [4078] */
    (xdc_Char)0x67,  /* [4079] */
    (xdc_Char)0x6e,  /* [4080] */
    (xdc_Char)0x3a,  /* [4081] */
    (xdc_Char)0x20,  /* [4082] */
    (xdc_Char)0x52,  /* [4083] */
    (xdc_Char)0x65,  /* [4084] */
    (xdc_Char)0x71,  /* [4085] */
    (xdc_Char)0x75,  /* [4086] */
    (xdc_Char)0x65,  /* [4087] */
    (xdc_Char)0x73,  /* [4088] */
    (xdc_Char)0x74,  /* [4089] */
    (xdc_Char)0x65,  /* [4090] */
    (xdc_Char)0x64,  /* [4091] */
    (xdc_Char)0x20,  /* [4092] */
    (xdc_Char)0x61,  /* [4093] */
    (xdc_Char)0x6c,  /* [4094] */
    (xdc_Char)0x69,  /* [4095] */
    (xdc_Char)0x67,  /* [4096] */
    (xdc_Char)0x6e,  /* [4097] */
    (xdc_Char)0x20,  /* [4098] */
    (xdc_Char)0x69,  /* [4099] */
    (xdc_Char)0x73,  /* [4100] */
    (xdc_Char)0x20,  /* [4101] */
    (xdc_Char)0x6e,  /* [4102] */
    (xdc_Char)0x6f,  /* [4103] */
    (xdc_Char)0x74,  /* [4104] */
    (xdc_Char)0x20,  /* [4105] */
    (xdc_Char)0x61,  /* [4106] */
    (xdc_Char)0x20,  /* [4107] */
    (xdc_Char)0x70,  /* [4108] */
    (xdc_Char)0x6f,  /* [4109] */
    (xdc_Char)0x77,  /* [4110] */
    (xdc_Char)0x65,  /* [4111] */
    (xdc_Char)0x72,  /* [4112] */
    (xdc_Char)0x20,  /* [4113] */
    (xdc_Char)0x6f,  /* [4114] */
    (xdc_Char)0x66,  /* [4115] */
    (xdc_Char)0x20,  /* [4116] */
    (xdc_Char)0x32,  /* [4117] */
    (xdc_Char)0x0,  /* [4118] */
    (xdc_Char)0x49,  /* [4119] */
    (xdc_Char)0x6e,  /* [4120] */
    (xdc_Char)0x76,  /* [4121] */
    (xdc_Char)0x61,  /* [4122] */
    (xdc_Char)0x6c,  /* [4123] */
    (xdc_Char)0x69,  /* [4124] */
    (xdc_Char)0x64,  /* [4125] */
    (xdc_Char)0x20,  /* [4126] */
    (xdc_Char)0x62,  /* [4127] */
    (xdc_Char)0x6c,  /* [4128] */
    (xdc_Char)0x6f,  /* [4129] */
    (xdc_Char)0x63,  /* [4130] */
    (xdc_Char)0x6b,  /* [4131] */
    (xdc_Char)0x20,  /* [4132] */
    (xdc_Char)0x61,  /* [4133] */
    (xdc_Char)0x64,  /* [4134] */
    (xdc_Char)0x64,  /* [4135] */
    (xdc_Char)0x72,  /* [4136] */
    (xdc_Char)0x65,  /* [4137] */
    (xdc_Char)0x73,  /* [4138] */
    (xdc_Char)0x73,  /* [4139] */
    (xdc_Char)0x20,  /* [4140] */
    (xdc_Char)0x6f,  /* [4141] */
    (xdc_Char)0x6e,  /* [4142] */
    (xdc_Char)0x20,  /* [4143] */
    (xdc_Char)0x74,  /* [4144] */
    (xdc_Char)0x68,  /* [4145] */
    (xdc_Char)0x65,  /* [4146] */
    (xdc_Char)0x20,  /* [4147] */
    (xdc_Char)0x66,  /* [4148] */
    (xdc_Char)0x72,  /* [4149] */
    (xdc_Char)0x65,  /* [4150] */
    (xdc_Char)0x65,  /* [4151] */
    (xdc_Char)0x2e,  /* [4152] */
    (xdc_Char)0x20,  /* [4153] */
    (xdc_Char)0x46,  /* [4154] */
    (xdc_Char)0x61,  /* [4155] */
    (xdc_Char)0x69,  /* [4156] */
    (xdc_Char)0x6c,  /* [4157] */
    (xdc_Char)0x65,  /* [4158] */
    (xdc_Char)0x64,  /* [4159] */
    (xdc_Char)0x20,  /* [4160] */
    (xdc_Char)0x74,  /* [4161] */
    (xdc_Char)0x6f,  /* [4162] */
    (xdc_Char)0x20,  /* [4163] */
    (xdc_Char)0x66,  /* [4164] */
    (xdc_Char)0x72,  /* [4165] */
    (xdc_Char)0x65,  /* [4166] */
    (xdc_Char)0x65,  /* [4167] */
    (xdc_Char)0x20,  /* [4168] */
    (xdc_Char)0x62,  /* [4169] */
    (xdc_Char)0x6c,  /* [4170] */
    (xdc_Char)0x6f,  /* [4171] */
    (xdc_Char)0x63,  /* [4172] */
    (xdc_Char)0x6b,  /* [4173] */
    (xdc_Char)0x20,  /* [4174] */
    (xdc_Char)0x62,  /* [4175] */
    (xdc_Char)0x61,  /* [4176] */
    (xdc_Char)0x63,  /* [4177] */
    (xdc_Char)0x6b,  /* [4178] */
    (xdc_Char)0x20,  /* [4179] */
    (xdc_Char)0x74,  /* [4180] */
    (xdc_Char)0x6f,  /* [4181] */
    (xdc_Char)0x20,  /* [4182] */
    (xdc_Char)0x68,  /* [4183] */
    (xdc_Char)0x65,  /* [4184] */
    (xdc_Char)0x61,  /* [4185] */
    (xdc_Char)0x70,  /* [4186] */
    (xdc_Char)0x2e,  /* [4187] */
    (xdc_Char)0x0,  /* [4188] */
    (xdc_Char)0x61,  /* [4189] */
    (xdc_Char)0x73,  /* [4190] */
    (xdc_Char)0x73,  /* [4191] */
    (xdc_Char)0x65,  /* [4192] */
    (xdc_Char)0x72,  /* [4193] */
    (xdc_Char)0x74,  /* [4194] */
    (xdc_Char)0x69,  /* [4195] */
    (xdc_Char)0x6f,  /* [4196] */
    (xdc_Char)0x6e,  /* [4197] */
    (xdc_Char)0x20,  /* [4198] */
    (xdc_Char)0x66,  /* [4199] */
    (xdc_Char)0x61,  /* [4200] */
    (xdc_Char)0x69,  /* [4201] */
    (xdc_Char)0x6c,  /* [4202] */
    (xdc_Char)0x75,  /* [4203] */
    (xdc_Char)0x72,  /* [4204] */
    (xdc_Char)0x65,  /* [4205] */
    (xdc_Char)0x25,  /* [4206] */
    (xdc_Char)0x73,  /* [4207] */
    (xdc_Char)0x25,  /* [4208] */
    (xdc_Char)0x73,  /* [4209] */
    (xdc_Char)0x0,  /* [4210] */
    (xdc_Char)0x25,  /* [4211] */
    (xdc_Char)0x24,  /* [4212] */
    (xdc_Char)0x53,  /* [4213] */
    (xdc_Char)0x0,  /* [4214] */
    (xdc_Char)0x6f,  /* [4215] */
    (xdc_Char)0x75,  /* [4216] */
    (xdc_Char)0x74,  /* [4217] */
    (xdc_Char)0x20,  /* [4218] */
    (xdc_Char)0x6f,  /* [4219] */
    (xdc_Char)0x66,  /* [4220] */
    (xdc_Char)0x20,  /* [4221] */
    (xdc_Char)0x6d,  /* [4222] */
    (xdc_Char)0x65,  /* [4223] */
    (xdc_Char)0x6d,  /* [4224] */
    (xdc_Char)0x6f,  /* [4225] */
    (xdc_Char)0x72,  /* [4226] */
    (xdc_Char)0x79,  /* [4227] */
    (xdc_Char)0x3a,  /* [4228] */
    (xdc_Char)0x20,  /* [4229] */
    (xdc_Char)0x68,  /* [4230] */
    (xdc_Char)0x65,  /* [4231] */
    (xdc_Char)0x61,  /* [4232] */
    (xdc_Char)0x70,  /* [4233] */
    (xdc_Char)0x3d,  /* [4234] */
    (xdc_Char)0x30,  /* [4235] */
    (xdc_Char)0x78,  /* [4236] */
    (xdc_Char)0x25,  /* [4237] */
    (xdc_Char)0x78,  /* [4238] */
    (xdc_Char)0x2c,  /* [4239] */
    (xdc_Char)0x20,  /* [4240] */
    (xdc_Char)0x73,  /* [4241] */
    (xdc_Char)0x69,  /* [4242] */
    (xdc_Char)0x7a,  /* [4243] */
    (xdc_Char)0x65,  /* [4244] */
    (xdc_Char)0x3d,  /* [4245] */
    (xdc_Char)0x25,  /* [4246] */
    (xdc_Char)0x75,  /* [4247] */
    (xdc_Char)0x0,  /* [4248] */
    (xdc_Char)0x25,  /* [4249] */
    (xdc_Char)0x73,  /* [4250] */
    (xdc_Char)0x20,  /* [4251] */
    (xdc_Char)0x30,  /* [4252] */
    (xdc_Char)0x78,  /* [4253] */
    (xdc_Char)0x25,  /* [4254] */
    (xdc_Char)0x78,  /* [4255] */
    (xdc_Char)0x0,  /* [4256] */
    (xdc_Char)0x45,  /* [4257] */
    (xdc_Char)0x5f,  /* [4258] */
    (xdc_Char)0x62,  /* [4259] */
    (xdc_Char)0x61,  /* [4260] */
    (xdc_Char)0x64,  /* [4261] */
    (xdc_Char)0x4c,  /* [4262] */
    (xdc_Char)0x65,  /* [4263] */
    (xdc_Char)0x76,  /* [4264] */
    (xdc_Char)0x65,  /* [4265] */
    (xdc_Char)0x6c,  /* [4266] */
    (xdc_Char)0x3a,  /* [4267] */
    (xdc_Char)0x20,  /* [4268] */
    (xdc_Char)0x42,  /* [4269] */
    (xdc_Char)0x61,  /* [4270] */
    (xdc_Char)0x64,  /* [4271] */
    (xdc_Char)0x20,  /* [4272] */
    (xdc_Char)0x66,  /* [4273] */
    (xdc_Char)0x69,  /* [4274] */
    (xdc_Char)0x6c,  /* [4275] */
    (xdc_Char)0x74,  /* [4276] */
    (xdc_Char)0x65,  /* [4277] */
    (xdc_Char)0x72,  /* [4278] */
    (xdc_Char)0x20,  /* [4279] */
    (xdc_Char)0x6c,  /* [4280] */
    (xdc_Char)0x65,  /* [4281] */
    (xdc_Char)0x76,  /* [4282] */
    (xdc_Char)0x65,  /* [4283] */
    (xdc_Char)0x6c,  /* [4284] */
    (xdc_Char)0x20,  /* [4285] */
    (xdc_Char)0x76,  /* [4286] */
    (xdc_Char)0x61,  /* [4287] */
    (xdc_Char)0x6c,  /* [4288] */
    (xdc_Char)0x75,  /* [4289] */
    (xdc_Char)0x65,  /* [4290] */
    (xdc_Char)0x3a,  /* [4291] */
    (xdc_Char)0x20,  /* [4292] */
    (xdc_Char)0x25,  /* [4293] */
    (xdc_Char)0x64,  /* [4294] */
    (xdc_Char)0x0,  /* [4295] */
    (xdc_Char)0x66,  /* [4296] */
    (xdc_Char)0x72,  /* [4297] */
    (xdc_Char)0x65,  /* [4298] */
    (xdc_Char)0x65,  /* [4299] */
    (xdc_Char)0x28,  /* [4300] */
    (xdc_Char)0x29,  /* [4301] */
    (xdc_Char)0x20,  /* [4302] */
    (xdc_Char)0x69,  /* [4303] */
    (xdc_Char)0x6e,  /* [4304] */
    (xdc_Char)0x76,  /* [4305] */
    (xdc_Char)0x61,  /* [4306] */
    (xdc_Char)0x6c,  /* [4307] */
    (xdc_Char)0x69,  /* [4308] */
    (xdc_Char)0x64,  /* [4309] */
    (xdc_Char)0x20,  /* [4310] */
    (xdc_Char)0x69,  /* [4311] */
    (xdc_Char)0x6e,  /* [4312] */
    (xdc_Char)0x20,  /* [4313] */
    (xdc_Char)0x67,  /* [4314] */
    (xdc_Char)0x72,  /* [4315] */
    (xdc_Char)0x6f,  /* [4316] */
    (xdc_Char)0x77,  /* [4317] */
    (xdc_Char)0x74,  /* [4318] */
    (xdc_Char)0x68,  /* [4319] */
    (xdc_Char)0x2d,  /* [4320] */
    (xdc_Char)0x6f,  /* [4321] */
    (xdc_Char)0x6e,  /* [4322] */
    (xdc_Char)0x6c,  /* [4323] */
    (xdc_Char)0x79,  /* [4324] */
    (xdc_Char)0x20,  /* [4325] */
    (xdc_Char)0x48,  /* [4326] */
    (xdc_Char)0x65,  /* [4327] */
    (xdc_Char)0x61,  /* [4328] */
    (xdc_Char)0x70,  /* [4329] */
    (xdc_Char)0x4d,  /* [4330] */
    (xdc_Char)0x69,  /* [4331] */
    (xdc_Char)0x6e,  /* [4332] */
    (xdc_Char)0x0,  /* [4333] */
    (xdc_Char)0x54,  /* [4334] */
    (xdc_Char)0x68,  /* [4335] */
    (xdc_Char)0x65,  /* [4336] */
    (xdc_Char)0x20,  /* [4337] */
    (xdc_Char)0x52,  /* [4338] */
    (xdc_Char)0x54,  /* [4339] */
    (xdc_Char)0x53,  /* [4340] */
    (xdc_Char)0x20,  /* [4341] */
    (xdc_Char)0x68,  /* [4342] */
    (xdc_Char)0x65,  /* [4343] */
    (xdc_Char)0x61,  /* [4344] */
    (xdc_Char)0x70,  /* [4345] */
    (xdc_Char)0x20,  /* [4346] */
    (xdc_Char)0x69,  /* [4347] */
    (xdc_Char)0x73,  /* [4348] */
    (xdc_Char)0x20,  /* [4349] */
    (xdc_Char)0x75,  /* [4350] */
    (xdc_Char)0x73,  /* [4351] */
    (xdc_Char)0x65,  /* [4352] */
    (xdc_Char)0x64,  /* [4353] */
    (xdc_Char)0x20,  /* [4354] */
    (xdc_Char)0x75,  /* [4355] */
    (xdc_Char)0x70,  /* [4356] */
    (xdc_Char)0x2e,  /* [4357] */
    (xdc_Char)0x20,  /* [4358] */
    (xdc_Char)0x45,  /* [4359] */
    (xdc_Char)0x78,  /* [4360] */
    (xdc_Char)0x61,  /* [4361] */
    (xdc_Char)0x6d,  /* [4362] */
    (xdc_Char)0x69,  /* [4363] */
    (xdc_Char)0x6e,  /* [4364] */
    (xdc_Char)0x65,  /* [4365] */
    (xdc_Char)0x20,  /* [4366] */
    (xdc_Char)0x50,  /* [4367] */
    (xdc_Char)0x72,  /* [4368] */
    (xdc_Char)0x6f,  /* [4369] */
    (xdc_Char)0x67,  /* [4370] */
    (xdc_Char)0x72,  /* [4371] */
    (xdc_Char)0x61,  /* [4372] */
    (xdc_Char)0x6d,  /* [4373] */
    (xdc_Char)0x2e,  /* [4374] */
    (xdc_Char)0x68,  /* [4375] */
    (xdc_Char)0x65,  /* [4376] */
    (xdc_Char)0x61,  /* [4377] */
    (xdc_Char)0x70,  /* [4378] */
    (xdc_Char)0x2e,  /* [4379] */
    (xdc_Char)0x0,  /* [4380] */
    (xdc_Char)0x45,  /* [4381] */
    (xdc_Char)0x5f,  /* [4382] */
    (xdc_Char)0x62,  /* [4383] */
    (xdc_Char)0x61,  /* [4384] */
    (xdc_Char)0x64,  /* [4385] */
    (xdc_Char)0x43,  /* [4386] */
    (xdc_Char)0x6f,  /* [4387] */
    (xdc_Char)0x6d,  /* [4388] */
    (xdc_Char)0x6d,  /* [4389] */
    (xdc_Char)0x61,  /* [4390] */
    (xdc_Char)0x6e,  /* [4391] */
    (xdc_Char)0x64,  /* [4392] */
    (xdc_Char)0x3a,  /* [4393] */
    (xdc_Char)0x20,  /* [4394] */
    (xdc_Char)0x52,  /* [4395] */
    (xdc_Char)0x65,  /* [4396] */
    (xdc_Char)0x63,  /* [4397] */
    (xdc_Char)0x65,  /* [4398] */
    (xdc_Char)0x69,  /* [4399] */
    (xdc_Char)0x76,  /* [4400] */
    (xdc_Char)0x65,  /* [4401] */
    (xdc_Char)0x64,  /* [4402] */
    (xdc_Char)0x20,  /* [4403] */
    (xdc_Char)0x69,  /* [4404] */
    (xdc_Char)0x6e,  /* [4405] */
    (xdc_Char)0x76,  /* [4406] */
    (xdc_Char)0x61,  /* [4407] */
    (xdc_Char)0x6c,  /* [4408] */
    (xdc_Char)0x69,  /* [4409] */
    (xdc_Char)0x64,  /* [4410] */
    (xdc_Char)0x20,  /* [4411] */
    (xdc_Char)0x63,  /* [4412] */
    (xdc_Char)0x6f,  /* [4413] */
    (xdc_Char)0x6d,  /* [4414] */
    (xdc_Char)0x6d,  /* [4415] */
    (xdc_Char)0x61,  /* [4416] */
    (xdc_Char)0x6e,  /* [4417] */
    (xdc_Char)0x64,  /* [4418] */
    (xdc_Char)0x2c,  /* [4419] */
    (xdc_Char)0x20,  /* [4420] */
    (xdc_Char)0x69,  /* [4421] */
    (xdc_Char)0x64,  /* [4422] */
    (xdc_Char)0x3a,  /* [4423] */
    (xdc_Char)0x20,  /* [4424] */
    (xdc_Char)0x25,  /* [4425] */
    (xdc_Char)0x64,  /* [4426] */
    (xdc_Char)0x2e,  /* [4427] */
    (xdc_Char)0x0,  /* [4428] */
    (xdc_Char)0x45,  /* [4429] */
    (xdc_Char)0x5f,  /* [4430] */
    (xdc_Char)0x73,  /* [4431] */
    (xdc_Char)0x74,  /* [4432] */
    (xdc_Char)0x61,  /* [4433] */
    (xdc_Char)0x63,  /* [4434] */
    (xdc_Char)0x6b,  /* [4435] */
    (xdc_Char)0x4f,  /* [4436] */
    (xdc_Char)0x76,  /* [4437] */
    (xdc_Char)0x65,  /* [4438] */
    (xdc_Char)0x72,  /* [4439] */
    (xdc_Char)0x66,  /* [4440] */
    (xdc_Char)0x6c,  /* [4441] */
    (xdc_Char)0x6f,  /* [4442] */
    (xdc_Char)0x77,  /* [4443] */
    (xdc_Char)0x3a,  /* [4444] */
    (xdc_Char)0x20,  /* [4445] */
    (xdc_Char)0x49,  /* [4446] */
    (xdc_Char)0x53,  /* [4447] */
    (xdc_Char)0x52,  /* [4448] */
    (xdc_Char)0x20,  /* [4449] */
    (xdc_Char)0x73,  /* [4450] */
    (xdc_Char)0x74,  /* [4451] */
    (xdc_Char)0x61,  /* [4452] */
    (xdc_Char)0x63,  /* [4453] */
    (xdc_Char)0x6b,  /* [4454] */
    (xdc_Char)0x20,  /* [4455] */
    (xdc_Char)0x6f,  /* [4456] */
    (xdc_Char)0x76,  /* [4457] */
    (xdc_Char)0x65,  /* [4458] */
    (xdc_Char)0x72,  /* [4459] */
    (xdc_Char)0x66,  /* [4460] */
    (xdc_Char)0x6c,  /* [4461] */
    (xdc_Char)0x6f,  /* [4462] */
    (xdc_Char)0x77,  /* [4463] */
    (xdc_Char)0x2e,  /* [4464] */
    (xdc_Char)0x0,  /* [4465] */
    (xdc_Char)0x45,  /* [4466] */
    (xdc_Char)0x5f,  /* [4467] */
    (xdc_Char)0x73,  /* [4468] */
    (xdc_Char)0x74,  /* [4469] */
    (xdc_Char)0x61,  /* [4470] */
    (xdc_Char)0x63,  /* [4471] */
    (xdc_Char)0x6b,  /* [4472] */
    (xdc_Char)0x4f,  /* [4473] */
    (xdc_Char)0x76,  /* [4474] */
    (xdc_Char)0x65,  /* [4475] */
    (xdc_Char)0x72,  /* [4476] */
    (xdc_Char)0x66,  /* [4477] */
    (xdc_Char)0x6c,  /* [4478] */
    (xdc_Char)0x6f,  /* [4479] */
    (xdc_Char)0x77,  /* [4480] */
    (xdc_Char)0x3a,  /* [4481] */
    (xdc_Char)0x20,  /* [4482] */
    (xdc_Char)0x54,  /* [4483] */
    (xdc_Char)0x61,  /* [4484] */
    (xdc_Char)0x73,  /* [4485] */
    (xdc_Char)0x6b,  /* [4486] */
    (xdc_Char)0x20,  /* [4487] */
    (xdc_Char)0x30,  /* [4488] */
    (xdc_Char)0x78,  /* [4489] */
    (xdc_Char)0x25,  /* [4490] */
    (xdc_Char)0x78,  /* [4491] */
    (xdc_Char)0x20,  /* [4492] */
    (xdc_Char)0x73,  /* [4493] */
    (xdc_Char)0x74,  /* [4494] */
    (xdc_Char)0x61,  /* [4495] */
    (xdc_Char)0x63,  /* [4496] */
    (xdc_Char)0x6b,  /* [4497] */
    (xdc_Char)0x20,  /* [4498] */
    (xdc_Char)0x6f,  /* [4499] */
    (xdc_Char)0x76,  /* [4500] */
    (xdc_Char)0x65,  /* [4501] */
    (xdc_Char)0x72,  /* [4502] */
    (xdc_Char)0x66,  /* [4503] */
    (xdc_Char)0x6c,  /* [4504] */
    (xdc_Char)0x6f,  /* [4505] */
    (xdc_Char)0x77,  /* [4506] */
    (xdc_Char)0x2e,  /* [4507] */
    (xdc_Char)0x0,  /* [4508] */
    (xdc_Char)0x45,  /* [4509] */
    (xdc_Char)0x5f,  /* [4510] */
    (xdc_Char)0x73,  /* [4511] */
    (xdc_Char)0x70,  /* [4512] */
    (xdc_Char)0x4f,  /* [4513] */
    (xdc_Char)0x75,  /* [4514] */
    (xdc_Char)0x74,  /* [4515] */
    (xdc_Char)0x4f,  /* [4516] */
    (xdc_Char)0x66,  /* [4517] */
    (xdc_Char)0x42,  /* [4518] */
    (xdc_Char)0x6f,  /* [4519] */
    (xdc_Char)0x75,  /* [4520] */
    (xdc_Char)0x6e,  /* [4521] */
    (xdc_Char)0x64,  /* [4522] */
    (xdc_Char)0x73,  /* [4523] */
    (xdc_Char)0x3a,  /* [4524] */
    (xdc_Char)0x20,  /* [4525] */
    (xdc_Char)0x54,  /* [4526] */
    (xdc_Char)0x61,  /* [4527] */
    (xdc_Char)0x73,  /* [4528] */
    (xdc_Char)0x6b,  /* [4529] */
    (xdc_Char)0x20,  /* [4530] */
    (xdc_Char)0x30,  /* [4531] */
    (xdc_Char)0x78,  /* [4532] */
    (xdc_Char)0x25,  /* [4533] */
    (xdc_Char)0x78,  /* [4534] */
    (xdc_Char)0x20,  /* [4535] */
    (xdc_Char)0x73,  /* [4536] */
    (xdc_Char)0x74,  /* [4537] */
    (xdc_Char)0x61,  /* [4538] */
    (xdc_Char)0x63,  /* [4539] */
    (xdc_Char)0x6b,  /* [4540] */
    (xdc_Char)0x20,  /* [4541] */
    (xdc_Char)0x65,  /* [4542] */
    (xdc_Char)0x72,  /* [4543] */
    (xdc_Char)0x72,  /* [4544] */
    (xdc_Char)0x6f,  /* [4545] */
    (xdc_Char)0x72,  /* [4546] */
    (xdc_Char)0x2c,  /* [4547] */
    (xdc_Char)0x20,  /* [4548] */
    (xdc_Char)0x53,  /* [4549] */
    (xdc_Char)0x50,  /* [4550] */
    (xdc_Char)0x20,  /* [4551] */
    (xdc_Char)0x3d,  /* [4552] */
    (xdc_Char)0x20,  /* [4553] */
    (xdc_Char)0x30,  /* [4554] */
    (xdc_Char)0x78,  /* [4555] */
    (xdc_Char)0x25,  /* [4556] */
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
    (xdc_Char)0x65,  /* [4610] */
    (xdc_Char)0x78,  /* [4611] */
    (xdc_Char)0x63,  /* [4612] */
    (xdc_Char)0x65,  /* [4613] */
    (xdc_Char)0x70,  /* [4614] */
    (xdc_Char)0x74,  /* [4615] */
    (xdc_Char)0x69,  /* [4616] */
    (xdc_Char)0x6f,  /* [4617] */
    (xdc_Char)0x6e,  /* [4618] */
    (xdc_Char)0x3a,  /* [4619] */
    (xdc_Char)0x20,  /* [4620] */
    (xdc_Char)0x69,  /* [4621] */
    (xdc_Char)0x64,  /* [4622] */
    (xdc_Char)0x20,  /* [4623] */
    (xdc_Char)0x3d,  /* [4624] */
    (xdc_Char)0x20,  /* [4625] */
    (xdc_Char)0x25,  /* [4626] */
    (xdc_Char)0x64,  /* [4627] */
    (xdc_Char)0x2c,  /* [4628] */
    (xdc_Char)0x20,  /* [4629] */
    (xdc_Char)0x70,  /* [4630] */
    (xdc_Char)0x63,  /* [4631] */
    (xdc_Char)0x20,  /* [4632] */
    (xdc_Char)0x3d,  /* [4633] */
    (xdc_Char)0x20,  /* [4634] */
    (xdc_Char)0x25,  /* [4635] */
    (xdc_Char)0x30,  /* [4636] */
    (xdc_Char)0x38,  /* [4637] */
    (xdc_Char)0x78,  /* [4638] */
    (xdc_Char)0x2e,  /* [4639] */
    (xdc_Char)0xa,  /* [4640] */
    (xdc_Char)0x54,  /* [4641] */
    (xdc_Char)0x6f,  /* [4642] */
    (xdc_Char)0x20,  /* [4643] */
    (xdc_Char)0x73,  /* [4644] */
    (xdc_Char)0x65,  /* [4645] */
    (xdc_Char)0x65,  /* [4646] */
    (xdc_Char)0x20,  /* [4647] */
    (xdc_Char)0x6d,  /* [4648] */
    (xdc_Char)0x6f,  /* [4649] */
    (xdc_Char)0x72,  /* [4650] */
    (xdc_Char)0x65,  /* [4651] */
    (xdc_Char)0x20,  /* [4652] */
    (xdc_Char)0x65,  /* [4653] */
    (xdc_Char)0x78,  /* [4654] */
    (xdc_Char)0x63,  /* [4655] */
    (xdc_Char)0x65,  /* [4656] */
    (xdc_Char)0x70,  /* [4657] */
    (xdc_Char)0x74,  /* [4658] */
    (xdc_Char)0x69,  /* [4659] */
    (xdc_Char)0x6f,  /* [4660] */
    (xdc_Char)0x6e,  /* [4661] */
    (xdc_Char)0x20,  /* [4662] */
    (xdc_Char)0x64,  /* [4663] */
    (xdc_Char)0x65,  /* [4664] */
    (xdc_Char)0x74,  /* [4665] */
    (xdc_Char)0x61,  /* [4666] */
    (xdc_Char)0x69,  /* [4667] */
    (xdc_Char)0x6c,  /* [4668] */
    (xdc_Char)0x2c,  /* [4669] */
    (xdc_Char)0x20,  /* [4670] */
    (xdc_Char)0x73,  /* [4671] */
    (xdc_Char)0x65,  /* [4672] */
    (xdc_Char)0x74,  /* [4673] */
    (xdc_Char)0x20,  /* [4674] */
    (xdc_Char)0x74,  /* [4675] */
    (xdc_Char)0x69,  /* [4676] */
    (xdc_Char)0x2e,  /* [4677] */
    (xdc_Char)0x73,  /* [4678] */
    (xdc_Char)0x79,  /* [4679] */
    (xdc_Char)0x73,  /* [4680] */
    (xdc_Char)0x62,  /* [4681] */
    (xdc_Char)0x69,  /* [4682] */
    (xdc_Char)0x6f,  /* [4683] */
    (xdc_Char)0x73,  /* [4684] */
    (xdc_Char)0x2e,  /* [4685] */
    (xdc_Char)0x66,  /* [4686] */
    (xdc_Char)0x61,  /* [4687] */
    (xdc_Char)0x6d,  /* [4688] */
    (xdc_Char)0x69,  /* [4689] */
    (xdc_Char)0x6c,  /* [4690] */
    (xdc_Char)0x79,  /* [4691] */
    (xdc_Char)0x2e,  /* [4692] */
    (xdc_Char)0x61,  /* [4693] */
    (xdc_Char)0x72,  /* [4694] */
    (xdc_Char)0x6d,  /* [4695] */
    (xdc_Char)0x2e,  /* [4696] */
    (xdc_Char)0x6d,  /* [4697] */
    (xdc_Char)0x33,  /* [4698] */
    (xdc_Char)0x2e,  /* [4699] */
    (xdc_Char)0x48,  /* [4700] */
    (xdc_Char)0x77,  /* [4701] */
    (xdc_Char)0x69,  /* [4702] */
    (xdc_Char)0x2e,  /* [4703] */
    (xdc_Char)0x65,  /* [4704] */
    (xdc_Char)0x6e,  /* [4705] */
    (xdc_Char)0x61,  /* [4706] */
    (xdc_Char)0x62,  /* [4707] */
    (xdc_Char)0x6c,  /* [4708] */
    (xdc_Char)0x65,  /* [4709] */
    (xdc_Char)0x45,  /* [4710] */
    (xdc_Char)0x78,  /* [4711] */
    (xdc_Char)0x63,  /* [4712] */
    (xdc_Char)0x65,  /* [4713] */
    (xdc_Char)0x70,  /* [4714] */
    (xdc_Char)0x74,  /* [4715] */
    (xdc_Char)0x69,  /* [4716] */
    (xdc_Char)0x6f,  /* [4717] */
    (xdc_Char)0x6e,  /* [4718] */
    (xdc_Char)0x20,  /* [4719] */
    (xdc_Char)0x3d,  /* [4720] */
    (xdc_Char)0x20,  /* [4721] */
    (xdc_Char)0x74,  /* [4722] */
    (xdc_Char)0x72,  /* [4723] */
    (xdc_Char)0x75,  /* [4724] */
    (xdc_Char)0x65,  /* [4725] */
    (xdc_Char)0x20,  /* [4726] */
    (xdc_Char)0x6f,  /* [4727] */
    (xdc_Char)0x72,  /* [4728] */
    (xdc_Char)0x2c,  /* [4729] */
    (xdc_Char)0xa,  /* [4730] */
    (xdc_Char)0x65,  /* [4731] */
    (xdc_Char)0x78,  /* [4732] */
    (xdc_Char)0x61,  /* [4733] */
    (xdc_Char)0x6d,  /* [4734] */
    (xdc_Char)0x69,  /* [4735] */
    (xdc_Char)0x6e,  /* [4736] */
    (xdc_Char)0x65,  /* [4737] */
    (xdc_Char)0x20,  /* [4738] */
    (xdc_Char)0x74,  /* [4739] */
    (xdc_Char)0x68,  /* [4740] */
    (xdc_Char)0x65,  /* [4741] */
    (xdc_Char)0x20,  /* [4742] */
    (xdc_Char)0x45,  /* [4743] */
    (xdc_Char)0x78,  /* [4744] */
    (xdc_Char)0x63,  /* [4745] */
    (xdc_Char)0x65,  /* [4746] */
    (xdc_Char)0x70,  /* [4747] */
    (xdc_Char)0x74,  /* [4748] */
    (xdc_Char)0x69,  /* [4749] */
    (xdc_Char)0x6f,  /* [4750] */
    (xdc_Char)0x6e,  /* [4751] */
    (xdc_Char)0x20,  /* [4752] */
    (xdc_Char)0x76,  /* [4753] */
    (xdc_Char)0x69,  /* [4754] */
    (xdc_Char)0x65,  /* [4755] */
    (xdc_Char)0x77,  /* [4756] */
    (xdc_Char)0x20,  /* [4757] */
    (xdc_Char)0x66,  /* [4758] */
    (xdc_Char)0x6f,  /* [4759] */
    (xdc_Char)0x72,  /* [4760] */
    (xdc_Char)0x20,  /* [4761] */
    (xdc_Char)0x74,  /* [4762] */
    (xdc_Char)0x68,  /* [4763] */
    (xdc_Char)0x65,  /* [4764] */
    (xdc_Char)0x20,  /* [4765] */
    (xdc_Char)0x74,  /* [4766] */
    (xdc_Char)0x69,  /* [4767] */
    (xdc_Char)0x2e,  /* [4768] */
    (xdc_Char)0x73,  /* [4769] */
    (xdc_Char)0x79,  /* [4770] */
    (xdc_Char)0x73,  /* [4771] */
    (xdc_Char)0x62,  /* [4772] */
    (xdc_Char)0x69,  /* [4773] */
    (xdc_Char)0x6f,  /* [4774] */
    (xdc_Char)0x73,  /* [4775] */
    (xdc_Char)0x2e,  /* [4776] */
    (xdc_Char)0x66,  /* [4777] */
    (xdc_Char)0x61,  /* [4778] */
    (xdc_Char)0x6d,  /* [4779] */
    (xdc_Char)0x69,  /* [4780] */
    (xdc_Char)0x6c,  /* [4781] */
    (xdc_Char)0x79,  /* [4782] */
    (xdc_Char)0x2e,  /* [4783] */
    (xdc_Char)0x61,  /* [4784] */
    (xdc_Char)0x72,  /* [4785] */
    (xdc_Char)0x6d,  /* [4786] */
    (xdc_Char)0x2e,  /* [4787] */
    (xdc_Char)0x6d,  /* [4788] */
    (xdc_Char)0x33,  /* [4789] */
    (xdc_Char)0x2e,  /* [4790] */
    (xdc_Char)0x48,  /* [4791] */
    (xdc_Char)0x77,  /* [4792] */
    (xdc_Char)0x69,  /* [4793] */
    (xdc_Char)0x20,  /* [4794] */
    (xdc_Char)0x6d,  /* [4795] */
    (xdc_Char)0x6f,  /* [4796] */
    (xdc_Char)0x64,  /* [4797] */
    (xdc_Char)0x75,  /* [4798] */
    (xdc_Char)0x6c,  /* [4799] */
    (xdc_Char)0x65,  /* [4800] */
    (xdc_Char)0x20,  /* [4801] */
    (xdc_Char)0x75,  /* [4802] */
    (xdc_Char)0x73,  /* [4803] */
    (xdc_Char)0x69,  /* [4804] */
    (xdc_Char)0x6e,  /* [4805] */
    (xdc_Char)0x67,  /* [4806] */
    (xdc_Char)0x20,  /* [4807] */
    (xdc_Char)0x52,  /* [4808] */
    (xdc_Char)0x4f,  /* [4809] */
    (xdc_Char)0x56,  /* [4810] */
    (xdc_Char)0x2e,  /* [4811] */
    (xdc_Char)0x0,  /* [4812] */
    (xdc_Char)0x45,  /* [4813] */
    (xdc_Char)0x5f,  /* [4814] */
    (xdc_Char)0x6e,  /* [4815] */
    (xdc_Char)0x6f,  /* [4816] */
    (xdc_Char)0x49,  /* [4817] */
    (xdc_Char)0x73,  /* [4818] */
    (xdc_Char)0x72,  /* [4819] */
    (xdc_Char)0x3a,  /* [4820] */
    (xdc_Char)0x20,  /* [4821] */
    (xdc_Char)0x69,  /* [4822] */
    (xdc_Char)0x64,  /* [4823] */
    (xdc_Char)0x20,  /* [4824] */
    (xdc_Char)0x3d,  /* [4825] */
    (xdc_Char)0x20,  /* [4826] */
    (xdc_Char)0x25,  /* [4827] */
    (xdc_Char)0x64,  /* [4828] */
    (xdc_Char)0x2c,  /* [4829] */
    (xdc_Char)0x20,  /* [4830] */
    (xdc_Char)0x70,  /* [4831] */
    (xdc_Char)0x63,  /* [4832] */
    (xdc_Char)0x20,  /* [4833] */
    (xdc_Char)0x3d,  /* [4834] */
    (xdc_Char)0x20,  /* [4835] */
    (xdc_Char)0x25,  /* [4836] */
    (xdc_Char)0x30,  /* [4837] */
    (xdc_Char)0x38,  /* [4838] */
    (xdc_Char)0x78,  /* [4839] */
    (xdc_Char)0x0,  /* [4840] */
    (xdc_Char)0x45,  /* [4841] */
    (xdc_Char)0x5f,  /* [4842] */
    (xdc_Char)0x4e,  /* [4843] */
    (xdc_Char)0x4d,  /* [4844] */
    (xdc_Char)0x49,  /* [4845] */
    (xdc_Char)0x3a,  /* [4846] */
    (xdc_Char)0x20,  /* [4847] */
    (xdc_Char)0x25,  /* [4848] */
    (xdc_Char)0x73,  /* [4849] */
    (xdc_Char)0x0,  /* [4850] */
    (xdc_Char)0x45,  /* [4851] */
    (xdc_Char)0x5f,  /* [4852] */
    (xdc_Char)0x68,  /* [4853] */
    (xdc_Char)0x61,  /* [4854] */
    (xdc_Char)0x72,  /* [4855] */
    (xdc_Char)0x64,  /* [4856] */
    (xdc_Char)0x46,  /* [4857] */
    (xdc_Char)0x61,  /* [4858] */
    (xdc_Char)0x75,  /* [4859] */
    (xdc_Char)0x6c,  /* [4860] */
    (xdc_Char)0x74,  /* [4861] */
    (xdc_Char)0x3a,  /* [4862] */
    (xdc_Char)0x20,  /* [4863] */
    (xdc_Char)0x25,  /* [4864] */
    (xdc_Char)0x73,  /* [4865] */
    (xdc_Char)0x0,  /* [4866] */
    (xdc_Char)0x45,  /* [4867] */
    (xdc_Char)0x5f,  /* [4868] */
    (xdc_Char)0x6d,  /* [4869] */
    (xdc_Char)0x65,  /* [4870] */
    (xdc_Char)0x6d,  /* [4871] */
    (xdc_Char)0x46,  /* [4872] */
    (xdc_Char)0x61,  /* [4873] */
    (xdc_Char)0x75,  /* [4874] */
    (xdc_Char)0x6c,  /* [4875] */
    (xdc_Char)0x74,  /* [4876] */
    (xdc_Char)0x3a,  /* [4877] */
    (xdc_Char)0x20,  /* [4878] */
    (xdc_Char)0x25,  /* [4879] */
    (xdc_Char)0x73,  /* [4880] */
    (xdc_Char)0x0,  /* [4881] */
    (xdc_Char)0x45,  /* [4882] */
    (xdc_Char)0x5f,  /* [4883] */
    (xdc_Char)0x62,  /* [4884] */
    (xdc_Char)0x75,  /* [4885] */
    (xdc_Char)0x73,  /* [4886] */
    (xdc_Char)0x46,  /* [4887] */
    (xdc_Char)0x61,  /* [4888] */
    (xdc_Char)0x75,  /* [4889] */
    (xdc_Char)0x6c,  /* [4890] */
    (xdc_Char)0x74,  /* [4891] */
    (xdc_Char)0x3a,  /* [4892] */
    (xdc_Char)0x20,  /* [4893] */
    (xdc_Char)0x25,  /* [4894] */
    (xdc_Char)0x73,  /* [4895] */
    (xdc_Char)0x0,  /* [4896] */
    (xdc_Char)0x45,  /* [4897] */
    (xdc_Char)0x5f,  /* [4898] */
    (xdc_Char)0x75,  /* [4899] */
    (xdc_Char)0x73,  /* [4900] */
    (xdc_Char)0x61,  /* [4901] */
    (xdc_Char)0x67,  /* [4902] */
    (xdc_Char)0x65,  /* [4903] */
    (xdc_Char)0x46,  /* [4904] */
    (xdc_Char)0x61,  /* [4905] */
    (xdc_Char)0x75,  /* [4906] */
    (xdc_Char)0x6c,  /* [4907] */
    (xdc_Char)0x74,  /* [4908] */
    (xdc_Char)0x3a,  /* [4909] */
    (xdc_Char)0x20,  /* [4910] */
    (xdc_Char)0x25,  /* [4911] */
    (xdc_Char)0x73,  /* [4912] */
    (xdc_Char)0x0,  /* [4913] */
    (xdc_Char)0x45,  /* [4914] */
    (xdc_Char)0x5f,  /* [4915] */
    (xdc_Char)0x73,  /* [4916] */
    (xdc_Char)0x76,  /* [4917] */
    (xdc_Char)0x43,  /* [4918] */
    (xdc_Char)0x61,  /* [4919] */
    (xdc_Char)0x6c,  /* [4920] */
    (xdc_Char)0x6c,  /* [4921] */
    (xdc_Char)0x3a,  /* [4922] */
    (xdc_Char)0x20,  /* [4923] */
    (xdc_Char)0x73,  /* [4924] */
    (xdc_Char)0x76,  /* [4925] */
    (xdc_Char)0x4e,  /* [4926] */
    (xdc_Char)0x75,  /* [4927] */
    (xdc_Char)0x6d,  /* [4928] */
    (xdc_Char)0x20,  /* [4929] */
    (xdc_Char)0x3d,  /* [4930] */
    (xdc_Char)0x20,  /* [4931] */
    (xdc_Char)0x25,  /* [4932] */
    (xdc_Char)0x64,  /* [4933] */
    (xdc_Char)0x0,  /* [4934] */
    (xdc_Char)0x45,  /* [4935] */
    (xdc_Char)0x5f,  /* [4936] */
    (xdc_Char)0x64,  /* [4937] */
    (xdc_Char)0x65,  /* [4938] */
    (xdc_Char)0x62,  /* [4939] */
    (xdc_Char)0x75,  /* [4940] */
    (xdc_Char)0x67,  /* [4941] */
    (xdc_Char)0x4d,  /* [4942] */
    (xdc_Char)0x6f,  /* [4943] */
    (xdc_Char)0x6e,  /* [4944] */
    (xdc_Char)0x3a,  /* [4945] */
    (xdc_Char)0x20,  /* [4946] */
    (xdc_Char)0x25,  /* [4947] */
    (xdc_Char)0x73,  /* [4948] */
    (xdc_Char)0x0,  /* [4949] */
    (xdc_Char)0x45,  /* [4950] */
    (xdc_Char)0x5f,  /* [4951] */
    (xdc_Char)0x72,  /* [4952] */
    (xdc_Char)0x65,  /* [4953] */
    (xdc_Char)0x73,  /* [4954] */
    (xdc_Char)0x65,  /* [4955] */
    (xdc_Char)0x72,  /* [4956] */
    (xdc_Char)0x76,  /* [4957] */
    (xdc_Char)0x65,  /* [4958] */
    (xdc_Char)0x64,  /* [4959] */
    (xdc_Char)0x3a,  /* [4960] */
    (xdc_Char)0x20,  /* [4961] */
    (xdc_Char)0x25,  /* [4962] */
    (xdc_Char)0x73,  /* [4963] */
    (xdc_Char)0x20,  /* [4964] */
    (xdc_Char)0x25,  /* [4965] */
    (xdc_Char)0x64,  /* [4966] */
    (xdc_Char)0x0,  /* [4967] */
    (xdc_Char)0x45,  /* [4968] */
    (xdc_Char)0x5f,  /* [4969] */
    (xdc_Char)0x69,  /* [4970] */
    (xdc_Char)0x6e,  /* [4971] */
    (xdc_Char)0x76,  /* [4972] */
    (xdc_Char)0x61,  /* [4973] */
    (xdc_Char)0x6c,  /* [4974] */
    (xdc_Char)0x69,  /* [4975] */
    (xdc_Char)0x64,  /* [4976] */
    (xdc_Char)0x54,  /* [4977] */
    (xdc_Char)0x69,  /* [4978] */
    (xdc_Char)0x6d,  /* [4979] */
    (xdc_Char)0x65,  /* [4980] */
    (xdc_Char)0x72,  /* [4981] */
    (xdc_Char)0x3a,  /* [4982] */
    (xdc_Char)0x20,  /* [4983] */
    (xdc_Char)0x49,  /* [4984] */
    (xdc_Char)0x6e,  /* [4985] */
    (xdc_Char)0x76,  /* [4986] */
    (xdc_Char)0x61,  /* [4987] */
    (xdc_Char)0x6c,  /* [4988] */
    (xdc_Char)0x69,  /* [4989] */
    (xdc_Char)0x64,  /* [4990] */
    (xdc_Char)0x20,  /* [4991] */
    (xdc_Char)0x54,  /* [4992] */
    (xdc_Char)0x69,  /* [4993] */
    (xdc_Char)0x6d,  /* [4994] */
    (xdc_Char)0x65,  /* [4995] */
    (xdc_Char)0x72,  /* [4996] */
    (xdc_Char)0x20,  /* [4997] */
    (xdc_Char)0x49,  /* [4998] */
    (xdc_Char)0x64,  /* [4999] */
    (xdc_Char)0x20,  /* [5000] */
    (xdc_Char)0x25,  /* [5001] */
    (xdc_Char)0x64,  /* [5002] */
    (xdc_Char)0x0,  /* [5003] */
    (xdc_Char)0x45,  /* [5004] */
    (xdc_Char)0x5f,  /* [5005] */
    (xdc_Char)0x6e,  /* [5006] */
    (xdc_Char)0x6f,  /* [5007] */
    (xdc_Char)0x74,  /* [5008] */
    (xdc_Char)0x41,  /* [5009] */
    (xdc_Char)0x76,  /* [5010] */
    (xdc_Char)0x61,  /* [5011] */
    (xdc_Char)0x69,  /* [5012] */
    (xdc_Char)0x6c,  /* [5013] */
    (xdc_Char)0x61,  /* [5014] */
    (xdc_Char)0x62,  /* [5015] */
    (xdc_Char)0x6c,  /* [5016] */
    (xdc_Char)0x65,  /* [5017] */
    (xdc_Char)0x3a,  /* [5018] */
    (xdc_Char)0x20,  /* [5019] */
    (xdc_Char)0x54,  /* [5020] */
    (xdc_Char)0x69,  /* [5021] */
    (xdc_Char)0x6d,  /* [5022] */
    (xdc_Char)0x65,  /* [5023] */
    (xdc_Char)0x72,  /* [5024] */
    (xdc_Char)0x20,  /* [5025] */
    (xdc_Char)0x6e,  /* [5026] */
    (xdc_Char)0x6f,  /* [5027] */
    (xdc_Char)0x74,  /* [5028] */
    (xdc_Char)0x20,  /* [5029] */
    (xdc_Char)0x61,  /* [5030] */
    (xdc_Char)0x76,  /* [5031] */
    (xdc_Char)0x61,  /* [5032] */
    (xdc_Char)0x69,  /* [5033] */
    (xdc_Char)0x6c,  /* [5034] */
    (xdc_Char)0x61,  /* [5035] */
    (xdc_Char)0x62,  /* [5036] */
    (xdc_Char)0x6c,  /* [5037] */
    (xdc_Char)0x65,  /* [5038] */
    (xdc_Char)0x20,  /* [5039] */
    (xdc_Char)0x25,  /* [5040] */
    (xdc_Char)0x64,  /* [5041] */
    (xdc_Char)0x0,  /* [5042] */
    (xdc_Char)0x45,  /* [5043] */
    (xdc_Char)0x5f,  /* [5044] */
    (xdc_Char)0x63,  /* [5045] */
    (xdc_Char)0x61,  /* [5046] */
    (xdc_Char)0x6e,  /* [5047] */
    (xdc_Char)0x6e,  /* [5048] */
    (xdc_Char)0x6f,  /* [5049] */
    (xdc_Char)0x74,  /* [5050] */
    (xdc_Char)0x53,  /* [5051] */
    (xdc_Char)0x75,  /* [5052] */
    (xdc_Char)0x70,  /* [5053] */
    (xdc_Char)0x70,  /* [5054] */
    (xdc_Char)0x6f,  /* [5055] */
    (xdc_Char)0x72,  /* [5056] */
    (xdc_Char)0x74,  /* [5057] */
    (xdc_Char)0x3a,  /* [5058] */
    (xdc_Char)0x20,  /* [5059] */
    (xdc_Char)0x54,  /* [5060] */
    (xdc_Char)0x69,  /* [5061] */
    (xdc_Char)0x6d,  /* [5062] */
    (xdc_Char)0x65,  /* [5063] */
    (xdc_Char)0x72,  /* [5064] */
    (xdc_Char)0x20,  /* [5065] */
    (xdc_Char)0x63,  /* [5066] */
    (xdc_Char)0x61,  /* [5067] */
    (xdc_Char)0x6e,  /* [5068] */
    (xdc_Char)0x6e,  /* [5069] */
    (xdc_Char)0x6f,  /* [5070] */
    (xdc_Char)0x74,  /* [5071] */
    (xdc_Char)0x20,  /* [5072] */
    (xdc_Char)0x73,  /* [5073] */
    (xdc_Char)0x75,  /* [5074] */
    (xdc_Char)0x70,  /* [5075] */
    (xdc_Char)0x70,  /* [5076] */
    (xdc_Char)0x6f,  /* [5077] */
    (xdc_Char)0x72,  /* [5078] */
    (xdc_Char)0x74,  /* [5079] */
    (xdc_Char)0x20,  /* [5080] */
    (xdc_Char)0x72,  /* [5081] */
    (xdc_Char)0x65,  /* [5082] */
    (xdc_Char)0x71,  /* [5083] */
    (xdc_Char)0x75,  /* [5084] */
    (xdc_Char)0x65,  /* [5085] */
    (xdc_Char)0x73,  /* [5086] */
    (xdc_Char)0x74,  /* [5087] */
    (xdc_Char)0x65,  /* [5088] */
    (xdc_Char)0x64,  /* [5089] */
    (xdc_Char)0x20,  /* [5090] */
    (xdc_Char)0x70,  /* [5091] */
    (xdc_Char)0x65,  /* [5092] */
    (xdc_Char)0x72,  /* [5093] */
    (xdc_Char)0x69,  /* [5094] */
    (xdc_Char)0x6f,  /* [5095] */
    (xdc_Char)0x64,  /* [5096] */
    (xdc_Char)0x20,  /* [5097] */
    (xdc_Char)0x25,  /* [5098] */
    (xdc_Char)0x64,  /* [5099] */
    (xdc_Char)0x0,  /* [5100] */
    (xdc_Char)0x45,  /* [5101] */
    (xdc_Char)0x5f,  /* [5102] */
    (xdc_Char)0x6d,  /* [5103] */
    (xdc_Char)0x69,  /* [5104] */
    (xdc_Char)0x73,  /* [5105] */
    (xdc_Char)0x6d,  /* [5106] */
    (xdc_Char)0x61,  /* [5107] */
    (xdc_Char)0x74,  /* [5108] */
    (xdc_Char)0x63,  /* [5109] */
    (xdc_Char)0x68,  /* [5110] */
    (xdc_Char)0x65,  /* [5111] */
    (xdc_Char)0x64,  /* [5112] */
    (xdc_Char)0x49,  /* [5113] */
    (xdc_Char)0x64,  /* [5114] */
    (xdc_Char)0x73,  /* [5115] */
    (xdc_Char)0x3a,  /* [5116] */
    (xdc_Char)0x20,  /* [5117] */
    (xdc_Char)0x43,  /* [5118] */
    (xdc_Char)0x6f,  /* [5119] */
    (xdc_Char)0x72,  /* [5120] */
    (xdc_Char)0x65,  /* [5121] */
    (xdc_Char)0x5f,  /* [5122] */
    (xdc_Char)0x49,  /* [5123] */
    (xdc_Char)0x64,  /* [5124] */
    (xdc_Char)0x3a,  /* [5125] */
    (xdc_Char)0x20,  /* [5126] */
    (xdc_Char)0x25,  /* [5127] */
    (xdc_Char)0x64,  /* [5128] */
    (xdc_Char)0x20,  /* [5129] */
    (xdc_Char)0x64,  /* [5130] */
    (xdc_Char)0x6f,  /* [5131] */
    (xdc_Char)0x65,  /* [5132] */
    (xdc_Char)0x73,  /* [5133] */
    (xdc_Char)0x20,  /* [5134] */
    (xdc_Char)0x6e,  /* [5135] */
    (xdc_Char)0x6f,  /* [5136] */
    (xdc_Char)0x74,  /* [5137] */
    (xdc_Char)0x20,  /* [5138] */
    (xdc_Char)0x6d,  /* [5139] */
    (xdc_Char)0x61,  /* [5140] */
    (xdc_Char)0x74,  /* [5141] */
    (xdc_Char)0x63,  /* [5142] */
    (xdc_Char)0x68,  /* [5143] */
    (xdc_Char)0x20,  /* [5144] */
    (xdc_Char)0x68,  /* [5145] */
    (xdc_Char)0x61,  /* [5146] */
    (xdc_Char)0x72,  /* [5147] */
    (xdc_Char)0x64,  /* [5148] */
    (xdc_Char)0x77,  /* [5149] */
    (xdc_Char)0x61,  /* [5150] */
    (xdc_Char)0x72,  /* [5151] */
    (xdc_Char)0x65,  /* [5152] */
    (xdc_Char)0x20,  /* [5153] */
    (xdc_Char)0x63,  /* [5154] */
    (xdc_Char)0x6f,  /* [5155] */
    (xdc_Char)0x72,  /* [5156] */
    (xdc_Char)0x65,  /* [5157] */
    (xdc_Char)0x20,  /* [5158] */
    (xdc_Char)0x49,  /* [5159] */
    (xdc_Char)0x64,  /* [5160] */
    (xdc_Char)0x3a,  /* [5161] */
    (xdc_Char)0x20,  /* [5162] */
    (xdc_Char)0x25,  /* [5163] */
    (xdc_Char)0x64,  /* [5164] */
    (xdc_Char)0x0,  /* [5165] */
    (xdc_Char)0x45,  /* [5166] */
    (xdc_Char)0x5f,  /* [5167] */
    (xdc_Char)0x69,  /* [5168] */
    (xdc_Char)0x6e,  /* [5169] */
    (xdc_Char)0x76,  /* [5170] */
    (xdc_Char)0x61,  /* [5171] */
    (xdc_Char)0x6c,  /* [5172] */
    (xdc_Char)0x69,  /* [5173] */
    (xdc_Char)0x64,  /* [5174] */
    (xdc_Char)0x49,  /* [5175] */
    (xdc_Char)0x6e,  /* [5176] */
    (xdc_Char)0x64,  /* [5177] */
    (xdc_Char)0x65,  /* [5178] */
    (xdc_Char)0x78,  /* [5179] */
    (xdc_Char)0x20,  /* [5180] */
    (xdc_Char)0x25,  /* [5181] */
    (xdc_Char)0x64,  /* [5182] */
    (xdc_Char)0x0,  /* [5183] */
    (xdc_Char)0x45,  /* [5184] */
    (xdc_Char)0x5f,  /* [5185] */
    (xdc_Char)0x67,  /* [5186] */
    (xdc_Char)0x61,  /* [5187] */
    (xdc_Char)0x74,  /* [5188] */
    (xdc_Char)0x65,  /* [5189] */
    (xdc_Char)0x49,  /* [5190] */
    (xdc_Char)0x6e,  /* [5191] */
    (xdc_Char)0x55,  /* [5192] */
    (xdc_Char)0x73,  /* [5193] */
    (xdc_Char)0x65,  /* [5194] */
    (xdc_Char)0x20,  /* [5195] */
    (xdc_Char)0x25,  /* [5196] */
    (xdc_Char)0x64,  /* [5197] */
    (xdc_Char)0x0,  /* [5198] */
    (xdc_Char)0x45,  /* [5199] */
    (xdc_Char)0x5f,  /* [5200] */
    (xdc_Char)0x6d,  /* [5201] */
    (xdc_Char)0x61,  /* [5202] */
    (xdc_Char)0x78,  /* [5203] */
    (xdc_Char)0x52,  /* [5204] */
    (xdc_Char)0x65,  /* [5205] */
    (xdc_Char)0x61,  /* [5206] */
    (xdc_Char)0x63,  /* [5207] */
    (xdc_Char)0x68,  /* [5208] */
    (xdc_Char)0x65,  /* [5209] */
    (xdc_Char)0x64,  /* [5210] */
    (xdc_Char)0x3a,  /* [5211] */
    (xdc_Char)0x20,  /* [5212] */
    (xdc_Char)0x41,  /* [5213] */
    (xdc_Char)0x6c,  /* [5214] */
    (xdc_Char)0x6c,  /* [5215] */
    (xdc_Char)0x20,  /* [5216] */
    (xdc_Char)0x65,  /* [5217] */
    (xdc_Char)0x6e,  /* [5218] */
    (xdc_Char)0x74,  /* [5219] */
    (xdc_Char)0x72,  /* [5220] */
    (xdc_Char)0x69,  /* [5221] */
    (xdc_Char)0x65,  /* [5222] */
    (xdc_Char)0x73,  /* [5223] */
    (xdc_Char)0x20,  /* [5224] */
    (xdc_Char)0x69,  /* [5225] */
    (xdc_Char)0x6e,  /* [5226] */
    (xdc_Char)0x20,  /* [5227] */
    (xdc_Char)0x75,  /* [5228] */
    (xdc_Char)0x73,  /* [5229] */
    (xdc_Char)0x65,  /* [5230] */
    (xdc_Char)0x2e,  /* [5231] */
    (xdc_Char)0x20,  /* [5232] */
    (xdc_Char)0x4e,  /* [5233] */
    (xdc_Char)0x61,  /* [5234] */
    (xdc_Char)0x6d,  /* [5235] */
    (xdc_Char)0x65,  /* [5236] */
    (xdc_Char)0x53,  /* [5237] */
    (xdc_Char)0x65,  /* [5238] */
    (xdc_Char)0x72,  /* [5239] */
    (xdc_Char)0x76,  /* [5240] */
    (xdc_Char)0x65,  /* [5241] */
    (xdc_Char)0x72,  /* [5242] */
    (xdc_Char)0x2e,  /* [5243] */
    (xdc_Char)0x6d,  /* [5244] */
    (xdc_Char)0x61,  /* [5245] */
    (xdc_Char)0x78,  /* [5246] */
    (xdc_Char)0x52,  /* [5247] */
    (xdc_Char)0x75,  /* [5248] */
    (xdc_Char)0x6e,  /* [5249] */
    (xdc_Char)0x74,  /* [5250] */
    (xdc_Char)0x69,  /* [5251] */
    (xdc_Char)0x6d,  /* [5252] */
    (xdc_Char)0x65,  /* [5253] */
    (xdc_Char)0x45,  /* [5254] */
    (xdc_Char)0x6e,  /* [5255] */
    (xdc_Char)0x74,  /* [5256] */
    (xdc_Char)0x72,  /* [5257] */
    (xdc_Char)0x69,  /* [5258] */
    (xdc_Char)0x65,  /* [5259] */
    (xdc_Char)0x73,  /* [5260] */
    (xdc_Char)0x20,  /* [5261] */
    (xdc_Char)0x69,  /* [5262] */
    (xdc_Char)0x73,  /* [5263] */
    (xdc_Char)0x20,  /* [5264] */
    (xdc_Char)0x25,  /* [5265] */
    (xdc_Char)0x64,  /* [5266] */
    (xdc_Char)0x0,  /* [5267] */
    (xdc_Char)0x45,  /* [5268] */
    (xdc_Char)0x5f,  /* [5269] */
    (xdc_Char)0x65,  /* [5270] */
    (xdc_Char)0x6e,  /* [5271] */
    (xdc_Char)0x74,  /* [5272] */
    (xdc_Char)0x72,  /* [5273] */
    (xdc_Char)0x79,  /* [5274] */
    (xdc_Char)0x45,  /* [5275] */
    (xdc_Char)0x78,  /* [5276] */
    (xdc_Char)0x69,  /* [5277] */
    (xdc_Char)0x73,  /* [5278] */
    (xdc_Char)0x74,  /* [5279] */
    (xdc_Char)0x73,  /* [5280] */
    (xdc_Char)0x3a,  /* [5281] */
    (xdc_Char)0x20,  /* [5282] */
    (xdc_Char)0x25,  /* [5283] */
    (xdc_Char)0x73,  /* [5284] */
    (xdc_Char)0x20,  /* [5285] */
    (xdc_Char)0x6e,  /* [5286] */
    (xdc_Char)0x61,  /* [5287] */
    (xdc_Char)0x6d,  /* [5288] */
    (xdc_Char)0x65,  /* [5289] */
    (xdc_Char)0x20,  /* [5290] */
    (xdc_Char)0x61,  /* [5291] */
    (xdc_Char)0x6c,  /* [5292] */
    (xdc_Char)0x72,  /* [5293] */
    (xdc_Char)0x65,  /* [5294] */
    (xdc_Char)0x61,  /* [5295] */
    (xdc_Char)0x64,  /* [5296] */
    (xdc_Char)0x79,  /* [5297] */
    (xdc_Char)0x20,  /* [5298] */
    (xdc_Char)0x69,  /* [5299] */
    (xdc_Char)0x6e,  /* [5300] */
    (xdc_Char)0x20,  /* [5301] */
    (xdc_Char)0x74,  /* [5302] */
    (xdc_Char)0x61,  /* [5303] */
    (xdc_Char)0x62,  /* [5304] */
    (xdc_Char)0x6c,  /* [5305] */
    (xdc_Char)0x65,  /* [5306] */
    (xdc_Char)0x20,  /* [5307] */
    (xdc_Char)0x0,  /* [5308] */
    (xdc_Char)0x45,  /* [5309] */
    (xdc_Char)0x5f,  /* [5310] */
    (xdc_Char)0x67,  /* [5311] */
    (xdc_Char)0x61,  /* [5312] */
    (xdc_Char)0x74,  /* [5313] */
    (xdc_Char)0x65,  /* [5314] */
    (xdc_Char)0x55,  /* [5315] */
    (xdc_Char)0x6e,  /* [5316] */
    (xdc_Char)0x61,  /* [5317] */
    (xdc_Char)0x76,  /* [5318] */
    (xdc_Char)0x61,  /* [5319] */
    (xdc_Char)0x69,  /* [5320] */
    (xdc_Char)0x6c,  /* [5321] */
    (xdc_Char)0x61,  /* [5322] */
    (xdc_Char)0x62,  /* [5323] */
    (xdc_Char)0x6c,  /* [5324] */
    (xdc_Char)0x65,  /* [5325] */
    (xdc_Char)0x3a,  /* [5326] */
    (xdc_Char)0x20,  /* [5327] */
    (xdc_Char)0x4e,  /* [5328] */
    (xdc_Char)0x6f,  /* [5329] */
    (xdc_Char)0x20,  /* [5330] */
    (xdc_Char)0x67,  /* [5331] */
    (xdc_Char)0x61,  /* [5332] */
    (xdc_Char)0x74,  /* [5333] */
    (xdc_Char)0x65,  /* [5334] */
    (xdc_Char)0x73,  /* [5335] */
    (xdc_Char)0x20,  /* [5336] */
    (xdc_Char)0x6f,  /* [5337] */
    (xdc_Char)0x66,  /* [5338] */
    (xdc_Char)0x20,  /* [5339] */
    (xdc_Char)0x72,  /* [5340] */
    (xdc_Char)0x65,  /* [5341] */
    (xdc_Char)0x71,  /* [5342] */
    (xdc_Char)0x75,  /* [5343] */
    (xdc_Char)0x65,  /* [5344] */
    (xdc_Char)0x73,  /* [5345] */
    (xdc_Char)0x74,  /* [5346] */
    (xdc_Char)0x65,  /* [5347] */
    (xdc_Char)0x64,  /* [5348] */
    (xdc_Char)0x20,  /* [5349] */
    (xdc_Char)0x74,  /* [5350] */
    (xdc_Char)0x79,  /* [5351] */
    (xdc_Char)0x70,  /* [5352] */
    (xdc_Char)0x65,  /* [5353] */
    (xdc_Char)0x20,  /* [5354] */
    (xdc_Char)0x61,  /* [5355] */
    (xdc_Char)0x72,  /* [5356] */
    (xdc_Char)0x65,  /* [5357] */
    (xdc_Char)0x20,  /* [5358] */
    (xdc_Char)0x61,  /* [5359] */
    (xdc_Char)0x76,  /* [5360] */
    (xdc_Char)0x61,  /* [5361] */
    (xdc_Char)0x69,  /* [5362] */
    (xdc_Char)0x6c,  /* [5363] */
    (xdc_Char)0x61,  /* [5364] */
    (xdc_Char)0x62,  /* [5365] */
    (xdc_Char)0x6c,  /* [5366] */
    (xdc_Char)0x65,  /* [5367] */
    (xdc_Char)0x0,  /* [5368] */
    (xdc_Char)0x45,  /* [5369] */
    (xdc_Char)0x5f,  /* [5370] */
    (xdc_Char)0x6c,  /* [5371] */
    (xdc_Char)0x6f,  /* [5372] */
    (xdc_Char)0x63,  /* [5373] */
    (xdc_Char)0x61,  /* [5374] */
    (xdc_Char)0x6c,  /* [5375] */
    (xdc_Char)0x47,  /* [5376] */
    (xdc_Char)0x61,  /* [5377] */
    (xdc_Char)0x74,  /* [5378] */
    (xdc_Char)0x65,  /* [5379] */
    (xdc_Char)0x3a,  /* [5380] */
    (xdc_Char)0x20,  /* [5381] */
    (xdc_Char)0x4f,  /* [5382] */
    (xdc_Char)0x6e,  /* [5383] */
    (xdc_Char)0x6c,  /* [5384] */
    (xdc_Char)0x79,  /* [5385] */
    (xdc_Char)0x20,  /* [5386] */
    (xdc_Char)0x63,  /* [5387] */
    (xdc_Char)0x72,  /* [5388] */
    (xdc_Char)0x65,  /* [5389] */
    (xdc_Char)0x61,  /* [5390] */
    (xdc_Char)0x74,  /* [5391] */
    (xdc_Char)0x6f,  /* [5392] */
    (xdc_Char)0x72,  /* [5393] */
    (xdc_Char)0x20,  /* [5394] */
    (xdc_Char)0x63,  /* [5395] */
    (xdc_Char)0x61,  /* [5396] */
    (xdc_Char)0x6e,  /* [5397] */
    (xdc_Char)0x20,  /* [5398] */
    (xdc_Char)0x6f,  /* [5399] */
    (xdc_Char)0x70,  /* [5400] */
    (xdc_Char)0x65,  /* [5401] */
    (xdc_Char)0x6e,  /* [5402] */
    (xdc_Char)0x20,  /* [5403] */
    (xdc_Char)0x6c,  /* [5404] */
    (xdc_Char)0x6f,  /* [5405] */
    (xdc_Char)0x63,  /* [5406] */
    (xdc_Char)0x61,  /* [5407] */
    (xdc_Char)0x6c,  /* [5408] */
    (xdc_Char)0x20,  /* [5409] */
    (xdc_Char)0x47,  /* [5410] */
    (xdc_Char)0x61,  /* [5411] */
    (xdc_Char)0x74,  /* [5412] */
    (xdc_Char)0x65,  /* [5413] */
    (xdc_Char)0x0,  /* [5414] */
    (xdc_Char)0x45,  /* [5415] */
    (xdc_Char)0x5f,  /* [5416] */
    (xdc_Char)0x6d,  /* [5417] */
    (xdc_Char)0x61,  /* [5418] */
    (xdc_Char)0x78,  /* [5419] */
    (xdc_Char)0x52,  /* [5420] */
    (xdc_Char)0x65,  /* [5421] */
    (xdc_Char)0x61,  /* [5422] */
    (xdc_Char)0x63,  /* [5423] */
    (xdc_Char)0x68,  /* [5424] */
    (xdc_Char)0x65,  /* [5425] */
    (xdc_Char)0x64,  /* [5426] */
    (xdc_Char)0x3a,  /* [5427] */
    (xdc_Char)0x20,  /* [5428] */
    (xdc_Char)0x41,  /* [5429] */
    (xdc_Char)0x6c,  /* [5430] */
    (xdc_Char)0x6c,  /* [5431] */
    (xdc_Char)0x20,  /* [5432] */
    (xdc_Char)0x6f,  /* [5433] */
    (xdc_Char)0x62,  /* [5434] */
    (xdc_Char)0x6a,  /* [5435] */
    (xdc_Char)0x65,  /* [5436] */
    (xdc_Char)0x63,  /* [5437] */
    (xdc_Char)0x74,  /* [5438] */
    (xdc_Char)0x73,  /* [5439] */
    (xdc_Char)0x20,  /* [5440] */
    (xdc_Char)0x69,  /* [5441] */
    (xdc_Char)0x6e,  /* [5442] */
    (xdc_Char)0x20,  /* [5443] */
    (xdc_Char)0x75,  /* [5444] */
    (xdc_Char)0x73,  /* [5445] */
    (xdc_Char)0x65,  /* [5446] */
    (xdc_Char)0x2e,  /* [5447] */
    (xdc_Char)0x20,  /* [5448] */
    (xdc_Char)0x4d,  /* [5449] */
    (xdc_Char)0x65,  /* [5450] */
    (xdc_Char)0x73,  /* [5451] */
    (xdc_Char)0x73,  /* [5452] */
    (xdc_Char)0x61,  /* [5453] */
    (xdc_Char)0x67,  /* [5454] */
    (xdc_Char)0x65,  /* [5455] */
    (xdc_Char)0x51,  /* [5456] */
    (xdc_Char)0x2e,  /* [5457] */
    (xdc_Char)0x6d,  /* [5458] */
    (xdc_Char)0x61,  /* [5459] */
    (xdc_Char)0x78,  /* [5460] */
    (xdc_Char)0x52,  /* [5461] */
    (xdc_Char)0x75,  /* [5462] */
    (xdc_Char)0x6e,  /* [5463] */
    (xdc_Char)0x74,  /* [5464] */
    (xdc_Char)0x69,  /* [5465] */
    (xdc_Char)0x6d,  /* [5466] */
    (xdc_Char)0x65,  /* [5467] */
    (xdc_Char)0x45,  /* [5468] */
    (xdc_Char)0x6e,  /* [5469] */
    (xdc_Char)0x74,  /* [5470] */
    (xdc_Char)0x72,  /* [5471] */
    (xdc_Char)0x69,  /* [5472] */
    (xdc_Char)0x65,  /* [5473] */
    (xdc_Char)0x73,  /* [5474] */
    (xdc_Char)0x20,  /* [5475] */
    (xdc_Char)0x69,  /* [5476] */
    (xdc_Char)0x73,  /* [5477] */
    (xdc_Char)0x20,  /* [5478] */
    (xdc_Char)0x25,  /* [5479] */
    (xdc_Char)0x64,  /* [5480] */
    (xdc_Char)0x0,  /* [5481] */
    (xdc_Char)0x45,  /* [5482] */
    (xdc_Char)0x5f,  /* [5483] */
    (xdc_Char)0x75,  /* [5484] */
    (xdc_Char)0x6e,  /* [5485] */
    (xdc_Char)0x72,  /* [5486] */
    (xdc_Char)0x65,  /* [5487] */
    (xdc_Char)0x67,  /* [5488] */
    (xdc_Char)0x69,  /* [5489] */
    (xdc_Char)0x73,  /* [5490] */
    (xdc_Char)0x74,  /* [5491] */
    (xdc_Char)0x65,  /* [5492] */
    (xdc_Char)0x72,  /* [5493] */
    (xdc_Char)0x48,  /* [5494] */
    (xdc_Char)0x65,  /* [5495] */
    (xdc_Char)0x61,  /* [5496] */
    (xdc_Char)0x70,  /* [5497] */
    (xdc_Char)0x49,  /* [5498] */
    (xdc_Char)0x64,  /* [5499] */
    (xdc_Char)0x3a,  /* [5500] */
    (xdc_Char)0x20,  /* [5501] */
    (xdc_Char)0x48,  /* [5502] */
    (xdc_Char)0x65,  /* [5503] */
    (xdc_Char)0x61,  /* [5504] */
    (xdc_Char)0x70,  /* [5505] */
    (xdc_Char)0x20,  /* [5506] */
    (xdc_Char)0x69,  /* [5507] */
    (xdc_Char)0x64,  /* [5508] */
    (xdc_Char)0x20,  /* [5509] */
    (xdc_Char)0x25,  /* [5510] */
    (xdc_Char)0x64,  /* [5511] */
    (xdc_Char)0x20,  /* [5512] */
    (xdc_Char)0x6e,  /* [5513] */
    (xdc_Char)0x6f,  /* [5514] */
    (xdc_Char)0x74,  /* [5515] */
    (xdc_Char)0x20,  /* [5516] */
    (xdc_Char)0x72,  /* [5517] */
    (xdc_Char)0x65,  /* [5518] */
    (xdc_Char)0x67,  /* [5519] */
    (xdc_Char)0x69,  /* [5520] */
    (xdc_Char)0x73,  /* [5521] */
    (xdc_Char)0x74,  /* [5522] */
    (xdc_Char)0x65,  /* [5523] */
    (xdc_Char)0x72,  /* [5524] */
    (xdc_Char)0x65,  /* [5525] */
    (xdc_Char)0x64,  /* [5526] */
    (xdc_Char)0x0,  /* [5527] */
    (xdc_Char)0x45,  /* [5528] */
    (xdc_Char)0x5f,  /* [5529] */
    (xdc_Char)0x6e,  /* [5530] */
    (xdc_Char)0x61,  /* [5531] */
    (xdc_Char)0x6d,  /* [5532] */
    (xdc_Char)0x65,  /* [5533] */
    (xdc_Char)0x46,  /* [5534] */
    (xdc_Char)0x61,  /* [5535] */
    (xdc_Char)0x69,  /* [5536] */
    (xdc_Char)0x6c,  /* [5537] */
    (xdc_Char)0x65,  /* [5538] */
    (xdc_Char)0x64,  /* [5539] */
    (xdc_Char)0x3a,  /* [5540] */
    (xdc_Char)0x20,  /* [5541] */
    (xdc_Char)0x27,  /* [5542] */
    (xdc_Char)0x25,  /* [5543] */
    (xdc_Char)0x73,  /* [5544] */
    (xdc_Char)0x27,  /* [5545] */
    (xdc_Char)0x20,  /* [5546] */
    (xdc_Char)0x6e,  /* [5547] */
    (xdc_Char)0x61,  /* [5548] */
    (xdc_Char)0x6d,  /* [5549] */
    (xdc_Char)0x65,  /* [5550] */
    (xdc_Char)0x20,  /* [5551] */
    (xdc_Char)0x66,  /* [5552] */
    (xdc_Char)0x61,  /* [5553] */
    (xdc_Char)0x69,  /* [5554] */
    (xdc_Char)0x6c,  /* [5555] */
    (xdc_Char)0x65,  /* [5556] */
    (xdc_Char)0x64,  /* [5557] */
    (xdc_Char)0x20,  /* [5558] */
    (xdc_Char)0x74,  /* [5559] */
    (xdc_Char)0x6f,  /* [5560] */
    (xdc_Char)0x20,  /* [5561] */
    (xdc_Char)0x62,  /* [5562] */
    (xdc_Char)0x65,  /* [5563] */
    (xdc_Char)0x20,  /* [5564] */
    (xdc_Char)0x61,  /* [5565] */
    (xdc_Char)0x64,  /* [5566] */
    (xdc_Char)0x64,  /* [5567] */
    (xdc_Char)0x65,  /* [5568] */
    (xdc_Char)0x64,  /* [5569] */
    (xdc_Char)0x20,  /* [5570] */
    (xdc_Char)0x74,  /* [5571] */
    (xdc_Char)0x6f,  /* [5572] */
    (xdc_Char)0x20,  /* [5573] */
    (xdc_Char)0x4e,  /* [5574] */
    (xdc_Char)0x61,  /* [5575] */
    (xdc_Char)0x6d,  /* [5576] */
    (xdc_Char)0x65,  /* [5577] */
    (xdc_Char)0x53,  /* [5578] */
    (xdc_Char)0x65,  /* [5579] */
    (xdc_Char)0x72,  /* [5580] */
    (xdc_Char)0x76,  /* [5581] */
    (xdc_Char)0x65,  /* [5582] */
    (xdc_Char)0x72,  /* [5583] */
    (xdc_Char)0x0,  /* [5584] */
    (xdc_Char)0x45,  /* [5585] */
    (xdc_Char)0x5f,  /* [5586] */
    (xdc_Char)0x69,  /* [5587] */
    (xdc_Char)0x6e,  /* [5588] */
    (xdc_Char)0x74,  /* [5589] */
    (xdc_Char)0x65,  /* [5590] */
    (xdc_Char)0x72,  /* [5591] */
    (xdc_Char)0x6e,  /* [5592] */
    (xdc_Char)0x61,  /* [5593] */
    (xdc_Char)0x6c,  /* [5594] */
    (xdc_Char)0x3a,  /* [5595] */
    (xdc_Char)0x20,  /* [5596] */
    (xdc_Char)0x41,  /* [5597] */
    (xdc_Char)0x6e,  /* [5598] */
    (xdc_Char)0x20,  /* [5599] */
    (xdc_Char)0x69,  /* [5600] */
    (xdc_Char)0x6e,  /* [5601] */
    (xdc_Char)0x74,  /* [5602] */
    (xdc_Char)0x65,  /* [5603] */
    (xdc_Char)0x72,  /* [5604] */
    (xdc_Char)0x6e,  /* [5605] */
    (xdc_Char)0x61,  /* [5606] */
    (xdc_Char)0x6c,  /* [5607] */
    (xdc_Char)0x20,  /* [5608] */
    (xdc_Char)0x65,  /* [5609] */
    (xdc_Char)0x72,  /* [5610] */
    (xdc_Char)0x72,  /* [5611] */
    (xdc_Char)0x6f,  /* [5612] */
    (xdc_Char)0x72,  /* [5613] */
    (xdc_Char)0x20,  /* [5614] */
    (xdc_Char)0x6f,  /* [5615] */
    (xdc_Char)0x63,  /* [5616] */
    (xdc_Char)0x63,  /* [5617] */
    (xdc_Char)0x75,  /* [5618] */
    (xdc_Char)0x72,  /* [5619] */
    (xdc_Char)0x72,  /* [5620] */
    (xdc_Char)0x65,  /* [5621] */
    (xdc_Char)0x64,  /* [5622] */
    (xdc_Char)0x0,  /* [5623] */
    (xdc_Char)0x45,  /* [5624] */
    (xdc_Char)0x5f,  /* [5625] */
    (xdc_Char)0x76,  /* [5626] */
    (xdc_Char)0x65,  /* [5627] */
    (xdc_Char)0x72,  /* [5628] */
    (xdc_Char)0x73,  /* [5629] */
    (xdc_Char)0x69,  /* [5630] */
    (xdc_Char)0x6f,  /* [5631] */
    (xdc_Char)0x6e,  /* [5632] */
    (xdc_Char)0x4d,  /* [5633] */
    (xdc_Char)0x69,  /* [5634] */
    (xdc_Char)0x73,  /* [5635] */
    (xdc_Char)0x6d,  /* [5636] */
    (xdc_Char)0x61,  /* [5637] */
    (xdc_Char)0x74,  /* [5638] */
    (xdc_Char)0x63,  /* [5639] */
    (xdc_Char)0x68,  /* [5640] */
    (xdc_Char)0x3a,  /* [5641] */
    (xdc_Char)0x20,  /* [5642] */
    (xdc_Char)0x49,  /* [5643] */
    (xdc_Char)0x50,  /* [5644] */
    (xdc_Char)0x43,  /* [5645] */
    (xdc_Char)0x20,  /* [5646] */
    (xdc_Char)0x4d,  /* [5647] */
    (xdc_Char)0x6f,  /* [5648] */
    (xdc_Char)0x64,  /* [5649] */
    (xdc_Char)0x75,  /* [5650] */
    (xdc_Char)0x6c,  /* [5651] */
    (xdc_Char)0x65,  /* [5652] */
    (xdc_Char)0x20,  /* [5653] */
    (xdc_Char)0x76,  /* [5654] */
    (xdc_Char)0x65,  /* [5655] */
    (xdc_Char)0x72,  /* [5656] */
    (xdc_Char)0x73,  /* [5657] */
    (xdc_Char)0x69,  /* [5658] */
    (xdc_Char)0x6f,  /* [5659] */
    (xdc_Char)0x6e,  /* [5660] */
    (xdc_Char)0x20,  /* [5661] */
    (xdc_Char)0x6d,  /* [5662] */
    (xdc_Char)0x69,  /* [5663] */
    (xdc_Char)0x73,  /* [5664] */
    (xdc_Char)0x6d,  /* [5665] */
    (xdc_Char)0x61,  /* [5666] */
    (xdc_Char)0x74,  /* [5667] */
    (xdc_Char)0x63,  /* [5668] */
    (xdc_Char)0x68,  /* [5669] */
    (xdc_Char)0x3a,  /* [5670] */
    (xdc_Char)0x20,  /* [5671] */
    (xdc_Char)0x63,  /* [5672] */
    (xdc_Char)0x72,  /* [5673] */
    (xdc_Char)0x65,  /* [5674] */
    (xdc_Char)0x61,  /* [5675] */
    (xdc_Char)0x74,  /* [5676] */
    (xdc_Char)0x6f,  /* [5677] */
    (xdc_Char)0x72,  /* [5678] */
    (xdc_Char)0x3a,  /* [5679] */
    (xdc_Char)0x20,  /* [5680] */
    (xdc_Char)0x25,  /* [5681] */
    (xdc_Char)0x64,  /* [5682] */
    (xdc_Char)0x2c,  /* [5683] */
    (xdc_Char)0x20,  /* [5684] */
    (xdc_Char)0x6f,  /* [5685] */
    (xdc_Char)0x70,  /* [5686] */
    (xdc_Char)0x65,  /* [5687] */
    (xdc_Char)0x6e,  /* [5688] */
    (xdc_Char)0x65,  /* [5689] */
    (xdc_Char)0x72,  /* [5690] */
    (xdc_Char)0x3a,  /* [5691] */
    (xdc_Char)0x20,  /* [5692] */
    (xdc_Char)0x25,  /* [5693] */
    (xdc_Char)0x64,  /* [5694] */
    (xdc_Char)0x0,  /* [5695] */
    (xdc_Char)0x45,  /* [5696] */
    (xdc_Char)0x5f,  /* [5697] */
    (xdc_Char)0x70,  /* [5698] */
    (xdc_Char)0x72,  /* [5699] */
    (xdc_Char)0x69,  /* [5700] */
    (xdc_Char)0x6f,  /* [5701] */
    (xdc_Char)0x72,  /* [5702] */
    (xdc_Char)0x69,  /* [5703] */
    (xdc_Char)0x74,  /* [5704] */
    (xdc_Char)0x79,  /* [5705] */
    (xdc_Char)0x3a,  /* [5706] */
    (xdc_Char)0x20,  /* [5707] */
    (xdc_Char)0x54,  /* [5708] */
    (xdc_Char)0x68,  /* [5709] */
    (xdc_Char)0x72,  /* [5710] */
    (xdc_Char)0x65,  /* [5711] */
    (xdc_Char)0x61,  /* [5712] */
    (xdc_Char)0x64,  /* [5713] */
    (xdc_Char)0x20,  /* [5714] */
    (xdc_Char)0x70,  /* [5715] */
    (xdc_Char)0x72,  /* [5716] */
    (xdc_Char)0x69,  /* [5717] */
    (xdc_Char)0x6f,  /* [5718] */
    (xdc_Char)0x72,  /* [5719] */
    (xdc_Char)0x69,  /* [5720] */
    (xdc_Char)0x74,  /* [5721] */
    (xdc_Char)0x79,  /* [5722] */
    (xdc_Char)0x20,  /* [5723] */
    (xdc_Char)0x69,  /* [5724] */
    (xdc_Char)0x73,  /* [5725] */
    (xdc_Char)0x20,  /* [5726] */
    (xdc_Char)0x69,  /* [5727] */
    (xdc_Char)0x6e,  /* [5728] */
    (xdc_Char)0x76,  /* [5729] */
    (xdc_Char)0x61,  /* [5730] */
    (xdc_Char)0x6c,  /* [5731] */
    (xdc_Char)0x69,  /* [5732] */
    (xdc_Char)0x64,  /* [5733] */
    (xdc_Char)0x20,  /* [5734] */
    (xdc_Char)0x25,  /* [5735] */
    (xdc_Char)0x64,  /* [5736] */
    (xdc_Char)0x0,  /* [5737] */
    (xdc_Char)0x72,  /* [5738] */
    (xdc_Char)0x65,  /* [5739] */
    (xdc_Char)0x71,  /* [5740] */
    (xdc_Char)0x75,  /* [5741] */
    (xdc_Char)0x65,  /* [5742] */
    (xdc_Char)0x73,  /* [5743] */
    (xdc_Char)0x74,  /* [5744] */
    (xdc_Char)0x65,  /* [5745] */
    (xdc_Char)0x64,  /* [5746] */
    (xdc_Char)0x20,  /* [5747] */
    (xdc_Char)0x73,  /* [5748] */
    (xdc_Char)0x69,  /* [5749] */
    (xdc_Char)0x7a,  /* [5750] */
    (xdc_Char)0x65,  /* [5751] */
    (xdc_Char)0x20,  /* [5752] */
    (xdc_Char)0x69,  /* [5753] */
    (xdc_Char)0x73,  /* [5754] */
    (xdc_Char)0x20,  /* [5755] */
    (xdc_Char)0x74,  /* [5756] */
    (xdc_Char)0x6f,  /* [5757] */
    (xdc_Char)0x6f,  /* [5758] */
    (xdc_Char)0x20,  /* [5759] */
    (xdc_Char)0x62,  /* [5760] */
    (xdc_Char)0x69,  /* [5761] */
    (xdc_Char)0x67,  /* [5762] */
    (xdc_Char)0x3a,  /* [5763] */
    (xdc_Char)0x20,  /* [5764] */
    (xdc_Char)0x68,  /* [5765] */
    (xdc_Char)0x61,  /* [5766] */
    (xdc_Char)0x6e,  /* [5767] */
    (xdc_Char)0x64,  /* [5768] */
    (xdc_Char)0x6c,  /* [5769] */
    (xdc_Char)0x65,  /* [5770] */
    (xdc_Char)0x3d,  /* [5771] */
    (xdc_Char)0x30,  /* [5772] */
    (xdc_Char)0x78,  /* [5773] */
    (xdc_Char)0x25,  /* [5774] */
    (xdc_Char)0x78,  /* [5775] */
    (xdc_Char)0x2c,  /* [5776] */
    (xdc_Char)0x20,  /* [5777] */
    (xdc_Char)0x73,  /* [5778] */
    (xdc_Char)0x69,  /* [5779] */
    (xdc_Char)0x7a,  /* [5780] */
    (xdc_Char)0x65,  /* [5781] */
    (xdc_Char)0x3d,  /* [5782] */
    (xdc_Char)0x25,  /* [5783] */
    (xdc_Char)0x75,  /* [5784] */
    (xdc_Char)0x0,  /* [5785] */
    (xdc_Char)0x6f,  /* [5786] */
    (xdc_Char)0x75,  /* [5787] */
    (xdc_Char)0x74,  /* [5788] */
    (xdc_Char)0x20,  /* [5789] */
    (xdc_Char)0x6f,  /* [5790] */
    (xdc_Char)0x66,  /* [5791] */
    (xdc_Char)0x20,  /* [5792] */
    (xdc_Char)0x6d,  /* [5793] */
    (xdc_Char)0x65,  /* [5794] */
    (xdc_Char)0x6d,  /* [5795] */
    (xdc_Char)0x6f,  /* [5796] */
    (xdc_Char)0x72,  /* [5797] */
    (xdc_Char)0x79,  /* [5798] */
    (xdc_Char)0x3a,  /* [5799] */
    (xdc_Char)0x20,  /* [5800] */
    (xdc_Char)0x68,  /* [5801] */
    (xdc_Char)0x61,  /* [5802] */
    (xdc_Char)0x6e,  /* [5803] */
    (xdc_Char)0x64,  /* [5804] */
    (xdc_Char)0x6c,  /* [5805] */
    (xdc_Char)0x65,  /* [5806] */
    (xdc_Char)0x3d,  /* [5807] */
    (xdc_Char)0x30,  /* [5808] */
    (xdc_Char)0x78,  /* [5809] */
    (xdc_Char)0x25,  /* [5810] */
    (xdc_Char)0x78,  /* [5811] */
    (xdc_Char)0x2c,  /* [5812] */
    (xdc_Char)0x20,  /* [5813] */
    (xdc_Char)0x73,  /* [5814] */
    (xdc_Char)0x69,  /* [5815] */
    (xdc_Char)0x7a,  /* [5816] */
    (xdc_Char)0x65,  /* [5817] */
    (xdc_Char)0x3d,  /* [5818] */
    (xdc_Char)0x25,  /* [5819] */
    (xdc_Char)0x75,  /* [5820] */
    (xdc_Char)0x0,  /* [5821] */
    (xdc_Char)0x3c,  /* [5822] */
    (xdc_Char)0x2d,  /* [5823] */
    (xdc_Char)0x2d,  /* [5824] */
    (xdc_Char)0x20,  /* [5825] */
    (xdc_Char)0x63,  /* [5826] */
    (xdc_Char)0x6f,  /* [5827] */
    (xdc_Char)0x6e,  /* [5828] */
    (xdc_Char)0x73,  /* [5829] */
    (xdc_Char)0x74,  /* [5830] */
    (xdc_Char)0x72,  /* [5831] */
    (xdc_Char)0x75,  /* [5832] */
    (xdc_Char)0x63,  /* [5833] */
    (xdc_Char)0x74,  /* [5834] */
    (xdc_Char)0x3a,  /* [5835] */
    (xdc_Char)0x20,  /* [5836] */
    (xdc_Char)0x25,  /* [5837] */
    (xdc_Char)0x70,  /* [5838] */
    (xdc_Char)0x28,  /* [5839] */
    (xdc_Char)0x27,  /* [5840] */
    (xdc_Char)0x25,  /* [5841] */
    (xdc_Char)0x73,  /* [5842] */
    (xdc_Char)0x27,  /* [5843] */
    (xdc_Char)0x29,  /* [5844] */
    (xdc_Char)0x0,  /* [5845] */
    (xdc_Char)0x3c,  /* [5846] */
    (xdc_Char)0x2d,  /* [5847] */
    (xdc_Char)0x2d,  /* [5848] */
    (xdc_Char)0x20,  /* [5849] */
    (xdc_Char)0x63,  /* [5850] */
    (xdc_Char)0x72,  /* [5851] */
    (xdc_Char)0x65,  /* [5852] */
    (xdc_Char)0x61,  /* [5853] */
    (xdc_Char)0x74,  /* [5854] */
    (xdc_Char)0x65,  /* [5855] */
    (xdc_Char)0x3a,  /* [5856] */
    (xdc_Char)0x20,  /* [5857] */
    (xdc_Char)0x25,  /* [5858] */
    (xdc_Char)0x70,  /* [5859] */
    (xdc_Char)0x28,  /* [5860] */
    (xdc_Char)0x27,  /* [5861] */
    (xdc_Char)0x25,  /* [5862] */
    (xdc_Char)0x73,  /* [5863] */
    (xdc_Char)0x27,  /* [5864] */
    (xdc_Char)0x29,  /* [5865] */
    (xdc_Char)0x0,  /* [5866] */
    (xdc_Char)0x2d,  /* [5867] */
    (xdc_Char)0x2d,  /* [5868] */
    (xdc_Char)0x3e,  /* [5869] */
    (xdc_Char)0x20,  /* [5870] */
    (xdc_Char)0x64,  /* [5871] */
    (xdc_Char)0x65,  /* [5872] */
    (xdc_Char)0x73,  /* [5873] */
    (xdc_Char)0x74,  /* [5874] */
    (xdc_Char)0x72,  /* [5875] */
    (xdc_Char)0x75,  /* [5876] */
    (xdc_Char)0x63,  /* [5877] */
    (xdc_Char)0x74,  /* [5878] */
    (xdc_Char)0x3a,  /* [5879] */
    (xdc_Char)0x20,  /* [5880] */
    (xdc_Char)0x28,  /* [5881] */
    (xdc_Char)0x25,  /* [5882] */
    (xdc_Char)0x70,  /* [5883] */
    (xdc_Char)0x29,  /* [5884] */
    (xdc_Char)0x0,  /* [5885] */
    (xdc_Char)0x2d,  /* [5886] */
    (xdc_Char)0x2d,  /* [5887] */
    (xdc_Char)0x3e,  /* [5888] */
    (xdc_Char)0x20,  /* [5889] */
    (xdc_Char)0x64,  /* [5890] */
    (xdc_Char)0x65,  /* [5891] */
    (xdc_Char)0x6c,  /* [5892] */
    (xdc_Char)0x65,  /* [5893] */
    (xdc_Char)0x74,  /* [5894] */
    (xdc_Char)0x65,  /* [5895] */
    (xdc_Char)0x3a,  /* [5896] */
    (xdc_Char)0x20,  /* [5897] */
    (xdc_Char)0x28,  /* [5898] */
    (xdc_Char)0x25,  /* [5899] */
    (xdc_Char)0x70,  /* [5900] */
    (xdc_Char)0x29,  /* [5901] */
    (xdc_Char)0x0,  /* [5902] */
    (xdc_Char)0x45,  /* [5903] */
    (xdc_Char)0x52,  /* [5904] */
    (xdc_Char)0x52,  /* [5905] */
    (xdc_Char)0x4f,  /* [5906] */
    (xdc_Char)0x52,  /* [5907] */
    (xdc_Char)0x3a,  /* [5908] */
    (xdc_Char)0x20,  /* [5909] */
    (xdc_Char)0x25,  /* [5910] */
    (xdc_Char)0x24,  /* [5911] */
    (xdc_Char)0x46,  /* [5912] */
    (xdc_Char)0x25,  /* [5913] */
    (xdc_Char)0x24,  /* [5914] */
    (xdc_Char)0x53,  /* [5915] */
    (xdc_Char)0x0,  /* [5916] */
    (xdc_Char)0x57,  /* [5917] */
    (xdc_Char)0x41,  /* [5918] */
    (xdc_Char)0x52,  /* [5919] */
    (xdc_Char)0x4e,  /* [5920] */
    (xdc_Char)0x49,  /* [5921] */
    (xdc_Char)0x4e,  /* [5922] */
    (xdc_Char)0x47,  /* [5923] */
    (xdc_Char)0x3a,  /* [5924] */
    (xdc_Char)0x20,  /* [5925] */
    (xdc_Char)0x25,  /* [5926] */
    (xdc_Char)0x24,  /* [5927] */
    (xdc_Char)0x46,  /* [5928] */
    (xdc_Char)0x25,  /* [5929] */
    (xdc_Char)0x24,  /* [5930] */
    (xdc_Char)0x53,  /* [5931] */
    (xdc_Char)0x0,  /* [5932] */
    (xdc_Char)0x25,  /* [5933] */
    (xdc_Char)0x24,  /* [5934] */
    (xdc_Char)0x46,  /* [5935] */
    (xdc_Char)0x25,  /* [5936] */
    (xdc_Char)0x24,  /* [5937] */
    (xdc_Char)0x53,  /* [5938] */
    (xdc_Char)0x0,  /* [5939] */
    (xdc_Char)0x53,  /* [5940] */
    (xdc_Char)0x74,  /* [5941] */
    (xdc_Char)0x61,  /* [5942] */
    (xdc_Char)0x72,  /* [5943] */
    (xdc_Char)0x74,  /* [5944] */
    (xdc_Char)0x3a,  /* [5945] */
    (xdc_Char)0x20,  /* [5946] */
    (xdc_Char)0x25,  /* [5947] */
    (xdc_Char)0x24,  /* [5948] */
    (xdc_Char)0x53,  /* [5949] */
    (xdc_Char)0x0,  /* [5950] */
    (xdc_Char)0x53,  /* [5951] */
    (xdc_Char)0x74,  /* [5952] */
    (xdc_Char)0x6f,  /* [5953] */
    (xdc_Char)0x70,  /* [5954] */
    (xdc_Char)0x3a,  /* [5955] */
    (xdc_Char)0x20,  /* [5956] */
    (xdc_Char)0x25,  /* [5957] */
    (xdc_Char)0x24,  /* [5958] */
    (xdc_Char)0x53,  /* [5959] */
    (xdc_Char)0x0,  /* [5960] */
    (xdc_Char)0x53,  /* [5961] */
    (xdc_Char)0x74,  /* [5962] */
    (xdc_Char)0x61,  /* [5963] */
    (xdc_Char)0x72,  /* [5964] */
    (xdc_Char)0x74,  /* [5965] */
    (xdc_Char)0x49,  /* [5966] */
    (xdc_Char)0x6e,  /* [5967] */
    (xdc_Char)0x73,  /* [5968] */
    (xdc_Char)0x74,  /* [5969] */
    (xdc_Char)0x61,  /* [5970] */
    (xdc_Char)0x6e,  /* [5971] */
    (xdc_Char)0x63,  /* [5972] */
    (xdc_Char)0x65,  /* [5973] */
    (xdc_Char)0x3a,  /* [5974] */
    (xdc_Char)0x20,  /* [5975] */
    (xdc_Char)0x25,  /* [5976] */
    (xdc_Char)0x24,  /* [5977] */
    (xdc_Char)0x53,  /* [5978] */
    (xdc_Char)0x0,  /* [5979] */
    (xdc_Char)0x53,  /* [5980] */
    (xdc_Char)0x74,  /* [5981] */
    (xdc_Char)0x6f,  /* [5982] */
    (xdc_Char)0x70,  /* [5983] */
    (xdc_Char)0x49,  /* [5984] */
    (xdc_Char)0x6e,  /* [5985] */
    (xdc_Char)0x73,  /* [5986] */
    (xdc_Char)0x74,  /* [5987] */
    (xdc_Char)0x61,  /* [5988] */
    (xdc_Char)0x6e,  /* [5989] */
    (xdc_Char)0x63,  /* [5990] */
    (xdc_Char)0x65,  /* [5991] */
    (xdc_Char)0x3a,  /* [5992] */
    (xdc_Char)0x20,  /* [5993] */
    (xdc_Char)0x25,  /* [5994] */
    (xdc_Char)0x24,  /* [5995] */
    (xdc_Char)0x53,  /* [5996] */
    (xdc_Char)0x0,  /* [5997] */
    (xdc_Char)0x4c,  /* [5998] */
    (xdc_Char)0x57,  /* [5999] */
    (xdc_Char)0x5f,  /* [6000] */
    (xdc_Char)0x64,  /* [6001] */
    (xdc_Char)0x65,  /* [6002] */
    (xdc_Char)0x6c,  /* [6003] */
    (xdc_Char)0x61,  /* [6004] */
    (xdc_Char)0x79,  /* [6005] */
    (xdc_Char)0x65,  /* [6006] */
    (xdc_Char)0x64,  /* [6007] */
    (xdc_Char)0x3a,  /* [6008] */
    (xdc_Char)0x20,  /* [6009] */
    (xdc_Char)0x64,  /* [6010] */
    (xdc_Char)0x65,  /* [6011] */
    (xdc_Char)0x6c,  /* [6012] */
    (xdc_Char)0x61,  /* [6013] */
    (xdc_Char)0x79,  /* [6014] */
    (xdc_Char)0x3a,  /* [6015] */
    (xdc_Char)0x20,  /* [6016] */
    (xdc_Char)0x25,  /* [6017] */
    (xdc_Char)0x64,  /* [6018] */
    (xdc_Char)0x0,  /* [6019] */
    (xdc_Char)0x4c,  /* [6020] */
    (xdc_Char)0x4d,  /* [6021] */
    (xdc_Char)0x5f,  /* [6022] */
    (xdc_Char)0x74,  /* [6023] */
    (xdc_Char)0x69,  /* [6024] */
    (xdc_Char)0x63,  /* [6025] */
    (xdc_Char)0x6b,  /* [6026] */
    (xdc_Char)0x3a,  /* [6027] */
    (xdc_Char)0x20,  /* [6028] */
    (xdc_Char)0x74,  /* [6029] */
    (xdc_Char)0x69,  /* [6030] */
    (xdc_Char)0x63,  /* [6031] */
    (xdc_Char)0x6b,  /* [6032] */
    (xdc_Char)0x3a,  /* [6033] */
    (xdc_Char)0x20,  /* [6034] */
    (xdc_Char)0x25,  /* [6035] */
    (xdc_Char)0x64,  /* [6036] */
    (xdc_Char)0x0,  /* [6037] */
    (xdc_Char)0x4c,  /* [6038] */
    (xdc_Char)0x4d,  /* [6039] */
    (xdc_Char)0x5f,  /* [6040] */
    (xdc_Char)0x62,  /* [6041] */
    (xdc_Char)0x65,  /* [6042] */
    (xdc_Char)0x67,  /* [6043] */
    (xdc_Char)0x69,  /* [6044] */
    (xdc_Char)0x6e,  /* [6045] */
    (xdc_Char)0x3a,  /* [6046] */
    (xdc_Char)0x20,  /* [6047] */
    (xdc_Char)0x63,  /* [6048] */
    (xdc_Char)0x6c,  /* [6049] */
    (xdc_Char)0x6b,  /* [6050] */
    (xdc_Char)0x3a,  /* [6051] */
    (xdc_Char)0x20,  /* [6052] */
    (xdc_Char)0x30,  /* [6053] */
    (xdc_Char)0x78,  /* [6054] */
    (xdc_Char)0x25,  /* [6055] */
    (xdc_Char)0x78,  /* [6056] */
    (xdc_Char)0x2c,  /* [6057] */
    (xdc_Char)0x20,  /* [6058] */
    (xdc_Char)0x66,  /* [6059] */
    (xdc_Char)0x75,  /* [6060] */
    (xdc_Char)0x6e,  /* [6061] */
    (xdc_Char)0x63,  /* [6062] */
    (xdc_Char)0x3a,  /* [6063] */
    (xdc_Char)0x20,  /* [6064] */
    (xdc_Char)0x30,  /* [6065] */
    (xdc_Char)0x78,  /* [6066] */
    (xdc_Char)0x25,  /* [6067] */
    (xdc_Char)0x78,  /* [6068] */
    (xdc_Char)0x0,  /* [6069] */
    (xdc_Char)0x4c,  /* [6070] */
    (xdc_Char)0x4d,  /* [6071] */
    (xdc_Char)0x5f,  /* [6072] */
    (xdc_Char)0x70,  /* [6073] */
    (xdc_Char)0x6f,  /* [6074] */
    (xdc_Char)0x73,  /* [6075] */
    (xdc_Char)0x74,  /* [6076] */
    (xdc_Char)0x3a,  /* [6077] */
    (xdc_Char)0x20,  /* [6078] */
    (xdc_Char)0x73,  /* [6079] */
    (xdc_Char)0x65,  /* [6080] */
    (xdc_Char)0x6d,  /* [6081] */
    (xdc_Char)0x3a,  /* [6082] */
    (xdc_Char)0x20,  /* [6083] */
    (xdc_Char)0x30,  /* [6084] */
    (xdc_Char)0x78,  /* [6085] */
    (xdc_Char)0x25,  /* [6086] */
    (xdc_Char)0x78,  /* [6087] */
    (xdc_Char)0x2c,  /* [6088] */
    (xdc_Char)0x20,  /* [6089] */
    (xdc_Char)0x63,  /* [6090] */
    (xdc_Char)0x6f,  /* [6091] */
    (xdc_Char)0x75,  /* [6092] */
    (xdc_Char)0x6e,  /* [6093] */
    (xdc_Char)0x74,  /* [6094] */
    (xdc_Char)0x3a,  /* [6095] */
    (xdc_Char)0x20,  /* [6096] */
    (xdc_Char)0x25,  /* [6097] */
    (xdc_Char)0x64,  /* [6098] */
    (xdc_Char)0x0,  /* [6099] */
    (xdc_Char)0x4c,  /* [6100] */
    (xdc_Char)0x4d,  /* [6101] */
    (xdc_Char)0x5f,  /* [6102] */
    (xdc_Char)0x70,  /* [6103] */
    (xdc_Char)0x65,  /* [6104] */
    (xdc_Char)0x6e,  /* [6105] */
    (xdc_Char)0x64,  /* [6106] */
    (xdc_Char)0x3a,  /* [6107] */
    (xdc_Char)0x20,  /* [6108] */
    (xdc_Char)0x73,  /* [6109] */
    (xdc_Char)0x65,  /* [6110] */
    (xdc_Char)0x6d,  /* [6111] */
    (xdc_Char)0x3a,  /* [6112] */
    (xdc_Char)0x20,  /* [6113] */
    (xdc_Char)0x30,  /* [6114] */
    (xdc_Char)0x78,  /* [6115] */
    (xdc_Char)0x25,  /* [6116] */
    (xdc_Char)0x78,  /* [6117] */
    (xdc_Char)0x2c,  /* [6118] */
    (xdc_Char)0x20,  /* [6119] */
    (xdc_Char)0x63,  /* [6120] */
    (xdc_Char)0x6f,  /* [6121] */
    (xdc_Char)0x75,  /* [6122] */
    (xdc_Char)0x6e,  /* [6123] */
    (xdc_Char)0x74,  /* [6124] */
    (xdc_Char)0x3a,  /* [6125] */
    (xdc_Char)0x20,  /* [6126] */
    (xdc_Char)0x25,  /* [6127] */
    (xdc_Char)0x64,  /* [6128] */
    (xdc_Char)0x2c,  /* [6129] */
    (xdc_Char)0x20,  /* [6130] */
    (xdc_Char)0x74,  /* [6131] */
    (xdc_Char)0x69,  /* [6132] */
    (xdc_Char)0x6d,  /* [6133] */
    (xdc_Char)0x65,  /* [6134] */
    (xdc_Char)0x6f,  /* [6135] */
    (xdc_Char)0x75,  /* [6136] */
    (xdc_Char)0x74,  /* [6137] */
    (xdc_Char)0x3a,  /* [6138] */
    (xdc_Char)0x20,  /* [6139] */
    (xdc_Char)0x25,  /* [6140] */
    (xdc_Char)0x64,  /* [6141] */
    (xdc_Char)0x0,  /* [6142] */
    (xdc_Char)0x4c,  /* [6143] */
    (xdc_Char)0x4d,  /* [6144] */
    (xdc_Char)0x5f,  /* [6145] */
    (xdc_Char)0x62,  /* [6146] */
    (xdc_Char)0x65,  /* [6147] */
    (xdc_Char)0x67,  /* [6148] */
    (xdc_Char)0x69,  /* [6149] */
    (xdc_Char)0x6e,  /* [6150] */
    (xdc_Char)0x3a,  /* [6151] */
    (xdc_Char)0x20,  /* [6152] */
    (xdc_Char)0x73,  /* [6153] */
    (xdc_Char)0x77,  /* [6154] */
    (xdc_Char)0x69,  /* [6155] */
    (xdc_Char)0x3a,  /* [6156] */
    (xdc_Char)0x20,  /* [6157] */
    (xdc_Char)0x30,  /* [6158] */
    (xdc_Char)0x78,  /* [6159] */
    (xdc_Char)0x25,  /* [6160] */
    (xdc_Char)0x78,  /* [6161] */
    (xdc_Char)0x2c,  /* [6162] */
    (xdc_Char)0x20,  /* [6163] */
    (xdc_Char)0x66,  /* [6164] */
    (xdc_Char)0x75,  /* [6165] */
    (xdc_Char)0x6e,  /* [6166] */
    (xdc_Char)0x63,  /* [6167] */
    (xdc_Char)0x3a,  /* [6168] */
    (xdc_Char)0x20,  /* [6169] */
    (xdc_Char)0x30,  /* [6170] */
    (xdc_Char)0x78,  /* [6171] */
    (xdc_Char)0x25,  /* [6172] */
    (xdc_Char)0x78,  /* [6173] */
    (xdc_Char)0x2c,  /* [6174] */
    (xdc_Char)0x20,  /* [6175] */
    (xdc_Char)0x70,  /* [6176] */
    (xdc_Char)0x72,  /* [6177] */
    (xdc_Char)0x65,  /* [6178] */
    (xdc_Char)0x54,  /* [6179] */
    (xdc_Char)0x68,  /* [6180] */
    (xdc_Char)0x72,  /* [6181] */
    (xdc_Char)0x65,  /* [6182] */
    (xdc_Char)0x61,  /* [6183] */
    (xdc_Char)0x64,  /* [6184] */
    (xdc_Char)0x3a,  /* [6185] */
    (xdc_Char)0x20,  /* [6186] */
    (xdc_Char)0x25,  /* [6187] */
    (xdc_Char)0x64,  /* [6188] */
    (xdc_Char)0x0,  /* [6189] */
    (xdc_Char)0x4c,  /* [6190] */
    (xdc_Char)0x44,  /* [6191] */
    (xdc_Char)0x5f,  /* [6192] */
    (xdc_Char)0x65,  /* [6193] */
    (xdc_Char)0x6e,  /* [6194] */
    (xdc_Char)0x64,  /* [6195] */
    (xdc_Char)0x3a,  /* [6196] */
    (xdc_Char)0x20,  /* [6197] */
    (xdc_Char)0x73,  /* [6198] */
    (xdc_Char)0x77,  /* [6199] */
    (xdc_Char)0x69,  /* [6200] */
    (xdc_Char)0x3a,  /* [6201] */
    (xdc_Char)0x20,  /* [6202] */
    (xdc_Char)0x30,  /* [6203] */
    (xdc_Char)0x78,  /* [6204] */
    (xdc_Char)0x25,  /* [6205] */
    (xdc_Char)0x78,  /* [6206] */
    (xdc_Char)0x0,  /* [6207] */
    (xdc_Char)0x4c,  /* [6208] */
    (xdc_Char)0x4d,  /* [6209] */
    (xdc_Char)0x5f,  /* [6210] */
    (xdc_Char)0x70,  /* [6211] */
    (xdc_Char)0x6f,  /* [6212] */
    (xdc_Char)0x73,  /* [6213] */
    (xdc_Char)0x74,  /* [6214] */
    (xdc_Char)0x3a,  /* [6215] */
    (xdc_Char)0x20,  /* [6216] */
    (xdc_Char)0x73,  /* [6217] */
    (xdc_Char)0x77,  /* [6218] */
    (xdc_Char)0x69,  /* [6219] */
    (xdc_Char)0x3a,  /* [6220] */
    (xdc_Char)0x20,  /* [6221] */
    (xdc_Char)0x30,  /* [6222] */
    (xdc_Char)0x78,  /* [6223] */
    (xdc_Char)0x25,  /* [6224] */
    (xdc_Char)0x78,  /* [6225] */
    (xdc_Char)0x2c,  /* [6226] */
    (xdc_Char)0x20,  /* [6227] */
    (xdc_Char)0x66,  /* [6228] */
    (xdc_Char)0x75,  /* [6229] */
    (xdc_Char)0x6e,  /* [6230] */
    (xdc_Char)0x63,  /* [6231] */
    (xdc_Char)0x3a,  /* [6232] */
    (xdc_Char)0x20,  /* [6233] */
    (xdc_Char)0x30,  /* [6234] */
    (xdc_Char)0x78,  /* [6235] */
    (xdc_Char)0x25,  /* [6236] */
    (xdc_Char)0x78,  /* [6237] */
    (xdc_Char)0x2c,  /* [6238] */
    (xdc_Char)0x20,  /* [6239] */
    (xdc_Char)0x70,  /* [6240] */
    (xdc_Char)0x72,  /* [6241] */
    (xdc_Char)0x69,  /* [6242] */
    (xdc_Char)0x3a,  /* [6243] */
    (xdc_Char)0x20,  /* [6244] */
    (xdc_Char)0x25,  /* [6245] */
    (xdc_Char)0x64,  /* [6246] */
    (xdc_Char)0x0,  /* [6247] */
    (xdc_Char)0x4c,  /* [6248] */
    (xdc_Char)0x4d,  /* [6249] */
    (xdc_Char)0x5f,  /* [6250] */
    (xdc_Char)0x73,  /* [6251] */
    (xdc_Char)0x77,  /* [6252] */
    (xdc_Char)0x69,  /* [6253] */
    (xdc_Char)0x74,  /* [6254] */
    (xdc_Char)0x63,  /* [6255] */
    (xdc_Char)0x68,  /* [6256] */
    (xdc_Char)0x3a,  /* [6257] */
    (xdc_Char)0x20,  /* [6258] */
    (xdc_Char)0x6f,  /* [6259] */
    (xdc_Char)0x6c,  /* [6260] */
    (xdc_Char)0x64,  /* [6261] */
    (xdc_Char)0x74,  /* [6262] */
    (xdc_Char)0x73,  /* [6263] */
    (xdc_Char)0x6b,  /* [6264] */
    (xdc_Char)0x3a,  /* [6265] */
    (xdc_Char)0x20,  /* [6266] */
    (xdc_Char)0x30,  /* [6267] */
    (xdc_Char)0x78,  /* [6268] */
    (xdc_Char)0x25,  /* [6269] */
    (xdc_Char)0x78,  /* [6270] */
    (xdc_Char)0x2c,  /* [6271] */
    (xdc_Char)0x20,  /* [6272] */
    (xdc_Char)0x6f,  /* [6273] */
    (xdc_Char)0x6c,  /* [6274] */
    (xdc_Char)0x64,  /* [6275] */
    (xdc_Char)0x66,  /* [6276] */
    (xdc_Char)0x75,  /* [6277] */
    (xdc_Char)0x6e,  /* [6278] */
    (xdc_Char)0x63,  /* [6279] */
    (xdc_Char)0x3a,  /* [6280] */
    (xdc_Char)0x20,  /* [6281] */
    (xdc_Char)0x30,  /* [6282] */
    (xdc_Char)0x78,  /* [6283] */
    (xdc_Char)0x25,  /* [6284] */
    (xdc_Char)0x78,  /* [6285] */
    (xdc_Char)0x2c,  /* [6286] */
    (xdc_Char)0x20,  /* [6287] */
    (xdc_Char)0x6e,  /* [6288] */
    (xdc_Char)0x65,  /* [6289] */
    (xdc_Char)0x77,  /* [6290] */
    (xdc_Char)0x74,  /* [6291] */
    (xdc_Char)0x73,  /* [6292] */
    (xdc_Char)0x6b,  /* [6293] */
    (xdc_Char)0x3a,  /* [6294] */
    (xdc_Char)0x20,  /* [6295] */
    (xdc_Char)0x30,  /* [6296] */
    (xdc_Char)0x78,  /* [6297] */
    (xdc_Char)0x25,  /* [6298] */
    (xdc_Char)0x78,  /* [6299] */
    (xdc_Char)0x2c,  /* [6300] */
    (xdc_Char)0x20,  /* [6301] */
    (xdc_Char)0x6e,  /* [6302] */
    (xdc_Char)0x65,  /* [6303] */
    (xdc_Char)0x77,  /* [6304] */
    (xdc_Char)0x66,  /* [6305] */
    (xdc_Char)0x75,  /* [6306] */
    (xdc_Char)0x6e,  /* [6307] */
    (xdc_Char)0x63,  /* [6308] */
    (xdc_Char)0x3a,  /* [6309] */
    (xdc_Char)0x20,  /* [6310] */
    (xdc_Char)0x30,  /* [6311] */
    (xdc_Char)0x78,  /* [6312] */
    (xdc_Char)0x25,  /* [6313] */
    (xdc_Char)0x78,  /* [6314] */
    (xdc_Char)0x0,  /* [6315] */
    (xdc_Char)0x4c,  /* [6316] */
    (xdc_Char)0x4d,  /* [6317] */
    (xdc_Char)0x5f,  /* [6318] */
    (xdc_Char)0x73,  /* [6319] */
    (xdc_Char)0x6c,  /* [6320] */
    (xdc_Char)0x65,  /* [6321] */
    (xdc_Char)0x65,  /* [6322] */
    (xdc_Char)0x70,  /* [6323] */
    (xdc_Char)0x3a,  /* [6324] */
    (xdc_Char)0x20,  /* [6325] */
    (xdc_Char)0x74,  /* [6326] */
    (xdc_Char)0x73,  /* [6327] */
    (xdc_Char)0x6b,  /* [6328] */
    (xdc_Char)0x3a,  /* [6329] */
    (xdc_Char)0x20,  /* [6330] */
    (xdc_Char)0x30,  /* [6331] */
    (xdc_Char)0x78,  /* [6332] */
    (xdc_Char)0x25,  /* [6333] */
    (xdc_Char)0x78,  /* [6334] */
    (xdc_Char)0x2c,  /* [6335] */
    (xdc_Char)0x20,  /* [6336] */
    (xdc_Char)0x66,  /* [6337] */
    (xdc_Char)0x75,  /* [6338] */
    (xdc_Char)0x6e,  /* [6339] */
    (xdc_Char)0x63,  /* [6340] */
    (xdc_Char)0x3a,  /* [6341] */
    (xdc_Char)0x20,  /* [6342] */
    (xdc_Char)0x30,  /* [6343] */
    (xdc_Char)0x78,  /* [6344] */
    (xdc_Char)0x25,  /* [6345] */
    (xdc_Char)0x78,  /* [6346] */
    (xdc_Char)0x2c,  /* [6347] */
    (xdc_Char)0x20,  /* [6348] */
    (xdc_Char)0x74,  /* [6349] */
    (xdc_Char)0x69,  /* [6350] */
    (xdc_Char)0x6d,  /* [6351] */
    (xdc_Char)0x65,  /* [6352] */
    (xdc_Char)0x6f,  /* [6353] */
    (xdc_Char)0x75,  /* [6354] */
    (xdc_Char)0x74,  /* [6355] */
    (xdc_Char)0x3a,  /* [6356] */
    (xdc_Char)0x20,  /* [6357] */
    (xdc_Char)0x25,  /* [6358] */
    (xdc_Char)0x64,  /* [6359] */
    (xdc_Char)0x0,  /* [6360] */
    (xdc_Char)0x4c,  /* [6361] */
    (xdc_Char)0x44,  /* [6362] */
    (xdc_Char)0x5f,  /* [6363] */
    (xdc_Char)0x72,  /* [6364] */
    (xdc_Char)0x65,  /* [6365] */
    (xdc_Char)0x61,  /* [6366] */
    (xdc_Char)0x64,  /* [6367] */
    (xdc_Char)0x79,  /* [6368] */
    (xdc_Char)0x3a,  /* [6369] */
    (xdc_Char)0x20,  /* [6370] */
    (xdc_Char)0x74,  /* [6371] */
    (xdc_Char)0x73,  /* [6372] */
    (xdc_Char)0x6b,  /* [6373] */
    (xdc_Char)0x3a,  /* [6374] */
    (xdc_Char)0x20,  /* [6375] */
    (xdc_Char)0x30,  /* [6376] */
    (xdc_Char)0x78,  /* [6377] */
    (xdc_Char)0x25,  /* [6378] */
    (xdc_Char)0x78,  /* [6379] */
    (xdc_Char)0x2c,  /* [6380] */
    (xdc_Char)0x20,  /* [6381] */
    (xdc_Char)0x66,  /* [6382] */
    (xdc_Char)0x75,  /* [6383] */
    (xdc_Char)0x6e,  /* [6384] */
    (xdc_Char)0x63,  /* [6385] */
    (xdc_Char)0x3a,  /* [6386] */
    (xdc_Char)0x20,  /* [6387] */
    (xdc_Char)0x30,  /* [6388] */
    (xdc_Char)0x78,  /* [6389] */
    (xdc_Char)0x25,  /* [6390] */
    (xdc_Char)0x78,  /* [6391] */
    (xdc_Char)0x2c,  /* [6392] */
    (xdc_Char)0x20,  /* [6393] */
    (xdc_Char)0x70,  /* [6394] */
    (xdc_Char)0x72,  /* [6395] */
    (xdc_Char)0x69,  /* [6396] */
    (xdc_Char)0x3a,  /* [6397] */
    (xdc_Char)0x20,  /* [6398] */
    (xdc_Char)0x25,  /* [6399] */
    (xdc_Char)0x64,  /* [6400] */
    (xdc_Char)0x0,  /* [6401] */
    (xdc_Char)0x4c,  /* [6402] */
    (xdc_Char)0x44,  /* [6403] */
    (xdc_Char)0x5f,  /* [6404] */
    (xdc_Char)0x62,  /* [6405] */
    (xdc_Char)0x6c,  /* [6406] */
    (xdc_Char)0x6f,  /* [6407] */
    (xdc_Char)0x63,  /* [6408] */
    (xdc_Char)0x6b,  /* [6409] */
    (xdc_Char)0x3a,  /* [6410] */
    (xdc_Char)0x20,  /* [6411] */
    (xdc_Char)0x74,  /* [6412] */
    (xdc_Char)0x73,  /* [6413] */
    (xdc_Char)0x6b,  /* [6414] */
    (xdc_Char)0x3a,  /* [6415] */
    (xdc_Char)0x20,  /* [6416] */
    (xdc_Char)0x30,  /* [6417] */
    (xdc_Char)0x78,  /* [6418] */
    (xdc_Char)0x25,  /* [6419] */
    (xdc_Char)0x78,  /* [6420] */
    (xdc_Char)0x2c,  /* [6421] */
    (xdc_Char)0x20,  /* [6422] */
    (xdc_Char)0x66,  /* [6423] */
    (xdc_Char)0x75,  /* [6424] */
    (xdc_Char)0x6e,  /* [6425] */
    (xdc_Char)0x63,  /* [6426] */
    (xdc_Char)0x3a,  /* [6427] */
    (xdc_Char)0x20,  /* [6428] */
    (xdc_Char)0x30,  /* [6429] */
    (xdc_Char)0x78,  /* [6430] */
    (xdc_Char)0x25,  /* [6431] */
    (xdc_Char)0x78,  /* [6432] */
    (xdc_Char)0x0,  /* [6433] */
    (xdc_Char)0x4c,  /* [6434] */
    (xdc_Char)0x4d,  /* [6435] */
    (xdc_Char)0x5f,  /* [6436] */
    (xdc_Char)0x79,  /* [6437] */
    (xdc_Char)0x69,  /* [6438] */
    (xdc_Char)0x65,  /* [6439] */
    (xdc_Char)0x6c,  /* [6440] */
    (xdc_Char)0x64,  /* [6441] */
    (xdc_Char)0x3a,  /* [6442] */
    (xdc_Char)0x20,  /* [6443] */
    (xdc_Char)0x74,  /* [6444] */
    (xdc_Char)0x73,  /* [6445] */
    (xdc_Char)0x6b,  /* [6446] */
    (xdc_Char)0x3a,  /* [6447] */
    (xdc_Char)0x20,  /* [6448] */
    (xdc_Char)0x30,  /* [6449] */
    (xdc_Char)0x78,  /* [6450] */
    (xdc_Char)0x25,  /* [6451] */
    (xdc_Char)0x78,  /* [6452] */
    (xdc_Char)0x2c,  /* [6453] */
    (xdc_Char)0x20,  /* [6454] */
    (xdc_Char)0x66,  /* [6455] */
    (xdc_Char)0x75,  /* [6456] */
    (xdc_Char)0x6e,  /* [6457] */
    (xdc_Char)0x63,  /* [6458] */
    (xdc_Char)0x3a,  /* [6459] */
    (xdc_Char)0x20,  /* [6460] */
    (xdc_Char)0x30,  /* [6461] */
    (xdc_Char)0x78,  /* [6462] */
    (xdc_Char)0x25,  /* [6463] */
    (xdc_Char)0x78,  /* [6464] */
    (xdc_Char)0x2c,  /* [6465] */
    (xdc_Char)0x20,  /* [6466] */
    (xdc_Char)0x63,  /* [6467] */
    (xdc_Char)0x75,  /* [6468] */
    (xdc_Char)0x72,  /* [6469] */
    (xdc_Char)0x72,  /* [6470] */
    (xdc_Char)0x54,  /* [6471] */
    (xdc_Char)0x68,  /* [6472] */
    (xdc_Char)0x72,  /* [6473] */
    (xdc_Char)0x65,  /* [6474] */
    (xdc_Char)0x61,  /* [6475] */
    (xdc_Char)0x64,  /* [6476] */
    (xdc_Char)0x3a,  /* [6477] */
    (xdc_Char)0x20,  /* [6478] */
    (xdc_Char)0x25,  /* [6479] */
    (xdc_Char)0x64,  /* [6480] */
    (xdc_Char)0x0,  /* [6481] */
    (xdc_Char)0x4c,  /* [6482] */
    (xdc_Char)0x4d,  /* [6483] */
    (xdc_Char)0x5f,  /* [6484] */
    (xdc_Char)0x73,  /* [6485] */
    (xdc_Char)0x65,  /* [6486] */
    (xdc_Char)0x74,  /* [6487] */
    (xdc_Char)0x50,  /* [6488] */
    (xdc_Char)0x72,  /* [6489] */
    (xdc_Char)0x69,  /* [6490] */
    (xdc_Char)0x3a,  /* [6491] */
    (xdc_Char)0x20,  /* [6492] */
    (xdc_Char)0x74,  /* [6493] */
    (xdc_Char)0x73,  /* [6494] */
    (xdc_Char)0x6b,  /* [6495] */
    (xdc_Char)0x3a,  /* [6496] */
    (xdc_Char)0x20,  /* [6497] */
    (xdc_Char)0x30,  /* [6498] */
    (xdc_Char)0x78,  /* [6499] */
    (xdc_Char)0x25,  /* [6500] */
    (xdc_Char)0x78,  /* [6501] */
    (xdc_Char)0x2c,  /* [6502] */
    (xdc_Char)0x20,  /* [6503] */
    (xdc_Char)0x66,  /* [6504] */
    (xdc_Char)0x75,  /* [6505] */
    (xdc_Char)0x6e,  /* [6506] */
    (xdc_Char)0x63,  /* [6507] */
    (xdc_Char)0x3a,  /* [6508] */
    (xdc_Char)0x20,  /* [6509] */
    (xdc_Char)0x30,  /* [6510] */
    (xdc_Char)0x78,  /* [6511] */
    (xdc_Char)0x25,  /* [6512] */
    (xdc_Char)0x78,  /* [6513] */
    (xdc_Char)0x2c,  /* [6514] */
    (xdc_Char)0x20,  /* [6515] */
    (xdc_Char)0x6f,  /* [6516] */
    (xdc_Char)0x6c,  /* [6517] */
    (xdc_Char)0x64,  /* [6518] */
    (xdc_Char)0x50,  /* [6519] */
    (xdc_Char)0x72,  /* [6520] */
    (xdc_Char)0x69,  /* [6521] */
    (xdc_Char)0x3a,  /* [6522] */
    (xdc_Char)0x20,  /* [6523] */
    (xdc_Char)0x25,  /* [6524] */
    (xdc_Char)0x64,  /* [6525] */
    (xdc_Char)0x2c,  /* [6526] */
    (xdc_Char)0x20,  /* [6527] */
    (xdc_Char)0x6e,  /* [6528] */
    (xdc_Char)0x65,  /* [6529] */
    (xdc_Char)0x77,  /* [6530] */
    (xdc_Char)0x50,  /* [6531] */
    (xdc_Char)0x72,  /* [6532] */
    (xdc_Char)0x69,  /* [6533] */
    (xdc_Char)0x20,  /* [6534] */
    (xdc_Char)0x25,  /* [6535] */
    (xdc_Char)0x64,  /* [6536] */
    (xdc_Char)0x0,  /* [6537] */
    (xdc_Char)0x4c,  /* [6538] */
    (xdc_Char)0x44,  /* [6539] */
    (xdc_Char)0x5f,  /* [6540] */
    (xdc_Char)0x65,  /* [6541] */
    (xdc_Char)0x78,  /* [6542] */
    (xdc_Char)0x69,  /* [6543] */
    (xdc_Char)0x74,  /* [6544] */
    (xdc_Char)0x3a,  /* [6545] */
    (xdc_Char)0x20,  /* [6546] */
    (xdc_Char)0x74,  /* [6547] */
    (xdc_Char)0x73,  /* [6548] */
    (xdc_Char)0x6b,  /* [6549] */
    (xdc_Char)0x3a,  /* [6550] */
    (xdc_Char)0x20,  /* [6551] */
    (xdc_Char)0x30,  /* [6552] */
    (xdc_Char)0x78,  /* [6553] */
    (xdc_Char)0x25,  /* [6554] */
    (xdc_Char)0x78,  /* [6555] */
    (xdc_Char)0x2c,  /* [6556] */
    (xdc_Char)0x20,  /* [6557] */
    (xdc_Char)0x66,  /* [6558] */
    (xdc_Char)0x75,  /* [6559] */
    (xdc_Char)0x6e,  /* [6560] */
    (xdc_Char)0x63,  /* [6561] */
    (xdc_Char)0x3a,  /* [6562] */
    (xdc_Char)0x20,  /* [6563] */
    (xdc_Char)0x30,  /* [6564] */
    (xdc_Char)0x78,  /* [6565] */
    (xdc_Char)0x25,  /* [6566] */
    (xdc_Char)0x78,  /* [6567] */
    (xdc_Char)0x0,  /* [6568] */
    (xdc_Char)0x4c,  /* [6569] */
    (xdc_Char)0x4d,  /* [6570] */
    (xdc_Char)0x5f,  /* [6571] */
    (xdc_Char)0x62,  /* [6572] */
    (xdc_Char)0x65,  /* [6573] */
    (xdc_Char)0x67,  /* [6574] */
    (xdc_Char)0x69,  /* [6575] */
    (xdc_Char)0x6e,  /* [6576] */
    (xdc_Char)0x3a,  /* [6577] */
    (xdc_Char)0x20,  /* [6578] */
    (xdc_Char)0x68,  /* [6579] */
    (xdc_Char)0x77,  /* [6580] */
    (xdc_Char)0x69,  /* [6581] */
    (xdc_Char)0x3a,  /* [6582] */
    (xdc_Char)0x20,  /* [6583] */
    (xdc_Char)0x30,  /* [6584] */
    (xdc_Char)0x78,  /* [6585] */
    (xdc_Char)0x25,  /* [6586] */
    (xdc_Char)0x78,  /* [6587] */
    (xdc_Char)0x2c,  /* [6588] */
    (xdc_Char)0x20,  /* [6589] */
    (xdc_Char)0x66,  /* [6590] */
    (xdc_Char)0x75,  /* [6591] */
    (xdc_Char)0x6e,  /* [6592] */
    (xdc_Char)0x63,  /* [6593] */
    (xdc_Char)0x3a,  /* [6594] */
    (xdc_Char)0x20,  /* [6595] */
    (xdc_Char)0x30,  /* [6596] */
    (xdc_Char)0x78,  /* [6597] */
    (xdc_Char)0x25,  /* [6598] */
    (xdc_Char)0x78,  /* [6599] */
    (xdc_Char)0x2c,  /* [6600] */
    (xdc_Char)0x20,  /* [6601] */
    (xdc_Char)0x70,  /* [6602] */
    (xdc_Char)0x72,  /* [6603] */
    (xdc_Char)0x65,  /* [6604] */
    (xdc_Char)0x54,  /* [6605] */
    (xdc_Char)0x68,  /* [6606] */
    (xdc_Char)0x72,  /* [6607] */
    (xdc_Char)0x65,  /* [6608] */
    (xdc_Char)0x61,  /* [6609] */
    (xdc_Char)0x64,  /* [6610] */
    (xdc_Char)0x3a,  /* [6611] */
    (xdc_Char)0x20,  /* [6612] */
    (xdc_Char)0x25,  /* [6613] */
    (xdc_Char)0x64,  /* [6614] */
    (xdc_Char)0x2c,  /* [6615] */
    (xdc_Char)0x20,  /* [6616] */
    (xdc_Char)0x69,  /* [6617] */
    (xdc_Char)0x6e,  /* [6618] */
    (xdc_Char)0x74,  /* [6619] */
    (xdc_Char)0x4e,  /* [6620] */
    (xdc_Char)0x75,  /* [6621] */
    (xdc_Char)0x6d,  /* [6622] */
    (xdc_Char)0x3a,  /* [6623] */
    (xdc_Char)0x20,  /* [6624] */
    (xdc_Char)0x25,  /* [6625] */
    (xdc_Char)0x64,  /* [6626] */
    (xdc_Char)0x2c,  /* [6627] */
    (xdc_Char)0x20,  /* [6628] */
    (xdc_Char)0x69,  /* [6629] */
    (xdc_Char)0x72,  /* [6630] */
    (xdc_Char)0x70,  /* [6631] */
    (xdc_Char)0x3a,  /* [6632] */
    (xdc_Char)0x20,  /* [6633] */
    (xdc_Char)0x30,  /* [6634] */
    (xdc_Char)0x78,  /* [6635] */
    (xdc_Char)0x25,  /* [6636] */
    (xdc_Char)0x78,  /* [6637] */
    (xdc_Char)0x0,  /* [6638] */
    (xdc_Char)0x4c,  /* [6639] */
    (xdc_Char)0x44,  /* [6640] */
    (xdc_Char)0x5f,  /* [6641] */
    (xdc_Char)0x65,  /* [6642] */
    (xdc_Char)0x6e,  /* [6643] */
    (xdc_Char)0x64,  /* [6644] */
    (xdc_Char)0x3a,  /* [6645] */
    (xdc_Char)0x20,  /* [6646] */
    (xdc_Char)0x68,  /* [6647] */
    (xdc_Char)0x77,  /* [6648] */
    (xdc_Char)0x69,  /* [6649] */
    (xdc_Char)0x3a,  /* [6650] */
    (xdc_Char)0x20,  /* [6651] */
    (xdc_Char)0x30,  /* [6652] */
    (xdc_Char)0x78,  /* [6653] */
    (xdc_Char)0x25,  /* [6654] */
    (xdc_Char)0x78,  /* [6655] */
    (xdc_Char)0x0,  /* [6656] */
    (xdc_Char)0x78,  /* [6657] */
    (xdc_Char)0x64,  /* [6658] */
    (xdc_Char)0x63,  /* [6659] */
    (xdc_Char)0x2e,  /* [6660] */
    (xdc_Char)0x0,  /* [6661] */
    (xdc_Char)0x72,  /* [6662] */
    (xdc_Char)0x75,  /* [6663] */
    (xdc_Char)0x6e,  /* [6664] */
    (xdc_Char)0x74,  /* [6665] */
    (xdc_Char)0x69,  /* [6666] */
    (xdc_Char)0x6d,  /* [6667] */
    (xdc_Char)0x65,  /* [6668] */
    (xdc_Char)0x2e,  /* [6669] */
    (xdc_Char)0x0,  /* [6670] */
    (xdc_Char)0x41,  /* [6671] */
    (xdc_Char)0x73,  /* [6672] */
    (xdc_Char)0x73,  /* [6673] */
    (xdc_Char)0x65,  /* [6674] */
    (xdc_Char)0x72,  /* [6675] */
    (xdc_Char)0x74,  /* [6676] */
    (xdc_Char)0x0,  /* [6677] */
    (xdc_Char)0x43,  /* [6678] */
    (xdc_Char)0x6f,  /* [6679] */
    (xdc_Char)0x72,  /* [6680] */
    (xdc_Char)0x65,  /* [6681] */
    (xdc_Char)0x0,  /* [6682] */
    (xdc_Char)0x44,  /* [6683] */
    (xdc_Char)0x65,  /* [6684] */
    (xdc_Char)0x66,  /* [6685] */
    (xdc_Char)0x61,  /* [6686] */
    (xdc_Char)0x75,  /* [6687] */
    (xdc_Char)0x6c,  /* [6688] */
    (xdc_Char)0x74,  /* [6689] */
    (xdc_Char)0x73,  /* [6690] */
    (xdc_Char)0x0,  /* [6691] */
    (xdc_Char)0x44,  /* [6692] */
    (xdc_Char)0x69,  /* [6693] */
    (xdc_Char)0x61,  /* [6694] */
    (xdc_Char)0x67,  /* [6695] */
    (xdc_Char)0x73,  /* [6696] */
    (xdc_Char)0x0,  /* [6697] */
    (xdc_Char)0x45,  /* [6698] */
    (xdc_Char)0x72,  /* [6699] */
    (xdc_Char)0x72,  /* [6700] */
    (xdc_Char)0x6f,  /* [6701] */
    (xdc_Char)0x72,  /* [6702] */
    (xdc_Char)0x0,  /* [6703] */
    (xdc_Char)0x47,  /* [6704] */
    (xdc_Char)0x61,  /* [6705] */
    (xdc_Char)0x74,  /* [6706] */
    (xdc_Char)0x65,  /* [6707] */
    (xdc_Char)0x0,  /* [6708] */
    (xdc_Char)0x4c,  /* [6709] */
    (xdc_Char)0x6f,  /* [6710] */
    (xdc_Char)0x67,  /* [6711] */
    (xdc_Char)0x0,  /* [6712] */
    (xdc_Char)0x4d,  /* [6713] */
    (xdc_Char)0x61,  /* [6714] */
    (xdc_Char)0x69,  /* [6715] */
    (xdc_Char)0x6e,  /* [6716] */
    (xdc_Char)0x0,  /* [6717] */
    (xdc_Char)0x4d,  /* [6718] */
    (xdc_Char)0x65,  /* [6719] */
    (xdc_Char)0x6d,  /* [6720] */
    (xdc_Char)0x6f,  /* [6721] */
    (xdc_Char)0x72,  /* [6722] */
    (xdc_Char)0x79,  /* [6723] */
    (xdc_Char)0x0,  /* [6724] */
    (xdc_Char)0x52,  /* [6725] */
    (xdc_Char)0x65,  /* [6726] */
    (xdc_Char)0x67,  /* [6727] */
    (xdc_Char)0x69,  /* [6728] */
    (xdc_Char)0x73,  /* [6729] */
    (xdc_Char)0x74,  /* [6730] */
    (xdc_Char)0x72,  /* [6731] */
    (xdc_Char)0x79,  /* [6732] */
    (xdc_Char)0x0,  /* [6733] */
    (xdc_Char)0x53,  /* [6734] */
    (xdc_Char)0x74,  /* [6735] */
    (xdc_Char)0x61,  /* [6736] */
    (xdc_Char)0x72,  /* [6737] */
    (xdc_Char)0x74,  /* [6738] */
    (xdc_Char)0x75,  /* [6739] */
    (xdc_Char)0x70,  /* [6740] */
    (xdc_Char)0x0,  /* [6741] */
    (xdc_Char)0x53,  /* [6742] */
    (xdc_Char)0x79,  /* [6743] */
    (xdc_Char)0x73,  /* [6744] */
    (xdc_Char)0x74,  /* [6745] */
    (xdc_Char)0x65,  /* [6746] */
    (xdc_Char)0x6d,  /* [6747] */
    (xdc_Char)0x0,  /* [6748] */
    (xdc_Char)0x53,  /* [6749] */
    (xdc_Char)0x79,  /* [6750] */
    (xdc_Char)0x73,  /* [6751] */
    (xdc_Char)0x4d,  /* [6752] */
    (xdc_Char)0x69,  /* [6753] */
    (xdc_Char)0x6e,  /* [6754] */
    (xdc_Char)0x0,  /* [6755] */
    (xdc_Char)0x54,  /* [6756] */
    (xdc_Char)0x65,  /* [6757] */
    (xdc_Char)0x78,  /* [6758] */
    (xdc_Char)0x74,  /* [6759] */
    (xdc_Char)0x0,  /* [6760] */
    (xdc_Char)0x74,  /* [6761] */
    (xdc_Char)0x69,  /* [6762] */
    (xdc_Char)0x2e,  /* [6763] */
    (xdc_Char)0x0,  /* [6764] */
    (xdc_Char)0x73,  /* [6765] */
    (xdc_Char)0x79,  /* [6766] */
    (xdc_Char)0x73,  /* [6767] */
    (xdc_Char)0x62,  /* [6768] */
    (xdc_Char)0x69,  /* [6769] */
    (xdc_Char)0x6f,  /* [6770] */
    (xdc_Char)0x73,  /* [6771] */
    (xdc_Char)0x2e,  /* [6772] */
    (xdc_Char)0x0,  /* [6773] */
    (xdc_Char)0x68,  /* [6774] */
    (xdc_Char)0x61,  /* [6775] */
    (xdc_Char)0x6c,  /* [6776] */
    (xdc_Char)0x2e,  /* [6777] */
    (xdc_Char)0x0,  /* [6778] */
    (xdc_Char)0x48,  /* [6779] */
    (xdc_Char)0x77,  /* [6780] */
    (xdc_Char)0x69,  /* [6781] */
    (xdc_Char)0x0,  /* [6782] */
    (xdc_Char)0x54,  /* [6783] */
    (xdc_Char)0x69,  /* [6784] */
    (xdc_Char)0x6d,  /* [6785] */
    (xdc_Char)0x65,  /* [6786] */
    (xdc_Char)0x72,  /* [6787] */
    (xdc_Char)0x0,  /* [6788] */
    (xdc_Char)0x6b,  /* [6789] */
    (xdc_Char)0x6e,  /* [6790] */
    (xdc_Char)0x6c,  /* [6791] */
    (xdc_Char)0x2e,  /* [6792] */
    (xdc_Char)0x0,  /* [6793] */
    (xdc_Char)0x43,  /* [6794] */
    (xdc_Char)0x6c,  /* [6795] */
    (xdc_Char)0x6f,  /* [6796] */
    (xdc_Char)0x63,  /* [6797] */
    (xdc_Char)0x6b,  /* [6798] */
    (xdc_Char)0x0,  /* [6799] */
    (xdc_Char)0x49,  /* [6800] */
    (xdc_Char)0x64,  /* [6801] */
    (xdc_Char)0x6c,  /* [6802] */
    (xdc_Char)0x65,  /* [6803] */
    (xdc_Char)0x0,  /* [6804] */
    (xdc_Char)0x49,  /* [6805] */
    (xdc_Char)0x6e,  /* [6806] */
    (xdc_Char)0x74,  /* [6807] */
    (xdc_Char)0x72,  /* [6808] */
    (xdc_Char)0x69,  /* [6809] */
    (xdc_Char)0x6e,  /* [6810] */
    (xdc_Char)0x73,  /* [6811] */
    (xdc_Char)0x69,  /* [6812] */
    (xdc_Char)0x63,  /* [6813] */
    (xdc_Char)0x73,  /* [6814] */
    (xdc_Char)0x0,  /* [6815] */
    (xdc_Char)0x51,  /* [6816] */
    (xdc_Char)0x75,  /* [6817] */
    (xdc_Char)0x65,  /* [6818] */
    (xdc_Char)0x75,  /* [6819] */
    (xdc_Char)0x65,  /* [6820] */
    (xdc_Char)0x0,  /* [6821] */
    (xdc_Char)0x53,  /* [6822] */
    (xdc_Char)0x65,  /* [6823] */
    (xdc_Char)0x6d,  /* [6824] */
    (xdc_Char)0x61,  /* [6825] */
    (xdc_Char)0x70,  /* [6826] */
    (xdc_Char)0x68,  /* [6827] */
    (xdc_Char)0x6f,  /* [6828] */
    (xdc_Char)0x72,  /* [6829] */
    (xdc_Char)0x65,  /* [6830] */
    (xdc_Char)0x0,  /* [6831] */
    (xdc_Char)0x53,  /* [6832] */
    (xdc_Char)0x77,  /* [6833] */
    (xdc_Char)0x69,  /* [6834] */
    (xdc_Char)0x0,  /* [6835] */
    (xdc_Char)0x54,  /* [6836] */
    (xdc_Char)0x61,  /* [6837] */
    (xdc_Char)0x73,  /* [6838] */
    (xdc_Char)0x6b,  /* [6839] */
    (xdc_Char)0x0,  /* [6840] */
    (xdc_Char)0x42,  /* [6841] */
    (xdc_Char)0x49,  /* [6842] */
    (xdc_Char)0x4f,  /* [6843] */
    (xdc_Char)0x53,  /* [6844] */
    (xdc_Char)0x0,  /* [6845] */
    (xdc_Char)0x66,  /* [6846] */
    (xdc_Char)0x61,  /* [6847] */
    (xdc_Char)0x6d,  /* [6848] */
    (xdc_Char)0x69,  /* [6849] */
    (xdc_Char)0x6c,  /* [6850] */
    (xdc_Char)0x79,  /* [6851] */
    (xdc_Char)0x2e,  /* [6852] */
    (xdc_Char)0x0,  /* [6853] */
    (xdc_Char)0x61,  /* [6854] */
    (xdc_Char)0x72,  /* [6855] */
    (xdc_Char)0x6d,  /* [6856] */
    (xdc_Char)0x2e,  /* [6857] */
    (xdc_Char)0x0,  /* [6858] */
    (xdc_Char)0x6d,  /* [6859] */
    (xdc_Char)0x33,  /* [6860] */
    (xdc_Char)0x2e,  /* [6861] */
    (xdc_Char)0x0,  /* [6862] */
    (xdc_Char)0x49,  /* [6863] */
    (xdc_Char)0x6e,  /* [6864] */
    (xdc_Char)0x74,  /* [6865] */
    (xdc_Char)0x72,  /* [6866] */
    (xdc_Char)0x69,  /* [6867] */
    (xdc_Char)0x6e,  /* [6868] */
    (xdc_Char)0x73,  /* [6869] */
    (xdc_Char)0x69,  /* [6870] */
    (xdc_Char)0x63,  /* [6871] */
    (xdc_Char)0x73,  /* [6872] */
    (xdc_Char)0x53,  /* [6873] */
    (xdc_Char)0x75,  /* [6874] */
    (xdc_Char)0x70,  /* [6875] */
    (xdc_Char)0x70,  /* [6876] */
    (xdc_Char)0x6f,  /* [6877] */
    (xdc_Char)0x72,  /* [6878] */
    (xdc_Char)0x74,  /* [6879] */
    (xdc_Char)0x0,  /* [6880] */
    (xdc_Char)0x54,  /* [6881] */
    (xdc_Char)0x61,  /* [6882] */
    (xdc_Char)0x73,  /* [6883] */
    (xdc_Char)0x6b,  /* [6884] */
    (xdc_Char)0x53,  /* [6885] */
    (xdc_Char)0x75,  /* [6886] */
    (xdc_Char)0x70,  /* [6887] */
    (xdc_Char)0x70,  /* [6888] */
    (xdc_Char)0x6f,  /* [6889] */
    (xdc_Char)0x72,  /* [6890] */
    (xdc_Char)0x74,  /* [6891] */
    (xdc_Char)0x0,  /* [6892] */
    (xdc_Char)0x64,  /* [6893] */
    (xdc_Char)0x75,  /* [6894] */
    (xdc_Char)0x63,  /* [6895] */
    (xdc_Char)0x61,  /* [6896] */
    (xdc_Char)0x74,  /* [6897] */
    (xdc_Char)0x69,  /* [6898] */
    (xdc_Char)0x2e,  /* [6899] */
    (xdc_Char)0x0,  /* [6900] */
    (xdc_Char)0x43,  /* [6901] */
    (xdc_Char)0x54,  /* [6902] */
    (xdc_Char)0x4d,  /* [6903] */
    (xdc_Char)0x0,  /* [6904] */
    (xdc_Char)0x67,  /* [6905] */
    (xdc_Char)0x61,  /* [6906] */
    (xdc_Char)0x74,  /* [6907] */
    (xdc_Char)0x65,  /* [6908] */
    (xdc_Char)0x73,  /* [6909] */
    (xdc_Char)0x2e,  /* [6910] */
    (xdc_Char)0x0,  /* [6911] */
    (xdc_Char)0x47,  /* [6912] */
    (xdc_Char)0x61,  /* [6913] */
    (xdc_Char)0x74,  /* [6914] */
    (xdc_Char)0x65,  /* [6915] */
    (xdc_Char)0x48,  /* [6916] */
    (xdc_Char)0x77,  /* [6917] */
    (xdc_Char)0x69,  /* [6918] */
    (xdc_Char)0x0,  /* [6919] */
    (xdc_Char)0x47,  /* [6920] */
    (xdc_Char)0x61,  /* [6921] */
    (xdc_Char)0x74,  /* [6922] */
    (xdc_Char)0x65,  /* [6923] */
    (xdc_Char)0x4d,  /* [6924] */
    (xdc_Char)0x75,  /* [6925] */
    (xdc_Char)0x74,  /* [6926] */
    (xdc_Char)0x65,  /* [6927] */
    (xdc_Char)0x78,  /* [6928] */
    (xdc_Char)0x0,  /* [6929] */
    (xdc_Char)0x73,  /* [6930] */
    (xdc_Char)0x64,  /* [6931] */
    (xdc_Char)0x6f,  /* [6932] */
    (xdc_Char)0x2e,  /* [6933] */
    (xdc_Char)0x0,  /* [6934] */
    (xdc_Char)0x75,  /* [6935] */
    (xdc_Char)0x74,  /* [6936] */
    (xdc_Char)0x69,  /* [6937] */
    (xdc_Char)0x6c,  /* [6938] */
    (xdc_Char)0x73,  /* [6939] */
    (xdc_Char)0x2e,  /* [6940] */
    (xdc_Char)0x0,  /* [6941] */
    (xdc_Char)0x4e,  /* [6942] */
    (xdc_Char)0x61,  /* [6943] */
    (xdc_Char)0x6d,  /* [6944] */
    (xdc_Char)0x65,  /* [6945] */
    (xdc_Char)0x53,  /* [6946] */
    (xdc_Char)0x65,  /* [6947] */
    (xdc_Char)0x72,  /* [6948] */
    (xdc_Char)0x76,  /* [6949] */
    (xdc_Char)0x65,  /* [6950] */
    (xdc_Char)0x72,  /* [6951] */
    (xdc_Char)0x52,  /* [6952] */
    (xdc_Char)0x65,  /* [6953] */
    (xdc_Char)0x6d,  /* [6954] */
    (xdc_Char)0x6f,  /* [6955] */
    (xdc_Char)0x74,  /* [6956] */
    (xdc_Char)0x65,  /* [6957] */
    (xdc_Char)0x4e,  /* [6958] */
    (xdc_Char)0x75,  /* [6959] */
    (xdc_Char)0x6c,  /* [6960] */
    (xdc_Char)0x6c,  /* [6961] */
    (xdc_Char)0x0,  /* [6962] */
    (xdc_Char)0x68,  /* [6963] */
    (xdc_Char)0x65,  /* [6964] */
    (xdc_Char)0x61,  /* [6965] */
    (xdc_Char)0x70,  /* [6966] */
    (xdc_Char)0x73,  /* [6967] */
    (xdc_Char)0x2e,  /* [6968] */
    (xdc_Char)0x0,  /* [6969] */
    (xdc_Char)0x48,  /* [6970] */
    (xdc_Char)0x65,  /* [6971] */
    (xdc_Char)0x61,  /* [6972] */
    (xdc_Char)0x70,  /* [6973] */
    (xdc_Char)0x4d,  /* [6974] */
    (xdc_Char)0x65,  /* [6975] */
    (xdc_Char)0x6d,  /* [6976] */
    (xdc_Char)0x0,  /* [6977] */
    (xdc_Char)0x74,  /* [6978] */
    (xdc_Char)0x69,  /* [6979] */
    (xdc_Char)0x2e,  /* [6980] */
    (xdc_Char)0x73,  /* [6981] */
    (xdc_Char)0x79,  /* [6982] */
    (xdc_Char)0x73,  /* [6983] */
    (xdc_Char)0x62,  /* [6984] */
    (xdc_Char)0x69,  /* [6985] */
    (xdc_Char)0x6f,  /* [6986] */
    (xdc_Char)0x73,  /* [6987] */
    (xdc_Char)0x2e,  /* [6988] */
    (xdc_Char)0x6b,  /* [6989] */
    (xdc_Char)0x6e,  /* [6990] */
    (xdc_Char)0x6c,  /* [6991] */
    (xdc_Char)0x2e,  /* [6992] */
    (xdc_Char)0x54,  /* [6993] */
    (xdc_Char)0x61,  /* [6994] */
    (xdc_Char)0x73,  /* [6995] */
    (xdc_Char)0x6b,  /* [6996] */
    (xdc_Char)0x2e,  /* [6997] */
    (xdc_Char)0x49,  /* [6998] */
    (xdc_Char)0x64,  /* [6999] */
    (xdc_Char)0x6c,  /* [7000] */
    (xdc_Char)0x65,  /* [7001] */
    (xdc_Char)0x54,  /* [7002] */
    (xdc_Char)0x61,  /* [7003] */
    (xdc_Char)0x73,  /* [7004] */
    (xdc_Char)0x6b,  /* [7005] */
    (xdc_Char)0x0,  /* [7006] */
};

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[47] = {
    {
        (xdc_Bits16)0x0,  /* left */
        (xdc_Bits16)0x0,  /* right */
    },  /* [0] */
    {
        (xdc_Bits16)0x1a01,  /* left */
        (xdc_Bits16)0x1a06,  /* right */
    },  /* [1] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a0f,  /* right */
    },  /* [2] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a16,  /* right */
    },  /* [3] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a1b,  /* right */
    },  /* [4] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a24,  /* right */
    },  /* [5] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a2a,  /* right */
    },  /* [6] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a30,  /* right */
    },  /* [7] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a35,  /* right */
    },  /* [8] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a39,  /* right */
    },  /* [9] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a3e,  /* right */
    },  /* [10] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a45,  /* right */
    },  /* [11] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a4e,  /* right */
    },  /* [12] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a56,  /* right */
    },  /* [13] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a5d,  /* right */
    },  /* [14] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1a64,  /* right */
    },  /* [15] */
    {
        (xdc_Bits16)0x1a69,  /* left */
        (xdc_Bits16)0x1a6d,  /* right */
    },  /* [16] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1a76,  /* right */
    },  /* [17] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1a7b,  /* right */
    },  /* [18] */
    {
        (xdc_Bits16)0x8011,  /* left */
        (xdc_Bits16)0x1a7f,  /* right */
    },  /* [19] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1a85,  /* right */
    },  /* [20] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1a8a,  /* right */
    },  /* [21] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1a90,  /* right */
    },  /* [22] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1a95,  /* right */
    },  /* [23] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1aa0,  /* right */
    },  /* [24] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1aa6,  /* right */
    },  /* [25] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1ab0,  /* right */
    },  /* [26] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1ab4,  /* right */
    },  /* [27] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1ab9,  /* right */
    },  /* [28] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1abe,  /* right */
    },  /* [29] */
    {
        (xdc_Bits16)0x801d,  /* left */
        (xdc_Bits16)0x1ac6,  /* right */
    },  /* [30] */
    {
        (xdc_Bits16)0x801e,  /* left */
        (xdc_Bits16)0x1acb,  /* right */
    },  /* [31] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x1a7b,  /* right */
    },  /* [32] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x1acf,  /* right */
    },  /* [33] */
    {
        (xdc_Bits16)0x801f,  /* left */
        (xdc_Bits16)0x1ae1,  /* right */
    },  /* [34] */
    {
        (xdc_Bits16)0x801e,  /* left */
        (xdc_Bits16)0x1aed,  /* right */
    },  /* [35] */
    {
        (xdc_Bits16)0x8023,  /* left */
        (xdc_Bits16)0x1a16,  /* right */
    },  /* [36] */
    {
        (xdc_Bits16)0x8023,  /* left */
        (xdc_Bits16)0x1af5,  /* right */
    },  /* [37] */
    {
        (xdc_Bits16)0x8023,  /* left */
        (xdc_Bits16)0x1a7f,  /* right */
    },  /* [38] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1af9,  /* right */
    },  /* [39] */
    {
        (xdc_Bits16)0x8027,  /* left */
        (xdc_Bits16)0x1b00,  /* right */
    },  /* [40] */
    {
        (xdc_Bits16)0x8027,  /* left */
        (xdc_Bits16)0x1b08,  /* right */
    },  /* [41] */
    {
        (xdc_Bits16)0x1a69,  /* left */
        (xdc_Bits16)0x1b12,  /* right */
    },  /* [42] */
    {
        (xdc_Bits16)0x802a,  /* left */
        (xdc_Bits16)0x1b17,  /* right */
    },  /* [43] */
    {
        (xdc_Bits16)0x802b,  /* left */
        (xdc_Bits16)0x1b1e,  /* right */
    },  /* [44] */
    {
        (xdc_Bits16)0x8010,  /* left */
        (xdc_Bits16)0x1b33,  /* right */
    },  /* [45] */
    {
        (xdc_Bits16)0x802d,  /* left */
        (xdc_Bits16)0x1b3a,  /* right */
    },  /* [46] */
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
__FAR__ const CT__xdc_runtime_Text_charCnt xdc_runtime_Text_charCnt__C = (xdc_Int16)0x1b5f;

/* nodeCnt__C */
__FAR__ const CT__xdc_runtime_Text_nodeCnt xdc_runtime_Text_nodeCnt__C = (xdc_Int16)0x2f;

/* unnamedModsLastId__C */
__FAR__ const CT__xdc_runtime_Text_unnamedModsLastId xdc_runtime_Text_unnamedModsLastId__C = (xdc_UInt16)0x4000;

/* registryModsLastId__C */
__FAR__ const CT__xdc_runtime_Text_registryModsLastId xdc_runtime_Text_registryModsLastId__C = (xdc_UInt16)0x7fff;

/* visitRopeFxn__C */
__FAR__ const CT__xdc_runtime_Text_visitRopeFxn xdc_runtime_Text_visitRopeFxn__C = ((CT__xdc_runtime_Text_visitRopeFxn)((xdc_Fxn)xdc_runtime_Text_visitRope__I));

/* visitRopeFxn2__C */
__FAR__ const CT__xdc_runtime_Text_visitRopeFxn2 xdc_runtime_Text_visitRopeFxn2__C = ((CT__xdc_runtime_Text_visitRopeFxn2)((xdc_Fxn)xdc_runtime_Text_visitRope2__I));


/*
 * ======== ti.sdo.utils.NameServerRemoteNull FUNCTION STUBS ========
 */

/* get__E */
xdc_Int ti_sdo_utils_NameServerRemoteNull_get__E( ti_sdo_utils_NameServerRemoteNull_Handle __inst, xdc_String instanceName, xdc_String name, xdc_Ptr value, xdc_UInt32* valueLen, xdc_runtime_knl_ISync_Handle syncHandle, xdc_runtime_Error_Block* eb ) 
{
    return ti_sdo_utils_NameServerRemoteNull_get__F((void*)__inst, instanceName, name, value, valueLen, syncHandle, eb);
}

/* Module_startup */
xdc_Int ti_sysbios_family_arm_ducati_Core_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_arm_ducati_Core_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_family_arm_ducati_Timer_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_arm_ducati_Timer_Module_startup__F(state);
}

/* Module_startup */
xdc_Int ti_sysbios_family_arm_m3_Hwi_Module_startup__E( xdc_Int state )
{
    return ti_sysbios_family_arm_m3_Hwi_Module_startup__F(state);
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

/* DELEGATES TO ti.sysbios.family.arm.m3.Hwi */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_m3_Hwi_Module__startupDone__S();
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
    return ti_sysbios_family_arm_m3_Hwi_Object__create__S(oa, osz, aa, (ti_sysbios_family_arm_m3_Hwi___ParamsPtr)pa, sizeof(ti_sysbios_interfaces_IHwi_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_hal_Hwi_HwiProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_family_arm_m3_Hwi_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Hwi_HwiProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_arm_m3_Hwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_family_arm_m3_Hwi_Handle__label__S(obj, lab);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_startup__E( void )
{
    ti_sysbios_family_arm_m3_Hwi_startup();
}

/* disable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disable__E( void )
{
    return ti_sysbios_family_arm_m3_Hwi_disable();
}

/* enable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enable__E( void )
{
    return ti_sysbios_family_arm_m3_Hwi_enable();
}

/* restore__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restore__E( xdc_UInt key )
{
    ti_sysbios_family_arm_m3_Hwi_restore(key);
}

/* switchFromBootStack__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E( void )
{
    ti_sysbios_family_arm_m3_Hwi_switchFromBootStack();
}

/* post__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_post__E( xdc_UInt intNum )
{
    ti_sysbios_family_arm_m3_Hwi_post(intNum);
}

/* getTaskSP__E */
xdc_Char* ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E( void )
{
    return ti_sysbios_family_arm_m3_Hwi_getTaskSP();
}

/* disableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_arm_m3_Hwi_disableInterrupt(intNum);
}

/* enableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_arm_m3_Hwi_enableInterrupt(intNum);
}

/* restoreInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key )
{
    ti_sysbios_family_arm_m3_Hwi_restoreInterrupt(intNum, key);
}

/* clearInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E( xdc_UInt intNum )
{
    ti_sysbios_family_arm_m3_Hwi_clearInterrupt(intNum);
}

/* getFunc__E */
ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_getFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_UArg* arg )
{
    return ti_sysbios_family_arm_m3_Hwi_getFunc((ti_sysbios_family_arm_m3_Hwi_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_arm_m3_Hwi_setFunc((ti_sysbios_family_arm_m3_Hwi_Handle)__inst, fxn, arg);
}

/* getHookContext__E */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id )
{
    return ti_sysbios_family_arm_m3_Hwi_getHookContext((ti_sysbios_family_arm_m3_Hwi_Handle)__inst, id);
}

/* setHookContext__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst, xdc_Int id, xdc_Ptr hookContext )
{
    ti_sysbios_family_arm_m3_Hwi_setHookContext((ti_sysbios_family_arm_m3_Hwi_Handle)__inst, id, hookContext);
}

/* getIrp__E */
ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_HwiProxy_getIrp__E( ti_sysbios_hal_Hwi_HwiProxy_Handle __inst )
{
    return ti_sysbios_family_arm_m3_Hwi_getIrp((ti_sysbios_family_arm_m3_Hwi_Handle)__inst);
}


/*
 * ======== ti.sysbios.hal.Timer_TimerProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.arm.ducati.Timer */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Timer_TimerProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_ducati_Timer_Module__startupDone__S();
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
    return ti_sysbios_family_arm_ducati_Timer_Object__create__S(oa, osz, aa, (ti_sysbios_family_arm_ducati_Timer___ParamsPtr)pa, sizeof(ti_sysbios_interfaces_ITimer_Params), eb);
}

/* Object__delete__S */
void ti_sysbios_hal_Timer_TimerProxy_Object__delete__S( Ptr instp ) 
{
    ti_sysbios_family_arm_ducati_Timer_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Timer_TimerProxy_Params__init__S( xdc_Ptr dst, const xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_arm_ducati_Timer_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_hal_Timer_TimerProxy_Handle__label__S( Ptr obj, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_family_arm_ducati_Timer_Handle__label__S(obj, lab);
}

/* getNumTimers__E */
xdc_UInt ti_sysbios_hal_Timer_TimerProxy_getNumTimers__E( void )
{
    return ti_sysbios_family_arm_ducati_Timer_getNumTimers();
}

/* getStatus__E */
ti_sysbios_interfaces_ITimer_Status ti_sysbios_hal_Timer_TimerProxy_getStatus__E( xdc_UInt id )
{
    return ti_sysbios_family_arm_ducati_Timer_getStatus(id);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_startup__E( void )
{
    ti_sysbios_family_arm_ducati_Timer_startup();
}

/* getMaxTicks__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getMaxTicks__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 periodCounts )
{
    return ti_sysbios_family_arm_ducati_Timer_getMaxTicks((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, periodCounts);
}

/* setNextTick__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setNextTick__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 newPeriod, xdc_UInt32 countsPerTick )
{
    ti_sysbios_family_arm_ducati_Timer_setNextTick((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, newPeriod, countsPerTick);
}

/* start__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_start__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    ti_sysbios_family_arm_ducati_Timer_start((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* stop__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_stop__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    ti_sysbios_family_arm_ducati_Timer_stop((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* setPeriod__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setPeriod__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 period )
{
    ti_sysbios_family_arm_ducati_Timer_setPeriod((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, period);
}

/* setPeriodMicroSecs__E */
xdc_Bool ti_sysbios_hal_Timer_TimerProxy_setPeriodMicroSecs__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 microsecs )
{
    return ti_sysbios_family_arm_ducati_Timer_setPeriodMicroSecs((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, microsecs);
}

/* getPeriod__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getPeriod__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_family_arm_ducati_Timer_getPeriod((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* getCount__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getCount__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_family_arm_ducati_Timer_getCount((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
}

/* getFreq__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_getFreq__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_runtime_Types_FreqHz* freq )
{
    ti_sysbios_family_arm_ducati_Timer_getFreq((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, freq);
}

/* getFunc__E */
ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_hal_Timer_TimerProxy_getFunc__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UArg* arg )
{
    return ti_sysbios_family_arm_ducati_Timer_getFunc((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_setFunc__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_arm_ducati_Timer_setFunc((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, fxn, arg);
}

/* trigger__E */
xdc_Void ti_sysbios_hal_Timer_TimerProxy_trigger__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst, xdc_UInt32 cycles )
{
    ti_sysbios_family_arm_ducati_Timer_trigger((ti_sysbios_family_arm_ducati_Timer_Handle)__inst, cycles);
}

/* getExpiredCounts__E */
xdc_UInt32 ti_sysbios_hal_Timer_TimerProxy_getExpiredCounts__E( ti_sysbios_hal_Timer_TimerProxy_Handle __inst )
{
    return ti_sysbios_family_arm_ducati_Timer_getExpiredCounts((ti_sysbios_family_arm_ducati_Timer_Handle)__inst);
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

/* DELEGATES TO ti.sysbios.family.arm.m3.IntrinsicsSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDone__S();
}

/* maxbit__E */
xdc_UInt ti_sysbios_knl_Intrinsics_SupportProxy_maxbit__E( xdc_UInt bits )
{
    return ti_sysbios_family_arm_m3_IntrinsicsSupport_maxbit(bits);
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.arm.m3.TaskSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_m3_TaskSupport_Module__startupDone__S();
}

/* start__E */
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_start__E( xdc_Ptr curTask, ti_sysbios_interfaces_ITaskSupport_FuncPtr enter, ti_sysbios_interfaces_ITaskSupport_FuncPtr exit, xdc_runtime_Error_Block* eb )
{
    return ti_sysbios_family_arm_m3_TaskSupport_start(curTask, enter, exit, eb);
}

/* swap__E */
xdc_Void ti_sysbios_knl_Task_SupportProxy_swap__E( xdc_Ptr* oldtskContext, xdc_Ptr* newtskContext )
{
    ti_sysbios_family_arm_m3_TaskSupport_swap(oldtskContext, newtskContext);
}

/* checkStack__E */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_checkStack__E( xdc_Char* stack, xdc_SizeT size )
{
    return ti_sysbios_family_arm_m3_TaskSupport_checkStack(stack, size);
}

/* stackUsed__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_stackUsed__E( xdc_Char* stack, xdc_SizeT size )
{
    return ti_sysbios_family_arm_m3_TaskSupport_stackUsed(stack, size);
}

/* getStackAlignment__E */
xdc_UInt ti_sysbios_knl_Task_SupportProxy_getStackAlignment__E( void )
{
    return ti_sysbios_family_arm_m3_TaskSupport_getStackAlignment();
}

/* getDefaultStackSize__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_getDefaultStackSize__E( void )
{
    return ti_sysbios_family_arm_m3_TaskSupport_getDefaultStackSize();
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
 * ======== ti.sysbios.family.arm.ducati.Timer OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_arm_ducati_Timer_Object2__ s0; char c; } ti_sysbios_family_arm_ducati_Timer___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_ducati_Timer_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_family_arm_ducati_Timer_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_arm_ducati_Timer___S1) - sizeof(ti_sysbios_family_arm_ducati_Timer_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_arm_ducati_Timer_Object2__), /* objSize */
    (Ptr)&ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_arm_ducati_Timer_Params), /* prmsSize */
};



/*
 * ======== ti.sysbios.family.arm.m3.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_arm_m3_Hwi_Object2__ s0; char c; } ti_sysbios_family_arm_m3_Hwi___S1;
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_arm_m3_Hwi_Object__DESC__C = {
    (Ptr)0, /* fxnTab */
    &ti_sysbios_family_arm_m3_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_arm_m3_Hwi___S1) - sizeof(ti_sysbios_family_arm_m3_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_arm_m3_Hwi_Object2__), /* objSize */
    (Ptr)&ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_arm_m3_Hwi_Params), /* prmsSize */
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
    lab->modId = 32812;
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
 * ======== ti.sysbios.family.arm.ducati.CTM SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_ducati_CTM_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.family.arm.ducati.Core SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_ducati_Core_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_ducati_Core_Module__startupDone__F();
}



/*
 * ======== ti.sysbios.family.arm.ducati.Timer SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_arm_ducati_Timer_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_arm_ducati_Timer_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_arm_ducati_Timer_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_arm_ducati_Timer_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_arm_ducati_Timer_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_arm_ducati_Timer_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_ducati_Timer_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_ducati_Timer_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_family_arm_ducati_Timer_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32806;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_arm_ducati_Timer_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_arm_ducati_Timer_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_family_arm_ducati_Timer_Object__*)oa) + i;
    }

    if (ti_sysbios_family_arm_ducati_Timer_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_family_arm_ducati_Timer_Object__*)ti_sysbios_family_arm_ducati_Timer_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_arm_ducati_Timer_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_arm_ducati_Timer_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_arm_ducati_Timer_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_arm_ducati_Timer_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_arm_ducati_Timer_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_arm_ducati_Timer_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_family_arm_ducati_Timer___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_family_arm_ducati_Timer_Params prms;
    ti_sysbios_family_arm_ducati_Timer_Object* obj;
    int iStat;

    ti_sysbios_family_arm_ducati_Timer_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_ducati_Timer_Instance_init__F(obj, args->id, args->tickFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_family_arm_ducati_Timer_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_arm_ducati_Timer_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, *((ti_sysbios_family_arm_ducati_Timer_Object**)instp), (xdc_Fxn)ti_sysbios_family_arm_ducati_Timer_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_family_arm_ducati_Timer_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.family.arm.m3.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_arm_m3_Hwi_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_arm_m3_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_m3_Hwi_Module__startupDone__S( void ) 
{
    return ti_sysbios_family_arm_m3_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label* ti_sysbios_family_arm_m3_Hwi_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab ) 
{
    lab->handle = obj;
    lab->modId = 32800;
    xdc_runtime_Core_assignLabel(lab, 0, 0);

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_arm_m3_Hwi_Params__init__S( xdc_Ptr prms, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_Ptr)(src ? src : &ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__get__S( xdc_Ptr oa, xdc_Int i ) 
{
    if (oa) {
        return ((ti_sysbios_family_arm_m3_Hwi_Object__*)oa) + i;
    }

    if (ti_sysbios_family_arm_m3_Hwi_Object__count__C == 0) {
        return NULL;
    }

    return ((ti_sysbios_family_arm_m3_Hwi_Object__*)ti_sysbios_family_arm_m3_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_arm_m3_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_arm_m3_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__next__S( xdc_Ptr obj ) 
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_arm_m3_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_arm_m3_Hwi_Object__create__S (
    xdc_Ptr oa,
    xdc_SizeT osz,
    const xdc_Ptr aa,
    const ti_sysbios_family_arm_m3_Hwi___ParamsPtr pa,
    xdc_SizeT psz,
    xdc_runtime_Error_Block* eb )
{
    ti_sysbios_family_arm_m3_Hwi_Params prms;
    ti_sysbios_family_arm_m3_Hwi_Object* obj;
    int iStat;

    ti_sysbios_family_arm_m3_Hwi_Args__create* args = aa;
    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, oa, osz, &prms, (xdc_Ptr)pa, psz, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_arm_m3_Hwi_Instance_init__F(obj, args->intNum, args->hwiFxn, &prms, eb);
    if (xdc_runtime_Error_check(eb)) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Instance_finalize__F, iStat, (xdc_Bool)(oa != NULL));
        return NULL;
    }

    return obj;
}

/* Object__destruct__S */
xdc_Void ti_sysbios_family_arm_m3_Hwi_Object__destruct__S( xdc_Ptr obj ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Instance_finalize__F, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_arm_m3_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, *((ti_sysbios_family_arm_m3_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_family_arm_m3_Hwi_Instance_finalize__F, 0, FALSE);
    *((ti_sysbios_family_arm_m3_Hwi_Handle*)instp) = NULL;
}


/*
 * ======== ti.sysbios.family.arm.m3.IntrinsicsSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDone__S( void ) 
{
    return 1;
}



/*
 * ======== ti.sysbios.family.arm.m3.TaskSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_arm_m3_TaskSupport_Module__startupDone__S( void ) 
{
    return 1;
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
    lab->modId = 32808;
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
    lab->modId = 32809;
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
    lab->modId = 32786;
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
    lab->modId = 32787;
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
    lab->modId = 32814;
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
    lab->modId = 32789;
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
    return (xdc_Ptr)&ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C;
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
    lab->modId = 32792;
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
    lab->modId = 32793;
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
    lab->modId = 32794;
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
    lab->modId = 32795;
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
#pragma DATA_SECTION(ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C, ".const:ti_sysbios_interfaces_IIntrinsicsSupport_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_IGateProvider_Interface__BASE__C, ".const:xdc_runtime_IGateProvider_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_IHeap_Interface__BASE__C, ".const:xdc_runtime_IHeap_Interface__BASE__C");
#pragma DATA_SECTION(xdc_runtime_ISystemSupport_Interface__BASE__C, ".const:xdc_runtime_ISystemSupport_Interface__BASE__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__FXNS__C, ".const:ti_sysbios_gates_GateHwi_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__FXNS__C, ".const:ti_sysbios_gates_GateMutex_Module__FXNS__C");
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__FXNS__C, ".const:ti_sysbios_heaps_HeapMem_Module__FXNS__C");
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__FXNS__C, ".const:xdc_runtime_SysMin_Module__FXNS__C");
#pragma DATA_SECTION(ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C, ".const:ti_sdo_utils_NameServerRemoteNull_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C");
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
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__diagsMask__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__gateObj__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__gatePrms__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__id__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerObj__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_ducati_CTM_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Object__count__C, ".const:ti_sysbios_family_arm_ducati_CTM_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Object__heap__C, ".const:ti_sysbios_family_arm_ducati_CTM_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Object__sizeof__C, ".const:ti_sysbios_family_arm_ducati_CTM_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_CTM_Object__table__C, ".const:ti_sysbios_family_arm_ducati_CTM_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__diagsMask__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__gateObj__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__gatePrms__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__id__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerObj__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_ducati_Core_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Object__count__C, ".const:ti_sysbios_family_arm_ducati_Core_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Object__heap__C, ".const:ti_sysbios_family_arm_ducati_Core_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Object__sizeof__C, ".const:ti_sysbios_family_arm_ducati_Core_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_Object__table__C, ".const:ti_sysbios_family_arm_ducati_Core_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_id__C, ".const:ti_sysbios_family_arm_ducati_Core_id__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Core_E_mismatchedIds__C, ".const:ti_sysbios_family_arm_ducati_Core_E_mismatchedIds__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__DESC__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__diagsMask__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__gateObj__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__gatePrms__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__id__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerObj__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_ducati_Timer_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__count__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__heap__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__sizeof__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_Object__table__C, ".const:ti_sysbios_family_arm_ducati_Timer_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_E_invalidTimer__C, ".const:ti_sysbios_family_arm_ducati_Timer_E_invalidTimer__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_E_notAvailable__C, ".const:ti_sysbios_family_arm_ducati_Timer_E_notAvailable__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_E_cannotSupport__C, ".const:ti_sysbios_family_arm_ducati_Timer_E_cannotSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_anyMask__C, ".const:ti_sysbios_family_arm_ducati_Timer_anyMask__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_ducati_Timer_startupNeeded__C, ".const:ti_sysbios_family_arm_ducati_Timer_startupNeeded__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__DESC__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__DESC__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__PARAMS__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__id__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_m3_Hwi_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__count__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__heap__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__sizeof__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_Object__table__C, ".const:ti_sysbios_family_arm_m3_Hwi_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__C, ".const:ti_sysbios_family_arm_m3_Hwi_dispatcherAutoNestingSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__C, ".const:ti_sysbios_family_arm_m3_Hwi_dispatcherSwiSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__C, ".const:ti_sysbios_family_arm_m3_Hwi_dispatcherTaskSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__C, ".const:ti_sysbios_family_arm_m3_Hwi_dispatcherIrpTrackingSupport__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__C, ".const:ti_sysbios_family_arm_m3_Hwi_NUM_INTERRUPTS__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__C, ".const:ti_sysbios_family_arm_m3_Hwi_NUM_PRIORITIES__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_LM_begin__C, ".const:ti_sysbios_family_arm_m3_Hwi_LM_begin__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_LD_end__C, ".const:ti_sysbios_family_arm_m3_Hwi_LD_end__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption__C, ".const:ti_sysbios_family_arm_m3_Hwi_A_unsupportedMaskingOption__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_alreadyDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_exception__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_exception__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_noIsr__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_noIsr__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_NMI__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_NMI__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_hardFault__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_hardFault__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_memFault__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_memFault__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_busFault__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_busFault__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_usageFault__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_usageFault__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_svCall__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_svCall__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_debugMon__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_debugMon__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_E_reserved__C, ".const:ti_sysbios_family_arm_m3_Hwi_E_reserved__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_excHookFunc__C, ".const:ti_sysbios_family_arm_m3_Hwi_excHookFunc__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_disablePriority__C, ".const:ti_sysbios_family_arm_m3_Hwi_disablePriority__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_priGroup__C, ".const:ti_sysbios_family_arm_m3_Hwi_priGroup__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_swiDisable__C, ".const:ti_sysbios_family_arm_m3_Hwi_swiDisable__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi__C, ".const:ti_sysbios_family_arm_m3_Hwi_swiRestoreHwi__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_taskDisable__C, ".const:ti_sysbios_family_arm_m3_Hwi_taskDisable__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi__C, ".const:ti_sysbios_family_arm_m3_Hwi_taskRestoreHwi__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_ccr__C, ".const:ti_sysbios_family_arm_m3_Hwi_ccr__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_hooks__C, ".const:ti_sysbios_family_arm_m3_Hwi_hooks__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_Hwi_excHandlerFunc__C, ".const:ti_sysbios_family_arm_m3_Hwi_excHandlerFunc__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__id__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__count__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__heap__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__sizeof__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__table__C, ".const:ti_sysbios_family_arm_m3_IntrinsicsSupport_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__diagsEnabled__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__diagsEnabled__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__diagsIncluded__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__diagsIncluded__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__diagsMask__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__gateObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__gatePrms__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__id__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__id__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerDefined__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerDefined__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerObj__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn0__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn1__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn2__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn4__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__loggerFxn8__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Module__startupDoneFxn__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Object__count__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Object__count__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Object__heap__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Object__heap__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Object__sizeof__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Object__sizeof__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_Object__table__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_Object__table__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_defaultStackSize__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_defaultStackSize__C");
#pragma DATA_SECTION(ti_sysbios_family_arm_m3_TaskSupport_stackAlignment__C, ".const:ti_sysbios_family_arm_m3_TaskSupport_stackAlignment__C");
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
