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

public class ti_sdo_ipc_examples_platforms_evmTI811X_host
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
        Global.callFxn("loadPackage", xdcO, "ti.platforms.generic");
        Global.callFxn("loadPackage", xdcO, "xdc.platform");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host", new Value.Obj("ti.sdo.ipc.examples.platforms.evmTI811X.host", pkgP));
    }

    void Platform$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform", new Value.Obj("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform", po));
        pkgV.bind("Platform", vo);
        // decls 
        om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Board", om.findStrict("xdc.platform.IPlatform.Board", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Memory", om.findStrict("xdc.platform.IPlatform.Memory", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        // insts 
        Object insP = om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$Object", new Proto.Obj());
        Object objP = om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Object", new Proto.Str(po, true));
        po = (Proto.Obj)om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$Params", new Proto.Obj());
        om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Params", new Proto.Str(po, true));
    }

    void Platform$$CONSTS()
    {
        // module Platform
    }

    void Platform$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        fxn = (Proto.Fxn)om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$create", new Proto.Fxn(om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Module", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Instance", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), 3, 2, false));
                fxn.addArg(0, "name", $$T_Str, $$UNDEF);
                fxn.addArg(1, "args", $$T_Obj, $$UNDEF);
                fxn.addArg(2, "__params", (Proto)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Params", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), Global.newObject());
        sb = new StringBuilder();
        sb.append("ti$sdo$ipc$examples$platforms$evmTI811X$host$Platform$$create = function( name, args, __params ) {\n");
            sb.append("var __mod = xdc.om['ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform'];\n");
            sb.append("var __inst = xdc.om['ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Instance'].$$make();\n");
            sb.append("__inst.$$bind('$package', xdc.om['ti.sdo.ipc.examples.platforms.evmTI811X.host']);\n");
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
        fxn = (Proto.Fxn)om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$construct", new Proto.Fxn(om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Module", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), null, 4, 2, false));
                fxn.addArg(0, "__obj", (Proto)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$Object", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), null);
                fxn.addArg(1, "name", $$T_Str, $$UNDEF);
                fxn.addArg(2, "args", $$T_Obj, $$UNDEF);
                fxn.addArg(3, "__params", (Proto)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Params", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), Global.newObject());
        sb = new StringBuilder();
        sb.append("ti$sdo$ipc$examples$platforms$evmTI811X$host$Platform$$construct = function( __obj, name, args, __params ) {\n");
            sb.append("var __mod = xdc.om['ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform'];\n");
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

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/sdo/ipc/examples/platforms/evmTI811X/host/Platform.xs");
        om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Module", "ti.sdo.ipc.examples.platforms.evmTI811X.host");
        po.init("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Module", om.findStrict("xdc.platform.IPlatform.Module", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("CPU", (Proto)om.findStrict("ti.platforms.generic.Platform.Instance", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), $$UNDEF, "wh");
                po.addFxn("create", (Proto.Fxn)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$create", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), Global.get("ti$sdo$ipc$examples$platforms$evmTI811X$host$Platform$$create"));
                po.addFxn("construct", (Proto.Fxn)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$construct", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), Global.get("ti$sdo$ipc$examples$platforms$evmTI811X$host$Platform$$construct"));
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        po = (Proto.Obj)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Instance", "ti.sdo.ipc.examples.platforms.evmTI811X.host");
        po.init("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Instance", om.findStrict("xdc.platform.IPlatform.Instance", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("codeMemory", $$T_Str, "DDR_HOST", "wh");
        po.addFld("dataMemory", $$T_Str, "DDR_HOST", "wh");
        po.addFld("stackMemory", $$T_Str, "DDR_HOST", "wh");
                fxn = Global.get(cap, "getCpuDataSheet");
                if (fxn != null) po.addFxn("getCpuDataSheet", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCpuDataSheet", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
                fxn = Global.get(cap, "getCreateArgs");
                if (fxn != null) po.addFxn("getCreateArgs", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCreateArgs", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
                fxn = Global.get(cap, "getExeContext");
                if (fxn != null) po.addFxn("getExeContext", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExeContext", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
                fxn = Global.get(cap, "getExecCmd");
                if (fxn != null) po.addFxn("getExecCmd", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExecCmd", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
                fxn = Global.get(cap, "getLinkTemplate");
                if (fxn != null) po.addFxn("getLinkTemplate", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getLinkTemplate", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
        po = (Proto.Obj)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$Params", "ti.sdo.ipc.examples.platforms.evmTI811X.host");
        po.init("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Params", om.findStrict("xdc.platform.IPlatform$$Params", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("codeMemory", $$T_Str, "DDR_HOST", "wh");
        po.addFld("dataMemory", $$T_Str, "DDR_HOST", "wh");
        po.addFld("stackMemory", $$T_Str, "DDR_HOST", "wh");
        po = (Proto.Obj)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$Object", "ti.sdo.ipc.examples.platforms.evmTI811X.host");
        po.init("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Object", om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Instance", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
                fxn = Global.get(cap, "getCpuDataSheet");
                if (fxn != null) po.addFxn("getCpuDataSheet", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCpuDataSheet", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
                fxn = Global.get(cap, "getCreateArgs");
                if (fxn != null) po.addFxn("getCreateArgs", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCreateArgs", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
                fxn = Global.get(cap, "getExeContext");
                if (fxn != null) po.addFxn("getExeContext", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExeContext", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
                fxn = Global.get(cap, "getExecCmd");
                if (fxn != null) po.addFxn("getExecCmd", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExecCmd", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
                fxn = Global.get(cap, "getLinkTemplate");
                if (fxn != null) po.addFxn("getLinkTemplate", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getLinkTemplate", "ti.sdo.ipc.examples.platforms.evmTI811X.host"), fxn);
    }

    void Platform$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.sdo.ipc.examples.platforms.evmTI811X.host.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        pkgP.bind("$capsule", $$UNDEF);
        pkgV.init2(pkgP, "ti.sdo.ipc.examples.platforms.evmTI811X.host", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.sdo.ipc.examples.platforms.evmTI811X.host");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.sdo.ipc.examples.platforms.evmTI811X.host.");
        pkgV.bind("$vers", Global.newArray());
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.sdo.ipc.examples.platforms.evmTI811X.host'];\n");
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

        vo = (Value.Obj)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform", "ti.sdo.ipc.examples.platforms.evmTI811X.host");
        po = (Proto.Obj)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Module", "ti.sdo.ipc.examples.platforms.evmTI811X.host");
        vo.init2(po, "ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$capsule", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        vo.bind("Instance", om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Instance", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        vo.bind("Params", om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Params", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Params", "ti.sdo.ipc.examples.platforms.evmTI811X.host")).newInstance());
        vo.bind("$package", om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("Board", om.findStrict("xdc.platform.IPlatform.Board", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        tdefs.add(om.findStrict("xdc.platform.IPlatform.Board", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        vo.bind("Memory", om.findStrict("xdc.platform.IPlatform.Memory", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        tdefs.add(om.findStrict("xdc.platform.IPlatform.Memory", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        vo.bind("MemoryMap", om.findStrict("xdc.platform.IPlatform.MemoryMap", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.platform");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.sdo.ipc.examples.platforms.evmTI811X.host")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("Object", om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform.Object", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        pkgV.bind("Platform", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Platform");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform", "ti.sdo.ipc.examples.platforms.evmTI811X.host"));
        vo = (Value.Obj)om.findStrict("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform", "ti.sdo.ipc.examples.platforms.evmTI811X.host");
        Global.put(vo, "CPU", Global.callFxn("create", (Scriptable)om.find("ti.platforms.generic.Platform"), "CPU", Global.newObject("clockRate", 600L, "catalogName", "ti.catalog.arm.cortexa8", "deviceName", "TMS320TI811X", "externalMemoryMap", Global.newArray(new Object[]{Global.newArray(new Object[]{"VECTORS", Global.newObject("base", 0x00000000L, "space", "code/data", "name", "VECTORS", "len", 0x00010000L, "access", "RWX")}), Global.newArray(new Object[]{"DDR_HOST", Global.newObject("base", 0x80000000L, "space", "code/data", "name", "DDR_HOST", "len", 0x0B000000L, "access", "RWX")}), Global.newArray(new Object[]{"DDR_SR0", Global.newObject("base", 0x8E000000L, "space", "code/data", "name", "DDR_SR0", "len", 0x01000000L, "access", "RWX")})}))));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.sdo.ipc.examples.platforms.evmTI811X.host.Platform")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.sdo.ipc.examples.platforms.evmTI811X.host")).add(pkgV);
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
