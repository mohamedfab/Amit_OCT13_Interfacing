/*****************************************
 * Led.c
 * Created on: Jun 11, 2022
 * Author: Eng_Fawzi
 *****************************************/

#include "Led_Interface.h"

void Led_Init(void)
{
	Dio_Configure_Channel(LED0_PORT, LED0_PIN, DIO_OUTPUT);
	Dio_Configure_Channel(LED1_PORT, LED1_PIN, DIO_OUTPUT);
	Dio_Configure_Channel(LED2_PORT, LED2_PIN, DIO_OUTPUT);

	Dio_Write_Channel(LED0_PORT, LED0_PIN, DIO_LOW);
	Dio_Write_Channel(LED1_PORT, LED1_PIN, DIO_LOW);
	Dio_Write_Channel(LED2_PORT, LED2_PIN, DIO_LOW);
}

void Led_ON(led_id_t led)
{
	switch (led)
	{
	case LED0:

#if(LED0_CONECTION == SOURCE)
		Dio_Write_Channel(LED0_PORT, LED0_PIN, DIO_HIGH);
#else
		Dio_Write_Channel(LED0_PORT, LED0_PIN, DIO_LOW);
#endif
		break;

	case LED1:
		Dio_Write_Channel(LED1_PORT, LED1_PIN, DIO_HIGH);
		break;
	case LED2:
		Dio_Write_Channel(LED2_PORT, LED2_PIN, DIO_HIGH);
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
	switch (led)
	{
	case LED0:
		Dio_Flip_Channel(DIO_PORTC, DIO_PIN2);
		break;

	case LED1:
		Dio_Flip_Channel(DIO_PORTC, DIO_PIN7);
		break;

	case LED2:
		Dio_Flip_Channel(DIO_PORTD, DIO_PIN3);
		break;
	}
}
