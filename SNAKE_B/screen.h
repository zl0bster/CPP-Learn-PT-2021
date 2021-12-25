#pragma once
#if defined _SCREEN_SET
#define _SCREEN_SET

#endif // 

#include "GraphicsLib.h"
#include "game.h"
#include "const.h"

struct PrintSequenceItem
{
	int xPos;
	int yPos;
	int symbol;
};

void init_screen(int xRes, int yRes);

void clear_field();
// draws border and fills field with fill in char ("space" or etc.)

int put_sequence(const PrintSequenceItem* charSeq, size_t seqSize=1);
// puts char sequence to deefined coords of screen array

void draw_screen();

int get_xResolution();
int get_yResolution();
void get_limits(Coord& lims);