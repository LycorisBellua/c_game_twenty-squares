#include "twenty_squares.h"

const char	*get_player_name(int index)
{
	if (index == 0)
		return ("Player One");
	else if (index == 1)
		return ("Player Two");
	return ("UNKNOWN_PLAYER");
}
