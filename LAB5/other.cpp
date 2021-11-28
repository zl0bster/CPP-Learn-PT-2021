#include "other.h"

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

void print_int_array(const int* arrInt, size_t arrSize)
{

	for (int i = 0; (i < arrSize); i++)
	{
		std::cout << arrInt[i] << ' ';
	}
	std::cout << '\n' << "======================" << '\n';
}

void fill_rndint_arr(int* arrInt, const size_t arrSize, const int limit)
{
	for (int i = (arrSize - 1); i >= 0; i--)
	{
		arrInt[i] = rand() % limit;
	}
}

size_t find_min_arr_ind(int* arrInt, const size_t arrSize)
{
	size_t minPos = 0;
	for (int i = (arrSize - 1); i >= 0; i--)
	{
		if (arrInt[i] < arrInt[minPos])
			minPos = i;
	}
	return minPos;
}

int* find_min_arr_ptr(int* arrInt, const size_t arrSize)
{
	size_t minPos = 0;
	for (int i = (arrSize - 1); i >= 0; i--)
	{
		if (arrInt[i] < arrInt[minPos])
			minPos = i;
	}
	return &arrInt[minPos];
}

int MyStrCmp(const char* line1, const char* line2)
{
	size_t i = 0;
	int compareResult = 0; //equal by default
	while ((line1[i]) && (line2[i]))
	{
#if defined _DEBUG
		std::cout << line1[i] << '\t' << line2[i] << '\n';
#endif
		if ((line1[i]) != (line2[i]))
			break;
		++i;
	}
	if ((line1[i]) > (line2[i]))
		compareResult = 1;
	else if ((line1[i]) < (line2[i]))
		compareResult = -1;

	return compareResult;
}

char* get_month_name(int month)
{
	static const char monthSeq[] = { "nop\0JAN\0FEB\0MAR\0APR\0MAY\0JUN\0JUL\0AUG\0SEP\0OCT\0NOV\0DEC\0" };
	if ((month < 1) || (month > 12))
		return const_cast<char*>(monthSeq);
	return const_cast<char*>(&monthSeq[month * 4]);
}

void count_freq_sym(const int* sorsArr, int sorsSize, int* freqArr, int valLim)
{
	size_t tmp;
	for (int i = sorsSize; i >= 0; i--)
	{
		tmp = static_cast<size_t> (*sorsArr);
		if (tmp <= valLim)
			(freqArr[tmp])++;
		sorsArr++;
	};
}
