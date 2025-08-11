#include "twenty_squares.h"

static void	print_turn_line(int nbr_turns);

void	print_board(int nbr_turns, int lvl, int player_id, t_player *players,
			t_cell *cells)
{
	int	line;

	clear_window();
	printf("\n");
	print_turn_line(nbr_turns);
	line = -1;
	while (++line < 42)
	{
		print_column0(line, lvl, player_id, players);
		print_column1(line, player_id, cells);
		print_column2(line, player_id, cells);
		print_column3(line, player_id, cells);
		print_column4(line, lvl, player_id, players);
		printf("\n");
	}
	return ;
}

static void	print_turn_line(int nbr_turns)
{
	int	curr_len;

	curr_len = printf("                                    TURN %d", nbr_turns);
	printf("%*s\n", 79 - curr_len, "");
	return ;
}
