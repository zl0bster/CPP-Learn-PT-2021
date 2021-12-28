#pragma once
#include "game.h"
#include "const.h"

enum Directions
{
	MOVE_UP,
	MOVE_DN,
	MOVE_RT,
	MOVE_LT,
	NOP
};

void init_snake(int snakeLen);
Directions change_snake_dir(Directions newDir);
bool is_snake_here(Coord& pos);
void do_life_step(Directions snakeDir);
void do_life_step1();

void snake_destructor();
