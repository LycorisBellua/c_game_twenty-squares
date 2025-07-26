#include "twenty_squares.h"

int	move_stone(int level, int number_of_cells_forward, Stone *chosen_stone,
		Cell ***target_cell, Player *current_player, Player *other_player)
{
	int	i;
	int	racetrack_index_of_origin_cell;
	int	pride_has_chosen;

	racetrack_index_of_origin_cell = 0;
	pride_has_chosen = 0;
	*target_cell = &current_player->racetrack[14];
	// I don't understand why, but racetrack_index_of_origin_cell needs to be 
	// set to 0, or after the first time entering the function, the variable 
	// will take a garbage value
	i = -1;
	while (++i < 14)
	{
		if ((*chosen_stone).coordinate
			== current_player->racetrack[i]->coordinate)
		{
			racetrack_index_of_origin_cell = i;
			break ;
		}
	}
	if ((*chosen_stone).id == ID_STONE_PRIDE)
	{
		// If possible, Pride wants to go out of bounds. As target_cell is 
		// already set to racetrack index 14, which means "out of bounds", we 
		// don't need to update it.
		i = -1;
		while (++i < 4)
		{
			if (!(*chosen_stone).possible_movements[i])
				break ;
			if (!pride_has_chosen)
			{
				if (racetrack_index_of_origin_cell
					+ (*chosen_stone).possible_movements[i] >= 14)
				{
					pride_has_chosen = 1;
					printf("\nPride seizes the opportunity to get rid of %s, "
						"and leaves.\n\n",
						current_player->is_ai ? current_player->name : "you");
					break ;
				}
			}
		}
		// If pride couldn't go out of bounds, we need to find another 
		// destination.
		if (!pride_has_chosen)
		{
			// (i - 1) is the last valid index of possible_movements.
			pride_has_chosen = !(i - 1) ? 0 : rng_minmax(&rng_seed, 0, i - 1);
			if (number_of_cells_forward
				== (*chosen_stone).possible_movements[pride_has_chosen])
			{
				printf("\nPride refuses to move. The turn passes.\n\n");
				return (0);
			}
			else
			{
				printf("\n\"%s\", huh? Pride will move somewhere else.\n\n", 
						number_of_cells_forward == 1 ? "One" 
						: number_of_cells_forward == 2 ? "Two" 
						: number_of_cells_forward == 3 ? "Three" 
						: "Four");

				number_of_cells_forward
					= (*chosen_stone).possible_movements[pride_has_chosen];
			}
			if (!(*chosen_stone).coordinate)
			{
				*target_cell
					= &current_player->racetrack[number_of_cells_forward - 1];
			}
			else
			{
				// If we are here, it means that the target cannot be out of 
				// bounds, so there's no need to check if it is.
				*target_cell
					= &current_player->racetrack[racetrack_index_of_origin_cell
					+ number_of_cells_forward];
			}
		}
	}
	else
	{
		if (!(*chosen_stone).coordinate)
		{
			*target_cell
				= &current_player->racetrack[number_of_cells_forward - 1];
		}
		else
		{
			if (racetrack_index_of_origin_cell + number_of_cells_forward < 14)
				*target_cell
					= &current_player->racetrack[racetrack_index_of_origin_cell
					+ number_of_cells_forward];
		}
	}
	if (!(*chosen_stone).coordinate)
		++(current_player->number_of_stones_on_board);
	else
		current_player->racetrack[racetrack_index_of_origin_cell]->stone_in_cell
			= 0;
	if ((*(*target_cell))->coordinate == 1)
	{
		(*chosen_stone).coordinate = 1;
		--(current_player->number_of_playable_stones);
		--(current_player->number_of_stones_on_board);
		++(current_player->points);
	}
	else
	{
		if ((*(*target_cell))->stone_in_cell)
		{
			if (level == 1 || level == 3)
				(*(*target_cell))->stone_in_cell->coordinate = 0;
			else
			{
				(*(*target_cell))->stone_in_cell->coordinate = -1;
				--(other_player->number_of_playable_stones);
				--(other_player->number_of_stones_on_board);
			}
		}
		(*(*target_cell))->stone_in_cell = chosen_stone;
		(*chosen_stone).coordinate = (*(*target_cell))->coordinate;
	}
	return (1);
}
