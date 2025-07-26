#include "twenty_squares.h"

void	print_column1(int line, int player_id, t_cell *cells)
{
	if (!line || line == 30)
	{
		printf(" _______________");
	}
	else if (line == 1 || line == 2 || line == 4 || line == 5 || line == 31
		|| line == 32 || line == 34 || line == 35)
	{
		printf("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	}
	else if (line == 6 || line == 7 || line == 9 || line == 11 || line == 12
		|| line == 14 || line == 16 || line == 17 || line == 19 || line == 36
		|| line == 37 || line == 39)
	{
		printf("|               ");
	}
	else if (line == 10 || line == 15 || line == 20 || line == 40)
	{
		printf("|_______________");
	}
	else if ((line >= 21 && line <= 29) || line == 41)
	{
		printf("                ");
	}
	else if (line == 3)
	{
		/* Cell Coordinate 11 */
		if (!cells[0].stone)
			printf("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		else
		{
			if (cells[0].stone->id == ID_STONE_ONE)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[01]▒▒▒▒▒" : "|▒▒▒▒▒▒ 01 ▒▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_TWO)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[02]▒▒▒▒▒" : "|▒▒▒▒▒▒ 02 ▒▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_THREE)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[03]▒▒▒▒▒" : "|▒▒▒▒▒▒ 03 ▒▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_FOUR)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[04]▒▒▒▒▒" : "|▒▒▒▒▒▒ 04 ▒▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_FIVE)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[05]▒▒▒▒▒" : "|▒▒▒▒▒▒ 05 ▒▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_SIX)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[06]▒▒▒▒▒" : "|▒▒▒▒▒▒ 06 ▒▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[07]▒▒▒▒▒" : "|▒▒▒▒▒▒ 07 ▒▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_LUST)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒[Lust]▒▒▒▒" : "|▒▒▒▒▒ Lust ▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒[Pride]▒▒▒▒" : "|▒▒▒▒ Pride ▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒[Gluttony]▒▒" : "|▒▒▒ Gluttony ▒▒");
			else if (cells[0].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒[Sloth]▒▒▒▒" : "|▒▒▒▒ Sloth ▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_ENVY)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒▒[Envy]▒▒▒▒" : "|▒▒▒▒▒ Envy ▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_WRATH)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒[Wrath]▒▒▒▒" : "|▒▒▒▒ Wrath ▒▒▒▒");
			else if (cells[0].stone->id == ID_STONE_GREED)
				printf("%s", cells[0].stone->player_id == player_id ?
					"|▒▒▒▒[Greed]▒▒▒▒" : "|▒▒▒▒ Greed ▒▒▒▒");
		}
	}
	else if (line == 8)
	{
		/* Cell Coordinate 12 */
		if (!cells[3].stone)
			printf("|               ");
		else
		{
			if (cells[3].stone->id == ID_STONE_ONE)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|      [01]     " : "|       01      ");
			else if (cells[3].stone->id == ID_STONE_TWO)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|      [02]     " : "|       02      ");
			else if (cells[3].stone->id == ID_STONE_THREE)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|      [03]     " : "|       03      ");
			else if (cells[3].stone->id == ID_STONE_FOUR)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|      [04]     " : "|       04      " );
			else if (cells[3].stone->id == ID_STONE_FIVE)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|      [05]     " : "|       05      ");
			else if (cells[3].stone->id == ID_STONE_SIX)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|      [06]     " : "|       06      ");
			else if (cells[3].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|      [07]     " : "|       07      ");
			else if (cells[3].stone->id == ID_STONE_LUST)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|     [Lust]    " : "|      Lust     ");
			else if (cells[3].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|    [Pride]    " : "|     Pride     ");
			else if (cells[3].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|   [Gluttony]  " : "|    Gluttony   ");
			else if (cells[3].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|    [Sloth]    " : "|     Sloth     ");
			else if (cells[3].stone->id == ID_STONE_ENVY)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|     [Envy]    " : "|      Envy     ");
			else if (cells[3].stone->id == ID_STONE_WRATH)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|    [Wrath]    " : "|     Wrath     ");
			else if (cells[3].stone->id == ID_STONE_GREED)
				printf("%s", cells[3].stone->player_id == player_id ?
					"|    [Greed]    " : "|     Greed     ");
		}
	}
	else if (line == 13)
	{
		/* Cell Coordinate 13 */
		if (!cells[6].stone)
			printf("|               ");
		else
		{
			if (cells[6].stone->id == ID_STONE_ONE)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|      [01]     " : "|       01      ");
			else if (cells[6].stone->id == ID_STONE_TWO)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|      [02]     " : "|       02      ");
			else if (cells[6].stone->id == ID_STONE_THREE)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|      [03]     " : "|       03      ");
			else if (cells[6].stone->id == ID_STONE_FOUR)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|      [04]     " : "|       04      " );
			else if (cells[6].stone->id == ID_STONE_FIVE)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|      [05]     " : "|       05      ");
			else if (cells[6].stone->id == ID_STONE_SIX)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|      [06]     " : "|       06      ");
			else if (cells[6].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|      [07]     " : "|       07      ");
			else if (cells[6].stone->id == ID_STONE_LUST)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|     [Lust]    " : "|      Lust     ");
			else if (cells[6].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|    [Pride]    " : "|     Pride     ");
			else if (cells[6].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|   [Gluttony]  " : "|    Gluttony   ");
			else if (cells[6].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|    [Sloth]    " : "|     Sloth     ");
			else if (cells[6].stone->id == ID_STONE_ENVY)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|     [Envy]    " : "|      Envy     ");
			else if (cells[6].stone->id == ID_STONE_WRATH)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|    [Wrath]    " : "|     Wrath     ");
			else if (cells[6].stone->id == ID_STONE_GREED)
				printf("%s", cells[6].stone->player_id == player_id ?
					"|    [Greed]    " : "|     Greed     ");
		}
	}
	else if (line == 18)
	{
		/* Cell Coordinate 14 */
		if (!cells[9].stone)
			printf("|               ");
		else
		{
			if (cells[9].stone->id == ID_STONE_ONE)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|      [01]     " : "|       01      ");
			else if (cells[9].stone->id == ID_STONE_TWO)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|      [02]     " : "|       02      ");
			else if (cells[9].stone->id == ID_STONE_THREE)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|      [03]     " : "|       03      ");
			else if (cells[9].stone->id == ID_STONE_FOUR)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|      [04]     " : "|       04      " );
			else if (cells[9].stone->id == ID_STONE_FIVE)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|      [05]     " : "|       05      ");
			else if (cells[9].stone->id == ID_STONE_SIX)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|      [06]     " : "|       06      ");
			else if (cells[9].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|      [07]     " : "|       07      ");
			else if (cells[9].stone->id == ID_STONE_LUST)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|     [Lust]    " : "|      Lust     ");
			else if (cells[9].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|    [Pride]    " : "|     Pride     ");
			else if (cells[9].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|   [Gluttony]  " : "|    Gluttony   ");
			else if (cells[9].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|    [Sloth]    " : "|     Sloth     ");
			else if (cells[9].stone->id == ID_STONE_ENVY)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|     [Envy]    " : "|      Envy     ");
			else if (cells[9].stone->id == ID_STONE_WRATH)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|    [Wrath]    " : "|     Wrath     ");
			else if (cells[9].stone->id == ID_STONE_GREED)
				printf("%s", cells[9].stone->player_id == player_id ?
					"|    [Greed]    " : "|     Greed     ");
		}
	}
	else if (line == 33)
	{
		/* Cell Coordinate 17 */
		if (!cells[14].stone)
			printf("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		else
		{
			if (cells[14].stone->id == ID_STONE_ONE)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[01]▒▒▒▒▒" : "|▒▒▒▒▒▒ 01 ▒▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_TWO)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[02]▒▒▒▒▒" : "|▒▒▒▒▒▒ 02 ▒▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_THREE)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[03]▒▒▒▒▒" : "|▒▒▒▒▒▒ 03 ▒▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_FOUR)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[04]▒▒▒▒▒" : "|▒▒▒▒▒▒ 04 ▒▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_FIVE)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[05]▒▒▒▒▒" : "|▒▒▒▒▒▒ 05 ▒▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_SIX)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[06]▒▒▒▒▒" : "|▒▒▒▒▒▒ 06 ▒▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒▒[07]▒▒▒▒▒" : "|▒▒▒▒▒▒ 07 ▒▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_LUST)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒[Lust]▒▒▒▒" : "|▒▒▒▒▒ Lust ▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒[Pride]▒▒▒▒" : "|▒▒▒▒ Pride ▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒[Gluttony]▒▒" : "|▒▒▒ Gluttony ▒▒");
			else if (cells[14].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒[Sloth]▒▒▒▒" : "|▒▒▒▒ Sloth ▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_ENVY)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒▒[Envy]▒▒▒▒" : "|▒▒▒▒▒ Envy ▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_WRATH)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒[Wrath]▒▒▒▒" : "|▒▒▒▒ Wrath ▒▒▒▒");
			else if (cells[14].stone->id == ID_STONE_GREED)
				printf("%s", cells[14].stone->player_id == player_id ?
					"|▒▒▒▒[Greed]▒▒▒▒" : "|▒▒▒▒ Greed ▒▒▒▒");
		}
	}
	else if (line == 38)
	{
		/* Cell Coordinate 18 */
		if (!cells[17].stone)
			printf("|               ");
		else
		{
			if (cells[17].stone->id == ID_STONE_ONE)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|      [01]     " : "|       01      ");
			else if (cells[17].stone->id == ID_STONE_TWO)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|      [02]     " : "|       02      ");
			else if (cells[17].stone->id == ID_STONE_THREE)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|      [03]     " : "|       03      ");
			else if (cells[17].stone->id == ID_STONE_FOUR)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|      [04]     " : "|       04      " );
			else if (cells[17].stone->id == ID_STONE_FIVE)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|      [05]     " : "|       05      ");
			else if (cells[17].stone->id == ID_STONE_SIX)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|      [06]     " : "|       06      ");
			else if (cells[17].stone->id == ID_STONE_SEVEN)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|      [07]     " : "|       07      ");
			else if (cells[17].stone->id == ID_STONE_LUST)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|     [Lust]    " : "|      Lust     ");
			else if (cells[17].stone->id == ID_STONE_PRIDE)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|    [Pride]    " : "|     Pride     ");
			else if (cells[17].stone->id == ID_STONE_GLUTTONY)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|   [Gluttony]  " : "|    Gluttony   ");
			else if (cells[17].stone->id == ID_STONE_SLOTH)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|    [Sloth]    " : "|     Sloth     ");
			else if (cells[17].stone->id == ID_STONE_ENVY)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|     [Envy]    " : "|      Envy     ");
			else if (cells[17].stone->id == ID_STONE_WRATH)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|    [Wrath]    " : "|     Wrath     ");
			else if (cells[17].stone->id == ID_STONE_GREED)
				printf("%s", cells[17].stone->player_id == player_id ?
					"|    [Greed]    " : "|     Greed     ");
		}
	}
	return ;
}
