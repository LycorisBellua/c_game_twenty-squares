#include "twenty_squares.h"

int	can_this_ds_stone_move(Stone *stone, Player *current_player, int dice)
{
	int		i;
	int		j;
	int		can_this_stone_move;
	int		is_wrath_on_no_killing_road;
	int		coordinate_of_closest_enemy;
	Cell	**target_cells_1;
	Cell	**target_cells_2;
	Cell	**target_cells_3;
	Cell	**target_cells_4;

	j = 0;
	can_this_stone_move = 0;
	is_wrath_on_no_killing_road = 0;
	coordinate_of_closest_enemy = 0;
	target_cells_1 = 0;
	target_cells_2 = 0;
	target_cells_3 = 0;
	target_cells_4 = 0;
	// target_cells are double pointers because current_player is a double 
	// pointer + they are not an array because I suck
	if (stone->coordinate == 1 || stone->coordinate == -1)
		return (can_this_stone_move);
	stone->possible_movements[0] = 0;
	stone->possible_movements[1] = 0;
	stone->possible_movements[2] = 0;
	stone->possible_movements[3] = 0;
	if (!stone->coordinate)
	{
		if (dice >= 1)
			target_cells_1 = &current_player->racetrack[0];
		if (dice >= 2)
			target_cells_2 = &current_player->racetrack[1];
		if (dice >= 3)
			target_cells_3 = &current_player->racetrack[2];
		if (dice == 4)
			target_cells_4 = &current_player->racetrack[3];
	}
	else
	{
		i = -1;
		while (++i < 14)
		{
			if (stone->coordinate == current_player->racetrack[i]->coordinate)
			{
				if (dice >= 1)
				{
					if (i + 1 >= 14)
					{
						// We break after an out of bounds coordinate is found, 
						// because we don't need more than one
						target_cells_1 = &current_player->racetrack[14];
						break ;
					}
					else
						target_cells_1 = &current_player->racetrack[i + 1];
				}
				if (dice >= 2)
				{
					if (i + 2 >= 14)
					{
						target_cells_2 = &current_player->racetrack[14];
						break ;
					}
					else
						target_cells_2 = &current_player->racetrack[i + 2];
				}
				if (dice >= 3)
				{
					if (i + 3 >= 14)
					{
						target_cells_3 = &current_player->racetrack[14];
						break ;
					}
					else
						target_cells_3 = &current_player->racetrack[i + 3];
				}
				if (dice == 4)
				{
					if (i + 4 >= 14)
					{
						target_cells_4 = &current_player->racetrack[14];
						break ;
					}
					else
						target_cells_4 = &current_player->racetrack[i + 4];
				}
				break ;
			}
		}
	}
	if (stone->id == ID_STONE_WRATH)
	{
		// If Wrath is on the "no killing" road, we don't care for enemies.
		if (stone->coordinate == current_player
				->racetrack[INDEX_1_ON_3_NO_KILLING_ROAD]->coordinate 
				|| stone->coordinate == current_player
				->racetrack[INDEX_2_ON_3_NO_KILLING_ROAD]->coordinate 
				|| stone->coordinate == current_player
				->racetrack[INDEX_3_ON_3_NO_KILLING_ROAD]->coordinate)
			is_wrath_on_no_killing_road = 1;
		// Wrath is not on "no killing" road
		if (!is_wrath_on_no_killing_road)
		{
			// We first get the index of Wrath's position.
			// If it's before the common road, we start checking for an enemy 
			// from the beginning of the common road.
			// If it's after this beginning, we start to check from the first 
			// cell after Wrath's position.
			i = -1;
			while (++i < 14)
			{
				if (!stone->coordinate || stone->coordinate
					== current_player->racetrack[i]->coordinate)
				{
					i = !stone->coordinate || ++i <= INDEX_1_ON_8_COMMON_ROAD ?
						INDEX_1_ON_8_COMMON_ROAD : i;
					while (i <= INDEX_8_ON_8_COMMON_ROAD)
					{
						if (current_player->racetrack[i]->stone_in_cell
							&& current_player->racetrack[i]
							->stone_in_cell->player_id != current_player->id)
						{
							coordinate_of_closest_enemy = current_player
								->racetrack[i]->coordinate;
							break ;
						}
						++i;
					}
					break ;
				}
			}
		}
		// Wrath is on no killing road OR there is no enemy on the common road 
		// in front of Wrath: 
		// It goes to the closest empty cell (this closest "cell" may be out of 
		// bounds).
		if (is_wrath_on_no_killing_road || !coordinate_of_closest_enemy)
		{
			if ((*target_cells_1)->coordinate == 1)
			{
				// This cell is out of bounds
				stone->possible_movements[0] = 1;
				return (1);
			}
			else if (!(*target_cells_1)->stone_in_cell)
			{
				// The closest cell is empty
				stone->possible_movements[0] = 1;
				return (1);
			}
			// The closest cell is neither out of bounds nor empty, so we check 
			// the next one, and so on
			if (target_cells_2)
			{
				if ((*target_cells_2)->coordinate == 1)
				{
					stone->possible_movements[0] = 2;
					return (1);
				}
				else if (!(*target_cells_2)->stone_in_cell)
				{
					stone->possible_movements[0] = 2;
					return (1);
				}
				if (target_cells_3)
				{
					if ((*target_cells_3)->coordinate == 1)
					{
						stone->possible_movements[0] = 3;
						return (1);
					}
					else if (!(*target_cells_3)->stone_in_cell)
					{
						stone->possible_movements[0] = 3;
						return (1);
					}
					if (target_cells_4)
					{
						if ((*target_cells_4)->coordinate == 1)
						{
							stone->possible_movements[0] = 4;
							return (1);
						}
						else if (!(*target_cells_4)->stone_in_cell)
						{
							stone->possible_movements[0] = 4;
							return (1);
						}
					}
				}
			}
		}
		else	// Wrath is not on "no killing" road and there's an enemy in front 
				// of it
		{
			// Wrath tries to get as close to the enemy as possible, until it 
			// can kill it, ignoring the presence of allies on its path 
			// (= killing them if needs be).
			// Disclaimer: The rosette protects stones from Wrath.
			if ((*target_cells_1)->coordinate == coordinate_of_closest_enemy)
			{
				if (!(*target_cells_1)->stone_in_cell->is_protected)
				{
					stone->possible_movements[0] = 1;
					return (1);
				}
				// The first cell contains the enemy, but it is protected 
				// by the rosette. Wrath remains right behind the stone, 
				// waiting for it to move.
				// Therefore, Wrath cannot move this turn.
				return (0);
			}
			if (target_cells_2)
			{
				if ((*target_cells_2)->coordinate == coordinate_of_closest_enemy)
				{
					if (!(*target_cells_2)->stone_in_cell->is_protected)
					{
						stone->possible_movements[0] = 2;
						return (1);
					}
					// The enemy is on this cell, but it is protected by 
					// the rosette, therefore Wrath goes to the cell right 
					// before this one.
					stone->possible_movements[0] = 1;
					return (1);
				}
				if (target_cells_3)
				{
					if ((*target_cells_3)->coordinate
						== coordinate_of_closest_enemy)
					{
						if (!(*target_cells_3)->stone_in_cell->is_protected)
						{
							stone->possible_movements[0] = 3;
							return (1);
						}
						else
						{
							stone->possible_movements[0] = 2;
							return (1);
						}
					}
					if (target_cells_4)
					{
						if ((*target_cells_4)->coordinate
							== coordinate_of_closest_enemy)
						{
							if (!(*target_cells_4)->stone_in_cell->is_protected)
							{
								stone->possible_movements[0] = 4;
								return (1);
							}
							else
							{
								stone->possible_movements[0] = 3;
								return (1);
							}
						}
					}
				}
			}
			// The enemy is not on the next 4 cells, so it must be from the 5th 
			// onwards. We need to go the farthest cell we can reach that is 
			// not protected by the rosette.
			if (target_cells_4
				&& !(*target_cells_4)->stone_in_cell->is_protected)
			{
				stone->possible_movements[0] = 4;
				return (1);
			}
			else if (target_cells_3
				&& !(*target_cells_3)->stone_in_cell->is_protected)
			{
				stone->possible_movements[0] = 3;
				return (1);
			}
			else if (target_cells_2
				&& !(*target_cells_2)->stone_in_cell->is_protected)
			{
				stone->possible_movements[0] = 2;
				return (1);
			}
			else if (!(*target_cells_1)->stone_in_cell->is_protected)
			{
				stone->possible_movements[0] = 1;
				return (1);
			}
			// Else: We simply wait to reach the "return 0" down below
		}
		return (0);
	}
	else if (stone->id == ID_STONE_GREED)
	{
		// Greed's first priority: An empty rosette
		if ((*target_cells_1)->is_rosette
			&& !(*target_cells_1)->stone_in_cell)
		{
			stone->possible_movements[0] = 1;
			return (1);
		}
		else if (target_cells_2)
		{
			if ((*target_cells_2)->is_rosette
				&& !(*target_cells_2)->stone_in_cell)
			{
				stone->possible_movements[0] = 2;
				return (1);
			}
			else if (target_cells_3)
			{
				if ((*target_cells_3)->is_rosette
					&& !(*target_cells_3)->stone_in_cell)
				{
					stone->possible_movements[0] = 3;
					return (1);
				}
				else if (target_cells_4
					&& (*target_cells_4)->is_rosette
					&& !(*target_cells_4)->stone_in_cell)
				{
					stone->possible_movements[0] = 4;
					return (1);
				}
			}
		}
		// Greed's second priority: The closest enemy not protected by the rosette
		if ((*target_cells_1)->stone_in_cell
			&& (*target_cells_1)->stone_in_cell->player_id != current_player->id
			&& !(*target_cells_1)->stone_in_cell->is_protected)
		{
			stone->possible_movements[0] = 1;
			return (1);
		}
		else if (target_cells_2)
		{
			if ((*target_cells_2)->stone_in_cell
				&& (*target_cells_2)->stone_in_cell->player_id
				!= current_player->id
				&& !(*target_cells_2)->stone_in_cell->is_protected)
			{
				stone->possible_movements[0] = 2;
				return (1);
			}
			else if (target_cells_3)
			{
				if ((*target_cells_3)->stone_in_cell
					&& (*target_cells_3)->stone_in_cell->player_id
					!= current_player->id
					&& !(*target_cells_3)->stone_in_cell->is_protected)
				{
					stone->possible_movements[0] = 3;
					return (1);
				}
				else if (target_cells_4
					&& (*target_cells_4)->stone_in_cell
					&& (*target_cells_4)->stone_in_cell->player_id
					!= current_player->id 
					&& !(*target_cells_4)->stone_in_cell->is_protected)
				{
					stone->possible_movements[0] = 4;
					return (1);
				}
			}
		}
		// Greed's third priority: The farthest cell (empty, because if not 
		// it's either an ally stone or an unkillable enemy)
		if (target_cells_4 && !(*target_cells_4)->stone_in_cell)
		{
			stone->possible_movements[0] = 4;
			return (1);
		}
		else if (target_cells_3 && !(*target_cells_3)->stone_in_cell)
		{
			stone->possible_movements[0] = 3;
			return (1);
		}
		else if (target_cells_2 && !(*target_cells_2)->stone_in_cell)
		{
			stone->possible_movements[0] = 2;
			return (1);
		}
		else if (!(*target_cells_1)->stone_in_cell)
		{
			stone->possible_movements[0] = 1;
			return (1);
		}
		return (0);
	}
	if (target_cells_1)
	{
		if ((*target_cells_1)->coordinate == 1)
		{
			// It goes out of bounds
			stone->possible_movements[j++] = 1;
			can_this_stone_move = 1;
		}
		else if (!(*target_cells_1)->stone_in_cell)
		{
			// The cell is empty
			stone->possible_movements[j++] = 1;
			can_this_stone_move = 1;
		}
		else if (!(*target_cells_1)->stone_in_cell->is_protected
			&& (*target_cells_1)->stone_in_cell->player_id
			!= current_player->id)
		{
			// Stone is not protected by the rosette and is an enemy
			stone->possible_movements[j++] = 1;
			can_this_stone_move = 1;
		}
	}
	if (target_cells_2)
	{
		if ((*target_cells_2)->coordinate == 1)
		{
			stone->possible_movements[j++] = 2;
			can_this_stone_move = 1;
		}
		else if (!(*target_cells_2)->stone_in_cell)
		{
			stone->possible_movements[j++] = 2;
			can_this_stone_move = 1;
		}
		else if (!(*target_cells_2)->stone_in_cell->is_protected
			&& (*target_cells_2)->stone_in_cell->player_id
			!= current_player->id)
		{
			stone->possible_movements[j++] = 2;
			can_this_stone_move = 1;
		}
	}
	if (target_cells_3)
	{
		if ((*target_cells_3)->coordinate == 1)
		{
			stone->possible_movements[j++] = 3;
			can_this_stone_move = 1;
		}
		else if (!(*target_cells_3)->stone_in_cell)
		{
			stone->possible_movements[j++] = 3;
			can_this_stone_move = 1;
		}
		else if (!(*target_cells_3)->stone_in_cell->is_protected
			&& (*target_cells_3)->stone_in_cell->player_id
			!= current_player->id)
		{
			stone->possible_movements[j++] = 3;
			can_this_stone_move = 1;
		}
	}
	if (target_cells_4)
	{
		if ((*target_cells_4)->coordinate == 1)
		{
			stone->possible_movements[j++] = 4;
			can_this_stone_move = 1;
		}
		else if (!(*target_cells_4)->stone_in_cell)
		{
			stone->possible_movements[j++] = 4;
			can_this_stone_move = 1;
		}
		else if (!(*target_cells_4)->stone_in_cell->is_protected
			&& (*target_cells_4)->stone_in_cell->player_id
			!= current_player->id)
		{
			stone->possible_movements[j++] = 4;
			can_this_stone_move = 1;
		}
	}
	return (can_this_stone_move);
}
