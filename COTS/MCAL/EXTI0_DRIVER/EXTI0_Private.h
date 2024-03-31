/*
 * EXTI0_Private.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_EXTI0_EXTI0_PRIVATE_H_
#define MCAL_EXTI0_EXTI0_PRIVATE_H_

#define GICR	  *((volatile u8 *)0x5B)
#define GIFR  	  *((volatile u8 *)0x5A)
#define MCUCR	  *((volatile u8 *)0x55)

//Interrupt sense control Bits
//ISC INT0 bit numbers
#define ISC01 1
#define ISC00 0

//ISC schema
//int0
#define LOW_LEVEL			 0b00
#define ANY_LOGICAL_CHANGE	 0b01
#define FALLING_EDGE		 0b10
#define RISING_EDGE			 0b11

//INTERRUPT STATUS
#define ENABLED 1
#define DISABLED 0

//GICR & GIFR Bits (PIE bits & flag bits) numbers
#define INT0 6

//vector table INT0
void __vector_1()__attribute__((signal));

#endif /* MCAL_EXTI0_EXTI0_PRIVATE_H_ */
