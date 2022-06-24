/**************************************
 * 	main.c
 *
 *  Created on: Jun 10, 2022
 *	Author: Eng_Fawzi
 **************************************/
#include <util/delay.h>
#include "Std_Types.h"
#include "Led_Interface.h"
#include "Lcd_Interface.h"
#include <stdio.h>
#include "SSD_Interface.h"
#include "Button_Interface.h"
int main ()
{
	s8 counter =0 ;
	SSD_Init();
	Button_Init();

	while (1)
	{
		if (Button_Is_Pressed(BUTTON0) == TRUE)
		{
			SSD_Display_With_Delay(counter,250);
				counter++;
			if (counter>=100)
			{
				counter = 0;
			}
		}
		if (Button_Is_Pressed(BUTTON2) == TRUE)
		{
			_delay_ms(10);
			counter--;
			if (counter<0)
			{
				counter = 0;
			}
		}
		SSD_Display(counter);
	}
	return 0;
}
