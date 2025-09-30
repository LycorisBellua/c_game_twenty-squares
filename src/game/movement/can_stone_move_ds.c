#include "twenty_squares.h"

int	can_stone_move_ds(t_stone *stone, t_player *player, int dice)
{
	int		i;
	int		j;
	int		can_move;
	int		is_wrath_on_no_killing_road;
	t_cell	*cell_closest_enemy;
	t_cell	*cell[4];

	j = 0;
	can_move = 0;
	cell_closest_enemy = 0;
	memset(stone->moves, 0, sizeof(stone->moves));
	memset(cell, 0, sizeof(cell));
	if (!stone->cell || stone->cell == player->track[INDEX_VICTORY])
		return (can_move);
	if (stone->cell == player->track[INDEX_HOME])
	{
		if (dice >= 1)
			cell[0] = player->track[INDEX_1_ON_4_INITIAL_ROAD];
		if (dice >= 2)
			cell[1] = player->track[INDEX_2_ON_4_INITIAL_ROAD];
		if (dice >= 3)
			cell[2] = player->track[INDEX_3_ON_4_INITIAL_ROAD];
		if (dice == 4)
			cell[3] = player->track[INDEX_4_ON_4_INITIAL_ROAD];
	}
	else
	{
		i = 0;
		while (++i < 15)
		{
			if (stone->cell == player->track[i])
			{
				if (dice >= 1)
				{
					if (i + 1 >= 15)
					{
						// We break after an out of bounds cell is found, 
						// because we don't need more than one
						cell[0] = player->track[15];
						break ;
					}
					else
						cell[0] = player->track[i + 1];
				}
				if (dice >= 2)
				{
					if (i + 2 >= 15)
					{
						cell[1] = player->track[15];
						break ;
					}
					else
						cell[1] = player->track[i + 2];
				}
				if (dice >= 3)
				{
					if (i + 3 >= 15)
					{
						cell[2] = player->track[15];
						break ;
					}
					else
						cell[2] = player->track[i + 3];
				}
				if (dice == 4)
				{
					if (i + 4 >= 15)
					{
						cell[3] = player->track[15];
						break ;
					}
					else
						cell[3] = player->track[i + 4];
				}
				break ;
			}
		}
	}
	if (stone->id == ID_STONE_WRATH)
	{
		// If Wrath is on the "no killing" road, we don't care for enemies.
		is_wrath_on_no_killing_road = 
			stone->cell == player->track[INDEX_8_ON_8_COMMON_ROAD] 
			|| stone->cell == player->track[INDEX_1_ON_2_END_ROAD] 
			|| stone->cell == player->track[INDEX_2_ON_2_END_ROAD];
		// Wrath is not on "no killing" road
		if (!is_wrath_on_no_killing_road)
		{
			// We first get the index of Wrath's position. If it's before the 
			// common road, we start checking for an enemy from the beginning 
			// of the common road. If it's after this beginning, we start to 
			// check from the first cell after Wrath's position.
			i = INDEX_HOME - 1;
			while (stone->cell != player->track[++i]);
			if (i < INDEX_1_ON_8_COMMON_ROAD)
				i = INDEX_1_ON_8_COMMON_ROAD;
			else
				++i;
			while (i <= INDEX_8_ON_8_COMMON_ROAD)
			{
				if (player->track[i]->stone && player->track[i]->stone->player_id != player->id)
				{
					cell_closest_enemy = player->track[i];
					break ;
				}
				++i;
			}
		}
		// Wrath is on no killing road OR there is no enemy on the common road 
		// in front of Wrath: It goes to the closest empty cell (this closest 
		// "cell" may be out of bounds).
		if (is_wrath_on_no_killing_road || !cell_closest_enemy)
		{
			if (cell[0] == player->track[INDEX_VICTORY])
			{
				// This cell is out of bounds
				stone->moves[0] = 1;
				return (1);
			}
			else if (!cell[0]->stone)
			{
				// The closest cell is empty
				stone->moves[0] = 1;
				return (1);
			}
			// The closest cell is neither out of bounds nor empty, so we check 
			// the next one, and so on
			if (cell[1])
			{
				if (cell[1] == player->track[INDEX_VICTORY])
				{
					stone->moves[0] = 2;
					return (1);
				}
				else if (!cell[1]->stone)
				{
					stone->moves[0] = 2;
					return (1);
				}
				if (cell[2])
				{
					if (cell[2] == player->track[INDEX_VICTORY])
					{
						stone->moves[0] = 3;
						return (1);
					}
					else if (!cell[2]->stone)
					{
						stone->moves[0] = 3;
						return (1);
					}
					if (cell[3])
					{
						if (cell[3] == player->track[INDEX_VICTORY])
						{
							stone->moves[0] = 4;
							return (1);
						}
						else if (!cell[3]->stone)
						{
							stone->moves[0] = 4;
							return (1);
						}
					}
				}
			}
		}
		// Wrath is not on "no killing" road and there's an enemy in front of it
		else
		{
			// Wrath tries to get as close to the enemy as possible, until it 
			// can kill it, ignoring the presence of allies on its path 
			// (= killing them if needs be). Disclaimer: The rosette protects 
			// stones from Wrath.
			if (cell[0] == cell_closest_enemy)
			{
				if (!cell[0]->stone->is_protected)
				{
					stone->moves[0] = 1;
					return (1);
				}
				// The first cell contains the enemy, but it is protected by 
				// the rosette. Wrath remains right behind the stone, waiting 
				// for it to move. Therefore, Wrath cannot move this turn.
				return (0);
			}
			if (cell[1])
			{
				if (cell[1] == cell_closest_enemy)
				{
					if (!cell[1]->stone->is_protected)
					{
						stone->moves[0] = 2;
						return (1);
					}
					// The enemy is on this cell, but it is protected by the 
					// rosette, therefore Wrath goes to the cell right before 
					// this one.
					stone->moves[0] = 1;
					return (1);
				}
				if (cell[2])
				{
					if (cell[2] == cell_closest_enemy)
					{
						if (!cell[2]->stone->is_protected)
						{
							stone->moves[0] = 3;
							return (1);
						}
						else
						{
							stone->moves[0] = 2;
							return (1);
						}
					}
					if (cell[3])
					{
						if (cell[3] == cell_closest_enemy)
						{
							if (!cell[3]->stone->is_protected)
							{
								stone->moves[0] = 4;
								return (1);
							}
							else
							{
								stone->moves[0] = 3;
								return (1);
							}
						}
					}
				}
			}
			// The enemy is not on the next 4 cells, so it must be from the 5th 
			// onwards. We need to go the farthest cell we can reach that is 
			// not protected by the rosette.
			if (cell[3] && cell[3]->stone && !cell[3]->stone->is_protected)
			{
				stone->moves[0] = 4;
				return (1);
			}
			else if (cell[2] && cell[2]->stone && !cell[2]->stone->is_protected)
			{
				stone->moves[0] = 3;
				return (1);
			}
			else if (cell[1] && cell[1]->stone && !cell[1]->stone->is_protected)
			{
				stone->moves[0] = 2;
				return (1);
			}
			else if (cell[0] && cell[0]->stone && !cell[0]->stone->is_protected)
			{
				stone->moves[0] = 1;
				return (1);
			}
			// Else: We simply wait to reach the "return 0" down below
		}
		return (0);
	}
	else if (stone->id == ID_STONE_GREED)
	{
		// Greed's first priority: An empty rosette
		if (cell[0]->is_rosette && !cell[0]->stone)
		{
			stone->moves[0] = 1;
			return (1);
		}
		else if (cell[1])
		{
			if (cell[1]->is_rosette && !cell[1]->stone)
			{
				stone->moves[0] = 2;
				return (1);
			}
			else if (cell[2])
			{
				if (cell[2]->is_rosette && !cell[2]->stone)
				{
					stone->moves[0] = 3;
					return (1);
				}
				else if (cell[3] && cell[3]->is_rosette && !cell[3]->stone)
				{
					stone->moves[0] = 4;
					return (1);
				}
			}
		}
		// Greed's second priority: The closest enemy not protected by the 
		// rosette
		if (cell[0]->stone && cell[0]->stone->player_id != player->id
			&& !cell[0]->stone->is_protected)
		{
			stone->moves[0] = 1;
			return (1);
		}
		else if (cell[1])
		{
			if (cell[1]->stone && cell[1]->stone->player_id != player->id
				&& !cell[1]->stone->is_protected)
			{
				stone->moves[0] = 2;
				return (1);
			}
			else if (cell[2])
			{
				if (cell[2]->stone && cell[2]->stone->player_id != player->id
					&& !cell[2]->stone->is_protected)
				{
					stone->moves[0] = 3;
					return (1);
				}
				else if (cell[3] && cell[3]->stone
					&& cell[3]->stone->player_id != player->id
					&& !cell[3]->stone->is_protected)
				{
					stone->moves[0] = 4;
					return (1);
				}
			}
		}
		// Greed's third priority: The farthest cell (empty, because if not 
		// it's either an ally stone or an unkillable enemy)
		if (cell[3] && !cell[3]->stone)
		{
			stone->moves[0] = 4;
			return (1);
		}
		else if (cell[2] && !cell[2]->stone)
		{
			stone->moves[0] = 3;
			return (1);
		}
		else if (cell[1] && !cell[1]->stone)
		{
			stone->moves[0] = 2;
			return (1);
		}
		else if (!cell[0]->stone)
		{
			stone->moves[0] = 1;
			return (1);
		}
		return (0);
	}
	if (cell[0])
	{
		if (cell[0] == player->track[INDEX_VICTORY])
		{
			// It goes out of bounds
			stone->moves[j++] = 1;
			can_move = 1;
		}
		else if (!cell[0]->stone)
		{
			// The cell is empty
			stone->moves[j++] = 1;
			can_move = 1;
		}
		else if (!cell[0]->stone->is_protected
			&& cell[0]->stone->player_id
			!= player->id)
		{
			// Stone is not protected by the rosette and is an enemy
			stone->moves[j++] = 1;
			can_move = 1;
		}
	}
	if (cell[1])
	{
		if (cell[1] == player->track[INDEX_VICTORY])
		{
			stone->moves[j++] = 2;
			can_move = 1;
		}
		else if (!cell[1]->stone)
		{
			stone->moves[j++] = 2;
			can_move = 1;
		}
		else if (!cell[1]->stone->is_protected
			&& cell[1]->stone->player_id != player->id)
		{
			stone->moves[j++] = 2;
			can_move = 1;
		}
	}
	if (cell[2])
	{
		if (cell[2] == player->track[INDEX_VICTORY])
		{
			stone->moves[j++] = 3;
			can_move = 1;
		}
		else if (!cell[2]->stone)
		{
			stone->moves[j++] = 3;
			can_move = 1;
		}
		else if (!cell[2]->stone->is_protected
			&& cell[2]->stone->player_id != player->id)
		{
			stone->moves[j++] = 3;
			can_move = 1;
		}
	}
	if (cell[3])
	{
		if (cell[3] == player->track[INDEX_VICTORY])
		{
			stone->moves[j++] = 4;
			can_move = 1;
		}
		else if (!cell[3]->stone)
		{
			stone->moves[j++] = 4;
			can_move = 1;
		}
		else if (!cell[3]->stone->is_protected
			&& cell[3]->stone->player_id != player->id)
		{
			stone->moves[j++] = 4;
			can_move = 1;
		}
	}
	return (can_move);
}
