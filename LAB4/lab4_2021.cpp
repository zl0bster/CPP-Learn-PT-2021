/*************************************************************
	Практическое занятие №4. Встроенные массивы.
							Простейшие алгоритмы сортировки и поиска.
							
*************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Sort_fx.h"

#define	  stop __asm nop

void print_int_array(const int* arrInt, size_t arrSize)
{

	for (int i = 0; (i < arrSize); i++)
	{
		std::cout << arrInt[i] << ' ';
	}
	std::cout << '\n' << "======================" << '\n';
}

bool isPresent(const int* arrInt, const size_t arrSize, const int value)
{
	for (int i = arrSize - 1; i >= 0; i--)
		if (arrInt[i] == value)
			return true;
	return false;
}

void fill_rndint_arr(int* arrInt, const size_t arrSize, const int limit)
{
	for (int i = (arrSize - 1); i >= 0; i--)
	{
		arrInt[i] = rand() % limit;
	}
}
void fill_uniqint_arr(int* arrInt, const size_t arrSize, const int limit)
{
	int value;
	for (int i = (arrSize - 1); i >= 0; i--)
	{
		do
			value = rand() % limit;
		while (isPresent(&arrInt[0], arrSize, value));
		arrInt[i] = value;
	}
}

void roll_int_arr(int* arrInt, const size_t arrSize, const bool directionRt)
{
	int temp;
	if (directionRt)
		temp = arrInt[arrSize - 1];
	else
		temp = arrInt[0];
	for (int i = (arrSize - 1); i > 0; i--)
	{
		if (directionRt)
			arrInt[i] = arrInt[i - 1];
		else
			arrInt[arrSize - i - 1] = arrInt[arrSize - i];
	}
	if (directionRt)
		arrInt[0] = temp;
	else
		arrInt[arrSize - 1] = temp;		
}

int main()
//Задания, помеченные * не являются обязательными. Но выполнение их крайне желательно!!!
{
///////////////////////////////////////////////////////////////
//			Указатели (продолжение)                              
///////////////////////////////////////////////////////////////

		//Задание 1. Модификатор const. 
		//В каждом из заданий объявите указатель требуемого вида. 
		//Посредством каждого указателя попробуйте:
		//1) получить значение по адресу
		//2) записать новое значение по адресу
		//3) модифицировать указатель
//Замечания:
//1.операторы явного преобразования типа использовать не следует
//2.если компилятор не позволяет выполнить операцию, то комментируйте эту строку с пояснением


		//Задание 1a. Указатель является константой.
	{
		unsigned int x = 0;
		unsigned int* const px = &x;
		stop
	}

		//Задание 1б. Указываемое значение является константой.
	{
		unsigned int x = 0;
		unsigned int const*  px = &x;
		stop
	}
	
// *******************************************************


		//Задание 1в. И указатель, и указываемое значение
		//являются константами. 
	{
		unsigned int x = 0;
		unsigned int const* const px = &x;
		stop
	}
	
// *******************************************************


		//Задание 1г. Указатель на переменную, объявленную с
		//ключевым словом const. 
	const int nN = 1;

	//Объявите указатель и проинициализируйте его выражением - &nN	
	int const*  pn = &nN;
	stop



// *******************************************************

	//Задание 2. Явное преобразование указателя. 
	//Иногда возникает необходимость одни и те же данные интерпретировать по-разному,

	//например, целое можно представить как совокупность четырех
	//байтов и работать с каждым байтом по отдельности. Для этого
	//нужно иметь возможность "указывать" как на целое, так и на байт. 

	//Следовательно, возникает необходимость явного преобразования указателя. 

	//Подсказка: для правильной интерпретации этого задания воспользуйтесь
	//возможностями отладчика представлять данные в интересующем
	//Вас виде (в данном случае - в шестнадцатеричном) - для
	//этого используйте правую клавишу мыши,находясь в окне

	//переменных и изменяйте пункт - Hexadecimal display !!!!!!!!!!!!!!!!!


	unsigned int nObject5=0x55667788;
	unsigned int* pnObject5=&nObject5;

	//Раскомментировав следующую строчку кода, обратите внимание на сообщение компилятора 
	//- он не считает преобразование "легальным" (безопасным)

	unsigned char* pucObject5;

	//pucObject5=static_cast<unsigned char*>(pnObject5);	//(1)

	pucObject5=reinterpret_cast<unsigned char*>(pnObject5);	//а такое
				//преобразование - целиком на совести программиста.
				//Его можно применять, только четко представляя себе
				//результат преобразования (2)

	//Откомментируйте (!) следующие строчки следующим образом:
	// сс=..., 	pucObject5 - изменился? 	*pucObject5=...

	char cc = *(pucObject5++);	//
	cc = (*pucObject5)++;		//

	cc = ++*(pucObject5);		//
	cc = *(++pucObject5);		//
	stop

		///////////////////////////////////////////////////////////////
		//			Встроенные массивы                               
		///////////////////////////////////////////////////////////////

			//Задание 3. 
			//Имеется одномерный встроенный массив, проинициализированный при объявлении 
			//Отсортируйте массив по возрастанию значений. 
			//Используйте "пузырьковую" сортировку  
			// Правильность решения проверьте с помощью отладчика

	{
		int ar[] = { 5, 4, 7,  8, 1, 2, 6, 0, 10, 12, 77, 11,
					  6, 8, 33, 21, 1, 2, 3, 4};
	int arrSize = sizeof(ar) / sizeof(ar[0]);
	int* pArr = &ar[0];
	print_int_array(&ar[0], arrSize);
	sort1(pArr, arrSize, descend);
	print_int_array(&ar[0], arrSize);
	}


		// *******************************************************
			//Задание 4  
			//в)Инициализация массива строковыми литералами:
			//Объявите одномерный массив УКАЗАТЕЛЕЙ и проинициализируйте его СТРОКОВЫМИ литералами . 
			//Выведите  массив на печать.

	{
		const int arrSize = 7;
		char arrChar[arrSize][16] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thusrsday", "Friday", "Saturday" };
		char* arrPchar[arrSize];
		for (int i = (arrSize - 1); i >= 0; i--)
		{
			std::cout << arrChar[i] << '\n';
		}

	}
	

// *******************************************************
	//Задание 5.
	{
	//a) Объявите одномерный неинициализированный массив ( размером N)
	//Задайте значения элементов с помощью генератора случайных чисел.
	const int arrSize = 40;
	int arrInt[arrSize];
	fill_rndint_arr(arrInt, arrSize, 100);
	/*for (int i = (arrSize - 1); i >= 0; i--)
	{
		arrInt[i] = rand() % 100;
	}*/
	//Подсказка 1: для генерации случайных чисел используйте функцию
	//стандартной библиотеки - rand() (<cstdlib>)
	// int tmp= rand(); // получим случайное значение в диапазоне от 0 до RAND_MAX
		//значение RAND_MAX задано в файле <stdlib.h>  и равно  0x7fff

	//если Вам требуется задать иные границы диапазона при генерации случайного числа, 
	//то это можно сделать так:
	//v1 = rand() % 100;         // v1 в диапазоне 0 - 99
	//v2 = rand() % 100 + 1;     // v2 в диапазоне 1 - 100
	//v3 = rand() % 30 + 1985;   // v3 в диапазоне 1985-2014 

	//Подсказка 2: На самом деле те значения, которые создаются генератором случайных
	//чисел являются «псевдослучайными», то есть при двух последовательных запусках
	//приложения Вы получаете две одинаковые последовательности значений.
	//Для того чтобы генерируемые "случайные" значения были разными при каждом 
	//запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
	//и time() (<ctime>).
	//Функция srand() осуществляет «привязку» начала генерации к указанному в качестве параметра значению.
	//Функция time() задает эту точку отсчета, считывая текущее время
	//srand( time( 0 ) );
//(Подсказки в файле Алгоритмы для лабораторной работы_4. pdf)


	//б) Выведите массив на печать
	print_int_array(&arrInt[0], arrSize);
	//в)Отсортируйте массив по убыванию значений. 
	//Используйте сортировку "выбором"
	sort1(&arrInt[0], arrSize, descend);
	print_int_array(&arrInt[0], arrSize);
	}
	// 

	// *******************************************************

		//Задание 6. 
		//Объявите встроенный одномерный массив, состоящий из N элементов целого типа. 
		//Напишите фрагмент кода, который вводит целые числа с помощью
		//потока ввода в объявленный Вами массив, каждый раз ( на каждой итерации!)
		//упорядочивая полученное значение по возрастанию.
		//Для проверки выводите массив на консоль на каждой итерации`


	// *******************************************************
		//Задание 7. 

		//Простой поиск.
		//Модифицируйте предыдущее задание следующим образом:
		//очередное введенное значение помещается в массив только при условии, 
		//что там еще такого нет (то есть дубли игнорируются)
	{
		int value;
		const int arrSize = 40;
		int arrInt[arrSize];
		fill_uniqint_arr(arrInt, arrSize, 100);
		print_int_array(&arrInt[0], arrSize);
		sort1(arrInt, arrSize, ascend);
		print_int_array(&arrInt[0], arrSize);
	}


	// *******************************************************
		//Задание 8
		//Объявите одномерный встроенный массив элементов типа char.
		//Сформируйте значения элементов массива с помощью генератора случайных 
		//чисел таким образом, чтобы в массиве были только символы '*' и '_'  
	{
		int value;
		const int arrSize = 40;
		char arrChar[arrSize];
		for (int i = (arrSize - 2); i >= 0; i--)
		{
			value = rand() % 2;
			if (value == 0)
				arrChar[i] = '_';
			else
				arrChar[i] = '*';
		}
		arrChar[arrSize - 1] = 0;
		std::cout << arrChar << '\n';

		//"сдвиньте звездочки" в начало массива, например:
		//было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
		//стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
		//и распечатайте массив 
		int flipNum;
		do
		{
			flipNum = 0;
			for (int i = (arrSize - 2); i > 0; i--)
			{
				if (arrChar[i] > arrChar[i - 1])
				{
					flipNum++;
					char temp = arrChar[i];
					arrChar[i] = arrChar[i - 1];
					arrChar[i - 1] = temp;
				}
			}
			std::cout << arrChar << '\n';
		} while (flipNum > 0);

	}
//(Подсказки в файле Алгоритмы для лабораторной работы_4. pdf)

// *******************************************************
	{
		//Задание 9
		//объявите одномерный встроенный массив  из N элементов и проинициализируйте его.
		//а) сдвиньте все элементы массива вправо на 1 позицию
		//б) (Циклическая перестановка). Сдвиньте все элементы массива вправо на 1 позицию , 
		//но последний элемент не должен быть утерян. Его следут переместить в начало.
		//например,  { 5, 2, 11, 4, 23, 9 } ->  {9, 5, 2, 11, 4, 23 }
		const int arrSize = 40;
		int arrInt[arrSize];
		fill_rndint_arr(arrInt, arrSize, 100);
		print_int_array(arrInt, arrSize);
		//в)(Кольцевой буфер) выведите массив на печать, циклически "сдвинув" элементы вправо на 1 позицию.
		//При решении задачи не следует перемещать элементы массива, а надо использовать кольцевой буфер.
		// Одномерный массив можно "свернуть" в кольцо и считать, что за последним элементом следует начальный и
		// потом установить "новое" начало массива.
		for (int i = 5; i > 0; i--)
		{
			roll_int_arr(arrInt, arrSize, true);
			print_int_array(arrInt, arrSize);
		}
		for (int i = 6; i > 0; i--)
		{
			roll_int_arr(arrInt, arrSize, false);
			print_int_array(arrInt, arrSize);
		}

	}
// *******************************************************
	{
		//Задание 10 (*)
	//алгоритм "тасования колоды"
	//объявите одномерный встроенный массив  из N элементов и 
	// заполните  его неповторяющимися числами из заданного отрезка 
	//натурального ряда, расположенными в случайном порядке

			const int arrSize = 40;
			int arrInt[arrSize];
			int arrResult[arrSize];
			char arrStat[arrSize];
			//fill_uniqint_arr(arrInt, arrSize, 100);
			for (int i = (arrSize - 1); i >= 0; i--)
				arrInt[i] = i;
			print_int_array(&arrInt[0], arrSize);
//(Подсказки в файле Алгоритмы для лабораторной работы_4.pdf)
//Алгоритм:
//Массив  A [N] инициализируется последовательными значениями из отрезка, например [0,N-1]
//index=N-1, где index- максимальное значение индекса.
			int val;
			for (int i = (arrSize - 1); i >= 0; i--)
			{
				do
					val = rand() % arrSize;
				while (arrStat[val] > 0);
				arrStat[val]=1;
				arrResult[i] = arrInt[val];
			}
			print_int_array(&arrResult[0], arrSize);
//В цикле по index выполняется перемешивание значений:
//	1. Генерируется случайное число  R из отрезка [0, index]
//	2. Выполняется обмен значений A[index]  и  A[R]
//	3. index=index -1
//	4. Если index==0, то конец
//	5. Переход к шагу 1    

	}
// *******************************************************

}
