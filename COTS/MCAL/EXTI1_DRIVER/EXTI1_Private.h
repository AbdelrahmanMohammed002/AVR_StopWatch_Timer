/*
 * EXTI1_Private.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_EXTI1_EXTI1_PRIVATE_H_
#define MCAL_EXTI1_EXTI1_PRIVATE_H_

#define MCUCR	  *((volatile u8 *)0x55)
#define GICR	  *((volatile u8 *)0x5B)
#define GIFR  	  *((volatile u8 *)0x5A)

//ISC INT1 bits numbers
#define ISC11 3
#define ISC10 2

//ISC schema
//int1
#define LOW_LEVEL			 0b00
#define ANY_LOGICAL_CHANGE	 0b01
#define FALLING_EDGE		 0b10
#define RISING_EDGE			 0b11

//INTERRUPT STATUS
#define ENABLED 1
#define DISABLED 0

//GICR & GIFR Bits (PIE bits & flag bits) numbers
#define INT1 7

void __vector_2()__attribute__((signal));

#endif /* MCAL_EXTI1_EXTI1_PRIVATE_H_ */
