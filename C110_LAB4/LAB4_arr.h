#pragma once
#include "books.h"

struct ArrItem {
	size_t id;
	Book* ptr;
};

struct ArrData {
	size_t arrSize;
	size_t membersQty;
	ArrItem* basePtr = nullptr;
	size_t incStep;
	size_t nextId;
};

ArrData* new_arr();
void close_arr(ArrData* arr);
size_t get_quantity(ArrData* arr);
Book* get_item(ArrData* arr, size_t pos);
size_t get_item_id(ArrData* arr, size_t pos);
Book* get_item_by_id(ArrData* arr, size_t id);
bool is_val_present(ArrData* arr, int val);
size_t get_size(ArrData* arr);
void print_metrics(ArrData* arr);
size_t add_item(ArrData* arr, Book* ptr);
void swap_items(ArrData* arr, size_t pos1, size_t pos2);
