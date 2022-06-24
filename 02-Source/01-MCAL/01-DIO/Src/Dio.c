/*
 * Dio.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Eng_Fawzi
 */
#include "Dio_Interface.h"


void Dio_Configure_Channel(dio_port_t port, dio_pin_t pin , dio_direction_t direction)
{
	switch (port)
	{
	case DIO_PORTA:
			if (direction == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRA_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRA_REG,pin);
			}
		break;

	case DIO_PORTB:
				if (direction == DIO_INPUT)
				{
					CLEAR_BIT(DIO_DDRB_REG,pin);
				}
				else
				{
					SET_BIT(DIO_DDRB_REG,pin);
				}
			break;

	case DIO_PORTC:
				if (direction == DIO_INPUT)
				{
					CLEAR_BIT(DIO_DDRC_REG,pin);
				}
				else
				{
					SET_BIT(DIO_DDRC_REG,pin);
				}
			break;

	case DIO_PORTD:
				if (direction == DIO_INPUT)
				{
					CLEAR_BIT(DIO_DDRD_REG,pin);
				}
				else
				{
					SET_BIT(DIO_DDRD_REG,pin);
				}
			break;
	}
}

void Dio_Write_Channel(dio_port_t port, dio_pin_t pin , dio_level_t level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTA_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTA_REG,pin);
		}
		break;
	case DIO_PORTB:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTB_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTB_REG,pin);
		}
		break;
	case DIO_PORTC:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTC_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTC_REG,pin);
		}
		break;
	case DIO_PORTD:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTD_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTD_REG,pin);
		}
		break;
	}
}

void Dio_Flip_Channel(dio_port_t port, dio_pin_t pin)
{
	switch(port)
	{
	case DIO_PORTA:
		TOGGLE_BIT(DIO_PORTA_REG,pin);
		break;

	case DIO_PORTB:
		TOGGLE_BIT(DIO_PORTB_REG,pin);
		break;

	case DIO_PORTC:
		TOGGLE_BIT(DIO_PORTC_REG,pin);
		break;

	case DIO_PORTD:
		TOGGLE_BIT(DIO_PORTD_REG,pin);
		break;
	}
}

dio_level_t Dio_Read_Channel(dio_port_t port, dio_pin_t pin)
{
	dio_level_t loc_result = DIO_LOW;

	switch (port)
	{
	case DIO_PORTA:
		loc_result=CHECK_BIT(DIO_PINA_REG,pin);
//		if (CHECK_BIT(DIO_PINA_REG,pin) == 1)
//		{
//			loc_result = DIO_HIGH;
//		}
//		else
//		{
//			loc_result = DIO_LOW;
//		}
		break;

	case DIO_PORTB:
		if (CHECK_BIT(DIO_PINB_REG,pin) == 1)
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

	case DIO_PORTC:
		if (CHECK_BIT(DIO_PINC_REG,pin) == 1)
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

	case DIO_PORTD:
		if (CHECK_BIT(DIO_PIND_REG,pin) == 1)
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;
	}
	return loc_result;
}



void Dio_Write_Channel_Group(dio_port_t port,u8 mask,u8 data)
{
	switch (port)
	{
		case DIO_PORTA:
		DIO_PORTA_REG = (DIO_PORTA_REG&~mask)|(data&mask);
		break;

		case DIO_PORTB:
		DIO_PORTB_REG = (DIO_PORTB_REG&~mask)|(data&mask);
		break;

		case DIO_PORTC:
			DIO_PORTC_REG = (DIO_PORTC_REG&~mask)|(data&mask);
		break;

		case DIO_PORTD:
		DIO_PORTD_REG = (DIO_PORTD_REG&~mask)|(data&mask);
		break;
	}
}

void Dio_PullUp_Enable(dio_port_t port, dio_pin_t pin)
{
	Dio_Write_Channel(port, pin, DIO_HIGH);
}
