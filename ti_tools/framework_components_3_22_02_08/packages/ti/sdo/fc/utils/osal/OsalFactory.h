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
 *     FUNCTION DECLARATIONS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sdo_fc_utils_osal_OsalFactory__include
#define ti_sdo_fc_utils_osal_OsalFactory__include

#ifndef __nested__
#define __nested__
#define ti_sdo_fc_utils_osal_OsalFactory__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_fc_utils_osal_OsalFactory___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sdo/fc/utils/osal/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/knl/ISemaphore.h>
#include <xdc/runtime/Error.h>


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
typedef xdc_Bits32 CT__ti_sdo_fc_utils_osal_OsalFactory_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__diagsEnabled ti_sdo_fc_utils_osal_OsalFactory_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_fc_utils_osal_OsalFactory_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__diagsIncluded ti_sdo_fc_utils_osal_OsalFactory_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sdo_fc_utils_osal_OsalFactory_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__diagsMask ti_sdo_fc_utils_osal_OsalFactory_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_fc_utils_osal_OsalFactory_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__gateObj ti_sdo_fc_utils_osal_OsalFactory_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_fc_utils_osal_OsalFactory_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__gatePrms ti_sdo_fc_utils_osal_OsalFactory_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_fc_utils_osal_OsalFactory_Module__id;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__id ti_sdo_fc_utils_osal_OsalFactory_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerDefined ti_sdo_fc_utils_osal_OsalFactory_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerObj ti_sdo_fc_utils_osal_OsalFactory_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn0 ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn1 ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn2 ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn4 ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn8 ti_sdo_fc_utils_osal_OsalFactory_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sdo_fc_utils_osal_OsalFactory_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Module__startupDoneFxn ti_sdo_fc_utils_osal_OsalFactory_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sdo_fc_utils_osal_OsalFactory_Object__count;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Object__count ti_sdo_fc_utils_osal_OsalFactory_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_fc_utils_osal_OsalFactory_Object__heap;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Object__heap ti_sdo_fc_utils_osal_OsalFactory_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_fc_utils_osal_OsalFactory_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Object__sizeof ti_sdo_fc_utils_osal_OsalFactory_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_fc_utils_osal_OsalFactory_Object__table;
__extern __FAR__ const CT__ti_sdo_fc_utils_osal_OsalFactory_Object__table ti_sdo_fc_utils_osal_OsalFactory_Object__table__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_fc_utils_osal_OsalFactory_Module_startup( state ) -1

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_fc_utils_osal_OsalFactory_Module__startupDone__S, "ti_sdo_fc_utils_osal_OsalFactory_Module__startupDone")
__extern xdc_Bool ti_sdo_fc_utils_osal_OsalFactory_Module__startupDone__S( void );

/* createSem__E */
#define ti_sdo_fc_utils_osal_OsalFactory_createSem ti_sdo_fc_utils_osal_OsalFactory_createSem__E
xdc__CODESECT(ti_sdo_fc_utils_osal_OsalFactory_createSem__E, "ti_sdo_fc_utils_osal_OsalFactory_createSem")
__extern xdc_runtime_knl_ISemaphore_Handle ti_sdo_fc_utils_osal_OsalFactory_createSem__E( xdc_Int count, xdc_Int key, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sdo_fc_utils_osal_OsalFactory_createSem__F, "ti_sdo_fc_utils_osal_OsalFactory_createSem")
__extern xdc_runtime_knl_ISemaphore_Handle ti_sdo_fc_utils_osal_OsalFactory_createSem__F( xdc_Int count, xdc_Int key, xdc_runtime_Error_Block* eb );
__extern xdc_runtime_knl_ISemaphore_Handle ti_sdo_fc_utils_osal_OsalFactory_createSem__R( xdc_Int count, xdc_Int key, xdc_runtime_Error_Block* eb );

/* deleteSem__E */
#define ti_sdo_fc_utils_osal_OsalFactory_deleteSem ti_sdo_fc_utils_osal_OsalFactory_deleteSem__E
xdc__CODESECT(ti_sdo_fc_utils_osal_OsalFactory_deleteSem__E, "ti_sdo_fc_utils_osal_OsalFactory_deleteSem")
__extern xdc_Void ti_sdo_fc_utils_osal_OsalFactory_deleteSem__E( xdc_runtime_knl_ISemaphore_Handle h );
xdc__CODESECT(ti_sdo_fc_utils_osal_OsalFactory_deleteSem__F, "ti_sdo_fc_utils_osal_OsalFactory_deleteSem")
__extern xdc_Void ti_sdo_fc_utils_osal_OsalFactory_deleteSem__F( xdc_runtime_knl_ISemaphore_Handle h );
__extern xdc_Void ti_sdo_fc_utils_osal_OsalFactory_deleteSem__R( xdc_runtime_knl_ISemaphore_Handle h );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_fc_utils_osal_OsalFactory_Module_startupDone() ti_sdo_fc_utils_osal_OsalFactory_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_fc_utils_osal_OsalFactory_Object_heap() ti_sdo_fc_utils_osal_OsalFactory_Object__heap__C

/* Module_heap */
#define ti_sdo_fc_utils_osal_OsalFactory_Module_heap() ti_sdo_fc_utils_osal_OsalFactory_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_fc_utils_osal_OsalFactory_Module__id ti_sdo_fc_utils_osal_OsalFactory_Module_id( void ) 
{
    return ti_sdo_fc_utils_osal_OsalFactory_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_fc_utils_osal_OsalFactory_Module_hasMask( void ) 
{
    return ti_sdo_fc_utils_osal_OsalFactory_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_fc_utils_osal_OsalFactory_Module_getMask( void ) 
{
    return ti_sdo_fc_utils_osal_OsalFactory_Module__diagsMask__C != NULL ? *ti_sdo_fc_utils_osal_OsalFactory_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_fc_utils_osal_OsalFactory_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sdo_fc_utils_osal_OsalFactory_Module__diagsMask__C != NULL) *ti_sdo_fc_utils_osal_OsalFactory_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_fc_utils_osal_OsalFactory__top__
#undef __nested__
#endif

#endif /* ti_sdo_fc_utils_osal_OsalFactory__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_fc_utils_osal_OsalFactory__internalaccess))

#ifndef ti_sdo_fc_utils_osal_OsalFactory__include_state
#define ti_sdo_fc_utils_osal_OsalFactory__include_state


#endif /* ti_sdo_fc_utils_osal_OsalFactory__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_fc_utils_osal_OsalFactory__nolocalnames)

#ifndef ti_sdo_fc_utils_osal_OsalFactory__localnames__done
#define ti_sdo_fc_utils_osal_OsalFactory__localnames__done

/* module prefix */
#define OsalFactory_createSem ti_sdo_fc_utils_osal_OsalFactory_createSem
#define OsalFactory_deleteSem ti_sdo_fc_utils_osal_OsalFactory_deleteSem
#define OsalFactory_Module_name ti_sdo_fc_utils_osal_OsalFactory_Module_name
#define OsalFactory_Module_id ti_sdo_fc_utils_osal_OsalFactory_Module_id
#define OsalFactory_Module_startup ti_sdo_fc_utils_osal_OsalFactory_Module_startup
#define OsalFactory_Module_startupDone ti_sdo_fc_utils_osal_OsalFactory_Module_startupDone
#define OsalFactory_Module_hasMask ti_sdo_fc_utils_osal_OsalFactory_Module_hasMask
#define OsalFactory_Module_getMask ti_sdo_fc_utils_osal_OsalFactory_Module_getMask
#define OsalFactory_Module_setMask ti_sdo_fc_utils_osal_OsalFactory_Module_setMask
#define OsalFactory_Object_heap ti_sdo_fc_utils_osal_OsalFactory_Object_heap
#define OsalFactory_Module_heap ti_sdo_fc_utils_osal_OsalFactory_Module_heap

#endif /* ti_sdo_fc_utils_osal_OsalFactory__localnames__done */
#endif
/*
 *  @(#) ti.sdo.fc.utils.osal; 1, 0, 0,3; 4-16-2012 00:02:50; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

