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
    var Utils = xdc.useModule('xdc.platform.Utils');
    var args = this.$private.args;

    if (args.verbose > 0) {
        print(this.$module.$name + "('"
            + this.$private.name + "') selecting ExeContext for program '"
            + prog.name + "' ...");
        print("    endian = "    + prog.endian);
        print("    codeModel = " + prog.codeModel);
        print("    cpuId = "   + prog.build.cpuId);
    }

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
            return ("$(SHELL) " + gdb.packageBase + "/gdbexec $(1) " + 
                prog.name);
        }
        catch (e) {
            return("@$(ECHO) " + this.$package.$name + " platform package " +
                   "cannot execute " + prog.name + " on " + os + "\n" +
                   updateComment);
        }
    }
    else if (os == "Windows") {
        try {
            var exec = xdc.loadPackage("ti.platforms.utils.exec");
        }
        catch (e) {
            return("@$(ECHO) " + this.$package.$name + " platform package " +
                   "cannot execute " + prog.name + " on " + os + "\n" +
                   updateComment);
        }
        if (this.ftpath == undefined || this.ftpath == null) {
            return("@$(ECHO) Path to FTSuite installation must be set in " +
              "config.bld to execute programs on " + prog.platformName +
              ".\n\t:");
        }

        var command = exec.Settings.getLibraryPath(os, this.ftpath);

        var executable = exec.Settings.getExecutable(os);
        var driverAPI = "tsi";
        var verbose = "-v";
        var timeout = 32000;
        /* check execArgs for options */
        if (prog.build.test.execArgs != undefined) {
            var opts = prog.build.test.execArgs.split(/\s+/);
            for (var i = 0; i < opts.length; i++) {
                if (opts[i] == "-v") {
                    verbose = opts[i];
                }
                if (opts[i] == "-t" && typeof(opts[i+1]) != undefined) {
                    timeout = opts[i+1] - 0;
                } 
            }
        }

        command += executable + " -a " + driverAPI;
        command += " -s -t " + timeout + " -r -n :TMS320C6713 " + verbose;

        command += " -b " + this.ftpath + "/targetdb/XDS560_C6713.xml";
        command += " -u 127.0.0.1";

        command += " -i " + this.$package.packageBase + "Init.x67";
        
        var dllExt = os == "Windows" ? ".dll" : ".so";
        var canPath = java.io.File(prog.name).getCanonicalPath() + "";
        canPath = canPath.replace(/\\/g, "/");
            
        command += " -x " + this.ftpath + "/target_server/bin/" + 
                   "ti_targetserver_dvr" + dllExt + " -e _abort " + canPath;
        return(command);
    }
    else {
        return("@$(ECHO) " + this.$package.$name + " platform package " +
               "cannot execute " + java.io.File(prog.name).getCanonicalPath() +
               " on " + os + "\n" + updateComment);
    }
}

/*
 *  ======== Platform.getLinkTemplate ========
 *  This Platform's implementation xdc.platform.IPlatform.getLinkTemplate
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
function instance$meta$init(name, args)
{
    /* cache the platform creation args and platform instance name for the
     * getExeContext method above.
     */
    this.$private.args = this.$args.args;    /* instance args structure */
    this.$private.name = this.$args.name;    /* instance name */

    if (args != null) {
        if ("sectMap" in args) {
            this.sectMap = args.sectMap;
        }

        if ("customMemoryMap" in args) {
            this.customMemoryMap = args.customMemoryMap;
        }
        
        if ("renameMap" in args) {
            this.renameMap = args.renameMap;
        }
        
        if ("externalMemoryMap" in args) {
            this.$module.$logError("External memory cannot be changed on " +
                "this platform", this, null); 
        }
        
        /* Check for FTSuite installation to determine if the platform can 
         * run exec.
         */
        if ("ftpath" in args) {
            this.ftpath = args.ftpath;
        }
        
        if("codeMemory" in args) {
            this.codeMemory = args.codeMemory;  
        }

        if("dataMemory" in args) {
            this.dataMemory = args.dataMemory;  
        }

        if("stackMemory" in args) {
            this.stackMemory = args.stackMemory;
        }
    }
};
/*
 *  @(#) ti.platforms.dsk6713; 1, 0, 0,367; 4-24-2012 14:56:43; /db/ztree/library/trees/platform/platform-n20x/src/
 */

