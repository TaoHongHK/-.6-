#include "console.h"

void set_cursor_position(int pos_x, int pos_y)
{
	//移动光标
	COORD coord = { pos_x * 2, pos_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//隐藏光标
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


void set_console_color(int fore_color, int back_color)
{
	HANDLE winhandle;
	winhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(winhandle, fore_color + back_color * 0x10);
}
