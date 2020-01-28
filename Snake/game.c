#include "game.h"

void start_game() 
{
	struct game *Game = (struct game*)malloc(sizeof(struct game));
	Snake *snake = new_born_snake(5, 5);
	Game->score = 0;
	init_map(Game);
	display_map(Game);
	display_snake(Game, snake);
	grow_food(Game);
	int input = no_option;
	int last_input = no_option;
	State = gaming_state;
	while (State == gaming_state)
	{
		if (_kbhit())
		{
			input = _getch();
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		}
		else input = no_option;
		switch (input)
		{
		case move_up:
		case move_right:
		case move_down:
		case move_left:
			judge_move_input(Game, snake, &input, &last_input);
			break;
		case esc:
			State = exit_state;
			break;
		case no_option:
		default:
			snake_move(Game, snake, snake->head->dir);
			break;
		}
	}
	free(Game);
	if (State == restart_state)
	{
		start_game();
	}
}

void judge_move_input(struct game*Game, Snake* snake, int* input, int* last_input)
{
	if (*last_input + *input == move_down + move_up ||
		*last_input + *input == move_left + move_right)
	{
		snake_move(Game, snake, snake->head->dir);
		return;
	}
	else if (*last_input == *input)
	{
		snake->speed = fast;
	}
	else
	{
		snake->speed = normal;
		*last_input = *input;
	}
	Direction dir = *input == move_up ? up : *input == move_down ?
		down : *input == move_left ? left : right;
	snake_move(Game, snake, dir);
}

void display_map(struct game*Game)
{
	for (int i = 0; i < WIDTH; i++) 
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			display_mark(&(Game->map[j][i]));
		}
	}
}

void display_snake(struct game*Game, Snake *snake) 
{
	Snake_Body_Node *head = snake->head;
	Stuff *stuff;
	while (head->next_node != head)
	{
		stuff = &Game->map[head->pos_y][head->pos_x];
		stuff->mark = _snake;
		display_mark(stuff);
	}
	stuff = &Game->map[head->pos_y][head->pos_x];
	stuff->mark = _snake;
	display_mark(stuff);
}

void grow_food(struct game* Game)
{
	int pos_x = rand() % WIDTH;
	int pos_y = rand() % HEIGHT;
	Stuff *stuff = &Game->map[pos_y][pos_x];
	stuff->mark = food;
	Game->food = stuff;
	display_mark(stuff);
}

void snake_move(struct game*Game, Snake* snake, Direction dir) 
{
	Stuff *stuff;
	int pos_x = snake->head->pos_x;
	int pos_y = snake->head->pos_y;
	pos_x = dir == left ? pos_x - 1 : dir == right ? pos_x + 1 : pos_x;
	pos_y = dir == up ? pos_y - 1 : dir == down ? pos_y + 1 : pos_y;
	switch (Game->map[pos_y][pos_x].mark)
	{
	case ground:
		stuff = &Game->map[pos_y][pos_x];
		stuff->mark = _snake;
		display_mark(stuff);
		stuff = &Game->
			map[snake->head->previous_node->pos_y][snake->head->previous_node->pos_x];
		stuff->mark = ground;
		display_mark(stuff);
		move(snake, dir, pos_x, pos_y);
		break;
	case food:
		stuff = &Game->map[pos_y][pos_x];
		stuff->mark = _snake;
		display_mark(stuff);
		eat(snake, dir, pos_x, pos_y);
		grow_food(Game);
		Game->score++;
		break;
	case _snake:
	case wall:
		if (if_can_rank(Game->score))
		{
			system("cls");
			add_to_ranking(Game->score);
			State = restart_state;
		}
		else dead();
		break;
	default:
		break;
	}
}

void dead()
{
	set_console_color(4, 0);
	set_cursor_position(WIDTH / 2 - 15, HEIGHT / 2 - 1);
	printf("%s", LONG_LINE);
	set_cursor_position(WIDTH / 2, HEIGHT / 2);
	printf("%s", DEAD_INFO);
	set_cursor_position(WIDTH / 2 - 15, HEIGHT / 2 + 1);
	printf("%s", LONG_LINE);
	while (1)
	{
		if (_kbhit())
		{
			State = restart_state;
			break;
		}
			
	}
}

void display_mark(Stuff *stuff)
{
	set_cursor_position(stuff->pos_x, stuff->pos_y);
	switch (stuff->mark)
	{
	case wall:
		set_console_color(6, 0);
		printf("##");
		break;
	case ground:
		set_console_color(7, 0);
		printf("  ");
		break;
	case food:
		set_console_color(4, 0);
		printf("@");
		break;
	case _snake:
		set_console_color(2, 0);
		printf("■");
		break;
	default:
		break;
	}
}

void init_map(struct game* Game)
{
	for (int i = 0; i < WIDTH; i++) 
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			Game->map[j][i].pos_x = i;
			Game->map[j][i].pos_y = j;
			if (j == 0 || j == HEIGHT-1 || i==0 || i==WIDTH-1)
			{
				Game->map[j][i].mark = wall;
			}
			else Game->map[j][i].mark = ground;
		}
	 }
}

