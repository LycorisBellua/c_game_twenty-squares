#include "twenty_squares.h"

int	can_this_classic_stone_move(const Stone *stone, Player *current_player,
		int dice)
{
	int		i;
	Cell	**target_cell;

	// target_cell is a double pointer because current_player is a double 
	// pointer
	if (stone->coordinate == 1 || stone->coordinate == -1)
		return (0);
	if (!stone->coordinate)
	{
		target_cell = &current_player->racetrack[dice - 1];
	}
	else
	{
		i = -1;
		while (++i < 14)
		{
			if (stone->coordinate == current_player->racetrack[i]->coordinate)
			{
				if (i + dice == 14)
					return (1);
				else if (i + dice > 14)
					return (0);
				target_cell = &current_player->racetrack[i + dice];
				break ;
			}
		}
	}
	if (!(*target_cell)->stone_in_cell)
		return (1);
	else if ((*target_cell)->stone_in_cell->is_protected)
		return (0);
	else if ((*target_cell)->stone_in_cell->player_id == current_player->id)
		return (0); // ally
	return (1); // enemy
}
