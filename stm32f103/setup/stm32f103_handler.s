	.syntax unified


	.macro DefaultHandler handler_name
	.align 1
	.thumb_func
	.weak \handler_name
	.type \handler_name, %function
\handler_name:
	b .			// Infinite loop
	.size \handler_name, . - \handler_name
	.endm

	.section .isr_vector
	.global __isr_vectors
__isr_vectors:
	.long __entry_stack
	.long ResetHandler
	.long NMIHandler
	.long HardFaultHandler
	.long MemoryManageHandler
	.long BusFaultHandler
	.long UsuageFaultHandler
	.long 0
	.long 0
	.long 0
	.long 0
	.long SVCallHandler
	.long DebugMonitorHandler
	.long 0
	.long PendSVHandler
	.long SysTickHandler
	.long WWDGHandler
	.long PVDHandler
	.long TAMPERHandler
	.long RTCHandler
	.long FLASHandler
	.long RCCHandler
	.long EXTI0_Handler
	.long EXTI1_Handler
	.long EXTI2_Handler
	.long EXTI3_Handler
	.long EXTI4_Hadnler
	.long DMA1_Channel1_Handler
	.long DMA1_Channel2_Handler
	.long DMA1_Channel3_Handler
	.long DMA1_Channel4_Handler
	.long DMA1_Channel5_Handler
	.long DMA1_Channel6_Handler
	.long DMA1_Channel7_Handler
	.long ADC1_2_Handler
	.long USB_HP_CAN_TX_Handler
	.long USB_LP_CAN_RX0_Handler
	.long CAN_RX1_Handler
	.long CAN_SCE_Handler
	.long EXTI9_5_Handler
	.long TIM1_BRK_Handler
	.long TIM1_UP_Handler
	.long TIM1_TRG_COM_Handler
	.long TIM1_CC_Handler
	.long TIM2_Handler
	.long TIM3_Handler
	.long 0
	.long I2C1_EV_Handler
	.long I2C1_ER_Handler
	.long 0
	.long 0
	.long SPI1_Handler
	.long 0
	.long USART1_Handler
	.long USART2_Handler
	.long 0
	.long EXTI15_10_Handler
	.long RTCAlarm_Handler
	.long USBWakeup_Handler

	.section .after_vectors

	// DefaultHandler ResetHandler
	.align 1
	.thumb_func
	.weak ResetHandler
	.type ResetHandler, %function
ResetHandler:
	ldr r0, =_start
	add r0, #2
	bx r0
	.size ResetHandler, . - ResetHandler

DefaultHandler NMIHandler

	// DefaultHandler HardFaultHandler
	.align 1
	.thumb_func
	.weak HardFaultHandler
	.type HardFaultHandler, %function
HardFaultHandler:
	tst lr, #4
	ite eq
	mrseq r0, msp
	mrsne r0, psp
	mov r1, lr
	ldr r2, =HardFaultHandler
	bx r2
	.size HardFaultHandler, . - HardFaultHandler

DefaultHandler MemoryManageHandler

	// DefaultHandler BusFaultHandler
	.align 1
	.thumb_func
	.weak BusFaultHandler
	.type BusFaultHandler, %function
BusFaultHandler:
	tst lr, #4
	ite eq
	mrseq r0, msp
	mrsne r0, psp
	mov r1, lr
	ldr r2, =BusFaultHandler
	bx r2
	.size BusFaultHandler, . - BusFaultHandler

	// DefaultHandler UsuageFaultHandler
	.align 1
	.thumb_func
	.weak UsuageFaultHandler
	.type UsuageFaultHandler, %function
UsuageFaultHandler:
	tst lr, #4
	ite eq
	mrseq r0, msp
	mrsne r0, psp
	mov r1, lr
	ldr r2, =UsuageFaultHandler
	bx r2
	.size UsuageFaultHandler, . - UsuageFaultHandler

DefaultHandler SVCallHandler
DefaultHandler DebugMonitorHandler
DefaultHandler PendSVHandler
DefaultHandler SysTickHandler
DefaultHandler WWDGHandler
DefaultHandler PVDHandler
DefaultHandler TAMPERHandler
DefaultHandler RTCHandler
DefaultHandler FLASHandler
DefaultHandler RCCHandler
DefaultHandler EXTI0_Handler
DefaultHandler EXTI1_Handler
DefaultHandler EXTI2_Handler
DefaultHandler EXTI3_Handler
DefaultHandler EXTI4_Hadnler
DefaultHandler DMA1_Channel1_Handler
DefaultHandler DMA1_Channel2_Handler
DefaultHandler DMA1_Channel3_Handler
DefaultHandler DMA1_Channel4_Handler
DefaultHandler DMA1_Channel5_Handler
DefaultHandler DMA1_Channel6_Handler
DefaultHandler DMA1_Channel7_Handler
DefaultHandler ADC1_2_Handler
DefaultHandler USB_HP_CAN_TX_Handler
DefaultHandler USB_LP_CAN_RX0_Handler
DefaultHandler CAN_RX1_Handler
DefaultHandler CAN_SCE_Handler
DefaultHandler EXTI9_5_Handler
DefaultHandler TIM1_BRK_Handler
DefaultHandler TIM1_UP_Handler
DefaultHandler TIM1_TRG_COM_Handler
DefaultHandler TIM1_CC_Handler
DefaultHandler TIM2_Handler
DefaultHandler TIM3_Handler
DefaultHandler I2C1_EV_Handler
DefaultHandler I2C1_ER_Handler
DefaultHandler SPI1_Handler
DefaultHandler USART1_Handler
DefaultHandler USART2_Handler
DefaultHandler EXTI15_10_Handler
DefaultHandler RTCAlarm_Handler
DefaultHandler USBWakeup_Handler
