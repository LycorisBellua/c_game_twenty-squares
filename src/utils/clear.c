#include "twenty_squares.h"

void	clear_window(void)
{
	#ifndef _WIN32
	write(STDOUT_FILENO, "\033c", 2);
	#else
	system("cls");
	#endif
	return ;
}

void	clear_prev_line(void)
{
	#ifndef _WIN32
	write(STDOUT_FILENO, "\033[1F", 4);
	write(STDOUT_FILENO, "\033[2K", 4);
	#else
	HANDLE						h_console;
	CONSOLE_SCREEN_BUFFER_INFO	csbi;
	COORD						cursor_pos;
	DWORD						written;

	h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (GetConsoleScreenBufferInfo(h_console, &csbi))
	{
		cursor_pos.X = 0;
		cursor_pos.Y = csbi.dwCursorPosition.Y - 1;
		SetConsoleCursorPosition(h_console, cursor_pos);
		FillConsoleOutputCharacter(h_console, ' ', csbi.dwSize.X, cursor_pos,
			&written);
		SetConsoleCursorPosition(h_console, cursor_pos);
	}
	#endif
	return ;
}
