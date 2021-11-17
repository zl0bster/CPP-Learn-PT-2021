#include "screen.h"
#include "const.h"
#include "windows.h"

const size_t MAX_SIZE = 10;
const size_t _DELAY = 100;


int test_screen()
{
	clear_screen();
	draw_screen();
	return 0;
}

struct Coord {
	int x;
	int y;
};

void put_snake_to_field(Coord* sPos, size_t size)
{
	PrintSequenceItem snakeFigure[MAX_SIZE];
	char symbol;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			symbol = headSymbol;
		else
			symbol = taleSymbol;
		snakeFigure[i].xPos = sPos->x;
		snakeFigure[i].yPos = sPos->y;
		snakeFigure[i].symbol = symbol;
		sPos++;
#if defined _DEBUG
		std::cout << snakeFigure[i].xPos << '\t' << snakeFigure[i].yPos << '\t' << snakeFigure[i].symbol << '\n';
		Sleep(_DELAY);
#endif
	};
	put_sequence(snakeFigure, size);
}

void move_snake(Coord* sPos, size_t size, Actions direct)
{
	Coord temp = *sPos;
	
	switch (direct)
	{
	case MOVE_LT:
		if (sPos->x == 0) sPos->x = get_xResolution() - 1;
		else sPos->x--;
		break;
	case MOVE_RT:
		if (sPos->x == get_xResolution()) sPos->x = 0;
		else sPos->x++;
		break;
	case MOVE_UP:
		if (sPos->y == 0) sPos->y = get_yResolution() - 1;
		else sPos->y--;
		break;
	case MOVE_DN:
		if (sPos->y == get_yResolution()) sPos->y = 0;
		else sPos->y++;
		break;
	}
	int tmp;
	for (int i = size; i > 0; i--)
	{
		//flip temp with coord
		sPos++;
		tmp = sPos->x;
		sPos->x = temp.x;
		temp.x = tmp;
		tmp = sPos->y;
		sPos->y = temp.y;
		temp.y = tmp;
	}

}

void move_snake_test()
{
	size_t snakeSize = 5;
	int snakeDir = MOVE_RT;
	int refX = get_xResolution() / 2;
	int refY = get_yResolution() / 2;
	Coord snakePos[MAX_SIZE];
	

	for (int i = 0; i < snakeSize; i++)
	{
		snakePos[i].x = refX - i;
		snakePos[i].y = refY;
#if defined _DEBUG
		std::cout << snakePos[i].x << '\t' << snakePos[i].y << '\n';
		Sleep(_DELAY);
#endif
	};
	clear_screen();
	put_snake_to_field(&snakePos[0], snakeSize);
	while (true)
	{
		clear_screen();
		move_snake(&snakePos[0], snakeSize, MOVE_RT);
		put_snake_to_field(&snakePos[0], snakeSize);
		draw_screen();
		Sleep(moveDelay);
	}
	//#TODO correct thru border movement
	//#TODO check all directions

}