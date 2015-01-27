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
	memset(&carInfo,0,sizeof(CAR_INFO));

	#if TEST

	RCC_GetClocksFreq(&clockInfo);
	sysFrequency = clockInfo.SYSCLK_Frequency;
	carInfo.udpDirectIn = 0x11111111;

	#endif
	while(1)
	{
		if(cmdProcess.doneFlag == 1)
		{	
			cmdTrans(&carInfo);
			carCal(&carInfo);
			carSpeedOut(&carInfo);
			carDirectOut(&carInfo);
		}
			

	}

	
	

}
