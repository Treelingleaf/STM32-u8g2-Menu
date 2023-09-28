#ifndef __MENU_H
#define __MENU_H

#include "stm32f10x.h"

#define LOW_SPEED 1
#define MID_SPEED 3
#define HIGH_SPEED 4
#define FAST_SPEED 6
#define SO_FAST_SPEED 8

typedef enum
{
    low_speed = LOW_SPEED,
    mid_speed = MID_SPEED,
    high_speed = HIGH_SPEED,
    fast_speed = FAST_SPEED,
    so_fast_speed = SO_FAST_SPEED
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
#define MAIN_TO_CHILD 0 /*主菜单下的子菜单*/
#define CHILD_TOCHILD 1 /*子菜单下的子菜单*/

typedef struct child_menu
{
    char *name; /*菜单名*/
    void (*fun)(void);
    struct child_menu *child;
    uint8_t opt; /*子菜单选项*/
} ChildMenu;

typedef struct
{
    uint8_t LocaFlag;
    const unsigned char *ImageData;
    char *MenuName;
    ChildMenu *ChildMenu;
} MainMenu;

/*----------------*/

void ui_run(char *a, char *a_trg, int b);
void ui_right_one_Picture(int16_t *a, int b);
void ui_left_one_Picture(int16_t *a, int b);
void Show_Menu(Speed_ENUM Speed_choose);
void Show_Menu_Config(void);

void Show_MainPage(void);
void Show_MenuRE(Speed_ENUM Speed_choose);

/**/
void Menu_To_X_Display(ChildMenu *menuitem);
void X_To_Menu_Display(ChildMenu *menuitem);
void Creat_Childv2_Menu(ChildMenu *menuitem, uint8_t Picture_Flag, char *Title);
#endif
