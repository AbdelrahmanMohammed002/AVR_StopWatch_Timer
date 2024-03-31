/*
 * EXTI1_Program.c
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../EXTI1_DRIVER/EXTI1_Config.h"
#include "../EXTI1_DRIVER/EXTI1_Interface.h"
#include "../EXTI1_DRIVER/EXTI1_Private.h"

void (*ptr_to_INT1)(void) = NULL;

/**
 * @brief Initialize external interrupt 1.
 */
void MEXTI1_vInit(void) {
	// Clear all ISC bits
	CLR_BIT(MCUCR, ISC10);
	CLR_BIT(MCUCR, ISC11);

	// Initialize INT1
#if ISC_INT1 == ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR, ISC10);
#elif ISC_INT1 == FALLING_EDGE
	SET_BIT(MCUCR, ISC11);
#elif ISC_INT1 == RISING_EDGE
	SET_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);
#endif

	// Enable or disable INT1
#if INT1_STATUS == ENABLED
	SET_BIT(GICR, INT1);
#elif INT1_STATUS == DISABLED
	CLR_BIT(GICR, INT1);
#endif

	// Clear flag bits
	SET_BIT(GIFR, INT1);
}

/**
 * @brief Set the callback function for external interrupt 1.
 *
 * @param ptr_to_fun Pointer to the callback function.
 */
void MEXTI1_vSetCallBack(void (*ptr_to_fun)(void)) {
	ptr_to_INT1 = ptr_to_fun;
}

// ISR of INT1
void __vector_2() {
	if (ptr_to_INT1 != NULL)
		ptr_to_INT1();
}
