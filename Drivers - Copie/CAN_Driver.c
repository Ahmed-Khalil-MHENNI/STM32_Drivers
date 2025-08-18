/*
 * CAN_Driver.c
 *
 *  Created on: Aug 17, 2025
 *      Author: HP
 */

#include "stm32f407-disc.h"
#include "CAN_Driver.h"

void CAN1_Init(void) {
    // 1. Enable clocks
    RCC->APB1ENR |= (1 << 25);
    RCC->AHB1ENR |= (1 << 1);

    // 2. Configure PB8 (RX) and PB9 (TX) as AF9
    GPIOB->MODER &= ~((3 << (8*2)) | (3 << (9*2)));
    GPIOB->MODER |= (2 << (8*2)) | (2 << (9*2));
    GPIOB->AFRH |= (9 << ((8-8)*4)) | (9 << ((9-8)*4));

    // 3. Init mode
    CAN1->MCR |= (1 << 0);
    while (!(CAN1->MSR & (1 << 0)));

    // 4. Bit timing (500 kbps @ 42 MHz APB1)
    CAN1->BTR = (2 << 24) | (9 << 20) | (2 << 16) | (5-1);

    // 5. Leave init
    CAN1->MCR &= ~(1 << 0);
    while (CAN1->MSR & (1 << 0));

    // 6. Filter - accept all
    CAN1->FMR |= (1 << 0);
    CAN1->FA1R |= 1;
    CAN1->FMR &= ~(1 << 0);
}

void CAN1_Send(uint16_t id, uint8_t *data, uint8_t len) {
    CAN1->sTxMailBox[0].TIR = (id << 21);
    CAN1->sTxMailBox[0].TDTR = len;
    CAN1->sTxMailBox[0].TDLR = *((uint32_t*)data);
    CAN1->sTxMailBox[0].TDHR = *((uint32_t*)(data+4));
    CAN1->sTxMailBox[0].TIR |= 1; // TXRQ
}

uint8_t CAN1_Receive(uint8_t *data) {
    if (CAN1->RF0R & 0x03) {
        uint32_t RDLR = CAN1->sFIFOMailBox[0].RDLR;
        uint32_t RDHR = CAN1->sFIFOMailBox[0].RDHR;
        data[0] = RDLR & 0xFF;
        data[1] = (RDLR >> 8) & 0xFF;
        // ... etc
        CAN1->RF0R |= (1 << 5);
        return 1;
    }
    return 0;
}
