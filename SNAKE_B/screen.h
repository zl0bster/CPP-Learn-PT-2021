#pragma once

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
int put_sequence(const PrintSequenceItem* charSeq, size_t seqSize=1);
void draw_screen();

int get_xResolution();
int get_yResolution();
void get_limits(Coord& lims);

void screen_destructor();