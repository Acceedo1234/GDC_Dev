/*
 * uart_communication_app.h
 *
 *  Created on: Sep 23, 2023
 *      Author: acceedo
 */
#include "main.h"
#ifndef SRC_APP_MODBUS_UART_COMMUNICATION_APP_H_
#define SRC_APP_MODBUS_UART_COMMUNICATION_APP_H_

extern void ModbusFrame(void);
extern void ModbusInit(void);
extern void Dwin_Rx_Decoder(void);

extern uint8_t DWINRxData[64];
extern uint16_t RxNoOfData;

#endif /* SRC_APP_MODBUS_UART_COMMUNICATION_APP_H_ */
