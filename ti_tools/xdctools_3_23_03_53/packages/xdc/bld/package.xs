/* 
 *  Copyright (c) 2008 Texas Instruments and others.
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
 *  ======== package.xs ========
 */

/*
 *  ======== Package.exit ========
 *  Finalize this package
 */
function exit() {
//    print(this.$name + ".exit() ...");
}

/*
 *  ======== Package.init ========
 *  Initialize this package.
 *
 *  This is called after the bld package schema has completely
 *  finished; i.e., at the very end of the "include('xdc.bld')"
 *  processing.
 */
function init () {

    this.BuildEnvironment.onInit();
    this.PackageContents.onInit();

    /* determine hostOSName */
    this.BuildEnvironment.hostOSName = "" + environment["xdc.hostOS"];
    
    if (this.BuildEnvironment.hostOSName == null) {
	if (environment["file.separator"] == "/") {
	    this.BuildEnvironment.hostOSName = "Solaris";
	}
	else {
	    this.BuildEnvironment.hostOSName = "Windows";
	}
    }

    /* initialize hostOS */
    this.BuildEnvironment.hostOS = this.BuildEnvironment.WINDOWS;
    if (this.BuildEnvironment.hostOSName == "Solaris") {
	this.BuildEnvironment.hostOS = this.BuildEnvironment.SOLARIS;
    }
    else if (this.BuildEnvironment.hostOSName == "Linux") {
	this.BuildEnvironment.hostOS = this.BuildEnvironment.LINUX;
    }
}


/*
 *  @(#) xdc.bld; 1, 0, 2,379; 4-27-2012 14:30:16; /db/ztree/library/trees/xdc/xdc-y25x/src/packages/
 */

