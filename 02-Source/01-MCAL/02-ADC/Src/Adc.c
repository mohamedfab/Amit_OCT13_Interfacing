/********************************
 * File  	:  Adc.c
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Eng_Fawzi
 ********************************/
#include "Adc_Interface.h"

void ADC_vidInit(void)
{
	ADC_ADMUX_REG|=(AVCC5V_REF<<6);  /*	AVCC aas Vref	*/
	ADC_ADCSRA_REG=(ADC_ENABLE)|(ADCPS_128);
}

u16 ADC_vidRead(adc_Channel_t chnlNo)
{
    u16 result;
    ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|(chnlNo);
    ADC_ADCSRA_REG|=(ADC_START_CONVERSION);
 	while(CHECK_BIT(ADC_ADCSRA_REG,ADIF_BIT_NO) != 1)
 		  {
 		  	  /*	Do Nothing	*/
 		  }
 	/*	Clear Interrupt Flag To Be Ready For Another Conversion	*/
 	 SET_BIT(ADC_ADCSRA_REG,ADIF_BIT_NO);
    result=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));
 	return result;
}
