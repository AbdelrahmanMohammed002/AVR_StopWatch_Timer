/*
 * 7-Segment_Interface.h
 *
 *  Created on: Feb 15, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 */

#ifndef HAL_7_SEGMENT_DRIVER_7_SEGMENT_INTERFACE_H_
#define HAL_7_SEGMENT_DRIVER_7_SEGMENT_INTERFACE_H_

/**
 * @brief Initialize the 7-segment display.
 */
void HSEVSEG_vSevenSegmentInit();

/**
 * @brief Set the value to be displayed on the 7-segment display.
 *
 * @param A_u8SevenSegmentValue The value to be displayed (0-9).
 */
void HSEVSEG_vSetSevenSegmentValue(u8 A_u8SevenSegmentValue);

/**
 * @brief Enable the 7-segment display.
 */
void HSEVSEG_vSevenSegmentEnable();

/**
 * @brief Disable the 7-segment display.
 */
void HSEVSEG_vSevenSegmentDisable();

#endif /* HAL_7_SEGMENT_DRIVER_7_SEGMENT_INTERFACE_H_ */
