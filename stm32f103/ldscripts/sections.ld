__stack = ORIGIN(RAM) + LENGTH(RAM);

__entry_stack = __stack;

__main_stack_size = 1024;

PROVIDE(_main_stack_size = __main_stack_size);
__main_stack_limit = __stack - __main_stack_size;

PROVIDE (_main_stack_limit = __main_stack_limit);

minimum_stack_size = 256;

ENTRY(_start)

SECTIONS
{
	.isr_vector : ALIGN(4)
	{
		FILL(0xFF)
		__VEC_START__  = ABSOLUTE(.);
		__VEC_STARTS__ = ABSOLUTE(.);
		KEEP(*(.isr_vector))
		KEEP(*(.cfmconfig))

		*(.after_vectors .after_vectors.*)
	} > BOOTLOADER

	.text : ALIGN(4)
	{
		*(.text .text.*)
		*(.rodata .rodata.* .constdata .constdata.*)
	} > APP
}