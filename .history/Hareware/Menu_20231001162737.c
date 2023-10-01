#include "Menu.h"
#include "Key.h"
#include "u8g2.h"
#include "picture.h"
#include <stdio.h>
#include "Delay.h"
#include <string.h>

/*
模块名称: 菜单管理模块
模块描述:
这个模块负责管理显示菜单和子菜单，以及处理用户在菜单页面的交互。模块中包含了一些主要函数，用于展示主菜单、子菜单、处理菜单之间的切换和用户操作。

主要思路:
1. 主菜单和子菜单是通过结构体数组进行组织的，其中每个菜单项都包含了名称、图标等信息。
2. 主菜单的切换通过左右滑动图标来实现，用户按键触发左滑和右滑操作，切换不同的主菜单项。
3. 子菜单的显示和切换在主菜单项被选中时执行，子菜单的内容也可以是一个子级菜单。
4. 菜单项的选中和确认操作由用户按键触发，选中后可以进入子菜单或执行相关操作。

主要实现方法:
1. 使用结构体数组来组织主菜单和子菜单，每个结构体包含了菜单的名称、图标等信息。
2. 利用图形库（u8g2）来绘制菜单和子菜单的界面，包括图标、文字等。
3. 通过处理用户按键来切换主菜单、子菜单和执行相关操作。
4. 实现了菜单到子菜单、子菜单到菜单的切换动画效果，提升用户体验。

如何创建或修改一个菜单页面:
1. 创建一个新的主菜单或子菜单需要定义一个对应的结构体数组，包括菜单项的名称、图标等信息。
2. 在`UIConnect`函数中建立菜单之间的父子关系，将子菜单链接到对应的主菜单项上。
3. 在`Show_Menu`函数中根据用户操作切换菜单，处理菜单的显示逻辑。
4. 如果需要在菜单页面中执行特定操作，可以在合适的地方添加相关代码，例如在选中菜单项后执行特定功能。

提示:
- 要创建新的菜单项，请定义一个新的结构体，并将其添加到对应的菜单数组中。
- 菜单的图标可以通过图形库来绘制，然后转换为XBM格式，并使用`u8g2_DrawXBM`来显示。
- 可以根据需要修改菜单的外观和布局，包括文字位置、字体大小等。
- 在处理用户按键时，注意检查按键状态并执行相应的操作，例如切换菜单、进入子菜单、执行功能等。

*/

/*定义主菜单*/
MainMenu MainMenu_Config[4] = {
	{game, "GAME", NULL},
	{wechat, "MESSAGE", NULL},
	{setting, "SETTING", NULL},
	{game, "EXIT", NULL}};

/*定义二级子菜单结构体*/
ChildMenu GameMune[4] = {
	{"game1:FlyBird", NULL, NULL, NULL, MAIN_TO_CHILD},
	{"game2:Dinosaur Rex", NULL, NULL, NULL, MAIN_TO_CHILD},
	{"game3:Stick Fight", NULL, NULL, NULL, MAIN_TO_CHILD},
	{"game4:Tetris", NULL, NULL, NULL, MAIN_TO_CHILD}};

ChildMenu SettingMune[4] = {
	{"setting1:FlyBird", NULL, NULL, NULL, MAIN_TO_CHILD},
	{"setting2:Dinosaur Rex", NULL, NULL, NULL, MAIN_TO_CHILD},
	{"setting3:Stick Fight", NULL, NULL, NULL, MAIN_TO_CHILD},
	{"setting4:Tetris", NULL, NULL, NULL, MAIN_TO_CHILD}};

ChildMenu GameChild4[4] = {
	{"this is set1", NULL, NULL, NULL, CHILD_TO_CHILD},
	{"this is set2", NULL, NULL, NULL, CHILD_TO_CHILD},
	{"this is set3", NULL, NULL, NULL, CHILD_TO_CHILD},
	{"this is set4", NULL, NULL, NULL, CHILD_TO_CHILD}};

/**
 * 连接主菜单和子菜单，建立父子关系。
 */
void UIConnect(void)
{
	/*子级关系*/
	MainMenu_Config[0].ChildMenu = GameMune;
	MainMenu_Config[2].ChildMenu = SettingMune;
	MainMenu_Config[3].ChildMenu = GameMune;

	GameMune[3].child = GameChild4;

	/*父级关系*/
	GameChild4->father = GameMune;
}

Speed_ENUM Speed_choose;

extern u8g2_t u8g2;
int16_t display = 48;
int16_t diaplay_trg = 1;
uint8_t circle_num;
uint8_t KeyNum;
static uint8_t Picture_Flag = 0; // 功能选择标志位
uint8_t Game_Menu_Flag = 0;

uint8_t MenuStatus;

uint8_t MainMenuQuantity = 0;

/*-----------------------------*/
mytime_t myTime = {13, 14, 0, 2023, 9, 26};
mytime_t myTimeTemp = {13, 14, 0, 2023, 9, 26};

/**
 * 更新秒数并检查是否需要增加分钟或小时。
 */
void MyTimeSecondRun()
{
	static int timeSecondCount = 0;
	timeSecondCount++;
	if (timeSecondCount > 33)
	{
		timeSecondCount = 0;
		myTime.Second++;
	}
}

/**
 * 更新时间，处理分钟和小时的增加。
 */
void MyTimeFun()
{
	if (myTime.Second > 59)
	{
		myTime.Second = 0;
		myTime.Minute++;
	}
	if (myTime.Minute > 59)
	{
		myTime.Minute = 0;
		myTime.Hour++;
	}
	if (myTime.Hour > 23)
	{
		myTime.Hour = 0;
	}
}

/*-----------------------------*/

/**
 * 根据目标值逐渐调整界面元素的位置。
 * @param a - 当前值的指针。
 * @param a_trg - 目标值的指针。
 * @param b - 调整步进。
 */
void ui_run(char *a, char *a_trg, int b)
{
	if (*a < *a_trg)
	{
		*a += b;
		if (*a > *a_trg) // 防止加过头
			*a = *a_trg;
	}
	if (*a > *a_trg)
	{
		*a -= b;
		if (*a < *a_trg) // 防止减过头
			*a = *a_trg;
	}
}

/**
 * 向右滚动一个图片位置。
 * @param a - 图片的当前位置。
 * @param b - 步进。
 */
void ui_right_one_Picture(int16_t *a, int b)
{
	uint8_t i = 0;
	if ((i <= 48))
	{
		*a += b;
		i += b;
	}
}

/**
 * 向左滚动一个图片位置。
 * @param a - 图片的当前位置。
 * @param b - 步进。
 */
void ui_left_one_Picture(int16_t *a, int b)
{
	uint8_t i = 0;
	if ((i <= 48))
	{
		*a -= b;
		i += b;
	}
}

/**
 * 显示菜单配置，包括主菜单和子菜单。
 */
void Show_Menu_Config(void)
{
	UIConnect();
	MainMenuQuantity = sizeof(MainMenu_Config) / sizeof(MainMenu);
	u8g2_SetFontMode(&u8g2, 1);					  // 设置字体模式，mode字体模式，启用（1）或禁用（0）透明模式
	u8g2_SetFontDirection(&u8g2, 0);			  // 设置字体方向
	u8g2_SetFont(&u8g2, u8g2_font_spleen6x12_mf); // 设置字体格式

	u8g2_DrawXBM(&u8g2, 44, 36, 40, 40, arrowhead); // 传入箭头标志图片
	for (int i = 0; i < MainMenuQuantity; i++)
	{
		u8g2_DrawXBM(&u8g2, display + 48 * i, 16, 32, 32, MainMenu_Config[i].ImageData);
	}
	u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
}

/**
 * 根据速度选择，显示菜单并处理用户输入。
 * @param Speed_choose - 用户选择的速度。
 * 主函数调用此函数
 */
void Show_MenuRE(Speed_ENUM Speed_choose)
{
	if (MenuStatus == MENU_SHOW)
	{
		while (1)
		{
			// 同步时间
			MyTimeSecondRun();
			Show_Menu(Speed_choose);
			if (Game_Menu_Flag == 4)
			{
				MenuStatus = MENU_MAIN;
				break;
			}
		}
	}
}

/**
 * 显示当前菜单，处理用户输入。
 * @param Speed_choose - 用户选择的速度。
 */
void Show_Menu(Speed_ENUM Speed_choose) // 显示菜单
{
	KeyNum = Key_GetNum();
	Game_Menu_Flag = KeyNum;

	if ((KeyNum == 1) && (display > -48 * (MainMenuQuantity - 2)))
	{
		Picture_Flag++;					// 图片标志位，显示"GAME","MESSAGE","SETTING"
		circle_num = 48 / Speed_choose; // 循环多少次，与动态速度有关系，速度越慢约丝滑
		while (circle_num)
		{
			u8g2_ClearBuffer(&u8g2); // 清除缓存必须在此位置，才不会导致画面被清空！
			ui_left_one_Picture(&display, Speed_choose);
			u8g2_DrawXBM(&u8g2, 44, 36, 40, 40, arrowhead);
			/*循环显示菜单图标*/
			for (int i = 0; i < MainMenuQuantity; i++)
			{
				u8g2_DrawXBM(&u8g2, display + 48 * i, 16, 32, 32, MainMenu_Config[i].ImageData);
			}
			// u8g2_DrawStr(&u8g2, 52, 10, "MENU:");
			u8g2_SendBuffer(&u8g2);

			circle_num--;
		}

		KeyNum = 0;
	}

	else if ((KeyNum == 2) && (display < 48))
	{
		Picture_Flag--;

		circle_num = 48 / Speed_choose;
		while (circle_num)
		{
			u8g2_ClearBuffer(&u8g2);
			ui_right_one_Picture(&display, Speed_choose);
			u8g2_DrawXBM(&u8g2, 44, 36, 40, 40, arrowhead);
			for (int i = 0; i < MainMenuQuantity; i++)
			{
				u8g2_DrawXBM(&u8g2, display + i * 48, 16, 32, 32, MainMenu_Config[i].ImageData);
			}
			u8g2_SendBuffer(&u8g2);
			circle_num--;
		}
		KeyNum = 0;
	}
	else
		;
	uint8_t str_x;

	str_x = (128 - (strlen(MainMenu_Config[Picture_Flag].MenuName) * 6)) / 2;
	u8g2_DrawStr(&u8g2, str_x, 10, MainMenu_Config[Picture_Flag].MenuName);
	u8g2_SendBuffer(&u8g2);
	if (MainMenu_Config[Picture_Flag].ChildMenu != NULL)
		Creat_Childv2_Menu(MainMenu_Config[Picture_Flag].ChildMenu, MainMenu_Config[Picture_Flag].MenuName, 0);
}

/**
 * 创建子菜单并处理用户输入。
 * @param menuitem - 指向子菜单的指针。
 * @param Title - 子菜单的标题。
 * @param child_Flag - 子菜单标志。
 */
void Creat_Childv2_Menu(ChildMenu *menuitem, char *Title, uint8_t child_Flag)
{
	static char Box_x = 1; // 设置小方框各种参数初始值
	static char Box_y = 15;
	static char Box_w = 84;
	static char Box_h = 12;

	static char Box_x_trg; // 设置小方框目标值
	static char Box_y_trg;
	static char Box_w_trg;
	static char Box_h_trg;

	static char Box_y_temp;
	static char Box_w_temp;

	static int8_t Box_Flag = 0;
	static int8_t Box_Flag_temp = 0;
	static int8_t Box_init = 0;

	Box_x_trg = 1;

	if (Game_Menu_Flag == 3) // 确认键
	{
		// Box_y_trg = 15 + 12 * Box_init;
		Box_Flag_temp = Box_Flag;
		Box_Flag = 0;
		Box_y_temp = Box_y_trg;
		Box_w_temp = Box_w_trg;
		Menu_To_X_Display(menuitem, child_Flag);
		while (1)
		{
			char *child_father_name = menuitem[Box_Flag].name;
			Game_Menu_Flag = Key_GetNum();
			u8g2_ClearBuffer(&u8g2);
			// TODO:根据标题长度进行居中处理
			uint8_t str_x = (128 - (strlen(Title) * 6)) / 2;
			u8g2_DrawStr(&u8g2, str_x, 10, Title);

			u8g2_DrawLine(&u8g2, 1, 13, 128, 13);
			for (int i = 0; i < 4; i++)
			{
				u8g2_DrawStr(&u8g2, 3, 24 + i * 12, menuitem[i].name);
			}
			ui_run(&Box_x, &Box_x_trg, 6);
			ui_run(&Box_y, &Box_y_trg, 6);
			ui_run(&Box_w, &Box_w_trg, 6);
			ui_run(&Box_h, &Box_h_trg, 6);

			u8g2_DrawFrame(&u8g2, Box_x, Box_y, Box_w, Box_h);
			u8g2_SendBuffer(&u8g2);

			if (Game_Menu_Flag == 1)
			{
				Box_Flag++;
				if (Box_Flag > 3)
					Box_Flag = 0;
			}

			if (Game_Menu_Flag == 2)
			{
				Box_Flag--;
				if (Box_Flag < 0)
					Box_Flag = 3;
			}

			if (Game_Menu_Flag == 4)
			{
				u8g2_ClearBuffer(&u8g2);
				X_To_Menu_Display(menuitem, child_Flag);
				if (menuitem->opt == CHILD_TO_CHILD)
				{
					Box_Flag = Box_Flag_temp;
					Box_y = Box_y_temp;
					Box_w = Box_w_temp;
				}
				Game_Menu_Flag = 0;
				break;
			}
			// Box_init = Box_Flag;
			Box_x_trg = 1;
			Box_y_trg = 15 + 12 * Box_Flag;
			Box_w_trg = strlen(menuitem[Box_Flag].name) * 6 + 6;
			Box_h_trg = 12;
			if (menuitem[Box_Flag].child != NULL)
				Creat_Childv2_Menu(menuitem[Box_Flag].child, child_father_name, Box_Flag);
		}
	}
	display = 48 - Picture_Flag * 48;
	Picture_Flag = Picture_Flag;
}

/**
 * 菜单到子菜单动画，处理界面过渡效果。
 * @param menuitem - 指向子菜单的指针。
 * @param child_Flag - 子菜单标志。
 */
void Menu_To_X_Display(ChildMenu *menuitem, uint8_t child_Flag) // 菜单→游戏菜单过渡动画
{

	char Game_Menu_Display = 10;
	char Game_Menu_Display_trg = 74;
	uint8_t str_x = 0;

	if (menuitem[child_Flag].opt == MAIN_TO_CHILD)
	{
		while (Game_Menu_Display != Game_Menu_Display_trg)
		{

			u8g2_ClearBuffer(&u8g2);
			// TODO:根据标题长度进行居中处理
			str_x = (128 - (strlen(MainMenu_Config[Picture_Flag].MenuName) * 6)) / 2;
			u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, MainMenu_Config[Picture_Flag].MenuName);

			u8g2_DrawXBM(&u8g2, 44, Game_Menu_Display + 26, 40, 40, arrowhead); // 传入箭头标志图片
			for (int i = 0; i < MainMenuQuantity; i++)
			{
				u8g2_DrawXBM(&u8g2, display + i * 48, Game_Menu_Display + 6, 32, 32, MainMenu_Config[i].ImageData);
			}
			ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
			u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
		}
	}
	else if (menuitem[child_Flag].opt == CHILD_TO_CHILD)
	{
		while (Game_Menu_Display != Game_Menu_Display_trg)
		{
			u8g2_ClearBuffer(&u8g2);
			if (menuitem->father[child_Flag].opt == MAIN_TO_CHILD)
			{
				str_x = (128 - (strlen(MainMenu_Config[Picture_Flag].MenuName) * 6)) / 2;
				u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, MainMenu_Config[Picture_Flag].MenuName); // Y要变为0或72“MENU”才会完全消失
			}
			else if (menuitem->father[child_Flag].opt == CHILD_TO_CHILD)
			{
				str_x = (128 - (strlen(menuitem->father[child_Flag].name) * 6)) / 2;
				u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, menuitem->father[child_Flag].name);
			}
			u8g2_DrawLine(&u8g2, 1, Game_Menu_Display + 3, 128, Game_Menu_Display + 3);
			for (int i = 0; i < 4; i++)
			{
				u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 14 + 12 * i, menuitem->father[i].name);
			}
			ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
			u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
		}
	}

	Game_Menu_Display = 74;
	Game_Menu_Display_trg = 10;

	while (Game_Menu_Display != Game_Menu_Display_trg)
	{
		u8g2_ClearBuffer(&u8g2);
		if (menuitem[child_Flag].opt == MAIN_TO_CHILD)
		{
			str_x = (128 - (strlen(MainMenu_Config[Picture_Flag].MenuName) * 6)) / 2;
			u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, MainMenu_Config[Picture_Flag].MenuName);
		}
		else if (menuitem[child_Flag].opt == CHILD_TO_CHILD)
		{
			str_x = (128 - (strlen(menuitem->father[child_Flag].name) * 6)) / 2;
			u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, menuitem->father[child_Flag].name);
		}
		u8g2_DrawLine(&u8g2, 1, Game_Menu_Display + 3, 128, Game_Menu_Display + 3);
		for (int i = 0; i < 4; i++)
		{
			u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 14 + 12 * i, menuitem[i].name);
		}
		ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
		u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
	}
}

/**
 * 子菜单返回主菜单动画，处理界面过渡效果。
 * @param menuitem - 指向子菜单的指针。
 * @param child_Flag - 子菜单标志。
 */
void X_To_Menu_Display(ChildMenu *menuitem, uint8_t child_Flag)
{
	char Game_Menu_Display = 10;
	char Game_Menu_Display_trg = 74;
	uint8_t str_x;
	while (Game_Menu_Display != Game_Menu_Display_trg)
	{
		u8g2_ClearBuffer(&u8g2);
		if (menuitem[child_Flag].opt == MAIN_TO_CHILD)
		{
			str_x = (128 - (strlen(MainMenu_Config[Picture_Flag].MenuName) * 6)) / 2;
			u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, MainMenu_Config[Picture_Flag].MenuName);
		}
		else if (menuitem[child_Flag].opt == CHILD_TO_CHILD)
		{
			str_x = (128 - (strlen(menuitem->father[child_Flag].name) * 6)) / 2;
			u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, menuitem->father[child_Flag].name);
		}
		u8g2_DrawLine(&u8g2, 1, Game_Menu_Display + 3, 128, Game_Menu_Display + 3);
		for (int i = 0; i < 4; i++)
		{
			u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 14 + 12 * i, menuitem[i].name);
		}
		ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
		u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
	}
	Game_Menu_Display = 74;
	Game_Menu_Display_trg = 10;

	if (menuitem[child_Flag].opt == MAIN_TO_CHILD)
	{
		while (Game_Menu_Display != Game_Menu_Display_trg)
		{
			u8g2_ClearBuffer(&u8g2);
			ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
			// TODO:根据标题长度进行居中处理
			str_x = (128 - (strlen(MainMenu_Config[Picture_Flag].MenuName) * 6)) / 2;
			u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, MainMenu_Config[Picture_Flag].MenuName);
			u8g2_DrawXBM(&u8g2, 44, Game_Menu_Display + 26, 40, 40, arrowhead); // 传入箭头标志图片
			for (int i = 0; i < MainMenuQuantity; i++)
			{
				u8g2_DrawXBM(&u8g2, display + i * 48, Game_Menu_Display + 6, 32, 32, MainMenu_Config[i].ImageData);
			}
			u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
		}
	}
	else if (menuitem[child_Flag].opt == CHILD_TO_CHILD)
	{
		while (Game_Menu_Display != Game_Menu_Display_trg)
		{
			u8g2_ClearBuffer(&u8g2);
			str_x = (128 - (strlen(MainMenu_Config[Picture_Flag].MenuName) * 6)) / 2;
			u8g2_DrawStr(&u8g2, str_x, Game_Menu_Display, MainMenu_Config[Picture_Flag].MenuName);
			u8g2_DrawLine(&u8g2, 1, Game_Menu_Display + 3, 128, Game_Menu_Display + 3);
			for (int i = 0; i < 4; i++)
			{
				u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 14 + 12 * i, menuitem->father[i].name);
			}
			ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
			u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
		}
	}
}

/**
 * 显示主页面，包括时间和日期信息。
 */
void Show_MainPage(void)
{
	if (MenuStatus == MENU_MAIN)
	{

		MyTimeFun();
		KeyNum = Key_GetNum();
		u8g2_SetFont(&u8g2, u8g2_font_ncenB14_tr);
		u8g2_ClearBuffer(&u8g2);
		// 画横线
		for (int i = 1; i < 15; i++)
		{
			u8g2_DrawHLine(&u8g2, 0, 8, 128);
			u8g2_DrawHLine(&u8g2, 0, 56, 128);
		}

		// 显示时间
		char timeStr[9];
		sprintf(timeStr, "%02d:%02d:%02d", myTime.Hour, myTime.Minute, myTime.Second);
		u8g2_DrawStr(&u8g2, 25, 28, timeStr);

		// 显示日期
		u8g2_SetFont(&u8g2, u8g2_font_helvR12_tr);
		char dateStr[11];
		sprintf(dateStr, "%04d/%02d/%02d", myTime.Year, myTime.Month, myTime.Day);
		u8g2_DrawStr(&u8g2, 22, 48, dateStr);
		u8g2_SendBuffer(&u8g2);
	}
}
