  #include<stdlib.h>
#include<stdio.h>
#ifndef _Splay_H

struct SplayNode;
typedef struct SplayNode* SplayTree;
typedef int ELementType;

SplayTree MakeEmpty(SplayTree T);
SplayTree Find(ELementType X, SplayTree T);
SplayTree FindMin(SplayTree T);
SplayTree FindMax(SplayTree T);
SplayTree Initialize(void);
SplayTree Insert(ELementType X, SplayTree T);
SplayTree Remove(ELementType X, SplayTree T);
ELementType Retrieve(SplayTree T);

#endif // !_Splay_H

struct SplayNode
{
	ELementType Element;
	SplayTree Left;
	SplayTree Right;

};

typedef struct SplayNode* Position;
static Position NullNode = NULL;

 #include"SplayTree.h"

SplayTree
Initialize(void)
{
	if (NullNode == NULL)
	{
		NullNode = (SplayNode*)malloc(sizeof(struct SplayNode));
		if (NullNode == NULL)
			printf("Out of Space");
		NullNode->Right = NullNode->Left = NULL;

	}
	return NullNode;
}


