
#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include"EXTI_Interface.h"

void HEXTI_voidSenseControl(u8 A_u8EXTINUM, u8 A_u8EXTIState)
{
	switch(A_u8EXTINUM)
	{
	case 0:
		switch(A_u8EXTIState)
		{
		case 0:  				/*	low level	*/
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		break;

		case 1:					/*	on change	*/
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,0);
		break;

		case 2:					/*	falling edge	*/
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		break;

		case 3:					/*	rising edge	*/
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		break;

		}
		break;

	case 1:
		switch(A_u8EXTIState)
		{
		case 0:					/*	low level	*/
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		break;

		case 1:					/*	on change	*/
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		break;

		case 2:					/*	falling edge	*/
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		break;

		case 3:					/*	rising edge	*/
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;

			}
		break;

	case 2:
		switch(A_u8EXTIState)
		{
		case 2:					/*	falling edge	*/
			CLR_BIT(MCUCSR,6);
		break;

		case 3:					/*	rising edge	*/
			SET_BIT(MCUCSR,6);
		break;
		}

	}
}


void HEXTI_voidEnable(u8 A_u8EXTINUM)
{
	switch(A_u8EXTINUM)
	{
	case 0:
		SET_BIT(GICR,6);
		break;

	case 1:
		SET_BIT(GICR,7);
		break;

	case 2:
		SET_BIT(GICR,5);
		break;
	}
}



void HEXTI_voidDisable(u8 A_u8EXTINUM)
{
	switch(A_u8EXTINUM)
	{
	case 0:
		CLR_BIT(GICR,6);
		break;

	case 1:
		CLR_BIT(GICR,7);
		break;

	case 2:
		CLR_BIT(GICR,5);
		break;
	}
}

