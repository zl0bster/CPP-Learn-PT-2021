#pragma once
#if defined _SCREEN_SET
#define _SCREEN_SET

#endif // 
#include "game.h"
#include "const.h"

struct PrintSequenceItem
{
	int xPos;
	int yPos;
	char symbol;
};

void clear_screen();
// draws border and fills field with fill in char ("space" or etc.)

int put_sequence(const PrintSequenceItem* charSeq, size_t seqSize=1);
// puts char sequence to deefined coords of screen array

void draw_screen();

void print_menu();

int get_xResolution();
int get_yResolution();
void get_limits(Coord& lims);