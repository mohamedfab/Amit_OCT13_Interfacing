/*
 * Lcd_Interface.h
 *
 *  Created on: Jun 17, 2022
 *      Author: Eng_Fawzi
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "Dio_Interface.h"
#include "Lcd_Types.h"
#include "Lcd_Cfg.h"
#include <util/delay.h>

void Lcd_Init(void);
void Lcd_Display_Chr(u8 chr);
void Lcd_Display_str(u8 str[]);
void Lcd_Goto_Row_Column(u8 row, u8 column);
void Lcd_Cmd(lcd_Cmd_Type command);

#endif /* LCD_INTERFACE_H_ */
