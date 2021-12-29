#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

#include "GraphicsLib.h"

#include "screen.h"
#include "const.h"

FieldData* init_screen(int xRes, int yRes)
{
	FieldData* fldPtr = new FieldData;
	fldPtr->xRes = xRes;
	fldPtr->yRes = yRes;
	fldPtr->fieldBase = new int[xRes * yRes];
	StartDemo();
	SetDimensions(yRes, xRes);
	return fldPtr;
}

void clear_field(FieldData*fp)
{
	size_t fieldLen = fp->xRes* fp->yRes;
	for (size_t i = 0; i < fieldLen; i++) fp->fieldBase[i] = emptyField;
}

int put_sequence(FieldData* fp, const PrintSequenceItem* charSeq, size_t seqSize)
{
	int x, y;
	bool posOK;
	for (int i = 0; i < seqSize; i++)
	{
		x = charSeq->xPos;
		y = charSeq->yPos;		
		posOK = ((x >= 0) && (y >= 0) && (x < fp->xRes) && (y < fp->yRes));
		if (posOK)
			fp->fieldBase[y* fp->xRes + x] = charSeq->symbol;
		else
			return -1;
		charSeq++;
	}
	return 0;
}

int get_xResolution(FieldData* fp)
{
	return fp->xRes;
}

int get_yResolution(FieldData* fp)
{
	return fp->yRes;
}

void get_limits(FieldData* fp, Coord& lims)
{
	lims.x = fp->xRes;
	lims.y = fp->yRes;
}

void draw_screen(FieldData* fp)
{
	DrawBalls(fp->fieldBase, fp->yRes, fp->xRes);
}

void screen_destructor(FieldData* fp)
{
	delete[] fp->fieldBase;
	fp->fieldBase = nullptr;
}