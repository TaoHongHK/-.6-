#ifndef SNAKE_HEAD_FILE
#define SNAKE_HEAD_FILE

#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <Windows.h>

typedef enum direction {
	up,
	right,
	down,
	left
}Direction;

typedef enum speed {
	slow,
	normal,
	fast,
}Speed;

//»·×´Ë«ÏòÁ´±í
typedef struct snake_body_node 
{
	int pos_x;
	int pos_y;
	Direction dir;
	struct snake_body_node *previous_node;
	struct snake_body_node *next_node;
}Snake_Body_Node;

typedef struct snake
{
	int length;
	Speed speed;
	Snake_Body_Node *head;
}Snake;

Snake *new_born_snake(int pos_x, int pos_y);
void add_head_node(Snake* snake, int pos_x, int pos_y);
void remove_tail_node(Snake* snake);
void destroy_snake(Snake* snake);
Snake_Body_Node* mknode();
void move(Snake* snake, Direction dir);

#endif // !SNAKE_HEAD_FILE
