//************************************************************************************************************
// FILE: port.c
//
// DESCRIPTION
// Writes 001 into the MUX field for pin control register (PORTx_PCRn)
// to enable the ports for GPIO
// Currently only writes to Port B, pins 0-3.  Still trying to figure out
// how to generalize it.
//
// AUTHOR
// John J. Hritz (John.Hritz@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
//************************************************************************************************************

#include "port.h"
#include "gpio.h"
#include "systick.h"

/*
callback_v_t g_portc_callback[32] = { 0 };


void callback_init()
{
	g_portc_callback[7] = pushb1_callback;
	g_portc_callback[10] = pushb2_callback;
}
*/

void port_gpio_config(uint32_t port, uint32_t pin)
{
	PORT_PCR(port, pin) &= ~(0b111) << 8;
	PORT_PCR(port, pin) |= 0b001 << 8;
}

/*
void portscd_isr()
{
	//check PTC7
	if(PORTC_ISFR & 0x00000080)
	{
		//Clear IRF
		PORTC_ISFR |= 0x00000080;
		
		//Debounce switch
		pushb_portc_debounce(7);
		
		if(g_portc_callback[7])
		{
			g_portc_callback[7]();
		}
	}
	
	//check PTC10
	if(PORTC_ISFR & 0x00000400)
	{
		//Clear IRF
		PORTC_ISFR |= 0x000000400;
		
		//Debounce switch
		pushb_portc_debounce(10);
		
		if(g_portc_callback[10])
		{
			g_portc_callback[10]();
		}
	}	
}
*/
