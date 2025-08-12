#include "twenty_squares.h"

static void	set_to_uppercase(char *s);
static void	set_whitespaces_to_fs(char *s);

const char	**get_input(void)
{
	char		*line;
	const char	**tokens;

	(void)!write(STDOUT_FILENO, "> ", 2);
	line = gnl(STDIN_FILENO);
	clear_prev_line();
	if (!line)
	{
		(void)!write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	set_to_uppercase(line);
	set_whitespaces_to_fs(line);
	tokens = (const char **)split(line, FS);
	free(line);
	return (tokens);
}

static void	set_to_uppercase(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		s[i] = toupper(s[i]);
		++i;
	}
	return ;
}

static void	set_whitespaces_to_fs(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (isspace(s[i]))
			s[i] = FS;
		++i;
	}
	return ;
}
