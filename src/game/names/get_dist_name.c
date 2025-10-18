#include "twenty_squares.h"

const char	*get_dist_name(int dist)
{
	if (dist == 1)
		return ("One");
	else if (dist == 2)
		return ("Two");
	else if (dist == 3)
		return ("Three");
	else if (dist == 4)
		return ("Four");
	return ("UNKNOWN_DIST");
}
