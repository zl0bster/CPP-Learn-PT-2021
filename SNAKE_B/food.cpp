
#include <ctype.h>

#include "screen.h"
#include "food.h"
#include "snake.h"

using std::rand;

namespace
{
	Coord foodPos;
}

bool is_food_here(Coord& pos)
{
	return (are_coords_equal(foodPos, pos));
}

void init_food()
{
	do
	{
		Coord limits;
		get_limits(limits);
		get_rand_pos(limits, foodPos);
	}
	while (is_snake_here(foodPos));
}

void set_food_pos(Coord& pos)
{
	foodPos.x = pos.x;
	foodPos.y = pos.y;
}

void print_food()
{
	PrintSequenceItem item;
	item.xPos = foodPos.x;
	item.yPos = foodPos.y;
	item.symbol = foodField;
	put_sequence(&item);
}



