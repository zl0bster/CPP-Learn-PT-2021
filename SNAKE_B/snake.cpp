#include "snake.h"
#include "const.h"
#include "screen.h"
#include "food.h"
#include "inputs.h"

const size_t MAX_SIZE = 10;
const size_t _DELAY = 100;

namespace
{
	Coord snakePos[MAX_SIZE];
	size_t snakeSize = 5;
	Directions snakeDir = MOVE_RT;
}


void init_snake(int snakeLen)
{
	int refX = get_xResolution() / 2;
	int refY = get_yResolution() / 2;
	snakeSize = snakeLen;
	for (int i = 0; i < snakeSize; i++)
	{
		snakePos[i].x = refX - i;
		snakePos[i].y = refY;
	};
}

void put_snake_to_field(Coord* sPos, size_t size)
{
	PrintSequenceItem snakeFigure[MAX_SIZE];
	int symbol;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			symbol = headField;
		else
			symbol = bodyField;
		snakeFigure[i].xPos = sPos->x;
		snakeFigure[i].yPos = sPos->y;
		snakeFigure[i].symbol = symbol;
		sPos++;
	};
	put_sequence(snakeFigure, size);
}

void move_snake(Coord* sPos, size_t size, Directions direct)
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
		if (sPos->x <= limLT) sPos->x = limRT;
		else sPos->x--;
		break;
	case MOVE_RT:
		if (sPos->x >= limRT) sPos->x = limLT;
		else sPos->x++;
		break;
	case MOVE_UP:
		if (sPos->y <= limUP) sPos->y = limDN;
		else sPos->y--;
		break;
	case MOVE_DN:
		if (sPos->y >= limDN) sPos->y = limUP;
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

void change_snake_dir(Directions newDir)
{
	// reverse movement is prohibited
	// direct movement makes no need to change
	// only perpendicular direction makes sence
	switch (newDir)
	{
	case MOVE_UP:
		if ((snakeDir == MOVE_LT) || (snakeDir == MOVE_RT))
			snakeDir = newDir;
		break;
	case MOVE_DN:
		if ((snakeDir == MOVE_LT) || (snakeDir == MOVE_RT))
			snakeDir = newDir;
		break;
	case MOVE_RT:
		if ((snakeDir == MOVE_UP) || (snakeDir == MOVE_DN))
			snakeDir = newDir;
		break;
	case MOVE_LT:
		if ((snakeDir == MOVE_UP) || (snakeDir == MOVE_DN))
			snakeDir = newDir;
		break;
	}
}
bool is_snake_here(Coord& pos)
{
	for (int i = 1; i < snakeSize; i++)
	{
		if (are_coords_equal(pos, snakePos[i]))
			return true;
	};
	return false;
}

void do_life_step(Directions newDir = NOP)	//game over added food added
{
	using std::cout;

	clear_field();
	char action = read_input();
	if (action == EXIT) game_over();
	change_snake_dir(newDir);
	move_snake(&snakePos[0], snakeSize, snakeDir);
	Coord head = snakePos[0];
	if (is_food_here(head))
	{
		snakeSize++;
		init_food();
	};
	if (is_snake_here(head))
		game_over();
	put_snake_to_field(&snakePos[0], snakeSize);
	print_food();
	draw_screen();
	//cout << '\n' << snakePos[0].x << '\t' << snakePos[0].y << '\t';
	Sleep(moveDelay);
}

void do_life_step1(Directions newDir = NOP)	//game over added but no food 
{
	using std::cout;

	clear_field();
	change_snake_dir(newDir);
	move_snake(&snakePos[0], snakeSize, snakeDir);
	Coord head = snakePos[0];
	if (is_snake_here(head))
		game_over();
	put_snake_to_field(&snakePos[0], snakeSize);
	draw_screen();
	//cout << '\n' << snakePos[0].x << '\t' << snakePos[0].y << '\t';
	Sleep(moveDelay);
}
