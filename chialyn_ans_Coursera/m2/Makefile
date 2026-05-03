#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# 輸出檔名
TARGET = c1m2

# 平台判斷
ifeq ($(PLATFORM),HOST)
    CC      = gcc
    CPPFLAGS = -DHOST
    LDFLAGS  = -Wl,-Map=$(TARGET).map
    ARCHFLAGS =

else
    CC      = arm-none-eabi-gcc
    CPPFLAGS = -DMSP432
    LDFLAGS  = -Wl,-Map=$(TARGET).map \
               -T msp432p401r.lds
    ARCHFLAGS = -mcpu=cortex-m4 \
                -mthumb \
                -march=armv7e-m \
                -mfloat-abi=hard \
                -mfpu=fpv4-sp-d16 \
                --specs=nosys.specs
endif

# 兩個平台都要加的旗標
CFLAGS = -Wall \
         -Werror \
         -g \
         -O0 \
         -std=c99 \
         $(ARCHFLAGS)

# 把 SOURCES 裡的 .c 換成 .o
OBJS = $(SOURCES:.c=.o)

# ---- 產生預處理檔 .i ----
%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -E $< -o $@

# ---- 產生組語檔 .asm ----
%.asm : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

# ---- 產生物件檔 .o ----
%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -MD -o $@ -c $<

# ---- 編譯所有 .o 但不 link ----
.PHONY: compile-all
compile-all: $(OBJS)

# ---- 完整編譯並 link ----
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	size $@

# ---- 清除所有產生的檔案 ----
.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f src/*.d
	rm -f src/*.i
	rm -f src/*.asm
	rm -f $(TARGET).out
	rm -f $(TARGET).map

