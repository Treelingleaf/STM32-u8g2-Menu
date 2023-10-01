#ifndef __MENU_H
#define __MENU_H

#include "stm32f10x.h"

#define LOW_SPEED 1
#define MID_SPEED 3
#define HIGH_SPEED 4
#define FAST_SPEED 6
#define SO_FAST_SPEED 8
#define FAST_MAX 12

typedef enum
{
    low_speed = LOW_SPEED,
    mid_speed = MID_SPEED,
    high_speed = HIGH_SPEED,
    fast_speed = FAST_SPEED,
    so_fast_speed = SO_FAST_SPEED,
    fast_max = FAST_MAX
} Speed_ENUM;

/*----------------*/
#define MENU_MAIN 0
#define MENU_SHOW 1

extern uint8_t MenuStatus;

typedef struct
{
    uint8_t Hour;
    uint8_t Minute;
    uint8_t Second;
    uint16_t Year;
    uint8_t Month;
    uint8_t Day;
} mytime_t;

extern mytime_t myTime;
extern mytime_t myTimeTemp;

void MyTimeSecondRun(void);
void MyTimeFun(void);

/*子菜单选项*/
#define MAIN_TO_CHILD 0  /*主菜单下的子菜单*/
#define CHILD_TO_CHILD 1 /*子菜单下的子菜单*/

typedef struct child_menu
{
    char *name;                /*菜单名*/
    void (*fun)(void);         /*功能函数*/
    struct child_menu *child;  /*子菜单*/
    struct child_menu *father; /*父菜单*/
    uint8_t opt;               /*菜单选项*/
} ChildMenu;

typedef struct
{
    const unsigned char *ImageData; /*菜单图片数据*/
    char *MenuName;                 /*菜单名*/
    ChildMenu *ChildMenu;           /*子菜单*/
} MainMenu;

/*----------------*/

void ui_run(char *a, char *a_trg, int b);
void ui_right_one_Picture(int16_t *a, int b); /*图片右移1单位*/
void ui_left_one_Picture(int16_t *a, int b);  /*图片左移1单位*/
void Show_Menu(Speed_ENUM Speed_choose);      /*显示菜单*/
void Show_Menu_Config(void);                  /*主菜单初始化/刷新*/

void Show_MainPage(void);                  /*显示主页*/
void Show_MenuRE(Speed_ENUM Speed_choose); /*主页切换菜单（主函数调用此函数即可）*/

/*重写函数*/
void Menu_To_X_Display(ChildMenu *menuitem, char *Title, uint8_t Box_Flag);      /*进入子菜单动画*/
void X_To_Menu_Display(ChildMenu *menuitem, char *Title);                        /*返回上一级菜单动画*/
void Creat_Childv2_Menu(ChildMenu *menuitem, uint8_t Picture_Flag, char *Title); /*创建子菜单动画*/
#endif
