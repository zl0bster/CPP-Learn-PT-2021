#pragma once
#include "const.h"
#include "screen.h"
#include "food.h"
#include "snake.h"

struct FoodData
{
	Coord foodPos;
	FieldData* fp;
};

bool is_food_here(FoodData* fd, Coord& pos);
FoodData* init_food(FieldData* fp);
void set_food_pos(FoodData* fd, SnakeData* sd);
void print_food(FoodData* fd);

void food_destructor(FoodData* fd);
