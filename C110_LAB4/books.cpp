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
	get_rnd_str1(bk->author, 4+rand()%(attrSize-4));
	get_rnd_str1(bk->bookName, 4 + rand() % (attrSize - 4));
	bk->yr = static_cast<short> (rand() % 120 + 1900);
	bk->tag = static_cast<BookType>(rand() % (NOPB));
}

static char* get_book_type(enum BookType bkt)
//static char* get_book_type(short bkt)
{
	char* typ = const_cast<char*> (typeList[NOPB].descript);
	for (size_t i = 0; i < NOPB; i++)
	{
		if (typeList[i].type == bkt)
		{
			//std::cout << typeList[i].type << ', ';
			typ = const_cast<char*> (typeList[i].descript);
			break;
		}
	}
	return typ;
}
void print_book(struct Book* bk)
{
	//std::cout << bk->yr << '\t' << bk->tag << '\t' << bk->author << '\t' << bk->bookName << '\n';
	std::cout << bk->yr << '\t' << get_book_type(bk->tag) << '\t' << bk->author << '\t' << bk->bookName << '\n';
}

void set_book_data(Book* bk, char* bkData)
{
	char* line = new char[80];

}

bool get_book_data_from_file(Book* bk, FILE* fl)
{
	if (fscanf(fl, "%i\t%i\t%s\t%s\n", bk->yr, bk->tag, bk->author, bk->bookName)==EOF) return true; // true means EOF
	return false;
}
void put_book_data_to_file(Book* bk, FILE* fl)
{
	fprintf(fl, "%i\t%i\t%s\t%s\n", bk->yr, bk->tag, bk->author, bk->bookName);
}