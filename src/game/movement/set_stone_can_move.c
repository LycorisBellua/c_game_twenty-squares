#include "twenty_squares.h"

static int	can_stone_move_classic(t_game *game, t_stone *stone);
static int	can_stone_move_deadlysins(t_game *game, t_stone *stone);
static int	can_stone_move_wrath(t_game *game, t_stone *stone, int cell_index);
static int	can_stone_move_greed(t_game *game, t_stone *stone, int cell_index);

int	set_stone_can_move(t_game *game, t_stone *stone)
{
	if (game->lvl <= 2)
		stone->can_move = can_stone_move_classic(game, stone);
	else
		stone->can_move = can_stone_move_deadlysins(game, stone);
	return (stone->can_move);
}

static int	can_stone_move_classic(t_game *game, t_stone *stone)
{
	int		cell_index;
	t_cell	*cell;

	cell_index = get_cell_index(game->player, stone);
	if (!game->dice || cell_index < 0 || cell_index == INDEX_VICTORY
		|| cell_index + game->dice > INDEX_VICTORY)
		return (0);
	cell = game->player->track[cell_index + game->dice];
	return (!cell->stone
		|| (!cell->is_rosette && cell->stone->player_id != game->player->id));
}

static int	can_stone_move_deadlysins(t_game *game, t_stone *stone)
{
	int		i;
	int		j;
	int		cell_index;
	t_cell	*cell;

	memset(stone->moves, 0, sizeof(stone->moves));
	cell_index = get_cell_index(game->player, stone);
	if (!game->dice || cell_index < 0 || cell_index == INDEX_VICTORY)
		return (0);
	else if (!strcmp(stone->name_long, "Wrath"))
		return (can_stone_move_wrath(game, stone, cell_index));
	else if (!strcmp(stone->name_long, "Greed"))
		return (can_stone_move_greed(game, stone, cell_index));
	i = 0;
	j = 0;
	while (++i <= game->dice && cell_index + i <= INDEX_VICTORY)
	{
		cell = game->player->track[cell_index + i];
		if (!cell->stone
			|| (!cell->is_rosette
				&& cell->stone->player_id != game->player->id))
			stone->moves[j++] = i;
	}
	return (!!j);
}

static int	can_stone_move_wrath(t_game *game, t_stone *stone, int cell_index)
{
	int	i;
	int	cell_index_enemy;

	cell_index_enemy = get_cell_index_closest_enemy(game->player, cell_index);
	if (cell_index_enemy < 0)
	{
		i = 0;
		while (++i <= game->dice && cell_index + i <= INDEX_VICTORY)
		{
			if (!game->player->track[cell_index + i]->stone)
			{
				stone->moves[0] = i;
				return (1);
			}
		}
		return (0);
	}
	i = 0;
	while (++i <= game->dice && cell_index + i <= cell_index_enemy)
	{
		if (!game->player->track[cell_index + i]->is_rosette)
			stone->moves[0] = i;
	}
	return (!!stone->moves[0]);
}

static int	can_stone_move_greed(t_game *game, t_stone *stone, int cell_index)
{
	t_cell	*cell[4];
	memset(cell, 0, sizeof(cell));
	int i = 0;
	while (++i <= game->dice && cell_index + i <= INDEX_VICTORY)
		cell[i - 1] = game->player->track[cell_index + i];

	// Greed's first priority: An empty rosette
	if (cell[0]->is_rosette && !cell[0]->stone)
	{
		stone->moves[0] = 1;
		return (1);
	}
	else if (cell[1])
	{
		if (cell[1]->is_rosette && !cell[1]->stone)
		{
			stone->moves[0] = 2;
			return (1);
		}
		else if (cell[2])
		{
			if (cell[2]->is_rosette && !cell[2]->stone)
			{
				stone->moves[0] = 3;
				return (1);
			}
			else if (cell[3] && cell[3]->is_rosette && !cell[3]->stone)
			{
				stone->moves[0] = 4;
				return (1);
			}
		}
	}
	// Greed's second priority: The closest enemy not protected by the rosette
	if (cell[0]->stone && cell[0]->stone->player_id != game->player->id
		&& !cell[0]->is_rosette)
	{
		stone->moves[0] = 1;
		return (1);
	}
	else if (cell[1])
	{
		if (cell[1]->stone && cell[1]->stone->player_id != game->player->id
			&& !cell[1]->is_rosette)
		{
			stone->moves[0] = 2;
			return (1);
		}
		else if (cell[2])
		{
			if (cell[2]->stone && cell[2]->stone->player_id != game->player->id
				&& !cell[2]->is_rosette)
			{
				stone->moves[0] = 3;
				return (1);
			}
			else if (cell[3] && cell[3]->stone
				&& cell[3]->stone->player_id != game->player->id
				&& !cell[3]->is_rosette)
			{
				stone->moves[0] = 4;
				return (1);
			}
		}
	}
	// Greed's third priority: The farthest cell (empty, because if not it's 
	// either an ally stone or an unkillable enemy)
	if (cell[3] && !cell[3]->stone)
	{
		stone->moves[0] = 4;
		return (1);
	}
	else if (cell[2] && !cell[2]->stone)
	{
		stone->moves[0] = 3;
		return (1);
	}
	else if (cell[1] && !cell[1]->stone)
	{
		stone->moves[0] = 2;
		return (1);
	}
	else if (!cell[0]->stone)
	{
		stone->moves[0] = 1;
		return (1);
	}
	return (0);
}
