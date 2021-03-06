/* --COPYRIGHT--,ESD
 *  Copyright (c) 2008 Texas Instruments. All rights reserved. 
 *  This program and the accompanying materials are made available under the 
 *  terms of the Eclipse Public License v1.0 and Eclipse Distribution License
 *  v. 1.0 which accompanies this distribution. The Eclipse Public License is
 *  available at http://www.eclipse.org/legal/epl-v10.html and the Eclipse
 *  Distribution License is available at 
 *  http://www.eclipse.org/org/documents/edl-v10.php.
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 * --/COPYRIGHT--*/
/*
 *  ======== LoggerUart.c ========
 */
#include <xdc/std.h>

#include <xdc/runtime/Log.h>
#include <xdc/runtime/Types.h>

#include "SysUart.h"

#include "package/internal/LoggerUart.xdc.h"

/*
 *  ======== Instance_init =========
 */
Void LoggerUart_Instance_init(LoggerUart_Object *obj,
    const LoggerUart_Params *prms)
{
    obj->enabled = TRUE;
}

/*
 *  ======== disable ========
 */
Bool LoggerUart_disable(LoggerUart_Object *obj)
{
    Bool prev = obj->enabled;
    obj->enabled = FALSE;
    return (prev);
}

/*
 *  ======== enable ========
 */
Bool LoggerUart_enable(LoggerUart_Object *obj)
{
    Bool prev = obj->enabled;
    obj->enabled = TRUE;
    return (prev);
}

/*
 *  ======== write0 =========
 */
Void LoggerUart_write0(LoggerUart_Object *obj, Types_Event evt,
    Types_ModuleId mid)
{
    LoggerUart_write8(obj, evt, mid, 0, 0, 0, 0, 0, 0, 0, 0);
}

/*
 *  ======== write1 =========
 */
Void LoggerUart_write1(LoggerUart_Object *obj, Types_Event evt,
    Types_ModuleId mid, IArg a1)
{
    LoggerUart_write8(obj, evt, mid, a1, 0, 0, 0, 0, 0, 0, 0);
}

/*
 *  ======== write2 =========
 */
Void LoggerUart_write2(LoggerUart_Object *obj, Types_Event evt,
    Types_ModuleId mid, IArg a1, IArg a2)
{
    LoggerUart_write8(obj, evt, mid, a1, a2, 0, 0, 0, 0, 0, 0);
}

/*
 *  ======== write4 =========
 */
Void LoggerUart_write4(LoggerUart_Object *obj, Types_Event evt,
    Types_ModuleId mid, IArg a1, IArg a2, IArg a3, IArg a4)
{
    LoggerUart_write8(obj, evt, mid, a1, a2, a3, a4, 0, 0, 0, 0);
}

/*
 *  ======== write8 =========
 */
Void LoggerUart_write8(LoggerUart_Object *obj, Types_Event evt,
    Types_ModuleId mid, IArg a1, IArg a2, IArg a3, IArg a4, IArg a5, IArg a6,
    IArg a7, IArg a8)
{
    Log_EventRec evrec;
    Int i;
    Char *cp;
    
    LoggerUart_TimestampProxy_get64(&evrec.tstamp);

    evrec.serial = 0;
    evrec.evt = Types_makeEvent(Log_getEventId(evt), mid);
    evrec.arg[0] = a1;
    evrec.arg[1] = a2;
    evrec.arg[2] = a3;
    evrec.arg[3] = a4;
    evrec.arg[4] = a5;
    evrec.arg[5] = a6;
    evrec.arg[6] = a7;
    evrec.arg[7] = a8;

    /* send header */
    SysUart_putch('\01');   /* switch to binary mode */
    SysUart_putch('\00');   /* send PID */

    /* send payload */
    for (cp = (Char *)&evrec, i = 0; i < sizeof(evrec); i++) {
        SysUart_putch(*cp++);
    }
}
