#include "screen.h"
#include "const.h"
#include "snake.h"
#include "food.h"
#include "inputs.h"
#include "test_screen.h"

int test_screen()
{
	clear_screen();
	draw_screen();
	return 0;
}

void move_snake_test()
{
	using std::cout;
	Sleep(moveDelay);
	init_snake();
	for (int i = 62; i > 0; i--)
	{
		if (if_exit()) return;
		do_life_step1(MOVE_UP);//no food
	}
	for (int i = 50; i > 0; i--)
	{
		if (if_exit()) return;
		do_life_step1(MOVE_LT);
	}
	for (int i = 30; i > 0; i--)
	{
		if (if_exit()) return;
		do_life_step1(MOVE_DN);
	}
	for (int i = 60; i > 0; i--)
	{
		if (if_exit()) return;
		do_life_step1(MOVE_RT);
	}
}

void move_snake_test1()
{
	using std::cout;
	Sleep(moveDelay);
	init_snake();
	for(short x = 30; x>0;x--)
	{
		Directions moveDir = static_cast <Directions> (rand() % NOP);
		unsigned short moveLen = static_cast <unsigned short> (rand() % get_yResolution());
		for (int i = moveLen; i > 0; i--)
		{
			if (if_exit()) return;
			do_life_step1(moveDir);//no food
		}
	}
}

void move_snake_test2()
{
	using std::cout;
	Sleep(moveDelay);
	init_snake();
	init_food();
	for (short x = 200; x > 0; x--)
	{
		Directions moveDir = static_cast <Directions> (rand() % NOP);
		unsigned short moveLen = static_cast <unsigned short> (rand() % get_yResolution());
		for (int i = moveLen; i > 0; i--)
		{
			if (if_exit()) return;
			do_life_step(moveDir);//food enabled
		}
	}
}