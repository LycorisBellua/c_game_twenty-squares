#include "twenty_squares.h"

void	initialize_cells(Cell *cells)
{
	memset(cells, 0, 21 * sizeof(Cell));
	cells[0].coordinate = 11;
	cells[0].is_rosette = 1;
	cells[1].coordinate = 21;
	cells[2].coordinate = 31;
	cells[2].is_rosette = 1;
	cells[3].coordinate = 12;
	cells[4].coordinate = 22;
	cells[5].coordinate = 32;
	cells[6].coordinate = 13;
	cells[7].coordinate = 23;
	cells[8].coordinate = 33;
	cells[9].coordinate = 14;
	cells[10].coordinate = 24;
	cells[10].is_rosette = 1;
	cells[11].coordinate = 34;
	cells[12].coordinate = 25;
	cells[13].coordinate = 26;
	cells[14].coordinate = 17;
	cells[14].is_rosette = 1;
	cells[15].coordinate = 27;
	cells[16].coordinate = 37;
	cells[16].is_rosette = 1;
	cells[17].coordinate = 18;
	cells[18].coordinate = 28;
	cells[19].coordinate = 38;
	cells[20].coordinate = 1;
	return ;
}
