// InsertSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define ARRAY_LENGTH 10

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///		直接插入排序：
///		假设array[0]是一个已排序的区间，然后将array[1]直接插入array[0]这个区间。
///		然后依次将后面的每一个数插入前面已经排好的序列中。
///
///		设数组为a[0…n-1]。
///		1. 初始时，a[0]自成1个有序区，无序区为a[1..n-1]。令i=1
///		2. 将a[i]并入当前的有序区a[0…i-1]中形成a[0…i]的有序区间。
///		3. i++并重复第二步直到i==n-1。排序完成。
///
//////////////////////////////////////////////////////////////////////////////////////////////////
///		% 这种算法在数组基本有序的情况下 效率很高
//////////////////////////////////////////////////////////////////////////////////////////////////

// 升序  ： 复杂粗暴翻译算法
void InsertSort(int Array[], int nLength)
{
	for (int i = 1; i < nLength; ++i)
	{
		// 待插入数
		int nWaitInsert = Array[i];

		// 待被插入的数组（0 到 i-1）
		for (int j = 0; j <= i-1; ++j)
		{
			if (nWaitInsert > Array[j])
			{
				continue;
			} // 找到一个合适的位置，

			// 然后将此位置后的数组 往后移动一位
			for (int k = i; k > j; --k)
			{
				Array[k] = Array[k-1];
			}

			// 把待插入的数据 放到合适的位置
			Array[j] = nWaitInsert;
			break;			
		}
	}
}

// 优化版本
void InsertSort2(int Array[], int nLength)
{
	for (int i = 1; i < nLength; ++i)
	{
		// 待插入数
		int nWaitInsert = Array[i];

		// 待被插入的数组（0 到 i-1）

		// 相邻位置
		int nComparePos = i - 1;

		// 与相邻位置的数据比较，符合则将这个数据右移一位，继续与nCoparePos左边的值进行比较
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
		//	} // 找到一个合适的位置，

		//	// 然后将此位置后的数组 往后移动一位
		//	for (int k = i; k > j; --k)
		//	{
		//		Array[k] = Array[k-1];
		//	}

		//	// 把待插入的数据 放到合适的位置
		//	Array[j] = nWaitInsert;
		//	break;			
		//}
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
	InsertSort2(arr,  ARRAY_LENGTH);
	cout << "排序后数据：" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}
