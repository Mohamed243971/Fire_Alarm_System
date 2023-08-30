

#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include"ADC_Interface.h"


/*
 * AREF      0
 * AVCC      1
 * INTERNAL  2
 *
 *
 */
void MADC_voidInit(u8 A_u8Vref)
{
	switch(A_u8Vref)
	{
	//AREF
	case 0:
		CLR_BIT(ADMUX,6);
		CLR_BIT(ADMUX,7);
		break;

	//AVCC
	case 1:
		SET_BIT(ADMUX,6);
		CLR_BIT(ADMUX,7);
		break;

	//INTERNAL
	case 2:
		CLR_BIT(ADMUX,6);
		SET_BIT(ADMUX,7);
		break;
	}


	/* ADC Left Adjust */
	SET_BIT(ADMUX,5);


	/* Prescalar */

	ADCSRA|=0b00000111;

	/* Enable */
	SET_BIT(ADCSRA,7);

}



u8 MADC_u8GetChannelReading(u8 A_8uChannel)
{
	/* 1- channel selection */
	ADMUX&=0b11100000;
	ADMUX|=A_8uChannel;

	/* 2- start conversion */
	SET_BIT(ADCSRA,6);

	/* Wait until flag is on */
	while(!GET_BIT(ADCSRA,4));

	/* Clear flag */
	SET_BIT(ADCSRA,4);

	return ADCH;
}

