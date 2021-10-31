#pragma once
typedef int ELementType;

#include<stdio.h>
#include<stdlib.h>

#ifndef _MErgeSort_
void Msort(ELementType A[], ELementType TmpArray[], int Left, int Right);
void MergeSort(ELementType A[], int N);
void Merge(ELementType A[], ELementType TmpArray[], int Lpos, int Rpos, int RightEnd); 
#endif // !_MErgeSort_

#include"MergeSort.h"

void
Msort(ELementType A[], ELementType TmpArray[], int Left, int Right)
{
	int center;

	center = (Left + Right) / 2;
	Msort(A, TmpArray, Left, center);
	Msort(A, TmpArray, center, Right);
	Merge(A, TmpArray, Left, center + 1, Right);
}

void
MergeSort(ELementType A[], int  N)
{
	ELementType* TmpArray;
	TmpArray = (ELementType*)malloc(sizeof(ELementType));
	if (TmpArray != NULL)
	{
		Msort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
	{
		printf("Out of Space");
		exit(0);
	}
}

void Merge(ELementType A[], ELementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int LeftEnd, TmpPos, i, NumELements;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumELements = RightEnd - Lpos + 1;//当前需要排序数组大小
	
	while (Lpos<=LeftEnd&&Rpos<=RightEnd)
	{
		if (A[Lpos] < A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];//Lpos和Rpos向Leftend和Righend前进，将两者的最小值给Tmp数组，知道有一边超过边界
	}
	while (Lpos <= LeftEnd)
	{
		TmpArray[TmpPos++] = A[Lpos++];
	}
	while (Rpos <= RightEnd)
	{
		TmpArray[TmpPos++] = A[Rpos++];
	}									//将没有超出边界的一边按顺序放入Tmp数组；
	 
	for (i = 0; i < NumELements; i++, RightEnd--)
		A[RightEnd] = TmpArray[RightEnd];         //复制Tmp数组有序的数组给A数组；    
}
