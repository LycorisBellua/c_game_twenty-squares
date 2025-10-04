#include "twenty_squares.h"

int	can_any_stone_move(t_game *game)
{
	int	i;
	int	nbr_moveable;

	if (!game->dice)
		return (0);
	i = -1;
	nbr_moveable = 0;
	while (++i < 7)
	{
		if (set_stone_can_move(game, &game->player->stones[i]))
			++nbr_moveable;
	}
	return (nbr_moveable);
}
