#ifndef __MENU_H
#define __MENU_H

#include "stm32f10x.h"

#define LOW_SPEED 1
#define MID_SPEED 3
#define HIGH_SPEED 4
#define FAST_SPEED 8
#define SO_FAST_SPEED 8

typedef enum
{
	low_speed = LOW_SPEED,
	mid_speed = MID_SPEED,
	high_speed = HIGH_SPEED,
	fast_speed = FAST_SPEED,
	so_fast_speed = SO_FAST_SPEED
} Speed_ENUM;

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

void ui_run(char *a, char *a_trg, int b);
void ui_right_one_Picture(int16_t *a, int b);
void ui_left_one_Picture(int16_t *a, int b);
void Show_Menu(Speed_ENUM Speed_choose);
void Game_Menu(void);
void Show_Menu_Config(void);

void To_Game_Menu_Display(void);
void Game_To_Menu_Display(void);

#endif
