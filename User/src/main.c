/*---------------------------------------------------------------------------------------------
    Author       : 姜万勇

    Created Date : 2015-01-12

    Descriptions : 底层控制主函数
      
    Version             Description             Date                Author
    0.1                 Created                 2015-01-12       姜万勇

---------------------------------------------------------------------------------------------*/
#include "typedef.h"
#include "drive_api.h"


#define TEST 1

int main(void)
{
	SYS_INFO sysInfo;
	CAR_INFO  carInfo;
	
	deviceInit(&sysInfo);
	#if TEST

	
	RCC_GetClocksFreq(&(sysInfo.clockInfo));
	// USART_SendData(USART1, 0x01);

	
	#endif
	while(1)
	{
		carCal(&carInfo);
		carSpeedOut(&carInfo);
		carDirectOut(&carInfo);
	}

	
	

}
