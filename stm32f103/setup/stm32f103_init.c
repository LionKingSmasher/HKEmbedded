/*
		stm32f103 init header file
*/

#include "stm32f103_init.h"

extern unsigned long __VEC_START__; // 0x80000000

inline void __attribute__((always_inline)) stm32f103_Init(void){
	SCB->VTOR = (uint32_t)(&__VEC_START__);
}