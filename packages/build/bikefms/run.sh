#!/bin/sh

test -f ./load.sh || exit 0
test -f ./init.sh || exit 0

if [ -x ./init.sh ]; then
	./init.sh
fi

if [ -x ./load.sh ]; then
	./load.sh
fi

if [ -e /mmc/hw_test.out ]; then
	echo "Running Hardware Test!!"
	chmod +x /mmc/hw_test.out
	/mmc/hw_test.out
fi

if [ -x ./bin/bikefms_app.out ]; then
	./bin/iw_scan.out &
	./bin/bikefms_app.out &
fi
