//#include <cstddef>
//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//
//#ifndef _HashSep_H
//struct ListNode;
//typedef struct ListNode* Position;
//struct HashTbl;
//typedef struct HashTbl* HashTable;
//typedef char ELementType;
//typedef unsigned int Index;
// 
//HashTable InitializeTable(int TableSize);
//void  Delete(HashTable H);
//Position Find(ELementType Key, HashTable H);
//void Insert(ELementType Key, HashTable H);
//ELementType Retrieve(Position P);
//int IsPrime(int X)
//int NextPrime(int X)
//#endif // !_HashSep_H
//
//struct  ListNode
//{
//	ELementType Element;
//	Position Next;
//};
//
//typedef Position List;
//
//struct  HashTbl
//{
//	int TableSize;
//	List* TheLists;
//};
//
//
//#define MinTableSize 10
//
//HashTable
//InitializeTable(int TableSize)
//{
//	HashTable H;
//	int i;
//
//	if (TableSize < MinTableSize)
//	{
//		Error("Table is too Small");
//		return NULL;
//	}
//	H = malloc(sizeof(struct HashTbl));
//	if (H == NULL)
//		FatalError("Out Of Space");
//	H->TableSize = NextPrime(TableSize);
//	H->TheLists = malloc(sizeof(List) * H->TableSize);
//	if (H->TheLists == NULL)
//		FatalError("Out Of Space");
//	for (i = 0; i < H->TableSize; i++)
//	{
//		H->TheLists[i] = malloc(sizeof(struct ListNode));
//		if (H->TheLists[i] == NULL)
//			FatalError("Out Of Space");
//		else
//			H->TheLists[i]->Next = NULL;
//		return H;
//	}
//}
//
////Find历程
//
//Position 
//Find(ELementType Key, HashTable H)
//{
//	Position P;
//	List L;
//
//	L = H->TheLists[Hash(Key, H->TableSize)];
//	P = L->Next;
//	while (P != NULL && P->Element != Key)
//		P = P->Next;
//	return P;
//}
//
//Index
//Hash(const ELementType* Key, int TableSize)
//{
//	unsigned int Hashval =0 ;
//	while (*Key != '\0')
//		Hashval = (Hashval<<5)+*Key++;
//	return Hashval % TableSize;
//}//我这里的hash散列的是字符型的
//
//Index
//HashFun(const  ELementType*Key, int tablesize)
//{
//	unsigned int hashval = 0;
//	while (*Key!= '\0')
//		hashval = (hashval << 5) + *Key++;
//	return hashval % tablesize;
//}
//
//void
//Insert(ELementType Key, HashTable H)
//{
//	Position Pos, NewcCell;
//	List L;
//
//	Pos = Find(Key, H);//返回查找元素的位置
//	if (Pos == NULL)//如果有查找到就直接不执行了，因为以已经有这个插入值；
//	{
//		NewcCell = malloc(sizeof(struct ListNode));
//		if (NewcCell == NULL)
//			FatalError("Out Of Space");
//		else
//		{
//			L = H->TheLists[Hash(Key, H->TableSize)];
//			NewcCell->Next = L->Next;
//			NewcCell->Element = Key;
//			L->Next = NewcCell;
//		}
//		
//	}
//
//
//}
//void
//Delete(HashTable H)
//{
//	Position P, Del;
//	int i;
//
//	for (i = 0; i < H->TableSize; i++)
//	{
//		P = H->TheLists[i]->Next;
//		while (P != NULL)
//		{
//			Del = P;
//			free(Del);
//			P = P->Next;
//		}
//	}
//	free(H->TheLists);
//	free(H);
//}
//
////返回
//ELementType
//Retrieve(Position P)
//{
//	if (P->Next != NULL)
//		return P->Element;
//	else
//		return NULL;
//}

//int NextPrime(int x)
//{
//	while (!isPrime(x))
//	{
//		x = x + 1;
//	}
//	return x;
//}
//
//
//int IsPrime(int x)
//{
//	int i;
//	for (i = 2; i < sqrt(x); i++)
//	{
//		if (x % i == 0)
//			return 0;
//	}
//	return 1;
