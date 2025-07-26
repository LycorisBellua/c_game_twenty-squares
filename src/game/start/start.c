#include "twenty_squares.h"

static void	set_utf8_encoding(void);
static void	display_intro_page(void);
static void	display_first_page(void);
static void	display_second_page(void);
static void	display_third_page(void);

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
	printf("This game is based upon a mesopotamian game which is at least 4.5 "
		"millenia old. Known today as the \"Royal Game of Ur\" or the \"Game "
		"of Twenty Squares\", this board game was later on overthrown by "
		"Backgammon. This project, Twenty Squares, is the opportunity to "
		"discover the oldest board game known to mankind. And, on top of a "
		"classic way of playing, I've provided my own twist by giving life to "
		"the stones in the Deadly Sins modes. The marvel of technology, pawns "
		"thinking for themselves...\n\n");
	return ;
}

static void	display_first_page(void)
{
	clear_window();
	printf("GUIDE - PAGE 1/3\n\n");
	printf("This board game is a race game. Two players, seven stones each, "
		"and the winner is whoever made all of their stones cross the other "
		"side first. To aid us, a dice going from 0 to 4. Let's explain the "
		"rules...\n\n");
	printf("             ___ ___ ___               ___ ___ ___     \n");
	printf("            |▒▒▒|   |▒▒▒|             | 4 | 5 |   |    \n");
	printf("            |▒▒▒|___|▒▒▒|             |___|___|___|    \n");
	printf("            |   |   |   |             | 3 | 6 |   |    \n");
	printf("            |___|___|___|             |___|___|___|    \n");
	printf("            |   |   |   |             | 2 | 7 |   |    \n");
	printf("            |___|___|___|             |___|___|___|    \n");
	printf("            |   |▒▒▒|   |             | 1 | 8 |   |    \n");
	printf("            |___|▒▒▒|___|             |___|___|___|    \n");
	printf("        ooooooo |   | ooooooo     ooooooo | 9 | ooooooo\n");
	printf("                |___|                     |___|        \n");
	printf("              x |   | x                 x |10 | x      \n");
	printf("             ___|___|___               ___|___|___     \n");
	printf("            |▒▒▒|   |▒▒▒|             |14 |11 |   |    \n");
	printf("            |▒▒▒|___|▒▒▒|             |___|___|___|    \n");
	printf("            |   |   |   |             |13 |12 |   |    \n");
	printf("            |___|___|___|             |___|___|___|    \n\n\n");
	printf("Let's take a look at the drawing on the left. The players begin "
		"and end the race on their own side of the board. Left for Player One, "
		"right for Player Two. On the drawing above, the stones are placed "
		"before their respective first cells. The 'x' marks the objective. The "
		"middle road is where the players meet and fight. On the right "
		"drawing, Player One's path has been detailed. Each turn, the dice is "
		"thrown and the result is the number of board cells forwards a stone "
		"can go, for one stone per cell. The turn passes if the dice lands on "
		"0 or if no stone can move. Stepping onto a cell occupied by an enemy "
		"stone makes you capture it, unless... See the gray cells on the left "
		"drawing? Such a cell is called a rosette, and it delivers abilities "
		"to the stone sitting upon it.\n\n");
	printf("What do these abilities do, and can the stones move less than the "
		"dice throw? To find out, let's see the different levels!\n\n");
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
	printf("The words 'Infinite' and 'Dispatch' are the first thing to pay "
		"attention to. In Infinite levels, captured stones return to their "
		"player's homebase, while in Dispatch ones they get straight up "
		"killed. This difference doesn't change the way a game is won. It's "
		"always whoever has the most points at the end of the game. A game "
		"ends when someone runs out of stones. A stone beyond the finish line "
		"gives 1 point. If it turns out that both players have the same amount "
		"of points at the end, it's not a draw: the one with a living stone or "
		"more wins.\n\n");
	printf("'Classic' and 'Deadly Sins,' on the other hand, refer to the "
		"stones' movements. In Classic levels, the stones can only move up to "
		"the dice throw. And as for abilities, in both cases, the rosette "
		"protects the stone and gives the player a free turn.\n\n");
	printf("When it comes to the Deadly Sins stones movements, the dice throw "
		"is a range, not a finality. How does each stone pick their cell?\n\n");
	press_enter_to_continue();
	return ;
}

static void	display_third_page(void)
{
	clear_window();
	printf("GUIDE - PAGE 3/3\n\n");
	printf("Lust has eyes only for you. It listens to everything you say and "
		"will go to the cell you pick.\n\n");
	printf("Pride doesn't do well with orders. It rejects what you picked and "
		"goes where it wants. It can also refuse to move just to be a "
		"bother.\n\n");
	printf("Gluttony doesn't think. It just goes the farthest it can.\n\n");
	printf("Sloth would rather be asleep. But since it doesn't have Pride's "
		"force of will, it can't remain immobile, and so picks the closest "
		"cell allowed.\n\n");
	printf("Envy lacks a personality of its own. It goes all over the place, "
		"not able to settle for a pattern. The cell is picked at random.\n\n");
	printf("Wrath is a slave to bloodlust. When it notices an enemy stone on "
		"the board, it targets it with unyielding focus, ready to step upon "
		"allies to see the enemy perish. The rest of the time, it moves to the "
		"closest available cell as to stick around longer: this way, it has "
		"more chance of meeting the other team.\n\n");
	printf("Greed follows a set of priorities: the closest rosette, then the "
		"closest enemy, and finally the finish line.\n\n");
	press_enter_to_continue();
	return ;
}
