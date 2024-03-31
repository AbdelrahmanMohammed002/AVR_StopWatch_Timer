/*
 * TIMER1_Private.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_TIMER0_DRIVER_TIMER1_PRIVATE_H_
#define MCAL_TIMER0_DRIVER_TIMER1_PRIVATE_H_

#define TCCR1A   (* (volatile u8 *) (0x4F))
#define TCCR1B   (* (volatile u8 *) (0x4E))
#define TCNT1    (* (volatile u16 *) (0x4C))
#define OCR1A    (* (volatile u16 *) (0x4A))
#define OCR1B    (* (volatile u16 *) (0x48))
#define ICR1     (* (volatile u16 *) (0x46))
#define TIMSK	*((volatile u8 *)(0x59))
#define TIFR	*((volatile u8 *)(0x58))

#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define WGM11	1
#define WGM10	0

#define ICNC1	7
#define ICES1	6
#define WGM13	4
#define WGM12	3
#define	CS12	2
#define CS11	1
#define CS10	0

#define TICIE1	5
#define	OCIE1A	4
#define OCIE1B	3
#define TOIE1	2

#define ICF1	5
#define OCF1A	4
#define OCF1B	3
#define TOV1	2

void __vector_6(void) __attribute__((signal));
void __vector_7(void) __attribute__((signal));
void __vector_8(void) __attribute__((signal));
void __vector_9(void) __attribute__((signal));

#define TIMER1_u8_NORMAL								0
#define TIMER1_u8_PWM_PHASE_CORRECT_8BIT				1
#define TIMER1_u8_PWM_PHASE_CORRECT_9BIT				2
#define TIMER1_u8_PWM_PHASE_CORRECT_10BIT				3
#define TIMER1_u8_CTC_OCR1A								4
#define TIMER1_u8_FAST_PWM_8BIT							5
#define TIMER1_u8_FAST_PWM_9BIT							6
#define TIMER1_u8_FAST_PWM_10BIT						7
#define TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_ICR1		8
#define TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_OCR1A		9
#define TIMER1_u8_PWM_PHASE_CORRECT_ICR1				10
#define TIMER1_u8_PWM_PHASE_CORRECT_OCR1A				11
#define TIMER1_u8_CTC_ICR1								12
#define TIMER1_u8_FAST_PWM_ICR1							13
#define TIMER1_u8_FAST_PWM_OCR1A						14




#define TIMER1_u8_OC1_DISCONNECTED			0
#define TIMER1_u8_OC1_TOGGLE				1
#define TIMER1_u8_OC1_CLEAR					2
#define TIMER1_u8_OC1_SET					3


#define	TIMER1_u8_STOP						0
#define	TIMER1_u8_DIV_BY_1					1
#define TIMER1_u8_DIV_BY_8					2
#define TIMER1_u8_DIV_BY_64					3
#define TIMER1_u8_DIV_BY_256				4
#define TIMER1_u8_DIV_BY_1024				5


#define	TIMER1_u8_FALLING_INPUT_CAPTURE		0
#define	TIMER1_u8_RISING_INPUT_CAPTURE		1


#endif /* MCAL_TIMER0_DRIVER_TIMER1_PRIVATE_H_ */
