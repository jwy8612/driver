#ifndef TYPEDEF_H
#define TYPEDEF_H

#include "stm32f10x_conf.h"
typedef struct 
{
	 USART_InitTypeDef 	usartInfo;	
	 EXTI_InitTypeDef 		extiInfo;
	 GPIO_InitTypeDef 		gpioInfo;
	 NVIC_InitTypeDef 		nvicInfo;
	 RCC_ClocksTypeDef	clockInfo;

}SYS_INFO;


#endif 
