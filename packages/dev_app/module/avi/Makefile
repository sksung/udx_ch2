ROOTDIR = ../../..
include $(ROOTDIR)/Rules.make

INCLUDES = -I . -I src/

TI_TOOLS_DIR= 		../../../../ti_tools
DEV_KIT_DIR=		$(TI_TOOLS_DIR)/linux_devkit
BUILD_PREFIX= 		$(DEV_KIT_DIR)/bin/arm-arago-linux-gnueabi-

CC := $(BUILD_PREFIX)gcc
CPLUSPLUS = $(BUILD_PREFIX)g++
STRIP := $(BUILD_PREFIX)strip

AR_FLAGS += -r
AR = $(BUILD_PREFIX)ar

TARGET_DIR = .
LIB_PATH := ./lib
LDFLAGS := -L$(LIB_PATH) $(LDFLAGS)
CFLAGS = $(INCLUDES) -D_LINUX -g -Wall

LIBS = src/libwriter.a

REL_LIB = libmulti_avi.a
REL_OBJS = udavi.o

all: $(REL_LIB)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

.cpp.o:
	$(CPLUSPLUS) -c $(CFLAGS) $< -o $@

udavi.cpp:	udavi.h

$(REL_LIB): $(REL_OBJS) $(LIBS)
	$(AR) $(AR_FLAGS) $(REL_LIB) $(LIBS) $(REL_OBJS)
	cp $(REL_LIB) ../../lib/
clean:
	rm -f $(TARGET_DIR)/$(REL_LIB)
	rm -f $(TARGET_DIR)/$(REL_OBJS)

install:
#	install -d $(EXEC_DIR)
#	install $(TARGET_DIR)/$(TARGET_EXE) $(EXEC_DIR)


#$(TARGET_EXE): $(TARGET_EXE).o
#	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $^ $(TARGET_EXE).c
#	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(EXTRALIBS)
#	$(AR) $(AR_FLAGS) lib$(TARGET_EXE).a $(LIBS) $(TARGET_EXE).o
#	$(STRIP) $@

