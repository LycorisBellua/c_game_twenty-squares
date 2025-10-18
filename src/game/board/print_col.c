#include "twenty_squares.h"

static int	col_2_long_cond(int line, int is_first);

void	print_col_1(int line, int player_id, t_cell cells[8][3])
{
	if (line == 0)
		printf(" _______");
	else if (line == 1 || line == 3 || line == 19 || line == 21)
		printf("|▒▒▒▒▒▒▒");
	else if (line == 4 || line == 7 || line == 10 || line == 22)
		printf("|       ");
	else if (line == 6 || line == 9 || line == 12 || line == 24)
		printf("|_______");
	else if (line >= 13 && line <= 17)
		printf("        ");
	else if (line == 18)
		printf(" _______");
	else if (line == 2)
		print_stone_rosette(cells[0][0].stone, player_id, 1);
	else if (line == 5)
		print_stone(cells[1][0].stone, player_id, 1);
	else if (line == 8)
		print_stone(cells[2][0].stone, player_id, 1);
	else if (line == 11)
		print_stone(cells[3][0].stone, player_id, 1);
	else if (line == 20)
		print_stone_rosette(cells[6][0].stone, player_id, 1);
	else if (line == 23)
		print_stone(cells[7][0].stone, player_id, 1);
	return ;
}

void	print_col_2(int line, int player_id, t_cell cells[8][3])
{
	if (line == 0)
		printf("________");
	else if (col_2_long_cond(line, 1))
		printf("|       ");
	else if (col_2_long_cond(line, 0))
		printf("|_______");
	else if (line == 10 || line == 12)
		printf("|▒▒▒▒▒▒▒");
	else if (line == 2)
		print_stone(cells[0][1].stone, player_id, 2);
	else if (line == 5)
		print_stone(cells[1][1].stone, player_id, 2);
	else if (line == 8)
		print_stone(cells[2][1].stone, player_id, 2);
	else if (line == 11)
		print_stone_rosette(cells[3][1].stone, player_id, 2);
	else if (line == 14)
		print_stone(cells[4][1].stone, player_id, 2);
	else if (line == 17)
		print_stone(cells[5][1].stone, player_id, 2);
	else if (line == 20)
		print_stone(cells[6][1].stone, player_id, 2);
	else if (line == 23)
		print_stone(cells[7][1].stone, player_id, 2);
	return ;
}

void	print_col_3(int line, int player_id, t_cell cells[8][3])
{
	if (line == 0)
		printf("________");
	else if (line == 1 || line == 3 || line == 19 || line == 21)
		printf("|▒▒▒▒▒▒▒|");
	else if (line == 4 || line == 7 || line == 10 || line == 22)
		printf("|       |");
	else if (line == 6 || line == 9 || line == 12 || line == 24)
		printf("|_______|");
	else if (line >= 13 && line <= 17)
		printf("|        ");
	else if (line == 18)
		printf("|_______ ");
	else if (line == 2)
		print_stone_rosette(cells[0][2].stone, player_id, 3);
	else if (line == 5)
		print_stone(cells[1][2].stone, player_id, 3);
	else if (line == 8)
		print_stone(cells[2][2].stone, player_id, 3);
	else if (line == 11)
		print_stone(cells[3][2].stone, player_id, 3);
	else if (line == 20)
		print_stone_rosette(cells[6][2].stone, player_id, 3);
	else if (line == 23)
		print_stone(cells[7][2].stone, player_id, 3);
	return ;
}

static int	col_2_long_cond(int line, int is_first)
{
	if (is_first)
		return (line == 1 || line == 4 || line == 7 || line == 13 || line == 16
			|| line == 19 || line == 22);
	return (line == 3 || line == 6 || line == 9 || line == 15 || line == 18
		|| line == 21 || line == 24);
}
