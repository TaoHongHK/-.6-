#ifndef CONSOLE_HEAD_FILE
#define CONSOLE_HEAD_FILE


#include <Windows.h>
#include <conio.h>
#include <stdlib.h>


void set_cursor_position(int pos_x, int pos_y);

/*0-黑色，1-蓝色，2-绿色，3-浅绿色，4-红色，5-紫色，6-黄色，7-白色，8-灰色
	9-淡蓝色，10-淡绿色，11-但浅绿色，12-淡红色，13-淡紫色，14-淡黄色，15-亮白色*/
void set_console_color(int fore_color, int back_color);

#endif // !CONSOLE_HEAD_FILE
