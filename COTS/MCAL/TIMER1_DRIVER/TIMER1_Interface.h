/*
 * TIMER1_Interface.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Abdelrahman (Ta'laab) Mohammed
 *		Github: https://github.com/AbdelrahmanMohammed002
 */

#ifndef MCAL_TIMER1_DRIVER_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_DRIVER_TIMER1_INTERFACE_H_

/**
 * @brief Initialize Timer1 module.
 */
void MTIMER1_vInit(void);

/**
 * @brief Deinitialize Timer1 module.
 */
void MTIMER1_vDisInit(void);

/**
 * @brief Set the value of Timer1 overflow register.
 * @param A_u16Value: Value to be set in the overflow register.
 */
void MTIMER1_vSetOVFRegister(u16 A_u16Value);

/**
 * @brief Set the value of Timer1 Channel A CTC register.
 * @param A_u16Value: Value to be set in the Channel A CTC register.
 */
void MTIMER1_vChannelASetCTCRegister(u16 A_u16Value);

/**
 * @brief Set the value of Timer1 Channel B CTC register.
 * @param A_u16Value: Value to be set in the Channel B CTC register.
 */
void MTIMER1_vChannelBSetCTCRegister(u16 A_u16Value);

/**
 * @brief Set the value of Timer1 Input Capture Register (ICR1).
 * @param A_u16Val: Value to be set in the Input Capture Register.
 */
void MTIMER1_vSetICR1Value(u16 A_u16Val);

/**
 * @brief Get the value of Timer1 Input Capture Register (ICR1).
 * @return The value of the Input Capture Register.
 */
u16 MTIMER1_u16InputCaptureValue(void);

/**
 * @brief Enable Timer1 overflow interrupt.
 */
void MTIMER1_vEnableOVFINT(void);

/**
 * @brief Disable Timer1 overflow interrupt.
 */
void MTIMER1_vDisableOVFINT(void);

/**
 * @brief Clear Timer1 overflow flag.
 */
void MTIMER1_vClearOVFFlag(void);

/**
 * @brief Enable Timer1 Channel A CTC interrupt.
 */
void MTIMER1_vChannelAEnableCTCINT(void);

/**
 * @brief Disable Timer1 Channel A CTC interrupt.
 */
void MTIMER1_vChannelADisableCTCINT(void);

/**
 * @brief Clear Timer1 Channel A CTC flag.
 */
void MTIMER1_vChannelAClearCTCFlag(void);

/**
 * @brief Enable Timer1 Channel B CTC interrupt.
 */
void MTIMER1_vChannelBEnableCTCINT(void);

/**
 * @brief Disable Timer1 Channel B CTC interrupt.
 */
void MTIMER1_vChannelBDisableCTCINT(void);

/**
 * @brief Clear Timer1 Channel B CTC flag.
 */
void MTIMER1_vChannelBClearCTCFlag(void);

/**
 * @brief Enable Timer1 input capture interrupt.
 */
void MTIMER1_vEnableInputCaptureINT(void);

/**
 * @brief Disable Timer1 input capture interrupt.
 */
void MTIMER1_vDisableInputCaptureINT(void);

/**
 * @brief Clear Timer1 input capture flag.
 */
void MTIMER1_vClearInputCaptureFlag(void);

/**
 * @brief Set callback function for Timer1 overflow interrupt.
 * @param CallBack: Pointer to the callback function.
 */
void MTIMER1_vSetOVFCallBack(void (*CallBack)(void));

/**
 * @brief Set callback function for Timer1 Channel A CTC interrupt.
 * @param CallBack: Pointer to the callback function.
 */
void MTIMER1_vChannelASetCTCCallBack(void (*CallBack)(void));

/**
 * @brief Set callback function for Timer1 Channel B CTC interrupt.
 * @param CallBack: Pointer to the callback function.
 */
void MTIMER1_vChannelBSetCTCCallBack(void (*CallBack)(void));

/**
 * @brief Set callback function for Timer1 input capture interrupt.
 * @param CallBack: Pointer to the callback function.
 */
void MTIMER1_vSetInputCaptureCallBack(void (*CallBack)(void));

/**
 * @brief Force output compare action for Timer1 Channel A.
 */
void MTIMER1_vChannelAForceOutputCompare(void);

/**
 * @brief Force output compare action for Timer1 Channel B.
 */
void MTIMER1_vChannelBForceOutputCompare(void);

#endif /* MCAL_TIMER1_DRIVER_TIMER1_INTERFACE_H_ */
