/* 
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
 * */
/*
 *  ======== Text.c ========
 */

#include <xdc/runtime/System.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Registry.h>

#include <string.h>
#include <stdarg.h>

#include "package/internal/Text.xdc.h"

/*
 *  ======== cordText ========
 */
String Text_cordText(Text_CordAddr cord)
{
    Char *p = (Char *)cord;

    if (p >= Text_charTab && p < Text_charTab + Text_charCnt
        && !Text_isLoaded) {
        return (NULL);
    }

    return ((String)cord);
}

/*
 *  ======== matchRope ========
 */
Int Text_matchRope(Types_RopeId rope, String pat, Int *lenp)
{
    Text_MatchVisState state;

    state.pat = pat;
    state.lenp = lenp;

    /*
     * Text_visitRopeFxn is a config parameter that references a function
     * generated by the template Text.xdt and initialized in Text.xdc.
     * It's visitRope2() with a stack large enough for all ropes in the
     * application.
     */
    Text_visitRopeFxn(rope, (Fxn)Text_matchVisFxn, &state);

    return (state.res);
}

/*
 *  ======== matchVisFxn ========
 *  Determines whether a given pattern matches the given string.
 *
 *  'obj' is a pointer a MatchVisState structure.
 *    pat - The pattern string to match to, which may contain the wildcard '%'
 *    lenp - The length of the pattern string
 *    res - Used to hold the result of this comparison
 *
 *  'src' is the string to compare the pattern to. It is intended to be a
 *  single node within a rope.
 *
 *  This function is intended for matching ropes one segment at a time. The 
 *  return value indicates whether the comparison is complete--it returns 
 *  FALSE if we need to move on to the next rope node, or TRUE if the 
 *  comparison is complete. The actual result of the comparison is returned
 *  through the MatchVisState. 'res' is 1 if it's a match, -1 if not.
 */
Bool Text_matchVisFxn(Ptr obj, String src)
{
    Text_MatchVisState *state;
    String pat;
    Int *lenp;

    state = obj;
    pat = state->pat;
    lenp = state->lenp;

    /* compare pat to src and return if pat != src or wildcard matches */
    for (; *lenp && *src; src++, pat++, *lenp -= 1) {
        if (*src != *pat) {
            state->res = *pat == '%' ? 1 : -1;
            return (TRUE);
        }
    }

    /* if src[0] != 0, we reached the end of pat */
    if (*src) {
        state->res = -1;
        return (TRUE);
    }
    else {
        /* we reached end of src, we need to get next part of rope */
        state->res = 0;
        state->pat = pat;
        return (FALSE);
    }
}

/*
 *  ======== printVisFxn ========
 */
Bool Text_printVisFxn(Ptr obj, String src)
{
    Text_PrintVisState *state = obj;

    if (state->len == 0) {
        return (TRUE);
    }
    else {
        Int oc = Text_xprintf(state->bufp, "%.*s", state->len, src);
        state->res += oc;
        if (state->len > 0) {
            state->len -= oc;
        }
        return (FALSE);
    }
}

/*
 *  ======== putLab ========
 *  len == -1 => infinite output 
 */
Int Text_putLab(Types_Label *lab, Char **bufp, Int len)
{
    Int res;

    res = Text_putMod(lab->modId, bufp, len);
    if (len < 0 || (len - res) > 8) {  /* need at most 9 characters for "%p" */
        res += Text_xprintf(bufp, "%p", lab->handle);
    }
    
    if (lab->named
        && (len < 0 || (len - res) >= (4 + (Int)strlen(lab->iname))) ) {

        res += Text_xprintf(bufp, "('%s')", lab->iname);
    }

    return (res);
}

/*
 *  ======== putMod ========
 */
Int Text_putMod(Types_ModuleId mid, Char **bufp, Int len)
{
    Text_PrintVisState state;

    /* If this is an unnamed module... */
    if (mid <= Text_unnamedModsLastId) {
        return (Text_xprintf(bufp, "{module#%d}", mid));
    }
    
    /* If this is a dynamically registered module... */
    if (mid <= Text_registryModsLastId) {
        return (Text_xprintf(bufp, Registry_findById(mid)->modName));
    }

    /* If this is a static, named module, but the strings are not loaded... */
    if (!Text_isLoaded) {
        return (Text_xprintf(bufp, "{module-rope:%x}", mid));
    }
    
    /* Otherwise, this is a static, named module. */
    state.bufp = bufp;
    state.len = len < 0 ? 0x7fff : len;   /* 0x7fff == infinite, almost */;
    state.res = 0;
    
    Text_visitRopeFxn(mid, (Fxn)Text_printVisFxn, &state);
    
    return (state.res);
}

/*
 *  ======== putSite ========
 *  len == -1 => infinite output
 *  
 *  If site->mod == 0, the module is unspecified and will be omitted from the output.
 */
Int Text_putSite(Types_Site *site, Char **bufp, Int len)
{
    Int res;
    Int max = len < 0 ? 0x7fff : len;   /* 0x7fff == infinite, well almost */

    res = 0;
    
    if (!site) {
        return (0);
    }

    /* The 'mod' field is optional; 0 if it's unspecified. */
    if (site->mod != 0) {
        res = Text_putMod(site->mod, bufp, max);
        max -= (res + 2);     /* +2 for the ": " string below */
    }
        
    if (max > 0) {
        /* Don't output this if there's no mod */
        if (site->mod != 0) {
            res += Text_xprintf(bufp, ": ");
        }

        if (site->line == 0) {
            return (res);
        }
    
        if (site->file && (max >= ((Int)strlen(site->file) + 4))) {
            Int oc = Text_xprintf(bufp, "\"%s\", ", site->file);
            res += oc;
            max -= oc;
        }
        
        /* 7 = length of "line : ", 10 = max decimal digits in 32-bit number */
        if (max >= (7 + 10)) {
            res += Text_xprintf(bufp, "line %d: ", site->line);
        }
    }

    return (res);
}

/*
 *  ======== ropeText ========
 */
String Text_ropeText(Text_RopeId rope)
{
    return (rope & 0x8000 ? NULL : Text_charTab + rope);
}

/*
 *  ======== visitRope2 ========
 *  Call visFxn on each "part" of the rope until visFxn returns TRUE or we
 *  reach the end of our rope.
 *
 *  The stack array must be large enough to hold the maximum number of
 *  nodes "in" rope.
 */
Void Text_visitRope2(Text_RopeId rope, Fxn visFxn, Ptr visState, String stack[])
{
    Int tos = 0;

    for (;;) {
        Text_Node *node;
        UInt16 index;
        String s = Text_ropeText(rope);
        if (s) {
            stack[tos++] = s;
            break;
        }
        index = rope & 0x7fff;
        node = Text_nodeTab + index;
        stack[tos++] = Text_ropeText(node->right);
        rope = node->left;
    }

    do {
        String s = stack[--tos];
        if (((Text_RopeVisitor)visFxn)(visState, s)) {
            return;
        }
    } while (tos);
}

/*
 *  ======== xprintf ========
 */
Int Text_xprintf(Char **bufp, String fmt, ...)
{
    va_list va;
    Char *b;
    Int res;

    va_start(va, fmt);
    b = (bufp && *bufp) ? *bufp : NULL;

    res = System_vsprintf(b, fmt, va);

    if (b) {
        *bufp += res;
    }

    va_end(va);

    return (res);
}
/*
 *  @(#) xdc.runtime; 2, 1, 0,375; 4-27-2012 14:30:34; /db/ztree/library/trees/xdc/xdc-y25x/src/packages/
 */
