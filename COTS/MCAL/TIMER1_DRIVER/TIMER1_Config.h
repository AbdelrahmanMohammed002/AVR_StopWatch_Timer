/*
 * TIMER1_Config.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_TIMER1_DRIVER_TIMER1_CONFIG_H_
#define MCAL_TIMER1_DRIVER_TIMER1_CONFIG_H_

/* 				TIMER 1 CONFIGURATION				*/

/*
 * 				UNCOMMENT TO ENABLE  TIMER 1 CHANNEL A
 * 				COMMENT   TO DISABLE TIMER 1 CHANNEL A
 * 				UNCOMMENT TO ENABLE  TIMER 1 CHANNEL B
 * 				COMMENT   TO DISABLE TIMER 1 CHANNEL B
 *
 **/
#define TIMER1_CHANNEL_A_ENABLE
//#define TIMER1_CHANNEL_B_ENABLE

/*
 * 				WAVEFORM GENERATION MODE
 *
 * OPTIONS:-
 * 			1-TIMER1_u8_NORMAL
 * 			2-TIMER1_u8_PWM_PHASE_CORRECT_8BIT
 * 			3-TIMER1_u8_PWM_PHASE_CORRECT_9BIT
 * 			4-TIMER1_u8_PWM_PHASE_CORRECT_10BIT
 * 			5-TIMER1_u8_CTC_OCR1A
 * 			6-TIMER1_u8_FAST_PWM_8BIT
 * 			7-TIMER1_u8_FAST_PWM_9BIT
 * 			8-TIMER1_u8_FAST_PWM_10BIT
 * 			9-TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_ICR1
 * 			10-TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_OCR1A
 * 			11-TIMER1_u8_PWM_PHASE_CORRECT_ICR1
 * 			12-TIMER1_u8_PWM_PHASE_CORRECT_OCR1A
 * 			13-TIMER1_u8_CTC_ICR1
 * 			14-TIMER1_u8_FAST_PWM_ICR1
 * 			15-TIMER1_u8_FAST_PWM_OCR1A
 */

#define TIMER1_u8_CHANNEL_A_WAVEFORM_MODE	TIMER1_u8_CTC_OCR1A
#define TIMER1_u8_CHANNEL_B_WAVEFORM_MODE	TIMER1_u8_PWM_PHASE_CORRECT_8BIT


/*
 * 				OUTPUT MODE  OC0 (PORTB 3)
 *
 * OPTIONS (NON-PWM MODE):-
 * 			1-TIMER1_u8_OC1_DISCONNECTED	(Normal port operation, OC1A/OC1B disconnected)
 * 			2-TIMER1_u8_OC1_TOGGLE			(Toggle OC1A/OC1B on compare match)
 * 			3-TIMER1_u8_OC1_CLEAR			(Clear OC1A/OC1B on compare match (Set output to low level))
 * 			4-TIMER1_u8_OC1_SET				(Set OC1A/OC1B on compare match (Set output to high level))
 *
 * OPTIONS (FAST-PWM MODE):-
 * 			1-TIMER1_u8_OC0_DISCONNECTED	(Normal port operation, OC1A/OC1B disconnected)
 * 	 		2-TIMER1_u8_OC1_TOGGLE			(WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation). For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.)
 * 			2-TIMER1_u8_OC1_CLEAR			(Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP)
 * 			3-TIMER1_u8_OC1_SET				(Set OC1A/OC1B on compare match, clear OC1A/OC1B at TOP)
 *
 * OPTIONS (Phase Correct and Phase and Frequency Correct PWM):-
 * 			1-TIMER1_u8_OC1_DISCONNECTED	(Normal port operation, OC1A/OC1B disconnected)
 * 	 		2-TIMER1_u8_OC1_TOGGLE			(WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation). For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.)
 * 			2-TIMER1_u8_OC1_CLEAR			(Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when downcounting.)
 * 			3-TIMER1_u8_OC1_SET				(Set OC1A/OC1B on compare match when upcounting. Clear OC1A/OC1B on compare match when downcounting.)
 *
 */


#define TIMER1_u8_CHANNEL_A_OUTPUT_MODE	TIMER1_u8_OC1_DISCONNECTED
#define TIMER1_u8_CHANNEL_B_OUTPUT_MODE	TIMER1_u8_OC1_DISCONNECTED

/*
 * 				PRESCALLER
 *
 * OPTIONS:-
 * 			1-TIMER1_u8_STOP				(No clock source (Timer/Counter stopped).)
 * 			2-TIMER1_u8_DIV_BY_1
 * 			3-TIMER1_u8_DIV_BY_8
 * 			4-TIMER1_u8_DIV_BY_64
 * 			5-TIMER1_u8_DIV_BY_256
 * 			6-TIMER1_u8_DIV_BY_1024
 *
 */

#define TIMER1_u8_PRESCALLER	TIMER1_u8_DIV_BY_8


/*
 * 				INPUT CAPTURE EDGE SELECT
 *
 * OPTIONS:-
 * 			1-TIMER1_u8_FALLING_INPUT_CAPTURE
 * 			2-TIMER1_u8_RISING_INPUT_CAPTURE
 *
 */


#define TIMER1_u8_INPUT_CAPTURE	TIMER1_u8_FALLING_INPUT_CAPTURE


#endif /* MCAL_TIMER1_DRIVER_TIMER1_CONFIG_H_ */
