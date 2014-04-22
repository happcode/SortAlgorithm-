// ShellSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define ARRAY_LENGTH 10
///////////////////////////////////////////////////////////////////////////////////////////
///
///		ϣ�����򣺾����Ż����ֱ�Ӳ�������
///		
///		������ֳ�n�飬��ÿ�����ݽ���ֱ������;
///		Ȼ�����������ֳ�n/2�� �ڽ���ֱ������ֱ��n/2 = 0
///
//////////////////////////////////////////////////////////////////////////////////////////

// 
void ShellSort(int Array[], int nLength)
{
	// ����  �ֶ��ٴ���
	for (int grap = nLength/2; grap > 0; grap /= 2)
	{
		// ���������飨ÿ����������ݵ�һ�����ݵ�Index��
		for (int i = 0; i < grap; ++i)
		{
			///////////////////////////////////////////////////////
			//													//
			//					ֱ�Ӳ�������					//
			//													//
			//////////////////////////////////////////////////////

			// ÿ�����ݣ��ӵڶ�����ʼȡ��Ȼ�����ǰ��������У�
			for (int j = i+grap; j < nLength; j+=grap)
			{
				// ��������
				int nWaitInsert = Array[j];
				int nComparePos = j-grap;

				while (nComparePos >= 0 && nWaitInsert < Array[nComparePos])
				{
					Array[nComparePos +grap] = Array[nComparePos];
					nComparePos = nComparePos - grap;
				}

				Array[nComparePos+grap] = nWaitInsert;
			}
		}
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
	ShellSort(arr,  ARRAY_LENGTH);
	cout << "��������ݣ�" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}

