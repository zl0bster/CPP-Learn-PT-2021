#include <iostream>
#include <cstdlib>
#include "LAB4_arr.h"

void init_arr(ArrData* arr)
{
	arr->arrPtr = new ArrItem[arr->incStep];
	arr->arrSize = arr->incStep;
}

ArrData* new_arr()
{
	ArrData* newArrStruct = new ArrData;
	newArrStruct->arrSize = 0;
	newArrStruct->membersQty = 0;
	newArrStruct->incStep = 8;
	newArrStruct->arrPtr = nullptr;
	newArrStruct->nextId = 0;
	init_arr(newArrStruct);
	return newArrStruct;
}

void close_arr(ArrData* arr)
{
	delete[] arr->arrPtr;
	arr->arrPtr = nullptr;
	arr->arrSize = -1;
	arr->membersQty = -1;
	delete arr;
}

size_t get_size(ArrData* arr)
{
	return arr->membersQty;
}

Book* get_item(ArrData* arr, size_t pos)
{
	return (pos< arr->membersQty) ? arr->arrPtr[pos]->ptr: nullptr;
}

static void add_arr_item(ArrData* arr, Book* bk)
{
	arr->arrPtr[arr->membersQty]->ptr = bk;
	arr->arrPtr[arr->membersQty]->id = arr->nextId;
	arr->membersQty++;
	arr->nextId++;
}

static void increase_arr_size(ArrData* arr)
{
	arr->arrSize += arr->incStep;
	ArrItem* newArrPtr = new ArrItem[arr->arrSize];
	for (size_t i = 0; i < arr->membersQty; i++)
	{
		newArrPtr[i]->id = arr->arrPtr[i]->id;
		newArrPtr[i]->ptr = arr->arrPtr[i]->ptr;
	}
	delete[] arr->arrPtr;
	arr->arrPtr = newArrPtr;
}

bool is_val_present(ArrData* arr, int val)
{
	for (size_t i = 0; i < arr->membersQty; i++)
		if (arr->arrPtr[i]->id == val) return true;
	return false;
}

size_t get_size(ArrData* arr)
{
	return arr->arrSize;
}

void print_metrics(ArrData* arr)
{
	std::cout << '\n' << "n= " << arr->membersQty << "\t size= " << arr->arrSize << '\n';
}

bool add_item(ArrData* arr, Book*ptr)
// returns:
// true if val added
// false if val present yet
{
	if (arr->membersQty == (arr->arrSize-1)) increase_arr_size(arr);
	add_arr_item(arr, ptr);
	return true;
}
