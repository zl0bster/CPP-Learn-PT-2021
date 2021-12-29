#pragma once
#include "game.h"
#include "const.h"
#include "food.h"

enum Directions
{
	MOVE_UP,
	MOVE_DN,
	MOVE_RT,
	MOVE_LT,
	NOP
};

struct SnakeData
{
	Coord* snakePos;
	int snakeSizeMax;
	size_t snakeSize = 5;
	Directions snakeDir = MOVE_RT;
	PrintSequenceItem* snakeFigure;
	FieldData* fp;
	FoodData* fd;
};

SnakeData* init_snake(FieldData* fp, FoodData* fd, int snakeLen);
Directions change_snake_dir(SnakeData* sd, Directions newDir);
bool is_snake_here(SnakeData* sd, Coord& pos);
void do_life_step(SnakeData* sd, Directions snakeDir);
void do_life_step1(SnakeData* sd);

void snake_destructor(SnakeData* sd);
