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
	//cout << '\n' << lib->id << '\n';
	for (size_t i = 0; i < get_quantity(lib->libPtr); i++)
	{
		std::cout << i << '\t'/* << get_item_id(lib->libPtr, i) << '\t'*/;
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
	std::cout << "Finish saving lib.\n";
	return true;
}

bool load_lib(LibRoot* lib, const char* fileName)
{
	FILE* fp = fopen(fileName, "r");
	if (!fp)
	{
		printf("Cannot open directory file.");
		exit(1);
	}
	std::cout << "Start loading lib.";
	while (true)
	{
		Book* tmp = new_book();
		if (get_book_data_from_file(tmp, fp)) break;
		add_book(lib,tmp);
	}
	fclose(fp);
	std::cout << "Finish loading lib.\n";
	return true;
}


static int cmp_bk_yr(const Book* bk1, const Book* bk2)
{
	if (bk1->yr == bk2->yr) return 0;
	return (bk1->yr > bk2->yr) ? 1 : -1;
}

static int cmp_bk_tag(const Book* bk1, const Book* bk2)
{
	if (bk1->tag == bk2->tag) return 0;
	return (bk1->tag > bk2->tag) ? 1 : -1;
}

static int cmp_bk_aut(const Book* bk1, const Book* bk2)
{
	return strcmp(bk1->author, bk2->author);
}

static int cmp_bk_nam(const Book* bk1, const Book* bk2)
{
	return strcmp(bk1->bookName, bk2->bookName);
}

static const struct cmpFxListItem {
	BookAttrs att;
	BookCmpFx fx;
};

cmpFxListItem bkCmpFxArr[] = {
	{BKAUTHOR, cmp_bk_aut},
	{BKNAME, cmp_bk_nam},
	{BKYR, cmp_bk_yr},
	{BKTAG, cmp_bk_tag}
};

void sort_lib(LibRoot* lib, BookAttrs attr)
{
	BookCmpFx fxPtr=nullptr;
	for (size_t i = 0; i < (BKTAG + 1); i++)
	{
		if (bkCmpFxArr[i].att == attr)
		{
			fxPtr = bkCmpFxArr[i].fx;
			break;
		}
	}
	size_t nNumber = lib->libPtr->membersQty;
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			size_t pCurrent =  j;
			size_t pPrevious = j - 1;
			if ((*fxPtr)(get_item(lib->libPtr, pPrevious), get_item(lib->libPtr, pCurrent)) > 0)
				swap_items(lib->libPtr, pPrevious, pCurrent);
		}
}

void remove_book_by_pos(LibRoot* lib, size_t pos)
{
	remove_item_by_pos(lib->libPtr, pos);
}