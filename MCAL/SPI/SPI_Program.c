/*
 * SPI_Program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: moham
 */

#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_Interface.h"

void MSPI_voidMasterInit()
{
	/*	Data order :LSB as default	*/

	/*	Master select	*/
	SET_BIT(SPCR,4);

	/*	CLOCK : as default	(BIT[3,2])*/

	/*	Frequency => Fosc/16	*/
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	CLR_BIT(SPSR,0);


	/*	 Bit 6: spi enable 	*/
	SET_BIT(SPCR,6);

}



void MSPI_voidSlaveInit()
{
	/*	Slave select	*/
	CLR_BIT(SPCR,4);


	/*	SPI enable 	*/
	SET_BIT(SPCR,6);

}



u8 MSPI_u8Transvieve(u8 A_u8Data)
{
	/*	Send Data	*/
	SPDR=A_u8Data;

	/*	Wait till transfer finished	*/
	while(GET_BIT(SPSR,7)==0);

	return SPDR;

}


/*
void MSPI_voidDisplayNumber(s32 A_s32Number)
{
	u32 local_u32Number=1;
	if (A_s32Number==0)
	{
		MSPI_u8Transvieve('0');
	}
	if (A_s32Number<0)
	{
		MSPI_u8Transvieve('-');
		A_s32Number *=-1;
	}
	while (A_s32Number!=0)
	{
		local_u32Number = ((local_u32Number * 10)+(A_s32Number % 10));
		A_s32Number = A_s32Number /10;
	}
	while (local_u32Number!=1)
	{
		MSPI_u8Transvieve((local_u32Number%10)+48);
		local_u32Number=local_u32Number/10;
	}
}*/
