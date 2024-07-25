#include "stm32f10x.h"                  // Device header


void LED_Init()
{
	GPIO_InitTypeDef  GPIO_InitStruce;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStruce.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruce.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_8;
	GPIO_InitStruce.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruce);
	GPIO_SetBits(GPIOA,GPIO_Pin_1 | GPIO_Pin_8);
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
}

void LED1_TURN(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA , GPIO_Pin_1) == 0)
	{
		GPIO_SetBits(GPIOA , GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA , GPIO_Pin_1);
	}
}

void LED2_TURN(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA , GPIO_Pin_8) == 0)
	{
		GPIO_SetBits(GPIOA , GPIO_Pin_8);
	}
	else
	{
		GPIO_ResetBits(GPIOA , GPIO_Pin_8);
	}
}

