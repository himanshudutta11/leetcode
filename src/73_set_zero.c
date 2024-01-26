#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int col = *matrixColSize;
    int row = matrixSize/col;
    bool *row_has_zero = (bool *)calloc(1, row*sizeof(bool));
    bool *col_has_zero = (bool *)calloc(1, col*sizeof(bool));
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] == 0)
            {
                row_has_zero[i] = true;
                col_has_zero[j] = true;
            }
        }
    }
    for(int i = 0; i < row; i++)
    {
        if(row_has_zero[i])
        {
            for(int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < col; i++)
    {
        if(col_has_zero[i])
        {
            for(int j = 0; j < row; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
}
int main()
{
    int mat[3][3] = {
                {1 , 1, 1},
                {1 , 0, 1},
                {1 , 1, 1},
                };
    int **matrix = (int **)calloc(3, sizeof(int *));
    for(int i = 0; i < 3; i++)
    {
        matrix[i] = (int *)calloc(3, sizeof(int));
    } 

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
    int matrixColSize = 3;
    int matrixSize = 9;
    setZeroes(matrix, matrixSize, &matrixColSize);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ,",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}