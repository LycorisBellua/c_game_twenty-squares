#include "twenty_squares.h"

int	can_stone_move_classic(t_game *game, t_stone *stone)
{
	int		cell_index;
	t_cell	*cell;

	memset(stone->moves, 0, sizeof(stone->moves));
	cell_index = get_cell_index(game->player, stone);
	if (!game->dice || cell_index < 0 || cell_index == 15
		|| cell_index + game->dice > 15)
		return (0);
	cell = game->player->track[cell_index + game->dice];
	if (!cell->stone
		|| (!cell->is_rosette && cell->stone->player_id != game->player->id))
		stone->moves[0] = game->dice;
	return (!!stone->moves[0]);
}
