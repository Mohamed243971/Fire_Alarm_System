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



	u8 L_u8Temp;

/*	SLAVE	*/
int main()
{


	/*	LCD CONNECTIONS	*/
	MDIO_voidSetPortDirection('D',0xff);
	MDIO_voidSetPortDirection('A',0x07);

	/*	SPI SLAVE PINS CONFIG	*/
	MDIO_voidSetPinDirection('B',4,0); //SS
	MDIO_voidSetPinDirection('B',5,0); //MOSI
	MDIO_voidSetPinDirection('B',6,1); //MISO
	MDIO_voidSetPinDirection('B',7,0); //SCK

	MDIO_voidSetPinDirection('B',3,1); //PWM

	MGIE_voidEnable();
	HLCD_voidInit();
	MSPI_voidSlaveInit();
	MTIMER0_voidTimerInit(1);
	MTIMER0_voidStart(256);

	while(1)
	{



				/*	CLR LCD	*/
				HLCD_voidGoto(0,0);

				/*	Receive Data	*/
				L_u8Temp = MSPI_u8Transvieve('0');


				/*	Leds Indication	*/
				if(L_u8Temp<=40)
				{
					MDIO_voidSetPortValue('D',0x02);
					HLCD_voidSendString("Fine ");
				}
				else if(L_u8Temp>40 && L_u8Temp<=50)
				{

					MDIO_voidSetPortValue('D',0x04);
					HLCD_voidSendString("Critical!");
				}
				else if(L_u8Temp>50)
				{
					MDIO_voidSetPortValue('D',0x08);
					MTIMER0_voidSetPreload(1,200);
					HLCD_voidSendString("DANGER!!");

				}

				HLCD_voidGoto(1,0);
				/*	Display on LCD	*/
				HLCD_voidSendString("TEMP = ");
				HLCD_voidDisplayNumber(L_u8Temp);




	}


	return 0;
}


