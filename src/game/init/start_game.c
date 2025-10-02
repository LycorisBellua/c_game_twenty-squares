#include "twenty_squares.h"

static void	set_game(t_game *game);
static int	set_ai_player(const char *arg, t_player *players);

void	start_game(const char *arg)
{
	t_game	game;

	init_cells(&game);
	init_players(&game);
	do
	{
		clear_window();
		printf("TWENTY SQUARES\n\n");
		printf("Level 1: %s.\nLevel 2: %s.\nLevel 3: %s.\nLevel 4: %s.\n\n",
			get_level_name(1), get_level_name(2), get_level_name(3),
			get_level_name(4));
		game.lvl = ask_nbr(1, 4, "Which lvl would you like to play?");
		if (game.lvl <= 0)
			break ;
		printf("Level: %s.\n\n", get_level_name(game.lvl));
		if (!set_ai_player(arg, game.players))
			break ;
		printf("Setting the game...\n");
		set_game(&game);
		sleep(1);
		game_loop(&game);
	} while (ask_yes_no("\nPlay again?") > 0);
	return ;
}

static void	set_game(t_game *game)
{
	game->turn_nbr = 0;
	game->dice = 0;
	game->dist_to_move = 0;
	game->nbr_moveable = 0;
	game->has_stone_moved = 0;
	game->is_turn_played_twice = 0;
	game->stone = 0;
	game->cell = 0;
	game->player = 0;
	game->other_player = 0;
	reset_cells(game);
	reset_players(game);
	return ;
}

static int	set_ai_player(const char *arg, t_player *players)
{
	int	ai_player;

	if ((arg && !strcmp(arg, "opponent_human"))
		|| (!arg && ask_yes_no("Do you want an AI opponent?") != 1))
		ai_player = 2;
	else
	{
		ai_player = ask_nbr(1, 2, "Which player would you want to be?");
		if (!ai_player)
			return (0);
		ai_player = ai_player % 2;
		printf("Player: %s.\n\n", get_player_name(!ai_player));
		players[0].is_ai = ai_player == players[0].id ? 1 : 0;
		players[1].is_ai = ai_player == players[1].id ? 1 : 0;
	}
	return (1);
}
