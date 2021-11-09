//#include "other.h"

///////////////////////////////////////////////////

int ref = 5;

int square(int& x)
{
	return x*x;
}

int IncByValue(int x)
{
	return x + 1;
}

int IncByPointer(const int* x)
{
	return *x + 1;
}

int IncByReference(const int& x)
{
	return x + 1;
}

void Swap_p(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Swap_r(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}