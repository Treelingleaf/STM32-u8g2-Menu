#include "Delay.h"
#include "Key.h"

static uint8_t Static_KeyNum;

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//设置为下拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 |GPIO_Pin_11 | GPIO_Pin_5 | GPIO_Pin_8;//启用B1,B11,B5引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum=0;
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)//按键按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
		Delay_ms(20);
		KeyNum = 1;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 1)//按键按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 1)
		Delay_ms(20);
		KeyNum = 2;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 1)//按键按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 1)
		Delay_ms(20);
		KeyNum = 3;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 1)//按键按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 1)
		Delay_ms(20);
		KeyNum = 4;
	}
	return KeyNum;
}

uint8_t Static_Key_GetNum(void)
{
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)//按键按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 1)
		Delay_ms(20);
		Static_KeyNum = 1;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 1)//按键按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 1)
		Delay_ms(20);
		Static_KeyNum = 2;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 1)//按键按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 1)
		Delay_ms(20);
		Static_KeyNum = 3;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 1)//按键按下
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 1)
		Delay_ms(20);
		Static_KeyNum = 4;
	}
	return	Static_KeyNum;
}



