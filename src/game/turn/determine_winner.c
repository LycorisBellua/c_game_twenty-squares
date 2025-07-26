#include "twenty_squares.h"

void	determine_winner(char *input, t_player *players)
{
	int	winner;

	if (!players[0].nbr_playable || !players[1].nbr_playable)
	{
		if (players[0].points > players[1].points)
			winner = 0;
		else if (players[1].points > players[0].points)
			winner = 1;
		else if (players[0].points == players[1].points)
			winner = !players[0].nbr_playable;
		printf("The game has ended. The winner is %s!\n", players[winner].name);
		memcpy(input, "quit", INPUT_LEN);
	}
	return ;
}
