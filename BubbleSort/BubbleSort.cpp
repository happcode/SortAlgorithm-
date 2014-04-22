// BubbleSort.cpp : 定义控制台应用程序的入口点。
//


///////////////////////////////////////////////////////////////////////////////////////////////
////      设数组长度为N。

////      1．比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交换。

////      2．这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就“沉”到数组第N-1个位置。

////      3．N=N-1，如果N不为0就重复前面二步，否则排序完成。
///////////////////////////////////////////////////////////////////////////////////////////////////////
///			冒泡排序效率底下，只适用于小规模数组；大规模数据还是作罢吧！
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>

using namespace std;

#define ARRAY_LENGTH 10

// 冒泡排序 升序

/////////////////////////////////////////////////////////////////////
/// 最直接粗暴 效率最低的排序方法
////////////////////////////////////////////////////////////////////
void BubbleSort(int Array[], int nLength) 
{
	// 进行多少轮排序
	for(int j = 1; j <= nLength; ++j) 
	{
		// 每轮所有的数据进行比较(每轮减少最后一个数)
		for(int i = 0; i < nLength - j; ++i)
		{
			if (Array[i] > Array[i+1])
			{
				// 数据交换
				int nTemp = Array[i];
				Array[i] = Array[i+1];
				Array[i+1] = nTemp; 
			}
		}
	}
}

//////////////////////////////////////////////////////////////////
//	设置一个标志，如果有一趟没有发生交换，说明排序已经完成。
//  如果这一趟发生了交换,说明排序还得继续。
//  即考虑到某种特殊情况的数组（例如已经是全部排好序的数组，就不用进行排序了）
///////////////////////////////////////////////////////////////////
void BubbleSortSpecial(int Array[], int nLength)
{
	// 排序轮次
	for (int i = 1; i <= nLength; ++i) 
	{
		bool bSwitched = false;
		for (int j = 0; j < nLength - i; ++j)
		{
			if (Array[j] > Array[j+1])
			{
				// 发生交换了，说明数组排序还未完全完成
				bSwitched = true;
				int nTemp = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] = nTemp;
			}
		}

		// 出现一次都未交换的情况，直接退出
		if (!bSwitched) 
		{
			return;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
///		考虑到一种更为特殊的情况：
///		数组 后半段的数据 是‘有序’而且‘都大于’前半段的数据。
///		这里需要记录 这一轮移动的数据 最后被安插的位置 （3 5 2 7 8 9）
///////////////////////////////////////////////////////////////////////
void BubbleSortSepcialTwo(int Array[], int nLength)
{
	int nMovePos = nLength;
	// 排序轮次
	for (int i = 1; i <= nMovePos; ++i)
	{		
		bool bSwitched = false;
		// 只排序之前的数据（nMovePos - i）
		for (int j = 0; j < nMovePos - 1; ++j)
		{			
			if (Array[j] > Array[j+1])
			{
				// 发生交换了，数据位置移动了(最后一次移动到的位置，一下次就只排序这之前的数据)
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
	BubbleSort(arr,  ARRAY_LENGTH);
	cout << "排序后数据：" << endl;
	PrintArray(arr, ARRAY_LENGTH);

	int arr2[ARRAY_LENGTH] = { 2, 9, 1, 5, 6, 8, 7, 3, 0, 11 };
	// 2.排序算法2(考虑特殊情况)
	cout << "排序前数据：" << endl;
	PrintArray(arr2, ARRAY_LENGTH);
	BubbleSort(arr2,  ARRAY_LENGTH);
	cout << "排序后数据：" << endl;
	PrintArray(arr2, ARRAY_LENGTH);


	int arr3[ARRAY_LENGTH] = { 2, 9, 1, 5, 6, 8, 7, 3, 0, 11 };
	// 3.排序算法3(考虑极为特殊情况，算法向上兼容)
	cout << "排序前数据：" << endl;
	PrintArray(arr3, ARRAY_LENGTH);
	BubbleSort(arr3,  ARRAY_LENGTH);
	cout << "排序后数据：" << endl;
	PrintArray(arr3, ARRAY_LENGTH);

	system("pause");
	return 0;
}

