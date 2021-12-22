#pragma once
#include "LAB4_arr.h"
#include "books.h"

const size_t idSize = 20;
typedef char* BookLink;
typedef BookLink* BookList;

typedef struct LibRoot {
	char id[idSize];
	ArrData* libPtr;
	//size_t bksQty;
	//BookList bkList;
};

LibRoot* new_lib();
void add_book(LibRoot* lib, Book* bk);
size_t add_book1(LibRoot* lib, Book* bk);
void del_book(LibRoot* lib, Book* bk);
bool save_lib(LibRoot* lib);
bool load_lib(LibRoot* lib);
void sort_lib(LibRoot* lib, BookAttrs attr);
void print_lib(LibRoot* lib);
size_t get_book_qty(LibRoot* lib);