用链表实现栈并且进行调试
 #ifndef _Stack_H
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
typedef int  ElementType;


int Isempty(Stack S);             //
Stack CreateStack(void);           //
void DisposeStack(Stack S);
void Makeempty(Stack S);        //
void Push(ElementType X, Stack S);  //
ElementType Top(Stack S);            //
void Pop(Stack S);            //

#endif // !_Stack_H

#include<stddef.h>
#include<stdio.h>
 
#include"Stack.h"
struct Node
{
	ElementType Element;
	PtrToNode Next;
};


//判断是否为空栈
int Isempty(Stack S)
{
	return S->Next == NULL;
}

//创建一个空栈
Stack CreateStack(void)
{
	Stack S;
	S = malloc(sizeof(struct Node));
	if (S = NULL)
		FatalError("Out of space");
	S->Next == NULL;
	Makeempty(S);
	return S;
}
void MakeEmpty(Stack S)
{
	if (S == NULL)
	{
		Error("Must use CreateStack first");
	}
	else
	{
		while (!Isempty(S))
			Pop(S);
	}
}

//元素进栈
void Push(ElementType X, Stack S)
{
	PtrToNode Tmpcell;

	Tmpcell = malloc(sizeof(struct Node));
	if (Tmpcell == NULL)
		FatalError("Out of space!!!");
	else
	{
		Tmpcell->Element = X;
		Tmpcell->Next = S->Next;
		S->Next = Tmpcell;
	}
}


//删除栈
void DisposeStack(Stack S)
{
	if (S!= NULL && S->Element != NULL)
	{
		free(S->Next);
		free(S);
	}
}
//弹出栈元素
void Pop(Stack S)
{
	PtrToNode FirstCell;

	if (Isempty(S))
		Error("Empty stack");
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}
//返回栈顶元素
ElementType
Top(Stack S)
{
	if (!Isempty(S))
	{
		return S->Next->Element;
	}
	Error("Empty Stack");
	return 0;
}
