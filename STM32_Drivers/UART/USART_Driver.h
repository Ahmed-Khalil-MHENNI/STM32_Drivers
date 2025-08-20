/*
 * USART_Driver.h
 *
 *  Created on: Aug 15, 2025
 *      Author: HP
 */

#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_

#include "stm32f407-disc.h"

void UART2_SendString(char *str);
char UART2_ReadChar(void);
void UART2_SendChar(char c);
void UART2_Init(void);

#endif /* USART_DRIVER_H_ */
