#include "twenty_squares.h"

static int	pride_movement(t_game *game, int dist);

int	select_dist_to_move(t_game *game)
{
	int			i;
	int			i_min;
	int			i_max;
	int			dist;
	int			is_dist_valid;
	const char	**tokens;

	if (game->lvl < 3)
		return (game->dice);
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
	// Wrath and Greed are handled in `can_move->stone_move_deadlysins`.
	if (i_min == i_max || !strcmp(game->stone->name_long, "Gluttony"))
		dist = game->stone->moves[i_max];
	else if (!strcmp(game->stone->name_long, "Sloth"))
		dist = game->stone->moves[i_min];
	else if (game->player->is_ai || !strcmp(game->stone->name_long, "Envy"))
		dist = game->stone->moves[rng_minmax(i_min, i_max)];
	else
	{
		printf("How many cells forwards should the stone move? ");
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
	if (!strcmp(game->stone->name_long, "Pride"))
		dist = pride_movement(game, dist);
	return (dist);
}

static int	pride_movement(t_game *game, int dist)
{
	int	i;
	int pride_choice;

	i = -1;
	while (++i < 4)
	{
		if (!game->stone->moves[i])
			break ;
	}
	// (i - 1) is the last valid index of possible_movements.
	pride_choice = rng_minmax(0, i - 1);
	if (dist == game->stone->moves[pride_choice])
	{
		printf("Pride refuses to move. The turn passes.\n\n");
		dist = 0;
	}
	else
	{
		printf("\"%s\", huh? Pride will move somewhere else.\n\n",
			dist == 1 ? "One" : dist == 2 ? "Two" : dist == 3 ? "Three"
				: "Four");
		dist = game->stone->moves[pride_choice];
	}
	return (dist);
}
