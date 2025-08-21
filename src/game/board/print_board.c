#include "twenty_squares.h"

static void	print_turn_line(int nbr_turns);
static void	print_col_p1(int line, int player_id, t_player *players);
static void	print_col_1(int line, int player_id, t_cell *cells);
static void	print_col_2(int line, int player_id, t_cell *cells);
static void	print_col_3(int line, int player_id, t_cell *cells);
static void	print_col_p2(int line, int player_id, t_player *players);

void	print_board(int nbr_turns, int player_id, t_player *players,
			t_cell *cells)
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
		print_stone_p(players[0].stoneset + 0, 0);
	else if (line == 8)
		print_stone_p(players[0].stoneset + 1, 0);
	else if (line == 9)
		print_stone_p(players[0].stoneset + 2, 0);
	else if (line == 10)
		print_stone_p(players[0].stoneset + 3, 0);
	else if (line == 11)
		print_stone_p(players[0].stoneset + 4, 0);
	else if (line == 12)
		print_stone_p(players[0].stoneset + 5, 0);
	else if (line == 13)
		print_stone_p(players[0].stoneset + 6, 0);
	else
		printf("               ");
	return ;
}

static void	print_col_1(int line, int player_id, t_cell *cells)
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
		print_stone_rosette(cells[0].stone, player_id, 1);  /* Cell Coord 11 */
	else if (line == 5)
		print_stone(cells[3].stone, player_id, 1);          /* Cell Coord 12 */
	else if (line == 8)
		print_stone(cells[6].stone, player_id, 1);          /* Cell Coord 13 */
	else if (line == 11)
		print_stone(cells[9].stone, player_id, 1);          /* Cell Coord 14 */
	else if (line == 20)
		print_stone_rosette(cells[14].stone, player_id, 1); /* Cell Coord 17 */
	else if (line == 23)
		print_stone(cells[17].stone, player_id, 1);         /* Cell Coord 18 */
	return ;
}

static void	print_col_2(int line, int player_id, t_cell *cells)
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
		print_stone(cells[1].stone, player_id, 2);          /* Cell Coord 21 */
	else if (line == 5)
		print_stone(cells[4].stone, player_id, 2);          /* Cell Coord 22 */
	else if (line == 8)
		print_stone(cells[7].stone, player_id, 2);          /* Cell Coord 23 */
	else if (line == 11)
		print_stone_rosette(cells[10].stone, player_id, 2); /* Cell Coord 24 */
	else if (line == 14)
		print_stone(cells[12].stone, player_id, 2);         /* Cell Coord 25 */
	else if (line == 17)
		print_stone(cells[13].stone, player_id, 2);         /* Cell Coord 26 */
	else if (line == 20)
		print_stone(cells[15].stone, player_id, 2);         /* Cell Coord 27 */
	else if (line == 23)
		print_stone(cells[18].stone, player_id, 2);         /* Cell Coord 28 */
	return ;
}

static void	print_col_3(int line, int player_id, t_cell *cells)
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
		print_stone_rosette(cells[2].stone, player_id, 3);  /* Cell Coord 31 */
	else if (line == 5)
		print_stone(cells[5].stone, player_id, 3);          /* Cell Coord 32 */
	else if (line == 8)
		print_stone(cells[8].stone, player_id, 3);          /* Cell Coord 33 */
	else if (line == 11)
		print_stone(cells[11].stone, player_id, 3);         /* Cell Coord 34 */
	else if (line == 20)
		print_stone_rosette(cells[16].stone, player_id, 3); /* Cell Coord 37 */
	else if (line == 23)
		print_stone(cells[19].stone, player_id, 3);         /* Cell Coord 38 */
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
		print_stone_p(players[1].stoneset + 0, 1);
	else if (line == 8)
		print_stone_p(players[1].stoneset + 1, 1);
	else if (line == 9)
		print_stone_p(players[1].stoneset + 2, 1);
	else if (line == 10)
		print_stone_p(players[1].stoneset + 3, 1);
	else if (line == 11)
		print_stone_p(players[1].stoneset + 4, 1);
	else if (line == 12)
		print_stone_p(players[1].stoneset + 5, 1);
	else if (line == 13)
		print_stone_p(players[1].stoneset + 6, 1);
	else
		printf("               ");
	return ;
}
