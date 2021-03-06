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
var coffUtils = xdc.loadCapsule("ti/targets/linkUtils.xs");

function genElfSections(prog)
{
    var nonSplitable = {
        ".bss": 1,
        ".init_array": 1,
        ".cinit": 1,
        ".const":1,
        ".stack": 1,
        ".sysstack": 1,
        ".sysmem": 1,
        ".esysmem": 1,
        ".fardata": 1,
        ".ti.decompress": 1,
        ".ti.handler_table": 1
    };
    var res = "";

    /* the section map is constructed from the target and program info */
    var sectMap = prog.getSectMap();
    
    if (sectMap['xdc.meta'] == undefined) {
        sectMap['xdc.meta'] = new prog.SectionSpec(sectMap[".const"]);
        sectMap['xdc.meta'].type = "COPY";
    }

    if ("xdc.runtime" in xdc.om && xdc.om['xdc.runtime.Text'].isLoaded != true
        && sectMap['xdc.noload'] == undefined) {
        sectMap['xdc.noload'] = new prog.SectionSpec(sectMap[".text"]);
        sectMap['xdc.noload'].type = "COPY";
    }

    if (sectMap['.args'] != undefined) {
        sectMap['.args'].loadAlign = 4;
        sectMap['.args'].runAlign = 4;
    }

    /* if the target version is 0, this is an *old* compiler/linker that
     * probably does not support splitting; we may need a more precise
     * target-specific heuristic.
     */
    var targetVers = prog.build.target.version.split(',')[2] - 0;
    var useSplit = targetVers > 0;
    var bssGroupDone = false;
    var exclude = ("sectionsExclude" in prog)
                    ? new RegExp(prog.sectionsExclude): null;
    for (var sn in sectMap) {
        if (exclude != null && sn.match(exclude) != null) {
            /* don't generate this section; the user will take care of this */
            continue;   
        }
        if (sn == ".bss" || sn == ".rodata" || sn == ".data") {
            if (!bssGroupDone) {
                var allocation = coffUtils.sectLine(sectMap, sn, ">");
                allocation = allocation.replace(sn, "GROUP");
                res += "    " + allocation + "\n    {\n";
                res += "        " + ".bss:\n";
                res += "        " + ".rodata:\n";
                res += "        " + ".data:\n";
                res += "    }\n";
                bssGroupDone = true;

                /* Check if .bss, .rodata, and .data could go to the same
                 * segment if we did not force them as above. The problem
                 * could happen only if both of them were allocated to using
                 * 'sectMap', but to two different segments.
                 */
                if (sectMap[".data"] != null) {
                    var dataAlloc =
                        coffUtils.sectLine(sectMap, ".data", ">");
                    dataAlloc = dataAlloc.replace(".data", "");
                }
                else {
                    var dataAlloc = coffUtils.sectLine(sectMap, sn, ">");
                    dataAlloc = dataAlloc.replace(sn, "");
                }
                if (sectMap[".bss"] != null) {
                    var bssAlloc = coffUtils.sectLine(sectMap, ".bss", ">");
                    bssAlloc = bssAlloc.replace(".bss", "");
                }
                else {
                    var bssAlloc = coffUtils.sectLine(sectMap, sn, ">");
                    bssAlloc = bssAlloc.replace(sn, "");
                }
                if (sectMap[".rodata"] != null) {
                    var roAlloc = coffUtils.sectLine(sectMap, ".rodata", ">");
                    roAlloc = roAlloc.replace(".rodata", "");
                }
                else {
                    var roAlloc = coffUtils.sectLine(sectMap, sn, ">");
                    roAlloc = roAlloc.replace(sn, "");
                }
                if(!(bssAlloc == dataAlloc && bssAlloc == roAlloc)) {
                    throw new Error("Allocations for sections '.bss', '.rodata'"
                        + " and '.data' must be same.");
                }
            }
        }
        else if (sn in nonSplitable) {
            res += "    " + coffUtils.sectLine(sectMap, sn, ">") + "\n";
        }
        else if (sn == ".args") {
            var argsFill = ", fill = 0";
            res += "    " + coffUtils.sectLine(sectMap, sn, ">") + argsFill 
                + " {_argsize = " + utils.toHex(prog.argSize) + "; }\n";
        }
        else {
            res += "    "
                + coffUtils.sectLine(sectMap, sn, useSplit ? ">>" : ">") + "\n";
        }
    }

    /* filter content using Program.sectionsTemplate */
    if ("sectionsTemplate" in prog && prog.sectionsTemplate != null) {
        var tplt = xdc.loadTemplate(prog.sectionsTemplate);
        var bout = new java.io.ByteArrayOutputStream();
        var out = new java.io.PrintStream(bout);
        tplt.genStream(out, prog, [sectMap, res]);
        res = bout.toString();
    }

    return (res);
}

/*
 *  ======== genElfSymbols ========
 *
 *  This function generates some additional symbols for arp32 ELF builds, which
 *  are automatically generated by the linker in C6x ELF builds. The purpose
 *  of adding these symbols here is to enable users relying on those symbols
 *  to use them independently from the object file format.
 */
function genElfSymbols(prog)
{
    var res = "/* ARP32 Elf symbols */\n--symbol_map __TI_STACK_BASE=_stack\n";
    return (res);
}
/*
 *  @(#) ti.targets.elf.arp32; 1, 0, 0,70; 4-27-2012 17:32:04; /db/ztree/library/trees/xdctargets/xdctargets-f21x/src/ xlibrary

 */

