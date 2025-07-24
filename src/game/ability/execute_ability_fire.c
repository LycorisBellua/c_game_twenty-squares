#include "twenty_squares.h"

void	execute_ability_fire(int level, Player *players, Player *current_player,
			Cell *all_cells)
{
	if (current_player->id)
	{
		printf("Fire will kill one of %s's stones.\n", PLAYER_ONE->name);
		remove_stone_from_board(all_cells, ABILITY_FIRE, level, PLAYER_ONE,
			current_player);
	}
	else
	{
		printf("Fire will kill one of %s's stones.\n", PLAYER_TWO->name);
		remove_stone_from_board(all_cells, ABILITY_FIRE, level, PLAYER_TWO,
			current_player);
	}
	return;
}
