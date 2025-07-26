#include "twenty_squares.h"

void	game_loop(int level, Player *players, Cell *cells)
{
	char	input[INPUT_SIZE];
	int		number_of_turns;
	int		dice;
	int		number_of_cells_forward;
	int		number_of_moveable_stones;
	int		has_stone_moved;
	int		is_turn_played_twice;
	Stone	*chosen_stone;
	Cell	**target_cell;
	Player	*current_player;
	Player	*other_player;

	memset(input, 0, sizeof(input));
	number_of_turns = 1;
	target_cell = 0;
	// target_cell is a double pointer here, and a triple pointer in fonctions, 
	// so it can take a cell's address through current_player. It wouldn't 
	// work otherwise. Am I missing something?
	while (strcmp(input, "quit"))
	{
		// (number_of_turns % 2) --> 1 --> 1 is true --> number_of_turns is an 
		// odd number.
		// (number_of_turns & 1) only works on twos-complement machines. If 
		// it's a 1-complement, use "1U" instead of "1"
		if (number_of_turns & 1)
		{
			current_player = players + 0;
			other_player = players + 1;
		}
		else
		{
			current_player = players + 1;
			other_player = players + 0;
		}
		is_turn_played_twice = 0;
		dice = rng_minmax(&rng_seed, 0, 4);
		number_of_moveable_stones = !dice ? 0
			: set_number_of_moveable_stones_and_every_can_stone_move
			(current_player, level, dice);
		print_board(number_of_turns, level, current_player->id, players,
			cells);
		if (!dice)
		{
			printf("Dice: 0. The turn passes to the other player.\n");
			memcpy(input, "", LENGTH_STONE_NAME);
			press_enter_to_continue();
		}
		else if (!number_of_moveable_stones)
		{
			printf("Dice: %d. No stone can move. The turn passes to the other "
				"player.\n", dice);
			memcpy(input, "", LENGTH_STONE_NAME);
			press_enter_to_continue();
		}
		else
		{
			printf("Enter 'Quit' to leave.\n\n");
			printf("Dice: %d.\n", dice);
			chosen_stone = select_stone(input, current_player);
			if (!strcmp(input, "quit"))
				printf("\nYou're quitting the game...\n\n");
			else
			{
				number_of_cells_forward = level > 2 ?
					select_number_of_cells_forward(current_player, chosen_stone)
					: dice;
				has_stone_moved = move_stone(level, number_of_cells_forward,
					chosen_stone, &target_cell, current_player, other_player);
				if (has_stone_moved)
					chosen_stone->is_protected = 0;
				press_enter_to_continue();
				if (has_stone_moved)
				{
					print_board(number_of_turns, level, current_player->id,
						players, cells);
					determine_winner(input, players);
					if (strcmp(input, "quit"))
					{
						if ((*target_cell)->is_rosette)
						{
							printf("This cell is a rosette.\n");
							printf("Effects: The current player gets a free "
								"turn and the stone is untouchable while "
								"standing on the cell.\n\n");
							is_turn_played_twice = 1;
							chosen_stone->is_protected = 1;
							press_enter_to_continue();
						}
					}
				}
			}
		}
		if (!is_turn_played_twice)
			++number_of_turns;
	}
	press_enter_to_continue();
	return ;
}
