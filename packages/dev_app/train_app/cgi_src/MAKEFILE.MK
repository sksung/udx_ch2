include $(MCFW_ROOT_PATH)/makerules/common_header_a8.mk

INCLUDE += $(OSA_INC) -I$(KERNELDIR)/usr/include

LIBS= $(LIB_DIR)/ipnc_rdk_osa.a

C_FLAGS += -Wall -Warray-bounds -O3 -pthread $(INCLUDE)

SOURCES  = $(wildcard *.c)
OBJFILES = $(SOURCES:%.c=%.cgi)
#CGIFILES = $(SOURCES:%.o=%.cgi)
TARGET = CGI

$(TARGET): $(OBJFILES)

%.cgi:%.c
	@echo \# $^: make cgi...
	$(CC) $(C_FLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.cgi

#include $(MCFW_ROOT_PATH)/makerules/common_footer_a8.mk

