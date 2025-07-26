#include "twenty_squares.h"

static void	init_player_one(int lvl, int human_player, t_player *players,
				t_cell *cells);
static void	init_player_two(int lvl, int human_player, t_player *players,
				t_cell *cells);

void	init_players(int lvl, int human_player, t_player *players,
			t_cell *cells)
{
	memset(players, 0, 2 * sizeof(t_player));
	init_player_one(lvl, human_player, players, cells);
	init_player_two(lvl, human_player, players, cells);
	return ;
}

static void	init_player_one(int lvl, int human_player, t_player *players,
				t_cell *cells)
{
	players[0].id = 0;
	memcpy(players[0].name, "Player One", PLAYER_NAME_LEN);
	players[0].is_ai = human_player == players[0].id ? 0 : 1;
	players[0].nbr_playable = 7;
	if (lvl > 2)
	{
		memcpy(players[0].stoneset[0].name, "Lust", STONE_NAME_LEN);
		players[0].stoneset[0].id = ID_STONE_LUST;
		players[0].stoneset[0].player_id = 0;
		players[0].stoneset[0].can_move = 1;
		memcpy(players[0].stoneset[1].name, "Pride", STONE_NAME_LEN);
		players[0].stoneset[1].id = ID_STONE_PRIDE;
		players[0].stoneset[1].player_id = 0;
		players[0].stoneset[1].can_move = 1;
		memcpy(players[0].stoneset[2].name, "Gluttony", STONE_NAME_LEN);
		players[0].stoneset[2].id = ID_STONE_GLUTTONY;
		players[0].stoneset[2].player_id = 0;
		players[0].stoneset[2].can_move = 1;
		memcpy(players[0].stoneset[3].name, "Sloth", STONE_NAME_LEN);
		players[0].stoneset[3].id = ID_STONE_SLOTH;
		players[0].stoneset[3].player_id = 0;
		players[0].stoneset[3].can_move = 1;
		memcpy(players[0].stoneset[4].name, "Envy", STONE_NAME_LEN);
		players[0].stoneset[4].id = ID_STONE_ENVY;
		players[0].stoneset[4].player_id = 0;
		players[0].stoneset[4].can_move = 1;
		memcpy(players[0].stoneset[5].name,"Wrath", STONE_NAME_LEN);
		players[0].stoneset[5].id = ID_STONE_WRATH;
		players[0].stoneset[5].player_id = 0;
		players[0].stoneset[5].can_move = 1;
		memcpy(players[0].stoneset[6].name, "Greed", STONE_NAME_LEN);
		players[0].stoneset[6].id = ID_STONE_GREED;
		players[0].stoneset[6].player_id = 0;
		players[0].stoneset[6].can_move = 1;
	}
	else
	{
		memcpy(players[0].stoneset[0].name, "One", STONE_NAME_LEN);
		players[0].stoneset[0].id = ID_STONE_ONE;
		players[0].stoneset[0].player_id = 0;
		players[0].stoneset[0].can_move = 1;
		memcpy(players[0].stoneset[1].name, "Two", STONE_NAME_LEN);
		players[0].stoneset[1].id = ID_STONE_TWO;
		players[0].stoneset[1].player_id = 0;
		players[0].stoneset[1].can_move = 1;
		memcpy(players[0].stoneset[2].name, "Three", STONE_NAME_LEN);
		players[0].stoneset[2].id = ID_STONE_THREE;
		players[0].stoneset[2].player_id = 0;
		players[0].stoneset[2].can_move = 1;
		memcpy(players[0].stoneset[3].name, "Four", STONE_NAME_LEN);
		players[0].stoneset[3].id = ID_STONE_FOUR;
		players[0].stoneset[3].player_id = 0;
		players[0].stoneset[3].can_move = 1;
		memcpy(players[0].stoneset[4].name, "Five", STONE_NAME_LEN);
		players[0].stoneset[4].id = ID_STONE_FIVE;
		players[0].stoneset[4].player_id = 0;
		players[0].stoneset[4].can_move = 1;
		memcpy(players[0].stoneset[5].name, "Six", STONE_NAME_LEN);
		players[0].stoneset[5].id = ID_STONE_SIX;
		players[0].stoneset[5].player_id = 0;
		players[0].stoneset[5].can_move = 1;
		memcpy(players[0].stoneset[6].name, "Seven", STONE_NAME_LEN);
		players[0].stoneset[6].id = ID_STONE_SEVEN;
		players[0].stoneset[6].player_id = 0;
		players[0].stoneset[6].can_move = 1;
	}
	players[0].track[0] = &cells[9]; /* Coordinate 14 */
	players[0].track[1] = &cells[6]; /* Coordinate 13 */
	players[0].track[2] = &cells[3]; /* Coordinate 12 */
	players[0].track[3] = &cells[0]; /* Coordinate 11 */
	players[0].track[4] = &cells[1]; /* Coordinate 21 */
	players[0].track[5] = &cells[4]; /* Coordinate 22 */
	players[0].track[6] = &cells[7]; /* Coordinate 23 */
	players[0].track[7] = &cells[10]; /* Coordinate 24 */
	players[0].track[8] = &cells[12]; /* Coordinate 25 */
	players[0].track[9] = &cells[13]; /* Coordinate 26 */
	players[0].track[10] = &cells[15]; /* Coordinate 27 */
	players[0].track[11] = &cells[18]; /* Coordinate 28 */
	players[0].track[12] = &cells[17]; /* Coordinate 18 */
	players[0].track[13] = &cells[14]; /* Coordinate 17 */
	players[0].track[14] = &cells[20]; /* Coordinate 1 */
	return ;
}

static void	init_player_two(int lvl, int human_player, t_player *players,
				t_cell *cells)
{
	players[1].id = 1;
	memcpy(players[1].name, "Player Two", PLAYER_NAME_LEN);
	players[1].is_ai = human_player == players[1].id ? 0 : 1;
	players[1].nbr_playable = 7;
	if (lvl > 2)
	{
		memcpy(players[1].stoneset[0].name, "Lust", STONE_NAME_LEN);
		players[1].stoneset[0].id = ID_STONE_LUST;
		players[1].stoneset[0].player_id = 1;
		players[1].stoneset[0].can_move = 1;
		memcpy(players[1].stoneset[1].name, "Pride", STONE_NAME_LEN);
		players[1].stoneset[1].id = ID_STONE_PRIDE;
		players[1].stoneset[1].player_id = 1;
		players[1].stoneset[1].can_move = 1;
		memcpy(players[1].stoneset[2].name, "Gluttony", STONE_NAME_LEN);
		players[1].stoneset[2].id = ID_STONE_GLUTTONY;
		players[1].stoneset[2].player_id = 1;
		players[1].stoneset[2].can_move = 1;
		memcpy(players[1].stoneset[3].name, "Sloth", STONE_NAME_LEN);
		players[1].stoneset[3].id = ID_STONE_SLOTH;
		players[1].stoneset[3].player_id = 1;
		players[1].stoneset[3].can_move = 1;
		memcpy(players[1].stoneset[4].name, "Envy", STONE_NAME_LEN);
		players[1].stoneset[4].id = ID_STONE_ENVY;
		players[1].stoneset[4].player_id = 1;
		players[1].stoneset[4].can_move = 1;
		memcpy(players[1].stoneset[5].name,"Wrath", STONE_NAME_LEN);
		players[1].stoneset[5].id = ID_STONE_WRATH;
		players[1].stoneset[5].player_id = 1;
		players[1].stoneset[5].can_move = 1;
		memcpy(players[1].stoneset[6].name, "Greed", STONE_NAME_LEN);
		players[1].stoneset[6].id = ID_STONE_GREED;
		players[1].stoneset[6].player_id = 1;
		players[1].stoneset[6].can_move = 1;
	}
	else
	{
		memcpy(players[1].stoneset[0].name, "One", STONE_NAME_LEN);
		players[1].stoneset[0].id = ID_STONE_ONE;
		players[1].stoneset[0].player_id = 1;
		players[1].stoneset[0].can_move = 1;
		memcpy(players[1].stoneset[1].name, "Two", STONE_NAME_LEN);
		players[1].stoneset[1].id = ID_STONE_TWO;
		players[1].stoneset[1].player_id = 1;
		players[1].stoneset[1].can_move = 1;
		memcpy(players[1].stoneset[2].name, "Three", STONE_NAME_LEN);
		players[1].stoneset[2].id = ID_STONE_THREE;
		players[1].stoneset[2].player_id = 1;
		players[1].stoneset[2].can_move = 1;
		memcpy(players[1].stoneset[3].name, "Four", STONE_NAME_LEN);
		players[1].stoneset[3].id = ID_STONE_FOUR;
		players[1].stoneset[3].player_id = 1;
		players[1].stoneset[3].can_move = 1;
		memcpy(players[1].stoneset[4].name, "Five", STONE_NAME_LEN);
		players[1].stoneset[4].id = ID_STONE_FIVE;
		players[1].stoneset[4].player_id = 1;
		players[1].stoneset[4].can_move = 1;
		memcpy(players[1].stoneset[5].name, "Six", STONE_NAME_LEN);
		players[1].stoneset[5].id = ID_STONE_SIX;
		players[1].stoneset[5].player_id = 1;
		players[1].stoneset[5].can_move = 1;
		memcpy(players[1].stoneset[6].name, "Seven", STONE_NAME_LEN);
		players[1].stoneset[6].id = ID_STONE_SEVEN;
		players[1].stoneset[6].player_id = 1;
		players[1].stoneset[6].can_move = 1;
	}
	players[1].track[0] = &cells[11]; /* Coordinate 34 */
	players[1].track[1] = &cells[8]; /* Coordinate 33 */
	players[1].track[2] = &cells[5]; /* Coordinate 32 */
	players[1].track[3] = &cells[2]; /* Coordinate 31 */
	players[1].track[4] = &cells[1]; /* Coordinate 21 */
	players[1].track[5] = &cells[4]; /* Coordinate 22 */
	players[1].track[6] = &cells[7]; /* Coordinate 23 */
	players[1].track[7] = &cells[10]; /* Coordinate 24 */
	players[1].track[8] = &cells[12]; /* Coordinate 25 */
	players[1].track[9] = &cells[13]; /* Coordinate 26 */
	players[1].track[10] = &cells[15]; /* Coordinate 27 */
	players[1].track[11] = &cells[18]; /* Coordinate 28 */
	players[1].track[12] = &cells[19]; /* Coordinate 38 */
	players[1].track[13] = &cells[16]; /* Coordinate 37 */
	players[1].track[14] = &cells[20]; /* Coordinate 1 */
	return ;
}
