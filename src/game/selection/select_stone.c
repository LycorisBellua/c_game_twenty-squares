#include "twenty_squares.h"

t_stone	*select_stone(char *input, t_player *player)
{
	int			i;
	int			j;
	int			random;
	int			is_input_valid;
	int			nbr_moveable;
	char		name_moveable[8][STONE_NAME_LEN];
	t_stone		*stone;
	const char	**tokens;

	is_input_valid = 0;
	nbr_moveable = 0;
	memset(name_moveable, 0, sizeof(name_moveable));
	// Print the available choices + set `name_moveable` and `nbr_moveable` at 
	// the same time
	printf("Stone:\n");
	memcpy(name_moveable[0], "quit", STONE_NAME_LEN);
	i = -1;
	j = 1;
	while (++i < 7)
	{
		if (player->stoneset[i].can_move)
		{
			printf("- %s ", player->stoneset[i].name);
			memcpy(name_moveable[j++], player->stoneset[i].name,
				STONE_NAME_LEN);
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
				memcpy(input, name_moveable[random], STONE_NAME_LEN);
				stone = &player->stoneset[i];
				printf("Stone: %s.\n\n", input);
				break ;
			}
		}
		return (stone);
	}
	i = 0;
	while (++i < 8)
		name_moveable[i][0] = tolower(name_moveable[i][0]);
	// `nbr_moveable` is incremented to take "quit" into account in the inner 
	// loop
	++nbr_moveable;
	strncpy(input, "quit", INPUT_LEN);
	while (!is_input_valid)
	{
		tokens = get_input();
		if (!tokens)
			break ;
		else if (tokens[0] && !tokens[1])
		{
			if (!strcmp(tokens[0], "quit"))
				is_input_valid = 1;
			else
			{
				i = -1;
				while (++i < nbr_moveable)
				{
					if (!strcmp(tokens[0], name_moveable[i]))
					{
						is_input_valid = 1;
						strncpy(input, name_moveable[i], INPUT_LEN);
						input[0] = toupper(input[0]);
					}
				}
			}
		}
		free_arr((void **)tokens, free);
	}
	if (strcmp(input, "quit"))
	{
		printf("Stone: %s.\n\n", input);
		i = -1;
		while (++i < 7)
		{
			if (!strcmp(player->stoneset[i].name, input))
			{
				stone = &player->stoneset[i];
				break ;
			}
		}
	}
	return (stone);
}
