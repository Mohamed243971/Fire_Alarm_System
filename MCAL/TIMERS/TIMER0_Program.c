
#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "TIMER0_Interface.h"


/*
 * Normal mode ----->  A_u8TimerMode=0
 * CTC mode -------->  A_u8TimerMode=2
 **/


void MTIMER0_voidTimerInit(u8 A_u8TimerMode)
{
	if(A_u8TimerMode==0)
	{
		CLR_BIT( TCCR0,3);
		CLR_BIT( TCCR0,6);

		SET_BIT(TIMSK,0);

	}

	else if(A_u8TimerMode==2)
	{
		SET_BIT( TCCR0,3);
		CLR_BIT( TCCR0,6);

		SET_BIT(TIMSK,1);

	}

	else if (A_u8TimerMode==3)
	{
		/*	FAST PWM timer mode	*/
		SET_BIT( TCCR0,3);
		SET_BIT( TCCR0,6);

		/*	Match compare output mode	*/
		CLR_BIT( TCCR0,4);
		SET_BIT( TCCR0,5);


	}

	else if (A_u8TimerMode==1)
	{
		/*	PHASE CORRECT PWM timer mode	*/
		CLR_BIT( TCCR0,3);
		SET_BIT( TCCR0,6);

		/*	Match compare output mode	*/
		CLR_BIT( TCCR0,4);
		SET_BIT( TCCR0,5);


	}



}


void MTIMER0_voidSetPreload(u8 A_u8TimerMode,u8 A_u8Preload)
{
	/*	 Normal    */
	if(A_u8TimerMode==0)
	{
		TCNT0=A_u8Preload;
	}

	else if(A_u8TimerMode==1 || A_u8TimerMode==2)
	{
		OCR0=A_u8Preload;
	}

}



void MTIMER0_voidStart(u16 A_u16Prescalar)
{
	switch(A_u16Prescalar)
	{
	case 8: /* Prescalar 8 */
			CLR_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		break;


	case 64:  /* Prescalar 64 */
			SET_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
			CLR_BIT(TCCR0,2);
		break;


	case 256:  /* Prescalar 256  */
			CLR_BIT(TCCR0,0);
			CLR_BIT(TCCR0,1);
			SET_BIT(TCCR0,2);
	break;

	}

}


void MTIMER0_voidStop()
{
	/* STOP */
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

}


/********************************************
 ********************************************
 ********************************************
 */

void MTIMER1_voidInit()
{
	/* select prescalar 8 */

	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);

}


void MTIMER1_voidSetValue(u16 A_u16Value)
{
	TCNT1=A_u16Value;
}


u16 MTIMER1_u16ReadTimer1()
{
	return TCNT1;
}
