#pragma once
#include <cstdlib>
#include <iostream>
const size_t attrSize = 20;

enum BookType {
	SCI,
	POE,
	STU,
	HUM,
	BIO,
	NOPB
};

struct BookTypeList {
	BookType type;
	const char* descript;
};

const BookTypeList typeList[] =
{
	{SCI, "Science"},
	{POE, "Poetry"},
	{STU, "Studybook"},
	{HUM, "Humor"},
	{BIO, "Biology"},
	{NOPB, "Undefined"}
};


typedef struct Book {
	char author[attrSize];
	char bookName[attrSize];
	short yr;
	BookType tag;
} BK;

enum BookAttrs {
	BKAUTHOR,
	BKNAME,
	BKYR,
	BKTAG
};

struct Book* new_book();
int compare_books(const Book* bk1, const Book* bk2, BookAttrs attr);
void print_book(struct Book* bk);
char* get_book_data(Book* bk);
void set_book_data(Book* bk, char* bkData);
bool get_book_data_from_file(Book* bk, FILE * fl);
void put_book_data_to_file(Book* bk, FILE* fl);
void del_book(Book* bk);
bool is_attr_eq(Book* bk, BookAttrs attr, ...);
void fill_book_rnd(Book* bk);