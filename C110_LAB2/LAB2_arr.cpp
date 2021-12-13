#include <iostream>
#include <cstdlib>

static size_t arrSize = 0;
static size_t membersN = 0;
static int* arrPtr = nullptr;
static size_t incStep = 8;

void init_arr()
{
	arrPtr = new int[incStep];
	arrSize = incStep;
}

void close_arr()
{
	delete[] arrPtr;
	arrPtr = nullptr;
	arrSize = -1;
	membersN = -1;
}

size_t get_size()
{
	return membersN;
}

int get_item(size_t pos)
{
	return (pos<membersN) ? arrPtr[pos]: -1;
}

static void add_arr_item(int val)
{
	arrPtr[membersN] = val;
	membersN++;
}

static void increase_arr_size()
{
	arrSize += incStep;
	int* newArrPtr = new int[arrSize];
	for (size_t i = 0; i < membersN; i++)
		newArrPtr[i] = arrPtr[i];
	delete[] arrPtr;
	arrPtr = newArrPtr;
}

bool is_val_present(int val)
{
	for (size_t i = 0; i < membersN; i++)
		if (arrPtr[i] == val) return true;
	return false;
}

size_t get_metrics()
{
	return arrSize;
}

void print_metrics()
{
	std::cout << '\n' << "n= " << membersN << "\t size= " << arrSize << '\n';
}

bool add_item(int val)
// returns:
// true if val added
// false if val present yet
{
	if (membersN == 0)
	{
		add_arr_item(val);
		return true;
	}
	if (is_val_present(val)) return false;
	if (membersN == (arrSize-1)) increase_arr_size();
	add_arr_item(val);
	return true;
}