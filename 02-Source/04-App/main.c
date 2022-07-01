/**************************************
 * 	main.c
 *  Created on: Jun 10, 2022
 *	Author: Eng_Fawzi
 **************************************/
#include <util/delay.h>
#include <stdio.h>
#include "Std_Types.h"
#include "Led_Interface.h"
#include "Lcd_Interface.h"
#include <stdio.h>
#include "SSD_Interface.h"
#include "Button_Interface.h"
#include "Keypad_Interface.h"
#include "Adc_Interface.h"
#include "GINT_Interface.h"
#include "Ext_INT_Interface.h"
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	Led_Toggle(LED0);
	while(1);
}


int main ()
{
	Led_Init();
	Ext_Interrupt_Enable(EXT_INT0);
	Ext_Interrupt_SncControl(EXT_INT0, RISING_EDGE);
	GINT_EnableAllInterrupts();
	while (1)
	{
		Led_Toggle(LED1);
		_delay_ms(500);
	}
	return 0;
}
