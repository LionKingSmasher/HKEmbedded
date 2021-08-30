#include "../Macro/stm32f103_macro.h"
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

#define GPIOA   ((__GPIO__*)(0x40010800)) // GPIOA
#define GPIOB   ((__GPIO__*)(0x40010C00)) // GPIOB
#define GPIOC   ((__GPIO__*)(0x40011000)) // GPIOC
#define GPIOD   ((__GPIO__*)(0x40011400)) // GPIOD
#define GPIOE   ((__GPIO__*)(0x40011800)) // GPIOE
#define GPIOF   ((__GPIO__*)(0x40011C00)) // GPIOF
#define GPIOG   ((__GPIO__*)(0x40012000)) // GPIOG

#define RCC     ((__RCC__*)(0x40021000))  // RCC

//================== core peripherals registers ================== 
#define SYSTICK ((__STK__*)(0xE000E010))  // SysTick
#define NVIC    ((__NVIC__*)(0xE000EF00)) // NVIC