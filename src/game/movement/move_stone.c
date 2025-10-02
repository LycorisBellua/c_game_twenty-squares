#include "twenty_squares.h"

int	move_stone(t_game *game)
{
	int	i;
	int	origin_cell_track_index;
	int	pride_choice;

	origin_cell_track_index = 0;
	game->cell = game->player->track[15];
	// I don't understand why, but `origin_cell_track_index` needs to be set to 
	// 0, or after the first time entering the function, the variable will take 
	// a garbage value
	i = 0;
	while (++i < 15)
	{
		if (game->stone->cell == game->player->track[i])
		{
			origin_cell_track_index = i;
			break ;
		}
	}
	if (!strcmp(game->stone->name_long, "Pride"))
	{
		// If possible, Pride wants to go out of bounds. As `cell` is already 
		// set to track index 15, which means "out of bounds", we don't need to 
		// update it.
		pride_choice = 0;
		i = -1;
		while (++i < 4)
		{
			if (!game->stone->moves[i])
				break ;
			if (origin_cell_track_index + game->stone->moves[i] >= 15)
			{
				pride_choice = 1;
				printf("Pride seizes the opportunity to get rid of %s, and "
					"leaves.\n\n", game->player->is_ai ? get_player_name(game->player->id) : "you");
				break ;
			}
		}
		// If pride couldn't go out of bounds, we need to find another dest.
		if (!pride_choice)
		{
			// (i - 1) is the last valid index of possible_movements.
			pride_choice = !(i - 1) ? 0 : rng_minmax(0, i - 1);
			if (game->dist_to_move == game->stone->moves[pride_choice])
			{
				printf("Pride refuses to move. The turn passes.\n\n");
				return (0);
			}
			else
			{
				printf("\"%s\", huh? Pride will move somewhere else.\n\n", 
					game->dist_to_move == 1 ? "One" : game->dist_to_move == 2 ? "Two" 
					: game->dist_to_move == 3 ? "Three" : "Four");
				game->dist_to_move = game->stone->moves[pride_choice];
			}
			if (game->stone->cell == game->player->track[INDEX_HOME])
				game->cell = game->player->track[game->dist_to_move];
			else
			{
				// If we are here, it means that the target cannot be out of 
				// bounds, so there's no need to check if it is.
				game->cell = game->player->track[origin_cell_track_index + game->dist_to_move];
			}
		}
	}
	else
	{
		if (game->stone->cell == game->player->track[INDEX_HOME])
			game->cell = game->player->track[game->dist_to_move];
		else if (origin_cell_track_index + game->dist_to_move < 15)
			game->cell = game->player->track[origin_cell_track_index + game->dist_to_move];
	}
	if (game->stone->cell != game->player->track[INDEX_HOME])
		game->player->track[origin_cell_track_index]->stone = 0;
	if (game->cell == game->player->track[INDEX_VICTORY])
	{
		game->stone->cell = game->player->track[INDEX_VICTORY];
		--game->player->nbr_playable;
		++game->player->points;
	}
	else
	{
		if (game->cell->stone)
		{
			if (game->lvl == 1 || game->lvl == 3)
				game->cell->stone->cell = game->player->track[INDEX_HOME];
			else
			{
				game->cell->stone->cell = 0;
				--game->other_player->nbr_playable;
			}
		}
		game->cell->stone = game->stone;
		game->stone->cell = game->cell;
	}
	return (1);
}
