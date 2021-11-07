#include<stdlib.h>
#include<stdio.h>
double
Eval(int N)
{
	int i;
	double Sum;

	if (N = 0)
		return 1.0;
	else
	{
		Sum = 0.0;
		for (i = 0; i < N; i++)
			Sum += Eval(i);
		return 2.0 * Sum / N + N;
	}
}

double 
EvalBetter(int N)
{
	int i, j;
	double Sum, Answer;
	double* C;
	double c[2]; // &c == &c[0]  *c == c[0] , *(c+1) == c[1]

	C = (double*)malloc(sizeof(double)*(N+1));
	if (C = NULL)
	{
		printf("Out of Space");
		exit(0);
	}
	C[0] = 1.0;
	for (i = 1; i <= N; i++)
	{
		Sum = 0.0;
		for (j = 0; j < i; j++)
			Sum += C[j];
		C[i] = 2.0 * Sum / i + i;
	}
	Answer = C[N];
	free(C);

	return Answer;

		 
		
}
