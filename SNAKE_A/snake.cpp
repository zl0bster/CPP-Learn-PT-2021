#include "snake.h"

const size_t MAX_SIZE = 10;
const size_t _DELAY = 100;

Coord snakePos[MAX_SIZE];
size_t snakeSize = 5;

void init_snake()
{
	int refX = get_xResolution() / 2;
	int refY = get_yResolution() / 2;

	for (int i = 0; i < snakeSize; i++)
	{
		snakePos[i].x = refX - i;
		snakePos[i].y = refY;
	};
}

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
	};
	put_sequence(snakeFigure, size);
}

void move_snake(Coord* sPos, size_t size, Actions direct)
{
	using std::cout;
	Coord temp = *sPos;
	size_t limLT = 0;
	size_t limRT = get_xResolution() - 1;
	size_t limUP = 0;
	size_t limDN = get_yResolution() - 1;
	switch (direct)
	{
	case MOVE_LT:
		if (sPos->x <= limLT) sPos->x = limRT - 1;
		else sPos->x--;
		break;
	case MOVE_RT:
		if (sPos->x >= limRT - 1) sPos->x = limLT;
		else sPos->x++;
		break;
	case MOVE_UP:
		if (sPos->y <= limUP) sPos->y = limDN - 1;
		else sPos->y--;
		break;
	case MOVE_DN:
		if (sPos->y >= limDN - 1) sPos->y = limUP;
		else sPos->y++;
		break;
	}
	int tmp;
	for (int i = size; i > 0; i--)
	{
		sPos++;

		//flip temp with coord
		tmp = sPos->x;
		sPos->x = temp.x;
		temp.x = tmp;
		tmp = sPos->y;
		sPos->y = temp.y;
		temp.y = tmp;
	}

}

void do_life_step(Actions snakeDir)
{
	using std::cout;

	clear_screen();
	move_snake(&snakePos[0], snakeSize, snakeDir);
	put_snake_to_field(&snakePos[0], snakeSize);
	draw_screen();
	cout << '\n' << snakePos[0].x << '\t' << snakePos[0].y << '\t';
	Sleep(moveDelay);
}