// MergerSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;

#define ARRAY_LENGTH 10


// 输出数组数据 声明
void PrintArray(int Array[], int nLength);
void ResetArray(int* SortArray);

/////////////////////////////////////////////////////////////////////////////////////////////
///
///		归并排序：
///		  1.先将数组分割成两个数组，然后再将分割的各个数组再分割成两个数组，
///			直到分组被分割成只有一个数据为止。
///			(称之为递归分组：这时每个组中的数据为有序状态，因为只有一个数据)
//		  2.然后对相邻的两个数组进行排序合并,直至结束
///
////////////////////////////////////////////////////////////////////////////////////////////

// 合并两个有序数组
///////////////////////////////////////////////////////////////////////////////
///		数组a[] = {2, 3, 4, 1}
///		被分割成数据分别为 2 3 & 4 1 的四个数组，然后数组再两两相邻合并，
///		合并组成的新数组，再放回到原两个合并数组的位置中。///
///
void MergeAndSortArray(int Array[], int nFirst, int nMid, int nLast, int* SortArray)
{
	int i = nFirst;
	int j = nMid + 1;
	int k = 0;
	while (i <= nMid && j <= nLast)
	{
		// 将较小的数放到新的数组中,并将位置后移
		if (Array[i] < Array[j])
		{
			SortArray[k] = Array[i];
			++i;
		} else {
			SortArray[k] = Array[j];
			++j;
		}
		// 新数组的存放位置也后移
		++k;
	}

	// 将数据没取完的数组中剩下的数放入新的数组中，另一个数组数据已经被取完
	while (i <= nMid)
	{
		SortArray[k++] = Array[i++];
	}
	while (j <= nLast)
	{
		SortArray[k++] = Array[j++];
	}

	// 将新数组中已经排好序的数据 放入到原来旧数组中（位置从nFirst->nLast）
	for (int m = 0; m < k; ++m)
	{
		Array[nFirst + m] = SortArray[m];
	}

	PrintArray(SortArray, ARRAY_LENGTH);
	ResetArray(SortArray);
}

// 递归分割数组，直到每个数组包含一个数据为止
void  DivideArray(int Array[], int nFirst, int nLast, int* SortArray)
{
	int nMid = (nFirst + nLast)/2;
	if (nFirst < nLast)
	{		
		DivideArray(Array, nFirst, nMid, SortArray);
		DivideArray(Array, nMid+1, nLast, SortArray);		
		MergeAndSortArray(Array, nFirst, nMid, nLast, SortArray);
	}	
}

// 归并排序
void MergeSort(int Array[], int nLength)
{
	int* SortArray = new int[nLength];
	ResetArray(SortArray);
	DivideArray(Array, 0, nLength - 1, SortArray);
	delete[] SortArray;
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

void ResetArray( int* SortArray ) 
{
	for (int i = 0; i < ARRAY_LENGTH;++i)
	{
		SortArray[i] = -1;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[ARRAY_LENGTH] = { 2, 9, 1, 5, 6, 8, 7, 3, 0, 11 };
	
	// 1.排序算法1
	cout << "排序前数据：" << endl;
	PrintArray(arr, ARRAY_LENGTH);
	MergeSort(arr,  ARRAY_LENGTH);
	cout << "排序后数据：" << endl;
	PrintArray(arr, ARRAY_LENGTH);	

	system("pause");
	return 0;
}

