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

int	get_cell_index_next_enemy(t_player *player, int start_index,
		int even_if_protected)
{
	int	i;

	i = start_index;
	while (++i < INDEX_VICTORY)
	{
		if (player->track[i]->stone
			&& player->track[i]->stone->player_id != player->id
			&& (even_if_protected || !player->track[i]->is_rosette))
			return (i);
	}
	return (-1);
}

int	get_cell_index_next_rosette(t_player *player, int start_index,
		int even_if_occupied)
{
	int	i;

	i = start_index;
	while (++i < INDEX_VICTORY)
	{
		if (player->track[i]->is_rosette
			&& (even_if_occupied || !player->track[i]->stone))
			return (i);
	}
	return (-1);
}
