#include <iostream>
#include <cstdio>
#include "MyList.h"

static ListRec* start = nullptr;
static ListRec* end = nullptr;
static size_t qty = 0;

static void init_list(int val)
{
	start = new ListRec;
	end = start;
	qty = 1;
	start->val = val;
}

void push(int val)
{
	if (qty == 0)
	{
		init_list(val);
		return;
	}
	ListRec *newRec = new ListRec;
	newRec->prev = end;
	newRec->next = nullptr;
	newRec->val = val;
	qty++;
#ifdef _DEBUG
	std::cout << newRec->val << '\t' << qty << '\n';
#endif // DEBUG

	if (qty == 1)
		return;
	end->next = newRec;
	end = newRec;
	
}

int pop()
{
	if (qty == 0)
		return 0;
	ListRec *popRec = end;
	int retVal = popRec->val;
	end = popRec->prev;
	qty--;
	delete popRec;
	return retVal;
}

void push_start(int val)
{
	if (qty == 0)
	{
		init_list(val);
		return;
	}
	ListRec *newRec = new ListRec;
	newRec->prev = nullptr;
	newRec->next = start;
	newRec->val = val;
	qty++;
	if (qty == 1)
		return;
	start->prev = newRec;
	start = newRec;
}

int pop_start()
{
	if (qty == 0)
		return 0;
	ListRec *popRec = start;
	int retVal = popRec->val;
	start = popRec->next;
	qty--;
	delete popRec;
	return retVal;
}

bool remove_by_val(int val)
{
	ListRec* current = start;
	while (current->val != val)
	{
		if (current->next == nullptr)
			return false;
		current = current->next;
	}
	current->next->prev = current->prev;
	current->prev->next = current->next;
	delete current;
	qty--;
	return true;
}

size_t get_qty()
{
	return qty;
}

int read_by_number(size_t num)
{
	if (num > qty)
		return end->val;
	ListRec *readRec = start;
	for (size_t i = 0; i < num; i++)
		readRec = readRec->next;
	return readRec->val;
}

void print_list()
{
	using std::cout;
	cout << "--\n";
	if (qty == 0)
		return;
	ListRec *current = start;
	for (size_t i = 0; i < qty; i++)
	{
		cout << current->val << ", ";
		current = current->next;
		//if (i % 20 == 0)
		//	cout << '\n';
	}
	cout << "\n";
}

void clear_list()
{
	for (size_t i = qty; i > 0; i--)
		pop();
}
bool save_list(const char* fileName)
{
	FILE* fout = fopen(fileName, "w");
	if (!fout)
		return false;
	ListRec* current = start;
	for (size_t i = 0; i < qty; i++)
	{
		fprintf(fout, "%d", current->val);
		current = current->next;
	}
	fclose(fout);
	return true;
}

bool load_list(const char* fileName)
{
	FILE* fin = fopen(fileName, "r");
	if (!fin)
		return false;
	ListRec* current = start;
	int tmp;
	while (true)
	{
		if (fscanf(fin, "%d", tmp) == EOF) break;
		push(tmp);
	}
	fclose(fin);
	return true;
}