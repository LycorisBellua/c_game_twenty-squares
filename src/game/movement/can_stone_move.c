#include "twenty_squares.h"

int	can_stone_move(const t_stone *stone, t_player *player, int dice)
{
	int		i;
	t_cell	*cell;

	if (stone->coord == 1 || stone->coord == -1)
		return (0);
	if (!stone->coord)
		cell = player->track[dice - 1];
	else
	{
		i = -1;
		while (++i < 14)
		{
			if (stone->coord == player->track[i]->coord)
			{
				if (i + dice == 14)
					return (1);
				else if (i + dice > 14)
					return (0);
				cell = player->track[i + dice];
				break ;
			}
		}
	}
	if (!cell->stone)
		return (1);
	else if (cell->stone->is_protected)
		return (0);
	else if (cell->stone->player_id == player->id)
		return (0); // ally
	return (1); // enemy
}
