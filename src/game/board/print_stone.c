#include "twenty_squares.h"

void	print_stone(const t_stone* s, int player_id, int col_num)
{
	if (!s)
		printf("|       ");
	else if (s->player_id == player_id)
		printf("|  [%s]%s", s->name, strlen(s->name) == 1 ? "  " : " ");
	else
		printf("|   %s %s", s->name, strlen(s->name) == 1 ? "  " : " ");
	if (col_num == 3)
		printf("|");
	return ;
}

void	print_stone_rosette(const t_stone* s, int player_id, int col_num)
{
	if (!s)
		printf("|▒▒▒▒▒▒▒");
	else if (s->player_id == player_id)
		printf("|▒▒[%s]%s", s->name, strlen(s->name) == 1 ? "▒▒" : "▒");
	else
		printf("|▒▒ %s %s", s->name, strlen(s->name) == 1 ? "▒▒" : "▒");
	if (col_num == 3)
		printf("|");
	return ;
}

void	print_stone_p(const t_stone* s, t_cell** track)
{
	const char	*name;

	if (!s->cell)
		name = "[Dead]";
	else if (s->cell == track[INDEX_VICTORY])
		name = "[Saved]";
	else
		name = s->name_long;
	if (s->player_id == 0)
		printf("%*s%s   ", 12 - (int)strlen(name), "", name);
	else
		printf("   %s%*s", name, 12 - (int)strlen(name), "");
	return ;
}
