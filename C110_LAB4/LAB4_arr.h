#pragma once
#include "books.h"

struct ArrItem {
	size_t id;
	Book* ptr;
};

struct ArrData {
	size_t arrSize;
	size_t membersQty;
	ArrItem* arrPtr = nullptr;
	size_t incStep;
	size_t nextId;
};

ArrData* new_arr();
void close_arr(ArrData* arr);
size_t get_size(ArrData* arr);
Book* get_item(ArrData* arr, size_t pos);
bool is_val_present(ArrData* arr, int val);
size_t get_size(ArrData* arr);
void print_metrics(ArrData* arr);
bool add_item(ArrData* arr, int val);
