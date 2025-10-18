#include "twenty_squares.h"

int	can_any_stone_move(t_game *game)
{
	int		i;
	int		nbr_moveable;
	t_stone	*stone;

	if (!game->dice)
		return (0);
	i = -1;
	nbr_moveable = 0;
	while (++i < 7)
	{
		stone = &game->player->stones[i];
		if (game->lvl <= 2)
			stone->can_move = can_stone_move_classic(game, stone);
		else
			stone->can_move = can_stone_move_deadlysins(game, stone);
		if (stone->can_move)
			++nbr_moveable;
	}
	return (nbr_moveable);
}
