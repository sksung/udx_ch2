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
 *  ======== Platform.xs ========
 *
 */

var Boot = null;

/*
 *  ======== module$meta$init ========
 */
function module$meta$init()
{
    if (xdc.om.$name != "cfg") {                                                
        return;                                                                 
    } 

    Boot = xdc.useModule('ti.catalog.c2800.init.Boot');

    Boot.disableWatchdog = true;
    Boot.pllType = Boot.Type_2802x_2803x_2806x;
    Boot.configurePll = true;
    Boot.pllOSCCLK = 30;
    Boot.pllcrDIV = 10;
    Boot.pllstsDIVSEL = 2;
}

/*
 *  ======== module$use ========
 */
function module$use()
{
    /* 
     * Force the boot code into internal memory so that it 
     * can safely configure the XINTF
     */
    if (Program.sectMap[".text:.bootCodeSection"] === undefined) {
        Program.sectMap[".text:.bootCodeSection"] = new Program.SectionSpec();
        Program.sectMap[".text:.bootCodeSection"].loadSegment = "L47SARAM";
    }
}

/*
 *  ======== Platform.getCpuDataSheet ========
 *  This Platform's implementation xdc.platform.IPlatform.getCpuDataSheet.
 *
 *  Return the xdc.platform.ICpuDataSheet.Instance object that corresponds
 *  to the device that runs executables loaded on the specified cpuId.
 */
function getCpuDataSheet(cpuId)
{
    var Utils = xdc.useModule('xdc.platform.Utils');
    return (Utils.getCpuDataSheet(this.$module.CPU));
}

/*
 *  ======== Platform.getCreateArgs ========
 */
function getCreateArgs()
{
    return (this.$private.args);
}

/*
 *  ======== Platform.getExeContext ========
 *  This Platform's implementation xdc.platform.IPlatform.getExeContext.
 *
 *  Return the xdc.platform.IPlatform.ExeContext object that will run the 
 *  specified program prog.
 */
function getExeContext(prog)
{
    var Utils = xdc.module("xdc.platform.Utils");

    var args = this.$private.args;

    var ExeContext = xdc.useModule('xdc.platform.ExeContext');

    /* create a default ExeContext execution context */
    var cpu = ExeContext.create(this.$module.CPU, this.$module.BOARD);

    /* Set the initial memory map from the cpu datasheet. Check if the user
     * tried to set cpuArgs, and if it's the case print a deprecation
     * warning message.
     */
    if (prog.build.cpuArgs != null) {
        this.$module.$logWarning("The parameter 'cpuArgs' in xdc.bld.Executable " +
            "is deprecated and will not be supported in future releases. " +
            "Please, use corresponding platform instance parameters to set " +
            "the initial register settings.", this.$module, null);
        
        for (var prop in prog.build.cpuArgs) {
            if (!(prop in this.$private.args)) {
                this.$private.args[prop] = prog.build.cpuArgs[prop];
            }
        }
    }
    cpu.memoryMap = Utils.assembleMemoryMap(cpu, this);

    for (var i = 0; i < cpu.memoryMap.length; i++) {
        if (cpu.memoryMap[i].page == null) {
            if (cpu.memoryMap[i].name == "PIEVECT") {
                cpu.memoryMap[i].page = 1;
            }
            else {
                cpu.memoryMap[i].page = 0;
            }
        }
    }

    // check for the overlap in the memory map
    var overlap = Utils.checkOverlap(cpu.memoryMap);

    if (overlap != null) {
        this.$module.$logError("Memory objects " + overlap + " overlap", this,
            overlap);
    }

    Utils.checkDefaults(this, cpu.memoryMap);
    this.$seal();
    
    return (cpu);
}

/*
 *  ======== Platform.getExecCmd ========
 *  This Platform's implementation xdc.platform.IPlatform.getExecCmd.
 */
function getExecCmd(prog)
{
    var os = environment["xdc.hostOS"];
    var updateComment = "@$(ECHO) Check for updates to this package at:\n" +
    "@$(ECHO) https://www-a.ti.com/downloads/sds_support/targetcontent/rtsc/index.html"
    + "\n\t:";

    if (os == "Solaris") {
        try {
            var gdb = xdc.loadPackage("ti.platforms.utils.gdb");
            return ("$(SHELL) " + gdb.packageBase + "/gdbexec $(1) "
                + prog.name);
        }
        catch (e) {
            return("@$(ECHO) " + this.$package.$name + " platform package " +
                "cannot execute " + prog.name + " on " + os + "\n" +
                 updateComment);
        }
    }
    else if (os == "Windows") {
        return("cscript runtest.js " + 
               java.io.File(prog.name).getCanonicalPath());
    }
    else {
        return("@$(ECHO) " + this.$package.$name + " platform package " +
               "cannot execute " + java.io.File(prog.name).getCanonicalPath() +
               " on " + os + "\n" + updateComment);
    }
}

/*
 *  ======== Platform.getLinkTemplate ========
 *  This is Platform's implementation xdc.platform.IPlatform.getLinkTemplate
 */
function getLinkTemplate(prog)
{
    return ("ti/targets/linkcmd.xdt");
}

/*
 *  ======== Platform.Instance.init ========
 *  This function is called to initialize a newly created instance of a
 *  platform.  Platform instances are created just prior to running
 *  program configuration scripts.
 *
 *  Platform instances may also be created in the build domain.
 *
 *  this.$args.args is the object configured in config.bld via
 *  Build.platformTable.  This is an untyped object that may specify
 *  platform specific parameters.
 *
 *  this.$args.name is the name used to identify this instance (without
 *  the package name prefix).
 */
function instance$meta$init(name)
{
    /* cache the platform instance name for the
     * getExeContext method above.
     */
    this.$private.name = this.$args.name;    /* instance name */
};
/*
 *  @(#) ti.platforms.control28335; 1, 0, 0,177; 4-24-2012 14:56:21; /db/ztree/library/trees/platform/platform-n20x/src/
 */

