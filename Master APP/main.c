#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include <avr/interrupt.h>
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Intrface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/TIMERS/TIMER0_Interface.h"
#include "../MCAL/UART/MUART_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"


	u8 L_u8ADC, L_u8Temp;

/*	MASTER	*/
int main()
{


	// ADC CHANNLE
	MDIO_voidSetPinDirection('A',0,0);

	/*	SPI MASTER PINS CONFIG	*/
	MDIO_voidSetPinDirection('B',4,0); //SS
	MDIO_voidSetPinValue('B',4,1);     //PULLUP
	MDIO_voidSetPinDirection('B',5,1); //MOSI
	MDIO_voidSetPinDirection('B',6,0); //MISO
	MDIO_voidSetPinDirection('B',7,1); //SCK

	MADC_voidInit(0);

	MSPI_voidMasterInit();


	while(1)
	{
		/*	Read Temperature	*/
		L_u8ADC=MADC_u8GetChannelReading(0);
		L_u8Temp=(L_u8ADC*500)/256;

		/*	Send Data to Slave	*/
		MSPI_u8Transvieve(L_u8Temp);

	}

	return 0;
}


