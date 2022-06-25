/**************************************
 * 	main.c
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
#include "Keypad_Interface.h"
#include "Adc_Interface.h"


int main ()
{
	u16 result = 0;
	u8 arr[4];
	ADC_vidInit();
	Lcd_Init();
	Lcd_Cmd(_LCD_CURSOR_OFF);
	 Lcd_Display_str("Result= ");
	while (1)
	{
	 result = ADC_vidRead(ADC_CHNL1);
	 Lcd_Goto_Row_Column(0, 8);
	 Lcd_Display_str("    ");
	 Lcd_Goto_Row_Column(0, 8);
	 sprintf(arr,"%d",result);
	 Lcd_Display_str(arr);
	 _delay_ms(500);
	}
	return 0;
}
