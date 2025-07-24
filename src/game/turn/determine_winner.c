#include "twenty_squares.h"

void	determine_winner(char *input, Player *players)
{
	int winner = 0;
	if (!PLAYER_ONE->number_of_playable_stones
		|| !PLAYER_TWO->number_of_playable_stones)
	{
		if (PLAYER_ONE->points > PLAYER_TWO->points)
			winner = 1;
		else if (PLAYER_TWO->points > PLAYER_ONE->points)
			winner = 2;
		else if (PLAYER_ONE->points == PLAYER_TWO->points)
			winner = 3;
		printf("The game has ended. The winner is %s!\n",
			!winner ? "[ERROR]" : winner == 1 ? PLAYER_ONE->name
			: winner == 2 ? PLAYER_TWO->name : "both of you");
		memcpy(input, "quit", INPUT_SIZE);
	}
	return;
}
