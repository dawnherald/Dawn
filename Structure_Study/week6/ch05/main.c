typedef double** Matrix;
void
MatrixMultiply(Matrix A,Matrix B,Matrix C,int N )
{
	int i, j, k;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			C[i][j] = 0.0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			for (k = 0; k < N; k++)
				C[i][k] += A[i][k] * B[k][j];
} 
