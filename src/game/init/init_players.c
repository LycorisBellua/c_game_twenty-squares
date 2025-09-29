#include "twenty_squares.h"

static void	init_player_one(int lvl, int ai_player, t_player *players,
				t_cell cells[8][3]);
static void	init_player_two(int lvl, int ai_player, t_player *players,
				t_cell cells[8][3]);

void	init_players(int lvl, int ai_player, t_player *players,
			t_cell cells[8][3])
{
	memset(players, 0, 2 * sizeof(t_player));
	init_player_one(lvl, ai_player, players, cells);
	init_player_two(lvl, ai_player, players, cells);
	return ;
}

static void	init_player_one(int lvl, int ai_player, t_player *players,
				t_cell cells[8][3])
{
	players[0].id = 0;
	strncpy(players[0].name, "Player One", PLAYER_NAME_LEN);
	players[0].is_ai = ai_player == players[0].id ? 1 : 0;
	players[0].nbr_playable = 7;
	if (lvl > 2)
	{
		players[0].stoneset[0].name_long = "Lust";
		players[0].stoneset[0].name = "L";
		players[0].stoneset[0].id = ID_STONE_LUST;
		players[0].stoneset[0].player_id = 0;
		players[0].stoneset[0].can_move = 1;
		players[0].stoneset[1].name_long = "Pride";
		players[0].stoneset[1].name = "P";
		players[0].stoneset[1].id = ID_STONE_PRIDE;
		players[0].stoneset[1].player_id = 0;
		players[0].stoneset[1].can_move = 1;
		players[0].stoneset[2].name_long = "Gluttony";
		players[0].stoneset[2].name = "GL";
		players[0].stoneset[2].id = ID_STONE_GLUTTONY;
		players[0].stoneset[2].player_id = 0;
		players[0].stoneset[2].can_move = 1;
		players[0].stoneset[3].name_long = "Sloth";
		players[0].stoneset[3].name = "S";
		players[0].stoneset[3].id = ID_STONE_SLOTH;
		players[0].stoneset[3].player_id = 0;
		players[0].stoneset[3].can_move = 1;
		players[0].stoneset[4].name_long = "Envy";
		players[0].stoneset[4].name = "E";
		players[0].stoneset[4].id = ID_STONE_ENVY;
		players[0].stoneset[4].player_id = 0;
		players[0].stoneset[4].can_move = 1;
		players[0].stoneset[5].name_long = "Wrath";
		players[0].stoneset[5].name ="W";
		players[0].stoneset[5].id = ID_STONE_WRATH;
		players[0].stoneset[5].player_id = 0;
		players[0].stoneset[5].can_move = 1;
		players[0].stoneset[6].name_long = "Greed";
		players[0].stoneset[6].name = "GR";
		players[0].stoneset[6].id = ID_STONE_GREED;
		players[0].stoneset[6].player_id = 0;
		players[0].stoneset[6].can_move = 1;
	}
	else
	{
		players[0].stoneset[0].name_long = "One";
		players[0].stoneset[0].name = "1";
		players[0].stoneset[0].id = ID_STONE_ONE;
		players[0].stoneset[0].player_id = 0;
		players[0].stoneset[0].can_move = 1;
		players[0].stoneset[1].name_long = "Two";
		players[0].stoneset[1].name = "2";
		players[0].stoneset[1].id = ID_STONE_TWO;
		players[0].stoneset[1].player_id = 0;
		players[0].stoneset[1].can_move = 1;
		players[0].stoneset[2].name_long = "Three";
		players[0].stoneset[2].name = "3";
		players[0].stoneset[2].id = ID_STONE_THREE;
		players[0].stoneset[2].player_id = 0;
		players[0].stoneset[2].can_move = 1;
		players[0].stoneset[3].name_long = "Four";
		players[0].stoneset[3].name = "4";
		players[0].stoneset[3].id = ID_STONE_FOUR;
		players[0].stoneset[3].player_id = 0;
		players[0].stoneset[3].can_move = 1;
		players[0].stoneset[4].name_long = "Five";
		players[0].stoneset[4].name = "5";
		players[0].stoneset[4].id = ID_STONE_FIVE;
		players[0].stoneset[4].player_id = 0;
		players[0].stoneset[4].can_move = 1;
		players[0].stoneset[5].name_long = "Six";
		players[0].stoneset[5].name = "6";
		players[0].stoneset[5].id = ID_STONE_SIX;
		players[0].stoneset[5].player_id = 0;
		players[0].stoneset[5].can_move = 1;
		players[0].stoneset[6].name_long = "Seven";
		players[0].stoneset[6].name = "7";
		players[0].stoneset[6].id = ID_STONE_SEVEN;
		players[0].stoneset[6].player_id = 0;
		players[0].stoneset[6].can_move = 1;
	}
	players[0].track[0]  = &cells[4][0];
	players[0].track[1]  = &cells[3][0];
	players[0].track[2]  = &cells[2][0];
	players[0].track[3]  = &cells[1][0];
	players[0].track[4]  = &cells[0][0];
	players[0].track[5]  = &cells[0][1];
	players[0].track[6]  = &cells[1][1];
	players[0].track[7]  = &cells[2][1];
	players[0].track[8]  = &cells[3][1];
	players[0].track[9]  = &cells[4][1];
	players[0].track[10]  = &cells[5][1];
	players[0].track[11] = &cells[6][1];
	players[0].track[12] = &cells[7][1];
	players[0].track[13] = &cells[7][0];
	players[0].track[14] = &cells[6][0];
	players[0].track[15] = &cells[5][0];
	int i = -1;
	while (++i < 7)
		players[0].stoneset[i].cell = players[0].track[0];
	return ;
}

static void	init_player_two(int lvl, int ai_player, t_player *players,
				t_cell cells[8][3])
{
	players[1].id = 1;
	strncpy(players[1].name, "Player Two", PLAYER_NAME_LEN);
	players[1].is_ai = ai_player == players[1].id ? 1 : 0;
	players[1].nbr_playable = 7;
	if (lvl > 2)
	{
		players[1].stoneset[0].name_long = "Lust";
		players[1].stoneset[0].name = "L";
		players[1].stoneset[0].id = ID_STONE_LUST;
		players[1].stoneset[0].player_id = 1;
		players[1].stoneset[0].can_move = 1;
		players[1].stoneset[1].name_long = "Pride";
		players[1].stoneset[1].name = "P";
		players[1].stoneset[1].id = ID_STONE_PRIDE;
		players[1].stoneset[1].player_id = 1;
		players[1].stoneset[1].can_move = 1;
		players[1].stoneset[2].name_long = "Gluttony";
		players[1].stoneset[2].name = "GL";
		players[1].stoneset[2].id = ID_STONE_GLUTTONY;
		players[1].stoneset[2].player_id = 1;
		players[1].stoneset[2].can_move = 1;
		players[1].stoneset[3].name_long = "Sloth";
		players[1].stoneset[3].name = "S";
		players[1].stoneset[3].id = ID_STONE_SLOTH;
		players[1].stoneset[3].player_id = 1;
		players[1].stoneset[3].can_move = 1;
		players[1].stoneset[4].name_long = "Envy";
		players[1].stoneset[4].name = "E";
		players[1].stoneset[4].id = ID_STONE_ENVY;
		players[1].stoneset[4].player_id = 1;
		players[1].stoneset[4].can_move = 1;
		players[1].stoneset[5].name_long = "Wrath";
		players[1].stoneset[5].name ="W";
		players[1].stoneset[5].id = ID_STONE_WRATH;
		players[1].stoneset[5].player_id = 1;
		players[1].stoneset[5].can_move = 1;
		players[1].stoneset[6].name_long = "Greed";
		players[1].stoneset[6].name = "GR";
		players[1].stoneset[6].id = ID_STONE_GREED;
		players[1].stoneset[6].player_id = 1;
		players[1].stoneset[6].can_move = 1;
	}
	else
	{
		players[1].stoneset[0].name_long = "One";
		players[1].stoneset[0].name = "1";
		players[1].stoneset[0].id = ID_STONE_ONE;
		players[1].stoneset[0].player_id = 1;
		players[1].stoneset[0].can_move = 1;
		players[1].stoneset[1].name_long = "Two";
		players[1].stoneset[1].name = "2";
		players[1].stoneset[1].id = ID_STONE_TWO;
		players[1].stoneset[1].player_id = 1;
		players[1].stoneset[1].can_move = 1;
		players[1].stoneset[2].name_long = "Three";
		players[1].stoneset[2].name = "3";
		players[1].stoneset[2].id = ID_STONE_THREE;
		players[1].stoneset[2].player_id = 1;
		players[1].stoneset[2].can_move = 1;
		players[1].stoneset[3].name_long = "Four";
		players[1].stoneset[3].name = "4";
		players[1].stoneset[3].id = ID_STONE_FOUR;
		players[1].stoneset[3].player_id = 1;
		players[1].stoneset[3].can_move = 1;
		players[1].stoneset[4].name_long = "Five";
		players[1].stoneset[4].name = "5";
		players[1].stoneset[4].id = ID_STONE_FIVE;
		players[1].stoneset[4].player_id = 1;
		players[1].stoneset[4].can_move = 1;
		players[1].stoneset[5].name_long = "Six";
		players[1].stoneset[5].name = "6";
		players[1].stoneset[5].id = ID_STONE_SIX;
		players[1].stoneset[5].player_id = 1;
		players[1].stoneset[5].can_move = 1;
		players[1].stoneset[6].name_long = "Seven";
		players[1].stoneset[6].name = "7";
		players[1].stoneset[6].id = ID_STONE_SEVEN;
		players[1].stoneset[6].player_id = 1;
		players[1].stoneset[6].can_move = 1;
	}
	players[1].track[0]  = &cells[4][2];
	players[1].track[1]  = &cells[3][2];
	players[1].track[2]  = &cells[2][2];
	players[1].track[3]  = &cells[1][2];
	players[1].track[4]  = &cells[0][2];
	players[1].track[5]  = &cells[0][1];
	players[1].track[6]  = &cells[1][1];
	players[1].track[7]  = &cells[2][1];
	players[1].track[8]  = &cells[3][1];
	players[1].track[9]  = &cells[4][1];
	players[1].track[10]  = &cells[5][1];
	players[1].track[11] = &cells[6][1];
	players[1].track[12] = &cells[7][1];
	players[1].track[13] = &cells[7][2];
	players[1].track[14] = &cells[6][2];
	players[1].track[15] = &cells[5][2];
	int i = -1;
	while (++i < 7)
		players[1].stoneset[i].cell = players[1].track[0];
	return ;
}
