/* --COPYRIGHT--,EPL
 *  Copyright (c) 2008 Texas Instruments and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *      Texas Instruments - initial implementation
 * 
 * --/COPYRIGHT--*/

/*
 *  ======== USCI_B0_I2C_2xx.xs ========
 */

/*
 *  ======== module$meta$init ========
 */
function module$meta$init() 
{
}

/*
 *  ======== instance$meta$init ========
 */
function instance$meta$init(clock) 
{
    this.clock = clock;
}

/*
 *  ======== setUCNACKIE ========
 */
function setUCNACKIE(set)
{
    var REGS = this.$module;
    if (set) {
        this.USCI_B0_I2C_2xx.UCB0I2CIE.UCNACKIE = REGS.UCNACKIE;
    }
    else {
        this.USCI_B0_I2C_2xx.UCB0I2CIE.UCNACKIE = REGS.UCNACKIE_OFF;
    }
    return set;
}

/*
 *  ======== getUCNACKIE ========
 */
function getUCNACKIE()
{
    var REGS = this.$module;
    if (this.USCI_B0_I2C_2xx.UCB0I2CIE.UCNACKIE == REGS.UCNACKIE) {
        return true;
    }
    else {
        return false;
    }
}

/*
 *  ======== setUCSTPIE ========
 */
function setUCSTPIE(set)
{
    var REGS = this.$module;
    if (set) {
        this.USCI_B0_I2C_2xx.UCB0I2CIE.UCSTPIE = REGS.UCSTPIE;
    }
    else {
        this.USCI_B0_I2C_2xx.UCB0I2CIE.UCSTPIE = REGS.UCSTPIE_OFF;
    }
    return set;
}

/*
 *  ======== getUCSTPIE ========
 */
function getUCSTPIE()
{
    var REGS = this.$module;
    if (this.USCI_B0_I2C_2xx.UCB0I2CIE.UCSTPIE == REGS.UCSTPIE) {
        return true;
    }
    else {
        return false;
    }
}
    
/*
 *  ======== setUCSTTIE ========
 */
function setUCSTTIE(set)
{
    var REGS = this.$module;
    if (set) {
        this.USCI_B0_I2C_2xx.UCB0I2CIE.UCSTTIE = REGS.UCSTTIE;
    }
    else {
        this.USCI_B0_I2C_2xx.UCB0I2CIE.UCSTTIE = REGS.UCSTTIE_OFF;
    }
    return set;
}

/*
 *  ======== getUCSTTIE ========
 */
function getUCSTTIE()
{
    var REGS = this.$module;
    if (this.USCI_B0_I2C_2xx.UCB0I2CIE.UCSTTIE == REGS.UCSTTIE) {
        return true;
    }
    else {
        return false;
    }
}
    
/*
 *  ======== setUCALIE ========
 */
function setUCALIE(set)
{
    var REGS = this.$module;
    if (set) {
        this.USCI_B0_I2C_2xx.UCB0I2CIE.UCALIE = REGS.UCALIE;
    }
    else {
        this.USCI_B0_I2C_2xx.UCB0I2CIE.UCALIE = REGS.UCALIE_OFF;
    }
    return set;
}

/*
 *  ======== getUCALIE ========
 */
function getUCALIE()
{
    var REGS = this.$module;
    if (this.USCI_B0_I2C_2xx.UCB0I2CIE.UCALIE == REGS.UCALIE) {
        return true;
    }
    else {
        return false;
    }
}
