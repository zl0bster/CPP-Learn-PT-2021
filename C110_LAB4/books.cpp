#include <cstdlib>
#include <iostream>
#include <string.h>

//#include "..\C110_LAB1\Lab1_stuff.h"

#include "LAB4_arr.h"
#include "books.h"
#include "utils.h"

#define _CRT_SECURE_NO_WARNINGS

struct Book* new_book()
{
	struct Book* ptr = new Book;
	return ptr;
}

void fill_book_rnd(struct Book* bk)
{
	/*char name[attrSize];
	get_rnd_str1(name, attrSize);
	name = get_rnd_str(attrSize);
	strcpy_s(bk->author, name);
	get_rnd_str1(name, attrSize);
	strcpy_s(bk->bookName, name);*/

	get_rnd_str1(bk->author, 4+rand()%(attrSize-4));
	get_rnd_str1(bk->bookName, attrSize);
	bk->yr = static_cast<short> (rand() % 120 + 1900);
	bk->tag = static_cast<BookType>(rand() % (NOPB)-1);
}

static char* get_book_type(enum BookType bkt)
//static char* get_book_type(short bkt)
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
void print_book(struct Book* bk)
{

	std::cout << bk->author << '\t' << bk->bookName << '\t' << bk->yr << '\t' << get_book_type(bk->tag)<<'\n';
}