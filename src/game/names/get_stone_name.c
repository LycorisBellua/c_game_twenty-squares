#include "twenty_squares.h"

static const char	*get_stone_name_classic_long(int index);
static const char	*get_stone_name_classic_short(int index);
static const char	*get_stone_name_deadlysins_long(int index);
static const char	*get_stone_name_deadlysins_short(int index);

const char	*get_stone_name(int level, int index, int full)
{
	if (level < 3)
	{
		if (full)
			return (get_stone_name_classic_long(index));
		return (get_stone_name_classic_short(index));
	}
	if (full)
		return (get_stone_name_deadlysins_long(index));
	return (get_stone_name_deadlysins_short(index));
}

static const char	*get_stone_name_classic_long(int index)
{
	if (index == 0)
		return ("One");
	else if (index == 1)
		return ("Two");
	else if (index == 2)
		return ("Three");
	else if (index == 3)
		return ("Four");
	else if (index == 4)
		return ("Five");
	else if (index == 5)
		return ("Six");
	else if (index == 6)
		return ("Seven");
	return ("UNKNOWN_STONE_CLASSIC_LONG");
}

static const char	*get_stone_name_classic_short(int index)
{
	if (index == 0)
		return ("1");
	else if (index == 1)
		return ("2");
	else if (index == 2)
		return ("3");
	else if (index == 3)
		return ("4");
	else if (index == 4)
		return ("5");
	else if (index == 5)
		return ("6");
	else if (index == 6)
		return ("7");
	return ("UNKNOWN_STONE_CLASSIC_SHORT");
}

static const char	*get_stone_name_deadlysins_long(int index)
{
	if (index == 0)
		return ("Lust");
	else if (index == 1)
		return ("Pride");
	else if (index == 2)
		return ("Gluttony");
	else if (index == 3)
		return ("Sloth");
	else if (index == 4)
		return ("Envy");
	else if (index == 5)
		return ("Wrath");
	else if (index == 6)
		return ("Greed");
	return ("UNKNOWN_STONE_DEADLYSINS_LONG");
}

static const char	*get_stone_name_deadlysins_short(int index)
{
	if (index == 0)
		return ("L");
	else if (index == 1)
		return ("P");
	else if (index == 2)
		return ("GL");
	else if (index == 3)
		return ("S");
	else if (index == 4)
		return ("E");
	else if (index == 5)
		return ("W");
	else if (index == 6)
		return ("GR");
	return ("UNKNOWN_STONE_DEADLYSINS_SHORT");
}
