#include "twenty_squares.h"

void	print_turn_line(int nbr_turns)
{
	if (nbr_turns < 10)
	{
		printf("                                    "
			"TURN 0%d                                    \n", nbr_turns);
	}
	else if (nbr_turns >= 10 && nbr_turns < 100)
	{
		printf("                                    "
			"TURN %d                                    \n", nbr_turns);
	}
	else if (nbr_turns >= 100 && nbr_turns < 1000)
	{
		printf("                                    "
			"TURN %d                                   \n", nbr_turns);
	}
	else if (nbr_turns >= 1000 && nbr_turns < 10000)
	{
		printf("                                    "
			"TURN %d                                  \n", nbr_turns);
	}
	else
	{
		printf("                                    "
			"TURN %d                                 \n", nbr_turns);
	}
	return ;
}
