#include <cstdlib>
#include <iostream>

#include "..\C110_LAB1\Lab1_stuff.h"

#include "LAB4_arr.h"
#include "books.h"

Book* new_book()
{
	Book* ptr = new Book;
	return ptr;
}

void fill_book_rnd(Book* bk)
{
	get_rnd_str1(bk->author, attrSize);
	get_rnd_str1(bk->bookName, attrSize);
	bk->yr = static_cast<short> (rand() % 120 + 1900);
	bk->tag = static_cast<BookType>(rand() % (NOPB)-1);
}

static char* get_book_type(BookType bkt)
{
	char* typ = const_cast<char*> (typeList[NOPB].descript);
	for (size_t i = 0; i < NOPB; i++)
	{
		if (typeList[i].type == bkt)
			char* typ = const_cast<char*> (typeList[i].descript);
		break;
	}
	return typ;
}
void print_book(Book* bk)
{

	std::cout << bk->author << '\t' << bk->bookName << '\t' << bk->yr << '\t' << get_book_type(bk->tag)<<'\n';
}