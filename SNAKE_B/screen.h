#pragma once

#include "GraphicsLib.h"
#include "game.h"
#include "const.h"

struct FieldData
{
	size_t xRes;
	size_t yRes;
	int* fieldBase;
};

struct PrintSequenceItem
{
	int xPos;
	int yPos;
	int symbol;
};

FieldData* init_screen(int xRes, int yRes);
void clear_field(FieldData* fp);
int put_sequence(FieldData* fp, const PrintSequenceItem* charSeq, size_t seqSize=1);
void draw_screen(FieldData* fp);

int get_xResolution(FieldData* fp);
int get_yResolution(FieldData* fp);
void get_limits(FieldData* fp, Coord& lims);

void screen_destructor(FieldData* fp);