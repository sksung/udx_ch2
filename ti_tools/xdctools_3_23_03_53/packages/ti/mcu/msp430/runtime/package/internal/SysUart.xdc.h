/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y23
 */

#ifndef ti_mcu_msp430_runtime_SysUart__INTERNAL__
#define ti_mcu_msp430_runtime_SysUart__INTERNAL__

#ifndef ti_mcu_msp430_runtime_SysUart__internalaccess
#define ti_mcu_msp430_runtime_SysUart__internalaccess
#endif

#include <ti/mcu/msp430/runtime/SysUart.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* abort */
#undef ti_mcu_msp430_runtime_SysUart_abort
#define ti_mcu_msp430_runtime_SysUart_abort ti_mcu_msp430_runtime_SysUart_abort__F

/* exit */
#undef ti_mcu_msp430_runtime_SysUart_exit
#define ti_mcu_msp430_runtime_SysUart_exit ti_mcu_msp430_runtime_SysUart_exit__F

/* flush */
#undef ti_mcu_msp430_runtime_SysUart_flush
#define ti_mcu_msp430_runtime_SysUart_flush ti_mcu_msp430_runtime_SysUart_flush__F

/* putch */
#undef ti_mcu_msp430_runtime_SysUart_putch
#define ti_mcu_msp430_runtime_SysUart_putch ti_mcu_msp430_runtime_SysUart_putch__F

/* ready */
#undef ti_mcu_msp430_runtime_SysUart_ready
#define ti_mcu_msp430_runtime_SysUart_ready ti_mcu_msp430_runtime_SysUart_ready__F

/* rxtxInit */
#define SysUart_rxtxInit ti_mcu_msp430_runtime_SysUart_rxtxInit__I

/* tx */
#define SysUart_tx ti_mcu_msp430_runtime_SysUart_tx__I

/* rx */
#define SysUart_rx ti_mcu_msp430_runtime_SysUart_rx__I

/* Module_startup */
#undef ti_mcu_msp430_runtime_SysUart_Module_startup
#define ti_mcu_msp430_runtime_SysUart_Module_startup ti_mcu_msp430_runtime_SysUart_Module_startup__F

/* Instance_init */
#undef ti_mcu_msp430_runtime_SysUart_Instance_init
#define ti_mcu_msp430_runtime_SysUart_Instance_init ti_mcu_msp430_runtime_SysUart_Instance_init__F

/* Instance_finalize */
#undef ti_mcu_msp430_runtime_SysUart_Instance_finalize
#define ti_mcu_msp430_runtime_SysUart_Instance_finalize ti_mcu_msp430_runtime_SysUart_Instance_finalize__F

/* module */
#define SysUart_module ((ti_mcu_msp430_runtime_SysUart_Module_State *)(xdc__MODOBJADDR__(ti_mcu_msp430_runtime_SysUart_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_mcu_msp430_runtime_SysUart__cplusplus)
#define module ((ti_mcu_msp430_runtime_SysUart_Module_State *)(xdc__MODOBJADDR__(ti_mcu_msp430_runtime_SysUart_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_mcu_msp430_runtime_SysUart_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_mcu_msp430_runtime_SysUart_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_mcu_msp430_runtime_SysUart_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_mcu_msp430_runtime_SysUart_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_mcu_msp430_runtime_SysUart_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_mcu_msp430_runtime_SysUart_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_mcu_msp430_runtime_SysUart_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_mcu_msp430_runtime_SysUart_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_mcu_msp430_runtime_SysUart_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_mcu_msp430_runtime_SysUart_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_mcu_msp430_runtime_SysUart_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_mcu_msp430_runtime_SysUart_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_mcu_msp430_runtime_SysUart_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_mcu_msp430_runtime_SysUart_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_mcu_msp430_runtime_SysUart_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_mcu_msp430_runtime_SysUart_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_mcu_msp430_runtime_SysUart_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_mcu_msp430_runtime_SysUart_Module_GateProxy_query


#endif /* ti_mcu_msp430_runtime_SysUart__INTERNAL____ */
