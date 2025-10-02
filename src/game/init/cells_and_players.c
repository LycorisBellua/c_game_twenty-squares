#include "twenty_squares.h"

void	init_cells(t_game *game)
{
	game->cells[0][0].is_rosette = 1;
	game->cells[6][0].is_rosette = 1;
	game->cells[3][1].is_rosette = 1;
	game->cells[0][2].is_rosette = 1;
	game->cells[6][2].is_rosette = 1;
	return ;
}

void	reset_cells(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 8)
	{
		x = -1;
		while (++x < 3)
			game->cells[y][x].stone = 0;
	}
	return ;
}

void	init_players(t_game *game)
{
	game->players[0].id = 0;
	game->players[0].track[0] = &game->cells[4][0];
	game->players[0].track[1] = &game->cells[3][0];
	game->players[0].track[2] = &game->cells[2][0];
	game->players[0].track[3] = &game->cells[1][0];
	game->players[0].track[4] = &game->cells[0][0];
	game->players[0].track[5] = &game->cells[0][1];
	game->players[0].track[6] = &game->cells[1][1];
	game->players[0].track[7] = &game->cells[2][1];
	game->players[0].track[8] = &game->cells[3][1];
	game->players[0].track[9] = &game->cells[4][1];
	game->players[0].track[10] = &game->cells[5][1];
	game->players[0].track[11] = &game->cells[6][1];
	game->players[0].track[12] = &game->cells[7][1];
	game->players[0].track[13] = &game->cells[7][0];
	game->players[0].track[14] = &game->cells[6][0];
	game->players[0].track[15] = &game->cells[5][0];
	game->players[1].id = 1;
	game->players[1].track[0] = &game->cells[4][2];
	game->players[1].track[1] = &game->cells[3][2];
	game->players[1].track[2] = &game->cells[2][2];
	game->players[1].track[3] = &game->cells[1][2];
	game->players[1].track[4] = &game->cells[0][2];
	game->players[1].track[5] = &game->cells[0][1];
	game->players[1].track[6] = &game->cells[1][1];
	game->players[1].track[7] = &game->cells[2][1];
	game->players[1].track[8] = &game->cells[3][1];
	game->players[1].track[9] = &game->cells[4][1];
	game->players[1].track[10] = &game->cells[5][1];
	game->players[1].track[11] = &game->cells[6][1];
	game->players[1].track[12] = &game->cells[7][1];
	game->players[1].track[13] = &game->cells[7][2];
	game->players[1].track[14] = &game->cells[6][2];
	game->players[1].track[15] = &game->cells[5][2];
	return ;
}

void	reset_players(t_game *game)
{
	game->players[0].points = 0;
	game->players[0].nbr_playable = 7;
	game->players[1].points = 0;
	game->players[1].nbr_playable = 7;
	int i = -1;
	while (++i < 7)
	{
		game->players[0].stones[i].can_move = 1;
		game->players[0].stones[i].player_id = game->players[0].id;
		game->players[0].stones[i].cell = game->players[0].track[0];
		game->players[0].stones[i].name = get_stone_name(game->lvl, i, 0);
		game->players[0].stones[i].name_long = get_stone_name(game->lvl, i, 1);
		game->players[1].stones[i].can_move = 1;
		game->players[1].stones[i].player_id = game->players[1].id;
		game->players[1].stones[i].cell = game->players[1].track[0];
		game->players[1].stones[i].name = get_stone_name(game->lvl, i, 0);
		game->players[1].stones[i].name_long = get_stone_name(game->lvl, i, 1);
	}
	return ;
}
