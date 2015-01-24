#ifndef TYPEDEF_H
#define TYPEDEF_H

#include "stm32f10x_conf.h"

typedef struct CAR_INFO
{
	signed char udpSpeedIn;
	signed char udpSpeedOut;
	char usartSpeedOut[10];
	char usartSpeedIn[10];
	short udpDirectIn;
	char udpDirectOut;
	char usartDirectOut[11];
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

typedef struct CMD_PROCESS
{
	char commandIn[50];
	char doneFlag;
	char recieveFlag;
	char datalength;
	char index;
}CMD_PROCESS;
#endif 

