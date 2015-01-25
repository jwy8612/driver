/*---------------------------------------------------------------------------------------------
    Author       : 姜万勇

    Created Date : 2015-01-12

    Descriptions : 底层控制主函数
      
    Version             Description             Date                Author
    0.1                 Created                 2015-01-12       姜万勇

---------------------------------------------------------------------------------------------*/
#include "typedef.h"
#include "drive_api.h"
#include "string.h"


#define TEST 1
CMD_PROCESS cmdProcess;


int sysFrequency;

void Init()
{
	deviceInit();
	memset(&cmdProcess, 0, sizeof(CMD_PROCESS));

}
int main(void)
{
	CAR_INFO  carInfo;
	RCC_ClocksTypeDef  clockInfo;
	int i;
	
	Init();
	#if TEST

	RCC_GetClocksFreq(&clockInfo);
	sysFrequency = clockInfo.SYSCLK_Frequency;

	carInfo.udpSpeedIn = -100;
	
	carInfo.udpDirectIn = 0x0200;
	//carCal(&carInfo);
	//carSpeedOut(&carInfo);
	//carDirectOut(&carInfo);
	#endif
	while(1)
	{
		//carSpeedOut(&carInfo);
		
		//carDirectOut(&carInfo);
		//USART_SendByte(USART1,0x01);
		if(cmdProcess.doneFlag == 1)
		{
			cmdTrans(&carInfo);
		}
			

	}

	
	

}
