/*************************************************************
	������������ ������� �1. ���������� ����������� �������.
							������������ ��������� ������.
							���������� ��������� ���������� � ������.
							������� ���������.
							������.
*************************************************************/
#include <iostream>
#include "Lab1_stuff.h"
#define	  stop __asm nop

int main()
{

///////////////////////////////////////////////////////////////
//			����������  ����������� �������                               //
///////////////////////////////////////////////////////////////

	//������� 1.
	{
		using std::cout;
		//�������� ���������� N*M*K ������ � ����������� ���������
		//�������� ��������� ��������� �������:
		//�) ������������������ ������ ��� ����������
		int arr1[3][3][3] = {
			{{1,1,1},{1,1,1},{1,1,1}},
			{{2,2,2},{2,2,2},{2,2,2}},
			{{3,3,3},{3,3,3},{3,3,3}}
		};
		stop
		//�) �������� �������������������� ������ � ��������� �������� ���������
		//	� ������� ����
		//					 |--------|		
		//				   / |3  3  3 |		
		//    			 |---------|3 |
			//		   / | 2  2  2 |3 |
		//			  |---------|2 |__|
		//			  | 1  1  1 |2 | /
		//			  | 1  1  1 |__| 
		//			  | 1  1  1 | /
		//			  |_________|
		//������������: � �������� ������������ ������� ����� ������� N, M, K,
		//� ��  �������� �� ������.  
		//���������� ��������� ��������� ������������ ������ �������. 
		//��� �������� ���������� ������� �� ������.
		// ������ �������� ��������� ������ ����  ������� � 
		//����� ������� ���� ���������� ������ ��� ����, ����� �������� ���� ���� �� �������

		const size_t N = 4;
		const size_t M = 3;
		const size_t K = 3;
		int arr2[N][M][K];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				for (int k = 0; k < K; k++)
					arr2[i][j][k] = i + 1;
		print_array(&arr2[0][0][0], N, M, K);
		
		//�) ������� ����� ��������� �������. ���������, ��� ��� ������� ����������.
		cout << "\n" << "sum = " << (summ_array(&arr2[0][0][0], N, M, K));
		cout << "\n" << "==================" << "\n";

		//�) ������������������ ������ ��� �����������:
		//				     |--------|		
		//			       / |3  0  0 |		
		//      		 |---------|0 |
		//    		   / | 2  0  0 |0 |
		//			  |---------|0 |__|
		//			  | 1  0  0 |0 | /
		//			  | 0  0  0 |__| 
		//			  | 0  0  0 | /
		//			  |_________|



		//�) ������������� �������� ���������� ����������:
		//�������� � ������������������ ���������� ���������� ��� �������:
		//���������� ������ � ������ ����������. �������� ������� � �������������
		//��������� ����� ��������.
	}

/////////////////////////////////////////////////////////////////////
//������� 2.
//� ������� ������ ��������� �������� ���������,�������:
//������ ������ � ���������� � ������� cin>>...
//� ����������� ���� ���������� ���������� ������ 10*80 ��������� ���� char;
//��������� ����� ����� �������� ������ * (�� ���� ������ - "*") ���
//���������� ����� ������� (������ ��������� ����� ���);

//�� ����:
	//a) ����� ��������� ���� ������ ��������� (�� �������� ����������, ������� ��������� � �������)
	//�) ����� ��������� ������ ��������, �� ��� ���, ���� ������������ �� ���� ������ "*".
	//��������:������ ������ (������ � ��������� �� ��������, �.�. ������� �������� �������������):
	//"Hello"
	//"Ok"
	//"*"
//���������� ����� � ���������� �������. 
//���������: ������ �� ������������� ��� ���������� ������� �������� ���������
//���������� �� � ������ ( � ����� ������ ���������� (����������) ������)
//������� ����������� ������� ������ ���������� �� ��������������� ������ 
//� ���������� ������ ��������� �� ������ ����� (�������� ��������).
//������: ��� ����� ������� ��� �����  �������������?

//���������: ��� ������������������� ��������� ����� �����������
//�������� ����������� ���������� strcmp(...), ������������ ���� <string.h>.
//int strcmp(char const* _Str1, char const* _Str2);

	// ����� ��� ������������ ��������, ������ ��������, �� ������� ������ ������.
	{

		//���������� ����������� �������� ��� ���������
		//STOP_STRING  -  "*"	//������� "���������� ����"
		//M  -  80	//������������ ������ ����� ������
		//N  -  10	//������������ ���������� ����� � �������



		//�������� ���������� ������ � ������ cBuffer ���� char �
		// ������������ N*M


		//�������� ������ (� ������ cPointers) ���������� �� ������
		//������������ N


		//���� ����� �����:
		//�) �������� ����������� ��� �����

		//�) ���� �� ������� ������ STOP_STRING ��� �� �������� ���� ������


		//���� ������ � ������ cBuffer:

		//���� ������� ������ - ������� ���������, �� ����� �� �����

		//��������� �������� ������� cPointers � �������� nIndex
		//��������� �� ������ � ������� nIndex � ������� cBuffer




		//������ ����������� � ���, ��� ����� ����� ��������.



		//������ ��������� ������:

	//���� ���������� ����� �� ������ "������������ ��������" �
	//������� ����������� ���� ������� �������
	
	}
//////////////////////////////////////////////////////////////////////////////

//������� 3*. ���������� � ������������� ���������� �� �����������
// �������. ������������������ ���������� ������
//double dArray[4][3][3] ���, ��� �������� �� ������� � �������� ��������
//����, ������� ������ ������� �������� ��������� ������
//� �������� �����:
//	����:			     |--------|
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

//	�����:			     |--------|
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
/*
for(int i=0; i<...; ...)
{
//���������: �� ����� �������������� ��������� ������ �� ����� ���������!!!
... =  dArray[i];
... =  dArray[i+1];
//���������: 
//1) ����� �� ����� ��������� ���� ���������� ���  ������� ���������. 
//��� ��� ������ ��������� "�����" �����, �.�. ��������� ��������, ��
// �������� ��������� ����� ��������� �������� ������������� ����� ���������� �������.

//2)������, ���������������� ����� �����������, ������������ ������� �������� i-���� � i+1-��� �����


}
*/

///////////////////////////////////////////////////////////////////////////
/*
//������� 4
//�) �������� ���������� ���������� ������ ��������� ���� char.
//����������� �������� ��������� ������� � ������� ���������� ���������
//����� ����� �������, ����� � ������� ���� ������ ������� '_' � '*'
	
	//��������� 1: ��� ��������� ��������� ����� ����������� �������
	//����������� ���������� - rand() (<cstdlib>)
	//����� � ������� ���������� ��������� �����  � ��������� % �������� �������� 0 � 1,
	// � � ������ �������� �������������� '_' � '*'.

	
	//��������� 2: �� ����� ���� �� ��������, ������� ��������� ����������� ���������
	//����� �������� �����������������, �� ���� ��� ���� ���������������� ��������
	//���������� �� ��������� ��� ���������� ������������������ ��������.
	//��� ���� ����� ������������ "���������" �������� ���� ������� ��� ������
	//������� ���������� ����������� ������� ����������� ���������� srand() (<cstdlib>)
	//� time() (<ctime>).
	//������� srand() ������������ ��������� ������ ��������� � ���������� � �������� ��������� ��������.
	//������� time() ������ ��� ����� �������, �������� ������� �����
	//srand( time( 0 ) );
	
	//���������: � ��������� ��������� ������� srand()  ���������� ���� ��� 
    

//� ������ ������ "�������� ���������" � ������ ������, ��������:
//���� - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
//�����: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
//� ������������ ������ �� ������� - "��������� �������������"

*/


// �) ������������� ���������� ������� ��������� ��������:
//����� ���������� ������� � ������� ���������� ��������� �����
//"��������" ��������� �� �������� ���� � ������������ ����������
//"�������������"

///////////////////////////////////////////////////////////////
//			������������ ��������� ������                    //
///////////////////////////////////////////////////////////////
//������� 5.
	////������� 5�.�������� ������������ ���������� ������ � �������������,
	//������������ � �������� ���������� ��������� - N*M.
	//������� �������� ��������� ������� ���������� ��������� �����.


	//������� 5�. � �������������� ������� ������������ ������ ������ ��
	//�������� ��������. ����������� ���������� "�������"


	//������� 5�. �������� ���������� ������ ������������ N.
	//����������� �������� i-��� �������� ����������� �������  
	//������ �������� �������� ��������� i-�� ������
	//����������� �������


	//��������� - �� �������� ���������� ������!

/////////////////////////////////////////////////////////////////////////////
//������� 6. 
	//���������� ������� �2, ��������� �� ����������, � ������������ ������� (������?).
	// �����! 
	//��� ��� ������ ����� ���� ������ �����, /����������� �������� ���� �� 
	//�������� ��� ������ ������ ����� ������� ������, ������� ��������� ��� �� ��������.
	//
	//��� ����, ����� ���������� ����� ��������� ������ ����� ��������������� 
	//�������� strlen 
	//size_t strlen(char const* _Str);
	
	//��� ���� �������� ���������� ����� ����������� � ������� ������ �����
	int nStringNumber;
	   	 

	//���� ����� �����:

	// ��� ����� ������ ����� ������������ ����� "������������" �������. 
	// � �������� ������ ������ ������ ������������ ���������� ������.
	// ��� ����, ����� ��������� ������  ����������� �� ������ � ������  �����,
	// ����� ��������������� �������� strcpy
	//char* strcpy_s(	char* _Dest,  char const* _Source);
	//  ���
	//errno_t strcpy_s(char* _Dest, size_t  _SizeInBytes, char const* _Source); 
	//��� _SizeInBytes - ������ "���������" ������.
	//���������: 
	//������ �����, ��� ���������� �� �������� ��������� ������:
	//Severity	Code	Description	Project	File	Line	Suppression State
	//	Error	C4996	'strcpy': This function or variable may be unsafe.
	//Consider using strcpy_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
	
	//��� ���������� ������, ��� ������� strcpy ��������� ������������.
	
	//��� ����, ����� ������������ �������� strcpy, � �� strcpy_s, �����
	//  - ���� �������� ������ #define _CRT_SECURE_NO_WARNINGS   (����������� �� ���� #include !!!!!)
	//- ���� ���������� ����� ��� ���. �������� �� ������������ Properties->C/C++ ->General->SDL checs -> No
	

	//���� ���������� ����� �� ������ "������������ ��������" �
	//������� ����������� ���� ������� �������





	//������������ ������� ������:




	return 0; 
}