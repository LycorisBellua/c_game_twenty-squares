#include "twenty_squares.h"

int	select_number_of_stones_for_water(int max_number,
		const Player *current_player)
{
	if (current_player->is_ai)
	{
		printf("%s chooses the number of stones they'll pick.\n",
			current_player->name);
		return rng_minmax(&rng_seed, 1, max_number);
	}
	return ask_nbr(1, max_number, "How many stones do you pick?");
}
