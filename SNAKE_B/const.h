#pragma once
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

#include "GraphicsLib.h"
//#include "game.h"

struct Coord {
	int x;
	int y;
};

 const int moveDelay = 150;
 const Colors emptyField = EMPTY;
 const Colors headField = BLUE;
 const Colors bodyField = GREEN;
 const Colors foodField = RED;

 bool are_coords_equal(Coord& pos1, Coord& pos2);
 void get_rand_pos(Coord& limits, Coord& pos);