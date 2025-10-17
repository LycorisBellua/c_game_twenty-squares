#include "twenty_squares.h"

static void	increment_turn(t_game *game);
static int	throw_dice(t_game *game);
static int	select_and_move_stone(t_game *game);
static int	determine_winner(t_game *game);

void	game_loop(t_game *game)
{
	while (1)
	{
		increment_turn(game);
		if (!throw_dice(game))
			continue ;
		else if (!select_and_move_stone(game))
			break ;
		else if (game->stone->cell->is_rosette)
		{
			printf("This cell is a rosette.\nEffects: The current player gets "
				"a free turn and the stone is untouchable while standing on "
				"the cell.\n\n");
			game->is_turn_played_twice = 1;
			press_enter_to_continue();
		}
		else if (determine_winner(game))
			break ;
	}
	return ;
}

static void	increment_turn(t_game *game)
{
	t_player	*tmp;

	if (!game->turn_nbr)
	{
		game->player = &game->players[0];
		game->other_player = &game->players[1];
	}
	else if (!game->is_turn_played_twice)
	{
		tmp = game->player;
		game->player = game->other_player;
		game->other_player = tmp;
	}
	game->is_turn_played_twice = 0;
	++game->turn_nbr;
	print_board(game);
	return ;
}

static int	throw_dice(t_game *game)
{
	game->dice = rng_minmax(0, 4);
	if (can_any_stone_move(game))
		return (1);
	printf("Dice: %d. No stone can move. The turn passes to the other player."
		"\n\n", game->dice);
	press_enter_to_continue();
	return (0);
}

static int	select_and_move_stone(t_game *game)
{
	int	i;

	printf("Enter 'Quit' to leave.\n\nDice: %d.\n", game->dice);
	printf("Stone:\n");
	i = -1;
	while (++i < 7)
	{
		if (game->player->stones[i].can_move)
			printf("- %s ", game->player->stones[i].name);
	}
	printf("-\n\n");
	game->stone = select_stone(game->player);
	if (!game->stone)
	{
		printf("You're quitting the game...\n");
		return (0);
	}
	printf("Stone: %s.\n\n", game->stone->name_long);
	game->dist_to_move = select_dist_to_move(game);
	move_stone(game);
	press_enter_to_continue();
	print_board(game);
	return (1);
}

static int	determine_winner(t_game *game)
{
	int	winner;

	if (!game->players[0].nbr_playable || !game->players[1].nbr_playable)
	{
		if (game->players[0].points == game->players[1].points)
			winner = !game->players[0].nbr_playable;
		else if (game->players[0].points > game->players[1].points)
			winner = 0;
		else
			winner = 1;
		printf("The game has ended. The winner is %s!\n",
			get_player_name(winner));
		return (1);
	}
	return (0);
}
