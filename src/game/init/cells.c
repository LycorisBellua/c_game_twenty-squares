#include "twenty_squares.h"

void	init_cells(t_cell cells[8][3])
{
	cells[0][0].is_rosette = 1;
	cells[6][0].is_rosette = 1;
	cells[3][1].is_rosette = 1;
	cells[0][2].is_rosette = 1;
	cells[6][2].is_rosette = 1;
	return ;
}

void	reset_cells(t_cell cells[8][3])
{
	int	y;
	int	x;

	y = -1;
	while (++y < 8)
	{
		x = -1;
		while (++x < 3)
			cells[y][x].stone = 0;
	}
	return ;
}
