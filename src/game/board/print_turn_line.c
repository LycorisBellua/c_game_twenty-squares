#include "twenty_squares.h"

void	print_turn_line(int number_of_turns)
{
	if (number_of_turns < 10)
	{
		printf("\n                                    "
			"TURN 0%d                                   \n", number_of_turns);
	}
	else if (number_of_turns >= 10 && number_of_turns < 100)
	{
		printf("\n                                    "
			"TURN %d                                   \n", number_of_turns);
	}
	else if (number_of_turns >= 100 && number_of_turns < 1000)
	{
		printf("\n                                    "
			"TURN %d                                  \n", number_of_turns);
	}
	else if (number_of_turns >= 1000 && number_of_turns < 10000)
	{
		printf("\n                                    "
			"TURN %d                                 \n", number_of_turns);
	}
	else
	{
		printf("\n                                    "
			"TURN %d                                \n", number_of_turns);
	}
	return ;
}
