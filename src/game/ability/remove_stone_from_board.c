#include "twenty_squares.h"

void	remove_stone_from_board(Cell *cells, int ability, int level,
			Player *targeted_player, Player *current_player)
{
	int			i;
	int			j;
	int			random;
	int			is_input_valid;
	int			index_of_stones_on_board[7];
	char		input[INPUT_SIZE];
	Stone		*targeted_stone;
	const char	**tokens;

	is_input_valid = 0;
	memset(index_of_stones_on_board, 0, sizeof(index_of_stones_on_board));
	targeted_stone = 0;
	if (current_player->is_ai)
	{
		printf("%s %s.\n", current_player->name, ability == ABILITY_FIRE ?
			"selects an enemy stone" : "selects a stone");
		i = -1;
		j = 0;
		while (++i < 7)
		{
			if (targeted_player->stoneset[i].coordinate > 2)
			{
				if (ability == ABILITY_WATER || (ability == ABILITY_FIRE
					&& !targeted_player->stoneset[i].protected_by_earth))
					index_of_stones_on_board[j++] = i;
			}
		}
		random = rng_minmax(&rng_seed, 0, j - 1);
		random = index_of_stones_on_board[random];
		targeted_stone = &(targeted_player->stoneset[random]);
	}
	else
	{
		printf("%s - Stone:\n", targeted_player->name);
		while (!is_input_valid)
		{
			tokens = get_input();
			if (!tokens)
				break ;
			else if (tokens[0] && !tokens[1])
			{
				strncpy(input, tokens[0], INPUT_SIZE);
				input[0] = toupper(input[0]);
				i = -1;
				while (++i < 7)
				{
					if (!strcmp(targeted_player->stoneset[i].name, input)
						&& targeted_player->stoneset[i].coordinate > 2 
						&& (ability == ABILITY_WATER
						|| ((ability == ABILITY_FIRE
						&& !targeted_player->stoneset[i].protected_by_earth))))
					{
						is_input_valid = 1;
						targeted_stone = &(targeted_player->stoneset[i]);
						break ;
					}
				}
			}
			free_arr((void **)tokens, free);
		}
	}
	i = -1;
	while (++i < 20)
	{
		if ((cells + i)->coordinate == targeted_stone->coordinate)
		{
			(cells + i)->stone_in_cell = 0;
			targeted_stone->coordinate = ability == ABILITY_FIRE
				&& (level == 2 || level == 4) ? -1 : 0;
			break ;
		}
	}
	--(targeted_player->number_of_stones_on_board);
	printf("%s: %s.\n", targeted_player->name, targeted_stone->name);
	return ;
}
