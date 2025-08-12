#include "twenty_squares.h"

int	ask_yes_no(const char *question)
{
	const char	**tokens;
	int			res;

	printf("%s Yes/No\n\n", question);
	res = -1;
	while (res < 0)
	{
		tokens = get_input();
		if (!tokens)
			break ;
		else if (tokens[0] && !tokens[1])
		{
			if (!strcmp(tokens[0], "YES") || !strcmp(tokens[0], "Y"))
				res = 1;
			else if (!strcmp(tokens[0], "NO") || !strcmp(tokens[0], "N"))
				res = 0;
			else if (!strcmp(tokens[0], "QUIT"))
				break ;
		}
		free_arr((void **)tokens, free);
	}
	return (res);
}
