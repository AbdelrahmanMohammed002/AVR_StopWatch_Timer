/*
 * EXTI1_Config.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_EXTI1_EXTI1_CONFIG_H_
#define MCAL_EXTI1_EXTI1_CONFIG_H_

/*
 * Configure Interrupt status
 *
 * Range:
 * ENABLED
 * DISABLED
 *
 * */
#define INT1_STATUS ENABLED

/*
 * Configure the ISC for INT1
 *
 * Range:
 * 	LOW_LEVEL
 * 	ANY_LOGICAL_CHANGE
 * 	FALLING_EDGE
 * 	RISING_EDGE
 *
 * */
#define ISC_INT1 RISING_EDGE

#endif /* MCAL_EXTI1_EXTI1_CONFIG_H_ */
