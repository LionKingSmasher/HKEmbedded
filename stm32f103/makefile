CC=arm-none-eabi-gcc
CPP=arm-none-eabi-g++
OBJCOPY=arm-none-eabi-objcopy
CFLAGS=-mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -T mem.ld -T sections.ld -nostartfiles -Xlinker --gc-sections -L"ldscripts"

C_SOURCES += \
./setup/stm32f103_init.c \
./setup/stm32f103_startup.c

OBJS += \
./setup/stm32f103_init.o \
./setup/stm32f103_startup.o

test.hex: test.elf
	$(OBJCOPY) -O ihex $^ $@

test.elf: main.c $(OBJS)
	$(CPP) -o $@ $^ $(CFLAGS)

setup/%.o: setup/%.c
	$(CC) -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_ITM -DSTM32F103x6 -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o $@ $<

clear:
	rm test.elf test.hex setup/*.o setup/*.d