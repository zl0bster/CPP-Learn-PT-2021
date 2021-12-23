#include <cstdlib>
#include <iostream>

#include "LAB4_arr.h"
#include "library.h"

LibRoot* new_lib()
{
	LibRoot* libRootPointer = new LibRoot;
	libRootPointer->libPtr = new_arr();
	return libRootPointer;
}

void add_book(LibRoot* lib, Book* bk)
{
	add_item(lib->libPtr, bk);
}

size_t add_book1(LibRoot* lib, Book* bk)
{
	return add_item(lib->libPtr, bk);
}

void print_lib(LibRoot* lib)
{
	using std::cout;
	cout << '\n' << lib->id << '\n';
	for (size_t i = 0; i < get_quantity(lib->libPtr); i++)
	{
		std::cout << i << '\t' << get_item_id(lib->libPtr, i) << '\t';
		print_book(get_item(lib->libPtr, i));
	}
}

size_t get_book_qty(LibRoot* lib)
{
	return lib->libPtr->membersQty;
}

bool save_lib(LibRoot* lib, const char* fileName)
{
	FILE* fp = fopen(fileName, "w");
	if (!fp)
	{
		printf("Cannot open directory file.");
		exit(1);
	}
	std::cout << "Start saving lib.";
	for (size_t i = 0; i < get_quantity(lib->libPtr); i++)
	{
		put_book_data_to_file(get_item(lib->libPtr, i), fp);
	}
	fclose(fp);
	std::cout << "Finish saving lib.";
	return true;
}

bool load_lib(LibRoot* lib, const char* fileName);