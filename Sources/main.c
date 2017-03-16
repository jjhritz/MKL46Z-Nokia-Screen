#include "global.h"
#include "nokia_lcd.h"
#include "gpio.h"
#include "port.h"
#include "spi.h"
#include "int.h"
#include "frdm_pushb.h"
#include "tpm.h"
#include "tpm_pwm.h"

#define forever for(;;)

static callback_v_t g_portc_callback[32] = { 0 };

void hardware_init()
{
	//Enable SIM clock to ports A-E
	SIM_SCGC5 |= 0b11111 << 9;

	//configure port pins for GPIO
	port_gpio_config(PORT_B, 3); // /RST
	port_gpio_config(PORT_C, 2); //DC

    //Configure pins for output
	gpiob_pddr_config(3, GPIO_PDDR_OUT);
    // KRB: Deassert /RST
    GPIOB_PDOR |= 1 << 3;
	gpioc_pddr_config(2, GPIO_PDDR_OUT);

	//Configure pins for SPI1
	//Configure PTD4 for SPI1_PCS0
	PORT_PCR(PORT_D, 4) &= 0b000 << 8;
	PORT_PCR(PORT_D, 4) |= 0b010 << 8;

	//Configure PTE3 for SPI1_MOSI
	PORT_PCR(PORT_E, 3) &= 0b000 << 8;
	PORT_PCR(PORT_E, 3) |= 0b101 << 8;
	
	//Configure PTE1 for SPI1_MOSI (For my purposes.  PTE3 on my board does not work)
	//PORT_PCR(PORT_E, 1) &= 0b000 << 8;
	//PORT_PCR(PORT_E, 1) |= 0b010 << 8;

	//Configure PTE2 for SPI1_SCK
	PORT_PCR(PORT_E, 2) &= 0b000 << 8;
	PORT_PCR(PORT_E, 2) |= 0b010 << 8;
	
	//Configure PTB9 for SPI1_SCK (For my purposes.  PTE2 on my board does not work)
	//PORT_PCR(PORT_B, 9) &= 0b000 << 8;
	//PORT_PCR(PORT_B, 9) |= 0b010 << 8;

	//Configure PTC1 for TPM0_CH0
	PORT_PCR(PORT_C, 1) &= 0b000 << 8;
	PORT_PCR(PORT_C, 1) |= 0b100 << 8;

	//Enable SIM clock to TPM0
	SIM_SCGC6 &= ~(1 << 24);
	SIM_SCGC6 |= (1 << 24);

    //Initialize TPM0_CH0 for PWM
	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(0b11);

	// Initialize TPM0_SC. We: (1) disable the TPM0 counter by writing
	// 0b00 to TPM0_SC[CMOD] (we will write 0b01 later
	// to enable the counter to begin up counting);
	// (2) DMA is disabled;
	// (3) timer overflow interrupts are disabled;
	// (4) the TPM counter will be an up counter;
	// (5) the prescale divider value is 2^2; this makes the TPM clock
	// period 1 us.

	TPM0_SC = 0x00000002;
	TPM0_CONF = 0;
	TPM0_CONF |= (0b11 << 6);
	TPM0_CNT = 0;
	TPM0_C0SC = 0b00101100;
	TPM0_MOD = 10 - 1; //Set for 10 us (100 Hz)
	TPM0_C0V = (10 * 50) / 100;	//Set for 50% duty cycle

	//Initialize SPI1
	spi1_init();

	//Initialize screen
	nokia_lcd_init();


	//Configure interrupts
	int_init(int_src_portscd, int_priority_3, int_state_enabled);
	
	//initialize push button hardware

	//Configure Push Button pins using the following parameters
	//(1) ISF = 1 to clear any pending interrupt requests; 
	//(2) IRQC = 0b1010 to watch for a falling edge; 
	//(3) MUX = 0b001 to configure the pin's function to be GPIO; 
	//(4) DSE = x since the pin is being configured as an input pin it does not matter what DSE is; 
	//(5) PFE = 0 to disable the internal passive filter; 
	//(6) SRE = 0 to select fast slew rate; 
	//(7) PE = 1 to enable the internal pullup or pulldown resistor;
	//(8) PS = 1 to enable the internal pullup resistor
	PORT_PCR(PORT_C, 3) = 0x010A0103;
	PORT_PCR(PORT_C, 12) = 0x010A0103;
	
	gpioc_pddr_config(3, GPIO_PDDR_IN);
	gpioc_pddr_config(12, GPIO_PDDR_IN);
	
	//Enable TPM0
	TPM0_SC |= (0b01 << 3);


}

void sw_init()
{
	g_portc_callback[3] = print_charset1;
	g_portc_callback[12] = print_charset2;
}

void pushb_portc_debounce(int p_pin)
{
    uint32_t signal = 1;
    uint16_t state = 0x0000;
    do 
    {
        state = (state << 1) | signal | 0xE000;
        signal = (~GPIOC_PDIR >> p_pin) & 0x01;
    } 
    while (state != 0xF000);
}

void portscd_isr()
{
    // Check PTC3
    if (PORTC_ISFR & 0x00000008) 
    {
        // Debounce before clearing the interrupt request flag. This will eliminate multiple invocations of this
        // ISR due to the switch bouncing up and down.
        pushb_portc_debounce(3);
        PORTC_ISFR |= 0x00000008;
        if (g_portc_callback[3]) 
        {
        	g_portc_callback[3]();
        }
    }
    
    // Check PTC12
    else if (PORTC_ISFR & 0x00001000) 
    {
        // Debounce before clearing the interrupt request flag. This will eliminate multiple invocations of this
        // ISR due to the switch bouncing up and down.
        pushb_portc_debounce(12);
        PORTC_ISFR |= 0x00001000;
        if (g_portc_callback[12])
        {
        	g_portc_callback[12]();
        }
    }
}

void run()
{
    // KRB: FILL SCREEN WITH A'S
    //for (int i = 0; i < 6*12; ++i)
    //	nokia_lcd_draw_char('A');
	
	/*
	nokia_lcd_clr();
	for(int ch = 32; ch <= 103; ch++)
	{
		nokia_lcd_draw_char((char) ch);
	}
	*/
	/*
	nokia_lcd_clr();
	for(int ch = 104; ch <= 126; ch++)
	{
		nokia_lcd_draw_char((char) ch);
	}
	*/
	
	nokia_lcd_draw_char('S');
	nokia_lcd_draw_char('T');
	nokia_lcd_draw_char('A');
	nokia_lcd_draw_char('R');
	nokia_lcd_draw_char('T');
	nokia_lcd_draw_char('U');
	nokia_lcd_draw_char('P');
	
    forever
    {
    	
    	
    	
    }
}

int main()
{
    hardware_init();
    sw_init();
    run();
    return 0;
}
