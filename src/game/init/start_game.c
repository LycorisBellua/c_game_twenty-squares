#include "twenty_squares.h"

static int	set_ai_player(const char *arg, int *ai_player);

void	start_game(const char *arg)
{
	int			lvl;
	int			ai_player;
	t_cell		cells[21]; // 21st is of coordinate "1"
	t_player	players[2];

	do
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
		if (!set_ai_player(arg, &ai_player))
			break ;
		printf("Setting the game...\n");
		init_cells(cells);
		init_players(lvl, ai_player, players, cells);
		sleep(1);
		game_loop(lvl, players, cells);
	} while (ask_yes_no("\nPlay again?") > 0);
	return ;
}

static int	set_ai_player(const char *arg, int *ai_player)
{
	if ((arg && !strcmp(arg, "opponent_human"))
		|| (!arg && ask_yes_no("Do you want an AI opponent?") != 1))
		*ai_player = 2;
	else
	{
		*ai_player = ask_nbr(1, 2, "Which player would you want to be?");
		if (!*ai_player)
			return (0);
		*ai_player = *ai_player % 2;
		printf("Player: %s.\n\n", *ai_player ? "Player One" : "Player Two");
	}
	return (1);
}
