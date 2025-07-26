#include "twenty_squares.h"

void	init_cells(t_cell *cells)
{
	memset(cells, 0, 21 * sizeof(t_cell));
	cells[0].coord = 11;
	cells[0].is_rosette = 1;
	cells[1].coord = 21;
	cells[2].coord = 31;
	cells[2].is_rosette = 1;
	cells[3].coord = 12;
	cells[4].coord = 22;
	cells[5].coord = 32;
	cells[6].coord = 13;
	cells[7].coord = 23;
	cells[8].coord = 33;
	cells[9].coord = 14;
	cells[10].coord = 24;
	cells[10].is_rosette = 1;
	cells[11].coord = 34;
	cells[12].coord = 25;
	cells[13].coord = 26;
	cells[14].coord = 17;
	cells[14].is_rosette = 1;
	cells[15].coord = 27;
	cells[16].coord = 37;
	cells[16].is_rosette = 1;
	cells[17].coord = 18;
	cells[18].coord = 28;
	cells[19].coord = 38;
	cells[20].coord = 1;
	return ;
}
