#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) 
{
    qsort((void *)nums, (size_t)numsSize, sizeof(int), compare);
    int i, j, k, l;

    int **result = (int **)malloc(sizeof(int *)*numsSize*numsSize*numsSize);

    //*returnColumnSizes = (int *)malloc(sizeof(int)*numsSize*numsSize*numsSize);

    *returnSize = 0;

    for(i = 0; i < numsSize; i++)
    {
        if(i = 0 || (nums[i] != nums[i-1]))
        {
            for(j = i+1; j < numsSize; j++)
            {
                if(j = i+1 || nums[j] != nums[j-1])
                {
                    l = numsSize - 1;
                    for(k = j+1; k < numsSize; k++)
                    {
                        if(k = j+1 || nums[k] != nums[k-1])
                        {
                            while(k < l && (long)nums[i] + nums[j] + nums[k] + nums[l] > target)
                            {
                                l--;
                            }
                            if(k == l)
                            {
                                break;
                            }
                            if((long)nums[i] + nums[j]+nums[k]+nums[l] == target)
                            {
                                result[*returnSize] = (int *)malloc(sizeof(int)*4);
                                result[*returnSize][0] = nums[i];
                                result[*returnSize][1] = nums[j];
                                result[*returnSize][2] = nums[k];
                                result[*returnSize][3] = nums[l];
                                (*returnColumnSizes)[*returnSize] = 4;
                                (*returnSize)++;
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}
int main()
{
    int nums[6] = {1, 0, -1, 0, -2, 2};
    // after sort {-2, -1, 0, 0, 1, 2}

    int numsSize = 6;
    int target = 0;
    int returnSize = 0;
    int **returnColumnSizes = (int**)malloc(sizeof(int*) * numsSize * numsSize * numsSize);
    printf("fourSUM");
    int **ans = fourSum(nums, numsSize, target, &returnSize, returnColumnSizes);
    for (int index = 0; index < returnSize; index++){
        printf("%d\t%d\t%d\t%d\n", ans[index][0], ans[index][1], ans[index][2], ans[index][3]);
    }
}