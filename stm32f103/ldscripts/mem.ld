MEMORY {
	RAM 	   (xrw) : ORIGIN = 0x02000000, LENGTH = 10K /* stm32f103t6 ram */
	BOOTLOADER (rx)  : ORIGIN = 0x08000000, LENGTH = 0x4000 /* bootloader for stm32f103t6 */
	APP        (rx)  : ORIGIN = 0x08004000, LENGTH = 32K-0x4000 /* App */
}