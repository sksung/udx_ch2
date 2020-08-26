app:
	make -fMAKEFILE.MK libs TARGET=depend
	make -fMAKEFILE.MK libs
	make -fMAKEFILE.MK apps TARGET=exe

app_demo:
	make -fMAKEFILE.MK -C$(APP_DIR)/graphic MODULE=app_demo $(TARGET)
	make -fMAKEFILE.MK -C$(APP_DIR)/device MODULE=app_demo $(TARGET)
	make -fMAKEFILE.MK -C$(APP_DIR)/demo MODULE=app_demo $(TARGET)

ucx_app:
ifeq ($(UBX_TARGET), UBX_CAR)
	make -fMAKEFILE.MK -C$(APP_DIR)/graphic MODULE=$(BRANCH_DIR)_app $(TARGET)
	make -fMAKEFILE.MK -C$(APP_DIR)/device MODULE=$(BRANCH_DIR)_app $(TARGET)
	make -fMAKEFILE.MK -C$(APP_DIR)/module/rtsptx MODULE=$(BRANCH_DIR)_app $(TARGET)
	make -fMAKEFILE.MK -C$(APP_DIR)/$(BRANCH_DIR)_app/control_sock MODULE=$(BRANCH_DIR)_app $(TARGET)
	make -fMAKEFILE.MK -C$(APP_DIR)/$(BRANCH_DIR)_app/src MODULE=$(BRANCH_DIR)_app $(TARGET)
endif

libs: app_demo ucx_app

apps:
	make -fMAKEFILE.MK -C$(APP_DIR)/demo MODULE=app_demo $(TARGET)
	make -fMAKEFILE.MK -C$(APP_DIR)/$(BRANCH_DIR)_app/src MODULE=$(BRANCH_DIR)_app $(TARGET)

clean:
	make -fMAKEFILE.MK libs TARGET=clean

all: clean apps

.PHONY: app_demo ucx_app apps clean app all
