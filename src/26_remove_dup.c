#include<stdio.h>
/*
int removeDuplicates(int* nums, int numsSize) {
    int k = numsSize;
    for(int i = 0; i < k; i++)
    {
        if(nums[i] == nums[i+1])
        {
            for(int j = i+1; j < k; j++)
            {
                nums[j] = nums[j+1];
            }
            k--;
            i--;
        }
    }
    return k;
}*/
int removeDuplicates(int* nums, int numsSize) {
    int i;
    int j;
    for(i =0, j= 1; j < numsSize; j++)
    {
        if(nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
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