// SelectSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define ARRAY_LENGTH 10
//////////////////////////////////////////////////////////////////////////////////////////////
///
//		选择排序算法：
//			在数组中选择最小或者最大的一个数，与第i（i=0）个数交换，
//			然后在数组中的从第二个数到最后的区间中再找 最小或者最大的数与
//			第i++个数交换，直到最后一个数
//
////////////////////////////////////////////////////////////////////////////////////////////


void Swap(int& nFirst, int& nSecond)
{
	// 1.
	//int nTemp = nFirst;
	//nFirst = nSecond;
	//nSecond = nTemp;

	// 2.如果连个数据相等，进行异或操作会导致数据变为0
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
		// 每次找出最小值
		for(int j = i+1; j < nLength; ++j)
		{			
			if (Array[j] < Array[nMinPos])
			{				
				nMinPos = j;
			}
		}
		// 交换
		Swap(Array[i], Array[nMinPos]);
	}
}

// 输出数组数据
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
	
	// 1.排序算法1
	cout << "排序前数据：" << endl;
	PrintArray(arr, ARRAY_LENGTH);
	SelectSort(arr,  ARRAY_LENGTH);
	cout << "排序后数据：" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}

