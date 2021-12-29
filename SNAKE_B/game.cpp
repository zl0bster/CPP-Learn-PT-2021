#include <iostream>
#include <conio.h>
#include "game.h"
#include "screen.h"
#include "inputs.h"
#include "snake.h"
#include "main.h"

void game_over()
{
	std::cout << "\n\n\t\tGAME OVER\n";
	exit_game();
}

static void do_up()
{
	set_new_dir(MOVE_UP);
}

static void do_dn()
{
	set_new_dir(MOVE_DN);
}

static void do_rt()
{
	set_new_dir(MOVE_RT);
}

static void do_lt()
{
	set_new_dir(MOVE_LT);
}

static void do_xt()
{
	exit_game();
}

using actFx = void (*)();

struct ActMapItem
{
	char key;
	actFx action;
};

static ActMapItem actMap[]
{
	{KEY_UP, do_up},
	{KEY_DN, do_dn},
	{KEY_LT, do_lt},
	{KEY_RT, do_rt},
	{EXIT, do_xt}
};

int react_inputs()
{
	int actMapSize = sizeof(actMap) / sizeof(actMap[0]);
	int act;
	void (*pAction)();
	act = read_input();
	for (int i = 0; i < actMapSize; i++)
	{
		if (act == actMap[i].key)
		{
			pAction = actMap[i].action;
			pAction();
			break;
		}
	}
	return 0;
}