/*
 * I2C_driver.c
 *
 *  Created on: Aug 13, 2025
 *      Author: HP
 */
#include "I2C_driver.h"
#include "stm32f407-disc.h"

void I2C1_Init(void) {
    // 1. Enable GPIOB and I2C1 clocks
    RCC->AHB1ENR |= (1 << 1);     // GPIOB
    RCC->APB1ENR |= (1 << 21);    // I2C1

    // 2. Configure PB6=SCL, PB7=SDA as AF4 (I2C)
    // Skipping GPIO config code here, use your gpio_init()

    // 3. Reset I2C1
    I2C1->CR1 = 0x8000;  // Software reset
    I2C1->CR1 = 0;

    // 4. Configure I2C timing
    I2C1->CR2 = 16;      // APB1 freq in MHz (e.g., 16 MHz)
    I2C1->CCR = 80;      // Clock control (for 100 kHz)
    I2C1->TRISE = 17;    // Maximum rise time

    // 5. Enable I2C peripheral
    I2C1->CR1 |= (1 << 0);
}
void I2C1_Start(void) {
	//I2C1->CR1 |= CR1_START;          // Generate START condition
    while (!(I2C1->SR1 & (1 << 0)));   // Wait until SB=1
}

void I2C1_Stop(void) {
	I2C1->CR1 |= (1 << 9);           // Generate STOP condition
}

void I2C1_WriteByte(uint8_t addr, uint8_t data) {
	I2C1->DR = addr << 1;             // Send address + write bit (0)
    while (!(I2C1->SR1 & (1 << 1)));  // Wait until address sent
    volatile uint32_t temp = I2C1->SR2; // Clear ADDR flag

    I2C1->DR = data;                  // Send data
    while (!(I2C1->SR1 & (1<<2)));   // Wait until byte transfer finished
}

uint8_t I2C1_ReadByte(uint8_t addr) {
    uint8_t data;

    I2C1->DR = (addr << 1) | 1;       // Send address + read bit (1)
    while (!(I2C1->SR1 & (1 << 1)));  // Wait until address sent
    volatile uint32_t temp = I2C1->SR2; // Clear ADDR flag

    I2C1->DR &= ~(1 << 10);            // NACK for single byte
    I2C1_Stop();

    while (!(I2C1->SR1 & (1 << 6)));  // Wait until data received
    data = I2C1->DR;

    return data;
}


