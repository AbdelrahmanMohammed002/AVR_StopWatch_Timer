#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"

// AVR CPU Core -> Status Register
// 1 enable
// 0 disable


void MGIE_vEnableInterrupts(void)
{
	SET_BIT(SREG, I);
}

void MGIE_vDisableInterrupts(void)
{
	CLR_BIT(SREG, I);
}

