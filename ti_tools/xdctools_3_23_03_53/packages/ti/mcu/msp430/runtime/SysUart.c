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
 *  ======== SysUart.c ========
 */
#include <xdc/runtime/Startup.h>
#include <ti/mcu/msp430/runtime/utils/Led.h>

#include "package/internal/SysUart.xdc.h"

#define FOREVER     -1

static void etx();
static void flash(Int color, Int period, Int count);

#define rxtxInit ti_mcu_msp430_runtime_SysUart_rxtxInit__I
#define tx       ti_mcu_msp430_runtime_SysUart_tx__I
#define rx       ti_mcu_msp430_runtime_SysUart_rx__I

/*
 *  ======== SysUart_Module_startup ========
 */
Int SysUart_Module_startup(Int state)
{
    rxtxInit();    
    flash(Led_GREEN, 50, 4);    /* indicate the init is done */
    return (Startup_DONE);
}

/*
 *  ======== SysUart_abort ========
 */
Void SysUart_abort(String str)
{
    if (str != NULL) {
        Char ch;
        
        while ((ch = *str++) != '\0') {
            SysUart_putch(ch);
        }
    }
    flash(Led_RED, FOREVER, FOREVER);
    etx();
}

/*
 *  ======== SysUart_exit ========
 */
Void SysUart_exit(Int stat)
{
    flash(Led_GREEN, FOREVER, FOREVER);
    etx();
}

/*
 *  ======== SysUart_flush ========
 */
Void SysUart_flush()
{
}

/*
 *  ======== SysUart_putch ========
 */
Void SysUart_putch(Char ch)
{
    tx(ch);
}

/*
 *  ======== SysUart_ready ========
 */
Bool SysUart_ready()
{
    return (TRUE);
}

/*
 *  ======== atexit ========
 *  The TI RTS library's atexit() implementation requires a _huge_ amount of
 *  data.  We stub it out here and replace exit() and abort() with functions
 *  that are sufficient for the proper operation of xdc.runtime.System.
 */
int atexit(void (*fxn)(void))
{
    return (0);
}

/*
 *  ======== abort ========
 *  See atexit() above
 */
void abort(void)
{
   /*  Define C$$EXIT label because TI debugger uses this to know when
    *  programs terminate.  This can be removed if the debugger is not
    *  used.
    */
   __asm("        .global C$$EXIT");
   __asm("C$$EXIT: nop");

   for (;;);   /* spin forever */
}

/*
 *  ======== exit ========
 *  See atexit() above
 */
void exit(int status)
{
    SysUart_exit(status);
}

/*
 *  ======== etx ========
 *  Flush HW TX buffers
 */
static void etx()
{
    tx(4);  /* ascii EOT */
    tx(0);
    tx(0);
    abort();
}

/*
 *  ======== flash ========
 */
static void flash(Int color, Int period, Int count)
{
    if (period == FOREVER) {
        Led_on(color);
        return;
    }
 
    while (count) {
        volatile unsigned int i;    /* volatile to prevent optimization */
        
        Led_toggle(color);             /* toggle P1.1,0 using exclusive-OR */
        
        for (i = period * 1000; i != 0; i--) {  /* delay period */
            ;
        }

        if (count > 0) {            /* if count starts < 0, go forever */
            count--;
        }
    }
}

/*
 *  ======== rx ========
 */
void rx(char c)
{
    if (SysUart_getLineFxn == NULL) {
        return;
    }

    if (SysUart_lineBuf == NULL) {
        SysUart_getLineFxn(&c, 1);
        return;
    }

    if (c == '\n') {
        SysUart_lineBuf[module->lineIdx] = 0;
        SysUart_getLineFxn(SysUart_lineBuf, module->lineIdx);
        module->lineIdx = 0;
    }
    else if (module->lineIdx < SysUart_lineSize) {
        SysUart_lineBuf[module->lineIdx++] = c;
    }
}

