/*
 * EXTI2_Private.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_EXTI2_EXTI2_PRIVATE_H_
#define MCAL_EXTI2_EXTI2_PRIVATE_H_

//external interrupts -> MCUCR ->

#define MCUCSR	  *((volatile u8 *)0x54)
#define GICR	  *((volatile u8 *)0x5B)
#define GIFR  	  *((volatile u8 *)0x5A)

//Interrupt sense control Bits
//ISC INT2 bit number
#define ISC2  6

//ISC schema
//INT2
#define FALLING_EDGE 	 0b00
#define RISING_EDGE     0b01

//INTERRUPT STATUS
#define ENABLED 1
#define DISABLED 0

//GICR & GIFR Bits (PIE bits & flag bits) numbers
#define INT2 5

void __vector_3()__attribute__((signal));

#endif /* MCAL_EXTI2_EXTI2_PRIVATE_H_ */
