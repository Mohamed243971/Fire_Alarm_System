/*
 * TIMER0_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: moham
 */

#ifndef MCAL_TIMERS_TIMER0_INTERFACE_H_
#define MCAL_TIMERS_TIMER0_INTERFACE_H_

void MTIMER0_voidSetPreload(u8 A_u8TimerMode, u8 A_u8Preload);

void MTIMER0_voidTimerInit(u8 A_u8TimerMode);

void MTIMER0_voidStart(u16 A_u16Prescalar);

void MTIMER0_voidStop();

void MTIMER1_voidInit();

void MTIMER1_voidSetValue(u16 A_u16Value);

u16 MTIMER1_voidReadTimer1();


#endif /* MCAL_TIMERS_TIMER0_INTERFACE_H_ */
