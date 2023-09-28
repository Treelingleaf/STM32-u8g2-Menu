#include "Menu.h"
#include "Key.h"
#include "u8g2.h"
#include "picture.h"
#include <stdio.h>
#include "Delay.h"

Speed_ENUM Speed_choose;

extern u8g2_t u8g2;
int16_t display = 48;
int16_t diaplay_trg = 1;
uint8_t circle_num;
uint8_t KeyNum;
static uint8_t Picture_Flag = 0; // 功能选择标志位
const char words[][10] = {{"GAME\0"}, {"MESSAGE\0"}, {"SETTING\0"}};
uint8_t Game_Menu_Flag = 0;

uint8_t MenuStatus;

/*-----------------------------*/
mytime_t myTime = {13, 14, 0, 2023, 9, 26};
mytime_t myTimeTemp = {13, 14, 0, 2023, 9, 26};

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

void ui_right_one_Picture(int16_t *a, int b)
{
	uint8_t i = 0;
	if ((i <= 48))
	{
		*a += b;
		i += b;
	}
}

void ui_left_one_Picture(int16_t *a, int b)
{
	uint8_t i = 0;
	if ((i <= 48))
	{
		*a -= b;
		i += b;
	}
}

/*定义主菜单*/
MainMenu MainMenu_Config[3] = {
	{0, game, "GAME", NULL},
	{1, wechat, "MESSAGE", NULL},
	{2, setting, "SETTING", NULL}};

/*定义二级子菜单结构体*/
ChildMenu GameMune[4] = {{"game1:FlyBird"}, {"game2:Dinosaur Rex"}, {"game3:Stick Fight"}, {"game4:Tetris"}};

ChildMenu SettingMune[4] = {
	{"setting1:FlyBird"},
	{"setting2:Dinosaur Rex"},
	{"setting3:Stick Fight"},
	{"setting4:Tetris"}};

/*链接MainMenu和ChildMenu*/
MainMenu_Config[0].ChildMenu = GameMune;

void Show_Menu_Config(void)
{

	u8g2_SetFontMode(&u8g2, 1);					  // 设置字体模式，mode字体模式，启用（1）或禁用（0）透明模式
	u8g2_SetFontDirection(&u8g2, 0);			  // 设置字体方向
	u8g2_SetFont(&u8g2, u8g2_font_spleen6x12_mf); // 设置字体格式

	u8g2_DrawXBM(&u8g2, 44, 36, 40, 40, arrowhead);			// 传入箭头标志图片
	u8g2_DrawXBM(&u8g2, display, 16, 32, 32, game);			// 传入游戏图标图片
	u8g2_DrawXBM(&u8g2, display + 48, 16, 32, 32, wechat);	// 传入信息图标图片
	u8g2_DrawXBM(&u8g2, display + 96, 16, 32, 32, setting); // 传入设置图标图片
	u8g2_SendBuffer(&u8g2);									// 把要显示的信息写入缓存
}

void Show_MenuRE(Speed_ENUM Speed_choose)
{
	if (MenuStatus == MENU_SHOW)
	{
		while (1)
		{
			// 同步时间
			MyTimeSecondRun();
			Show_Menu(fast_speed);
			if (Game_Menu_Flag == 4)
			{
				MenuStatus = MENU_MAIN;
				// Show_MainPage();
				// printf("key4\r\n");
				break;
			}
		}
	}
}

void Show_Menu(Speed_ENUM Speed_choose) // 显示菜单
{
	KeyNum = Key_GetNum();
	Game_Menu_Flag = KeyNum;

	if ((KeyNum == 1) && (display > -48))
	{
		Picture_Flag++;					// 图片标志位，显示"GAME","MESSAGE","SETTING"
		circle_num = 48 / Speed_choose; // 循环多少次，与动态速度有关系，速度越慢约丝滑
		while (circle_num)
		{
			u8g2_ClearBuffer(&u8g2); // 清除缓存必须在此位置，才不会导致画面被清空！
			ui_left_one_Picture(&display, Speed_choose);
			u8g2_DrawXBM(&u8g2, 44, 36, 40, 40, arrowhead);
			u8g2_DrawXBM(&u8g2, display, 16, 32, 32, game);
			u8g2_DrawXBM(&u8g2, display + 48, 16, 32, 32, wechat);
			u8g2_DrawXBM(&u8g2, display + 96, 16, 32, 32, setting);

			u8g2_DrawStr(&u8g2, 52, 10, "MENU:");
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
			u8g2_DrawXBM(&u8g2, display, 16, 32, 32, game);
			u8g2_DrawXBM(&u8g2, display + 48, 16, 32, 32, wechat);
			u8g2_DrawXBM(&u8g2, display + 96, 16, 32, 32, setting);
			u8g2_DrawStr(&u8g2, 52, 10, "MENU:");
			u8g2_SendBuffer(&u8g2);
			circle_num--;
		}
		KeyNum = 0;
	}
	else
		;

	switch (Picture_Flag)
	{
	case 0:
		u8g2_DrawStr(&u8g2, 52, 10, "MENU:");
		u8g2_DrawStr(&u8g2, 82, 10, &words[0][0]);
		u8g2_SendBuffer(&u8g2);
		Creat_Child_Menu(GameMune, "GAME");
		break;

	case 1:
		u8g2_DrawStr(&u8g2, 52, 10, "MENU:");
		u8g2_DrawStr(&u8g2, 82, 10, &words[1][0]);
		u8g2_SendBuffer(&u8g2);
		break;

	case 2:
		u8g2_DrawStr(&u8g2, 52, 10, "MENU:");
		u8g2_DrawStr(&u8g2, 82, 10, &words[2][0]);
		u8g2_SendBuffer(&u8g2);
		Creat_Child_Menu(SettingMune, "Setting");
		break;
	}
}

void Setting_Menu(void)
{
	static char Box_x = 1; // 设置小方框各种参数初始值
	static char Box_y = 14;
	static char Box_w = 84;
	static char Box_h = 13;

	static char Box_x_trg; // 设置小方框目标值
	static char Box_y_trg;
	static char Box_w_trg;
	static char Box_h_trg;

	static int8_t Box_Flag = 0;

	if (Game_Menu_Flag == 3) // 确认键
	{
		// To_Setting_Menu_Display();
		Menu_To_X_Display(SettingMune);
		while (1)
		{

			Game_Menu_Flag = Key_GetNum();
			u8g2_ClearBuffer(&u8g2);

			u8g2_DrawStr(&u8g2, 52, 10, "Setting");
			u8g2_DrawLine(&u8g2, 1, 13, 128, 13);
			u8g2_DrawStr(&u8g2, 3, 24, "setting1:FlyBird");
			u8g2_DrawStr(&u8g2, 3, 36, "setting2:Dinosaur Rex");
			u8g2_DrawStr(&u8g2, 3, 48, "setting3:Stick Fight");
			u8g2_DrawStr(&u8g2, 3, 60, "setting4:Tetris");

			ui_run(&Box_x, &Box_x_trg, 1);
			ui_run(&Box_y, &Box_y_trg, 1);
			ui_run(&Box_w, &Box_w_trg, 2);
			ui_run(&Box_h, &Box_h_trg, 1);

			u8g2_DrawFrame(&u8g2, Box_x, Box_y, Box_w, Box_h);
			u8g2_SendBuffer(&u8g2);

			if (Game_Menu_Flag == 1)
			{
				Box_Flag++;
				if (Box_Flag >= 3)
					Box_Flag = 3;
			}

			if (Game_Menu_Flag == 2)
			{
				Box_Flag--;
				if (Box_Flag <= 0)
					Box_Flag = 0;
			}

			if (Game_Menu_Flag == 4)
			{
				u8g2_ClearBuffer(&u8g2);
				X_To_Menu_Display(SettingMune);
				Game_Menu_Flag = 0;
				break;
			}

			switch (Box_Flag) // 获取方框参数目标值
			{
			case 0:
				Box_x_trg = 1;
				Box_y_trg = 14;
				Box_w_trg = sizeof("game1:FlyBird") * 6;
				Box_h_trg = 13;
				break;
			case 1:
				Box_x_trg = 1;
				Box_y_trg = 27;
				Box_w_trg = sizeof("game2:Dinosaur Rex") * 6;
				Box_h_trg = 13;
				break;
			case 2:
				Box_x_trg = 1;
				Box_y_trg = 38;
				Box_w_trg = sizeof("game1:Stick Fight") * 6;
				Box_h_trg = 13;
				break;
			case 3:
				Box_x_trg = 1;
				Box_y_trg = 51;
				Box_w_trg = sizeof("game1:Tetris") * 6;
				Box_h_trg = 12;
				break;
			}
		}
	}
	// Game_Menu_Flag = 0;//重置
	// Show_Menu_Config();//回到主显示页面
	display = 48 - 96;
	Picture_Flag = 2;
}

/*
@MenuItem

*/
void Game_Menu(void)
{
	static char Box_x = 1; // 设置小方框各种参数初始值
	static char Box_y = 14;
	static char Box_w = 84;
	static char Box_h = 13;

	static char Box_x_trg; // 设置小方框目标值
	static char Box_y_trg;
	static char Box_w_trg;
	static char Box_h_trg;

	static int8_t Box_Flag = 0;

	if (Game_Menu_Flag == 3) // 确认键
	{
		// To_Game_Menu_Display();
		Menu_To_X_Display(GameMune);
		while (1)
		{

			Game_Menu_Flag = Key_GetNum();
			u8g2_ClearBuffer(&u8g2);

			u8g2_DrawStr(&u8g2, 52, 10, "GAME");
			u8g2_DrawLine(&u8g2, 1, 13, 128, 13);
			u8g2_DrawStr(&u8g2, 3, 24, "game1:FlyBird");
			u8g2_DrawStr(&u8g2, 3, 36, "game2:Dinosaur Rex");
			u8g2_DrawStr(&u8g2, 3, 48, "game3:Stick Fight");
			u8g2_DrawStr(&u8g2, 3, 60, "game4:Tetris");

			ui_run(&Box_x, &Box_x_trg, 1);
			ui_run(&Box_y, &Box_y_trg, 1);
			ui_run(&Box_w, &Box_w_trg, 2);
			ui_run(&Box_h, &Box_h_trg, 1);

			u8g2_DrawFrame(&u8g2, Box_x, Box_y, Box_w, Box_h);
			u8g2_SendBuffer(&u8g2);

			if (Game_Menu_Flag == 1)
			{
				Box_Flag++;
				if (Box_Flag >= 3)
					Box_Flag = 3;
			}

			if (Game_Menu_Flag == 2)
			{
				Box_Flag--;
				if (Box_Flag <= 0)
					Box_Flag = 0;
			}

			if (Game_Menu_Flag == 4)
			{
				u8g2_ClearBuffer(&u8g2);
				X_To_Menu_Display(GameMune);
				Game_Menu_Flag = 0;
				break;
			}

			switch (Box_Flag) // 获取方框参数目标值
			{
			case 0:
				Box_x_trg = 1;
				Box_y_trg = 14;
				Box_w_trg = sizeof("game1:FlyBird") * 6;
				Box_h_trg = 13;
				break;
			case 1:
				Box_x_trg = 1;
				Box_y_trg = 27;
				Box_w_trg = sizeof("game2:Dinosaur Rex") * 6;
				Box_h_trg = 13;
				break;
			case 2:
				Box_x_trg = 1;
				Box_y_trg = 38;
				Box_w_trg = sizeof("game1:Stick Fight") * 6;
				Box_h_trg = 13;
				break;
			case 3:
				Box_x_trg = 1;
				Box_y_trg = 51;
				Box_w_trg = sizeof("game1:Tetris") * 6;
				Box_h_trg = 12;
				break;
			}
		}
	}
	// Game_Menu_Flag = 0;//重置
	// Show_Menu_Config();//回到主显示页面
	display = 48;
	Picture_Flag = 0;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void Creat_Child_Menu(MenuItem *menuitem, char *ChildMenuName)
{
	static char Box_x = 1; // 设置小方框各种参数初始值
	static char Box_y = 14;
	static char Box_w = 84;
	static char Box_h = 13;

	static char Box_x_trg; // 设置小方框目标值
	static char Box_y_trg;
	static char Box_w_trg;
	static char Box_h_trg;

	static int8_t Box_Flag = 0;

	if (Game_Menu_Flag == 3) // 确认键
	{
		// To_Game_Menu_Display();
		Menu_To_X_Display(menuitem);
		while (1)
		{

			Game_Menu_Flag = Key_GetNum();
			u8g2_ClearBuffer(&u8g2);

			u8g2_DrawStr(&u8g2, 52, 10, ChildMenuName);
			u8g2_DrawLine(&u8g2, 1, 13, 128, 13);
			for (int i = 0; i < 4; i++)
			{
				u8g2_DrawStr(&u8g2, 3, 24 + i * 12, menuitem[i].name);
			}
			// u8g2_DrawStr(&u8g2,3,24,"game1:FlyBird");
			// u8g2_DrawStr(&u8g2,3,36,"game2:Dinosaur Rex");
			// u8g2_DrawStr(&u8g2,3,48,"game3:Stick Fight");
			// u8g2_DrawStr(&u8g2,3,60,"game4:Tetris");

			ui_run(&Box_x, &Box_x_trg, 1);
			ui_run(&Box_y, &Box_y_trg, 1);
			ui_run(&Box_w, &Box_w_trg, 2);
			ui_run(&Box_h, &Box_h_trg, 1);

			u8g2_DrawFrame(&u8g2, Box_x, Box_y, Box_w, Box_h);
			u8g2_SendBuffer(&u8g2);

			if (Game_Menu_Flag == 1)
			{
				Box_Flag++;
				if (Box_Flag >= 3)
					Box_Flag = 3;
			}

			if (Game_Menu_Flag == 2)
			{
				Box_Flag--;
				if (Box_Flag <= 0)
					Box_Flag = 0;
			}

			if (Game_Menu_Flag == 4)
			{
				u8g2_ClearBuffer(&u8g2);
				X_To_Menu_Display(menuitem);
				Game_Menu_Flag = 0;
				break;
			}

			switch (Box_Flag) // 获取方框参数目标值
			{
			case 0:
				Box_x_trg = 1;
				Box_y_trg = 14;
				Box_w_trg = sizeof("game1:FlyBird") * 6;
				Box_h_trg = 13;
				break;
			case 1:
				Box_x_trg = 1;
				Box_y_trg = 27;
				Box_w_trg = sizeof("game2:Dinosaur Rex") * 6;
				Box_h_trg = 13;
				break;
			case 2:
				Box_x_trg = 1;
				Box_y_trg = 38;
				Box_w_trg = sizeof("game1:Stick Fight") * 6;
				Box_h_trg = 13;
				break;
			case 3:
				Box_x_trg = 1;
				Box_y_trg = 51;
				Box_w_trg = sizeof("game1:Tetris") * 6;
				Box_h_trg = 12;
				break;
			}
		}
	}
	display = 48;
	Picture_Flag = 0;
}

/*
菜单到子菜单动画
@menuitem：指向MenuItem结构体数组的指针
*/
void Menu_To_X_Display(MenuItem *menuitem) // 菜单→游戏菜单过渡动画
{

	char Game_Menu_Display = 10;
	char Game_Menu_Display_trg = 74;

	while (Game_Menu_Display != Game_Menu_Display_trg)
	{

		u8g2_ClearBuffer(&u8g2);
		u8g2_DrawStr(&u8g2, 52, Game_Menu_Display, "MENU:");					   // Y要变为0或72“MENU”才会完全消失
		u8g2_DrawXBM(&u8g2, 44, Game_Menu_Display + 26, 40, 40, arrowhead);		   // 传入箭头标志图片
		u8g2_DrawXBM(&u8g2, display, Game_Menu_Display + 6, 32, 32, game);		   // 传入游戏图标图片
		u8g2_DrawXBM(&u8g2, display + 48, Game_Menu_Display + 6, 32, 32, wechat);  // 传入信息图标图片
		u8g2_DrawXBM(&u8g2, display + 96, Game_Menu_Display + 6, 32, 32, setting); // 传入设置图标图片
		ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
		u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
	}

	Game_Menu_Display = 74;
	Game_Menu_Display_trg = 10;

	while (Game_Menu_Display != Game_Menu_Display_trg)
	{
		u8g2_ClearBuffer(&u8g2);
		u8g2_DrawStr(&u8g2, 52, Game_Menu_Display, "GAME"); // Game_Menu_Display+16+62为72，此时“Game”消失
		u8g2_DrawLine(&u8g2, 1, Game_Menu_Display + 3, 128, Game_Menu_Display + 3);
		u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 14, menuitem[0].name);
		u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 26, menuitem[1].name);
		u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 38, menuitem[2].name);
		u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 50, menuitem[3].name);
		ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
		u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
	}
}
/*
子菜单返回主菜单动画
@menuitem：指向MenuItem结构体数组的指针
*/
void X_To_Menu_Display(MenuItem *menuitem)
{
	char Game_Menu_Display = 10;
	char Game_Menu_Display_trg = 74;

	while (Game_Menu_Display != Game_Menu_Display_trg)
	{
		u8g2_ClearBuffer(&u8g2);
		u8g2_DrawStr(&u8g2, 52, Game_Menu_Display, "GAME"); // Game_Menu_Display+16+62为72，此时“Game”消失
		u8g2_DrawLine(&u8g2, 1, Game_Menu_Display + 3, 128, Game_Menu_Display + 3);
		u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 14, menuitem[0].name);
		u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 26, menuitem[1].name);
		u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 38, menuitem[2].name);
		u8g2_DrawStr(&u8g2, 3, Game_Menu_Display + 50, menuitem[3].name);
		ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
		u8g2_SendBuffer(&u8g2); // 把要显示的信息写入缓存
	}
	Game_Menu_Display = 74;
	Game_Menu_Display_trg = 10;

	while (Game_Menu_Display != Game_Menu_Display_trg)
	{
		u8g2_ClearBuffer(&u8g2);
		ui_run(&Game_Menu_Display, &Game_Menu_Display_trg, 8);
		u8g2_DrawStr(&u8g2, 52, Game_Menu_Display, "MENU:");					   // Y要变为0或>=72“MENU”才会完全消失
		u8g2_DrawXBM(&u8g2, 44, Game_Menu_Display + 26, 40, 40, arrowhead);		   // 传入箭头标志图片
		u8g2_DrawXBM(&u8g2, display, Game_Menu_Display + 6, 32, 32, game);		   // 传入游戏图标图片
		u8g2_DrawXBM(&u8g2, display + 48, Game_Menu_Display + 6, 32, 32, wechat);  // 传入信息图标图片
		u8g2_DrawXBM(&u8g2, display + 96, Game_Menu_Display + 6, 32, 32, setting); // 传入设置图标图片
		u8g2_SendBuffer(&u8g2);													   // 把要显示的信息写入缓存
	}
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

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

void Menu_start(void)
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
