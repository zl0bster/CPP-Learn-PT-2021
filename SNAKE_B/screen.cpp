#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

#include "GraphicsLib.h"

#include "screen.h"
#include "const.h"

namespace
{
	size_t xResolution;
	size_t yResolution;
	int* fieldBase;
}

void init_screen(int xRes, int yRes)
{
	xResolution = xRes;
	yResolution = yRes;
	fieldBase = new int[xRes * yRes];
	StartDemo();
	SetDimensions(yRes, xRes);
}

void clear_field()
{
	size_t fieldLen = xResolution * yResolution;
	for (size_t i = 0; i < fieldLen; i++) fieldBase[i] = emptyField;
}

int put_sequence(const PrintSequenceItem* charSeq, size_t seqSize)
{
	int x, y;
	bool posOK;
	for (int i = 0; i < seqSize; i++)
	{
		x = charSeq->xPos;
		y = charSeq->yPos;		
		posOK = ((x >= 0) && (y >= 0) && (x < xResolution) && (y < yResolution));
		if (posOK)
			fieldBase[y*xResolution + x] = charSeq->symbol;
		else
			return -1;
		charSeq++;
	}
	return 0;
}

int get_xResolution()
{
	return xResolution;
}

int get_yResolution()
{
	return yResolution;
}

void get_limits(Coord& lims)
{
	lims.x = xResolution;
	lims.y = yResolution;
}

void draw_screen()
{
	DrawBalls(fieldBase, yResolution, xResolution);
}