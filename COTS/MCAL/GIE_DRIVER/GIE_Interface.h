/*
 * GIE_Interface.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Abdelrahman (Ta'laab) Mohammed
 */

#ifndef COTS_MCAL_GIE_DRIVER_GIE_INTERFACE_H_
#define COTS_MCAL_GIE_DRIVER_GIE_INTERFACE_H_

/**
 * @brief Disable global interrupts.
 */
void MGIE_vDisableInterrupts(void);

/**
 * @brief Enable global interrupts.
 */
void MGIE_vEnableInterrupts(void);

#endif /* COTS_MCAL_GIE_DRIVER_GIE_INTERFACE_H_ */
