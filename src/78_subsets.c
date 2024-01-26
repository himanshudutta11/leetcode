/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 1 << numsSize;
    int **result = (int **)calloc(*returnSize, sizeof(int *));
    *returnColumnSizes = (int *)calloc(*returnSize, sizeof(int));

    for(int i = 0; i < *returnSize; i++)
    {
        result[i] = (int *)calloc(numsSize, sizeof(int));
        (*returnColumnSizes)[i] = 0;

        int bit = 0;
        int criterion = i;

        while(criterion)
        {
            if(criterion & 1)
            {
                result[i][(*returnColumnSizes)[i]] = nums[bit];
                (*returnColumnSizes)[i]++;
            }
            bit++;
            criterion = criterion >> 1;
        }
    }

    return result;    
}
int main()
{
    int nums[3] = {1,2,3};
    int returnSize;
    int *returnColumnSizes;
    int **result = subsets(nums, 3, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; i++)
    {
        printf("\nresult[%d]: ", i);
        for(int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", result[i][j]);
        }
    }
    return 0;
}