#pragma once
#include "game.h"
#include "const.h"
#include "windows.h"

enum Directions
{
	MOVE_UP,
	MOVE_DN,
	MOVE_RT,
	MOVE_LT,
	NOP
};

void init_snake(int snakeLen);
bool is_snake_here(Coord& pos);
void do_life_step(Directions snakeDir);
void do_life_step1(Directions newDir);
