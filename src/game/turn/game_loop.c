#include "twenty_squares.h"

static void	increment_turn(t_game *game);
static int	determine_winner(t_game *game);

void	game_loop(t_game *game)
{
	while (1)
	{
		increment_turn(game);
		print_board(game);
		game->dice = rng_minmax(0, 4);
		/**/
		game->nbr_moveable = set_nbr_moveable_and_can_move(game->player, game->lvl, game->dice);
		if (!game->nbr_moveable)
		{
			printf("Dice: %d. No stone can move. The turn passes to the other "
				"player.\n\n", game->dice);
			press_enter_to_continue();
			continue ;
		}
		printf("Enter 'Quit' to leave.\n\nDice: %d.\n", game->dice);
		game->stone = select_stone(game->player);
		if (!game->stone)
		{
			printf("You're quitting the game->..\n");
			break ;
		}
		game->dist_to_move = game->lvl < 3 ? game->dice : select_dist_to_move(game);
		game->has_stone_moved = move_stone(game);
		if (game->has_stone_moved)
			game->stone->is_protected = 0;
		press_enter_to_continue();
		if (game->has_stone_moved)
		{
			print_board(game);
			if (determine_winner(game))
				break ;
			else if (game->cell->is_rosette)
			{
				printf("This cell is a rosette.\nEffects: The current player "
					"gets a free turn and the stone is untouchable while "
					"standing on the cell.\n\n");
				game->is_turn_played_twice = 1;
				game->stone->is_protected = 1;
				press_enter_to_continue();
			}
		}
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
	return ;
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
