#include "twenty_squares.h"

int	set_ability(int level, Cell ***target_cell, const Player *players,
		const Player *current_player)
{
	int i;
	int ability = ABILITY_NONE;

	if ((*(*target_cell))->is_cell_special)
	{
		ability = level > 2 ? rng_minmax(&rng_seed, 2, 5) : ABILITY_CLASSIC;
		if (ability == ABILITY_FIRE)
		{
			if (!current_player->id)
			{
				// No enemy of P1 on board OR enemies are protected by Earth: 
				// Fire is impossible --> replace with Water
				if (!PLAYER_TWO->number_of_stones_on_board)
					ability = ABILITY_WATER;
				else
				{
					for (i = 0; i <= 7; ++i)
					{
						if (i == 7)
							ability = ABILITY_WATER;
						if (PLAYER_TWO->stoneset[i].coordinate > 2
							&& !PLAYER_TWO->stoneset[i].protected_by_earth)
							break;
					}
				}
			}
			else if (current_player->id == 1)
			{
				// No enemy of P2 on board OR enemies are protected by Earth: 
				// Fire is impossible --> replace with Water
				if (!PLAYER_ONE->number_of_stones_on_board)
					ability = ABILITY_WATER;
				else
				{
					for (i = 0; i <= 7; ++i)
					{
						if (i == 7)
							ability = ABILITY_WATER;
						if (PLAYER_ONE->stoneset[i].coordinate > 2
							&& !PLAYER_ONE->stoneset[i].protected_by_earth)
							break;
					}
				}
			}
		}
	}
	return ability;
}
