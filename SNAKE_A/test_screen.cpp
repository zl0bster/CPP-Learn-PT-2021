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

void move_snake_test()
{
	size_t snakeSize = 3;
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
	draw_screen();
	


}