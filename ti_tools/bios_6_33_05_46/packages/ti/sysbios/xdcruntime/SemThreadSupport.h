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

#ifndef ti_sysbios_xdcruntime_SemThreadSupport__include
#define ti_sysbios_xdcruntime_SemThreadSupport__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_xdcruntime_SemThreadSupport__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_xdcruntime_SemThreadSupport___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/xdcruntime/package/package.defs.h>

#include <xdc/runtime/knl/ISemThreadSupport.h>
#include <ti/sysbios/knl/Semaphore.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* PendStatus */
typedef xdc_runtime_knl_ISemaphore_PendStatus ti_sysbios_xdcruntime_SemThreadSupport_PendStatus;

/* FOREVER */
#define ti_sysbios_xdcruntime_SemThreadSupport_FOREVER (~(0))

/* Mode */
typedef xdc_runtime_knl_ISemaphore_Mode ti_sysbios_xdcruntime_SemThreadSupport_Mode;

/* PendStatus_ERROR */
#define ti_sysbios_xdcruntime_SemThreadSupport_PendStatus_ERROR xdc_runtime_knl_ISemaphore_PendStatus_ERROR

/* PendStatus_TIMEOUT */
#define ti_sysbios_xdcruntime_SemThreadSupport_PendStatus_TIMEOUT xdc_runtime_knl_ISemaphore_PendStatus_TIMEOUT

/* PendStatus_SUCCESS */
#define ti_sysbios_xdcruntime_SemThreadSupport_PendStatus_SUCCESS xdc_runtime_knl_ISemaphore_PendStatus_SUCCESS

/* Mode_COUNTING */
#define ti_sysbios_xdcruntime_SemThreadSupport_Mode_COUNTING xdc_runtime_knl_ISemaphore_Mode_COUNTING

/* Mode_BINARY */
#define ti_sysbios_xdcruntime_SemThreadSupport_Mode_BINARY xdc_runtime_knl_ISemaphore_Mode_BINARY


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_xdcruntime_SemThreadSupport_Args__create {
    xdc_Int count;
} ti_sysbios_xdcruntime_SemThreadSupport_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsEnabled ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsIncluded ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsMask ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__gateObj ti_sysbios_xdcruntime_SemThreadSupport_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__gatePrms ti_sysbios_xdcruntime_SemThreadSupport_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__id;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__id ti_sysbios_xdcruntime_SemThreadSupport_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerDefined ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerObj ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn0 ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn1 ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn2 ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn4 ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn8 ti_sysbios_xdcruntime_SemThreadSupport_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__startupDoneFxn ti_sysbios_xdcruntime_SemThreadSupport_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_xdcruntime_SemThreadSupport_Object__count;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Object__count ti_sysbios_xdcruntime_SemThreadSupport_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_xdcruntime_SemThreadSupport_Object__heap;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Object__heap ti_sysbios_xdcruntime_SemThreadSupport_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_xdcruntime_SemThreadSupport_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Object__sizeof ti_sysbios_xdcruntime_SemThreadSupport_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_xdcruntime_SemThreadSupport_Object__table;
__extern __FAR__ const CT__ti_sysbios_xdcruntime_SemThreadSupport_Object__table ti_sysbios_xdcruntime_SemThreadSupport_Object__table__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_xdcruntime_SemThreadSupport_Params {
    size_t __size;
    const void* __self;
    void* __fxns;
    xdc_runtime_IInstance_Params* instance;
    xdc_runtime_knl_ISemaphore_Mode mode;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_xdcruntime_SemThreadSupport_Struct {
    const ti_sysbios_xdcruntime_SemThreadSupport_Fxns__* __fxns;
    ti_sysbios_knl_Semaphore_Struct __f0;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_xdcruntime_SemThreadSupport_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Int (*pend)(ti_sysbios_xdcruntime_SemThreadSupport_Handle, xdc_UInt, xdc_runtime_Error_Block*);
    xdc_Bool (*post)(ti_sysbios_xdcruntime_SemThreadSupport_Handle, xdc_runtime_Error_Block*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_xdcruntime_SemThreadSupport_Fxns__ ti_sysbios_xdcruntime_SemThreadSupport_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_xdcruntime_SemThreadSupport_Module_startup( state ) -1

/* Instance_init__F */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Instance_init__F, "ti_sysbios_xdcruntime_SemThreadSupport_Instance_init")
__extern void ti_sysbios_xdcruntime_SemThreadSupport_Instance_init__F( ti_sysbios_xdcruntime_SemThreadSupport_Object*, xdc_Int count, const ti_sysbios_xdcruntime_SemThreadSupport_Params* );

/* Instance_finalize__F */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Instance_finalize__F, "ti_sysbios_xdcruntime_SemThreadSupport_Instance_finalize")
__extern void ti_sysbios_xdcruntime_SemThreadSupport_Instance_finalize__F( ti_sysbios_xdcruntime_SemThreadSupport_Object* );

/* Instance_init__R */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Instance_init__R, "ti_sysbios_xdcruntime_SemThreadSupport_Instance_init")
__extern void ti_sysbios_xdcruntime_SemThreadSupport_Instance_init__R( ti_sysbios_xdcruntime_SemThreadSupport_Object*, xdc_Int count, const ti_sysbios_xdcruntime_SemThreadSupport_Params* );

/* Instance_finalize__R */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Instance_finalize__R, "ti_sysbios_xdcruntime_SemThreadSupport_Instance_finalize")
__extern void ti_sysbios_xdcruntime_SemThreadSupport_Instance_finalize__R( ti_sysbios_xdcruntime_SemThreadSupport_Object* );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Handle__label__S, "ti_sysbios_xdcruntime_SemThreadSupport_Handle__label")
__extern xdc_runtime_Types_Label* ti_sysbios_xdcruntime_SemThreadSupport_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Module__startupDone__S, "ti_sysbios_xdcruntime_SemThreadSupport_Module__startupDone")
__extern xdc_Bool ti_sysbios_xdcruntime_SemThreadSupport_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Object__create__S, "ti_sysbios_xdcruntime_SemThreadSupport_Object__create")
__extern xdc_Ptr ti_sysbios_xdcruntime_SemThreadSupport_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar* __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Object__delete__S, "ti_sysbios_xdcruntime_SemThreadSupport_Object__delete")
__extern xdc_Void ti_sysbios_xdcruntime_SemThreadSupport_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Object__destruct__S, "ti_sysbios_xdcruntime_SemThreadSupport_Object__destruct")
__extern xdc_Void ti_sysbios_xdcruntime_SemThreadSupport_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Object__get__S, "ti_sysbios_xdcruntime_SemThreadSupport_Object__get")
__extern xdc_Ptr ti_sysbios_xdcruntime_SemThreadSupport_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Object__first__S, "ti_sysbios_xdcruntime_SemThreadSupport_Object__first")
__extern xdc_Ptr ti_sysbios_xdcruntime_SemThreadSupport_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Object__next__S, "ti_sysbios_xdcruntime_SemThreadSupport_Object__next")
__extern xdc_Ptr ti_sysbios_xdcruntime_SemThreadSupport_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_Params__init__S, "ti_sysbios_xdcruntime_SemThreadSupport_Params__init")
__extern xdc_Void ti_sysbios_xdcruntime_SemThreadSupport_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz );

/* pend__E */
#define ti_sysbios_xdcruntime_SemThreadSupport_pend ti_sysbios_xdcruntime_SemThreadSupport_pend__E
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_pend__E, "ti_sysbios_xdcruntime_SemThreadSupport_pend")
__extern xdc_Int ti_sysbios_xdcruntime_SemThreadSupport_pend__E( ti_sysbios_xdcruntime_SemThreadSupport_Handle __inst, xdc_UInt timeout, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_pend__F, "ti_sysbios_xdcruntime_SemThreadSupport_pend")
__extern xdc_Int ti_sysbios_xdcruntime_SemThreadSupport_pend__F( ti_sysbios_xdcruntime_SemThreadSupport_Object* __inst, xdc_UInt timeout, xdc_runtime_Error_Block* eb );
__extern xdc_Int ti_sysbios_xdcruntime_SemThreadSupport_pend__R( ti_sysbios_xdcruntime_SemThreadSupport_Handle __inst, xdc_UInt timeout, xdc_runtime_Error_Block* eb );

/* post__E */
#define ti_sysbios_xdcruntime_SemThreadSupport_post ti_sysbios_xdcruntime_SemThreadSupport_post__E
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_post__E, "ti_sysbios_xdcruntime_SemThreadSupport_post")
__extern xdc_Bool ti_sysbios_xdcruntime_SemThreadSupport_post__E( ti_sysbios_xdcruntime_SemThreadSupport_Handle __inst, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sysbios_xdcruntime_SemThreadSupport_post__F, "ti_sysbios_xdcruntime_SemThreadSupport_post")
__extern xdc_Bool ti_sysbios_xdcruntime_SemThreadSupport_post__F( ti_sysbios_xdcruntime_SemThreadSupport_Object* __inst, xdc_runtime_Error_Block* eb );
__extern xdc_Bool ti_sysbios_xdcruntime_SemThreadSupport_post__R( ti_sysbios_xdcruntime_SemThreadSupport_Handle __inst, xdc_runtime_Error_Block* eb );


/*
 * ======== FUNCTION SELECTORS ========
 */

/* pend_{FxnT,fxnP} */
typedef xdc_Int (*ti_sysbios_xdcruntime_SemThreadSupport_pend_FxnT)(void*, xdc_UInt, xdc_runtime_Error_Block*);
static inline ti_sysbios_xdcruntime_SemThreadSupport_pend_FxnT ti_sysbios_xdcruntime_SemThreadSupport_pend_fxnP( void )
{
    return (ti_sysbios_xdcruntime_SemThreadSupport_pend_FxnT)ti_sysbios_xdcruntime_SemThreadSupport_pend; 
}

/* post_{FxnT,fxnP} */
typedef xdc_Bool (*ti_sysbios_xdcruntime_SemThreadSupport_post_FxnT)(void*, xdc_runtime_Error_Block*);
static inline ti_sysbios_xdcruntime_SemThreadSupport_post_FxnT ti_sysbios_xdcruntime_SemThreadSupport_post_fxnP( void )
{
    return (ti_sysbios_xdcruntime_SemThreadSupport_post_FxnT)ti_sysbios_xdcruntime_SemThreadSupport_post; 
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_knl_ISemThreadSupport_Module ti_sysbios_xdcruntime_SemThreadSupport_Module_upCast( void )
{
    return (xdc_runtime_knl_ISemThreadSupport_Module)&ti_sysbios_xdcruntime_SemThreadSupport_Module__FXNS__C;
}

/* Module_to_xdc_runtime_knl_ISemThreadSupport */
#define ti_sysbios_xdcruntime_SemThreadSupport_Module_to_xdc_runtime_knl_ISemThreadSupport ti_sysbios_xdcruntime_SemThreadSupport_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_knl_ISemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_Handle_upCast( ti_sysbios_xdcruntime_SemThreadSupport_Handle i )
{
    return (xdc_runtime_knl_ISemThreadSupport_Handle)i;
}

/* Handle_to_xdc_runtime_knl_ISemThreadSupport */
#define ti_sysbios_xdcruntime_SemThreadSupport_Handle_to_xdc_runtime_knl_ISemThreadSupport ti_sysbios_xdcruntime_SemThreadSupport_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_xdcruntime_SemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_Handle_downCast( xdc_runtime_knl_ISemThreadSupport_Handle i )
{
    xdc_runtime_knl_ISemThreadSupport_Handle i2 = (xdc_runtime_knl_ISemThreadSupport_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_xdcruntime_SemThreadSupport_Module__FXNS__C ? (ti_sysbios_xdcruntime_SemThreadSupport_Handle)i : 0;
}

/* Handle_from_xdc_runtime_knl_ISemThreadSupport */
#define ti_sysbios_xdcruntime_SemThreadSupport_Handle_from_xdc_runtime_knl_ISemThreadSupport ti_sysbios_xdcruntime_SemThreadSupport_Handle_downCast

/* Module_upCast2 */
static inline xdc_runtime_knl_ISemaphore_Module ti_sysbios_xdcruntime_SemThreadSupport_Module_upCast2( void )
{
    return (xdc_runtime_knl_ISemaphore_Module)&ti_sysbios_xdcruntime_SemThreadSupport_Module__FXNS__C;
}

/* Module_to_xdc_runtime_knl_ISemaphore */
#define ti_sysbios_xdcruntime_SemThreadSupport_Module_to_xdc_runtime_knl_ISemaphore ti_sysbios_xdcruntime_SemThreadSupport_Module_upCast2

/* Handle_upCast2 */
static inline xdc_runtime_knl_ISemaphore_Handle ti_sysbios_xdcruntime_SemThreadSupport_Handle_upCast2( ti_sysbios_xdcruntime_SemThreadSupport_Handle i )
{
    return (xdc_runtime_knl_ISemaphore_Handle)i;
}

/* Handle_to_xdc_runtime_knl_ISemaphore */
#define ti_sysbios_xdcruntime_SemThreadSupport_Handle_to_xdc_runtime_knl_ISemaphore ti_sysbios_xdcruntime_SemThreadSupport_Handle_upCast2

/* Handle_downCast2 */
static inline ti_sysbios_xdcruntime_SemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_Handle_downCast2( xdc_runtime_knl_ISemaphore_Handle i )
{
    xdc_runtime_knl_ISemaphore_Handle i2 = (xdc_runtime_knl_ISemaphore_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_xdcruntime_SemThreadSupport_Module__FXNS__C ? (ti_sysbios_xdcruntime_SemThreadSupport_Handle)i : 0;
}

/* Handle_from_xdc_runtime_knl_ISemaphore */
#define ti_sysbios_xdcruntime_SemThreadSupport_Handle_from_xdc_runtime_knl_ISemaphore ti_sysbios_xdcruntime_SemThreadSupport_Handle_downCast2


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_xdcruntime_SemThreadSupport_Module_startupDone() ti_sysbios_xdcruntime_SemThreadSupport_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_xdcruntime_SemThreadSupport_Object_heap() ti_sysbios_xdcruntime_SemThreadSupport_Object__heap__C

/* Module_heap */
#define ti_sysbios_xdcruntime_SemThreadSupport_Module_heap() ti_sysbios_xdcruntime_SemThreadSupport_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_xdcruntime_SemThreadSupport_Module__id ti_sysbios_xdcruntime_SemThreadSupport_Module_id( void ) 
{
    return ti_sysbios_xdcruntime_SemThreadSupport_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_xdcruntime_SemThreadSupport_Module_hasMask( void ) 
{
    return ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_xdcruntime_SemThreadSupport_Module_getMask( void ) 
{
    return ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsMask__C != NULL ? *ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_xdcruntime_SemThreadSupport_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsMask__C != NULL) *ti_sysbios_xdcruntime_SemThreadSupport_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_xdcruntime_SemThreadSupport_Params_init( ti_sysbios_xdcruntime_SemThreadSupport_Params* prms ) 
{
    if (prms) {
        ti_sysbios_xdcruntime_SemThreadSupport_Params__init__S(prms, 0, sizeof(ti_sysbios_xdcruntime_SemThreadSupport_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_xdcruntime_SemThreadSupport_Params_copy( ti_sysbios_xdcruntime_SemThreadSupport_Params* dst, const ti_sysbios_xdcruntime_SemThreadSupport_Params* src ) 
{
    if (dst) {
        ti_sysbios_xdcruntime_SemThreadSupport_Params__init__S(dst, (xdc_Ptr)src, sizeof(ti_sysbios_xdcruntime_SemThreadSupport_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_xdcruntime_SemThreadSupport_Object_count() ti_sysbios_xdcruntime_SemThreadSupport_Object__count__C

/* Object_sizeof */
#define ti_sysbios_xdcruntime_SemThreadSupport_Object_sizeof() ti_sysbios_xdcruntime_SemThreadSupport_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_xdcruntime_SemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_Object_get( ti_sysbios_xdcruntime_SemThreadSupport_Instance_State* oarr, int i ) 
{
    return (ti_sysbios_xdcruntime_SemThreadSupport_Handle)ti_sysbios_xdcruntime_SemThreadSupport_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_xdcruntime_SemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_Object_first( void )
{
    return (ti_sysbios_xdcruntime_SemThreadSupport_Handle)ti_sysbios_xdcruntime_SemThreadSupport_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_xdcruntime_SemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_Object_next( ti_sysbios_xdcruntime_SemThreadSupport_Object* obj )
{
    return (ti_sysbios_xdcruntime_SemThreadSupport_Handle)ti_sysbios_xdcruntime_SemThreadSupport_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label* ti_sysbios_xdcruntime_SemThreadSupport_Handle_label( ti_sysbios_xdcruntime_SemThreadSupport_Handle inst, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_xdcruntime_SemThreadSupport_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline String ti_sysbios_xdcruntime_SemThreadSupport_Handle_name( ti_sysbios_xdcruntime_SemThreadSupport_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_xdcruntime_SemThreadSupport_Handle__label__S(inst, &lab)->iname;
}

/* create */
static inline ti_sysbios_xdcruntime_SemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_create( xdc_Int count, const ti_sysbios_xdcruntime_SemThreadSupport_Params* __prms, xdc_runtime_Error_Block* __eb )
{
    ti_sysbios_xdcruntime_SemThreadSupport_Args__create __args;
    __args.count = count;
    return (ti_sysbios_xdcruntime_SemThreadSupport_Handle)ti_sysbios_xdcruntime_SemThreadSupport_Object__create__S(0, 0, &__args, (const xdc_UChar*)__prms, sizeof(ti_sysbios_xdcruntime_SemThreadSupport_Params), __eb);
}

/* construct */
static inline void ti_sysbios_xdcruntime_SemThreadSupport_construct( ti_sysbios_xdcruntime_SemThreadSupport_Struct* __obj, xdc_Int count, const ti_sysbios_xdcruntime_SemThreadSupport_Params* __prms )
{
    ti_sysbios_xdcruntime_SemThreadSupport_Args__create __args;
    __args.count = count;
    ti_sysbios_xdcruntime_SemThreadSupport_Object__create__S(__obj, sizeof (ti_sysbios_xdcruntime_SemThreadSupport_Struct), &__args, (const xdc_UChar*)__prms, sizeof(ti_sysbios_xdcruntime_SemThreadSupport_Params), NULL);
}

/* delete */
static inline void ti_sysbios_xdcruntime_SemThreadSupport_delete( ti_sysbios_xdcruntime_SemThreadSupport_Handle* instp )
{
    ti_sysbios_xdcruntime_SemThreadSupport_Object__delete__S(instp);
}

/* destruct */
static inline void ti_sysbios_xdcruntime_SemThreadSupport_destruct( ti_sysbios_xdcruntime_SemThreadSupport_Struct* obj )
{
    ti_sysbios_xdcruntime_SemThreadSupport_Object__destruct__S(obj);
}

/* handle */
static inline ti_sysbios_xdcruntime_SemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_handle( ti_sysbios_xdcruntime_SemThreadSupport_Struct* str )
{
    return (ti_sysbios_xdcruntime_SemThreadSupport_Handle)str;
}

/* struct */
static inline ti_sysbios_xdcruntime_SemThreadSupport_Struct* ti_sysbios_xdcruntime_SemThreadSupport_struct( ti_sysbios_xdcruntime_SemThreadSupport_Handle inst )
{
    return (ti_sysbios_xdcruntime_SemThreadSupport_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_xdcruntime_SemThreadSupport__top__
#undef __nested__
#endif

#endif /* ti_sysbios_xdcruntime_SemThreadSupport__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_xdcruntime_SemThreadSupport__internalaccess))

#ifndef ti_sysbios_xdcruntime_SemThreadSupport__include_state
#define ti_sysbios_xdcruntime_SemThreadSupport__include_state

/* Object */
struct ti_sysbios_xdcruntime_SemThreadSupport_Object {
    const ti_sysbios_xdcruntime_SemThreadSupport_Fxns__* __fxns;
    char __dummy;
};

/* Instance_State_sem */
__extern __FAR__ const xdc_SizeT ti_sysbios_xdcruntime_SemThreadSupport_Instance_State_sem__O;
static inline ti_sysbios_knl_Semaphore_Handle ti_sysbios_xdcruntime_SemThreadSupport_Instance_State_sem(ti_sysbios_xdcruntime_SemThreadSupport_Object* obj)
{
    return (ti_sysbios_knl_Semaphore_Handle)(((char*)obj) + ti_sysbios_xdcruntime_SemThreadSupport_Instance_State_sem__O);
}

#endif /* ti_sysbios_xdcruntime_SemThreadSupport__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_xdcruntime_SemThreadSupport__nolocalnames)

#ifndef ti_sysbios_xdcruntime_SemThreadSupport__localnames__done
#define ti_sysbios_xdcruntime_SemThreadSupport__localnames__done

/* module prefix */
#define SemThreadSupport_Instance ti_sysbios_xdcruntime_SemThreadSupport_Instance
#define SemThreadSupport_Handle ti_sysbios_xdcruntime_SemThreadSupport_Handle
#define SemThreadSupport_Module ti_sysbios_xdcruntime_SemThreadSupport_Module
#define SemThreadSupport_Object ti_sysbios_xdcruntime_SemThreadSupport_Object
#define SemThreadSupport_Struct ti_sysbios_xdcruntime_SemThreadSupport_Struct
#define SemThreadSupport_PendStatus ti_sysbios_xdcruntime_SemThreadSupport_PendStatus
#define SemThreadSupport_FOREVER ti_sysbios_xdcruntime_SemThreadSupport_FOREVER
#define SemThreadSupport_Mode ti_sysbios_xdcruntime_SemThreadSupport_Mode
#define SemThreadSupport_Instance_State ti_sysbios_xdcruntime_SemThreadSupport_Instance_State
#define SemThreadSupport_PendStatus_ERROR ti_sysbios_xdcruntime_SemThreadSupport_PendStatus_ERROR
#define SemThreadSupport_PendStatus_TIMEOUT ti_sysbios_xdcruntime_SemThreadSupport_PendStatus_TIMEOUT
#define SemThreadSupport_PendStatus_SUCCESS ti_sysbios_xdcruntime_SemThreadSupport_PendStatus_SUCCESS
#define SemThreadSupport_Mode_COUNTING ti_sysbios_xdcruntime_SemThreadSupport_Mode_COUNTING
#define SemThreadSupport_Mode_BINARY ti_sysbios_xdcruntime_SemThreadSupport_Mode_BINARY
#define SemThreadSupport_Instance_State_sem ti_sysbios_xdcruntime_SemThreadSupport_Instance_State_sem
#define SemThreadSupport_Params ti_sysbios_xdcruntime_SemThreadSupport_Params
#define SemThreadSupport_pend ti_sysbios_xdcruntime_SemThreadSupport_pend
#define SemThreadSupport_pend_fxnP ti_sysbios_xdcruntime_SemThreadSupport_pend_fxnP
#define SemThreadSupport_pend_FxnT ti_sysbios_xdcruntime_SemThreadSupport_pend_FxnT
#define SemThreadSupport_post ti_sysbios_xdcruntime_SemThreadSupport_post
#define SemThreadSupport_post_fxnP ti_sysbios_xdcruntime_SemThreadSupport_post_fxnP
#define SemThreadSupport_post_FxnT ti_sysbios_xdcruntime_SemThreadSupport_post_FxnT
#define SemThreadSupport_Module_name ti_sysbios_xdcruntime_SemThreadSupport_Module_name
#define SemThreadSupport_Module_id ti_sysbios_xdcruntime_SemThreadSupport_Module_id
#define SemThreadSupport_Module_startup ti_sysbios_xdcruntime_SemThreadSupport_Module_startup
#define SemThreadSupport_Module_startupDone ti_sysbios_xdcruntime_SemThreadSupport_Module_startupDone
#define SemThreadSupport_Module_hasMask ti_sysbios_xdcruntime_SemThreadSupport_Module_hasMask
#define SemThreadSupport_Module_getMask ti_sysbios_xdcruntime_SemThreadSupport_Module_getMask
#define SemThreadSupport_Module_setMask ti_sysbios_xdcruntime_SemThreadSupport_Module_setMask
#define SemThreadSupport_Object_heap ti_sysbios_xdcruntime_SemThreadSupport_Object_heap
#define SemThreadSupport_Module_heap ti_sysbios_xdcruntime_SemThreadSupport_Module_heap
#define SemThreadSupport_construct ti_sysbios_xdcruntime_SemThreadSupport_construct
#define SemThreadSupport_create ti_sysbios_xdcruntime_SemThreadSupport_create
#define SemThreadSupport_handle ti_sysbios_xdcruntime_SemThreadSupport_handle
#define SemThreadSupport_struct ti_sysbios_xdcruntime_SemThreadSupport_struct
#define SemThreadSupport_Handle_label ti_sysbios_xdcruntime_SemThreadSupport_Handle_label
#define SemThreadSupport_Handle_name ti_sysbios_xdcruntime_SemThreadSupport_Handle_name
#define SemThreadSupport_Instance_init ti_sysbios_xdcruntime_SemThreadSupport_Instance_init
#define SemThreadSupport_Object_count ti_sysbios_xdcruntime_SemThreadSupport_Object_count
#define SemThreadSupport_Object_get ti_sysbios_xdcruntime_SemThreadSupport_Object_get
#define SemThreadSupport_Object_first ti_sysbios_xdcruntime_SemThreadSupport_Object_first
#define SemThreadSupport_Object_next ti_sysbios_xdcruntime_SemThreadSupport_Object_next
#define SemThreadSupport_Object_sizeof ti_sysbios_xdcruntime_SemThreadSupport_Object_sizeof
#define SemThreadSupport_Params_copy ti_sysbios_xdcruntime_SemThreadSupport_Params_copy
#define SemThreadSupport_Params_init ti_sysbios_xdcruntime_SemThreadSupport_Params_init
#define SemThreadSupport_Instance_finalize ti_sysbios_xdcruntime_SemThreadSupport_Instance_finalize
#define SemThreadSupport_delete ti_sysbios_xdcruntime_SemThreadSupport_delete
#define SemThreadSupport_destruct ti_sysbios_xdcruntime_SemThreadSupport_destruct
#define SemThreadSupport_Module_upCast ti_sysbios_xdcruntime_SemThreadSupport_Module_upCast
#define SemThreadSupport_Module_to_xdc_runtime_knl_ISemThreadSupport ti_sysbios_xdcruntime_SemThreadSupport_Module_to_xdc_runtime_knl_ISemThreadSupport
#define SemThreadSupport_Handle_upCast ti_sysbios_xdcruntime_SemThreadSupport_Handle_upCast
#define SemThreadSupport_Handle_to_xdc_runtime_knl_ISemThreadSupport ti_sysbios_xdcruntime_SemThreadSupport_Handle_to_xdc_runtime_knl_ISemThreadSupport
#define SemThreadSupport_Handle_downCast ti_sysbios_xdcruntime_SemThreadSupport_Handle_downCast
#define SemThreadSupport_Handle_from_xdc_runtime_knl_ISemThreadSupport ti_sysbios_xdcruntime_SemThreadSupport_Handle_from_xdc_runtime_knl_ISemThreadSupport
#define SemThreadSupport_Module_upCast2 ti_sysbios_xdcruntime_SemThreadSupport_Module_upCast2
#define SemThreadSupport_Module_to_xdc_runtime_knl_ISemaphore ti_sysbios_xdcruntime_SemThreadSupport_Module_to_xdc_runtime_knl_ISemaphore
#define SemThreadSupport_Handle_upCast2 ti_sysbios_xdcruntime_SemThreadSupport_Handle_upCast2
#define SemThreadSupport_Handle_to_xdc_runtime_knl_ISemaphore ti_sysbios_xdcruntime_SemThreadSupport_Handle_to_xdc_runtime_knl_ISemaphore
#define SemThreadSupport_Handle_downCast2 ti_sysbios_xdcruntime_SemThreadSupport_Handle_downCast2
#define SemThreadSupport_Handle_from_xdc_runtime_knl_ISemaphore ti_sysbios_xdcruntime_SemThreadSupport_Handle_from_xdc_runtime_knl_ISemaphore

#endif /* ti_sysbios_xdcruntime_SemThreadSupport__localnames__done */
#endif
/*
 *  @(#) ti.sysbios.xdcruntime; 1, 0, 0,282; 5-18-2012 06:06:24; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

