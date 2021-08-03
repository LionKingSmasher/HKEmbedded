/*
		stm32f103 init header file
*/

#include "stm32f103_init.h"

extern uint32_t __VEC_START__; // 0x80004000

void __attribute__((always_inline)) stm32f103_Init(void){
	SCB->VTOR = __VEC_START__ << 9;
}