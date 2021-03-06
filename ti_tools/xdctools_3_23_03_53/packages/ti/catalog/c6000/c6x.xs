/*
 *  Copyright (c) 2012 by Texas Instruments and others.
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
 *  ======== init6x1xMap ========
 *  Initialize memory map for an instance of a C6x1x data sheet
 */
function init6x1xMap(inst, memSize, regs)
{
    var map = inst.memMap;
    map["IRAM"].len = memSize;
    
    if (regs != null && "l2Mode" in regs && regs.l2Mode != null) {
        var cacheSize = inst.$module.cacheSize;
        if (cacheSize[regs.l2Mode] != undefined) {
            map["IRAM"].len -= cacheSize[regs.l2Mode];
        }
        else {
            throw Error(regs.l2Mode + " is an incorrect value for l2Mode");
        }
    }

    return (map);
}
/*
 *  @(#) ti.catalog.c6000; 1, 0, 0, 0,390; 4-24-2012 14:56:08; /db/ztree/library/trees/platform/platform-n20x/src/
 */

