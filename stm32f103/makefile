CC=arm-none-eabi-g++
OBJCOPY=arm-none-eabi-objcopy
CFLAGS=-mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -T mem.ld -nostartfiles -Xlinker --gc-sections -L"ldscripts"

test.hex: test.elf
	$(OBJCOPY) -O ihex $^ $@

test.elf: main.c setup/stm32f103_init.c setup/stm32f103_startup.c
	$(CC) $(CFLAGS) -o $@ $^