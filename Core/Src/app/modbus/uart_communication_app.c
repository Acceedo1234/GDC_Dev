/*
 * uart_communication_app.c
 *
 *  Created on: Sep 23, 2023
 *      Author: acceedo
 */
#include "uart_communication_app.h"

#include "main.h"

#include "ace_modbus.h"
#include "ace_businesslogic.h"

#define SalveId 1
#define FUNCTIONCODE_READMULTIPLEREG  0x03
#define FUNCTIONCODE_WRITEMULTIPLEREG 0x10

#define STARTADD_READ  0x3000
#define STARTADD_WRITE 0x2000

#define NO_OF_READDATA 	 0x0A
#define NO_OF_WRITEDATA  0x0A

uint16_t Production;

void ModbusFrame(void)
{
	switch(Config)
	{
		case  ReadMultileReg:
			bufftx[0] = SalveId;
			bufftx[1] = FUNCTIONCODE_READMULTIPLEREG;
			bufftx[2] = (STARTADD_READ & 0xff00)>>8;
			bufftx[3] = (STARTADD_READ & 0xff);
			bufftx[4] = (NO_OF_READDATA & 0xff00)>>8;
			bufftx[5] = (NO_OF_READDATA & 0xff);

			CRC_value = ASCChecksum(bufftx,6);

			bufftx[6] = (CRC_value & 0xff);
			bufftx[7] = (CRC_value & 0xff00)>>8;
			HAL_UART_Transmit_IT(&huart1,bufftx,8);
			Config = WriteMultipleReg;
		break;
		case WriteMultipleReg:
			bufftx[0] = SalveId;
			bufftx[1] = FUNCTIONCODE_WRITEMULTIPLEREG;
			bufftx[2] = (STARTADD_WRITE & 0xff00)>>8;
			bufftx[3] = (STARTADD_WRITE & 0xff);

			bufftx[4] = (NO_OF_WRITEDATA & 0xff00)>>8;
			bufftx[5] = (NO_OF_WRITEDATA & 0xff);

			bufftx[6] = NO_OF_WRITEDATA*2;

			bufftx[7] = (Production & 0xff00)>>8;
			bufftx[8] = (Production & 0xff);

			bufftx[9] = (0 & 0xff00)>>8;
			bufftx[10] = (0 & 0xff);

			bufftx[11] = (0 & 0xff00)>>8;
			bufftx[12] = (0 & 0xff);

			bufftx[12] = (Inputs_Status & 0xff00)>>8;
			bufftx[13] = (Inputs_Status & 0xff);

			bufftx[14] = (0 & 0xff00)>>8;
			bufftx[15] = (0 & 0xff);

			bufftx[16] = (0 & 0xff00)>>8;
			bufftx[17] = (0 & 0xff);

			bufftx[18] = (0 & 0xff00)>>8;
			bufftx[19] = (0 & 0xff);

			bufftx[20] = (0 & 0xff00)>>8;
			bufftx[21] = (0 & 0xff);

			bufftx[22] = (0 & 0xff00)>>8;
			bufftx[23] = (0 & 0xff);

			bufftx[24] = (0 & 0xff00)>>8;
			bufftx[25] = (0 & 0xff);
			CRC_value = ASCChecksum(bufftx,26);

			bufftx[26] = (CRC_value & 0xff);
			bufftx[27] = (CRC_value & 0xff00)>>8;
			HAL_UART_Transmit_IT(&huart1,bufftx,28);
			Config = ReadMultileReg;
		break;
		default:
			Config = ReadMultileReg;
		break;
	}
}

uint16_t ASCChecksum(uint8_t *ASCSrc, uint8_t NoOfBytes)
{
	uint8_t i, CheckSumBytes;
	uint8_t CRCRegLow = 0xff;
	uint8_t CRCRegHigh = 0xff;
	uint8_t CRCIndex;

	CheckSumBytes = NoOfBytes;
   	for(i=0;i < CheckSumBytes;i++)
   	{
	    CRCIndex = CRCRegLow ^ *ASCSrc++; 				//TransmittingData[i];
		CRCRegLow = CRCRegHigh ^ CRCArrayHigh[CRCIndex];
		CRCRegHigh = CRCArrayLow[CRCIndex];

	}
	return (CRCRegHigh << 8 | CRCRegLow );
}


