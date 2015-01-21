/*---------------------------------------------------------------------------------------------
    Author       : ½ªÍòÓÂ

    Created Date : 2015-01-12

    Descriptions : µ×²ã¿ØÖÆapi
      
    Version             Description             Date                Author
    0.1                 Created                 2015-01-12       ½ªÍòÓÂ

---------------------------------------------------------------------------------------------*/
#include "typedef.h"
#include <string.h>
int deviceInit(SYS_INFO * sysInfo)
{
	int ret =0;
	 USART_InitTypeDef * usartInfo 	= &(sysInfo->usartInfo);	
//	 EXTI_InitTypeDef *	 extiInfo 	= &(sysInfo->extiInfo);
//	 GPIO_InitTypeDef * gpioInfo 	= &(sysInfo->gpioInfo);
//	 NVIC_InitTypeDef * nvicInfo 	= &(sysInfo->nvicInfo);
//	 RCC_ClocksTypeDef * clockInfo 	= &(sysInfo->clockInfo);

	USART_DeInit(USART1);
	USART_DeInit(USART2);
	USART_StructInit(usartInfo);
	usartInfo->USART_BaudRate = 115200;
	USART_Init(USART1, usartInfo);
	USART_Init(USART2, usartInfo);

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	SysTick_Config(72000000 /100);
	
	return ret;
}

int carCal(CAR_INFO * carInfo)
{
	int ret = 0;
	char * usartSpeedOut = carInfo->usartSpeedOut;
	char * usartDirectOut = carInfo->usartDirectOut;

	memset(usartSpeedOut, 0, 10);
	memset(usartDirectOut, 0, 10);
	
	usartSpeedOut[0] = 0x76;//v
	usartSpeedOut[1] = 0x30 + 5;
	usartSpeedOut[2] = 0x30 + 0;
	usartSpeedOut[3] = 0x30 + 0;
	usartSpeedOut[4] = 0x00 + 0;
	usartSpeedOut[5] = 0x0d;

	

	return ret;
}
int carSpeedOut(CAR_INFO * carInfo)
{
	int ret = 0;
	char i;
	char * usartSpeedOut = carInfo->usartSpeedOut;

	for(i = 0; i < 10; i ++)
	{
		if(usartSpeedOut[i])
		{
			USART_SendData(USART1,usartSpeedOut[i]);
		}
	}

	return ret;
}

int carDirectOut(CAR_INFO * carInfo)
{
	int ret =0;
	char i;
	char * usartDirectOut = carInfo->usartDirectOut;

	for(i = 0; i < 10; i ++)
	{
		if(usartDirectOut[i])
		{
			USART_SendData(USART1,usartDirectOut[i]);
		}
	}

	return ret;
}
