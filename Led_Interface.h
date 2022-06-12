/*
 * Led_Interface.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Eng_Fawzi
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "Dio_Interface.h"
#include "Led_Types.h"
void Led_Init(void);
void Led_ON(led_id_t led);
void Led_OFF(led_id_t led);
void Led_Toggle(led_id_t led);
#endif /* LED_INTERFACE_H_ */
