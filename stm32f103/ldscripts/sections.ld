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