#include "twenty_squares.h"

void	print_column1(int line, int current_player_id, Cell *cells)
{
	int	id;
	int	stone_belongs_to_current_player;

	stone_belongs_to_current_player = 0;
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
		if (!(cells + 0)->stone_in_cell)
			id = 0;
		else
		{
			id = (cells + 0)->stone_in_cell->id;
			stone_belongs_to_current_player = (cells + 0)->stone_in_cell
				->player_id == current_player_id ? 1 : 0;
		}
		if (!id)
			printf("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		else
		{
			if (id == ID_STONE_ONE)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[01]▒▒▒▒▒" : "|▒▒▒▒▒▒ 01 ▒▒▒▒▒");
			else if (id == ID_STONE_TWO)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[02]▒▒▒▒▒" : "|▒▒▒▒▒▒ 02 ▒▒▒▒▒");
			else if (id == ID_STONE_THREE)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[03]▒▒▒▒▒" : "|▒▒▒▒▒▒ 03 ▒▒▒▒▒");
			else if (id == ID_STONE_FOUR)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[04]▒▒▒▒▒" : "|▒▒▒▒▒▒ 04 ▒▒▒▒▒");
			else if (id == ID_STONE_FIVE)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[05]▒▒▒▒▒" : "|▒▒▒▒▒▒ 05 ▒▒▒▒▒");
			else if (id == ID_STONE_SIX)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[06]▒▒▒▒▒" : "|▒▒▒▒▒▒ 06 ▒▒▒▒▒");
			else if (id == ID_STONE_SEVEN)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[07]▒▒▒▒▒" : "|▒▒▒▒▒▒ 07 ▒▒▒▒▒");
			else if (id == ID_STONE_LUST)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒[Lust]▒▒▒▒" : "|▒▒▒▒▒ Lust ▒▒▒▒");
			else if (id == ID_STONE_PRIDE)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒[Pride]▒▒▒▒" : "|▒▒▒▒ Pride ▒▒▒▒");
			else if (id == ID_STONE_GLUTTONY)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒[Gluttony]▒▒" : "|▒▒▒ Gluttony ▒▒");
			else if (id == ID_STONE_SLOTH)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒[Sloth]▒▒▒▒" : "|▒▒▒▒ Sloth ▒▒▒▒");
			else if (id == ID_STONE_ENVY)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒[Envy]▒▒▒▒" : "|▒▒▒▒▒ Envy ▒▒▒▒");
			else if (id == ID_STONE_WRATH)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒[Wrath]▒▒▒▒" : "|▒▒▒▒ Wrath ▒▒▒▒");
			else if (id == ID_STONE_GREED)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒[Greed]▒▒▒▒" : "|▒▒▒▒ Greed ▒▒▒▒");
		}
	}
	else if (line == 8)
	{
		/* Cell Coordinate 12 */
		if (!(cells + 3)->stone_in_cell)
			id = 0;
		else
		{
			id = (cells + 3)->stone_in_cell->id;
			stone_belongs_to_current_player = (cells + 3)->stone_in_cell
				->player_id == current_player_id ? 1 : 0;
		}
		if (!id)
			printf("|               ");
		else
		{
			if (id == ID_STONE_ONE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [01]     " : "|       01      ");
			else if (id == ID_STONE_TWO)
				printf("%s", stone_belongs_to_current_player ?
					"|      [02]     " : "|       02      ");
			else if (id == ID_STONE_THREE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [03]     " : "|       03      ");
			else if (id == ID_STONE_FOUR)
				printf("%s", stone_belongs_to_current_player ?
					"|      [04]     " : "|       04      " );
			else if (id == ID_STONE_FIVE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [05]     " : "|       05      ");
			else if (id == ID_STONE_SIX)
				printf("%s", stone_belongs_to_current_player ?
					"|      [06]     " : "|       06      ");
			else if (id == ID_STONE_SEVEN)
				printf("%s", stone_belongs_to_current_player ?
					"|      [07]     " : "|       07      ");
			else if (id == ID_STONE_LUST)
				printf("%s", stone_belongs_to_current_player ?
					"|     [Lust]    " : "|      Lust     ");
			else if (id == ID_STONE_PRIDE)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Pride]    " : "|     Pride     ");
			else if (id == ID_STONE_GLUTTONY)
				printf("%s", stone_belongs_to_current_player ?
					"|   [Gluttony]  " : "|    Gluttony   ");
			else if (id == ID_STONE_SLOTH)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Sloth]    " : "|     Sloth     ");
			else if (id == ID_STONE_ENVY)
				printf("%s", stone_belongs_to_current_player ?
					"|     [Envy]    " : "|      Envy     ");
			else if (id == ID_STONE_WRATH)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Wrath]    " : "|     Wrath     ");
			else if (id == ID_STONE_GREED)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Greed]    " : "|     Greed     ");
		}
	}
	else if (line == 13)
	{
		/* Cell Coordinate 13 */
		if (!(cells + 6)->stone_in_cell)
			id = 0;
		else
		{
			id = (cells + 6)->stone_in_cell->id;
			stone_belongs_to_current_player = (cells + 6)->stone_in_cell
				->player_id == current_player_id ? 1 : 0;
		}
		if (!id)
			printf("|               ");
		else
		{
			if (id == ID_STONE_ONE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [01]     " : "|       01      ");
			else if (id == ID_STONE_TWO)
				printf("%s", stone_belongs_to_current_player ?
					"|      [02]     " : "|       02      ");
			else if (id == ID_STONE_THREE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [03]     " : "|       03      ");
			else if (id == ID_STONE_FOUR)
				printf("%s", stone_belongs_to_current_player ?
					"|      [04]     " : "|       04      " );
			else if (id == ID_STONE_FIVE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [05]     " : "|       05      ");
			else if (id == ID_STONE_SIX)
				printf("%s", stone_belongs_to_current_player ?
					"|      [06]     " : "|       06      ");
			else if (id == ID_STONE_SEVEN)
				printf("%s", stone_belongs_to_current_player ?
					"|      [07]     " : "|       07      ");
			else if (id == ID_STONE_LUST)
				printf("%s", stone_belongs_to_current_player ?
					"|     [Lust]    " : "|      Lust     ");
			else if (id == ID_STONE_PRIDE)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Pride]    " : "|     Pride     ");
			else if (id == ID_STONE_GLUTTONY)
				printf("%s", stone_belongs_to_current_player ?
					"|   [Gluttony]  " : "|    Gluttony   ");
			else if (id == ID_STONE_SLOTH)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Sloth]    " : "|     Sloth     ");
			else if (id == ID_STONE_ENVY)
				printf("%s", stone_belongs_to_current_player ?
					"|     [Envy]    " : "|      Envy     ");
			else if (id == ID_STONE_WRATH)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Wrath]    " : "|     Wrath     ");
			else if (id == ID_STONE_GREED)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Greed]    " : "|     Greed     ");
		}
	}
	else if (line == 18)
	{
		/* Cell Coordinate 14 */
		if (!(cells + 9)->stone_in_cell)
			id = 0;
		else
		{
			id = (cells + 9)->stone_in_cell->id;
			stone_belongs_to_current_player = (cells + 9)->stone_in_cell
				->player_id == current_player_id ? 1 : 0;
		}
		if (!id)
			printf("|               ");
		else
		{
			if (id == ID_STONE_ONE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [01]     " : "|       01      ");
			else if (id == ID_STONE_TWO)
				printf("%s", stone_belongs_to_current_player ?
					"|      [02]     " : "|       02      ");
			else if (id == ID_STONE_THREE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [03]     " : "|       03      ");
			else if (id == ID_STONE_FOUR)
				printf("%s", stone_belongs_to_current_player ?
					"|      [04]     " : "|       04      " );
			else if (id == ID_STONE_FIVE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [05]     " : "|       05      ");
			else if (id == ID_STONE_SIX)
				printf("%s", stone_belongs_to_current_player ?
					"|      [06]     " : "|       06      ");
			else if (id == ID_STONE_SEVEN)
				printf("%s", stone_belongs_to_current_player ?
					"|      [07]     " : "|       07      ");
			else if (id == ID_STONE_LUST)
				printf("%s", stone_belongs_to_current_player ?
					"|     [Lust]    " : "|      Lust     ");
			else if (id == ID_STONE_PRIDE)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Pride]    " : "|     Pride     ");
			else if (id == ID_STONE_GLUTTONY)
				printf("%s", stone_belongs_to_current_player ?
					"|   [Gluttony]  " : "|    Gluttony   ");
			else if (id == ID_STONE_SLOTH)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Sloth]    " : "|     Sloth     ");
			else if (id == ID_STONE_ENVY)
				printf("%s", stone_belongs_to_current_player ?
					"|     [Envy]    " : "|      Envy     ");
			else if (id == ID_STONE_WRATH)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Wrath]    " : "|     Wrath     ");
			else if (id == ID_STONE_GREED)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Greed]    " : "|     Greed     ");
		}
	}
	else if (line == 33)
	{
		/* Cell Coordinate 17 */
		if (!(cells + 14)->stone_in_cell)
			id = 0;
		else
		{
			id = (cells + 14)->stone_in_cell->id;
			stone_belongs_to_current_player = (cells + 14)->stone_in_cell
				->player_id == current_player_id ? 1 : 0;
		}
		if (!id)
			printf("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		else
		{
			if (id == ID_STONE_ONE)

				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[01]▒▒▒▒▒" : "|▒▒▒▒▒▒ 01 ▒▒▒▒▒");
			else if (id == ID_STONE_TWO)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[02]▒▒▒▒▒" : "|▒▒▒▒▒▒ 02 ▒▒▒▒▒");
			else if (id == ID_STONE_THREE)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[03]▒▒▒▒▒" : "|▒▒▒▒▒▒ 03 ▒▒▒▒▒");
			else if (id == ID_STONE_FOUR)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[04]▒▒▒▒▒" : "|▒▒▒▒▒▒ 04 ▒▒▒▒▒");
			else if (id == ID_STONE_FIVE)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[05]▒▒▒▒▒" : "|▒▒▒▒▒▒ 05 ▒▒▒▒▒");
			else if (id == ID_STONE_SIX)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[06]▒▒▒▒▒" : "|▒▒▒▒▒▒ 06 ▒▒▒▒▒");
			else if (id == ID_STONE_SEVEN)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒▒[07]▒▒▒▒▒" : "|▒▒▒▒▒▒ 07 ▒▒▒▒▒");
			else if (id == ID_STONE_LUST)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒[Lust]▒▒▒▒" : "|▒▒▒▒▒ Lust ▒▒▒▒");
			else if (id == ID_STONE_PRIDE)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒[Pride]▒▒▒▒" : "|▒▒▒▒ Pride ▒▒▒▒");
			else if (id == ID_STONE_GLUTTONY)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒[Gluttony]▒▒" : "|▒▒▒ Gluttony ▒▒");
			else if (id == ID_STONE_SLOTH)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒[Sloth]▒▒▒▒" : "|▒▒▒▒ Sloth ▒▒▒▒");
			else if (id == ID_STONE_ENVY)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒▒[Envy]▒▒▒▒" : "|▒▒▒▒▒ Envy ▒▒▒▒");
			else if (id == ID_STONE_WRATH)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒[Wrath]▒▒▒▒" : "|▒▒▒▒ Wrath ▒▒▒▒");
			else if (id == ID_STONE_GREED)
				printf("%s", stone_belongs_to_current_player ?
					"|▒▒▒▒[Greed]▒▒▒▒" : "|▒▒▒▒ Greed ▒▒▒▒");
		}
	}
	else if (line == 38)
	{
		/* Cell Coordinate 18 */
		if (!(cells + 17)->stone_in_cell)
			id = 0;
		else
		{
			id = (cells + 17)->stone_in_cell->id;
			stone_belongs_to_current_player = (cells + 17)->stone_in_cell
				->player_id == current_player_id ? 1 : 0;
		}
		if (!id)
			printf("|               ");
		else
		{
			if (id == ID_STONE_ONE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [01]     " : "|       01      ");
			else if (id == ID_STONE_TWO)
				printf("%s", stone_belongs_to_current_player ?
					"|      [02]     " : "|       02      ");
			else if (id == ID_STONE_THREE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [03]     " : "|       03      ");
			else if (id == ID_STONE_FOUR)
				printf("%s", stone_belongs_to_current_player ?
					"|      [04]     " : "|       04      " );
			else if (id == ID_STONE_FIVE)
				printf("%s", stone_belongs_to_current_player ?
					"|      [05]     " : "|       05      ");
			else if (id == ID_STONE_SIX)
				printf("%s", stone_belongs_to_current_player ?
					"|      [06]     " : "|       06      ");
			else if (id == ID_STONE_SEVEN)
				printf("%s", stone_belongs_to_current_player ?
					"|      [07]     " : "|       07      ");
			else if (id == ID_STONE_LUST)
				printf("%s", stone_belongs_to_current_player ?
					"|     [Lust]    " : "|      Lust     ");
			else if (id == ID_STONE_PRIDE)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Pride]    " : "|     Pride     ");
			else if (id == ID_STONE_GLUTTONY)
				printf("%s", stone_belongs_to_current_player ?
					"|   [Gluttony]  " : "|    Gluttony   ");
			else if (id == ID_STONE_SLOTH)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Sloth]    " : "|     Sloth     ");
			else if (id == ID_STONE_ENVY)
				printf("%s", stone_belongs_to_current_player ?
					"|     [Envy]    " : "|      Envy     ");
			else if (id == ID_STONE_WRATH)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Wrath]    " : "|     Wrath     ");
			else if (id == ID_STONE_GREED)
				printf("%s", stone_belongs_to_current_player ?
					"|    [Greed]    " : "|     Greed     ");
		}
	}
	return ;
}
