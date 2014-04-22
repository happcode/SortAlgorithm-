// BubbleSort.cpp : �������̨Ӧ�ó������ڵ㡣
//


///////////////////////////////////////////////////////////////////////////////////////////////
////      �����鳤��ΪN��

////      1���Ƚ����ڵ�ǰ��������ݣ����ǰ�����ݴ��ں�������ݣ��ͽ��������ݽ�����

////      2������������ĵ�0�����ݵ�N-1�����ݽ���һ�α���������һ�����ݾ͡������������N-1��λ�á�

////      3��N=N-1�����N��Ϊ0���ظ�ǰ�����������������ɡ�
///////////////////////////////////////////////////////////////////////////////////////////////////////
///			ð������Ч�ʵ��£�ֻ������С��ģ���飻���ģ���ݻ������հɣ�
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>

using namespace std;

#define ARRAY_LENGTH 10

// ð������ ����

/////////////////////////////////////////////////////////////////////
/// ��ֱ�Ӵֱ� Ч����͵����򷽷�
////////////////////////////////////////////////////////////////////
void BubbleSort(int Array[], int nLength) 
{
	// ���ж���������
	for(int j = 1; j <= nLength; ++j) 
	{
		// ÿ�����е����ݽ��бȽ�(ÿ�ּ������һ����)
		for(int i = 0; i < nLength - j; ++i)
		{
			if (Array[i] > Array[i+1])
			{
				// ���ݽ���
				int nTemp = Array[i];
				Array[i] = Array[i+1];
				Array[i+1] = nTemp; 
			}
		}
	}
}

//////////////////////////////////////////////////////////////////
//	����һ����־�������һ��û�з���������˵�������Ѿ���ɡ�
//  �����һ�˷����˽���,˵�����򻹵ü�����
//  �����ǵ�ĳ��������������飨�����Ѿ���ȫ���ź�������飬�Ͳ��ý��������ˣ�
///////////////////////////////////////////////////////////////////
void BubbleSortSpecial(int Array[], int nLength)
{
	// �����ִ�
	for (int i = 1; i <= nLength; ++i) 
	{
		bool bSwitched = false;
		for (int j = 0; j < nLength - i; ++j)
		{
			if (Array[j] > Array[j+1])
			{
				// ���������ˣ�˵����������δ��ȫ���
				bSwitched = true;
				int nTemp = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] = nTemp;
			}
		}

		// ����һ�ζ�δ�����������ֱ���˳�
		if (!bSwitched) 
		{
			return;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
///		���ǵ�һ�ָ�Ϊ����������
///		���� ���ε����� �ǡ����򡯶��ҡ������ڡ�ǰ��ε����ݡ�
///		������Ҫ��¼ ��һ���ƶ������� ��󱻰����λ�� ��3 5 2 7 8 9��
///////////////////////////////////////////////////////////////////////
void BubbleSortSepcialTwo(int Array[], int nLength)
{
	int nMovePos = nLength;
	// �����ִ�
	for (int i = 1; i <= nMovePos; ++i)
	{		
		bool bSwitched = false;
		// ֻ����֮ǰ�����ݣ�nMovePos - i��
		for (int j = 0; j < nMovePos - 1; ++j)
		{			
			if (Array[j] > Array[j+1])
			{
				// ���������ˣ�����λ���ƶ���(���һ���ƶ�����λ�ã�һ�´ξ�ֻ������֮ǰ������)
				nMovePos = j;
				bSwitched = false;
				int nTemp = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] = nTemp;
			}
		}

		if (!bSwitched)
		{
			return;
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
	BubbleSort(arr,  ARRAY_LENGTH);
	cout << "��������ݣ�" << endl;
	PrintArray(arr, ARRAY_LENGTH);

	int arr2[ARRAY_LENGTH] = { 2, 9, 1, 5, 6, 8, 7, 3, 0, 11 };
	// 2.�����㷨2(�����������)
	cout << "����ǰ���ݣ�" << endl;
	PrintArray(arr2, ARRAY_LENGTH);
	BubbleSort(arr2,  ARRAY_LENGTH);
	cout << "��������ݣ�" << endl;
	PrintArray(arr2, ARRAY_LENGTH);


	int arr3[ARRAY_LENGTH] = { 2, 9, 1, 5, 6, 8, 7, 3, 0, 11 };
	// 3.�����㷨3(���Ǽ�Ϊ����������㷨���ϼ���)
	cout << "����ǰ���ݣ�" << endl;
	PrintArray(arr3, ARRAY_LENGTH);
	BubbleSort(arr3,  ARRAY_LENGTH);
	cout << "��������ݣ�" << endl;
	PrintArray(arr3, ARRAY_LENGTH);

	system("pause");
	return 0;
}

