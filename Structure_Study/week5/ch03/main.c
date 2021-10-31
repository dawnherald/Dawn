#define MinPQSize 10
#include<stdio.h>
#include<stdlib.h>
#ifndef _LeftHeap_H
typedef int ElementType;
struct TreeNode;
typedef struct TreeNode* PriorityQueue;

PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);

#define Insert(X,H)(H=Insert1((X),H)

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
PriorityQueue SwapChildren(PriorityQueue H1);
#endif // !_LeftHeap_H
struct TreeNode
{
	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;
};

#include"LeftHeap.h"
//合并的驱动程序
PriorityQueue
Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
		return H2;
	if (H2 = NULL)
		return H1;
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);

}

PriorityQueue
Merge1(PriorityQueue H1, PriorityQueue H2)//H1总是最小的
{
	if (H1->Left == NULL)
		H1->Left = H2;
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
			SwapChildren(H1);

		H1->Npl = H1->Right->Npl + 1;
		return H1;
	}

}
PriorityQueue
SwapChildren(PriorityQueue H1)
{
	PriorityQueue Ege;
	Ege = H1->Left;
	H1->Left = H1->Right;
	H1->Right = Ege;
	return H1;
}

PriorityQueue
Insert1(ElementType X, PriorityQueue H1)
{
	PriorityQueue SingleNode;
	SingleNode =(TreeNode*) malloc(sizeof(struct TreeNode));
	if (SingleNode == NULL)
	{
		printf("Out of Sapce");
		return 0;
	}

	else
	{
		SingleNode->Element = X;
		SingleNode->Left = SingleNode->Right = NULL;
		SingleNode->Npl = 0;
		H1 = Merge(SingleNode, H1);
	}
	return H1;
}

PriorityQueue
DeleteMin(PriorityQueue H)
{
	PriorityQueue LeftHeap, RightHeap;

	if (IsEmpty)
	{
		printf("Priority is empty");
		return H;
	}
	LeftHeap = H->Left;
	RightHeap = H->Right;//注意删除了最小值但是Npl并没有改变；
	free(H);
	return Merge(LeftHeap, RightHeap);//并且这里只是应用了两个Priority结构变量的地址，所以没有申请内存空间；
}

int IsEmpty(PriorityQueue H)
{
	return H->Left == NULL && H->Right == NULL;
}
PriorityQueue
Initialize(void)
{
	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(struct TreeNode));
	if (H == NULL)
	{
		printf("Out of space");
		exit(0);
	}
	else
	{
		H->Left = H->Right = NULL;
		H->Npl = 0;
		H->Element = 0;
	}

}
ElementType
FindMin(PriorityQueue H)
{
	if (H != NULL)
		return H->Element;
	else

		return NULL;
}
 
