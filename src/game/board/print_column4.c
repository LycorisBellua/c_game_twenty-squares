#include "twenty_squares.h"

void	print_column4(int line, int lvl, int player_id, t_player *players)
{
	if (line == 1)
	{
		printf("   PLAYER TWO  ");
	}
	else if (line == 2)
	{
		printf("%s", player_id == 1 ?
			" ............. " : "               ");
	}
	else if (line == 4)
	{
		printf("   POINTS     ");
	}
	else if (line == 5)
	{
		printf("     %d        ", players[1].points);
	}
	else if (line == 7)
	{
		if (players[1].stoneset[0].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[0].coord == 1)
			printf("   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   One        " : "   Lust       ");
	}
	else if (line == 8)
	{
		if (players[1].stoneset[1].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[1].coord == 1)
			printf("   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Two        " : "   Pride      ");
	}
	else if (line == 9)
	{
		if (players[1].stoneset[2].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[2].coord == 1)
			printf("   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Three      " : "   Gluttony   ");
	}
	else if (line == 10)
	{
		if (players[1].stoneset[3].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[3].coord == 1)
			printf("   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Four       " : "   Sloth      ");
	}
	else if (line == 11)
	{
		if (players[1].stoneset[4].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[4].coord == 1)
			printf("   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Five       " :  "   Envy      ");
	}
	else if (line == 12)
	{
		if (players[1].stoneset[5].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[5].coord == 1)
			printf("   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Six        " : "   Wrath      ");
	}
	else if (line == 13)
	{
		if (players[1].stoneset[6].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[6].coord == 1)
			printf("   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Seven      " : "   Greed      ");
	}
	else
		printf("               ");
	return ;
}
