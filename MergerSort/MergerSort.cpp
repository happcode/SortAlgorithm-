// MergerSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;

#define ARRAY_LENGTH 10


// ����������� ����
void PrintArray(int Array[], int nLength);
void ResetArray(int* SortArray);

/////////////////////////////////////////////////////////////////////////////////////////////
///
///		�鲢����
///		  1.�Ƚ�����ָ���������飬Ȼ���ٽ��ָ�ĸ��������ٷָ���������飬
///			ֱ�����鱻�ָ��ֻ��һ������Ϊֹ��
///			(��֮Ϊ�ݹ���飺��ʱÿ�����е�����Ϊ����״̬����Ϊֻ��һ������)
//		  2.Ȼ������ڵ����������������ϲ�,ֱ������
///
////////////////////////////////////////////////////////////////////////////////////////////

// �ϲ�������������
///////////////////////////////////////////////////////////////////////////////
///		����a[] = {2, 3, 4, 1}
///		���ָ�����ݷֱ�Ϊ 2 3 & 4 1 ���ĸ����飬Ȼ���������������ںϲ���
///		�ϲ���ɵ������飬�ٷŻص�ԭ�����ϲ������λ���С�///
///
void MergeAndSortArray(int Array[], int nFirst, int nMid, int nLast, int* SortArray)
{
	int i = nFirst;
	int j = nMid + 1;
	int k = 0;
	while (i <= nMid && j <= nLast)
	{
		// ����С�����ŵ��µ�������,����λ�ú���
		if (Array[i] < Array[j])
		{
			SortArray[k] = Array[i];
			++i;
		} else {
			SortArray[k] = Array[j];
			++j;
		}
		// ������Ĵ��λ��Ҳ����
		++k;
	}

	// ������ûȡ���������ʣ�µ��������µ������У���һ�����������Ѿ���ȡ��
	while (i <= nMid)
	{
		SortArray[k++] = Array[i++];
	}
	while (j <= nLast)
	{
		SortArray[k++] = Array[j++];
	}

	// �����������Ѿ��ź�������� ���뵽ԭ���������У�λ�ô�nFirst->nLast��
	for (int m = 0; m < k; ++m)
	{
		Array[nFirst + m] = SortArray[m];
	}

	PrintArray(SortArray, ARRAY_LENGTH);
	ResetArray(SortArray);
}

// �ݹ�ָ����飬ֱ��ÿ���������һ������Ϊֹ
void  DivideArray(int Array[], int nFirst, int nLast, int* SortArray)
{
	int nMid = (nFirst + nLast)/2;
	if (nFirst < nLast)
	{		
		DivideArray(Array, nFirst, nMid, SortArray);
		DivideArray(Array, nMid+1, nLast, SortArray);		
		MergeAndSortArray(Array, nFirst, nMid, nLast, SortArray);
	}	
}

// �鲢����
void MergeSort(int Array[], int nLength)
{
	int* SortArray = new int[nLength];
	ResetArray(SortArray);
	DivideArray(Array, 0, nLength - 1, SortArray);
	delete[] SortArray;
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

void ResetArray( int* SortArray ) 
{
	for (int i = 0; i < ARRAY_LENGTH;++i)
	{
		SortArray[i] = -1;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[ARRAY_LENGTH] = { 2, 9, 1, 5, 6, 8, 7, 3, 0, 11 };
	
	// 1.�����㷨1
	cout << "����ǰ���ݣ�" << endl;
	PrintArray(arr, ARRAY_LENGTH);
	MergeSort(arr,  ARRAY_LENGTH);
	cout << "��������ݣ�" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}

