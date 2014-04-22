// HeapSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;
#define ARRAY_LENGTH 10

void PrintHeapArray(int Array[], int nLength);

//////////////////////////////////////////////////////////////////////////
//	����ѣ�
//		���ź���Ķѣ���Ϊ���ѻ���С��
//		ĳ���ڵ�����ӽڵ�Ϊ��2*i + 1)�����ӽڵ�Ϊ��2*i + 2��
//		�������������洢Ԫ�أ�����Ĵ洢�ṹ
//
//	����С��Ϊ����
//
//		�Ѳ��������
//			�������ֻ�ܴ����λ�ò���
//		ɾ��������
//			ɾ������ֻ�ܴӵ�һ��λ��ɾ��
//		�����������
//
//////////////////////////////////////////////////////////////////////////

// �Ѳ������,���뵽���λ�ã�Ȼ���븸�ڵ���бȽϣ�����Ԫ�أ�ʹ���Ϊ���С��
// �����ڲ�������
void HeapInsert(int Array[], int nInsertPos)
{	
	int nInserValue = Array[nInsertPos];

	while (nInsertPos >= 1)
	{
		// ���ڵ�
		int nComparePos = (nInsertPos - 1)/2;		
		
		// �ȸ��ڵ�С���򽻻�ֵ���������µ�λ�ã������븸�ڵ�Ƚ�
		if (nInserValue < Array[nComparePos])
		{
			Array[nInsertPos] = Array[nComparePos];
			Array[nComparePos] = nInserValue;
			nInsertPos = nComparePos;
			continue;
		}
		break;
	}
}

// ��ĳ�������³�����
void DataFixDown(int Array[], int nLength, int nPos)
{
	int nTemp = Array[nPos];

	// zuo�ӽڵ�
	int nLeftPos = 2*nPos+1;
	// �ҳ��ӽڵ��н�С��ֵ
	int nMinPos = 0;

	while (nLeftPos < nLength)
	{
		if (nLeftPos+1 < nLength && (Array[nLeftPos] > Array[nLeftPos+1]))
		{			
			nMinPos = nLeftPos+1;
		} 
		else 
		{			
			nMinPos = nLeftPos;
		}

		// �ӽڵ㶼���Լ���
		if (Array[nMinPos] >= nTemp)
		{
			break;
		}

		// ����ֵ
		Array[nPos] = Array[nMinPos];
		Array[nMinPos] = nTemp;
		nPos = nMinPos;

		// ���ӽڵ�
		nLeftPos = 2*nPos + 1;
	}
}

// ��ɾ������,�����λ�õ�Ԫ�طŵ���һ��λ�á�Ȼ�����ӵ���бȽϣ�����Ԫ�أ�ʹ���Ϊ���С��
void HeapDelete(int Array[], int nLength)
{	
	// ������ֵ�ŵ���һ��λ��
	Array[0] = Array[nLength-1];
	nLength = nLength-2;
	// �������³�
	DataFixDown(Array, nLength, 0);
}


// ������ѻ�����ʹ���Ϊ�����С�ѣ�
//////////////////////////////////////////////////////////////////////////
//	��ÿ�����ڵ��������������С������
//	���ڵ���� = n/2 -1
/////////////////////////////////////////////////////////////////////////
void Heaplize(int Array[], int nLength)
{
	for (int i = nLength/2-1; i >= 0; i--)
	{
		DataFixDown(Array, nLength, i);
	}
}

// ������
//////////////////////////////////////////////////////////////////////////
//	�ѻ��󣬵�һ��Ԫ��ʼ����������Сֵ��
//	Ȼ������ȡ����ɾ������һ��ֵ��Ȼ���ٽ����ع��ѻ������һ��Ԫ��������������С���Ǹ�ֵ
//	�ظ�ȡ����ɾ����������ֱ��Ԫ��ֻ��һ��ʱ��������������
/////////////////////////////////////////////////////////////////////////
void HeapSort(int Array[], int nLength)
{
	// �ȶѻ�����
	Heaplize(Array, nLength);
	PrintHeapArray(Array, nLength);

	// ������
	int nTemp;
	for (int i = nLength; i >= 1; i--)
	{		
		// ��0����Сֵ���ͺ�n������Ԫ�أ�����λ�ã�Ȼ���ٶ�[0��n-1]����Ԫ���³�������Ȼ���ظ�
		nTemp = Array[i-1];
		Array[i-1] = Array[0];
		Array[0] = nTemp;

		DataFixDown(Array, i-1, 0);
	}
	cout << "�����������" << endl;
	PrintHeapArray(Array, nLength);
}

// ������Լ����������ӽڵ㣬��������ӽڵ�
void PrintHeapArray(int Array[], int nLength)
{	
	for (int k = 0; k < nLength; k++)
	{
		cout << Array[k] << ", ";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[ARRAY_LENGTH] = { 2, 4, 6, 5, 8, 7, 11, 3 };

	// ������Ԫ��
	HeapInsert(arr, 7);
	PrintHeapArray(arr, 8);
	
	// ��ɾ��Ԫ��
	int arr2[ARRAY_LENGTH] = { 2, 4, 6, 5, 8, 7, 11, 20 };
	HeapDelete(arr2, 8);
	cout << endl;
	PrintHeapArray(arr2, 7);

	// �ѻ���������
	int arr3[ARRAY_LENGTH] = { 7, 4, 2, 3, 8, 1, 5, 11, 6, 20};
	HeapSort(arr3, ARRAY_LENGTH);

	system("pause");
	return 0;
}

