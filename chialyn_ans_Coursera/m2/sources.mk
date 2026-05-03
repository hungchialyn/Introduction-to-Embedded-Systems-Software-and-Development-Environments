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
 

# HOST 平台只需要兩個檔案
ifeq ($(PLATFORM),HOST)
    SOURCES = src/main.c \
              src/memory.c

    INCLUDES = -I include/common

# MSP432 需要全部五個檔案
else
    SOURCES = src/main.c \
              src/memory.c \
              src/interrupts_msp432p401r_gcc.c \
              src/startup_msp432p401r_gcc.c \
              src/system_msp432p401r.c

    INCLUDES = -I include/common \
               -I include/msp432 \
               -I include/CMSIS
endif
