#pragma once
#define MinPQSize 10
#include<stdio.h>
#include<stdlib.h>
#ifndef _BinHeap_H
#define MinData 0
struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(int MaxElement);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
ElementType Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
 
 

#endif // !_BinHeap_H

struct  HeapStruct
{
	int Capacity;
	int Size;
	ElementType* Element;
};
#include"BinHeap.h"
PriorityQueue
Initialize(int MaxElements)//先申请空间,在对结构体里面数据或指针初始化
{
	PriorityQueue H;
	if (MaxElements < MinPQSize)
	{
		printf("Priority queue is too small");
		return 0;
	}
	H = (HeapStruct*)malloc(sizeof(struct HeapStruct));      //
	if (H == NULL)
	{
		printf("Priority queue is too small");
		exit(0);
	}
	H->Element = (ElementType*)malloc(sizeof(ElementType) * (MaxElements + 1));        //
	if (H->Element == NULL)
	{
		printf("Priority queue is too small");
		exit(0);
	}
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Element[0] = MinData;

	return H;


}

//利用上滤进行插入,空穴点既是当前点位置i;右儿子为2i,父亲为i/2;

ElementType
Insert(ElementType X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		printf("Priority queue is fulll ");
		return NULL;
	}
	for (i = ++H->Size; H->Element[i / 2] > X; i /= 2)
		H->Element[i] = H->Element[i / 2];
	H->Element[i] = X;
}

//删除最小根节点后,利用下滤(把空穴左右最小儿子放入空穴,进而让空穴往下一层走)
ElementType
DeleMin(PriorityQueue H)
{
	int i, child;//i代表此刻的空穴,child代表空穴的儿子,最开始是左儿子
	ElementType MinElement, LastElement;

	if (IsEmpty)
	{
		printf("Priority queue is empty");
		return H->Element[0];
	}
	MinElement = H->Element[1];
	LastElement = H->Element[H->Size--];//--代表优先队列Size减1;

	for (i = 1; i * 2 <= H->Size; i = child)
	{
		child = 2 * i;
		if (child != H->Size && H->Element[child] > H->Element[child + 1])//这里实现找出最小儿子树进行下滤,并且如果child到了最优队列的Size就不要在++,不然会溢出
			child++;
		if (LastElement > H->Element[child])//判断最后的元素如果大于空穴的儿子,那么空穴继续下移,如果不是,那么这个点就是应该插入的点就break
			H->Element[i] = H->Element[child];
		else
			break;
		H->Element[i] = LastElement;//这里的空穴应该插入最后的元素
		return MinElement;
	}
}

int
IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}

int
IsFull(PriorityQueue H)
{
	return H->Size == H->Capacity - 1;
}

void
MakeEmpty(PriorityQueue H)
{
	H->Size = 0;//懒惰删除
}

ElementType
FindMin(PriorityQueue H)
{
	return H->Element[0];

}

void Destory(PriorityQueue H)
{
	free(H->Element);
	free(H);
}
