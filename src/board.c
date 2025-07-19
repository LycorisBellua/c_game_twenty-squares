#include "board.h"
#include "input.h"
#include "output.h"

void print_board(const int number_of_turns, const int level, const int current_player_id, Player* players, Cell* all_cells)
{
    int line;
    CLEAR_TERMINAL
    print_turn_line(number_of_turns);

    for (line = 0; line < 42; ++line)
    {
        print_column0(line, level, current_player_id, players);
        print_column1(line, current_player_id, all_cells);
        print_column2(line, current_player_id, all_cells);
        print_column3(line, current_player_id, all_cells);
        print_column4(line, level, current_player_id, players);
        write_line("\n");
    }
    return;
}

void print_turn_line(const int number_of_turns)
{
    if (number_of_turns < 10)
    {
        write_line("\n                                    TURN 0%d                                   \n", number_of_turns);
    }
    else if (number_of_turns >= 10 && number_of_turns < 100)
    {
        write_line("\n                                    TURN %d                                   \n", number_of_turns);
    }
    else if (number_of_turns >= 100 && number_of_turns < 1000)
    {
        write_line("\n                                    TURN %d                                  \n", number_of_turns);
    }
    else if (number_of_turns >= 1000 && number_of_turns < 10000)
    {
        write_line("\n                                    TURN %d                                 \n", number_of_turns);
    }
    else
    {
        write_line("\n                                    TURN %d                                \n", number_of_turns);
    }
    return;
}

void print_column0(const int line, const int level, const int current_player_id, Player* players)
{
    if (line == 0 || line == 3 || line == 6 || line == 8 || line == 16 || ((level == 1 || level == 3) && (line >= 17 && line <= 26)) || (line >= 27 && line <= 41))
    {
        write_line("               ");
    }
    else if (line == 1)
    {
        write_line("  PLAYER ONE   ");
    }
    else if (line == 2)
    {
        write_line("%s", current_player_id == 0 ? " ............. " : "               ");
    }
    else if (line == 4)
    {
        write_line("      POINTS   ");
    }
    else if (line == 5)
    {
        if (PLAYER_ONE->points < 0)
            write_line("        00     ");
        else if (PLAYER_ONE->points < 10)
            write_line("        0%d     ", PLAYER_ONE->points);
        else
            write_line("        %d     ", PLAYER_ONE->points);
    }
    else if (line == 7)
    {
        write_line("      ALLIES   ");
    }
    else if (line == 9)
    {
        if (PLAYER_ONE->stoneset[0].coordinate == -1)
            write_line("      [Dead]   ");
        else if (PLAYER_ONE->stoneset[0].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "       [Won]   " : "     [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "         One   " : "        Lust   ");
    }
    else if (line == 10)
    {
        if (PLAYER_ONE->stoneset[1].coordinate == -1)
            write_line("      [Dead]   ");
        else if (PLAYER_ONE->stoneset[1].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "       [Won]   " : "     [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "         Two   " : "       Pride   ");
    }
    else if (line == 11)
    {
        if (PLAYER_ONE->stoneset[2].coordinate == -1)
            write_line("      [Dead]   ");
        else if (PLAYER_ONE->stoneset[2].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "       [Won]   " : "     [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "       Three   " : "    Gluttony   ");
    }
    else if (line == 12)
    {
        if (PLAYER_ONE->stoneset[3].coordinate == -1)
            write_line("      [Dead]   ");
        else if (PLAYER_ONE->stoneset[3].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "       [Won]   " : "     [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "        Four   " : "       Sloth   ");
    }
    else if (line == 13)
    {
        if (PLAYER_ONE->stoneset[4].coordinate == -1)
            write_line("      [Dead]   ");
        else if (PLAYER_ONE->stoneset[4].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "       [Won]   " : "     [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "        Five   " : "        Envy   ");
    }
    else if (line == 14)
    {
        if (PLAYER_ONE->stoneset[5].coordinate == -1)
            write_line("      [Dead]   ");
        else if (PLAYER_ONE->stoneset[5].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "       [Won]   " : "     [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "         Six   " : "       Wrath   ");
    }
    else if (line == 15)
    {
        if (PLAYER_ONE->stoneset[6].coordinate == -1)
            write_line("      [Dead]   ");
        else if (PLAYER_ONE->stoneset[6].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "       [Won]   " : "     [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "       Seven   " : "       Greed   ");
    }
    else if (level == 2 || level == 4)
    {
        if (line == 17)
        {
            write_line("     ENEMIES   ");
        }
        else if (line == 18)
        {
            write_line("      KILLED   ");
        }
        else if (line == 19)
        {
            write_line("%s", current_player_id == 0 ? " ............. " : "               ");
        }
        else if (line == 20)
        {
            write_line("%s", PLAYER_TWO->stoneset[0].coordinate != -1 ? "     [Empty]   " : level == 2 ? "         One   " : "        Lust   ");
        }
        else if (line == 21)
        {
            write_line("%s", PLAYER_TWO->stoneset[1].coordinate != -1 ? "     [Empty]   " : level == 2 ? "         Two   " : "       Pride   ");
        }
        else if (line == 22)
        {
            write_line("%s", PLAYER_TWO->stoneset[2].coordinate != -1 ? "     [Empty]   " : level == 2 ? "       Three   " : "    Gluttony   ");
        }
        else if (line == 23)
        {
            write_line("%s", PLAYER_TWO->stoneset[3].coordinate != -1 ? "     [Empty]   " : level == 2 ? "        Four   " : "       Sloth   ");
        }
        else if (line == 24)
        {
            write_line("%s", PLAYER_TWO->stoneset[4].coordinate != -1 ? "     [Empty]   " : level == 2 ? "        Five   " : "        Envy   ");
        }
        else if (line == 25)
        {
            write_line("%s", PLAYER_TWO->stoneset[5].coordinate != -1 ? "     [Empty]   " : level == 2 ? "         Six   " : "       Wrath   ");
        }
        else if (line == 26)
        {
            write_line("%s", PLAYER_TWO->stoneset[6].coordinate != -1 ? "     [Empty]   " : level == 2 ? "       Seven   " : "       Greed   ");
        }
    }
    return;
}

void print_column4(const int line, const int level, const int current_player_id, Player* players)
{
    if (line == 0 || line == 3 || line == 6 || line == 8 || line == 16 || ((level == 1 || level == 3) && (line >= 17 && line <= 26)) || (line >= 27 && line <= 41))
    {
        write_line("               ");
    }
    else if (line == 1)
    {
        write_line("   PLAYER TWO ");
    }
    else if (line == 2)
    {
        write_line("%s", current_player_id == 1 ? " ............." : "              ");
    }
    else if (line == 4)
    {
        write_line("   POINTS    ");
    }
    else if (line == 5)
    {
        if (PLAYER_TWO->points < 0)
            write_line("     00      ");
        else if (PLAYER_TWO->points < 10)
            write_line("     0%d      ", PLAYER_TWO->points);
        else
            write_line("     %d      ", PLAYER_TWO->points);
    }
    else if (line == 7)
    {
        write_line("   ALLIES    ");
    }
    else if (line == 9)
    {
        if (PLAYER_TWO->stoneset[0].coordinate == -1)
            write_line("   [Dead]    ");
        else if (PLAYER_TWO->stoneset[0].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "   [Won]     " : "   [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "   One       " : "   Lust      ");
    }
    else if (line == 10)
    {
        if (PLAYER_TWO->stoneset[1].coordinate == -1)
            write_line("   [Dead]    ");
        else if (PLAYER_TWO->stoneset[1].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "   [Won]     " : "   [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "   Two       " : "   Pride     ");
    }
    else if (line == 11)
    {
        if (PLAYER_TWO->stoneset[2].coordinate == -1)
            write_line("   [Dead]    ");
        else if (PLAYER_TWO->stoneset[2].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "   [Won]     " : "   [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "   Three     " : "   Gluttony  ");
    }
    else if (line == 12)
    {
        if (PLAYER_TWO->stoneset[3].coordinate == -1)
            write_line("   [Dead]    ");
        else if (PLAYER_TWO->stoneset[3].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "   [Won]     " : "   [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "   Four      " : "   Sloth     ");
    }
    else if (line == 13)
    {
        if (PLAYER_TWO->stoneset[4].coordinate == -1)
            write_line("   [Dead]    ");
        else if (PLAYER_TWO->stoneset[4].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "   [Won]     " : "   [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "   Five      " :  "   Envy     ");
    }
    else if (line == 14)
    {
        if (PLAYER_TWO->stoneset[5].coordinate == -1)
            write_line("   [Dead]    ");
        else if (PLAYER_TWO->stoneset[5].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "   [Won]     " : "   [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "   Six       " : "   Wrath     ");
    }
    else if (line == 15)
    {
        if (PLAYER_TWO->stoneset[6].coordinate == -1)
            write_line("   [Dead]    ");
        else if (PLAYER_TWO->stoneset[6].coordinate == 1)
            write_line("%s", level == 1 || level == 2 ? "   [Won]     " : "   [Saved]   ");
        else
            write_line("%s", level == 1 || level == 2 ? "   Seven     " : "   Greed     ");
    }
    else if (level == 2 || level == 4)
    {
        if (line == 17)
        {
            write_line("   ENEMIES   ");
        }
        else if (line == 18)
        {
            write_line("   KILLED    ");
        }
        else if (line == 19)
        {
            write_line("%s", current_player_id == 1 ? " ............." : "              ");
        }
        else if (line == 20)
        {
            write_line("%s", PLAYER_ONE->stoneset[0].coordinate != -1 ? "   [Empty]    " : level == 2 ? "   One        " : "   Lust       ");
        }
        else if (line == 21)
        {
            write_line("%s", PLAYER_ONE->stoneset[1].coordinate != -1 ? "   [Empty]    " : level == 2 ? "   Two        " : "   Pride      ");
        }
        else if (line == 22)
        {
            write_line("%s", PLAYER_ONE->stoneset[2].coordinate != -1 ? "   [Empty]    " : level == 2 ? "   Three      " : "   Gluttony   ");
        }
        else if (line == 23)
        {
            write_line("%s", PLAYER_ONE->stoneset[3].coordinate != -1 ? "   [Empty]    " : level == 2 ? "   Four       " : "   Sloth      ");
        }
        else if (line == 24)
        {
            write_line("%s", PLAYER_ONE->stoneset[4].coordinate != -1 ? "   [Empty]    " : level == 2 ? "   Five       " : "   Envy       ");
        }
        else if (line == 25)
        {
            write_line("%s", PLAYER_ONE->stoneset[5].coordinate != -1 ? "   [Empty]    " : level == 2 ? "   Six        " : "   Wrath      ");
        }
        else if (line == 26)
        {
            write_line("%s", PLAYER_ONE->stoneset[6].coordinate != -1 ? "   [Empty]    " : level == 2 ? "   Seven      " : "   Greed      ");
        }
    }
    return;
}

void print_column1(const int line, const int current_player_id, Cell* all_cells)
{
    int id, stone_belongs_to_current_player = 0;

    if (line == 0 || line == 30)
    {
        write_line(" _______________");
    }
    else if (line == 1 || line == 2 || line == 4 || line == 5 || line == 31 || line == 32 || line == 34 || line == 35)
    {
        write_line("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
    }
    else if (line == 6 || line == 7 || line == 9 || line == 11 || line == 12 || line == 14 || line == 16 || line == 17 || line == 19 || line == 36 || line == 37 || line == 39)
    {
        write_line("|               ");
    }
    else if (line == 10 || line == 15 || line == 20 || line == 40)
    {
        write_line("|_______________");
    }
    else if ((line >= 21 && line <= 29) || line == 41)
    {
        write_line("                ");
    }
    else if (line == 3)
    {
        /* Cell Coordinate 11 */
        if ((all_cells + 0)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 0)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 0)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[01]▒▒▒▒▒" : "|▒▒▒▒▒▒ 01 ▒▒▒▒▒");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[02]▒▒▒▒▒" : "|▒▒▒▒▒▒ 02 ▒▒▒▒▒");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[03]▒▒▒▒▒" : "|▒▒▒▒▒▒ 03 ▒▒▒▒▒");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[04]▒▒▒▒▒" : "|▒▒▒▒▒▒ 04 ▒▒▒▒▒");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[05]▒▒▒▒▒" : "|▒▒▒▒▒▒ 05 ▒▒▒▒▒");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[06]▒▒▒▒▒" : "|▒▒▒▒▒▒ 06 ▒▒▒▒▒");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[07]▒▒▒▒▒" : "|▒▒▒▒▒▒ 07 ▒▒▒▒▒");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[Lust]▒▒▒▒" : "|▒▒▒▒▒ Lust ▒▒▒▒");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Pride]▒▒▒▒" : "|▒▒▒▒ Pride ▒▒▒▒");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒[Gluttony]▒▒" : "|▒▒▒ Gluttony ▒▒");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Sloth]▒▒▒▒" : "|▒▒▒▒ Sloth ▒▒▒▒");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[Envy]▒▒▒▒" : "|▒▒▒▒▒ Envy ▒▒▒▒");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Wrath]▒▒▒▒" : "|▒▒▒▒ Wrath ▒▒▒▒");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Greed]▒▒▒▒" : "|▒▒▒▒ Greed ▒▒▒▒");
        }
    }
    else if (line == 8)
    {
        /* Cell Coordinate 12 */
        if ((all_cells + 3)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 3)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 3)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)

                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 13)
    {
        /* Cell Coordinate 13 */
        if ((all_cells + 6)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 6)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 6)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 18)
    {
        /* Cell Coordinate 14 */
        if ((all_cells + 9)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 9)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 9)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 33)
    {
        /* Cell Coordinate 17 */
        if ((all_cells + 14)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 14)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 14)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
        else
        {
            if (id == ID_STONE_ONE)

                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[01]▒▒▒▒▒" : "|▒▒▒▒▒▒ 01 ▒▒▒▒▒");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[02]▒▒▒▒▒" : "|▒▒▒▒▒▒ 02 ▒▒▒▒▒");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[03]▒▒▒▒▒" : "|▒▒▒▒▒▒ 03 ▒▒▒▒▒");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[04]▒▒▒▒▒" : "|▒▒▒▒▒▒ 04 ▒▒▒▒▒");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[05]▒▒▒▒▒" : "|▒▒▒▒▒▒ 05 ▒▒▒▒▒");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[06]▒▒▒▒▒" : "|▒▒▒▒▒▒ 06 ▒▒▒▒▒");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[07]▒▒▒▒▒" : "|▒▒▒▒▒▒ 07 ▒▒▒▒▒");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[Lust]▒▒▒▒" : "|▒▒▒▒▒ Lust ▒▒▒▒");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Pride]▒▒▒▒" : "|▒▒▒▒ Pride ▒▒▒▒");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒[Gluttony]▒▒" : "|▒▒▒ Gluttony ▒▒");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Sloth]▒▒▒▒" : "|▒▒▒▒ Sloth ▒▒▒▒");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[Envy]▒▒▒▒" : "|▒▒▒▒▒ Envy ▒▒▒▒");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Wrath]▒▒▒▒" : "|▒▒▒▒ Wrath ▒▒▒▒");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Greed]▒▒▒▒" : "|▒▒▒▒ Greed ▒▒▒▒");
        }
    }
    else if (line == 38)
    {
        /* Cell Coordinate 18 */
        if ((all_cells + 17)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 17)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 17)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    return;
}

void print_column2(const int line, const int current_player_id, Cell* all_cells)
{
    int id, stone_belongs_to_current_player = 0;

    if (line == 0)
    {
        write_line("________________");
    }
    else if (line == 1 || line == 2 || line == 4 || line == 6 || line == 7 || line == 9 || line == 11 || line == 12 || line == 14 || line == 21 ||
        line == 22 || line == 24 || line == 26 || line == 27 || line == 29 || line == 31 || line == 32 || line == 34 || line == 36 || line == 37 || line == 39)
    {
        write_line("|               ");
    }
    else if (line == 5 || line == 10 || line == 15 || line == 25 || line == 30 || line == 35 || line == 40)
    {
        write_line("|_______________");
    }
    else if (line == 16 || line == 17 || line == 19 || line == 20)
    {
        write_line("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
    }
    else if (line == 41)
    {
        write_line("                ");
    }
    else if (line == 3)
    {
        /* Cell Coordinate 21 */
        if ((all_cells + 1)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 1)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 1)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 8)
    {
        /* Cell Coordinate 22 */
        if ((all_cells + 4)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 4)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 4)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 13)
    {
        /* Cell Coordinate 23 */
        if ((all_cells + 7)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 7)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 7)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 18)
    {
        /* Cell Coordinate 24 */
        if ((all_cells + 10)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 10)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 10)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[01]▒▒▒▒▒" : "|▒▒▒▒▒▒ 01 ▒▒▒▒▒");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[02]▒▒▒▒▒" : "|▒▒▒▒▒▒ 02 ▒▒▒▒▒");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[03]▒▒▒▒▒" : "|▒▒▒▒▒▒ 03 ▒▒▒▒▒");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[04]▒▒▒▒▒" : "|▒▒▒▒▒▒ 04 ▒▒▒▒▒");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[05]▒▒▒▒▒" : "|▒▒▒▒▒▒ 05 ▒▒▒▒▒");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[06]▒▒▒▒▒" : "|▒▒▒▒▒▒ 06 ▒▒▒▒▒");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒▒[07]▒▒▒▒▒" : "|▒▒▒▒▒▒ 07 ▒▒▒▒▒");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[Lust]▒▒▒▒" : "|▒▒▒▒▒ Lust ▒▒▒▒");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Pride]▒▒▒▒" : "|▒▒▒▒ Pride ▒▒▒▒");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒[Gluttony]▒▒" : "|▒▒▒ Gluttony ▒▒");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Sloth]▒▒▒▒" : "|▒▒▒▒ Sloth ▒▒▒▒");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[Envy]▒▒▒▒" : "|▒▒▒▒▒ Envy ▒▒▒▒");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Wrath]▒▒▒▒" : "|▒▒▒▒ Wrath ▒▒▒▒");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Greed]▒▒▒▒" : "|▒▒▒▒ Greed ▒▒▒▒");
        }
    }
    else if (line == 23)
    {
        /* Cell Coordinate 25 */
        if ((all_cells + 12)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 12)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 12)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 28)
    {
        /* Cell Coordinate 26 */
        if ((all_cells + 13)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 13)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 13)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 33)
    {
        /* Cell Coordinate 27 */
        if ((all_cells + 15)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 15)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 15)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    else if (line == 38)
    {
        /* Cell Coordinate 28 */
        if ((all_cells + 18)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 18)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 18)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               ");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|      [01]     " : "|       01      ");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|      [02]     " : "|       02      ");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|      [03]     " : "|       03      ");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|      [04]     " : "|       04      " );
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|      [05]     " : "|       05      ");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|      [06]     " : "|       06      ");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|      [07]     " : "|       07      ");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|     [Lust]    " : "|      Lust     ");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    " : "|     Pride     ");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|   [Gluttony]  " : "|    Gluttony   ");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    " : "|     Sloth     ");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|     [Envy]    " : "|      Envy     ");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    " : "|     Wrath     ");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    " : "|     Greed     ");
        }
    }
    return;
}

void print_column3(const int line, const int current_player_id, Cell* all_cells)
{
    int id, stone_belongs_to_current_player = 0;

    if (line == 0)
    {
        write_line("________________");
    }
    else if (line == 1 || line == 2 || line == 4 || line == 5 || line == 31 || line == 32 || line == 34 || line == 35)
    {
        write_line("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒|");
    }
    else if (line == 6 || line == 7 || line == 9 || line == 11 || line == 12 || line == 14 || line == 16 || line == 17 || line == 19 || line == 36 || line == 37 || line == 39)
    {
        write_line("|               |");
    }
    else if (line == 10 || line == 15 || line == 20 || line == 40)
    {
        write_line("|_______________|");
    }
    else if (line >= 21 && line <= 29)
    {
        write_line("|                ");
    }
    else if (line == 30)
    {
        write_line("|_______________ ");
    }
    else if (line == 41)
    {
        write_line("                 ");
    }
    else if (line == 3)
    {
        /* Cell Coordinate 31 */
        if ((all_cells + 2)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 2)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 2)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒|");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[01]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 01 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[02]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 02 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[03]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 03 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[04]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 04 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[05]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 05 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[06]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 06 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[07]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 07 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Lust]▒▒▒▒▒|" : "|▒▒▒▒ Lust ▒▒▒▒▒|");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Pride]▒▒▒▒|" : "|▒▒▒▒ Pride ▒▒▒▒|");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒[Gluttony]▒▒▒|" : "|▒▒ Gluttony ▒▒▒|");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Sloth]▒▒▒▒|" : "|▒▒▒▒ Sloth ▒▒▒▒|");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Envy]▒▒▒▒▒|" : "|▒▒▒▒ Envy ▒▒▒▒▒|");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Wrath]▒▒▒▒|" : "|▒▒▒▒ Wrath ▒▒▒▒|");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Greed]▒▒▒▒|" : "|▒▒▒▒ Greed ▒▒▒▒|");
        }
    }
    else if (line == 8)
    {
        /* Cell Coordinate 32 */
        if ((all_cells + 5)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 5)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 5)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               |");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|     [01]      |" : "|      01       |");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|     [02]      |" : "|      02       |");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|     [03]      |" : "|      03       |");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|     [04]      |" : "|      04       |");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|     [05]      |" : "|      05       |");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|     [06]      |" : "|      06       |");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|     [07]      |" : "|      07       |");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|    [Lust]     |" : "|     Lust      |");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    |" : "|     Pride     |");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|  [Gluttony]   |" : "|   Gluttony    |");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    |" : "|     Sloth     |");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|    [Envy]     |" : "|     Envy      |");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    |" : "|     Wrath     |");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    |" : "|     Greed     |");
        }
    }
    else if (line == 13)
    {
        /* Cell Coordinate 33 */
        if ((all_cells + 8)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 8)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 8)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               |");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|     [01]      |" : "|      01       |");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|     [02]      |" : "|      02       |");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|     [03]      |" : "|      03       |");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|     [04]      |" : "|      04       |");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|     [05]      |" : "|      05       |");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|     [06]      |" : "|      06       |");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|     [07]      |" : "|      07       |");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|    [Lust]     |" : "|     Lust      |");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    |" : "|     Pride     |");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|  [Gluttony]   |" : "|   Gluttony    |");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    |" : "|     Sloth     |");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|    [Envy]     |" : "|     Envy      |");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    |" : "|     Wrath     |");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    |" : "|     Greed     |");
        }
    }
    else if (line == 18)
    {
        /* Cell Coordinate 34 */
        if ((all_cells + 11)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 11)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 11)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               |");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|     [01]      |" : "|      01       |");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|     [02]      |" : "|      02       |");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|     [03]      |" : "|      03       |");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|     [04]      |" : "|      04       |");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|     [05]      |" : "|      05       |");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|     [06]      |" : "|      06       |");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|     [07]      |" : "|      07       |");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|    [Lust]     |" : "|     Lust      |");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    |" : "|     Pride     |");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|  [Gluttony]   |" : "|   Gluttony    |");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    |" : "|     Sloth     |");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|    [Envy]     |" : "|     Envy      |");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    |" : "|     Wrath     |");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    |" : "|     Greed     |");
        }
    }
    else if (line == 33)
    {
        /* Cell Coordinate 37 */
        if ((all_cells + 16)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 16)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 16)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒|");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[01]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 01 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[02]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 02 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[03]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 03 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[04]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 04 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[05]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 05 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[06]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 06 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒▒[07]▒▒▒▒▒▒|" : "|▒▒▒▒▒ 07 ▒▒▒▒▒▒|");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Lust]▒▒▒▒▒|" : "|▒▒▒▒ Lust ▒▒▒▒▒|");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Pride]▒▒▒▒|" : "|▒▒▒▒ Pride ▒▒▒▒|");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒[Gluttony]▒▒▒|" : "|▒▒ Gluttony ▒▒▒|");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Sloth]▒▒▒▒|" : "|▒▒▒▒ Sloth ▒▒▒▒|");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Envy]▒▒▒▒▒|" : "|▒▒▒▒ Envy ▒▒▒▒▒|");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Wrath]▒▒▒▒|" : "|▒▒▒▒ Wrath ▒▒▒▒|");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|▒▒▒▒[Greed]▒▒▒▒|" : "|▒▒▒▒ Greed ▒▒▒▒|");
        }
    }
    else if (line == 38)
    {
        /* Cell Coordinate 38 */
        if ((all_cells + 19)->stone_in_cell == NULL)
            id = 0;
        else
        {
            id = (all_cells + 19)->stone_in_cell->id;
            stone_belongs_to_current_player = (all_cells + 19)->stone_in_cell->player_id == current_player_id ? 1 : 0;
        }

        if (!id)
            write_line("|               |");
        else
        {
            if (id == ID_STONE_ONE)
                write_line("%s", stone_belongs_to_current_player ? "|     [01]      |" : "|      01       |");
            else if (id == ID_STONE_TWO)
                write_line("%s", stone_belongs_to_current_player ? "|     [02]      |" : "|      02       |");
            else if (id == ID_STONE_THREE)
                write_line("%s", stone_belongs_to_current_player ? "|     [03]      |" : "|      03       |");
            else if (id == ID_STONE_FOUR)
                write_line("%s", stone_belongs_to_current_player ? "|     [04]      |" : "|      04       |");
            else if (id == ID_STONE_FIVE)
                write_line("%s", stone_belongs_to_current_player ? "|     [05]      |" : "|      05       |");
            else if (id == ID_STONE_SIX)
                write_line("%s", stone_belongs_to_current_player ? "|     [06]      |" : "|      06       |");
            else if (id == ID_STONE_SEVEN)
                write_line("%s", stone_belongs_to_current_player ? "|     [07]      |" : "|      07       |");
            else if (id == ID_STONE_LUST)
                write_line("%s", stone_belongs_to_current_player ? "|    [Lust]     |" : "|     Lust      |");
            else if (id == ID_STONE_PRIDE)
                write_line("%s", stone_belongs_to_current_player ? "|    [Pride]    |" : "|     Pride     |");
            else if (id == ID_STONE_GLUTTONY)
                write_line("%s", stone_belongs_to_current_player ? "|  [Gluttony]   |" : "|   Gluttony    |");
            else if (id == ID_STONE_SLOTH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Sloth]    |" : "|     Sloth     |");
            else if (id == ID_STONE_ENVY)
                write_line("%s", stone_belongs_to_current_player ? "|    [Envy]     |" : "|     Envy      |");
            else if (id == ID_STONE_WRATH)
                write_line("%s", stone_belongs_to_current_player ? "|    [Wrath]    |" : "|     Wrath     |");
            else if (id == ID_STONE_GREED)
                write_line("%s", stone_belongs_to_current_player ? "|    [Greed]    |" : "|     Greed     |");
        }
    }
    return;
}

