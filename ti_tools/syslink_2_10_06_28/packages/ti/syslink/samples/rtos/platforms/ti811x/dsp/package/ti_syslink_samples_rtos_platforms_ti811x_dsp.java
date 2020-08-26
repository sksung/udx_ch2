/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y25
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class ti_syslink_samples_rtos_platforms_ti811x_dsp
{
    static final String VERS = "@(#) xdc-y25\n";

    static final Proto.Elm $$T_Bool = Proto.Elm.newBool();
    static final Proto.Elm $$T_Num = Proto.Elm.newNum();
    static final Proto.Elm $$T_Str = Proto.Elm.newStr();
    static final Proto.Elm $$T_Obj = Proto.Elm.newObj();

    static final Proto.Fxn $$T_Met = new Proto.Fxn(null, null, 0, -1, false);
    static final Proto.Map $$T_Map = new Proto.Map($$T_Obj);
    static final Proto.Arr $$T_Vec = new Proto.Arr($$T_Obj);

    static final XScriptO $$DEFAULT = Value.DEFAULT;
    static final Object $$UNDEF = Undefined.instance;

    static final Proto.Obj $$Package = (Proto.Obj)Global.get("$$Package");
    static final Proto.Obj $$Module = (Proto.Obj)Global.get("$$Module");
    static final Proto.Obj $$Instance = (Proto.Obj)Global.get("$$Instance");
    static final Proto.Obj $$Params = (Proto.Obj)Global.get("$$Params");

    static final Object $$objFldGet = Global.get("$$objFldGet");
    static final Object $$objFldSet = Global.get("$$objFldSet");
    static final Object $$proxyGet = Global.get("$$proxyGet");
    static final Object $$proxySet = Global.get("$$proxySet");
    static final Object $$delegGet = Global.get("$$delegGet");
    static final Object $$delegSet = Global.get("$$delegSet");

    Scriptable xdcO;
    Session ses;
    Value.Obj om;

    boolean isROV;
    boolean isCFG;

    Proto.Obj pkgP;
    Value.Obj pkgV;

    ArrayList<Object> imports = new ArrayList<Object>();
    ArrayList<Object> loggables = new ArrayList<Object>();
    ArrayList<Object> mcfgs = new ArrayList<Object>();
    ArrayList<Object> icfgs = new ArrayList<Object>();
    ArrayList<String> inherits = new ArrayList<String>();
    ArrayList<Object> proxies = new ArrayList<Object>();
    ArrayList<Object> sizes = new ArrayList<Object>();
    ArrayList<Object> tdefs = new ArrayList<Object>();

    void $$IMPORTS()
    {
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
        Global.callFxn("loadPackage", xdcO, "xdc.platform");
        Global.callFxn("loadPackage", xdcO, "ti.platforms.generic");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp", new Value.Obj("ti.syslink.samples.rtos.platforms.ti811x.dsp", pkgP));
    }

    void Platform$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform", new Value.Obj("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform", po));
        pkgV.bind("Platform", vo);
        // decls 
        om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Board", om.findStrict("xdc.platform.IPlatform.Board", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Memory", om.findStrict("xdc.platform.IPlatform.Memory", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        // insts 
        Object insP = om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$Object", new Proto.Obj());
        Object objP = om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Object", new Proto.Str(po, true));
        po = (Proto.Obj)om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$Params", new Proto.Obj());
        om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Params", new Proto.Str(po, true));
    }

    void Platform$$CONSTS()
    {
        // module Platform
    }

    void Platform$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        fxn = (Proto.Fxn)om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$create", new Proto.Fxn(om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Module", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Instance", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), 3, 2, false));
                fxn.addArg(0, "name", $$T_Str, $$UNDEF);
                fxn.addArg(1, "args", $$T_Obj, $$UNDEF);
                fxn.addArg(2, "__params", (Proto)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Params", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), Global.newObject());
        sb = new StringBuilder();
        sb.append("ti$syslink$samples$rtos$platforms$ti811x$dsp$Platform$$create = function( name, args, __params ) {\n");
            sb.append("var __mod = xdc.om['ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform'];\n");
            sb.append("var __inst = xdc.om['ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Instance'].$$make();\n");
            sb.append("__inst.$$bind('$package', xdc.om['ti.syslink.samples.rtos.platforms.ti811x.dsp']);\n");
            sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
            sb.append("__inst.$$bind('$category', 'Instance');\n");
            sb.append("__inst.$$bind('$args', {name:name, args:args});\n");
            sb.append("__inst.$$bind('$module', __mod);\n");
            sb.append("__mod.$instances.$add(__inst);\n");
            sb.append("__inst.externalMemoryMap = __mod.PARAMS.externalMemoryMap;\n");
            sb.append("__inst.customMemoryMap = __mod.PARAMS.customMemoryMap;\n");
            sb.append("__inst.renameMap = __mod.PARAMS.renameMap;\n");
            sb.append("__inst.dataMemory = __mod.PARAMS.dataMemory;\n");
            sb.append("__inst.codeMemory = __mod.PARAMS.codeMemory;\n");
            sb.append("__inst.stackMemory = __mod.PARAMS.stackMemory;\n");
            sb.append("__inst.sectMap = __mod.PARAMS.sectMap;\n");
            sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
            sb.append("var save = xdc.om.$curpkg;\n");
            sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
            sb.append("__mod.instance$meta$init.$fxn.apply(__inst, [name, args]);\n");
            sb.append("xdc.om.$$bind('$curpkg', save);\n");
            sb.append("__inst.$$bless();\n");
            sb.append("return __inst;\n");
        sb.append("}\n");
        Global.eval(sb.toString());
        fxn = (Proto.Fxn)om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$construct", new Proto.Fxn(om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Module", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), null, 4, 2, false));
                fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$Object", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), null);
                fxn.addArg(1, "name", $$T_Str, $$UNDEF);
                fxn.addArg(2, "args", $$T_Obj, $$UNDEF);
                fxn.addArg(3, "__params", (Proto)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Params", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), Global.newObject());
        sb = new StringBuilder();
        sb.append("ti$syslink$samples$rtos$platforms$ti811x$dsp$Platform$$construct = function( __obj, name, args, __params ) {\n");
            sb.append("var __mod = xdc.om['ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform'];\n");
            sb.append("var __inst = __obj;\n");
            sb.append("__inst.$$bind('$args', {name:name, args:args});\n");
            sb.append("__inst.$$bind('$module', __mod);\n");
            sb.append("__mod.$objects.$add(__inst);\n");
            sb.append("__inst.externalMemoryMap = __mod.PARAMS.externalMemoryMap;\n");
            sb.append("__inst.customMemoryMap = __mod.PARAMS.customMemoryMap;\n");
            sb.append("__inst.renameMap = __mod.PARAMS.renameMap;\n");
            sb.append("__inst.dataMemory = __mod.PARAMS.dataMemory;\n");
            sb.append("__inst.codeMemory = __mod.PARAMS.codeMemory;\n");
            sb.append("__inst.stackMemory = __mod.PARAMS.stackMemory;\n");
            sb.append("__inst.sectMap = __mod.PARAMS.sectMap;\n");
            sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
            sb.append("__inst.$$bless();\n");
            sb.append("return null;\n");
        sb.append("}\n");
        Global.eval(sb.toString());
    }

    void Platform$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void Platform$$SIZES()
    {
    }

    void Platform$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/syslink/samples/rtos/platforms/ti811x/dsp/Platform.xs");
        om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Module", "ti.syslink.samples.rtos.platforms.ti811x.dsp");
        po.init("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Module", om.findStrict("xdc.platform.IPlatform.Module", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("plat", (Proto)om.findStrict("ti.platforms.generic.Platform.Instance", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), $$UNDEF, "wh");
                po.addFxn("create", (Proto.Fxn)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$create", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), Global.get("ti$syslink$samples$rtos$platforms$ti811x$dsp$Platform$$create"));
                po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$construct", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), Global.get("ti$syslink$samples$rtos$platforms$ti811x$dsp$Platform$$construct"));
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        po = (Proto.Obj)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Instance", "ti.syslink.samples.rtos.platforms.ti811x.dsp");
        po.init("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Instance", om.findStrict("xdc.platform.IPlatform.Instance", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("codeMemory", $$T_Str, "DDR2", "wh");
        po.addFld("dataMemory", $$T_Str, "DDR2", "wh");
        po.addFld("stackMemory", $$T_Str, "DDR2", "wh");
                fxn = Global.get(cap, "getCpuDataSheet");
                if (fxn != null) po.addFxn("getCpuDataSheet", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCpuDataSheet", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
                fxn = Global.get(cap, "getCreateArgs");
                if (fxn != null) po.addFxn("getCreateArgs", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCreateArgs", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
                fxn = Global.get(cap, "getExeContext");
                if (fxn != null) po.addFxn("getExeContext", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExeContext", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
                fxn = Global.get(cap, "getExecCmd");
                if (fxn != null) po.addFxn("getExecCmd", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExecCmd", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
                fxn = Global.get(cap, "getLinkTemplate");
                if (fxn != null) po.addFxn("getLinkTemplate", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getLinkTemplate", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
        po = (Proto.Obj)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$Params", "ti.syslink.samples.rtos.platforms.ti811x.dsp");
        po.init("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Params", om.findStrict("xdc.platform.IPlatform$$Params", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("codeMemory", $$T_Str, "DDR2", "wh");
        po.addFld("dataMemory", $$T_Str, "DDR2", "wh");
        po.addFld("stackMemory", $$T_Str, "DDR2", "wh");
        po = (Proto.Obj)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$Object", "ti.syslink.samples.rtos.platforms.ti811x.dsp");
        po.init("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Object", om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Instance", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
                fxn = Global.get(cap, "getCpuDataSheet");
                if (fxn != null) po.addFxn("getCpuDataSheet", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCpuDataSheet", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
                fxn = Global.get(cap, "getCreateArgs");
                if (fxn != null) po.addFxn("getCreateArgs", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCreateArgs", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
                fxn = Global.get(cap, "getExeContext");
                if (fxn != null) po.addFxn("getExeContext", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExeContext", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
                fxn = Global.get(cap, "getExecCmd");
                if (fxn != null) po.addFxn("getExecCmd", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExecCmd", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
                fxn = Global.get(cap, "getLinkTemplate");
                if (fxn != null) po.addFxn("getLinkTemplate", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getLinkTemplate", "ti.syslink.samples.rtos.platforms.ti811x.dsp"), fxn);
    }

    void Platform$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.syslink.samples.rtos.platforms.ti811x.dsp.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        pkgP.bind("$capsule", $$UNDEF);
        pkgV.init2(pkgP, "ti.syslink.samples.rtos.platforms.ti811x.dsp", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.syslink.samples.rtos.platforms.ti811x.dsp");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.syslink.samples.rtos.platforms.ti811x.dsp.");
        pkgV.bind("$vers", Global.newArray());
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.syslink.samples.rtos.platforms.ti811x.dsp'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void Platform$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform", "ti.syslink.samples.rtos.platforms.ti811x.dsp");
        po = (Proto.Obj)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Module", "ti.syslink.samples.rtos.platforms.ti811x.dsp");
        vo.init2(po, "ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$capsule", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        vo.bind("Instance", om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Instance", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        vo.bind("Params", om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Params", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Params", "ti.syslink.samples.rtos.platforms.ti811x.dsp")).newInstance());
        vo.bind("$package", om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("Board", om.findStrict("xdc.platform.IPlatform.Board", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        tdefs.add(om.findStrict("xdc.platform.IPlatform.Board", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        vo.bind("Memory", om.findStrict("xdc.platform.IPlatform.Memory", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        tdefs.add(om.findStrict("xdc.platform.IPlatform.Memory", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        vo.bind("MemoryMap", om.findStrict("xdc.platform.IPlatform.MemoryMap", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.platform");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.syslink.samples.rtos.platforms.ti811x.dsp")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform.Object", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        pkgV.bind("Platform", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Platform");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform", "ti.syslink.samples.rtos.platforms.ti811x.dsp"));
        vo = (Value.Obj)om.findStrict("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform", "ti.syslink.samples.rtos.platforms.ti811x.dsp");
        Global.put(vo, "plat", Global.callFxn("create", (Scriptable)om.find("ti.platforms.generic.Platform"), "plat", Global.newObject("clockRate", 500.0, "catalogName", "ti.catalog.c6000", "deviceName", "TMS320TI811X", "externalMemoryMap", Global.newArray(new Object[]{Global.newArray(new Object[]{"EXT_RAM", Global.newObject("name", "EXT_RAM", "base", 0x80000000L, "len", 0x0A600000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"DDR2", Global.newObject("name", "DDR2", "base", 0x8B000000L, "len", 0x01FFDB00L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"HOST_DSP_NOTIFYMEM", Global.newObject("name", "HOST_DSP_NOTIFYMEM", "base", 0x8CFFDB00L, "len", 0x00002500L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"SR0", Global.newObject("name", "SR0", "base", 0x8E000000L, "len", 0x01000000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"SR1", Global.newObject("name", "SR1", "base", 0x8D000000L, "len", 0x00C00000L, "space", "code/data", "access", "RWX")})}), "l1DMode", "32k", "l1PMode", "32k", "l2Mode", "256k")));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.syslink.samples.rtos.platforms.ti811x.dsp.Platform")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.syslink.samples.rtos.platforms.ti811x.dsp")).add(pkgV);
    }

    public void exec( Scriptable xdcO, Session ses )
    {
        this.xdcO = xdcO;
        this.ses = ses;
        om = (Value.Obj)xdcO.get("om", null);

        Object o = om.geto("$name");
        String s = o instanceof String ? (String)o : null;
        isCFG = s != null && s.equals("cfg");
        isROV = s != null && s.equals("rov");

        $$IMPORTS();
        $$OBJECTS();
        Platform$$OBJECTS();
        Platform$$CONSTS();
        Platform$$CREATES();
        Platform$$FUNCTIONS();
        Platform$$SIZES();
        Platform$$TYPES();
        if (isROV) {
            Platform$$ROV();
        }//isROV
        $$SINGLETONS();
        Platform$$SINGLETONS();
        $$INITIALIZATION();
    }
}
