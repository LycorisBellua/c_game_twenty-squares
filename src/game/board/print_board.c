#include "twenty_squares.h"

void	print_board(int number_of_turns, int level, int current_player_id,
			Player *players, Cell *cells)
{
	int	line;

	clear_window();
	print_turn_line(number_of_turns);
	line = -1;
	while (++line < 42)
	{
		print_column0(line, level, current_player_id, players);
		print_column1(line, current_player_id, cells);
		print_column2(line, current_player_id, cells);
		print_column3(line, current_player_id, cells);
		print_column4(line, level, current_player_id, players);
		printf("\n");
	}
	return ;
}
