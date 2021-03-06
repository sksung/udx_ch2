/* 
 *  Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *      Texas Instruments - initial implementation
 * 
 * */

/*
 *  ======== microsoft/targets/arm/std.h ========
 *
 */

/*
 *  ======== microsoft/targets/arm/std.h ========
 *  Standard types for supported Microsoft Arm compilers
 */

#ifndef microsoft_targets_arm_STD_
#define microsoft_targets_arm_STD_

/*  Define target-specific "portable" macros
 *
 *  The build command-line define xdc_target_name__ to be the value
 *  of the target's name config parameter.  We use this to include the
 *  target-specific definitions for the required target-independent
 *  xdc_target* macros.
 */
#if defined(xdc_target_name__) & !defined(xdc_target_macros_include__)
#include xdc__local_include(xdc_target_name__)
#endif

/* "inherit" (i.e., include) all microsoft.targets standard types */
#include <microsoft/targets/std.h>

#endif /* ti_targets_arm_STD_ */
/*
 *  @(#) microsoft.targets.arm; 1, 0, 0, 0,286; 4-27-2012 17:07:30; /db/ztree/library/trees/xdctargets/xdctargets-f21x/src/ xlibrary

 */

