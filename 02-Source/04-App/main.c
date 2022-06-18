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
int main ()
{
	Lcd_Init();
	u8 var = 200;
	u8 ch[10];
	sprintf(ch,"%d",var);
	Lcd_Display_str(ch);
	while (1)
	{

	}
	return 0;
}
