// SelectSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define ARRAY_LENGTH 10
//////////////////////////////////////////////////////////////////////////////////////////////
///
//		ѡ�������㷨��
//			��������ѡ����С��������һ���������i��i=0������������
//			Ȼ���������еĴӵڶ��������������������� ��С������������
//			��i++����������ֱ�����һ����
//
////////////////////////////////////////////////////////////////////////////////////////////


void Swap(int& nFirst, int& nSecond)
{
	// 1.
	//int nTemp = nFirst;
	//nFirst = nSecond;
	//nSecond = nTemp;

	// 2.�������������ȣ������������ᵼ�����ݱ�Ϊ0
	if (nFirst != nSecond)
	{
		nFirst = nFirst^nSecond;
		nSecond = nFirst^nSecond;
		nFirst = nFirst^nSecond;
	}
}

// 
void SelectSort(int Array[], int nLength)
{	
	for (int i = 0; i < nLength; ++i)
	{		
		int nMinPos = i;
		// ÿ���ҳ���Сֵ
		for(int j = i+1; j < nLength; ++j)
		{			
			if (Array[j] < Array[nMinPos])
			{				
				nMinPos = j;
			}
		}
		// ����
		Swap(Array[i], Array[nMinPos]);
	}
}

// �����������
void PrintArray(int Array[], int nLength)
{
	for(int i = 0; i < nLength; ++i)
	{
		cout << Array[i] << ", ";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[ARRAY_LENGTH] = { 2, 9, 1, 5, 6, 8, 7, 3, 0, 11 };
	
	// 1.�����㷨1
	cout << "����ǰ���ݣ�" << endl;
	PrintArray(arr, ARRAY_LENGTH);
	SelectSort(arr,  ARRAY_LENGTH);
	cout << "��������ݣ�" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}

