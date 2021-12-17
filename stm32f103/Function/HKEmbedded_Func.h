#include "../Memory/stm32f103_memory.h"

enum HKEmbedded_Bit_Set_t {
	BIT_SET = 0,
	BIT_RESET
};

//============================== Bit ===============================
#define HK_BIT_SET(REG, BIT) REG |= (0x01 << BIT)
#define HK_BIT_CLEAR(REG, BIT) REG &= ~(0x01 << BIT)
#define HK_BIT_TOGGLE(REG, BIT) REG ^= (0x01 << BIT)
//==================================================================

//============================== GPIO ==============================
enum GPIO_Enum {
	GPIO_CRL = 0,
	GPIO_CRH,
	GPIO_IDR,
	GPIO_ODR,
	GPIO_BSRR,
	GPIO_BRR,
	GPIO_LCKR
};

void HKEmbedded_GPIO_Set(__GPIO__*, GPIO_Enum)
void HKEmbedded_GPIO_Reset(__GPIO__*, GPIO_Enum)
//==================================================================