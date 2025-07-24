#include "twenty_squares.h"

int	set_number_of_moveable_stones_and_every_can_stone_move
		(Player *current_player, int level, int dice)
{
	int	i;
	int	number_of_moveable_stones;

	number_of_moveable_stones = 0;
	i = -1;
	while (++i < 7)
	{
		if (level <= 2
			&& can_this_classic_stone_move(&(current_player->stoneset[i]),
			current_player, dice))
		{
			current_player->stoneset[i].can_stone_move = 1;
			++number_of_moveable_stones;
		}
		else if (level > 2
			&& can_this_ds_stone_move(&(current_player->stoneset[i]),
			current_player, dice))
		{
			current_player->stoneset[i].can_stone_move = 1;
			++number_of_moveable_stones;
		}
		else
			current_player->stoneset[i].can_stone_move = 0;
	}
	return (number_of_moveable_stones);
}
