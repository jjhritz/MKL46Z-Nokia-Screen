//************************************************************************************************************
// FILE: spi.c
//
// DESCRIPTION
//
// AUTHOR
// John J. Hritz (John.Hritz@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
//************************************************************************************************************
#include "spi.h"
#include "global.h"


void spi1_init()
{
	//Enable SIM to SPI1
	SIM_SCGC4 |= (1 << 23);

	//Activate the SPI1 module.
	//SPI1_C1[SPE] = 1
	SPI1_C1 |= (1 << 6);

	//Configure the MKL46Z to be the SPI master.
	//SPI1_C1[MSTR] = 1
	SPI1_C1 |= (1 << 4);

	//Configure SPI1_BR to obtain f_SCK = 4 MHz.
	//SPI1_BR[SPPR] = 2 (010)
	//SPI1_BR[SPR] = 1 (0001)
	SPI1_BR = 0b0100001;

	//Configure the clock polarity to 0 (low) and clock phase to 0
	//(rx on first edge, tx on second edge)
	//SPI1_C1[CPOL] = 0
	SPI1_C1 &= ~(1 << 3);
	//SPI1_C1[CPHA] = 0
	SPI1_C1 &= ~(1 << 2);

	//Configure 8-bit transfers.
	//SPI1_C2[SPIMODE] = 0
	SPI1_C2 &= ~(1 << 6);

	//Configure SPI to use the Rx and Tx FIFO's.
	//SPI_C3[FIFOMODE] = 1
	SPI1_C3 |= (1 << 0);

	//Configure SPI to send msb first.
	//SPI1_C1[LSBFE] = 0
	SPI1_C1 &= ~(1 << 0);

	//Configure SPI1 to automatically assert and deassert /SS (SPI1_PCS0).
	//SPI1_C1[SSOE] = 1
	SPI1_C1 |= (1 << 1);
	//SPI1_C2[MODFEN] = 1
	SPI1_C2 |= (1 << 4);

	//Disable all interrupts.
	//SPI1_C1[SPIE] = 0
	SPI1_C1 &= ~(1 << 7);
	//SPI1_C1[SPTIE] = 0
	SPI1_C1 &= ~(1 << 5);
	//SPI1_C2[SPMIE] = 0
	SPI1_C2 &= ~(1 << 7);
	//SPI1_C2[TXDMAE] = 0
	SPI1_C2 &= ~(1 << 5);
	//SPI1_C2[RXDMAE] = 0
	SPI1_C2 &= ~(1 << 2);
	//SPI1_C3[TNEARIEN] = 0
	SPI1_C3 &= ~(1 << 2);
	//SPI1_C3[RNFULLIEN] = 0
	SPI1_C2 &= ~(1 << 1);

	//Disable bidirectionality by configuring the MOSI pin to act as the master out pin and not as an input pin.
	//SPI1_C2[SPC0] = 0
	SPI1_C2 &= ~(1 << 0);
	//SPI1_C2[BIDROE] = 0
	SPI1_C2 &= ~(1 << 3);

	//SPI1_C1 = 0x52;
	//SPI1_C2 = 0x10;
	//SPI1_BR = 0x21;
	//SPI1_C3 = 0x01;
}

void spi1_tx_byte(uint8_t data)
{
	//Wait for FIFO to become non-full before writing the next 8-bits
	while(SPI1_S & SPI_S_TXFULLF_MASK)
	{
		//do nothing
	}

	//Transfer 8-bits of data.
	SPI1_DL = data;
}

void spi1_tx_block(uint32_t n, uint8_t block[])
{
	for(uint32_t index = 0; index < n; index++)
	{
		spi1_tx_byte(block[n]);
	}
}
