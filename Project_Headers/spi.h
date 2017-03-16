//************************************************************************************************************
// FILE: spi.h
//
// DESCRIPTION
//
// AUTHOR
// John J. Hritz (John.Hritz@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
//************************************************************************************************************
#ifndef SPI_H_
#define SPI_H_

#include "global.h"

void spi1_init();
void spi1_tx_byte(uint8_t data);
void spi1_tx_block(uint32_t n, uint8_t block[]);

#endif
