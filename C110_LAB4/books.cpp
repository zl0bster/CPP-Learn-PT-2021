#include <cstdlib>
#include <iostream>
#include <string.h>

#include "LAB4_arr.h"
#include "books.h"
#include "utils.h"

#define _CRT_SECURE_NO_WARNINGS

const BookTypeList typeList[] =
{
	{SCI, "Science"},
	{POE, "Poetry"},
	{STU, "Studybook"},
	{HUM, "Humor"},
	{BIO, "Biology"},
	{NOPB, "Undefined"}
};


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
	//static const char* bookType[] = 
	char* typ = const_cast<char*> (typeList[NOPB].descript);
	for (size_t i = 0; i < NOPB; i++)
	{
		if (typeList[i].type == bkt)
		{
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

bool get_book_data_from_file(Book* bk, FILE* fl)
{
	int i = 0;
	if (fscanf(fl, "%i", &i)==EOF) return true; // true means EOF
	bk->yr = i;
	if (fscanf(fl, "%i", &i)==EOF) return true; // true means EOF
	bk->tag = static_cast<BookType>(i);
	char tmp[80];
	if (fscanf(fl, "%s", tmp)==EOF) return true; // true means EOF
	strncpy(bk->author, tmp, attrSize);
	if (fscanf(fl, "%s", tmp)==EOF) return true; // true means EOF
	strncpy(bk->bookName, tmp, attrSize);
	return false;
}

void put_book_data_to_file(Book* bk, FILE* fl)
{
	fprintf(fl, "%i\t%i\t%s\t%s\n", bk->yr, bk->tag, bk->author, bk->bookName);
}
