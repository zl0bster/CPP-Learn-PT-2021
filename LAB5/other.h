//Прототипы используемых в данном задании функций:

extern int ref; 

int square(int& x);

int IncByValue(int x);
int IncByPointer(const int* x);
int IncByReference(const int& x);

void Swap_p(int* x, int* y);
void Swap_r(int& x, int& y);