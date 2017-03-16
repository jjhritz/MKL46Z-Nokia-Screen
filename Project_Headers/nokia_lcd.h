//************************************************************************************************************
// FILE: nokia_lcd.h
//
// DESCRIPTION
//
// AUTHOR
// John J. Hritz (John.Hritz@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
//************************************************************************************************************
#ifndef NOKIA_LCD_H_
#define NOKIA_LCD_H_

typedef enum
{
	nokia_lcd_mode_cmd,
	nokia_lcd_mode_data
} nokia_lcd_mode_t;

typedef enum
{
	nokia_lcd_reset_asserted,
	nokia_lcd_reset_deasserted
} nokia_lcd_reset_t;

extern uint8_t g_font_table[95][5];

void nokia_lcd_init();
void nokia_lcd_disp_char_xy(uint8_t x, uint8_t y, char ch);
void nokia_lcd_draw_char(char ch);
void nokia_lcd_set_x_char(uint8_t x);
void nokia_lcd_set_y_char(uint8_t y);
void nokia_lcd_set_xy_char(uint8_t x, uint8_t y);
void nokia_lcd_set_x(uint8_t x);
void nokia_lcd_set_y(uint8_t y);
void nokia_lcd_set_xy(uint8_t x, uint8_t y);
void nokia_lcd_clr();
void nokia_lcd_tx(nokia_lcd_mode_t mode, uint8_t data);
void nokia_lcd_cfg_dc(nokia_lcd_mode_t mode);
void nokia_lcd_cfg_reset(nokia_lcd_reset_t state);

#endif
