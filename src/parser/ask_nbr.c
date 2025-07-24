#include "twenty_squares.h"

int	ask_nbr(int min_nbr, int max_nbr, const char *question)
{
	const char	**tokens;
	int			nbr;

	printf("%s %d - %d.\n\n", question, min_nbr, max_nbr);
	nbr = min_nbr - 1;
	while (nbr < min_nbr || nbr > max_nbr)
	{
		tokens = get_input();
		if (!tokens)
			break ;
		else if (tokens[0] && !tokens[1])
			nbr = atoi(tokens[0]);
		free_arr((void **)tokens, free);
	}
	return (nbr);
}
