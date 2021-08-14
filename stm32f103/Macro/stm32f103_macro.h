/*
		stm32f103 Macro header file
*/

#include <inttypes.h>

#define IO  volatile
#define UIO(X) volatile uint##X##_t

#define __CORE_PERIPHERAL_BASE_ADDRESS__ 0xE000E000