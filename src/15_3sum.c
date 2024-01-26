#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort((void *)nums, (size_t)numsSize, sizeof(int), compare);
    int i, j, k;
    int **result = (int **)malloc(sizeof(int *)*numsSize*numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int)*numsSize*numsSize);
    *returnSize = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(i == 0 || nums[i] != nums[i-1])
        {
            k = numsSize - 1;
            for(j = i + 1; j < numsSize; j++)
            {
                if(j == i + 1 || nums[j] != nums[j-1])
                {
                    while(j < k && nums[i] + nums[j] + nums[k] > 0)
                    {
                        k--;
                    }
                    if(j == k)
                    {
                        break;
                    }
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        result[*returnSize] = (int *)malloc(sizeof(int)*3);
                        result[*returnSize][0] = nums[i];
                        result[*returnSize][1] = nums[j];
                        result[*returnSize][2] = nums[k];
                        (*returnColumnSizes)[*returnSize] = 3;
                        (*returnSize)++;
                    }
                }
            }
        }
    }
    return result;
}
int main()
{
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    // after sort {-4, -1, -1, 0, 1, 2}

    int numsSize = 6;
    int returnSize = 0;
    int **returnColumnSizes = (int**)malloc(sizeof(int*) * numsSize * numsSize);

    int **ans = threeSum(nums, numsSize, &returnSize, returnColumnSizes);
    for (int index = 0; index < returnSize; index++)
    {
        printf("%d\t%d\t%d\n", ans[index][0], ans[index][1], ans[index][2]);
    }
}
