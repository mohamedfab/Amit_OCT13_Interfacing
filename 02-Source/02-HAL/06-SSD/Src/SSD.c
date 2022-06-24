/*
 * SSD.c
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng_Fawzi
 */
#include "SSD_Interface.h"
void SSD_Init(void)
{
	/*	Configure SSD Enable Lines as Output	*/
	Dio_Configure_Channel(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);
	/*	Configure SSD DP Line as Output	*/
	Dio_Configure_Channel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	/*	Configure SSD Data Lines as Output		*/
	Dio_Configure_Channel(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTA, DIO_PIN5, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTA, DIO_PIN6, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTA, DIO_PIN7, DIO_OUTPUT);
	/*	Turn OFF SSD	*/
	Dio_Write_Channel(DIO_PORTB, DIO_PIN1,DIO_LOW);
	Dio_Write_Channel(DIO_PORTB, DIO_PIN2,DIO_LOW);
}

void SSD_Display(u8 num)
{
	u8 loc_SSD_First_Digit = (num%10)<<4;
	u8 loc_SSD_Second_Digit = (num/10)<<4;

	if (num <= 99)
	{
		/*	Enable SSD1	*/
		Dio_Write_Channel(DIO_PORTB, DIO_PIN1,DIO_HIGH);
		/*	Disable SSD2	*/
		Dio_Write_Channel(DIO_PORTB, DIO_PIN2,DIO_LOW);
		/*	Write First Digit	*/
		Dio_Write_Channel_Group(DIO_PORTA, 0xF0, loc_SSD_First_Digit);
		_delay_ms(1);

		/*	Disable SSD1	*/
		Dio_Write_Channel(DIO_PORTB, DIO_PIN1,DIO_LOW);
		/*	Enable SSD2	*/
		Dio_Write_Channel(DIO_PORTB, DIO_PIN2,DIO_HIGH);
		/*	Write Second Digit	*/
		Dio_Write_Channel_Group(DIO_PORTA, 0xF0, loc_SSD_Second_Digit);
		_delay_ms(1);
	}
	else
	{
		/*	Do Nothing	*/
	}
}
void SSD_Display_With_Delay(u8 num,u32 delay)
{
	u32 count = 0;
	for (count =0; count<delay; count+=3)
	{
		SSD_Display(num);
		_delay_ms(1);
	}
}

