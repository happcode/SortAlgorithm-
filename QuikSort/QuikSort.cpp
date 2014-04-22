// QuikSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;

#define ARRAY_LENGTH 10

// 输出数组数据 声明
void PrintArray(int Array[], int nLength);

//////////////////////////////////////////////////////////////////////////////////////////
//
//	快速排序：（挖坑 填充法）
//		1.取出数组中第一个数作为基准数。i=0,数组大小为n,beforePos = i,afterPos = n-1
//
//		2.然后从数组afterPos位置开始找出一个比“基准数”小的数，
//			放到beforePos位置，这时当前这个位置的数就空了，记录下该位置afterPos.
//		
//		3.然后从数组beforePos位置开始找出一个比“基准数”大的数，
//			放到afterPos位置，这时当前这个位置的数就空了，记录下该位置beforePos.
//		
//		4.重复2、3步骤，直到beforePos == afterPos，记录下这个位置pos
//		
//		5.在[0,pos),(pos, n]两个数组中分别进行 1、2、3、4操作。直到每个数组中的元素个数为1时，排序完成
//
/////////////////////////////////////////////////////////////////////////////////////////

void Adjust(int Array[], int nStart, int nEnd)
{
	if (nStart >= nEnd)
	{
		return;
	}

	// 基准数
	int nMidValue = Array[nStart];
	// 前后基准位置
	int nBeforePos = nStart;
	int nAfterPos = nEnd;

	while (nAfterPos != nBeforePos)
	{
		// 从数组后查找比基准数小的数，并交换赋值
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

		// 从数组前查找比基准数大的数，并交换赋值
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

	// 把基准数放到合适的位置（左边数比自己小，右边数比自己大）
	Array[nBeforePos] = nMidValue;
	PrintArray(Array, ARRAY_LENGTH);

	// 将数组以基准位置分割成两份，重复以上步骤
	Adjust(Array, nStart, nBeforePos-1);
	Adjust(Array, nBeforePos+1, nEnd-1);
}

// 快速排序算法
void QuikSort(int Array[], int nLength)
{
	Adjust(Array, 0, nLength-1);
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
	QuikSort(arr,  ARRAY_LENGTH);
	cout << "排序后数据：" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}

