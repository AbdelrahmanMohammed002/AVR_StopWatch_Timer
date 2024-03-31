/*
 * EXTI0_Program.c
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../EXTI0_DRIVER/EXTI0_Config.h"
#include "../EXTI0_DRIVER/EXTI0_Interface.h"
#include "../EXTI0_DRIVER/EXTI0_Private.h"

#define NULL   ((void *) 0)

// Function pointer to store interrupt callback
void (*ptr_to_INT0)(void) = NULL;

/**
 * @brief Initialize external interrupt 0.
 */
void MEXTI0_vInit(void) {
	// Clear all ISC bits
	CLR_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);

	// Initialize INT0
#if ISC_INT0 == ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR, ISC00);
#elif ISC_INT0 == FALLING_EDGE
	SET_BIT(MCUCR, ISC01);
#elif ISC_INT0 == RISING_EDGE
	SET_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
#endif

	/*
	 * Initialize INT0
	 */
#if INT0_STATUS == ENABLED
	SET_BIT(GICR, INT0);
#elif INT0_STATUS == DISABLED
	CLR_BIT(GICR, INT0);
#endif

	/*
	 * Clear flag bits
	 */
	SET_BIT(GIFR, INT0);
}

/**
 * @brief Set the callback function for external interrupt 0.
 *
 * @param ptr_to_fun Pointer to the callback function.
 */
void MEXTI0_vSetCallBack(void (*ptr_to_fun)(void)) {
	ptr_to_INT0 = ptr_to_fun;
}

// ISR of INT0
void __vector_1() {
	if (ptr_to_INT0 != NULL)
		ptr_to_INT0();
}
