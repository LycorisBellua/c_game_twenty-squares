#include "twenty_squares.h"

t_stone	*select_stone(t_player *player)
{
	int			i;
	int			j;
	int			random;
	int			is_input_valid;
	int			nbr_moveable;
	const char	*name_moveable[8];
	t_stone		*stone;
	const char	**tokens;

	nbr_moveable = 0;
	stone = 0;
	memset(name_moveable, 0, sizeof(name_moveable));
	// Print the available choices + set `name_moveable` and `nbr_moveable` at 
	// the same time
	printf("Stone:\n");
	name_moveable[0] = "QUIT";
	i = -1;
	j = 1;
	while (++i < 7)
	{
		if (player->stoneset[i].can_move)
		{
			printf("- %s ", player->stoneset[i].name);
			name_moveable[j++] = player->stoneset[i].name;
		}
	}
	nbr_moveable = j - 1;
	printf("-\n\n");
	if (player->is_ai)
	{
		random = rng_minmax(1, nbr_moveable);
		i = -1;
		while (++i < 7)
		{
			if (!strcmp(player->stoneset[i].name, name_moveable[random]))
			{
				stone = &player->stoneset[i];
				printf("Stone: %s.\n\n", stone->name_long);
				break ;
			}
		}
		return (stone);
	}
	// `nbr_moveable` is incremented to take "QUIT" into account in the inner 
	// loop
	++nbr_moveable;
	is_input_valid = 0;
	while (!is_input_valid)
	{
		tokens = get_input();
		if (!tokens)
			break ;
		else if (tokens[0] && !tokens[1])
		{
			if (!strcmp(tokens[0], "QUIT"))
				is_input_valid = 1;
			else
			{
				i = -1;
				while (++i < nbr_moveable)
				{
					if (!strcmp(tokens[0], name_moveable[i]))
					{
						is_input_valid = 1;
						j = -1;
						while (++j < 7)
						{
							if (!strcmp(player->stoneset[j].name, name_moveable[i]))
							{
								stone = &player->stoneset[j];
								printf("Stone: %s.\n\n", stone->name_long);
								break ;
							}
						}
						break ;
					}
				}
			}
		}
		free_arr((void **)tokens, free);
	}
	return (stone);
}
