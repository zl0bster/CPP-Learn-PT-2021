#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include "screen.h"

static const char xResolution = 40;
static const char yResolution = 6;
static const char emptyFill = '.';
static const char borderFill = '#';
static char screenArray[yResolution + 2][xResolution + 3];

int init_screen()
{
	
	static const PrintSequenceItem border[] =
	{
		{0,0,'*'},
		{0,yResolution+1, '+'},
		{xResolution+1, 0, '+'},
		{xResolution+1, yResolution, '*'}
	};
	return 0;
}
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
#if defined _DEBUG
	std::cout << line << '\n';
#endif
	copy_line(screenArray[0], sizeof(line), line);
	copy_line(screenArray[yResolution], sizeof(line), line);
	//fill middle lines
	for (int i = 1; i < (sizeof(line) - 2); i++)
		line[i] = emptyFill;
	line[0] = borderFill;
	line[sizeof(line)-1] = borderFill;
	line[xResolution + 2] = '\0';
#if defined _DEBUG
	std::cout << line << '\n';
#endif
	for (int i = 1; i < yResolution ; i++)
		copy_line(screenArray[i], sizeof(line), line);
#if defined _DEBUG
	std::cout <<"=====================" << '\n';
#endif
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
	system("CLS");
	for (int i = 0; i < (yResolution + 1); i++)
		std::cout << screenArray[i] << '\n';
}