## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,em3 linker.cmd \
  package/cfg/MAIN_APP_m3video_pem3.oem3 \

linker.cmd: package/cfg/MAIN_APP_m3video_pem3.xdl
	$(SED) 's"^\"\(package/cfg/MAIN_APP_m3video_pem3cfg.cmd\)\"$""\"/home/sksung/work/udx/ch2/packages/mcfw_sdk/build/ipnc_rdk/obj/ti810x-evm/m3video/debug/ipnc_rdk_configuro/\1\""' package/cfg/MAIN_APP_m3video_pem3.xdl > $@
