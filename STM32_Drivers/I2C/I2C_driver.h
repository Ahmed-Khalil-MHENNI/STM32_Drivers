/*
 * I2C_driver.h
 *
 *  Created on: Aug 13, 2025
 *      Author: HP
 */

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "stm32f407-disc.h"
void I2C_config();
void I2C_Init(void);
void I2C_Transmit (uint8_t *data, int size);
void I2C_Receive (uint8_t *data, int size);
void I2C_GPIOConfig (void);

#endif /* I2C_DRIVER_H_ */
