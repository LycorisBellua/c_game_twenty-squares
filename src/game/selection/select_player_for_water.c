#include "twenty_squares.h"

int	select_player_for_water(const Player *current_player)
{
	if (current_player->is_ai)
		return (rng_minmax(&rng_seed, 1, 2));
	return (ask_nbr(1, 2, "Player: "));
}
