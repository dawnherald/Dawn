// #include<time.h>
//#include<stdio.h>
//#include"BinHeap.h"
//int main(void)
//{
//	PriorityQueue H;
//	int Num[100], j;
//	H = Initialize(100);
//	for (j = 0; j < 12; j++)
//		scanf_s("%4d", H->Element);
//	for (j = 0; j < 12; j++)
//		printf("%4d", H->Element);
//	return 0;
//}
#include"ShellSort.h"
#include<stdio.h>
int main(void)
{
	ElementType A[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &A[i]);
	}
	ShellSort(A, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%5d", A[i]);
	}
}


