/*
 * GPIOx.h
 *
 *  Created on: Aug 5, 2025
 *      Author: HP
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "stm32f407-disc.h"


#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALTFUN 2
#define GPIO_MODE_ANALOG 3

#define GPIO_LOW_SPEED 0
#define GPIO_MED_SPEED 1
#define GPIO_HIGH_SPEED 2
#define GPIO_VHIGH_SPEED 3

#define GPIO_NOPUPD 0
#define GPIO_PU 1
#define GPIO_PD 2
#define GPIO_RESERVED 3

#define GPIO_PUSHPULL 0
#define GPIO_OPENDR 1

#define GPIO_AF0 0
#define GPIO_AF1 1
#define GPIO_AF2 2
#define GPIO_AF3 3
#define GPIO_AF4 4
#define GPIO_AF5 5
#define GPIO_AF6 6
#define GPIO_AF7 7
#define GPIO_AF8 8
#define GPIO_AF9 9
#define GPIO_AF10 10
#define GPIO_AF11 11
#define GPIO_AF12 12
#define GPIO_AF13 13
#define GPIO_AF14 14
#define GPIO_AF15 15

void clockcontrol(GPIO_REG_DEF_t *gpio, uint8_t value);

//init and deinit
void gpio_init(GPIO_REG_DEF_t *gpio, uint8_t GPIO_pinumber,
		uint8_t GPIO_pinmode, uint8_t GPIO_pinspeed,
		uint8_t GPIO_pinpupdcontrol, uint8_t GPIO_pinOPtype,
		uint8_t GPIO_pinalt_funmode);

void gpio_deinit(GPIO_REG_DEF_t *gpio);
//Read write
uint8_t gpio_read_inpin(GPIO_REG_DEF_t *gpio, uint8_t GPIO_pinnumber);
uint16_t gpio_read_inport(GPIO_REG_DEF_t *gpio);

void gpio_write_outpin(GPIO_REG_DEF_t *gpio, uint8_t GPIO_pinnumber, uint8_t value);
void gpio_write_outport(GPIO_REG_DEF_t *gpio, uint16_t value);

#endif /* GPIO_DRIVER_H_ */
