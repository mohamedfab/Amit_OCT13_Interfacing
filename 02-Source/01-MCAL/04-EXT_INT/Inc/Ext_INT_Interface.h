/*
 * Ext_INT.h
 *
 *  Created on: Dec 4, 2021
 *      Author: Eng_Fawzi
 */

#ifndef _EXT_INT_H_
#define _EXT_INT_H_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Ext_INT_Reg.h"
#include "Ext_INT_Types.h"
void Ext_Interrupt_Enable(ext_Int_t intID);
void Ext_Interrupt_Disable(ext_Int_t intID);
void Ext_Interrupt_SncControl(ext_Int_t intID, snc_mode_t mdoe);
#endif /* 01_SOURCE_01_MCAL_EXT_INT_INC_EXT_INT_H_ */
