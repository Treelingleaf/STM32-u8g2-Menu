# STM32 OLED动画菜单项目

# 菜单项目

这是一个简单的菜单项目，用于在嵌入式设备上创建和管理菜单。该项目包括一个用户界面，可以通过按键来选择不同的菜单选项，以及子菜单导航功能。

## 目录

- [背景](#背景)
- [安装](#安装)
- [使用](#使用)
- [主要功能](#主要功能)
- [硬件连接](#硬件连接)

## 背景

这个菜单项目的目标是提供一个轻量级的菜单系统，适用于嵌入式设备或其他需要简单用户界面的应用。用户可以通过按键来浏览不同的菜单选项，查看子菜单，并执行相关操作。

## 安装

要使用这个菜单项目，您需要按照以下步骤进行安装：

1. 克隆或下载项目源代码。
2. 编译并部署项目到您的目标设备。
3. 根据您的需求配置菜单选项和子菜单。
4. 运行项目，即可开始使用菜单系统。

## 使用

您可以通过以下方式使用菜单项目：

```c
// 示例代码
#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "u8g2.h"
#include "Key.h"
#include "Menu.h"
#include "usart1.h"

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

```
创建一个菜单，详细参数查看Menu.c和Menu.h：
```c
/*定义主菜单*/
MainMenu MainMenu_Config[4] = {
	{game, "GAME", NULL},
	{wechat, "MESSAGE", NULL},
	{setting, "SETTING", NULL},
	{game, "EXIT", NULL}};

/*二级菜单*/
ChildMenu MessageMune[4] = {
	{"Hello World", NULL, NULL, NULL, MAIN_TO_CHILD}, 
	{"Hello Kettiy", NULL, NULL, NULL, MAIN_TO_CHILD}, 
	{"I'm Li Hua", NULL, NULL, NULL, MAIN_TO_CHILD},
	{"This is a message", NULL, NULL, NULL, MAIN_TO_CHILD}};

/*三级菜单*/
ChildMenu MessageChild2[4] = { 
	{"this is message1", NULL, NULL, NULL, CHILD_TO_CHILD},
	{"this is message2", NULL, NULL, NULL, CHILD_TO_CHILD},
	{"this is message3", NULL, NULL, NULL, CHILD_TO_CHILD},
	{"this is message4", NULL, NULL, NULL, CHILD_TO_CHILD}}; 

/*在UIConnect中链接菜单*/ 
void UIConnect(void) 
{
	/*主菜单和子菜单关系*/
	MainMenu_Config[1].ChildMenu = MessageMune;

    /*子级关系*/
	MessageMune[1].child = MessageChild2; 

	/*父级关系*/ 
	MessageChild2->father = MessageMune;
}
```

## 主要功能

- 主菜单和子菜单支持。
- 使用按键导航和选择不同的菜单选项。
- 显示菜单内容和子菜单内容。
- 简单的动画效果来切换菜单界面。
- 可扩展性，您可以根据自己的需求自定义菜单项。

## 硬件连接
Key_left --- PB11   
key_right --- PB0  
key_ok --- PB5  
key_return --- PB8   
I2C_SCK --- PB6  
I2c_SDA --- PB
