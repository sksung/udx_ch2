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
 *  ======== package.xs ========
 */

/*
 *  ======== init ========
 */
function init()
{
}

/*
 *  ======== close ========
 */
function close()
{
}

/*
 *  ======== validate ========
 */
function validate()
{
    for (var sym in Program.symbol) {
        var obj = Program.symbol[sym];

        if (typeof(obj) == 'number'
	    || ('$category' in obj && obj.$category == 'Instance')) {
	    continue;
	}

        Program.$logError("value of symbol '" + sym +
            "' must be a number or instance object", Program);
    }
    
    var map = Program.getSectMap();
    
    for (var key in map) {
        if (map[key].loadSegment != null && map[key].loadSegment != undefined &&
            map[key].loadAddress != null && map[key].loadAddress != undefined) {
            Program.$logError("Section '" + key + "' defines both loadSegment "
            + "and loadAddress.", Program);
        }
        if (map[key].runSegment != null && map[key].runSegment != undefined &&
            map[key].runAddress != null && map[key].runAddress != undefined) {
            Program.$logError("Section '" + key + "' defines both runSegment " +
            "and runAddress.", Program);
        }
        if (map[key].loadAlign != null && map[key].loadAlign != undefined &&
            map[key].loadAddress != null && map[key].loadAddress != undefined) {
            Program.$logError("Section '" + key + "' defines both loadAlign "
            + "and loadAddress.", Program);
        }
        if (map[key].runAlign != null && map[key].runAlign != undefined &&
            map[key].runAddress != null && map[key].runAddress != undefined) {
            Program.$logError("Section '" + key + "' defines both runAlign " +
            "and runAddress.", Program);
        }
    }
    
}
/*
 *  @(#) xdc.cfg; 1, 0, 2, 0,376; 4-27-2012 14:30:17; /db/ztree/library/trees/xdc/xdc-y25x/src/packages/
 */

