/*************************************************************
	Практическое занятие №3. Директивы препроцессора.
							Указатели.
*************************************************************/
#define _USE_MATH_DEFINES
#include <iostream>
#include <tchar.h>
#include <cmath>

//#define _USE_MATH_DEFINES

//#define M_PI 3.1415926
#define	  stop __asm nop	//с помощью директивы препроцессора задаем
							//макроподстановку

int _tmain()
{
// ********************************************************
	//Задание 1. Директивы препроцессора

	//1.1. Использование "математических" макросов стандартной библиотеки:
	//в заголовочном файле <cmath> (который в свою очередь включает старый
	//файл math.h) определены часто используемые математические
	//константы, например M_PI. Воспользуйтесь этой константой для
	//вычисления длины окружности.
	//Обратите внимание: определения констант в свою очередь тоже заключены
	//в директивы условной трансляции. Что еще, кроме подключения заголовочного
	//файла, требуется сделать???
// *******************************************************

	
	//1.2.Макросы с параметрами.
	//1.2.1 Напишите свою макроподстановку LENGHT которая вычисляет длину окружности.
	// протестируйте написанный макрос для следующих ситуаций:

#define LENGTH(x) (M_PI*(x)*2)
	{
		float l1 = LENGTH(1 + 2); // должно быть 18.8495...
		float l2 = 1 / LENGTH(2); // должно быть 0.07957...
		stop
	}
// *******************************************************

	//1.2.2 (B) определите макрос MAX(A, B)  для вычисления б'ольшего
	//значения из двух.
#define MAX(a, b)	(((a)>(b))? (a):(b))
	//Используйте макрос следующим образом. Следите за изменением
	//значений переменных k, i, j. Объясните результат.
	//Постарайтесь убрать побочные эффекты.
	//Отметьте случаи, когда избежать побочных эффектов невозможно

	int i = 10, j = 12, k;
	k = MAX(i, j);
	k = MAX(j, i) * 2;
	k = MAX(j, i+3);
	k = MAX(i--, j++);

// *******************************************************

	//1.2.3 определите макрос EXCHANGE(X, Y)  для перестановки
	//двух объектов типа int в памяти местами. Проверьте для приведенного
	//фрагмента. Подумайте, что будет делать макроподстановка, если
	//переставляемые значения разного типа???
#define EXCHANGE(a, b) {int tmp=a; a=b; b=tmp;}

	int x1=1, y1=-5;
	EXCHANGE(x1,y1);

	int x2=100, y2=-100;
	EXCHANGE(x2,y2);


// *******************************************************


	//1.3. Директивы условной трансляции
	//Выполняя следующий фрагмент, посмотрите, какое
	//значение принимает переменная iNN. Что нужно сделать
	//для того, чтобы результат был равен 0? 1? 2?

//#define NNN
//#define MMM
int iNN;
#if defined NNN && defined MMM
	iNN = 0;
#elif defined MMM
	iNN = 1;
#elif defined NNN 
	iNN = 2;

#else
	iNN = -1;
#endif
	
	stop

		// *******************************************************

			//Задание 1.4. Загляните в Project -> Properties -> диалоговая панель
			//- Property Pages -> C\C++  -> Preprocessor -> Preprocessor definitions.
			//В опциях командной строки в зависимости от мишени сборки проекта
			//(Debug или Release) может быть определено с помощью ключа /D
			//имя _DEBUG. С помощью директив условной
			//трансляции напишите фрагмент кода, который в зависимости от типа
			//мишени выводит с помощью cout разный текст на консоль. Проверьте
			//при разных мишенях сборки.

#ifdef _DEBUG
		std::cout << "Debug mode" << "\n";
		std::cout << __DATE__ << "\n";
		std::cout << __FILE__ << "\n";
#else
		std::cout << "Release configuration!" << "\n";
#endif // DEBUG


	//Пусть
	//для мишени Debug в процессе выполнения данного участка
	//кода на экран выводится информация об
	//имени файла, номере строки с функцией вывода, дате и времени 
	//компиляции файла, содержащего данную функцию вывода,
	//а также имя функции, содержащей данную строку.

	//Для мишени Release должна быть просто выведена строка
	//"Release configuration!"

	//Подсказка: для получения нужной информации зайдите в online справку
	//(Help -> View Help), выберете язык C++ и в поле поиска введите 
	//следующую ключевую фразу: Predefined Macros
	
	//Подсказка: мишень сборки проекта можно
	//поменять следующим образом - Build-> Configuration Manager -> Configuration




// *******************************************************
	{
		//Задание 1.5  Управляя определенностью идентификатора _UNICODE и используя
		//возможности заголовочного <tchar.h>, определим и проинициализируем переменную,
		//которая может становиться как однобайтовой, так и расширенной без 
		//изменения исходного текста.
		//С помощью отладчика проверьте результат (определите значение в 10-чной и 16-чной системе счисления).

	//Подсказка: Для того, чтобы настроить проект на работу с  некоторой кодировкой, надо:
		//1)Выбрать Project -> Properties. Будет открыта диалоговая панель  Property Pages  
		//2)Configuration Properties -> Advansed-> Advansed Properties -> Character Set
		//3) установить флаг "Use Unicode Character Set", если требуется Unicode
		//4) установить флаг "Not Set", если требуется  работа с однобайторфми символами.
		TCHAR ch1 = __T('A');	// ch1=
		size_t s1 = sizeof(ch1);// s1=?
		TCHAR ch2 = __T('Ф');	// ch2=
		TCHAR ch3 = 'Ф';	// ch3=
	}
// ********************************************************
	//Задание 2.Заголовочные файлы. Директива #include
	//Создайте и подключите к проекту два заголовочных файла 1.h и 2.h
	//В каждом заголовочном файле объявите перечисление с одинаковыми именами
	//констант, но сопоставьте именованным константам разные значения, например:
	//1.h - enum MyEnum{My1, My2, My3};  . 2.h - enum MyEnum{My1=5, My2, My3};
	//С помощью директив условной трансляции в DEBUG-версии пользуйтесь значениями
	//констант из 1.h, а в RELEASE-версии значениями констант из 2.h
#ifdef _DEBUG
	std::cout << "DEBUG - Import 1.h" << "\n";
	#include "1.h"
#else
	std::cout << "RELEASE - Import 2.h" << "\n";
	#include "2.h"
#endif // DEBUG

// ********************************************************

	//Задание 3. Указатели
	//Объявите объекты разных типов и проинициализируйте их.
	//Объявите указатели соответствующих типов и проинициализируйте их
	//адресами заданных объектов. 
	//Выполняя задание, с помощью отладчика посмотрите, какие значения
	//будут присвоены переменным-указателям и на что эти указатели
	//"указывают"
	{
	int x = 0;
	char d = -1;
	double c = 1.1e-5;
	int* px = &x;
	char* pd = &d;
	double* pc = &c;
	std::cout << static_cast <int> (*pd) << '\n';
	}

// *******************************************************

	//Задание 3а. Объявите указатель на тип char и проинициализируйте
	//его адресом строкового литерала. Присвойте переменной типа char значение
	//любого элемента строки.
	//Проверьте - возможно ли присвоить какое-либо значение по адресу,
	//задаваемому указателем?
	{
		char name [] = "Vasilisa";
		char* pname =&name[0];
		std::cout << *pname << "\n";
		std::cout << name << "\n";
		name[7] = 'K';
		std::cout << *pname << "\n";
		std::cout << name << "\n";
		*name = 'K';
		std::cout << *pname << "\n";
		std::cout << name << "\n";
	}

	{
		const char *name = "vasilisa";
		char* pname = const_cast <char*> (name);
		//*name = 'A';
	//	*pname = 'A';

	}
	stop

// *******************************************************

	//Задание 4. Арифметика указателей. Операция разыменования указателя.
	//Выполняя задание, следите за изменением значений
	//указателей и значений объектов, на которые они указывают.
	//Интерпретируте наблюдаемые результаты
	{
		int nAr[3] = {1,3};
		int* pn = &nAr[0];
		(*pn)++;	
		pn++;	

		char cAr[]={'A','B','C','D'};
		char* pc = &cAr[0];
		(*pc)=(*pc)+5;	
		pc=pc+3;	
	
		double dAr[3]={1.0,2.0};
		double* pd1 = &dAr[0];
		double* pd2 = pd1;
		(*pd2)+=2;
		pd2+=2;

		//Объясните результат выполнения операции
		//вычитания двух указателей
		pd1 = &dAr[0];
		pd2 = &dAr[1];
		int nNumber=pd2 - pd1;

		//Сравните указатели pd2 и pd1 и с помощью cout
		//выведите результаты сравнения.

		stop
	}


// *******************************************************

	//Задание 5. Void-указатель. 
	//5.1. Выполняя задание, посмотрите - какие значения присваиваются
	//void-указателю. Обратите внимание: средствами отладчика Вы
	//не можете посмотреть значения, на которые "указывает"
	//void-указатель
	void*	pVoid;	//объявление void-указателя
	int	nObject3=5;
	char cObject3='A';
	int*	pInt = &nObject3;	
	pVoid=&nObject3;
	pVoid=&cObject3;
	pVoid=pInt;
	
	//Прежде, чем раскомментировать следующую строчку, вспомните:
	//что нужно сделать, чтобы выражение стало корректным 	
	pInt=static_cast <int*> (pVoid);

	//Что нужно сделать для того, чтобы следующее закомментированное выражение
	//стало корректным?
	{
		const int n = 1;
		const void* pn = &n;//????объявить слева void-указатель
	}
// *******************************************************

	//5.2. При выполнении следующего фрагмента посмотрите, какие неприятности
	//могут Вас ожидать при явном приведении типа void-указателя,
	//который в момент времени (1) указывает на double, к типу 
	//указателя на int (2) 

	double dObject3 = 33.33;
	pVoid = &dObject3;	//(1)

	int nTmp = *(static_cast<int*>(pVoid) ); //(2) 
	stop

// *******************************************************


	//Задание 6.При выполнении задания обратите внимание на то,
	//как наглядно отладчик "раскрывает" конструкции типа
	//"указатель на указатель" и на способы получения конечного
	//объекта по таким "иерархическим" указателям
	int	n1=1;

    //Объявите указатель pn и проинициализируйте его так, чтобы он
	//"указывал" на n1
	int* pn1 = &n1;

    //Объявите указатель ppn и проинициализируйте его так, чтобы он
	//"указывал" на pn
	int** ppn1 = &pn1;

    //Объявите указатель pppn и проинициализируйте его так, чтобы он
	//"указывал" на ppn
	int*** pppn1 = &ppn1;
  
	//С помощью указателей pn, ppn и ppn получите значение объекта n1
	//и присвойте его n2
	std::cout << *pn1 << "\n";
	std::cout << **ppn1 << "\n";
	std::cout << *pppn1 << "\n";
	int n2 = **ppn1;

  
	stop




	return 0;
}//end main
