/*
 *  Copyright 2012 by Texas Instruments Incorporated.
 *
 */

/*
 *  ======== C54.h ========
 *  DO NOT MODIFY: This header is generated from stddef.xdt
 *
 *  This header contains target-specific definitions of target-independent
 *  macros required by the ITarget interface.  These definitions allow C/C++
 *  sources to portably compile for multiple targets (using #ifdef ...).
 */
#ifndef xdc_target_macros_include__
#define xdc_target_macros_include__    1

/*
 *  ======== ti_targets_C54 ========
 *  This macro identifies the specific target being used.  This macro should
 *  probably be avoided in portable sources.
 */
#define ti_targets_C54  1

/*
 *  ======== xdc_target__isaCompatible_* macros ========
 *  The following definitions enable clients to conditionally compile for any
 *  compatible subset of the actual target ISA.
 */
#define xdc_target__isaCompatible_54  1

/*
 *  ======== xdc_target__isa_54 ========
 *  This macro identifies the specific target ISA for which we are being
 *  compiled.
 */
#define xdc_target__isa_54  1

/*
 *  ======== xdc_target__os_undefined ========
 *  The following macro enables clients to portably compile for target specific
 *  OS; e.g., Linux, Solaris, Windows, undefined.
 */
#define xdc_target__os_undefined    1

/*
 *  ======== xdc_target__sizeof_ ========
 *  The following macros enable clients to portably determine type sizes
 *  within #ifdef blocks; sizeof() can't be used and the definitions in
 *  stdint.h are not available to C++ clients (unless the special macro
 *  __STDC_LIMIT_MACROS is defined).
 */
#define  xdc_target__sizeof_IArg 2
#define  xdc_target__sizeof_Char 1
#define  xdc_target__sizeof_Double 2
#define  xdc_target__sizeof_Float 2
#define  xdc_target__sizeof_Fxn 1
#define  xdc_target__sizeof_Int 1
#define  xdc_target__sizeof_Int8 1
#define  xdc_target__sizeof_Int16 1
#define  xdc_target__sizeof_Int32 2
#define  xdc_target__sizeof_Long 2
#define  xdc_target__sizeof_LDouble 2
#define  xdc_target__sizeof_Ptr 1
#define  xdc_target__sizeof_Short 1
#define  xdc_target__sizeof_Size 1

/*
 *  ======== xdc_target__alignof_ ========
 *  The following macros enable clients to portably determine type alignment
 *  within #ifdef blocks; even if provided by the compiler, alignof() can't
 *  be used in pre-processor statements.
 */
#define  xdc_target__alignof_IArg 2
#define  xdc_target__alignof_Char 1
#define  xdc_target__alignof_Double 2
#define  xdc_target__alignof_Float 2
#define  xdc_target__alignof_Fxn 1
#define  xdc_target__alignof_Int 1
#define  xdc_target__alignof_Int8 1
#define  xdc_target__alignof_Int16 1
#define  xdc_target__alignof_Int32 2
#define  xdc_target__alignof_Long 2
#define  xdc_target__alignof_LDouble 2
#define  xdc_target__alignof_Ptr 1
#define  xdc_target__alignof_Short 1
#define  xdc_target__alignof_Size 1

/*
 *  ======== xdc_target__bitsPerChar ========
 *  The number of bits in a char.  This macro allow one to determine the
 *  precise number of bits in any of the standard types (whose sizes are
 *  expressed as a number of chars).
 */
#define  xdc_target__bitsPerChar 16

#endif  /* end multi-include guard */
/*
 *  @(#) ti.targets; 1, 0, 3,531; 4-27-2012 17:07:35; /db/ztree/library/trees/xdctargets/xdctargets-f21x/src/ xlibrary

 */

