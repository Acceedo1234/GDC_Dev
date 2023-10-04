/*
 * uart_handler.c
 *
 *  Created on: 04-Oct-2023
 *      Author: Acceedo
 */
#include "main.h"
#include "uart_communication_app.h"
uint8_t dwin_scan;
uint16_t dwin_rx_multipledata[20];
uint8_t dwin_rx_multipledata_completed;
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(DWINRxData[0]==1)
	{
		if(DWINRxData[1]==0x03)
		{
			for(dwin_scan=0;dwin_scan<DWINRxData[3];dwin_scan++)
			{
				dwin_rx_multipledata[dwin_scan]= (DWINRxData[4+dwin_scan]<<8|DWINRxData[5+dwin_scan]);
			}
			dwin_rx_multipledata_completed=1;
		}
	}

}
