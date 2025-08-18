/*
 * stm32f407-disc.h
 *
 *  Created on: Aug 5, 2025
 *      Author: HP
 */

#ifndef STM32F407_DISC_H_
#define STM32F407_DISC_H_

#include <stdint.h>
#include "CAN_Driver.h"
#define AHB1_BASE_ADDR 0x40020000U
#define AHB2_BASE_ADDR 0x50050000U
#define AHB3_BASE_ADDR 0x60000000U

#define APB1_BASE_ADDR 0x40000000U
#define APB2_BASE_ADDR 0x40023844U

#define GPIOA_BASE_ADDR 0x40020000U
#define GPIOB_BASE_ADDR (AHB1_BASE_ADDR+(0x0400))
#define GPIOC_BASE_ADDR (AHB1_BASE_ADDR+(0x0800))
#define GPIOD_BASE_ADDR (AHB1_BASE_ADDR+(0x0C00))
#define GPIOE_BASE_ADDR (AHB1_BASE_ADDR+(0x1000))
#define GPIOF_BASE_ADDR (AHB1_BASE_ADDR+(0x1400))
#define GPIOG_BASE_ADDR (AHB1_BASE_ADDR+(0x1800))
#define GPIOH_BASE_ADDR (AHB1_BASE_ADDR+(0x1C00))
#define GPIOI_BASE_ADDR (AHB1_BASE_ADDR+(0x2000))


#define GPIO_PIN_0 (1 << 0)

#define ENABLE 1
#define DISABLE 0

typedef struct{
	uint32_t MCR;
	uint32_t MSR;
	uint32_t TSR;
	uint32_t RF0R;
	uint32_t RF1R;
	uint32_t IER;
	uint32_t ESR;
	uint32_t BTR;
	CAN_TxMailBox_TypeDef sTxMailBox[3];      /*!< CAN Tx MailBox,      Address offset: 0x180 - 0x1AC */
    CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];  /*!< CAN FIFO MailBox,    Address offset: 0x1B0 - 0x1CC */
	uint32_t FMR;
	uint32_t FM1R;
	uint32_t FS1R;
	uint32_t FFA1R;
	uint32_t FA1R;
	uint32_t F0R1;
	uint32_t F0R2;
	uint32_t F1R1;
	uint32_t F1R2;
	uint32_t F2R1;
	uint32_t F2R2;
	uint32_t F3R1;
	uint32_t F3R2;
	uint32_t F4R1;
	uint32_t F4R2;
	uint32_t F5R1;
	uint32_t F5R2;
	uint32_t F6R1;
	uint32_t F6R2;
	uint32_t F7R1;
	uint32_t F7R2;
	uint32_t F8R1;
	uint32_t F8R2;
	uint32_t F9R1;
	uint32_t F9R2;
	uint32_t F10R1;
	uint32_t F10R2;
	uint32_t F11R1;
	uint32_t F11R2;
	uint32_t F12R1;
	uint32_t F12R2;
	uint32_t F13R1;
	uint32_t F13R2;
	uint32_t F14R1;
	uint32_t F14R2;
	uint32_t F15R1;
	uint32_t F15R2;
	uint32_t F16R1;
	uint32_t F16R2;
	uint32_t F17R1;
	uint32_t F17R2;
	uint32_t F18R1;
	uint32_t F18R2;
	uint32_t F19R1;
	uint32_t F19R2;
	uint32_t F20R1;
	uint32_t F20R2;
	uint32_t F21R1;
	uint32_t F21R2;
	uint32_t F22R1;
	uint32_t F22R2;
	uint32_t F23R1;
	uint32_t F23R2;
	uint32_t F24R1;
	uint32_t F24R2;
	uint32_t F25R1;
	uint32_t F25R2;
	uint32_t F26R1;
	uint32_t F26R2;
	uint32_t F27R1;
	uint32_t F27R2;
}CAN1_REG_DEF_t;

typedef struct{
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
}USART2_REG_DEF_t;

typedef struct{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t OAR1;
	uint32_t OAR2;
	uint32_t DR;
	uint32_t SR1;
	uint32_t SR2;
	uint32_t CCR;
	uint32_t TRISE;
}I2C_REG_DEF_t;

typedef struct{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SR;
	uint32_t DR;
	uint32_t CRCPR;
	uint32_t RXCRCR;
	uint32_t TXCRCR;
	uint32_t I2SCFGR;
	uint32_t I2SPR;
}SPI_REG_DEF_t;

typedef struct{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;

}GPIO_REG_DEF_t;

typedef struct{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t RESERVED2;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RESERVED6[2];
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
	uint32_t PLLSAICFGR;
	uint32_t RCC_DCKCFGR;

}RCC_REG_DEF_t;

#define GPIOA ((GPIO_REG_DEF_t*)GPIOA_BASE_ADDR)
#define GPIOB ((GPIO_REG_DEF_t*)GPIOB_BASE_ADDR)
#define GPIOC ((GPIO_REG_DEF_t*)GPIOC_BASE_ADDR)
#define GPIOD ((GPIO_REG_DEF_t*)GPIOD_BASE_ADDR)
#define GPIOE ((GPIO_REG_DEF_t*)GPIOE_BASE_ADDR)
#define GPIOF ((GPIO_REG_DEF_t*)GPIOF_BASE_ADDR)
#define GPIOG ((GPIO_REG_DEF_t*)GPIOG_BASE_ADDR)
#define GPIOH ((GPIO_REG_DEF_t*)GPIOH_BASE_ADDR)
#define GPIOI ((GPIO_REG_DEF_t*)GPIOI_BASE_ADDR)


#define RCC_BASE_ADDR 0x40023800U
#define RCC ((RCC_REG_DEF_t*)RCC_BASE_ADDR)


#define gpioa_clock_en() (RCC ->AHB1ENR |= (1<<0))
#define gpiob_clock_en() (RCC->AHB1ENR |= (1<<1))
#define gpioc_clock_en() (RCC->AHB1ENR |= (1<<2))
#define gpiod_clock_en() (RCC->AHB1ENR |= (1<<3))
#define gpioe_clock_en() (RCC->AHB1ENR |= (1<<4))
#define gpiof_clock_en() (RCC->AHB1ENR |= (1<<5))
#define gpiog_clock_en() (RCC->AHB1ENR |= (1<<6))
#define gpioh_clock_en() (RCC->AHB1ENR |= (1<<7))
#define gpioi_clock_en() (RCC->AHB1ENR |= (1<<8))

#define gpioa_clock_dis() (RCC->AHB1ENR &= ~ (1<<0))
#define gpiob_clock_dis() (RCC->AHB1ENR &= ~ (1<<1))
#define gpioc_clock_dis() (RCC->AHB1ENR &= ~ (1<<2))
#define gpiod_clock_dis() (RCC->AHB1ENR &= ~ (1<<3))
#define gpioe_clock_dis() (RCC->AHB1ENR &= ~ (1<<4))
#define gpiof_clock_dis() (RCC->AHB1ENR &= ~ (1<<5))
#define gpiog_clock_dis() (RCC->AHB1ENR &= ~ (1<<6))
#define gpioh_clock_dis() (RCC->AHB1ENR &= ~ (1<<7))
#define gpioi_clock_dis() (RCC->AHB1ENR &= ~ (1<<8))

#define SPI_BASE_ADDR 0x40013000U
#define SPI1 ((SPI_REG_DEF_t*)SPI_BASE_ADDR)

#define I2C_BASE_ADDR 0x40005400U
#define I2C1 ((I2C_REG_DEF_t*)I2C_BASE_ADDR)

#define USART2_BASE_ADDR 0x40004c00U
#define USART2 ((USART2_REG_DEF_t*)USART2_BASE_ADDR)

#define CAN1_BASE_ADDR 0x40006400U
#define CAN1 ((CAN1_REG_DEF_t*)CAN1_BASE_ADDR)

#endif /* STM32F407_DISC_H_ */
