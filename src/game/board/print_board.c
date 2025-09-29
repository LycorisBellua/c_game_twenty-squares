#include "twenty_squares.h"

static void	print_turn_line(int nbr_turns);
static void	print_col_p1(int line, int player_id, t_player *players);
static void	print_col_1(int line, int player_id, t_cell cells[8][3]);
static void	print_col_2(int line, int player_id, t_cell cells[8][3]);
static void	print_col_3(int line, int player_id, t_cell cells[8][3]);
static void	print_col_p2(int line, int player_id, t_player *players);

void	print_board(int nbr_turns, int player_id, t_player *players,
			t_cell cells[8][3])
{
	int	line;

	clear_window();
	printf("\n");
	print_turn_line(nbr_turns);
	line = -1;
	while (++line < 25)
	{
		print_col_p1(line, player_id, players);
		print_col_1(line, player_id, cells);
		print_col_2(line, player_id, cells);
		print_col_3(line, player_id, cells);
		print_col_p2(line, player_id, players);
		printf("\n");
	}
	printf("\n");
	return ;
}

static void	print_turn_line(int nbr_turns)
{
	const int	len_total = 55;
	const int	len_space_first = 24;
	int			len_turn;

	printf("%*s", len_space_first, "");
	len_turn = printf("TURN %d", nbr_turns);
	printf("%*s\n", len_total - len_space_first - len_turn, "");
	return ;
}

static void	print_col_p1(int line, int player_id, t_player *players)
{
	if (line == 1)
		printf("  PLAYER ONE   ");
	else if (line == 2)
		printf("%s", !player_id ? " ............. " : "               ");
	else if (line == 4)
		printf("      POINTS   ");
	else if (line == 5)
		printf("         %d     ", players[0].points);
	else if (line == 7)
		print_stone_p(players[0].stoneset + 0, players[0].track);
	else if (line == 8)
		print_stone_p(players[0].stoneset + 1, players[0].track);
	else if (line == 9)
		print_stone_p(players[0].stoneset + 2, players[0].track);
	else if (line == 10)
		print_stone_p(players[0].stoneset + 3, players[0].track);
	else if (line == 11)
		print_stone_p(players[0].stoneset + 4, players[0].track);
	else if (line == 12)
		print_stone_p(players[0].stoneset + 5, players[0].track);
	else if (line == 13)
		print_stone_p(players[0].stoneset + 6, players[0].track);
	else
		printf("               ");
	return ;
}

static void	print_col_1(int line, int player_id, t_cell cells[8][3])
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

static void	print_col_2(int line, int player_id, t_cell cells[8][3])
{
	if (line == 0)
		printf("________");
	else if (line == 1 || line == 4 || line == 7 || line == 13 || line == 16
		|| line == 19 || line == 22)
		printf("|       ");
	else if (line == 3 || line == 6 || line == 9 || line == 15 || line == 18
		|| line == 21 || line == 24)
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

static void	print_col_3(int line, int player_id, t_cell cells[8][3])
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

static void	print_col_p2(int line, int player_id, t_player *players)
{
	if (line == 1)
		printf("   PLAYER TWO  ");
	else if (line == 2)
		printf("%s", player_id == 1 ? " ............. " : "               ");
	else if (line == 4)
		printf("   POINTS     ");
	else if (line == 5)
		printf("     %d        ", players[1].points);
	else if (line == 7)
		print_stone_p(players[1].stoneset + 0, players[1].track);
	else if (line == 8)
		print_stone_p(players[1].stoneset + 1, players[1].track);
	else if (line == 9)
		print_stone_p(players[1].stoneset + 2, players[1].track);
	else if (line == 10)
		print_stone_p(players[1].stoneset + 3, players[1].track);
	else if (line == 11)
		print_stone_p(players[1].stoneset + 4, players[1].track);
	else if (line == 12)
		print_stone_p(players[1].stoneset + 5, players[1].track);
	else if (line == 13)
		print_stone_p(players[1].stoneset + 6, players[1].track);
	else
		printf("               ");
	return ;
}
