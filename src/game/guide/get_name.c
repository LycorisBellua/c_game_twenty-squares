#include "twenty_squares.h"

const char	*get_player_name(int index)
{
	if (index == 0)
		return ("Player One");
	else if (index == 1)
		return ("Player Two");
	return ("UNKNOWN_PLAYER");
}

const char	*get_level_name(int level)
{
	if (level == 1)
		return ("Classic Infinite");
	else if (level == 2)
		return ("Classic Dispatch");
	else if (level == 3)
		return ("Deadly Sins Infinite");
	else if (level == 4)
		return ("Deadly Sins Dispatch");
	return ("UNKNOWN_LEVEL");
}

const char	*get_stone_name(int level, int index, int full)
{
	if (level < 3)
	{
		if (index == 0)
			return (full ? "One" : "1");
		else if (index == 1)
			return (full ? "Two" : "2");
		else if (index == 2)
			return (full ? "Three" : "3");
		else if (index == 3)
			return (full ? "Four" : "4");
		else if (index == 4)
			return (full ? "Five" : "5");
		else if (index == 5)
			return (full ? "Six" : "6");
		else if (index == 6)
			return (full ? "Seven" : "7");
	}
	else if (level < 5)
	{
		if (index == 0)
			return (full ? "Lust" : "L");
		else if (index == 1)
			return (full ? "Pride" : "P");
		else if (index == 2)
			return (full ? "Gluttony" : "GL");
		else if (index == 3)
			return (full ? "Sloth" : "S");
		else if (index == 4)
			return (full ? "Envy" : "E");
		else if (index == 5)
			return (full ? "Wrath" : "W");
		else if (index == 6)
			return (full ? "Greed" : "GR");
	}
	return ("UNKNOWN_STONE");
}
