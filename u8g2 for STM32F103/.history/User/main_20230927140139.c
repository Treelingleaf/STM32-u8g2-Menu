#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "u8g2.h"
#include "Key.h"
#include "Menu.h"
#include "usart1.h"
// #include "picture.h"

uint8_t u8g2_gpio_and_delay_stm32(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr);
u8g2_t u8g2;

void u8g2_Config()
{
	u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_hw_i2c, u8g2_gpio_and_delay_stm32); // U8G2_R0代表屏幕方向
	u8g2_InitDisplay(&u8g2);																			 // send init sequence to the display, display is in sleep mode after this,
	u8g2_SetPowerSave(&u8g2, 0);																		 // wake up display
	u8g2_ClearBuffer(&u8g2);
}

int main(void)
{
	Key_Init();			// 按键初始化
	I2C_Config();		// I2C所用GPIO口初始化
	u8g2_Config();		// u8g2库初始化
	USART_Config();		// 串口初始化
	Show_Menu_Config(); // 菜单初始化
	while (1)
	{
		// Show_Menu(fast_speed);  //菜单混动函数，修改"fast_speed"可以更改移滚动速度
		Menu_start();
	}
}
