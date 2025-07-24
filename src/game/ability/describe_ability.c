#include "twenty_squares.h"

void	describe_ability(int ability, int dice)
{
	if (ability == ABILITY_CLASSIC)
	{
		printf("This Special Cell obtains the abilities 'Air' and 'Earth'.\n");
		printf("Effects: The current player gets a free turn and the stone is "
			"untouchable while standing on the cell.\n\n");
	}
	else if (ability == ABILITY_AIR)
	{
		printf("This Special Cell obtains the ability 'Air'.\n");
		printf("Effect: The current player gets a free turn.\n\n");
	}
	else if (ability == ABILITY_EARTH)
	{
		printf("This Special Cell obtains the ability 'Earth'.\n");
		printf("Effect: The stone is untouchable while standing on the "
			"cell.\n\n");
	}
	else if (ability == ABILITY_WATER)
	{
		printf("This Special Cell obtains the ability 'Water'.\n");
		printf("Effect: ");
		if (dice == 1)
			printf("Pick a living stone you want to put back to homebase.\n\n");
		else
			printf("From 1 to %d, pick living stones you want to put back to "
				"their respective homebase.\n\n", dice);
	}
	else if (ability == ABILITY_FIRE)
	{
		printf("This Special Cell obtains the ability 'Fire'.\n");
		printf("Effect: Pick an enemy stone standing on the board and not "
			"protected by Earth, and have it die.\n\n");
	}
	return ;
}
