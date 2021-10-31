#pragma once
typedef int ELementType;

#include<stdio.h>
#include<stdlib.h>

#ifndef _MErgeSort_
void Msort(ELementType A[], ELementType TmpArray[], int Left, int Right);
void MergeSort(ELementType A[], int N);
void Merge(ELementType A[], ELementType TmpArray[], int Lpos, int Rpos, int RightEnd); 
#endif // !_MErgeSort_

#include"QuickSort.h"
#include"InsertSort.h"
#include"HeapSort.h"

void
QuickSort(ElementType A[], int N)
{
	Qsort(A, 0, N - 1);
}
 
ElementType
Median3(ElementType A[], int Left, int Right)
{
	int center;
	center = (Left + Right) / 2;
	if (A[Left] > A[center])
		Swap(&A[Left], &A[center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[center] > A[Right])
		Swap(&A[center],&A[Right]);//将left，right，center按大小升序

	Swap(&A[center],&A[Right-1]);//将right-1位置元素与center位置元素交换，center位置元素就是pivot，所以right位置元素一定是大于pivot的
								//right-1位置的元素未知与pivot的大小，所以交换到center位置
	return A[Right - 1];
}

 
void
Qsort(ElementType A[], int Left, int Right)
{
	int i, j;
	ElementType Pivot;

	if (Left + Cutoff <= Right)
	{
		Pivot = Median3(A, Left, Right);
		i = Left, j = Right - 1;
		for (;;)
		{
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			if (i < j)
				Swap(&A[i], &A[j]);//此时的i，j对应的位置刚好就是需要交换的点；
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);//这个位置很有趣，i位置恰好是大于pivot的点，现在与right-1位置（pivot）交换以后，i位置就是（pivot），而right-1位置就是大于pivot的点了
		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}		
	//简而言之交换以后，i位置左边全小于Pivot，右边全大于pivot；
	else

		InsertionSort(A + Left, Right - Left + 1);//A+left是指数组A+Left的位置；当数组内元素过小了，利用插入排序；
	
}
void//查找第K个最小元
Qselect(ElementType A[], int k, int Left, int Right)
{
	
	int i, j;
	ElementType Pivot;

	if (Left + Cutoff <= Right)
	{
		Pivot = Median3(A, Left, Right);
		i = Left, j = Right - 1;
		for (;;)
		{
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			if (i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);
		if (k <= i)
			Qselect(A, k, Left, i - 1);
		else
			if (k > i + 1)
				Qselect(A, k, i + 1, Right);
		//如果K=i+1，那么程序终止，代表已经找到；
	}
	else
		InsertionSort(A + Left, Right - Left + 1);


}
