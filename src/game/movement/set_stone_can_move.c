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
	int	index_enemy;

	index_enemy = get_cell_index_next_enemy(game->player, cell_index, 1);
	if (index_enemy < 0)
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
	while (++i <= game->dice && cell_index + i <= index_enemy)
	{
		if (!game->player->track[cell_index + i]->is_rosette)
			stone->moves[0] = i;
	}
	return (!!stone->moves[0]);
}

static int	can_stone_move_greed(t_game *game, t_stone *stone, int cell_index)
{
	int	i;
	int	index_rosette;
	int	index_enemy;
	int	move_farthest;

	index_rosette = get_cell_index_next_rosette(game->player, cell_index, 0);
	index_enemy = get_cell_index_next_enemy(game->player, cell_index, 0);
	move_farthest = 0;
	i = 0;
	while (++i <= game->dice && cell_index + i <= INDEX_VICTORY)
	{
		if (!game->player->track[cell_index + i]->stone)
			move_farthest = i;
	}
	if (index_rosette >= 0 && index_rosette - cell_index <= game->dice)
		stone->moves[0] = index_rosette - cell_index;
	else if (index_enemy >= 0 && index_enemy - cell_index <= game->dice)
		stone->moves[0] = index_enemy - cell_index;
	else
		stone->moves[0] = move_farthest;
	return (!!stone->moves[0]);
}
