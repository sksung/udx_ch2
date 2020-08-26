#!/bin/sh

# start application -----------------------------
echo -e "start application"

app_dir="bikefms"

is_mmc=0
check_mmc=`grep mmcblk0p1 /proc/partitions`
# Make Volume and default directory
if [ -n "$check_mmc" ]; then
	is_mmc=1
	#dosfslabel /dev/mmcblk0p1 ubx
	sync
	cd /opt/
fi

echo "mmc detect : $is_mmc"

if [ -x ./$app_dir/run.sh ]; then
	cd ./$app_dir/
	./run.sh $is_mmc
fi

