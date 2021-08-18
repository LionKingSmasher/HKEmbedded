/*
		stm32f103 init header file
*/

#include "stm32f103_init.h"

extern unsigned long __VEC_START__; // 0x80000000

inline void __attribute__((always_inline)) stm32f103_Init(void){
	SCB->VTOR = (uint32_t)(&__VEC_START__);
}

void __attribute__((weak)) stm32f103_Init_args(int* __argc, char*** __argv){
	static char argv_1[] = ""; // last stored argv. So argv_1 has 'static'

	static char* argv[2] = {
		argv_1, // First
		NULL    // Last
	};

	*__argc = 1; // size
	*__argv = &argv[0];
	return;
}