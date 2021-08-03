#include "../Macro/stm32f103_macro.h"
#include <stdint.h>

typedef struct __SCB__ {
	UIO(32) CPUID; // 0x00
	UIO(32) ICSR;  // 0x04
	UIO(32) VTOR;  // 0x08
	UIO(32) AIRCR; // 0x0c
	UIO(32) SCR;   // 0x10
	UIO(32) CCR;   // 0x14
	UIO(32) SHPR1; // 0x18
	UIO(32) SHPR2; // 0x1c
	UIO(32) SHPR3; // 0x20
	UIO(32) SHCSR; // 0x24
	UIO(32) CFSR;  // 0x28
	UIO(32) HFSR;  // 0x2c
	UIO(32) MMFAR; // 0x30
	UIO(32) BFAR;  // 0x34
} __SCB_TYPE__;

#define SCB ((__SCB_TYPE__*)(__CORE_PERIPHERAL_BASE_ADDRESS__+0xd00)) // SCB register

void stm32f103_Init(void);