#include "LED.h"
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//打开GPIOA的时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//设置为推挽输出,GPIO配置好以后默认低电平
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 |GPIO_Pin_2;//启用A1,A2引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
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
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void LED1_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 1)
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	else
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void LED2_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 1)
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	else
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
}
