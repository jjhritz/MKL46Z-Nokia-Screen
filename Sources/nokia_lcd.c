//************************************************************************************************************
// FILE: nokia_lcd.c
//
// DESCRIPTION
//
// AUTHOR
// John J. Hritz (John.Hritz@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
//************************************************************************************************************

#include "global.h"
#include "nokia_lcd.h"
#include "spi.h"

uint8_t g_font_table[95][5] =
{
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 32: Space
	    { 0x00, 0x00, 0x5F, 0x00, 0x00 }, // 33: !
	    { 0x00, 0x03, 0x00, 0x03, 0x00 }, // 34: "
	    { 0x14, 0x7F, 0x14, 0x7F, 0x14 }, // 35: #
	    { 0x24, 0x2A, 0x7F, 0x2A, 0x12 }, // 36: $
	    { 0x23, 0x13, 0x08, 0x64, 0x62 }, // 37: %
	    { 0x36, 0x49, 0x55, 0x22, 0x50 }, // 38: &
	    { 0x00, 0x00, 0x03, 0x00, 0x00 }, // 39: '
	    { 0x1C, 0x22, 0x41, 0x00, 0x00 }, // 40: (
	    { 0x00, 0x00, 0x41, 0x22, 0x1C }, // 41: )
	    { 0x0A, 0x04, 0x1F, 0x04, 0x0A }, // 42: *
	    { 0x08, 0x08, 0x3E, 0x08, 0x08 }, // 43: +
	    { 0x00, 0x50, 0x30, 0x00, 0x00 }, // 44: ,
	    { 0x08, 0x08, 0x08, 0x08, 0x08 }, // 45: -
	    { 0x00, 0x60, 0x60, 0x00, 0x00 }, // 46: .
	    { 0x20, 0x10, 0x08, 0x04, 0x02 }, // 47: /
	    { 0x3E, 0x51, 0x49, 0x45, 0x3E }, // 48: 0
	    { 0x00, 0x42, 0x7F, 0x40, 0x00 }, // 49: 1
	    { 0x42, 0x61, 0x51, 0x49, 0x46 }, // 50: 2
	    { 0x21, 0x41, 0x45, 0x4B, 0x31 }, // 51: 3
	    { 0x10, 0x18, 0x14, 0x12, 0x7F }, // 52: 4
	    { 0x27, 0x45, 0x45, 0x45, 0x39 }, // 53: 5
	    { 0x3E, 0x49, 0x49, 0x49, 0x30 }, // 54: 6
	    { 0x03, 0x71, 0x09, 0x05, 0x03 }, // 55: 7
	    { 0x36, 0x49, 0x49, 0x49, 0x36 }, // 56: 8
	    { 0x06, 0x49, 0x49, 0x49, 0x3E }, // 57: 9
	    { 0x00, 0x36, 0x36, 0x00, 0x00 }, // 58: :
	    { 0x00, 0x56, 0x36, 0x00, 0x00 }, // 59: ;
	    { 0x08, 0x14, 0x22, 0x41, 0x00 }, // 60: <
	    { 0x14, 0x14, 0x14, 0x14, 0x14 }, // 61: =
	    { 0x00, 0x41, 0x22, 0x14, 0x08 }, // 62: >
	    { 0x06, 0x01, 0x51, 0x09, 0x06 }, // 63: ?
	    { 0x32, 0x49, 0x79, 0x41, 0x3E }, // 64: @
	    { 0x7C, 0x0A, 0x09, 0x0A, 0x7C }, // 65: A
	    { 0x7F, 0x49, 0x49, 0x49, 0x36 }, // 66: B
	    { 0x3E, 0x41, 0x41, 0x41, 0x22 }, // 67: C
	    { 0x7F, 0x41, 0x41, 0x41, 0x3E }, // 68: D
	    { 0x7F, 0x49, 0x49, 0x49, 0x41 }, // 69: E
	    { 0x7F, 0x09, 0x09, 0x09, 0x01 }, // 70: F
	    { 0x3E, 0x41, 0x41, 0x51, 0x32 }, // 71: G
	    { 0x7F, 0x08, 0x08, 0x08, 0x7F }, // 72: H
	    { 0x00, 0x41, 0x7F, 0x41, 0x00 }, // 73: I
	    { 0x20, 0x40, 0x41, 0x3F, 0x01 }, // 74: J
	    { 0x7F, 0x08, 0x14, 0x22, 0x41 }, // 75: K
	    { 0x7F, 0x40, 0x40, 0x40, 0x40 }, // 76: L
	    { 0x7E, 0x01, 0x06, 0x01, 0x7E }, // 77: M
	    { 0x7F, 0x04, 0x08, 0x10, 0x7F }, // 78: N
	    { 0x3E, 0x41, 0x41, 0x41, 0x3E }, // 79: O
	    { 0x7F, 0x09, 0x09, 0x09, 0x06 }, // 80: P
	    { 0x3E, 0x41, 0x51, 0x21, 0x5E }, // 81: Q
	    { 0x7F, 0x09, 0x19, 0x29, 0x46 }, // 82: R
	    { 0x26, 0x49, 0x49, 0x49, 0x32 }, // 83: S
	    { 0x01, 0x01, 0x7F, 0x01, 0x01 }, // 84: T
	    { 0x3F, 0x40, 0x40, 0x40, 0x3F }, // 85: U
	    { 0x1F, 0x20, 0x40, 0x20, 0x1F }, // 86: V
	    { 0x3F, 0x40, 0x30, 0x40, 0x3F }, // 87: W
	    { 0x63, 0x14, 0x08, 0x14, 0x63 }, // 88: X
	    { 0x07, 0x08, 0x78, 0x08, 0x07 }, // 89: Y
	    { 0x61, 0x51, 0x49, 0x45, 0x43 }, // 90: Z
	    { 0x7F, 0x41, 0x41, 0x00, 0x00 }, // 91: [
	    { 0x02, 0x04, 0x08, 0x10, 0x20 }, // 92: '\'
	    { 0x00, 0x00, 0x41, 0x41, 0x7F }, // 93: ]
	    { 0x04, 0x02, 0x01, 0x02, 0x04 }, // 94: ^
	    { 0x40, 0x40, 0x40, 0x40, 0x40 }, // 95: _
	    { 0x01, 0x02, 0x04, 0x00, 0x00 }, // 96: `
	    { 0x20, 0x54, 0x54, 0x54, 0x78 }, // 97: a
	    { 0x7F, 0x48, 0x48, 0x48, 0x30 }, // 98: b
	    { 0x38, 0x44, 0x44, 0x44, 0x44 }, // 99: c
	    { 0x30, 0x48, 0x48, 0x48, 0x7F }, // 100: d
	    { 0x38, 0x54, 0x54, 0x54, 0x58 }, // 101: e
	    { 0x00, 0x08, 0x7E, 0x09, 0x02 }, // 102: f
	    { 0x48, 0x54, 0x54, 0x54, 0x3C }, // 103: g
	    { 0x7F, 0x08, 0x08, 0x08, 0x70 }, // 104: h
	    { 0x00, 0x00, 0x7A, 0x00, 0x00 }, // 105: i
	    { 0x20, 0x40, 0x40, 0x3D, 0x00 }, // 106: j
	    { 0x00, 0x7F, 0x10, 0x28, 0x44 }, // 107: k
	    { 0x00, 0x41, 0x7F, 0x40, 0x00 }, // 108: l
	    { 0x7C, 0x04, 0x18, 0x04, 0x7C }, // 109: m
	    { 0x7C, 0x08, 0x04, 0x04, 0x78 }, // 110: n
	    { 0x38, 0x44, 0x44, 0x44, 0x38 }, // 111: o
	    { 0x00, 0x7C, 0x14, 0x14, 0x08 }, // 112: p
	    { 0x08, 0x14, 0x14, 0x14, 0x7C }, // 113: q
	    { 0x7C, 0x08, 0x04, 0x04, 0x08 }, // 114: r
	    { 0x48, 0x54, 0x54, 0x54, 0x24 }, // 115: s
	    { 0x04, 0x04, 0x3F, 0x44, 0x24 }, // 116: t
	    { 0x3C, 0x40, 0x40, 0x40, 0x3C }, // 117: u
	    { 0x1C, 0x20, 0x40, 0x20, 0x1C }, // 118: v
	    { 0x3C, 0x40, 0x30, 0x40, 0x3C }, // 119: w
	    { 0x44, 0x28, 0x10, 0x28, 0x44 }, // 120: x
	    { 0x04, 0x48, 0x30, 0x08, 0x04 }, // 121: y
	    { 0x44, 0x64, 0x54, 0x4C, 0x44 }, // 122: z
	    { 0x08, 0x36, 0x41, 0x41, 0x00 }, // 123: {
	    { 0x00, 0x00, 0x7F, 0x00, 0x00 }, // 124: |
	    { 0x00, 0x41, 0x41, 0x36, 0x08 }, // 125: }
	    { 0x02, 0x01, 0x02, 0x04, 0x02 }, // 126: ~
};

void nokia_lcd_init()
{
	//First, we have to reset the PCD8544. This is accomplished by asserting
	// /RST for at least 100 ns before deasserting it.

	//call a gpio module function which sets the state of this GPIO pin
	// /RST = low
	GPIOB_PDOR &= ~(1 << 3);

	//kill time for at least 100 ns -- use a for loop
	for (int i = 0; i < 5; ++i)
	{
		//do nothing
	}

	//call a gpio module function which sets the state of this GPIO pin
	// /RST = high
	GPIOB_PDOR |= (1 << 3);

	//Send instruction Function Set with PD = 0 (we are not powering down),
	//V = 0 (selects horizontal addressing), and H = 1 (use extended instructions).
	//spi1_tx(dc = 0, 0b00100001); 0x21
	nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00100001);

	//Send instruction Set Vop with VOP6..OP0 = 48
	//(this sets the operating voltage of the LCD to 5.94 V;
	//see the discussion of Vop in §8.9 of the data sheet).
	//The lower the operating voltage, the dimmer the display. For my display, 48 worked well.
	//If your display is too dim, try 56. You can experiment with different values
	//but note in the Limiting Values table in §9, VLCD is limited to a maximum of 10 V.
	//spi1_tx(dc = 0, 0b10110000); 0xB8 = 56, 0xC0 = 64
	nokia_lcd_tx(nokia_lcd_mode_cmd, 0b11000000);

	//Send instruction Temperature Control with TC1 and TC0 = 0b00.
	//Liquid crystal displays (aka LCD's) are sensitive to changes in temperature
	//and it requires more voltage at low temperatures to get the atoms
	//moving than it does at higher temperatures.
	//0b00 works well at ambient temperature, but just for fun,
	//you might try putting your evaluation board and LCD in the freezer
	//for a while to see what happens to the display then.
	//spi1_tx(dc = 0, 0b00000100); 0x04
	nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00000100);

	//Send instruction Bias System with BS = 0b11 (see §8.8 of the data sheet).
	//I am not sure what this does, but this is the value that others on the internet have recommended.
	//spi1_tx(dc = 0, 0b00010011); 0x13
	nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00010011);

	//Send instruction Function Set with PD = 0, V = 0, and H = 0 (select basic instructions).
	//spi1_tx(dc = 0, 0b00100000); 0x20
	nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00100000);


	//Send instruction Display Control with D:E = 0b10 (see Table 2 in the data sheet).
	//This configures the display for "normal mode",
	//i.e., pixels are drawn dark on a light background.
	//If D:E = 0b00, the display is blanked, i.e., nothing is displayed.
	//If D:E = 01, all all pixels are turned on. If D:E = 11, inverse mode
	//is selected where pixels are drawn light on a dark background.
	//spi1_tx(dc = 0, 0b00001100); 0x0C
	nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00001100);

	// KRB: Let's clear the RAM before returning.
	nokia_lcd_clr();
}

void nokia_lcd_disp_char_xy(uint8_t x, uint8_t y, char ch)
{
	nokia_lcd_set_xy_char(x, y);
	nokia_lcd_draw_char(ch);
}

void nokia_lcd_draw_char(char ch)
{
	//Draw blank column to the left of the character bitmap
	nokia_lcd_tx(nokia_lcd_mode_data, 0x00);

	//Send each column of pixel data to the display.
	for(uint8_t column = 0; column < 5 ; column++)
	{
		//subtract 32 because ' ' is ASCII 32
		nokia_lcd_tx(nokia_lcd_mode_data, g_font_table[ch - 32][column]);
	}

	//Draw blank column to the right of the character bitmap
	nokia_lcd_tx(nokia_lcd_mode_data, 0x00);
}

void nokia_lcd_set_x_char(uint8_t x)
{
	//if( x >= 0 && x <= 11)
	//{
		//The pixel x-coordinate is 7 * character x-coordinate
		nokia_lcd_set_x(7 * x);
	//}
}

void nokia_lcd_set_y_char(uint8_t y)
{
	//if (y >= 0 && y <= 5)
	//{
		//The pixel y-coordinate is the same as the character y-coordinate
		nokia_lcd_set_y(y);
	//}
}

void nokia_lcd_set_xy_char(uint8_t x, uint8_t y)
{
	//if((x >= 0 && x <= 11) && (y >= 0 && y <= 5))
	//{
		nokia_lcd_set_x_char(x);
		nokia_lcd_set_y_char(y);
	//}
}

void nokia_lcd_set_x(uint8_t x)
{
	//if (x >= 0 && x <= 83)
	//{
		//Set the RAM current x address to x using the Set X Address of RAM instruction.
		//This instruction is identified by the msb being set to 1.
		//Note: || means bit concatenation. Note also that the basic
		//instruction set must be selected (by H = 0 in a Function Set instruction).

		//This function assumes that is the case.
		// KRB: To configure the basic instruction set, need to send 0b0010_0000.
		// nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00100001);
        nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00100000);

		//spi1_tx(dc = 0, 0b1 || x);
		int data = 0b1 << 7;
		data |= x;
		nokia_lcd_tx(nokia_lcd_mode_cmd, data);
	//}
}

void nokia_lcd_set_y(uint8_t y)
{
	//if(y >= 0 && y <= 5)
	//{
		//Set the RAM current y address to y using the Set X Address of RAM instruction.
		//This instruction is identified by the bit 6 being set to 1.
		//Note: || means bit concatenation. Note also that the basic
		//instruction set must be selected (by H = 0 in a Function Set instruction).
		//This function assumes that is the case.
        // KRB: To configure the basic instruction set, need to send 0b0010_0000.
        // nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00100001);
        nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00100000);

		//spi1_tx(dc = 0, 0b01 || y);
		uint8_t data = 0b01 << 6;
		data |= y;
		nokia_lcd_tx(nokia_lcd_mode_cmd, data);
	//}
}

void nokia_lcd_set_xy(uint8_t x, uint8_t y)
{
	//if((y >= 0 && y <= 5) && (x >= 0 && x <= 83))
	//{
		nokia_lcd_set_x(x);

		// KRB: My pseudocode had a mistake that has since been corrected. We should be calling nokica_lcd_set_y().
		//nokia_lcd_set_x(y);
		nokia_lcd_set_y(y);
	//}
}

void nokia_lcd_clr()
{
	//If we are not sure if the basic instruction set is selected,
	//then sending Function Set with H = 0 will select it.
	//spi1_tx(dc = 0, 0b00100000);
	nokia_lcd_tx(nokia_lcd_mode_cmd, 0b00100000);

	//Set the current address to y = bank 0, x = column 0.
	nokia_lcd_set_xy(0, 0);

	//Note that sending data can be done with H = 0 (basic instruction set) or
	//H = 1 (extended instruction set).
	//Note also that DC = 1 when sending pixel data.
	//spi1_tx(dc = 1, 0b00000000);
	for(uint32_t pix = 0; pix < (6 * 84); pix++)
	{
		nokia_lcd_tx(nokia_lcd_mode_data, 0b00000000);
	}
}

void nokia_lcd_tx(nokia_lcd_mode_t mode, uint8_t data)
{
	 nokia_lcd_cfg_dc(mode);
	 spi1_tx_byte(data);
}

void nokia_lcd_cfg_dc(nokia_lcd_mode_t mode)
{
	if(mode == nokia_lcd_mode_cmd)
	{
		//call a gpio module function which sets the state of this GPIO pin to low
		// /DC = 0
		GPIOC_PDOR &= ~(1 << 2);
	}

	else
	{
		//call a gpio module function which sets the state of this GPIO pin to high
		// /DC = 1
		GPIOC_PDOR |= (1 << 2);
	}
}

void nokia_lcd_cfg_reset(nokia_lcd_reset_t state)
{
	//if state is nokia_lcd_reset_asserted then /RST is brought low

	if(state == nokia_lcd_reset_asserted)
	{
		// /RST = 0
		//Since /RST is configured as a GPIO pin,
		//this function shall call a gpio function to set the state of the pin.
		GPIOB_PDOR &= ~(1 << 3);
	}

	else if(state == nokia_lcd_reset_deasserted)
	{
		GPIOB_PDOR |= (1 << 3);
	}
}
