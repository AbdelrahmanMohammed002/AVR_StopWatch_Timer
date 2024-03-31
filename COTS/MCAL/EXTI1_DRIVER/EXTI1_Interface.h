/*
 * EXTI1_Interface.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_EXTI1_EXTI1_INTERFACE_H_
#define MCAL_EXTI1_EXTI1_INTERFACE_H_

/**
 * @brief Initialize external interrupt 1.
 */
void MEXTI1_vInit(void);

/**
 * @brief Set the callback function for external interrupt 1.
 *
 * @param ptr_to_fun Pointer to the callback function.
 */
void MEXTI1_vSetCallBack(void (*ptr_to_fun)(void));

#endif /* MCAL_EXTI1_EXTI1_INTERFACE_H_ */
