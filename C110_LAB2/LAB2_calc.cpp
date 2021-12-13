#include "LAB2_calc.h"
int do_sub(int x, int y)
{
	return x - y;
}

int do_add(int x, int y)
{
	return x + y;
}

int do_mul(int x, int y)
{
	return x * y;
}

int do_div(int x, int y)
{
	return (y != 0) ? (x / y) : 0;
}

int do_res(int x, int y)
{
	return x % y;
}

using actFx = int (*)(int x, int y);

struct ActMapItem
{
	char key;
	actFx action;
};

ActMapItem actMap[]
{
	{'-', do_sub},
	{'+', do_add},
	{'*', do_mul},
	{'/', do_div},
	{'%', do_res},
};

int calculate(char op, int x, int y)
{
	int actMapSize = sizeof(actMap) / sizeof(actMap[0]);
	int result = 0;
	int (*pAction)(int x, int y);
	for (int i = 0; i < actMapSize; i++)
	{
		if (op == actMap[i].key)
		{
			pAction = actMap[i].action;
			result = pAction(x, y);
			break;
		}
	}
	return result;
}