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

# define INDEX_HOME                0
# define INDEX_1_ON_4_INITIAL_ROAD 1
# define INDEX_2_ON_4_INITIAL_ROAD 2
# define INDEX_3_ON_4_INITIAL_ROAD 3
# define INDEX_4_ON_4_INITIAL_ROAD 4
# define INDEX_1_ON_8_COMMON_ROAD  5
# define INDEX_2_ON_8_COMMON_ROAD  6
# define INDEX_3_ON_8_COMMON_ROAD  7
# define INDEX_4_ON_8_COMMON_ROAD  8
# define INDEX_5_ON_8_COMMON_ROAD  9
# define INDEX_6_ON_8_COMMON_ROAD  10
# define INDEX_7_ON_8_COMMON_ROAD  11
# define INDEX_8_ON_8_COMMON_ROAD  12
# define INDEX_1_ON_2_END_ROAD     13
# define INDEX_2_ON_2_END_ROAD     14
# define INDEX_VICTORY             15

typedef struct s_stone t_stone;

typedef struct s_cell
{
	int		is_rosette;
	t_stone	*stone;
}	t_cell;

struct s_stone
{
	const char	*name;
	const char	*name_long;
	int			player_id;
	t_cell		*cell;
	int			is_protected;
	int			can_move;
	int			moves[4];
};

typedef struct s_player
{
	int			id;
	int			is_ai;
	int			points;
	int			nbr_playable;
	t_cell		*track[16];
	t_stone		stones[7];
}	t_player;

typedef struct s_game
{
	t_cell		cells[8][3];
	t_player	players[2];
	int			lvl;
	int			turn_nbr;
	int			dice;
	int			dist_to_move;
	int			nbr_moveable;
	int			has_stone_moved;
	int			is_turn_played_twice;
	t_stone		*stone;
	t_cell		*cell;
	t_player	*player;
	t_player	*other_player;
}	t_game;

/* Board -------------------------------------------------------------------- */

void		print_board(t_game *game);
void		print_stone(const t_stone* s, int player_id, int col_num);
void		print_stone_rosette(const t_stone* s, int player_id, int col_num);
void		print_stone_p(const t_stone* s, t_cell** track);

/* Guide -------------------------------------------------------------------- */

void		display_guide_intro(void);
void		display_guide_page1(void);
void		display_guide_page2(void);
void		display_guide_page3(void);
const char	*get_player_name(int index);
const char	*get_level_name(int level);
const char	*get_stone_name(int level, int index, int full);

/* Init --------------------------------------------------------------------- */

void		start_game(const char *arg);
void		init_cells(t_game *game);
void		init_players(t_game *game);
void		reset_cells(t_game *game);
void		reset_players(t_game *game);

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
int			move_stone(t_game *game);

/* Selection ---------------------------------------------------------------- */

t_stone		*select_stone(t_player *player);
int			select_dist_to_move(t_game *game);

/* Turn --------------------------------------------------------------------- */

void		game_loop(t_game *game);

/* Utils -------------------------------------------------------------------- */

void		printl(const char *line);
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
