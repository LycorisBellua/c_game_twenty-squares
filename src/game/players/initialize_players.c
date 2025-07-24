#include "twenty_squares.h"

static void	init_player_one(int level, int human_player, Player *players,
				Cell *cells);
static void	init_player_two(int level, int human_player, Player *players,
				Cell *cells);

void	initialize_players(int level, int human_player, Player *players,
			Cell *cells)
{
	memset(players, 0, 2 * sizeof(Player));
	init_player_one(level, human_player, players, cells);
	init_player_two(level, human_player, players, cells);
	return ;
}

static void	init_player_one(int level, int human_player, Player *players,
				Cell *cells)
{
	PLAYER_ONE->id = 0;
	memcpy(PLAYER_ONE->name, "Player One", LENGTH_PLAYER_NAME);
	PLAYER_ONE->is_ai = human_player == PLAYER_ONE->id ? 0 : 1;
	PLAYER_ONE->number_of_playable_stones = 7;
	if (level > 2)
	{
		memcpy(PLAYER_ONE->stoneset[0].name, "Lust", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[0].id = ID_STONE_LUST;
		PLAYER_ONE->stoneset[0].player_id = 0;
		PLAYER_ONE->stoneset[0].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[1].name, "Pride", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[1].id = ID_STONE_PRIDE;
		PLAYER_ONE->stoneset[1].player_id = 0;
		PLAYER_ONE->stoneset[1].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[2].name, "Gluttony", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[2].id = ID_STONE_GLUTTONY;
		PLAYER_ONE->stoneset[2].player_id = 0;
		PLAYER_ONE->stoneset[2].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[3].name, "Sloth", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[3].id = ID_STONE_SLOTH;
		PLAYER_ONE->stoneset[3].player_id = 0;
		PLAYER_ONE->stoneset[3].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[4].name, "Envy", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[4].id = ID_STONE_ENVY;
		PLAYER_ONE->stoneset[4].player_id = 0;
		PLAYER_ONE->stoneset[4].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[5].name,"Wrath", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[5].id = ID_STONE_WRATH;
		PLAYER_ONE->stoneset[5].player_id = 0;
		PLAYER_ONE->stoneset[5].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[6].name, "Greed", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[6].id = ID_STONE_GREED;
		PLAYER_ONE->stoneset[6].player_id = 0;
		PLAYER_ONE->stoneset[6].can_stone_move = 1;
	}
	else
	{
		memcpy(PLAYER_ONE->stoneset[0].name, "One", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[0].id = ID_STONE_ONE;
		PLAYER_ONE->stoneset[0].player_id = 0;
		PLAYER_ONE->stoneset[0].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[1].name, "Two", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[1].id = ID_STONE_TWO;
		PLAYER_ONE->stoneset[1].player_id = 0;
		PLAYER_ONE->stoneset[1].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[2].name, "Three", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[2].id = ID_STONE_THREE;
		PLAYER_ONE->stoneset[2].player_id = 0;
		PLAYER_ONE->stoneset[2].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[3].name, "Four", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[3].id = ID_STONE_FOUR;
		PLAYER_ONE->stoneset[3].player_id = 0;
		PLAYER_ONE->stoneset[3].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[4].name, "Five", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[4].id = ID_STONE_FIVE;
		PLAYER_ONE->stoneset[4].player_id = 0;
		PLAYER_ONE->stoneset[4].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[5].name, "Six", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[5].id = ID_STONE_SIX;
		PLAYER_ONE->stoneset[5].player_id = 0;
		PLAYER_ONE->stoneset[5].can_stone_move = 1;
		memcpy(PLAYER_ONE->stoneset[6].name, "Seven", LENGTH_STONE_NAME);
		PLAYER_ONE->stoneset[6].id = ID_STONE_SEVEN;
		PLAYER_ONE->stoneset[6].player_id = 0;
		PLAYER_ONE->stoneset[6].can_stone_move = 1;
	}
	PLAYER_ONE->racetrack[0] =  (cells +  9); /* Coordinate 14 */
	PLAYER_ONE->racetrack[1] =  (cells +  6); /* Coordinate 13 */
	PLAYER_ONE->racetrack[2] =  (cells +  3); /* Coordinate 12 */
	PLAYER_ONE->racetrack[3] =  (cells +  0); /* Coordinate 11 */
	PLAYER_ONE->racetrack[4] =  (cells +  1); /* Coordinate 21 */
	PLAYER_ONE->racetrack[5] =  (cells +  4); /* Coordinate 22 */
	PLAYER_ONE->racetrack[6] =  (cells +  7); /* Coordinate 23 */
	PLAYER_ONE->racetrack[7] =  (cells + 10); /* Coordinate 24 */
	PLAYER_ONE->racetrack[8] =  (cells + 12); /* Coordinate 25 */
	PLAYER_ONE->racetrack[9] =  (cells + 13); /* Coordinate 26 */
	PLAYER_ONE->racetrack[10] = (cells + 15); /* Coordinate 27 */
	PLAYER_ONE->racetrack[11] = (cells + 18); /* Coordinate 28 */
	PLAYER_ONE->racetrack[12] = (cells + 17); /* Coordinate 18 */
	PLAYER_ONE->racetrack[13] = (cells + 14); /* Coordinate 17 */
	PLAYER_ONE->racetrack[14] = (cells + 20); /* Coordinate 1 */
	return ;
}

static void	init_player_two(int level, int human_player, Player *players,
				Cell *cells)
{
	PLAYER_TWO->id = 1;
	memcpy(PLAYER_TWO->name, "Player Two", LENGTH_PLAYER_NAME);
	PLAYER_TWO->is_ai = human_player == PLAYER_TWO->id ? 0 : 1;
	PLAYER_TWO->number_of_playable_stones = 7;
	if (level > 2)
	{
		memcpy(PLAYER_TWO->stoneset[0].name, "Lust", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[0].id = ID_STONE_LUST;
		PLAYER_TWO->stoneset[0].player_id = 1;
		PLAYER_TWO->stoneset[0].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[1].name, "Pride", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[1].id = ID_STONE_PRIDE;
		PLAYER_TWO->stoneset[1].player_id = 1;
		PLAYER_TWO->stoneset[1].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[2].name, "Gluttony", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[2].id = ID_STONE_GLUTTONY;
		PLAYER_TWO->stoneset[2].player_id = 1;
		PLAYER_TWO->stoneset[2].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[3].name, "Sloth", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[3].id = ID_STONE_SLOTH;
		PLAYER_TWO->stoneset[3].player_id = 1;
		PLAYER_TWO->stoneset[3].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[4].name, "Envy", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[4].id = ID_STONE_ENVY;
		PLAYER_TWO->stoneset[4].player_id = 1;
		PLAYER_TWO->stoneset[4].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[5].name,"Wrath", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[5].id = ID_STONE_WRATH;
		PLAYER_TWO->stoneset[5].player_id = 1;
		PLAYER_TWO->stoneset[5].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[6].name, "Greed", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[6].id = ID_STONE_GREED;
		PLAYER_TWO->stoneset[6].player_id = 1;
		PLAYER_TWO->stoneset[6].can_stone_move = 1;
	}
	else
	{
		memcpy(PLAYER_TWO->stoneset[0].name, "One", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[0].id = ID_STONE_ONE;
		PLAYER_TWO->stoneset[0].player_id = 1;
		PLAYER_TWO->stoneset[0].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[1].name, "Two", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[1].id = ID_STONE_TWO;
		PLAYER_TWO->stoneset[1].player_id = 1;
		PLAYER_TWO->stoneset[1].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[2].name, "Three", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[2].id = ID_STONE_THREE;
		PLAYER_TWO->stoneset[2].player_id = 1;
		PLAYER_TWO->stoneset[2].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[3].name, "Four", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[3].id = ID_STONE_FOUR;
		PLAYER_TWO->stoneset[3].player_id = 1;
		PLAYER_TWO->stoneset[3].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[4].name, "Five", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[4].id = ID_STONE_FIVE;
		PLAYER_TWO->stoneset[4].player_id = 1;
		PLAYER_TWO->stoneset[4].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[5].name, "Six", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[5].id = ID_STONE_SIX;
		PLAYER_TWO->stoneset[5].player_id = 1;
		PLAYER_TWO->stoneset[5].can_stone_move = 1;
		memcpy(PLAYER_TWO->stoneset[6].name, "Seven", LENGTH_STONE_NAME);
		PLAYER_TWO->stoneset[6].id = ID_STONE_SEVEN;
		PLAYER_TWO->stoneset[6].player_id = 1;
		PLAYER_TWO->stoneset[6].can_stone_move = 1;
	}
	PLAYER_TWO->racetrack[0] =  (cells + 11); /* Coordinate 34 */
	PLAYER_TWO->racetrack[1] =  (cells +  8); /* Coordinate 33 */
	PLAYER_TWO->racetrack[2] =  (cells +  5); /* Coordinate 32 */
	PLAYER_TWO->racetrack[3] =  (cells +  2); /* Coordinate 31 */
	PLAYER_TWO->racetrack[4] =  (cells +  1); /* Coordinate 21 */
	PLAYER_TWO->racetrack[5] =  (cells +  4); /* Coordinate 22 */
	PLAYER_TWO->racetrack[6] =  (cells +  7); /* Coordinate 23 */
	PLAYER_TWO->racetrack[7] =  (cells + 10); /* Coordinate 24 */
	PLAYER_TWO->racetrack[8] =  (cells + 12); /* Coordinate 25 */
	PLAYER_TWO->racetrack[9] =  (cells + 13); /* Coordinate 26 */
	PLAYER_TWO->racetrack[10] = (cells + 15); /* Coordinate 27 */
	PLAYER_TWO->racetrack[11] = (cells + 18); /* Coordinate 28 */
	PLAYER_TWO->racetrack[12] = (cells + 19); /* Coordinate 38 */
	PLAYER_TWO->racetrack[13] = (cells + 16); /* Coordinate 37 */
	PLAYER_TWO->racetrack[14] = (cells + 20); /* Coordinate 1 */
	return ;
}
