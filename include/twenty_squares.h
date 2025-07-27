#ifndef TWENTY_SQUARES_H
# define TWENTY_SQUARES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# ifdef _WIN32
#  include <windows.h>
# endif

# define FS '\x1C'

# define STONE_NAME_LEN               9
# define PLAYER_NAME_LEN              11

# define ID_STONE_ONE                 1
# define ID_STONE_TWO                 2
# define ID_STONE_THREE               3
# define ID_STONE_FOUR                4
# define ID_STONE_FIVE                5
# define ID_STONE_SIX                 6
# define ID_STONE_SEVEN               7
# define ID_STONE_LUST                8
# define ID_STONE_PRIDE               9
# define ID_STONE_GLUTTONY            10
# define ID_STONE_SLOTH               11
# define ID_STONE_ENVY                12
# define ID_STONE_WRATH               13
# define ID_STONE_GREED               14

# define INDEX_1_ON_4_INITIAL_ROAD    0
# define INDEX_2_ON_4_INITIAL_ROAD    1
# define INDEX_3_ON_4_INITIAL_ROAD    2
# define INDEX_4_ON_4_INITIAL_ROAD    3
# define INDEX_1_ON_8_COMMON_ROAD     4
# define INDEX_2_ON_8_COMMON_ROAD     5
# define INDEX_3_ON_8_COMMON_ROAD     6
# define INDEX_4_ON_8_COMMON_ROAD     7
# define INDEX_5_ON_8_COMMON_ROAD     8
# define INDEX_6_ON_8_COMMON_ROAD     9
# define INDEX_7_ON_8_COMMON_ROAD     10
# define INDEX_8_ON_8_COMMON_ROAD     11
# define INDEX_1_ON_2_END_ROAD        12
# define INDEX_2_ON_2_END_ROAD        13
# define INDEX_OUT_OF_BOUND           14

typedef struct s_stone
{
	char	name[STONE_NAME_LEN];
	int		id;
	int		player_id;
	int		coord;
	int		is_protected;
	int		can_move;
	int		moves[4];
}	t_stone;

typedef struct s_cell
{
	int		coord;
	t_stone	*stone;
	int		is_rosette;
}	t_cell;

typedef struct s_player
{
	int		id;
	char	name[PLAYER_NAME_LEN];
	int		is_ai;
	int		points;
	// Stones which aren't dead or won/saved, even if they can't move:
	int		nbr_playable;
	t_stone	stoneset[7];
	// The 15th element is INDEX_OUT_OF_BOUND and has a coordinate of "1":
	t_cell	*track[15];
}	t_player;

/* Board -------------------------------------------------------------------- */

void		print_board(int nbr_turns, int lvl, int player_id,
				t_player *players, t_cell *cells);
void		print_turn_line(int nbr_turns);
void		print_column0(int line, int lvl, int player_id, t_player *players);
void		print_column1(int line, int player_id, t_cell *cells);
void		print_column2(int line, int player_id, t_cell *cells);
void		print_column3(int line, int player_id, t_cell *cells);
void		print_column4(int line, int lvl, int player_id, t_player *players);

/* Init --------------------------------------------------------------------- */

void		init_cells(t_cell *cells);
void		init_players(int lvl, int human_player, t_player *players,
				t_cell *cells);

/* Input -------------------------------------------------------------------- */

const char	**get_input(void);
int			ask_yes_no(const char *question);
int			ask_nbr(int min_nbr, int max_nbr, const char *question);
int			ask_nbr_from_arr(const int *arr, int len, const char *question);
void		press_enter_to_continue(void);

/* Movement ----------------------------------------------------------------- */

int			set_nbr_moveable_and_can_move(t_player *player, int lvl, int dice);
int			can_stone_move(const t_stone *stone, t_player *player, int dice);
int			can_stone_move_ds(t_stone *stone, t_player *player, int dice);
int			move_stone(int lvl, int dist_to_move, t_stone *stone, t_cell **cell,
				t_player *player, t_player *other_player);

/* Selection ---------------------------------------------------------------- */

t_stone		*select_stone(t_player *player);
int			select_dist_to_move(const t_player *player, const t_stone *stone);

/* Turn --------------------------------------------------------------------- */

void		start_game(void);
void		game_loop(int lvl, t_player *players, t_cell *cells);
int			determine_winner(t_player *players);

/* Utils -------------------------------------------------------------------- */

size_t		count_arr(void **arr);
void		free_arr(void **arr, void (*free_fct)(void *));
void		remove_arr_elems(void **arr, size_t from, size_t to,
				void (*free_fct)(void *));
void		clear_window(void);
void		clear_prev_line(void);
char		*gnl(int fd);
int			rng_minmax(int min, int max);
char		**split(const char *s, char c);

#endif
