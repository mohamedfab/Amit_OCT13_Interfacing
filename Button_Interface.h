/*
 * Button_Interface.h
 *
 *  Created on: Jun 12, 2022
 *      Author: Eng_Fawzi
 */

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "Button_Types.h"
#include "Std_Types.h"
#include "Dio_Interface.h"

void Button_Init(void);
boolean Button_Is_Pressed(button_id_t button);

#endif /* BUTTON_INTERFACE_H_ */
