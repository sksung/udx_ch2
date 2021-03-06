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

#ifndef ti_sdo_io_drivers_Generator__include
#define ti_sdo_io_drivers_Generator__include

#ifndef __nested__
#define __nested__
#define ti_sdo_io_drivers_Generator__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sdo_io_drivers_Generator___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sdo/io/drivers/package/package.defs.h>

#include <ti/sdo/utils/List.h>
#include <xdc/runtime/Error.h>
#include <ti/sdo/io/DriverTypes.h>
#include <xdc/runtime/IHeap.h>
#include <ti/sdo/io/IDriver.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* GenFunc */
typedef xdc_Void (*ti_sdo_io_drivers_Generator_GenFunc)(xdc_Ptr, xdc_SizeT, xdc_UArg);

/* NUMCHANS */
#define ti_sdo_io_drivers_Generator_NUMCHANS (2)

/* ChanParams */
struct ti_sdo_io_drivers_Generator_ChanParams {
    ti_sdo_io_drivers_Generator_GenFunc userFxn;
    xdc_UArg userArg;
    xdc_Bool returnPending;
};


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* ChanObj */
struct ti_sdo_io_drivers_Generator_ChanObj {
    ti_sdo_utils_List_Elem elem;
    xdc_Bool inUse;
    xdc_Bool returnPending;
    ti_sdo_utils_List_Handle pendList;
    ti_sdo_io_DriverTypes_DoneFxn cbFxn;
    xdc_UArg cbArg;
    ti_sdo_io_drivers_Generator_GenFunc userFxn;
    xdc_UArg userArg;
};

/* Instance_State */
typedef ti_sdo_io_drivers_Generator_ChanObj __T1_ti_sdo_io_drivers_Generator_Instance_State__chans;
typedef ti_sdo_io_drivers_Generator_ChanObj __ARRAY1_ti_sdo_io_drivers_Generator_Instance_State__chans[2];
typedef __ARRAY1_ti_sdo_io_drivers_Generator_Instance_State__chans __TA_ti_sdo_io_drivers_Generator_Instance_State__chans;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sdo_io_drivers_Generator_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__diagsEnabled ti_sdo_io_drivers_Generator_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sdo_io_drivers_Generator_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__diagsIncluded ti_sdo_io_drivers_Generator_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sdo_io_drivers_Generator_Module__diagsMask;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__diagsMask ti_sdo_io_drivers_Generator_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sdo_io_drivers_Generator_Module__gateObj;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__gateObj ti_sdo_io_drivers_Generator_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sdo_io_drivers_Generator_Module__gatePrms;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__gatePrms ti_sdo_io_drivers_Generator_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sdo_io_drivers_Generator_Module__id;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__id ti_sdo_io_drivers_Generator_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sdo_io_drivers_Generator_Module__loggerDefined;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__loggerDefined ti_sdo_io_drivers_Generator_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sdo_io_drivers_Generator_Module__loggerObj;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__loggerObj ti_sdo_io_drivers_Generator_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sdo_io_drivers_Generator_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__loggerFxn0 ti_sdo_io_drivers_Generator_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sdo_io_drivers_Generator_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__loggerFxn1 ti_sdo_io_drivers_Generator_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sdo_io_drivers_Generator_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__loggerFxn2 ti_sdo_io_drivers_Generator_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sdo_io_drivers_Generator_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__loggerFxn4 ti_sdo_io_drivers_Generator_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sdo_io_drivers_Generator_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__loggerFxn8 ti_sdo_io_drivers_Generator_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sdo_io_drivers_Generator_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Module__startupDoneFxn ti_sdo_io_drivers_Generator_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sdo_io_drivers_Generator_Object__count;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Object__count ti_sdo_io_drivers_Generator_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sdo_io_drivers_Generator_Object__heap;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Object__heap ti_sdo_io_drivers_Generator_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sdo_io_drivers_Generator_Object__sizeof;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Object__sizeof ti_sdo_io_drivers_Generator_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sdo_io_drivers_Generator_Object__table;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_Object__table ti_sdo_io_drivers_Generator_Object__table__C;

/* E_nullParams */
#define ti_sdo_io_drivers_Generator_E_nullParams (ti_sdo_io_drivers_Generator_E_nullParams__C)
typedef xdc_runtime_Error_Id CT__ti_sdo_io_drivers_Generator_E_nullParams;
__extern __FAR__ const CT__ti_sdo_io_drivers_Generator_E_nullParams ti_sdo_io_drivers_Generator_E_nullParams__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sdo_io_drivers_Generator_Params {
    size_t __size;
    const void* __self;
    void* __fxns;
    xdc_runtime_IInstance_Params* instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sdo_io_drivers_Generator_Struct {
    const ti_sdo_io_drivers_Generator_Fxns__* __fxns;
    __TA_ti_sdo_io_drivers_Generator_Instance_State__chans __f0;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sdo_io_drivers_Generator_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Ptr (*open)(ti_sdo_io_drivers_Generator_Handle, xdc_String, xdc_UInt, xdc_UArg, ti_sdo_io_DriverTypes_DoneFxn, xdc_UArg, xdc_runtime_Error_Block*);
    xdc_Void (*close)(ti_sdo_io_drivers_Generator_Handle, xdc_Ptr, xdc_runtime_Error_Block*);
    xdc_UInt (*submit)(ti_sdo_io_drivers_Generator_Handle, xdc_Ptr, ti_sdo_io_DriverTypes_Packet*, xdc_runtime_Error_Block*);
    xdc_Void (*control)(ti_sdo_io_drivers_Generator_Handle, xdc_Ptr, ti_sdo_io_DriverTypes_ControlCmd, xdc_UArg, xdc_runtime_Error_Block*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sdo_io_drivers_Generator_Fxns__ ti_sdo_io_drivers_Generator_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sdo_io_drivers_Generator_Module_startup( state ) -1

/* Instance_init__F */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Instance_init__F, "ti_sdo_io_drivers_Generator_Instance_init")
__extern void ti_sdo_io_drivers_Generator_Instance_init__F( ti_sdo_io_drivers_Generator_Object*, const ti_sdo_io_drivers_Generator_Params* );

/* Instance_init__R */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Instance_init__R, "ti_sdo_io_drivers_Generator_Instance_init")
__extern void ti_sdo_io_drivers_Generator_Instance_init__R( ti_sdo_io_drivers_Generator_Object*, const ti_sdo_io_drivers_Generator_Params* );

/* Handle__label__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Handle__label__S, "ti_sdo_io_drivers_Generator_Handle__label")
__extern xdc_runtime_Types_Label* ti_sdo_io_drivers_Generator_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Module__startupDone__S, "ti_sdo_io_drivers_Generator_Module__startupDone")
__extern xdc_Bool ti_sdo_io_drivers_Generator_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Object__create__S, "ti_sdo_io_drivers_Generator_Object__create")
__extern xdc_Ptr ti_sdo_io_drivers_Generator_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar* __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb );

/* Object__delete__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Object__delete__S, "ti_sdo_io_drivers_Generator_Object__delete")
__extern xdc_Void ti_sdo_io_drivers_Generator_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Object__destruct__S, "ti_sdo_io_drivers_Generator_Object__destruct")
__extern xdc_Void ti_sdo_io_drivers_Generator_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Object__get__S, "ti_sdo_io_drivers_Generator_Object__get")
__extern xdc_Ptr ti_sdo_io_drivers_Generator_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Object__first__S, "ti_sdo_io_drivers_Generator_Object__first")
__extern xdc_Ptr ti_sdo_io_drivers_Generator_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Object__next__S, "ti_sdo_io_drivers_Generator_Object__next")
__extern xdc_Ptr ti_sdo_io_drivers_Generator_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sdo_io_drivers_Generator_Params__init__S, "ti_sdo_io_drivers_Generator_Params__init")
__extern xdc_Void ti_sdo_io_drivers_Generator_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz );

/* open__E */
#define ti_sdo_io_drivers_Generator_open ti_sdo_io_drivers_Generator_open__E
xdc__CODESECT(ti_sdo_io_drivers_Generator_open__E, "ti_sdo_io_drivers_Generator_open")
__extern xdc_Ptr ti_sdo_io_drivers_Generator_open__E( ti_sdo_io_drivers_Generator_Handle __inst, xdc_String name, xdc_UInt mode, xdc_UArg chanParams, ti_sdo_io_DriverTypes_DoneFxn cbFxn, xdc_UArg cbArg, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sdo_io_drivers_Generator_open__F, "ti_sdo_io_drivers_Generator_open")
__extern xdc_Ptr ti_sdo_io_drivers_Generator_open__F( ti_sdo_io_drivers_Generator_Object* __inst, xdc_String name, xdc_UInt mode, xdc_UArg chanParams, ti_sdo_io_DriverTypes_DoneFxn cbFxn, xdc_UArg cbArg, xdc_runtime_Error_Block* eb );
__extern xdc_Ptr ti_sdo_io_drivers_Generator_open__R( ti_sdo_io_drivers_Generator_Handle __inst, xdc_String name, xdc_UInt mode, xdc_UArg chanParams, ti_sdo_io_DriverTypes_DoneFxn cbFxn, xdc_UArg cbArg, xdc_runtime_Error_Block* eb );

/* close__E */
#define ti_sdo_io_drivers_Generator_close ti_sdo_io_drivers_Generator_close__E
xdc__CODESECT(ti_sdo_io_drivers_Generator_close__E, "ti_sdo_io_drivers_Generator_close")
__extern xdc_Void ti_sdo_io_drivers_Generator_close__E( ti_sdo_io_drivers_Generator_Handle __inst, xdc_Ptr chanHandle, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sdo_io_drivers_Generator_close__F, "ti_sdo_io_drivers_Generator_close")
__extern xdc_Void ti_sdo_io_drivers_Generator_close__F( ti_sdo_io_drivers_Generator_Object* __inst, xdc_Ptr chanHandle, xdc_runtime_Error_Block* eb );
__extern xdc_Void ti_sdo_io_drivers_Generator_close__R( ti_sdo_io_drivers_Generator_Handle __inst, xdc_Ptr chanHandle, xdc_runtime_Error_Block* eb );

/* submit__E */
#define ti_sdo_io_drivers_Generator_submit ti_sdo_io_drivers_Generator_submit__E
xdc__CODESECT(ti_sdo_io_drivers_Generator_submit__E, "ti_sdo_io_drivers_Generator_submit")
__extern xdc_UInt ti_sdo_io_drivers_Generator_submit__E( ti_sdo_io_drivers_Generator_Handle __inst, xdc_Ptr chanHandle, ti_sdo_io_DriverTypes_Packet* packet, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sdo_io_drivers_Generator_submit__F, "ti_sdo_io_drivers_Generator_submit")
__extern xdc_UInt ti_sdo_io_drivers_Generator_submit__F( ti_sdo_io_drivers_Generator_Object* __inst, xdc_Ptr chanHandle, ti_sdo_io_DriverTypes_Packet* packet, xdc_runtime_Error_Block* eb );
__extern xdc_UInt ti_sdo_io_drivers_Generator_submit__R( ti_sdo_io_drivers_Generator_Handle __inst, xdc_Ptr chanHandle, ti_sdo_io_DriverTypes_Packet* packet, xdc_runtime_Error_Block* eb );

/* control__E */
#define ti_sdo_io_drivers_Generator_control ti_sdo_io_drivers_Generator_control__E
xdc__CODESECT(ti_sdo_io_drivers_Generator_control__E, "ti_sdo_io_drivers_Generator_control")
__extern xdc_Void ti_sdo_io_drivers_Generator_control__E( ti_sdo_io_drivers_Generator_Handle __inst, xdc_Ptr chanHandle, ti_sdo_io_DriverTypes_ControlCmd cmd, xdc_UArg cmdArgs, xdc_runtime_Error_Block* eb );
xdc__CODESECT(ti_sdo_io_drivers_Generator_control__F, "ti_sdo_io_drivers_Generator_control")
__extern xdc_Void ti_sdo_io_drivers_Generator_control__F( ti_sdo_io_drivers_Generator_Object* __inst, xdc_Ptr chanHandle, ti_sdo_io_DriverTypes_ControlCmd cmd, xdc_UArg cmdArgs, xdc_runtime_Error_Block* eb );
__extern xdc_Void ti_sdo_io_drivers_Generator_control__R( ti_sdo_io_drivers_Generator_Handle __inst, xdc_Ptr chanHandle, ti_sdo_io_DriverTypes_ControlCmd cmd, xdc_UArg cmdArgs, xdc_runtime_Error_Block* eb );

/* simulateIsr__E */
#define ti_sdo_io_drivers_Generator_simulateIsr ti_sdo_io_drivers_Generator_simulateIsr__E
xdc__CODESECT(ti_sdo_io_drivers_Generator_simulateIsr__E, "ti_sdo_io_drivers_Generator_simulateIsr")
__extern xdc_Void ti_sdo_io_drivers_Generator_simulateIsr__E( xdc_UArg arg );
xdc__CODESECT(ti_sdo_io_drivers_Generator_simulateIsr__F, "ti_sdo_io_drivers_Generator_simulateIsr")
__extern xdc_Void ti_sdo_io_drivers_Generator_simulateIsr__F( xdc_UArg arg );
__extern xdc_Void ti_sdo_io_drivers_Generator_simulateIsr__R( xdc_UArg arg );


/*
 * ======== FUNCTION SELECTORS ========
 */

/* open_{FxnT,fxnP} */
typedef xdc_Ptr (*ti_sdo_io_drivers_Generator_open_FxnT)(void*, xdc_String, xdc_UInt, xdc_UArg, ti_sdo_io_DriverTypes_DoneFxn, xdc_UArg, xdc_runtime_Error_Block*);
static inline ti_sdo_io_drivers_Generator_open_FxnT ti_sdo_io_drivers_Generator_open_fxnP( void )
{
    return (ti_sdo_io_drivers_Generator_open_FxnT)ti_sdo_io_drivers_Generator_open; 
}

/* close_{FxnT,fxnP} */
typedef xdc_Void (*ti_sdo_io_drivers_Generator_close_FxnT)(void*, xdc_Ptr, xdc_runtime_Error_Block*);
static inline ti_sdo_io_drivers_Generator_close_FxnT ti_sdo_io_drivers_Generator_close_fxnP( void )
{
    return (ti_sdo_io_drivers_Generator_close_FxnT)ti_sdo_io_drivers_Generator_close; 
}

/* submit_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sdo_io_drivers_Generator_submit_FxnT)(void*, xdc_Ptr, ti_sdo_io_DriverTypes_Packet*, xdc_runtime_Error_Block*);
static inline ti_sdo_io_drivers_Generator_submit_FxnT ti_sdo_io_drivers_Generator_submit_fxnP( void )
{
    return (ti_sdo_io_drivers_Generator_submit_FxnT)ti_sdo_io_drivers_Generator_submit; 
}

/* control_{FxnT,fxnP} */
typedef xdc_Void (*ti_sdo_io_drivers_Generator_control_FxnT)(void*, xdc_Ptr, ti_sdo_io_DriverTypes_ControlCmd, xdc_UArg, xdc_runtime_Error_Block*);
static inline ti_sdo_io_drivers_Generator_control_FxnT ti_sdo_io_drivers_Generator_control_fxnP( void )
{
    return (ti_sdo_io_drivers_Generator_control_FxnT)ti_sdo_io_drivers_Generator_control; 
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sdo_io_IDriver_Module ti_sdo_io_drivers_Generator_Module_upCast( void )
{
    return (ti_sdo_io_IDriver_Module)&ti_sdo_io_drivers_Generator_Module__FXNS__C;
}

/* Module_to_ti_sdo_io_IDriver */
#define ti_sdo_io_drivers_Generator_Module_to_ti_sdo_io_IDriver ti_sdo_io_drivers_Generator_Module_upCast

/* Handle_upCast */
static inline ti_sdo_io_IDriver_Handle ti_sdo_io_drivers_Generator_Handle_upCast( ti_sdo_io_drivers_Generator_Handle i )
{
    return (ti_sdo_io_IDriver_Handle)i;
}

/* Handle_to_ti_sdo_io_IDriver */
#define ti_sdo_io_drivers_Generator_Handle_to_ti_sdo_io_IDriver ti_sdo_io_drivers_Generator_Handle_upCast

/* Handle_downCast */
static inline ti_sdo_io_drivers_Generator_Handle ti_sdo_io_drivers_Generator_Handle_downCast( ti_sdo_io_IDriver_Handle i )
{
    ti_sdo_io_IDriver_Handle i2 = (ti_sdo_io_IDriver_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sdo_io_drivers_Generator_Module__FXNS__C ? (ti_sdo_io_drivers_Generator_Handle)i : 0;
}

/* Handle_from_ti_sdo_io_IDriver */
#define ti_sdo_io_drivers_Generator_Handle_from_ti_sdo_io_IDriver ti_sdo_io_drivers_Generator_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sdo_io_drivers_Generator_Module_startupDone() ti_sdo_io_drivers_Generator_Module__startupDone__S()

/* Object_heap */
#define ti_sdo_io_drivers_Generator_Object_heap() ti_sdo_io_drivers_Generator_Object__heap__C

/* Module_heap */
#define ti_sdo_io_drivers_Generator_Module_heap() ti_sdo_io_drivers_Generator_Object__heap__C

/* Module_id */
static inline CT__ti_sdo_io_drivers_Generator_Module__id ti_sdo_io_drivers_Generator_Module_id( void ) 
{
    return ti_sdo_io_drivers_Generator_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sdo_io_drivers_Generator_Module_hasMask( void ) 
{
    return ti_sdo_io_drivers_Generator_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sdo_io_drivers_Generator_Module_getMask( void ) 
{
    return ti_sdo_io_drivers_Generator_Module__diagsMask__C != NULL ? *ti_sdo_io_drivers_Generator_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sdo_io_drivers_Generator_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sdo_io_drivers_Generator_Module__diagsMask__C != NULL) *ti_sdo_io_drivers_Generator_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sdo_io_drivers_Generator_Params_init( ti_sdo_io_drivers_Generator_Params* prms ) 
{
    if (prms) {
        ti_sdo_io_drivers_Generator_Params__init__S(prms, 0, sizeof(ti_sdo_io_drivers_Generator_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sdo_io_drivers_Generator_Params_copy( ti_sdo_io_drivers_Generator_Params* dst, const ti_sdo_io_drivers_Generator_Params* src ) 
{
    if (dst) {
        ti_sdo_io_drivers_Generator_Params__init__S(dst, (xdc_Ptr)src, sizeof(ti_sdo_io_drivers_Generator_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sdo_io_drivers_Generator_Object_count() ti_sdo_io_drivers_Generator_Object__count__C

/* Object_sizeof */
#define ti_sdo_io_drivers_Generator_Object_sizeof() ti_sdo_io_drivers_Generator_Object__sizeof__C

/* Object_get */
static inline ti_sdo_io_drivers_Generator_Handle ti_sdo_io_drivers_Generator_Object_get( ti_sdo_io_drivers_Generator_Instance_State* oarr, int i ) 
{
    return (ti_sdo_io_drivers_Generator_Handle)ti_sdo_io_drivers_Generator_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sdo_io_drivers_Generator_Handle ti_sdo_io_drivers_Generator_Object_first( void )
{
    return (ti_sdo_io_drivers_Generator_Handle)ti_sdo_io_drivers_Generator_Object__first__S();
}

/* Object_next */
static inline ti_sdo_io_drivers_Generator_Handle ti_sdo_io_drivers_Generator_Object_next( ti_sdo_io_drivers_Generator_Object* obj )
{
    return (ti_sdo_io_drivers_Generator_Handle)ti_sdo_io_drivers_Generator_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label* ti_sdo_io_drivers_Generator_Handle_label( ti_sdo_io_drivers_Generator_Handle inst, xdc_runtime_Types_Label* lab )
{
    return ti_sdo_io_drivers_Generator_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline String ti_sdo_io_drivers_Generator_Handle_name( ti_sdo_io_drivers_Generator_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sdo_io_drivers_Generator_Handle__label__S(inst, &lab)->iname;
}

/* create */
static inline ti_sdo_io_drivers_Generator_Handle ti_sdo_io_drivers_Generator_create( const ti_sdo_io_drivers_Generator_Params* __prms, xdc_runtime_Error_Block* __eb )
{
    return (ti_sdo_io_drivers_Generator_Handle)ti_sdo_io_drivers_Generator_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(ti_sdo_io_drivers_Generator_Params), __eb);
}

/* construct */
static inline void ti_sdo_io_drivers_Generator_construct( ti_sdo_io_drivers_Generator_Struct* __obj, const ti_sdo_io_drivers_Generator_Params* __prms )
{
    ti_sdo_io_drivers_Generator_Object__create__S(__obj, sizeof (ti_sdo_io_drivers_Generator_Struct), 0, (const xdc_UChar*)__prms, sizeof(ti_sdo_io_drivers_Generator_Params), NULL);
}

/* delete */
static inline void ti_sdo_io_drivers_Generator_delete( ti_sdo_io_drivers_Generator_Handle* instp )
{
    ti_sdo_io_drivers_Generator_Object__delete__S(instp);
}

/* destruct */
static inline void ti_sdo_io_drivers_Generator_destruct( ti_sdo_io_drivers_Generator_Struct* obj )
{
    ti_sdo_io_drivers_Generator_Object__destruct__S(obj);
}

/* handle */
static inline ti_sdo_io_drivers_Generator_Handle ti_sdo_io_drivers_Generator_handle( ti_sdo_io_drivers_Generator_Struct* str )
{
    return (ti_sdo_io_drivers_Generator_Handle)str;
}

/* struct */
static inline ti_sdo_io_drivers_Generator_Struct* ti_sdo_io_drivers_Generator_struct( ti_sdo_io_drivers_Generator_Handle inst )
{
    return (ti_sdo_io_drivers_Generator_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sdo_io_drivers_Generator__top__
#undef __nested__
#endif

#endif /* ti_sdo_io_drivers_Generator__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sdo_io_drivers_Generator__internalaccess))

#ifndef ti_sdo_io_drivers_Generator__include_state
#define ti_sdo_io_drivers_Generator__include_state

/* Module_State */
struct ti_sdo_io_drivers_Generator_Module_State {
    char __dummy;
};

/* Module__state__V */
extern struct ti_sdo_io_drivers_Generator_Module_State__ ti_sdo_io_drivers_Generator_Module__state__V;

/* Object */
struct ti_sdo_io_drivers_Generator_Object {
    const ti_sdo_io_drivers_Generator_Fxns__* __fxns;
    __TA_ti_sdo_io_drivers_Generator_Instance_State__chans chans;
};

/* Module_State_chanList */
__extern __FAR__ const xdc_SizeT ti_sdo_io_drivers_Generator_Module_State_chanList__O;
static inline ti_sdo_utils_List_Handle ti_sdo_io_drivers_Generator_Module_State_chanList()
{
    return (ti_sdo_utils_List_Handle)(((char*)&ti_sdo_io_drivers_Generator_Module__state__V) + ti_sdo_io_drivers_Generator_Module_State_chanList__O);
}

#endif /* ti_sdo_io_drivers_Generator__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sdo_io_drivers_Generator__nolocalnames)

#ifndef ti_sdo_io_drivers_Generator__localnames__done
#define ti_sdo_io_drivers_Generator__localnames__done

/* module prefix */
#define Generator_Instance ti_sdo_io_drivers_Generator_Instance
#define Generator_Handle ti_sdo_io_drivers_Generator_Handle
#define Generator_Module ti_sdo_io_drivers_Generator_Module
#define Generator_Object ti_sdo_io_drivers_Generator_Object
#define Generator_Struct ti_sdo_io_drivers_Generator_Struct
#define Generator_GenFunc ti_sdo_io_drivers_Generator_GenFunc
#define Generator_NUMCHANS ti_sdo_io_drivers_Generator_NUMCHANS
#define Generator_ChanParams ti_sdo_io_drivers_Generator_ChanParams
#define Generator_ChanObj ti_sdo_io_drivers_Generator_ChanObj
#define Generator_Instance_State ti_sdo_io_drivers_Generator_Instance_State
#define Generator_Module_State ti_sdo_io_drivers_Generator_Module_State
#define Generator_E_nullParams ti_sdo_io_drivers_Generator_E_nullParams
#define Generator_Module_State_chanList ti_sdo_io_drivers_Generator_Module_State_chanList
#define Generator_Params ti_sdo_io_drivers_Generator_Params
#define Generator_open ti_sdo_io_drivers_Generator_open
#define Generator_open_fxnP ti_sdo_io_drivers_Generator_open_fxnP
#define Generator_open_FxnT ti_sdo_io_drivers_Generator_open_FxnT
#define Generator_close ti_sdo_io_drivers_Generator_close
#define Generator_close_fxnP ti_sdo_io_drivers_Generator_close_fxnP
#define Generator_close_FxnT ti_sdo_io_drivers_Generator_close_FxnT
#define Generator_submit ti_sdo_io_drivers_Generator_submit
#define Generator_submit_fxnP ti_sdo_io_drivers_Generator_submit_fxnP
#define Generator_submit_FxnT ti_sdo_io_drivers_Generator_submit_FxnT
#define Generator_control ti_sdo_io_drivers_Generator_control
#define Generator_control_fxnP ti_sdo_io_drivers_Generator_control_fxnP
#define Generator_control_FxnT ti_sdo_io_drivers_Generator_control_FxnT
#define Generator_simulateIsr ti_sdo_io_drivers_Generator_simulateIsr
#define Generator_Module_name ti_sdo_io_drivers_Generator_Module_name
#define Generator_Module_id ti_sdo_io_drivers_Generator_Module_id
#define Generator_Module_startup ti_sdo_io_drivers_Generator_Module_startup
#define Generator_Module_startupDone ti_sdo_io_drivers_Generator_Module_startupDone
#define Generator_Module_hasMask ti_sdo_io_drivers_Generator_Module_hasMask
#define Generator_Module_getMask ti_sdo_io_drivers_Generator_Module_getMask
#define Generator_Module_setMask ti_sdo_io_drivers_Generator_Module_setMask
#define Generator_Object_heap ti_sdo_io_drivers_Generator_Object_heap
#define Generator_Module_heap ti_sdo_io_drivers_Generator_Module_heap
#define Generator_construct ti_sdo_io_drivers_Generator_construct
#define Generator_create ti_sdo_io_drivers_Generator_create
#define Generator_handle ti_sdo_io_drivers_Generator_handle
#define Generator_struct ti_sdo_io_drivers_Generator_struct
#define Generator_Handle_label ti_sdo_io_drivers_Generator_Handle_label
#define Generator_Handle_name ti_sdo_io_drivers_Generator_Handle_name
#define Generator_Instance_init ti_sdo_io_drivers_Generator_Instance_init
#define Generator_Object_count ti_sdo_io_drivers_Generator_Object_count
#define Generator_Object_get ti_sdo_io_drivers_Generator_Object_get
#define Generator_Object_first ti_sdo_io_drivers_Generator_Object_first
#define Generator_Object_next ti_sdo_io_drivers_Generator_Object_next
#define Generator_Object_sizeof ti_sdo_io_drivers_Generator_Object_sizeof
#define Generator_Params_copy ti_sdo_io_drivers_Generator_Params_copy
#define Generator_Params_init ti_sdo_io_drivers_Generator_Params_init
#define Generator_delete ti_sdo_io_drivers_Generator_delete
#define Generator_destruct ti_sdo_io_drivers_Generator_destruct
#define Generator_Module_upCast ti_sdo_io_drivers_Generator_Module_upCast
#define Generator_Module_to_ti_sdo_io_IDriver ti_sdo_io_drivers_Generator_Module_to_ti_sdo_io_IDriver
#define Generator_Handle_upCast ti_sdo_io_drivers_Generator_Handle_upCast
#define Generator_Handle_to_ti_sdo_io_IDriver ti_sdo_io_drivers_Generator_Handle_to_ti_sdo_io_IDriver
#define Generator_Handle_downCast ti_sdo_io_drivers_Generator_Handle_downCast
#define Generator_Handle_from_ti_sdo_io_IDriver ti_sdo_io_drivers_Generator_Handle_from_ti_sdo_io_IDriver

#endif /* ti_sdo_io_drivers_Generator__localnames__done */
#endif
/*
 *  @(#) ti.sdo.io.drivers; 1, 0, 0, 0,1; 5-22-2012 16:17:35; /db/vtree/library/trees/ipc/ipc-h32/src/ xlibrary

 */

