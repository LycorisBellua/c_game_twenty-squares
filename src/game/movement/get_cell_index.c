#include "twenty_squares.h"

int	get_cell_index(t_player *player, t_stone *stone)
{
	int	i;

	if (player && stone && stone->cell)
	{
		i = -1;
		while (++i < 16)
		{
			if (stone->cell == player->track[i])
				return (i);
		}
	}
	return (-1);
}

int	get_cell_index_closest_enemy(t_player *player, int start_index)
{
	int	i;

	i = start_index - 1;
	while (++i < INDEX_VICTORY)
	{
		if (player->track[i]->stone
			&& player->track[i]->stone->player_id != player->id)
			return (i);
	}
	return (-1);
}
