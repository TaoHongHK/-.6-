#ifndef CONSOLE_HEAD_FILE
#define CONSOLE_HEAD_FILE

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>


void set_cursor_position(int pos_x, int pos_y);

/*0-��ɫ��1-��ɫ��2-��ɫ��3-ǳ��ɫ��4-��ɫ��5-��ɫ��6-��ɫ��7-��ɫ��8-��ɫ
	9-����ɫ��10-����ɫ��11-��ǳ��ɫ��12-����ɫ��13-����ɫ��14-����ɫ��15-����ɫ*/
void set_console_color(int fore_color, int back_color);

#endif // !CONSOLE_HEAD_FILE
