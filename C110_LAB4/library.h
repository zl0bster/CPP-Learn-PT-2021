#pragma once
#include "LAB4_arr.h"
#include "books.h"

const size_t idSize = 20;
typedef char* BookLink;
typedef BookLink* BookList;

struct LibRoot {
	char id[idSize];
	ArrData* libPtr;
	//size_t bksQty;
	//BookList bkList;
};

LibRoot* new_lib();
void add_book(LibRoot* lib, Book* bk);
void del_book(LibRoot* lib, Book* bk);
bool save_lib(LibRoot* lib);
bool load_lib(LibRoot* lib);
void sort_lib(LibRoot* lib, BookAttrs attr);
void print_lib(LibRoot* lib);