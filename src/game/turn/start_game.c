#include "twenty_squares.h"

void	start_game(void)
{
	int			lvl;
	int			human_player;
	t_cell		*cells; // 21st is of coordinate "1"
	t_player	*players;

	cells = calloc(21, sizeof(t_cell));
	players = calloc(2, sizeof(t_player));
	while (1)
	{
		clear_window();
		printf("TWENTY SQUARES\n\n");
		printf("Level 1: Classic Infinite.\n"
			"Level 2: Classic Dispatch.\n"
			"Level 3: Deadly Sins Infinite.\n"
			"Level 4: Deadly Sins Dispatch.\n\n");
		lvl = ask_nbr(1, 4, "Which lvl would you like to play?");
		if (lvl <= 0)
			break ;
		printf("Level: %s.\n\n", lvl == 1 ? "Classic Infinite"
			: lvl == 2 ? "Classic Dispatch" : lvl == 3 ? "Deadly Sins Infinite"
			: "Deadly Sins Dispatch");
		human_player = ask_nbr(1, 2, "Which player would you want to be?") - 1;
		if (human_player < 0)
			break ;
		printf("Player: %s.\n\n", !human_player ? "Player One" : "Player Two");
		printf("Setting the game...\n");
		init_cells(cells);
		init_players(lvl, human_player, players, cells);
		sleep(1);
		game_loop(lvl, players, cells);
		if (ask_yes_no("\nPlay again?") <= 0)
			break ;
	}
	free(players);
	free(cells);
	return ;
}
