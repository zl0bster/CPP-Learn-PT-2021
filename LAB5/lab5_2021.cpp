﻿
/*************************************************************
	Практическое занятие №5. Функции.
	Объявление, определение, вызов.
	Передача параметров. Возвращение значения.
	
*************************************************************/
#include <iostream>
#include <tchar.h>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"


#define	  stop __asm nop

int _tmain()
{
	/*
	/////////////////////////////////////////////////////////////////////////////
	// Задание 1. Ссылки.
	// 1.1. Объявите ссылку на тип double. Посредством ссылки измените значение



	// 1.2. Раскомментируйте  следующую строчку. 
	//Что следует сделать, чтобы linker не выдавал ошибки при создании exe-файла?
	// Подсказка: ref - это внешняя по отношению к данному файлу ссылка!
	//Подумайте, где надо объявить эту внешнюю ссылку, а где ее определить.
	
	
	//ref++;

	// 1.3. Раскомментируйте следующую строку. 
	//Что следует сделать, чтобы компилятор не выдавал ошибки 
	//int& ref1 = 1;


	// 1.4. Задан указатель:
	char c='A';
	char* pc = &c;

	//Объявите ссылку на указатель. Посредством ссылки измените
	//а) значение по адресу
	//б) сам адрес


	 // 1.5. Объявите и определите функцию, вычисляющую квадрат числа, переданного в качестве параметра.
	 //  параметр должен быть ссылкой (!). Вызовите функцию с заданными ниже аргументами
	//Замечание (!!!):
	// объявления функций принято помещать в заголовочный файл (.h),
	// а определения функций- в файл реализации (.cpp)
	// в задании заготовлены файлы other.cpp и other.h. 
	//Эти файлы можно использовать для размещения  Ваших функций.
	 {
		int x = 10;
		int res1 = square(x);
		int res2 = square(5);
		stop
	}

*/
////////////////////////////////////////////////////////////////////////////	
	/*
	//Задание 2. Отличия при передаче параметров 
	//а) по значению, б) по ссылке, в) по указателю

	// 2.1. Объявите и определите три функции, которые увеличивают заданное
	//с помощью параметра значение на 1 
	// а) - IncByValue(),
	// б) - IncByPointer(), 
	//в) - IncByReference() . 
	//Проверьте правильность с помощью отладчика.
	//

	int val = 1;//значение этой переменной должно быть увеличено с помощью
				//каждой из функций на единицу

	stop
	*/
		/*
	// 2.2 Передача параметров c помощью указателя и по ссылке.
	//Создайте функцию (функции) Swap(), которая меняет значения
	//переменных nX и nY местами.
	
	// а)Функция должна принимать два указателя на int  и оперируя этими указателями
	//   должна менять значения переменных в вызывающей (!) программе

	// б)Функция должна принимать две ссылки на int и оперируя этими ссылками
	//   должна менять значения переменных в вызывающей (!) программе
	//Проверьте правильность с помощью приведенного ниже фрагмента.

			int	nX = 1;
			int nY = -1;
			Swap_p(...  ,  ...);  //поменяли местами значения nX и nY с помощью указателей на nX и nY
			Swap_r(...  ,  ...);  //а теперь обратно с помощью ссылок на nX и nY
			stop
	*/
		////////////////////////////////////////////////////////////////////////////
	/*
		//Задание 3. Массивы в качестве аргументов.
		// 3.1. Напишите функцию печати элементов во встроенном одномерном массиве

		//Например:
		int ar[N] = {список инициализаторов};//подумайте - как и где должна быть задана N
		PrintArray(ar, ... может быть, понадобится передать еще какие-нибудь данные);

		// 3.2. Напишите функцию поиска минимального элемента во встроенном одномерном массиве

		//Например:
		int ar[] = {список инициализаторов};
		int res = Min(ar, ... может быть, понадобится передать еще какие-нибудь данные);
	*/

	/*
		// 3.3. Напишите функцию сравнения двух строк - MyStrCmp():
		//Функция должна принимать два указателя на сравниваемые строки 
		//(возможно Вы должны указать компилятору, что функция не имеет права модифицировать 
		//содержимое строк)

		//Функция должна возвращать отрицательное значение, если
		//первая строка лексикографически меньше второй, 0 - если
		//они равны и положительное значение, если первая строка
		//больше второй.
		//Замечание: при лексикографическом способе сравниваются коды символов (!!!), а не длина строк
		// если код  символа первой строки > соответствующего кода символа второй строки, 
		// то первая строка > второй 
		//Вспомните, что признаком конца строки является нулевой байт.


		//Создайте две строки для сравнения:

		//Вызовите функцию сравнения

		//Выведите результат сравнения с помощью cout:

		stop
	*/
////////////////////////////////////////////////////////////////////////////
	//Задание 4. Функции работы со строками

		// 4. Создайте и вызовите функцию, которая принимает в качестве параметра 
		//порядковый номер - nN - месяца, 
		//а возвращает  указатель на символьную строку, содержащую название заданного месяца. 
		//Подсказка: 
		//-для того, чтобы данная функция работала корректно, очень важно – как объявлена строка,
		//указатель на которую требуется вернуть.
		//Кроме того, было бы неплохо предусмотреть защиту при некорректном значении месяца.
		{
			 const char* mStr = NameOfMonth(3);
			std::cout << mStr << std::endl;
			stop
		}

		

////////////////////////////////////////////////////////////////////////////
	//Задание 5. Возвращение адреса.
	//Напишите функцию, которая находит адрес минимального элемента в массиве,
	// таким образом, чтобы ее вызов можно было использовать слева от знака 
	// равенства: *MyMin(параметры) = 0;
	

////////////////////////////////////////////////////////////////////////////
	//Задание 6 (*).
	//Дан одномерный массив из N элементов
	//Известно: значения элементов могут быть только в диапазоне 0, 1, 2 …., 30, 31.  
	//Напишите две функции :
	//•первая - «выясняет» какие значения встречаются в массиве четное число раз, 
	//а какие – нечетное(при этом для результата можно использовать только один int) = >
	//int   f1(параметры);
	//•вторая –  выводит результат(Например: 0 встречается в массиве четное число раз)

	//В задании привести объявление, определение и вызов функций.


	return 0;
}//main
