#include "twenty_squares.h"

int	determine_winner(t_player *players)
{
	int	winner;

	if (!players[0].nbr_playable || !players[1].nbr_playable)
	{
		if (players[0].points == players[1].points)
			winner = !players[0].nbr_playable;
		else if (players[0].points > players[1].points)
			winner = 0;
		else
			winner = 1;
		printf("The game has ended. The winner is %s!\n", players[winner].name);
		return (1);
	}
	return (0);
}
