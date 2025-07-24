#include "twenty_squares.h"

void	execute_ability_water(int dice, int level, Player *players,
			Player *current_player, Cell *all_cells)
{
	int i;
	int selected_player = 0;
	int total_stones_on_board = PLAYER_ONE->number_of_stones_on_board
		+ PLAYER_TWO->number_of_stones_on_board;
	int max_number_of_stones_to_select = total_stones_on_board < dice ?
		total_stones_on_board : dice;
	int number = max_number_of_stones_to_select == 1 ?
		1 : select_number_of_stones_for_water(max_number_of_stones_to_select,
		current_player);

	printf("Water will wash %d %s away.\n", number, number == 1 ? "stone"
		: "stones");
	for (i = 0; i < number; ++i)
	{
		if (PLAYER_ONE->number_of_stones_on_board > 0
			&& PLAYER_TWO->number_of_stones_on_board > 0)
			selected_player = select_player_for_water(current_player);
		else if (PLAYER_ONE->number_of_stones_on_board > 0
			&& !PLAYER_TWO->number_of_stones_on_board)
			selected_player = 1;
		else if (!PLAYER_ONE->number_of_stones_on_board
			&& PLAYER_TWO->number_of_stones_on_board > 0)
			selected_player = 2;

		selected_player == 1 ? remove_stone_from_board(all_cells, ABILITY_WATER,
			level, PLAYER_ONE, current_player)
			: remove_stone_from_board(all_cells, ABILITY_WATER, level,
			PLAYER_TWO, current_player);
	}
	return;
}
