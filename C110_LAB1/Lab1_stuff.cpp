


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
