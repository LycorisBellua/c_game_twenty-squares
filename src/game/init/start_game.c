#include "twenty_squares.h"

static int	set_ai_player(const char *arg, int *ai_player);

void	start_game(const char *arg)
{
	int			lvl;
	int			ai_player;
	t_cell		cells[8][3];
	t_player	players[2];

	init_cells(cells);
	init_players(players, cells);
	do
	{
		clear_window();
		printf("TWENTY SQUARES\n\n");
		printf("Level 1: %s.\nLevel 2: %s.\nLevel 3: %s.\nLevel 4: %s.\n\n",
			get_level_name(1), get_level_name(2), get_level_name(3),
			get_level_name(4));
		lvl = ask_nbr(1, 4, "Which lvl would you like to play?");
		if (lvl <= 0)
			break ;
		printf("Level: %s.\n\n", get_level_name(lvl));
		if (!set_ai_player(arg, &ai_player))
			break ;
		printf("Setting the game...\n");
		reset_cells(cells);
		reset_players(players, ai_player, lvl);
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
		printf("Player: %s.\n\n", get_player_name(!*ai_player));
	}
	return (1);
}
