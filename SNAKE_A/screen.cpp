#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

#include "winconsole.h"

#include "screen.h"
#include "const.h"


static char screenArray[yResolution + 2][xResolution + 3];

void copy_line(char* dest, size_t length, const char* source)
{
	for (int i = 0; i < length; i++)
		dest[i] = source[i];
}

void clear_screen()
{
	//#TODO draw border and fill field with fill in char ("space" or etc.)
	char line[xResolution + 3];
	//fill top and bottom lines
	for (int i = 0; i < (sizeof(line) - 1); i++)
		line[i] = borderFill;
	line[xResolution + 2] = '\0';
	copy_line(screenArray[0], sizeof(line), line);
	copy_line(screenArray[yResolution+1], sizeof(line), line);

	//fill middle lines
	for (int i = 1; i < (sizeof(line) - 2); i++)
		line[i] = emptyFill;
	line[0] = borderFill;
	line[sizeof(line)-1] = borderFill;
	line[xResolution + 2] = '\0';
	for (int i = 1; i <= yResolution; i++)
		copy_line(screenArray[i], sizeof(line), line);
}

int put_sequence(const PrintSequenceItem* charSeq, size_t seqSize)
{
	int x, y;
	bool posOK;
	for (int i = 0; i < seqSize; i++)
	{
		x = charSeq->xPos + 1;
		y = charSeq->yPos + 1;		
		posOK = ((x > 0) && (y > 0) && (x <= xResolution) && (y <= yResolution));
		if (posOK)
			screenArray[y][x] = charSeq->symbol;
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
	setCursorPosition(0, 0);
	for (int i = 0; i < (yResolution + 2); i++)
		std::cout << screenArray[i] << '\n';
}


void print_menu()
{
	system("CLS");
	setCursorPosition(3, 3);
	std::cout << "Snake game demo";
	setCursorPosition(6, 5);
	std::cout << "1 - snake movement";
	setCursorPosition(6, 7);
	std::cout << "2 - snake rnd movement";
	setCursorPosition(6, 9);
	std::cout << "3 - snake rnd movement with food";
	setCursorPosition(6, 13);
	std::cout << "0 or ESC - exit";
}
