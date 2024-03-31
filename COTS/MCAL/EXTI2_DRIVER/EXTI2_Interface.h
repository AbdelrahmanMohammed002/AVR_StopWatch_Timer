/*
 * EXTI2_Interface.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_EXTI2_EXTI2_INTERFACE_H_
#define MCAL_EXTI2_EXTI2_INTERFACE_H_

/**
 * @brief Initialize external interrupt 2.
 */
void MEXTI2_vInit(void);

/**
 * @brief Set the callback function for external interrupt 2.
 *
 * @param ptr_to_fun Pointer to the callback function.
 */
void MEXTI2_vSetCallBack(void (*ptr_to_fun)(void));

#endif /* MCAL_EXTI2_EXTI2_INTERFACE_H_ */
