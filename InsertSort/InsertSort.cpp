// InsertSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define ARRAY_LENGTH 10

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///		ֱ�Ӳ�������
///		����array[0]��һ������������䣬Ȼ��array[1]ֱ�Ӳ���array[0]������䡣
///		Ȼ�����ν������ÿһ��������ǰ���Ѿ��źõ������С�
///
///		������Ϊa[0��n-1]��
///		1. ��ʼʱ��a[0]�Գ�1����������������Ϊa[1..n-1]����i=1
///		2. ��a[i]���뵱ǰ��������a[0��i-1]���γ�a[0��i]���������䡣
///		3. i++���ظ��ڶ���ֱ��i==n-1��������ɡ�
///
//////////////////////////////////////////////////////////////////////////////////////////////////
///		% �����㷨������������������� Ч�ʺܸ�
//////////////////////////////////////////////////////////////////////////////////////////////////

// ����  �� ���Ӵֱ������㷨
void InsertSort(int Array[], int nLength)
{
	for (int i = 1; i < nLength; ++i)
	{
		// ��������
		int nWaitInsert = Array[i];

		// ������������飨0 �� i-1��
		for (int j = 0; j <= i-1; ++j)
		{
			if (nWaitInsert > Array[j])
			{
				continue;
			} // �ҵ�һ�����ʵ�λ�ã�

			// Ȼ�󽫴�λ�ú������ �����ƶ�һλ
			for (int k = i; k > j; --k)
			{
				Array[k] = Array[k-1];
			}

			// �Ѵ���������� �ŵ����ʵ�λ��
			Array[j] = nWaitInsert;
			break;			
		}
	}
}

// �Ż��汾
void InsertSort2(int Array[], int nLength)
{
	for (int i = 1; i < nLength; ++i)
	{
		// ��������
		int nWaitInsert = Array[i];

		// ������������飨0 �� i-1��

		// ����λ��
		int nComparePos = i - 1;

		// ������λ�õ����ݱȽϣ������������������һλ��������nCoparePos��ߵ�ֵ���бȽ�
		while (nComparePos >=0 && nWaitInsert < Array[nComparePos])
		{
			Array[nComparePos+1] = Array[nComparePos];
			nComparePos = nComparePos -1;
		}
		Array[nComparePos+1] = nWaitInsert;

		//for (int j = 0; j <= i-1; ++j)
		//{
		//	if (nWaitInsert > Array[j])
		//	{
		//		continue;
		//	} // �ҵ�һ�����ʵ�λ�ã�

		//	// Ȼ�󽫴�λ�ú������ �����ƶ�һλ
		//	for (int k = i; k > j; --k)
		//	{
		//		Array[k] = Array[k-1];
		//	}

		//	// �Ѵ���������� �ŵ����ʵ�λ��
		//	Array[j] = nWaitInsert;
		//	break;			
		//}
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
	InsertSort2(arr,  ARRAY_LENGTH);
	cout << "��������ݣ�" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}
