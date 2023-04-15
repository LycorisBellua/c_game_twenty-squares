#ifndef TURN_H
#define TURN_H

#ifndef STANDARD_LIBRARY_UNISTD
#define STANDARD_LIBRARY_UNISTD
    #include <unistd.h>
#endif
#ifndef STANDARD_LIBRARY_WINDOWS
#define STANDARD_LIBRARY_WINDOWS
    #ifdef _WIN32
    #include <windows.h>
    #endif
#endif

#include "start.h"

void start_game(void);
void game_loop(const int level, Player* players, Cell* all_cells);
void count_points(Player* players);
void determine_winner(char* input, Player* players);

#endif

