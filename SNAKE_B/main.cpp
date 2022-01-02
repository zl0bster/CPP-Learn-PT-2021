#include <iostream>
#include <stdlib.h>

#include "screen.h"
#include "snake.h"
#include "food.h"
#include "game.h"
#include "inputs.h"
#include "main.h"

Directions newDir; //command bufer
bool exit_flag;

static MainData* prepare_game(int argQty, char* args[])
{
	//define default parameters
	size_t snakeLen = 3;
	size_t xRes = 20;
	size_t yRes = 8;
	size_t gameMode = 0;
	MainData* md = new MainData;
	//check and set command line params
	// Input args:
	// 1. horizontal field size
	// 2. vertical field size
	// 3. starting snake length
	// 4. game mode: 2 for manual control, others - for DEMO mode
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
	if (argQty >= 5)
		if (int n = atoi(args[4]))
			if (n == 2) 
				gameMode = MANUAL_MODE;
	md->gameMode = gameMode;
	md->fp = init_screen(xRes, yRes);
	md->fd = init_food(md->fp);
	md->sd = init_snake(md->fp, md->fd, snakeLen);
	set_food_pos((md->fd), (md->sd));
	exit_flag = false;
	return md;
}

static void play_demo_rnd(MainData*md)
{
	std::cout << "\n\n\t\tPress any key to exit demo\n";
	for (short x = 200; x > 0; x--)
	{
		Sleep(md->moveDelay/2);
		if (read_input()!=NOPS) return;
		Directions moveDir = static_cast <Directions> (rand() % NOP);
		unsigned short moveLen = static_cast <unsigned short> (rand() % get_yResolution(md->fp));
		for (int i = moveLen; i > 0; i--)
			if (!do_life_step(md->sd, moveDir))
			{
				game_over();
				break;
			}
	}
}

void set_new_dir(Directions dir)
{
	newDir = dir;
}
void set_exit_flag()
{
	exit_flag = true;
}

static void play_game(MainData* md)
{
	while (true)
	{
		react_inputs();
		Sleep(md->moveDelay);
		change_snake_dir(md->sd, newDir);
		if (!do_life_step1(md->sd))
		{
			game_over();
			break;
		};
		if (exit_flag) return;
	}
}


void exit_game(MainData* md)
{
	std::cout << "\n\t\tPRESS ANY KEY\n";
	_getch();
	FinishDemo();
	screen_destructor(md->fp);
	snake_destructor(md->sd);
	food_destructor(md->fd);
	std::exit(EXIT_SUCCESS);
}

int main(int argQty, char* args[])
{
	MainData* md = prepare_game(argQty, args);
	(md->gameMode == MANUAL_MODE) ? play_game(md) : play_demo_rnd(md);
	exit_game(md);
}