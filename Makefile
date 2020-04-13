TARGET = output

AS = arm-none-eabi-as
LD = arm-none-eabi-ld
CC = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump
OS = arm-none-eabi-size

ASFLAGS += -mcpu=cortex-m3
ASFLAGS += -mthumb

CFLAGS += -mcpu=cortex-m3
CFLAGS += -mthumb
CFLAGS += -g
CFLAGS += -O0
CFLAGS += -fno-common

CFLAGS += -I./inc
CFLAGS += -I./src

LSCRIPT = ./ld/stm32.ld
LFLAGS += -T$(LSCRIPT)

OBJS = inc/startup_stm32f10x_md_vl.o src/main.o

all: $(TARGET).elf
	$(OC) -O binary $< $(TARGET).bin

upload:
	stm32flash -v -g 0x0 -w $(TARGET).bin /dev/ttyUSB0

$(TARGET).elf: $(OBJS)
	@echo
	@echo Linking: $@
	$(LD) $(LFLAGS) -o $@ $^
	$(OD) -h -S $(TARGET).elf  > $(TARGET).lst

main.o: src/main.c
	@echo
	@echo Compiling: $<
	$(CC) -c $(CFLAGS) -I. src/main.c -o src/main.o

%.o: inc/%.c
	@echo
	@echo Compiling: $<
	$(CC) -c $(CFLAGS) -I. $< -o inc/$@

%.o: inc/%.S
	@echo
	@echo Assembling: $<
	$(AS) $(ASFLAGS) -o inc/$@ $< -alh=inc/$*.lst

clean:
	@echo
	@echo Cleaning:
	$(RM) $(OBJS)
	$(RM) *.o
	$(RM) src/*.o
	$(RM) inc/*.o
	$(RM) *.elf
	$(RM) *.bin
