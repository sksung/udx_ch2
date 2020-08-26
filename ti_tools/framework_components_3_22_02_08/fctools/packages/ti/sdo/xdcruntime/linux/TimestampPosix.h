/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *
 */

/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y21
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
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

#ifndef ti_sdo_xdcruntime_linux_TimestampPosix__include
#define ti_sdo_xdcruntime_linux_TimestampPosix__include

#ifndef __nested__
#define __nested__
#define ti_sdo_xdcruntime_linux_TimestampPosix__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_xdcruntime_linux_TimestampPosix___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sdo/xdcruntime/linux/package/package.defs.h>

#include <xdc/runtime/ITimestampProvider.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsEnabled ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsIncluded ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsMask ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__gateObj ti_sdo_xdcruntime_linux_TimestampPosix_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__gatePrms ti_sdo_xdcruntime_linux_TimestampPosix_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__id;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__id ti_sdo_xdcruntime_linux_TimestampPosix_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerDefined ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerObj ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn0 ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn1 ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn2 ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn4 ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn8 ti_sdo_xdcruntime_linux_TimestampPosix_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__startupDoneFxn ti_sdo_xdcruntime_linux_TimestampPosix_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sdo_xdcruntime_linux_TimestampPosix_Object__count;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Object__count ti_sdo_xdcruntime_linux_TimestampPosix_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_xdcruntime_linux_TimestampPosix_Object__heap;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Object__heap ti_sdo_xdcruntime_linux_TimestampPosix_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_xdcruntime_linux_TimestampPosix_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Object__sizeof ti_sdo_xdcruntime_linux_TimestampPosix_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_xdcruntime_linux_TimestampPosix_Object__table;
__extern __FAR__ const CT__ti_sdo_xdcruntime_linux_TimestampPosix_Object__table ti_sdo_xdcruntime_linux_TimestampPosix_Object__table__C;


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sdo_xdcruntime_linux_TimestampPosix_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Bits32 (*get32)(void);
    xdc_Void (*get64)(xdc_runtime_Types_Timestamp64*);
    xdc_Void (*getFreq)(xdc_runtime_Types_FreqHz*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sdo_xdcruntime_linux_TimestampPosix_Fxns__ ti_sdo_xdcruntime_linux_TimestampPosix_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_xdcruntime_linux_TimestampPosix_Module_startup( state ) -1

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_xdcruntime_linux_TimestampPosix_Module__startupDone__S, "ti_sdo_xdcruntime_linux_TimestampPosix_Module__startupDone")
__extern xdc_Bool ti_sdo_xdcruntime_linux_TimestampPosix_Module__startupDone__S( void );

/* get32__E */
#define ti_sdo_xdcruntime_linux_TimestampPosix_get32 ti_sdo_xdcruntime_linux_TimestampPosix_get32__E
xdc__CODESECT(ti_sdo_xdcruntime_linux_TimestampPosix_get32__E, "ti_sdo_xdcruntime_linux_TimestampPosix_get32")
__extern xdc_Bits32 ti_sdo_xdcruntime_linux_TimestampPosix_get32__E( void );
xdc__CODESECT(ti_sdo_xdcruntime_linux_TimestampPosix_get32__F, "ti_sdo_xdcruntime_linux_TimestampPosix_get32")
__extern xdc_Bits32 ti_sdo_xdcruntime_linux_TimestampPosix_get32__F( void );
__extern xdc_Bits32 ti_sdo_xdcruntime_linux_TimestampPosix_get32__R( void );

/* get64__E */
#define ti_sdo_xdcruntime_linux_TimestampPosix_get64 ti_sdo_xdcruntime_linux_TimestampPosix_get64__E
xdc__CODESECT(ti_sdo_xdcruntime_linux_TimestampPosix_get64__E, "ti_sdo_xdcruntime_linux_TimestampPosix_get64")
__extern xdc_Void ti_sdo_xdcruntime_linux_TimestampPosix_get64__E( xdc_runtime_Types_Timestamp64* result );
xdc__CODESECT(ti_sdo_xdcruntime_linux_TimestampPosix_get64__F, "ti_sdo_xdcruntime_linux_TimestampPosix_get64")
__extern xdc_Void ti_sdo_xdcruntime_linux_TimestampPosix_get64__F( xdc_runtime_Types_Timestamp64* result );
__extern xdc_Void ti_sdo_xdcruntime_linux_TimestampPosix_get64__R( xdc_runtime_Types_Timestamp64* result );

/* getFreq__E */
#define ti_sdo_xdcruntime_linux_TimestampPosix_getFreq ti_sdo_xdcruntime_linux_TimestampPosix_getFreq__E
xdc__CODESECT(ti_sdo_xdcruntime_linux_TimestampPosix_getFreq__E, "ti_sdo_xdcruntime_linux_TimestampPosix_getFreq")
__extern xdc_Void ti_sdo_xdcruntime_linux_TimestampPosix_getFreq__E( xdc_runtime_Types_FreqHz* freq );
xdc__CODESECT(ti_sdo_xdcruntime_linux_TimestampPosix_getFreq__F, "ti_sdo_xdcruntime_linux_TimestampPosix_getFreq")
__extern xdc_Void ti_sdo_xdcruntime_linux_TimestampPosix_getFreq__F( xdc_runtime_Types_FreqHz* freq );
__extern xdc_Void ti_sdo_xdcruntime_linux_TimestampPosix_getFreq__R( xdc_runtime_Types_FreqHz* freq );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_ITimestampProvider_Module ti_sdo_xdcruntime_linux_TimestampPosix_Module_upCast( void )
{
    return (xdc_runtime_ITimestampProvider_Module)&ti_sdo_xdcruntime_linux_TimestampPosix_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ITimestampProvider */
#define ti_sdo_xdcruntime_linux_TimestampPosix_Module_to_xdc_runtime_ITimestampProvider ti_sdo_xdcruntime_linux_TimestampPosix_Module_upCast

/* Module_upCast2 */
static inline xdc_runtime_ITimestampClient_Module ti_sdo_xdcruntime_linux_TimestampPosix_Module_upCast2( void )
{
    return (xdc_runtime_ITimestampClient_Module)&ti_sdo_xdcruntime_linux_TimestampPosix_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ITimestampClient */
#define ti_sdo_xdcruntime_linux_TimestampPosix_Module_to_xdc_runtime_ITimestampClient ti_sdo_xdcruntime_linux_TimestampPosix_Module_upCast2


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_xdcruntime_linux_TimestampPosix_Module_startupDone() ti_sdo_xdcruntime_linux_TimestampPosix_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_xdcruntime_linux_TimestampPosix_Object_heap() ti_sdo_xdcruntime_linux_TimestampPosix_Object__heap__C

/* Module_heap */
#define ti_sdo_xdcruntime_linux_TimestampPosix_Module_heap() ti_sdo_xdcruntime_linux_TimestampPosix_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_xdcruntime_linux_TimestampPosix_Module__id ti_sdo_xdcruntime_linux_TimestampPosix_Module_id( void ) 
{
    return ti_sdo_xdcruntime_linux_TimestampPosix_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_xdcruntime_linux_TimestampPosix_Module_hasMask( void ) 
{
    return ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_xdcruntime_linux_TimestampPosix_Module_getMask( void ) 
{
    return ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsMask__C != NULL ? *ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_xdcruntime_linux_TimestampPosix_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsMask__C != NULL) *ti_sdo_xdcruntime_linux_TimestampPosix_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_xdcruntime_linux_TimestampPosix__top__
#undef __nested__
#endif

#endif /* ti_sdo_xdcruntime_linux_TimestampPosix__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_xdcruntime_linux_TimestampPosix__internalaccess))

#ifndef ti_sdo_xdcruntime_linux_TimestampPosix__include_state
#define ti_sdo_xdcruntime_linux_TimestampPosix__include_state


#endif /* ti_sdo_xdcruntime_linux_TimestampPosix__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_xdcruntime_linux_TimestampPosix__nolocalnames)

#ifndef ti_sdo_xdcruntime_linux_TimestampPosix__localnames__done
#define ti_sdo_xdcruntime_linux_TimestampPosix__localnames__done

/* module prefix */
#define TimestampPosix_get32 ti_sdo_xdcruntime_linux_TimestampPosix_get32
#define TimestampPosix_get64 ti_sdo_xdcruntime_linux_TimestampPosix_get64
#define TimestampPosix_getFreq ti_sdo_xdcruntime_linux_TimestampPosix_getFreq
#define TimestampPosix_Module_name ti_sdo_xdcruntime_linux_TimestampPosix_Module_name
#define TimestampPosix_Module_id ti_sdo_xdcruntime_linux_TimestampPosix_Module_id
#define TimestampPosix_Module_startup ti_sdo_xdcruntime_linux_TimestampPosix_Module_startup
#define TimestampPosix_Module_startupDone ti_sdo_xdcruntime_linux_TimestampPosix_Module_startupDone
#define TimestampPosix_Module_hasMask ti_sdo_xdcruntime_linux_TimestampPosix_Module_hasMask
#define TimestampPosix_Module_getMask ti_sdo_xdcruntime_linux_TimestampPosix_Module_getMask
#define TimestampPosix_Module_setMask ti_sdo_xdcruntime_linux_TimestampPosix_Module_setMask
#define TimestampPosix_Object_heap ti_sdo_xdcruntime_linux_TimestampPosix_Object_heap
#define TimestampPosix_Module_heap ti_sdo_xdcruntime_linux_TimestampPosix_Module_heap
#define TimestampPosix_Module_upCast ti_sdo_xdcruntime_linux_TimestampPosix_Module_upCast
#define TimestampPosix_Module_to_xdc_runtime_ITimestampProvider ti_sdo_xdcruntime_linux_TimestampPosix_Module_to_xdc_runtime_ITimestampProvider
#define TimestampPosix_Module_upCast2 ti_sdo_xdcruntime_linux_TimestampPosix_Module_upCast2
#define TimestampPosix_Module_to_xdc_runtime_ITimestampClient ti_sdo_xdcruntime_linux_TimestampPosix_Module_to_xdc_runtime_ITimestampClient

#endif /* ti_sdo_xdcruntime_linux_TimestampPosix__localnames__done */
#endif
/*
 *  @(#) ti.sdo.xdcruntime.linux; 1, 0, 0,1; 2-15-2012 07:45:02; /db/atree/library/trees/osal/osal-e09/src/ xlibrary

 */

