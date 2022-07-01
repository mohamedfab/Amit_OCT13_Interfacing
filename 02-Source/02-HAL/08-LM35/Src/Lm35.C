

void Lm35_Init(void)
{
	ADC_Init();
}
u16 Lm35_Read(void)
{
	u16 result = 0;
	f32 volt =0;
	u16 temp =0;
	result = ADC_Read(LM35_CHANNEL);
	 volt = result * 4.8;
	 temp = volt/10;
	return temp;
}
