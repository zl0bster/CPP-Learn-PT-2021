#include "snake.h"
#include "const.h"
#include "screen.h"
#include "food.h"
#include "inputs.h"

SnakeData* init_snake(FieldData* fp, FoodData* fd, int snakeLen)
{
	SnakeData* sd = new SnakeData;
	int refX = get_xResolution(fp) / 2;
	int refY = get_yResolution(fp) / 2;
	sd->snakeSizeMax = get_xResolution(fp) * get_yResolution(fp);
	sd->snakePos = new Coord[sd->snakeSizeMax];
	sd->snakeFigure = new PrintSequenceItem[sd->snakeSizeMax];
	sd->snakeSize = snakeLen;
	sd->fd = fd;
	for (int i = 0; i < sd->snakeSize; i++)
	{
		sd->snakePos[i].x = refX - i;
		sd->snakePos[i].y = refY;
	};
	return sd;
}

void put_snake_to_field(SnakeData* sd, Coord* sPos, size_t size)
{
	int symbol;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			symbol = headField;
		else
			symbol = bodyField;
		sd->snakeFigure[i].xPos = sPos->x;
		sd->snakeFigure[i].yPos = sPos->y;
		sd->snakeFigure[i].symbol = symbol;
		sPos++;
	};
	put_sequence(sd->fp, sd->snakeFigure, size);
}

void move_snake(SnakeData* sd, Coord* sPos, size_t size, Directions direct)
{
	using std::cout;
	Coord temp = *sPos;
	size_t limLT = 0;
	size_t limRT = get_xResolution(sd->fp) - 1;
	size_t limUP = 0;
	size_t limDN = get_yResolution(sd->fp) - 1;
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

Directions change_snake_dir(SnakeData* sd, Directions newDir)
{
	// reverse movement is prohibited
	// direct movement makes no need to change
	// only perpendicular direction makes sence
	switch (newDir)
	{
	case MOVE_UP:
		if ((sd->snakeDir == MOVE_LT) || (sd->snakeDir == MOVE_RT))
			sd->snakeDir = newDir;
		break;
	case MOVE_DN:
		if ((sd->snakeDir == MOVE_LT) || (sd->snakeDir == MOVE_RT))
			sd->snakeDir = newDir;
		break;
	case MOVE_RT:
		if ((sd->snakeDir == MOVE_UP) || (sd->snakeDir == MOVE_DN))
			sd->snakeDir = newDir;
		break;
	case MOVE_LT:
		if ((sd->snakeDir == MOVE_UP) || (sd->snakeDir == MOVE_DN))
			sd->snakeDir = newDir;
		break;
	}
	return sd->snakeDir;
}

bool is_snake_here(SnakeData* sd, Coord& pos)
{
	for (int i = 1; i < sd->snakeSize; i++)
	{
		if (are_coords_equal(pos, sd->snakePos[i]))
			return true;
	};
	return false;
}

void do_life_step(SnakeData* sd, Directions newDir = NOP)	//demo game mode
{
	clear_field(sd->fp);
	change_snake_dir(sd, newDir);
	move_snake(sd, sd->snakePos, sd->snakeSize, sd->snakeDir);
	Coord head = sd->snakePos[0];
	if (is_food_here(sd->fd, head))
	{
		sd->snakeSize++;
		set_food_pos(sd->fd, sd);
	};
	if (is_snake_here(sd, head))
		game_over();
	put_snake_to_field(sd, sd->snakePos, sd->snakeSize);
	print_food(sd->fd);
	draw_screen(sd->fp);
}

void do_life_step1(SnakeData* sd)	//keyboard direction control
{
	clear_field(sd->fp);
	move_snake(sd, sd->snakePos, sd->snakeSize, sd->snakeDir);
	Coord head = sd->snakePos[0];
	if (is_food_here(sd->fd, head))
	{
		sd->snakeSize++;
		set_food_pos(sd->fd, sd);
	}
	if (is_snake_here(sd, head))
		game_over();
	print_food(sd->fd);
	put_snake_to_field(sd, sd->snakePos, sd->snakeSize);
	draw_screen(sd->fp);
}

void snake_destructor(SnakeData* sd)
{
	delete[] sd->snakeFigure;
	sd->snakeFigure = nullptr;
}