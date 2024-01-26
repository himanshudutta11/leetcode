#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int x = nums[0];
    int i;
    int idx = 1;
    for(i = 1; i < numsSize; i++)
    {
        if(x != nums[i])
        {
            x = nums[i];
            nums[idx++] = nums[i];
        }
        else
        {
            nums[idx++] = nums[i];
            for(int j = i; j < numsSize && x == nums[j]; j++)
            {
                i = j;
            }
        }
    }
    return idx;
}
int main()
{
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    int num = sizeof(arr)/sizeof(arr[0]);
    int ret = removeDuplicates(arr, num);
    for(int i = 0; i < ret; i++)
    {
        printf("%d,", arr[i]);
    }
    return 0;
}