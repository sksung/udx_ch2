/* 
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * */
/*
 *  ======== Settings.xs ========
 *
 */

var settings = {
    device: {
        "TMS320F2812" : {
            hwiDelegate : "ti.sysbios.family.c28.Hwi",
            timerDelegate : "ti.sysbios.family.c28.Timer",
            timestampDelegate : "ti.sysbios.family.c28.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c28.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c28.IntrinsicsSupport",
            cacheDelegate : null,
            clockTickPeriod : 1000,
            targets : ["ti.targets.C28_large"]
        },
        "TMS320F28335" : {
            hwiDelegate : "ti.sysbios.family.c28.Hwi",
            timerDelegate : "ti.sysbios.family.c28.Timer",
            timestampDelegate : "ti.sysbios.family.c28.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c28.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c28.IntrinsicsSupport",
            cacheDelegate : null,
            clockTickPeriod : 1000,
            targets : ["ti.targets.C28_float"]
        },
        "F28M35x" : {
            hwiDelegate : "ti.sysbios.family.c28.Hwi",
            timerDelegate : "ti.sysbios.family.c28.Timer",
            timestampDelegate : "ti.sysbios.family.c28.f28m35x.TimestampProvider",
            taskSupportDelegate : "ti.sysbios.family.c28.TaskSupport",
            intrinsicsSupportDelegate : "ti.sysbios.family.c28.IntrinsicsSupport",
            cacheDelegate : null,
            clockTickPeriod : 1000,
            targets : ["ti.targets.C28_float"]
        }
    }
}

/* supported TMS320F devices */
settings.device["TMS320F2801"] = settings.device["TMS320F2812"];
settings.device["TMS320F28015"] = settings.device["TMS320F2812"];
settings.device["TMS320F28016"] = settings.device["TMS320F2812"];
settings.device["TMS320F2802"] = settings.device["TMS320F2812"];
settings.device["TMS320F2806"] = settings.device["TMS320F2812"];
settings.device["TMS320F2808"] = settings.device["TMS320F2812"];
settings.device["TMS320F2809"] = settings.device["TMS320F2812"];
settings.device["TMS320F2810"] = settings.device["TMS320F2812"];
settings.device["TMS320F2811"] = settings.device["TMS320F2812"];

settings.device["TMS320F28020"] = settings.device["TMS320F2812"];
settings.device["TMS320F28021"] = settings.device["TMS320F2812"];
settings.device["TMS320F28022"] = settings.device["TMS320F2812"];
settings.device["TMS320F28023"] = settings.device["TMS320F2812"];
settings.device["TMS320F28026"] = settings.device["TMS320F2812"];
settings.device["TMS320F28027"] = settings.device["TMS320F2812"];
settings.device["TMS320F28030"] = settings.device["TMS320F2812"];

settings.device["TMS320F28031"] = settings.device["TMS320F2812"];
settings.device["TMS320F28032"] = settings.device["TMS320F2812"];
settings.device["TMS320F28033"] = settings.device["TMS320F2812"];
settings.device["TMS320F28034"] = settings.device["TMS320F2812"];
settings.device["TMS320F28035"] = settings.device["TMS320F2812"];
settings.device["TMS320F28044"] = settings.device["TMS320F2812"];

settings.device["TMS320F28050"]  = settings.device["TMS320F2812"];
settings.device["TMS320F28051"]  = settings.device["TMS320F2812"];
settings.device["TMS320F28052"]  = settings.device["TMS320F2812"];
settings.device["TMS320F28052F"] = settings.device["TMS320F2812"];
settings.device["TMS320F28052M"] = settings.device["TMS320F2812"];
settings.device["TMS320F28053"]  = settings.device["TMS320F2812"];
settings.device["TMS320F28054"]  = settings.device["TMS320F2812"];
settings.device["TMS320F28054F"] = settings.device["TMS320F2812"];
settings.device["TMS320F28054M"] = settings.device["TMS320F2812"];
settings.device["TMS320F28055"]  = settings.device["TMS320F2812"];

settings.device["TMS320F28232"] = settings.device["TMS320F2812"];
settings.device["TMS320F28234"] = settings.device["TMS320F2812"];
settings.device["TMS320F28235"] = settings.device["TMS320F2812"];

settings.device["TMS320F28332"] = settings.device["TMS320F28335"];
settings.device["TMS320F28334"] = settings.device["TMS320F28335"];

/* supported TMS320C devices */
settings.device["TMS320C2801"] = settings.device["TMS320F2812"];
settings.device["TMS320C2806"] = settings.device["TMS320F2812"];
settings.device["TMS320C2808"] = settings.device["TMS320F2812"];
settings.device["TMS320C2810"] = settings.device["TMS320F2812"];
settings.device["TMS320C2811"] = settings.device["TMS320F2812"];
settings.device["TMS320C2812"] = settings.device["TMS320F2812"];

settings.device["TMS320C28020"] = settings.device["TMS320F2812"];
settings.device["TMS320C28021"] = settings.device["TMS320F2812"];
settings.device["TMS320C28022"] = settings.device["TMS320F2812"];
settings.device["TMS320C28023"] = settings.device["TMS320F2812"];
settings.device["TMS320C28026"] = settings.device["TMS320F2812"];
settings.device["TMS320C28027"] = settings.device["TMS320F2812"];

settings.device["TMS320C28032"] = settings.device["TMS320F2812"];
settings.device["TMS320C28033"] = settings.device["TMS320F2812"];
settings.device["TMS320C28034"] = settings.device["TMS320F2812"];
settings.device["TMS320C28035"] = settings.device["TMS320F2812"];

settings.device["TMS320C28232"] = settings.device["TMS320F2812"];
settings.device["TMS320C28234"] = settings.device["TMS320F2812"];
settings.device["TMS320C28235"] = settings.device["TMS320F2812"];

settings.device["TMS320C28332"] = settings.device["TMS320F28335"];
settings.device["TMS320C28334"] = settings.device["TMS320F28335"];
settings.device["TMS320C28335"] = settings.device["TMS320F28335"];

settings.device["TMS320C28341"] = settings.device["TMS320F28335"];
settings.device["TMS320C28342"] = settings.device["TMS320F28335"];
settings.device["TMS320C28343"] = settings.device["TMS320F28335"];
settings.device["TMS320C28344"] = settings.device["TMS320F28335"];
settings.device["TMS320C28345"] = settings.device["TMS320F28335"];
settings.device["TMS320C28346"] = settings.device["TMS320F28335"];

/* supported Octave devices */
settings.device["TMS320F28062"] = settings.device["TMS320F28335"];
settings.device["TMS320F28063"] = settings.device["TMS320F28335"];
settings.device["TMS320F28064"] = settings.device["TMS320F28335"];
settings.device["TMS320F28065"] = settings.device["TMS320F28335"];
settings.device["TMS320F28066"] = settings.device["TMS320F28335"];
settings.device["TMS320F28067"] = settings.device["TMS320F28335"];
settings.device["TMS320F28068"] = settings.device["TMS320F28335"];
settings.device["TMS320F28069"] = settings.device["TMS320F28335"];

/*
 *  ======== getDefaultHwiDelegate ========
 */
function getDefaultHwiDelegate()
{
    return ("ti.sysbios.family.c28.Hwi");
}

/*
 *  ======== getDefaultTimerDelegate ========
 */
function getDefaultTimerDelegate()
{
    return ("ti.sysbios.family.c28.Timer");
}

/*
 *  ======== getDefaultTimestampDelegate ========
 */
function getDefaultTimestampDelegate()
{
    if (Program.cpu.deviceName.match(/F28M35/)) {
        return ("ti.sysbios.family.c28.f28m35x.TimestampProvider");
    }
    else {
        return ("ti.sysbios.family.c28.TimestampProvider");
    }
}

/*
 *  ======== getDefaultTaskSupportDelegate ========
 */
function getDefaultTaskSupportDelegate()
{
    return ("ti.sysbios.family.c28.TaskSupport");
}

/*
 *  ======== getDefaultIntrinsicsSupportDelegate ========
 */
function getDefaultIntrinsicsSupportDelegate()
{
    return ("ti.sysbios.family.c28.IntrinsicsSupport");
}

/*
 *  ======== getDefaultCacheDelegate ========
 */
function getDefaultCacheDelegate()
{
    return (null);
}

/*
 *  ======== getDefaultBootModule ========
 */
function getDefaultBootModule()
{
    if (Program.cpu.deviceName.match(/F28M35/)) {
        return ("ti.catalog.c2800.concertoInit.Boot");
    }
    else {
        return ("ti.catalog.c2800.init.Boot");
    }
}

/*
 *  ======== getDefaultMmuModule ========
 */
function getDefaultMmuModule()
{
    return (null);
}
 
/*
 *  ======== getFamilySettingsXml ========
 */
function getFamilySettingsXml()
{
    return ("family/c28/Settings.xml");
}

/*
 *  ======== getDefaultClockTickPeriod ========
 */
function getDefaultClockTickPeriod()
{
    return (1000);
}
/*
 *  @(#) ti.sysbios.family.c28; 2, 0, 0, 0,521; 5-18-2012 06:04:38; /db/vtree/library/trees/avala/avala-q37x/src/ xlibrary

 */

