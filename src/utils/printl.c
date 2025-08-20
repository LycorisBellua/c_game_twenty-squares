#include "twenty_squares.h"

static void	print_word(const char **line, size_t *col, size_t max_col);

void	printl(const char *line)
{
	const size_t	max_col = 55;
	size_t			col;

	col = 0;
	while (*line)
	{
		print_word(&line, &col, max_col);
		if (col >= max_col)
		{
			(void)!write(1, "\n", 1);
			col = 0;
		}
	}
	(void)!write(1, "\n", 1);
	return ;
}

static void	print_word(const char **line, size_t *col, size_t max_col)
{
	size_t	word_len;

	word_len = 0;
	while ((*line)[word_len] && !isspace((*line)[word_len]))
		++word_len;
	*col += word_len;
	if (*col <= max_col)
	{
		(void)!write(1, *line, word_len);
		*line += word_len;
		if (**line)
		{
			if (*col < max_col)
				(void)!write(1, *line, 1);
			++*line;
			++*col;
		}
	}
	return ;
}
