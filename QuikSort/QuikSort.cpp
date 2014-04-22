// QuikSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;

#define ARRAY_LENGTH 10

// ����������� ����
void PrintArray(int Array[], int nLength);

//////////////////////////////////////////////////////////////////////////////////////////
//
//	�������򣺣��ڿ� ��䷨��
//		1.ȡ�������е�һ������Ϊ��׼����i=0,�����СΪn,beforePos = i,afterPos = n-1
//
//		2.Ȼ�������afterPosλ�ÿ�ʼ�ҳ�һ���ȡ���׼����С������
//			�ŵ�beforePosλ�ã���ʱ��ǰ���λ�õ����Ϳ��ˣ���¼�¸�λ��afterPos.
//		
//		3.Ȼ�������beforePosλ�ÿ�ʼ�ҳ�һ���ȡ���׼�����������
//			�ŵ�afterPosλ�ã���ʱ��ǰ���λ�õ����Ϳ��ˣ���¼�¸�λ��beforePos.
//		
//		4.�ظ�2��3���裬ֱ��beforePos == afterPos����¼�����λ��pos
//		
//		5.��[0,pos),(pos, n]���������зֱ���� 1��2��3��4������ֱ��ÿ�������е�Ԫ�ظ���Ϊ1ʱ���������
//
/////////////////////////////////////////////////////////////////////////////////////////

void Adjust(int Array[], int nStart, int nEnd)
{
	if (nStart >= nEnd)
	{
		return;
	}

	// ��׼��
	int nMidValue = Array[nStart];
	// ǰ���׼λ��
	int nBeforePos = nStart;
	int nAfterPos = nEnd;

	while (nAfterPos != nBeforePos)
	{
		// ���������ұȻ�׼��С��������������ֵ
		while (nAfterPos != nBeforePos)
		{
			if (Array[nAfterPos] < nMidValue)
			{
				Array[nBeforePos] = Array[nAfterPos];
				++nBeforePos;
				break;
			}
			--nAfterPos;
		}

		// ������ǰ���ұȻ�׼�����������������ֵ
		while (nBeforePos != nAfterPos)
		{
			if (Array[nBeforePos] > nMidValue)
			{
				Array[nAfterPos] = Array[nBeforePos];
				--nAfterPos;
				break;
			}
			++nBeforePos;
		}
	}

	// �ѻ�׼���ŵ����ʵ�λ�ã���������Լ�С���ұ������Լ���
	Array[nBeforePos] = nMidValue;
	PrintArray(Array, ARRAY_LENGTH);

	// �������Ի�׼λ�÷ָ�����ݣ��ظ����ϲ���
	Adjust(Array, nStart, nBeforePos-1);
	Adjust(Array, nBeforePos+1, nEnd-1);
}

// ���������㷨
void QuikSort(int Array[], int nLength)
{
	Adjust(Array, 0, nLength-1);
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
	QuikSort(arr,  ARRAY_LENGTH);
	cout << "��������ݣ�" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}

