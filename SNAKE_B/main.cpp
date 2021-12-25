#include <iostream>
#include <stdlib.h>

#include "screen.h"
#include "snake.h"
#include "food.h"


int main(int argQty, char* args[])
{
#ifdef _DEBUG
	std::cout << argQty << "-----" << '\n';
	for (int i = 0; i < argQty; i++)
		std::cout << args[i] << '\t' << atoi(args[i]) << '\n';
#endif // _DEBUG

	//define default parameters
	size_t snakeLen = 3;
	size_t xRes = 20;
	size_t yRes = 8;

	//check and set command line params
	if (argQty >= 2)
		if (int x = atoi(args[1]))
			if ((x > 0) && (x < 81))
				xRes = x;
	if (argQty >= 3)
		if (int y = atoi(args[2]))
			if ((y > 0) && (y < 61))
				yRes = y;
	if (argQty >= 4)
		if (int n = atoi(args[3]))
			if ((n > 1) && (n < (xRes/2)))
				snakeLen = n;

	init_screen(xRes, yRes);
	std::cout << get_xResolution() << get_yResolution() << '\n';
	init_snake(snakeLen);
	init_food();
	for (short x = 200; x > 0; x--)
	{
		Directions moveDir = static_cast <Directions> (rand() % NOP);
		unsigned short moveLen = static_cast <unsigned short> (rand() % get_yResolution());
		for (int i = moveLen; i > 0; i--)
			do_life_step(moveDir);//food enabled
	}
	FinishDemo();
}