利用数组对栈进行实现
#ifndef _Stack_h
struct StackRecord;
typedef struct StackRecord* Stack;
typedef int ElementType;

int IsEmpty(Stack S);               //
int IsFull(Stack S);               //
Stack CreateStack(int MaxElements);           //
void DisposeStack(Stack S);                    //
void MakeEmpty(Stack S);              //
void Push(ElementType X, Stack S);            //
ElementType Top(Stack S);               //
void Pop(Stack S);               //
ElementType TopAndPop(Stack S);           //
#endif // !1 

 

#include<stdio.h>
#include<stddef.h>
#include"Stack.h"
#define EmptyTOS -1
#define MinStackSize 5
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType* Array;
};


//栈的创建
Stack
CreateStack(int MaxElement)
{
	Stack S;

	if (MaxElement < MinStackSize)
		Error("Stack size is too samll!");
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		FatalError("Out of space!!!");
	S->Array = malloc(sizeof(ElementType) * MaxElement);
	if (S->Array == NULL)
		FatalError("Out of space!!!");
	S->Capacity = MaxElement;
	MakeEmpty(S);

	return S;
}


//释放栈
void
DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);

	}
}
//是否是空栈
int Isempty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}
//创建空栈
void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}
//元素1进栈
void Push(ElementType X, Stack S)
{
	if (IsFull(S))
	{	
		Error("Full Stack");
	}
	else
	{
		S->Array[++S->TopOfStack] = X;
	}
}
//返回栈顶
ElementType Top(Stack S)
{
	if (!IsEmpty(S))
	{
		return S->Array[S->TopOfStack];
	}
	Error("Empty satck");
	return 0;
}

//弹出元素
void Pop(Stack S)
{
	if (IsEmpty(S))
		Error("Empty stack");
	else
		S->TopOfStack--;
}

//给出栈元素并且弹出栈顶元素
ElementType Top(Stack S)
{
	if (!IsEmpty(S))
	{
		return S->Array[S->TopOfStack--];
	}
	Error("Empty satck");
	return 0;
}
