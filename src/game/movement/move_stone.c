#include "twenty_squares.h"

int	move_stone(int lvl, int dist_to_move, t_stone *stone, t_cell **cell,
		t_player *player, t_player *other_player)
{
	int	i;
	int	origin_cell_track_index;
	int	pride_choice;

	origin_cell_track_index = 0;
	*cell = player->track[14];
	// I don't understand why, but `origin_cell_track_index` needs to be set to 
	// 0, or after the first time entering the function, the variable will take 
	// a garbage value
	i = -1;
	while (++i < 14)
	{
		if (stone->coord
			== player->track[i]->coord)
		{
			origin_cell_track_index = i;
			break ;
		}
	}
	if (stone->id == ID_STONE_PRIDE)
	{
		// If possible, Pride wants to go out of bounds. As `cell` is already 
		// set to track index 14, which means "out of bounds", we don't need to 
		// update it.
		pride_choice = 0;
		i = -1;
		while (++i < 4)
		{
			if (!stone->moves[i])
				break ;
			if (origin_cell_track_index + stone->moves[i] >= 14)
			{
				pride_choice = 1;
				printf("Pride seizes the opportunity to get rid of %s, and "
					"leaves.\n\n", player->is_ai ? player->name : "you");
				break ;
			}
		}
		// If pride couldn't go out of bounds, we need to find another dest.
		if (!pride_choice)
		{
			// (i - 1) is the last valid index of possible_movements.
			pride_choice = !(i - 1) ? 0 : rng_minmax(0, i - 1);
			if (dist_to_move == stone->moves[pride_choice])
			{
				printf("Pride refuses to move. The turn passes.\n\n");
				return (0);
			}
			else
			{
				printf("\"%s\", huh? Pride will move somewhere else.\n\n", 
					dist_to_move == 1 ? "One" : dist_to_move == 2 ? "Two" 
					: dist_to_move == 3 ? "Three" : "Four");
				dist_to_move = stone->moves[pride_choice];
			}
			if (!stone->coord)
			{
				*cell = player->track[dist_to_move - 1];
			}
			else
			{
				// If we are here, it means that the target cannot be out of 
				// bounds, so there's no need to check if it is.
				*cell = player->track[origin_cell_track_index + dist_to_move];
			}
		}
	}
	else
	{
		if (!stone->coord)
		{
			*cell = player->track[dist_to_move - 1];
		}
		else
		{
			if (origin_cell_track_index + dist_to_move < 14)
				*cell = player->track[origin_cell_track_index + dist_to_move];
		}
	}
	if (stone->coord)
		player->track[origin_cell_track_index]->stone = 0;
	if ((*cell)->coord == 1)
	{
		stone->coord = 1;
		--player->nbr_playable;
		++player->points;
	}
	else
	{
		if ((*cell)->stone)
		{
			if (lvl == 1 || lvl == 3)
				(*cell)->stone->coord = 0;
			else
			{
				(*cell)->stone->coord = -1;
				--other_player->nbr_playable;
			}
		}
		(*cell)->stone = stone;
		stone->coord = (*cell)->coord;
	}
	return (1);
}
