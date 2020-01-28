#ifndef MENU_HEAD_FILE
#define MENU_HEAD_FILE

#include "game.h"
#include <Windows.h>

#define WELCOME "SNAKE"
#define LONG_LINE "------------------------------------------------------------------"
#define CHOICE_NUM 3
#define MENU_ONE "开始游戏"
#define MENU_TWO "查看排名"
#define MENU_THREE "退出游戏"


enum menu_option {
	menu_up = 'w',
	menu_down = 's',
	menu_enter = 13
};


void menu();
void show_menu();

#endif // !MENU_HEAD_FILE

