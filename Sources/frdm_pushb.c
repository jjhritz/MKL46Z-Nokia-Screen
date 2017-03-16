//************************************************************************************************************
// FILE: frdm_pushb.c
//
// DESCRIPTION
//
// AUTHOR
// John J. Hritz (John.Hritz@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
//************************************************************************************************************
#include "frdm_pushb.h"
#include "nokia_lcd.h"
#include "gpio.h"
#include "port.h"
#include "global.h"

void frdm_pushb_init()
{
	//configure PTC3 for GIPO (SW1)
	port_gpio_config(PORT_C, 3);
	//Enable internal pullup resistor
	PORT_PCR(PORT_C, 3) &= ~(0b11) << 0;
	PORT_PCR(PORT_C, 3) |= 0b11 << 0;
	//Interrupt on falling edge
	PORT_PCR(PORT_C, 3) &= ~(0b1111) << 16;
	PORT_PCR(PORT_C, 3) |= 0b1010 << 16;
	
	//configure PTC12 for GIPO (SW2)
	port_gpio_config(PORT_C, 12);
	//Enable internal pullup resistor
	PORT_PCR(PORT_C, 12) &= ~(0b11) << 0;
	PORT_PCR(PORT_C, 12) |= 0b11 << 0;
	//Interrupt on falling edge
	PORT_PCR(PORT_C, 12) &= ~(0b1111) << 16;
	PORT_PCR(PORT_C, 12) |= 0b1010 << 16;
}

void print_charset1()
{
	nokia_lcd_clr();
	for(int ch = 32; ch <= 103; ch++)
	{
		nokia_lcd_draw_char((char) ch);
	}
}

void print_charset2()
{
	nokia_lcd_clr();
	for(int ch = 104; ch <= 126; ch++)
	{
		nokia_lcd_draw_char((char) ch);
	}
}
