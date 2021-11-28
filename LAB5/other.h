//Прототипы используемых в данном задании функций:
#include <iostream>
#include <tchar.h>

extern int ref; 

int square(int& x);

int IncByValue(int x);
int IncByPointer(const int* x);
int IncByReference(const int& x);

void Swap_p(int* x, int* y);
void Swap_r(int& x, int& y);

void print_int_array(const int* arrInt, size_t arrSize);
void fill_rndint_arr(int* arrInt, const size_t arrSize, const int limit);
size_t find_min_arr_ind(int* arrInt, const size_t arrSize);
int* find_min_arr_ptr(int* arrInt, const size_t arrSize);
int MyStrCmp(const char* line1, const char* line2);
char* get_month_name(int month);
void count_freq_sym(const int * sorsArr, int sorsSize, int * freqArr, int valLim);