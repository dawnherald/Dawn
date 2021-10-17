/*#ifndef _Queue_h
struct  QueueRecord;
typedef struct QueueRecord* Queue;
typedef int ElementType;

int Isempty(Queue Q);
int Isfull(Queue Q);
Queue CreatQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
#endif // !_Queue_h


#include<stdio.h>
#include"Queue.h"

#define MinQueueSize 10

struct QueueRecord
{
	int Capacity;//容量
	int Front;
	int Rear;
	int Size;//队列已经入队的规模
	ElementType* Array;
};

//判断是否为空
int
Isempty(Queue Q)
{
	return Q->Size == 0;
}
//判断是否满队列
Isfull(Queue Q)
{
	return Q->Size == Q->Capacity;

}
//制造一个空队列
Queue
CreatQueue(int MaxElements)
{
	Queue Q;
	if (MakeEmpty < MinQueueSize)
	{
		Error("Queue is too small");
	}
	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
		FatalError("Out of space");
	Q->Array = malloc(sizeof(ElementType) * MaxElements); //将malloc返回的内存空间地址转成(ElemType*)类型的然后赋值给Q
	if (Q->Array == NULL)
		FatalError("Out of space");
	Q->Capacity = MaxElements;
	MakeEmpty(Q);
}
//销毁队列
void
DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}
//让队列造空
void
MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
//连续起队列
static int
Succ(int Value, Queue Q)
{
	if (++Value == Q->Capacity)
		Value = 0;
	return Value;
}

void
Enqueue(ElementType X, Queue Q)
{
	if (Isfull(Q))
		Error("Full queue");
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}

}
//出列
void
Dequeue(Queue Q)
{
	if (Isempty(Q))
		Error("Empty Queue");
	else
	{
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);//实现队列的循环，如果front 或者Rear超过Capability，那么让它为0，回到队列开始
	}
}

//
ElementType Front(Queue Q)
{
	if (!Isempty(Q))
	{
		return Q->Array[Q->Front];
	}
	Error("empty queue");
	return 0;
}
//出队并且给front--
ElementType FrontAndQueue(Queue Q)
{
	ElementType X = 0;
	if (Isempty(Q))
		Error("Empty queue");
	else
	{
		Q->Size--;
		X = Q->Array[Q->Front];
		Q->Front = Succ(Q->Front, Q);
	}
	return X;
}*/
