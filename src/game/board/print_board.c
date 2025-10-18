#include "twenty_squares.h"

void	print_board(t_game *game)
{
	int	line;

	clear_window();
	printf("\n");
	print_turn_line(game->turn_nbr);
	line = -1;
	while (++line < 25)
	{
		print_col_p1(line, game->player->id, game->players);
		print_col_1(line, game->player->id, game->cells);
		print_col_2(line, game->player->id, game->cells);
		print_col_3(line, game->player->id, game->cells);
		print_col_p2(line, game->player->id, game->players);
		printf("\n");
	}
	printf("\n");
	return ;
}
