#include "twenty_squares.h"

void	print_column0(int line, int level, int current_player_id,
			Player *players)
{
	if (!line || line == 3 || line == 6 || line == 8 || line == 16
		|| ((level == 1 || level == 3) && (line >= 17 && line <= 26))
		|| (line >= 27 && line <= 41))
	{
		printf("               ");
	}
	else if (line == 1)
	{
		printf("  PLAYER ONE   ");
	}
	else if (line == 2)
	{
		printf("%s", !current_player_id ?
			" ............. " : "               ");
	}
	else if (line == 4)
	{
		printf("      POINTS   ");
	}
	else if (line == 5)
	{
		if (PLAYER_ONE->points < 0)
			printf("        00     ");
		else if (PLAYER_ONE->points < 10)
			printf("        0%d     ", PLAYER_ONE->points);
		else
			printf("        %d     ", PLAYER_ONE->points);
	}
	else if (line == 7)
	{
		printf("      ALLIES   ");
	}
	else if (line == 9)
	{
		if (PLAYER_ONE->stoneset[0].coordinate == -1)
			printf("      [Dead]   ");
		else if (PLAYER_ONE->stoneset[0].coordinate == 1)
			printf("%s", level == 1 || level == 2 ?
				"       [Won]   " : "     [Saved]   ");
		else
			printf("%s", level == 1 || level == 2 ?
				"         One   " : "        Lust   ");
	}
	else if (line == 10)
	{
		if (PLAYER_ONE->stoneset[1].coordinate == -1)
			printf("      [Dead]   ");
		else if (PLAYER_ONE->stoneset[1].coordinate == 1)
			printf("%s", level == 1 || level == 2 ?
				"       [Won]   " : "     [Saved]   ");
		else
			printf("%s", level == 1 || level == 2 ?
				"         Two   " : "       Pride   ");
	}
	else if (line == 11)
	{
		if (PLAYER_ONE->stoneset[2].coordinate == -1)
			printf("      [Dead]   ");
		else if (PLAYER_ONE->stoneset[2].coordinate == 1)
			printf("%s", level == 1 || level == 2 ?
				"       [Won]   " : "     [Saved]   ");
		else
			printf("%s", level == 1 || level == 2 ?
				"       Three   " : "    Gluttony   ");
	}
	else if (line == 12)
	{
		if (PLAYER_ONE->stoneset[3].coordinate == -1)
			printf("      [Dead]   ");
		else if (PLAYER_ONE->stoneset[3].coordinate == 1)
			printf("%s", level == 1 || level == 2 ?
				"       [Won]   " : "     [Saved]   ");
		else
			printf("%s", level == 1 || level == 2 ?
				"        Four   " : "       Sloth   ");
	}
	else if (line == 13)
	{
		if (PLAYER_ONE->stoneset[4].coordinate == -1)
			printf("      [Dead]   ");
		else if (PLAYER_ONE->stoneset[4].coordinate == 1)
			printf("%s", level == 1 || level == 2 ?
				"       [Won]   " : "     [Saved]   ");
		else
			printf("%s", level == 1 || level == 2 ?
				"        Five   " : "        Envy   ");
	}
	else if (line == 14)
	{
		if (PLAYER_ONE->stoneset[5].coordinate == -1)
			printf("      [Dead]   ");
		else if (PLAYER_ONE->stoneset[5].coordinate == 1)
			printf("%s", level == 1 || level == 2 ?
				"       [Won]   " : "     [Saved]   ");
		else
			printf("%s", level == 1 || level == 2 ?
				"         Six   " : "       Wrath   ");
	}
	else if (line == 15)
	{
		if (PLAYER_ONE->stoneset[6].coordinate == -1)
			printf("      [Dead]   ");
		else if (PLAYER_ONE->stoneset[6].coordinate == 1)
			printf("%s", level == 1 || level == 2 ?
				"       [Won]   " : "     [Saved]   ");
		else
			printf("%s", level == 1 || level == 2 ?
				"       Seven   " : "       Greed   ");
	}
	else if (level == 2 || level == 4)
	{
		if (line == 17)
		{
			printf("     ENEMIES   ");
		}
		else if (line == 18)
		{
			printf("      KILLED   ");
		}
		else if (line == 19)
		{
			printf("%s", !current_player_id ?
				" ............. " : "               ");
		}
		else if (line == 20)
		{
			printf("%s", PLAYER_TWO->stoneset[0].coordinate != -1 ?
				"     [Empty]   " : level == 2 ?
				"         One   " : "        Lust   ");
		}
		else if (line == 21)
		{
			printf("%s", PLAYER_TWO->stoneset[1].coordinate != -1 ?
				"     [Empty]   " : level == 2 ?
				"         Two   " : "       Pride   ");
		}
		else if (line == 22)
		{
			printf("%s", PLAYER_TWO->stoneset[2].coordinate != -1 ?
				"     [Empty]   " : level == 2 ?
				"       Three   " : "    Gluttony   ");
		}
		else if (line == 23)
		{
			printf("%s", PLAYER_TWO->stoneset[3].coordinate != -1 ?
				"     [Empty]   " : level == 2 ?
				"        Four   " : "       Sloth   ");
		}
		else if (line == 24)
		{
			printf("%s", PLAYER_TWO->stoneset[4].coordinate != -1 ?
				"     [Empty]   " : level == 2 ?
				"        Five   " : "        Envy   ");
		}
		else if (line == 25)
		{
			printf("%s", PLAYER_TWO->stoneset[5].coordinate != -1 ?
				"     [Empty]   " : level == 2 ?
				"         Six   " : "       Wrath   ");
		}
		else if (line == 26)
		{
			printf("%s", PLAYER_TWO->stoneset[6].coordinate != -1 ?
				"     [Empty]   " : level == 2 ?
				"       Seven   " : "       Greed   ");
		}
	}
	return;
}
