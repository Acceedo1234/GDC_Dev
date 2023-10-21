/*
 * flashmemory.c
 *
 *  Created on: 14-Oct-2023
 *      Author: acceedo
 */
#include "main.h"
#include "w25qxx.h"
#include "uart_handler.h"
#include "ace_businesslogic.h"

#define HMIDATASECTOR 0

uint8_t writeFlashBuf[10];

uint8_t databuffer_sector_zero[20];
void flashmemoryread(void);

void flashmemoryinit(void){
	W25qxx_Init();
	flashmemoryread();

}

void flashmemoryroutine(void)
{
	if(Trigger_Hmi_Data_Save)
	{
		Trigger_Hmi_Data_Save=0;
		databuffer_sector_zero[0] = (CuringTime & 0xff00)>>8;
		databuffer_sector_zero[1] = (CuringTime & 0xff);
		databuffer_sector_zero[2] = (TIltingup & 0xff00)>>8;
		databuffer_sector_zero[3] = (TIltingup & 0xff);
		databuffer_sector_zero[4] = (tinltingdown & 0xff00)>>8;
		databuffer_sector_zero[5] = (tinltingdown & 0xff);
		databuffer_sector_zero[6] = (sliderin & 0xff00)>>8;
		databuffer_sector_zero[7] = (sliderin & 0xff);
		databuffer_sector_zero[8] = (SLiderout & 0xff00)>>8;
		databuffer_sector_zero[9] = (SLiderout & 0xff);
		databuffer_sector_zero[10] = (Ejectionon & 0xff00)>>8;
		databuffer_sector_zero[11] = (Ejectionon & 0xff);
		databuffer_sector_zero[12] = (Ejectionoff & 0xff00)>>8;
		databuffer_sector_zero[13] = (Ejectionoff & 0xff);
		W25qxx_EraseSector(0);
		W25qxx_WriteSector(databuffer_sector_zero,HMIDATASECTOR,0,14);

	}
}

void flashmemoryread(void)
{
	W25qxx_ReadSector(databuffer_sector_zero,HMIDATASECTOR,0,14);
	CuringTime 		= (databuffer_sector_zero[0]<<8 | databuffer_sector_zero[1]);
	TIltingup 		= (databuffer_sector_zero[2]<<8 | databuffer_sector_zero[3]);
	tinltingdown 	= (databuffer_sector_zero[4]<<8 | databuffer_sector_zero[5]);
	sliderin 		= (databuffer_sector_zero[6]<<8 | databuffer_sector_zero[7]);
	SLiderout 		= (databuffer_sector_zero[8]<<8 | databuffer_sector_zero[9]);
	Ejectionon 		= (databuffer_sector_zero[10]<<8 | databuffer_sector_zero[11]);
	Ejectionoff 	= (databuffer_sector_zero[12]<<8 | databuffer_sector_zero[13]);
	CuringTime_k1 = CuringTime;
	TIltingup_k1 = TIltingup;
	tinltingdown_k1 = tinltingdown;
	SLiderout_k1 = SLiderout;
	sliderin_k1=sliderin;
	Ejectionon_k1 =Ejectionon;
	Ejectionoff_k1=Ejectionoff;
}

