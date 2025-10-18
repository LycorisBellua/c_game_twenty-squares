#include "twenty_squares.h"

void	print_turn_line(int turn_nbr)
{
	const int	len_total = 55;
	const int	len_space_first = 24;
	int			len_turn;

	printf("%*s", len_space_first, "");
	len_turn = printf("TURN %d", turn_nbr);
	printf("%*s\n", len_total - len_space_first - len_turn, "");
	return ;
}
