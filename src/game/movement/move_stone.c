#include "twenty_squares.h"

void	move_stone(t_game *game)
{
	t_cell	*dest_cell;

	if (game->stone->cell != game->player->track[0])
		game->stone->cell->stone = 0;
	dest_cell = game->player->track[get_cell_index(game->player, game->stone)
		+ game->dist_to_move];
	if (dest_cell->stone)
	{
		if (game->lvl == 1 || game->lvl == 3)
			dest_cell->stone->cell = game->other_player->track[0];
		else
		{
			dest_cell->stone->cell = 0;
			--game->other_player->nbr_playable;
		}
	}
	game->stone->cell = dest_cell;
	if (dest_cell != game->player->track[0])
		dest_cell->stone = game->stone;
	else
	{
		--game->player->nbr_playable;
		++game->player->points;
	}
	return ;
}
