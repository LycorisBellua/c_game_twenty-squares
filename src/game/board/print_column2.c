#include "twenty_squares.h"

void	print_column2(int line, int player_id, t_cell *cells)
{
	if (line == 0)
	{
		printf("________");
	}
	else if (line == 1 || line == 4 || line == 7 || line == 13 || line == 16
		|| line == 19 || line == 22)
	{
		printf("|       ");
	}
	else if (line == 3 || line == 6 || line == 9 || line == 15 || line == 18
		|| line == 21 || line == 24)
	{
		printf("|_______");
	}
	else if (line == 10 || line == 12)
	{
		printf("|▒▒▒▒▒▒▒");
	}
	else if (line == 2)
	{
		/* Cell Coordinate 21 */
		if (!cells[1].stone)
			printf("|       ");
		else
		{
			if (cells[1].stone->id == ID_STONE_ONE)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [1]  " : "|   1   ");
			else if (cells[1].stone->id == ID_STONE_TWO)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [2]  " : "|   2   ");
			else if (cells[1].stone->id == ID_STONE_THREE)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [3]  " : "|   3   ");
			else if (cells[1].stone->id == ID_STONE_FOUR)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [4]  " : "|   4   ");
			else if (cells[1].stone->id == ID_STONE_FIVE)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [5]  " : "|   5   ");
			else if (cells[1].stone->id == ID_STONE_SIX)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [6]  " : "|   6   ");
			else if (cells[1].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [7]  " : "|   7   ");
			else if (cells[1].stone->id == ID_STONE_LUST)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [L]  " : "|   L   ");
			else if (cells[1].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [P]  " : "|   P   ");
			else if (cells[1].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [GL] " : "|   GL  ");
			else if (cells[1].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [S]  " : "|   S   ");
			else if (cells[1].stone->id == ID_STONE_ENVY)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [E]  " : "|   E   ");
			else if (cells[1].stone->id == ID_STONE_WRATH)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [W]  " : "|   W   ");
			else if (cells[1].stone->id == ID_STONE_GREED)
				printf("%s", cells[1].stone->player_id == player_id ?
					"|  [GR] " : "|   GR  ");
		}
	}
	else if (line == 5)
	{
		/* Cell Coordinate 22 */
		if (!cells[4].stone)
			printf("|       ");
		else
		{
			if (cells[4].stone->id == ID_STONE_ONE)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [1]  " : "|   1   ");
			else if (cells[4].stone->id == ID_STONE_TWO)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [2]  " : "|   2   ");
			else if (cells[4].stone->id == ID_STONE_THREE)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [3]  " : "|   3   ");
			else if (cells[4].stone->id == ID_STONE_FOUR)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [4]  " : "|   4   ");
			else if (cells[4].stone->id == ID_STONE_FIVE)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [5]  " : "|   5   ");
			else if (cells[4].stone->id == ID_STONE_SIX)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [6]  " : "|   6   ");
			else if (cells[4].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [7]  " : "|   7   ");
			else if (cells[4].stone->id == ID_STONE_LUST)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [L]  " : "|   L   ");
			else if (cells[4].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [P]  " : "|   P   ");
			else if (cells[4].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[4].stone->player_id == player_id ?
					"  [GL] " : "|   GL  ");
			else if (cells[4].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [S]  " : "|   S   ");
			else if (cells[4].stone->id == ID_STONE_ENVY)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [E]  " : "|   E   ");
			else if (cells[4].stone->id == ID_STONE_WRATH)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [W]  " : "|   W   ");
			else if (cells[4].stone->id == ID_STONE_GREED)
				printf("%s", cells[4].stone->player_id == player_id ?
					"|  [GR] " : "|   GR  ");
		}
	}
	else if (line == 8)
	{
		/* Cell Coordinate 23 */
		if (!cells[7].stone)
			printf("|       ");
		else
		{
			if (cells[7].stone->id == ID_STONE_ONE)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [1]  " : "|   1   ");
			else if (cells[7].stone->id == ID_STONE_TWO)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [2]  " : "|   2   ");
			else if (cells[7].stone->id == ID_STONE_THREE)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [3]  " : "|   3   ");
			else if (cells[7].stone->id == ID_STONE_FOUR)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [4]  " : "|   4   ");
			else if (cells[7].stone->id == ID_STONE_FIVE)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [5]  " : "|   5   ");
			else if (cells[7].stone->id == ID_STONE_SIX)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [6]  " : "|   6   ");
			else if (cells[7].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [7]  " : "|   7   ");
			else if (cells[7].stone->id == ID_STONE_LUST)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [L]  " : "|   L   ");
			else if (cells[7].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [P]  " : "|   P   ");
			else if (cells[7].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [GL] " : "|   GL  ");
			else if (cells[7].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [S]  " : "|   S   ");
			else if (cells[7].stone->id == ID_STONE_ENVY)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [E]  " : "|   E   ");
			else if (cells[7].stone->id == ID_STONE_WRATH)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [W]  " : "|   W   ");
			else if (cells[7].stone->id == ID_STONE_GREED)
				printf("%s", cells[7].stone->player_id == player_id ?
					"|  [GR] " : "|   GR  ");
		}
	}
	else if (line == 11)
	{
		/* Cell Coordinate 24 */
		if (!cells[10].stone)
			printf("|▒▒▒▒▒▒▒");
		else
		{
			if (cells[10].stone->id == ID_STONE_ONE)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[1]▒▒" : "|▒▒ 1 ▒▒");
			else if (cells[10].stone->id == ID_STONE_TWO)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[2]▒▒" : "|▒▒ 2 ▒▒");
			else if (cells[10].stone->id == ID_STONE_THREE)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[3]▒▒" : "|▒▒ 3 ▒▒");
			else if (cells[10].stone->id == ID_STONE_FOUR)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[4]▒▒" : "|▒▒ 4 ▒▒");
			else if (cells[10].stone->id == ID_STONE_FIVE)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[5]▒▒" : "|▒▒ 5 ▒▒");
			else if (cells[10].stone->id == ID_STONE_SIX)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[6]▒▒" : "|▒▒ 6 ▒▒");
			else if (cells[10].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[7]▒▒" : "|▒▒ 7 ▒▒");
			else if (cells[10].stone->id == ID_STONE_LUST)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[L]▒▒" : "|▒▒ L ▒▒");
			else if (cells[10].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[P]▒▒" : "|▒▒ P ▒▒");
			else if (cells[10].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[GL]▒" : "|▒▒ GL ▒");
			else if (cells[10].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[S]▒▒" : "|▒▒ S ▒▒");
			else if (cells[10].stone->id == ID_STONE_ENVY)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[E]▒▒" : "|▒▒ E ▒▒");
			else if (cells[10].stone->id == ID_STONE_WRATH)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[W]▒▒" : "|▒▒ W ▒▒");
			else if (cells[10].stone->id == ID_STONE_GREED)
				printf("%s", cells[10].stone->player_id == player_id ?
					"|▒▒[GR]▒" : "|▒▒ GR ▒");
		}
	}
	else if (line == 14)
	{
		/* Cell Coordinate 25 */
		if (!cells[12].stone)
			printf("|       ");
		else
		{
			if (cells[12].stone->id == ID_STONE_ONE)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [1]  " : "|   1   ");
			else if (cells[12].stone->id == ID_STONE_TWO)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [2]  " : "|   2   ");
			else if (cells[12].stone->id == ID_STONE_THREE)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [3]  " : "|   3   ");
			else if (cells[12].stone->id == ID_STONE_FOUR)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [4]  " : "|   4   ");
			else if (cells[12].stone->id == ID_STONE_FIVE)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [5]  " : "|   5   ");
			else if (cells[12].stone->id == ID_STONE_SIX)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [6]  " : "|   6   ");
			else if (cells[12].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [7]  " : "|   7   ");
			else if (cells[12].stone->id == ID_STONE_LUST)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [L]  " : "|   L   ");
			else if (cells[12].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [P]  " : "|   P   ");
			else if (cells[12].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [GL] " : "|   GL  ");
			else if (cells[12].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [S]  " : "|   S   ");
			else if (cells[12].stone->id == ID_STONE_ENVY)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [E]  " : "|   E   ");
			else if (cells[12].stone->id == ID_STONE_WRATH)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [W]  " : "|   W   ");
			else if (cells[12].stone->id == ID_STONE_GREED)
				printf("%s", cells[12].stone->player_id == player_id ?
					"|  [GR] " : "|   GR  ");
		}
	}
	else if (line == 17)
	{
		/* Cell Coordinate 26 */
		if (!cells[13].stone)
			printf("|       ");
		else
		{
			if (cells[13].stone->id == ID_STONE_ONE)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [1]  " : "|   1   ");
			else if (cells[13].stone->id == ID_STONE_TWO)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [2]  " : "|   2   ");
			else if (cells[13].stone->id == ID_STONE_THREE)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [3]  " : "|   3   ");
			else if (cells[13].stone->id == ID_STONE_FOUR)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [4]  " : "|   4   ");
			else if (cells[13].stone->id == ID_STONE_FIVE)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [5]  " : "|   5   ");
			else if (cells[13].stone->id == ID_STONE_SIX)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [6]  " : "|   6   ");
			else if (cells[13].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [7]  " : "|   7   ");
			else if (cells[13].stone->id == ID_STONE_LUST)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [L]  " : "|   L   ");
			else if (cells[13].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [P]  " : "|   P   ");
			else if (cells[13].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [GL] " : "|   GL  ");
			else if (cells[13].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [S]  " : "|   S   ");
			else if (cells[13].stone->id == ID_STONE_ENVY)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [E]  " : "|   E   ");
			else if (cells[13].stone->id == ID_STONE_WRATH)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [W]  " : "|   W   ");
			else if (cells[13].stone->id == ID_STONE_GREED)
				printf("%s", cells[13].stone->player_id == player_id ?
					"|  [GR] " : "|   GR  ");
		}
	}
	else if (line == 20)
	{
		/* Cell Coordinate 27 */
		if (!cells[15].stone)
			printf("|       ");
		else
		{
			if (cells[15].stone->id == ID_STONE_ONE)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [1]  " : "|   1   ");
			else if (cells[15].stone->id == ID_STONE_TWO)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [2]  " : "|   2   ");
			else if (cells[15].stone->id == ID_STONE_THREE)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [3]  " : "|   3   ");
			else if (cells[15].stone->id == ID_STONE_FOUR)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [4]  " : "|   4   ");
			else if (cells[15].stone->id == ID_STONE_FIVE)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [5]  " : "|   5   ");
			else if (cells[15].stone->id == ID_STONE_SIX)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [6]  " : "|   6   ");
			else if (cells[15].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [7]  " : "|   7   ");
			else if (cells[15].stone->id == ID_STONE_LUST)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [L]  " : "|   L   ");
			else if (cells[15].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [P]  " : "|   P   ");
			else if (cells[15].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [GL] " : "|   GL  ");
			else if (cells[15].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [S]  " : "|   S   ");
			else if (cells[15].stone->id == ID_STONE_ENVY)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [E]  " : "|   E   ");
			else if (cells[15].stone->id == ID_STONE_WRATH)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [W]  " : "|   W   ");
			else if (cells[15].stone->id == ID_STONE_GREED)
				printf("%s", cells[15].stone->player_id == player_id ?
					"|  [GR] " : "|   GR  ");
		}
	}
	else if (line == 23)
	{
		/* Cell Coordinate 28 */
		if (!cells[18].stone)
			printf("|       ");
		else
		{
			if (cells[18].stone->id == ID_STONE_ONE)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [1]  " : "|   1   ");
			else if (cells[18].stone->id == ID_STONE_TWO)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [2]  " : "|   2   ");
			else if (cells[18].stone->id == ID_STONE_THREE)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [3]  " : "|   3   ");
			else if (cells[18].stone->id == ID_STONE_FOUR)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [4]  " : "|   4   ");
			else if (cells[18].stone->id == ID_STONE_FIVE)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [5]  " : "|   5   ");
			else if (cells[18].stone->id == ID_STONE_SIX)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [6]  " : "|   6   ");
			else if (cells[18].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [7]  " : "|   7   ");
			else if (cells[18].stone->id == ID_STONE_LUST)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [L]  " : "|   L   ");
			else if (cells[18].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [P]  " : "|   P   ");
			else if (cells[18].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [GL] " : "|   GL  ");
			else if (cells[18].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [S]  " : "|   S   ");
			else if (cells[18].stone->id == ID_STONE_ENVY)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [E]  " : "|   E   ");
			else if (cells[18].stone->id == ID_STONE_WRATH)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [W]  " : "|   W   ");
			else if (cells[18].stone->id == ID_STONE_GREED)
				printf("%s", cells[18].stone->player_id == player_id ?
					"|  [GR] " : "|   GR  ");
		}
	}
	return ;
}
