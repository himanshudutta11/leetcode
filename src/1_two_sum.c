#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *arr = (int *)calloc(2, sizeof(int));
    for(int i = 0; i < numsSize -1; i++)
    {
        for(int j = i+1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
                return arr;
            }
        }
    }
    return arr;
}
int main()
{
    int nums[] = {2,7,11,15};
    int size = 0;
    int *ret = twoSum(nums, sizeof(nums)/sizeof(nums[0]), 9, &size);

    for(int i = 0; i < size; i++)
    {
        printf("%d,\n", ret[i]);
    }

    return 0;
}