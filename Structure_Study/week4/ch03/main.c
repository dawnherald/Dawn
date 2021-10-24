//#include <cstddef>
//#include<stddef.h>
//#include<stdlib.h>
//#ifndef _HashQuad_H
//typedef unsigned int Index;
//typedef Index Position;
//typedef int ElementType;
//
//
//struct HashTbl;
//typedef struct HashTbl* HashTable;
//
//HashTable InitializeTable(int TableSize);
//void DestroyTable(HashTable H);
//Position Find(ElementType Key, HashTable H);
//void Insert(ElementType Key, HashTable H);
//ElementType Retrieve(Position P, HashTable H);
//HashTable ReHash(HashTable H);
//#endif // !_HashQuad_H
//
//enum KindOfEntry { Legitimate, Empty, Deleted };
//
//struct  HashEntry
//{
//	ElementType Element;
//	enum KindOfEntry Info;
//};
//typedef struct HashEntry Cell;
//
//struct HashTbl
//{
//	int Tablesize;
//	Cell* TheCell;
//};
//#define MinTableSize 10
//HashTable
//InitializeTable(int TableSize)
//{
//	HashTable H;
//	int i;
//
//	if (TableSize < MinTableSize)
//	{
//		Error("Table is too samll");
//		return NULL;
//
//	}
//	H = malloc(sizeof(struct HashTbl));
//	if (H == NULL)
//		FatalError("Out of Space");
//	H->Tablesize = NextPrime(TableSize);
//
//	H->TheCell = malloc(sizeof(Cell) * H->Tablesize);
//	if (H->TheCell == NULL)
//		FatalError("Out of Space");
//	for (i = 0; i < H->Tablesize; i++)
//	{
//		H->TheCell[i].Info = Empty;
//	}
//	return H;
//
//}
////平方探测find
//Position 
//Find(ElementType Key, HashTable H)
//{
//	Position CurrentPos;//这里的Position是unsigned int;
//	int collsionNum;//代表冲突的次数
//	collsionNum = 0;
//	CurrentPos = Hash(Key, H->Tablesize);
//	while (H->TheCell[CurrentPos].Info != Empty && H->TheCell[CurrentPos].Element != Key)
//	{
//		CurrentPos += 2 *+ collsionNum - 1;//利用冲突的次数对当前的位置进行深入查找
//		if (CurrentPos >= H->Tablesize)
//			CurrentPos=H->Tablesize-CurrentPos;
//	}
//	return CurrentPos;
//
//}
//
////插入历程
//void
//Insert(ElementType Key, HashTable H)
//{
//	Position Pos;
//	
//	Pos = Find(Key, H);//这里使用的是Find函数,如果hash表里面已经有这个元素,那么不进行操作,如果没有元素,FInd里面的Hash会返回一个空的表格数组
//	if(H->TheCell[Pos].Info!=Legitimate)
//	{
//		H->TheCell[Pos].Info = Legitimate;
//		H->TheCell[Pos].Element = Key;
//		H->TheCell[Pos].Info;
//	}
//}
//
//
//HashTable
//Rehash(HashTable H)
//{
//	int i, OldSize;
//	Cell* OldCells;
//
//	OldCells = H->TheCell;//建立一个新的Hash表格
//	OldSize = H->Tablesize;
//
//	H = InitializeTable(2*OldSize);
//	for (i = 0; i < OldSize; i++)
//		if (OldCells[i].Info == Legitimate)
//			Insert(OldCells[i].Element, H);
//	free(OldCells);
//	return H;
//
//
//}
//void 
//DestroyTable(HashTable H)
//{
//	int i;
//	for (i = 0; i < H->Tablesize; i++)
//	{
//	
//		free(H->TheCell[i].Info);
//		free(H->TheCell[i].Element);
//
//	}
//	free(H->Tablesize);
//}
//
//ElementType
//Retrieve(Position P, HashTable H)
//{
//	if (H->TheCell[P].Info != Empty)
//		return H->TheCell[P].Element;
//	else
//		return 0;
//}
