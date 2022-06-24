/*
 * SSD_Interface.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng_Fawzi
 */

#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_

#include "Dio_Interface.h"
#include "Std_Types.h"
#include <util/delay.h>

void SSD_Init(void);
void SSD_Display(u8 num);
void SSD_Display_With_Delay(u8 num,u32 delay);
#endif /* 02_SOURCE_02_HAL_06_SSD_INC_SSD_INTERFACE_H_ */
