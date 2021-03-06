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

#ifndef ti_sdo_fc_rman_examples_EXAMPLE__include
#define ti_sdo_fc_rman_examples_EXAMPLE__include

#ifndef __nested__
#define __nested__
#define ti_sdo_fc_rman_examples_EXAMPLE__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_fc_rman_examples_EXAMPLE___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sdo/fc/rman/examples/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/IGateProvider.h>
#include <ti/sdo/fc/rman/examples/package/EXAMPLE_Module_GateProxy.h>


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
typedef xdc_Bits32 CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsEnabled ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsIncluded ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsMask ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__gateObj ti_sdo_fc_rman_examples_EXAMPLE_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__gatePrms ti_sdo_fc_rman_examples_EXAMPLE_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__id;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__id ti_sdo_fc_rman_examples_EXAMPLE_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerDefined ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerObj ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn0 ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn1 ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn2 ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn4 ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn8 ti_sdo_fc_rman_examples_EXAMPLE_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__startupDoneFxn ti_sdo_fc_rman_examples_EXAMPLE_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sdo_fc_rman_examples_EXAMPLE_Object__count;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Object__count ti_sdo_fc_rman_examples_EXAMPLE_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_fc_rman_examples_EXAMPLE_Object__heap;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Object__heap ti_sdo_fc_rman_examples_EXAMPLE_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_fc_rman_examples_EXAMPLE_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Object__sizeof ti_sdo_fc_rman_examples_EXAMPLE_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_fc_rman_examples_EXAMPLE_Object__table;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_Object__table ti_sdo_fc_rman_examples_EXAMPLE_Object__table__C;

/* gate */
#define ti_sdo_fc_rman_examples_EXAMPLE_gate (ti_sdo_fc_rman_examples_EXAMPLE_gate__C)
typedef xdc_runtime_IGateProvider_Handle CT__ti_sdo_fc_rman_examples_EXAMPLE_gate;
__extern __FAR__ const CT__ti_sdo_fc_rman_examples_EXAMPLE_gate ti_sdo_fc_rman_examples_EXAMPLE_gate__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_fc_rman_examples_EXAMPLE_Module_startup( state ) -1

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_fc_rman_examples_EXAMPLE_Module__startupDone__S, "ti_sdo_fc_rman_examples_EXAMPLE_Module__startupDone")
__extern xdc_Bool ti_sdo_fc_rman_examples_EXAMPLE_Module__startupDone__S( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_fc_rman_examples_EXAMPLE_Module_startupDone() ti_sdo_fc_rman_examples_EXAMPLE_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_fc_rman_examples_EXAMPLE_Object_heap() ti_sdo_fc_rman_examples_EXAMPLE_Object__heap__C

/* Module_heap */
#define ti_sdo_fc_rman_examples_EXAMPLE_Module_heap() ti_sdo_fc_rman_examples_EXAMPLE_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_fc_rman_examples_EXAMPLE_Module__id ti_sdo_fc_rman_examples_EXAMPLE_Module_id( void ) 
{
    return ti_sdo_fc_rman_examples_EXAMPLE_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_fc_rman_examples_EXAMPLE_Module_hasMask( void ) 
{
    return ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_fc_rman_examples_EXAMPLE_Module_getMask( void ) 
{
    return ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsMask__C != NULL ? *ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_fc_rman_examples_EXAMPLE_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsMask__C != NULL) *ti_sdo_fc_rman_examples_EXAMPLE_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_fc_rman_examples_EXAMPLE__top__
#undef __nested__
#endif

#endif /* ti_sdo_fc_rman_examples_EXAMPLE__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_fc_rman_examples_EXAMPLE__internalaccess))

#ifndef ti_sdo_fc_rman_examples_EXAMPLE__include_state
#define ti_sdo_fc_rman_examples_EXAMPLE__include_state


#endif /* ti_sdo_fc_rman_examples_EXAMPLE__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_fc_rman_examples_EXAMPLE__nolocalnames)

#ifndef ti_sdo_fc_rman_examples_EXAMPLE__localnames__done
#define ti_sdo_fc_rman_examples_EXAMPLE__localnames__done

/* module prefix */
#define EXAMPLE_gate ti_sdo_fc_rman_examples_EXAMPLE_gate
#define EXAMPLE_Module_name ti_sdo_fc_rman_examples_EXAMPLE_Module_name
#define EXAMPLE_Module_id ti_sdo_fc_rman_examples_EXAMPLE_Module_id
#define EXAMPLE_Module_startup ti_sdo_fc_rman_examples_EXAMPLE_Module_startup
#define EXAMPLE_Module_startupDone ti_sdo_fc_rman_examples_EXAMPLE_Module_startupDone
#define EXAMPLE_Module_hasMask ti_sdo_fc_rman_examples_EXAMPLE_Module_hasMask
#define EXAMPLE_Module_getMask ti_sdo_fc_rman_examples_EXAMPLE_Module_getMask
#define EXAMPLE_Module_setMask ti_sdo_fc_rman_examples_EXAMPLE_Module_setMask
#define EXAMPLE_Object_heap ti_sdo_fc_rman_examples_EXAMPLE_Object_heap
#define EXAMPLE_Module_heap ti_sdo_fc_rman_examples_EXAMPLE_Module_heap

/* proxies */
#include <ti/sdo/fc/rman/examples/package/EXAMPLE_Module_GateProxy.h>

#endif /* ti_sdo_fc_rman_examples_EXAMPLE__localnames__done */
#endif
/*
 *  @(#) ti.sdo.fc.rman.examples; 1, 0, 0,3; 4-16-2012 00:01:59; /db/atree/library/trees/fc/fc-q08/src/ xlibrary

 */

