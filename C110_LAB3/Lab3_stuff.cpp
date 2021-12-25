#include <stdlib.h>
#include "Lab3_stuff.h"


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

