#include "twenty_squares.h"

void	display_guide(void)
{
	clear_window();
	display_guide_intro();
	if (!ask_yes_no("Do you know the rules of the game?"))
	{
		clear_window();
		printl("GUIDE - PAGE 1/3\n");
		display_guide_page1();
		press_enter_to_continue();
		clear_window();
		printl("GUIDE - PAGE 2/3\n");
		display_guide_page2();
		press_enter_to_continue();
		clear_window();
		printl("GUIDE - PAGE 3/3\n");
		display_guide_page3();
		press_enter_to_continue();
	}
	return ;
}
