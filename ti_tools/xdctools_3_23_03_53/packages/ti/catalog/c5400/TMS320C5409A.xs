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
 *  ======== TMS320C5409A.xs ========
 *
 */

/*
 *  ======== TMS320C5409A.getMemoryMap ========
 *  Returns the memory map as seen by a program running on this device
 *  when the registers are set as specified by the regs hash.
 */
function getMemoryMap(regs)
{
    if (regs == null) {
        regs = {};
    }
    if (!("pmst" in regs)) {
        regs.pmst = 0xffe0;
    }

    var memBlock = this.$module.memBlock;
    var map = this.memMap;
    
    /* care about MP/MC, OVLY bits only. */
    var pmst = (regs.pmst - 0) & 0x60;
    
    switch (pmst) {
        case 0x0:   /* MP/MC = 0, OVLY = 0 */
            map = [
                ["P_ROM", memBlock["P_ROM"]],
                ["VECT", memBlock["VECT"]],
                ["D_SPRAM", memBlock["D_SPRAM"]],
                ["D_DARAM", memBlock["D_DARAM"]]
            ];
            break;

        case 0x20:  /* MP/MC = 0, OVLY = 1 */
            map = [
                ["P_DARAM", memBlock["P_DARAM"]],
                ["P_ROM", memBlock["P_ROM"]],
                ["VECT", memBlock["VECT"]],
                ["D_SPRAM", memBlock["D_SPRAM"]],
                ["D_DARAM", memBlock["D_DARAM"]]
            ];
            break;

        case 0x40:  /* MP/MC = 1, OVLY = 0 */
            map = [
                ["D_SPRAM", memBlock["D_SPRAM"]],
                ["D_DARAM", memBlock["D_DARAM"]]
            ];
        break;

        case 0x60:  /* MP/MC = 1, OVLY = 1 */
            map = [
                ["P_DARAM", memBlock["P_DARAM"]],
                ["D_SPRAM", memBlock["D_SPRAM"]],
                ["D_DARAM", memBlock["D_DARAM"]],
            ];
            break;

        default: {
            map = [];
            break;
        }
    }

    return (map);
}
/*
 *  @(#) ti.catalog.c5400; 1, 0, 0, 0,390; 4-24-2012 14:55:59; /db/ztree/library/trees/platform/platform-n20x/src/
 */

