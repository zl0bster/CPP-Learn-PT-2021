#include <iostream>
#include <conio.h>
//#include <stdio.h>
//#include <string.h>
//#include <cstdlib>


#include "test_screen.h"
#include "inputs.h"


void do_up()
{
std::cout << "KEY UP";
}

void do_dn()
{
std::cout << "KEY DN";
}

void do_rt()
{
std::cout << "KEY RT";
}

void do_lt()
{
std::cout << "KEY LT";
}

void do_xt()
{
std::cout << "KEY EXIT";
std::exit(EXIT_SUCCESS);
}


void do_ud()
{
	std::cout << "KEY UNDEFINED";
}

void do_op1()
{
	//test_screen();
	std::cout << "KEY OP1\t";
	move_snake_test();
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
	{OP1, do_op1}
};

int test_inputs()
{
	int actMapSize = sizeof(actMap) / sizeof(actMap[0]);
	char ch;
	void (* pAction)();
	while (true)
	{
		ch = read_input();
		for (int i = 0; i < actMapSize; i++)
		{
			if (ch == actMap[i].key)
			{
				system("CLS");
#if defined _DEBUG
				std::cout << actMapSize << '\t' << i << '\n';
#endif
				pAction = actMap[i].action;
				pAction();
				break;
			}
		}
	}
	return 0;
}