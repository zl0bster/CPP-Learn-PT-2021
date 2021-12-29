
#include <ctype.h>

#include "screen.h"
#include "food.h"
#include "snake.h"

bool is_food_here(FoodData* fd, Coord& pos)
{
	return (are_coords_equal(fd->foodPos, pos));
}

FoodData* init_food(FieldData* fp)
{
	FoodData* fd = new FoodData;
	fd->fp = fp;
	return fd;
}

void set_food_pos(FoodData* fd, SnakeData* sd)
{
	do
	{
		Coord limits;
		get_limits(fd->fp, limits);
		get_rand_pos(limits, fd->foodPos);
	} while (is_snake_here(sd, fd->foodPos));
}

void print_food(FoodData* fd)
{
	PrintSequenceItem item;
	item.xPos = fd->foodPos.x;
	item.yPos = fd->foodPos.y;
	item.symbol = foodField;
	put_sequence(fd->fp, &item);
}

void food_destructor(FoodData* fd)
{
	delete fd;
}

