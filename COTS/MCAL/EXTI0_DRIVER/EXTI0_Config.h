/*
 * EXTI0_Config.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_EXTI0_DRIVER_EXTI0_CONFIG_H_
#define MCAL_EXTI0_DRIVER_EXTI0_CONFIG_H_

/*
 * Configure Interrupt status
 *
 * Range:
 * ENABLED
 * DISABLED
 *
 * */
#define INT0_STATUS ENABLED

/*
 * Configure the ISC for INT0
 *
 * Range:
 * 	LOW_LEVEL
 * 	ANY LOGICAL CHANGE
 * 	FALLING EDGE
 * 	RISING EDGE
 *
 * */
#define ISC_INT0 FALLING_EDGE



#endif /* MCAL_EXTI0_DRIVER_EXTI0_CONFIG_H_ */
