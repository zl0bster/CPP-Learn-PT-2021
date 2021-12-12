
/*************************************************************
	������������ ������� �2 ���� �110. �������.
	��������� �� �������

*************************************************************/
#include <iostream>
#include <tchar.h>
#include <cstdlib>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"
#include "C:\Users\79110\source\repos\CPP Learn PT 2021\C110_LAB1\Lab1_stuff.h"


#define	  stop __asm nop
				
int _tmain()
//int main()
{

	//������� 1. 
	
	//��������� �� ������� � �������� ����������.
	//�������� ��� �������� ������� ������ ���������
	//1. �� ���������� ��������� �������
	//int ar[N][M] = {������ ���������������};//��������� - ��� � ��� ������ ���� ������ N � M
	//����� ������� PrintArray   ����� ��������� ���:
	//PrintArray(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);  //�����! ������ ��������- ��� ���������� (!) �������
	//2. � ������������ ��������� ������� (��� ����������� �����������)
	{
		const size_t N = 4;
		const size_t M = 3;
		const size_t K = 3;
		int arr2[N][M][K];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				for (int k = 0; k < K; k++)
					arr2[i][j][k] = i + 1;
		print_array(&arr2[0][0][0], N, M, K);

		size_t xS = 20;
		size_t yS = 14;
		unsigned int maxVal = 30;
		size_t arr1Size = xS * yS;
		int* arr1 = new int[arr1Size];
		for (unsigned int i = 0; i < arr1Size; i++)
			arr1[i] = rand() % maxVal;
		print_array(&arr1[0], 1, yS, xS);
		delete [] arr1;
	}
/////////////////////////////////////////////////////////////////////////////
	//������� 2.
	//�������� ��������� �� ���������� ������ � �������� ��������� �������.
			//�������� ��� ����������������� ���� ����� �������:
			//1.  ... DayOfYear(...)
			//- ����������� ���� ������ (�����,����� � ��� �������� � �������� ����������)
			//� ���������� ���� ����(������������ ��������)
			//2. ... DayOfMonth(...) - ������� ����������� ���������� ���� ���� � ���� ������
			// (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
			// ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)

			//��������� ����������������� ����� ������� � ������� ���������� ���������:


			//� �������� ���������� ��� �������� ��������� "���������� - ������������" ���.
			//��� �������� "������������" ���� ����� ����� ������� ������� (isLeepYear)
			//��� ����� ������������ � ������ ������� � �������� ������ �� ���������� ����������
			//������ ������������ ���� ����������� ������� nDayTab

	int nDayTab[2][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31}, //������������ ���
		{31,29,31,30,31,30,31,31,30,31,30,31} };	//���������� ���

	//����� ������� DayOfYear   ����� ��������� ���:
	

	//size_t day = ..., month = ..., year = ...;
	//size_t numDay = DayOfYear(day, month, year, nDayTab);  //�����! ��������� ��������- ��� ���������� (!) �������


	//�������� ���������� �������� �������� DayOfMonth        //�����! ��������� ��������- ��� ���������� (!) �������
	//...

	stop
/////////////////////////////////////////////////////////////////////////////
	//������� 3.
	//������� 3�. ������� � ���������� ������ ����������.
	//�������� ������� (���� ��������� VarArgs, �� ������������
	// �������), ������� ��������� ���������� ����� ����������
	// ���� int � ������� �� ������ ����� �������� ���������� �
	// �� ��������.
	// ��������� ����� ������ �������� ������� ��������.
/*	
	int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
	VarArgs(nN1,0);	
	VarArgs(nN1,nN2,0);	
	VarArgs(nN1,nN2,nN3,nN4,nN5,0);	
	stop


	//������� 3�. ������������� ������� 3� � ������� ��������
	// va_start, va_arg, va_end
*/


///////////////////////////////////////////////////////////////////
	//���� ��������� �� �������

	//������� 4. ��������� �� �������. "�����������".
	//�������� �������:
	//1)Sum - ��������� ��� �������� double � ���������� �����
	//���� ��������
	//2)Sub- ��������� ��� �������� double � ���������� ��������
	//���� ��������
	//3)Mul - *
	//4)Div - /
	//5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
	//		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
	//		��������� 2: ����������� ���������� ������������� ��������� �������������
	//		��������� ���� �������, � ��� ����������� ������������ ��������� �� 
	//		double pow(double, double);

	//������������ ������������	��������� �����������:
	//���� ������������ ����� ������������ �������� ������ ������������,
	//�� ����� ������� ��� �������� � ���� ��������
	//� �� �������� ���������. ��������� ��������� ����������� ������
	//��������������� ����� ������� �� ���������.
	//������������� ����������� ����� ������������������ ����� ��������


	stop
///////////////////////////////////////////////////////////////////
	//������� 5. ��������� �� ������� � �������� ���������.
	//���� ��������� ������� ���������� ����� �������� - Sort.
	//������� ��������� ��������� ���������:
	//1) ��������� �� ������ ����������� �������
	//2) ���������� ����������� ���������
	//3) ������ �������� � ������
	//4) ��������� �� ������� ������������ ���������
	//5) ��������� �� ������� ��������� ���������

	//5a. �������� ������� ������������ ���� ����� �������� -
	// SwapInt, ������� ��������� ��� void ��������� � 
	//������ �������� �������

	//�������� ������� ��������� ���� ����� �������� -
	// CmpInt, ������� ��������� ��� void ��������� �
	//���������� int ��������� ���������: 
	//<0 - ������ ������� ������, ��� ������
	//=0 - �����
	//>0 - ������ ������� ������, ��� ������
	/*
		int nAr[]=...	//������ ��� ����������

		//������ ��������� �������

		//����� ����������
		int nTotal=...			//���������� ��������� � �������
		Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

		//������ ����������� ����������

		stop
	*/
	/*
	//������� 5�. �� �������� � 5� �������� ���������������
	//������� - SwapDouble � CmpDouble � �������� ������� Sort
	//��� ���������� ������� ������������ ��������.
	*/
	/*
	//������� 5�*. �� �������� � 5� �������� ���������������
	//������� - SwapStr � CmpStr � �������� ������� Sort
	//��� ���������� ������� ���������� �� ������.
	
	const char* arStr[] = { "QQQ", "SDF", "ABC","Abba", "ENFR","En",. . . };
	//���������:
	//� ������� ������� ����� ������ �����, ���� �������� ����� �������, 
		Sort(reinterpret_cast<char*>(&arStr[0])), nTotal, sizeof(???), SwapStr, CmpStr);
	*/
///////////////////////////////////////////////////////////////////
	/*
	//������� 6. ������� ���������� �� �������.
	//�������� ��������� ������� ����
	//const char* GetString1();   
	//const char* GetString2();
	//const char* GetString3();
	//const char* GetString4();
	//const char* GetString5();

	//		...., ������ �� ������� ���������� ��������� �� ���� ������
	//(��������� - ����� ����� �� ������ ����� ���������� �� �������)
	
	// ��� ������������ ��� ���� �������. 
	//���������:
	//1) ��� �� ��� ���������, ���� ���, �� ��� ��������� ��������������
	//2) ����� ���� ��������� �����-�� �������������� ��������

	//�������� � ������������������ ������ ���������� �� �������
	//GetString1,GetString2...
	//������� ����� �������, ������� �� ������ �������:
		int n;



	//�������� �������



	//������������ ���������


	*/
////////////////////////////////////////////////////////////////////////////
	//������� 7*.
	//�������� ���������� ������ (����������� ����������� � ��������
	//���������� ���������), ��������� ��� ����������.
	//�������� �������, ������� ��������� � ������ ����� �������� ������ (!) ��� �������,
	//��� ������ �������� � ������� ��� ���. 
	//���������: ��� ���� ������  ������� ������ �����������!
	//��� �������� �������� �������, ������� ������� �������� ���� ��������� �� �����
///////////////////////////////////////////////////////////////////////////
	

	return 0;
}//main

