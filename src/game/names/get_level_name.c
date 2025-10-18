#include "twenty_squares.h"

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
