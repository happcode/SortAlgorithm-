// ShellSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define ARRAY_LENGTH 10
///////////////////////////////////////////////////////////////////////////////////////////
///
///		希尔排序：就是优化版的直接插入排序
///		
///		将数组分成n组，对每组数据进行直接排序;
///		然后继续将数组分成n/2组 在进行直接排序；直到n/2 = 0
///
//////////////////////////////////////////////////////////////////////////////////////////

// 
void ShellSort(int Array[], int nLength)
{
	// 步长  分多少次组
	for (int grap = nLength/2; grap > 0; grap /= 2)
	{
		// 多少组数组（每组数组的数据第一个数据的Index）
		for (int i = 0; i < grap; ++i)
		{
			///////////////////////////////////////////////////////
			//													//
			//					直接插入排序					//
			//													//
			//////////////////////////////////////////////////////

			// 每组数据（从第二个开始取，然后插入前面的序列中）
			for (int j = i+grap; j < nLength; j+=grap)
			{
				// 待插入数
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
	ShellSort(arr,  ARRAY_LENGTH);
	cout << "排序后数据：" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}

