/*
 * SPI_driver.h
 *
 *  Created on: Aug 7, 2025
 *      Author: HP
 */

#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include "stm32f407-disc.h"
#include <stdint.h>



#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALTEN 2
#define GPIO_MODE_ANALOG 3

void spi_config();
void SPI1_Init(void);
void SPI1_Transfer(uint8_t *outp, uint8_t *inp, int count);
void SPI_Receive (uint8_t *data, int size);
void SPI_GPIOConfig (void);

#endif /* SPI_DRIVER_H_ */
