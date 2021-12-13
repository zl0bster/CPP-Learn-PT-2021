#include "other.h"
#include <string.h>
#include <cstdlib>
#include <iostream>
//#include <cstdio>
#include <cstdarg>
///////////////////////////////////////////////////

//Подсказка-заготовка для задания 5а
//Без использования макросов

void VarArgs(int arg1,...)
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	int* pArg = &arg1;
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов
	std::cout << "-\n";
	while (*pArg != 0)
	{
		std::cout << *pArg << '\t';
		pArg++;
		number++;
	}
	//Печать числа элементов
	std::cout << ":= " << number << '\n';
}

void VarArgs1(int arg1,...)
{
	int number = 0;	//счетчик элементов
	int i = arg1;
	va_list pArg;
	va_start(pArg, arg1);
	std::cout << "=\n";
	while (i != 0)
	{
		std::cout << i << '\t';
		i = va_arg(pArg, int);
		number++;
	}
	va_end(pArg);
	std::cout << ":= " << number << '\n';
}

///////////////////////////////////////////////////
char* convert_date_to_str(date  const& date1)
{
	char* dateStr = new char[11];
	return dateStr;
}

void print_date(date const& date1)
{
	std::cout << date1.yr << '-' << date1.mon << '-' << date1.day;
}

unsigned int count_day_N_from_Date(date const& date1)
{
	unsigned int dayN = date1.day;
	short yrType = (date1.yr % 4 == 0) ? 1 : 0;
	short monthN = (date1.mon <= 12) ? date1.mon : 12;
	for (size_t i = 0; i < (monthN - 1); i++)
		dayN += nDayTab[yrType][i];
	return dayN;
}

date* count_Date_from_N_days(unsigned int yr, unsigned int day)
{
	date* date1 = new date;
	date1->yr = yr;
	short yrType = (yr % 4 == 0) ? 1 : 0;
	short dayN = (day <= 366) ? day : 366;
	for (size_t i = 0; i < 12; i++)
	{
		short dayN1 = dayN - nDayTab[yrType][i];
		if (dayN1 <= 0)
		{
			date1->mon = i + 1;
			date1->day = dayN;
			break;
		}
		dayN = dayN1;
	}
	return date1;
}

void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//требуется
												//переставить
				(*Swap)(pPrevious, pCurrent);
		}
}
//-----------------------------------------------------------------------
void SwapInt(void* p1, void* p2)
{


}
//-----------------------------------------------------------------------
int CmpInt(void* p1, void* p2)
{
	int nResult =0;




	return nResult;
}
//-----------------------------------------------------------------------
const char* GetString1()
{
	return "Hello";
}
//-----------------------------------------------------------------------
const char* GetString2()
{
	const char* str = "Book";
	return str;
}
//-----------------------------------------------------------------------
const char* GetString3()
{
	char str[] = "Little";
	return str;
}
//-----------------------------------------------------------------------
const char* GetString4()
{
	static char str[] = "world";
	return str;
}
//-----------------------------------------------------------------------
const char* GetString5()
{
	char* str = new char[strlen("time")+1];
	return str;
}
