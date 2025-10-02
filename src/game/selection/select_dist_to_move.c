#include "twenty_squares.h"

int	select_dist_to_move(t_game *game)
{
	int			i;
	int			i_min;
	int			i_max;
	int			dist;
	int			is_dist_valid;
	const char	**tokens;

	i_min = -1;
	i_max = 0;
	is_dist_valid = 0;
	i = -1;
	while (++i < 4)
	{
		if (game->stone->moves[i])
		{
			if (i_min < 0)
				i_min = i;
			i_max = i;
		}
	}
	// Lust doesn't have a special move.
	// Pride is handled in `move_game->stone`.
	// Wrath and Greed are handled in `can_game->stone_move_ds`.
	if (i_min == i_max || !strcmp(game->stone->name_long, "Gluttony"))
		dist = game->stone->moves[i_max];
	else if (!strcmp(game->stone->name_long, "Sloth"))
		dist = game->stone->moves[i_min];
	else if (game->player->is_ai || !strcmp(game->stone->name_long, "Envy"))
		dist = game->stone->moves[rng_minmax(i_min, i_max)];
	else
	{
		printf("How many cells forwards should the game->stone move? ");
		i = i_min - 1;
		while (++i < i_max)
			printf("%d - ", game->stone->moves[i]);
		printf("%d.\n\n", game->stone->moves[i]);
		dist = 0;
		while (!is_dist_valid)
		{
			tokens = get_input();
			if (!tokens)
				break ;
			else if (tokens[0] && !tokens[1])
			{
				dist = atoi(tokens[0]);
				if (dist || !strcmp(tokens[0], "0"))
				{
					i = i_min - 1;
					while (++i <= i_max)
					{
						if (dist
							== game->stone->moves[i])
						{
							is_dist_valid = 1;
							break ;
						}
					}
				}
			}
			free_arr((void **)tokens, free);
		}
	}
	printf("Movement: %d %s forwards.\n\n", dist, dist < 2 ? "cell" : "cells");
	return (dist);
}
