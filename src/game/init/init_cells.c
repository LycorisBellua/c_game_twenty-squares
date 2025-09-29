#include "twenty_squares.h"

void	init_cells(t_cell cells[8][3])
{
	int y = -1;
	while (++y < 8)
		memset(cells[y], 0, 3 * sizeof(t_cell));
	cells[0][0].is_rosette = 1;
	cells[6][0].is_rosette = 1;
	cells[3][1].is_rosette = 1;
	cells[0][2].is_rosette = 1;
	cells[6][2].is_rosette = 1;
	return ;
}
