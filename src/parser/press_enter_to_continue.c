#include "twenty_squares.h"

void	press_enter_to_continue(void)
{
	const char	*flavor_text = "Press ENTER to continue.";

	write(STDOUT_FILENO, flavor_text, strlen(flavor_text));
	free(gnl(STDIN_FILENO));
	return ;
}
