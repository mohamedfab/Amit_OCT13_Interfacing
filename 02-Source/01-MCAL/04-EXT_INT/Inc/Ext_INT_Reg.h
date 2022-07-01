/*
 * Ext_INT_Reg.h
 *
 *  Created on: Dec 4, 2021
 *      Author: Eng_Fawzi
 */

#ifndef _EXT_INT_REG_H_
#define _EXT_INT_REG_H_

#define EXT_INT_MCUCR_REG			 (*(volatile u8*)(0x55))
#define EXT_INT_MCUCSR_REG 			 (*(volatile u8*)(0x54))
#define EXT_INT_GICR_REG 			 (*(volatile u8*)(0x5B))
#define EXT_INT_GIFR_REG 			 (*(volatile u8*)(0x5A))

#endif /* 01_SOURCE_01_MCAL_EXT_INT_INC_EXT_INT_REG_H_ */
