#include<stdio.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void permutation(int *nums, int left, int right, int **ret, int *row)
{
    printf("Permute Start\n");

    if(left == right)
    {
        memcpy(ret[(*row)++], nums, (right+1)*sizeof(int));
    }
    else
    {
        int i;
        for(i = left; i <= right; i++)
        {
            swap(nums+left, nums+i);
            permutation(nums, left+1, right, ret, row);
            swap(nums+left, nums+i);
        }
    }
    int i;
    for (i = 0; i <=right; i++) 
    {
        printf("%d ", nums[i]);
    }
    printf("\nPermute End\n");
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{

    (*returnSize) = 1;
    int i;
    for(i = 2; i <= numsSize; i++)
    {
        (*returnSize) *= i;
    }
    int **ret = (int **)calloc(*returnSize , sizeof(int *));
    for(i = 0; i < *returnSize; i++)
    {
        ret[i] = (int *)calloc(numsSize, sizeof(int));
    }
    **returnColumnSizes = numsSize;
    int row = 0;

    permutation(nums, 0, numsSize-1, ret, &row);

    return ret;
    
}
int main() {
    int numsSize = 3;
    int *nums = (int *)malloc(numsSize * sizeof(int));
    int i, j;
    for (i = 0; i < numsSize; i++) {
        nums[i] = i + 1;
    }

    int returnSize = 0;
    int columnSize = 0;
    int *returnColumnSizes = &columnSize;
    int **ret = permute(nums, numsSize, &returnSize, &returnColumnSizes);
    printf("================\n");

    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < numsSize; j++) {
            printf("%d ", ret[i][j]);
        }
        free(ret[i]);
        printf("\n");
    }
    free(ret);

    return 0;
}