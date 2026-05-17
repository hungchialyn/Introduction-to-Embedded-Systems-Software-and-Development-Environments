include sources.mk

TARGET = c1m2
PLATFORM ?= HOST

ifeq ($(PLATFORM),HOST)
    CC = gcc
    CPPFLAGS = -DHOST -DCOURSE1 -DVERBOSE
    LDFLAGS = -Wl,-Map=$(TARGET).map
    ARCHFLAGS =
else
    CC = arm-none-eabi-gcc
    CPPFLAGS = -DMSP432 -DCOURSE1 -DVERBOSE
    LDFLAGS = -Wl,-Map=$(TARGET).map \
              -T msp432p401r.lds
    ARCHFLAGS = -mcpu=cortex-m4 \
                -mthumb \
                -march=armv7e-m \
                -mfloat-abi=hard \
                -mfpu=fpv4-sp-d16 \
                --specs=nosys.specs
endif

CFLAGS = -Wall \
         -Werror \
         -g \
         -O0 \
         -std=c99 \
         $(ARCHFLAGS)

OBJS = $(SOURCES:.c=.o)

%.i : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -E $< -o $@

%.asm : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -MD -o $@ -c $<

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	size $@

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f src/*.d
	rm -f src/*.i
	rm -f src/*.asm
	rm -f $(TARGET).out
	rm -f $(TARGET).map
