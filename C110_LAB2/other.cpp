//#include "other.h"
#include <string.h>
#include <cstdlib>
///////////////////////////////////////////////////

//���������-��������� ��� ������� 5�
//��� ������������� ��������
/*
void VarArgs(int arg1,...)
{
	int number = 0;	//������� ���������
	//�������� ��������� �� int � ��������������� ��� �������
	//������� ���������
	
	//���� �� ��������� ����� ������:
	// �) ������ �������� ���������� ���������
	// �) ����������� ��������� (�� ������ ��������� ��
	//��������� �������� ������)
	// �) ��������� ������� ���������




	//������ ����� ���������

}
*/
//#include "other.h"

///////////////////////////////////////////////////



void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//���������
												//�����������
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
