#include "../Macro/stm32f103_macro.h"

typedef struct __PWR_TYPE__ {
	UIO(32) CR;  // 0x00
	UIO(32) CSR; // 0x04
} __PWR__;

typedef struct __BKP_TYPE__ {
	uint32_t ZERO; 		 // 0x00
	UIO(32) DR1;   		 // 0x04
	UIO(32) DR2;   		 // 0x08
	UIO(32) DR3;   		 // 0x0C
	UIO(32) DR4;   		 // 0x10
	UIO(32) DR5;   		 // 0x14
	UIO(32) DR6;   		 // 0x18
	UIO(32) DR7;   		 // 0x1C
	UIO(32) DR8;   		 // 0x20
	UIO(32) DR9;   		 // 0x24
	UIO(32) DR10;   	 // 0x28
	UIO(32) RTCCR;   	 // 0x2C
	UIO(32) CR;   		 // 0x30
	UIO(32) CSR;   		 // 0x34
	uint32_t ZERO2[2];   // 0x38
	UIO(32) DR11;   	 // 0x40
	UIO(32) DR12;   	 // 0x44
	UIO(32) DR13;   	 // 0x48
	UIO(32) DR14;   	 // 0x4C
	UIO(32) DR15;   	 // 0x50
	UIO(32) DR16;   	 // 0x54
	UIO(32) DR17;   	 // 0x58
	UIO(32) DR18;   	 // 0x5C
	UIO(32) DR19;   	 // 0x60
	UIO(32) DR20;   	 // 0x64
	UIO(32) DR21;   	 // 0x68
	UIO(32) DR22;   	 // 0x6C
	UIO(32) DR23;   	 // 0x70
	UIO(32) DR24;   	 // 0x74
	UIO(32) DR25;   	 // 0x78
	UIO(32) DR26;   	 // 0x7C
	UIO(32) DR27;   	 // 0x80
	UIO(32) DR28;   	 // 0x84
	UIO(32) DR29;   	 // 0x88
	UIO(32) DR30;   	 // 0x8C
	UIO(32) DR31;   	 // 0x90
	UIO(32) DR32;   	 // 0x94
	UIO(32) DR33;   	 // 0x98
	UIO(32) DR34;   	 // 0x9C
	UIO(32) DR35;   	 // 0xA0
	UIO(32) DR36;   	 // 0xA4
	UIO(32) DR37;   	 // 0xA8
	UIO(32) DR38;   	 // 0xAC
	UIO(32) DR39;   	 // 0xB0
	UIO(32) DR40;   	 // 0xB4
	UIO(32) DR41;   	 // 0xB8
	UIO(32) DR42;   	 // 0xBC
} __BKP__;

typedef struct __GPIO_TYPE__ {
	UIO(32) CRL;  // 0x00
	UIO(32) CRH;  // 0x04
	UIO(32) IDR;  // 0x08
	UIO(32) ODR;  // 0x0C
	UIO(32) BSRR; // 0x10
	UIO(32) BRR;  // 0x14
	UIO(32) LCKR; // 0x18
} __GPIO__;

typedef struct __RCC_TYPE__ {
	UIO(32) CR;      // 0x00
	UIO(32) CFGR;    // 0x04
	UIO(32) CIR;     // 0x08
	UIO(32) APB2STR; // 0x0C
	UIO(32) APB1STR; // 0x10
	UIO(32) AHBENR;  // 0x14
	UIO(32) APB2ENR; // 0x18
	UIO(32) APB1ENR; // 0x1C
	UIO(32) BDCR;    // 0x20
	UIO(32) CSR;     // 0x24
	UIO(32) AHBSTR;  // 0x28
	UIO(32) CFGR2;   // 0x2C
} __RCC__;


typedef struct __NVIC_TYPE__ {
	UIO(32)  ISER[3];    // 0x000-0x008
	uint32_t ZERO1[29];  // never used
	UIO(32)  ICER[3];    // 0x080-0x088
	uint32_t ZERO2[93];  // never used
	UIO(32)  ISPR[3];    // 0x200-0x208
	uint32_t ZERO3[29];  // never used
	UIO(32)  ICPR[3];    // 0x280-0x288
	uint32_t ZERO4[29];  // never used
	UIO(32)  IABR[3];    // 0x300-0x308
	uint32_t ZERO5[61];  // never used
	UIO(8)   IPR[68];    // 0x400-0x4??
	uint32_t ZERO6[638]; // never used
	UIO(32)  STIR;       // 0xe00 
} __NVIC__;

typedef struct __STK_TYPE__ {
	UIO(32) CTRL;  // 0x00
	UIO(32) LOAD;  // 0x04
	UIO(32) VAL;   // 0x08
	UIO(32) CALIB; // 0x0c
} __STK__;


//========================= Reigsters ============================

#define GPIOA   ((__GPIO__*)(0x40010800)) // GPIOA
#define GPIOB   ((__GPIO__*)(0x40010C00)) // GPIOB
#define GPIOC   ((__GPIO__*)(0x40011000)) // GPIOC
#define GPIOD   ((__GPIO__*)(0x40011400)) // GPIOD
#define GPIOE   ((__GPIO__*)(0x40011800)) // GPIOE
#define GPIOF   ((__GPIO__*)(0x40011C00)) // GPIOF
#define GPIOG   ((__GPIO__*)(0x40012000)) // GPIOG

#define RCC     ((__RCC__*)(0x40021000))  // RCC

#define BKP     ((__BKP__*)(0x40006C00))  // Backup
#define PWR     ((__PWR__*)(0x40007000))  // Power Control

//================== core peripherals registers ================== 
#define SYSTICK ((__STK__*)(0xE000E010))  // SysTick
#define NVIC    ((__NVIC__*)(0xE000EF00)) // NVIC