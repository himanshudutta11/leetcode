#include<stdio.h>
#include<stdlib.h>
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, k;
    int col = *matrixColSize;
    for(i = 0, j = col - 1; j >= 0; j -=2, i++)
    {
        for(k = 0; k < j; k++)
        {
            /* First take left top element as backup */
            int temp = matrix[i][i+k];
            /* left bottom element --> left top element */
            matrix[i][i+k] = matrix[i+j-k][i];
            /* right bottom element --> left bottom element */
            matrix[i+j-k][i] = matrix[i+j][i+j-k];
            /* right top element --> right bottom element */
            matrix[i+j][i+j-k] = matrix[i+k][i+j];
            /* left top element --> right top element */
            matrix[i+k][i+j] = temp;
        }
    }   
}

int main()
{
    int matrixColSize = 3;
    int mat[3][3] = {
                {4 , 5, 6},
                {1 , 2, 14},
                {11 , 2, 1},
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

                  
    rotate(matrix, 9, &matrixColSize);

    printf("After rotating\n");

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    } 

    return 1;
}