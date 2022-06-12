/*
 * Led.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Eng_Fawzi
 */

#include "Led_Interface.h"

void Led_Init(void)
{
	Dio_Configure_Channel(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTC, DIO_PIN7, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTD, DIO_PIN3, DIO_OUTPUT);

	Dio_Write_Channel(DIO_PORTC, DIO_PIN2, DIO_LOW);
	Dio_Write_Channel(DIO_PORTC, DIO_PIN7, DIO_LOW);
	Dio_Write_Channel(DIO_PORTD, DIO_PIN3, DIO_LOW);
}
void Led_ON(led_id_t led)
{
	switch (led)
	{
	case LED0:
		Dio_Write_Channel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		break;

	case LED1:
		Dio_Write_Channel(DIO_PORTC, DIO_PIN7, DIO_HIGH);
		break;
	case LED2:
		Dio_Write_Channel(DIO_PORTD, DIO_PIN3, DIO_HIGH);
		break;
	}
}

void Led_OFF(led_id_t led)
{
	switch (led)
	{
	case LED0:
		Dio_Write_Channel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		break;

	case LED1:
		Dio_Write_Channel(DIO_PORTC, DIO_PIN7, DIO_LOW);
		break;

	case LED2:
		Dio_Write_Channel(DIO_PORTD, DIO_PIN3, DIO_LOW);
		break;
	}
}

void Led_Toggle(led_id_t led)
{

}
