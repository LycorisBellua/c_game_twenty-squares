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
