#include<stdio.h>
#include<stdlib.h>
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int **mat = (int **)calloc(n, sizeof(int *)*n);
    for(int i = 0; i < n; i++)
    {
        mat[i] = (int *)calloc(1, sizeof(int)*n);
    }
    int left = 0;
    int right = n-1;
    int top = 0;
    int bottom = n-1;
    int k = 1;
    while(left <= right && top <= bottom)
    {
        if(left == right && top == bottom)
        {
            mat[left][top] = k++;
            left++;
            right--;
            top++;
            bottom--;
        }
        else
        {
            for(int i = left; i <= right; i++)
            {
                mat[top][i] = k++;
            }
            top++;
            for(int i = top; i <= bottom; i++)
            {
                mat[i][right] = k++;
            }
            right--;
            for(int i = right; i >=left; i--)
            {
                mat[bottom][i] = k++;
            }
            bottom--;
            for(int i = bottom; i >= top; i--)
            {
                mat[i][left] = k++;
            }
            left++;
        }
    }
    return mat;
}
int main()
{
    int returnSize;
    int *returnColumnSizes;
    int num = 3;
    int **arr = generateMatrix(num, &returnSize, &returnColumnSizes);

    return 0;
}