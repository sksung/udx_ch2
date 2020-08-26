#------------------------------------------------------------------------------
# Makefile for dvr board static sound library
# 13.07.01 by phoong
#------------------------------------------------------------------------------

include $(MCFW_ROOT_PATH)/makerules/common_header_a8.mk
INCLUDE_DIR = -I.
LIB_DIR = $(APP_DIR)/lib
SRC_DIR = $(APP_DIR)/$(BRANCH_DIR)_app/src

.SUFFIXES:


CFLAGS = -O2 $(INCLUDE_DIR) -Wall

LIB=libsnd_db.a

DEL=rm -f

#------------------------------------------------------------------------------
OBJS = snd_db.o
#------------------------------------------------------------------------------

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:	all \
		clean

all: mkwav $(LIB)
	-@mv $(LIB) $(LIB_DIR)
	-@mv snd_db.h $(SRC_DIR)/inc/ucx_db_snd.h
	-@$(DEL) *.o *.h
	@echo -e "\n--- make sound db done! (`date +'%H:%M:%S'`)---\n"

$(LIB): $(OBJS)
	@echo --- make $(LIB) ---
	$(AR) -rc $@ $^

mkwav:
	-@./wav2db.out ./wav .

clean:
	-$(DEL) *.o
#	-$(DEL) $(LIB_DIR)/$(LIB)
