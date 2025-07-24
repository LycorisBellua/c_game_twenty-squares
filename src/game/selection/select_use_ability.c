#include "twenty_squares.h"

int	select_use_ability(const Player *current_player, int ability,
		int ds_decision, Cell ***target_cell)
{
	int	choice;

	choice = -1;
	if (ability == ABILITY_CLASSIC || ds_decision == DS_DECISION_USE)
	{
		choice = 1;
		return (choice);
	}
	else if (ds_decision == DS_DECISION_DISCARD)
	{
		choice = 0;
		return (choice);
	}
	if (current_player->is_ai)
	{
		if (ability == ABILITY_EARTH && (*(*target_cell))->coordinate
			== current_player->racetrack[INDEX_2_ON_2_END_ROAD]->coordinate)
			choice = 0;
		else
		{
			if (rng_minmax(&rng_seed, 0, 1))
				choice = 1;
			else
				choice = 0;
		}
	}
	else
	{
		choice = ask_yes_no("Do you use the ability?");
		if (choice != -1)
			printf("\n");
	}
	if (choice == 1)
		printf("%s uses the ability.\n\n", current_player->name);
	else if (!choice)
		printf("%s discards the ability.\n\n", current_player->name);
	return (choice);
}
