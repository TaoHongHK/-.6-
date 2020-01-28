#ifndef GAME_HEAD_FILE
#define GAME_HEAD_FILE

#include "snake.h"
#include "console.h"
#include <conio.h>
#include "rank.h"

#define WIDTH  50
#define HEIGHT  30
#define DEAD_INFO "WASTED"
#define LONG_LINE "------------------------------------------------------------------"

typedef enum stuff_mark 
{
	wall,
	ground,
	food,
	_snake
}Stuff_Mark;

typedef enum option
{
	move_up = 'w',
	move_right = 'd',
	move_down = 's',
	move_left = 'a',
	
	esc = 27,
	no_option = 0
}Option;

enum state
{
	gaming_state,
	restart_state,
	exit_state
}State;

typedef struct stuff {
	int pos_x;
	int pos_y;
	Stuff_Mark mark;
}Stuff;

struct game 
{
	int score;
	Stuff map[HEIGHT][WIDTH];
	Stuff *food;
};


void start_game();
void init_map(struct game* Game);
void display_map(struct game* Game);
void display_snake(struct game *Game, Snake *snake);
void display_mark(Stuff *stuff);
void grow_food(struct game*Game);
void snake_move(struct game*Game, Snake* snake, Direction direction);
void judge_move_input(struct game*Game, Snake* snake, int* input, int*last_input);
void dead();

#endif // !GAME_HEAD_FILE 

