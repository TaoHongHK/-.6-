#include "menu.h"


void menu()
{
	show_menu();
	int input = no_option;
	int choice = 0;
	int last_choice = 0;
	while (1)
	{
		if (_kbhit())
		{
			input = _getch();
			switch (input)
			{
			case menu_up :
				if (choice - 1 >= 0)
				{
					last_choice = choice;
					choice = choice - 1;
				}
				break;
			case menu_down:
				if (choice + 1 < CHOICE_NUM)
				{
					last_choice = choice;
					choice = choice + 1;
				}
				break;
			case menu_enter:
				system("cls");
				if (choice == 0)
				{
					start_game();
				}
				else if (choice == 1)
				{
					rank();
				}
				else if (choice == 2)
				{
					exit(0);
				}
				system("cls");
				show_menu();
				break;
			default:
				continue;
			}
			set_cursor_position(10, 6 + choice);
			printf("--->");
			set_cursor_position(10, 6 + last_choice);
			printf("     ");
		}
	}
}

void show_menu()
{
	set_console_color(3, 0);
	set_cursor_position(0, 0);
	printf("%s", LONG_LINE);
	set_cursor_position(15, 1);
	printf("%s", WELCOME);
	set_cursor_position(0, 2);
	printf("%s", LONG_LINE);
	set_console_color(8, 0);
	set_cursor_position(15, 6);
	printf("%s", MENU_ONE);
	set_cursor_position(15, 7);
	printf("%s", MENU_TWO);
	set_cursor_position(15, 8);
	printf("%s", MENU_THREE);
	set_cursor_position(10, 6);
	printf("--->");
}
