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
##################################################
# Target Platform (Default: HOST)
##################################################
PLATFORM ?= HOST

##################################################
# Include Source List
##################################################
include sources.mk

##################################################
# General Flags
##################################################
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS =
LDFLAGS =
INCLUDES =

##################################################
# Platform Specific Configuration
##################################################
ifeq ($(PLATFORM),HOST)

CC = gcc
CPPFLAGS += -DHOST

INCLUDES += -I include/common

else

CC = arm-none-eabi-gcc
CPPFLAGS += -DMSP432

CFLAGS += -mcpu=cortex-m4 -mthumb -march=armv7e-m \
          -mfloat-abi=hard -mfpu=fpv4-sp-d16

LDFLAGS += -T msp432p401r.lds \
           -mcpu=cortex-m4 -mthumb -march=armv7e-m \
           -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
           --specs=nosys.specs

INCLUDES += -I include/common \
            -I include/msp432 \
            -I include/CMSIS

endif

##################################################
# Object Files
##################################################
OBJECTS = $(SOURCES:.c=.o)

##################################################
# Build Target
##################################################
.PHONY: build
build: $(OBJECTS)
	$(CC) $(OBJECTS) -o c1m2.out $(LDFLAGS) -Wl,-Map=c1m2.map
	size c1m2.out

##################################################
# Compile All (No Linking)
##################################################
.PHONY: compile-all
compile-all: $(OBJECTS)

##################################################
# Pattern Rules
##################################################

# Object Files + Dependency Files
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# Preprocessed Output
%.i: %.c
	$(CC) $(CPPFLAGS) $(INCLUDES) -E $< -o $@

# Assembly Output
%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

##################################################
# Clean
##################################################
.PHONY: clean
clean:
	rm -f src/*.o src/*.d src/*.i src/*.asm *.out *.map

##################################################
# Include Dependency Files
##################################################
-include $(SOURCES:.c=.d)

$(info SOURCES=$(SOURCES))
$(info OBJECTS=$(OBJECTS))

