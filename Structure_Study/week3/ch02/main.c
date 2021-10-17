 
 
#ifndef _Tree_H
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchRTree;
typedef int ElementType;
 
SearchRTree MakeEmpty(SearchRTree T);
Position Find(ElementType X, SearchRTree T);
Position FindMin(SearchRTree T);
Position FindMax(SearchRTree T);
SearchRTree Insert(ElementType X,SearchRTree T);
SearchRTree Delete(ElementType X, SearchRTree T);
ElementType Retrive(Position P);
#endif // !_Tree_H

#include <cstddef>
#include<stdio.h>
struct TreeNode
{
	ElementType Element;
	SearchRTree Left;
	SearchRTree Right;
};
//建立空树
SearchRTree MakeEmpty(SearchRTree T)
{
	if (T != NULL)
	{	
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T); //先把树的左右子树位置给出再free，避免程序终止
	}
	return NULL;
}
//二叉树查找程序
Position
Find(ElementType X, SearchRTree T)
{
	if (T = NULL)
		return NULL;
	if (X > T->Element)
		return Find(X, T->Right);
	else
		if (X < T->Element)
			return FindMin(X, T->Left);
		else
			return T;
}
//FindMIn的递归实现
Position
FindMin(SearchRTree T)
{
	if (T = NULL)
		return NULL;
	if (T->Left = NULL)
		return NULL;
	else
		return FindMin(T->Left);
}
//FindMax的非递归实现
Position 
FindMax(SearchRTree T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T->Right;
	return T;
 
}
//FindMax的递归实现
Position
FindMax(SearchRTree T)
{
	if (T = NULL)
		return NULL;
	if (T->Right = NULL)
		return NULL;
	else
		return FindMax(T->Right);

}
//树的删除并且不打乱顺序  
SearchRTree
Delete(ElementType X, SearchRTree T)
{
	Position TmpCell;

	if (T == NULL)
		Error("Element Not Find");
	else
		if (X < T->Element)
			T->Left = Delete(X,T->Left);
		else
			if (X > T->Element)
				T->Right = Delete(X,T->Right);
			else
				if (T->Left && T->Right)
				{
					TmpCell = FindMin(T->Right);
					T->Element = TmpCell->Element;
					T->Right = Delete(T->Element, T->Right);
				}
				else
				{
					TmpCell = T;
					if (T->Left = NULL)
						T = T->Right;
					else
						if (T->Right = NULL)
							T = T->Left;
					free(TmpCell);
				}
	return T;
}
//元素查找
SearchRTree 
Insert(ElementType X, SearchRTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL)
			FatalError("Out of space");
		else
		{
			T->Element = X;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
		else
		if (X < T->Left)
			T->Left = Insert(T->Element, T->Left);
		else
		if (X> T->Right)
			T->Right = Insert(T->Element, T->Right);
	return T;
}
//返回值
ElementType
Retrieve(Position P)
{
	return P->Element;
}
