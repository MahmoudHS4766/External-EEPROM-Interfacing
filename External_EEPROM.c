/*
 * External_EEPROM.c
 *
 * Created: 2/8/2024 1:02:09 PM
 *  Author: mahmo
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "LCD.h"
#include "I2C_driver.h"

int main(void)
{
	LCD_Init();
	unsigned char x;
	I2C_MasterInit(50000);
	_delay_ms(500);
	
	I2C_StartCondtion();
	I2C_SLA_plusWrite(0b10100000);
	I2C_WriteData(0b00000000);
	I2C_WriteData(0x34);
	I2C_StopCondtion();
	_delay_ms(500);
	
	I2C_StartCondtion();
	I2C_SLA_plusWrite(0b10100000);
	I2C_WriteData(0b00000000);
	I2C_StopCondtion();
	I2C_StartCondtion();
	//I2C_RepeatedStart();
	I2C_SLA_plusRead(0b10100001);
	x = I2C_NACK_MasterRead();
	I2C_StopCondtion();
	LCD_sendChar(x);
    while (1)
    {
	
    }
}