#include<stdio.h>
#define MIN(A, B) (A < B)?A:B
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    //int col = *matrixColSize;
    //int row = matrixSize/col;
    int *prev_row_cost = (int *)calloc(matrixSize, sizeof(int));
    int *cur_row_cost = (int *)calloc(matrixSize, sizeof(int));

    for(int i = 0; i < matrixSize; i++)
    {
        prev_row_cost[i] = matrix[0][i];
    }
    int min = __INT_MAX__;
    for(int row = 1; row < matrixSize; row++)
    {
        for(int col = 0; col < matrixSize; col++)
        {

        }
    }
}