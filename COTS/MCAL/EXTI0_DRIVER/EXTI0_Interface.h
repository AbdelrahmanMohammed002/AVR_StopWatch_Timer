/*
 * EXTI0_Interface.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_EXTI0_EXTI0_INTERFACE_H_
#define MCAL_EXTI0_EXTI0_INTERFACE_H_

/**
 * @brief Initialize external interrupt 0.
 */
void MEXTI0_vInit(void);

/**
 * @brief Set the callback function for external interrupt 0.
 *
 * @param ptr_to_fun Pointer to the callback function.
 */
void MEXTI0_vSetCallBack(void (*ptr_to_fun)(void));

#endif /* MCAL_EXTI0_EXTI0_INTERFACE_H_ */
