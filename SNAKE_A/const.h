#pragma once
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

//#include "game.h"

struct Coord {
	int x;
	int y;
};

 const char xResolution = 24;
 const char yResolution = 8;
 const char emptyFill = ' \'';
 const char borderFill = '#';
 const char headSymbol = 'H';
 const char taleSymbol = 'o';
 const char foodSymbol = 'f';
 const int moveDelay = 150;

 bool are_coords_equal(Coord& pos1, Coord& pos2);
 void get_rand_pos(Coord& limits, Coord& pos);