#include "twenty_squares.h"

void	init_cells(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 8)
	{
		x = -1;
		while (++x < 3)
			game->cells[y][x].is_rosette = 0;
	}
	game->cells[0][0].is_rosette = 1;
	game->cells[6][0].is_rosette = 1;
	game->cells[3][1].is_rosette = 1;
	game->cells[0][2].is_rosette = 1;
	game->cells[6][2].is_rosette = 1;
	return ;
}

void	reset_cells(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 8)
	{
		x = -1;
		while (++x < 3)
			game->cells[y][x].stone = 0;
	}
	return ;
}
