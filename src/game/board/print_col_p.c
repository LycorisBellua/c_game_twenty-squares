#include "twenty_squares.h"

static void	highlight_player(int highlight);

void	print_col_p1(int line, int player_id, t_player *players)
{
	if (line == 1)
		printf("  PLAYER ONE   ");
	else if (line == 2)
		highlight_player(player_id == 0);
	else if (line == 4)
		printf("      POINTS   ");
	else if (line == 5)
		printf("         %d     ", players[0].points);
	else if (line == 7)
		print_stone_p(players[0].stones + 0, players[0].track);
	else if (line == 8)
		print_stone_p(players[0].stones + 1, players[0].track);
	else if (line == 9)
		print_stone_p(players[0].stones + 2, players[0].track);
	else if (line == 10)
		print_stone_p(players[0].stones + 3, players[0].track);
	else if (line == 11)
		print_stone_p(players[0].stones + 4, players[0].track);
	else if (line == 12)
		print_stone_p(players[0].stones + 5, players[0].track);
	else if (line == 13)
		print_stone_p(players[0].stones + 6, players[0].track);
	else
		printf("               ");
	return ;
}

void	print_col_p2(int line, int player_id, t_player *players)
{
	if (line == 1)
		printf("   PLAYER TWO  ");
	else if (line == 2)
		highlight_player(player_id == 1);
	else if (line == 4)
		printf("   POINTS     ");
	else if (line == 5)
		printf("     %d        ", players[1].points);
	else if (line == 7)
		print_stone_p(players[1].stones + 0, players[1].track);
	else if (line == 8)
		print_stone_p(players[1].stones + 1, players[1].track);
	else if (line == 9)
		print_stone_p(players[1].stones + 2, players[1].track);
	else if (line == 10)
		print_stone_p(players[1].stones + 3, players[1].track);
	else if (line == 11)
		print_stone_p(players[1].stones + 4, players[1].track);
	else if (line == 12)
		print_stone_p(players[1].stones + 5, players[1].track);
	else if (line == 13)
		print_stone_p(players[1].stones + 6, players[1].track);
	else
		printf("               ");
	return ;
}

static void	highlight_player(int highlight)
{
	if (highlight)
		printf(" ............. ");
	else
		printf("               ");
	return ;
}
