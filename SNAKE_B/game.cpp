#include <iostream>
#include <conio.h>
#include "game.h"
#include "screen.h"
#include "inputs.h"
#include "snake.h"
#include "main.h"


void exit_game()
{
	std::cout << "\nPRESS ANY KEY\n";
	_getch();
	FinishDemo();
	std::exit(EXIT_SUCCESS);
}

void game_over()
{
	std::cout << "GAME OVER\n";
	exit_game();
}

static void do_up()
{
	set_new_dir(MOVE_UP);
	std::cout << "KEY UP";
}

static void do_dn()
{
	set_new_dir(MOVE_DN);
	std::cout << "KEY DN";
}

static void do_rt()
{
	set_new_dir(MOVE_RT);
	std::cout << "KEY RT";
}

static void do_lt()
{
	set_new_dir(MOVE_LT);
	std::cout << "KEY LT";
}

static void do_xt()
{
	std::cout << "KEY EXIT";
	exit_game();
}


static void do_ud()
{
	std::cout << "KEY UNDEFINED";
}

static void do_op1()
{
	//test_screen();
	std::cout << "KEY OP1\t";
	//move_snake_test();
}

static void do_op2()
{
	//test_screen();
	std::cout << "KEY OP2\t";
	//move_snake_test1();
}


static void do_op3()
{
	//test_screen();
	std::cout << "KEY OP2\t";
	//move_snake_test2();
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
	{EXIT, do_xt},
	{UNDEF, do_ud},
	{OP1, do_op1},
	{OP2, do_op2},
	{OP3, do_op3}
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
#if defined _DEBUG
			system("CLS");
			std::cout << actMapSize << '\t' << i << '\n';
#endif
			pAction = actMap[i].action;
			pAction();
			break;
		}
	}
	return 0;
}