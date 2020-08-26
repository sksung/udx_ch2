#------------------------------------------------------------------------------
# Makefile for dvr board static image library
# 10.02.02 by phoong
#------------------------------------------------------------------------------

include $(MCFW_ROOT_PATH)/makerules/common_header_a8.mk
INCLUDE_DIR = -I.
SRC_DIR = $(APP_DIR)/$(BRANCH_DIR)_app/src
LIB_DIR = $(APP_DIR)/lib

.SUFFIXES:


CFLAGS = -O2 $(INCLUDE_DIR) -Wall

LIB=libimg_db.a

DEL=rm -f

#------------------------------------------------------------------------------
OBJS = img_db.o
#------------------------------------------------------------------------------

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:	all \
		clean

all: mkimg $(LIB)
	-@mv $(LIB) $(LIB_DIR)
	-@mv img_db.h $(SRC_DIR)/inc/ucx_db_img.h
	-@$(DEL) *.o *.h
	@echo -e "\n--- make image db done! (`date +'%H:%M:%S'`)---\n"

$(LIB): $(OBJS)
	@echo --- make $(LIB) ---
	$(AR) -rc $@ $^

mkimg:
	-@./bmp2db.out ./bmp .

clean:
	-$(DEL) *.o
#	-$(DEL) $(LIB_DIR)/$(LIB)
