#include "twenty_squares.h"

int	rng_seed;

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
	rng_seed = generate_seed();
	display_intro_page();
	if (!ask_yes_no("Do you know the rules of the game?"))
	{
		display_first_page();
		display_second_page();
		display_third_page();
	}
	start_game();
	clear_window();
	return EXIT_SUCCESS;
}

static void	set_utf8_encoding(void)
{
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	#endif
	return;
}

static void	display_intro_page(void)
{
	clear_window();
	printf("TWENTY SQUARES\n\n");
	printf("This game is based upon the oldest game known to mankind: a five "
		"millennia old mesopotamian board game, known today as the Game of "
		"Twenty Squares or the Royal Game of Ur.\n");
	printf("Its purpose is to provide a \"classic\" version of the game, as "
		"well as a new take on it, that exploits possibilities brought by a "
		"computer.\n");
	printf("On these notes, I reserve special thanks to Irving Finkel of the "
		"British Museum and Tom Scott, who was his guest in the Museum's "
		"introductory video on the Royal Game of Ur. This video is how I came "
		"to learn of the game, and I've used the simple rules described in it "
		"to make the first level.\n\n");
	return;
}

static void	display_first_page(void)
{
	clear_window();
	printf("GUIDE - PAGE 1/3\n\n");
	printf("The Twenty Squares is a board game where two players face each "
		"other using, well... A board, and also stones and a dice from 0 to 4. "
		"The goal is to bring each of our seven stones beyond the finish "
		"line.\n");

	printf("                                                       \n");
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
		"drawing? They are Special Cells and deliver abilities to the stones "
		"standing on them. The abilities are named after the four "
		"elements.\n\n");
	printf("What do these abilities do, and can the stones move less than the "
		"dice throw? To find out, let's see the different levels!\n\n");
	press_enter_to_continue();
	return;
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
		"killed. This difference changes the way a game is won. While in "
		"Infinite levels the winner is whoever first runs out of stones, in "
		"Dispatch levels we experience a system a points. A stone beyond the "
		"finish line is +1 point, and a stone killed is -1. Once a player gets "
		"rid of all their stones, the game ends, the points are counted, and "
		"the winner is determined.\n\n");
	printf("'Classic' and 'Deadly Sins,' on the other hand, refer to the "
		"stones' movements and the abilities. In Classic levels, the stones "
		"can only move up to the dice throw, and the abilities are "
		"automatically used upon receiving. Classic levels have two abilities, "
		"always given together: Air and Earth. Air gives the player a free "
		"turn, while Earth protects the stone as long as it stands still or as "
		"long as Water is not used against it.\n\n");
	printf("In Deadly Sins levels, the four abilities are available, but only "
		"one at a time, and the stone is responsible for whether they are "
		"used, discarded, or the decision let to the player. Lust, Pride, Envy "
		"and Greed leave the decision to the player, while Gluttony uses it, "
		"Sloth discards, and as for Wrath, it discards or uses it depending on "
		"which ability it is.\n\n");
	printf("As for the effect of the last two abilities, Water and Fire: from "
		"1 to the dice throw result, Water lets you select stones to bring "
		"back to their respective homebases. Fire, however, kills the enemy "
		"stone of our choice. Of course, in Infinite this means the stone goes "
		"back to homebase.\n\n");
	printf("When it comes to the Deadly Sins stones movements, the dice throw "
		"is a range, not a finality. How does each stone pick their cell?\n\n");
	press_enter_to_continue();
	return;
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
		"the board, it targets it with an unyielding focus, ready to step upon "
		"allies to see the enemy perish. The rest of the time, it moves to the "
		"closest available cell as to stick around longer: this way, it has "
		"more chance of meeting the other team.\n\n");
	printf("Greed follows a set of priorities: the closest Special Cell, then "
		"the closest enemy, and finally the finish line. The reason it lets "
		"you decide what to do with the ability, is because it doesn't know "
		"how to use what it gathered. There's no personal purpose to its "
		"hoarding, but hopefully it'll help you win.\n\n");
	press_enter_to_continue();
	return;
}
