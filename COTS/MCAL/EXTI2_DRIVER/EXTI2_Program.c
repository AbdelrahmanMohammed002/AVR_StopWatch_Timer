/*
 * EXTI2_Program.c
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../EXTI2_DRIVER/EXTI2_Config.h"
#include "../EXTI2_DRIVER/EXTI2_Interface.h"
#include "../EXTI2_DRIVER/EXTI2_Private.h"

#define NULL   ((void *) 0)

void (*ptr_to_INT2)(void) = NULL;

/**
 * @brief Initialize external interrupt 2.
 */
void MEXTI2_vInit(void) {
	// Clear all ISC bits
	CLR_BIT(MCUCSR, ISC2);

	// Initialize INT2
#if ISC_INT2 == FALLING_EDGE
	CLR_BIT(MCUCSR, ISC2);
#elif ISC_INT2 == RISING_EDGE
	SET_BIT(MCUCSR, ISC2);
#endif

	// Enable or disable INT2
#if INT2_STATUS == ENABLED
	SET_BIT(GICR, INT2);
#elif INT2_STATUS == DISABLED
	CLR_BIT(GICR, INT2);
#endif

	// Clear interrupt flag
	SET_BIT(GIFR, INT2);
}

/**
 * @brief Set the callback function for external interrupt 2.
 *
 * @param ptr_to_fun Pointer to the callback function.
 */
void MEXTI2_vSetCallBack(void (*ptr_to_fun)(void)) {
	ptr_to_INT2 = ptr_to_fun;
}

// ISR of INT2
void __vector_3() {
	if (ptr_to_INT2 != NULL)
		ptr_to_INT2();
}
