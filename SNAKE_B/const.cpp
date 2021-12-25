#include "const.h"

bool are_coords_equal(Coord& pos1, Coord& pos2)
{
	return ((pos1.x == pos2.x) && (pos1.y == pos2.y));
}

void get_rand_pos(Coord& limits, Coord& pos)
{
	pos.x = rand() % limits.x;
	pos.y = rand() % limits.y;
}