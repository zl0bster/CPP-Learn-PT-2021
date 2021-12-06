/*************************************************************
	Практическое занятие №1. Встроенные многомерные массивы.
							Динамическое выделение памяти.
							Простейшие алгоритмы сортировки и поиска.
							Сложные указатели.
							Ссылки.
*************************************************************/
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Lab1_stuff.h"
#define	  stop __asm nop

int main()
{

///////////////////////////////////////////////////////////////
//			Встроенные  многомерные массивы                               //
///////////////////////////////////////////////////////////////

	//Задание 1.
	{
		using std::cout;
		//Объявите трехмерный N*M*K массив и сформируйте указанные
		//значения элементов следующим образом:
		//а) проинициализируйте массив при объявлении
		int arr1[3][3][3] = {
			{{1,1,1},{1,1,1},{1,1,1}},
			{{2,2,2},{2,2,2},{2,2,2}},
			{{3,3,3},{3,3,3},{3,3,3}}
		};
		stop
		//б) объявите неинициализированный массив и присвойте значения элементам
		//	с помощью кода
		//					 |--------|		
		//				   / |3  3  3 |		
		//    			 |---------|3 |
			//		   / | 2  2  2 |3 |
		//			  |---------|2 |__|
		//			  | 1  1  1 |2 | /
		//			  | 1  1  1 |__| 
		//			  | 1  1  1 | /
		//			  |_________|
		//Рекомендация: В качестве размерностей массива лучше указать N, M, K,
		//а не  задавать их жестко.  
		//Средствами отладчика проверьте правильность Вашего решения. 
		//Или выведите содержимое массива на печать.
		// Удобно выводить построчно каждый слой  массива и 
		//после каждого слоя пропускать строку для того, чтобы отделить один слой от другого

		const size_t N = 4;
		const size_t M = 3;
		const size_t K = 3;
		int arr2[N][M][K];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				for (int k = 0; k < K; k++)
					arr2[i][j][k] = i + 1;
		print_array(&arr2[0][0][0], N, M, K);
		
		//в) найдите сумму элементов массива. Подумайте, как это сделать эффективно.
		cout << "\n" << "sum = " << (summ_array(&arr2[0][0][0], N, M, K));
		cout << "\n" << "==================" << "\n";

		//г) проинициализируйте массив при определении:
		//				     |--------|		
		//			       / |3  0  0 |		
		//      		 |---------|0 |
		//    		   / | 2  0  0 |0 |
		//			  |---------|0 |__|
		//			  | 1  0  0 |0 | /
		//			  | 0  0  0 |__| 
		//			  | 0  0  0 | /
		//			  |_________|
		int arr3[3][3][3] = {
			{1},
			{2},
			{3}
		};
		print_array(&arr3[0][0][0], 3, 3, 3);
		cout << "\n" << "==================" << "\n";

		//д) Инициализация массивов строковыми литералами:
		//Объявите и проинициализируйте строковыми литералами два массива:
		//двухмерный массив и массив указателей. Поясните разницу в использовании
		//элементов таких массивов.
		const size_t nWords = 4;
		const char arr4[nWords][10] = {
			{"ZLOY"},
			{"BOBER"},
			{"SGEVAL"},
			{"DUPLO"}
		};
		const char* arr5[nWords];
		for (size_t i = 0; i < nWords; i++)
			arr5[i] =const_cast <char*> (&arr4[i][0]);
		for (size_t i = 0; i < nWords; i++)
			cout << arr5[i] << ' ';
		cout << "\n" << "==================" << "\n";
	}

/////////////////////////////////////////////////////////////////////
//Задание 2.
/*
//С помощью данной заготовки напишите программу,которая:
//вводит строки с клавиатуры с помощью cin>>...
//в объявленный Вами двухмерный ВСТРОЕННЫЙ массив 10*80 элементов типа char;
//признаком конца ввода является символ * (то есть строка - "*") или
//заполнение всего массива (больше свободных строк нет);

//То есть:
	//a) можно заполнять весь массив полностью (не забудьте подсказать, сколько элементов в массиве)
	//б) можно заполнять массив частично, до тех пор, пока пользователь не ввел строку "*".
	//Например:вводим строки (строки с пробелами не задаются, т.к. пробелы являются разделителями):
	//"Hello"
	//"Ok"
	//"*"
//сортировка строк в алфавитном порядке. 
//Пояснение: крайне не рекомендуется для сортировки сложных объектов физически
//перемещать их в памяти ( в нашем случае перемещать (копировать) строки)
//Намного эффективнее завести массив указателей на соответствующие строки 
//и перемещать только указатели на начало строк (массивов символов).
//Вопрос: При таком способе что будет  отсортировано?

//Подсказка: для лексикографического сравнения строк пользуйтесь
//функцией стандартной библиотеки strcmp(...), заголовочный файл <string.h>.
//int strcmp(char const* _Str1, char const* _Str2);
*/
	// далее Вам предлагается алгоритм, следуя которому, Вы сможете решить задачу.
	//{
	//using std::cout;
	//	//Определите необходимые значения как константы
	//	//STOP_STRING  -  "*"	//признак "прекратить ввод"
	//	//M  -  80	//максимальный размер одной строки
	//	//N  -  10	//максимальное количество строк в массиве
	//	const char STOP_STR[] = "*";
	//	const size_t M = 80;
	//	const size_t N = 10;

	//	//Объявите двухмерный массив с именем cBuffer типа char и
	//	// размерностью N*M
	//	char cBuf[N][M];

	//	//Объявите массив (с именем cPointers) указателей на строки
	//	//размерностью N
	//	char* cPointers[N];
	//	cout << "\n" << "==================" << "\n";

	//	//Цикл ввода строк:
	//	//а) выведите приглашение для ввода
	//	cout << "\n" << "Input string. Type \"*\" for finish." << "\n";
	//	//б) пока не введена строка STOP_STRING или не заполнен весь массив
	//	size_t it = 0;
	//	bool ifInputNext;
	//	do
	//	{
	//	//ввод строки в массив cBuffer:
	//		std::cin >> cBuf[it]; // str len should be checked
	//	//Присвойте элементу массива cPointers с индексом nIndex
	//	//указатель на строку с номером nIndex в массиве cBuffer
	//		cPointers[it] = cBuf[it];
	//		it++;
	//	//если введена строка - признак окончания, то выйти из цикла
	//		//ifInputNext = ((cBuf[i] != STOP_STR) || (i < N));
	//		ifInputNext = ((strcmp(cBuf[it], STOP_STR) != 0) && (it < N));
	//	} while (ifInputNext);

	//	//Выдать диагностику о том, что прием строк завершен.
	//	cout << "\n" << "==================" << "\n";
	//	cout <<  "You have input "<< it <<" lines." << "\n";
	//	for (size_t n = 0; n < it; n++)
	//		cout << cPointers[n] << "\n";
	//	//Теперь сортируем строки:
	//	bool isUnsorted = true;
	//	while (isUnsorted)
	//	{
	//		isUnsorted = false;
	//		for (size_t n = 0; n < (it - 1); n++)
	//		{
	//			cout << cPointers[n] << "\t" << cPointers[n + 1] << "\t" << strcmp(cPointers[n], cPointers[n + 1])<< "\n";
	//			if (strcmp(cPointers[n], cPointers[n + 1]) < 0)
	//			{
	//				swap_pointers(&cPointers[n], &cPointers[n + 1]);
	//				isUnsorted = true;
	//			}
	//		}
	//	}
	//	cout << "\n" << "==================" << "\n";
	//	for (size_t n = 0; n < it; n++)
	//		cout << cPointers[n] << "\n";
	////Цикл сортировки строк по методу "всплывающего пузырька" в
	////порядке возрастания кода первого символа
	//
	//}
//////////////////////////////////////////////////////////////////////////////

//Задание 3*. Объявление и использование указателей на многомерные массивы.
	{
		// Проинициализируйте трехмерный массив
		//double dArray[4][3][3] так, как показано на рисунке и напишите фрагмент
		//кода, который меняет местами значения элементов четных
		//и нечетных слоев:
		//	было:			     |--------|
		//  				   / |4  4  4 |
		//				     |--------| 4 |
		//			       / |3  3  3 | 4 |
		//    			 |---------|3 |   |
		//			   / | 2  2  2 |3 | /
		//			  |---------|2 |__|
		//			  | 1  1  1 |2 | /
		//			  | 1  1  1 |__|
		//			  | 1  1  1 | /
		//			  |_________|

		//	стало:			     |--------|
		//  				   / |3  3  3 |
		//				     |--------| 3 |
		//			       / |4  4  4 | 3 |
		//    			 |---------|4 |   |
		//			   / | 1  1  1 |4 | /
		//			  |---------|1 |__|
		//			  | 2  2  2 |1 | /
		//			  | 2  2  2 |__|
		//			  | 2  2  2 | /
		//			  |_________|
		using std::cout;
		const size_t N = 4;
		const size_t M = 3;
		const size_t K = 3;
		int arr2[N][M][K];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				for (int k = 0; k < K; k++)
					arr2[i][j][k] = i + 1;
		cout << "\n" << "==================" << "\n";
		print_array(&arr2[0][0][0], N, M, K);
		{
			//Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА РАВЕНСТВА!!!
			//int (*pp1)[K] = arr2[0];
			/*... = dArray[i];
			... = dArray[i + 1];*/
			//Подсказки: 
			//1) Слева от знака равенства надо определить два  сложных указателя. 
			//Так как справа находятся "имена" слоев, т.е. двумерных массивов, то
			// остается вспомнить какой указатель является эквивалентным имени двумерного массива.
			//2)дальше, воспользовавшись этими указателями, переставляем местами элементы i-того и i+1-ого слоев
		}
		int *p1 = &arr2[0][0][0];
		int *p2 = &arr2[2][0][0];
		for (size_t i = 0; i < (M * K); i++)
		{
			Swap_p(p1, p1 + (M * K));
			Swap_p(p2, p2 + (M * K));
			p1++;
			p2++;
		}
		cout << "\n" << "==================" << "\n";
		print_array(&arr2[0][0][0], N, M, K);
	}
///////////////////////////////////////////////////////////////////////////

//Задание 4
	{
		//а) Объявите двухмерный ВСТРОЕННЫЙ массив элементов типа char.
		//Сформируйте значения элементов массива с помощью генератора случайных
		//чисел таким образом, чтобы в массиве были только символы '_' и '*'
		char arr4[chArLineNum][chArLineLen];
			//Подсказка 1: для генерации случайных чисел используйте функцию
			//стандартной библиотеки - rand() (<cstdlib>)
			//Можно с помощью генератора случайных чисел  и оператора % получать значения 0 и 1,
			// а в массив помещать соответственно '_' и '*'.
		char* p1 = &arr4[0][0];
		for (size_t i = 0; i < (chArLineNum * chArLineLen); i++)
		{
			*p1 = (rand() % 2 == 0) ?  '-': '*';
			if ((i + 1) % chArLineLen == 0)
				* p1 = '\0';
			p1++;
		}
		print_ch_array(arr4);
			//Подсказка 2: На самом деле те значения, которые создаются генератором случайных
			//чисел являются «псевдослучайными», то есть при двух последовательных запусках
			//приложения Вы получаете две одинаковые последовательности значений.
			//Для того чтобы генерируемые "случайные" значения были разными при каждом
			//запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
			//и time() (<ctime>).
			//Функция srand() осуществляет «привязку» начала генерации к указанному в качестве параметра значению.
			//Функция time() задает эту точку отсчета, считывая текущее время
			//srand( time( 0 ) );
			//Замечание: в программе запускать функцию srand()  достаточно один раз 
			//В каждой строке "сдвиньте звездочки" в начало строки, например:
			//было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
			//стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
			//и распечатайте массив по строкам - "постройте распределение"
		bool isUnsorted = true;
		char tmp;
		while (isUnsorted)
		{
			isUnsorted = false;
			for (size_t y = 0; y < chArLineNum; y++)
				for (size_t x = 0; x < chArLineLen; x++)
				{
					if (arr4[y][x + 1] == '\0')
						break;
					if (arr4[y][x + 1] > arr4[y][x])
					{
						isUnsorted = true;
						tmp = arr4[y][x];
						arr4[y][x] = arr4[y][x + 1];
						arr4[y][x + 1] = tmp;
					}
				}
		}
		std::cout << "\n" << "==================" << "\n";
		print_ch_array(arr4);
		// б) Модифицируйте предыдущее задание следующим способом:
		//После заполнения массива с помощью генератора случайных чисел
		//"сдвиньте" звездочки по столбцам вниз и распечатайте полученное
		//"распределение"
	}
///////////////////////////////////////////////////////////////
//			Динамическое выделение памяти                    //
///////////////////////////////////////////////////////////////
//Задание 5.
	////Задание 5а.Создайте ДИНАМИЧЕСКИЙ двухмерный массив с размерностями,
	//вычисляемыми в процессе выполнения программы - N*M.
	//Задайте значения элементов помощью генератора случайных чисел.


	//Задание 5б. В сформированном массиве отсортируйте каждую строку по
	//убыванию значений. Используйте сортировку "выбором"


	//Задание 5в. Объявите одномерный массив размерностью N.
	//Сформируйте значение i-ого элемента одномерного массива  
	//равным среднему значению элементов i-ой строки
	//двухмерного массива


	//Подсказка - не забудьте освободить память!

/////////////////////////////////////////////////////////////////////////////
//Задание 6. 
	//Реализуйте задание №2, используя не встроенные, а ДИНАМИЧЕСКИЕ массивы (массив?).
	// Важно! 
	//Так как строки могут быть разной длины, /эффективным решением было бы 
	//отводить под каждую строку ровно столько байтов, сколько требуется для ее хранения.
	//
	//Для того, чтобы определить длину введенной строки можно воспользоваться 
	//функцией strlen 
	//size_t strlen(char const* _Str);
	
	//При этом значение количества строк сформируйте с помощью потока ввода
	int nStringNumber;
	   	 

	//Цикл ввода строк:

	// Для ввода строки нужно использовать буфер "достаточного" размера. 
	// В качестве такого буфера обычно используется встроенный массив.
	// Для того, чтобы введенную строку  скопировать из буфера в массив  строк,
	// можно воспользоваться функцией strcpy
	//char* strcpy_s(	char* _Dest,  char const* _Source);
	//  или
	//errno_t strcpy_s(char* _Dest, size_t  _SizeInBytes, char const* _Source); 
	//где _SizeInBytes - размер "приемного" буфера.
	//Замечание: 
	//скорее всего, при компиляции Вы получите следующую ошибку:
	//Severity	Code	Description	Project	File	Line	Suppression State
	//	Error	C4996	'strcpy': This function or variable may be unsafe.
	//Consider using strcpy_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
	
	//Это происходит потому, что функция strcpy считается небезопасной.
	
	//Для того, чтобы пользоваться функцией strcpy, а не strcpy_s, можно
	//  - либо объявить макрос #define _CRT_SECURE_NO_WARNINGS   (обязательно ДО всех #include !!!!!)
	//- либо установить режим без доп. проверки на безопасность Properties->C/C++ ->General->SDL checs -> No
	

	//Цикл сортировки строк по методу "всплывающего пузырька" в
	//порядке возрастания кода первого символа





	//Освобождение занятой памяти:




	return 0; 
}
