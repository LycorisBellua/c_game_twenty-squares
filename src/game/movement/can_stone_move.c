#include "twenty_squares.h"

int	can_stone_move(const t_stone *stone, t_player *player, int dice)
{
	int		i;
	t_cell	*cell;

	cell = 0;
	if (!stone->cell || stone->cell == player->track[INDEX_VICTORY])
		return (0);
	else if (stone->cell == player->track[INDEX_HOME])
		cell = player->track[dice];
	else
	{
		i = 0;
		while (++i < 15)
		{
			if (stone->cell == player->track[i])
			{
				if (i + dice == 15)
					return (1);
				else if (i + dice > 15)
					return (0);
				cell = player->track[i + dice];
				break ;
			}
		}
	}
	if (!cell)
		return (0);
	else if (!cell->stone)
		return (1);
	else if (cell->stone->is_protected)
		return (0);
	else if (cell->stone->player_id == player->id)
		return (0); // ally
	return (1); // enemy
}
