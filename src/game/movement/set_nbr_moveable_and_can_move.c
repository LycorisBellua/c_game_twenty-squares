#include "twenty_squares.h"

int	set_nbr_moveable_and_can_move(t_player *player, int lvl, int dice)
{
	int	i;
	int	nbr_moveable;

	nbr_moveable = 0;
	i = -1;
	while (++i < 7)
	{
		if (lvl <= 2 && can_stone_move(&player->stoneset[i], player, dice))
		{
			player->stoneset[i].can_move = 1;
			++nbr_moveable;
		}
		else if (lvl > 2
			&& can_stone_move_ds(&player->stoneset[i], player, dice))
		{
			player->stoneset[i].can_move = 1;
			++nbr_moveable;
		}
		else
			player->stoneset[i].can_move = 0;
	}
	return (nbr_moveable);
}
