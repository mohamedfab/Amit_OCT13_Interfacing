/*
 * Keypad_Interface.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng_Fawzi
 */

#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_
#include "Dio_Interface.h"
#include <util/delay.h>

void Keypad_Init(void);
u8 Keypad_Read(void);

#endif /* 02_SOURCE_02_HAL_07_KEYPAD_INC_KEYPAD_INTERFACE_H_ */
