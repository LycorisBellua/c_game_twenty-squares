#include "twenty_squares.h"

static void	display_dist_options(t_game *game, int i_max);
static int	select_dist_with_input(t_game *game);
static int	get_pride_choice(t_game *game, int i_max, int dist);

int	select_dist_to_move(t_game *game)
{
	int	i_max;
	int	dist;

	i_max = 0;
	while (i_max < 4 && game->stone->moves[i_max + 1])
		++i_max;
	if (!i_max)
		dist = game->stone->moves[i_max];
	else if (game->player->is_ai)
		dist = game->stone->moves[rng_minmax(0, i_max)];
	else
	{
		display_dist_options(game, i_max);
		dist = select_dist_with_input(game);
	}
	printf("Movement: %d %s forwards.\n\n", dist, dist < 2 ? "cell" : "cells");
	if (!strcmp(game->stone->name, "P"))
		dist = get_pride_choice(game, i_max, dist);
	return (dist);
}

static void	display_dist_options(t_game *game, int i_max)
{
	int	i;

	printf("How many cells forwards should the stone move? ");
	i = -1;
	while (++i < i_max)
		printf("%d - ", game->stone->moves[i]);
	printf("%d.\n\n", game->stone->moves[i]);
	return ;
}

static int	select_dist_with_input(t_game *game)
{
	int			i;
	int			dist;
	const char	**tokens;

	dist = 0;
	while (1)
	{
		tokens = get_input();
		if (!tokens)
			return (0);
		else if (tokens[0] && !tokens[1])
		{
			dist = atoi(tokens[0]);
			free_arr((void **)tokens, free);
			i = -1;
			while (++i < 4 && game->stone->moves[i] == dist)
				;
			if (dist && i < 4)
				return (dist);
		}
	}
	return (0);
}

static int	get_pride_choice(t_game *game, int i_max, int dist)
{
	int pride_choice;

	pride_choice = rng_minmax(0, i_max);
	if (game->stone->moves[pride_choice] == dist)
	{
		printf("Pride refuses to move. The turn passes.\n\n");
		return (0);
	}
	printf("\"%s\", huh? Pride will move somewhere else.\n\n",
		get_dist_name(dist));
	return (game->stone->moves[pride_choice]);
}
