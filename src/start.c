#include "twenty_squares.h"

static void	set_utf8_encoding(void);
static int	check_args(int argc, char **argv);

#ifdef _WIN32
__declspec(dllexport) 
#else
__attribute__((visibility("default")))
#endif
int	start(int argc, char **argv)
{
	set_utf8_encoding();
	if (!check_args(argc, argv))
		return (1);
	display_guide_intro();
	if (!ask_yes_no("Do you know the rules of the game?"))
	{
		display_guide_page1();
		display_guide_page2();
		display_guide_page3();
	}
	start_game(argv[1]);
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

static int	check_args(int argc, char **argv)
{
	if (argc > 2)
	{
		fprintf(stderr, "Error: Too many arguments "
			"- Usage: No arg | \"opponent_ai\" | \"opponent_human\"\n");
		return (0);
	}
	else if (argc == 2 && strcmp(argv[1], "opponent_ai")
		&& strcmp(argv[1], "opponent_human"))
	{
		fprintf(stderr, "Error: Invalid argument "
			"- Usage: No arg | \"opponent_ai\" | \"opponent_human\"\n");
		return (0);
	}
	return (1);
}
