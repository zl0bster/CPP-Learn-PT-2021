
#include <string.h>
#include <cstdlib>
#include "Lab1_stuff.h"

void print_array(const int* arr, size_t nLayers, size_t nLines, size_t nCols)
{
	using std::cout;
	for (int i = 0; i < nLayers; i++)
	{
		for (int j = 0; j < nLines; j++)
		{
			for (int k = 0; k < nCols; k++)
			{
				//cout << arr[i][j][k] << ' ';
				cout << *arr << ' ';
				arr++;
			}
			cout << "\n";
		}
		cout << "\n";
	}
};
void print_array(const float* arr, size_t nLayers, size_t nLines, size_t nCols)
{
	using std::cout;
	cout << "printing float values" << '\n';
	for (int i = 0; i < nLayers; i++)
	{
		for (int j = 0; j < nLines; j++)
		{
			for (int k = 0; k < nCols; k++)
			{
				//cout << arr[i][j][k] << ' ';
				cout << *arr << ' ';
				arr++;
			}
			cout << "\n";
		}
		cout << "\n";
	}
};

int summ_array(const int* arr, size_t nLayers, size_t nLines, size_t nCols)
{
	int arrSum = 0;
	for (int i = 0; i < nLayers; i++)
	{
		for (int j = 0; j < nLines; j++)
		{
			for (int k = 0; k < nCols; k++)
			{
				arrSum+= *arr;
				arr++;
			}
		}
	}
	return arrSum;
};

void swap_pointers(char** p1, char** p2)
{
	char* ptemp = *p1;
	*p1 = *p2;
	*p2 = ptemp;
}

void Swap_p(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void print_ch_array(char charArray[][chArLineLen])
{
	//system("CLS");
	for (int i = 0; i < (chArLineNum); i++)
		std::cout << charArray[i] << '\n';
}

char* get_rnd_str(size_t maxLen)
{
	using std::cout;
	const char* genCharSet = "abcdefghijklmnopqrstuvwxyz";
	const char* charSet1 = "aeiou ";
	size_t genSetLen = strlen(genCharSet);
	size_t set1Len = strlen(charSet1);
	char* newStr = new char[maxLen];
#if _DEBUG
	cout << maxLen << '\t' << genSetLen << '\t' << set1Len << '\n';
#endif
	unsigned int i = 0;
	while (i < maxLen)
	{
		if (i % 2 == 0)
			newStr[i] = genCharSet[rand() % genSetLen];
		else
			newStr[i] = charSet1[rand() % set1Len];
		i++;
	}
	newStr[maxLen - 1] = '\0';
#if _DEBUG
	cout << newStr << '\n';
#endif
	return newStr;
}

void get_rnd_str1(char * newStr, size_t maxLen)
{
	using std::cout;
	const char* genCharSet = "abcdefghijklmnopqrstuvwxyz";
	const char* charSet1 = "aeiou ";
	size_t genSetLen = strlen(genCharSet);
	size_t set1Len = strlen(charSet1);
	//static char* newStr = new char[maxLen];
#if _DEBUG
	cout << maxLen << '\t' << genSetLen << '\t' << set1Len << '\n';
#endif
	unsigned int i = 0;
	while (i < maxLen)
	{
		if (i % 2 == 0)
			newStr[i] = genCharSet[rand() % genSetLen];
		else
			newStr[i] = charSet1[rand() % set1Len];
		i++;
	}
	newStr[maxLen - 1] = '\0';
#if _DEBUG
	cout << newStr << '\n';
#endif
	
}
