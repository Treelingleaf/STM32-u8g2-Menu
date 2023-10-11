#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "u8g2.h"
#include "Key.h"
#include "Menu.h"
#include "usart1.h"
// #include "picture.h"

// 这是一个GPIO和延迟函数，用于u8g2库在STM32上的使用
// 通常情况下，您不需要修改此函数
uint8_t u8g2_gpio_and_delay_stm32(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr);

// 声明u8g2_t类型的全局变量u8g2，用于控制显示器
u8g2_t u8g2;

// 声明全局变量MenuStatus，您可能在其他地方使用此变量来跟踪菜单状态
extern uint8_t MenuStatus;

// 这是一个配置u8g2库的函数
void u8g2_Config()
{
	// 使用u8g2_Setup_ssd1306_i2c_128x64_noname_f函数来设置显示器参数
	// 第一个参数是u8g2_t类型的结构体，用于控制显示器
	// U8G2_R0代表屏幕方向，可以根据需要更改为其他值
	// u8x8_byte_hw_i2c和u8g2_gpio_and_delay_stm32是通信和延迟函数，通常情况下，您不需要修改它们
	u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_hw_i2c, u8g2_gpio_and_delay_stm32);

	// 初始化显示器，向显示器发送初始化序列，然后将显示器置于休眠模式
	u8g2_InitDisplay(&u8g2);

	// 唤醒显示器，使其进入正常工作模式
	u8g2_SetPowerSave(&u8g2, 0);

	// 清除显示缓冲区
	u8g2_ClearBuffer(&u8g2);
}

int main(void)
{
	Key_Init();		// 按键初始化
	I2C_Config();	// I2C所用GPIO口初始化
	u8g2_Config();	// u8g2库初始化
	USART_Config(); // 串口初始化
	MenuStatus = MENU_MAIN;
	while (1)
	{
		Menu_Start();
	}
}
