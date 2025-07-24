#include "twenty_squares.h"

int	select_number_of_cells_forward(const Player *current_player,
		const Stone *chosen_stone)
{
	int			i;
	int			min_index;
	int			max_index;
	int			chosen_number;
	int			is_chosen_number_valid;
	const char	**tokens;

	min_index = -1;
	is_chosen_number_valid = 0;
	i = -1;
	while (++i < 4)
	{
		if (chosen_stone->possible_movements[i])
		{
			if (min_index < 0)
				min_index = i;
			max_index = i;
		}
	}
	// Lust doesn't have a special move.
	// Pride is handled in move_stone().
	// Wrath and Greed are handled in can_this_ds_stone_move().
	if (min_index == max_index || chosen_stone->id == ID_STONE_GLUTTONY)
	{
		chosen_number = chosen_stone->possible_movements[max_index];
	}
	else if (chosen_stone->id == ID_STONE_SLOTH)
	{
		chosen_number = chosen_stone->possible_movements[min_index];
	}
	else if (current_player->is_ai || chosen_stone->id == ID_STONE_ENVY)
	{
		chosen_number = chosen_stone->possible_movements[rng_minmax(&rng_seed,
			min_index, max_index)];
	}
	else
	{
		printf("How many cells forwards should the stone move? ");
		i = min_index - 1;
		while (++i < max_index)
			printf("%d - ", chosen_stone->possible_movements[i]);
		printf("%d.\n\n", chosen_stone->possible_movements[i]);
		while (!is_chosen_number_valid)
		{
			tokens = get_input();
			if (!tokens)
				break ;
			else if (tokens[0] && !tokens[1])
			{
				chosen_number = atoi(tokens[0]);
				if (!chosen_number || !strcmp(tokens[0], "0"))
				{
					i = min_index - 1;
					while (++i <= max_index)
					{
						if (chosen_number
							== chosen_stone->possible_movements[i])
						{
							is_chosen_number_valid = 1;
							break ;
						}
					}
				}
			}
			free_arr((void **)tokens, free);
		}
		printf("\n");
	}
	printf("Movement: %d %s forwards.\n",
		chosen_number, chosen_number == 1 ? "cell" : "cells");
	return (chosen_number);
}
