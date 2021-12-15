
//Прототипы функций, используемых в данном задании :
//void VarArgs(int arg1, ...);

struct date {
	unsigned int yr;
	unsigned int mon;
	unsigned int day;
};
const int nDayTab[2][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31}, //невисокосный год
	{31,29,31,30,31,30,31,31,30,31,30,31} };	//високосный год

void VarArgs(int arg1, ...);
void VarArgs1(int arg1, ...);

char* convert_date_to_str(date  const & date1);
void print_date(date const & date1);
unsigned int count_day_N_from_Date(date const& date1);
date * count_Date_from_N_days( unsigned int yr, unsigned int day);

void Sort(char* pcFirst, int nNumber, int size,
void(*Swap)(void*, void*), int(*Compare)(void*, void*));
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);
void SwapFloat(void* p1, void* p2);
int CmpFloat(void* p1, void* p2);
void SwapStr(void* p1, void* p2);
int CmpStr(void* p1, void* p2);

const char* GetString1();
const char* GetString2();
const char* GetString3();
const char* GetString4();
const char* GetString5();


