/*
 * Ext_INT_Types.h
 *
 *  Created on: Dec 4, 2021
 *      Author: Eng_Fawzi
 */

#ifndef _INT_TYPES_H_
#define _INT_TYPES_H_

typedef enum
{
 EXT_INT0,
 EXT_INT1,
 EXT_INT2
}ext_Int_t;


typedef enum
{
 LOW_LEVEL,
 BOTH_EDGES,
 FAILING_EDGE,
 RISING_EDGE
}snc_mode_t;
#endif /* 01_SOURCE_01_MCAL_EXT_INT_INC_EXT_INT_TYPES_H_ */
