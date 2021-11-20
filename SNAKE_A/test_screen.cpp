#include "screen.h"
#include "const.h"
#include "snake.h"

int test_screen()
{
	clear_screen();
	draw_screen();
	return 0;
}

void move_snake_test()
{
	using std::cout;
	init_snake();
	for (int i = 62; i > 0; i--)
		do_life_step(MOVE_UP);
	for (int i = 50; i > 0; i--)
		do_life_step(MOVE_LT);
	for (int i = 30; i > 0; i--)
		do_life_step(MOVE_DN);
	for (int i = 60; i > 0; i--)
		do_life_step(MOVE_RT);
}