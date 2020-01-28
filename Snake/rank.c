#include "rank.h"

void save_score(int score, char* player)
{
	FILE *fp = NULL;
	if (fopen_s(&fp, "./rank.txt", "r+"))
		return;
	char each_info[15], new_player[15];
	int scores[RANK_NUM];
	char names[RANK_NUM][15];
	for (int i = 0; i < RANK_NUM * 2 && fgets(each_info, 15, fp) != NULL; i++)
	{
		if (!(i & 1))
			scores[i / 2] = atoi(each_info);
		else strcpy_s(*(names + i / 2), 15, each_info);
	}
	for (int i = 0; i < RANK_NUM; i++)
	{
		if (score > scores[i])
		{
			for (int j = RANK_NUM - 1; j > i; j--)
			{
				scores[j] = scores[j - 1];
				strcpy_s(*(names + j), 15, *(names + j - 1));
			}
			scores[i] = score;
			strcpy_s(new_player, 15, player);
			strcat_s(new_player, 15, "\n");
			strcpy_s(*(names + i), 15, new_player);
			break;
		}
	}
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i < RANK_NUM; i++)
	{
		fprintf_s(fp, "%d\n%s", scores[i], *(names + i));
	}
	fclose(fp);
}

void add_to_ranking(int score)
{
	set_console_color(3, 0);
	set_cursor_position(0, 0);
	printf("%s", LONG_LINE);
	set_cursor_position(15, 1);
	printf("Your Score: %d", score);
	set_cursor_position(0, 2);
	printf("%s", LONG_LINE);
	char player[10];
	set_cursor_position(10, 3);
	printf("Press 's' To Rank, 'esc' To exit");
	while (1)
	{
		if (_kbhit())
		{
			int input = _getch();
			if (input == 's')
			{
				set_cursor_position(10, 4);
				printf("Enter Your Name: ");
				scanf_s("%s", &player, 10);
				save_score(score, player);
				break;
			}
			else if (input == 27) break;
		}
	}
}

int if_can_rank(int score)
{
	FILE *fp;
	if (fopen_s(&fp, "./rank.txt", "r"))
		return 0;
	char each_info[15];
	int scores[RANK_NUM];
	for (int i = 0; i < RANK_NUM * 2; i++)
	{
		fgets(each_info, 15, fp);
		if (!(i & 1))
		{
			scores[i / 2] = atoi(each_info);
		}
	}
	fclose(fp);
	return score >= scores[RANK_NUM - 1];
}

void load_ranking()
{
	FILE *fp;
	if (fopen_s(&fp, "./rank.txt", "r"))
		return;
	char each_info[15];
	while (fgets(each_info, 15, fp))
	{
		printf("score:");
		printf("%20s", each_info);
		fgets(each_info, 15, fp);
		printf("player:");
		printf("%20s", each_info);
	}
	fclose(fp);
}

void rank()
{
	set_console_color(3, 0);
	set_cursor_position(0, 0);
	printf("%s", LONG_LINE);
	set_cursor_position(15, 1);
	printf("%s", RANKING);
	set_cursor_position(0, 2);
	printf("%s\n", LONG_LINE);
	load_ranking();
	while (1)
	{
		if (_kbhit())
			break;
	}
}