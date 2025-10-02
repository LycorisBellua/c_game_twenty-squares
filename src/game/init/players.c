#include "twenty_squares.h"

static void	init_player_one(t_player *players, t_cell cells[8][3]);
static void	init_player_two(t_player *players, t_cell cells[8][3]);

void	init_players(t_player *players, t_cell cells[8][3])
{
	init_player_one(players, cells);
	init_player_two(players, cells);
	return ;
}

void	reset_players(t_player *players, int ai_player, int lvl)
{
	players[0].is_ai = ai_player == players[0].id ? 1 : 0;
	players[0].points = 0;
	players[0].nbr_playable = 7;
	players[1].is_ai = ai_player == players[1].id ? 1 : 0;
	players[1].points = 0;
	players[1].nbr_playable = 7;
	int i = -1;
	while (++i < 7)
	{
		players[0].stoneset[i].can_move = 1;
		players[0].stoneset[i].player_id = players[0].id;
		players[0].stoneset[i].cell = players[0].track[0];
		players[0].stoneset[i].name = get_stone_name(lvl, i, 0);
		players[0].stoneset[i].name_long = get_stone_name(lvl, i, 1);
		players[1].stoneset[i].can_move = 1;
		players[1].stoneset[i].player_id = players[1].id;
		players[1].stoneset[i].cell = players[1].track[0];
		players[1].stoneset[i].name = get_stone_name(lvl, i, 0);
		players[1].stoneset[i].name_long = get_stone_name(lvl, i, 1);
	}
	return ;
}

static void	init_player_one(t_player *players, t_cell cells[8][3])
{
	players[0].id = 0;
	players[0].track[0] = &cells[4][0];
	players[0].track[1] = &cells[3][0];
	players[0].track[2] = &cells[2][0];
	players[0].track[3] = &cells[1][0];
	players[0].track[4] = &cells[0][0];
	players[0].track[5] = &cells[0][1];
	players[0].track[6] = &cells[1][1];
	players[0].track[7] = &cells[2][1];
	players[0].track[8] = &cells[3][1];
	players[0].track[9] = &cells[4][1];
	players[0].track[10] = &cells[5][1];
	players[0].track[11] = &cells[6][1];
	players[0].track[12] = &cells[7][1];
	players[0].track[13] = &cells[7][0];
	players[0].track[14] = &cells[6][0];
	players[0].track[15] = &cells[5][0];
	return ;
}

static void	init_player_two(t_player *players, t_cell cells[8][3])
{
	players[1].id = 1;
	players[1].track[0] = &cells[4][2];
	players[1].track[1] = &cells[3][2];
	players[1].track[2] = &cells[2][2];
	players[1].track[3] = &cells[1][2];
	players[1].track[4] = &cells[0][2];
	players[1].track[5] = &cells[0][1];
	players[1].track[6] = &cells[1][1];
	players[1].track[7] = &cells[2][1];
	players[1].track[8] = &cells[3][1];
	players[1].track[9] = &cells[4][1];
	players[1].track[10] = &cells[5][1];
	players[1].track[11] = &cells[6][1];
	players[1].track[12] = &cells[7][1];
	players[1].track[13] = &cells[7][2];
	players[1].track[14] = &cells[6][2];
	players[1].track[15] = &cells[5][2];
	return ;
}
