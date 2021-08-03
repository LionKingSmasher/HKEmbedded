/*
		stm32f103 Macro header file
*/

#define IO(X)  volatile X
#define UIO(X) volatile uint##X##_t

#define __CORE_PERIPHERAL_BASE_ADDRESS__ 0xE000E000