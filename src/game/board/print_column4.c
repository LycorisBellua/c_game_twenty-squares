#include "twenty_squares.h"

void	print_column4(int line, int lvl, int player_id, t_player *players)
{
	if (!line || line == 3 || line == 6 || line == 8 || line == 16
		|| ((lvl == 1 || lvl == 3) && (line >= 17 && line <= 26))
		|| (line >= 27 && line <= 41))
	{
		printf("                ");
	}
	else if (line == 1)
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
		if (players[1].points < 0)
			printf("     00       ");
		else if (players[1].points < 10)
			printf("     0%d       ", players[1].points);
		else
			printf("     %d       ", players[1].points);
	}
	else if (line == 7)
	{
		printf("   ALLIES     ");
	}
	else if (line == 9)
	{
		if (players[1].stoneset[0].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[0].coord == 1)
			printf("%s", lvl == 1 || lvl == 2 ?
				"   [Won]      " : "   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   One        " : "   Lust       ");
	}
	else if (line == 10)
	{
		if (players[1].stoneset[1].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[1].coord == 1)
			printf("%s", lvl == 1 || lvl == 2 ?
				"   [Won]      " : "   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Two        " : "   Pride      ");
	}
	else if (line == 11)
	{
		if (players[1].stoneset[2].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[2].coord == 1)
			printf("%s", lvl == 1 || lvl == 2 ?
				"   [Won]      " : "   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Three      " : "   Gluttony   ");
	}
	else if (line == 12)
	{
		if (players[1].stoneset[3].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[3].coord == 1)
			printf("%s", lvl == 1 || lvl == 2 ?
				"   [Won]      " : "   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Four       " : "   Sloth      ");
	}
	else if (line == 13)
	{
		if (players[1].stoneset[4].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[4].coord == 1)
			printf("%s", lvl == 1 || lvl == 2 ?
				"   [Won]      " : "   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Five       " :  "   Envy      ");
	}
	else if (line == 14)
	{
		if (players[1].stoneset[5].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[5].coord == 1)
			printf("%s", lvl == 1 || lvl == 2 ?
				"   [Won]      " : "   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Six        " : "   Wrath      ");
	}
	else if (line == 15)
	{
		if (players[1].stoneset[6].coord == -1)
			printf("   [Dead]     ");
		else if (players[1].stoneset[6].coord == 1)
			printf("%s", lvl == 1 || lvl == 2 ?
				"   [Won]      " : "   [Saved]    ");
		else
			printf("%s", lvl == 1 || lvl == 2 ?
				"   Seven      " : "   Greed      ");
	}
	else if (lvl == 2 || lvl == 4)
	{
		if (line == 17)
		{
			printf("   ENEMIES    ");
		}
		else if (line == 18)
		{
			printf("   KILLED     ");
		}
		else if (line == 19)
		{
			printf("%s", player_id == 1 ?
				" ............. " : "               ");
		}
		else if (line == 20)
		{
			printf("%s", players[0].stoneset[0].coord != -1 ?
				"   [Empty]     " : lvl == 2 ?
				"   One         " : "   Lust        ");
		}
		else if (line == 21)
		{
			printf("%s", players[0].stoneset[1].coord != -1 ?
				"   [Empty]     " : lvl == 2 ?
				"   Two         " : "   Pride       ");
		}
		else if (line == 22)
		{
			printf("%s", players[0].stoneset[2].coord != -1 ?
				"   [Empty]     " : lvl == 2 ?
				"   Three       " : "   Gluttony    ");
		}
		else if (line == 23)
		{
			printf("%s", players[0].stoneset[3].coord != -1 ?
				"   [Empty]     " : lvl == 2 ?
				"   Four        " : "   Sloth       ");
		}
		else if (line == 24)
		{
			printf("%s", players[0].stoneset[4].coord != -1 ?
				"   [Empty]     " : lvl == 2 ?
				"   Five        " : "   Envy        ");
		}
		else if (line == 25)
		{
			printf("%s", players[0].stoneset[5].coord != -1 ?
				"   [Empty]     " : lvl == 2 ?
				"   Six         " : "   Wrath       ");
		}
		else if (line == 26)
		{
			printf("%s", players[0].stoneset[6].coord != -1 ?
				"   [Empty]     " : lvl == 2 ?
				"   Seven       " : "   Greed       ");
		}
	}
	return ;
}
