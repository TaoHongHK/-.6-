#ifndef GAME_HEAD_FILE
#define GAME_HEAD_FILE

#include "snake.h"
#include "console.h"

#define WIDTH  50
#define HEIGHT  30

#define WELCOME "SNAKE"
#define DEAD_INFO "WASTED"
#define RANKING "RANKING"
#define LONG_LINE "------------------------------------------------------------------"
#define CHOICE_NUM 3
#define MENU_ONE "开始游戏"
#define MENU_TWO "查看排名"
#define MENU_THREE "退出游戏"
#define RANK_NUM 10

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
	enter = 13,
	no_option = 0
}Option;

enum state {
	in_menu,
	gaming,
	_check_ranking,
	snake_dead,
	to_quit	
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
void menu();
void show_menu();
void save_score(int score, char* player);
void rank();
int if_can_rank(int score);
void add_to_ranking(int score);
void load_ranking();
void dead();

#endif // !GAME_HEAD_FILE 

