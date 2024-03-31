/*
 * 7-Segment_Program.c
 *
 *  Created on: Feb 15, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 */

/*
 * MCAL & LIB
 * */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO_DRIVER/DIO_Interface.h"

/*
 * Components
 * */
#include "../7_SEGMENT_DRIVER/7-Segment_Config.h"
#include "../7_SEGMENT_DRIVER/7-Segment_Interface.h"

void HSEVSEG_vSevenSegmentInit()
{
	//Data Pins
	MDIO_vSetPinDirection(DATA_PORT, A, OUTPUT);
	MDIO_vSetPinDirection(DATA_PORT, B, OUTPUT);
	MDIO_vSetPinDirection(DATA_PORT, C, OUTPUT);
	MDIO_vSetPinDirection(DATA_PORT, D, OUTPUT);


}

void HSEVSEG_vSetSevenSegmentValue(u8 A_u8SevenSegmentValue)
{
	if(A_u8SevenSegmentValue<10)
	{
		MDIO_vSetPinValue(DATA_PORT, A, GET_BIT(A_u8SevenSegmentValue, 0));
		MDIO_vSetPinValue(DATA_PORT, B, GET_BIT(A_u8SevenSegmentValue, 1));
		MDIO_vSetPinValue(DATA_PORT, C, GET_BIT(A_u8SevenSegmentValue, 2));
		MDIO_vSetPinValue(DATA_PORT, D, GET_BIT(A_u8SevenSegmentValue, 3));
	}
}

void HSEVSEG_vSevenSegmentEnable()
{
	//Enable Pin
	MDIO_vSetPinDirection(CONTROL_PORT, EN, OUTPUT);
	MDIO_vSetPinValue(CONTROL_PORT, EN, HIGH);
}

void HSEVSEG_vSevenSegmentDisable()
{
	MDIO_vSetPinValue(CONTROL_PORT, EN, LOW);
}



