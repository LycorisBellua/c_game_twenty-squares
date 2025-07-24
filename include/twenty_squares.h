#ifndef TWENTY_SQUARES_H
#define TWENTY_SQUARES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define ID_STONE_ONE                    1
#define ID_STONE_TWO                    2
#define ID_STONE_THREE                  3
#define ID_STONE_FOUR                   4
#define ID_STONE_FIVE                   5
#define ID_STONE_SIX                    6
#define ID_STONE_SEVEN                  7
#define ID_STONE_LUST                   8
#define ID_STONE_PRIDE                  9
#define ID_STONE_GLUTTONY               10
#define ID_STONE_SLOTH                  11
#define ID_STONE_ENVY                   12
#define ID_STONE_WRATH                  13
#define ID_STONE_GREED                  14

#define ABILITY_NONE                    0
#define ABILITY_CLASSIC                 1
#define ABILITY_AIR                     2
#define ABILITY_EARTH                   3
#define ABILITY_WATER                   4
#define ABILITY_FIRE                    5

#define DS_DECISION_PLAYER              0
#define DS_DECISION_USE                 1
#define DS_DECISION_DISCARD             2

#define INDEX_1_ON_4_INITIAL_ROAD       0
#define INDEX_2_ON_4_INITIAL_ROAD       1
#define INDEX_3_ON_4_INITIAL_ROAD       2
#define INDEX_4_ON_4_INITIAL_ROAD       3
#define INDEX_1_ON_8_COMMON_ROAD        4
#define INDEX_2_ON_8_COMMON_ROAD        5
#define INDEX_3_ON_8_COMMON_ROAD        6
#define INDEX_4_ON_8_COMMON_ROAD        7
#define INDEX_5_ON_8_COMMON_ROAD        8
#define INDEX_6_ON_8_COMMON_ROAD        9
#define INDEX_7_ON_8_COMMON_ROAD        10
#define INDEX_8_ON_8_COMMON_ROAD        11
#define INDEX_1_ON_2_END_ROAD           12
#define INDEX_2_ON_2_END_ROAD           13
#define INDEX_OUT_OF_BOUND              14
#define INDEX_1_ON_3_NO_KILLING_ROAD    11
#define INDEX_2_ON_3_NO_KILLING_ROAD    12
#define INDEX_3_ON_3_NO_KILLING_ROAD    13

#define LENGTH_STONE_NAME               9
#define LENGTH_PLAYER_NAME              11
#define PLAYER_ONE                      (players + 0)
#define PLAYER_TWO                      (players + 1)

typedef struct
{
	char	name[LENGTH_STONE_NAME];
	int		id;
	int		player_id;
	int		coordinate;
	int		protected_by_earth;
	int		can_stone_move;
	int		possible_movements[4];
}	Stone;

typedef struct
{
	int		coordinate;
	Stone	*stone_in_cell;
	int		ability;
	int		is_cell_special;
}	Cell;

typedef struct
{
	int		id;
	char	name[11];
	int		is_ai;
	int		points;
	int		number_of_playable_stones;	// Stones that aren't dead or won/saved,
										// even if they can't move
	int		number_of_stones_on_board;	// Stones that are strictly on the board
	Stone	stoneset[7];
	Cell	*racetrack[15];	// The 15th element is INDEX_OUT_OF_BOUND and has a 
							// coordinate of "1"
}	Player;

extern int rng_seed;

/* Init --------------------------------------------------------------------- */

int		start(int argc, char **argv);

/* Abilities ---------------------------------------------------------------- */

int		set_ability(int level, Cell ***target_cell, const Player *players,
			const Player *current_player);
void	describe_ability(int ability, int dice);
int		ds_stones_handle_ability(const Stone *chosen_stone, int ability,
			int level, const Player *current_player,
			const Player *other_player);
void	execute_ability_fire(int level, Player *players, Player *current_player,
			Cell *all_cells);
void	execute_ability_water(int dice, int level, Player *players,
			Player *current_player, Cell *all_cells);
void	remove_stone_from_board(Cell *all_cells, int ability, int level,
			Player *targeted_player, Player *current_player);

/* Board -------------------------------------------------------------------- */

void	print_board(int number_of_turns, int level, int current_player_id,
			Player *players, Cell *all_cells);
void	print_turn_line(int number_of_turns);
void	print_column0(int line, int level, int current_player_id,
			Player *players);
void	print_column1(int line, int current_player_id, Cell *all_cells);
void	print_column2(int line, int current_player_id, Cell *all_cells);
void	print_column3(int line, int current_player_id, Cell *all_cells);
void	print_column4(int line, int level, int current_player_id,
			Player *players);

/* Cells -------------------------------------------------------------------- */

void	initialize_all_cells(Cell *all_cells);

/* Movement ----------------------------------------------------------------- */

int		set_number_of_moveable_stones_and_every_can_stone_move(
			Player *current_player, int level, int dice);
int		can_this_classic_stone_move(const Stone *stone, Player *current_player,
			int dice);
int		can_this_ds_stone_move(Stone *stone, Player *current_player, int dice);
int		move_stone(int level, int number_of_cells_forward, Stone *chosen_stone,
			Cell ***target_cell, Player *current_player, Player *other_player);

/* Players ------------------------------------------------------------------ */

void	initialize_players(int level, int human_player, Player *players,
			Cell *all_cells);

/* RNG ---------------------------------------------------------------------- */

int		generate_seed(void);
int		rng_minmax(int *seed, int min, int max);

/* Selection ---------------------------------------------------------------- */

Stone	*select_stone(char *input, Player *current_player);
int		select_number_of_cells_forward(const Player *current_player,
			const Stone *chosen_stone);
int		select_use_ability(const Player *current_player, int ability,
			int ds_decision, Cell ***target_cell);
int		select_number_of_stones_for_water(int max_number,
			const Player *current_player);
int		select_player_for_water(const Player *current_player);

/* Turn --------------------------------------------------------------------- */

void	start_game(void);
void	game_loop(int level, Player *players, Cell *all_cells);
void	determine_winner(char *input, Player *players);

#endif
