#include "twenty_squares.h"

int	ds_stones_handle_ability(const Stone *chosen_stone, int ability, int level,
		const Player *current_player, const Player *other_player)
{
	if (chosen_stone->id == ID_STONE_GLUTTONY)
	{
		printf("Gluttony uses the ability. No waste.\n");
		return (DS_DECISION_USE);
	}
	else if (chosen_stone->id == ID_STONE_SLOTH)
	{
		printf("Sloth discards the ability. Leave them alone.\n");
		return (DS_DECISION_DISCARD);
	}
	else if (chosen_stone->id == ID_STONE_WRATH)
	{
		if (ability == ABILITY_WATER)
		{
			printf("Wrath discards the ability, because this one is not "
				"very... \"killing friendly.\"\n");
			return (DS_DECISION_DISCARD);
		}
		else if (ability == ABILITY_AIR)
		{
			if (!other_player->number_of_playable_stones)
			{
				printf("Wrath discards the ability, because... What good would "
					"it be to play on a board devoid of enemies?\n");
				return (DS_DECISION_DISCARD);
			}
			else if (chosen_stone->coordinate == current_player
				->racetrack[INDEX_3_ON_3_NO_KILLING_ROAD]->coordinate)
			{
				printf("Wrath uses the ability. This way, it can be used on a "
					"more useful stone.\n");
				return (DS_DECISION_USE);
			}
			printf("Wrath uses the ability. One more chance to play! "
				"Please pick them! ...Pretty please?\n");
			return (DS_DECISION_USE);
		}
		else if (ability == ABILITY_FIRE)
		{
			printf("Wrath uses the ability. Haha, perfect! Don't run little "
				"stone... Not that you can anyway.\n");
			return (DS_DECISION_USE);
		}
		else if (ability == ABILITY_EARTH)
		{
			if (chosen_stone->coordinate == current_player
				->racetrack[INDEX_3_ON_3_NO_KILLING_ROAD]->coordinate)
			{
				printf("Wrath discards the ability. There is no point in "
					"sticking around.\n");
				return (DS_DECISION_DISCARD);
			}
			printf("Wrath uses the ability. With that, they will remain "
				"longer on the board... Even a bit is fine. Even one more "
				"stone.\n");
			return (DS_DECISION_USE);
		}
	}
	if (level > 2)
	{
		if (current_player->is_ai)
		{
			printf("%s lets %s decide what to do with the ability.\n",
				chosen_stone->name, current_player->name);
		}
		else
		{
			printf("%s lets you decide what to do with the ability.\n",
				chosen_stone->name);
			printf("If it's not used right away, it will be discarded.\n");
		}
	}
	return (DS_DECISION_PLAYER);
}
