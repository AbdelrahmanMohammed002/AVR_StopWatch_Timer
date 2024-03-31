/*
 * main.c
 *
 *  Created on: Mar 30, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO_DRIVER/DIO_Interface.h"
#include "../HAL/7_SEGMENT_DRIVER/7-Segment_Interface.h"
#include "../MCAL/GIE_DRIVER/GIE_Interface.h"
#include "../MCAL/EXTI0_DRIVER/EXTI0_Interface.h"
#include "../MCAL/EXTI1_DRIVER/EXTI1_Interface.h"
#include "../MCAL/EXTI2_DRIVER/EXTI2_Interface.h"
#include "../MCAL/TIMER1_DRIVER/TIMER1_Interface.h"

#include <util/delay.h>

#define F_CPU 8000000UL
#define INT0 	2
#define INT1 	3
#define INT2	2

u8 counter = 0, secs = 0, mins = 0, hours = 0;

/**
 * @brief Interrupt service routine for external interrupt INT0.
 *        Resets the timer by setting counter, seconds, minutes, and hours to 0.
 */
void INT0_ISR_RESET_TIMER() {
	counter = 0, secs = 0, mins = 0, hours = 0;
}

/**
 * @brief Interrupt service routine for external interrupt INT1.
 *        Pauses the timer by disabling Timer1 module.
 */
void INT1_ISR_PAUSE_TIMER() {
	MTIMER1_vDisInit();
}

/**
 * @brief Interrupt service routine for external interrupt INT2.
 *        Resumes the timer by re-initializing and enabling Timer1 module.
 */
void INT2_ISR_RESUME_TIMER() {
	MTIMER1_vInit();
	MTIMER1_vChannelASetCTCRegister(62500);
}

/**
 * @brief Increases the timer by incrementing seconds, minutes, and hours.
 */
void increaseNum(void) {
	secs++;

	if (secs == 60) {
		secs = 0;
		mins++;

		if (mins == 60) {
			mins = 0;
			hours++;

			if (hours == 24) {
				hours = 0;
			}
		}
	}
}

/**
 * @brief Displays the current time on the seven-segment display.
 */
void display_seven_segment() {
	u8 sec_units, sec_tens, min_units, min_tens, hour_units, hour_tens;

	// Extract digits
	sec_units = secs % 10;
	sec_tens = secs / 10;

	min_units = mins % 10;
	min_tens = mins / 10;

	hour_units = hours % 10;
	hour_tens = hours / 10;

	// Display seconds
	MDIO_vSetPortValue(PORT_A, LOW);
	HSEVSEG_vSetSevenSegmentValue(sec_units);
	MDIO_vSetPinValue(PORT_A, 0, HIGH);
	_delay_ms(2);
	MDIO_vSetPinValue(PORT_A, 0, LOW);

	HSEVSEG_vSetSevenSegmentValue(sec_tens);
	MDIO_vSetPinValue(PORT_A, 1, HIGH);
	_delay_ms(2);
	MDIO_vSetPinValue(PORT_A, 1, LOW);

	// Display minutes
	HSEVSEG_vSetSevenSegmentValue(min_units);
	MDIO_vSetPinValue(PORT_A, 2, HIGH);
	_delay_ms(2);
	MDIO_vSetPinValue(PORT_A, 2, LOW);

	HSEVSEG_vSetSevenSegmentValue(min_tens);
	MDIO_vSetPinValue(PORT_A, 3, HIGH);
	_delay_ms(2);
	MDIO_vSetPinValue(PORT_A, 3, LOW);

	// Display hours
	HSEVSEG_vSetSevenSegmentValue(hour_units);
	MDIO_vSetPinValue(PORT_A, 4, HIGH);
	_delay_ms(2);
	MDIO_vSetPinValue(PORT_A, 4, LOW);

	HSEVSEG_vSetSevenSegmentValue(hour_tens);
	MDIO_vSetPinValue(PORT_A, 5, HIGH);
	_delay_ms(2);
	MDIO_vSetPinValue(PORT_A, 5, LOW);

	MDIO_vSetPortValue(PORT_A, LOW);
}

/**
 * @brief Interrupt service routine for Timer1 channel A CTC interrupt.
 *        Increments the counter and calls the function to increase the timer.
 */
void TIMER1_CTC_INT_ISR() {
	if (counter == 15) {
		increaseNum();
		counter = 0;
	} else {
		counter++;
	}
}

/**
 * @brief The main function initializes peripherals, sets up interrupts, and enters an infinite loop to display the time.
 */
int main(int argc, char **argv) {

	// Set pin directions
	MDIO_vSetPinDirection(PORT_A, 0, OUTPUT);
	MDIO_vSetPinDirection(PORT_A, 1, OUTPUT);
	MDIO_vSetPinDirection(PORT_A, 2, OUTPUT);
	MDIO_vSetPinDirection(PORT_A, 3, OUTPUT);
	MDIO_vSetPinDirection(PORT_A, 4, OUTPUT);
	MDIO_vSetPinDirection(PORT_A, 5, OUTPUT);

	MDIO_vSetPinDirection(PORT_D, INT0, INPUT);
	MDIO_vSetPinValue(PORT_D, INT0, HIGH);

	MDIO_vSetPinDirection(PORT_B, INT2, INPUT);
	MDIO_vSetPinValue(PORT_B, INT2, HIGH);

	MDIO_vSetPinDirection(PORT_D, INT1, INPUT);
	MDIO_vSetPinValue(PORT_D, INT1, LOW);

	// Initialize seven-segment display
	HSEVSEG_vSevenSegmentEnable();
	HSEVSEG_vSevenSegmentInit();
	HSEVSEG_vSetSevenSegmentValue(4);

	// Initialize Timer1 and set callback for channel A CTC interrupt
	MTIMER1_vInit();
	MTIMER1_vChannelASetCTCCallBack(&TIMER1_CTC_INT_ISR);
	MTIMER1_vChannelASetCTCRegister(62500);
	MTIMER1_vChannelAEnableCTCINT();

	// Initialize external interrupts
	MEXTI0_vSetCallBack(&INT0_ISR_RESET_TIMER);
	MEXTI0_vInit();

	MEXTI1_vSetCallBack(&INT1_ISR_PAUSE_TIMER);
	MEXTI1_vInit();

	MEXTI2_vSetCallBack(&INT2_ISR_RESUME_TIMER);
	MEXTI2_vInit();

	// Enable global interrupts
	MGIE_vEnableInterrupts();

	// Main loop to display the time
	while (1) {
		display_seven_segment();
	}
}

