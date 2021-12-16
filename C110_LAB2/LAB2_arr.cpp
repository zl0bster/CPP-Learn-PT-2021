#include <iostream>
#include <cstdlib>
#include "LAB2_arr.h"

void init_arr(ArrData* arr)
{
	arr->arrPtr = new int[arr->incStep];
	arr->arrSize = arr->incStep;
}

ArrData* new_arr()
{
	ArrData* newArrStruct = new ArrData;
	newArrStruct->arrSize = 0;
	newArrStruct->membersN = 0;
	newArrStruct->incStep = 8;
	newArrStruct->arrPtr = nullptr;
	init_arr(newArrStruct);
	return newArrStruct;
}

void close_arr(ArrData* arr)
{
	delete[] arr->arrPtr;
	arr->arrPtr = nullptr;
	arr->arrSize = -1;
	arr->membersN = -1;
	delete arr;
}

size_t get_size(ArrData* arr)
{
	return arr->membersN;
}

int get_item(ArrData* arr, size_t pos)
{
	return (pos< arr->membersN) ? arr->arrPtr[pos]: -1;
}

static void add_arr_item(ArrData* arr,int val)
{
	arr->arrPtr[arr->membersN] = val;
	arr->membersN++;
}

static void increase_arr_size(ArrData* arr)
{
	arr->arrSize += arr->incStep;
	int* newArrPtr = new int[arr->arrSize];
	for (size_t i = 0; i < arr->membersN; i++)
		newArrPtr[i] = arr->arrPtr[i];
	delete[] arr->arrPtr;
	arr->arrPtr = newArrPtr;
}

bool is_val_present(ArrData* arr, int val)
{
	for (size_t i = 0; i < arr->membersN; i++)
		if (arr->arrPtr[i] == val) return true;
	return false;
}

size_t get_metrics(ArrData* arr)
{
	return arr->arrSize;
}

void print_metrics(ArrData* arr)
{
	std::cout << '\n' << "n= " << arr->membersN << "\t size= " << arr->arrSize << '\n';
}

bool add_item(ArrData* arr, int val)
// returns:
// true if val added
// false if val present yet
{
	if (arr->membersN == 0)
	{
		add_arr_item(arr, val);
		return true;
	}
	if (is_val_present(arr, val)) return false;
	if (arr->membersN == (arr->arrSize-1)) increase_arr_size(arr);
	add_arr_item(arr, val);
	return true;
}
