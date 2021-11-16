#include <iostream>
#include <conio.h>
//#include <stdio.h>
//#include <string.h>
//#include <cstdlib>

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

using actFx = void (*)();

struct ActMapItem
{
	char key;
	actFx action;
};

static ActMapItem actMap[]
{
	{MOVE_UP, do_up},
	{MOVE_DN, do_dn},
	{MOVE_LT, do_lt},
	{MOVE_RT, do_rt},
	{EXIT, do_xt},
	{UNDEF, do_ud}
};

int _main()
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