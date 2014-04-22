// HeapSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
#define ARRAY_LENGTH 10

void PrintHeapArray(int Array[], int nLength);

//////////////////////////////////////////////////////////////////////////
//	二叉堆：
//		已排好序的堆，分为最大堆或最小堆
//		某个节点的左子节点为（2*i + 1)，右子节点为（2*i + 2）
//		堆是由数组来存储元素，有序的存储结构
//
//	以最小堆为例：
//
//		堆插入操作：
//			插入操作只能从最后位置插入
//		删除操作：
//			删除操作只能从第一个位置删除
//		堆排序操作：
//
//////////////////////////////////////////////////////////////////////////

// 堆插入操作,插入到最后位置，然后与父节点进行比较，交换元素，使其成为最大、小堆
// 类似于插入排序
void HeapInsert(int Array[], int nInsertPos)
{	
	int nInserValue = Array[nInsertPos];

	while (nInsertPos >= 1)
	{
		// 父节点
		int nComparePos = (nInsertPos - 1)/2;		
		
		// 比父节点小，则交换值，并保存新的位置；继续与父节点比较
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

// 将某个数据下沉操作
void DataFixDown(int Array[], int nLength, int nPos)
{
	int nTemp = Array[nPos];

	// zuo子节点
	int nLeftPos = 2*nPos+1;
	// 找出子节点中较小的值
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

		// 子节点都比自己打
		if (Array[nMinPos] >= nTemp)
		{
			break;
		}

		// 交换值
		Array[nPos] = Array[nMinPos];
		Array[nMinPos] = nTemp;
		nPos = nMinPos;

		// 左子节点
		nLeftPos = 2*nPos + 1;
	}
}

// 堆删除操作,将最后位置的元素放到第一个位置。然后与子点进行比较，交换元素，使其成为最大、小堆
void HeapDelete(int Array[], int nLength)
{	
	// 将最后的值放到第一个位置
	Array[0] = Array[nLength-1];
	nLength = nLength-2;
	// 将数据下沉
	DataFixDown(Array, nLength, 0);
}


// 将数组堆化（即使其成为最大、最小堆）
//////////////////////////////////////////////////////////////////////////
//	将每个父节点做调整（最大最小）即可
//	父节点个数 = n/2 -1
/////////////////////////////////////////////////////////////////////////
void Heaplize(int Array[], int nLength)
{
	for (int i = nLength/2-1; i >= 0; i--)
	{
		DataFixDown(Array, nLength, i);
	}
}

// 堆排序
//////////////////////////////////////////////////////////////////////////
//	堆化后，第一个元素始终是最大或最小值，
//	然后我们取出（删除）第一个值，然后再将堆重构堆化，则地一个元素又是最大或者最小的那个值
//	重复取出（删除）操作，直到元素只有一个时，堆排序就完成了
/////////////////////////////////////////////////////////////////////////
void HeapSort(int Array[], int nLength)
{
	// 先堆化数组
	Heaplize(Array, nLength);
	PrintHeapArray(Array, nLength);

	// 堆排序
	int nTemp;
	for (int i = nLength; i >= 1; i--)
	{		
		// 将0（最小值）和和n（最后的元素）交换位置，然后再对[0，n-1]进行元素下沉操作，然后重复
		nTemp = Array[i-1];
		Array[i-1] = Array[0];
		Array[0] = nTemp;

		DataFixDown(Array, i-1, 0);
	}
	cout << "堆排序操作：" << endl;
	PrintHeapArray(Array, nLength);
}

// 先输出自己，再输左子节点，再输出右子节点
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

	// 堆增加元素
	HeapInsert(arr, 7);
	PrintHeapArray(arr, 8);
	
	// 堆删除元素
	int arr2[ARRAY_LENGTH] = { 2, 4, 6, 5, 8, 7, 11, 20 };
	HeapDelete(arr2, 8);
	cout << endl;
	PrintHeapArray(arr2, 7);

	// 堆化，堆排序
	int arr3[ARRAY_LENGTH] = { 7, 4, 2, 3, 8, 1, 5, 11, 6, 20};
	HeapSort(arr3, ARRAY_LENGTH);

	system("pause");
	return 0;
}

