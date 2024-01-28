#include<stdio.h>
#include<stdlib.h>
int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target) {
    const int m = matrixSize;
    const int n = *matrixColSize;
    int **sums = (int **)calloc(m+1, sizeof(int *));
    for(int i = 0; i < (m+1); i++)
    {
        sums[i] = (int *)calloc(n+1, sizeof(int));
    }
    int result = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sums[i][j] = sums[i][j-1] + sums[i-1][j] - sums[i-1][j-1] + matrix[i-1][j-1];
        }
    }

    int temp = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int p = 1; p <= i; p++)
            {
                for(int q = 1; q <= j; q++)
                {
                    temp = sums[i][j] - sums[i][q-1] - sums[p-1][j] + sums[p-1][q-1];
                    if(temp == target)
                    {
                        result++;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < m+1; i++)
    {
        free(sums[i]);
    }

    free(sums);

    return result;
}
int main()
{
#define M 5    
#define N 6    
    //int mat[3][3] = {{0,1,0},{1,1,1},{0,1,0}};
    int mat[M][N] = {{0,1,1,1,0,1},{0,0,0,0,0,1},{0,0,1,0,0,1},{1,1,0,1,1,0},{1,0,0,1,0,0}};
    int **matrix = (int **)calloc(M, sizeof(int *));
    for(int i = 0; i < M; i++)
    {
        matrix[i] = (int *)calloc(N, sizeof(int));
    } 

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
    int matrixSize = M;
    int matrixColSize = N;
    int target = 0;
    int *matrixColSize_p = &matrixColSize;
    printf("%d \n", numSubmatrixSumTarget(matrix, matrixSize, matrixColSize_p, target));

    return 0; 
}