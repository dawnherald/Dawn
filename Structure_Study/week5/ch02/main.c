#include<stdio.h>
#include<stdlib.h>
#define MaxTrees 10

int Capacity = MaxTrees;
typedef struct BinNode* Position;
typedef struct Collection* BinQueue;
typedef Position BinTree;
typedef int ElementType;
struct BinNode
{
	ElementType Element;
	Position LeftChild; //左儿子
	Position NextSibling;//下一个兄弟
};

struct Collection
{
	int CurrentSize;
	BinTree TheTrees[MaxTrees];
};
#include"BinomialQueues.h"
BinTree
CombineTrees(BinTree T1, BinTree T2)
{
	if (T1->Element > T2->Element)
		return (T2, T1);
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}
BinQueue
Merge(BinQueue H1, BinQueue H2)
{
	BinTree T1, T2, Carry = NULL;
	int i, j;


	if (H1->CurrentSize + H2->CurrentSize > Capacity)
	{
		printf("Merge would Exceed capacity");
		exit(0);
	}
	H1->CurrentSize += H2->CurrentSize;
	for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2)
	{
		T1 = H1->TheTrees[i] ; T2 = H2->TheTrees[i];

		switch (!!T1 + 2 * !!T2 + 4 * !!Carry)
		{
		case 0:
		case 1: break;
		case 2:
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		case 4:
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		case 3:
			Carry = CombineTrees(T1, T2);
			H1->TheTrees[i] = H2->TheTrees[i] = NULL;
			break;
		case 5:
			Carry = CombineTrees(T1, Carry);
			H1->TheTrees[i] = NULL;
			break;
		case 6:
			Carry = CombineTrees(T2, Carry);
			H2->TheTrees[i] = NULL;
			break;
		case 7:
			H1->TheTrees[i] = Carry;
			Carry = CombineTrees(T1, T2);
			H2->TheTrees[i] = NULL;
			break;
		}
	}
	return H1;
}
