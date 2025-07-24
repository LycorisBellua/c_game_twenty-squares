#include "twenty_squares.h"

void	start_game(void)
{
	int level, human_player;
	Cell* all_cells = calloc(21, sizeof(Cell)); /* 21st is of coordinate "1" */
	Player* players = calloc(2, sizeof(Player));

	while (1)
	{
		clear_window();
		printf("TWENTY SQUARES\n\n");
		printf("Level 1: Classic Infinite.\n"
			"Level 2: Classic Dispatch.\n"
			"Level 3: Deadly Sins Infinite.\n"
			"Level 4: Deadly Sins Dispatch.\n\n");
		level = get_number_input(1, 4, "Which level would you like to play?");
		printf("Level: %s.\n\n",
			level == 1 ? "Classic Infinite"
			: level == 2 ? "Classic Dispatch"
			: level == 3 ? "Deadly Sins Infinite"
			: "Deadly Sins Dispatch");
		human_player = get_number_input(1, 2,
			"Which player would you want to be?") - 1;
		printf("Player: %s.\n\n", !human_player ? "Player One" : "Player Two");

		printf("Setting the game...\n");
		initialize_all_cells(all_cells);
		initialize_players(level, human_player, players, all_cells);
		sleep(1);
		game_loop(level, players, all_cells);

		if (!get_yes_no_input("\nPlay again?"))
		{
			free(players);
			free(all_cells);
			break;
		}
	}
	return;
}

void	game_loop(int level, Player *players, Cell *all_cells)
{
	char input[INPUT_SIZE] = {0};
	int yes_no_quit = -1;
	int number_of_turns = 1, dice, number_of_cells_forward, 
		number_of_moveable_stones, ability, ds_decision;
	int has_stone_moved, is_turn_played_twice;
	Stone* chosen_stone;
	Cell** target_cell = 0;
	Player *current_player, *other_player;

	/* target_cell is a double pointer here, and a triple pointer in fonctions, 
		so it can take a cell's address through current_player. It wouldn't 
		work otherwise. Am I missing something? */

	while (strcmp(input, "quit"))
	{
		/* (number_of_turns % 2) --> 1 --> 1 is true --> number_of_turns is an 
			odd number.
			(number_of_turns & 1) only works on twos-complement machines. If 
			it's a 1-complement, use "1U" instead of "1" */
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
		ds_decision = DS_DECISION_PLAYER;
		dice = rng_minmax(&rng_seed, 0, 4);
		number_of_moveable_stones = !dice ? 0
			: set_number_of_moveable_stones_and_every_can_stone_move
			(current_player, level, dice);
		print_board(number_of_turns, level, current_player->id, players,
			all_cells);

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
					chosen_stone->protected_by_earth = 0;
				press_enter_to_continue();
				if (has_stone_moved)
				{
					print_board(number_of_turns, level, current_player->id,
						players, all_cells);
					determine_winner(input, players);

					if (strcmp(input, "quit"))
					{
						ability = set_ability(level, &target_cell, players,
							current_player);
						if (ability != ABILITY_NONE)
						{
							printf("Enter 'Quit' to leave.\n\n");
							describe_ability(ability, dice);
							ds_decision = ds_stones_handle_ability(chosen_stone,
								ability, level, current_player, other_player);
							yes_no_quit = select_use_ability(current_player,
								ability, ds_decision, &target_cell);

							if (yes_no_quit == -1)
							{
								memcpy(input, "quit", INPUT_SIZE);
								printf("\nYou're quitting the game...\n\n");
							}
							else if (!yes_no_quit)
								press_enter_to_continue();
							else
							{
								if (ability == ABILITY_CLASSIC
									|| ability == ABILITY_AIR)
									is_turn_played_twice = 1;
								if (ability == ABILITY_CLASSIC
									|| ability == ABILITY_EARTH)
								{
									(*target_cell)->ability = ABILITY_EARTH;
									chosen_stone->protected_by_earth = 1;
								}
								press_enter_to_continue();

								if (ability == ABILITY_WATER
									|| ability == ABILITY_FIRE)
								{
									printf("Enter 'Quit' to leave.\n\n");
									print_board(number_of_turns, level,
										current_player->id, players, all_cells);
									ability == ABILITY_FIRE ?
										execute_ability_fire(level, players,
										current_player, all_cells) 
										: execute_ability_water(dice, level,
										players, current_player, all_cells);
									press_enter_to_continue();

									print_board(number_of_turns, level,
										current_player->id, players, all_cells);
									determine_winner(input, players);
								}
							}
						}
					}
				}
			}
		}

		if (!is_turn_played_twice)
			++number_of_turns;
	}
	press_enter_to_continue();
	return;
}

void	determine_winner(char *input, Player *players)
{
	int winner = 0;
	if (!PLAYER_ONE->number_of_playable_stones
		|| !PLAYER_TWO->number_of_playable_stones)
	{
		if (PLAYER_ONE->points > PLAYER_TWO->points)
			winner = 1;
		else if (PLAYER_TWO->points > PLAYER_ONE->points)
			winner = 2;
		else if (PLAYER_ONE->points == PLAYER_TWO->points)
			winner = 3;
		printf("The game has ended. The winner is %s!\n",
			!winner ? "[ERROR]" : winner == 1 ? PLAYER_ONE->name
			: winner == 2 ? PLAYER_TWO->name : "both of you");
		memcpy(input, "quit", INPUT_SIZE);
	}
	return;
}
