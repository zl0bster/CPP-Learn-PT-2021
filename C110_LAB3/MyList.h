#pragma once

struct ListRec
{
	ListRec* prev;
	ListRec* next;
	int val;
};

//void init_list();
void push(int val);
int pop();
void push_start(int val);
int pop_start();
bool remove_by_val(int val);
size_t get_qty();
int read_by_number(size_t num);
void print_list();
void clear_list();