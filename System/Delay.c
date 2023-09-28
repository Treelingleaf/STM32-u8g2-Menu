
#include "Delay.h"
/**
  * @brief  微秒级延时
  * @param  xus 延时时长，范围：0~233015
  * @retval 无
  */
void Delay_us(uint32_t xus)
{
	SysTick->LOAD = 72 * xus;				//设置定时器重装值
	SysTick->VAL = 0x00;					//清空当前计数值
	SysTick->CTRL = 0x00000005;				//设置时钟源为HCLK，启动定时器
	while(!(SysTick->CTRL & 0x00010000));	//等待计数到0
	SysTick->CTRL = 0x00000004;				//关闭定时器
}

/**
  * @brief  毫秒级延时
  * @param  xms 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_ms(uint32_t xms)
{
	while(xms--)
	{
		Delay_us(1000);
	}
}
 
/**
  * @brief  秒级延时
  * @param  xs 延时时长，范围：0~4294967295
  * @retval 无
  */
void Delay_s(uint32_t xs)
{
	while(xs--)
	{
		Delay_ms(1000);
	}
} 


 void Delayxus(u32 nus)
{
	u32 temp;
	SysTick->LOAD = 9*nus;//Systick时钟源为8分频 72M/8=9M
	SysTick->VAL = 0x00;//计数寄存器清零
	SysTick->CTRL = 0x01;//Systick计数器使能 时钟源为HCLK/8
	do
	{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&(!(temp&(1<<16))));//判断标志位和使能位
	SysTick->CTRL = 0x00;
	SysTick->VAL = 0x00;
}
/********************************************************************
*名    称:Delay_nms(u32 nms)
*功    能:延时n毫秒 最大值:18642
*入口参数:nms
*出口参数:无
*说    明:无
*调用方法：无
********************************************************************/
 void Delayxms(u32 nms)
{
	u32 temp;
	SysTick->LOAD = 9000*nms;//Systick时钟源为8分频 72M/8=9M
	SysTick->VAL = 0x00;//计数寄存器清零
	SysTick->CTRL = 0x01;//Systick计数器势能 时钟源为HCLK/8
	do
	{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&(!(temp&(1<<16))));//判断标志位和使能位
	SysTick->CTRL = 0x00;
	SysTick->VAL = 0x00;
}

