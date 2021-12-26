#include <iostream>
#include <stdlib.h>

#include "screen.h"
#include "snake.h"
#include "food.h"
#include "game.h"
#include "inputs.h"
#include "main.h"

namespace
{
	Directions newDir = MOVE_RT;
}

static size_t prepare_game(int argQty, char* args[])
{
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
			if ((n > 1) && (n < (xRes / 2)))
				snakeLen = n;

	init_screen(xRes, yRes);
	return snakeLen;
}

static void play_demo_rnd()
{
	std::cout << "\n\n\t\tPress any key to exit demo\n";
	for (short x = 200; x > 0; x--)
	{
		if (read_input()!=NOPS) return;
		Directions moveDir = static_cast <Directions> (rand() % NOP);
		unsigned short moveLen = static_cast <unsigned short> (rand() % get_yResolution());
		for (int i = moveLen; i > 0; i--)
			do_life_step(moveDir);//food enabled
	}
}

void set_new_dir(Directions dir)
{
	newDir = dir;
}

static void play_game()
{
	//Directions moveDir = MOVE_RT;
	
	while (true)
	{
		react_inputs();
		change_snake_dir(newDir);
		do_life_step1();
	}
}

int main(int argQty, char* args[])
{
#ifdef _DEBUG
	std::cout << argQty << "-----" << '\n';
	for (int i = 0; i < argQty; i++)
		std::cout << args[i] << '\t' << atoi(args[i]) << '\n';
#endif // _DEBUG

	size_t snakeLen = prepare_game(argQty, args);

#ifdef _DEBUG
	std::cout << get_xResolution() << get_yResolution() << '\n';
#endif // _DEBUG

	init_snake(snakeLen);
	init_food();
	//play_demo_rnd();
	play_game();
	exit_game();
}