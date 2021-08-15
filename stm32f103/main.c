/*
		Test File for HKEmbedded

	
	Written by LionKingSmasher

*/

#include "stm32f103.h"

int main(int argc, char** argv){
	RCC->APB2ENR |= 0x01 << 4;
	while(1);
	return 0;
}