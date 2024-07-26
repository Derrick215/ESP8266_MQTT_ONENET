#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "delay.h"

LED_INFO LED_info = {0};

void LED_Init()
{
	GPIO_InitTypeDef  GPIO_InitStruce;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStruce.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruce.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStruce.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruce);
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
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

/*
************************************************************
*	�������ƣ�	LED_Set
*
*	�������ܣ�	LED����
*
*	��ڲ�����	status������LED
*
*	���ز�����	��
*
*	˵����		��-LED_ON		��-LED_OFF
************************************************************
*/
void LED1_Set(_Bool status)
{
	
	GPIO_WriteBit(GPIOA, GPIO_Pin_1, status == LED_ON ? Bit_RESET : Bit_SET);		//���status����LED_ON���򷵻�Bit_RESET�����򷵻�Bit_SET
	
	LED_info.LED_Status = status;

}

void LED_Run(void)
{
	LED1_TURN();
	DelayXms(50);
	LED1_TURN();
	DelayXms(50);
}
