#include "../Macro/stm32f103_macro.h"
#include <stdint.h>

typedef struct __SCB__ {
	uint32_t CPUID; // 0x00
	uint32_t ICSR;  // 0x04
	uint32_t VTOR;  // 0x08
	uint32_t AIRCR; // 0x0c
	uint32_t SCR;   // 0x10
	uint32_t CCR;   // 0x14
	uint32_t SHPR1; // 0x18
	uint32_t SHPR2; // 0x1c
	uint32_t SHPR3; // 0x20
	uint32_t SHCSR; // 0x24
	uint32_t CFSR;  // 0x28
	uint32_t HFSR;  // 0x2c
	uint32_t MMFAR; // 0x30
	uint32_t BFAR;  // 0x34
} __SCB_TYPE__;

#define SCB ((IO(__SCB_TYPE__)*)0xe000e008) // SCB

void stm32f103_Init(void);