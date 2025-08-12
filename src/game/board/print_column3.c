#include "twenty_squares.h"

void	print_column3(int line, int player_id, t_cell *cells)
{
	if (line == 0)
	{
		printf("________");
	}
	else if (line == 1 || line == 3 || line == 19 || line == 21)
	{
		printf("|▒▒▒▒▒▒▒|");
	}
	else if (line == 4 || line == 7 || line == 10 || line == 22)
	{
		printf("|       |");
	}
	else if (line == 6 || line == 9 || line == 12 || line == 24)
	{
		printf("|_______|");
	}
	else if (line >= 13 && line <= 17)
	{
		printf("|        ");
	}
	else if (line == 18)
	{
		printf("|_______ ");
	}
	else if (line == 2)
	{
		/* Cell Coordinate 31 */
		if (!cells[2].stone)
			printf("|▒▒▒▒▒▒▒|");
		else
		{
			if (cells[2].stone->id == ID_STONE_ONE)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[1]▒▒|" : "|▒▒ 1 ▒▒|");
			else if (cells[2].stone->id == ID_STONE_TWO)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[2]▒▒|" : "|▒▒ 2 ▒▒|");
			else if (cells[2].stone->id == ID_STONE_THREE)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[3]▒▒|" : "|▒▒ 3 ▒▒|");
			else if (cells[2].stone->id == ID_STONE_FOUR)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[4]▒▒|" : "|▒▒ 4 ▒▒|");
			else if (cells[2].stone->id == ID_STONE_FIVE)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[5]▒▒|" : "|▒▒ 5 ▒▒|");
			else if (cells[2].stone->id == ID_STONE_SIX)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[6]▒▒|" : "|▒▒ 6 ▒▒|");
			else if (cells[2].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[7]▒▒|" : "|▒▒ 7 ▒▒|");
			else if (cells[2].stone->id == ID_STONE_LUST)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[L]▒▒|" : "|▒▒ L ▒▒|");
			else if (cells[2].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[P]▒▒|" : "|▒▒ P ▒▒|");
			else if (cells[2].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒[GL]▒▒|" : "|▒ GL ▒▒|");
			else if (cells[2].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[S]▒▒|" : "|▒▒ S ▒▒|");
			else if (cells[2].stone->id == ID_STONE_ENVY)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[E]▒▒|" : "|▒▒ E ▒▒|");
			else if (cells[2].stone->id == ID_STONE_WRATH)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒▒[W]▒▒|" : "|▒▒ W ▒▒|");
			else if (cells[2].stone->id == ID_STONE_GREED)
				printf("%s", cells[2].stone->player_id == player_id ?
					"|▒[GR]▒▒|" : "|▒ GR ▒▒|");
		}
	}
	else if (line == 5)
	{
		/* Cell Coordinate 32 */
		if (!cells[5].stone)
			printf("|       |");
		else
		{
			if (cells[5].stone->id == ID_STONE_ONE)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [1]  |" : "|   1   |");
			else if (cells[5].stone->id == ID_STONE_TWO)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [2]  |" : "|   2   |");
			else if (cells[5].stone->id == ID_STONE_THREE)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [3]  |" : "|   3   |");
			else if (cells[5].stone->id == ID_STONE_FOUR)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [4]  |" : "|   4   |");
			else if (cells[5].stone->id == ID_STONE_FIVE)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [5]  |" : "|   5   |");
			else if (cells[5].stone->id == ID_STONE_SIX)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [6]  |" : "|   6   |");
			else if (cells[5].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [7]  |" : "|   7   |");
			else if (cells[5].stone->id == ID_STONE_LUST)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [L]  |" : "|   L   |");
			else if (cells[5].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [P]  |" : "|   P   |");
			else if (cells[5].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[5].stone->player_id == player_id ?
					"| [GL]  |" : "|  GL   |");
			else if (cells[5].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [S]  |" : "|   S   |");
			else if (cells[5].stone->id == ID_STONE_ENVY)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [E]  |" : "|   E   |");
			else if (cells[5].stone->id == ID_STONE_WRATH)
				printf("%s", cells[5].stone->player_id == player_id ?
					"|  [W]  |" : "|   W   |");
			else if (cells[5].stone->id == ID_STONE_GREED)
				printf("%s", cells[5].stone->player_id == player_id ?
					"| [GR]  |" : "|  GR   |");
		}
	}
	else if (line == 8)
	{
		/* Cell Coordinate 33 */
		if (!cells[8].stone)
			printf("|       |");
		else
		{
			if (cells[8].stone->id == ID_STONE_ONE)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [1]  |" : "|   1   |");
			else if (cells[8].stone->id == ID_STONE_TWO)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [2]  |" : "|   2   |");
			else if (cells[8].stone->id == ID_STONE_THREE)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [3]  |" : "|   3   |");
			else if (cells[8].stone->id == ID_STONE_FOUR)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [4]  |" : "|   4   |");
			else if (cells[8].stone->id == ID_STONE_FIVE)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [5]  |" : "|   5   |");
			else if (cells[8].stone->id == ID_STONE_SIX)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [6]  |" : "|   6   |");
			else if (cells[8].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [7]  |" : "|   7   |");
			else if (cells[8].stone->id == ID_STONE_LUST)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [L]  |" : "|   L   |");
			else if (cells[8].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [P]  |" : "|   P   |");
			else if (cells[8].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[8].stone->player_id == player_id ?
					"| [GL]  |" : "|  GL   |");
			else if (cells[8].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [S]  |" : "|   S   |");
			else if (cells[8].stone->id == ID_STONE_ENVY)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [E]  |" : "|   E   |");
			else if (cells[8].stone->id == ID_STONE_WRATH)
				printf("%s", cells[8].stone->player_id == player_id ?
					"|  [W]  |" : "|   W   |");
			else if (cells[8].stone->id == ID_STONE_GREED)
				printf("%s", cells[8].stone->player_id == player_id ?
					"| [GR]  |" : "|  GR   |");
		}
	}
	else if (line == 11)
	{
		/* Cell Coordinate 34 */
		if (!cells[11].stone)
			printf("|       |");
		else
		{
			if (cells[11].stone->id == ID_STONE_ONE)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [1]  |" : "|   1   |");
			else if (cells[11].stone->id == ID_STONE_TWO)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [2]  |" : "|   2   |");
			else if (cells[11].stone->id == ID_STONE_THREE)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [3]  |" : "|   3   |");
			else if (cells[11].stone->id == ID_STONE_FOUR)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [4]  |" : "|   4   |");
			else if (cells[11].stone->id == ID_STONE_FIVE)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [5]  |" : "|   5   |");
			else if (cells[11].stone->id == ID_STONE_SIX)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [6]  |" : "|   6   |");
			else if (cells[11].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [7]  |" : "|   7   |");
			else if (cells[11].stone->id == ID_STONE_LUST)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [L]  |" : "|   L   |");
			else if (cells[11].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [P]  |" : "|   P   |");
			else if (cells[11].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[11].stone->player_id == player_id ?
					"| [GL]  |" : "|  GL   |");
			else if (cells[11].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [S]  |" : "|   S   |");
			else if (cells[11].stone->id == ID_STONE_ENVY)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [E]  |" : "|   E   |");
			else if (cells[11].stone->id == ID_STONE_WRATH)
				printf("%s", cells[11].stone->player_id == player_id ?
					"|  [W]  |" : "|   W   |");
			else if (cells[11].stone->id == ID_STONE_GREED)
				printf("%s", cells[11].stone->player_id == player_id ?
					"| [GR]  |" : "|  GR   |");
		}
	}
	else if (line == 20)
	{
		/* Cell Coordinate 37 */
		if (!cells[16].stone)
			printf("|▒▒▒▒▒▒▒|");
		else
		{
			if (cells[16].stone->id == ID_STONE_ONE)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[1]▒▒|" : "|▒▒ 1 ▒▒|");
			else if (cells[16].stone->id == ID_STONE_TWO)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[2]▒▒|" : "|▒▒ 2 ▒▒|");
			else if (cells[16].stone->id == ID_STONE_THREE)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[3]▒▒|" : "|▒▒ 3 ▒▒|");
			else if (cells[16].stone->id == ID_STONE_FOUR)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[4]▒▒|" : "|▒▒ 4 ▒▒|");
			else if (cells[16].stone->id == ID_STONE_FIVE)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[5]▒▒|" : "|▒▒ 5 ▒▒|");
			else if (cells[16].stone->id == ID_STONE_SIX)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[6]▒▒|" : "|▒▒ 6 ▒▒|");
			else if (cells[16].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[7]▒▒|" : "|▒▒ 7 ▒▒|");
			else if (cells[16].stone->id == ID_STONE_LUST)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[L]▒▒|" : "|▒▒ L ▒▒|");
			else if (cells[16].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[P]▒▒|" : "|▒▒ P ▒▒|");
			else if (cells[16].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒[GL]▒▒|" : "|▒ GL ▒▒|");
			else if (cells[16].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[S]▒▒|" : "|▒▒ S ▒▒|");
			else if (cells[16].stone->id == ID_STONE_ENVY)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[E]▒▒|" : "|▒▒ E ▒▒|");
			else if (cells[16].stone->id == ID_STONE_WRATH)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒▒[W]▒▒|" : "|▒▒ W ▒▒|");
			else if (cells[16].stone->id == ID_STONE_GREED)
				printf("%s", cells[16].stone->player_id == player_id ?
					"|▒[GR]▒▒|" : "|▒ GR ▒▒|");
		}
	}
	else if (line == 23)
	{
		/* Cell Coordinate 38 */
		if (!cells[19].stone)
			printf("|       |");
		else
		{
			if (cells[19].stone->id == ID_STONE_ONE)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [1]  |" : "|   1   |");
			else if (cells[19].stone->id == ID_STONE_TWO)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [2]  |" : "|   2   |");
			else if (cells[19].stone->id == ID_STONE_THREE)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [3]  |" : "|   3   |");
			else if (cells[19].stone->id == ID_STONE_FOUR)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [4]  |" : "|   4   |");
			else if (cells[19].stone->id == ID_STONE_FIVE)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [5]  |" : "|   5   |");
			else if (cells[19].stone->id == ID_STONE_SIX)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [6]  |" : "|   6   |");
			else if (cells[19].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [7]  |" : "|   7   |");
			else if (cells[19].stone->id == ID_STONE_LUST)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [L]  |" : "|   L   |");
			else if (cells[19].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [P]  |" : "|   P   |");
			else if (cells[19].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[19].stone->player_id == player_id ?
					"| [GL]  |" : "|  GL   |");
			else if (cells[19].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [S]  |" : "|   S   |");
			else if (cells[19].stone->id == ID_STONE_ENVY)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [E]  |" : "|   E   |");
			else if (cells[19].stone->id == ID_STONE_WRATH)
				printf("%s", cells[19].stone->player_id == player_id ?
					"|  [W]  |" : "|   W   |");
			else if (cells[19].stone->id == ID_STONE_GREED)
				printf("%s", cells[19].stone->player_id == player_id ?
					"| [GR]  |" : "|  GR   |");
		}
	}
	return ;
}
