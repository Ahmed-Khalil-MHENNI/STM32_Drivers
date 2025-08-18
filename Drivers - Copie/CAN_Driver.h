/*
 * CAN_Driver.h
 *
 *  Created on: Aug 17, 2025
 *      Author: HP
 */

#ifndef CAN_DRIVER_H_
#define CAN_DRIVER_H_

#include "stm32f407-disc.h"
//-----------------------------
// CAN Driver Declarations
//-----------------------------
typedef struct
{
   uint32_t TIR;
   uint32_t TDTR;
   uint32_t TDLR;
   uint32_t TDHR;
} CAN_TxMailBox_TypeDef;

typedef struct
{
   uint32_t RIR;
   uint32_t RDTR;
   uint32_t RDLR;
   uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
   uint32_t FR1;
   uint32_t FR2;
} CAN_FilterRegister_TypeDef;



// Bitrate (à adapter selon ton bus CAN)
#define CAN_BITRATE 500000

// CAN Message Structure
typedef struct {
    uint32_t id;        // Identifiant (standard 11 bits ou étendu 29 bits)
    uint8_t  ide;       // 0 = standard, 1 = étendu
    uint8_t  rtr;       // 0 = data frame, 1 = remote frame
    uint8_t  dlc;       // Data Length Code (0..8)
    uint8_t  data[8];   // Données
} CAN_Message;

//-----------------------------
// Function Prototypes
//-----------------------------
void CAN1_Init(void);                          // Init CAN1 peripheral
void CAN1_SendMessage(CAN_Message *msg);       // Send a CAN message
uint8_t CAN1_ReceiveMessage(CAN_Message *msg); // Receive CAN message (returns 1 if ok, 0 if none)

//-----------------------------
// Global Variables
//-----------------------------
volatile uint8_t CAN1_MessagePending = 0;      // Flag if a new message is pending


#endif /* CAN_DRIVER_H_ */
