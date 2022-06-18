/*************************************
 * Lcd.c
 *
 *  Created on: Jun 17, 2022
 *  Author: Eng_Fawzi
 *************************************/

#include "Lcd_Interface.h"

/*
 * D4 - D7  -> PA4 - PA7
 * Rs  	PB1
 * RW	PB2
 * E	PB3
 * */

static void Lcd_Pulse(void)
{
	Dio_Write_Channel(DIO_PORTB, DIO_PIN3, DIO_HIGH);
	_delay_us(1);
	Dio_Write_Channel(DIO_PORTB, DIO_PIN3, DIO_LOW);
}

static void Lcd_Cmd(u8 command)
{
	u8 loc_High_Nibble = command;
	u8 loc_Low_Nibble= command<<4;
	/*	RS = 0	*/
	Dio_Write_Channel(DIO_PORTB,DIO_PIN1, DIO_LOW);
	/*	Write High Nibble	*/
	Dio_Write_Channel_Group(DIO_PORTA,0xF0,loc_High_Nibble);
	/*	Enable pulse	*/
	Lcd_Pulse();

	/*	Write Low Nibble	*/
	Dio_Write_Channel_Group(DIO_PORTA,0xF0,loc_Low_Nibble);
	/*	Enable pulse	*/
	Lcd_Pulse();
}
static void Lcd_Data(u8 data)
{
	u8 loc_High_Nibble = data;
	u8 loc_Low_Nibble= data<<4;
	/*	RS = 1	*/
	Dio_Write_Channel(DIO_PORTB,DIO_PIN1, DIO_HIGH);
	/*	Write High Nibble	*/
	Dio_Write_Channel_Group(DIO_PORTA,0xF0,loc_High_Nibble);
	/*	Enable pulse	*/
	Lcd_Pulse();

	/*	Write Low Nibble	*/
	Dio_Write_Channel_Group(DIO_PORTA,0xF0,loc_Low_Nibble);
	/*	Enable pulse	*/
	Lcd_Pulse();
}
void Lcd_Init(void)
{
	/*	Configure LCD Control Lines as Output	*/
	Dio_Configure_Channel(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);

	/*	Configure LCD Data Lines as Output		*/
	Dio_Configure_Channel(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTA, DIO_PIN5, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTA, DIO_PIN6, DIO_OUTPUT);
	Dio_Configure_Channel(DIO_PORTA, DIO_PIN7, DIO_OUTPUT);

	/*	Set LCD For Write Mode	*/
	Dio_Write_Channel(DIO_PORTB, DIO_PIN2, DIO_LOW);

}


void Lcd_Display_Chr(u8 chr)
{
	Lcd_Data(chr);
}
void Lcd_Display_str(u8 str[])
{
	while(*str != '\0')
	{
		Lcd_Display_Chr(*str);
		str++;
	}
}
void Lcd_Goto_Row_Column(u8 row, u8 column)
{

}
