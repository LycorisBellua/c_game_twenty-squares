#include "twenty_squares.h"

static void	set_utf8_encoding(void);
static void	display_intro_page(void);
static void	display_first_page(void);
static void	display_second_page(void);
static void	display_third_page(void);

#ifdef _WIN32
__declspec(dllexport) 
#else
__attribute__((visibility("default")))
#endif
int	start(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	set_utf8_encoding();
	display_intro_page();
	if (!ask_yes_no("Do you know the rules of the game?"))
	{
		display_first_page();
		display_second_page();
		display_third_page();
	}
	start_game();
	clear_window();
	return (0);
}

static void	set_utf8_encoding(void)
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	#endif
	return ;
}

static void	display_intro_page(void)
{
	clear_window();
	printf("TWENTY SQUARES\n\n");
	printf("This game is based upon a mesopotamian game which is at\nleast 4.5 "
		"millennia old. Known today as the \"Royal Game\nof Ur\" or the \"Game "
		"of Twenty Squares\", this board \ngame was later on overthrown by "
		"Backgammon. This \nproject, Twenty Squares, is the opportunity to "
		"discover\nthe oldest board game known to mankind. And, on top of \na "
		"classic way of playing, following the Finkel rules, \nI've provided "
		"my own twist by giving life to the stones\nin the Deadly Sins modes. "
		"Pawns thinking for \nthemselves... Unbelievable.\n\n");
	return ;
}

static void	display_first_page(void)
{
	clear_window();
	printf("GUIDE - PAGE 1/3\n\n");
	printf("This board game is a race game. Two players, seven \nstones each, "
		"and the winner is whoever led all of their\nstones beyond the finish "
		"line. To aid us, a dice going \nfrom 0 to 4. Let's explain the rules"
		"...\n\n");
	printf("         ___ ___ ___               ___ ___ ___         \n");
	printf("        |▒▒▒|   |▒▒▒|             | 4 | 5 |   |        \n");
	printf("        |▒▒▒|___|▒▒▒|             |___|___|___|        \n");
	printf("        |   |   |   |             | 3 | 6 |   |        \n");
	printf("        |___|___|___|             |___|___|___|        \n");
	printf("        |   |   |   |             | 2 | 7 |   |        \n");
	printf("        |___|___|___|             |___|___|___|        \n");
	printf("        |   |▒▒▒|   |             | 1 | 8 |   |        \n");
	printf("        |___|▒▒▒|___|             |___|___|___|        \n");
	printf("    ooooooo |   | ooooooo     ooooooo | 9 | ooooooo    \n");
	printf("            |___|                     |___|            \n");
	printf("            |   |                     |10 |            \n");
	printf("         ___|___|___               _x_|___|_x_         \n");
	printf("        |▒▒▒|   |▒▒▒|             |14 |11 |   |        \n");
	printf("        |▒▒▒|___|▒▒▒|             |___|___|___|        \n");
	printf("        |   |   |   |             |13 |12 |   |        \n");
	printf("        |___|___|___|             |___|___|___|        \n\n");
	printf("\n");
	printf("See where the stones are placed? The cell right above \nthem is "
		"the first cell of each player's racetracks: \nleft for Player One, "
		"right Player Two. The racetrack of\nPlayer One has been detailed in "
		"the second drawing. The\nlast cell is beyond the 14th, an invisible "
		"cell outside\nof the board: when a stone reaches it, it wins. As "
		"for \nPlayer Two, it's the exact same racetrack, but \nmirrored: it "
		"both starts and ends on the right side of \nthe board. The middle "
		"road, from cell n°5 to n°12, is \nwhere both players can encounter "
		"each other.\n\n");
	printf("Each turn, the dice is thrown for a value between 0 and\n4, which "
		"represents the number of cells forward a stone\nmust go. You can "
		"pick any of your stones, and you \ncannot pass your turn. Your turn "
		"only passes if the \ndice gives 0 or if no stone can be moved. "
		"Indeed, your \nstone can step on an enemy, but not an ally, and a \n"
		"captured stone simply goes back to its homebase, as if \nit never "
		"roamed the board at all. And as for going \nbeyond the finish line, "
		"you need the exact throw: it \ntruly is an invisible extra cell.\n\n");
	printf("Now, see the gray cells on the left drawing? Such a \ncell is "
		"called a rosette. Stepping upon one protects \nthe stone from being "
		"captured, and it gives you another\nturn.\n\n");
	printf("Let's see the different levels!\n\n");
	press_enter_to_continue();
	return ;
}

static void	display_second_page(void)
{
	clear_window();
	printf("GUIDE - PAGE 2/3\n\n");
	printf("Level 1: Classic Infinite.\n");
	printf("Level 2: Classic Dispatch.\n");
	printf("Level 3: Deadly Sins Infinite.\n");
	printf("Level 4: Deadly Sins Dispatch.\n\n");
	printf("Classic Infinite is what has just been explained. \nDispatch is "
		"different in that a stone is now killed \nupon being captured. When "
		"this happens, no point is \nearned or lost. You still win the game by "
		"making more \nstones reach the finish line than your opponent. Once \n"
		"the game ends, if you both happen to have the same \namount of "
		"points, it's not a draw: the one with still a\nplayable stone wins."
		"\n\n");
	printf("As for Deadly Sins, it refers to the stone's movement. \nThe dice "
		"throw is no longer final, it becomes a range \nof possible movements. "
		"That being said, it doesn't mean\nyou can always pick the cell "
		"yourself. Whichever Deadly\nSins stone you move has its own behavior."
		"\n\n");
	printf("Let's see how Deadly Sins stones pick their cell!\n\n");
	press_enter_to_continue();
	return ;
}

static void	display_third_page(void)
{
	clear_window();
	printf("GUIDE - PAGE 3/3\n\n");
	printf("- Lust has only eyes for you. It listens to everything \nyou say "
		"and will go to the cell you pick.\n");
	printf("- Pride doesn't do well with orders. It rejects what \nyou picked "
		"and goes where it wants. It can also refuse \nto move just to be a "
		"bother.\n");
	printf("- Gluttony doesn't think. It just goes the farthest it \ncan.\n");
	printf("- Sloth would rather be asleep. But since it doesn't \nhave "
		"Pride's force of will, it can't remain immobile if\nyou tell it to "
		"move, and so it picks the closest \navailable cell.\n");
	printf("- Envy lacks a personality of its own. It goes all over\nthe "
		"place, not able to settle for a pattern. The cell \nis picked at "
		"random.\n");
	printf("- Wrath is a slave to bloodlust. When it notices an \nenemy stone "
		"on the board, it targets it with unyielding\nfocus, ready to step "
		"upon allies to see the enemy \nperish. The rest of the time, it moves "
		"to the closest \navailable cell so as to stick around longer: this "
		"way, \nit can wait for enemies to arrive.\n");
	printf("- Greed follows a set of priorities: the closest \nrosette, then "
		"the closest enemy, and finally the finish\nline.\n\n");
	press_enter_to_continue();
	return ;
}
