#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == target)
        {
            return i;
        }
        else if((nums[i] > target) && (i == 0))
        {
            return i;
        }
        else if((nums[i] < target) && (i == numsSize -1))
        {
            return i+1;
        }
        else if((nums[i] < target) && (nums[i+1] > target))
        {
            return i+1;
        }
    }
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    printf("%d", searchInsert(arr, sizeof(arr)/sizeof(arr[0]), 8));
    return 0;
}