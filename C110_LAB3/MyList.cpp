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
	if (qty = 0)
	{
		init_list(val);
		return;
	}
	ListRec *newRec = new ListRec;
	newRec->prev = end;
	newRec->next = nullptr;
	newRec->val = val;
	end->next = newRec;
	end = newRec;
	qty++;
}