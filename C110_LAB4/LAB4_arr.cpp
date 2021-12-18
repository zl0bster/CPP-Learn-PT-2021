#include <iostream>
#include <cstdlib>
#include "LAB4_arr.h"

void init_arr(ArrData* arr)
{
	arr->basePtr = new ArrItem[arr->incStep];
	arr->arrSize = arr->incStep;
}

ArrData* new_arr()
{
	ArrData* newArrStruct = new ArrData;
	newArrStruct->arrSize = 0;
	newArrStruct->membersQty = 0;
	newArrStruct->incStep = 8;
	newArrStruct->basePtr = nullptr;
	newArrStruct->nextId = 1;
	init_arr(newArrStruct);
	return newArrStruct;
}

void close_arr(ArrData* arr)
{
	delete[] arr->basePtr;
	arr->basePtr = nullptr;
	arr->arrSize = -1;
	arr->membersQty = -1;
	delete arr;
}

size_t get_quantity(ArrData* arr)
{
	return arr->membersQty;
}

Book* get_item(ArrData* arr, size_t pos)
{
	if (pos < arr->membersQty) return nullptr;
	ArrItem record =  arr->basePtr[pos];
	return record.ptr;
}

static void add_arr_item(ArrData* arr, Book* bk)
{
	ArrItem record = arr->basePtr[arr->membersQty];
	record.ptr = bk;
	record.id = arr->nextId;
	arr->membersQty++;
	arr->nextId++;
}

static void increase_arr_size(ArrData* arr)
{
	arr->arrSize += arr->incStep;
	ArrItem* newArrPtr = new ArrItem[arr->arrSize];
	for (size_t i = 0; i < arr->membersQty; i++)
	{
		newArrPtr[i].id = arr->basePtr[i].id;
		newArrPtr[i].ptr = arr->basePtr[i].ptr;
	}
	delete[] arr->basePtr;
	arr->basePtr = newArrPtr;
}

bool is_val_present(ArrData* arr, int val)
{
	for (size_t i = 0; i < arr->membersQty; i++)
		if (arr->basePtr[i].id == val) return true;
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
