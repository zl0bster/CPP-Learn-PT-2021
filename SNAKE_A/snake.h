#pragma once
#include "screen.h"
#include "const.h"
#include "windows.h"

//const size_t MAX_SIZE = 10;
//const size_t _DELAY = 100;

struct Coord {
	int x;
	int y;
};

enum Directions
{
	MOVE_UP,
	MOVE_DN,
	MOVE_RT,
	MOVE_LT,
	NOP
};

void init_snake();



void do_life_step(Actions snakeDir);