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
function getLibs(prog)
{
    var libs = "lib/" + this.$name + ".a" + prog.build.target.suffix;

    if (prog.build.cfgScript == null || !prog.build.cfgScript.match(/\.tcf$/)) {
        libs += ";lib/boot.a" + prog.build.target.suffix;
    }

    return (libs);
}
/*
 *  @(#) ti.targets.rts5500; 1, 0, 0, 0,364; 4-27-2012 17:32:32; /db/ztree/library/trees/xdctargets/xdctargets-f21x/src/ xlibrary

 */

