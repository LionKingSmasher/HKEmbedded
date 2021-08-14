//#include "../stm32f103.h"
#include "stm32f103_init.h"

// extern unsigned long __VEC_START__;

extern int main(int argc, char** argv);

void _start(void);

void _exit(int __attribute__((unused)) code){
	while(1);
}


void __attribute__((section(".after_vectors"), weak, noreturn)) _start(void){
	stm32f103_Init();

	int argc; char** argv;

	int ret = main(argc, argv);

	_exit(ret);
}