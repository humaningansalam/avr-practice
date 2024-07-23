###############################################################################
# Makefile for the project AVR0615_01
###############################################################################

## General Flags
PROJECT = AVR0615_01
MCU = atmega128
TARGET = AVR0615_01.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -O2 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=AVR0615_01.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"D:\avr\AVR0615_01\inc" 

## Objects that must be built in order to link
OBJECTS = main.o buzzer.o fnd.o keypad.o led.o timer.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) AVR0615_01.hex AVR0615_01.eep AVR0615_01.lss size

## Compile
main.o: ../main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

buzzer.o: ../src/buzzer.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

fnd.o: ../src/fnd.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

keypad.o: ../src/keypad.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

led.o: ../src/led.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

timer.o: ../src/timer.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) AVR0615_01.elf dep/* AVR0615_01.hex AVR0615_01.eep AVR0615_01.lss AVR0615_01.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

