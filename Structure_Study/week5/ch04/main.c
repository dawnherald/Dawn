#pragma once
typedef int ElemenType;

#include<stdio.h>
#define LeftChild(i)(2*(i)+1)
#ifndef _HeapSort_
void PerDown(ElemenType A[], int i, int N);
void HeapSort(ElemenType A[],int N);
void Swap(int* p1, int* p2);
#endif // !_HeapSort_
#include"HeapSort.h"
void 
PerDown(ElemenType A[], int i, int N)
{
	int Child;
	ElemenType Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child] < A[Child + 1])//判断左右儿子最大值；
			Child++;
		if (A[Child] > Tmp)
			A[i] = A[Child];//如果儿子比父亲大，那么把儿子的最大值给父亲；
		else
			break;
	}
	A[i] = Tmp;//如果上面产生交换，或者说是，多次交换，那么把父亲最开始的那个较小值给最后与之交换的结点
}



void 
HeapSort(ElemenType A[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)
		PerDown(A, i, N);//先建立一颗堆序树
	for (i = N - 1; i >= 0; i--)
	{
		Swap(&A[0], &A[i]);
		PerDown(A, 0, i);//删除根节点最大值（把根节点放在树的末尾），这样会对堆序树产生破环，所以需要二次恢复堆序树
	}
}
void
Swap(int* p1, int* p2)
{
	int* Turn;
	Turn = p1;
	p1 = p2;
	p2 = Turn;
}
