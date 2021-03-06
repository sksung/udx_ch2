/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *
 */

/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y25
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     CREATE ARGS
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     FUNCTION SELECTORS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_family_arm_sim1030_Timer__include
#define ti_sysbios_family_arm_sim1030_Timer__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_sim1030_Timer__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_sim1030_Timer___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/family/arm/sim1030/package/package.defs.h>

#include <ti/sysbios/interfaces/ITimer.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_family_arm_sim1030_Timer_FuncPtr;

/* ANY */
#define ti_sysbios_family_arm_sim1030_Timer_ANY (~0)

/* StartMode */
typedef ti_sysbios_interfaces_ITimer_StartMode ti_sysbios_family_arm_sim1030_Timer_StartMode;

/* RunMode */
typedef ti_sysbios_interfaces_ITimer_RunMode ti_sysbios_family_arm_sim1030_Timer_RunMode;

/* Status */
typedef ti_sysbios_interfaces_ITimer_Status ti_sysbios_family_arm_sim1030_Timer_Status;

/* PeriodType */
typedef ti_sysbios_interfaces_ITimer_PeriodType ti_sysbios_family_arm_sim1030_Timer_PeriodType;

/* StartMode_AUTO */
#define ti_sysbios_family_arm_sim1030_Timer_StartMode_AUTO ti_sysbios_interfaces_ITimer_StartMode_AUTO

/* StartMode_USER */
#define ti_sysbios_family_arm_sim1030_Timer_StartMode_USER ti_sysbios_interfaces_ITimer_StartMode_USER

/* RunMode_CONTINUOUS */
#define ti_sysbios_family_arm_sim1030_Timer_RunMode_CONTINUOUS ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS

/* RunMode_ONESHOT */
#define ti_sysbios_family_arm_sim1030_Timer_RunMode_ONESHOT ti_sysbios_interfaces_ITimer_RunMode_ONESHOT

/* RunMode_DYNAMIC */
#define ti_sysbios_family_arm_sim1030_Timer_RunMode_DYNAMIC ti_sysbios_interfaces_ITimer_RunMode_DYNAMIC

/* Status_INUSE */
#define ti_sysbios_family_arm_sim1030_Timer_Status_INUSE ti_sysbios_interfaces_ITimer_Status_INUSE

/* Status_FREE */
#define ti_sysbios_family_arm_sim1030_Timer_Status_FREE ti_sysbios_interfaces_ITimer_Status_FREE

/* PeriodType_MICROSECS */
#define ti_sysbios_family_arm_sim1030_Timer_PeriodType_MICROSECS ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS

/* PeriodType_COUNTS */
#define ti_sysbios_family_arm_sim1030_Timer_PeriodType_COUNTS ti_sysbios_interfaces_ITimer_PeriodType_COUNTS


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_family_arm_sim1030_Timer_Args__create {
    xdc_Int id;
    ti_sysbios_interfaces_ITimer_FuncPtr tickFxn;
} ti_sysbios_family_arm_sim1030_Timer_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_sim1030_Timer_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__diagsEnabled ti_sysbios_family_arm_sim1030_Timer_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_sim1030_Timer_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__diagsIncluded ti_sysbios_family_arm_sim1030_Timer_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sysbios_family_arm_sim1030_Timer_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__diagsMask ti_sysbios_family_arm_sim1030_Timer_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_sim1030_Timer_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__gateObj ti_sysbios_family_arm_sim1030_Timer_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_sim1030_Timer_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__gatePrms ti_sysbios_family_arm_sim1030_Timer_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_sim1030_Timer_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__id ti_sysbios_family_arm_sim1030_Timer_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerDefined ti_sysbios_family_arm_sim1030_Timer_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerObj ti_sysbios_family_arm_sim1030_Timer_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn0 ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn1 ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn2 ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn4 ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn8 ti_sysbios_family_arm_sim1030_Timer_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_sim1030_Timer_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Module__startupDoneFxn ti_sysbios_family_arm_sim1030_Timer_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_sim1030_Timer_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Object__count ti_sysbios_family_arm_sim1030_Timer_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_sim1030_Timer_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Object__heap ti_sysbios_family_arm_sim1030_Timer_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_sim1030_Timer_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Object__sizeof ti_sysbios_family_arm_sim1030_Timer_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_sim1030_Timer_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_sim1030_Timer_Object__table ti_sysbios_family_arm_sim1030_Timer_Object__table__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_family_arm_sim1030_Timer_Params {
    size_t __size;
    const void* __self;
    void* __fxns;
    xdc_runtime_IInstance_Params* instance;
    ti_sysbios_interfaces_ITimer_RunMode runMode;
    ti_sysbios_interfaces_ITimer_StartMode startMode;
    xdc_UArg arg;
    xdc_UInt32 period;
    ti_sysbios_interfaces_ITimer_PeriodType periodType;
    xdc_runtime_Types_FreqHz extFreq;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_family_arm_sim1030_Timer_Struct {
    const ti_sysbios_family_arm_sim1030_Timer_Fxns__* __fxns;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_family_arm_sim1030_Timer_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_UInt (*getNumTimers)(void);
    ti_sysbios_interfaces_ITimer_Status (*getStatus)(xdc_UInt);
    xdc_Void (*startup)(void);
    xdc_UInt32 (*getMaxTicks)(ti_sysbios_family_arm_sim1030_Timer_Handle, xdc_UInt32);
    xdc_Void (*setNextTick)(ti_sysbios_family_arm_sim1030_Timer_Handle, xdc_UInt32, xdc_UInt32);
    xdc_Void (*start)(ti_sysbios_family_arm_sim1030_Timer_Handle);
    xdc_Void (*stop)(ti_sysbios_family_arm_sim1030_Timer_Handle);
    xdc_Void (*setPeriod)(ti_sysbios_family_arm_sim1030_Timer_Handle, xdc_UInt32);
    xdc_Bool (*setPeriodMicroSecs)(ti_sysbios_family_arm_sim1030_Timer_Handle, xdc_UInt32);
    xdc_UInt32 (*getPeriod)(ti_sysbios_family_arm_sim1030_Timer_Handle);
    xdc_UInt32 (*getCount)(ti_sysbios_family_arm_sim1030_Timer_Handle);
    xdc_Void (*getFreq)(ti_sysbios_family_arm_sim1030_Timer_Handle, xdc_runtime_Types_FreqHz*);
    ti_sysbios_interfaces_ITimer_FuncPtr (*getFunc)(ti_sysbios_family_arm_sim1030_Timer_Handle, xdc_UArg*);
    xdc_Void (*setFunc)(ti_sysbios_family_arm_sim1030_Timer_Handle, ti_sysbios_interfaces_ITimer_FuncPtr, xdc_UArg);
    xdc_Void (*trigger)(ti_sysbios_family_arm_sim1030_Timer_Handle, xdc_UInt32);
    xdc_UInt32 (*getExpiredCounts)(ti_sysbios_family_arm_sim1030_Timer_Handle);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_family_arm_sim1030_Timer_Fxns__ ti_sysbios_family_arm_sim1030_Timer_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_sim1030_Timer_Module_startup( state ) -1

/* Instance_init__F */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Instance_init__F, "ti_sysbios_family_arm_sim1030_Timer_Instance_init")
__extern void ti_sysbios_family_arm_sim1030_Timer_Instance_init__F( ti_sysbios_family_arm_sim1030_Timer_Object*, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_family_arm_sim1030_Timer_Params* );

/* Instance_init__R */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Instance_init__R, "ti_sysbios_family_arm_sim1030_Timer_Instance_init")
__extern void ti_sysbios_family_arm_sim1030_Timer_Instance_init__R( ti_sysbios_family_arm_sim1030_Timer_Object*, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_family_arm_sim1030_Timer_Params* );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Handle__label__S, "ti_sysbios_family_arm_sim1030_Timer_Handle__label")
__extern xdc_runtime_Types_Label* ti_sysbios_family_arm_sim1030_Timer_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Module__startupDone__S, "ti_sysbios_family_arm_sim1030_Timer_Module__startupDone")
__extern xdc_Bool ti_sysbios_family_arm_sim1030_Timer_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Object__create__S, "ti_sysbios_family_arm_sim1030_Timer_Object__create")
__extern xdc_Ptr ti_sysbios_family_arm_sim1030_Timer_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar* __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Object__delete__S, "ti_sysbios_family_arm_sim1030_Timer_Object__delete")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Object__destruct__S, "ti_sysbios_family_arm_sim1030_Timer_Object__destruct")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Object__get__S, "ti_sysbios_family_arm_sim1030_Timer_Object__get")
__extern xdc_Ptr ti_sysbios_family_arm_sim1030_Timer_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Object__first__S, "ti_sysbios_family_arm_sim1030_Timer_Object__first")
__extern xdc_Ptr ti_sysbios_family_arm_sim1030_Timer_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Object__next__S, "ti_sysbios_family_arm_sim1030_Timer_Object__next")
__extern xdc_Ptr ti_sysbios_family_arm_sim1030_Timer_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_Params__init__S, "ti_sysbios_family_arm_sim1030_Timer_Params__init")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz );

/* getNumTimers__E */
#define ti_sysbios_family_arm_sim1030_Timer_getNumTimers ti_sysbios_family_arm_sim1030_Timer_getNumTimers__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getNumTimers__E, "ti_sysbios_family_arm_sim1030_Timer_getNumTimers")
__extern xdc_UInt ti_sysbios_family_arm_sim1030_Timer_getNumTimers__E( void );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getNumTimers__F, "ti_sysbios_family_arm_sim1030_Timer_getNumTimers")
__extern xdc_UInt ti_sysbios_family_arm_sim1030_Timer_getNumTimers__F( void );
__extern xdc_UInt ti_sysbios_family_arm_sim1030_Timer_getNumTimers__R( void );

/* getStatus__E */
#define ti_sysbios_family_arm_sim1030_Timer_getStatus ti_sysbios_family_arm_sim1030_Timer_getStatus__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getStatus__E, "ti_sysbios_family_arm_sim1030_Timer_getStatus")
__extern ti_sysbios_interfaces_ITimer_Status ti_sysbios_family_arm_sim1030_Timer_getStatus__E( xdc_UInt id );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getStatus__F, "ti_sysbios_family_arm_sim1030_Timer_getStatus")
__extern ti_sysbios_interfaces_ITimer_Status ti_sysbios_family_arm_sim1030_Timer_getStatus__F( xdc_UInt id );
__extern ti_sysbios_interfaces_ITimer_Status ti_sysbios_family_arm_sim1030_Timer_getStatus__R( xdc_UInt id );

/* startup__E */
#define ti_sysbios_family_arm_sim1030_Timer_startup ti_sysbios_family_arm_sim1030_Timer_startup__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_startup__E, "ti_sysbios_family_arm_sim1030_Timer_startup")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_startup__E( void );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_startup__F, "ti_sysbios_family_arm_sim1030_Timer_startup")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_startup__F( void );
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_startup__R( void );

/* getMaxTicks__E */
#define ti_sysbios_family_arm_sim1030_Timer_getMaxTicks ti_sysbios_family_arm_sim1030_Timer_getMaxTicks__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getMaxTicks__E, "ti_sysbios_family_arm_sim1030_Timer_getMaxTicks")
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getMaxTicks__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 periodCounts );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getMaxTicks__F, "ti_sysbios_family_arm_sim1030_Timer_getMaxTicks")
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getMaxTicks__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst, xdc_UInt32 periodCounts );
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getMaxTicks__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 periodCounts );

/* setNextTick__E */
#define ti_sysbios_family_arm_sim1030_Timer_setNextTick ti_sysbios_family_arm_sim1030_Timer_setNextTick__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_setNextTick__E, "ti_sysbios_family_arm_sim1030_Timer_setNextTick")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setNextTick__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 newPeriod, xdc_UInt32 countsPerTick );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_setNextTick__F, "ti_sysbios_family_arm_sim1030_Timer_setNextTick")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setNextTick__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst, xdc_UInt32 newPeriod, xdc_UInt32 countsPerTick );
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setNextTick__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 newPeriod, xdc_UInt32 countsPerTick );

/* start__E */
#define ti_sysbios_family_arm_sim1030_Timer_start ti_sysbios_family_arm_sim1030_Timer_start__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_start__E, "ti_sysbios_family_arm_sim1030_Timer_start")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_start__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_start__F, "ti_sysbios_family_arm_sim1030_Timer_start")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_start__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst );
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_start__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );

/* stop__E */
#define ti_sysbios_family_arm_sim1030_Timer_stop ti_sysbios_family_arm_sim1030_Timer_stop__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_stop__E, "ti_sysbios_family_arm_sim1030_Timer_stop")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_stop__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_stop__F, "ti_sysbios_family_arm_sim1030_Timer_stop")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_stop__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst );
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_stop__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );

/* setPeriod__E */
#define ti_sysbios_family_arm_sim1030_Timer_setPeriod ti_sysbios_family_arm_sim1030_Timer_setPeriod__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_setPeriod__E, "ti_sysbios_family_arm_sim1030_Timer_setPeriod")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setPeriod__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 period );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_setPeriod__F, "ti_sysbios_family_arm_sim1030_Timer_setPeriod")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setPeriod__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst, xdc_UInt32 period );
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setPeriod__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 period );

/* setPeriodMicroSecs__E */
#define ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs__E, "ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs")
__extern xdc_Bool ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 microsecs );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs__F, "ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs")
__extern xdc_Bool ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst, xdc_UInt32 microsecs );
__extern xdc_Bool ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 microsecs );

/* getPeriod__E */
#define ti_sysbios_family_arm_sim1030_Timer_getPeriod ti_sysbios_family_arm_sim1030_Timer_getPeriod__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getPeriod__E, "ti_sysbios_family_arm_sim1030_Timer_getPeriod")
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getPeriod__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getPeriod__F, "ti_sysbios_family_arm_sim1030_Timer_getPeriod")
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getPeriod__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst );
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getPeriod__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );

/* getCount__E */
#define ti_sysbios_family_arm_sim1030_Timer_getCount ti_sysbios_family_arm_sim1030_Timer_getCount__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getCount__E, "ti_sysbios_family_arm_sim1030_Timer_getCount")
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getCount__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getCount__F, "ti_sysbios_family_arm_sim1030_Timer_getCount")
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getCount__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst );
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getCount__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );

/* getFreq__E */
#define ti_sysbios_family_arm_sim1030_Timer_getFreq ti_sysbios_family_arm_sim1030_Timer_getFreq__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getFreq__E, "ti_sysbios_family_arm_sim1030_Timer_getFreq")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_getFreq__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_runtime_Types_FreqHz* freq );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getFreq__F, "ti_sysbios_family_arm_sim1030_Timer_getFreq")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_getFreq__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst, xdc_runtime_Types_FreqHz* freq );
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_getFreq__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_runtime_Types_FreqHz* freq );

/* getFunc__E */
#define ti_sysbios_family_arm_sim1030_Timer_getFunc ti_sysbios_family_arm_sim1030_Timer_getFunc__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getFunc__E, "ti_sysbios_family_arm_sim1030_Timer_getFunc")
__extern ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_family_arm_sim1030_Timer_getFunc__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UArg* arg );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getFunc__F, "ti_sysbios_family_arm_sim1030_Timer_getFunc")
__extern ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_family_arm_sim1030_Timer_getFunc__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst, xdc_UArg* arg );
__extern ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_family_arm_sim1030_Timer_getFunc__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UArg* arg );

/* setFunc__E */
#define ti_sysbios_family_arm_sim1030_Timer_setFunc ti_sysbios_family_arm_sim1030_Timer_setFunc__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_setFunc__E, "ti_sysbios_family_arm_sim1030_Timer_setFunc")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setFunc__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_setFunc__F, "ti_sysbios_family_arm_sim1030_Timer_setFunc")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setFunc__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg );
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_setFunc__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg );

/* trigger__E */
#define ti_sysbios_family_arm_sim1030_Timer_trigger ti_sysbios_family_arm_sim1030_Timer_trigger__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_trigger__E, "ti_sysbios_family_arm_sim1030_Timer_trigger")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_trigger__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 cycles );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_trigger__F, "ti_sysbios_family_arm_sim1030_Timer_trigger")
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_trigger__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst, xdc_UInt32 cycles );
__extern xdc_Void ti_sysbios_family_arm_sim1030_Timer_trigger__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst, xdc_UInt32 cycles );

/* getExpiredCounts__E */
#define ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts__E
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts__E, "ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts")
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts__E( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );
xdc__CODESECT(ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts__F, "ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts")
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts__F( ti_sysbios_family_arm_sim1030_Timer_Object* __inst );
__extern xdc_UInt32 ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts__R( ti_sysbios_family_arm_sim1030_Timer_Handle __inst );


/*
 * ======== FUNCTION SELECTORS ========
 */

/* getMaxTicks_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_family_arm_sim1030_Timer_getMaxTicks_FxnT)(void*, xdc_UInt32);
static inline ti_sysbios_family_arm_sim1030_Timer_getMaxTicks_FxnT ti_sysbios_family_arm_sim1030_Timer_getMaxTicks_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_getMaxTicks_FxnT)ti_sysbios_family_arm_sim1030_Timer_getMaxTicks; 
}

/* setNextTick_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_sim1030_Timer_setNextTick_FxnT)(void*, xdc_UInt32, xdc_UInt32);
static inline ti_sysbios_family_arm_sim1030_Timer_setNextTick_FxnT ti_sysbios_family_arm_sim1030_Timer_setNextTick_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_setNextTick_FxnT)ti_sysbios_family_arm_sim1030_Timer_setNextTick; 
}

/* start_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_sim1030_Timer_start_FxnT)(void*);
static inline ti_sysbios_family_arm_sim1030_Timer_start_FxnT ti_sysbios_family_arm_sim1030_Timer_start_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_start_FxnT)ti_sysbios_family_arm_sim1030_Timer_start; 
}

/* stop_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_sim1030_Timer_stop_FxnT)(void*);
static inline ti_sysbios_family_arm_sim1030_Timer_stop_FxnT ti_sysbios_family_arm_sim1030_Timer_stop_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_stop_FxnT)ti_sysbios_family_arm_sim1030_Timer_stop; 
}

/* setPeriod_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_sim1030_Timer_setPeriod_FxnT)(void*, xdc_UInt32);
static inline ti_sysbios_family_arm_sim1030_Timer_setPeriod_FxnT ti_sysbios_family_arm_sim1030_Timer_setPeriod_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_setPeriod_FxnT)ti_sysbios_family_arm_sim1030_Timer_setPeriod; 
}

/* setPeriodMicroSecs_{FxnT,fxnP} */
typedef xdc_Bool (*ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs_FxnT)(void*, xdc_UInt32);
static inline ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs_FxnT ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs_FxnT)ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs; 
}

/* getPeriod_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_family_arm_sim1030_Timer_getPeriod_FxnT)(void*);
static inline ti_sysbios_family_arm_sim1030_Timer_getPeriod_FxnT ti_sysbios_family_arm_sim1030_Timer_getPeriod_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_getPeriod_FxnT)ti_sysbios_family_arm_sim1030_Timer_getPeriod; 
}

/* getCount_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_family_arm_sim1030_Timer_getCount_FxnT)(void*);
static inline ti_sysbios_family_arm_sim1030_Timer_getCount_FxnT ti_sysbios_family_arm_sim1030_Timer_getCount_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_getCount_FxnT)ti_sysbios_family_arm_sim1030_Timer_getCount; 
}

/* getFreq_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_sim1030_Timer_getFreq_FxnT)(void*, xdc_runtime_Types_FreqHz*);
static inline ti_sysbios_family_arm_sim1030_Timer_getFreq_FxnT ti_sysbios_family_arm_sim1030_Timer_getFreq_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_getFreq_FxnT)ti_sysbios_family_arm_sim1030_Timer_getFreq; 
}

/* getFunc_{FxnT,fxnP} */
typedef ti_sysbios_interfaces_ITimer_FuncPtr (*ti_sysbios_family_arm_sim1030_Timer_getFunc_FxnT)(void*, xdc_UArg*);
static inline ti_sysbios_family_arm_sim1030_Timer_getFunc_FxnT ti_sysbios_family_arm_sim1030_Timer_getFunc_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_getFunc_FxnT)ti_sysbios_family_arm_sim1030_Timer_getFunc; 
}

/* setFunc_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_sim1030_Timer_setFunc_FxnT)(void*, ti_sysbios_interfaces_ITimer_FuncPtr, xdc_UArg);
static inline ti_sysbios_family_arm_sim1030_Timer_setFunc_FxnT ti_sysbios_family_arm_sim1030_Timer_setFunc_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_setFunc_FxnT)ti_sysbios_family_arm_sim1030_Timer_setFunc; 
}

/* trigger_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_sim1030_Timer_trigger_FxnT)(void*, xdc_UInt32);
static inline ti_sysbios_family_arm_sim1030_Timer_trigger_FxnT ti_sysbios_family_arm_sim1030_Timer_trigger_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_trigger_FxnT)ti_sysbios_family_arm_sim1030_Timer_trigger; 
}

/* getExpiredCounts_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts_FxnT)(void*);
static inline ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts_FxnT ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts_fxnP( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts_FxnT)ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts; 
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_ITimer_Module ti_sysbios_family_arm_sim1030_Timer_Module_upCast( void )
{
    return (ti_sysbios_interfaces_ITimer_Module)&ti_sysbios_family_arm_sim1030_Timer_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_ITimer */
#define ti_sysbios_family_arm_sim1030_Timer_Module_to_ti_sysbios_interfaces_ITimer ti_sysbios_family_arm_sim1030_Timer_Module_upCast

/* Handle_upCast */
static inline ti_sysbios_interfaces_ITimer_Handle ti_sysbios_family_arm_sim1030_Timer_Handle_upCast( ti_sysbios_family_arm_sim1030_Timer_Handle i )
{
    return (ti_sysbios_interfaces_ITimer_Handle)i;
}

/* Handle_to_ti_sysbios_interfaces_ITimer */
#define ti_sysbios_family_arm_sim1030_Timer_Handle_to_ti_sysbios_interfaces_ITimer ti_sysbios_family_arm_sim1030_Timer_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_family_arm_sim1030_Timer_Handle ti_sysbios_family_arm_sim1030_Timer_Handle_downCast( ti_sysbios_interfaces_ITimer_Handle i )
{
    ti_sysbios_interfaces_ITimer_Handle i2 = (ti_sysbios_interfaces_ITimer_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_family_arm_sim1030_Timer_Module__FXNS__C ? (ti_sysbios_family_arm_sim1030_Timer_Handle)i : 0;
}

/* Handle_from_ti_sysbios_interfaces_ITimer */
#define ti_sysbios_family_arm_sim1030_Timer_Handle_from_ti_sysbios_interfaces_ITimer ti_sysbios_family_arm_sim1030_Timer_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_sim1030_Timer_Module_startupDone() ti_sysbios_family_arm_sim1030_Timer_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_sim1030_Timer_Object_heap() ti_sysbios_family_arm_sim1030_Timer_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_sim1030_Timer_Module_heap() ti_sysbios_family_arm_sim1030_Timer_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_sim1030_Timer_Module__id ti_sysbios_family_arm_sim1030_Timer_Module_id( void ) 
{
    return ti_sysbios_family_arm_sim1030_Timer_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_sim1030_Timer_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_sim1030_Timer_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_sim1030_Timer_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_sim1030_Timer_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_sim1030_Timer_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_sim1030_Timer_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_sim1030_Timer_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_sim1030_Timer_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_family_arm_sim1030_Timer_Params_init( ti_sysbios_family_arm_sim1030_Timer_Params* prms ) 
{
    if (prms) {
        ti_sysbios_family_arm_sim1030_Timer_Params__init__S(prms, 0, sizeof(ti_sysbios_family_arm_sim1030_Timer_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_family_arm_sim1030_Timer_Params_copy( ti_sysbios_family_arm_sim1030_Timer_Params* dst, const ti_sysbios_family_arm_sim1030_Timer_Params* src ) 
{
    if (dst) {
        ti_sysbios_family_arm_sim1030_Timer_Params__init__S(dst, (xdc_Ptr)src, sizeof(ti_sysbios_family_arm_sim1030_Timer_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_family_arm_sim1030_Timer_Object_count() ti_sysbios_family_arm_sim1030_Timer_Object__count__C

/* Object_sizeof */
#define ti_sysbios_family_arm_sim1030_Timer_Object_sizeof() ti_sysbios_family_arm_sim1030_Timer_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_family_arm_sim1030_Timer_Handle ti_sysbios_family_arm_sim1030_Timer_Object_get( ti_sysbios_family_arm_sim1030_Timer_Instance_State* oarr, int i ) 
{
    return (ti_sysbios_family_arm_sim1030_Timer_Handle)ti_sysbios_family_arm_sim1030_Timer_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_family_arm_sim1030_Timer_Handle ti_sysbios_family_arm_sim1030_Timer_Object_first( void )
{
    return (ti_sysbios_family_arm_sim1030_Timer_Handle)ti_sysbios_family_arm_sim1030_Timer_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_family_arm_sim1030_Timer_Handle ti_sysbios_family_arm_sim1030_Timer_Object_next( ti_sysbios_family_arm_sim1030_Timer_Object* obj )
{
    return (ti_sysbios_family_arm_sim1030_Timer_Handle)ti_sysbios_family_arm_sim1030_Timer_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label* ti_sysbios_family_arm_sim1030_Timer_Handle_label( ti_sysbios_family_arm_sim1030_Timer_Handle inst, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_family_arm_sim1030_Timer_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline String ti_sysbios_family_arm_sim1030_Timer_Handle_name( ti_sysbios_family_arm_sim1030_Timer_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_family_arm_sim1030_Timer_Handle__label__S(inst, &lab)->iname;
}

/* create */
static inline ti_sysbios_family_arm_sim1030_Timer_Handle ti_sysbios_family_arm_sim1030_Timer_create( xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_family_arm_sim1030_Timer_Params* __prms, xdc_runtime_Error_Block* __eb )
{
    ti_sysbios_family_arm_sim1030_Timer_Args__create __args;
    __args.id = id;
    __args.tickFxn = tickFxn;
    return (ti_sysbios_family_arm_sim1030_Timer_Handle)ti_sysbios_family_arm_sim1030_Timer_Object__create__S(0, 0, &__args, (const xdc_UChar*)__prms, sizeof(ti_sysbios_family_arm_sim1030_Timer_Params), __eb);
}

/* construct */
static inline void ti_sysbios_family_arm_sim1030_Timer_construct( ti_sysbios_family_arm_sim1030_Timer_Struct* __obj, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_family_arm_sim1030_Timer_Params* __prms )
{
    ti_sysbios_family_arm_sim1030_Timer_Args__create __args;
    __args.id = id;
    __args.tickFxn = tickFxn;
    ti_sysbios_family_arm_sim1030_Timer_Object__create__S(__obj, sizeof (ti_sysbios_family_arm_sim1030_Timer_Struct), &__args, (const xdc_UChar*)__prms, sizeof(ti_sysbios_family_arm_sim1030_Timer_Params), NULL);
}

/* delete */
static inline void ti_sysbios_family_arm_sim1030_Timer_delete( ti_sysbios_family_arm_sim1030_Timer_Handle* instp )
{
    ti_sysbios_family_arm_sim1030_Timer_Object__delete__S(instp);
}

/* destruct */
static inline void ti_sysbios_family_arm_sim1030_Timer_destruct( ti_sysbios_family_arm_sim1030_Timer_Struct* obj )
{
    ti_sysbios_family_arm_sim1030_Timer_Object__destruct__S(obj);
}

/* handle */
static inline ti_sysbios_family_arm_sim1030_Timer_Handle ti_sysbios_family_arm_sim1030_Timer_handle( ti_sysbios_family_arm_sim1030_Timer_Struct* str )
{
    return (ti_sysbios_family_arm_sim1030_Timer_Handle)str;
}

/* struct */
static inline ti_sysbios_family_arm_sim1030_Timer_Struct* ti_sysbios_family_arm_sim1030_Timer_struct( ti_sysbios_family_arm_sim1030_Timer_Handle inst )
{
    return (ti_sysbios_family_arm_sim1030_Timer_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_sim1030_Timer__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_sim1030_Timer__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_sim1030_Timer__internalaccess))

#ifndef ti_sysbios_family_arm_sim1030_Timer__include_state
#define ti_sysbios_family_arm_sim1030_Timer__include_state

/* Object */
struct ti_sysbios_family_arm_sim1030_Timer_Object {
    const ti_sysbios_family_arm_sim1030_Timer_Fxns__* __fxns;
};

#endif /* ti_sysbios_family_arm_sim1030_Timer__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_sim1030_Timer__nolocalnames)

#ifndef ti_sysbios_family_arm_sim1030_Timer__localnames__done
#define ti_sysbios_family_arm_sim1030_Timer__localnames__done

/* module prefix */
#define Timer_Instance ti_sysbios_family_arm_sim1030_Timer_Instance
#define Timer_Handle ti_sysbios_family_arm_sim1030_Timer_Handle
#define Timer_Module ti_sysbios_family_arm_sim1030_Timer_Module
#define Timer_Object ti_sysbios_family_arm_sim1030_Timer_Object
#define Timer_Struct ti_sysbios_family_arm_sim1030_Timer_Struct
#define Timer_FuncPtr ti_sysbios_family_arm_sim1030_Timer_FuncPtr
#define Timer_ANY ti_sysbios_family_arm_sim1030_Timer_ANY
#define Timer_StartMode ti_sysbios_family_arm_sim1030_Timer_StartMode
#define Timer_RunMode ti_sysbios_family_arm_sim1030_Timer_RunMode
#define Timer_Status ti_sysbios_family_arm_sim1030_Timer_Status
#define Timer_PeriodType ti_sysbios_family_arm_sim1030_Timer_PeriodType
#define Timer_Instance_State ti_sysbios_family_arm_sim1030_Timer_Instance_State
#define Timer_StartMode_AUTO ti_sysbios_family_arm_sim1030_Timer_StartMode_AUTO
#define Timer_StartMode_USER ti_sysbios_family_arm_sim1030_Timer_StartMode_USER
#define Timer_RunMode_CONTINUOUS ti_sysbios_family_arm_sim1030_Timer_RunMode_CONTINUOUS
#define Timer_RunMode_ONESHOT ti_sysbios_family_arm_sim1030_Timer_RunMode_ONESHOT
#define Timer_RunMode_DYNAMIC ti_sysbios_family_arm_sim1030_Timer_RunMode_DYNAMIC
#define Timer_Status_INUSE ti_sysbios_family_arm_sim1030_Timer_Status_INUSE
#define Timer_Status_FREE ti_sysbios_family_arm_sim1030_Timer_Status_FREE
#define Timer_PeriodType_MICROSECS ti_sysbios_family_arm_sim1030_Timer_PeriodType_MICROSECS
#define Timer_PeriodType_COUNTS ti_sysbios_family_arm_sim1030_Timer_PeriodType_COUNTS
#define Timer_Params ti_sysbios_family_arm_sim1030_Timer_Params
#define Timer_getNumTimers ti_sysbios_family_arm_sim1030_Timer_getNumTimers
#define Timer_getStatus ti_sysbios_family_arm_sim1030_Timer_getStatus
#define Timer_startup ti_sysbios_family_arm_sim1030_Timer_startup
#define Timer_getMaxTicks ti_sysbios_family_arm_sim1030_Timer_getMaxTicks
#define Timer_getMaxTicks_fxnP ti_sysbios_family_arm_sim1030_Timer_getMaxTicks_fxnP
#define Timer_getMaxTicks_FxnT ti_sysbios_family_arm_sim1030_Timer_getMaxTicks_FxnT
#define Timer_setNextTick ti_sysbios_family_arm_sim1030_Timer_setNextTick
#define Timer_setNextTick_fxnP ti_sysbios_family_arm_sim1030_Timer_setNextTick_fxnP
#define Timer_setNextTick_FxnT ti_sysbios_family_arm_sim1030_Timer_setNextTick_FxnT
#define Timer_start ti_sysbios_family_arm_sim1030_Timer_start
#define Timer_start_fxnP ti_sysbios_family_arm_sim1030_Timer_start_fxnP
#define Timer_start_FxnT ti_sysbios_family_arm_sim1030_Timer_start_FxnT
#define Timer_stop ti_sysbios_family_arm_sim1030_Timer_stop
#define Timer_stop_fxnP ti_sysbios_family_arm_sim1030_Timer_stop_fxnP
#define Timer_stop_FxnT ti_sysbios_family_arm_sim1030_Timer_stop_FxnT
#define Timer_setPeriod ti_sysbios_family_arm_sim1030_Timer_setPeriod
#define Timer_setPeriod_fxnP ti_sysbios_family_arm_sim1030_Timer_setPeriod_fxnP
#define Timer_setPeriod_FxnT ti_sysbios_family_arm_sim1030_Timer_setPeriod_FxnT
#define Timer_setPeriodMicroSecs ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs
#define Timer_setPeriodMicroSecs_fxnP ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs_fxnP
#define Timer_setPeriodMicroSecs_FxnT ti_sysbios_family_arm_sim1030_Timer_setPeriodMicroSecs_FxnT
#define Timer_getPeriod ti_sysbios_family_arm_sim1030_Timer_getPeriod
#define Timer_getPeriod_fxnP ti_sysbios_family_arm_sim1030_Timer_getPeriod_fxnP
#define Timer_getPeriod_FxnT ti_sysbios_family_arm_sim1030_Timer_getPeriod_FxnT
#define Timer_getCount ti_sysbios_family_arm_sim1030_Timer_getCount
#define Timer_getCount_fxnP ti_sysbios_family_arm_sim1030_Timer_getCount_fxnP
#define Timer_getCount_FxnT ti_sysbios_family_arm_sim1030_Timer_getCount_FxnT
#define Timer_getFreq ti_sysbios_family_arm_sim1030_Timer_getFreq
#define Timer_getFreq_fxnP ti_sysbios_family_arm_sim1030_Timer_getFreq_fxnP
#define Timer_getFreq_FxnT ti_sysbios_family_arm_sim1030_Timer_getFreq_FxnT
#define Timer_getFunc ti_sysbios_family_arm_sim1030_Timer_getFunc
#define Timer_getFunc_fxnP ti_sysbios_family_arm_sim1030_Timer_getFunc_fxnP
#define Timer_getFunc_FxnT ti_sysbios_family_arm_sim1030_Timer_getFunc_FxnT
#define Timer_setFunc ti_sysbios_family_arm_sim1030_Timer_setFunc
#define Timer_setFunc_fxnP ti_sysbios_family_arm_sim1030_Timer_setFunc_fxnP
#define Timer_setFunc_FxnT ti_sysbios_family_arm_sim1030_Timer_setFunc_FxnT
#define Timer_trigger ti_sysbios_family_arm_sim1030_Timer_trigger
#define Timer_trigger_fxnP ti_sysbios_family_arm_sim1030_Timer_trigger_fxnP
#define Timer_trigger_FxnT ti_sysbios_family_arm_sim1030_Timer_trigger_FxnT
#define Timer_getExpiredCounts ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts
#define Timer_getExpiredCounts_fxnP ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts_fxnP
#define Timer_getExpiredCounts_FxnT ti_sysbios_family_arm_sim1030_Timer_getExpiredCounts_FxnT
#define Timer_Module_name ti_sysbios_family_arm_sim1030_Timer_Module_name
#define Timer_Module_id ti_sysbios_family_arm_sim1030_Timer_Module_id
#define Timer_Module_startup ti_sysbios_family_arm_sim1030_Timer_Module_startup
#define Timer_Module_startupDone ti_sysbios_family_arm_sim1030_Timer_Module_startupDone
#define Timer_Module_hasMask ti_sysbios_family_arm_sim1030_Timer_Module_hasMask
#define Timer_Module_getMask ti_sysbios_family_arm_sim1030_Timer_Module_getMask
#define Timer_Module_setMask ti_sysbios_family_arm_sim1030_Timer_Module_setMask
#define Timer_Object_heap ti_sysbios_family_arm_sim1030_Timer_Object_heap
#define Timer_Module_heap ti_sysbios_family_arm_sim1030_Timer_Module_heap
#define Timer_construct ti_sysbios_family_arm_sim1030_Timer_construct
#define Timer_create ti_sysbios_family_arm_sim1030_Timer_create
#define Timer_handle ti_sysbios_family_arm_sim1030_Timer_handle
#define Timer_struct ti_sysbios_family_arm_sim1030_Timer_struct
#define Timer_Handle_label ti_sysbios_family_arm_sim1030_Timer_Handle_label
#define Timer_Handle_name ti_sysbios_family_arm_sim1030_Timer_Handle_name
#define Timer_Instance_init ti_sysbios_family_arm_sim1030_Timer_Instance_init
#define Timer_Object_count ti_sysbios_family_arm_sim1030_Timer_Object_count
#define Timer_Object_get ti_sysbios_family_arm_sim1030_Timer_Object_get
#define Timer_Object_first ti_sysbios_family_arm_sim1030_Timer_Object_first
#define Timer_Object_next ti_sysbios_family_arm_sim1030_Timer_Object_next
#define Timer_Object_sizeof ti_sysbios_family_arm_sim1030_Timer_Object_sizeof
#define Timer_Params_copy ti_sysbios_family_arm_sim1030_Timer_Params_copy
#define Timer_Params_init ti_sysbios_family_arm_sim1030_Timer_Params_init
#define Timer_delete ti_sysbios_family_arm_sim1030_Timer_delete
#define Timer_destruct ti_sysbios_family_arm_sim1030_Timer_destruct
#define Timer_Module_upCast ti_sysbios_family_arm_sim1030_Timer_Module_upCast
#define Timer_Module_to_ti_sysbios_interfaces_ITimer ti_sysbios_family_arm_sim1030_Timer_Module_to_ti_sysbios_interfaces_ITimer
#define Timer_Handle_upCast ti_sysbios_family_arm_sim1030_Timer_Handle_upCast
#define Timer_Handle_to_ti_sysbios_interfaces_ITimer ti_sysbios_family_arm_sim1030_Timer_Handle_to_ti_sysbios_interfaces_ITimer
#define Timer_Handle_downCast ti_sysbios_family_arm_sim1030_Timer_Handle_downCast
#define Timer_Handle_from_ti_sysbios_interfaces_ITimer ti_sysbios_family_arm_sim1030_Timer_Handle_from_ti_sysbios_interfaces_ITimer

#endif /* ti_sysbios_family_arm_sim1030_Timer__localnames__done */
#endif
/*
 *  @(#) ti.sysbios.family.arm.sim1030; 2, 0, 0, 0,296; 5-18-2012 06:04:31; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

