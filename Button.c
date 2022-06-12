/*
 * Button.c
 *
 *  Created on: Jun 12, 2022
 *      Author: Eng_Fawzi
 */

#include "Button_Interface.h"

void Button_Init(void)
{
	Dio_Configure_Channel(DIO_PORTB, DIO_PIN0, DIO_INPUT);
	Dio_Configure_Channel(DIO_PORTB, DIO_PIN4, DIO_INPUT);
	Dio_Configure_Channel(DIO_PORTD, DIO_PIN2, DIO_INPUT);
}

boolean Button_Is_Pressed(button_id_t button)
{
	boolean loc_button_pressed = FALSE;

	switch(button)
	{
	case BUTTON0:
		if (Dio_Read_Channel(DIO_PORTB, DIO_PIN0) == DIO_HIGH)
		{
			loc_button_pressed = TRUE;
		}
		else
		{
			loc_button_pressed = FALSE;
		}
		break;

	case BUTTON1:
		if (Dio_Read_Channel(DIO_PORTB, DIO_PIN4) == DIO_HIGH)
		{
			loc_button_pressed = TRUE;
		}
		else
		{
			loc_button_pressed = FALSE;
		}
		break;

	case BUTTON2:
		if (Dio_Read_Channel(DIO_PORTD, DIO_PIN2) == DIO_HIGH)
		{
			loc_button_pressed = TRUE;
		}
		else
		{
			loc_button_pressed = FALSE;
		}
		break;
	}
	return loc_button_pressed;
}
