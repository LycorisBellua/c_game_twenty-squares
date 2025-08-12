#include "twenty_squares.h"

static int	determine_winner(t_player *players);

void	game_loop(int lvl, t_player *players, t_cell *cells)
{
	int			quit;
	int			nbr_turns;
	int			dice;
	int			dist_to_move;
	int			nbr_moveable;
	int			has_stone_moved;
	int			is_turn_played_twice;
	t_stone		*stone;
	t_cell		*cell;
	t_player	*player;
	t_player	*other_player;

	quit = 0;
	nbr_turns = 1;
	cell = 0;
	while (!quit)
	{
		if (nbr_turns % 2)
		{
			player = &players[0];
			other_player = &players[1];
		}
		else
		{
			player = &players[1];
			other_player = &players[0];
		}
		is_turn_played_twice = 0;
		dice = rng_minmax(0, 4);
		nbr_moveable = !dice ? 0
			: set_nbr_moveable_and_can_move(player, lvl, dice);
		print_board(nbr_turns, lvl, player->id, players, cells);
		if (!dice)
		{
			printf("Dice: 0. The turn passes to the other player.\n\n");
			press_enter_to_continue();
		}
		else if (!nbr_moveable)
		{
			printf("Dice: %d. No stone can move. The turn passes to the other "
				"player.\n\n", dice);
			press_enter_to_continue();
		}
		else
		{
			printf("Enter 'Quit' to leave.\n\n");
			printf("Dice: %d.\n", dice);
			stone = select_stone(player);
			quit = !stone;
			if (quit)
				printf("You're quitting the game...\n");
			else
			{
				dist_to_move = lvl > 2 ? select_dist_to_move(player, stone)
					: dice;
				has_stone_moved = move_stone(lvl, dist_to_move, stone, &cell,
					player, other_player);
				if (has_stone_moved)
					stone->is_protected = 0;
				press_enter_to_continue();
				if (has_stone_moved)
				{
					print_board(nbr_turns, lvl, player->id, players, cells);
					quit = determine_winner(players);
					if (!quit)
					{
						if (cell->is_rosette)
						{
							printf("This cell is a rosette.\n");
							printf("Effects: The current player gets a free "
								"turn and the stone is untouchable while "
								"standing on the cell.\n\n");
							is_turn_played_twice = 1;
							stone->is_protected = 1;
							press_enter_to_continue();
						}
					}
				}
			}
		}
		if (!is_turn_played_twice)
			++nbr_turns;
	}
	return ;
}

static int	determine_winner(t_player *players)
{
	int	winner;

	if (!players[0].nbr_playable || !players[1].nbr_playable)
	{
		if (players[0].points == players[1].points)
			winner = !players[0].nbr_playable;
		else if (players[0].points > players[1].points)
			winner = 0;
		else
			winner = 1;
		printf("The game has ended. The winner is %s!\n", players[winner].name);
		return (1);
	}
	return (0);
}
