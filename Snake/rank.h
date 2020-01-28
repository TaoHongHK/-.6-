#ifndef RANK_HEAD_FILE
#define RANK_HEAD_FILE

#include <stdio.h>

#define RANK_NUM 10
#define RANKING "RANKING"
#define LONG_LINE "------------------------------------------------------------------"

void save_score(int score, char* player);
void rank();
int if_can_rank(int score);
void add_to_ranking(int score);
void load_ranking();

#endif // !RANK_HEAD_FILE

