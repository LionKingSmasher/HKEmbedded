#include "../stm32f103.h"
#include "stm32f103_init.h"

void _exit(int __attribute__((unused)) code){
	while(1);
}

int __attribute__((weak)) main(int argc, char** argv);

void __attribute__((weak)) _start(void){
	stm32f103_Init();
	int argc; char** argv;

	int ret = main(argc, argv);

	_exit(ret);
}