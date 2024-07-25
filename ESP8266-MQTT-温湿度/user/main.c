/**
	************************************************************
	************************************************************
	************************************************************
	*	文件名： 	main.c
	*
	*	作者： 		张继瑞
	*
	*	日期： 		2017-05-08
	*
	*	版本： 		V1.0
	*
	*	说明： 		接入onenet，上传数据和命令控制
	*
	*	修改记录：	
	************************************************************
	************************************************************
	************************************************************
**/

//单片机头文件
#include "stm32f10x.h"

//网络协议层
#include "onenet.h"

//网络设备
#include "esp8266.h"

//硬件驱动
#include "delay.h"
#include "usart.h"
#include "beep.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"


//C库
#include <string.h>


#define ESP8266_ONENET_INFO		"AT+CIPSTART=\"TCP\",\"183.230.40.96\",1883\r\n"


/*
************************************************************
*	函数名称：	Hardware_Init
*
*	函数功能：	硬件初始化
*
*	入口参数：	无
*
*	返回参数：	无
*
*	说明：		初始化单片机功能以及外接设备
************************************************************
*/
void Hardware_Init(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//中断控制器分组设置

	Delay_Init();									//systick初始化
	
	LED_Init();										//LED初始化
	
	Key_Init();										//按键初始化
	
	OLED_Init();									//OLED初始化
	
	Usart1_Init(115200);							//串口1，打印信息用
	
	Usart2_Init(115200);							//串口2，驱动ESP8266用
	
//	IIC_Init();										//软件IIC初始化
	
	Beep_Init();									//蜂鸣器初始化
	
	UsartPrintf(USART_DEBUG, " Hardware init OK\r\n");
	
}

uint8_t Key_Num = 0;

/*
************************************************************
*	函数名称：	main
*
*	函数功能：	
*
*	入口参数：	无
*
*	返回参数：	0
*
*	说明：		
************************************************************
*/
int main(void)
{
	
	unsigned short timeCount = 0;	//发送间隔变量
	
	unsigned char *dataPtr = NULL;
	
	Hardware_Init();				//初始化外围硬件
	
	ESP8266_Init();					//初始化ESP8266
////	
//	OneNET_RegisterDevice();
//	
//	UsartPrintf(USART_DEBUG, "Connect MQTTs Server...\r\n");
//	while(ESP8266_SendCmd(ESP8266_ONENET_INFO, "CONNECT"))
//		DelayXms(500);
//	
//	while(OneNet_DevLink())			//接入OneNET
//		DelayXms(500);
	
	OLED_ShowString(1, 1, "OLED_Init!");
	
	Beep_Set(BEEP_ON);				//鸣叫提示接入成功
	LED1_ON();
	LED2_ON();
	DelayXms(250);
	Beep_Set(BEEP_OFF);
	LED1_OFF();
	LED2_OFF();
	
	while(1)
	{
		
//		if(++timeCount >= 500)									//发送间隔5s
//		{
//			SHT20_GetValue();
//			
//			UsartPrintf(USART_DEBUG, "OneNet_SendData\r\n");
//			OneNet_SendData();									//发送数据
//			
//			timeCount = 0;
//			ESP8266_Clear();
//		}
//		
//		dataPtr = ESP8266_GetIPD(0);
//		if(dataPtr != NULL)
//			OneNet_RevPro(dataPtr);
		
		Key_Num = GetKeyNum();
		
		switch (Key_Num)
		{
			case 1:
			{
				LED1_TURN();
				break;
			}
			
			case 2:
			{
				LED2_TURN();
				break;
			}
		}
		
		DelayXms(10);
	
	}

}
