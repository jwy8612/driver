#ifndef TYPEDEF_H
#define TYPEDEF_H

#include "stm32f10x_conf.h"

typedef struct CAR_INFO
{
	char udpSpeedIn;
	char udpSpeedOut;
	char usartSpeedOut[10];
	char usartSpeedIn[10];
	char udpDirectIn;
	char udpDirectOut;
	char usartDirectOut[10];
	char usartDirectIn[10];


}CAR_INFO;

typedef struct SYS_INFO
{
	 USART_InitTypeDef 	usartInfo;	
	 EXTI_InitTypeDef 		extiInfo;
	 GPIO_InitTypeDef 		gpioInfo;
	 NVIC_InitTypeDef 		nvicInfo;
	 RCC_ClocksTypeDef	clockInfo;
	// CAR_INFO			carInfo;

}SYS_INFO;


#endif 
