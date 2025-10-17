#include "twenty_squares.h"

static t_stone	*select_stone_ai(t_player *player);
static int		is_stone_valid(t_player *player, const char *token,
					t_stone **stone);

t_stone	*select_stone(t_player *player)
{
	int			is_input_valid;
	t_stone		*stone;
	const char	**tokens;

	if (player->is_ai)
		return (select_stone_ai(player));
	stone = 0;
	is_input_valid = 0;
	while (!is_input_valid)
	{
		tokens = get_input();
		if (!tokens)
			break ;
		else if (tokens[0] && !tokens[1])
		{
			if (!strcmp(tokens[0], "QUIT")
				|| is_stone_valid(player, tokens[0], &stone))
				is_input_valid = 1;
		}
		free_arr((void **)tokens, free);
	}
	return (stone);
}

static t_stone	*select_stone_ai(t_player *player)
{
	int	random;

	while (1)
	{
		random = rng_minmax(0, 6);
		if (player->stones[random].can_move)
			break ;
	}
	return (&player->stones[random]);
}

static int	is_stone_valid(t_player *player, const char *token, t_stone **stone)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		if (!strcmp(token, player->stones[i].name))
		{
			if (player->stones[i].can_move)
			{
				*stone = &player->stones[i];
				return (1);
			}
			break ;
		}
	}
	return (0);
}
