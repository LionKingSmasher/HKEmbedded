#include "../stm32f103.h"
#include "stm32f103_init.h"

void _exit(int __attribute__((unused)) code){
	while(1);
}

static void DefaultFunction(void){
	_exit(0);
}

void __attribute__((weak, alias("DefaultFunction"))) main(int argc, char** argv);

void __attribute__((weak)) _start(void){
	stm32f103_Init();
	int argc; char** argv;

	int ret = main(argc, argv);

	_exit(ret);
}