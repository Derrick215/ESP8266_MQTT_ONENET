#include "stm32f10x.h"                  // Device header
#include "delay.h"

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruce;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStruce.GPIO_Mode = GPIO_Mode_IPU;		//上拉输入，悬空时为弱上拉。
	GPIO_InitStruce.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStruce.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruce);
}

uint8_t GetKeyNum(void)
{
	uint8_t KeyNumber=0;
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
	{
		DelayXms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0);
		DelayXms(20);
		KeyNumber=1;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		DelayXms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
		DelayXms(20);
		KeyNumber=2;
	}
	return KeyNumber;
}
