#include "snake.h"

struct  snake * new_born_snake(int pos_x, int pos_y) 
{
	Snake* new_snake = (Snake*)malloc(sizeof(Snake));
	Snake_Body_Node *head = mknode();
	new_snake->length = 1;
	new_snake->speed = normal;
	head->dir = up;
	head->pos_x = pos_x;
	head->pos_y = pos_y;
	new_snake->head = head;
	head->next_node = head;
	head->previous_node = head;
	return new_snake;
}

void add_head_node(Snake* snake, int pos_x, int pos_y) 
{
	Snake_Body_Node *head = snake->head;
	Snake_Body_Node *body = mknode();
	body->pos_x = pos_x;
	body->pos_y = pos_y;
	body->dir = head->dir;
	if (head->next_node == head)
	{
		body->previous_node = head;
		head->next_node = body;
	}
	else
	{
		body->previous_node = head->previous_node;
		head->previous_node->next_node = body;

	}
	head->previous_node = body;
	body->next_node = head;
	snake->head = body;
	snake->length++;
}

void remove_tail_node(Snake* snake)
{
	Snake_Body_Node *head = snake->head;
	Snake_Body_Node *tail = head->previous_node;
	head->previous_node = tail->previous_node;
	tail->previous_node->next_node = head;
	free(tail);
	snake->length--;
}

void destroy_snake(Snake* snake)
{
	Snake_Body_Node* head = snake->head;
	while (head != head->next_node) {
		free(head);
		head = head->next_node;
	}
	free(head);
	free(snake);
}

Snake_Body_Node* mknode()
{
	Snake_Body_Node* node = (Snake_Body_Node*)malloc(sizeof(Snake_Body_Node));
	if (node == NULL)
	{
		printf("out of memory");
		exit(1);
	}
	return node;
}

void move(Snake* snake,  Direction dir) {
	Snake_Body_Node * head = snake->head;
	int pos_x = head->pos_x;
	int pos_y = head->pos_y;
	Sleep(700 - snake->speed * 200);
	switch (dir)
	{
	case up:
		snake->head->dir = up;
		add_head_node(snake, pos_x, pos_y - 1);
		remove_tail_node(snake);
		break;
	case right:
		snake->head->dir = right;
		add_head_node(snake, pos_x + 1, pos_y);
		remove_tail_node(snake);
		break;
	case down:
		snake->head->dir = down;
		add_head_node(snake, pos_x, pos_y + 1);
		remove_tail_node(snake);
		break;
	case left:
		snake->head->dir = left;
		add_head_node(snake, pos_x - 1, pos_y);
		remove_tail_node(snake);
		break;
	default:
		break;
	}
}