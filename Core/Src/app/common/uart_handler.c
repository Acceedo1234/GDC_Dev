/*
 * uart_handler.c
 *
 *  Created on: 04-Oct-2023
 *      Author: Acceedo
 */
#include "main.h"
#include "uart_communication_app.h"
#include "ace_businesslogic.h"

extern UART_HandleTypeDef huart1;

uint8_t dwin_scan;
uint16_t dwin_rx_multipledata[20];
uint8_t dwin_rx_multipledata_completed;
uint8_t Trigger_Hmi_Data_Save;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if((DWINRxData[1] == 0x03)&&(DWINRxData[2] == 0x14))
	{
		CuringTime = (DWINRxData[3]<<8 | DWINRxData[4]);
		TIltingup = (DWINRxData[5]<<8 | DWINRxData[6]);
		tinltingdown = (DWINRxData[7]<<8 | DWINRxData[8]);
		sliderin = (DWINRxData[9]<<8 | DWINRxData[10]);
		SLiderout = (DWINRxData[11]<<8 | DWINRxData[12]);
		Ejectionon = (DWINRxData[13]<<8 | DWINRxData[14]);
		Ejectionoff = (DWINRxData[15]<<8 | DWINRxData[16]);
		Trigger_Hmi_Data_Save =1;
	}

}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(&huart1,DWINRxData,RxNoOfData);
}
