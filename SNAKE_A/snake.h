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
//
//Coord snakePos[MAX_SIZE];
//size_t snakeSize = 5;

void init_snake();



void do_life_step(Actions snakeDir);