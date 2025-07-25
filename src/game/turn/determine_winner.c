#include "twenty_squares.h"

void	determine_winner(char *input, Player *players)
{
	int	winner;

	if (!PLAYER_ONE->number_of_playable_stones
		|| !PLAYER_TWO->number_of_playable_stones)
	{
		if (PLAYER_ONE->points > PLAYER_TWO->points)
			winner = 1;
		else if (PLAYER_TWO->points > PLAYER_ONE->points)
			winner = 2;
		else if (PLAYER_ONE->points == PLAYER_TWO->points)
			winner = !PLAYER_ONE->number_of_playable_stones + 1;
		printf("The game has ended. The winner is %s!\n",
			winner == 1 ? PLAYER_ONE->name : PLAYER_TWO->name);
		memcpy(input, "quit", INPUT_SIZE);
	}
	return ;
}
