#ifndef MENU_HEAD_FILE
#define MENU_HEAD_FILE

#include "game.h"
#include <Windows.h>

#define WELCOME "SNAKE"
#define LONG_LINE "------------------------------------------------------------------"
#define CHOICE_NUM 3
#define MENU_ONE "��ʼ��Ϸ"
#define MENU_TWO "�鿴����"
#define MENU_THREE "�˳���Ϸ"


enum menu_option {
	menu_up = 'w',
	menu_down = 's',
	menu_enter = 13
};


void menu();
void show_menu();

#endif // !MENU_HEAD_FILE

