用游标实现链表代码段以及调试
 

#ifndef CUSORLIST_H_INCLUDED
#define CUSORLIST_H_INCLUDED

 
typedef int PtrToNode;
typedef int ElementType;  //设置元素类型为整数
typedef PtrToNode List;
typedef PtrToNode Position;
#define SpaceSize 100;
void InitiaLizeCursorSpace(void);                 //

List MakeEmpty(List L);                         //
int Isempty(const List L);
int IsLast(const Position P,const List L);
Position Find(ElementType X,const List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X,List L,Position P);
void DeleteList(List L);
Position Header(const List L);                             //
Position First(const List L);                            //
Position Advance(const Position P);                             //
ElementType Retrieve(const Position);                         

#endif

 
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "CursorList.h" //让编译器先在当前工程所在路径下搜索，找不到再去编译器预设的标准路径查找，一般用来包含自己定义的头文件


#define SpaceSize 40
struct Node
{
	ElementType Element;
	Position Next;
}; struct Node  CursorSpace[SpaceSize];
 
 
 

//CursorSpace 初始化
void Initialize(void)
{
	int i = 0;
	while (i<SpaceSize-1)
	{
		CursorSpace[i].Next = ++i;
		CursorSpace[SpaceSize - 1].Next = NULL;
	}
}
//调用malloc从系统全局内存得到
static Position
CursorAlloc(void)
{
	Position P;

	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;

	return P;
}
static void
//Cursorspace并且实现free
CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}
//测试P是否是链表的末尾
int IsLast(Position P, List L)
{
	return CursorSpace[P].Next == 0;
}
//测试是否为空
int Isempty(  List L)
{
	return CursorSpace[L].Next == 0;
}
//例程Find  FindFind在下面表出，它返回某个元素在表中的位置
//P != NULL && P->Element != X
Position Find(ElementType X, List L)
{
	Position P;

	P = CursorSpace[L].Next;
	while (P&&CursorSpace[P].Element!=X)
	{
		P = CursorSpace[P].Next;
	}
	return P;
}
//FindPrevious函数找出含有X的表元的前驱元PP

Position FindPrevious(ElementType X, const List L)            //出错点//const List L和List 区别
{
	Position P;
	P = L;
	Position tmp = CursorSpace[P].Next;
	while (CursorSpace[tmp].Next != 0 && CursorSpace[tmp].Element != X) {
		tmp = CursorSpace[tmp].Next;
		P = CursorSpace[P].Next;
	}
	return P;
}

 /*{
	Position P;
	P = L;
	Position tmp = CursorSpace[P].Next;
	while (CursorSpace[tmp].Next != 0 && CursorSpace[tmp].Element != X) {
		tmp = CursorSpace[tmp].Next;
		P = CursorSpace[P].Next;
	}
	return P;
} 

 
//对链表进行删除Delete  我们的例程将删除第一次出现的XX，如果XX不在表中我们就什么也不做

void Delete(ElementType X, List L)
{
	Position P, Tmpcell;

	P = FindPrevious(X, L);
	if (!IsLast(X, L))
	{
		Tmpcell = CursorSpace[P].Next;
		CursorSpace[P].Next = CursorSpace[Tmpcell].Next;
		CursorFree(Tmpcell);
	}
}

//对链表进行插入操作Insert
void
Insert(ElementType X, List L, Position P)
{
	Position Tmpcell;

	Tmpcell = CursorAlloc();
	if (Tmpcell == 0)
		FatalError("Out of Space");

	CursorSpace[Tmpcell].Element = X;
	CursorSpace[Tmpcell].Next = CursorSpace[P].Next;
	CursorSpace[P].Next = Tmpcell;

}
//删除整个表的正确方法
void DeleteList(List L)
{
	Position P, Tmpcell;
	P = CursorSpace[L].Next;	//表L的第一个结点
	CursorSpace[L].Next = 0;
	while (P != 0)
	{
		Tmpcell = CursorSpace[P].Next;//依次传递并且递交给Tmpcell每一项的Next（下一项的地址），然后释放每一项的内存空间
		free(P);
		P = Tmpcell;
	}
}
 
