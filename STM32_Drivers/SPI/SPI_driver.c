/*
 * SPI_driver.C
 *
 *  Created on: Aug 7, 2025
 *      Author: HP
 */



#include"SPI_driver.h"
#include <stdint.h>

void SPI1_Init (void)
{
  RCC->APB2ENR |= (1<<12);  // Enable SPI1 CLock

  SPI1->CR1 |= (1<<0)|(1<<1);   // CPOL=1, CPHA=1

  SPI1->CR1 |= (1<<6);  // Master Mode

  SPI1->CR1 |= (1<<2);  // Master Mode

  SPI1->CR1 |= (3<<3);  // BR[2:0] = 011: fPCLK/16, PCLK2 = 80MHz, SPI clk = 5MHz

  SPI1->CR1 &= ~(1<<7);  // LSBFIRST = 0, MSB first

  SPI1->CR1 |= (1<<8) | (1<<9);  // SSM=1, SSi=1 -> Software Slave Management

  SPI1->CR1 &= ~(1<<10);  // RXONLY = 0, full-duplex

  SPI1->CR1 &= ~(1<<11);  // DFF=0, 8 bit data

  SPI1->CR2 = 0;
}



void SPI1_Transfer(uint8_t *outp, uint8_t *inp, int count) {
   while(count--) {
   while(!(SPI1->SR & (1<<1)));
   *(volatile uint8_t *)&SPI1->DR = *outp++;
   while(!(SPI1->SR & (1<<0)))
   ;
   *inp++ = *(volatile uint8_t *)&SPI1->DR;
   }
}
void SPI_Receive (uint8_t *data, int size)
{
	/************** STEPS TO FOLLOW *****************
	1. Wait for the BSY bit to reset in Status Register
	2. Send some Dummy data before reading the DATA
	3. Wait for the RXNE bit to Set in the status Register
	4. Read data from Data Register
	************************************************/

	while (size)
	{
		while (((SPI1->SR)&(1<<7))) {};  // wait for BSY bit to Reset -> This will indicate that SPI is not busy in communication
		SPI1->DR = 0;  // send dummy data
		while (!((SPI1->SR) &(1<<0))){};  // Wait for RXNE to set -> This will indicate that the Rx buffer is not empty
	  *data++ = (SPI1->DR);
		size--;

	}
}

void SPI_GPIOConfig (void)
{
	RCC->AHB1ENR |= (1<<0);  // Enable GPIO Clock

	GPIOA->MODER |= (2<<10)|(2<<12)|(2<<14)|(1<<18);  // Alternate functions for PA5, PA6, PA7 and Output for PA9

	GPIOA->OSPEEDR |= (3<<10)|(3<<12)|(3<<14)|(3<<18);  // HIGH Speed for PA5, PA6, PA7, PA9

	GPIOA->AFRL |= (5<<20)|(5<<24)|(5<<28);   // AF5(SPI1) for PA5, PA6, PA7
}
