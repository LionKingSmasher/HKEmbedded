#include "stm32f103_init.h"

extern unsigned int __entry_stack;

typedef void (*const stm32f103Handler)(void);

void __attribute__((section(".after_vectors"))) NoneHandler(void){
	while(1);
}

void __attribute__((section(".after_vectors"), noreturn)) ResetHandler(void){
	_start();
}

void __attribute__((alias("NoneHandler"), weak)) NMIHandler(void);

void __attribute__((section(".after_vectors"), weak, naked)) HardFaultHandler(void){
	asm volatile(
		" tst lr, #4 \n"
		" ite eq \n"
		" mrseq r0, msp \n"
		" mrsne r0, psp \n"
		" mov r1, lr\n"
		" ldr r2, =HardFaultHandler \n"
		" bx r2"
		:
		:
		:
	);
}

void __attribute__((alias("NoneHandler"), weak)) MemoryManageHandler(void);

void __attribute__((section(".after_vectors"), weak, naked)) BusFaultHandler(void){
	asm volatile(
		" tst lr, #4 \n"
		" ite eq \n"
		" mrseq r0, msp \n"
		" mrsne r0, psp \n"
		" mov r1, lr\n"
		" ldr r2, =BusFaultHandler \n"
		" bx r2"
		:
		:
		:
	);
}

void __attribute__((section(".after_vectors"), weak, naked)) UsuageFaultHandler(void){
	asm volatile(
		" tst lr, #4 \n"
		" ite eq \n"
		" mrseq r0, msp \n"
		" mrsne r0, psp \n"
		" mov r1, lr\n"
		" ldr r2, =UsuageFaultHandler \n"
		" bx r2"
		:
		:
		:
	);
}

void __attribute__((alias("NoneHandler"), weak)) SVCallHandler(void);
void __attribute__((alias("NoneHandler"), weak)) DebugMonitorHandler(void);
void __attribute__((alias("NoneHandler"), weak)) PendSVHandler(void);

void __attribute__((section(".after_vectors"), weak)) SysTickHandler(void){

}

void __attribute__((alias("NoneHandler"), weak)) WWDGHandler(void);
void __attribute__((alias("NoneHandler"), weak)) PVDHandler(void);
void __attribute__((alias("NoneHandler"), weak)) TAMPERHandler(void);
void __attribute__((alias("NoneHandler"), weak)) RTCHandler(void);
void __attribute__((alias("NoneHandler"), weak)) FLASHandler(void);
void __attribute__((alias("NoneHandler"), weak)) RCCHandler(void);
void __attribute__((alias("NoneHandler"), weak)) EXTI0_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) EXTI1_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) EXTI2_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) EXTI3_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) EXTI4_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA1_Channel1_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA1_Channel2_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA1_Channel3_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA1_Channel4_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA1_Channel5_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA1_Channel6_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA1_Channel7_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) ADC1_2_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) USB_HP_CAN_TX_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) USB_LP_CAN_RX0_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) CAN_RX1_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) CAN_SCE_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) EXTI9_5_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM1_BRK_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM1_UP_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM1_TRG_COM_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM1_CC_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM2_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM3_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM4_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) I2C1_EV_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) I2C1_ER_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) I2C2_EV_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) I2C2_ER_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) SPI1_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) SPI2_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) USART1_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) USART2_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) USART3_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) EXTI15_10_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) RTCAlarm_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) USBWakeup_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM8_BRK_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM8_UP_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM8_TRG_COM_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM8_CC_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) ADC3_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) FSMC_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) SDIO_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM5_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) SPI3_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) UART4_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) UART5_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM6_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) TIM7_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA2_Channel1_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA2_Channel2_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA2_Channel3_Handler(void);
void __attribute__((alias("NoneHandler"), weak)) DMA2_Channel4_5_Handler(void);

__attribute__((section(".isr_vector"), used)) stm32f103Handler __isr_vectors[] = {
	(stm32f103Handler)&__entry_stack, // 0x00
	ResetHandler, 					  // 0x04
	NMIHandler,						  // 0x08
	HardFaultHandler,				  // 0x0c
	MemoryManageHandler,			  // 0x10
	BusFaultHandler,				  // 0x14
	UsuageFaultHandler,				  // 0x18
	0,								  // 0x1c (Reserved)
	0,								  // 0x20 (Reserved)
	0,								  // 0x24 (Reserved)
	0,								  // 0x28 (Reserved)
	SVCallHandler,					  // 0x2c
	DebugMonitorHandler,			  // 0x30
	0,								  // 0x34 (Reserved)
	PendSVHandler,					  // 0x38
	SysTickHandler,					  // 0x3c
	WWDGHandler,					  // 0x40
	PVDHandler,						  // 0x44
	TAMPERHandler,					  // 0x48
	RTCHandler,					  // 0x4c
	FLASHandler,					  // 0x50
	RCCHandler,						  // 0x54
	EXTI0_Handler,					  // 0x58
	EXTI1_Handler,					  // 0x5C
	EXTI2_Handler,					  // 0x60
	EXTI3_Handler,					  // 0x64
	EXTI4_Handler,					  // 0x68
	DMA1_Channel1_Handler,			  // 0x6c
	DMA1_Channel2_Handler,			  // 0x70
	DMA1_Channel3_Handler,			  // 0x74
	DMA1_Channel4_Handler,			  // 0x78
	DMA1_Channel5_Handler,			  // 0x7c
	DMA1_Channel6_Handler,			  // 0x80
	DMA1_Channel7_Handler,			  // 0x84
	ADC1_2_Handler,					  // 0x88
	USB_HP_CAN_TX_Handler,			  // 0x8c
	USB_LP_CAN_RX0_Handler,			  // 0x90
	CAN_RX1_Handler,				  // 0x94
	CAN_SCE_Handler,				  // 0x98
	EXTI9_5_Handler,				  // 0x9c
	TIM1_BRK_Handler,				  // 0xa0
	TIM1_UP_Handler,				  // 0xa4
	TIM1_TRG_COM_Handler,			  // 0xa8
	TIM1_CC_Handler,				  // 0xac
	TIM2_Handler,					  // 0xb0
	TIM3_Handler,					  // 0xb4
	0,								  // 0xb8
	I2C1_EV_Handler,				  // 0xbc
	I2C1_ER_Handler,				  // 0xc0
	0,								  // 0xc4 (reserved)
	0,								  // 0xc8 (Reserved)
	SPI1_Handler,					  // 0xcc
	0,								  // 0xD0 (Reserved)
	USART1_Handler,					  // 0xD4
	USART2_Handler,					  // 0xD8
	0,								  // 0xDC (reserved)
	EXTI15_10_Handler,				  // 0xE0
	RTCAlarm_Handler,				  // 0xE4
	USBWakeup_Handler,				  // 0xE8
	// TIM8_BRK_Handler,				  // 0xEC
	// TIM8_UP_Handler,				  // 0xF0
	// TIM8_TRG_COM_Handler,			  // 0xF4
	// TIM8_CC_Handler,				  // 0xF8
	// ADC3_Handler,					  // 0xFC
	// FSMC_Handler,					  // 0x100
	// SDIO_Handler,					  // 0x104
	// TIM5_Handler,					  // 0x108
	// SPI3_Handler,					  // 0x10C
	// UART4_Handler,					  // 0x110
	// UART5_Handler,					  // 0x114
	// TIM6_Handler,					  // 0x118
	// TIM7_Handler,					  // 0x11C
	// DMA2_Channel1_Handler,			  // 0x120
	// DMA2_Channel2_Handler,			  // 0x124
	// DMA2_Channel3_Handler,			  // 0x128
	// DMA2_Channel4_5_Handler,		  // 0x12C
};