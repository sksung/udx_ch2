# invoke SourceDir generated makefile for MAIN_APP_m3video.pem3
MAIN_APP_m3video.pem3: .libraries,MAIN_APP_m3video.pem3
.libraries,MAIN_APP_m3video.pem3: package/cfg/MAIN_APP_m3video_pem3.xdl
	$(MAKE) -f package/cfg/MAIN_APP_m3video_pem3.src/makefile.libs

clean::
	$(MAKE) -f package/cfg/MAIN_APP_m3video_pem3.src/makefile.libs clean

