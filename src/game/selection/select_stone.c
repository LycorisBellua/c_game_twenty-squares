#include "twenty_squares.h"

Stone	*select_stone(char *input, Player *current_player)
{
	int i, j, random;
	int is_input_valid = 0;
	int number_of_moveable_stones = 0;
	char moveable_stones_names[8][LENGTH_STONE_NAME] = {0};
	Stone* chosen_stone;
	const char	**tokens;

	// Print the available choices + set moveable_stones_names and 
	// number_of_moveable_stones at the same time
	printf("Stone:\n");
	memcpy(moveable_stones_names[0], "quit", LENGTH_STONE_NAME);
	for (i = 0, j = 1; i < 7; ++i)
	{
		if (current_player->stoneset[i].can_stone_move)
		{
			printf("- %s ", current_player->stoneset[i].name);
			memcpy(moveable_stones_names[j++], current_player->stoneset[i].name,
				LENGTH_STONE_NAME);
		}
	}
	number_of_moveable_stones = j - 1;
	printf("-\n\n");

	if (current_player->is_ai)
	{
		random = rng_minmax(&rng_seed, 1, number_of_moveable_stones);
		for (i = 0; i < 7; ++i)
		{
			if (!strcmp(current_player->stoneset[i].name,
				moveable_stones_names[random]))
			{
				memcpy(input, moveable_stones_names[random], LENGTH_STONE_NAME);
				chosen_stone = &(current_player->stoneset[i]);
				printf("Stone: %s.\n\n", input);
				break;
			}
		}
		return chosen_stone;
	}
	for (i = 1; i < 8; ++i)
		moveable_stones_names[i][0] = tolower(moveable_stones_names[i][0]);

	// number_of_moveable_stones is incremented to take "quit" into account 
	// in the for loop
	++number_of_moveable_stones;
	strncpy(input, "quit", INPUT_SIZE);
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
				for (i = 0; i < number_of_moveable_stones; ++i)
				{
					if (!strcmp(tokens[0], moveable_stones_names[i]))
					{
						is_input_valid = 1;
						strncpy(input, moveable_stones_names[i], INPUT_SIZE);
						input[0] = toupper(input[0]);
					}
				}
			}
		}
		free_arr((void **)tokens, free);
	}

	if (strcmp(input, "quit"))
	{
		printf("\nStone: %s.\n\n", input);
		for (i = 0; i < 7; ++i)
		{
			if (!strcmp(current_player->stoneset[i].name, input))
			{
				chosen_stone = &(current_player->stoneset[i]);
				break;
			}
		}
	}
	return chosen_stone;
}
