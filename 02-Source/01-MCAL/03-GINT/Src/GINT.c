/*
 * GINT.c
 *
 *  Created on: Jan 15, 2022
 *      Author: Eng_Fawzi
 */

#include <GINT_Interface.h>

void GINT_EnableAllInterrupts(void)
{
	SET_BIT(GINT_SREG_REG,7);
}
void GINT_DisableAllInterrupts(void)
{
	CLEAR_BIT(GINT_SREG_REG,7);
}
