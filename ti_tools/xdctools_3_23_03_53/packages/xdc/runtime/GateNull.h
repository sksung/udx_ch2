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

#ifndef xdc_runtime_GateNull__include
#define xdc_runtime_GateNull__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_GateNull__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_GateNull___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IGateProvider.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Q_BLOCKING */
#define xdc_runtime_GateNull_Q_BLOCKING (1)

/* Q_PREEMPTING */
#define xdc_runtime_GateNull_Q_PREEMPTING (2)


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_GateNull_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__diagsEnabled xdc_runtime_GateNull_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_GateNull_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__diagsIncluded xdc_runtime_GateNull_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__xdc_runtime_GateNull_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__diagsMask xdc_runtime_GateNull_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_GateNull_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__gateObj xdc_runtime_GateNull_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_GateNull_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__gatePrms xdc_runtime_GateNull_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_GateNull_Module__id;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__id xdc_runtime_GateNull_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_GateNull_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__loggerDefined xdc_runtime_GateNull_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_GateNull_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__loggerObj xdc_runtime_GateNull_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_GateNull_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__loggerFxn0 xdc_runtime_GateNull_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_GateNull_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__loggerFxn1 xdc_runtime_GateNull_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_GateNull_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__loggerFxn2 xdc_runtime_GateNull_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_GateNull_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__loggerFxn4 xdc_runtime_GateNull_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_GateNull_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__loggerFxn8 xdc_runtime_GateNull_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_GateNull_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_GateNull_Module__startupDoneFxn xdc_runtime_GateNull_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_GateNull_Object__count;
__extern __FAR__ const CT__xdc_runtime_GateNull_Object__count xdc_runtime_GateNull_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_GateNull_Object__heap;
__extern __FAR__ const CT__xdc_runtime_GateNull_Object__heap xdc_runtime_GateNull_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_GateNull_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_GateNull_Object__sizeof xdc_runtime_GateNull_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_GateNull_Object__table;
__extern __FAR__ const CT__xdc_runtime_GateNull_Object__table xdc_runtime_GateNull_Object__table__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_GateNull_Params {
    size_t __size;
    const void* __self;
    void* __fxns;
    xdc_runtime_IInstance_Params* instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct xdc_runtime_GateNull_Struct {
    const xdc_runtime_GateNull_Fxns__* __fxns;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_GateNull_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Bool (*query)(xdc_Int);
    xdc_IArg (*enter)(xdc_runtime_GateNull_Handle);
    xdc_Void (*leave)(xdc_runtime_GateNull_Handle, xdc_IArg);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const xdc_runtime_GateNull_Fxns__ xdc_runtime_GateNull_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_GateNull_Module_startup( state ) -1

/* Instance_init__F */
xdc__CODESECT(xdc_runtime_GateNull_Instance_init__F, "xdc_runtime_GateNull_Instance_init")
__extern void xdc_runtime_GateNull_Instance_init__F( xdc_runtime_GateNull_Object*, const xdc_runtime_GateNull_Params* );

/* Instance_init__R */
xdc__CODESECT(xdc_runtime_GateNull_Instance_init__R, "xdc_runtime_GateNull_Instance_init")
__extern void xdc_runtime_GateNull_Instance_init__R( xdc_runtime_GateNull_Object*, const xdc_runtime_GateNull_Params* );

/* Handle__label__S */
xdc__CODESECT(xdc_runtime_GateNull_Handle__label__S, "xdc_runtime_GateNull_Handle__label")
__extern xdc_runtime_Types_Label* xdc_runtime_GateNull_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab );

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_GateNull_Module__startupDone__S, "xdc_runtime_GateNull_Module__startupDone")
__extern xdc_Bool xdc_runtime_GateNull_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(xdc_runtime_GateNull_Object__create__S, "xdc_runtime_GateNull_Object__create")
__extern xdc_Ptr xdc_runtime_GateNull_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar* __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb );

/* Object__delete__S */
xdc__CODESECT(xdc_runtime_GateNull_Object__delete__S, "xdc_runtime_GateNull_Object__delete")
__extern xdc_Void xdc_runtime_GateNull_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(xdc_runtime_GateNull_Object__destruct__S, "xdc_runtime_GateNull_Object__destruct")
__extern xdc_Void xdc_runtime_GateNull_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(xdc_runtime_GateNull_Object__get__S, "xdc_runtime_GateNull_Object__get")
__extern xdc_Ptr xdc_runtime_GateNull_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(xdc_runtime_GateNull_Object__first__S, "xdc_runtime_GateNull_Object__first")
__extern xdc_Ptr xdc_runtime_GateNull_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(xdc_runtime_GateNull_Object__next__S, "xdc_runtime_GateNull_Object__next")
__extern xdc_Ptr xdc_runtime_GateNull_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(xdc_runtime_GateNull_Params__init__S, "xdc_runtime_GateNull_Params__init")
__extern xdc_Void xdc_runtime_GateNull_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz );

/* query__E */
#define xdc_runtime_GateNull_query xdc_runtime_GateNull_query__E
xdc__CODESECT(xdc_runtime_GateNull_query__E, "xdc_runtime_GateNull_query")
__extern xdc_Bool xdc_runtime_GateNull_query__E( xdc_Int qual );
xdc__CODESECT(xdc_runtime_GateNull_query__F, "xdc_runtime_GateNull_query")
__extern xdc_Bool xdc_runtime_GateNull_query__F( xdc_Int qual );
__extern xdc_Bool xdc_runtime_GateNull_query__R( xdc_Int qual );

/* enter__E */
#define xdc_runtime_GateNull_enter xdc_runtime_GateNull_enter__E
xdc__CODESECT(xdc_runtime_GateNull_enter__E, "xdc_runtime_GateNull_enter")
__extern xdc_IArg xdc_runtime_GateNull_enter__E( xdc_runtime_GateNull_Handle __inst );
xdc__CODESECT(xdc_runtime_GateNull_enter__F, "xdc_runtime_GateNull_enter")
__extern xdc_IArg xdc_runtime_GateNull_enter__F( xdc_runtime_GateNull_Object* __inst );
__extern xdc_IArg xdc_runtime_GateNull_enter__R( xdc_runtime_GateNull_Handle __inst );

/* leave__E */
#define xdc_runtime_GateNull_leave xdc_runtime_GateNull_leave__E
xdc__CODESECT(xdc_runtime_GateNull_leave__E, "xdc_runtime_GateNull_leave")
__extern xdc_Void xdc_runtime_GateNull_leave__E( xdc_runtime_GateNull_Handle __inst, xdc_IArg key );
xdc__CODESECT(xdc_runtime_GateNull_leave__F, "xdc_runtime_GateNull_leave")
__extern xdc_Void xdc_runtime_GateNull_leave__F( xdc_runtime_GateNull_Object* __inst, xdc_IArg key );
__extern xdc_Void xdc_runtime_GateNull_leave__R( xdc_runtime_GateNull_Handle __inst, xdc_IArg key );


/*
 * ======== FUNCTION SELECTORS ========
 */

/* enter_{FxnT,fxnP} */
typedef xdc_IArg (*xdc_runtime_GateNull_enter_FxnT)(void*);
static inline xdc_runtime_GateNull_enter_FxnT xdc_runtime_GateNull_enter_fxnP( void )
{
    return (xdc_runtime_GateNull_enter_FxnT)xdc_runtime_GateNull_enter; 
}

/* leave_{FxnT,fxnP} */
typedef xdc_Void (*xdc_runtime_GateNull_leave_FxnT)(void*, xdc_IArg);
static inline xdc_runtime_GateNull_leave_FxnT xdc_runtime_GateNull_leave_fxnP( void )
{
    return (xdc_runtime_GateNull_leave_FxnT)xdc_runtime_GateNull_leave; 
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_IGateProvider_Module xdc_runtime_GateNull_Module_upCast( void )
{
    return (xdc_runtime_IGateProvider_Module)&xdc_runtime_GateNull_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IGateProvider */
#define xdc_runtime_GateNull_Module_to_xdc_runtime_IGateProvider xdc_runtime_GateNull_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_IGateProvider_Handle xdc_runtime_GateNull_Handle_upCast( xdc_runtime_GateNull_Handle i )
{
    return (xdc_runtime_IGateProvider_Handle)i;
}

/* Handle_to_xdc_runtime_IGateProvider */
#define xdc_runtime_GateNull_Handle_to_xdc_runtime_IGateProvider xdc_runtime_GateNull_Handle_upCast

/* Handle_downCast */
static inline xdc_runtime_GateNull_Handle xdc_runtime_GateNull_Handle_downCast( xdc_runtime_IGateProvider_Handle i )
{
    xdc_runtime_IGateProvider_Handle i2 = (xdc_runtime_IGateProvider_Handle)i;
    return (void*)i2->__fxns == (void*)&xdc_runtime_GateNull_Module__FXNS__C ? (xdc_runtime_GateNull_Handle)i : 0;
}

/* Handle_from_xdc_runtime_IGateProvider */
#define xdc_runtime_GateNull_Handle_from_xdc_runtime_IGateProvider xdc_runtime_GateNull_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_GateNull_Module_startupDone() xdc_runtime_GateNull_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_GateNull_Object_heap() xdc_runtime_GateNull_Object__heap__C

/* Module_heap */
#define xdc_runtime_GateNull_Module_heap() xdc_runtime_GateNull_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_GateNull_Module__id xdc_runtime_GateNull_Module_id( void ) 
{
    return xdc_runtime_GateNull_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool xdc_runtime_GateNull_Module_hasMask( void ) 
{
    return xdc_runtime_GateNull_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 xdc_runtime_GateNull_Module_getMask( void ) 
{
    return xdc_runtime_GateNull_Module__diagsMask__C != NULL ? *xdc_runtime_GateNull_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void xdc_runtime_GateNull_Module_setMask( xdc_Bits16 mask ) 
{
    if (xdc_runtime_GateNull_Module__diagsMask__C != NULL) *xdc_runtime_GateNull_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void xdc_runtime_GateNull_Params_init( xdc_runtime_GateNull_Params* prms ) 
{
    if (prms) {
        xdc_runtime_GateNull_Params__init__S(prms, 0, sizeof(xdc_runtime_GateNull_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void xdc_runtime_GateNull_Params_copy( xdc_runtime_GateNull_Params* dst, const xdc_runtime_GateNull_Params* src ) 
{
    if (dst) {
        xdc_runtime_GateNull_Params__init__S(dst, (xdc_Ptr)src, sizeof(xdc_runtime_GateNull_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define xdc_runtime_GateNull_Object_count() xdc_runtime_GateNull_Object__count__C

/* Object_sizeof */
#define xdc_runtime_GateNull_Object_sizeof() xdc_runtime_GateNull_Object__sizeof__C

/* Object_get */
static inline xdc_runtime_GateNull_Handle xdc_runtime_GateNull_Object_get( xdc_runtime_GateNull_Instance_State* oarr, int i ) 
{
    return (xdc_runtime_GateNull_Handle)xdc_runtime_GateNull_Object__get__S(oarr, i);
}

/* Object_first */
static inline xdc_runtime_GateNull_Handle xdc_runtime_GateNull_Object_first( void )
{
    return (xdc_runtime_GateNull_Handle)xdc_runtime_GateNull_Object__first__S();
}

/* Object_next */
static inline xdc_runtime_GateNull_Handle xdc_runtime_GateNull_Object_next( xdc_runtime_GateNull_Object* obj )
{
    return (xdc_runtime_GateNull_Handle)xdc_runtime_GateNull_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label* xdc_runtime_GateNull_Handle_label( xdc_runtime_GateNull_Handle inst, xdc_runtime_Types_Label* lab )
{
    return xdc_runtime_GateNull_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline String xdc_runtime_GateNull_Handle_name( xdc_runtime_GateNull_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return xdc_runtime_GateNull_Handle__label__S(inst, &lab)->iname;
}

/* create */
static inline xdc_runtime_GateNull_Handle xdc_runtime_GateNull_create( const xdc_runtime_GateNull_Params* __prms, xdc_runtime_Error_Block* __eb )
{
    return (xdc_runtime_GateNull_Handle)xdc_runtime_GateNull_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(xdc_runtime_GateNull_Params), __eb);
}

/* construct */
static inline void xdc_runtime_GateNull_construct( xdc_runtime_GateNull_Struct* __obj, const xdc_runtime_GateNull_Params* __prms )
{
    xdc_runtime_GateNull_Object__create__S(__obj, sizeof (xdc_runtime_GateNull_Struct), 0, (const xdc_UChar*)__prms, sizeof(xdc_runtime_GateNull_Params), NULL);
}

/* delete */
static inline void xdc_runtime_GateNull_delete( xdc_runtime_GateNull_Handle* instp )
{
    xdc_runtime_GateNull_Object__delete__S(instp);
}

/* destruct */
static inline void xdc_runtime_GateNull_destruct( xdc_runtime_GateNull_Struct* obj )
{
    xdc_runtime_GateNull_Object__destruct__S(obj);
}

/* handle */
static inline xdc_runtime_GateNull_Handle xdc_runtime_GateNull_handle( xdc_runtime_GateNull_Struct* str )
{
    return (xdc_runtime_GateNull_Handle)str;
}

/* struct */
static inline xdc_runtime_GateNull_Struct* xdc_runtime_GateNull_struct( xdc_runtime_GateNull_Handle inst )
{
    return (xdc_runtime_GateNull_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_GateNull__top__
#undef __nested__
#endif

#endif /* xdc_runtime_GateNull__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(xdc_runtime_GateNull__internalaccess))

#ifndef xdc_runtime_GateNull__include_state
#define xdc_runtime_GateNull__include_state

/* Object */
struct xdc_runtime_GateNull_Object {
    const xdc_runtime_GateNull_Fxns__* __fxns;
};

#endif /* xdc_runtime_GateNull__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_GateNull__nolocalnames)

#ifndef xdc_runtime_GateNull__localnames__done
#define xdc_runtime_GateNull__localnames__done

/* module prefix */
#define GateNull_Instance xdc_runtime_GateNull_Instance
#define GateNull_Handle xdc_runtime_GateNull_Handle
#define GateNull_Module xdc_runtime_GateNull_Module
#define GateNull_Object xdc_runtime_GateNull_Object
#define GateNull_Struct xdc_runtime_GateNull_Struct
#define GateNull_Q_BLOCKING xdc_runtime_GateNull_Q_BLOCKING
#define GateNull_Q_PREEMPTING xdc_runtime_GateNull_Q_PREEMPTING
#define GateNull_Instance_State xdc_runtime_GateNull_Instance_State
#define GateNull_Params xdc_runtime_GateNull_Params
#define GateNull_query xdc_runtime_GateNull_query
#define GateNull_enter xdc_runtime_GateNull_enter
#define GateNull_enter_fxnP xdc_runtime_GateNull_enter_fxnP
#define GateNull_enter_FxnT xdc_runtime_GateNull_enter_FxnT
#define GateNull_leave xdc_runtime_GateNull_leave
#define GateNull_leave_fxnP xdc_runtime_GateNull_leave_fxnP
#define GateNull_leave_FxnT xdc_runtime_GateNull_leave_FxnT
#define GateNull_Module_name xdc_runtime_GateNull_Module_name
#define GateNull_Module_id xdc_runtime_GateNull_Module_id
#define GateNull_Module_startup xdc_runtime_GateNull_Module_startup
#define GateNull_Module_startupDone xdc_runtime_GateNull_Module_startupDone
#define GateNull_Module_hasMask xdc_runtime_GateNull_Module_hasMask
#define GateNull_Module_getMask xdc_runtime_GateNull_Module_getMask
#define GateNull_Module_setMask xdc_runtime_GateNull_Module_setMask
#define GateNull_Object_heap xdc_runtime_GateNull_Object_heap
#define GateNull_Module_heap xdc_runtime_GateNull_Module_heap
#define GateNull_construct xdc_runtime_GateNull_construct
#define GateNull_create xdc_runtime_GateNull_create
#define GateNull_handle xdc_runtime_GateNull_handle
#define GateNull_struct xdc_runtime_GateNull_struct
#define GateNull_Handle_label xdc_runtime_GateNull_Handle_label
#define GateNull_Handle_name xdc_runtime_GateNull_Handle_name
#define GateNull_Instance_init xdc_runtime_GateNull_Instance_init
#define GateNull_Object_count xdc_runtime_GateNull_Object_count
#define GateNull_Object_get xdc_runtime_GateNull_Object_get
#define GateNull_Object_first xdc_runtime_GateNull_Object_first
#define GateNull_Object_next xdc_runtime_GateNull_Object_next
#define GateNull_Object_sizeof xdc_runtime_GateNull_Object_sizeof
#define GateNull_Params_copy xdc_runtime_GateNull_Params_copy
#define GateNull_Params_init xdc_runtime_GateNull_Params_init
#define GateNull_Instance_State xdc_runtime_GateNull_Instance_State
#define GateNull_delete xdc_runtime_GateNull_delete
#define GateNull_destruct xdc_runtime_GateNull_destruct
#define GateNull_Module_upCast xdc_runtime_GateNull_Module_upCast
#define GateNull_Module_to_xdc_runtime_IGateProvider xdc_runtime_GateNull_Module_to_xdc_runtime_IGateProvider
#define GateNull_Handle_upCast xdc_runtime_GateNull_Handle_upCast
#define GateNull_Handle_to_xdc_runtime_IGateProvider xdc_runtime_GateNull_Handle_to_xdc_runtime_IGateProvider
#define GateNull_Handle_downCast xdc_runtime_GateNull_Handle_downCast
#define GateNull_Handle_from_xdc_runtime_IGateProvider xdc_runtime_GateNull_Handle_from_xdc_runtime_IGateProvider

#endif /* xdc_runtime_GateNull__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,375; 4-27-2012 14:30:33; /db/ztree/library/trees/xdc/xdc-y25x/src/packages/
 */

