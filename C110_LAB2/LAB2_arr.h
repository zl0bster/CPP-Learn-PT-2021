#pragma once

struct ArrData {
	size_t arrSize;
	size_t membersN;
	int* arrPtr = nullptr;
	size_t incStep;
};

ArrData* new_arr();
void close_arr(ArrData* arr);
size_t get_size(ArrData* arr);
int get_item(ArrData* arr, size_t pos);
bool is_val_present(ArrData* arr, int val);
size_t get_metrics(ArrData* arr);
void print_metrics(ArrData* arr);
bool add_item(ArrData* arr, int val);
