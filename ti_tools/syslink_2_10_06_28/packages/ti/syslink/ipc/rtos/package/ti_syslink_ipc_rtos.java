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

public class ti_syslink_ipc_rtos
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
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.syslink.ipc.rtos.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.syslink.ipc.rtos", new Value.Obj("ti.syslink.ipc.rtos", pkgP));
    }

    void Syslink$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("ti.syslink.ipc.rtos.Syslink.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("ti.syslink.ipc.rtos.Syslink", new Value.Obj("ti.syslink.ipc.rtos.Syslink", po));
        pkgV.bind("Syslink", vo);
        // decls 
    }

    void Syslink$$CONSTS()
    {
        // module Syslink
    }

    void Syslink$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

    }

    void Syslink$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void Syslink$$SIZES()
    {
    }

    void Syslink$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/syslink/ipc/rtos/Syslink.xs");
        om.bind("ti.syslink.ipc.rtos.Syslink$$capsule", cap);
        po = (Proto.Obj)om.findStrict("ti.syslink.ipc.rtos.Syslink.Module", "ti.syslink.ipc.rtos");
        po.init("ti.syslink.ipc.rtos.Syslink.Module", $$Module);
                po.addFld("$hostonly", $$T_Num, 1, "r");
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("ti.syslink.ipc.rtos.Syslink$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("ti.syslink.ipc.rtos.Syslink$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("ti.syslink.ipc.rtos.Syslink$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
    }

    void Syslink$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.syslink.ipc.rtos.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.syslink.ipc.rtos"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/syslink/ipc/rtos/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.syslink.ipc.rtos"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.syslink.ipc.rtos"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.syslink.ipc.rtos"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.syslink.ipc.rtos"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.syslink.ipc.rtos"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.syslink.ipc.rtos"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.syslink.ipc.rtos", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.syslink.ipc.rtos");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.syslink.ipc.rtos.");
        pkgV.bind("$vers", Global.newArray("1, 0, 0, 0"));
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.syslink.ipc.rtos'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/debug/ti.syslink.ipc.rtos.ae674',\n");
            sb.append("'lib/release/ti.syslink.ipc.rtos.ae674',\n");
            sb.append("'lib/debug/ti.syslink.ipc.rtos.aem3',\n");
            sb.append("'lib/release/ti.syslink.ipc.rtos.aem3',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/debug/ti.syslink.ipc.rtos.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/release/ti.syslink.ipc.rtos.ae674', {target: 'ti.targets.elf.C674', suffix: 'e674'}],\n");
            sb.append("['lib/debug/ti.syslink.ipc.rtos.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/release/ti.syslink.ipc.rtos.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void Syslink$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("ti.syslink.ipc.rtos.Syslink", "ti.syslink.ipc.rtos");
        po = (Proto.Obj)om.findStrict("ti.syslink.ipc.rtos.Syslink.Module", "ti.syslink.ipc.rtos");
        vo.init2(po, "ti.syslink.ipc.rtos.Syslink", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("ti.syslink.ipc.rtos.Syslink$$capsule", "ti.syslink.ipc.rtos"));
        vo.bind("$package", om.findStrict("ti.syslink.ipc.rtos", "ti.syslink.ipc.rtos"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "ti.syslink.ipc.rtos")).add(vo);
        vo.bind("$$instflag", 0);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 0);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("ti.syslink.ipc.rtos.Syslink$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        pkgV.bind("Syslink", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Syslink");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("ti.syslink.ipc.rtos.Syslink", "ti.syslink.ipc.rtos"));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("ti.syslink.ipc.rtos.Syslink")).bless();
        ((Value.Arr)om.findStrict("$packages", "ti.syslink.ipc.rtos")).add(pkgV);
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
        Syslink$$OBJECTS();
        Syslink$$CONSTS();
        Syslink$$CREATES();
        Syslink$$FUNCTIONS();
        Syslink$$SIZES();
        Syslink$$TYPES();
        if (isROV) {
            Syslink$$ROV();
        }//isROV
        $$SINGLETONS();
        Syslink$$SINGLETONS();
        $$INITIALIZATION();
    }
}
