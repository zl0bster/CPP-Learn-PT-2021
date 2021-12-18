#pragma once
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


struct Book {
	char author[attrSize];
	char bookName[attrSize];
	short yr;
	BookType tag;
};

enum BookAttrs {
	BKAUTHOR,
	BKNAME,
	BKYR,
	BKTAG
};

Book* new_book();
int compare_books(const Book* bk1, const Book* bk2, BookAttrs attr);
void print_book(Book* bk);
char* get_book_data(Book* bk);
void set_book_data(Book* bk, char* bkData);
void del_book(Book* bk);
bool is_attr_eq(Book* bk, BookAttrs attr, ...);
void fill_book_rnd(Book* bk);