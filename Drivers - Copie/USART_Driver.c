/*
 * USART_Driver.c
 *
 *  Created on: Aug 15, 2025
 *      Author: HP
 */


#include "stm32f407-disc.h".h"

void UART2_Init(void) {
    // 1. Activer horloge GPIOA et USART2
    RCC->AHB1ENR |= (1<<0);     // GPIOA clock
    RCC->APB1ENR |= (1 << 17);    // USART2 clock

    // 2. Configurer PA2 (TX) et PA3 (RX) en AF7
    GPIOA->MODER &= ~((3 << (2*2)) | (3 << (3*2))); // Clear bits
    GPIOA->MODER |= (2 << (2*2)) | (2 << (3*2));    // Alternate function

    GPIOA->AFRL &= ~((0xF << (4*2)) | (0xF << (4*3))); // Clear AFR
    GPIOA->AFRL |= (7 << (4*2)) | (7 << (4*3));        // AF7 (USART2)

    // 3. Configurer Baudrate (ex: 16MHz PCLK1, 9600 baud)
    USART2->BRR = 0x0683; // Mantisse=104, Fraction=3

    // 4. Activer USART, TX et RX
    USART2->CR1 |= (1 << 3) | (1 << 2); // Enable Transmit & Receive
    USART2->CR1 |= (1 << 13);                // USART enable
}

void UART2_SendChar(char c) {
    while (!(USART2->SR & (1 << 7))); // Wait until TX buffer empty
    USART2->DR = c;
}

char UART2_ReadChar(void) {
    while (!(USART2->SR & (1 << 5))); // Wait until data ready
    return USART2->DR;
}

void UART2_SendString(char *str) {
    while (*str) {
        UART2_SendChar(*str++);
    }
}


