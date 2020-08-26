#
# boot script for hd2
#
echo "update NAND"

#nand scrub
#--- u-boot --------------------------------------
mw.b 0x81000000 0xFF 0x20000
if mmc rescan;fatload mmc 0 0x81000000 u-boot_hd2.min.nand; then
	nandecc hw 2;nand erase 0x0 0x20000;nand write.i 0x81000000 0x0 0x20000
fi

mw.b 0x81000000 0xFF 0x30000
if mmc rescan;fatload mmc 0 0x81000000 u-boot_hd2.bin; then
	nand erase 0x020000 0xA0000;nand write.i 0x81000000 0x20000 0x30000
fi

#init env
nand erase 0x0C0000 0x20000

#--- kernel --------------------------------------
mw.b 0x81000000 0xFF 0x300000
if mmc rescan;fatload mmc 0 0x81000000 uImage_hd2; then
	nand erase 0x00220000 0x300000;nand write 0x81000000 0x00220000 ${filesize}
fi

#--- ubifs ---------------------------------------
#nand scrub 0x00520000 0x3000000
#nand scrub 0x00520000 0x3000000
if mmc rescan;fatload mmc 0 0x81000000 rfs_hd2.ubifs; then
	nand erase 0x00520000 0x3000000;nand write 0x81000000 0x00520000 ${filesize}
fi

setenv showlogo 'nand read 0x82100000 0x00120000 0xBB800;logo on 0x82000000;'
setenv bootcmd 'run showlogo;if test ${nand_update} -eq 1; then if mmc rescan; then if run loadbootscript; then run bootscript; fi; fi; else nboot.e 0x81000000 0 0x220000;bootm 0x81000000; fi';
setenv bootargs 'mem=180M console=ttyO0,115200n8 noinitrd rw ubi.mtd=5,2048 rootfstype=ubifs root=ubi0:rootfs ip=off vram=3M notifyk.vpssm3_sva=0xBFD00000' eth=${ethaddr} mcu=${udxii}

#--- reboot ---
setenv nand_update 2
saveenv

#--- mcu -----------------------------------------
if mmc rescan;fatload mmc 0 0x81000000 mcu_hd2.txt; then
	mcu update
fi

#--- reboot ---
re
