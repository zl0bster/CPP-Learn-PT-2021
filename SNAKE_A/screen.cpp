#include <conio.h>
#include <ctype.h>

#include "screen.h"

static const char xResolution = 40;
static const char yResolution = 6;

int init_screen()
{
	static char screenArray[xResolution+2][yResolution+2];
	static const PrintSequenceItem border[] =
	{
		{0,0,'*'},
		{0,yResolution+1, '+'},
		{xResolution+1, 0, '+'},
		{xResolution+1, yResolution, '*'}
	};
	return 0;
}

void crear_screen()
{
	//#TODO draw border and fill field with fill in char ("space" or etc.)
}

int put_sequence(const PrintSequenceItem* charSeq, size_t seqSize)
{
	//#TODO check position in limits and correct position x+1, y+1 reminding border
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

void put_border()
{
	//#TODO put border char sequence to screen array
}

void put_char_sequence(const PrintSequenceItem* charSeq, size_t seqSize)
{
	//#TODO no check position and no correction 
}

void draw_screen()
{
	//#TODO clear screen and print screenarray
}