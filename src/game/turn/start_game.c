#include "twenty_squares.h"

void	start_game(void)
{
	int		level;
	int		human_player;
	Cell	*cells; // 21st is of coordinate "1"
	Player	*players;

	cells = calloc(21, sizeof(Cell));
	players = calloc(2, sizeof(Player));
	while (1)
	{
		clear_window();
		printf("TWENTY SQUARES\n\n");
		printf("Level 1: Classic Infinite.\n"
			"Level 2: Classic Dispatch.\n"
			"Level 3: Deadly Sins Infinite.\n"
			"Level 4: Deadly Sins Dispatch.\n\n");
		level = ask_nbr(1, 4, "Which level would you like to play?");
		if (level <= 0)
			break ;
		printf("Level: %s.\n\n",
			level == 1 ? "Classic Infinite"
			: level == 2 ? "Classic Dispatch"
			: level == 3 ? "Deadly Sins Infinite"
			: "Deadly Sins Dispatch");
		human_player = ask_nbr(1, 2, "Which player would you want to be?") - 1;
		if (human_player < 0)
			break ;
		printf("Player: %s.\n\n", !human_player ? "Player One" : "Player Two");
		printf("Setting the game...\n");
		initialize_cells(cells);
		initialize_players(level, human_player, players, cells);
		sleep(1);
		game_loop(level, players, cells);
		if (ask_yes_no("\nPlay again?") <= 0)
			break ;
	}
	free(players);
	free(cells);
	return ;
}
