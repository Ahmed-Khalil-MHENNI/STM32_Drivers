/*
 * gpio_driver.c
 *
 *  Created on: Aug 5, 2025
 *      Author: HP
 */
#include "gpio_driver.h"

void clockcontrol(GPIO_REG_DEF_t *gpio, uint8_t value){

	if (value == ENABLE){
		if(gpio== GPIOA){

			gpioa_clock_en();

		}else if(gpio== GPIOB){

			gpiob_clock_en();

		}else if(gpio== GPIOC){

			gpioc_clock_en();

		}else if(gpio== GPIOD){

			gpiod_clock_en();

		}else if(gpio== GPIOE){

			gpioe_clock_en();

		}else if(gpio== GPIOF){

			gpiof_clock_en();

		}else if(gpio== GPIOG){

			gpiog_clock_en();

		}else if(gpio== GPIOH){

			gpioh_clock_en();

		}else if(gpio== GPIOI){

			gpioi_clock_en();

		}

	}
	else if(value==DISABLE){
		if(gpio== GPIOA){

			gpioa_clock_dis();

		}else if(gpio== GPIOB){

			gpiob_clock_dis();

		}else if(gpio== GPIOC){

			gpioc_clock_dis();

		}else if(gpio== GPIOD){

			gpiod_clock_dis();

		}else if(gpio== GPIOE){

			gpioe_clock_dis();

		}else if(gpio== GPIOF){

			gpiof_clock_dis();

		}else if(gpio== GPIOG){

			gpiog_clock_dis();

		}else if(gpio== GPIOH){

			gpioh_clock_dis();

		}else if(gpio== GPIOI){

			gpioi_clock_dis();

		}

	}
}

void gpio_init(GPIO_REG_DEF_t *gpio,uint8_t GPIO_pinnumber,
		uint8_t GPIO_pinmode,
		uint8_t GPIO_pinspeed,
		uint8_t GPIO_pinpupdcontrol,
		uint8_t GPIO_pinOPtype,
		uint8_t GPIO_pinalt_funmode){

	uint32_t tempreg = 0;
	tempreg |= (GPIO_pinmode << 2*GPIO_pinnumber);
	gpio->MODER &= ~(3<<2*GPIO_pinnumber);
	gpio->MODER |= tempreg;

	tempreg = 0;
	tempreg |= (GPIO_pinspeed << 2*GPIO_pinnumber);
	gpio->OSPEEDR &= ~(3<<2*GPIO_pinnumber);
	gpio->OSPEEDR |= tempreg;

	tempreg = 0;
	tempreg |= (GPIO_pinpupdcontrol << 2*GPIO_pinnumber);
	gpio->PUPDR &= ~(3<<2*GPIO_pinnumber);
	gpio->PUPDR |= tempreg;

	tempreg = 0;
	tempreg |= (GPIO_pinOPtype << GPIO_pinnumber);
	gpio->OTYPER &= ~(1<<GPIO_pinnumber);
	gpio->OTYPER |= tempreg;


	if(GPIO_pinnumber <= 7){
		tempreg = 0;
		tempreg |= (GPIO_pinalt_funmode << 4*GPIO_pinnumber);
		gpio->AFRL &= ~(15<<4*GPIO_pinnumber);
		gpio->AFRL |= tempreg;
	}
	else if(GPIO_pinnumber > 7){
		tempreg = 0;
		tempreg |= (GPIO_pinalt_funmode << 4*GPIO_pinnumber);
		gpio->AFRH &= ~(15<<4*GPIO_pinnumber);
		gpio->AFRH |= tempreg;

	}
}

void gpio_deinit(GPIO_REG_DEF_t *gpio){

	if(gpio == GPIOA){
		RCC -> AHB1RSTR |= (1 << 0);
	}else if(gpio == GPIOB){
		RCC -> AHB1RSTR |= (1 << 1);
	}else if(gpio == GPIOC){
		RCC -> AHB1RSTR |= (1 << 2);
	}else if(gpio == GPIOD){
		RCC -> AHB1RSTR |= (1 << 3);
	}else if(gpio == GPIOE){
		RCC -> AHB1RSTR |= (1 << 4);
	}else if(gpio == GPIOF){
		RCC -> AHB1RSTR |= (1 << 5);
	}else if(gpio == GPIOG){
		RCC -> AHB1RSTR |= (1 << 6);
	}else if(gpio == GPIOH){
		RCC -> AHB1RSTR |= (1 << 7);
	}else if(gpio == GPIOI){
		RCC -> AHB1RSTR |= (1 << 8);
	}
}

uint8_t gpio_read_inpin(GPIO_REG_DEF_t *gpio, uint8_t GPIO_pinnumber){

	uint8_t value;
	value = (((gpio -> IDR) >> GPIO_pinnumber) & 0x0000001);
	return value;
}

uint16_t gpio_read_inport(GPIO_REG_DEF_t *gpio){

	uint16_t value;
	value = gpio -> IDR;
	return value;
}

void gpio_write_outpin(GPIO_REG_DEF_t *gpio, uint8_t GPIO_pinnumber, uint8_t value){

	if( value == 1){
	(gpio -> ODR) |= (value << GPIO_pinnumber);
	} else if (value == 0){
	(gpio -> ODR) &= ~(value << GPIO_pinnumber);
	}
}
void gpio_write_outport(GPIO_REG_DEF_t *gpio, uint16_t value){

		gpio -> ODR |= value;
}




