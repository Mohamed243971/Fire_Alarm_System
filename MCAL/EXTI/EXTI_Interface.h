/*
 * EXTI_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: moham
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


void HEXTI_voidSenseControl(u8 A_u8EXTINUM, u8 A_u8EXTIState);

void HEXTI_voidEnable(u8 A_u8EXTINUM);

void HEXTI_voidDisable(u8 A_u8EXTINUM);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
