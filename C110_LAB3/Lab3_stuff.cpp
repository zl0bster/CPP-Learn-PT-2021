#include <stdlib.h>
#include "Lab3_stuff.h"
#include <iostream>


int count_sum(int n)
{
	int sum = 0;
	int sign = (n < 0) ? -1 : 1;
	n = abs(n);
	while (n > 0)
	{
		sum += n;
		n--;
	}
	sum *= sign;
	return sum;
}

unsigned int count_sum_recurs(unsigned int n)
{
	if (n == 0) return 0;
	return n + count_sum_recurs(n - 1);
}

size_t count_digits_qty(int n)
{
	if ((n / 10) == 0) return 1;
	return 1 + count_digits_qty(n / 10);
}

void print_backwards(const char*  st)
{
	if (*st != '\0') print_backwards(st+1);
	std::cout <<st[0];
}

void print_forwards(const char* st)
{
	if (*st == '\0') return;
	std::cout << st[0];
	print_forwards(st+1);
}

void print_parabolic_data(float a, float b, float c,
	float x0, float x1, float inc)
{
	using std::cout;
	cout << "=================\n";
	printf("a = %f, b = %f, c = %f\n", a, b, c);
	printf("x0 = %f, x1 = %f, inc = %f\n", x0, x1, inc);
	float y = 0;
	while (x0 < x1)
	{
		y = a * x0 * x0 + b * x0 + c;
		printf("%f\t%f\n", x0, y);
		x0 += inc;
	}
	cout << "=================\n";
}